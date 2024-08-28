/****************************************************************************
*
* Copyright © 2016-2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/

/**
 * @file    clock.c
 * @brief   SPC582Bxx clock subsystem source.
 *
 * @addtogroup CLOCK
 * @{
 */

#include "clock.h"

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

#if (SPC5_CLEAR_FCCU_RGM == TRUE)
/**
 * @brief   Clear FCCU Status Register errors and RGM errors.
 *
 * @notapi
 */
static void spc_clear_fccu_rgm(void) {

  /* Clear FCCU Status Register0 errors */
  FCCU.RFK.R = 0xAB3498FEUL;
  FCCU.RF_S[0].R = 0xFFFFFFFFUL;
  while (FCCU.CTRL.B.OPS != 0x03UL) {
  }

  /* Clear FCCU Status Register1 errors */
  FCCU.RFK.R = 0xAB3498FEUL;
  FCCU.RF_S[1].R = 0xFFFFFFFFUL;
  while (FCCU.CTRL.B.OPS != 0x03UL) {
  }

  /* Clear FCCU Status Register2 errors */
  FCCU.RFK.R = 0xAB3498FEUL;
  FCCU.RF_S[2].R = 0xFFFFFFFFUL;
  while (FCCU.CTRL.B.OPS != 0x03UL) {
  }

  /* Clear FCCU Status Register3 errors */
  FCCU.RFK.R = 0xAB3498FEUL;
  FCCU.RF_S[3].R = 0xFFFFFFFFUL;
  while (FCCU.CTRL.B.OPS != 0x03UL) {
  }

  /* RGM errors clearing.*/
  MC_RGM.FES.R = 0xFFFFU;
  MC_RGM.DES.R = 0xFFFFU;
}
#endif /* SPC5_CLEAR_FCCU_RGM */

/**
 * @brief   Setup PFLASH controller
 *
 * @param[in] clk_freq  clock frequency for PFlash Controller
 *
 * @notapi
 */
static void SPCSetPFlashController(uint32_t clk_freq) {

  if ((clk_freq > 0UL) && (clk_freq <= 80000000UL)) {
    PFLASH_1.PFCR1.B.APC = 0;
    PFLASH_1.PFCR1.B.P0_BFEN = 1;
    PFLASH_1.PFCR2.B.P1_BFEN = 1;
    if (clk_freq <= 27000000UL) {
      /* 0 < clk_freq <= 27MHz*/
      PFLASH_1.PFCR1.B.RWSC = 0;
    } else if (clk_freq <= 54000000UL) {
      /* 27MHz < clk_freq <= 54MHz*/
      PFLASH_1.PFCR1.B.RWSC = 1;
    } else {
      /* 54MHz < clk_freq <= 80MHz*/
      PFLASH_1.PFCR1.B.RWSC = 2;
    }
    PFLASH_1.PFCR1.B.APC = 4;
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Clock initialization.
 *
 * @notapi
 */
void clockInit(void) {

  /* The system is switched in the final run mode (default is RUN0 mode).*/
  if (SPCSetRunMode(SPC5_FINAL_RUNMODE) == CLOCK_FAILED) {
    SPC5_CLOCK_FAILURE_HOOK();
  }
}

/**
 * @brief   SPC582Bxx clocks and PLL initialization.
 *
 * @note    This function must be invoked only after the system reset.
 *
 * @special
 */
void spc_clock_init(void) {

  /* Waiting for IRC stabilization before attempting anything else.*/
  while (MC_ME.GS.B.S_IRC == 0U){
  }

#if (SPC5_NO_INIT == FALSE)

  /* SSCM initialization from configuration data.*/
  SSCM.ERROR.R            = (uint16_t)SPC5_SSCM_ERROR_INIT;

  /* Clear FCCU/RGM errors if FCCU driver is disabled, otherwise the errors are
     managed by the FCCU driver.*/
#if (SPC5_CLEAR_FCCU_RGM == TRUE)
  spc_clear_fccu_rgm();
#endif /* SPC5_CLEAR_FCCU_RGM */

  /* The system must be in DRUN mode on entry, if this is not the case then
     it is considered a serious anomaly.*/
  if (MC_ME.GS.B.S_CURRENT_MODE != (uint32_t)SPC5_RUNMODE_DRUN) {
    SPC5_CLOCK_FAILURE_HOOK();
  }

#if (SPC5_XOSC_DISABLED == FALSE)
#if (SPC5_OSC_BYPASS == TRUE)
  /* If the board is equipped with an oscillator instead of a crystal then the
     bypass must be activated.*/
  OSC40M_DIG.CTL.B.OSCBYP = TRUE;
#endif /* SPC5_OSC_BYPASS */
#endif /* !SPC5_XOSC_DISABLED */

  /* set RCDIV filed in CMU control status register to its BAF
     default value */
  CMU_0.CSR.B.RCDIV = 3U;

  /* Setting the system dividers to their final values.*/
  MC_CGM.SC_DC0.R         = SPC5_CGM_SC_DC0_BITS;
  MC_CGM.SC_DC1.R         = SPC5_CGM_SC_DC1_BITS;
  MC_CGM.SC_DC2.R         = SPC5_CGM_SC_DC2_BITS;
  MC_CGM.SC_DC3.R         = SPC5_CGM_SC_DC3_BITS;
  MC_CGM.SC_DC4.R         = SPC5_CGM_SC_DC4_BITS;

  /* Setting the auxiliary dividers to their final values.*/
  MC_CGM.AC0_DC0.R        = SPC5_CGM_AC0_DC0_BITS;
  MC_CGM.AC0_DC1.R        = SPC5_CGM_AC0_DC1_BITS;
  MC_CGM.AC6_DC0.R        = SPC5_CGM_AC6_DC0_BITS;
  MC_CGM.AC8_DC0.R        = SPC5_CGM_AC8_DC0_BITS;
  MC_CGM.AC9_DC0.R        = SPC5_CGM_AC9_DC0_BITS;
  MC_CGM.AC11_DC0.R       = SPC5_CGM_AC11_DC0_BITS;
  MC_CGM.AC12_DC0.R       = SPC5_CGM_AC12_DC0_BITS;
  MC_CGM.AC12_DC1.R       = SPC5_CGM_AC12_DC1_BITS;
  MC_CGM.AC12_DC2.R       = SPC5_CGM_AC12_DC2_BITS;

  /* Setting the clock selectors to their final sources.*/
  MC_CGM.AC0_SC.R         = SPC5_CGM_AC0_SC_BITS;
  MC_CGM.AC3_SC.R         = SPC5_CGM_AC3_SC_BITS;
  MC_CGM.AC4_SC.R         = SPC5_CGM_AC4_SC_BITS;
  RTC_API.RTCC.B.CLKSEL   = SPC5_RTCC_CLKSEL_VALUE;
  MC_CGM.AC6_SC.R         = SPC5_CGM_AC6_SC_BITS;
  MC_CGM.AC8_SC.R         = SPC5_CGM_AC8_SC_BITS;
  MC_CGM.AC9_SC.R         = SPC5_CGM_AC9_SC_BITS;
  MC_CGM.AC11_SC.R        = SPC5_CGM_AC11_SC_BITS;
  MC_CGM.AC12_SC.R        = SPC5_CGM_AC12_SC_BITS;

#if (SPC5_XOSC_DISABLED == FALSE)
  /* Enables the XOSC in order to check its functionality before proceeding
     with the initialization.*/
  MC_ME.DRUN_MC.R         = SPC5_ME_MC_SYSCLK_IRC | SPC5_ME_MC_IRCON |
                            SPC5_ME_MC_XOSCON | SPC5_ME_MC_FLAON_NORMAL |
                            SPC5_ME_MC_MVRON;
  if (SPCSetRunMode(SPC5_RUNMODE_DRUN) == CLOCK_FAILED) {
    SPC5_CLOCK_FAILURE_HOOK();
  }
#endif /* !SPC5_XOSC_DISABLED */

  /* PLLs initialization, the changes will have effect on mode switch.*/
  PLLDIG.PLL0CR.R         = 0U;
  PLLDIG.PLL0DV.R         = SPC5_PLL0_DV_RFDPHI1(SPC5_PLL0_RFDPHI1_VALUE) |
                            SPC5_PLL0_DV_RFDPHI(SPC5_PLL0_RFDPHI_VALUE) |
                            SPC5_PLL0_DV_PREDIV(SPC5_PLL0_PREDIV_VALUE) |
                            SPC5_PLL0_DV_MFD(SPC5_PLL0_MFD_VALUE);
  PLLDIG.PLL1CR.R         = 0U;
  PLLDIG.PLL1DV.R         = SPC5_PLL1_DV_RFDPHI(SPC5_PLL1_RFDPHI_VALUE) |
                            SPC5_PLL1_DV_MFD(SPC5_PLL1_MFD_VALUE);

  /* Run modes initialization, note writes to the MC registers are verified
     by a protection mechanism, the operation success is verified at the
     end of the sequence.*/
  MC_ME.IS.R              = 8U;                     /* Resetting I_ICONF status.*/
  MC_ME.ME.R              = SPC5_ME_ME_BITS;
  MC_ME.SAFE_MC.R         = SPC5_ME_SAFE_MC_BITS;
  MC_ME.DRUN_MC.R         = SPC5_ME_DRUN_MC_BITS;
  MC_ME.RUN_MC[0].R       = SPC5_ME_RUN0_MC_BITS;
  MC_ME.RUN_MC[1].R       = SPC5_ME_RUN1_MC_BITS;
  MC_ME.RUN_MC[2].R       = SPC5_ME_RUN2_MC_BITS;
  MC_ME.RUN_MC[3].R       = SPC5_ME_RUN3_MC_BITS;
  MC_ME.HALT0_MC.R        = SPC5_ME_HALT0_MC_BITS;
  MC_ME.STOP0_MC.R        = SPC5_ME_STOP0_MC_BITS;
  MC_ME.STANDBY0_MC.R     = SPC5_ME_STANDBY0_MC_BITS;
  if ((MC_ME.IS.B.I_ICONF & 1U) == 1U) {
    /* Configuration rejected.*/
    SPC5_CLOCK_FAILURE_HOOK();
  }

  /* Peripherals run and low power modes initialization.*/
  MC_ME.RUN_PC[0].R       = SPC5_ME_RUN_PC0_BITS;
  MC_ME.RUN_PC[1].R       = SPC5_ME_RUN_PC1_BITS;
  MC_ME.RUN_PC[2].R       = SPC5_ME_RUN_PC2_BITS;
  MC_ME.RUN_PC[3].R       = SPC5_ME_RUN_PC3_BITS;
  MC_ME.RUN_PC[4].R       = SPC5_ME_RUN_PC4_BITS;
  MC_ME.RUN_PC[5].R       = SPC5_ME_RUN_PC5_BITS;
  MC_ME.RUN_PC[6].R       = SPC5_ME_RUN_PC6_BITS;
  MC_ME.RUN_PC[7].R       = SPC5_ME_RUN_PC7_BITS;
  MC_ME.LP_PC[0].R        = SPC5_ME_LP_PC0_BITS;
  MC_ME.LP_PC[1].R        = SPC5_ME_LP_PC1_BITS;
  MC_ME.LP_PC[2].R        = SPC5_ME_LP_PC2_BITS;
  MC_ME.LP_PC[3].R        = SPC5_ME_LP_PC3_BITS;
  MC_ME.LP_PC[4].R        = SPC5_ME_LP_PC4_BITS;
  MC_ME.LP_PC[5].R        = SPC5_ME_LP_PC5_BITS;
  MC_ME.LP_PC[6].R        = SPC5_ME_LP_PC6_BITS;
  MC_ME.LP_PC[7].R        = SPC5_ME_LP_PC7_BITS;

  /* PFLASH Controller settings.*/
  SPCSetPFlashController(SPC5_XBAR_CLK);

  /* Switches again to DRUN mode (current mode) in order to update the
     settings.*/
  if (SPCSetRunMode(SPC5_RUNMODE_DRUN) == CLOCK_FAILED) {
    SPC5_CLOCK_FAILURE_HOOK();
  }

#endif /* !SPC5_NO_INIT */
}

/**
 * @brief   Early initialization code.
 * @note    This initialization must be performed just after stack setup and
 *          before any other initialization.
 *
 * @special
 */
void __early_init(void) {

  spc_clock_init();
}

/**
 * @brief   Switches the system to the specified run mode.
 *
 * @param[in] mode      one of the possible run modes
 *
 * @return              The operation status.
 * @retval CLOCK_SUCCESS if the switch operation has been completed.
 * @retval CLOCK_FAILED  if the switch operation failed.
 */
uint8_t SPCSetRunMode(uint8_t mode) {

  /* Clearing status register bits */
  MC_ME.IS.R = 0x3FU;

  /* Starts a transition process.*/
  MC_ME.MCTL.R = SPC5_ME_MCTL_MODE(mode) | SPC5_ME_MCTL_KEY;
  MC_ME.MCTL.R = SPC5_ME_MCTL_MODE(mode) | SPC5_ME_MCTL_KEY_INV;

  /* Waits for the mode switch or an error condition.*/
  while (MC_ME.IS.R == 0U) {
    ;
  }
  /* Check if no error during mode switch */
  if (MC_ME.IS.B.I_MTC == 1U) {
    return CLOCK_SUCCESS;
  } else {
    return CLOCK_FAILED;
  }
}

/**
 * @brief   Changes the clock mode of a peripheral.
 *
 * @param[in] n         index of the @p PCTL register
 * @param[in] pctl      new value for the @p PCTL register
 *
 * @notapi
 */
void SPCSetPeripheralClockMode(uint32_t n, uint32_t pctl) {
  uint8_t mode;

  MC_ME.PCTL[n].R = (uint8_t)pctl;
  mode = (uint8_t)MC_ME.MCTL.B.TARGET_MODE;
  if(SPCSetRunMode(mode) == CLOCK_FAILED) {
    SPC5_CLOCK_FAILURE_HOOK();
  }
}

#if (SPC5_NO_INIT == FALSE) || defined(__DOXYGEN__)
/**
 * @brief   Returns the system clock under the current run mode.
 *
 * @return              The system clock in Hertz.
 */
uint32_t SPCGetSystemClock(void) {
  uint32_t sysclk;
  uint32_t sc_dc0_div;

  if (MC_CGM.SC_DC0.B.DE == 0U) {
    sc_dc0_div = 1UL;
  } else {
    sc_dc0_div = (MC_CGM.SC_DC0.B.DIV + 1UL);
  }

  sysclk = MC_ME.GS.B.S_SYSCLK;
  switch (sysclk) {
  case SPC5_ME_GS_SYSCLK_IRC:
    return SPC5_IRC_CLK / sc_dc0_div;
  case SPC5_ME_GS_SYSCLK_XOSC:
    return SPC5_XOSC_CLK / sc_dc0_div;
  case SPC5_ME_GS_SYSCLK_PLL0PHI:
    return SPC5_PLL0_PHI_CLK / sc_dc0_div;
  case SPC5_ME_GS_SYSCLK_PLL1PHI:
    return SPC5_PLL1_PHI_CLK / sc_dc0_div;
  default:
    return 0;
  }
}
#endif /* !SPC5_NO_INIT */

/** @} */

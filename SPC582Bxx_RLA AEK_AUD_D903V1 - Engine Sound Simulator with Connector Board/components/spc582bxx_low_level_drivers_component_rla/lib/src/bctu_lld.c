/****************************************************************************
*
* Copyright © 2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    bctu_lld.c
 * @brief   SPC5xx BCTU low level driver code.
 *
 * @addtogroup BCTU
 * @{
 */

#include "bctu_lld.h"

#if (LLD_USE_BCTU == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   BCTU driver identifier.
 */
BCTUDriver BCTUD1;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level BCTU driver initialization.
 *
 * @init
 */
void bctu_lld_init(void) {

  BCTUD1.bctup = &SPC5_BCTU;

#if (SPC5_BCTU_USE_EMIOS0_TRIGGER == TRUE)
  BCTUD1.emiosp0 = &SPC5_EMIOS_0;
#endif /* SPC5_BCTU_USE_EMIOS0_TRIGGER */
#if (SPC5_BCTU_USE_EMIOS1_TRIGGER == TRUE)
  BCTUD1.emiosp1 = &SPC5_EMIOS_1;
#endif /* SPC5_BCTU_USE_EMIOS1_TRIGGER */
#if (SPC5_BCTU_USE_EMIOS2_TRIGGER == TRUE)
  BCTUD1.emiosp2 = &SPC5_EMIOS_2;
#endif /* SPC5_BCTU_USE_EMIOS2_TRIGGER */

  BCTUD1.saradcp = &SPC5_SARADC12_SV;
}

/**
 * @brief   Low level BCTU driver configuration and start.
 *
 * @param[in] bctudp    pointer to a @p BCTUDriver object
 * @param[in] config    the architecture-dependent BCTU driver configuration.
 *
 * @api
 */
void bctu_lld_start(BCTUDriver *bctudp, BCTUConfig *config) {

  uint8_t i;
  uint8_t reg_index, bit_index;

  /* Setup the BCTU configuration.*/
  bctudp->config = config;

  /* Enable BCTU Clock.*/
  SPCSetPeripheralClockMode(SPC5_BCTU_PCTL, SPC5_BCTU_START_PCTL);

  /* If the eMIOS is used as trigger, eMIOS clocks are enabled in order to
     configure the eMIOS registers even if the eMIOS low level driver is 
	 disabled.*/
#if (SPC5_BCTU_USE_EMIOS0_TRIGGER == TRUE)
  SPCSetPeripheralClockMode(SPC5_EMIOS0_PCTL, SPC5_EMIOS0_START_PCTL);
#endif /* SPC5_BCTU_USE_EMIOS0_TRIGGER */

#if (SPC5_BCTU_USE_EMIOS1_TRIGGER == TRUE)
  SPCSetPeripheralClockMode(SPC5_EMIOS1_PCTL, SPC5_EMIOS1_START_PCTL);
#endif /* SPC5_BCTU_USE_EMIOS1_TRIGGER */

#if (SPC5_BCTU_USE_EMIOS2_TRIGGER == TRUE)
  SPCSetPeripheralClockMode(SPC5_EMIOS2_PCTL, SPC5_EMIOS2_START_PCTL);
#endif /* SPC5_BCTU_USE_EMIOS2_TRIGGER */

  /* Setup BTCU triggers.*/
  for(i = 0U; i < SPC5_BCTU_TRIGGER_NUMBER; i++) {
    if(bctudp->config->trigger[i] != NULL) {
      switch(bctudp->config->trigger[i]->source) {
        case SPC5_BCTU_TRIGGER_SRC_EMIOS0:
#if (SPC5_BCTU_USE_EMIOS0_TRIGGER == TRUE)
          bctudp->emiosp0->CH[i].C.B.DMA = 1;    /* Enable DMA/CTU triggering */
          bctudp->emiosp0->CH[i].C.B.FEN = 1;    /* Enable flag               */
#endif /* SPC5_BCTU_USE_EMIOS0_TRIGGER */
          break;
        case SPC5_BCTU_TRIGGER_SRC_EMIOS1:
#if (SPC5_BCTU_USE_EMIOS1_TRIGGER == TRUE)
          bctudp->emiosp1->CH[i%32].C.B.DMA = 1; /* Enable DMA/CTU triggering */
          bctudp->emiosp1->CH[i%32].C.B.FEN = 1; /* Enable flag               */
#endif /* SPC5_BCTU_USE_EMIOS1_TRIGGER */
          break;
        case SPC5_BCTU_TRIGGER_SRC_EMIOS2:
#if (SPC5_BCTU_USE_EMIOS2_TRIGGER == TRUE)
          bctudp->emiosp2->CH[i%32].C.B.DMA = 1; /* Enable DMA/CTU triggering */
          bctudp->emiosp2->CH[i%32].C.B.FEN = 1; /* Enable flag               */
#endif /* SPC5_BCTU_USE_EMIOS2_TRIGGER */
          break;
        case SPC5_BCTU_TRIGGER_SRC_PIT0:
        case SPC5_BCTU_TRIGGER_SRC_PIT1:
        default:
          /* Dummy comment for MISRA check.*/
          break;
      }
    }
  }

  /* SARADC SV clock is enabled in order to configure the SARADC SV registers
     for the conversion via BCTU even if the SARADC low level driver is disabled.*/
  SPCSetPeripheralClockMode(SPC5_SARADC12_SV_PCTL, SPC5_SARADC12_SV_START_PCTL);

  /* Set SARADC SV is in normal mode.*/
  bctudp->saradcp->MCR.B.PWDN = 0U;
  /* Enable triggered injected conversion via BCTU in SARADC SV.*/
  bctudp->saradcp->MCR.B.CTUEN = 1U;
  bctudp->saradcp->MCR.B.CTU_MODE = 0U;

  /* Setup SARADC SV injected channels.*/
  for(i = 0U; i < SPC5_BCTU_TRIGGER_NUMBER; i++) {
    if(bctudp->config->trigger[i] != NULL) {
      reg_index = (uint8_t)(bctudp->config->trigger[i]->channel / 32U);
      bit_index = (uint8_t)(bctudp->config->trigger[i]->channel % 32U);
	  bctudp->saradcp->ICJCMR[reg_index].R |= (1UL << bit_index);
    }
  }

  /* Setup BCTU.*/
  for(i = 0U; i < SPC5_BCTU_TRIGGER_NUMBER; i++) {
    if(bctudp->config->trigger[i] != NULL) {
      bctudp->bctup->EVTCFGR[i].B.TM = 0x1U;
      bctudp->bctup->EVTCFGR[i].B.CHANNEL_VALUE = bctudp->config->trigger[i]->channel;
    }
  }
}

/**
 * @brief   Return the BCTU trigger interrupt flag.
 *
 * @param[in] bctudp    pointer to the @p BCTUDriver object
 *
 * @return              1 if a trigger output request is occurred, 0 otherwise
 *
 * @api
 */
uint8_t bctu_lld_get_trigger_int_flag(BCTUDriver *bctudp) {

  return (uint8_t)bctudp->bctup->CSR.B.TRGI;
}

/**
 * @brief   Clear the BCTU trigger interrupt flag.
 *
 * @param[in] bctudp    pointer to the @p BCTUDriver object
 *
 * @api
 */
void bctu_clear_trigger_int_flag(BCTUDriver *bctudp) {

  bctudp->bctup->CSR.B.TRGI = 0x1U;
}

/**
 * @brief   Deactivates the BCTU peripheral.
 *
 * @param[in] bctudp    pointer to the @p BCTUDriver object
 *
 * @api
 */
void bctu_lld_stop(BCTUDriver *bctudp) {

  uint8_t i;

  /* Disable all BCTU triggers previously enabled.*/
  for(i = 0U; i < SPC5_BCTU_TRIGGER_NUMBER; i++) {
    if(bctudp->config->trigger[i] != NULL) {
      bctudp->bctup->EVTCFGR[i].B.TM = 0x0U;
    }
  }

  /* Disable BCTU Clock.*/
  SPCSetPeripheralClockMode(SPC5_BCTU_PCTL, SPC5_BCTU_STOP_PCTL);
}

#endif /* LLD_USE_FCCU */

/** @} */

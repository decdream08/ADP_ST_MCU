/****************************************************************************
*
* Copyright © 2017-2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    swt_lld.c
 * @brief   SPC5xx SWT low level driver code.
 *
 * @addtogroup SWT
 * @{
 */

#include "swt_lld.h"

#if (LLD_USE_SWT == TRUE) || defined(__DOXYGEN__)
	
#include "swt_lld_cfg.h"

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   SWT0 driver identifier.
 */
#if (SPC5_SWT_USE_SWT0 == TRUE) || defined(__DOXYGEN__)
SWTDriver SWTD1;
#endif

/**
 * @brief   SWT1 driver identifier.
 */
#if (SPC5_SWT_USE_SWT1 == TRUE) || defined(__DOXYGEN__)
SWTDriver SWTD2;
#endif

/**
 * @brief   SWT2 driver identifier.
 */
#if (SPC5_SWT_USE_SWT2 == TRUE) || defined(__DOXYGEN__)
SWTDriver SWTD3;
#endif

/**
 * @brief   SWT3 driver identifier.
 */
#if (SPC5_SWT_USE_SWT3 == TRUE) || defined(__DOXYGEN__)
SWTDriver SWTD4;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*
 * Service keys
 */
#define SWT_SERVICE_KEY_1   0xA602
#define SWT_SERVICE_KEY_2   0xB480

/*
 * Unlock keys
 */
#define SWT_UNLOCK_KEY_1    0xC520
#define SWT_UNLOCK_KEY_2    0xD928


/*
 * Converts a period (milliseconds) to ticks
 */
#define SWT_PERIOD_TO_TICKS(__frequency__, __period__) \
		((__frequency__ / 1000U) * __period__)

/*
 * Pseudo random generated keys
 *
 * SKn+1 = ((17 * SKn) + 3) mod 2^16
 */
#define NEW_SERVICE_KEY(__old_key__) \
		((((17U * ((uint32_t)(__old_key__))) + 3U)) & 0xFFFFU)


#if (SPC5_HAS_FCCU == TRUE)
/**
 * @brief   Enable in the FCCU the reset for a specified SWT.
 *
 * @param[in] swt_fccu_ch    FCCU channel related to the SWT
 *
 * @notapi
 */
static void swt_lld_enable_reset(uint32_t swt_fccu_ch)
{
  /* Pointer to the FCCU registers block.*/
  volatile struct spc5_fccu_tag *fccup = SPC5_FCCU_TAG;

#ifndef SPC5_SWT_NOTRANS_LOCK
  /* FCCU transiently unlock.*/
  fccup->TRANS_LOCK.B.TRANSKEY = 0xBC;
#endif

  /* Move FCCU into CONFIG state.*/
  fccup->CTRLK.R = 0x913756AFUL;
  fccup->CTRL.R = 1U;
  while (fccup->CTRL.B.OPS != 3U) {
    ;
  }

  /* Setup recoverable fault state configuration related to SWT.*/
  fccup->RFS_CFG[(swt_fccu_ch / 16U)].R &= (~(3UL << (2U * (swt_fccu_ch % 16U))));
  fccup->RFS_CFG[(swt_fccu_ch / 16U)].R |= (2UL << (2U * (swt_fccu_ch % 16U)));

  /* Enable recoverable fault related to SWT.*/
  fccup->RF_E[(swt_fccu_ch / 32U)].R |= 1UL << (swt_fccu_ch % 32U);

  /* Move back FCCU into NORMAL state.*/
  fccup->CTRLK.R = 0x825A132BUL;
  fccup->CTRL.R = 2UL;
  while (fccup->CTRL.B.OPS != 3U) {
    ;
  }
}
#endif /* SPC5_HAS_FCCU */

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if ((SPC5_SWT0_INTERRUPT_MODE == TRUE) || (SPC5_SWT1_INTERRUPT_MODE == TRUE) || (SPC5_SWT2_INTERRUPT_MODE == TRUE) || (SPC5_SWT3_INTERRUPT_MODE == TRUE))

static void swt_interrupt_handler(SWTDriver *swtp)
{
  /* Acknowledge the interrupt, no bit field access on TIF */
  swtp->swtp->IR.R = 1;

  /* call the callback, if set */
  if (swtp->swt_config->callback != NULL) {
    swtp->swt_config->callback(swtp);
  }
}
#endif

#if ((SPC5_SWT_USE_SWT0 == TRUE) && (SPC5_SWT0_INTERRUPT_MODE == TRUE)) || defined(__DOXYGEN__)
/**
 * @brief   SWT0 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_SWT0_HANDLER) {
  IRQ_PROLOGUE();

  swt_interrupt_handler(&SWTD1);

  IRQ_EPILOGUE();
}
#endif

#if ((SPC5_SWT_USE_SWT1 == TRUE) && (SPC5_SWT1_INTERRUPT_MODE == TRUE)) || defined(__DOXYGEN__)
/**
 * @brief   SWT1 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_SWT1_HANDLER) {
  IRQ_PROLOGUE();

  swt_interrupt_handler(&SWTD2);

  IRQ_EPILOGUE();
}
#endif

#if ((SPC5_SWT_USE_SWT2 == TRUE) && (SPC5_SWT2_INTERRUPT_MODE == TRUE)) || defined(__DOXYGEN__)
/**
 * @brief   SWT2 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_SWT2_HANDLER) {
  IRQ_PROLOGUE();

  swt_interrupt_handler(&SWTD3);

  IRQ_EPILOGUE();
}
#endif

#if ((SPC5_SWT_USE_SWT3 == TRUE) && (SPC5_SWT3_INTERRUPT_MODE == TRUE)) || defined(__DOXYGEN__)
/**
 * @brief   SWT3 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_SWT3_HANDLER) {
  IRQ_PROLOGUE();

  swt_interrupt_handler(&SWTD4);

  IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level swt driver initialisation.
 *
 * @init
 */
void swt_lld_init(void) {

#if (SPC5_SWT_USE_SWT0 == TRUE)
  SWTD1.swtp = SPC5_SWT0;

#if (SPC5_HAS_FCCU == TRUE)
  /* If the FCCU is present, only the reset related to SWT2 is enabled by
     default. The reset of the other SWTs have to be enabled in the FCCU.*/
  swt_lld_enable_reset(SPC5_SWT0_FCCU_CHANNEL);
#endif

  /* running frequency */
  SWTD1.swt_freq = SPC5_SWT0_FREQUENCY;

  /* clear the software lock bit */
  SWTD1.swtp->SR.R = SWT_UNLOCK_KEY_1;
  SWTD1.swtp->SR.R = SWT_UNLOCK_KEY_2;

  /* even not used, set MAPs to 1 */
  SWTD1.swtp->CR.R = 0xFF000000U;

#if (SPC5_SWT0_PSEUDO_RANDOM_KEY == TRUE)
  SWTD1.swtp->CR.B.KEY = 1;
#endif

#if (SPC5_SWT0_SYSTEM_RESET == TRUE)
  SWTD1.swtp->CR.B.RIA = 1;
#endif

#if (SPC5_SWT0_WINDOW_MODE == TRUE)
  SWTD1.swtp->CR.B.WND = 1;
#endif

#if (SPC5_SWT0_INTERRUPT_MODE == TRUE)
  SWTD1.swtp->CR.B.ITR = 1;

  INTC_PSR(SPC5_SWT0_INT_NUMBER) = SPC5_SWT0_IRQ_PRIORITY;
#endif

#if (SPC5_SWT0_CLOCK_SOURCE_OSC == TRUE)
  SWTD1.swtp->CR.B.CSL = 1;
#endif

#if (SPC5_SWT0_STOP_IN_STOP_MODE == TRUE)
  SWTD1.swtp->CR.B.STP = 1;
#endif

#if (SPC5_SWT0_FREEZE_IN_DEBUG_MODE == TRUE)
  SWTD1.swtp->CR.B.FRZ = 1;
#endif
#endif /* SPC5_SWT_USE_SWT0 */


#if (SPC5_SWT_USE_SWT1 == TRUE)
  SWTD2.swtp = SPC5_SWT1;

#if (SPC5_HAS_FCCU == TRUE)
  /* If the FCCU is present, only the reset related to SWT2 is enabled by
     default. The reset of the other SWTs have to be enabled in the FCCU.*/
  swt_lld_enable_reset(SPC5_SWT1_FCCU_CHANNEL);
#endif

  /* running frequency */
  SWTD2.swt_freq = SPC5_SWT1_FREQUENCY;

  /* clear the software lock bit */
  SWTD2.swtp->SR.R = SWT_UNLOCK_KEY_1;
  SWTD2.swtp->SR.R = SWT_UNLOCK_KEY_2;

  /* even not used, set MAPs to 1 */
  SWTD2.swtp->CR.R = 0xFF000000U;

#if (SPC5_SWT1_PSEUDO_RANDOM_KEY == TRUE)
  SWTD2.swtp->CR.B.KEY = 1;
#endif

#if (SPC5_SWT1_SYSTEM_RESET == TRUE)
  SWTD2.swtp->CR.B.RIA = 1;
#endif

#if (SPC5_SWT1_WINDOW_MODE == TRUE)
  SWTD2.swtp->CR.B.WND = 1;
#endif

#if (SPC5_SWT1_INTERRUPT_MODE == TRUE)
  SWTD2.swtp->CR.B.ITR = 1;

  INTC_PSR(SPC5_SWT1_INT_NUMBER) = SPC5_SWT1_IRQ_PRIORITY;
#endif

#if (SPC5_SWT1_CLOCK_SOURCE_OSC == TRUE)
  SWTD2.swtp->CR.B.CSL = 1;
#endif

#if (SPC5_SWT1_STOP_IN_STOP_MODE == TRUE)
  SWTD2.swtp->CR.B.STP = 1;
#endif

#if (SPC5_SWT1_FREEZE_IN_DEBUG_MODE == TRUE)
  SWTD2.swtp->CR.B.FRZ = 1;
#endif
#endif /* SPC5_SWT_USE_SWT1 */


#if (SPC5_SWT_USE_SWT2 == TRUE)
  SWTD3.swtp = SPC5_SWT2;

#if (SPC5_HAS_FCCU == TRUE)
  /* If the FCCU is present, only the reset related to SWT2 is enabled by
     default. The reset of the other SWTs have to be enabled in the FCCU.*/
  swt_lld_enable_reset(SPC5_SWT2_FCCU_CHANNEL);
#endif

  /* running frequency */
  SWTD3.swt_freq = SPC5_SWT2_FREQUENCY;

  /* clear the software lock bit */
  SWTD3.swtp->SR.R = SWT_UNLOCK_KEY_1;
  SWTD3.swtp->SR.R = SWT_UNLOCK_KEY_2;

  /* even not used, set MAPs to 1 */
  SWTD3.swtp->CR.R = 0xFF000000U;

#if (SPC5_SWT2_PSEUDO_RANDOM_KEY == TRUE)
  SWTD3.swtp->CR.B.KEY = 1;
#endif

#if (SPC5_SWT2_SYSTEM_RESET == TRUE)
  SWTD3.swtp->CR.B.RIA = 1;
#endif

#if (SPC5_SWT2_WINDOW_MODE == TRUE)
  SWTD3.swtp->CR.B.WND = 1;
#endif

#if (SPC5_SWT2_INTERRUPT_MODE == TRUE)
  SWTD3.swtp->CR.B.ITR = 1;

  INTC_PSR(SPC5_SWT2_INT_NUMBER) = SPC5_SWT2_IRQ_PRIORITY;
#endif

#if (SPC5_SWT2_CLOCK_SOURCE_OSC == TRUE)
  SWTD3.swtp->CR.B.CSL = 1;
#endif

#if (SPC5_SWT2_STOP_IN_STOP_MODE == TRUE)
  SWTD3.swtp->CR.B.STP = 1;
#endif

#if (SPC5_SWT2_FREEZE_IN_DEBUG_MODE == TRUE)
  SWTD3.swtp->CR.B.FRZ = 1;
#endif
#endif /* SPC5_SWT_USE_SWT2 */


#if (SPC5_SWT_USE_SWT3 == TRUE)
  SWTD4.swtp = SPC5_SWT3;

#if (SPC5_HAS_FCCU == TRUE)
  /* If the FCCU is present, only the reset related to SWT2 is enabled by
     default. The reset of the other SWTs have to be enabled in the FCCU.*/
  swt_lld_enable_reset(SPC5_SWT3_FCCU_CHANNEL);
#endif

  /* running frequency */
  SWTD4.swt_freq = SPC5_SWT3_FREQUENCY;

  /* clear the software lock bit */
  SWTD4.swtp->SR.R = SWT_UNLOCK_KEY_1;
  SWTD4.swtp->SR.R = SWT_UNLOCK_KEY_2;

  /* even not used, set MAPs to 1 */
  SWTD4.swtp->CR.R = 0xFF000000U;

#if (SPC5_SWT3_PSEUDO_RANDOM_KEY == TRUE)
  SWTD4.swtp->CR.B.KEY = 1;
#endif

#if (SPC5_SWT3_SYSTEM_RESET == TRUE)
  SWTD4.swtp->CR.B.RIA = 1;
#endif

#if (SPC5_SWT3_WINDOW_MODE == TRUE)
  SWTD4.swtp->CR.B.WND = 1;
#endif

#if (SPC5_SWT3_INTERRUPT_MODE == TRUE)
  SWTD4.swtp->CR.B.ITR = 1;

  INTC_PSR(SPC5_SWT3_INT_NUMBER) = SPC5_SWT3_IRQ_PRIORITY;
#endif

#if (SPC5_SWT3_CLOCK_SOURCE_OSC == TRUE)
  SWTD4.swtp->CR.B.CSL = 1;
#endif

#if (SPC5_SWT3_STOP_IN_STOP_MODE == TRUE)
  SWTD4.swtp->CR.B.STP = 1;
#endif

#if (SPC5_SWT3_FREEZE_IN_DEBUG_MODE == TRUE)
  SWTD4.swtp->CR.B.FRZ = 1;
#endif
#endif /* SPC5_SWT_USE_SWT3 */
}

/**
 * @brief   Activate and configure SWT peripheral
 *
 * @param[in] swtd      pointer to the @p SWTDriver object
 * @param[in] config	pointer to the  @p SWT_Config object
 *
 * @api
 */
void swt_lld_start (SWTDriver *swtd, SWT_Config *config) {

  /* set driver configuration */
  swtd->swt_config = config;

  /* clear the software lock bit */
  swtd->swtp->SR.R = SWT_UNLOCK_KEY_1;
  swtd->swtp->SR.R = SWT_UNLOCK_KEY_2;

  /* set timeout period. */
  swtd->swtp->TO.R = SWT_PERIOD_TO_TICKS(swtd->swt_freq, config->timeout_period);

  /* set the window period */
  if (swtd->swtp->CR.B.WND == 1U) {
    swtd->swtp->WN.B.WST = SWT_PERIOD_TO_TICKS(swtd->swt_freq, config->window_period);
  }

  /* SWT enabled. */
  swtd->swtp->CR.B.WEN = 1;
}


/**
 * @brief   Execute the watchdog servicing sequence
 *
 * @param[in] swtd      pointer to the @p SWTDriver object
 *
 * @api
 */
void swt_lld_keep_alive (SWTDriver *swtd) {

  if (swtd->swtp->CR.B.KEY == 1U) {

    uint32_t old_serv_key;
    uint32_t serv_key;

    /* get old key */
    old_serv_key = swtd->swtp->SK.R;

    /* calculate new key #1 */
    serv_key = NEW_SERVICE_KEY(old_serv_key);
    swtd->swtp->SR.R = serv_key;

    /* calculate new key #2 */
    serv_key = NEW_SERVICE_KEY(serv_key);
    swtd->swtp->SR.R = serv_key;
  } else {
    swtd->swtp->SR.R = SWT_SERVICE_KEY_1;
    swtd->swtp->SR.R = SWT_SERVICE_KEY_2;
  }
}


/**
 * @brief   Stop the SWT peripheral
 *
 * @param[in] swtd      pointer to the @p SWTDriver object
 *
 * @api
 */
void swt_lld_stop (SWTDriver *swtd) {

  /* clear the software lock bit */
  swtd->swtp->SR.R = SWT_UNLOCK_KEY_1;
  swtd->swtp->SR.R = SWT_UNLOCK_KEY_2;

  swtd->swtp->CR.B.WEN = 0;

  swtd->swt_config = NULL;
}
#endif /* LLD_USE_SWT */

/** @} */

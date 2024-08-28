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
 * @file    rtc_lld.c
 * @brief   SPC5xx RTC/API low level driver code.
 *
 * @addtogroup RTC
 * @{
 */

#include "rtc_lld.h"

#if (LLD_USE_RTC == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   RTC/API driver identifier.
 */
RTCDriver RTCD1;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Common RTC IRQ handler.
 *
 * @param[in] rtcdp     pointer to a @p RTCDriver object
 */
static void spc5xx_serve_rtc_interrupt(RTCDriver *rtcdp) {

  /* Check if RTC interrupt is occurred.*/
  if (rtcdp->rtc_tagp->RTCS.B.RTCF == 1U) {
    /* Invoke RTC interrupt callback function.*/
    if ((rtcdp->rtc_config->rtcInt == TRUE) && (rtcdp->rtc_config->rtcClbk != NULL)) {
      rtcdp->rtc_config->rtcClbk(rtcdp);
    }
    /* Clear RTC Interrupt Flag.*/
    rtcdp->rtc_tagp->RTCS.B.RTCF = 1U;
  }

  /* Check if Counter Roll Over interrupt is occurred.*/
  if (rtcdp->rtc_tagp->RTCS.B.ROVRF == 1U) {
    /* Invoke Counter Roll Over interrupt callback function.*/
    if ((rtcdp->rtc_config->rolloverInt == TRUE) && (rtcdp->rtc_config->rolloverClbk != NULL)) {
      rtcdp->rtc_config->rolloverClbk(rtcdp);
    }
    /* Clear Counter Roll Over Interrupt Flag.*/
    rtcdp->rtc_tagp->RTCS.B.ROVRF = 1U;
  }
}

/**
 * @brief   Common API IRQ handler.
 *
 * @param[in] rtcdp     pointer to a @p RTCDriver object
 */
static void spc5xx_serve_api_interrupt(RTCDriver *rtcdp) {

  /* Disable Autonomous Periodic Interrupt.*/
  rtcdp->rtc_tagp->RTCC.B.APIEN = 0U;

  /* Check if API interrupt is occurred.*/
  if (rtcdp->rtc_tagp->RTCS.B.APIF == 1U) {
    /* Invoke API interrupt callback function.*/
    if ((rtcdp->rtc_config->apiInt == TRUE) && (rtcdp->rtc_config->apiClbk != NULL)) {
      rtcdp->rtc_config->apiClbk(rtcdp);
    }
    /* Clear API Interrupt Flag.*/
    rtcdp->rtc_tagp->RTCS.B.APIF = 1U;
  }

  /* Enable Autonomous Periodic Interrupt.*/
  rtcdp->rtc_tagp->RTCC.B.APIEN = 1U;

}
/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/**
 * @brief   RTC interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SCP5_RTC_RTC_HANDLER) {
  IRQ_PROLOGUE();

  spc5xx_serve_rtc_interrupt(&RTCD1)

  IRQ_EPILOGUE();
}

/**
 * @brief   API interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SCP5_RTC_API_HANDLER) {
  IRQ_PROLOGUE();

  spc5xx_serve_api_interrupt(&RTCD1)

  IRQ_EPILOGUE();
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level RTC/API driver initialization.
 *
 * @init
 */
void rtc_lld_init(void) {

  RTCD1.rtc_tagp = &RTC_API;

  INTC_PSR(SCP5_RTC_RTC_INT_NUMBER) = SCP5_RTC_RTC_IRQ_PRIORITY;
  INTC_PSR(SCP5_RTC_API_INT_NUMBER) = SCP5_RTC_API_IRQ_PRIORITY;

  /* Disable RTC.*/
  RTCD1.rtc_tagp->RTCC.B.CNTEN = 0U;

  /* Clear RTC Interrupt Flag.*/
  RTCD1.rtc_tagp->RTCS.B.RTCF = 1U;

  /* Clear Counter Roll Over Interrupt Flag.*/
  RTCD1.rtc_tagp->RTCS.B.ROVRF = 1U;

  /* Clear API Interrupt Flag.*/
  RTCD1.rtc_tagp->RTCS.B.APIF = 1U;
}

/**
 * @brief   Low level RTC/API driver configuration and start.
 *
 * @param[in] rtcdp     pointer to a @p RTCDriver object
 * @param[in] rtc_cfg   the architecture-dependent RTC/API driver configuration.
 *
 * @api
 */
void rtc_lld_start (RTCDriver *rtcdp, RTCConfig *rtc_cfg) {

  rtcdp->rtc_config = rtc_cfg;

  /* Set 32 Clock Divider.*/
  rtcdp->rtc_tagp->RTCC.B.DIV32EN  = rtcdp->rtc_config->rtcPrescaler32;
  /* Set 512 Clock Divider.*/
  rtcdp->rtc_tagp->RTCC.B.DIV512EN = rtcdp->rtc_config->rtcPrescaler512;

  /* Set Freeze in debug mode.*/
  rtcdp->rtc_tagp->RTCC.B.FRZEN = rtcdp->rtc_config->rtcFreezeEn;

  /* Enable RTC Interrupt request.*/
  if (rtcdp->rtc_config->rtcInt == TRUE) {
    rtcdp->rtc_tagp->RTCC.B.RTCIE = 1U;
    /* Set RTC Compare Value.*/
    rtcdp->rtc_tagp->RTCVAL.R = rtcdp->rtc_config->rtcCompareValue;
  }

  /* Enable RTC Roll Over Interrupt request.*/
  if ((rtcdp->rtc_config->rtcInt == TRUE) && (rtcdp->rtc_config->rolloverInt == TRUE)) {
    rtcdp->rtc_tagp->RTCC.B.ROVREN = 1U;
  }

  /* Enable Autonomous Periodic Interrupt request.*/
  if (rtcdp->rtc_config->apiInt == TRUE) {
    rtcdp->rtc_tagp->RTCC.B.APIIE = 1U;
    rtcdp->rtc_tagp->RTCC.B.APIEN = 1U;
    /* Set API Compare Value.*/
    rtcdp->rtc_tagp->APIVAL.R = rtcdp->rtc_config->apiCompareValue;
  }

  /* Enable RTC.*/
  rtcdp->rtc_tagp->RTCC.B.CNTEN = 1U;
}

/**
 * @brief   Low level RTC/API driver stop.
 *
 * @param[in] rtcdp     pointer to a @p RTCDriver object
 *
 * @api
 */
void rtc_lld_stop (RTCDriver *rtcdp) {

  /* Disable RTC.*/
  rtcdp->rtc_tagp->RTCC.B.CNTEN = 0U;
}

#endif /* LLD_USE_RTC */

/** @} */

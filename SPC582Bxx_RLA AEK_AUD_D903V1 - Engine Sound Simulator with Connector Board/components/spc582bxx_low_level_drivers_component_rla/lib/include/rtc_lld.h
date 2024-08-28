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
 * @file    rtc_lld.h
 * @brief   SPC5xx RTC/API low level driver header.
 *
 * @addtogroup RTC
 * @{
 */

#ifndef _RTC_LLD_H_
#define _RTC_LLD_H_

#include "spc5_lld.h"
#include "lldconf.h"

#if (LLD_USE_RTC == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   RTC IRQ priority.
 */
#if !defined(SCP5_RTC_RTC_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SCP5_RTC_RTC_IRQ_PRIORITY           INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 15)
#endif

/**
 * @brief   API IRQ priority.
 */
#if !defined(SCP5_RTC_API_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SCP5_RTC_API_IRQ_PRIORITY           INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 15)
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief Type of a structure representing an RTC/API driver.
 */
typedef struct RTCDriver RTCDriver;

/**
 * @brief   RTC/API notification callback type.
 *
 * @param[in] rtcdp     pointer to the @p RTCDriver object triggering the
 *                      callback
 */
typedef void (*rtccallback_t)(RTCDriver *rtcdp);

/**
 * @brief   Structure representing a RTC/API configuration
 */
typedef struct {
  /**
   * @brief   RTC Compare Value.
   */
  uint32_t                    rtcCompareValue;
  /**
   * @brief   API Compare Value.
   */
  uint32_t                    apiCompareValue;
  /**
   * @brief   RTC 32 Prescaler Values: 1 -> Enabled, 0 -> Disabled) .
   */
  uint8_t                     rtcPrescaler32;
  /**
   * @brief   RTC 512 Prescaler Values: 1 -> Enabled, 0 -> Disabled).
   */
  uint8_t                     rtcPrescaler512;
  /**
   * @brief   RTC Freeze Enable: if set to 1, the counter will stop in debug mode.
   */
  uint8_t                     rtcFreezeEn;
  /**
   * @brief   RTC Interrupt Enabled.
   */
  uint8_t                     rtcInt;
  /**
   * @brief   rtc Interrupt callback function.
   */
  rtccallback_t               rtcClbk;
  /**
   * @brief   rollover Interrupt Enabled.
   */
  uint8_t                     rolloverInt;
  /**
   * @brief   wakeup Interrupt callback function.
   */
  rtccallback_t               rolloverClbk;
  /**
   * @brief   API Interrupt Enabled.
   */
  uint8_t                     apiInt;
  /**
   * @brief   API Interrupt callback function.
   */
  rtccallback_t               apiClbk;
}RTCConfig;

/**
 * @brief   Structure representing a RTC/API driver.
 */
struct RTCDriver {
  /**
   * @brief   Current configuration data.
   */
  RTCConfig                  *rtc_config;

  /**
   * @brief Pointer to the RTC registers block.
   */
  volatile struct RTC_API_tag *rtc_tagp;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* IRQ Handlers                                                              */
/*===========================================================================*/
IRQ_HANDLER(SCP5_RTC_RTC_HANDLER);
IRQ_HANDLER(SCP5_RTC_API_HANDLER);

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

extern RTCDriver RTCD1;

#ifdef __cplusplus
extern "C" {
#endif
  void rtc_lld_init(void);
  void rtc_lld_start(RTCDriver *rtcdp, RTCConfig *rtc_cfg);
  void rtc_lld_stop(RTCDriver *rtcdp);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_RTC */

#endif /* _RTC_LLD_H_ */

/** @} */

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
 * @file    icu_lld.h
 * @brief   SPC5xx ICU low level driver header.
 *
 * @addtogroup ICU
 * @{
 */

#ifndef _ICU_LLD_H_
#define _ICU_LLD_H_

#include "spc5_lld.h"
#include "lldconf.h"

#if (LLD_USE_ICU == TRUE) || defined(__DOXYGEN__)

#include "spc5_emios.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if (SPC5_ICU_USE_EMIOS0_CH0  == TRUE) || (SPC5_ICU_USE_EMIOS0_CH1  == TRUE) || \
    (SPC5_ICU_USE_EMIOS0_CH2  == TRUE) || (SPC5_ICU_USE_EMIOS0_CH3  == TRUE) || \
    (SPC5_ICU_USE_EMIOS0_CH4  == TRUE) || (SPC5_ICU_USE_EMIOS0_CH5  == TRUE) || \
    (SPC5_ICU_USE_EMIOS0_CH6  == TRUE) || (SPC5_ICU_USE_EMIOS0_CH7  == TRUE)
#define SPC5_ICU_USE_EMIOS0                  TRUE
#else
#define SPC5_ICU_USE_EMIOS0                  FALSE
#endif

#if (SPC5_HAS_EMIOS0 == FALSE) && (SPC5_ICU_USE_EMIOS0 == TRUE)
#error "EMIOS0 not present in the selected device"
#endif

#if (SPC5_ICU_USE_EMIOS0 == FALSE)
#error "ICU driver activated but no Channels assigned"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a structure representing an ICU driver.
 */
typedef struct ICUDriver ICUDriver;

/**
 * @brief   ICU notification callback type.
 *
 * @param[in] icup      pointer to a @p ICUDriver object
 */
typedef void (*icucallback_t)(ICUDriver *icup);

/**
 * @brief ICU driver mode.
 */
typedef enum {
  ICU_INPUT_ACTIVE_HIGH = 0,        /**< Trigger on rising edge.  */
  ICU_INPUT_ACTIVE_LOW  = 1         /**< Trigger on falling edge. */
} icumode_t;

/**
 * @brief   ICU prescaler type.
 */
typedef uint8_t  icupsc_t;

/**
 * @brief   ICU channel type.
 */
typedef uint8_t icuchannel_t;

/**
 * @brief   ICU width type.
 */
typedef uint16_t icuwidth_t;

/**
 * @brief   ICU period type.
 */
typedef uint16_t icuperiod_t;

/**
 * @brief   ICU pulse edge type.
 */
typedef int16_t icupe_t;

/**
 * @brief   Driver configuration structure.
 */
typedef struct {
  /**
   * @brief Counter prescaler.
   */
  icupsc_t                  psc;
  /**
   * @brief   Driver mode.
   */
  icumode_t                 mode;
  /**
   * @brief   Callback for pulse width measurement.
   */
  icucallback_t             width_cb;
  /**
   * @brief   Callback for cycle period measurement.
   */
  icucallback_t             period_cb;
  /**
   * @brief   Callback for timer overflow.
   */
  icucallback_t             overflow_cb;
} ICUConfig;

/**
 * @brief   Pulse edge structure.
 * @note    It contains for each channel the temporary counter A2 
 *          values used to calculate the period and width of the 
 *          related input pulse.
 */
typedef struct {
  /**
   * @brief   Counter A2 value on the first pulse edge.
   * @note    First rising edge for ICU_INPUT_ACTIVE_HIGH,
   *          first falling edge for ICU_INPUT_ACTIVE_LOW.
   */
  icupe_t                   a2_1;
  /**
   * @brief   Counter A2 value on the second pulse edge.
   * @note    First falling edge for ICU_INPUT_ACTIVE_HIGH,
   *          first rising edge for ICU_INPUT_ACTIVE_LOW.
   */
  icupe_t                   a2_2;
  /**
   * @brief   Counter A2 value on the first pulse edge.
   * @note    Second rising edge for ICU_INPUT_ACTIVE_HIGH,
   *          second falling edge for ICU_INPUT_ACTIVE_LOW.
   */
  icupe_t                   a2_3;
} ICUPulseEdges;

/**
 * @brief   Structure representing an ICU driver.
 */
struct ICUDriver {
  /**
   * @brief eMIOSx channel number.
   */
  icuchannel_t              emios_ch;
  /**
   * @brief Current configuration data.
   */
  ICUConfig           		*config;
  /**
   * @brief Pointer to the eMIOSx registers block.
   */
  volatile struct spc5_emios *emiosp;
  /**
   * @brief Last pulse edges.
   */
  ICUPulseEdges             pe;
  /**
   * @brief Last width capture value.
   */
  icuwidth_t                width;
  /**
   * @brief Last period capture value.
   */
  icuperiod_t               period;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Returns the width of the latest pulse.
 * @details The pulse width is defined as number of ticks between the start
 *          edge and the stop edge.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 * @return              The number of ticks.
 *
 * @notapi
 */
#define icu_lld_get_width(icup) ((icup)->width)

/**
 * @brief   Returns the period of the latest cycle.
 * @details The period is defined as number of ticks between a start edge
 *          and the next start edge.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 * @return              The number of ticks.
 *
 * @notapi
 */
#define icu_lld_get_period(icup) ((icup)->period)
/** @} */

/*===========================================================================*/
/* IRQ Handlers                                                              */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (SPC5_ICU_USE_EMIOS0_CH0 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD1;
#endif

#if (SPC5_ICU_USE_EMIOS0_CH1 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD2;
#endif

#if (SPC5_ICU_USE_EMIOS0_CH2 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD3;
#endif

#if (SPC5_ICU_USE_EMIOS0_CH3 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD4;
#endif

#if (SPC5_ICU_USE_EMIOS0_CH4 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD5;
#endif

#if (SPC5_ICU_USE_EMIOS0_CH5 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD6;
#endif

#if (SPC5_ICU_USE_EMIOS0_CH6 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD7;
#endif

#if (SPC5_ICU_USE_EMIOS0_CH7 == TRUE) && !defined(__DOXYGEN__)
extern ICUDriver ICUD8;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void icu_lld_init(void);
  void icu_lld_start(ICUDriver *icup, ICUConfig *config);
  void icu_lld_stop(ICUDriver *icup);
  void icu_lld_enable(ICUDriver *icup);
  void icu_lld_disable(ICUDriver *icup);
  void icu_lld_serve_interrupt(ICUDriver *icup);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_ICU */

#endif /* _ICU_LLD_H_ */

/** @} */

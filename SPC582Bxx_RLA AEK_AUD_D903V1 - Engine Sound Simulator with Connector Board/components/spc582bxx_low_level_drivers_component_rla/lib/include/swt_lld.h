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
 * @file    swt_lld.h
 * @brief   SPC5xx SWT low level driver header.
 *
 * @addtogroup SWT
 * @{
 */

#ifndef _SWT_LLD_H_
#define _SWT_LLD_H_

#include "spc5_lld.h"
#include "lldconf.h"

#if (LLD_USE_SWT == TRUE) || defined(__DOXYGEN__)

#include "spc5_swt.h"

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
 * @brief   SWT0 driver enable switch.
 * @details If set to @p TRUE the support for SWT0 is included.
 */
#if !defined(SPC5_SWT_USE_SWT0) || defined(__DOXYGEN__)
#define SPC5_SWT_USE_SWT0                          FALSE
#endif

/**
 * @brief   SWT1 driver enable switch.
 * @details If set to @p TRUE the support for SWT1 is included.
 */
#if !defined(SPC5_SWT_USE_SWT1) || defined(__DOXYGEN__)
#define SPC5_SWT_USE_SWT1                          FALSE
#endif

/**
 * @brief   SWT2 driver enable switch.
 * @details If set to @p TRUE the support for SWT0 is included.
 */
#if !defined(SPC5_SWT_USE_SWT2) || defined(__DOXYGEN__)
#define SPC5_SWT_USE_SWT2                          FALSE
#endif

/**
 * @brief   SWT3 driver enable switch.
 * @details If set to @p TRUE the support for SWT0 is included.
 */
#if !defined(SPC5_SWT_USE_SWT3) || defined(__DOXYGEN__)
#define SPC5_SWT_USE_SWT3                          FALSE
#endif


/**
 * @brief   SWT0 IRQ priority.
 */
#if !defined(SPC5_SWT0_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_SWT0_IRQ_PRIORITY                    INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 15)
#endif

/**
 * @brief   SWT1 IRQ priority.
 */
#if !defined(SPC5_SWT1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_SWT1_IRQ_PRIORITY                    INTC_PSR_ENABLE(INTC_PSR_CORE0, 15)
#endif

/**
 * @brief   SWT2 IRQ priority.
 */
#if !defined(SPC5_SWT2_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_SWT2_IRQ_PRIORITY                    INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 15)
#endif

/**
 * @brief   SWT3 IRQ priority.
 */
#if !defined(SPC5_SWT3_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_SWT3_IRQ_PRIORITY                    INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 15)
#endif


#if !defined(SPC5_SWT0_INTERRUPT_MODE)
#define SPC5_SWT0_INTERRUPT_MODE                  FALSE
#endif

#if !defined(SPC5_SWT1_INTERRUPT_MODE)
#define SPC5_SWT1_INTERRUPT_MODE                  FALSE
#endif

#if !defined(SPC5_SWT2_INTERRUPT_MODE)
#define SPC5_SWT2_INTERRUPT_MODE                  FALSE
#endif

#if !defined(SPC5_SWT3_INTERRUPT_MODE)
#define SPC5_SWT3_INTERRUPT_MODE                  FALSE
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/
#if (SPC5_SWT_USE_SWT0 == FALSE) && (SPC5_SWT_USE_SWT1 == FALSE) && \
    (SPC5_SWT_USE_SWT2 == FALSE) && (SPC5_SWT_USE_SWT3 == FALSE)
#error "SWT driver activated but no SWT peripheral assigned"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief Type of a structure representing an SWT driver.
 */
typedef struct SWTDriver SWTDriver;

/**
 * @brief   SWT notification callback type.
 *
 */
typedef void (*swtcallback_t)(SWTDriver *swtp);

/**
 * @brief   Structure representing a SWT configuration
 */
typedef struct {

  /**
   * @brief   timeout period (in ms).
   */
  uint32_t                  timeout_period;

  /**
   * @brief   Window period (in ms).
   */
   uint32_t                 window_period;

  /**
   * @brief   callback function.
   */
  swtcallback_t             callback;
} SWT_Config;

/**
 * @brief   Structure representing a SWT driver.
 */
struct SWTDriver {
  /**
   * @brief   Current configuration data.
   */
  SWT_Config          		*swt_config;
   
  /**
   * @brief   Current running frequency.
   */
  uint32_t                  swt_freq;

  /**
   * @brief Pointer to the SWT registers block.
   */
  volatile struct spc5_swt  *swtp;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/


/*===========================================================================*/
/* IRQ Handlers                                                              */
/*===========================================================================*/

#if ((SPC5_HAS_SWT0 == TRUE) && (SPC5_SWT0_INTERRUPT_MODE == TRUE))
IRQ_HANDLER(SPC5_SWT0_HANDLER);
#endif

#if ((SPC5_HAS_SWT1 == TRUE) && (SPC5_SWT1_INTERRUPT_MODE == TRUE))
IRQ_HANDLER(SPC5_SWT1_HANDLER);
#endif

#if ((SPC5_HAS_SWT2 == TRUE) && (SPC5_SWT2_INTERRUPT_MODE == TRUE))
IRQ_HANDLER(SPC5_SWT2_HANDLER);
#endif

#if ((SPC5_HAS_SWT3 == TRUE) && (SPC5_SWT3_INTERRUPT_MODE == TRUE))
IRQ_HANDLER(SPC5_SWT3_HANDLER);
#endif

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (SPC5_HAS_SWT0 == TRUE) && !defined(__DOXYGEN__)
extern SWTDriver SWTD1;
#endif

#if (SPC5_HAS_SWT1 == TRUE) && !defined(__DOXYGEN__)
extern SWTDriver SWTD2;
#endif

#if (SPC5_HAS_SWT2 == TRUE) && !defined(__DOXYGEN__)
extern SWTDriver SWTD3;
#endif

#if (SPC5_HAS_SWT3 == TRUE) && !defined(__DOXYGEN__)
extern SWTDriver SWTD4;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void swt_lld_init       (void);
  void swt_lld_start      (SWTDriver *swtd, SWT_Config *config);
  void swt_lld_keep_alive (SWTDriver *swtd);
  void swt_lld_stop	      (SWTDriver *swtd);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_SWT */

#endif /* _SWT_LLD_H_ */

/** @} */

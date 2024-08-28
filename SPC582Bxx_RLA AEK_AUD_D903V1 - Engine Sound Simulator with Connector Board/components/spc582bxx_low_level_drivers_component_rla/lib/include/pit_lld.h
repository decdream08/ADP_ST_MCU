/****************************************************************************
*
* Copyright © 2015-2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    pit_lld.h
 * @brief   SPC5xx PIT low level driver header.
 *
 * @addtogroup PIT
 * @{
 */

#ifndef _PIT_LLD_H_
#define _PIT_LLD_H_

#include "spc5_lld.h"
#include "lldconf.h"

#if (LLD_USE_PIT == TRUE) || defined(__DOXYGEN__)

#include "spc5_pit.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    PIT channel identifiers
 * @{
 */
#define PIT0_CHANNEL_CH0                  0U
#define PIT0_CHANNEL_CH1                  1U
#define PIT0_CHANNEL_CH2                  2U
#define PIT0_CHANNEL_CH3                  3U
#define PIT0_CHANNEL_CH4                  4U
#define PIT0_CHANNEL_CH5                  5U
#define PIT0_CHANNEL_CH6                  6U
#define PIT0_CHANNEL_CH7                  7U
#define PIT1_CHANNEL_CH0                  0U
#define PIT1_CHANNEL_CH1                  1U
#define PIT1_CHANNEL_CH2                  2U
#define PIT1_CHANNEL_CH3                  3U
#define PIT1_CHANNEL_CH4                  4U
#define PIT1_CHANNEL_CH5                  5U
#define PIT1_CHANNEL_CH6                  6U
#define PIT1_CHANNEL_CH7                  7U
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
 
/**
 * @brief   PIT0 driver enable switch.
 * @details If set to @p TRUE the support for PIT0 is included.
 */
#if !defined(SPC5_PIT_USE_PIT0) || defined(__DOXYGEN__)
#define SPC5_PIT_USE_PIT0                         FALSE
#endif

/**
 * @brief   PIT1driver enable switch.
 * @details If set to @p TRUE the support for PIT1 is included.
 */
#if !defined(SPC5_PIT_USE_PIT1) || defined(__DOXYGEN__)
#define SPC5_PIT_USE_PIT1                         FALSE
#endif

/**
 * @brief   PIT0 CH0 IRQ priority.
 * @note    This PIT channel is also allocated for system tick
 *          generation.
 */
#if !defined(SPC5_PIT0_CH0_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_PIT0_IRQ_PRIORITY                    INTC_PSR_ENABLE(INTC_PSR_MAINCORE,4)
#endif

/**
 * @brief   PIT CH1 IRQ priority.
 * 
 */
#if !defined(SPC5_PIT0_CH1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_PIT0_CH1_IRQ_PRIORITY                INTC_PSR_ENABLE(INTC_PSR_MAINCORE,12)
#endif

/**
 * @brief   PIT CH2 IRQ priority.
 * 
 */
#if !defined(SPC5_PIT0_CH2_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_PIT0_CH2_IRQ_PRIORITY                INTC_PSR_ENABLE(INTC_PSR_MAINCORE,12)
#endif

/**
 * @brief   PIT CH3 IRQ priority.
 * 
 */

#if !defined(SPC5_PIT0_CH3_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_PIT0_CH3_IRQ_PRIORITY                INTC_PSR_ENABLE(INTC_PSR_MAINCORE,12)
#endif

/**
 * @brief   PIT CH4 IRQ priority.
 * 
 */
#if !defined(SPC5_PIT0_CH4_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_PIT0_CH4_IRQ_PRIORITY                INTC_PSR_ENABLE(INTC_PSR_MAINCORE,12)
#endif

/**
 * @brief   PIT CH5 IRQ priority.
 * 
 */
#if !defined(SPC5_PIT0_CH5_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_PIT0_CH5_IRQ_PRIORITY                INTC_PSR_ENABLE(INTC_PSR_MAINCORE,12)
#endif

/**
 * @brief   PIT CH6 IRQ priority.
 * 
 */
#if !defined(SPC5_PIT0_CH6_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_PIT0_CH6_IRQ_PRIORITY                INTC_PSR_ENABLE(INTC_PSR_MAINCORE,12)
#endif

/**
 * @brief   PIT CH7 IRQ priority.
 * 
 */
#if !defined(SPC5_PIT0_CH7_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_PIT0_CH7_IRQ_PRIORITY                INTC_PSR_ENABLE(INTC_PSR_MAINCORE,12)
#endif

/**
 * @brief   PIT peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_PIT0_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_PIT0_START_PCTL                 (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   PIT peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(SPC5_PIT0_STOP_PCTL) || defined(__DOXYGEN__)
#define SPC5_PIT0_STOP_PCTL                  (SPC5_ME_PCTL_RUN(0) |          \
                                             SPC5_ME_PCTL_LP(0))
#endif

/**
 * @name    Configuration options
 * @{
 */
 
/**
 * @brief   PIT1 CH0 IRQ priority.
 * @note    This PIT channel is also allocated for system tick
 *          generation.
 */
#if !defined(SPC5_PIT1_CH0_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_PIT1_IRQ_PRIORITY                    INTC_PSR_ENABLE(INTC_PSR_MAINCORE,12)
#endif

/**
 * @brief   PIT CH1 IRQ priority.
 * 
 */
#if !defined(SPC5_PIT1_CH1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_PIT1_CH1_IRQ_PRIORITY                INTC_PSR_ENABLE(INTC_PSR_MAINCORE,12)
#endif

/**
 * @brief   PIT CH2 IRQ priority.
 * 
 */
#if !defined(SPC5_PIT1_CH2_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_PIT1_CH2_IRQ_PRIORITY                INTC_PSR_ENABLE(INTC_PSR_MAINCORE,12)
#endif

/**
 * @brief   PIT CH3 IRQ priority.
 * 
 */

#if !defined(SPC5_PIT1_CH3_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_PIT1_CH3_IRQ_PRIORITY                INTC_PSR_ENABLE(INTC_PSR_MAINCORE,12)
#endif

/**
 * @brief   PIT CH4 IRQ priority.
 * 
 */
#if !defined(SPC5_PIT1_CH4_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_PIT1_CH4_IRQ_PRIORITY                INTC_PSR_ENABLE(INTC_PSR_MAINCORE,12)
#endif

/**
 * @brief   PIT CH5 IRQ priority.
 * 
 */
#if !defined(SPC5_PIT1_CH5_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_PIT1_CH5_IRQ_PRIORITY                INTC_PSR_ENABLE(INTC_PSR_MAINCORE,12)
#endif

/**
 * @brief   PIT CH6 IRQ priority.
 * 
 */
#if !defined(SPC5_PIT1_CH6_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_PIT1_CH6_IRQ_PRIORITY                INTC_PSR_ENABLE(INTC_PSR_MAINCORE,12)
#endif

/**
 * @brief   PIT CH7 IRQ priority.
 * 
 */
#if !defined(SPC5_PIT1_CH7_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_PIT1_CH7_IRQ_PRIORITY                INTC_PSR_ENABLE(INTC_PSR_MAINCORE,12)
#endif

/**
 * @brief   PIT peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_PIT1_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_PIT1_START_PCTL                 (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   PIT peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(SPC5_PIT1_STOP_PCTL) || defined(__DOXYGEN__)
#define SPC5_PIT1_STOP_PCTL                  (SPC5_ME_PCTL_RUN(0) |          \
                                             SPC5_ME_PCTL_LP(0))
#endif

/** @} */
/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/
/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if (SPC5_PIT_USE_PIT0 == FALSE) && (SPC5_PIT_USE_PIT1 == FALSE)
#error "PIT driver activated but no PIT peripheral assigned"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief Type of a structure representing an PIT driver.
 */
typedef struct PITDriver PITDriver;

/**
 * @brief   PIT notification callback type.
 *
 * @param[in] adcp      pointer to the @p PITDriver object triggering the
 *                      callback
 */
typedef void (*pitcallback_t)(void);

/**
 * @brief   Structure representing a PIT Channel configuration
 */
typedef struct {
  /**
   * @brief   Channel Enabled.
   */  
   uint8_t enabled;
  /**
   * @brief   timer frequency.
   */
   uint32_t frequency;
  /**
   * @brief   callback function.
   */
   pitcallback_t callback;
}PIT_CH_Config;

/**
 * @brief   Structure representing a PIT driver.
 */
struct PITDriver {
  /**
   * @brief   Current configuration data.
   */
  PIT_CH_Config *pit_ch_config;
   
  /**
   * @brief Pointer to the PIT registers block.
   */
  volatile struct spc5_pit  *pit_tagp;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/


/*===========================================================================*/
/* IRQ Handlers                                                              */
/*===========================================================================*/

#if (SPC5_PIT_USE_PIT0 == TRUE) || defined(__DOXYGEN__)
#if ((SPC5_HAS_PIT0_CH0 == TRUE) && (PIT0_CHANNEL_CH0_ENABLED == TRUE))
IRQ_HANDLER(SPC5_PIT0_CH0_HANDLER);
#endif

#if ((SPC5_HAS_PIT0_CH1 == TRUE) && (PIT0_CHANNEL_CH1_ENABLED == TRUE))
IRQ_HANDLER(SPC5_PIT0_CH1_HANDLER);
#endif

#if ((SPC5_HAS_PIT0_CH2 == TRUE) && (PIT0_CHANNEL_CH2_ENABLED == TRUE))
IRQ_HANDLER(SPC5_PIT0_CH2_HANDLER);
#endif

#if ((SPC5_HAS_PIT0_CH3 == TRUE) && (PIT0_CHANNEL_CH3_ENABLED == TRUE))
IRQ_HANDLER(SPC5_PIT0_CH3_HANDLER);
#endif

#if ((SPC5_HAS_PIT0_CH4 == TRUE) && (PIT0_CHANNEL_CH4_ENABLED == TRUE))
IRQ_HANDLER(SPC5_PIT0_CH4_HANDLER);
#endif

#if ((SPC5_HAS_PIT0_CH5 == TRUE) && (PIT0_CHANNEL_CH5_ENABLED == TRUE))
IRQ_HANDLER(SPC5_PIT0_CH5_HANDLER);
#endif

#if ((SPC5_HAS_PIT0_CH6 == TRUE) && (PIT0_CHANNEL_CH6_ENABLED == TRUE))
IRQ_HANDLER(SPC5_PIT0_CH6_HANDLER);
#endif

#if ((SPC5_HAS_PIT0_CH7 == TRUE) && (PIT0_CHANNEL_CH7_ENABLED == TRUE))
IRQ_HANDLER(SPC5_PIT0_CH7_HANDLER);
#endif
#endif

#if (SPC5_PIT_USE_PIT1 == TRUE) || defined(__DOXYGEN__)
#if ((SPC5_HAS_PIT1_CH0 == TRUE) && (PIT1_CHANNEL_CH0_ENABLED == TRUE))
IRQ_HANDLER(SPC5_PIT1_CH0_HANDLER);
#endif

#if ((SPC5_HAS_PIT1_CH1 == TRUE) && (PIT1_CHANNEL_CH1_ENABLED == TRUE))
IRQ_HANDLER(SPC5_PIT1_CH1_HANDLER);
#endif

#if ((SPC5_HAS_PIT1_CH2 == TRUE) && (PIT1_CHANNEL_CH2_ENABLED == TRUE))
IRQ_HANDLER(SPC5_PIT1_CH2_HANDLER);
#endif

#if ((SPC5_HAS_PIT1_CH3 == TRUE) && (PIT1_CHANNEL_CH3_ENABLED == TRUE))
IRQ_HANDLER(SPC5_PIT1_CH3_HANDLER);
#endif

#if ((SPC5_HAS_PIT1_CH4 == TRUE) && (PIT1_CHANNEL_CH4_ENABLED == TRUE))
IRQ_HANDLER(SPC5_PIT1_CH4_HANDLER);
#endif

#if ((SPC5_HAS_PIT1_CH5 == TRUE) && (PIT1_CHANNEL_CH5_ENABLED == TRUE))
IRQ_HANDLER(SPC5_PIT1_CH5_HANDLER);
#endif

#if ((SPC5_HAS_PIT1_CH6 == TRUE) && (PIT1_CHANNEL_CH6_ENABLED == TRUE))
IRQ_HANDLER(SPC5_PIT1_CH6_HANDLER);
#endif

#if ((SPC5_HAS_PIT1_CH7 == TRUE) && (PIT1_CHANNEL_CH7_ENABLED == TRUE))
IRQ_HANDLER(SPC5_PIT1_CH7_HANDLER);
#endif
#endif
/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/**
 * @brief   PIT0 driver extern declaration.
 */
#if (SPC5_PIT_USE_PIT0 == TRUE) || defined(__DOXYGEN__)
extern PITDriver PITD1;
#endif

/**
 * @brief   PIT1 driver extern declaration.
 */
#if (SPC5_PIT_USE_PIT1 == TRUE) || defined(__DOXYGEN__)
extern PITDriver PITD2;
#endif


#ifdef __cplusplus
extern "C" {
#endif
  void pit_lld_init             (void);
  void pit_lld_start            (PITDriver *pitd, PIT_CH_Config *config);
  void pit_lld_channel_start    (PITDriver *pitd, uint8_t channel);
  void pit_lld_channel_set_freq (PITDriver *pitd, uint8_t channel,uint32_t frequency);
  void pit_lld_channel_stop     (PITDriver *pitd, uint8_t channel);
  void pit_lld_stop			    (PITDriver *pitd);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_PIT */

#endif /* _PIT_LLD_H_ */

/** @} */

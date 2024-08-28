/****************************************************************************
*
* Copyright © 2018-2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    i2s_lld.h
 * @brief   SPC5xx I2S low level driver header.
 *
 * @addtogroup I2S
 * @{
 */

#ifndef _I2S_LLD_H_
#define _I2S_LLD_H_

#include "spc5_lld.h"
#include "lldconf.h"

#if (LLD_USE_I2S == TRUE) || defined(__DOXYGEN__)

#include "spc5_edma.h"
#include "spc5_dspi.h"


/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/* Playback options */

/* Loop forever */
#define SPC5_I2S_LOOP_FOREVER           (-1)

/* Play once */
#define SPC5_I2S_PLAY_ONCE               (1)


/* 8-bits per sample */
#define SPC5_I2S_BPS_8                   8U

/* 16-bits per sample */
#define SPC5_I2S_BPS_16                  16U

/* 24-bits per sample */
#define SPC5_I2S_BPS_24                  24U

/* 32-bits per sample */
#define SPC5_I2S_BPS_32                  32U


/* Standard I2S word select signal level (low = Left channel, High = Right channel) */
#define SPC5_I2S_STANDARD_WS_SL          0U

/* Inverted I2S word select signal level (low = Right channel, High = Left channel) */
#define SPC5_I2S_INVERT_WS_SL            1U


/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   I2SD1 driver enable switch.
 * @details If set to @p TRUE the support for DSPI0 is included.
 */
#if !defined(SPC5_I2S_USE_DSPI0) || defined(__DOXYGEN__)
#define SPC5_I2S_USE_DSPI0                  FALSE
#endif

/**
 * @brief   I2SD2 driver enable switch.
 * @details If set to @p TRUE the support for DSPI1 is included.
 */
#if !defined(SPC5_I2S_USE_DSPI1) || defined(__DOXYGEN__)
#define SPC5_I2S_USE_DSPI1                  FALSE
#endif

/**
 * @brief   I2SD3 driver enable switch.
 * @details If set to @p TRUE the support for DSPI2 is included.
 */
#if !defined(SPC5_I2S_USE_DSPI2) || defined(__DOXYGEN__)
#define SPC5_I2S_USE_DSPI2                  FALSE
#endif

/**
 * @brief   I2SD4 driver enable switch.
 * @details If set to @p TRUE the support for DSPI3 is included.
 */
#if !defined(SPC5_I2S_USE_DSPI3) || defined(__DOXYGEN__)
#define SPC5_I2S_USE_DSPI3                  FALSE
#endif

/**
 * @brief   I2SD5 driver enable switch.
 * @details If set to @p TRUE the support for DSPI4 is included.
 */
#if !defined(SPC5_I2S_USE_DSPI4) || defined(__DOXYGEN__)
#define SPC5_I2S_USE_DSPI4                  FALSE
#endif

/**
 * @brief   I2SD6 driver enable switch.
 * @details If set to @p TRUE the support for DSPI5 is included.
 */
#if !defined(SPC5_I2S_USE_DSPI5) || defined(__DOXYGEN__)
#define SPC5_I2S_USE_DSPI5                  FALSE
#endif

/**
 * @brief   I2SD7 driver enable switch.
 * @details If set to @p TRUE the support for DSPI6 is included.
 */
#if !defined(SPC5_I2S_USE_DSPI6) || defined(__DOXYGEN__)
#define SPC5_I2S_USE_DSPI6                  FALSE
#endif

/**
 * @brief   I2SD8 driver enable switch.
 * @details If set to @p TRUE the support for DSPI7 is included.
 */
#if !defined(SPC5_I2S_USE_DSPI7) || defined(__DOXYGEN__)
#define SPC5_I2S_USE_DSPI7                  FALSE
#endif

/**
 * @brief   I2SD9 driver enable switch.
 * @details If set to @p TRUE the support for DSPI8 is included.
 */
#if !defined(SPC5_I2S_USE_DSPI8) || defined(__DOXYGEN__)
#define SPC5_I2S_USE_DSPI8                  FALSE
#endif

/**
 * @brief   I2SD10 driver enable switch.
 * @details If set to @p TRUE the support for DSPI8 is included.
 */
#if !defined(SPC5_I2S_USE_DSPI9) || defined(__DOXYGEN__)
#define SPC5_I2S_USE_DSPI9                  FALSE
#endif

/**
 * @brief   DSPI0 MCR PCS defaults.
 */
#if !defined(SPC5_I2S_DSPI0_MCR) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI0_MCR                  (SPC5_MCR_PCSIS0 |              \
                                             SPC5_MCR_PCSIS1 |              \
                                             SPC5_MCR_PCSIS2 |              \
                                             SPC5_MCR_PCSIS3 |              \
                                             SPC5_MCR_PCSIS4 |              \
                                             SPC5_MCR_PCSIS5 |              \
                                             SPC5_MCR_PCSIS6 |              \
                                             SPC5_MCR_PCSIS7)
#endif

/**
 * @brief   DSPI1 MCR PCS defaults.
 */
#if !defined(SPC5_I2S_DSPI1_MCR) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI1_MCR                  (SPC5_MCR_PCSIS0 |              \
                                             SPC5_MCR_PCSIS1 |              \
                                             SPC5_MCR_PCSIS2 |              \
                                             SPC5_MCR_PCSIS3 |              \
                                             SPC5_MCR_PCSIS4 |              \
                                             SPC5_MCR_PCSIS5 |              \
                                             SPC5_MCR_PCSIS6 |              \
                                             SPC5_MCR_PCSIS7)
#endif

/**
 * @brief   DSP2 MCR PCS defaults.
 */
#if !defined(SPC5_I2S_DSPI2_MCR) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI2_MCR                  (SPC5_MCR_PCSIS0 |              \
                                             SPC5_MCR_PCSIS1 |              \
                                             SPC5_MCR_PCSIS2 |              \
                                             SPC5_MCR_PCSIS3 |              \
                                             SPC5_MCR_PCSIS4 |              \
                                             SPC5_MCR_PCSIS5 |              \
                                             SPC5_MCR_PCSIS6 |              \
                                             SPC5_MCR_PCSIS7)
#endif

/**
 * @brief   DSPI3 MCR PCS defaults.
 */
#if !defined(SPC5_I2S_DSPI3_MCR) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI3_MCR                  (SPC5_MCR_PCSIS0 |              \
                                             SPC5_MCR_PCSIS1 |              \
                                             SPC5_MCR_PCSIS2 |              \
                                             SPC5_MCR_PCSIS3 |              \
                                             SPC5_MCR_PCSIS4 |              \
                                             SPC5_MCR_PCSIS5 |              \
                                             SPC5_MCR_PCSIS6 |              \
                                             SPC5_MCR_PCSIS7)
#endif

/**
 * @brief   DSPI4 MCR PCS defaults.
 */
#if !defined(SPC5_I2S_DSPI4_MCR) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI4_MCR                  (SPC5_MCR_PCSIS0 |              \
                                             SPC5_MCR_PCSIS1 |              \
                                             SPC5_MCR_PCSIS2 |              \
                                             SPC5_MCR_PCSIS3 |              \
                                             SPC5_MCR_PCSIS4 |              \
                                             SPC5_MCR_PCSIS5 |              \
                                             SPC5_MCR_PCSIS6 |              \
                                             SPC5_MCR_PCSIS7)
#endif

/**
 * @brief   DSPI5 MCR PCS defaults.
 */
#if !defined(SPC5_I2S_DSPI5_MCR) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI5_MCR                  (SPC5_MCR_PCSIS0 |              \
                                             SPC5_MCR_PCSIS1 |              \
                                             SPC5_MCR_PCSIS2 |              \
                                             SPC5_MCR_PCSIS3 |              \
                                             SPC5_MCR_PCSIS4 |              \
                                             SPC5_MCR_PCSIS5 |              \
                                             SPC5_MCR_PCSIS6 |              \
                                             SPC5_MCR_PCSIS7)
#endif

/**
 * @brief   DSPI6 MCR PCS defaults.
 */
#if !defined(SPC5_I2S_DSPI6_MCR) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI6_MCR                  (SPC5_MCR_PCSIS0 |              \
                                             SPC5_MCR_PCSIS1 |              \
                                             SPC5_MCR_PCSIS2 |              \
                                             SPC5_MCR_PCSIS3 |              \
                                             SPC5_MCR_PCSIS4 |              \
                                             SPC5_MCR_PCSIS5 |              \
                                             SPC5_MCR_PCSIS6 |              \
                                             SPC5_MCR_PCSIS7)
#endif

/**
 * @brief   DSPI7 MCR PCS defaults.
 */
#if !defined(SPC5_I2S_DSPI7_MCR) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI7_MCR                  (SPC5_MCR_PCSIS0 |              \
                                             SPC5_MCR_PCSIS1 |              \
                                             SPC5_MCR_PCSIS2 |              \
                                             SPC5_MCR_PCSIS3 |              \
                                             SPC5_MCR_PCSIS4 |              \
                                             SPC5_MCR_PCSIS5 |              \
                                             SPC5_MCR_PCSIS6 |              \
                                             SPC5_MCR_PCSIS7)
#endif

/**
 * @brief   DSPI8 MCR PCS defaults.
 */
#if !defined(SPC5_I2S_DSPI8_MCR) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI8_MCR                  (SPC5_MCR_PCSIS0 |              \
                                             SPC5_MCR_PCSIS1 |              \
                                             SPC5_MCR_PCSIS2 |              \
                                             SPC5_MCR_PCSIS3 |              \
                                             SPC5_MCR_PCSIS4 |              \
                                             SPC5_MCR_PCSIS5 |              \
                                             SPC5_MCR_PCSIS6 |              \
                                             SPC5_MCR_PCSIS7)
#endif

/**
 * @brief   DSPI9 MCR PCS defaults.
 */
#if !defined(SPC5_I2S_DSPI9_MCR) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI9_MCR                  (SPC5_MCR_PCSIS0 |              \
                                             SPC5_MCR_PCSIS1 |              \
                                             SPC5_MCR_PCSIS2 |              \
                                             SPC5_MCR_PCSIS3 |              \
                                             SPC5_MCR_PCSIS4 |              \
                                             SPC5_MCR_PCSIS5 |              \
                                             SPC5_MCR_PCSIS6 |              \
                                             SPC5_MCR_PCSIS7)
#endif


/**
 * @brief   DSPI0 DMA IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI0_DMA_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI0_DMA_IRQ_PRIO         10
#endif

/**
 * @brief   DSPI1 DMA IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI1_DMA_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI1_DMA_IRQ_PRIO         10
#endif

/**
 * @brief   DSPI2 DMA IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI2_DMA_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI2_DMA_IRQ_PRIO         10
#endif

/**
 * @brief   DSPI3 DMA IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI3_DMA_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI3_DMA_IRQ_PRIO         10
#endif

/**
 * @brief   DSPI4 DMA IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI4_DMA_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI4_DMA_IRQ_PRIO         10
#endif

/**
 * @brief   DSPI5 DMA IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI5_DMA_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI5_DMA_IRQ_PRIO         10
#endif

/**
 * @brief   DSPI6 DMA IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI6_DMA_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI6_DMA_IRQ_PRIO         10
#endif

/**
 * @brief   DSPI7 DMA IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI7_DMA_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI7_DMA_IRQ_PRIO         10
#endif

/**
 * @brief   DSPI8 DMA IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI8_DMA_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI8_DMA_IRQ_PRIO         10
#endif

/**
 * @brief   DSPI9 DMA IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI9_DMA_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI9_DMA_IRQ_PRIO         10
#endif

/**
 * @brief   I2S DMA error hook.
 */
#if !defined(SPC5_I2S_DMA_ERROR_HOOK) || defined(__DOXYGEN__)
#define SPC5_I2S_DMA_ERROR_HOOK(spip)       irqSysHalt()
#endif

/**
 * @brief   DSPI0 IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI0_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI0_IRQ_PRIO             10
#endif

/**
 * @brief   DSPI1 IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI1_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI1_IRQ_PRIO             10
#endif

/**
 * @brief   DSPI2 IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI2_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI2_IRQ_PRIO             10
#endif

/**
 * @brief   DSPI3 IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI3_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI3_IRQ_PRIO             10
#endif

/**
 * @brief   DSPI4 IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI4_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI4_IRQ_PRIO             10
#endif

/**
 * @brief   DSPI5 IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI5_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI5_IRQ_PRIO             10
#endif

/**
 * @brief   DSPI6 IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI6_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI6_IRQ_PRIO             10
#endif

/**
 * @brief   DSPI7 IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI7_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI7_IRQ_PRIO             10
#endif

/**
 * @brief   DSPI8 IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI8_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI8_IRQ_PRIO             10
#endif

/**
 * @brief   DSPI9 IRQ priority.
 */
#if !defined(SPC5_I2S_DSPI9_IRQ_PRIO) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI9_IRQ_PRIO             10
#endif


/**
 * @brief   DSPI0 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI0_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI0_START_PCTL           (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   DSPI0 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI0_STOP_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI0_STOP_PCTL            (SPC5_ME_PCTL_RUN(0) |          \
                                             SPC5_ME_PCTL_LP(0))
#endif

/**
 * @brief   DSPI1 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI1_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI1_START_PCTL           (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   DSPI1 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI1_STOP_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI1_STOP_PCTL            (SPC5_ME_PCTL_RUN(0) |          \
                                             SPC5_ME_PCTL_LP(0))
#endif

/**
 * @brief   DSPI2 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI2_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI2_START_PCTL           (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   DSPI2 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI2_STOP_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI2_STOP_PCTL            (SPC5_ME_PCTL_RUN(0) |          \
                                             SPC5_ME_PCTL_LP(0))
#endif

/**
 * @brief   DSPI3 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI3_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI3_START_PCTL           (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   DSPI3 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI3_STOP_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI3_STOP_PCTL            (SPC5_ME_PCTL_RUN(0) |          \
                                             SPC5_ME_PCTL_LP(0))
#endif

/**
 * @brief   DSPI4 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI4_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI4_START_PCTL           (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   DSPI4 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI4_STOP_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI4_STOP_PCTL            (SPC5_ME_PCTL_RUN(0) |          \
                                             SPC5_ME_PCTL_LP(0))
#endif

/**
 * @brief   DSPI5 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI5_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI5_START_PCTL           (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   DSPI5 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI5_STOP_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI5_STOP_PCTL            (SPC5_ME_PCTL_RUN(0) |          \
                                             SPC5_ME_PCTL_LP(0))
#endif

/**
 * @brief   DSPI6 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI6_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI6_START_PCTL           (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   DSPI6 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI6_STOP_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI6_STOP_PCTL            (SPC5_ME_PCTL_RUN(0) |          \
                                             SPC5_ME_PCTL_LP(0))
#endif

/**
 * @brief   DSPI7 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI7_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI7_START_PCTL           (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   DSPI7 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI7_STOP_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI7_STOP_PCTL            (SPC5_ME_PCTL_RUN(0) |          \
                                             SPC5_ME_PCTL_LP(0))
#endif

/**
 * @brief   DSPI8 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI8_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI8_START_PCTL           (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   DSPI8 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI8_STOP_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI8_STOP_PCTL            (SPC5_ME_PCTL_RUN(0) |          \
                                             SPC5_ME_PCTL_LP(0))
#endif

/**
 * @brief   DSPI9 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI9_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI9_START_PCTL           (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   DSPI9 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(SPC5_I2S_DSPI9_STOP_PCTL) || defined(__DOXYGEN__)
#define SPC5_I2S_DSPI9_STOP_PCTL            (SPC5_ME_PCTL_RUN(0) |          \
                                             SPC5_ME_PCTL_LP(0))
#endif

/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if (SPC5_HAS_EDMA == FALSE)
#error "No DMA found on this device; I2S works only with DMA"
#endif

#if (SPC5_I2S_USE_DSPI0 == TRUE) && (SPC5_HAS_DSPI0 == FALSE)
#error "DSPI0 not present in the selected device"
#endif

#if (SPC5_I2S_USE_DSPI1 == TRUE) && (SPC5_HAS_DSPI1 == FALSE)
#error "DSPI1 not present in the selected device"
#endif

#if (SPC5_I2S_USE_DSPI2 == TRUE) && (SPC5_HAS_DSPI2 == FALSE)
#error "DSPI2 not present in the selected device"
#endif

#if (SPC5_I2S_USE_DSPI3 == TRUE) && (SPC5_HAS_DSPI3 == FALSE)
#error "DSPI3 not present in the selected device"
#endif

#if (SPC5_I2S_USE_DSPI4 == TRUE) && (SPC5_HAS_DSPI4 == FALSE)
#error "DSPI4 not present in the selected device"
#endif

#if (SPC5_I2S_USE_DSPI5 == TRUE) && (SPC5_HAS_DSPI5 == FALSE)
#error "DSPI5 not present in the selected device"
#endif

#if (SPC5_I2S_USE_DSPI6 == TRUE) && (SPC5_HAS_DSPI6 == FALSE)
#error "DSPI6 not present in the selected device"
#endif

#if (SPC5_I2S_USE_DSPI7 == TRUE) && (SPC5_HAS_DSPI7 == FALSE)
#error "DSPI7 not present in the selected device"
#endif

#if (SPC5_I2S_USE_DSPI8 == TRUE) && (SPC5_HAS_DSPI8 == FALSE)
#error "DSPI8 not present in the selected device"
#endif

#if (SPC5_I2S_USE_DSPI9 == TRUE) && (SPC5_HAS_DSPI9 == FALSE)
#error "DSPI9 not present in the selected device"
#endif

#if (SPC5_I2S_USE_DSPI0 == FALSE) && (SPC5_I2S_USE_DSPI1 == FALSE) &&       \
    (SPC5_I2S_USE_DSPI2 == FALSE) && (SPC5_I2S_USE_DSPI3 == FALSE) &&       \
    (SPC5_I2S_USE_DSPI4 == FALSE) && (SPC5_I2S_USE_DSPI5 == FALSE) &&       \
    (SPC5_I2S_USE_DSPI6 == FALSE) && (SPC5_I2S_USE_DSPI7 == FALSE) &&       \
    (SPC5_I2S_USE_DSPI8 == FALSE) && (SPC5_I2S_USE_DSPI9 == FALSE)
#error "I2S driver activated but no DSPI peripheral assigned"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a structure representing an SPI driver.
 */
typedef struct I2SDriver I2SDriver;

/**
 * @brief   I2S notification callback type.
 *
 * @param[in] i2sp      pointer to the @p I2SDriver object triggering the
 *                      callback
 */
typedef void (*i2scallback_t)(I2SDriver *i2sp);

/**
 * @brief   Driver configuration structure.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
typedef struct {
  /**
   * @brief   Operation complete callback.
   */
  i2scallback_t         end_cb;
  /**
   * @brief   Half transmit callback.
   */
  i2scallback_t         half_cb;
  /**
   * @brief   Operation complete callback.
   */
  i2scallback_t         end_rx_cb;
  /**
   * @brief   Half transmit callback.
   */
  i2scallback_t         half_rx_cb;
  /* End of the mandatory fields.*/
  /**
   * @brief   DSPI CTAR0 value for this session.
   */
  uint32_t              ctar0;
  /**
   * @brief   DSPI PUSHR command for this session.
   * @note    Only CTAR0 can be referenced, the other CTARs are not
   *          initialized. The data part must be left to zero.
   */
  uint32_t              pushr_left;
  /**
   * @brief   DSPI PUSHR command for this session.
   * @note    Only CTAR0 can be referenced, the other CTARs are not
   *          initialized. The data part must be left to zero.
   */
  uint32_t              pushr_right;
  /**
   * @brief   Word Select (WS) signal level.
   */
  uint32_t              invert_ws;
  /**
   * @brief   Effective sample size.
   */
  uint32_t              sample_size;
} I2SConfig;

/**
 * @brief   Structure representing an I2S driver.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
struct I2SDriver {
  /**
   * @brief   Current configuration data.
   */
  I2SConfig           		*config;
#if (I2S_USE_WAIT == TRUE) || defined(__DOXYGEN__)
  /**
   * @brief   Waiting flag.
   */
  volatile uint8_t           ready;
#endif /* I2S_USE_WAIT */
  /**
   * @brief   Pointer to the DSPI registers block.
   */
  struct spc5_dspi          *dspi;
  /**
   * @brief   EDMA channel used for data memory to memory copy.
   */
  edma_channel_t            tx1_channel;
  /**
   * @brief   EDMA channel used for transmit.
   */
  edma_channel_t            tx2_channel;
  /**
   * @brief   Playback options.
   */
  int32_t                   playback_opts;
  /**
   * @brief   Buffer length.
   */
  uint32_t                  buf_len;
  /**
   * @brief   EDMA channel used for receiving.
   */
  edma_channel_t            rx_channel;
  /**
   * @brief   Command for the ongoing TX operation.
   */
  uint32_t                  tx_intermediate_buffer[4]  __attribute__ ((aligned (256)));
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @name    Low Level driver helper macros
 * @{
 */
#if (I2S_USE_WAIT == TRUE) || defined(__DOXYGEN__)
#ifdef __ghs__
#pragma ghs ZO
#endif
/**
 * @brief   Waits for operation completion.
 * @details This function waits for the driver to complete the current
 *          operation.
 * @pre     An operation must be running while the function is invoked.
 * @note    No more than one thread can wait on a SPI driver using
 *          this function.
 *
 * @param[in] i2sp      pointer to the @p I2SDriver object
 *
 * @notapi
 */
#define _i2s_wait_s(i2sp) {                                                 \
  while(i2sp->ready == FALSE) {                                             \
  }                                                                         \
}
#ifdef __ghs__
#pragma ghs O
#endif

/**
 * @brief   Wakes up the waiting thread.
 *
 * @param[in] i2sp      pointer to the @p I2SDriver object
 *
 * @notapi
 */
#define _i2s_wakeup_isr(i2sp) i2sp->ready = TRUE;
#else /* !I2S_USE_WAIT */
#define _i2s_wait_s(i2sp)
#define _i2s_wakeup_isr(i2sp)
#endif /* !I2S_USE_WAIT */

/**
 * @brief   Common ISR code.
 * @details This code handles the portable part of the ISR code:
 *          - Callback invocation.
 *          - Waiting thread wakeup, if any.
 *          - Driver state transitions.
 *          .
 * @note    This macro is meant to be used in the low level drivers
 *          implementation only.
 *
 * @param[in] i2sp      pointer to the @p I2SDriver object
 *
 * @notapi
 */
#define _i2s_isr_code(i2sp) {                                               \
  _i2s_wakeup_isr(i2sp);                                                    \
}
/** @} */

/*===========================================================================*/
/* IRQ Handlers                                                              */
/*===========================================================================*/

#if (SPC5_I2S_USE_DSPI0 == TRUE) || defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_DSPI0_TFFF_HANDLER);
#endif /* SPC5_I2S_USE_DSPI0 */
#if (SPC5_I2S_USE_DSPI1 == TRUE) || defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_DSPI1_TFFF_HANDLER) ;
#endif /* SPC5_I2S_USE_DSPI1 */
#if (SPC5_I2S_USE_DSPI2 == TRUE) || defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_DSPI2_TFFF_HANDLER);
#endif /* SPC5_I2S_USE_DSPI2 */
#if (SPC5_I2S_USE_DSPI3 == TRUE) || defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_DSPI3_TFFF_HANDLER);
#endif /* SPC5_I2S_USE_DSPI3 */
#if (SPC5_I2S_USE_DSPI4 == TRUE) || defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_DSPI4_TFFF_HANDLER);
#endif /* SPC5_I2S_USE_DSPI4 */
#if (SPC5_I2S_USE_DSPI5 == TRUE) || defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_DSPI5_TFFF_HANDLER);
#endif /* SPC5_I2S_USE_DSPI5 */
#if (SPC5_I2S_USE_DSPI6 == TRUE) || defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_DSPI6_TFFF_HANDLER);
#endif /* SPC5_I2S_USE_DSPI6 */
#if (SPC5_I2S_USE_DSPI7 == TRUE) || defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_DSPI7_TFFF_HANDLER);
#endif /* SPC5_I2S_USE_DSPI7 */
#if (SPC5_I2S_USE_DSPI8 == TRUE) || defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_DSPI8_TFFF_HANDLER);
#endif /* SPC5_I2S_USE_DSPI8 */
#if (SPC5_I2S_USE_DSPI9 == TRUE) || defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_DSPI9_TFFF_HANDLER);
#endif /* SPC5_I2S_USE_DSPI9 */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (SPC5_I2S_USE_DSPI0 == TRUE) && !defined(__DOXYGEN__)
extern I2SDriver I2SD1;
#endif

#if (SPC5_I2S_USE_DSPI1 == TRUE) && !defined(__DOXYGEN__)
extern I2SDriver I2SD2;
#endif

#if (SPC5_I2S_USE_DSPI2 == TRUE) && !defined(__DOXYGEN__)
extern I2SDriver I2SD3;
#endif

#if (SPC5_I2S_USE_DSPI3 == TRUE) && !defined(__DOXYGEN__)
extern I2SDriver I2SD4;
#endif

#if (SPC5_I2S_USE_DSPI4 == TRUE) && !defined(__DOXYGEN__)
extern I2SDriver I2SD5;
#endif

#if (SPC5_I2S_USE_DSPI5 == TRUE) && !defined(__DOXYGEN__)
extern I2SDriver I2SD6;
#endif

#if (SPC5_I2S_USE_DSPI6 == TRUE) && !defined(__DOXYGEN__)
extern I2SDriver I2SD7;
#endif

#if (SPC5_I2S_USE_DSPI7 == TRUE) && !defined(__DOXYGEN__)
extern I2SDriver I2SD8;
#endif

#if (SPC5_I2S_USE_DSPI8 == TRUE) && !defined(__DOXYGEN__)
extern I2SDriver I2SD9;
#endif

#if (SPC5_I2S_USE_DSPI9 == TRUE) && !defined(__DOXYGEN__)
extern I2SDriver I2SD10;
#endif


#ifdef __cplusplus
extern "C" {
#endif
  void i2s_lld_init(void);
  void i2s_lld_start(I2SDriver *i2sp, I2SConfig *config);
  void i2s_lld_stop(I2SDriver *i2sp);
  void i2s_lld_playback(I2SDriver *i2sp, size_t n, void *buffer, int32_t options);
  void i2s_lld_playbackEx(I2SDriver *i2sp, size_t n, void *tx_buf, int32_t options, void *rx_buf);
  void i2s_lld_stop_playback(I2SDriver *i2sp);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_I2S */

#endif /* _I2S_LLD_H_ */

/** @} */

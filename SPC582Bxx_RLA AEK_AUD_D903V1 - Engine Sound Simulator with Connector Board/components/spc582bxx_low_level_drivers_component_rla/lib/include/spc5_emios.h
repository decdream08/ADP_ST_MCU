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
 * @file    spc5_emios.h
 * @brief   SPC5xx ICU-PWM low level drivers common header.
 *
 * @addtogroup SPC5xx_eMIOS
 * @{
 */

#ifndef _SPC5_EMIOS_H_
#define _SPC5_EMIOS_H_

#include "spc5_lld.h"
#include "lldconf.h"

#if (LLD_USE_ICU == TRUE) || (LLD_USE_PWM == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

#define EMIOSMCR_MDIS                       (1UL << 30U)
#define EMIOSMCR_FRZ                        (1UL << 29U)
#define EMIOSMCR_GTBE                       (1UL << 28U)
#define EMIOSMCR_GPREN                      (1UL << 26U)
#define EMIOSMCR_GPRE(n)                    ((uint32_t)(n) << 8U)

#define EMIOSC_FREN                         (1UL << 31U)
#define EMIOSC_UCPRE(n)                     ((uint32_t)(n) << 26U)
#define EMIOSC_UCPREN                       (1UL << 25U)
#define EMIOSC_DMA                          (1UL << 24U)
#define EMIOSC_IF(n)                        ((uint32_t)(n) << 19U)
#define EMIOSC_FCK                          (1UL << 18U)
#define EMIOSC_FEN                          (1UL << 17U)
#define EMIOSC_FORCMA                       (1UL << 13U)
#define EMIOSC_FORCMB                       (1UL << 12U)
#define EMIOSC_BSL(n)                       ((uint32_t)(n) << 9U)
#define EMIOSC_EDSEL                        (1UL << 8U)
#define EMIOSC_EDPOL                        (1UL << 7U)
#define EMIOSC_MODE(n)                      ((uint32_t)(n) << 0U)

#define EMIOS_BSL_COUNTER_BUS_A             0UL
#define EMIOS_BSL_COUNTER_BUS_BCDE          1UL
#define EMIOS_BSL_INTERNAL_COUNTER          3UL

#define EMIOS_CCR_MODE_GPIO_IN              0U
#define EMIOS_CCR_MODE_GPIO_OUT             1U
#define EMIOS_CCR_MODE_SAIC                 2U
#define EMIOS_CCR_MODE_SAOC                 3U
#define EMIOS_CCR_MODE_IPWM                 4U
#define EMIOS_CCR_MODE_IPM                  5U
#define EMIOS_CCR_MODE_DAOC_B_MATCH         6U
#define EMIOS_CCR_MODE_DAOC_BOTH_MATCH      7U
#define EMIOS_CCR_MODE_MC_CMS               16U
#define EMIOS_CCR_MODE_MC_CME               17U
#define EMIOS_CCR_MODE_MC_UP_DOWN           18U
#define EMIOS_CCR_MODE_OPWMT                38U
#define EMIOS_CCR_MODE_MCB_UP               80U
#define EMIOS_CCR_MODE_MCB_UP_DOWN          84U
#define EMIOS_CCR_MODE_OPWFMB               88U
#define EMIOS_CCR_MODE_OPWMCB_TE            92U
#define EMIOS_CCR_MODE_OPWMCB_LE            93U
#define EMIOS_CCR_MODE_OPWMB                96U

#define EMIOSS_OVR                          (1UL << 31U)
#define EMIOSS_OVRC                         (1UL << 31U)
#define EMIOSS_OVFL                         (1UL << 15U)
#define EMIOSS_OVFLC                        (1UL << 15U)
#define EMIOSS_FLAG                         (1UL << 0U)
#define EMIOSS_FLAGC                        (1UL << 0U)

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   EMIOS0 PWM CH0 enable switch.
 * @details If set to @p TRUE the support for PWM CH0 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS0_CH0) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS0_CH0             FALSE
#endif

/**
 * @brief   EMIOS0 PWM CH1 enable switch.
 * @details If set to @p TRUE the support for PWM CH1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS0_CH1) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS0_CH1             FALSE
#endif

/**
 * @brief   EMIOS0 PWM CH2 enable switch.
 * @details If set to @p TRUE the support for PWM CH2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS0_CH2) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS0_CH2             FALSE
#endif

/**
 * @brief   EMIOS0 PWM CH3 enable switch.
 * @details If set to @p TRUE the support for PWM CH3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS0_CH3) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS0_CH3             FALSE
#endif

/**
 * @brief   EMIOS0 PWM CH4 enable switch.
 * @details If set to @p TRUE the support for PWM CH4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS0_CH4) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS0_CH4             FALSE
#endif

/**
 * @brief   EMIOS0 PWM CH5 enable switch.
 * @details If set to @p TRUE the support for PWM CH5 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS0_CH5) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS0_CH5             FALSE
#endif

/**
 * @brief   EMIOS0 PWM CH6 enable switch.
 * @details If set to @p TRUE the support for PWM CH6 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS0_CH6) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS0_CH6             FALSE
#endif

/**
 * @brief   EMIOS0 PWM CH7 enable switch.
 * @details If set to @p TRUE the support for PWM CH7 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS0_CH7) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS0_CH7             FALSE
#endif

/**
 * @brief   ICUD1 driver enable switch.
 * @details If set to @p TRUE the support for ICUD1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS0_CH0) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS0_CH0             FALSE
#endif

/**
 * @brief   ICUD2 driver enable switch.
 * @details If set to @p TRUE the support for ICUD2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS0_CH1) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS0_CH1             FALSE
#endif

/**
 * @brief   ICUD3 driver enable switch.
 * @details If set to @p TRUE the support for ICUD3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS0_CH2) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS0_CH2             FALSE
#endif

/**
 * @brief   ICUD4 driver enable switch.
 * @details If set to @p TRUE the support for ICUD4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS0_CH3) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS0_CH3             FALSE
#endif

/**
 * @brief   ICUD5 driver enable switch.
 * @details If set to @p TRUE the support for ICUD5 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS0_CH4) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS0_CH4             FALSE
#endif

/**
 * @brief   ICUD6 driver enable switch.
 * @details If set to @p TRUE the support for ICUD6 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS0_CH5) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS0_CH5             FALSE
#endif

/**
 * @brief   ICUD7 driver enable switch.
 * @details If set to @p TRUE the support for ICUD7 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS0_CH6) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS0_CH6             FALSE
#endif

/**
 * @brief   ICUD8 driver enable switch.
 * @details If set to @p TRUE the support for ICUD8 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_ICU_USE_EMIOS0_CH7) || defined(__DOXYGEN__)
#define SPC5_ICU_USE_EMIOS0_CH7             FALSE
#endif

/**
 * @brief   EMIOS0 PWM CH9-CH15 enable switch.
 * @details If set to @p TRUE the support for PWM CH9-CH15 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS0_GROUP1) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS0_GROUP1          FALSE
#endif

/**
 * @brief   EMIOS0 PWM CH17-CH23 enable switch.
 * @details If set to @p TRUE the support for PWM CH17-CH23 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS0_GROUP2) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS0_GROUP2          FALSE
#endif

/**
 * @brief   EMIOS0 PWM CH25-CH31 enable switch.
 * @details If set to @p TRUE the support for PWM CH25-CH31 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS0_GROUP3) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS0_GROUP3          FALSE
#endif

/**
 * @brief   EMIOS0 CH0-CH1 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS0_GFR_F0F1_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_GFR_F0F1_PRIORITY       7
#endif

/**
 * @brief   EMIOS0 CH2-CH3 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS0_GFR_F2F3_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_GFR_F2F3_PRIORITY       7
#endif

/**
 * @brief   EMIOS0 CH4-CH5 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS0_GFR_F4F5_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_GFR_F4F5_PRIORITY       7
#endif

/**
 * @brief   EMIOS0 CH6-CH7 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS0_GFR_F6F7_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_GFR_F6F7_PRIORITY       7
#endif

/**
 * @brief   EMIOS0 CH8-CH9 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS0_GFR_F8F9_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_GFR_F8F9_PRIORITY       7
#endif

/**
 * @brief   EMIOS0 CH10-CH11 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS0_GFR_F10F11_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_GFR_F10F11_PRIORITY     7
#endif

/**
 * @brief   EMIOS0 CH12-CH13 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS0_GFR_F12F13_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_GFR_F12F13_PRIORITY     7
#endif

/**
 * @brief   EMIOS0 CH14-CH15 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS0_GFR_F14F15_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_GFR_F14F15_PRIORITY     7
#endif

/**
 * @brief   EMIOS0 CH16-CH17 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS0_GFR_F16F17_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_GFR_F16F17_PRIORITY     7
#endif

/**
 * @brief   EMIOS0 CH18-CH19 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS0_GFR_F18F19_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_GFR_F18F19_PRIORITY     7
#endif

/**
 * @brief   EMIOS0 CH20-CH21 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS0_GFR_F20F21_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_GFR_F20F21_PRIORITY     7
#endif

/**
 * @brief   EMIOS0 CH22-CH23 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS0_GFR_F22F23_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_GFR_F22F23_PRIORITY     7
#endif

/**
 * @brief   EMIOS0 CH24-CH25 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS0_GFR_F24F25_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_GFR_F24F25_PRIORITY     7
#endif

/**
 * @brief   EMIOS0 CH26-CH27 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS0_GFR_F26F27_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_GFR_F26F27_PRIORITY     7
#endif

/**
 * @brief   EMIOS0 CH28-CH29 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS0_GFR_F28F29_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_GFR_F28F29_PRIORITY     7
#endif

/**
 * @brief   EMIOS0 CH30-CH31 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS0_GFR_F30F31_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_GFR_F30F31_PRIORITY     7
#endif

/**
 * @brief   eMIOS0 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_EMIOS0_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_START_PCTL              (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   eMIOS0 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(SPC5_EMIOS0_STOP_PCTL) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_STOP_PCTL               (SPC5_ME_PCTL_RUN(0) |          \
                                             SPC5_ME_PCTL_LP(0))
#endif

/**
 * @brief   eMIOS0 global prescaler value.
 */
#if !defined(SPC5_EMIOS0_GPRE_VALUE) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_GPRE_VALUE              20UL
#endif

/* Check on the SPC5_EMIOS0_GPRE_VALUE.*/
#if (SPC5_EMIOS0_GPRE_VALUE < 1U) || (SPC5_EMIOS0_GPRE_VALUE > 256U)
#error "invalid SPC5_EMIOS0_GPRE_VALUE value specified"
#endif

/**
 * @brief   EMIOS1 PWM CH1-CH7 enable switch.
 * @details If set to @p TRUE the support for PWM CH1-CH7 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS1_GROUP0) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS1_GROUP0          FALSE
#endif

/**
 * @brief   EMIOS1 PWM CH9-CH15 enable switch.
 * @details If set to @p TRUE the support for PWM CH9-CH15 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS1_GROUP1) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS1_GROUP1          FALSE
#endif

/**
 * @brief   EMIOS1 PWM CH17-CH23 enable switch.
 * @details If set to @p TRUE the support for PWM CH17-CH23 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS1_GROUP2) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS1_GROUP2          FALSE
#endif

/**
 * @brief   EMIOS1 PWM CH25-CH31 enable switch.
 * @details If set to @p TRUE the support for PWM CH25-CH31 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS1_GROUP3) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS1_GROUP3          FALSE
#endif

/**
 * @brief   EMIOS1 CH0-CH1 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS1_GFR_F0F1_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_GFR_F0F1_PRIORITY       7
#endif

/**
 * @brief   EMIOS1 CH2-CH3 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS1_GFR_F2F3_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_GFR_F2F3_PRIORITY       7
#endif

/**
 * @brief   EMIOS1 CH4-CH5 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS1_GFR_F4F5_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_GFR_F4F5_PRIORITY       7
#endif

/**
 * @brief   EMIOS1 CH6-CH7 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS1_GFR_F6F7_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_GFR_F6F7_PRIORITY       7
#endif

/**
 * @brief   EMIOS1 CH8-CH9 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS1_GFR_F8F9_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_GFR_F8F9_PRIORITY       7
#endif

/**
 * @brief   EMIOS1 CH10-CH11 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS1_GFR_F10F11_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_GFR_F10F11_PRIORITY     7
#endif

/**
 * @brief   EMIOS1 CH12-CH13 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS1_GFR_F12F13_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_GFR_F12F13_PRIORITY     7
#endif

/**
 * @brief   EMIOS1 CH14-CH15 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS1_GFR_F14F15_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_GFR_F14F15_PRIORITY     7
#endif

/**
 * @brief   EMIOS1 CH16-CH17 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS1_GFR_F16F17_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_GFR_F16F17_PRIORITY     7
#endif

/**
 * @brief   EMIOS1 CH18-CH19 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS1_GFR_F18F19_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_GFR_F18F19_PRIORITY     7
#endif

/**
 * @brief   EMIOS1 CH20-CH21 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS1_GFR_F20F21_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_GFR_F20F21_PRIORITY     7
#endif

/**
 * @brief   EMIOS1 CH22-CH23 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS1_GFR_F22F23_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_GFR_F22F23_PRIORITY     7
#endif

/**
 * @brief   EMIOS1 CH24-CH25 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS1_GFR_F24F25_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_GFR_F24F25_PRIORITY     7
#endif

/**
 * @brief   EMIOS1 CH26-CH27 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS1_GFR_F26F27_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_GFR_F26F27_PRIORITY     7
#endif

/**
 * @brief   EMIOS1 CH28-CH29 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS1_GFR_F28F29_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_GFR_F28F29_PRIORITY     7
#endif

/**
 * @brief   EMIOS1 CH30-CH31 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS1_GFR_F30F31_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_GFR_F30F31_PRIORITY     7
#endif

/**
 * @brief   eMIOS1 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_EMIOS1_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_START_PCTL              (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   eMIOS1 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(SPC5_EMIOS1_STOP_PCTL) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_STOP_PCTL               (SPC5_ME_PCTL_RUN(0) |          \
                                             SPC5_ME_PCTL_LP(0))
#endif

/**
 * @brief   eMIOS1 global prescaler value.
 */
#if !defined(SPC5_EMIOS1_GPRE_VALUE) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_GPRE_VALUE              20UL
#endif

/* Check on the SPC5_EMIOS1_GPRE_VALUE.*/
#if (SPC5_EMIOS1_GPRE_VALUE < 1U) || (SPC5_EMIOS1_GPRE_VALUE > 256U)
#error "invalid SPC5_EMIOS1_GPRE_VALUE value specified"
#endif

/**
 * @brief   EMIOS2 PWM CH1-CH7 enable switch.
 * @details If set to @p TRUE the support for PWM CH1-CH7 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS2_GROUP0) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS2_GROUP0          FALSE
#endif

/**
 * @brief   EMIOS2 PWM CH9-CH15 enable switch.
 * @details If set to @p TRUE the support for PWM CH9-CH15 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS2_GROUP1) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS2_GROUP1          FALSE
#endif

/**
 * @brief   EMIOS2 PWM CH17-CH23 enable switch.
 * @details If set to @p TRUE the support for PWM CH17-CH23 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS2_GROUP2) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS2_GROUP2          FALSE
#endif

/**
 * @brief   EMIOS2 PWM CH25-CH31 enable switch.
 * @details If set to @p TRUE the support for PWM CH25-CH31 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(SPC5_PWM_USE_EMIOS2_GROUP3) || defined(__DOXYGEN__)
#define SPC5_PWM_USE_EMIOS2_GROUP3          FALSE
#endif

/**
 * @brief   EMIOS2 CH0-CH1 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS2_GFR_F0F1_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_GFR_F0F1_PRIORITY       7
#endif

/**
 * @brief   EMIOS2 CH2-CH3 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS2_GFR_F2F3_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_GFR_F2F3_PRIORITY       7
#endif

/**
 * @brief   EMIOS2 CH4-CH5 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS2_GFR_F4F5_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_GFR_F4F5_PRIORITY       7
#endif

/**
 * @brief   EMIOS2 CH6-CH7 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS2_GFR_F6F7_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_GFR_F6F7_PRIORITY       7
#endif

/**
 * @brief   EMIOS2 CH8-CH9 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS2_GFR_F8F9_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_GFR_F8F9_PRIORITY       7
#endif

/**
 * @brief   EMIOS2 CH10-CH11 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS2_GFR_F10F11_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_GFR_F10F11_PRIORITY     7
#endif

/**
 * @brief   EMIOS2 CH12-CH13 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS2_GFR_F12F13_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_GFR_F12F13_PRIORITY     7
#endif

/**
 * @brief   EMIOS2 CH14-CH15 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS2_GFR_F14F15_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_GFR_F14F15_PRIORITY     7
#endif

/**
 * @brief   EMIOS2 CH16-CH17 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS2_GFR_F16F17_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_GFR_F16F17_PRIORITY     7
#endif

/**
 * @brief   EMIOS2 CH18-CH19 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS2_GFR_F18F19_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_GFR_F18F19_PRIORITY     7
#endif

/**
 * @brief   EMIOS2 CH20-CH21 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS2_GFR_F20F21_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_GFR_F20F21_PRIORITY     7
#endif

/**
 * @brief   EMIOS2 CH22-CH23 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS2_GFR_F22F23_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_GFR_F22F23_PRIORITY     7
#endif

/**
 * @brief   EMIOS2 CH24-CH25 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS2_GFR_F24F25_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_GFR_F24F25_PRIORITY     7
#endif

/**
 * @brief   EMIOS2 CH26-CH27 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS2_GFR_F26F27_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_GFR_F26F27_PRIORITY     7
#endif

/**
 * @brief   EMIOS2 CH28-CH29 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS2_GFR_F28F29_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_GFR_F28F29_PRIORITY     7
#endif

/**
 * @brief   EMIOS2 CH30-CH31 interrupt priority level setting.
 */
#if !defined(SPC5_EMIOS2_GFR_F30F31_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_GFR_F30F31_PRIORITY     7
#endif

/**
 * @brief   eMIOS2 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_EMIOS2_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_START_PCTL              (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   eMIOS2 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(SPC5_EMIOS2_STOP_PCTL) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_STOP_PCTL               (SPC5_ME_PCTL_RUN(0) |          \
                                             SPC5_ME_PCTL_LP(0))
#endif

/**
 * @brief   eMIOS2 global prescaler value.
 */
#if !defined(SPC5_EMIOS2_GPRE_VALUE) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_GPRE_VALUE              20UL
#endif

/* Check on the SPC5_EMIOS2_GPRE_VALUE.*/
#if (SPC5_EMIOS2_GPRE_VALUE < 1U) || (SPC5_EMIOS2_GPRE_VALUE > 256U)
#error "invalid SPC5_EMIOS2_GPRE_VALUE value specified"
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/* PPC register definitions not compatible with MISRA rules on bit-fields 
   (Rules 6.1). */
/*lint -e46 */
struct spc5_emios {
  union {
    vuint32_t R;
    struct {
      vuint32_t unused_3:1;
      vuint32_t MDIS:1;
      vuint32_t FRZ:1;
      vuint32_t GTBE:1;
      vuint32_t unused_2:1;
      vuint32_t GPREN:1;
      vuint32_t unused_1:10;
      vuint32_t GPRE:8;
      vuint32_t unused_0:8;
    } B;
  } MCR;

  union {
    vuint32_t R;
    struct {
      vuint32_t F31:1;
      vuint32_t F30:1;
      vuint32_t F29:1;
      vuint32_t F28:1;
      vuint32_t F27:1;
      vuint32_t F26:1;
      vuint32_t F25:1;
      vuint32_t F24:1;
      vuint32_t F23:1;
      vuint32_t F22:1;
      vuint32_t F21:1;
      vuint32_t F20:1;
      vuint32_t F19:1;
      vuint32_t F18:1;
      vuint32_t F17:1;
      vuint32_t F16:1;
      vuint32_t F15:1;
      vuint32_t F14:1;
      vuint32_t F13:1;
      vuint32_t F12:1;
      vuint32_t F11:1;
      vuint32_t F10:1;
      vuint32_t F9:1;
      vuint32_t F8:1;
      vuint32_t F7:1;
      vuint32_t F6:1;
      vuint32_t F5:1;
      vuint32_t F4:1;
      vuint32_t F3:1;
      vuint32_t F2:1;
      vuint32_t F1:1;
      vuint32_t F0:1;
    } B;
  } GFLAG;

  union {
    vuint32_t R;
    struct {
      vuint32_t OU31:1;
      vuint32_t OU30:1;
      vuint32_t OU29:1;
      vuint32_t OU28:1;
      vuint32_t OU27:1;
      vuint32_t OU26:1;
      vuint32_t OU25:1;
      vuint32_t OU24:1;
      vuint32_t OU23:1;
      vuint32_t OU22:1;
      vuint32_t OU21:1;
      vuint32_t OU20:1;
      vuint32_t OU19:1;
      vuint32_t OU18:1;
      vuint32_t OU17:1;
      vuint32_t OU16:1;
      vuint32_t OU15:1;
      vuint32_t OU14:1;
      vuint32_t OU13:1;
      vuint32_t OU12:1;
      vuint32_t OU11:1;
      vuint32_t OU10:1;
      vuint32_t OU9:1;
      vuint32_t OU8:1;
      vuint32_t OU7:1;
      vuint32_t OU6:1;
      vuint32_t OU5:1;
      vuint32_t OU4:1;
      vuint32_t OU3:1;
      vuint32_t OU2:1;
      vuint32_t OU1:1;
      vuint32_t OU0:1;
    } B;
  } OUDIS;

  union {
    vuint32_t R;
    struct {
      vuint32_t CHDIS31:1;
      vuint32_t CHDIS30:1;
      vuint32_t CHDIS29:1;
      vuint32_t CHDIS28:1;
      vuint32_t CHDIS27:1;
      vuint32_t CHDIS26:1;
      vuint32_t CHDIS25:1;
      vuint32_t CHDIS24:1;
      vuint32_t CHDIS23:1;
      vuint32_t CHDIS22:1;
      vuint32_t CHDIS21:1;
      vuint32_t CHDIS20:1;
      vuint32_t CHDIS19:1;
      vuint32_t CHDIS18:1;
      vuint32_t CHDIS17:1;
      vuint32_t CHDIS16:1;
      vuint32_t CHDIS15:1;
      vuint32_t CHDIS14:1;
      vuint32_t CHDIS13:1;
      vuint32_t CHDIS12:1;
      vuint32_t CHDIS11:1;
      vuint32_t CHDIS10:1;
      vuint32_t CHDIS9:1;
      vuint32_t CHDIS8:1;
      vuint32_t CHDIS7:1;
      vuint32_t CHDIS6:1;
      vuint32_t CHDIS5:1;
      vuint32_t CHDIS4:1;
      vuint32_t CHDIS3:1;
      vuint32_t CHDIS2:1;
      vuint32_t CHDIS1:1;
      vuint32_t CHDIS0:1;
    } B;
  } UCDIS;

  vuint8_t ADR_reserved0[16];

  struct {
    union {
      vuint32_t R;
      struct {
        vuint32_t unused_0:16;
        vuint32_t A:16;
      } B;
    } A;

    union {
      vuint32_t R;
      struct {
        vuint32_t unused_0:16;
        vuint32_t B:16;
      } B;
    } B;

    union {
      vuint32_t R;
      struct {
        vuint32_t unused_0:16;
        vuint32_t C:16;
      } B;
    } CNT;

    union {
      vuint32_t R;
      struct {
        vuint32_t FREN:1;
        vuint32_t ODIS:1;
        vuint32_t ODISSL:2;
        vuint32_t UCPRE:2;
        vuint32_t UCPREN:1;
        vuint32_t DMA:1;
        vuint32_t unused_2:1;
        vuint32_t IF:4;
        vuint32_t FCK:1;
        vuint32_t FEN:1;
        vuint32_t unused_1:3;
        vuint32_t FORCMA:1;
        vuint32_t FORCMB:1;
        vuint32_t unused_0:1;
        vuint32_t BSL:2;
        vuint32_t EDSEL:1;
        vuint32_t EDPOL:1;
        vuint32_t MODE:7;
      } B;
    } C;

    union {
      vuint32_t R;
      struct {
        vuint32_t OVR:1;
        vuint32_t unused_1:15;
        vuint32_t OVFL:1;
        vuint32_t unused_0:12;
        vuint32_t UCIN:1;
        vuint32_t UCOUT:1;
        vuint32_t FLAG:1;
      } B;
    } S;

    union {
      vuint32_t R;
      struct {
        vuint32_t unused_0:16;
        vuint32_t ALTA:16;
      } B;
    } ALTA;

    vuint8_t EMIOS_reserved1[8];

  } CH[32];
};
/*lint +e46 */

/**
 * @brief   Type of a structure representing the EMIOS data.
 */
typedef struct EMIOSData EMIOSData;

/**
 * @brief   Structure representing the EMIOS data.
 */
struct EMIOSData {
  /**
   * @brief Number of eMIOSx active channels.
   */
  uint32_t                  emios_active_channels;
  /**
   * @brief Pointer to the eMIOSx registers block.
   */
  volatile struct spc5_emios *emiosp;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @name    eTIMER units references
 * @{
 */
#if (SPC5_HAS_EMIOS0 == TRUE) || defined(__DOXYGEN__)
#define SPC5_EMIOS_0        (*(volatile struct spc5_emios *)SPC5_EMIOS0_BASE)
#endif

#if (SPC5_HAS_EMIOS1 == TRUE) || defined(__DOXYGEN__)
#define SPC5_EMIOS_1        (*(volatile struct spc5_emios *)SPC5_EMIOS1_BASE)
#endif

#if (SPC5_HAS_EMIOS2 == TRUE) || defined(__DOXYGEN__)
#define SPC5_EMIOS_2        (*(volatile struct spc5_emios *)SPC5_EMIOS2_BASE)
#endif
/** @} */

/*===========================================================================*/
/* IRQ Handlers                                                              */
/*===========================================================================*/

#if (SPC5_ICU_USE_EMIOS0_CH0 == TRUE) || (SPC5_ICU_USE_EMIOS0_CH1 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_CH0 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH1 == TRUE)
IRQ_HANDLER(SPC5_EMIOS0_GFR_F0F1_HANDLER);
#endif

#if (SPC5_ICU_USE_EMIOS0_CH2 == TRUE) || (SPC5_ICU_USE_EMIOS0_CH3 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_CH2 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH3 == TRUE)
IRQ_HANDLER(SPC5_EMIOS0_GFR_F2F3_HANDLER);
#endif

#if (SPC5_ICU_USE_EMIOS0_CH4 == TRUE) || (SPC5_ICU_USE_EMIOS0_CH5 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_CH4 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH5 == TRUE)
IRQ_HANDLER(SPC5_EMIOS0_GFR_F4F5_HANDLER);
#endif

#if (SPC5_ICU_USE_EMIOS0_CH6 == TRUE) || (SPC5_ICU_USE_EMIOS0_CH7 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_CH6 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH7 == TRUE)
IRQ_HANDLER(SPC5_EMIOS0_GFR_F6F7_HANDLER);
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE)
IRQ_HANDLER(SPC5_EMIOS0_GFR_F8F9_HANDLER);
IRQ_HANDLER(SPC5_EMIOS0_GFR_F10F11_HANDLER);
IRQ_HANDLER(SPC5_EMIOS0_GFR_F12F13_HANDLER);
IRQ_HANDLER(SPC5_EMIOS0_GFR_F14F15_HANDLER);
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE)
IRQ_HANDLER(SPC5_EMIOS0_GFR_F16F17_HANDLER);
IRQ_HANDLER(SPC5_EMIOS0_GFR_F18F19_HANDLER);
IRQ_HANDLER(SPC5_EMIOS0_GFR_F20F21_HANDLER);
IRQ_HANDLER(SPC5_EMIOS0_GFR_F22F23_HANDLER);
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE)
IRQ_HANDLER(SPC5_EMIOS0_GFR_F24F25_HANDLER);
IRQ_HANDLER(SPC5_EMIOS0_GFR_F26F27_HANDLER);
IRQ_HANDLER(SPC5_EMIOS0_GFR_F28F29_HANDLER);
IRQ_HANDLER(SPC5_EMIOS0_GFR_F30F31_HANDLER);
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE)
IRQ_HANDLER(SPC5_EMIOS1_GFR_F0F1_HANDLER);
IRQ_HANDLER(SPC5_EMIOS1_GFR_F2F3_HANDLER);
IRQ_HANDLER(SPC5_EMIOS1_GFR_F4F5_HANDLER);
IRQ_HANDLER(SPC5_EMIOS1_GFR_F6F7_HANDLER);
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE)
IRQ_HANDLER(SPC5_EMIOS1_GFR_F8F9_HANDLER);
IRQ_HANDLER(SPC5_EMIOS1_GFR_F10F11_HANDLER);
IRQ_HANDLER(SPC5_EMIOS1_GFR_F12F13_HANDLER);
IRQ_HANDLER(SPC5_EMIOS1_GFR_F14F15_HANDLER);
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE)
IRQ_HANDLER(SPC5_EMIOS1_GFR_F16F17_HANDLER);
IRQ_HANDLER(SPC5_EMIOS1_GFR_F18F19_HANDLER);
IRQ_HANDLER(SPC5_EMIOS1_GFR_F20F21_HANDLER);
IRQ_HANDLER(SPC5_EMIOS1_GFR_F22F23_HANDLER);
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE)
IRQ_HANDLER(SPC5_EMIOS1_GFR_F24F25_HANDLER);
IRQ_HANDLER(SPC5_EMIOS1_GFR_F26F27_HANDLER);
IRQ_HANDLER(SPC5_EMIOS1_GFR_F28F29_HANDLER);
IRQ_HANDLER(SPC5_EMIOS1_GFR_F30F31_HANDLER);
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE)
IRQ_HANDLER(SPC5_EMIOS2_GFR_F0F1_HANDLER);
IRQ_HANDLER(SPC5_EMIOS2_GFR_F2F3_HANDLER);
IRQ_HANDLER(SPC5_EMIOS2_GFR_F4F5_HANDLER);
IRQ_HANDLER(SPC5_EMIOS2_GFR_F6F7_HANDLER);
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE)
IRQ_HANDLER(SPC5_EMIOS2_GFR_F8F9_HANDLER);
IRQ_HANDLER(SPC5_EMIOS2_GFR_F10F11_HANDLER);
IRQ_HANDLER(SPC5_EMIOS2_GFR_F12F13_HANDLER);
IRQ_HANDLER(SPC5_EMIOS2_GFR_F14F15_HANDLER);
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE)
IRQ_HANDLER(SPC5_EMIOS2_GFR_F16F17_HANDLER);
IRQ_HANDLER(SPC5_EMIOS2_GFR_F18F19_HANDLER);
IRQ_HANDLER(SPC5_EMIOS2_GFR_F20F21_HANDLER);
IRQ_HANDLER(SPC5_EMIOS2_GFR_F22F23_HANDLER);
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
IRQ_HANDLER(SPC5_EMIOS2_GFR_F24F25_HANDLER);
IRQ_HANDLER(SPC5_EMIOS2_GFR_F26F27_HANDLER);
IRQ_HANDLER(SPC5_EMIOS2_GFR_F28F29_HANDLER);
IRQ_HANDLER(SPC5_EMIOS2_GFR_F30F31_HANDLER);
#endif

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (SPC5_HAS_EMIOS0 == TRUE) && !defined(__DOXYGEN__)
extern EMIOSData EMIOS0D;
#endif

#if (SPC5_HAS_EMIOS1 == TRUE) && !defined(__DOXYGEN__)
extern EMIOSData EMIOS1D;
#endif

#if (SPC5_HAS_EMIOS2 == TRUE) && !defined(__DOXYGEN__)
extern EMIOSData EMIOS2D;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void emios_enable_clock(EMIOSData *emiosdp);
  void emios_disable_clock(EMIOSData *emiosdp);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_ICU || LLD_USE_PWM */

#endif /* _SPC5_EMIOS_H_ */

/** @} */

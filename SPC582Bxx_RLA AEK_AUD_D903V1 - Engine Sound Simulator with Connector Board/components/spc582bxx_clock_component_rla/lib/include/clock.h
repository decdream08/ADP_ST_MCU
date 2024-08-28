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
 * @file    clock.h
 * @brief   SPC582Bxx clock subsystem header
 *
 * @addtogroup CLOCK
 * @{
 */

#ifndef _CLOCK_H_
#define _CLOCK_H_

#include "platform.h"
#include "irq.h"
#include "clock_cfg.h"

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @name    Common constants
 * @{
 */
#if !defined(FALSE) || defined(__DOXYGEN__)
#define FALSE                               0
#endif

#if !defined(TRUE) || defined(__DOXYGEN__)
#define TRUE                                1
#endif

#define CLOCK_SUCCESS                       0U
#define CLOCK_FAILED                        1U
/** @} */

/**
 * @name    Absolute Maximum Ratings
 * @{
 */
/**
 * @brief   Maximum XOSC clock frequency.
 */
#define SPC5_XOSC_CLK_MAX                   44000000U

/**
 * @brief   Minimum XOSC clock frequency.
 */
#define SPC5_XOSC_CLK_MIN                   8000000U

/**
 * @brief   Minimum PLL0 input clock frequency.
 */
#define SPC5_PLL0IN_MIN                     8000000U

/**
 * @brief   Maximum PLL0 input clock frequency.
 */
#define SPC5_PLL0IN_MAX                     44000000U

/**
 * @brief   Minimum PLL1 input clock frequency.
 */
#define SPC5_PLL1IN_MIN                     37500000U

/**
 * @brief   Maximum PLL1 input clock frequency.
 */
#define SPC5_PLL1IN_MAX                     87500000U

/**
 * @brief   Maximum PLL0 VCO clock frequency.
 */
#define SPC5_PLL0VCO_MAX                    1400000000U

/**
 * @brief   Minimum PLL0 VCO clock frequency.
 */
#define SPC5_PLL0VCO_MIN                    600000000U

/**
 * @brief   Maximum PLL1 VCO clock frequency.
 */
#define SPC5_PLL1VCO_MAX                    1400000000U

/**
 * @brief   Minimum PLL1 VCO clock frequency.
 */
#define SPC5_PLL1VCO_MIN                    600000000U

/**
 * @brief   Maximum PLL0 output clock frequency.
 */
#define SPC5_PLL0_CLK_MAX                   400000000U

/**
 * @brief   Minimum PLL0 output clock frequency.
 */
#define SPC5_PLL0_CLK_MIN                   4762000U

/**
 * @brief   Maximum PLL1 output clock frequency.
 */
#define SPC5_PLL1_CLK_MAX                   80000000U

/**
 * @brief   Minimum PLL1 output clock frequency.
 */
#define SPC5_PLL1_CLK_MIN                   4762000U

/**
 * @brief   Maximum SC DC2 clock frequency.
 */
#define SPC5_PBRIDGE_CLK_MAX                40000000U

/**
 * @brief   Maximum AC0 DC0 clock frequency.
 */
#define SPC5_SARADC_CLK_MAX                 16000000U

/**
 * @brief   Maximum AC0 DC1 clock frequency.
 */
#define SPC5_EMIOS_CLK_MAX                  40000000U

/**
 * @brief   Maximum AC6 DC0 clock frequency.
 */
#define SPC5_SYSCLK0_MAX                    20000000U

/**
 * @brief   Maximum AC8 DC0 clock frequency.
 */
#define SPC5_CANCLK0_MAX                    80000000U

/**
 * @brief   Maximum AC9 DC0 clock frequency.
 */
#define SPC5_RTI_CLK_MAX                    40000000U

/**
 * @brief   Maximum AC11 DC0 clock frequency.
 */
#define SPC5_CANCLK1_MAX                    80000000U

/**
 * @brief   Maximum AC12 DC0 clock frequency.
 */
#define SPC5_DSPI_CLK_MAX                   80000000U

/**
 * @brief   Maximum AC12 DC1 clock frequency.
 */
#define SPC5_LIN_CLK_MAX                    80000000U

/**
 * @brief   Maximum AC12 DC2 clock frequency.
 */
#define SPC5_PER_CLK_MAX                    80000000U
/** @} */

/**
 * @name    Internal clock sources
 * @{
 */
#define SPC5_IRC_CLK                        16000000U
/** @} */

/**
 * @name    PLL0 registers bits definitions
 * @{
 */
#define SPC5_PLL0_CR_CLKCFG_MASK            (3UL << 8)
#define SPC5_PLL0_CR_CLKCFG_OFF             (0UL << 8)
#define SPC5_PLL0_CR_CLKCFG_RUNNING         (3UL << 8)
#define SPC5_PLL0_CR_EXPDIE                 (1UL << 7)
#define SPC5_PLL0_CR_LOLIE                  (1UL << 3)

#define SPC5_PLL0_SR_EXTPDF                 (1UL << 7)
#define SPC5_PLL0_SR_LOLF                   (1UL << 3)
#define SPC5_PLL0_SR_LOCK                   (1UL << 2)

#define SPC5_PLL0_DV_RFDPHI1_MASK           (15UL << 27)
#define SPC5_PLL0_DV_RFDPHI1(n)             (((uint32_t)(n)) << 27)

#define SPC5_PLL0_DV_RFDPHI_MASK            (63UL << 16)
#define SPC5_PLL0_DV_RFDPHI(n)              (((uint32_t)(n)) << 16)

#define SPC5_PLL0_DV_PREDIV_MASK            (15UL << 12)
#define SPC5_PLL0_DV_PREDIV(n)              (((uint32_t)(n)) << 12)

#define SPC5_PLL0_DV_MFD_MASK               (127UL << 0)
#define SPC5_PLL0_DV_MFD(n)                 (((uint32_t)(n)) << 0)
/** @} */

/**
 * @name    PLL1 registers bits definitions
 * @{
 */
#define SPC5_PLL1_CR_CLKCFG_MASK            (3UL << 8)
#define SPC5_PLL1_CR_CLKCFG_OFF             (0UL << 8)
#define SPC5_PLL1_CR_CLKCFG_RUNNING         (3UL << 8)
#define SPC5_PLL1_CR_EXPDIE                 (1UL << 7)
#define SPC5_PLL1_CR_LOLIE                  (1UL << 3)

#define SPC5_PLL1_SR_EXTPDF                 (1UL << 7)
#define SPC5_PLL1_SR_LOLF                   (1UL << 3)
#define SPC5_PLL1_SR_LOCK                   (1UL << 2)

#define SPC5_PLL1_DV_RFDPHI_MASK            (63UL << 16)
#define SPC5_PLL1_DV_RFDPHI(n)              (((uint32_t)(n)) << 16)

#define SPC5_PLL1_DV_MFD_MASK               (127UL << 0)
#define SPC5_PLL1_DV_MFD(n)                 (((uint32_t)(n)) << 0)

#define SPC5_PLL1_FM_MODEN                  (1UL << 30)
#define SPC5_PLL1_FM_MODSEL                 (1UL << 29)
#define SPC5_PLL1_FM_MODPRD_MASK            (0x1FFFUL << 16)
#define SPC5_PLL1_FM_INCSTP_MASK            (0x7FFFUL << 0)

#define SPC5_PLL1_FD_FDEN                   (1UL << 30)
#define SPC5_PLL1_FD_DTHDIS_MASK            (3UL << 16)
#define SPC5_PLL1_FD_DTHDIS(n)              (((uint32_t)(n)) << 16)
#define SPC5_PLL1_FD_FRCDIV_MASK            (0xFFFL << 0)
#define SPC5_PLL1_FD_FRCDIV(n)              (((uint32_t)(n)) << 0)
/** @} */

/**
 * @name    Clock selectors used in the various GCM SC registers
 * @{
 */
#define SPC5_CGM_SC_MASK                    (15UL << 24)
#define SPC5_CGM_SC_IRC                     (0UL << 24)
#define SPC5_CGM_SC_XOSC                    (1UL << 24)
#define SPC5_CGM_SC_PLL0PHI                 (2UL << 24)
#define SPC5_CGM_SC_PLL0PHI1                (3UL << 24)
#define SPC5_CGM_SC_PLL1PHI                 (4UL << 24)
#define SPC5_CGM_SC_LFAST                   (5UL << 24)
#define SPC5_CGM_SC_RTC_CLK                 (6UL << 24)
/** @} */

/**
 * @name    Clock dividers used in the CGM_AC12_DC0.DIV_FMT field
 * @{
 */
#define SPC5_CGM_DIV_FMT_DIV1               (0UL << 0)
#define SPC5_CGM_DIV_FMT_DIV10              (1UL << 0)
#define SPC5_CGM_DIV_FMT_DIV100             (2UL << 0)
#define SPC5_CGM_DIV_FMT_DIV1000            (3UL << 0)
/** @} */

/**
 * @name    RTC clock selector
 * @{
 */
#define SPC5_RTCC_CLKSEL_LPRC               1U
#define SPC5_RTCC_CLKSEL_IRC                2U
/** @} */

/**
 * @name    ME_GS register bits definitions
 * @{
 */
#define SPC5_ME_GS_SYSCLK_MASK              (15UL << 0)
#define SPC5_ME_GS_SYSCLK_IRC               (0UL << 0)
#define SPC5_ME_GS_SYSCLK_XOSC              (1UL << 0)
#define SPC5_ME_GS_SYSCLK_PLL0PHI           (2UL << 0)
#define SPC5_ME_GS_SYSCLK_PLL1PHI           (4UL << 0)
/** @} */

/**
 * @name    ME_ME register bits definitions
 * @{
 */
#define SPC5_ME_ME_RESET                    (1UL << 0)
#define SPC5_ME_ME_TEST                     (1UL << 1)
#define SPC5_ME_ME_SAFE                     (1UL << 2)
#define SPC5_ME_ME_DRUN                     (1UL << 3)
#define SPC5_ME_ME_RUN0                     (1UL << 4)
#define SPC5_ME_ME_RUN1                     (1UL << 5)
#define SPC5_ME_ME_RUN2                     (1UL << 6)
#define SPC5_ME_ME_RUN3                     (1UL << 7)
#define SPC5_ME_ME_HALT0                    (1UL << 8)
#define SPC5_ME_ME_STOP0                    (1UL << 10)
#define SPC5_ME_ME_STANDBY0                 (1UL << 13)
/** @} */

/**
 * @name    ME_CCTLx register bits definitions
 * @{
 */
#define SPC5_ME_CCTL_RESET                  (1U << 0)
#define SPC5_ME_CCTL_TEST                   (1U << 1)
#define SPC5_ME_CCTL_SAFE                   (1U << 2)
#define SPC5_ME_CCTL_DRUN                   (1U << 3)
#define SPC5_ME_CCTL_RUN0                   (1U << 4)
#define SPC5_ME_CCTL_RUN1                   (1U << 5)
#define SPC5_ME_CCTL_RUN2                   (1U << 6)
#define SPC5_ME_CCTL_RUN3                   (1U << 7)
#define SPC5_ME_CCTL_HALT0                  (1U << 8)
#define SPC5_ME_CCTL_STOP0                  (1U << 10)
#define SPC5_ME_CCTL_STANDBY0               (1U << 13)
/** @} */

/**
 * @name    ME_xxx_MC registers bits definitions
 * @{
 */
#define SPC5_ME_MC_SYSCLK_MASK              (15UL << 0)
#define SPC5_ME_MC_SYSCLK(n)                (((uint32_t)(n)) << 0)
#define SPC5_ME_MC_SYSCLK_IRC               SPC5_ME_MC_SYSCLK(0)
#define SPC5_ME_MC_SYSCLK_XOSC              SPC5_ME_MC_SYSCLK(1)
#define SPC5_ME_MC_SYSCLK_PLL0PHI           SPC5_ME_MC_SYSCLK(2)
#define SPC5_ME_MC_SYSCLK_PLL1PHI           SPC5_ME_MC_SYSCLK(4)
#define SPC5_ME_MC_SYSCLK_DISABLED          SPC5_ME_MC_SYSCLK(15)
#define SPC5_ME_MC_IRCON                    (1UL << 4)
#define SPC5_ME_MC_XOSCON                   (1UL << 5)
#define SPC5_ME_MC_PLL0ON                   (1UL << 6)
#define SPC5_ME_MC_PLL1ON                   (1UL << 7)
#define SPC5_ME_MC_FLAON_MASK               (3UL << 16)
#define SPC5_ME_MC_FLAON(n)                 (((uint32_t)(n)) << 16)
#define SPC5_ME_MC_FLAON_PD                 SPC5_ME_MC_FLAON(1)
#define SPC5_ME_MC_FLAON_LP                 SPC5_ME_MC_FLAON(2)
#define SPC5_ME_MC_FLAON_NORMAL             SPC5_ME_MC_FLAON(3)
#define SPC5_ME_MC_MVRON                    (1UL << 20)
#define SPC5_ME_MC_PDO                      (1UL << 23)
#define SPC5_ME_MC_PWRLVL_MASK              (7UL << 28)
#define SPC5_ME_MC_PWRLVL(n)                (((uint32_t)(n)) << 28)
/** @} */

/**
 * @name    ME_MCTL register bits definitions
 * @{
 */
#define SPC5_ME_MCTL_KEY                    0x5AF0UL
#define SPC5_ME_MCTL_KEY_INV                0xA50FUL
#define SPC5_ME_MCTL_MODE_MASK              (15UL << 28)
#define SPC5_ME_MCTL_MODE(n)                (((uint32_t)(n)) << 28)
/** @} */

/**
 * @name    ME_RUN_PCx registers bits definitions
 * @{
 */
#define SPC5_ME_RUN_PC_SAFE                 (1UL << 2)
#define SPC5_ME_RUN_PC_DRUN                 (1UL << 3)
#define SPC5_ME_RUN_PC_RUN0                 (1UL << 4)
#define SPC5_ME_RUN_PC_RUN1                 (1UL << 5)
#define SPC5_ME_RUN_PC_RUN2                 (1UL << 6)
#define SPC5_ME_RUN_PC_RUN3                 (1UL << 7)
/** @} */

/**
 * @name    ME_LP_PCx registers bits definitions
 * @{
 */
#define SPC5_ME_LP_PC_HALT0                 (1UL << 8)
#define SPC5_ME_LP_PC_STOP0                 (1UL << 10)
#define SPC5_ME_LP_PC_STANDBY0              (1UL << 13)
/** @} */

/**
 * @name    ME_PCTL registers bits definitions
 * @{
 */
#define SPC5_ME_PCTL_RUN_MASK               (7UL << 0)
#define SPC5_ME_PCTL_RUN(n)                 (((uint8_t)(n)) << 0)
#define SPC5_ME_PCTL_LP_MASK                (7UL << 3)
#define SPC5_ME_PCTL_LP(n)                  (((uint8_t)(n)) << 3)
/** @} */

/**
 * @name    SSCM_ERROR register bits definitions
 * @{
 */
#define SPC5_SSCM_ERROR_RAE                 (1U << 0)
#define SPC5_SSCM_ERROR_PAE                 (1U << 1)
/** @} */

/**
 * @name    Run modes
 * @{
 */
#define SPC5_RUNMODE_SAFE                   2U
#define SPC5_RUNMODE_DRUN                   3U
#define SPC5_RUNMODE_RUN0                   4U
#define SPC5_RUNMODE_RUN1                   5U
#define SPC5_RUNMODE_RUN2                   6U
#define SPC5_RUNMODE_RUN3                   7U
#define SPC5_RUNMODE_HALT0                  8U
#define SPC5_RUNMODE_STOP0                  10U
#define SPC5_RUNMODE_STANDBY0               13U
/** @} */

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   Disables the clocks initialization.
 */
#if !defined(SPC5_NO_INIT) || defined(__DOXYGEN__)
#define SPC5_NO_INIT                        FALSE
#endif

/**
 * @brief   Disables the overclock checks.
 */
#if !defined(SPC5_ALLOW_OVERCLOCK) || defined(__DOXYGEN__)
#define SPC5_ALLOW_OVERCLOCK                FALSE
#endif

/**
 * @brief   Disables Clockout
 */
#if !defined(SPC5_ENABLE_CLOCKOUT) || defined(__DOXYGEN__)
#define SPC5_ENABLE_CLOCKOUT                FALSE
#endif

/**
 * @brief   PLL0 PREDIV divider value.
 * @note    The default value is calculated for XOSC=40MHz and PLL0PHI=400MHz.
 */
#if !defined(SPC5_PLL0_PREDIV_VALUE) || defined(__DOXYGEN__)
#define SPC5_PLL0_PREDIV_VALUE              2U
#endif

/**
 * @brief   PLL0 MFD multiplier value.
 * @note    The default value is calculated for XOSC=40MHz and PLL0PHI=400MHz.
 */
#if !defined(SPC5_PLL0_MFD_VALUE) || defined(__DOXYGEN__)
#define SPC5_PLL0_MFD_VALUE                 32U
#endif

/**
 * @brief   PLL0 RFDPHI divider value.
 * @note    The default value is calculated for XOSC=40MHz and PLL0PHI=400MHz.
 */
#if !defined(SPC5_PLL0_RFDPHI_VALUE) || defined(__DOXYGEN__)
#define SPC5_PLL0_RFDPHI_VALUE              2U
#endif

/**
 * @brief   PLL0 RFDPHI1 divider value.
 * @note    The default value is calculated for XOSC=40MHz and PLL0PHI1=66.6MHz.
 */
#if !defined(SPC5_PLL0_RFDPHI1_VALUE) || defined(__DOXYGEN__)
#define SPC5_PLL0_RFDPHI1_VALUE             8U
#endif

/**
 * @brief   PLL1 MFD multiplier value.
 * @note    The default value is calculated for XOSC=40MHz and PLL1PHI=180MHz.
 */
#if !defined(SPC5_PLL1_MFD_VALUE) || defined(__DOXYGEN__)
#define SPC5_PLL1_MFD_VALUE                 16U
#endif

/**
 * @brief   PLL1 RFDPHI divider value.
 * @note    The default value is calculated for XOSC=40MHz and PLL1PHI=180MHz.
 */
#if !defined(SPC5_PLL1_RFDPHI_VALUE) || defined(__DOXYGEN__)
#define SPC5_PLL1_RFDPHI_VALUE              8U
#endif

/**
 * @brief   CGM_SC_DC0 clock divider value.
 * @note    Range 1..64, zero means disabled clock.
 * @note    The dividers on the SC must have values that are multiples of
 *          all the other SC dividers except the lowest one.
 */
#if !defined(SPC5_CGM_SC_DC0_DIV_VALUE) || defined(__DOXYGEN__)
#define SPC5_CGM_SC_DC0_DIV_VALUE           1U
#endif

/**
 * @brief   CGM_SC_DC1 clock divider value.
 * @note    Range 1..64, zero means disabled clock.
 * @note    The dividers on the SC must have values that are multiples of
 *          all the other SC dividers except the lowest one.
 */
#if !defined(SPC5_CGM_SC_DC1_DIV_VALUE) || defined(__DOXYGEN__)
#define SPC5_CGM_SC_DC1_DIV_VALUE           2U
#endif

/**
 * @brief   CGM_SC_DC2 clock divider value.
 * @note    Range 1..64, zero means disabled clock.
 * @note    The dividers on the SC must have values that are multiples of
 *          all the other SC dividers except the lowest one.
 */
#if !defined(SPC5_CGM_SC_DC2_DIV_VALUE) || defined(__DOXYGEN__)
#define SPC5_CGM_SC_DC2_DIV_VALUE           2U
#endif

/**
 * @brief   CGM_SC_DC3 clock divider value.
 * @note    Range 1..64, zero means disabled clock.
 * @note    The dividers on the SC must have values that are multiples of
 *          all the other SC dividers except the lowest one.
 */
#if !defined(SPC5_CGM_SC_DC3_DIV_VALUE) || defined(__DOXYGEN__)
#define SPC5_CGM_SC_DC3_DIV_VALUE           1U
#endif

/**
 * @brief   CGM_SC_DC4 clock divider value.
 * @note    Range 1..64, zero means disabled clock.
 * @note    The dividers on the SC must have values that are multiples of
 *          all the other SC dividers except the lowest one.
 */
#if !defined(SPC5_CGM_SC_DC4_DIV_VALUE) || defined(__DOXYGEN__)
#define SPC5_CGM_SC_DC4_DIV_VALUE           1U
#endif

/**
 * @brief   CGM_AC0_SC clock source.
 */
#if !defined(SPC5_CGM_AC0_SC_BITS) || defined(__DOXYGEN__)
#define SPC5_CGM_AC0_SC_BITS                SPC5_CGM_SC_PLL0PHI
#endif

/**
 * @brief   CGM_AC0_DC0 clock divider value.
 * @note    Range 1..128, zero means disabled clock.
 */
#if !defined(SPC5_CGM_AC0_DC0_DIV_VALUE) || defined(__DOXYGEN__)
#define SPC5_CGM_AC0_DC0_DIV_VALUE          20U
#endif

/**
 * @brief   CGM_AC0_DC1 clock divider value.
 * @note    Range 1..16, zero means disabled clock.
 */
#if !defined(SPC5_CGM_AC0_DC1_DIV_VALUE) || defined(__DOXYGEN__)
#define SPC5_CGM_AC0_DC1_DIV_VALUE          8U
#endif

/**
 * @brief   CGM_AC3_SC clock source.
 */
#if !defined(SPC5_CGM_AC3_SC_BITS) || defined(__DOXYGEN__)
#define SPC5_CGM_AC3_SC_BITS                SPC5_CGM_SC_XOSC
#endif

/**
 * @brief   CGM_AC4_SC clock source.
 */
#if !defined(SPC5_CGM_AC4_SC_BITS) || defined(__DOXYGEN__)
#define SPC5_CGM_AC4_SC_BITS                SPC5_CGM_SC_PLL0PHI1
#endif

/**
 * @brief   RTCC_CLKSEL clock source.
 */
#if !defined(SPC5_RTCC_CLKSEL_VALUE) || defined(__DOXYGEN__)
#define SPC5_RTCC_CLKSEL_VALUE              SPC5_RTCC_CLKSEL_SXOSC
#endif

/**
 * @brief   CGM_AC6_SC clock source.
 */
#if !defined(SPC5_CGM_AC6_SC_BITS) || defined(__DOXYGEN__)
#define SPC5_CGM_AC6_SC_BITS                SPC5_CGM_SC_PLL1PHI
#endif

/**
 * @brief   CGM_AC6_DC0 clock divider value.
 * @note    Range 1..512, zero means disabled clock.
 */
#if !defined(SPC5_CGM_AC6_DC0_DIV_VALUE) || defined(__DOXYGEN__)
#define SPC5_CGM_AC6_DC0_DIV_VALUE          4U
#endif

/**
 * @brief   CGM_AC8_SC clock source.
 */
#if !defined(SPC5_CGM_AC8_SC_BITS) || defined(__DOXYGEN__)
#define SPC5_CGM_AC8_SC_BITS                SPC5_CGM_SC_XOSC
#endif

/**
 * @brief   CGM_AC8_DC0 clock divider value.
 * @note    Range 1..64, zero means disabled clock.
 */
#if !defined(SPC5_CGM_AC8_DC0_DIV_VALUE) || defined(__DOXYGEN__)
#define SPC5_CGM_AC8_DC0_DIV_VALUE          1U
#endif

/**
 * @brief   CGM_AC9_SC clock source.
 */
#if !defined(SPC5_CGM_AC9_SC_BITS) || defined(__DOXYGEN__)
#define SPC5_CGM_AC9_SC_BITS                SPC5_CGM_SC_XOSC
#endif

/**
 * @brief   CGM_AC9_DC0 clock divider value.
 * @note    Range 1..64, zero means disabled clock.
 */
#if !defined(SPC5_CGM_AC9_DC0_DIV_VALUE) || defined(__DOXYGEN__)
#define SPC5_CGM_AC9_DC0_DIV_VALUE          1U
#endif

/**
 * @brief   CGM_AC11_SC clock source.
 */
#if !defined(SPC5_CGM_AC11_SC_BITS) || defined(__DOXYGEN__)
#define SPC5_CGM_AC11_SC_BITS               SPC5_CGM_SC_XOSC
#endif


/**
 * @brief   CGM_AC11_DC0 clock divider value.
 * @note    Range 1..64, zero means disabled clock.
 */
#if !defined(SPC5_CGM_AC11_DC0_DIV_VALUE) || defined(__DOXYGEN__)
#define SPC5_CGM_AC11_DC0_DIV_VALUE         1U
#endif

/**
 * @brief   CGM_AC12_SC clock source.
 */
#if !defined(SPC5_CGM_AC12_SC_BITS) || defined(__DOXYGEN__)
#define SPC5_CGM_AC12_SC_BITS               SPC5_CGM_SC_PLL0PHI
#endif

/**
 * @brief   CGM_AC12_DC0 clock divider value.
 * @note    Range 1..16, zero means disabled clock.
 */
#if !defined(SPC5_CGM_AC12_DC0_DIV_VALUE) || defined(__DOXYGEN__)
#define SPC5_CGM_AC12_DC0_DIV_VALUE         4U
#endif

/**
 * @brief   CGM_AC12_DC0 clock divider multiplier value.
 * @note    Possible values are 1, 10, 100 and 1000.
 */
#if !defined(SPC5_CGM_AC12_DC0_DIV_FMT_VALUE) || defined(__DOXYGEN__)
#define SPC5_CGM_AC12_DC0_DIV_FMT_VALUE     1U
#endif

/**
 * @brief   CGM_AC12_DC1 clock divider value.
 * @note    Range 1..16, zero means disabled clock.
 */
#if !defined(SPC5_CGM_AC12_DC1_DIV_VALUE) || defined(__DOXYGEN__)
#define SPC5_CGM_AC12_DC1_DIV_VALUE         4U
#endif

/**
 * @brief   CGM_AC12_DC2 clock divider value.
 * @note    Range 1..16, zero means disabled clock.
 */
#if !defined(SPC5_CGM_AC12_DC2_DIV_VALUE) || defined(__DOXYGEN__)
#define SPC5_CGM_AC12_DC2_DIV_VALUE         4U
#endif


/**
 * @brief   Active run modes in ME_ME register.
 * @note    Modes RESET, SAFE, DRUN, and RUN0 modes are always enabled, there
 *          is no need to specify them.
 */
#if !defined(SPC5_ME_ME_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_ME_BITS                     (SPC5_ME_ME_RUN1 |              \
                                             SPC5_ME_ME_RUN2 |              \
                                             SPC5_ME_ME_RUN3 |              \
                                             SPC5_ME_ME_HALT0 |             \
                                             SPC5_ME_ME_STOP0)              \
                                             SPC5_ME_ME_STANDBY0)
#endif

/**
 * @brief   SAFE mode settings.
 */
#if !defined(SPC5_ME_SAFE_MC_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_SAFE_MC_BITS                (SPC5_ME_MC_PDO)
#endif

/**
 * @brief   DRUN mode settings.
 */
#if !defined(SPC5_ME_DRUN_MC_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_DRUN_MC_BITS                (SPC5_ME_MC_SYSCLK_PLL1PHI |    \
                                             SPC5_ME_MC_IRCON |             \
                                             SPC5_ME_MC_XOSCON |            \
                                             SPC5_ME_MC_PLL0ON |            \
                                             SPC5_ME_MC_PLL1ON |            \
                                             SPC5_ME_MC_FLAON_NORMAL |      \
                                             SPC5_ME_MC_MVRON)
#endif

/**
 * @brief   RUN0 mode settings.
 */
#if !defined(SPC5_ME_RUN0_MC_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_RUN0_MC_BITS                (SPC5_ME_MC_SYSCLK_PLL1PHI |    \
                                             SPC5_ME_MC_IRCON |             \
                                             SPC5_ME_MC_XOSCON |            \
                                             SPC5_ME_MC_PLL0ON |            \
                                             SPC5_ME_MC_PLL1ON |            \
                                             SPC5_ME_MC_FLAON_NORMAL |      \
                                             SPC5_ME_MC_MVRON)
#endif

/**
 * @brief   RUN1 mode settings.
 */
#if !defined(SPC5_ME_RUN1_MC_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_RUN1_MC_BITS                (SPC5_ME_MC_SYSCLK_PLL1PHI |    \
                                             SPC5_ME_MC_IRCON |             \
                                             SPC5_ME_MC_XOSCON |            \
                                             SPC5_ME_MC_PLL0ON |            \
                                             SPC5_ME_MC_PLL1ON |            \
                                             SPC5_ME_MC_FLAON_NORMAL |      \
                                             SPC5_ME_MC_MVRON)
#endif

/**
 * @brief   RUN2 mode settings.
 */
#if !defined(SPC5_ME_RUN2_MC_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_RUN2_MC_BITS                (SPC5_ME_MC_SYSCLK_PLL1PHI |    \
                                             SPC5_ME_MC_IRCON |             \
                                             SPC5_ME_MC_XOSCON |            \
                                             SPC5_ME_MC_PLL0ON |            \
                                             SPC5_ME_MC_PLL1ON |            \
                                             SPC5_ME_MC_FLAON_NORMAL |      \
                                             SPC5_ME_MC_MVRON)
#endif

/**
 * @brief   RUN3 mode settings.
 */
#if !defined(SPC5_ME_RUN3_MC_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_RUN3_MC_BITS                (SPC5_ME_MC_SYSCLK_PLL1PHI |    \
                                             SPC5_ME_MC_IRCON |             \
                                             SPC5_ME_MC_XOSCON |            \
                                             SPC5_ME_MC_PLL0ON |            \
                                             SPC5_ME_MC_PLL1ON |            \
                                             SPC5_ME_MC_FLAON_NORMAL |      \
                                             SPC5_ME_MC_MVRON)
#endif

/**
 * @brief   HALT0 mode settings.
 */
#if !defined(SPC5_ME_HALT0_MC_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_HALT0_MC_BITS               (SPC5_ME_MC_SYSCLK_PLL1PHI |    \
                                             SPC5_ME_MC_IRCON |             \
                                             SPC5_ME_MC_XOSCON |            \
                                             SPC5_ME_MC_PLL0ON |            \
                                             SPC5_ME_MC_PLL1ON |            \
                                             SPC5_ME_MC_FLAON_NORMAL |      \
                                             SPC5_ME_MC_MVRON)
#endif

/**
 * @brief   STOP0 mode settings.
 */
#if !defined(SPC5_ME_STOP0_MC_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_STOP0_MC_BITS               (SPC5_ME_MC_SYSCLK_PLL1PHI |    \
                                             SPC5_ME_MC_IRCON |             \
                                             SPC5_ME_MC_XOSCON |            \
                                             SPC5_ME_MC_PLL0ON |            \
                                             SPC5_ME_MC_PLL1ON |            \
                                             SPC5_ME_MC_FLAON_NORMAL |      \
                                             SPC5_ME_MC_MVRON)
#endif

/**
 * @brief   STANDBY0 mode settings.
 */
#if !defined(SPC5_ME_STANDBY0_MC_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_STANDBY0_MC_BITS            (SPC5_ME_MC_SYSCLK_DISABLED |   \
                                             SPC5_ME_MC_IRCON |             \
                                             SPC5_ME_MC_CFLAON_PD |         \
                                             SPC5_ME_MC_PDO)
#endif

/**
 * @brief   Peripheral mode 0 (run mode).
 * @note    Do not change this setting, it is expected to be the "never run"
 *          mode.
 */
#if !defined(SPC5_ME_RUN_PC0_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_RUN_PC0_BITS                0
#endif

/**
 * @brief   Peripheral mode 1 (run mode).
 * @note    Do not change this setting, it is expected to be the "always run"
 *          mode.
 */
#if !defined(SPC5_ME_RUN_PC1_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_RUN_PC1_BITS                (SPC5_ME_RUN_PC_SAFE |          \
                                             SPC5_ME_RUN_PC_DRUN |          \
                                             SPC5_ME_RUN_PC_RUN0 |          \
                                             SPC5_ME_RUN_PC_RUN1 |          \
                                             SPC5_ME_RUN_PC_RUN2 |          \
                                             SPC5_ME_RUN_PC_RUN3)
#endif

/**
 * @brief   Peripheral mode 2 (run mode).
 * @note    Do not change this setting, it is expected to be the "only during
 *          normal run" mode.
 */
#if !defined(SPC5_ME_RUN_PC2_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_RUN_PC2_BITS                (SPC5_ME_RUN_PC_DRUN |          \
                                             SPC5_ME_RUN_PC_RUN0 |          \
                                             SPC5_ME_RUN_PC_RUN1 |          \
                                             SPC5_ME_RUN_PC_RUN2 |          \
                                             SPC5_ME_RUN_PC_RUN3)
#endif

/**
 * @brief   Peripheral mode 3 (run mode).
 * @note    Not defined, available to application-specific modes.
 */
#if !defined(SPC5_ME_RUN_PC3_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_RUN_PC3_BITS                (SPC5_ME_RUN_PC_DRUN |          \
                                             SPC5_ME_RUN_PC_RUN0 |          \
                                             SPC5_ME_RUN_PC_RUN1 |          \
                                             SPC5_ME_RUN_PC_RUN2 |          \
                                             SPC5_ME_RUN_PC_RUN3)
#endif

/**
 * @brief   Peripheral mode 4 (run mode).
 * @note    Not defined, available to application-specific modes.
 */
#if !defined(SPC5_ME_RUN_PC4_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_RUN_PC4_BITS                (SPC5_ME_RUN_PC_DRUN |          \
                                             SPC5_ME_RUN_PC_RUN0 |          \
                                             SPC5_ME_RUN_PC_RUN1 |          \
                                             SPC5_ME_RUN_PC_RUN2 |          \
                                             SPC5_ME_RUN_PC_RUN3)
#endif

/**
 * @brief   Peripheral mode 5 (run mode).
 * @note    Not defined, available to application-specific modes.
 */
#if !defined(SPC5_ME_RUN_PC5_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_RUN_PC5_BITS                (SPC5_ME_RUN_PC_DRUN |          \
                                             SPC5_ME_RUN_PC_RUN0 |          \
                                             SPC5_ME_RUN_PC_RUN1 |          \
                                             SPC5_ME_RUN_PC_RUN2 |          \
                                             SPC5_ME_RUN_PC_RUN3)
#endif

/**
 * @brief   Peripheral mode 6 (run mode).
 * @note    Not defined, available to application-specific modes.
 */
#if !defined(SPC5_ME_RUN_PC6_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_RUN_PC6_BITS                (SPC5_ME_RUN_PC_DRUN |          \
                                             SPC5_ME_RUN_PC_RUN0 |          \
                                             SPC5_ME_RUN_PC_RUN1 |          \
                                             SPC5_ME_RUN_PC_RUN2 |          \
                                             SPC5_ME_RUN_PC_RUN3)
#endif

/**
 * @brief   Peripheral mode 7 (run mode).
 * @note    Not defined, available to application-specific modes.
 */
#if !defined(SPC5_ME_RUN_PC7_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_RUN_PC7_BITS                (SPC5_ME_RUN_PC_DRUN |          \
                                             SPC5_ME_RUN_PC_RUN0 |          \
                                             SPC5_ME_RUN_PC_RUN1 |          \
                                             SPC5_ME_RUN_PC_RUN2 |          \
                                             SPC5_ME_RUN_PC_RUN3)
#endif

/**
 * @brief   Peripheral mode 0 (low power mode).
 * @note    Do not change this setting, it is expected to be the "never run"
 *          mode.
 */
#if !defined(SPC5_ME_LP_PC0_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_LP_PC0_BITS                 0
#endif

/**
 * @brief   Peripheral mode 1 (low power mode).
 * @note    Do not change this setting, it is expected to be the "always run"
 *          mode.
 */
#if !defined(SPC5_ME_LP_PC1_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_LP_PC1_BITS                 (SPC5_ME_LP_PC_HALT0 |          \
                                             SPC5_ME_LP_PC_STOP0 |          \
                                             SPC5_ME_LP_PC_STANDBY0)
#endif

/**
 * @brief   Peripheral mode 2 (low power mode).
 * @note    Do not change this setting, it is expected to be the "halt only"
 *          mode.
 */
#if !defined(SPC5_ME_LP_PC2_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_LP_PC2_BITS                 (SPC5_ME_LP_PC_HALT0)
#endif

/**
 * @brief   Peripheral mode 3 (low power mode).
 * @note    Do not change this setting, it is expected to be the "stop only"
 *          mode.
 */
#if !defined(SPC5_ME_LP_PC3_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_LP_PC3_BITS                 (SPC5_ME_LP_PC_STOP0)
#endif

/**
 * @brief   Peripheral mode 4 (low power mode).
 * @note    Not defined, available to application-specific modes.
 */
#if !defined(SPC5_ME_LP_PC4_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_LP_PC4_BITS                 (SPC5_ME_LP_PC_HALT0 |          \
                                             SPC5_ME_LP_PC_STOP0)
#endif

/**
 * @brief   Peripheral mode 5 (low power mode).
 * @note    Not defined, available to application-specific modes.
 */
#if !defined(SPC5_ME_LP_PC5_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_LP_PC5_BITS                 (SPC5_ME_LP_PC_HALT0 |          \
                                             SPC5_ME_LP_PC_STOP0)
#endif

/**
 * @brief   Peripheral mode 6 (low power mode).
 * @note    Not defined, available to application-specific modes.
 */
#if !defined(SPC5_ME_LP_PC6_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_LP_PC6_BITS                 (SPC5_ME_LP_PC_HALT0 |          \
                                             SPC5_ME_LP_PC_STOP0)
#endif

/**
 * @brief   Peripheral mode 7 (low power mode).
 * @note    Not defined, available to application-specific modes.
 */
#if !defined(SPC5_ME_LP_PC7_BITS) || defined(__DOXYGEN__)
#define SPC5_ME_LP_PC7_BITS                 (SPC5_ME_LP_PC_HALT0 |          \
                                             SPC5_ME_LP_PC_STOP0)
#endif

/**
 * @brief   Final run mode after initialization.
 * @note    It can be selected between DRUN, RUN0...RUN3.
 */
#if !defined(SPC5_FINAL_RUNMODE) || defined(__DOXYGEN__)
#define SPC5_FINAL_RUNMODE                  SPC5_RUNMODE_RUN0
#endif

/**
 * @brief   SSCM.ERROR register initialization.
 */
#if !defined(SPC5_SSCM_ERROR_INIT) || defined(__DOXYGEN__)
#define SPC5_SSCM_ERROR_INIT                (SPC5_SSCM_ERROR_PAE |          \
                                             SPC5_SSCM_ERROR_RAE)
#endif

/**
 * @brief   Clock initialization failure hook.
 * @note    The default is to stop the system and let the RTC restart it.
 * @note    The hook code must not return.
 */
#if !defined(SPC5_CLOCK_FAILURE_HOOK) || defined(__DOXYGEN__)
#define SPC5_CLOCK_FAILURE_HOOK()           irqSysHalt()
#endif

/**
 * @brief   XOSC disabled initialization.
 * @note    The default is XOSC enabled.
 */
#if !defined(SPC5_XOSC_DISABLED) || defined(__DOXYGEN__)
#define SPC5_XOSC_DISABLED                  FALSE
#endif

/**
 * @brief   XOSCON set at least in one run mode initialization.
 * @note    The default is XOSCON not set in all run modes.
 */
#if !defined(SPC5_ME_MC_IS_XOSCON) || defined(__DOXYGEN__)
#define SPC5_ME_MC_IS_XOSCON                FALSE
#endif

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*-----------------------------------------*
 * Oscillators-related checks.             *
 *-----------------------------------------*/

/* Check on the XOSC frequency.*/
#if (SPC5_XOSC_CLK < SPC5_XOSC_CLK_MIN) ||                                  \
    (SPC5_XOSC_CLK > SPC5_XOSC_CLK_MAX)
#error "invalid SPC5_XOSC_CLK value specified"
#endif

/*-----------------------------------------*
 * PLL-related checks.                     *
 *-----------------------------------------*/

/* Check on SPC5_PLL0_PREDIV_VALUE.*/
#if (SPC5_PLL0_PREDIV_VALUE < 1U) || (SPC5_PLL0_PREDIV_VALUE > 7U)
#error "invalid SPC5_PLL0_PREDIV_VALUE value specified"
#endif

/* Check on SPC5_PLL0_MFD_VALUE.*/
#if (SPC5_PLL0_MFD_VALUE < 8U) || (SPC5_PLL0_MFD_VALUE > 127U)
#error "invalid SPC5_PLL0_MFD_VALUE value specified"
#endif

/* Check on SPC5_PLL0_RFDPHI_VALUE.*/
#if (SPC5_PLL0_RFDPHI_VALUE < 1U) || (SPC5_PLL0_RFDPHI_VALUE > 63U)
#error "invalid SPC5_PLL0_RFDPHI_VALUE value specified"
#endif

/* Check on SPC5_PLL0_RFDPHI1_VALUE.*/
#if (SPC5_PLL0_RFDPHI1_VALUE < 4U) || (SPC5_PLL0_RFDPHI1_VALUE > 15U)
#error "invalid SPC5_PLL0_RFDPHI1_VALUE value specified"
#endif

/* Check on SPC5_PLL1_MFD_VALUE.*/
#if (SPC5_PLL1_MFD_VALUE < 16U) || (SPC5_PLL1_MFD_VALUE > 34U)
#error "invalid SPC5_PLL1_MFD_VALUE value specified"
#endif

/* Check on SPC5_PLL1_RFDPHI_VALUE.*/
#if (SPC5_PLL1_RFDPHI_VALUE < 1U) || (SPC5_PLL1_RFDPHI_VALUE > 63U)
#error "invalid SPC5_PLL1_RFDPHI_VALUE value specified"
#endif

/*-----------------------------------------*
 * Mux-related checks and assignments.     *
 *-----------------------------------------*/

/* Check on SPC5_CGM_AC0_SC_BITS.*/
#if SPC5_CGM_AC0_SC_BITS == SPC5_CGM_SC_IRC
#define SPC5_AUX0_CLK                       SPC5_IRC_CLK
#elif SPC5_CGM_AC0_SC_BITS == SPC5_CGM_SC_XOSC
#define SPC5_AUX0_CLK                       SPC5_XOSC_CLK
#elif SPC5_CGM_AC0_SC_BITS == SPC5_CGM_SC_PLL0PHI
#define SPC5_AUX0_CLK                       SPC5_PLL0_PHI_CLK
#else
#error "invalid SPC5_CGM_AC0_SC_BITS value specified"
#endif

/* Check on SPC5_CGM_AC3_SC_BITS.*/
#if SPC5_CGM_AC3_SC_BITS == SPC5_CGM_SC_IRC
#define SPC5_PLL0_INPUT_CLK                 SPC5_IRC_CLK
#elif SPC5_CGM_AC3_SC_BITS == SPC5_CGM_SC_XOSC
#define SPC5_PLL0_INPUT_CLK                 SPC5_XOSC_CLK
#else
#error "invalid SPC5_CGM_AC3_SC_BITS value specified"
#endif

/* Check on SPC5_CGM_AC4_SC_BITS.*/
#if SPC5_CGM_AC4_SC_BITS == SPC5_CGM_SC_XOSC
#define SPC5_PLL1_INPUT_CLK                 SPC5_XOSC_CLK
#elif SPC5_CGM_AC4_SC_BITS == SPC5_CGM_SC_PLL0PHI1
#define SPC5_PLL1_INPUT_CLK                 SPC5_PLL0_PHI1_CLK
#else
#error "invalid SPC5_CGM_AC4_SC_BITS value specified"
#endif

/* Check on SPC5_RTCC_CLKSEL_VALUE.*/
#if SPC5_RTCC_CLKSEL_VALUE == SPC5_RTCC_CLKSEL_LPRC
#define SPC5_RTC_CLK                        SPC5_LPRC_CLK
#elif SPC5_RTCC_CLKSEL_VALUE == SPC5_RTCC_CLKSEL_IRC
#define SPC5_RTC_CLK                        SPC5_IRC_CLK
#else
#error "invalid SPC5_RTCC_CLKSEL_VALUE value specified"
#endif

/* Check on SPC5_CGM_AC6_SC_BITS.*/
#if SPC5_CGM_AC6_SC_BITS == SPC5_CGM_SC_IRC
#define SPC5_AUX6_CLK                       SPC5_IRC_CLK
#elif SPC5_CGM_AC6_SC_BITS == SPC5_CGM_SC_XOSC
#define SPC5_AUX6_CLK                       SPC5_XOSC_CLK
#elif SPC5_CGM_AC6_SC_BITS == SPC5_CGM_SC_PLL0PHI
#define SPC5_AUX6_CLK                       SPC5_PLL0_PHI_CLK
#elif SPC5_CGM_AC6_SC_BITS == SPC5_CGM_SC_PLL1PHI
#define SPC5_AUX6_CLK                       SPC5_PLL1_PHI_CLK
#elif SPC5_CGM_AC6_SC_BITS == SPC5_CGM_SC_RTC_CLK
#define SPC5_AUX6_CLK                       SPC5_RTC_CLK
#else
#error "invalid SPC5_CGM_AC6_SC_BITS value specified"
#endif

/* Check on SPC5_CGM_AC8_SC_BITS.*/
#if SPC5_CGM_AC8_SC_BITS == SPC5_CGM_SC_XOSC
#define SPC5_AUX8_CLK                       SPC5_XOSC_CLK
#elif SPC5_CGM_AC8_SC_BITS == SPC5_CGM_SC_PLL0PHI
#define SPC5_AUX8_CLK                       SPC5_PLL0_PHI_CLK
#else
#error "invalid SPC5_CGM_AC8_SC_BITS value specified"
#endif

/* Check on SPC5_CGM_AC9_SC_BITS.*/
#if SPC5_CGM_AC9_SC_BITS == SPC5_CGM_SC_IRC
#define SPC5_AUX9_CLK                       SPC5_IRC_CLK
#elif SPC5_CGM_AC9_SC_BITS == SPC5_CGM_SC_XOSC
#define SPC5_AUX9_CLK                       SPC5_XOSC_CLK
#else
#error "invalid SPC5_CGM_AC9_SC_BITS value specified"
#endif

/* Check on SPC5_CGM_AC11_SC_BITS.*/
#if SPC5_CGM_AC11_SC_BITS == SPC5_CGM_SC_XOSC
#define SPC5_AUX11_CLK                      SPC5_XOSC_CLK
#elif SPC5_CGM_AC11_SC_BITS == SPC5_CGM_SC_PLL0PHI
#define SPC5_AUX11_CLK                      SPC5_PLL0_PHI_CLK
#else
#error "invalid SPC5_CGM_AC11_SC_BITS value specified"
#endif

/* Check on SPC5_CGM_AC12_SC_BITS.*/
#if SPC5_CGM_AC12_SC_BITS == SPC5_CGM_SC_IRC
#define SPC5_AUX12_CLK                      SPC5_IRC_CLK
#elif SPC5_CGM_AC12_SC_BITS == SPC5_CGM_SC_XOSC
#define SPC5_AUX12_CLK                      SPC5_XOSC_CLK
#elif SPC5_CGM_AC12_SC_BITS == SPC5_CGM_SC_PLL0PHI
#define SPC5_AUX12_CLK                      SPC5_PLL0_PHI_CLK
#else
#error "invalid SPC5_CGM_AC12_SC_BITS value specified"
#endif

/*-----------------------------------------*
 * Dividers-related checks.                *
 *-----------------------------------------*/

/* Check on the SC divider 0 settings.*/
#if (SPC5_CGM_SC_DC0_DIV_VALUE >= 1U) && (SPC5_CGM_SC_DC0_DIV_VALUE <= 64U)
#define SPC5_CGM_SC_DC0_BITS                ((uint32_t)(0x8000U |           \
                                             (uint8_t)(SPC5_CGM_SC_DC0_DIV_VALUE - 1U)) << 16)
#else
#error "invalid SPC5_CGM_SC_DC0_DIV_VALUE value specified"
#endif

/* Check on the SC divider 1 settings.*/
#if (SPC5_CGM_SC_DC1_DIV_VALUE >= 1U) && (SPC5_CGM_SC_DC1_DIV_VALUE <= 64U)
#define SPC5_CGM_SC_DC1_BITS                ((uint32_t)(0x8000U |           \
                                             (uint8_t)(SPC5_CGM_SC_DC1_DIV_VALUE - 1U)) << 16)
#else
#error "invalid SPC5_CGM_SC_DC1_DIV_VALUE value specified"
#endif

/* Check on the SC divider 2 settings.*/
#if (SPC5_CGM_SC_DC2_DIV_VALUE >= 1U) && (SPC5_CGM_SC_DC2_DIV_VALUE <= 64U)
#define SPC5_CGM_SC_DC2_BITS                ((uint32_t)(0x8000U |           \
                                             (uint8_t)(SPC5_CGM_SC_DC2_DIV_VALUE - 1U)) << 16)
#else
#error "invalid SPC5_CGM_SC_DC2_DIV_VALUE value specified"
#endif

/* Check on the SC divider 3 settings.*/
#if (SPC5_CGM_SC_DC3_DIV_VALUE >= 1U) && (SPC5_CGM_SC_DC3_DIV_VALUE <= 64U)
#define SPC5_CGM_SC_DC3_BITS                ((uint32_t)(0x8000U |           \
                                             (uint8_t)(SPC5_CGM_SC_DC3_DIV_VALUE - 1U)) << 16)
#else
#error "invalid SPC5_CGM_SC_DC3_DIV_VALUE value specified"
#endif

/* Check on the SC divider 4 settings.*/
#if (SPC5_CGM_SC_DC4_DIV_VALUE >= 1U) && (SPC5_CGM_SC_DC4_DIV_VALUE <= 64U)
#define SPC5_CGM_SC_DC4_BITS                ((uint32_t)(0x8000U |           \
                                             (uint8_t)(SPC5_CGM_SC_DC4_DIV_VALUE - 1U)) << 16)
#else
#error "invalid SPC5_CGM_SC_DC4_DIV_VALUE value specified"
#endif

/* Check on the AUX0 divider 0 settings.*/
#if SPC5_CGM_AC0_DC0_DIV_VALUE == 0U
#define SPC5_CGM_AC0_DC0_BITS               0U
#elif (SPC5_CGM_AC0_DC0_DIV_VALUE >= 1U) && (SPC5_CGM_AC0_DC0_DIV_VALUE <= 128U)
#define SPC5_CGM_AC0_DC0_BITS               ((uint32_t)(0x8000U |           \
                                             (uint8_t)(SPC5_CGM_AC0_DC0_DIV_VALUE - 1U)) << 16)
#else
#error "invalid SPC5_CGM_AC0_DC0_DIV_VALUE value specified"
#endif

/* Check on the AUX0 divider 1 settings.*/
#if SPC5_CGM_AC0_DC1_DIV_VALUE == 0U
#define SPC5_CGM_AC0_DC1_BITS               0U
#elif (SPC5_CGM_AC0_DC1_DIV_VALUE >= 1U) && (SPC5_CGM_AC0_DC1_DIV_VALUE <= 16U)
#define SPC5_CGM_AC0_DC1_BITS               ((uint32_t)(0x8000U |           \
                                             (uint8_t)(SPC5_CGM_AC0_DC1_DIV_VALUE - 1U)) << 16)
#else
#error "invalid SPC5_CGM_AC0_DC1_DIV_VALUE value specified"
#endif

/* Check on the AUX6 divider 0 settings.*/
#if (SPC5_CGM_AC6_DC0_DIV_VALUE == 0U) || (SPC5_ENABLE_CLOCKOUT == FALSE)
#define SPC5_CGM_AC6_DC0_BITS               0U
#elif (SPC5_CGM_AC6_DC0_DIV_VALUE >= 1U) && (SPC5_CGM_AC6_DC0_DIV_VALUE <= 512U)
#define SPC5_CGM_AC6_DC0_BITS               ((uint32_t)(0x8000U |           \
                                             (uint16_t)(SPC5_CGM_AC6_DC0_DIV_VALUE - 1U)) << 16)
#else
#error "invalid SPC5_CGM_AC6_DC0_DIV_VALUE value specified"
#endif

/* Check on the AUX8 divider 0 settings.*/
#if SPC5_CGM_AC8_DC0_DIV_VALUE == 0U
#define SPC5_CGM_AC8_DC0_BITS               0U
#elif (SPC5_CGM_AC8_DC0_DIV_VALUE >= 1U) && (SPC5_CGM_AC8_DC0_DIV_VALUE <= 64U)
#define SPC5_CGM_AC8_DC0_BITS               ((uint32_t)(0x8000U |           \
                                             (uint8_t)(SPC5_CGM_AC8_DC0_DIV_VALUE - 1U)) << 16)
#else
#error "invalid SPC5_CGM_AC8_DC0_DIV_VALUE value specified"
#endif

/* Check on the AUX9 divider 0 settings.*/
#if SPC5_CGM_AC9_DC0_DIV_VALUE == 0U
#define SPC5_CGM_AC9_DC0_BITS               0U
#elif (SPC5_CGM_AC9_DC0_DIV_VALUE >= 1U) && (SPC5_CGM_AC9_DC0_DIV_VALUE <= 64U)
#define SPC5_CGM_AC9_DC0_BITS               ((uint32_t)(0x8000U |           \
                                             (uint8_t)(SPC5_CGM_AC9_DC0_DIV_VALUE - 1U)) << 16)
#else
#error "invalid SPC5_CGM_AC9_DC0_DIV_VALUE value specified"
#endif

/* Check on the AUX11 divider 0 settings.*/
#if SPC5_CGM_AC11_DC0_DIV_VALUE == 0U
#define SPC5_CGM_AC11_DC0_BITS              0U
#elif (SPC5_CGM_AC11_DC0_DIV_VALUE >= 1U) && (SPC5_CGM_AC11_DC0_DIV_VALUE <= 64U)
#define SPC5_CGM_AC11_DC0_BITS              ((uint32_t)(0x8000U |           \
                                             (uint8_t)(SPC5_CGM_AC11_DC0_DIV_VALUE - 1U)) << 16)
#else
#error "invalid SPC5_CGM_AC11_DC0_DIV_VALUE value specified"
#endif

/* Check on the AUX12 divider 0 multiplier settings.*/
#if SPC5_CGM_AC12_DC0_DIV_FMT_VALUE == 1U
#define SPC5_CGM_AC12_DC0_DIV_FMT           SPC5_CGM_DIV_FMT_DIV1
#elif SPC5_CGM_AC12_DC0_DIV_FMT_VALUE == 10U
#define SPC5_CGM_AC12_DC0_DIV_FMT           SPC5_CGM_DIV_FMT_DIV10
#elif SPC5_CGM_AC12_DC0_DIV_FMT_VALUE == 100U
#define SPC5_CGM_AC12_DC0_DIV_FMT           SPC5_CGM_DIV_FMT_DIV100
#elif SPC5_CGM_AC12_DC0_DIV_FMT_VALUE == 1000U
#define SPC5_CGM_AC12_DC0_DIV_FMT           SPC5_CGM_DIV_FMT_DIV1000
#else
#error "invalid SPC5_CGM_AC12_DC0_DIV_FMT_VALUE value specified"
#endif

/* Check on the AUX12 divider 0 settings.*/
#if SPC5_CGM_AC12_DC0_DIV_VALUE == 0U
#define SPC5_CGM_AC12_DC0_BITS              0U
#elif (SPC5_CGM_AC12_DC0_DIV_VALUE >= 1U) && (SPC5_CGM_AC12_DC0_DIV_VALUE <= 16U)
#define SPC5_CGM_AC12_DC0_BITS              ((uint32_t)(0x8000U |           \
                                             (uint16_t)(SPC5_CGM_AC12_DC0_DIV_VALUE - 1U)) << 16) | \
                                             ((uint32_t)(SPC5_CGM_AC12_DC0_DIV_FMT))
#else
#error "invalid SPC5_CGM_AC12_DC0_DIV_VALUE value specified"
#endif

/* Check on the AUX12 divider 1 settings.*/
#if SPC5_CGM_AC12_DC1_DIV_VALUE == 0U
#define SPC5_CGM_AC12_DC1_BITS               0U
#elif (SPC5_CGM_AC12_DC1_DIV_VALUE >= 1U) && (SPC5_CGM_AC12_DC1_DIV_VALUE <= 16U)
#define SPC5_CGM_AC12_DC1_BITS              ((uint32_t)(0x8000U |          \
                                             (uint8_t)(SPC5_CGM_AC12_DC1_DIV_VALUE - 1U)) << 16)
#else
#error "invalid SPC5_CGM_AC12_DC1_DIV_VALUE value specified"
#endif

/* Check on the AUX12 divider 2 settings.*/
#if SPC5_CGM_AC12_DC2_DIV_VALUE == 0U
#define SPC5_CGM_AC12_DC2_BITS               0U
#elif (SPC5_CGM_AC12_DC2_DIV_VALUE >= 1U) && (SPC5_CGM_AC12_DC2_DIV_VALUE <= 16U)
#define SPC5_CGM_AC12_DC2_BITS              ((uint32_t)(0x8000U |          \
                                             (uint8_t)(SPC5_CGM_AC12_DC2_DIV_VALUE - 1U)) << 16)
#else
#error "invalid SPC5_CGM_AC12_DC2_DIV_VALUE value specified"
#endif


/*-----------------------------------------*
 * Clock points calculation and check.     *
 *-----------------------------------------*/

/**
 * @brief   SPC5_PLL0_VCO_CLK clock point.
 */
#define SPC5_PLL0_VCO_CLK                                                   \
  ((SPC5_PLL0_INPUT_CLK / SPC5_PLL0_PREDIV_VALUE) * (2U * SPC5_PLL0_MFD_VALUE))

/* Check on PLL0 VCO output.*/
#if (SPC5_PLL0_VCO_CLK < SPC5_PLL0VCO_MIN) ||                               \
    (SPC5_PLL0_VCO_CLK > SPC5_PLL0VCO_MAX)
#error "SPC5_PLL0_VCO_CLK outside acceptable range (SPC5_PLL0VCO_MIN...SPC5_PLL0VCO_MAX)"
#endif

/**
 * @brief   SPC5_PLL0_PHI_CLK clock point.
 */
#define SPC5_PLL0_PHI_CLK                                                   \
  ((SPC5_PLL0_VCO_CLK / SPC5_PLL0_RFDPHI_VALUE) / 2U)

/* Check on SPC5_PLL0_PHI_CLK.*/
#if ((SPC5_PLL0_PHI_CLK > SPC5_PLL0_CLK_MAX) ||                             \
     (SPC5_PLL0_PHI_CLK < SPC5_PLL0_CLK_MIN)) && (SPC5_ALLOW_OVERCLOCK == FALSE)
#error "SPC5_PLL0_PHI_CLK outside acceptable range (SPC5_PLL0_CLK_MIN...SPC5_PLL0_CLK_MAX)"
#endif

/**
 * @brief   SPC5_PLL0_PHI1_CLK clock point.
 */
#define SPC5_PLL0_PHI1_CLK                                                  \
  ((SPC5_PLL0_VCO_CLK / SPC5_PLL0_RFDPHI1_VALUE) / 2U)

/* Check on SPC5_PLL0_PH1I_CLK.*/
#if ((SPC5_PLL0_PHI1_CLK > SPC5_PLL0_CLK_MAX) ||                            \
     (SPC5_PLL0_PHI1_CLK < SPC5_PLL0_CLK_MIN)) && (SPC5_ALLOW_OVERCLOCK == FALSE)
#error "SPC5_PLL0_PHI1_CLK outside acceptable range (SPC5_PLL0_CLK_MIN...SPC5_PLL0_CLK_MAX)"
#endif

/**
 * @brief   SPC5_PLL1_VCO_CLK clock point.
 */
#define SPC5_PLL1_VCO_CLK                                                   \
  (SPC5_PLL1_INPUT_CLK * SPC5_PLL1_MFD_VALUE)

/* Check on PLL1 VCO output.*/
#if (SPC5_PLL1_VCO_CLK < SPC5_PLL1VCO_MIN) ||                               \
    (SPC5_PLL1_VCO_CLK > SPC5_PLL1VCO_MAX)
#error "SPC5_PLL1_VCO_CLK outside acceptable range (SPC5_PLL1VCO_MIN...SPC5_PLL1VCO_MAX)"
#endif

/**
 * @brief   SPC5_PLL1_PHI_CLK clock point.
 * @note    The calculation is still wrong in the rev.5 RM.
 */
#define SPC5_PLL1_PHI_CLK                                                   \
  ((SPC5_PLL1_VCO_CLK / SPC5_PLL1_RFDPHI_VALUE) / 2U)

/* Check on SPC5_PLL1_PHI_CLK.*/
#if ((SPC5_PLL1_PHI_CLK > SPC5_PLL1_CLK_MAX) ||                             \
     (SPC5_PLL1_PHI_CLK < SPC5_PLL1_CLK_MIN)) && (SPC5_ALLOW_OVERCLOCK == FALSE)
#error "SPC5_PLL1_PHI_CLK outside acceptable range (SPC5_PLL1_CLK_MIN...SPC5_PLL1_CLK_MAX)"
#endif

/**
 * @brief   SPC5_PBRIDGE_CLK clock point.
 */
#define SPC5_PBRIDGE_CLK                    (SPC5_SYS_CLK / SPC5_CGM_SC_DC2_DIV_VALUE)

/* Check on SPC5_PBRIDGE_CLK.*/
#if SPC5_PBRIDGE_CLK > SPC5_PBRIDGE_CLK_MAX
#error "SPC5_PBRIDGE_CLK outside acceptable range (0...SPC5_PBRIDGE_CLK_MAX)"
#endif

/**
 * @brief   SPC5_SARADC_CLK clock point.
 */
#if (SPC5_CGM_AC0_DC0_DIV_VALUE == 0U)
#define SPC5_SARADC_CLK                     0U
#else
#define SPC5_SARADC_CLK                     (SPC5_AUX0_CLK / SPC5_CGM_AC0_DC0_DIV_VALUE)
#endif

/* Check on SPC5_SARADC_CLK.*/
#if SPC5_SARADC_CLK > SPC5_SARADC_CLK_MAX
#error "SPC5_SARADC_CLK outside acceptable range (0...SPC5_SARADC_CLK_MAX)"
#endif

/**
 * @brief   SPC5_EMIOS_CLK clock point.
 */
#if (SPC5_CGM_AC0_DC1_DIV_VALUE == 0U)
#define SPC5_EMIOS_CLK                      0U
#else
#define SPC5_EMIOS_CLK                      (SPC5_AUX0_CLK / SPC5_CGM_AC0_DC1_DIV_VALUE)
#endif

/* Check on SPC5_EMIOS_CLK.*/
#if SPC5_EMIOS_CLK > SPC5_EMIOS_CLK_MAX
#error "SPC5_EMIOS_CLK outside acceptable range (0...SPC5_EMIOS_CLK_MAX)"
#endif

/**
 * @brief   SPC5_SYSCLK0 clock point.
 */
#if (SPC5_CGM_AC6_DC0_DIV_VALUE == 0U)
#define SPC5_SYSCLK0                        0U
#else
#define SPC5_SYSCLK0                        (SPC5_AUX6_CLK / SPC5_CGM_AC6_DC0_DIV_VALUE)
#endif

/* Check on SPC5_SYSCLK0.*/
#if SPC5_SYSCLK0 > SPC5_SYSCLK0_MAX
#error "SPC5_SYSCLK0 outside acceptable range (0...SPC5_SYSCLK0_MAX)"
#endif

/**
 * @brief   SPC5_CANCLK0 clock point.
 */
#if (SPC5_CGM_AC8_DC0_DIV_VALUE == 0U)
#define SPC5_CANCLK0                        0U
#else
#define SPC5_CANCLK0                        (SPC5_AUX8_CLK / SPC5_CGM_AC8_DC0_DIV_VALUE)
#endif

/* Check on SPC5_CANCLK0.*/
#if SPC5_CANCLK0 > SPC5_CANCLK0_MAX
#error "SPC5_CANCLK0 outside acceptable range (0...SPC5_CANCLK0_MAX)"
#endif

/**
 * @brief   SPC5_RTI_CLK clock point.
 */
#if (SPC5_CGM_AC9_DC0_DIV_VALUE == 0U)
#define SPC5_RTI_CLK                        0U
#else
#define SPC5_RTI_CLK                        (SPC5_AUX9_CLK / SPC5_CGM_AC9_DC0_DIV_VALUE)
#endif

/* Check on SPC5_RTI_CLK.*/
#if SPC5_RTI_CLK > SPC5_RTI_CLK_MAX
#error "SPC5_RTI_CLK outside acceptable range (0...SPC5_RTI_CLK_MAX)"
#endif

/**
 * @brief   SPC5_CANCLK1 clock point.
 */
#if (SPC5_CGM_AC11_DC0_DIV_VALUE == 0U)
#define SPC5_CANCLK1                        0U
#else
#define SPC5_CANCLK1                        (SPC5_AUX11_CLK / SPC5_CGM_AC11_DC0_DIV_VALUE)
#endif

/* Check on SPC5_FRAY_CLK.*/
#if SPC5_CANCLK1 > SPC5_CANCLK1_MAX
#error "SPC5_CANCLK1 outside acceptable range (0...SPC5_CANCLK1_MAX)"
#endif

/**
 * @brief   SPC5_DSPI_CLK clock point.
 */
#if (SPC5_CGM_AC12_DC0_DIV_VALUE == 0U)
#define SPC5_DSPI_CLK                       0U
#else
#define SPC5_DSPI_CLK                       (SPC5_AUX12_CLK / (SPC5_CGM_AC12_DC0_DIV_VALUE * \
                                                               SPC5_CGM_AC12_DC0_DIV_FMT_VALUE))
#endif

/* Check on SPC5_DSPI_CLK.*/
#if SPC5_DSPI_CLK > SPC5_DSPI_CLK_MAX
#error "SPC5_DSPI_CLK outside acceptable range (0...SPC5_DSPI_CLK_MAX)"
#endif

/**
 * @brief   SPC5_LIN_CLK clock point.
 */
#if (SPC5_CGM_AC12_DC1_DIV_VALUE == 0U)
#define SPC5_LIN_CLK                        0U
#else
#define SPC5_LIN_CLK                        (SPC5_AUX12_CLK / SPC5_CGM_AC12_DC1_DIV_VALUE)
#endif

/* Check on SPC5_LIN_CLK.*/
#if SPC5_LIN_CLK > SPC5_LIN_CLK_MAX
#error "SPC5_LIN_CLK outside acceptable range (0...SPC5_LIN_CLK_MAX)"
#endif

/* Check ratio between SPC5_LIN_CLK and PBRIDGE_CLK.*/
#if (SPC5_LIN_CLK != 0U) && (SPC5_PBRIDGE_CLK < ((1UL * SPC5_LIN_CLK) / 3UL) || SPC5_PBRIDGE_CLK > ((2UL * SPC5_LIN_CLK) / 3UL))
#error "The relationship (2/3) * SPC5_LIN_CLK > SPC5_PBRIDGE_CLK > (1/3) * SPC5_LIN_CLK should be maintained"
#endif

/**
 * @brief   SPC5_PER_CLK clock point.
 */
#if (SPC5_CGM_AC12_DC2_DIV_VALUE == 0U)
#define SPC5_PER_CLK                        0U
#else
#define SPC5_PER_CLK                        (SPC5_AUX12_CLK / SPC5_CGM_AC12_DC2_DIV_VALUE)
#endif

/* Check on SPC5_PER_CLK.*/
#if SPC5_PER_CLK > SPC5_PER_CLK_MAX
#error "SPC5_PER_CLK outside acceptable range (0...SPC5_PER_CLK_MAX)"
#endif

/* Check XOSC is not used if it is disabled.*/
#if (SPC5_XOSC_DISABLED == TRUE)
#if ((SPC5_CGM_AC0_SC_BITS == SPC5_CGM_SC_XOSC)  || (SPC5_CGM_AC3_SC_BITS == SPC5_CGM_SC_XOSC)  || \
     (SPC5_CGM_AC4_SC_BITS == SPC5_CGM_SC_XOSC)  || (SPC5_CGM_AC6_SC_BITS == SPC5_CGM_SC_XOSC)  || \
     (SPC5_CGM_AC8_SC_BITS == SPC5_CGM_SC_XOSC)  || (SPC5_CGM_AC9_SC_BITS == SPC5_CGM_SC_XOSC)  || \
     (SPC5_CGM_AC11_SC_BITS == SPC5_CGM_SC_XOSC) || (SPC5_CGM_AC12_SC_BITS == SPC5_CGM_SC_XOSC))
#error "XOSC cannot be selected as clock source if it is disabled."
#endif

#if(SPC5_ME_MC_IS_XOSCON == TRUE)
#error "XOSCON cannot be set in one or more Run Modes if XOSC is disabled."
#endif
#endif

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void clockInit(void);
  void spc_clock_init(void);
  void __early_init(void);
  uint8_t SPCSetRunMode(uint8_t mode);
  void SPCSetPeripheralClockMode(uint32_t n, uint32_t pctl);
#if (SPC5_NO_INIT == FALSE)
  uint32_t SPCGetSystemClock(void);
#endif
#ifdef __cplusplus
}
#endif

#endif /* _CLOCK_H_ */

/** @} */

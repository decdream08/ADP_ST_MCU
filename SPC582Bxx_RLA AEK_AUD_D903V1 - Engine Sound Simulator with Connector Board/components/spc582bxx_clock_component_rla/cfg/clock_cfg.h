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

#ifndef _CLOCK_CFG_H_
#define _CLOCK_CFG_H_

/*
 * Clock parameter settings.
 */
#define SPC5_XOSC_DISABLED                  FALSE
#define SPC5_XOSC_CLK                       40000000U
#define SPC5_OSC_BYPASS                     FALSE
#define SPC5_NO_INIT                        FALSE
#define SPC5_ALLOW_OVERCLOCK                FALSE
#define SPC5_ENABLE_CLOCKOUT                FALSE
#define SPC5_CLEAR_FCCU_RGM                 TRUE
#define SPC5_CLOCK_FAILURE_HOOK()           irqSysHalt()
#define SPC5_PLL0_PREDIV_VALUE              2U
#define SPC5_PLL0_MFD_VALUE                 32U
#define SPC5_PLL0_RFDPHI_VALUE              2U
#define SPC5_PLL0_RFDPHI1_VALUE             8U
#define SPC5_PLL1_MFD_VALUE                 16U
#define SPC5_PLL1_RFDPHI_VALUE              8U
#define SPC5_CGM_SC_DC0_DIV_VALUE           1U
#define SPC5_CGM_SC_DC1_DIV_VALUE           2U
#define SPC5_CGM_SC_DC2_DIV_VALUE           2U
#define SPC5_CGM_SC_DC3_DIV_VALUE           1U
#define SPC5_CGM_SC_DC4_DIV_VALUE           1U
#define SPC5_CGM_AC0_SC_BITS                SPC5_CGM_SC_PLL0PHI
#define SPC5_CGM_AC0_DC0_DIV_VALUE          20U
#define SPC5_CGM_AC0_DC1_DIV_VALUE          8U
#define SPC5_CGM_AC3_SC_BITS                SPC5_CGM_SC_XOSC
#define SPC5_CGM_AC4_SC_BITS                SPC5_CGM_SC_PLL0PHI1
#define SPC5_CGM_AC6_SC_BITS                SPC5_CGM_SC_PLL1PHI
#define SPC5_RTCC_CLKSEL_VALUE              SPC5_RTCC_CLKSEL_LPRC
#define SPC5_CGM_AC6_DC0_DIV_VALUE          4U
#define SPC5_CGM_AC8_SC_BITS                SPC5_CGM_SC_XOSC
#define SPC5_CGM_AC8_DC0_DIV_VALUE          5U
#define SPC5_CGM_AC9_SC_BITS                SPC5_CGM_SC_XOSC
#define SPC5_CGM_AC9_DC0_DIV_VALUE          1U
#define SPC5_CGM_AC11_SC_BITS               SPC5_CGM_SC_XOSC
#define SPC5_CGM_AC11_DC0_DIV_VALUE         5U
#define SPC5_CGM_AC12_SC_BITS               SPC5_CGM_SC_PLL0PHI
#define SPC5_CGM_AC12_DC0_DIV_VALUE         4U
#define SPC5_CGM_AC12_DC0_DIV_FMT_VALUE     1U
#define SPC5_CGM_AC12_DC1_DIV_VALUE         4U
#define SPC5_CGM_AC12_DC2_DIV_VALUE         4U
#define SPC5_ME_ME_BITS                     (0UL | SPC5_ME_ME_RESET | SPC5_ME_ME_SAFE | SPC5_ME_ME_DRUN | SPC5_ME_ME_RUN0 | SPC5_ME_ME_RUN1 | SPC5_ME_ME_RUN2 | SPC5_ME_ME_RUN3 | SPC5_ME_ME_HALT0 | SPC5_ME_ME_STOP0 | SPC5_ME_ME_STANDBY0)
#define SPC5_ME_SAFE_MC_BITS                (0UL | SPC5_ME_MC_PWRLVL(0) | SPC5_ME_MC_PDO | SPC5_ME_MC_MVRON | SPC5_ME_MC_FLAON_NORMAL | SPC5_ME_MC_IRCON | SPC5_ME_MC_SYSCLK_IRC)
#define SPC5_ME_DRUN_MC_BITS                (0UL | SPC5_ME_MC_PWRLVL(0) | SPC5_ME_MC_MVRON | SPC5_ME_MC_FLAON_NORMAL | SPC5_ME_MC_PLL1ON | SPC5_ME_MC_PLL0ON | SPC5_ME_MC_XOSCON | SPC5_ME_MC_IRCON | SPC5_ME_MC_SYSCLK_PLL1PHI)
#define SPC5_ME_RUN0_MC_BITS                (0UL | SPC5_ME_MC_PWRLVL(0) | SPC5_ME_MC_MVRON | SPC5_ME_MC_FLAON_NORMAL | SPC5_ME_MC_PLL1ON | SPC5_ME_MC_PLL0ON | SPC5_ME_MC_XOSCON | SPC5_ME_MC_IRCON | SPC5_ME_MC_SYSCLK_PLL1PHI)
#define SPC5_ME_RUN1_MC_BITS                (0UL | SPC5_ME_MC_PWRLVL(0) | SPC5_ME_MC_MVRON | SPC5_ME_MC_FLAON_NORMAL | SPC5_ME_MC_IRCON | SPC5_ME_MC_SYSCLK_IRC)
#define SPC5_ME_RUN2_MC_BITS                (0UL | SPC5_ME_MC_PWRLVL(0) | SPC5_ME_MC_MVRON | SPC5_ME_MC_FLAON_NORMAL | SPC5_ME_MC_IRCON | SPC5_ME_MC_SYSCLK_IRC)
#define SPC5_ME_RUN3_MC_BITS                (0UL | SPC5_ME_MC_PWRLVL(0) | SPC5_ME_MC_MVRON | SPC5_ME_MC_FLAON_NORMAL | SPC5_ME_MC_IRCON | SPC5_ME_MC_SYSCLK_IRC)
#define SPC5_ME_HALT0_MC_BITS               (0UL | SPC5_ME_MC_PWRLVL(0) | SPC5_ME_MC_MVRON | SPC5_ME_MC_FLAON_LP | SPC5_ME_MC_IRCON | SPC5_ME_MC_SYSCLK_IRC)
#define SPC5_ME_STOP0_MC_BITS               (0UL | SPC5_ME_MC_PWRLVL(0) | SPC5_ME_MC_MVRON | SPC5_ME_MC_FLAON_PD | SPC5_ME_MC_IRCON | SPC5_ME_MC_SYSCLK_IRC)
#define SPC5_ME_STANDBY0_MC_BITS            (0UL | SPC5_ME_MC_PWRLVL(0) | SPC5_ME_MC_PDO | SPC5_ME_MC_FLAON_PD | SPC5_ME_MC_IRCON | SPC5_ME_MC_SYSCLK_DISABLED)
#define SPC5_ME_MC_IS_XOSCON                TRUE
#define SPC5_ME_RUN_PC3_BITS                (0UL)
#define SPC5_ME_RUN_PC4_BITS                (0UL)
#define SPC5_ME_RUN_PC5_BITS                (0UL)
#define SPC5_ME_RUN_PC6_BITS                (0UL)
#define SPC5_ME_RUN_PC7_BITS                (0UL)
#define SPC5_ME_LP_PC4_BITS                 (0UL)
#define SPC5_ME_LP_PC5_BITS                 (0UL)
#define SPC5_ME_LP_PC6_BITS                 (0UL)
#define SPC5_ME_LP_PC7_BITS                 (0UL)
#define SPC5_FINAL_RUNMODE                  SPC5_RUNMODE_RUN0

#define SPC5_SYS_CLK 						80000000U
#define SPC5_CORE2_CLK 						80000000U
#define SPC5_XBAR_CLK  						80000000U

#endif /* _CLOCK_CFG_H_ */

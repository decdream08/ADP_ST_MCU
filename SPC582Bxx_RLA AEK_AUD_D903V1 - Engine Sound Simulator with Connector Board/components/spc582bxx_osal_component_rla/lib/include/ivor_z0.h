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
 * @file    ivor_z0.h
 * @brief   Interrupt Handler Macros.
 *
 * @addtogroup PPC_CORE
 * @{
 */

#define _FROM_ASM_

#if !defined(__DOXYGEN__)

#define LOAD_IVOR1_EXC_REG LOAD_CSSR0_CSSR1
#define RET_IVOR1 se_rfci
#if defined (_SPC570Sxx_)
#define LOAD_IVOR9_EXC_REG LOAD_DSSR0_DSSR1
#define RET_IVOR9 se_rfdi
#else
#define LOAD_IVOR9_EXC_REG LOAD_SSR0_SSR1_PLUS
#define RET_IVOR9 se_rfi
#endif


#endif /* !defined(__DOXYGEN__) */


  /** @} */

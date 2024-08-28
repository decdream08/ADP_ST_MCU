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
 * @file    ivor_z2.h
 * @brief   Interrupt Handler Macros.
 *
 * @addtogroup PPC_CORE
 * @{
 */

 #define _FROM_ASM_

#if !defined(__DOXYGEN__)

#define LOAD_IVOR1_EXC_REG LOAD_MCSSR0_MCSR
#define LOAD_IVOR9_EXC_REG LOAD_DSSR0_DSSR1
#define RET_IVOR1 se_rfmci
#define RET_IVOR9 se_rfdi 

#endif /* !defined(__DOXYGEN__) */

/** @} */

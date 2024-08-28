/****************************************************************************
*
* Copyright (c) 2017-2020 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    crc_lld_cfg.h
 * @brief   CRC Driver configuration macros and structures.
 * @addtogroup CRC
 * @{
 */

#ifndef _CRC_LLD_CFG_H_
#define _CRC_LLD_CFG_H_

#include <crc_lld.h>

#if (LLD_USE_CRC == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver defines.                                                           */
/*===========================================================================*/

/** @brief  Number of CRC modules */
#define SPC5_CRC_MODULES                         2U

#define SPC5_CRC_0_PTCL                          38
#define SPC5_CRC_1_PTCL                          166

/** @brief  Number of contexts for CRC modules */
#define SPC5_CRC_CONTEXTS                        4U

#define SPC5_CRC_CONTEXT_OUTPUT_INVERSION        0x01U
#define SPC5_CRC_CONTEXT_OUTPUT_SWAP             0x02U
#define SPC5_CRC_CONTEXT_POLYNOMIAL_CRC_CCITT    0x00U
#define SPC5_CRC_CONTEXT_POLYNOMIAL_CRC_32       0x04U
#define SPC5_CRC_CONTEXT_POLYNOMIAL_CRC_8        0x08U
#define SPC5_CRC_CONTEXT_POLYNOMIAL_CRC_8H2F     0x0CU
#define SPC5_CRC_CONTEXT_INPUT_BIT_SWAP          0x10U
#define SPC5_CRC_CONTEXT_INPUT_BYTE_SWAP         0x20U

/*===========================================================================*/
/* Driver constants, data structures and types.                              */
/*===========================================================================*/


#endif /* LLD_USE_CRC */
#endif /* _CRC_LLD_CFG_H_ */

/** @} */

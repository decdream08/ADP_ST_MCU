/****************************************************************************
*
* Copyright (c) 2021 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    aic_lld_cfg.h
 * @brief   AIC Driver configuration macros and structures.
 *
 * @addtogroup AIC
 * @{
 */

#ifndef _AIC_LLD_CFG_H_
#define _AIC_LLD_CFG_H_

#include <aic_lld.h>

#if (LLD_USE_AIC == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/** @brief  Maximum number of registers for AIC signature */
#define SPC5_AIC_SIGNATURE_REGS      10U

/** @brief  Mask for implemented registers for AIC signature */
#define SPC5_AIC_UM_REGS_MASK     0x30FU

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/



#endif /* LLD_USE_AIC */
#endif /* _AIC_LLD_CFG_H_ */

/** @} */

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
 * @file    swt_lld_cfg.h
 * @brief   SWT Driver configuration macros and structures.
 *
 * @addtogroup SWT
 * @{
 */

#ifndef _SWT_LLD_CFG_H_
#define _SWT_LLD_CFG_H_

#include "spc5_lld.h"
#include "swt_lld.h"

#if (LLD_USE_SWT == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/
/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* List of the SWTConfig structures defined in swt_lld_cfg.c.*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 * SWT configuration structures and callback prototypes.
 */





#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_SWT */

#endif /* _SWT_LLD_CFG_H_ */

/** @} */

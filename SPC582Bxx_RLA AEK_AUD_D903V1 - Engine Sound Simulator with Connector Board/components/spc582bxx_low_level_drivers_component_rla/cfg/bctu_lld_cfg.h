/****************************************************************************
*
* Copyright © 2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    bctu_lld_cfg.h
 * @brief   BCTU Driver configuration macros and structures.
 *
 * @addtogroup BCTU
 * @{
 */

#ifndef _BCTU_LLD_CFG_H_
#define _BCTU_LLD_CFG_H_

#include "spc5_lld.h"
#include "bctu_lld.h"

#if (LLD_USE_BCTU == TRUE) || defined(__DOXYGEN__)

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

/* List of the BCTUChannelConfig structures defined in bctu_lld_cfg.c.*/

/* List of the BCTUConfig structures defined in bctu_lld_cfg.c.*/

#endif /* LLD_USE_BCTU */

#endif /* _BCTU_LLD_CFG_H_ */

/** @} */

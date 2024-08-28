/****************************************************************************
*
* Copyright © 2015-2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    pit_lld_cfg.h
 * @brief   PIT Driver configuration macros and strupitres.
 *
 * @addtogroup PIT
 * @{
 */

#ifndef _PIT_LLD_CFG_H_
#define _PIT_LLD_CFG_H_

#include "spc5_lld.h"
#include "pit_lld.h"

#if (LLD_USE_PIT == TRUE) || defined(__DOXYGEN__)

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
/* Driver data strupitres and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* List of the PITConfig structures defined in pit_lld_cfg.c.*/
extern PIT_CH_Config pit0_config[SPC5_PIT0_CHANNELS];

#ifdef __cplusplus
extern "C" {
#endif
/*Callback Prototypes*/
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_PIT */

#endif /* _PIT_LLD_CFG_H_ */

/** @} */

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
 * @file    i2s_lld_cfg.h
 * @brief   I2S Driver configuration macros and structures.
 *
 * @addtogroup I2S
 * @{
 */

#ifndef _I2S_LLD_CFG_H_
#define _I2S_LLD_CFG_H_

#include "spc5_lld.h"
#include "i2s_lld.h"

#if (LLD_USE_I2S == TRUE) || defined(__DOXYGEN__)

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

/* List of the I2SConfig structures defined in i2s_lld_cfg.c.*/
extern I2SConfig i2s_config_AEK_AUD_D903V1Board0_J10_WS_LABEL_I2SCR_I2SSDA1_SCL;

#ifdef __cplusplus
extern "C" {
#endif
  /* List of the callback functions referenced from the I2SConfig structures in i2s_lld_cfg.c.*/
  void EndTransmitCallback(I2SDriver *i2sp);
  void HalfTransmitCallback(I2SDriver *i2sp);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_I2S */

#endif /* _I2S_LLD_CFG_H_ */

/** @} */

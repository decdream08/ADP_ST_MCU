/****************************************************************************
*
* Copyright © 2017-2021 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    i2c_lld_cfg.c
 * @brief   I2C Driver configuration code.
 *
 * @addtogroup I2C
 * @{
 */

#include "i2c_lld_cfg.h"

#if (LLD_USE_I2C == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   Structure defining the I2C HW configuration "AEK_AUD_D903V1Board0".
 */
I2CHWConfig i2c_hw_config_AEK_AUD_D903V1Board0 = {
  I2C_HARDWARE,
  I2C_MASTER,
  (0x6d << 0x1),
  I2C_DRIVEN_BY_INTERRUPT,
  800,
  144
};


/*===========================================================================*/
/* Driver local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

 /*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

#endif /* LLD_USE_I2C */

/** @} */

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
 * @file    i2c_lld_cfg.h
 * @brief   I2C Driver configuration macros and structures.
 *
 * @addtogroup I2C
 * @{
 */

#ifndef _I2C_LLD_CFG_H_
#define _I2C_LLD_CFG_H_

#include <i2c_lld.h>

#if (LLD_USE_I2C == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/
/* The max number of the available I2C Hardware interfaces */
#define I2C_HW_NUMBER_OF_DRIVERS   1U
/* The max number of the configurable I2C Software interfaces */
#define I2C_SW_NUMBER_OF_DRIVERS   4U

/* I2C HW instance #1 */
#define I2CD1_ENABLE	TRUE
#define I2CD1_INIT		i2c_hw_init
#define I2CD1_TYPE		I2C_CONFIG_HARDWARE

/* I2C SW instance #2 */
#define I2CD2_ENABLE	FALSE
#define I2CD2_TYPE		I2C_CONFIG_SOFTWARE
/* I2C SW instance #3 */
#define I2CD3_ENABLE	FALSE
#define I2CD3_TYPE		I2C_CONFIG_SOFTWARE
/* I2C SW instance #4 */
#define I2CD4_ENABLE	FALSE
#define I2CD4_TYPE		I2C_CONFIG_SOFTWARE
/* I2C SW instance #5 */
#define I2CD5_ENABLE	FALSE
#define I2CD5_TYPE		I2C_CONFIG_SOFTWARE

/* I2C Common interface for old and new registry references */
#define IIC_TX TXRX
#define IIC_MS MSSL
#ifndef IIC_0 
#define IIC_0 I2C_0
#define IIC_TAG volatile struct I2C_tag
#else
#define IIC_TAG volatile struct IIC_tag
#endif

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/
/* List of the I2CHWConfig structures defined in i2c_lld_cfg.c.*/
extern I2CHWConfig i2c_hw_config_AEK_AUD_D903V1Board0;

/* List of the I2CSWConfig structures defined in i2c_lld_cfg.c.*/

#endif /* LLD_USE_I2C */
#endif /* _I2C_LLD_CFG_H_ */

/** @} */

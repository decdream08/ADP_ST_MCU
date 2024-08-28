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
 * @file    i2c_hw.h
 * @brief   SPC5xx Hardware I2C low level driver header.
 *
 * @addtogroup I2C
 * @{
 */
#ifndef _I2C_HW_H_
#define _I2C_HW_H_

#include <i2c_if.h>

#if (LLD_USE_I2C == TRUE) || defined(__DOXYGEN__)

/*******************************************************************************
* Includes
*******************************************************************************/

/*******************************************************************************
* Constants
*******************************************************************************/

/*******************************************************************************
* Macros 
*******************************************************************************/

/*******************************************************************************
* Types
*******************************************************************************/

/*******************************************************************************
* Global variables
*******************************************************************************/

/*******************************************************************************
* Global functions
*******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

void i2c_hw_init(i2c_ops_t *ops);

#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_I2C */

#endif /* _I2C_HW_H_ */
/** @} */
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
 * @file    i2c_if.h
 * @brief   SPC5xx I2C wrapper interface to low level driver.
 *
 * @addtogroup I2C
 * @{
 */
#ifndef _I2C_IF_H_
#define _I2C_IF_H_

#include <i2c_lld.h>

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

#define I2C_8_BIT_REG_ADDRESS         1U
#define I2C_16_BIT_REG_ADDRESS        2U

/*******************************************************************************
* Types
*******************************************************************************/
/**
 * @brief   Type of a structure representing I2C driver operations.
 */
typedef struct i2c_ops_s {

  /**
   * @brief   Hardware or software driver id.
   */
  uint32_t       id;

  /**
   * @brief   Private pointer used by internal driver implementation.
   */
  void          *priv;

  /**
   * @brief   Low level I2C start function.
   */
  i2c_result_t (*start)(void *i2cd, void *config);

  /**
   * @brief   Low level I2C stop function.
   */
  i2c_result_t (*stop)(void *i2cd);

  /**
   * @brief   Low level I2C write function.
   */
  int (*write)(void *i2cd, uint8_t dev_addr, uint16_t reg_addr, uint8_t reg_addr_size, uint8_t *data, uint32_t ndata_bytes);

  /**
   * @brief   Low level I2C read function.
   */
  int (*read)(void *i2cd, uint8_t dev_addr, uint16_t reg_addr, uint8_t reg_addr_size, uint8_t *data, uint32_t ndata_bytes);

} i2c_ops_t;

/*******************************************************************************
* Global variables
*******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_I2C */

#endif /* _I2C_IF_H_ */
/** @} */

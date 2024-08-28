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
 * @file    i2c_lld.h
 * @brief   SPC5xx I2C control unit.
 *
 * @addtogroup I2C
 * @{
 */
#include <i2c_lld.h>

#if (LLD_USE_I2C == TRUE) || defined(__DOXYGEN__)
	
#include <string.h>
#include <i2c_lld_cfg.h>
#include <i2c_if.h>
#include <i2c_hw.h>
#include <i2c_sw.h>

/*******************************************************************************
* External objects
*******************************************************************************/

/*******************************************************************************
* Global variables
*******************************************************************************/

/*******************************************************************************
* Constants and macros
*******************************************************************************/

/*******************************************************************************
* Local types
*******************************************************************************/

/**
 * @brief   Structure representing an I2C driver.
 */
struct I2CDriver {
  /**
   * @brief   I2C driver type (Hardware/Software).
   */
  i2c_type_t   type;

  /**
   * @brief   Low level driver operations.
   */
  i2c_ops_t    ops;
};

/*******************************************************************************
* Local function prototypes
*******************************************************************************/

/*******************************************************************************
* Local variables
*******************************************************************************/
/**
 * @brief   I2C driver instance #1.
 */
#if (I2CD1_ENABLE == TRUE)
I2CDriver I2CD1;
#endif
/**
 * @brief   I2C driver instance #2.
 */
#if (I2CD2_ENABLE == TRUE)
I2CDriver I2CD2;
#endif
/**
 * @brief   I2C driver instance #3.
 */
#if (I2CD3_ENABLE == TRUE)
I2CDriver I2CD3;
#endif
/**
 * @brief   I2C driver instance #4.
 */
#if (I2CD4_ENABLE == TRUE)
I2CDriver I2CD4;
#endif
/**
 * @brief   I2C driver instance #5.
 */
#if (I2CD5_ENABLE == TRUE)
I2CDriver I2CD5;
#endif
/**
 * @brief   I2C driver instance #6.
 */
#if (I2CD6_ENABLE == TRUE)
I2CDriver I2CD6;
#endif
/**
 * @brief   I2C driver instance #7.
 */
#if (I2CD7_ENABLE == TRUE)
I2CDriver I2CD7;
#endif
/**
 * @brief   I2C driver instance #8.
 */
#if (I2CD8_ENABLE == TRUE)
I2CDriver I2CD8;
#endif

/*******************************************************************************
* Local functions
*******************************************************************************/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*******************************************************************************
* Global functions
*******************************************************************************/

/**
 * @brief   Initialize I2C drivers
 *
 * @api
 */
void i2c_lld_init(void) {

#if (I2CD1_ENABLE == TRUE)
  I2CD1.ops.id = 0U;
  I2CD1.type = I2CD1_TYPE;
  I2CD1_INIT(&I2CD1.ops);
#endif
#if (I2CD2_ENABLE == TRUE)
  I2CD2.ops.id = 1U;
  I2CD2.type = I2CD2_TYPE;
  I2CD2_INIT(&I2CD2.ops);
#endif
#if (I2CD3_ENABLE == TRUE)
  I2CD3.ops.id = 2U;
  I2CD3.type = I2CD3_TYPE;
  I2CD3_INIT(&I2CD3.ops);
#endif
#if (I2CD4_ENABLE == TRUE)
  I2CD4.ops.id = 3U;
  I2CD4.type = I2CD4_TYPE;
  I2CD4_INIT(&I2CD4.ops);
#endif
#if (I2CD5_ENABLE == TRUE)
  I2CD5.ops.id = 0U;
  I2CD5.type = I2CD5_TYPE;
  I2CD5_INIT(&I2CD5.ops);
#endif
#if (I2CD6_ENABLE == TRUE)
  I2CD6.ops.id = 1U;
  I2CD6.type = I2CD6_TYPE;
  I2CD6_INIT(&I2CD6.ops);
#endif
#if (I2CD7_ENABLE == TRUE)
  I2CD7.ops.id = 2U;
  I2CD7.type = I2CD7_TYPE;
  I2CD7_INIT(&I2CD7.ops);
#endif
#if (I2CD8_ENABLE == TRUE)
  I2CD8.ops.id = 3U;
  I2CD8.type = I2CD8_TYPE;
  I2CD8_INIT(&I2CD8.ops);
#endif
}


/**
 * @brief    I2C driver initialization.
 *
 * @details  The module will be initialized with a provided configuration structure.
 *
 * @param[in] i2cd      pointer to the @p I2CDriver object
 * @param[in] config    pointer to the @p I2CHWConfig or I2CSWConfig object
 *
 * @return    operation result.
 *
 * @api
 */
i2c_result_t i2c_lld_start(I2CDriver *i2cd, void *config) {

  I2CHWConfig *hw_config;

  if (config == NULL) {
    return I2C_ERROR_INVALID_ARGUMENT;
  }

  /*
   * Assuming an hardware configuration just to read first field
   * which is the configuration type.
   * For both hardware and software configuration structures
   * first field is always the configuration type
   */
  hw_config = config;

  if (i2cd->type != hw_config->type) {
    return I2C_ERROR_INVALID_ARGUMENT;
  }

  return (i2cd->ops.start != NULL) ? i2cd->ops.start(i2cd->ops.priv, config) : I2C_ERROR_INVALID_ARGUMENT;
}


/**
 * @brief   Stops I2C module.
 *
 * @param[in] i2cd      pointer to the @p I2CDriver object
 *
 * @return    operation result.
 *
 * @api
 */
i2c_result_t i2c_lld_stop(I2CDriver *i2cd) {

  return (i2cd->ops.stop != NULL) ? i2cd->ops.stop(i2cd->ops.priv) : I2C_ERROR_INVALID_ARGUMENT;
}

/**
 * @brief   I2C Write routine
 *
 * @param[in]  i2cd         pointer to the @p I2CDriver object
 * @param[in]  dev_addr     device to address. Valid range [0x08,0x77].
 * @param[in]  reg_addr     internal device register to address.
 * @param[in]  data         pointer to data buffer to send.
 * @param[in]  ndata_bytes  data length in bytes.
 *
 * @return    operation result.
 *
 * @api
 */
int i2c_lld_write(I2CDriver *i2cd, uint8_t dev_addr, uint16_t reg_addr, uint8_t *data, uint32_t ndata_bytes) {

  if (ndata_bytes == 0U) {
    return I2C_NO_ERROR;
  }

  /* Check for valid address */
  if ((dev_addr == 0U) || ((dev_addr & 1U) == 1U)) {
    return I2C_ERROR_INVALID_ADDRESS;
  }

  if (data == NULL) {
    return I2C_ERROR_INVALID_ARGUMENT;
  }

  return (i2cd->ops.write != NULL) ? i2cd->ops.write(i2cd->ops.priv, dev_addr, reg_addr, I2C_8_BIT_REG_ADDRESS, data, ndata_bytes) : I2C_ERROR_INVALID_ARGUMENT;
}

/**
 * @brief     I2C read routine
 *
 * @param[in]  i2cd         pointer to the @p I2CDriver object
 * @param[in]  dev_addr     device to address. Valid range [0x08,0x77].
 * @param[in]  reg_addr     internal device register to address.
 * @param[out] data         buffer for data receiving.
 * @param[in]  ndata_bytes  data buffer length in bytes.
 *
 * @return    operation result.
 *
 * @api
 */
int i2c_lld_read(I2CDriver *i2cd, uint8_t dev_addr, uint16_t reg_addr, uint8_t *data, uint32_t ndata_bytes) {

  if (ndata_bytes == 0U) {
    return I2C_NO_ERROR;
  }

  /* Check for valid address */
  if ((dev_addr == 0U) || ((dev_addr & 1U) == 1U)) {
    return I2C_ERROR_INVALID_ADDRESS;
  }

  if (data == NULL) {
    return I2C_ERROR_INVALID_ARGUMENT;
  }

  return (i2cd->ops.read != NULL) ? i2cd->ops.read(i2cd->ops.priv, dev_addr, reg_addr, I2C_8_BIT_REG_ADDRESS, data, ndata_bytes) : I2C_ERROR_INVALID_ARGUMENT;
}

/**
 * @brief   I2C Write routine (16 bit register address)
 *
 * @param[in]  i2cd         pointer to the @p I2CDriver object
 * @param[in]  dev_addr     device to address. Valid range [0x08,0x77].
 * @param[in]  reg_addr     internal device register to address.
 * @param[in]  data         pointer to data buffer to send.
 * @param[in]  ndata_bytes  data length in bytes.
 *
 * @return    operation result.
 *
 * @api
 */
i2c_result_t i2c_lld_write16(I2CDriver *i2cd, uint8_t dev_addr, uint16_t reg_addr, uint8_t *data, uint32_t ndata_bytes) {

  if (ndata_bytes == 0U) {
    return I2C_NO_ERROR;
  }

  /* Check for valid address */
  if ((dev_addr == 0U) || ((dev_addr & 1U) == 1U)) {
    return I2C_ERROR_INVALID_ADDRESS;
  }

  if (data == NULL) {
    return I2C_ERROR_INVALID_ARGUMENT;
  }

  return (i2cd->ops.write != NULL) ? i2cd->ops.write(i2cd->ops.priv, dev_addr, reg_addr, I2C_16_BIT_REG_ADDRESS, data, ndata_bytes) : I2C_ERROR_INVALID_ARGUMENT;
}

/**
 * @brief     I2C read routine (16 bit register address)
 *
 * @param[in]  i2cd         pointer to the @p I2CDriver object
 * @param[in]  dev_addr     device to address. Valid range [0x08,0x77].
 * @param[in]  reg_addr     internal device register to address.
 * @param[out] data         buffer for data receiving.
 * @param[in]  ndata_bytes  data buffer length in bytes.
 *
 * @return    operation result.
 *
 * @api
 */
int i2c_lld_read16(I2CDriver *i2cd, uint8_t dev_addr, uint16_t reg_addr, uint8_t *data, uint32_t ndata_bytes) {

  if (ndata_bytes == 0U) {
    return I2C_NO_ERROR;
  }

  /* Check for valid address */
  if ((dev_addr == 0U) || ((dev_addr & 1U) == 1U)) {
    return I2C_ERROR_INVALID_ADDRESS;
  }

  if (data == NULL) {
    return I2C_ERROR_INVALID_ARGUMENT;
  }

  return (i2cd->ops.read != NULL) ? i2cd->ops.read(i2cd->ops.priv, dev_addr, reg_addr, I2C_16_BIT_REG_ADDRESS, data, ndata_bytes) : I2C_ERROR_INVALID_ARGUMENT;
}

#endif /* LLD_USE_I2C */
/** @} */


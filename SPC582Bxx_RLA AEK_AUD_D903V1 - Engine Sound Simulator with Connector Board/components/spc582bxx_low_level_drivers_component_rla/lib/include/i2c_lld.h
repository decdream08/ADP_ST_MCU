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
 * @brief   SPC5xx I2C low level driver header.
 *
 * @addtogroup I2C
 * @{
 */
#ifndef _I2C_LLD_H_
#define _I2C_LLD_H_

#include <spc5_lld.h>
#include <lldconf.h>

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
/**
 * @brief   Type of a structure representing an I2C driver.
 */
typedef struct I2CDriver I2CDriver;

/**
 * @brief I2C input configuration type.
 */
#define I2C_CONFIG_HARDWARE    0U 	/**< @brief   I2C Hardware configurtion type. */
#define I2C_CONFIG_SOFTWARE    1U	/**< @brief   I2C Software configuration type. */

/**
 * @brief I2C driver type.
 */
typedef enum {
  I2C_HARDWARE = I2C_CONFIG_HARDWARE,  /**< @brief   I2C driver for hardware device. */
  I2C_SOFTWARE = I2C_CONFIG_SOFTWARE   /**< @brief   I2C driver for software device. */
} i2c_type_t;

/**
 * @brief I2C functional mode.
 */
typedef enum {
  I2C_SLAVE,       /**< @brief   I2C driver configured in slave mode. */
  I2C_MASTER       /**< @brief   I2C driver configured in master mode. */
} i2c_mode_t;

/**
 * @brief I2C repeat start mode.
 */
typedef enum {
  I2C_DISABLE_REPEAT_START,	/**< @brief   I2C disable repeat start mode. */
  I2C_ENABLE_REPEAT_START,	/**< @brief   I2C enable repeat start mode. */
  I2C_DISABLE_ACKNOWLEDGE,  /**< @brief   I2C disable acknowledge. */
  I2C_ENABLE_ACKNOWLEDGE,   /**< @brief   I2C enable acknowledge. */
} i2c_property_t;

/**
 * @brief I2C transfer type.
 */
typedef enum {
  I2C_DRIVEN_BY_POLLING,       /**< @brief   I2C driver for hardware device in polling mode. */
  I2C_DRIVEN_BY_INTERRUPT      /**< @brief   I2C driver for hardware device in interrupt mode. */
} i2c_transfer_mode_t;

/**
 * @brief    I2C computation results
 */
typedef enum {
  I2C_NO_ERROR = 0,                	  /**< @brief   no errors. */
  I2C_ERROR_TRANSFER_IN_PROGRESS = -1,/**< @brief   transfer is on going. */
  I2C_ERROR_NO_ACK = -2,           	  /**< @brief   acknowledge not received. */
  I2C_ERROR_BUS_BUSY = -3,        	  /**< @brief   bus is busy. */
  I2C_ERROR_ARBITRATION_LOST = -4,    /**< @brief   arbitration lost notified. */
  I2C_ERROR_INVALID_ADDRESS = -5,     /**< @brief   slave device not found. */
  I2C_ERROR_INVALID_ARGUMENT = -6,    /**< @brief   wrong input argument. */
  I2C_ERROR_TIMEOUT = -7,             /**< @brief   timeout on transfer. */
  I2C_ERROR_BUFFER_OVERFLOW = -8	  /**< @brief   Buffer overflow */
} i2c_result_t;


/**
 * @brief   Driver configuration structure for I2C Hardware.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
typedef struct {
  /**
   * @brief   I2C type (Hardware/Software) [Must be the first field].
   */
  i2c_type_t            type;
  /**
   * @brief   I2C mode (Master/Slave).
   */
  i2c_mode_t            mode;
    /**
   * @brief   I2C Slave Address.
   */
  uint8_t               slave_addr;
  /**
   * @brief   I2C transfer mode (Interrupt/Polling).
   */
  i2c_transfer_mode_t   transfer_mode;
  /**
   * @brief   I2C timeout (msec).
   */
  uint32_t              timeout;
  /**
   * @brief   I2C baud rate configuration register.
   */
  uint8_t               ibc;
} I2CHWConfig;


/**
 * @brief   Driver configuration structure for I2C Software.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
typedef struct {
  /**
   * @brief   I2C type (Hardware/Software)  [Must be the first field].
   */
  i2c_type_t            type;
    /**
   * @brief   I2C Slave Address.
   */
  uint8_t               slave_addr;
  /**
   * @brief   I2C timeout (msec).
   */
  uint32_t              timeout;
  /**
   * @brief   I2C SCL port.
   */
  uint32_t              scl_port;
  /**
   * @brief   I2C SCL pin.
   */
  uint32_t              scl_pin;
  /**
   * @brief   I2C SDA port.
   */
  uint32_t              sda_port;
  /**
   * @brief   I2C SDA pin.
   */
  uint32_t              sda_pin;
} I2CSWConfig;


/*******************************************************************************
* Global variables
*******************************************************************************/

#ifndef __DOXYGEN__
extern I2CDriver I2CD1;
extern I2CDriver I2CD2;
extern I2CDriver I2CD3;
extern I2CDriver I2CD4;
extern I2CDriver I2CD5;
extern I2CDriver I2CD6;
extern I2CDriver I2CD7;
extern I2CDriver I2CD8;
#endif /* __DOXYGEN__ */

/*******************************************************************************
* Global functions
*******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

void i2c_lld_init(void);
i2c_result_t i2c_lld_start(I2CDriver *i2cd, void *config);
i2c_result_t i2c_lld_stop(I2CDriver *i2cd);
int i2c_lld_write(I2CDriver *i2cd, uint8_t dev_addr, uint16_t reg_addr,
							uint8_t *data, uint32_t ndata_bytes);
int i2c_lld_read(I2CDriver *i2cd, uint8_t dev_addr, uint16_t reg_addr,
							uint8_t *data, uint32_t ndata_bytes);
int i2c_lld_write16(I2CDriver *i2cd, uint8_t dev_addr, uint16_t reg_addr,
							uint8_t *data, uint32_t ndata_bytes);
int i2c_lld_read16(I2CDriver *i2cd, uint8_t dev_addr, uint16_t reg_addr,
							uint8_t *data, uint32_t ndata_bytes);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_I2C */

#endif /* _I2C_LLD_H_ */
/** @} */

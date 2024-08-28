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
 * @file    i2c_sw.c
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
#include <i2c_sw.h>
#include <siul_lld.h>

/*******************************************************************************
* External objects
*******************************************************************************/

/*******************************************************************************
* Global variables
*******************************************************************************/

/*******************************************************************************
* Constants and macros
*******************************************************************************/

/** Write bit (see I2C Specification) */
#define I2C_SW_WRITE          0U

/** Read bit (see I2C Specification) */
#define I2C_SW_READ           1U

/** Wait timeout for clock line goes low (stretch clock) */
#define I2C_SW_WAIT_TIMEOUT   2000U

/** Clock low value */
#define I2C_SW_CLOCK_LOW      0U

/** Clock high value */
#define I2C_SW_CLOCK_HIGH     1U

/*
 * Delay
 * 40 = 80 KHz (clock frequency)
 */
#define I2C_SW_DELAY      40U

/* Common macros */
#define I2C_SET_LOW(_port_, _pin_)     siul_lld_clearpad((_port_), (_pin_))
#define I2C_SET_HIGH(_port_, _pin_)    siul_lld_setpad((_port_), (_pin_))
#define I2C_GET_VALUE(_port_, _pin_)   siul_lld_readpad((_port_), (_pin_))

/* Clock line macros */
#define I2C_CLOCK_LOW(_i2cd_)          I2C_SET_LOW((_i2cd_)->scl_port, (_i2cd_)->scl_pin)
#define I2C_CLOCK_HIGH(_i2cd_)         I2C_SET_HIGH((_i2cd_)->scl_port, (_i2cd_)->scl_pin)
#define I2C_CLOCK_GET(_i2cd_)          I2C_GET_VALUE((_i2cd_)->scl_port, (_i2cd_)->scl_pin)

/* Data line macros */
#define I2C_DATA_LOW(_i2cd_)           I2C_SET_LOW((_i2cd_)->sda_port, (_i2cd_)->sda_pin)
#define I2C_DATA_HIGH(_i2cd_)          I2C_SET_HIGH((_i2cd_)->sda_port, (_i2cd_)->sda_pin)
#define I2C_DATA_GET(_i2cd_)           I2C_GET_VALUE((_i2cd_)->sda_port, (_i2cd_)->sda_pin)

/* Simple no-operation macro */
#define __NOP()                        asm volatile ("e_ori  0, 0, 0\t\n")

/*******************************************************************************
* Local types
*******************************************************************************/

/**
 * @brief   Structure representing a SW I2C driver.
 */
typedef struct I2C_SW_Driver {
  /**
   * @brief Port used for SCL line.
   */
  uint32_t scl_port;

  /**
   * @brief Pin used for SCL line.
   */
  uint32_t scl_pin;

  /**
   * @brief Port used for SDA line.
   */
  uint32_t sda_port;

  /**
   * @brief Pin used for SCL line.
   */
  uint32_t sda_pin;
} I2C_SW_Driver;

/*******************************************************************************
* Local function prototypes
*******************************************************************************/

/*******************************************************************************
* Local variables
*******************************************************************************/

static struct I2C_SW_Driver i2c_sw[I2C_SW_NUMBER_OF_DRIVERS];

/*******************************************************************************
* Local functions
*******************************************************************************/

/* Busy wait delay */
static inline void i2c_sw_delay(uint16_t times) {
  uint16_t i;
  for (i = 0U; i < times; i++) {
    __NOP();
  }
}


/* I2C wait for clock line specific level (high/low) */
static inline void i2c_sw_wait(I2C_SW_Driver *i2cd, uint32_t clk) {
  uint32_t timeout;

  timeout = 0U;
  do {
    i2c_sw_delay(I2C_SW_DELAY);
    timeout++;
    if (timeout > I2C_SW_WAIT_TIMEOUT) {
      break;
    }
  } while (I2C_CLOCK_GET(i2cd) == clk);
}


/* I2C start condition */
static inline void i2c_sw_start_condition(I2C_SW_Driver *i2cd) {

  I2C_CLOCK_LOW(i2cd);
  i2c_sw_delay(I2C_SW_DELAY);

  I2C_DATA_HIGH(i2cd);
  I2C_CLOCK_HIGH(i2cd);
  i2c_sw_delay(I2C_SW_DELAY);

  I2C_DATA_LOW(i2cd);
  i2c_sw_delay(I2C_SW_DELAY);

  I2C_CLOCK_LOW(i2cd);
  i2c_sw_delay(I2C_SW_DELAY);
}


/* I2C stop condition */
static inline void i2c_sw_stop_condition(I2C_SW_Driver *i2cd) {

  I2C_CLOCK_LOW(i2cd);
  I2C_DATA_LOW(i2cd);
  i2c_sw_delay(I2C_SW_DELAY);

  I2C_CLOCK_HIGH(i2cd);
  i2c_sw_delay(I2C_SW_DELAY);

  I2C_DATA_HIGH(i2cd);
  i2c_sw_delay(I2C_SW_DELAY);
}

/* Write 1 byte to I2C bus */
static inline uint8_t i2c_sw_write8(I2C_SW_Driver *i2cd, uint8_t data) {
  uint8_t i, ack;

  for (i = 8U; i > 0U; i--) {
    I2C_CLOCK_LOW(i2cd);
    if ((data & 0x80U) != 0U) {
      I2C_DATA_HIGH(i2cd);
    } else {
      I2C_DATA_LOW(i2cd);
    }
    i2c_sw_delay(I2C_SW_DELAY);
    I2C_CLOCK_HIGH(i2cd);

    /* Check the clock line in case slave keeps it low (clock stretching) */
    i2c_sw_wait(i2cd, I2C_SW_CLOCK_LOW);

    data <<= 1;
  }

  I2C_CLOCK_LOW(i2cd);
  I2C_DATA_HIGH(i2cd);
  i2c_sw_delay(I2C_SW_DELAY);

  /* ACK pulse */
  I2C_CLOCK_HIGH(i2cd);

  /* Check the clock line in case slave keeps it low (clock stretching) */
  i2c_sw_wait(i2cd, I2C_SW_CLOCK_LOW);

  ack = I2C_DATA_GET(i2cd);

  if (ack != 0U) {
    i2c_sw_delay(I2C_SW_DELAY);
  }

  /* Leave clock and data lines low */
  i2c_sw_delay(I2C_SW_DELAY);
  I2C_DATA_LOW(i2cd);
  i2c_sw_delay(I2C_SW_DELAY);

  return ack;
}


/* Read 1 byte from I2C bus */
static inline uint8_t i2c_sw_read8(I2C_SW_Driver *i2cd, uint8_t *pdata, uint8_t nack) {
  uint8_t i, data;

  I2C_CLOCK_LOW(i2cd);
  i2c_sw_delay(I2C_SW_DELAY);
  I2C_DATA_HIGH(i2cd);

  data = 0U;
  for (i = 0U; i < 8U; i++) {
    I2C_CLOCK_LOW(i2cd);
    I2C_DATA_HIGH(i2cd);
    i2c_sw_delay(I2C_SW_DELAY);
    I2C_CLOCK_HIGH(i2cd);

    /* Check the clock line in case slave keeps it low (clock stretching) */
    i2c_sw_wait(i2cd, I2C_SW_CLOCK_LOW);

    i2c_sw_delay(I2C_SW_DELAY);

    data <<= 1;
    if (I2C_DATA_GET(i2cd) == 1U) {
      data |= 1U;
    }
  }

  I2C_CLOCK_LOW(i2cd);
  i2c_sw_delay(I2C_SW_DELAY);

  /* Do not generate ack on last byte (see I2C Specification) */
  if (nack == 1U) {
    /* NACK */
    I2C_DATA_HIGH(i2cd);
  } else {
    /* ACK */
    I2C_DATA_LOW(i2cd);
  }

  i2c_sw_delay(I2C_SW_DELAY);
  I2C_CLOCK_HIGH(i2cd);

  /* Check for clock stretch condition from slave */
  do {
    i2c_sw_delay(I2C_SW_DELAY);
  } while (I2C_CLOCK_GET(i2cd) == 0U);

  /* Leave clock and data lines low */
  I2C_CLOCK_LOW(i2cd);
  i2c_sw_delay(I2C_SW_DELAY);

  *pdata = data;

  return 0;
}



/**
 * @brief    I2C software driver initialization.
 *
 * @detail
 * The module will be initialized with a provided configuration structure.
 *
 * @param[in] priv      internal driver pointer
 * @param[in] config    pointer to the @p I2CSWConfig object
 *
 * @return    operation result.
 *
 * @api
 */
static i2c_result_t i2c_sw_start(void *priv, void *config) {

  I2C_SW_Driver *i2cd = priv;
  I2CSWConfig *sw_config = config;

  /* SCL */
  i2cd->scl_port = sw_config->scl_port;
  i2cd->scl_pin = sw_config->scl_pin;

  /* SDA */
  i2cd->sda_port = sw_config->sda_port;
  i2cd->sda_pin = sw_config->sda_pin;

  return I2C_NO_ERROR;
}

/**
 * @brief   Stops the I2C software driver.
 *
 * @param[in] priv      internal driver pointer
 *
 * @return    operation result.
 *
 * @api
 */
static i2c_result_t i2c_sw_stop(void *priv) {

  (void) priv;

  return I2C_NO_ERROR;
}

/**
 * @brief   I2C software write routine
 *
 * @param[in]  priv         internal driver pointer
 * @param[in]  dev_addr     device to address.
 * @param[in]  reg_addr     internal device register to address.
 * @param[in]  data         pointer to data buffer to send.
 * @param[in]  ndata_bytes  data length in bytes.
 *
 * @return    operation result.
 *
 * @api
 */
static i2c_result_t i2c_sw_write(void *priv, uint8_t dev_addr, uint16_t reg_addr, uint8_t reg_addr_size, uint8_t *data, uint32_t ndata_bytes) {

  uint32_t i;
  uint32_t err;
  I2C_SW_Driver *i2cd = priv;

  /* Send start condition */
  i2c_sw_start_condition(i2cd);

  /* Send device address */
  err = i2c_sw_write8(i2cd, dev_addr | I2C_SW_WRITE);

  if (err == 0U) {
    /* Send register address */
    if (reg_addr_size == I2C_16_BIT_REG_ADDRESS) {
        /* Send high byte of register address */
       err = i2c_sw_write8(i2cd, (uint8_t)(reg_addr >> 8));
    }
    if (err == 0U) {
       /* Send low byte of register address */
       err = i2c_sw_write8(i2cd, (uint8_t)reg_addr);
    }
  }



  for (i = 0U; (err == 0U) && (i < ndata_bytes); i++) {
    /* Send data */
    err = i2c_sw_write8(i2cd, *data++);
  }

  /* Send stop condition */
  i2c_sw_stop_condition(i2cd);

  return (err == 0U) ? I2C_NO_ERROR : I2C_ERROR_NO_ACK;
}

/**
 * @brief     I2C software read routine
 *
 * @param[in]  priv         internal private pointer
 * @param[in]  dev_addr     device to address.
 * @param[in]  reg_addr     internal device register to address.
 * @param[out] data         buffer for data receiving.
 * @param[in]  ndata_bytes  data buffer length in bytes.
 *
 * @return    operation result.
 *
 * @api
 */
static i2c_result_t i2c_sw_read(void *priv, uint8_t dev_addr, uint16_t reg_addr, uint8_t reg_addr_size, uint8_t *data, uint32_t ndata_bytes) {

  uint32_t i;
  uint32_t err;
  I2C_SW_Driver *i2cd = priv;

  /* Send start condition */
  i2c_sw_start_condition(i2cd);

  /* Send device address */
  err = i2c_sw_write8(i2cd, dev_addr | I2C_SW_WRITE);

  if (err == 0U) {
    /* Send register address */
    if (reg_addr_size == I2C_16_BIT_REG_ADDRESS) {
       /* Send high byte of register address */
       err = i2c_sw_write8(i2cd, (uint8_t)(reg_addr >> 8));
    }
    if (err == 0U) {
       /* Send low byte of register address */
       err = i2c_sw_write8(i2cd, (uint8_t)reg_addr);
    }
  }

  if (err == 0U) {
    /* Send repeated start condition */
    i2c_sw_start_condition(i2cd);
  }

  /* Send device address */
  if (err == 0U) {
    /* Send device address again with read flag */
    err = i2c_sw_write8(i2cd, dev_addr | I2C_SW_READ);
  }

  if (err == 0U) {
    i = 0U;
    do {
      i++;
      /* Read data */
      err = i2c_sw_read8(i2cd, data++, ((i == ndata_bytes) ? 1U : 0U));
    } while (i < ndata_bytes);
  }

  /* Send stop condition even in case of error */
  i2c_sw_stop_condition(i2cd);

  return (err == 0U) ? I2C_NO_ERROR : I2C_ERROR_NO_ACK;
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*******************************************************************************
* Global functions
*******************************************************************************/

/**
 * @brief   Initialize I2C software driver
 *
 * @param[in]  ops         pointer to the @p i2c_ops_t object
 * @api
 */
void i2c_sw_init(i2c_ops_t *ops) {

  uint32_t id;

  id = ops->id;

#if (I2C_SW_NUMBER_OF_DRIVERS > 0U)
  /* Do not initialize in case of wrong id */
  if (id >= I2C_SW_NUMBER_OF_DRIVERS) {
    return;
  }
#endif

  /* Initialize driver operations */
  ops->start = i2c_sw_start;
  ops->stop = i2c_sw_stop;
  ops->write = i2c_sw_write;
  ops->read = i2c_sw_read;

  /* Set driver private pointer */
  ops->priv = &i2c_sw[id];
}

#endif /* LLD_USE_I2C */
/** @} */

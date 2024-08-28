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
 * @file    i2c_hw.c
 * @brief   SPC5xx Hardware I2C low level driver header.
 *
 * @addtogroup I2C
 * @{
 */
#include <i2c_lld.h>

#if (LLD_USE_I2C == TRUE) || defined(__DOXYGEN__)

#include <i2c_lld_cfg.h>
#include <i2c_if.h>
#include <i2c_hw.h>
#include <osal.h>

/*******************************************************************************
* External objects
*******************************************************************************/

/*******************************************************************************
* Global variables
*******************************************************************************/

/*******************************************************************************
* Constants and macros
*******************************************************************************/
/* This is not required under normal I2C bus where only slave passive devises are
 * present, like sensors, but could be useful to enable it where another MCU
 * configured as I2C SLAVE is present on the bus. The I2C bus arbitration between
 * two MCU's, one in I2C MASTER and another in SLAVE mode is not garantee by the driver
 * and must be managed at application level.
 */
#define USE_REPEAT_START 0

/* Simple no-operation macro */
#define __NOP()                        asm volatile ("e_ori  0, 0, 0\t\n")

/*******************************************************************************
* Local types
*******************************************************************************/
/**
 * @brief I2C R/W operation as per I2C specification.
 */
 typedef enum {
	 I2C_HW_WRITE,
	 I2C_HW_READ
} i2c_operation_t;

/**
 * @brief I2C state machine
 */
typedef enum {
  I2C_MASTER_WRITE_DATA = 0x10,
  I2C_MASTER_SEND_REG_ADDRESS_HIGH,
  I2C_MASTER_SEND_REG_ADDRESS_LOW,
  I2C_MASTER_REPEATED_START,
  I2C_MASTER_READ_DUMMY_DATA,
  I2C_MASTER_TRANSFER_IN_PROGRESS,
  I2C_SLAVE_READY,
  I2C_SLAVE_BUSY,
  I2C_SLAVE_OVERFLOW,
  I2C_TRANSFER_COMPLETE
} i2c_state_t;

/**
 * @brief I2C address type
 */
typedef union {
  uint16_t W;
  struct {
    uint8_t H;
    uint8_t L;
  } B;
} i2c_addr_t;


/**
 * @brief   Structure representing a HW I2C driver.
 */
typedef struct I2C_HW_Driver {
  /**
   * @brief   Driver id reference.
   */
   uint8_t id;
  /**
   * @brief   Driver status.
   */
  volatile i2c_state_t      state;

  /**
   * @brief   Operation result.
   */
  i2c_result_t              result;

  /**
   * @brief   I2C mode (Master/Slave).
   */
  i2c_mode_t                mode;

  /**
   * @brief   I2C transfer mode (Interrupt/Polling).
   */
  uint32_t                  transfer_mode;

  /**
   * @brief   I2C timeout (msec).
   */
  uint32_t                  timeout;

  /**
   * @brief Pointer to the I2C registers block.
   */
  IIC_TAG                  *i2c_tagp;

  /**
   * @brief Device address for this driver instance.
   */
  uint8_t                   dev_addr;

  /**
   * @brief Device operation (read/write).
   */
  i2c_operation_t           operation;

  /**
   * @brief Number of bytes to transfer.
   */
  uint32_t                   ndata_bytes;
 
 /**
   * @brief Max number of bytes available by the slave.
   */
  uint32_t                   max_bytes;
  
  /**
   * @brief Pointer to supplied user buffer to read from or write to.
   */
  uint8_t                  *data;
  
  /**
   * @brief Slave device register address to read from or write to.
   */
  i2c_addr_t                reg_addr;
} I2C_HW_Driver;

/*******************************************************************************
* Local function prototypes
*******************************************************************************/

/**
 * @brief   I2C interrupt handlers.
 *
 * @isr
 */
#if (I2CD1_ENABLE == TRUE) && (I2CD1_TYPE == I2C_HARDWARE)
IRQ_HANDLER(SPC5_I2C0_HANDLER);
#endif	
#if (I2CD2_ENABLE == TRUE) && (I2CD2_TYPE == I2C_HARDWARE)
IRQ_HANDLER(SPC5_I2C1_HANDLER);
#endif	
#if (I2CD3_ENABLE == TRUE) && (I2CD3_TYPE == I2C_HARDWARE)
IRQ_HANDLER(SPC5_I2C2_HANDLER);
#endif	
#if (I2CD4_ENABLE == TRUE) && (I2CD4_TYPE == I2C_HARDWARE)
IRQ_HANDLER(SPC5_I2C3_HANDLER);
#endif	

/*******************************************************************************
* Local variables
*******************************************************************************/

/**
 * @brief   I2C Hardware: internal driver instances.
 *
 */
static struct I2C_HW_Driver i2c_hw[I2C_HW_NUMBER_OF_DRIVERS];

/*******************************************************************************
* Local functions
*******************************************************************************/
static void i2c_lld_wait_for_idle(I2C_HW_Driver *i2cd) {
	uint32_t timeout = 0x0, limit = 0xff;

    while (i2cd->i2c_tagp->IBSR.B.IBB == 1U) {
    	__NOP();
    	if (timeout++ > limit) {
    		break;
    	}
    }
}

static void i2c_lld_irq_master(I2C_HW_Driver *i2cd) {
	uint8_t status = i2cd->i2c_tagp->IBSR.R;
#if (USE_REPEAT_START == 1)
	uint32_t i=0;
#endif

    if (i2cd->i2c_tagp->IBCR.B.IIC_TX == 1U) {
		/* Transmit mode selected */
	  
		if ((status & 0x1) == 0x0) {
        /* Acknowledge received */
        switch(i2cd->state) {
        case I2C_MASTER_SEND_REG_ADDRESS_HIGH:
			/* Send upper byte of word address */
			i2cd->i2c_tagp->IBDR.R = i2cd->reg_addr.B.H;
			i2cd->state = I2C_MASTER_SEND_REG_ADDRESS_LOW;
			break;

        case I2C_MASTER_SEND_REG_ADDRESS_LOW:
			/* Send lower byte of word address */
			i2cd->i2c_tagp->IBDR.R = i2cd->reg_addr.B.L;

			if (i2cd->operation == I2C_HW_WRITE) {
				i2cd->state = I2C_MASTER_WRITE_DATA;
			} else {
				i2cd->state = I2C_MASTER_REPEATED_START;
			}
			break;

        case I2C_MASTER_REPEATED_START:
#if (USE_REPEAT_START == 1)
          i2cd->i2c_tagp->IBCR.B.IIC_MS = 0;
          i2cd->state = I2C_TRANSFER_COMPLETE;
          i2cd->result = I2C_NO_ERROR;
		  
		  i2c_lld_wait_for_idle(i2cd);
		            
          i2cd->i2c_tagp->IBCR.B.IIC_MS = 1;
          i2cd->i2c_tagp->IBCR.B.IIC_TX = 1;
          for(i=0;i<0xFF;i++);
#endif
          i2cd->i2c_tagp->IBCR.B.RSTA = 1;
          i2cd->i2c_tagp->IBDR.R = i2cd->dev_addr | I2C_HW_READ;
          i2cd->state = I2C_MASTER_READ_DUMMY_DATA;
          break;
		  
        case I2C_MASTER_READ_DUMMY_DATA:
			i2cd->i2c_tagp->IBCR.B.IIC_TX = 0;
			if (i2cd->ndata_bytes == 1U) {
				i2cd->i2c_tagp->IBCR.B.NOACK = 1;
			}
			/* dummy initiates next byte data receiving */
			if (i2cd->i2c_tagp->IBDR.R == 0U)  {}
			break;

        case I2C_MASTER_WRITE_DATA:
          if (i2cd->ndata_bytes != 0U) {
            /* Write next bytes */
            i2cd->i2c_tagp->IBDR.R = *i2cd->data++;
            i2cd->ndata_bytes--;
          } else {
            /* I2C transfer completed with success */
            i2cd->i2c_tagp->IBCR.B.IIC_MS = 0;
            i2cd->state = I2C_TRANSFER_COMPLETE;
            i2cd->result = I2C_NO_ERROR;
			i2c_lld_wait_for_idle(i2cd);
          }
          break;

        case I2C_TRANSFER_COMPLETE:
        case I2C_MASTER_TRANSFER_IN_PROGRESS:
        default:
          /* Nothing to do */
          break;
        }
		} else {
			/* No response from the slave. */
			i2cd->i2c_tagp->IBCR.B.IIC_MS = 0;
			i2cd->state = I2C_TRANSFER_COMPLETE;
			i2cd->result = I2C_ERROR_NO_ACK;
		}
    } else {
     /* Receive mode selected */
      if ((i2cd->ndata_bytes - 2U) == 0U) {
        /* NOACK next received byte */
        i2cd->i2c_tagp->IBCR.B.NOACK = 1;
      }

      if ((i2cd->ndata_bytes - 1U) == 0U) {
       /* Reset Control Register */
        i2cd->i2c_tagp->IBCR.B.IIC_MS = 0;
        i2cd->i2c_tagp->IBCR.B.NOACK = 0;
        i2cd->state = I2C_TRANSFER_COMPLETE;
        i2cd->result = I2C_NO_ERROR;
		i2c_lld_wait_for_idle(i2cd);
      }

      /* Store data read */
      *(i2cd->data++) = i2cd->i2c_tagp->IBDR.R;
      i2cd->ndata_bytes--;
    }
}

static void i2c_lld_irq_slave(I2C_HW_Driver *i2cd) {
	static uint8_t reg_addr = 0x0;
	static uint8_t data_off = 0x0;

	/* Slave mode selected */
    if (i2cd->i2c_tagp->IBSR.B.IBAL == 0x1) {
        i2cd->i2c_tagp->IBSR.B.IBAL = 0x1;
        if (i2cd->i2c_tagp->IBSR.B.IAAS == 0x0) {
        	return;
        }
addressed:
		/* Address matched. Received a request from the MASTER. */
		i2cd->state = I2C_SLAVE_BUSY;
		i2cd->result = I2C_NO_ERROR;
		if (i2cd->i2c_tagp->IBSR.B.SRW == 0x1) {
        	/* Slave transmit, master reading from slave */
        	i2cd->i2c_tagp->IBCR.B.IIC_TX = 0x1;
        	i2cd->i2c_tagp->IBDR.R = *(i2cd->data + data_off);
        	i2cd->ndata_bytes++;
        } else {
        	/* Slave receive, master writing to slave */
        	i2cd->i2c_tagp->IBCR.B.IIC_TX = 0x0;
        	if (i2cd->i2c_tagp->IBDR.R == 0U)  {}
        }
    	return;
	}
    /* No arbitration lost */
    if (i2cd->i2c_tagp->IBSR.B.IAAS == 0x1)
    	goto addressed;

    if ((i2cd->state == I2C_SLAVE_BUSY) && (i2cd->i2c_tagp->IBSR.B.IBB == 0x1)) {
    	/* Checking for buffer overflow */
    	if (i2cd->ndata_bytes >= i2cd->max_bytes) {
    		data_off = 0x0;
    		/* The master is trying to read much more bytes available */
    		if ((i2cd->i2c_tagp->IBCR.B.IIC_TX == 0x0) &&
    			(i2cd->ndata_bytes > i2cd->max_bytes))
    			i2cd->result = I2C_ERROR_BUFFER_OVERFLOW;
    	} else {
    		data_off = i2cd->ndata_bytes;
    	}
    	if (i2cd->i2c_tagp->IBCR.B.IIC_TX == 0x1) {
    		if (i2cd->i2c_tagp->IBSR.B.RXAK == 0) {
    			/* Acknowledge received */
    			i2cd->i2c_tagp->IBDR.R = *(i2cd->data + data_off);
    			i2cd->ndata_bytes++;
    		} else {
    			/* No acknowledge received. */
    			i2cd->i2c_tagp->IBCR.B.IIC_TX = 0x0;
    			/* dummy initiates next byte data */
    			if (i2cd->i2c_tagp->IBDR.R == 0U)  {}
    		}
    		return;
    	}
    	/* Store data. Don't care the register address.
    	 * This concept will be supported later. */
    	if (reg_addr == 0x0) {
    		reg_addr = i2cd->i2c_tagp->IBDR.R;
    		reg_addr = 0x1;
    	} else {
    		*(i2cd->data + data_off) = i2cd->i2c_tagp->IBDR.R;
    		i2cd->ndata_bytes++;
    	}
    }
	if (i2cd->i2c_tagp->IBSR.B.IBB == 0x0) {
		reg_addr = data_off = 0x0;
		i2cd->state = I2C_TRANSFER_COMPLETE;
	}
}

/* ******************************************************************************************/

/* I2C HW interrupt handler */
static void i2c_lld_irq_handler(I2C_HW_Driver *i2cd) {

  if (i2cd->i2c_tagp->IBCR.B.IIC_MS == 1U) {
	  /* Master mode selected */
	  i2c_lld_irq_master(i2cd);
  } else {
	  /* Slave mode selected */
	  i2c_lld_irq_slave(i2cd);
  }

  /* Clear Bus Interrupt flags */
  i2cd->i2c_tagp->IBSR.R = 0x12;
}

/* Waits for data transfer completion */
static void wait_for_transfer_completion(I2C_HW_Driver *i2cd) {
  uint32_t start_timeout, timeout;

  start_timeout = osalThreadGetMilliseconds();

  do {
	  if (i2cd->mode == I2C_MASTER) {
		  // Master in polling mode
		  /* No interrupt driven is used */
		  if (i2cd->i2c_tagp->IBCR.B.IBIE == 0U)  {
			  /* Waiting for I-bus Interrupt Flag is set */
			  do {
				  timeout = osalThreadGetMilliseconds() - start_timeout;
				  if (timeout > i2cd->timeout) {
					  break;
				  }
			  } while (i2cd->i2c_tagp->IBSR.B.IBIF == 0U);

			  if (i2cd->i2c_tagp->IBSR.B.IBIF == 1U) {
				  i2c_lld_irq_handler(i2cd);
			  }
		  }

		  // Master in interrupt mode checks for timeout transfer
		  timeout = osalThreadGetMilliseconds() - start_timeout;

		  if (timeout > i2cd->timeout) {
			  	  	  	  	  	  i2cd->result = I2C_ERROR_TIMEOUT;
			  break;
		  }
	  }
  } while (i2cd->state != I2C_TRANSFER_COMPLETE);
}


/**
 * @brief    I2C hardware driver initialization.
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
static i2c_result_t i2c_hw_start(void *priv, void *config) {

  I2C_HW_Driver *i2cd = priv;
  I2CHWConfig *hw_config = config;

  if (hw_config->ibc > 191U) {
    return I2C_ERROR_INVALID_ARGUMENT;
  }

  /* Set I2C mode (Master/Slave) */
  i2cd->mode = hw_config->mode;
  /* Set I2C transfer mode (Interrupt/Polling) */
  i2cd->transfer_mode = hw_config->transfer_mode;
  /* Set I2C timeout (msec) */
  i2cd->timeout = hw_config->timeout;
  
  /* Enable I2C peripheral clock */
#if (I2CD1_ENABLE == TRUE) && (I2CD1_TYPE == I2C_HARDWARE)
	SPCSetPeripheralClockMode(SPC5_I2C0_PCTL, SPC5_ME_PCTL_RUN(1) | SPC5_ME_PCTL_LP(2));
#endif
#if (I2CD2_ENABLE == TRUE) && (I2CD2_TYPE == I2C_HARDWARE)
	SPCSetPeripheralClockMode(SPC5_I2C1_PCTL, SPC5_ME_PCTL_RUN(1) | SPC5_ME_PCTL_LP(2));
#endif
#if (I2CD3_ENABLE == TRUE) && (I2CD3_TYPE == I2C_HARDWARE)
	SPCSetPeripheralClockMode(SPC5_I2C2_PCTL, SPC5_ME_PCTL_RUN(1) | SPC5_ME_PCTL_LP(2));
#endif
#if (I2CD4_ENABLE == TRUE) && (I2CD4_TYPE == I2C_HARDWARE)
	SPCSetPeripheralClockMode(SPC5_I2C3_PCTL, SPC5_ME_PCTL_RUN(1) | SPC5_ME_PCTL_LP(2));
#endif

	if (i2cd->mode == I2C_MASTER) {
		i2cd->i2c_tagp->IBSR.R = 0x12;
		i2cd->i2c_tagp->IBCR.B.IBIE = (uint8_t)i2cd->transfer_mode;
		i2cd->i2c_tagp->IBIC.R = 0x00;
		i2cd->i2c_tagp->IBCR.B.MDIS = 0x0;
		i2cd->i2c_tagp->IBAD.R = 0x00;
		i2cd->i2c_tagp->IBFD.B.IBC = hw_config->ibc;
	} else {
		i2cd->i2c_tagp->IBAD.R = (hw_config->slave_addr );
		i2cd->i2c_tagp->IBFD.B.IBC = 0x0;
		i2cd->i2c_tagp->IBCR.B.MDIS = 0x0;
		i2cd->i2c_tagp->IBCR.B.IIC_MS = 0x0;
		i2cd->i2c_tagp->IBSR.R = 0x12;
		i2cd->i2c_tagp->IBCR.B.IBIE = (uint8_t)i2cd->transfer_mode;
		i2cd->i2c_tagp->IBIC.R = 0x80;
	}
	i2cd->state = I2C_TRANSFER_COMPLETE;

  return I2C_NO_ERROR;
}

/**
 * @brief   Stops the I2C hardware driver.
 *
 * @param[in] priv      internal driver pointer
 *
 * @return    operation result.
 *
 * @api
 */
static i2c_result_t i2c_hw_stop(void *priv) {

  I2C_HW_Driver *i2cd = priv;

  /* Clear IBAL, IBIF flags and module disable */
  i2cd->i2c_tagp->IBSR.R = 0x12;
  i2cd->i2c_tagp->IBIC.R = 0x00;
  i2cd->i2c_tagp->IBCR.B.MDIS = 0x1;

  /* Disable I2C peripheral clock */
#if (I2CD1_ENABLE == TRUE) && (I2CD1_TYPE == I2C_HARDWARE)
	SPCSetPeripheralClockMode(SPC5_I2C0_PCTL, SPC5_ME_PCTL_RUN(0) | SPC5_ME_PCTL_LP(0));
#endif
#if (I2CD2_ENABLE == TRUE) && (I2CD2_TYPE == I2C_HARDWARE)
	SPCSetPeripheralClockMode(SPC5_I2C1_PCTL, SPC5_ME_PCTL_RUN(0) | SPC5_ME_PCTL_LP(0));
#endif
#if (I2CD3_ENABLE == TRUE) && (I2CD3_TYPE == I2C_HARDWARE)
	SPCSetPeripheralClockMode(SPC5_I2C2_PCTL, SPC5_ME_PCTL_RUN(0) | SPC5_ME_PCTL_LP(0));
#endif
#if (I2CD4_ENABLE == TRUE) && (I2CD4_TYPE == I2C_HARDWARE)
	SPCSetPeripheralClockMode(SPC5_I2C3_PCTL, SPC5_ME_PCTL_RUN(0) | SPC5_ME_PCTL_LP(0));
#endif

  return I2C_NO_ERROR;
}

/**
 * @brief   I2C hardware write routine
 *
 * @param[in]  priv         internal driver pointer
 * @param[in]  dev_addr     device to address.
 * @param[in]  reg_addr     internal device register to address.
 * @param[in]  data         pointer to data buffer to send.
 * @param[in]  ndata_bytes  data length in bytes.
 *
 * @return    operation result or bytes read if no error happened.
 *
 * @api
 */
static i2c_result_t i2c_hw_write(void *priv, uint8_t dev_addr, uint16_t reg_addr, uint8_t reg_addr_size, uint8_t *data, uint32_t ndata_bytes) {

	I2C_HW_Driver *i2cd = priv;

	if (i2cd->i2c_tagp->IBSR.B.IBB == 1U) {
		i2cd->result = I2C_ERROR_BUS_BUSY;
		return I2C_ERROR_BUS_BUSY;
	}
	
	/* Set i2c context */
	i2cd->data = data;
	i2cd->operation = I2C_HW_WRITE;
	i2cd->result = I2C_ERROR_TRANSFER_IN_PROGRESS;

	if (i2cd->mode == I2C_MASTER) {
		i2cd->ndata_bytes = ndata_bytes;
		i2cd->dev_addr = dev_addr | I2C_HW_WRITE;
		i2cd->reg_addr.W = reg_addr;

		if (reg_addr_size == I2C_16_BIT_REG_ADDRESS) {
			i2cd->state = I2C_MASTER_SEND_REG_ADDRESS_HIGH;
		} else {
			i2cd->state = I2C_MASTER_SEND_REG_ADDRESS_LOW;
		}
	}

	i2cd->i2c_tagp->IBCR.B.IIC_MS = (uint8_t)i2cd->mode;
	if (i2cd->mode == I2C_SLAVE) {
		/* Slave Transmit when slave device address matchs */
		i2cd->i2c_tagp->IBAD.R = dev_addr;
		i2cd->timeout = 0x0;
		i2cd->ndata_bytes = 0x0;
		i2cd->max_bytes = ndata_bytes;
		i2cd->state = I2C_SLAVE_READY;
	} else {
		/* Master Transmit the device address */
		i2cd->i2c_tagp->IBCR.B.IIC_TX = 1;
		i2cd->i2c_tagp->IBDR.R = i2cd->dev_addr;
	}
		
	/* Wait for transfer completion. With timeout in MASTER mode. */
	wait_for_transfer_completion(i2cd);

	if ((i2cd->result == I2C_NO_ERROR) &&
	    (i2cd->ndata_bytes != 0x0))
		return i2cd->ndata_bytes;

	return(i2cd->result);
}

/**
 * @brief     I2C hardware read routine
 *
 * @param[in]  priv         internal private pointer
 * @param[in]  dev_addr     device to address.
 * @param[in]  reg_addr     internal device register to address.
 * @param[out] data         buffer for data receiving.
 * @param[in]  ndata_bytes  data buffer length in bytes.
 *
 * @return    operation result or bytes read if no error happened.
 *
 * @api
 */
static int i2c_hw_read(void *priv, uint8_t dev_addr, uint16_t reg_addr, uint8_t reg_addr_size, uint8_t *data, uint32_t ndata_bytes) {

	I2C_HW_Driver *i2cd = priv;

	if (i2cd->i2c_tagp->IBSR.B.IBB == 1U) {
		i2cd->result = I2C_ERROR_BUS_BUSY;
		return i2cd->result;
	}

	/* Set i2c context */
	i2cd->data = data;
	if (i2cd->mode == I2C_MASTER) {
		i2cd->dev_addr = dev_addr | I2C_HW_WRITE;
		i2cd->reg_addr.W = reg_addr;
		/* Master wants to read exactly ndata_bytes from slave device  */
		i2cd->ndata_bytes = ndata_bytes;

		if (reg_addr_size == I2C_16_BIT_REG_ADDRESS) {
			i2cd->state = I2C_MASTER_SEND_REG_ADDRESS_HIGH;
		} else {
			i2cd->state = I2C_MASTER_SEND_REG_ADDRESS_LOW;
		}

		/* Transmit the device address using a specific sequence
		 * of steps to generate START signal and address sent */
#if (USE_REPEAT_START == 1)
		i2cd->i2c_tagp->IBCR.B.RSTA = 0x1;
		i2cd->i2c_tagp->IBCR.B.IIC_MS = (uint8_t)i2cd->mode;
		i2cd->i2c_tagp->IBCR.B.IIC_TX = 0x1;
		i2cd->i2c_tagp->IBDR.R = i2cd->dev_addr| I2C_HW_READ;
		i2cd->state = I2C_MASTER_READ_DUMMY_DATA;
#else
		i2cd->i2c_tagp->IBCR.B.IIC_MS = (uint8_t)i2cd->mode;
		i2cd->i2c_tagp->IBCR.B.IIC_TX = 0x1;
		i2cd->i2c_tagp->IBDR.R = i2cd->dev_addr;
#endif
	} else {
		/* In slave mode it reads until no data on the I2C bus */
		i2cd->i2c_tagp->IBAD.R = dev_addr;
		i2cd->ndata_bytes = 0x0;
		i2cd->max_bytes = ndata_bytes;
		i2cd->timeout = 0x0;
		i2cd->state = I2C_SLAVE_READY;
	}

	i2cd->operation = I2C_HW_READ;
	i2cd->result = I2C_ERROR_TRANSFER_IN_PROGRESS;

	/* Wait for transfer completion. With timeout in MASTER mode. */
	wait_for_transfer_completion(i2cd);

	if ((i2cd->result == I2C_NO_ERROR) &&
	    (i2cd->ndata_bytes != 0x0))
		return i2cd->ndata_bytes;

	return (i2cd->result);
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/**
 * @brief   I2C interrupt handler.
 *
 * @isr
 */
#if (I2CD1_ENABLE == TRUE) && (I2CD1_TYPE == I2C_HARDWARE)
IRQ_HANDLER(SPC5_I2C0_HANDLER) {
  IRQ_PROLOGUE();

  i2c_lld_irq_handler(&i2c_hw[0U]);

  IRQ_EPILOGUE();
}
#endif
#if (I2CD2_ENABLE == TRUE) && (I2CD2_TYPE == I2C_HARDWARE)
IRQ_HANDLER(SPC5_I2C1_HANDLER) {
  IRQ_PROLOGUE();

  i2c_lld_irq_handler(&i2c_hw[1U]);

  IRQ_EPILOGUE();
}
#endif
#if (I2CD3_ENABLE == TRUE) && (I2CD3_TYPE == I2C_HARDWARE)
IRQ_HANDLER(SPC5_I2C2_HANDLER) {
  IRQ_PROLOGUE();

  i2c_lld_irq_handler(&i2c_hw[2U]);

  IRQ_EPILOGUE();
}
#endif
#if (I2CD4_ENABLE == TRUE) && (I2CD4_TYPE == I2C_HARDWARE)
IRQ_HANDLER(SPC5_I2C3_HANDLER) {
  IRQ_PROLOGUE();

  i2c_lld_irq_handler(&i2c_hw[3U]);

  IRQ_EPILOGUE();
}
#endif


/*******************************************************************************
* Global functions
*******************************************************************************/
/**
 * @brief   Initialize I2C hardware driver
 *
 * @param[in]  ops         pointer to the @p i2c_ops_t object
 * @api
 */
void i2c_hw_init(i2c_ops_t *ops) {

  uint32_t id;

  id = ops->id;

  /* do not initialize in case of wrong input data */
  if (id >= I2C_HW_NUMBER_OF_DRIVERS) {
    return;
  }

  /* enable interrupts */
#if (I2CD1_ENABLE == TRUE) && (I2CD1_TYPE == I2C_HARDWARE)
  if (id == 0U) {
	INTC_PSR(SPC5_I2C0_INT_NUMBER) = SPC5_I2C_IRQ_PRIORITY;
	i2c_hw[id].id = id;
	i2c_hw[id].i2c_tagp = &IIC_0;
	i2c_hw[id].result = I2C_NO_ERROR;
  }
#endif
#if (I2CD2_ENABLE == TRUE) && (I2CD2_TYPE == I2C_HARDWARE)
  if (id == 1U) {
	INTC_PSR(SPC5_I2C1_INT_NUMBER) = SPC5_I2C_IRQ_PRIORITY;
	i2c_hw[id].id = id;
	i2c_hw[id].i2c_tagp = &IIC_1;
	i2c_hw[id].result = I2C_NO_ERROR;
  }
#endif
#if (I2CD3_ENABLE == TRUE) && (I2CD3_TYPE == I2C_HARDWARE)
  if (id == 2U) {
	INTC_PSR(SPC5_I2C2_INT_NUMBER) = SPC5_I2C_IRQ_PRIORITY;
	i2c_hw[id].id = id;
	i2c_hw[id].i2c_tagp = &IIC_2;
	i2c_hw[id].result = I2C_NO_ERROR;
  }
#endif
#if (I2CD4_ENABLE == TRUE) && (I2CD4_TYPE == I2C_HARDWARE)
  if (id == 3U) {
	INTC_PSR(SPC5_I2C3_INT_NUMBER) = SPC5_I2C_IRQ_PRIORITY;
	i2c_hw[id].id = id;
	i2c_hw[id].i2c_tagp = &IIC_3;
	i2c_hw[id].result = I2C_NO_ERROR;
  }
#endif

  /* Initialize driver operations */
  ops->start = i2c_hw_start;
  ops->stop = i2c_hw_stop;
  ops->write = i2c_hw_write;
  ops->read = i2c_hw_read;

  /* Set driver private pointer */
  ops->priv = &i2c_hw[id];
}

#endif /* LLD_USE_I2C */
/** @} */

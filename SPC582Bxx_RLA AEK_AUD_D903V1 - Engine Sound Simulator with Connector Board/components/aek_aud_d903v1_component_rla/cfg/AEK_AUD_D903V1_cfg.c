/****************************************************************************
*
* Copyright � 2020 STMicroelectronics - All Rights Reserved
*
* License terms: STMicroelectronics Proprietary in accordance with licensing
* terms SLA0098 at www.st.com.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* EVALUATION ONLY - NOT FOR USE IN PRODUCTION
*****************************************************************************/


/**
 * @file    AEK_AUD_D903V1_cfg.c
 * @brief   AEK_AUD_D903V1 Driver configuration macros and structures.
 *
 * @addtogroup AEK_AUD_D903V1
 * @{
 */

#ifndef _AEK_AUD_D903V1_CFG_C_
#define _AEK_AUD_D903V1_CFG_C_


#include "spc5_lld.h"
#include "lldconf.h"
#include "i2s_lld.h"
#include "i2c_lld.h"
#include <i2s_lld_cfg.h>
#include <i2c_lld_cfg.h>
#include <AEK_AUD_D903V1_cfg.h>




/* Ready for new buffer */
volatile uint32_t load_new_sample = 0U;

/* Buffer ping-pong flag */
volatile uint8_t which_buffer = 1U;




I2SDriver* AEK_AUD_D903V1_I2S_DRIVER[1] = {
&I2SD1
};

I2SConfig* AEK_AUD_D903V1_I2S_CONFIGURATION[1] = {&i2s_config_AEK_AUD_D903V1Board0_J10_WS_LABEL_I2SCR_I2SSDA1_SCL};


I2CDriver* AEK_AUD_D903V1_I2C_ARRAY_DRIVER[1]={
&I2CD1
};

void* AEK_AUD_D903V1_I2C_ARRAY_CONFIGURATION[1]={
&i2c_hw_config_AEK_AUD_D903V1Board0
};	



uint8_t Enables_ARRAY[1][8]={{	
							2,
							13U,
							2,
							12U,
							12,
							14U,
							2,
							4U}

};


const uint8_t I2CAddress[1] = {
#ifdef HW_FIXED_AMP_I2C_ADDR //KMS240826_1 : I2C sub address for Amp
	0xE0
#else
	0xE4
#endif
};


void HalfTransmitCallback(I2SDriver *i2sp) {
  (void) i2sp;
  if (load_new_sample == 0)
  {
	  which_buffer = 1U - which_buffer;
	  load_new_sample = 1;
	}
}

/* End transmit callback */
void EndTransmitCallback(I2SDriver *i2sp) {
  (void) i2sp;
  if (load_new_sample == 0)
    {
  	  which_buffer = 1U - which_buffer;
  	  load_new_sample = 1;
  	}
}

#endif /* _AEK_AUD_D903V1_CFG_C_ */

/** @} */

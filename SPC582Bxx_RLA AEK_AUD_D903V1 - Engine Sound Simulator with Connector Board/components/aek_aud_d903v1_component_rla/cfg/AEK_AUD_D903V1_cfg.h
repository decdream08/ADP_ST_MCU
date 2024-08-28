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
 * @file    AEK_AUD_D903V1_cfg.h
 * @brief   AEK_AUD_D903V1 Driver configuration macros and structures.
 *
 * @addtogroup AEK_AUD_D903V1
 * @{
 */

#ifndef _AEK_AUD_D903V1_CFG_H_
#define _AEK_AUD_D903V1_CFG_H_

#include "spc5_lld.h"
#include "lldconf.h"
#include "i2s_lld.h"
#include "i2c_lld.h"
#include <i2s_lld_cfg.h>
#include <i2c_lld_cfg.h>

#define HW_FIXED_AMP_I2C_ADDR		TRUE //KMS240826_1 : ESTec uses HW fixed I2C sub address for Amp(0100 = 0xE0)

#define Allocation_Executed  

		


#define AUD_LIST_ELEMENT 1



extern  I2CDriver* AEK_AUD_D903V1_I2C_ARRAY_DRIVER[1];
extern  void* AEK_AUD_D903V1_I2C_ARRAY_CONFIGURATION[1];
extern const uint8_t I2CAddress[1];
extern  I2SDriver* AEK_AUD_D903V1_I2S_DRIVER[1];
extern  I2SConfig* AEK_AUD_D903V1_I2S_CONFIGURATION[1];
extern volatile uint8_t which_buffer;
extern volatile uint32_t load_new_sample;
extern uint8_t Enables_ARRAY[1][8];

void EndTransmitCallback(I2SDriver *i2sp);
void HalfTransmitCallback(I2SDriver *i2sp);

typedef enum 
{
		AEK_AUD_D903V1_DEV0=0
}AEK_AUD_D903V1_DEVICE;


#endif /* _AEK_AUD_D903V1_CFG_H_ */

/** @} */



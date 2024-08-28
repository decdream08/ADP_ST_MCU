/****************************************************************************
*
* Copyright ï¿?2020 STMicroelectronics - All Rights Reserved
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
 * @file    AEK_AUD_D903V1.c
 * @brief   SPC5xx AEK_AUD_D903V1 driver code.
 *
 * @addtogroup AEK_AUD_D903V1
 * @{
 */
#include "AEK_AUD_D903V1.h"

#ifdef Allocation_Executed

/*******************************************************************************
 ********************************** Variables **********************************
 *******************************************************************************/
FDA_Errors_t FDA903_Errors[AUD_LIST_ELEMENT];
uint8_t FDA903D_Status_DB[AUD_LIST_ELEMENT][FDA903D_DB_ADDR_MAX - FDA903D_DB_ADDR_MIN + 1];  //  from DBO to DB6  --> size  7
uint8_t FDA903D_Status_IB[AUD_LIST_ELEMENT][FDA903D_IB_ADDR_MAX - FDA903D_IB_ADDR_MIN + 1];  //  from IB0 to IB14 --> size 15
uint8_t txbuf[1008] __attribute__ ((aligned (256)));
uint8_t rxbuf[1008] __attribute__ ((aligned (256)));
FDA_State_t  FDA_Status[AUD_LIST_ELEMENT];
CurrentSensingElement FDA903_CurrentSensingBuff[1];
I2CDriver* _I2CDriver_started;
uint8_t NO_READ_DB_AND_IB_REG_DURING_PLAY =0;
uint8_t current_sensing_full_scale;
uint16_t saturation_code;
/*******************************************************************************
 ********************************** Functions **********************************
 *******************************************************************************/

/**
 *  @brief		Writes IB register(s)
 *
 *  @param[in]	AEK_AUD_D903V1_DEVICE dev
 *
 *  @param[in]	uint8_t reg_addr - 7bit address of IB register
 *
 *  @param[in]	uint8_t *data - pointer to the data where written data will be stored
 *
 *  @param[in]	uint8_t size - number of bytes to write
 *
 *  @return   	i2c_result_t
 *
 *  @api
 */
i2c_result_t AEK_903D_Write_IB(AEK_AUD_D903V1_DEVICE dev, uint8_t reg_addr, uint8_t * data, uint8_t size)
{
	// Check address range
    if (reg_addr > FDA903D_IB_ADDR_MAX)
    {
        return I2C_ERROR_INVALID_ADDRESS;
    }
    if (size > 1)
    {
        reg_addr |= 0x80;       // Continues Write
    }
    return i2c_lld_write(AEK_AUD_D903V1_I2C_ARRAY_DRIVER[dev],(uint8_t)I2CAddress[dev], reg_addr, data, size);
}

/**
 *  @brief   	Reads IB register(s)
 *
 *  @param[in]	AEK_AUD_D903V1_DEVICE dev
 *
 *  @param[in]	uint8_t reg_addr - 7bit address of IB register
 *
 *  @param[in]  uint8_t *data - pointer to the data where read data will be stored
 *
 *  @param[in]  uint8_t size - number of bytes to read
 *
 *  @return   	i2c_result_t
 *
 *  @api
 */
i2c_result_t AEK_903D_Read_IB(AEK_AUD_D903V1_DEVICE dev, uint8_t reg_addr, uint8_t * data, uint8_t size)
{
    // Check address range
    if (reg_addr > FDA903D_IB_ADDR_MAX)
    {
        return I2C_ERROR_INVALID_ADDRESS;
    }

    if (size > 1)
    {
        reg_addr |= 0x80;       // Continues Read
    }
    return i2c_lld_read (AEK_AUD_D903V1_I2C_ARRAY_DRIVER[dev],(uint8_t)I2CAddress[dev], reg_addr, data, size);
}

/**
 * @brief   	Reads all IB registers and store them in uint8_t FDA903D_Status_IB[];
 *
 * @param[in]	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_Read_All_IB(AEK_AUD_D903V1_DEVICE dev)
{
    return  AEK_903D_Read_IB(dev,FDA903D_IB_ADDR_MIN, FDA903D_Status_IB[dev], (FDA903D_IB_ADDR_MAX - FDA903D_IB_ADDR_MIN + 1));
}

/**
 *  @brief		Reads DB register(s)
 *
 *  @param[in] 	uint8_t reg_addr - 7bit address of DB register
 *
 *  @param[in] 	uint8_t *data - pointer to the data where read data will be stored
 *
 *  @param[in]	uint8_t size - number of bytes to read
 *
 *  @return		i2c_result_t
 *
 *  @api
 */
i2c_result_t AEK_903D_Read_DB(AEK_AUD_D903V1_DEVICE dev, uint8_t reg_addr, uint8_t * data, uint8_t size)
{
	// Check address range
    if ((reg_addr < FDA903D_DB_ADDR_MIN) || (reg_addr > FDA903D_DB_ADDR_MAX))
    {
        return I2C_ERROR_INVALID_ADDRESS;
    }
    if (size > 1)
    {
        reg_addr |= 0x80;       // Continues Read
    }
    return i2c_lld_read (AEK_AUD_D903V1_I2C_ARRAY_DRIVER[dev],(uint8_t)I2CAddress[dev], reg_addr, data, size);
}

/**
 * @brief		Reads all DB registers and store them in uint8_t FDA903D_Status_DB[];
 *
 * @param[in]	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_Read_All_DB( AEK_AUD_D903V1_DEVICE dev )
{
    return  AEK_903D_Read_DB(dev, FDA903D_DB_ADDR_MIN, FDA903D_Status_DB[dev], (FDA903D_DB_ADDR_MAX - FDA903D_DB_ADDR_MIN + 1));
}

/**
 * @brief   	Initialize I2C registers in AEK-AUD-D903V1 and set first bit of IB14 to 1 - ready to work.
 *
 * @param[in]	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetDefaultRegisters(AEK_AUD_D903V1_DEVICE dev)
{
    uint8_t data[15];
    // Init: Turn IB registers into application default setting
	data[0]  = IB0_DEFAULT; 		// data[0] = 0x00;
    data[1]  = IB1_DEFAULT;			// data[1] = 0x00;
    data[2]  = IB2_DEFAULT;  		// data[2] = 0x00;
    data[3]  = IB3_DEFAULT;  		// data[3] = 0x38;
    data[4]  = IB4_DEFAULT;  		// data[4] = 0x00;
    data[5]  = IB5_DEFAULT;  		// data[5] = 0x00;
    data[6]  = IB6_DEFAULT;  		// data[6] = 0x00;
    data[7]  = IB7_DEFAULT;  		// data[7] = 0x00;
    data[8]  = IB8_DEFAULT;  		// data[8] = 0xC0;
    data[9]  = IB9_DEFAULT;  		// data[9] = 0x00;
    data[10] = IB10_DEFAULT;  		// data[10] = 0x50;
    data[11] = IB11_DEFAULT;  		// data[11] = 0x30;
    data[12] = IB12_DEFAULT;  		// data[12] = 0x00;
    data[13] = IB13_DEFAULT;  		// data[13] = 0x20;
    data[14] = IB14_DEFAULT;  		// data[14] = 0x09;
    return AEK_903D_Write_IB(dev, IB0, &data[0], 15);  // IB14[0] = 1; FIRST bit
}

/**
 * @brief   	Set the Enable pins of the board as defined in the configuration.
 *
 * @param[in]	AEK_AUD_D903V1_DEVICE dev
 *
 * @api
 */
void AEK_903D_SetEnables(AEK_AUD_D903V1_DEVICE dev)
{
	switch(I2CAddress[dev])
	{
			case 0xE0:
#ifdef HW_FIXED_AMP_I2C_ADDR
				pal_lld_setpad(PORT_PIN_AMP_EN2_GPIO35, PIN_AMP_EN2_GPIO35);
#else //HW_FIXED_AMP_I2C_ADDR
				pal_lld_clearpad(Enables_ARRAY[dev][0], Enables_ARRAY[dev][1]);         //Enable 1 = 0
				pal_lld_setpad(Enables_ARRAY[dev][2], Enables_ARRAY[dev][3]);         	//Enable 2 = 1
				pal_lld_clearpad(Enables_ARRAY[dev][4], Enables_ARRAY[dev][5]);        	//Enable 3 = 0
				pal_lld_clearpad(Enables_ARRAY[dev][6], Enables_ARRAY[dev][7]);         //Enable 4 = 0
#endif //HW_FIXED_AMP_I2C_ADDR
				break;
			case 0xE2:
				pal_lld_setpad(Enables_ARRAY[dev][0], Enables_ARRAY[dev][1]);           //Enable 1 = 1
				pal_lld_setpad(Enables_ARRAY[dev][2], Enables_ARRAY[dev][3]);        	//Enable 2 = 1
				pal_lld_clearpad(Enables_ARRAY[dev][4], Enables_ARRAY[dev][5]);        	//Enable 3 = 0
				pal_lld_clearpad(Enables_ARRAY[dev][6], Enables_ARRAY[dev][7]);         //Enable 4 = 0
				break;
			case 0xE4:
				pal_lld_clearpad(Enables_ARRAY[dev][0], Enables_ARRAY[dev][1]);         //Enable 1 = 0
				pal_lld_clearpad(Enables_ARRAY[dev][2], Enables_ARRAY[dev][3]);         //Enable 2 = 0
				pal_lld_setpad(Enables_ARRAY[dev][4], Enables_ARRAY[dev][5]);        	//Enable 3 = 1
				pal_lld_clearpad(Enables_ARRAY[dev][6], Enables_ARRAY[dev][7]);         //Enable 4 = 0
				break;
			case 0xE6:
				pal_lld_clearpad(Enables_ARRAY[dev][0], Enables_ARRAY[dev][1]);         //Enable 1 = 0
				pal_lld_setpad(Enables_ARRAY[dev][2], Enables_ARRAY[dev][3]);         	//Enable 2 = 1
				pal_lld_setpad(Enables_ARRAY[dev][4], Enables_ARRAY[dev][5]);        	//Enable 3 = 1
				pal_lld_clearpad(Enables_ARRAY[dev][6], Enables_ARRAY[dev][7]);         //Enable 4 = 0
				break;
			case 0xE8:
				pal_lld_clearpad(Enables_ARRAY[dev][0], Enables_ARRAY[dev][1]);         //Enable 1 = 0
				pal_lld_setpad(Enables_ARRAY[dev][2], Enables_ARRAY[dev][3]);         	//Enable 2 = 1
				pal_lld_clearpad(Enables_ARRAY[dev][4], Enables_ARRAY[dev][5]);        	//Enable 3 = 0
				pal_lld_setpad(Enables_ARRAY[dev][6], Enables_ARRAY[dev][7]);           //Enable 4 = 1
				break;
			case 0xEA:
				pal_lld_setpad(Enables_ARRAY[dev][0], Enables_ARRAY[dev][1]);         	//Enable 1 = 1
				pal_lld_setpad(Enables_ARRAY[dev][2], Enables_ARRAY[dev][3]);         	//Enable 2 = 1
				pal_lld_clearpad(Enables_ARRAY[dev][4], Enables_ARRAY[dev][5]);        	//Enable 3 = 0
				pal_lld_setpad(Enables_ARRAY[dev][6], Enables_ARRAY[dev][7]);         	//Enable 4 = 1
				break;
			case 0xEC:
				pal_lld_clearpad(Enables_ARRAY[dev][0], Enables_ARRAY[dev][1]);         //Enable 1 = 0
				pal_lld_clearpad(Enables_ARRAY[dev][2], Enables_ARRAY[dev][3]);         //Enable 2 = 0
				pal_lld_setpad(Enables_ARRAY[dev][4], Enables_ARRAY[dev][5]);        	//Enable 3 = 1
				pal_lld_setpad(Enables_ARRAY[dev][6], Enables_ARRAY[dev][7]);           //Enable 4 = 1
				break;
			case 0xEE:
				pal_lld_clearpad(Enables_ARRAY[dev][0], Enables_ARRAY[dev][1]);         //Enable 1 = 0
				pal_lld_setpad(Enables_ARRAY[dev][2], Enables_ARRAY[dev][3]);         	//Enable 2 = 1
				pal_lld_setpad(Enables_ARRAY[dev][4], Enables_ARRAY[dev][5]);        	//Enable 3 = 1
				pal_lld_setpad(Enables_ARRAY[dev][6], Enables_ARRAY[dev][7]);           //Enable 4 = 1
				break;
			default:
				break;

	}
}

/**
 * @brief   	Initialize I2C peripheral
 *
 * @param[in]	AEK_AUD_D903V1_DEVICE dev
 *
 * @api
 */
i2c_result_t AEK_903D_I2C_Init(AEK_AUD_D903V1_DEVICE dev)
{
	/* Initialize I2C */
	return i2c_lld_start(AEK_AUD_D903V1_I2C_ARRAY_DRIVER[dev], AEK_AUD_D903V1_I2C_ARRAY_CONFIGURATION[dev]);
}

/**
 * @brief   	Initialize I2S peripheral
 *
 * @param[in]	AEK_AUD_D903V1_DEVICE dev
 *
 * @api
 */
void AEK_903D_I2S_Init(AEK_AUD_D903V1_DEVICE dev)
{
	memset(txbuf, 0, sizeof(txbuf));
	/* Initialize i2s */
	i2s_lld_start(AEK_AUD_D903V1_I2S_DRIVER[dev], AEK_AUD_D903V1_I2S_CONFIGURATION[dev]);
    /* Go in play-back */
	i2s_lld_playbackEx(AEK_AUD_D903V1_I2S_DRIVER[dev], sizeof(txbuf), txbuf, SPC5_I2S_LOOP_FOREVER, rxbuf);
}

/**
 * @brief   	Initialize GPIOs, I2C peripheral and configure AEK-AUD-D903V1 (FIRST bit, IB14)
 *
 * @param[in]	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_Init(AEK_AUD_D903V1_DEVICE dev)
{
	i2c_result_t ret = I2C_NO_ERROR;

	//EN1 ~ 4 are all clear here.
#ifdef HW_FIXED_AMP_I2C_ADDR //KMS240826_1 : Clear I2C sub address pin for Amp
	pal_lld_clearpad(PORT_PIN_AMP_EN2_GPIO35, PIN_AMP_EN2_GPIO35);
	//pal_lld_clearpad(Enables_ARRAY[dev][0], Enables_ARRAY[dev][1]); 	   
		//pal_lld_clearpad(Enables_ARRAY[dev][2], Enables_ARRAY[dev][3]); 			
		//pal_lld_clearpad(Enables_ARRAY[dev][4], Enables_ARRAY[dev][5]); 		
//		pal_lld_clearpad(Enables_ARRAY[dev][6], Enables_ARRAY[dev][7]);

	//(PORT_PIN_AEK_AUD_D903V1Board0_J10_EN2_EN2_GPIO35, PIN_AEK_AUD_D903V1Board0_J10_EN2_EN2_GPIO35)
#else //HW_FIXED_AMP_I2C_ADDR
	pal_lld_clearpad(Enables_ARRAY[dev][0], Enables_ARRAY[dev][1]);        
	pal_lld_clearpad(Enables_ARRAY[dev][2], Enables_ARRAY[dev][3]);         	
	pal_lld_clearpad(Enables_ARRAY[dev][4], Enables_ARRAY[dev][5]);        	
	pal_lld_clearpad(Enables_ARRAY[dev][6], Enables_ARRAY[dev][7]);
#endif //HW_FIXED_AMP_I2C_ADDR

	osalThreadDelayMilliseconds(500);

	/* Initialize I2C */
	//This check is to avoid that the same I2C HW driver is started two times
	if(_I2CDriver_started != AEK_AUD_D903V1_I2C_ARRAY_DRIVER[dev])
	{
		_I2CDriver_started = AEK_AUD_D903V1_I2C_ARRAY_DRIVER[dev];
		ret = i2c_lld_start(AEK_AUD_D903V1_I2C_ARRAY_DRIVER[dev], AEK_AUD_D903V1_I2C_ARRAY_CONFIGURATION[dev]);
	}

	/* KMS240826_1 : Enables combination 0100 (0xE0) */
	AEK_903D_SetEnables(dev);


	memset(txbuf, 0, sizeof(txbuf));
	memset(rxbuf, 0, sizeof(rxbuf)); //mio

	if(dev == 0)
	{
	   /* Initialize i2s */
		i2s_lld_start(AEK_AUD_D903V1_I2S_DRIVER[dev], AEK_AUD_D903V1_I2S_CONFIGURATION[dev]);
	   /* Go in play-back */
		i2s_lld_playbackEx(AEK_AUD_D903V1_I2S_DRIVER[dev], sizeof(txbuf), txbuf, SPC5_I2S_LOOP_FOREVER, rxbuf);
	}

   /* Initialize register with default value */
    ret |= AEK_903D_SetDefaultRegisters(dev);
	return ret;
}

//-------------------------------------------------------IB0---------------------------------------------------
/**
 * @brief   	This function enables the writing on IBs.
 *
 * @param[in] 	AEK_AUD_D903V1_DEVICE dev
 *
 * @return 		i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_EnableWritingOnIBs(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev] != PLAY)
	{
		AEK_903D_Read_IB(dev, IB0,&FDA903D_Status_IB[dev][0],1);
	}

	FDA903D_Status_IB[dev][0] = (FDA903D_Status_IB[dev][0] & 0x7F) | IB0_WRITE_ON_IBS_ENABLE ;
	return AEK_903D_Write_IB(dev, IB0, &FDA903D_Status_IB[dev][0],1);
}

/**
 * @brief   	This function disables the writing on IBs.
 *
 * @param[in] 	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_DisableWritingOnIBs(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB0,&FDA903D_Status_IB[dev][0],1);
	}

	FDA903D_Status_IB[dev][0] = (FDA903D_Status_IB[dev][0] & 0x7F) | IB0_WRITE_ON_IBS_DISABLE ;
	return AEK_903D_Write_IB(dev, IB0, &FDA903D_Status_IB[dev][0],1);
}

/**
 * @brief   	This function sets the digital input data formats.
 *
 *  @param[in] 	AEK_AUD_D903V1_DEVICE dev,
 *
 *	@param[in] 	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 *  	-	IB0_DIGITAL_INPUT_I2S_STANDARD
 *  	-	IB0_DIGITAL_INPUT_TDM_4_CHs
 *  	-	IB0_DIGITAL_INPUT_TDM_8_CHs
 *  	-	IB0_DIGITAL_INPUT_TDM_16_CHs
 *
 *  @return   i2c_result_t
 *
 *  @api
 */
i2c_result_t AEK_903D_SetInputDataFormats(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB0,&FDA903D_Status_IB[dev][0],1);
	}

	FDA903D_Status_IB[dev][0] = (FDA903D_Status_IB[dev][0] & 0x9F) | value ;
	return AEK_903D_Write_IB(dev, IB0, &FDA903D_Status_IB[dev][0],1);
}

/**
 * @brief   	This function selects the channel position for I2S, TDM4, TDM8 and TDM16 standards.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in] 	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 *		-	IB0_SLOT_0_TDM_MODE_OR_I2S_MODE_RIGHT_CH
 *		-	IB0_SLOT_1_TDM_MODE_OR_I2S_MODE_LEFT_CH
 *		-	IB0_SLOT_2_TDM_MODE
 *		-	IB0_SLOT_3_TDM_MODE
 *		-	IB0_SLOT_4_TDM_8_16_MODE
 *		-	IB0_SLOT_5_TDM_8_16_MODE
 *		-	IB0_SLOT_6_TDM_8_16_MODE
 *		-	IB0_SLOT_7_TDM_8_16_MODE
 *		- 	IB0_PSLOT_8_TDM_16_MODE
 *		-	IB0_SLOT_9_TDM_16_MODE
 *		-	IB0_SLOT_10_TDM_16_MODE
 *		-	IB0_SLOT_11_TDM_16_MODE
 *		-	IB0_SLOT_12_TDM_16_MODE
 *		-	IB0_SLOT_13_TDM_16_ONLY
 *		-	IB0_SLOT_14_TDM_16_ONLY
 *		-	IB0_SLOT_15_TDM_16_ONLY
 *
 * @return   i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SelectChannelPosition(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB0,&FDA903D_Status_IB[dev][0],1);
	}

	FDA903D_Status_IB[dev][0] = (FDA903D_Status_IB[dev][0] & 0xE1) | value ;
	return AEK_903D_Write_IB(dev, IB0, &FDA903D_Status_IB[dev][0],1);
}

/**
 * @brief   	This function sets the voltage mode.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in] 	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 * 		-	IB0_STANDARD_VOLTAGE_MODE
 * 		-	IB0_LOW_VOLTAGE_MODE
 *
 * @return   i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetVoltageMode(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev,IB0,&FDA903D_Status_IB[dev][0],1);
	}

	FDA903D_Status_IB[dev][0] = (FDA903D_Status_IB[dev][0] & 0xFE) | value ;
	return AEK_903D_Write_IB(dev, IB0, &FDA903D_Status_IB[dev][0],1);
}
//-------------------------------------------------------IB1---------------------------------------------------
/**
 * @brief   	This function sets the digital input frame sync frequency (Word Select).
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in] 	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 *		-	IB1_FRAME_SYNC_WS_FREQ_44_1_kHz
 *		-	IB1_FRAME_SYNC_WS_FREQ_48_kHz
 *		-	IB1_FRAME_SYNC_WS_FREQ_96_kHz
 *		-	IB1_FRAME_SYNC_WS_FREQ_192_kHz
 *
 *  @return   i2c_result_t
 *
 *  @api
 */
i2c_result_t AEK_903D_SetI2SWordSelect(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB1,&FDA903D_Status_IB[dev][1],1);
	}

	FDA903D_Status_IB[dev][1] = (FDA903D_Status_IB[dev][1] & 0x3F) | value ;
	return AEK_903D_Write_IB(dev, IB1, &FDA903D_Status_IB[dev][1],1);
}

/**
 * @brief   	This function sets the PWM switching frequency in agreement with the I2S Word select.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in] 	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 *		-	IB1_PWM_SWITCH_FREQ_308_7_336_384_384_kHz
 *		-	IB1_PWM_SWITCH_FREQ_352_8_384_384_384_kHz
 *		-	IB1_PWM_SWITCH_FREQ_396_9_432_384_384_kHz
 *
 * @return   i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetPWMSwitchingFrequency(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB1,&FDA903D_Status_IB[dev][1],1);
	}

	FDA903D_Status_IB[dev][1] = (FDA903D_Status_IB[dev][1] & 0xE7) | value ;
	return AEK_903D_Write_IB(dev, IB1, &FDA903D_Status_IB[dev][1],1);
}

/**
 * @brief   	This function sets the PWM amplifier dithered.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetPwmAplifierDithered(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB1,&FDA903D_Status_IB[dev][1],1);
	}

	FDA903D_Status_IB[dev][1] = (FDA903D_Status_IB[dev][1] & 0xFB) | IB1_PWM_AMPLIFIER_CLOCK_DITHERED ;
	return AEK_903D_Write_IB(dev, IB1, &FDA903D_Status_IB[dev][1],1);
}

/**
 * @brief   	This function sets the PWM amplifier NOT dithered.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetPwmAplifierNotDithered(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB1,&FDA903D_Status_IB[dev][1],1);
	}

	FDA903D_Status_IB[dev][1] = (FDA903D_Status_IB[dev][1] & 0xFB) | IB1_PWM_AMPLIFIER_CLOCK_NOT_DITHERED ;
	return AEK_903D_Write_IB(dev, IB1, &FDA903D_Status_IB[dev][1],1);
}

/**
 * @brief   	This function sets the PWM in phase.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetPwmInPhase(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB1,&FDA903D_Status_IB[dev][1],1);
	}

	FDA903D_Status_IB[dev][1] = (FDA903D_Status_IB[dev][1] & 0xFE) | IB1_PWM_IN_PHASE ;
	return AEK_903D_Write_IB(dev, IB1, &FDA903D_Status_IB[dev][1],1);
}

/**
 * @brief   	This function sets the PWM out of phase.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetPwmOutOfPhase(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB1,&FDA903D_Status_IB[dev][1],1);
	}

	FDA903D_Status_IB[dev][1] = (FDA903D_Status_IB[dev][1] & 0xFE) | IB1_PWM_OUT_PHASE ;
	return AEK_903D_Write_IB(dev, IB1, &FDA903D_Status_IB[dev][1],1);
}
//-------------------------------------------------------IB2---------------------------------------------------
/**
 * @brief   	This function sets the Diag Short 2 Supply Timing.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in] 	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 * 		-	IB2_DIAGSHORT2SUPPLY_90MS
 * 		-	IB2_DIAGSHORT2SUPPLY_70MS
 * 		-	IB2_DIAGSHORT2SUPPLY_45MS
 * 		-	IB2_DIAGSHORT2SUPPLY_20MS
 *
 * @return     i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetDiagShort2SupplyTiming(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB2,&FDA903D_Status_IB[dev][2],1);
	}

	FDA903D_Status_IB[dev][2] = (FDA903D_Status_IB[dev][2] & 0x3F) | value ;
	return AEK_903D_Write_IB(dev, IB2, &FDA903D_Status_IB[dev][2],1);
}

/**
 * @brief   	This function disables the low radiation function.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_DisableLowRadiationFunction(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB2,&FDA903D_Status_IB[dev][2],1);
	}

	FDA903D_Status_IB[dev][2] = (FDA903D_Status_IB[dev][2] & 0xEF) | IB2_LOW_RADIATION_FUNCTION_OFF ;
	return AEK_903D_Write_IB(dev, IB2, &FDA903D_Status_IB[dev][2],1);
}

/**
 * @brief   	This function enables the low radiation function.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_EnableLowRadiationFunction(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev,IB2,&FDA903D_Status_IB[dev][2],1);
	}

	FDA903D_Status_IB[dev][2] = (FDA903D_Status_IB[dev][2] & 0xEF) | IB2_LOW_RADIATION_FUNCTION_ON ;
	return AEK_903D_Write_IB(dev,IB2, &FDA903D_Status_IB[dev][2],1);
}

/**
 * @brief   	This function configures power limiter.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in] 	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 *		-	IB2_POWER_LIMITER_DISABLED
 *		-	IB2_POWER_LIMITER_MAX_SCALE_15        	(15%)
 *		-	IB2_POWER_LIMITER_MAX_SCALE_20		    (20%)
 *		-	IB2_POWER_LIMITER_MAX_SCALE_25 			(25%)
 *		-	IB2_POWER_LIMITER_MAX_SCALE_30 			(30%)
 *		-	IB2_POWER_LIMITER_MAX_SCALE_35			(35%)
 *		-	IB2_POWER_LIMITER_MAX_SCALE_40			(40%)
 *		-	IB2_POWER_LIMITER_MAX_SCALE_45			(45%)
 *		-	IB2_POWER_LIMITER_MAX_SCALE_50			(50%)
 *		-	IB2_POWER_LIMITER_MAX_SCALE_60			(60%)
 *		-	IB2_POWER_LIMITER_MAX_SCALE_70			(70%)
 *		-	IB2_POWER_LIMITER_MAX_SCALE_80			(80%)
 *
 * @return   i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_ConfigurePowerLimit(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB2,&FDA903D_Status_IB[dev][2],1);
	}

	FDA903D_Status_IB[dev][2] = (FDA903D_Status_IB[dev][2] & 0xF0) | value ;
	return AEK_903D_Write_IB(dev, IB2, &FDA903D_Status_IB[dev][2],1);
}
//-------------------------------------------------------IB3---------------------------------------------------
/**
 * @brief   	This function disables the output voltage offset detector.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_DisableOutputVoltageOffsetDetector(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB3,&FDA903D_Status_IB[dev][3],1);
	}

	FDA903D_Status_IB[dev][3] = (FDA903D_Status_IB[dev][3] & 0xDF) | IB3_OUTPUT_VOLTAGE_OFFSET_DETECTOR_DISABLE ;
	return AEK_903D_Write_IB(dev, IB3, &FDA903D_Status_IB[dev][3],1);
}

/**
 * @brief   	This function enables the output voltage offset detector.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_EnableOutputVoltageOffsetDetector(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB3,&FDA903D_Status_IB[dev][3],1);
	}

	FDA903D_Status_IB[dev][3] = (FDA903D_Status_IB[dev][3] & 0xDF) | IB3_OUTPUT_VOLTAGE_OFFSET_DETECTOR_EN ;
	return AEK_903D_Write_IB(dev, IB3, &FDA903D_Status_IB[dev][3],1);
}

/**
 * @brief   	This function disables the input offset detector.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_DisableInputOffsetDetector(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB3,&FDA903D_Status_IB[dev][3],1);
	}

	FDA903D_Status_IB[dev][3] = (FDA903D_Status_IB[dev][3] & 0xEF) | IB3_INPUT_OFFSET_DETECTOR_DISABLE ;
	return AEK_903D_Write_IB(dev, IB3, &FDA903D_Status_IB[dev][3],1);
}

/**
 * @brief   	This function enables the input offset detector.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_EnableInputOffsetDetector(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB3,&FDA903D_Status_IB[dev][3],1);
	}

	FDA903D_Status_IB[dev][3] = (FDA903D_Status_IB[dev][3] & 0xEF) | IB3_INPUT_OFFSET_DETECTOR_EN ;
	return AEK_903D_Write_IB(dev, IB3, &FDA903D_Status_IB[dev][3],1);
}

/**
 *
 * @brief   	This function disables the output offset current detector.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_DisableOutputOffsetCurrentDetector(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB3,&FDA903D_Status_IB[dev][3],1);
	}

	FDA903D_Status_IB[dev][3] = (FDA903D_Status_IB[dev][3] & 0xF7) | IB3_OUTPUT_CURRENT_OFFSET_DETECTOR_DISABLE ;
	return AEK_903D_Write_IB(dev, IB3, &FDA903D_Status_IB[dev][3],1);
}

/**
 * @brief   	This function triggers the output offset current detector.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_TriggerOutputOffsetCurrentDetector(AEK_AUD_D903V1_DEVICE dev)
{
	//AEK_903D_Read_IB(dev, IB3,&FDA903D_Status_IB[dev][3],1);
	if ((FDA903D_Status_IB[dev][3] & IB3_OUTPUT_CURRENT_OFFSET_DETECTOR_EN) != IB3_OUTPUT_CURRENT_OFFSET_DETECTOR_EN)
	{
		if(FDA_Status[dev]  != PLAY)
		{
			AEK_903D_Read_IB(dev, IB3,&FDA903D_Status_IB[dev][3],1);
		}

		FDA903D_Status_IB[dev][3] = (FDA903D_Status_IB[dev][3] & 0xF7) | IB3_OUTPUT_CURRENT_OFFSET_DETECTOR_EN ;
		return AEK_903D_Write_IB(dev, IB3, &FDA903D_Status_IB[dev][3],1);
	}
	else
	{
		return I2C_NO_ERROR;
	}
}

/**
 * @brief   	This function disables the high pass filter in the DAC.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_DisableHighPassInDAC(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB3,&FDA903D_Status_IB[dev][3],1);
	}

	FDA903D_Status_IB[dev][3] = (FDA903D_Status_IB[dev][3] & 0xFB) | IB3_HI_PASS_DAC_DISABLED ;
	return AEK_903D_Write_IB(dev, IB3, &FDA903D_Status_IB[dev][3],1);
}

/**
 * @brief   	This function enables the high pass filter in the DAC.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_EnableHighPassInDAC(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB3,&FDA903D_Status_IB[dev][3],1);
	}

	FDA903D_Status_IB[dev][3] = (FDA903D_Status_IB[dev][3] & 0xFB) | IB3_HI_PASS_DAC_ENABLED ;
	return AEK_903D_Write_IB(dev, IB3, &FDA903D_Status_IB[dev][3],1);
}

/**
 * @brief   	This function disables the noise gating.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_DisableNoiseGating(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB3,&FDA903D_Status_IB[dev][3],1);
	}

	FDA903D_Status_IB[dev][3] = (FDA903D_Status_IB[dev][3] & 0xFD) | IB3_NOISE_GATING_DISABLE ;
	return AEK_903D_Write_IB(dev, IB3, &FDA903D_Status_IB[dev][3],1);
}

/**
 * @brief   	This function enables the noise gating.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_EnableNoiseGating(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB3,&FDA903D_Status_IB[dev][3],1);
	}

	FDA903D_Status_IB[dev][3] = (FDA903D_Status_IB[dev][3] & 0xFD) | IB3_NOISE_GATING_EN ;
	return AEK_903D_Write_IB(dev, IB3, &FDA903D_Status_IB[dev][3],1);
}

/**
 * @brief   	This function disables the open load in play detection test.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_DisableOpenLoadInPlayDetection(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB3,&FDA903D_Status_IB[dev][3],1);
	}

	FDA903D_Status_IB[dev][3] = (FDA903D_Status_IB[dev][3] & 0xFE) | IB3_OPENLOAD_PLAY_DISABLE ;
	return AEK_903D_Write_IB(dev, IB3, &FDA903D_Status_IB[dev][3],1);
}

/**
 * @brief   	This function triggers the open load in play detection test.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_TriggerOpenLoadInPlayDetection(AEK_AUD_D903V1_DEVICE dev)
{
//		AEK_903D_Read_IB(dev, IB3,&FDA903D_Status_IB[dev][3],1);
	if ((FDA903D_Status_IB[dev][3] & IB3_OPENLOAD_PLAY_EN) != IB3_OPENLOAD_PLAY_EN)
	{
		if(FDA_Status[dev]  != PLAY)
		{
			AEK_903D_Read_IB(dev, IB3,&FDA903D_Status_IB[dev][3],1);
		}

		FDA903D_Status_IB[dev][3] = (FDA903D_Status_IB[dev][3] & 0xFE) | IB3_OPENLOAD_PLAY_EN ;
		return AEK_903D_Write_IB(dev, IB3, &FDA903D_Status_IB[dev][3],1);
	}
	else
	{
		return I2C_NO_ERROR;
	}
	
}
//-------------------------------------------------------IB4---------------------------------------------------
/**
 * @brief   	This function enables the communication on CDDIAG pin regarding output voltage offset information.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return		i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_EnableOutputVoltageOffsetInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB4,&FDA903D_Status_IB[dev][4],1);
	}

	FDA903D_Status_IB[dev][4] = (FDA903D_Status_IB[dev][4] & 0x7F) | IB4_OUTPUT_VOLTAGE_OFFSET_INFO_ON_CDDIAG ;
	return AEK_903D_Write_IB(dev, IB4, &FDA903D_Status_IB[dev][4],1);
}

/**
 * @brief   	This function disables the communication on CDDIAG pin regarding output voltage offset information.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_DisableOutputVoltageOffsetInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB4,&FDA903D_Status_IB[dev][4],1);
	}

	FDA903D_Status_IB[dev][4] = (FDA903D_Status_IB[dev][4] & 0x7F) | IB4_NO_OUTPUT_VOLTAGE_OFFSET_INFO_ON_CDDIAG ;
	return AEK_903D_Write_IB(dev, IB4, &FDA903D_Status_IB[dev][4],1);
}

/**
 * @brief   	This function configures the communication on CDDIAG pin regarding thermal warning information.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in]	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 *		-	IB4_NO_THERMAL_WARNING_ON_CDDIAG
 * 		-	IB4_TW_LEVEL_1_INFO_ON_CDDIAG
 * 		-	IB4_TW_LEVEL_2_INFO_ON_CDDIAG
 * 		-	IB4_TW_LEVEL_3_INFO_ON_CDDIAG
 * 		-	IB4_TW_LEVEL_4_INFO_ON_CDDIAG
 *
 * @return   i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_ConfigureThermalWarningInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB4,&FDA903D_Status_IB[dev][4],1);
	}

	FDA903D_Status_IB[dev][4] = (FDA903D_Status_IB[dev][4] & 0x8F) | value ;
	return AEK_903D_Write_IB(dev, IB4, &FDA903D_Status_IB[dev][4],1);
}

/**
 * @brief   	This function enables the communication on CDDIAG pin regarding over-current information.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_EnableOvercurrentInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB4,&FDA903D_Status_IB[dev][4],1);
	}

	FDA903D_Status_IB[dev][4] = (FDA903D_Status_IB[dev][4] & 0xF7) | IB4_OVERCURRENT_INFO_ON_CDDIAG ;
	return AEK_903D_Write_IB(dev, IB4, &FDA903D_Status_IB[dev][4],1);
}

/**
 * @brief   	This function disables the communication on CDDIAG pin regarding over-current information.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_DisableOvercurrentInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB4,&FDA903D_Status_IB[dev][4],1);
	}

	FDA903D_Status_IB[dev][4] = (FDA903D_Status_IB[dev][4] & 0xF7) | IB4_NO_OVERCURRENT_INFO_ON_CDDIAG ;
	return AEK_903D_Write_IB(dev, IB4, &FDA903D_Status_IB[dev][4],1);
}

/**
 * @brief   	This function enables the communication on CDDIAG pin regarding input offset information.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_EnableInputOffsetInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB4,&FDA903D_Status_IB[dev][4],1);
	}

	FDA903D_Status_IB[dev][4] = (FDA903D_Status_IB[dev][4] & 0xFB) | IB4_INPUT_OFFSET_INFO_ON_CDDIAG ;
	return AEK_903D_Write_IB(dev, IB4, &FDA903D_Status_IB[dev][4],1);
}

/**
 * @brief   	This function disables the communication on CDDIAG pin regarding input offset information.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return  	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_DisableInputOffsetInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB4,&FDA903D_Status_IB[dev][4],1);
	}

	FDA903D_Status_IB[dev][4] = (FDA903D_Status_IB[dev][4] & 0xFB) | IB4_NO_INPUT_OFFSET_INFO_ON_CDDIAG ;
	return AEK_903D_Write_IB(dev, IB4, &FDA903D_Status_IB[dev][4],1);
}

/**
 * @brief   	This function enables the communication on CDDIAG pin regarding short to Vcc/Gnd information.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_EnableShortToVccOrGndInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev,IB4,&FDA903D_Status_IB[dev][4],1);
	}

	FDA903D_Status_IB[dev][4] = (FDA903D_Status_IB[dev][4] & 0xFD) | IB4_SHORT_TO_VCC_OR_GND_INFO_ON_CDDIAG ;
	return AEK_903D_Write_IB(dev, IB4, &FDA903D_Status_IB[dev][4],1);
}

/**
 * @brief   	This function disables the communication on CDDIAG pin regarding short to Vcc/Gnd information.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_DisableShortToVccOrGndInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB4,&FDA903D_Status_IB[dev][4],1);
	}

	FDA903D_Status_IB[dev][4] = (FDA903D_Status_IB[dev][4] & 0xFD) | IB4_NO_SHORT_TO_VCC_OR_GND_INFO_ON_CDDIAG ;
	return AEK_903D_Write_IB(dev, IB4, &FDA903D_Status_IB[dev][4],1);
}

/**
 * @brief   	This function enables the communication on CDDIAG pin regarding high voltage mute information.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_EnableHighVoltageMuteInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB4,&FDA903D_Status_IB[dev][4],1);
	}

	FDA903D_Status_IB[dev][4] = (FDA903D_Status_IB[dev][4] & 0xFE) | IB4_HIGH_VOLTAGE_MUTE_INFO_ON_CDDIAG ;
	return AEK_903D_Write_IB(dev, IB4, &FDA903D_Status_IB[dev][4],1);
}

/**
 * @brief   	This function disables the communication on CDDIAG pin regarding high voltage mute information.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_DisableHighVoltageMuteInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB4,&FDA903D_Status_IB[dev][4],1);
	}

	FDA903D_Status_IB[dev][4] = (FDA903D_Status_IB[dev][4] & 0xFE) | IB4_NO_HIGH_VOLTAGE_MUTE_INFO_ON_CDDIAG ;
	return AEK_903D_Write_IB(dev, IB4, &FDA903D_Status_IB[dev][4],1);
}
//-------------------------------------------------------IB5---------------------------------------------------
/**
 * @brief   	This function enables the communication on CDDIAG pin regarding under-voltage vcc information.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_EnableUvlovccInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB5,&FDA903D_Status_IB[dev][5],1);
	}

	FDA903D_Status_IB[dev][5] = (FDA903D_Status_IB[dev][5] & 0x7F) | IB5_UVLOVCC_INFO_ON_CDDIAG ;
	return AEK_903D_Write_IB(dev, IB5, &FDA903D_Status_IB[dev][5],1);
}

/**
 * @brief   	This function disables the communication on CDDIAG pin regarding under-voltage vcc information.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_DisableUvlovccInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB5,&FDA903D_Status_IB[dev][5],1);
	}

	FDA903D_Status_IB[dev][5] = (FDA903D_Status_IB[dev][5] & 0x7F) | IB5_NO_UVLOVCC_INFO_ON_CDDIAG ;
	return AEK_903D_Write_IB(dev, IB5, &FDA903D_Status_IB[dev][5],1);
}

/**
 * @brief   	This function enables the communication on CDDIAG pin regarding thermal shutdown information.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_EnableThermalShutdownInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB5,&FDA903D_Status_IB[dev][5],1);
	}

	FDA903D_Status_IB[dev][5] = (FDA903D_Status_IB[dev][5] & 0xBF) | IB5_THERMAL_SHUTDOWN_INFO_ON_CDDIAG ;
	return AEK_903D_Write_IB(dev, IB5, &FDA903D_Status_IB[dev][5],1);
}

/**
 * @brief   	This function disables the communication on CDDIAG pin regarding thermal shutdown information.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_DisableThermalShutdownInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB5,&FDA903D_Status_IB[dev][5],1);
	}

	FDA903D_Status_IB[dev][5] = (FDA903D_Status_IB[dev][5] & 0xBF) | IB5_NO_THERMAL_SHUTDOWN_INFO_ON_CDDIAG ;
	return AEK_903D_Write_IB(dev, IB5, &FDA903D_Status_IB[dev][5],1);
}

/**
 * @brief   	This function enables the communication on CDDIAG pin regarding pwm pulse skipping detector information.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_EnablePwmPulseSkippingInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB5,&FDA903D_Status_IB[dev][5],1);
	}

	FDA903D_Status_IB[dev][5] = (FDA903D_Status_IB[dev][5] & 0xCF) | IB5_PWM_PULSE_SKIPPING_DETECTOR ;
	return AEK_903D_Write_IB(dev, IB5, &FDA903D_Status_IB[dev][5],1);
}

/**
 * @brief   	This function disables the communication on CDDIAG pin regarding pwm pulse skipping detector information.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return  	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_DisablePwmPulseSkippingInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB5,&FDA903D_Status_IB[dev][5],1);
	}

	FDA903D_Status_IB[dev][5] = (FDA903D_Status_IB[dev][5] & 0xCF) | IB5_NO_CLIPPING_INFORMATION ;
	return AEK_903D_Write_IB(dev, IB5, &FDA903D_Status_IB[dev][5],1);
}
//-------------------------------------------------------IB6---------------------------------------------------
/**
 * @brief   	This function selects the mute timing setup (values with fsample = 44.1 kHz).
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in]	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 * 		-	IB6_VERY_FAST_MUTE_TIMING_SETUP
 * 		-	IB6_FAST_MUTE_TIMING_SETUP
 * 		-	IB6_SLOW_MUTE_TIMING_SETUP
 * 		-	IB6_VERY_SLOW_MUTE_TIMING_SETUP
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_SelectMuteTimingsetup(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB6,&FDA903D_Status_IB[dev][6],1);
	}

	FDA903D_Status_IB[dev][6] = (FDA903D_Status_IB[dev][6] & 0x3F) | value ;
	return  AEK_903D_Write_IB(dev, IB6, &FDA903D_Status_IB[dev][6],1);
}

/**
 * @brief   	This function selects the audio signal gain control.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in]	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 * 		-	IB6_STANDARD_DIGITAL_AUDIO_GAIN
 * 		-	IB6_6DB_DIGITAL_AUDIO_GAIN
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_SelectAudioSignalGainControl(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB6,&FDA903D_Status_IB[dev][6],1);
	}

	FDA903D_Status_IB[dev][6] = (FDA903D_Status_IB[dev][6] & 0xDF) | value ;

	return  AEK_903D_Write_IB(dev, IB6, &FDA903D_Status_IB[dev][6],1);
}

/**
 * @brief   	This function selects the gain setting.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in]	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 * 		-	IB6_STANDARD_GAIN
 * 		-	IB6_LOW_GAIN
 *
 * @return   i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_SelectGainSetting(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB6,&FDA903D_Status_IB[dev][6],1);
	}

	FDA903D_Status_IB[dev][6] = (FDA903D_Status_IB[dev][6] & 0xEF) | value ;
	return  AEK_903D_Write_IB(dev, IB6, &FDA903D_Status_IB[dev][6],1);
}
//-------------------------------------------------------IB7---------------------------------------------------
/**
 * @brief   	This function selects the diagnostic ramp time.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in]	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 * 		-	IB7_DIAGNOSTIC_RAMP_TIME_NORMAL
 * 		-	IB7_DIAGNOSTIC_RAMP_TIME_x2
 * 		-	IB7_DIAGNOSTIC_RAMP_TIME_x4
 * 		-	IB7_DIAGNOSTIC_RAMP_TIME_x0_5
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_SelectDiagnosticRampTime(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB7,&FDA903D_Status_IB[dev][7],1);
	}

	FDA903D_Status_IB[dev][7] = (FDA903D_Status_IB[dev][7] & 0x3F) | value ;
	return  AEK_903D_Write_IB(dev, IB7, &FDA903D_Status_IB[dev][7],1);
}

/**
 * @brief   	This function selects the diagnostic hold time.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in]	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 * 		-	IB7_DIAGNOSTIC_HOLD_TIME_NORMAL
 * 		-	IB7_DIAGNOSTIC_HOLD_TIME_x2
 * 		-	IB7_DIAGNOSTIC_HOLD_TIME_x4
 * 		-	IB7_DIAGNOSTIC_HOLD_TIME_x0_5
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_SelectDiagnosticHoldTime(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB7,&FDA903D_Status_IB[dev][7],1);
	}

	FDA903D_Status_IB[dev][7] = (FDA903D_Status_IB[dev][7] & 0xCF) | value ;
	return  AEK_903D_Write_IB(dev, IB7, &FDA903D_Status_IB[dev][7],1);
}

/**
 * @brief   	This function select the current sensing data communication.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in]	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 * 		-	IB7_DATA_OUT_ON_I2SCLK_FALLING_EDGE
 * 		-	IB7_DATA_OUT_ON_I2SCLK_RISING_EDGE
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_SelectCurrentSensingCommunication(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB7,&FDA903D_Status_IB[dev][7],1);
	}

	FDA903D_Status_IB[dev][7] = (FDA903D_Status_IB[dev][7] & 0xFD) | value ;
	return  AEK_903D_Write_IB(dev, IB7, &FDA903D_Status_IB[dev][7],1);
}

/**
 * @brief   	This function select the current sensing protocol configuration.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in]	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 * 		-	IB7_I2STEST_AT_ZERO_ON_OTHER_SLOTS
 * 		-	IB7_TRANSMITTER_IN_HiZ_STATE_OTHER_SLOTS
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t  AEK_903D_SelectCurrentSensingProtocolConfiguration(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB7,&FDA903D_Status_IB[dev][7],1);
	}

	FDA903D_Status_IB[dev][7] = (FDA903D_Status_IB[dev][7] & 0xFE) | value ;
	return  AEK_903D_Write_IB(dev, IB7, &FDA903D_Status_IB[dev][7],1);
}
//-------------------------------------------------------IB8---------------------------------------------------
/**
 * @brief   	This function sets the current sensing full scale.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in]	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 * 		-	IB8_Imax1A
 * 		-	IB8_Imax2A
 * 		-	IB8_Imax4A
 * 		-	IB8_Imax8A
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetCurrentSensingFullScale(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB8,&FDA903D_Status_IB[dev][8],1);
	}

	switch(value)
	{
		case IB8_Imax1A:
			current_sensing_full_scale = 1;
			break;
		case IB8_Imax2A:
			current_sensing_full_scale = 2;
			break;
		case IB8_Imax4A:
			current_sensing_full_scale = 4;
			break;
		case IB8_Imax8A:
			current_sensing_full_scale = 8;
			break;
		default:
			current_sensing_full_scale = 0;
			break;
	}
	FDA903D_Status_IB[dev][8] = (FDA903D_Status_IB[dev][8] & 0x3F) | value ;
	return  AEK_903D_Write_IB(dev, IB8, &FDA903D_Status_IB[dev][8],1);
}

/**
 * @brief   	This function sets channel with PWM OFF.(TRISTATE)
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetChannelWithPWMoff(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB8,&FDA903D_Status_IB[dev][8],1);
	}

	FDA903D_Status_IB[dev][8] = (FDA903D_Status_IB[dev][8] & 0xDF) | IB8_PWM_OFF ;
	FDA_Status[dev]  = ECO_MODE;
	return  AEK_903D_Write_IB(dev, IB8, &FDA903D_Status_IB[dev][8],1);
}

/**
 * @brief   	This function sets channel with PWM ON.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetChannelWithPWMon(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB8,&FDA903D_Status_IB[dev][8],1);
	}
	
	FDA903D_Status_IB[dev][8] = (FDA903D_Status_IB[dev][8] & 0xDF) | IB8_PWM_ON ;
	FDA_Status[dev]  = MUTE;
    return  AEK_903D_Write_IB(dev, IB8, &FDA903D_Status_IB[dev][8], 1);
}

/**
 * @brief   	This function allows the audio amplifier to go in ECO mode.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_Eco_Mode(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB8,&FDA903D_Status_IB[dev][8],1);
	}

	FDA903D_Status_IB[dev][8] = (FDA903D_Status_IB[dev][8] & 0xDF) | IB8_PWM_OFF ;
	FDA_Status[dev]  = ECO_MODE;
    return AEK_903D_Write_IB(dev, IB8, &FDA903D_Status_IB[dev][8], 1);
}

/**
 * @brief   	This function enables the DC diagnostic test and assures to have the PWM in phase (PWM in phase is required during DC Diagnostic).
 * 				Before to enter in Diag DC state, you must stay in MUTE state.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_StartDCDiag(AEK_AUD_D903V1_DEVICE dev)
{
	i2c_result_t ret;
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB8,&FDA903D_Status_IB[dev][8],1);
		 /*The DCDiag require PWM in Phase*/
		AEK_903D_Read_IB(dev, IB1,&FDA903D_Status_IB[dev][1],1);
	}

	FDA903D_Status_IB[dev][8] = (FDA903D_Status_IB[dev][8] & 0xEF) | IB8_START_DIAG ;
	ret = AEK_903D_Write_IB(dev, IB8, &FDA903D_Status_IB[dev][8],1);
	/*The DCDiag require PWM in Phase*/
	FDA903D_Status_IB[dev][1] = (FDA903D_Status_IB[dev][1] & 0xFE) | IB1_PWM_IN_PHASE;
	ret |= AEK_903D_Write_IB(dev, IB1, &FDA903D_Status_IB[dev][1],1);

	FDA_Status[dev]  = DIAG_DC;
	return ret;
}

/**
 * @brief   	This function disables the DC diagnostic test.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_DisableDCDiag(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB8,&FDA903D_Status_IB[dev][8],1);
	}

	FDA903D_Status_IB[dev][8] = (FDA903D_Status_IB[dev][8] & 0xEF) | IB8_DC_DIAG_DISABLE ;
	FDA_Status[dev]  = MUTE;
	return AEK_903D_Write_IB(dev, IB8, &FDA903D_Status_IB[dev][8], 1);
}

/**
 * @brief   	This function configures the I2Stest pin.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in]	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 * 		-  	IB8_HIGH_IMPEDENCE_CONFIG
 * 		-	IB8_CURRENT_SENSING_ENABLED
 * 		-	IB8_PWM_SYNCHRO_SIGNAL
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_I2TestPinConfiguration(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB8,&FDA903D_Status_IB[dev][8],1);
	}

	FDA903D_Status_IB[dev][8] = (FDA903D_Status_IB[dev][8] & 0xF1) | value ;
	return AEK_903D_Write_IB(dev, IB8, &FDA903D_Status_IB[dev][8], 1);
}

/**
 * @brief   	This function allows the audio amplifier to go in PLAY state.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_Play(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB8,&FDA903D_Status_IB[dev][8],1);
	}

	FDA903D_Status_IB[dev][8] = (FDA903D_Status_IB[dev][8] & 0xFE) | IB8_PWM_ON | IB8_PLAY  ; // play and PWM on
	return AEK_903D_Write_IB(dev, IB8, &FDA903D_Status_IB[dev][8], 1);
}

/**
 * @brief   	This function allows the audio amplifier to go in Mute state.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_Mute(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB8,&FDA903D_Status_IB[dev][8],1);
	}

	FDA903D_Status_IB[dev][8] = (FDA903D_Status_IB[dev][8] & 0xFE) | IB8_PWM_ON | IB8_MUTE  ;
	FDA_Status[dev]  = MUTE;
    return AEK_903D_Write_IB(dev, IB8, &FDA903D_Status_IB[dev][8], 1);
}
//-------------------------------------------------------IB9---------------------------------------------------
/**
 * @brief   	This function enables watch-dog for Word Select.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_EnableWatchDogForWordSelect(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB9,&FDA903D_Status_IB[dev][9],1);
	}

	FDA903D_Status_IB[dev][9] = (FDA903D_Status_IB[dev][9] & 0xEF) | IB9_ENABLE_WATCH_DOG_FOR_WORDSELECT  ;
	return AEK_903D_Write_IB(dev, IB9, &FDA903D_Status_IB[dev][9], 1);
}

/**
 * @brief    	This function disables watch-dog for Word Select.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_DisableWatchDogForWordSelect(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB9,&FDA903D_Status_IB[dev][9],1);
	}

	FDA903D_Status_IB[dev][9] = (FDA903D_Status_IB[dev][9] & 0xEF) | IB9_DISABLE_WATCH_DOG_FOR_WORDSELECT  ;
	return AEK_903D_Write_IB(dev, IB9, &FDA903D_Status_IB[dev][9], 1);
}
//-------------------------------------------------------IB10---------------------------------------------------
/**
 * @brief   	This function sets the short load impedance threshold.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in]	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 * 		-  	IB10_SHORT_LOAD_IMP_THRESOLD_0_075ohm
 * 		-	IB10_SHORT_LOAD_IMP_THRESOLD_1_05ohm
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetShortLoadImpedanceThreshold(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB10,&FDA903D_Status_IB[dev][10],1);
	}

	FDA903D_Status_IB[dev][10] = (FDA903D_Status_IB[dev][10] & 0x7F) | value ;
	return AEK_903D_Write_IB(dev, IB10, &FDA903D_Status_IB[dev][10], 1);
}

/**
 * @brief   	This function sets the open load impedance threshold.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in]	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 * 		-  	IB10_OPEN_LOAD_IMP_THRESOLD_0_25ohm
 * 		-	IB10_OPEN_LOAD_IMP_THRESOLD_1_15ohm
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetOpenLoadImpedanceThreshold(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB10,&FDA903D_Status_IB[dev][10],1);
	}

	FDA903D_Status_IB[dev][10] = (FDA903D_Status_IB[dev][10] & 0xBF) | value ;
	return AEK_903D_Write_IB(dev, IB10, &FDA903D_Status_IB[dev][10], 1);
}

/**
 * @brief   	This function sets the current offset threshold.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in]	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 * 		-  	IB10_CURRENT_OFFSET_025A
 * 		-	IB10_CURRENT_OFFSET_05A
 * 		-	IB10_CURRENT_OFFSET_1A
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetCurrentOffsetThreshold(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB10,&FDA903D_Status_IB[dev][10],1);
	}

	FDA903D_Status_IB[dev][10] = (FDA903D_Status_IB[dev][10] & 0xE7) | value ;
	return AEK_903D_Write_IB(dev, IB10, &FDA903D_Status_IB[dev][10], 1);
}
//-------------------------------------------------------IB11---------------------------------------------------
/**
 * @brief   	This function selects the over current protection Level.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in]	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 * 		-  	IB11_OVER_CURRENT_PROTECTION_11A
 * 		-	IB11_OVER_CURRENT_PROTECTION_8A
 * 		-	IB11_OVER_CURRENT_PROTECTION_6A
 *		-	IB11_OVER_CURRENT_PROTECTION_4A
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SelectOverCurrentProtectionLevel(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB11,&FDA903D_Status_IB[dev][11],1);
	}

	FDA903D_Status_IB[dev][11] = (FDA903D_Status_IB[dev][11] & 0xCF) | value ;
	return AEK_903D_Write_IB(dev,IB11, &FDA903D_Status_IB[dev][11], 1);
}

/**
 * @brief   	This function sets the slow slope PWM configuration. Please observe that thermal warning shift -15 ï¿½C (IB12[D7] = 1) is required.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetSlowSlopePWMConfiguration(AEK_AUD_D903V1_DEVICE dev)
{
	i2c_result_t ret;
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB11,&FDA903D_Status_IB[dev][11],1);
		/*The slow slope PWM requires thermal warning shift -15 ï¿½C*/
		AEK_903D_Read_IB(dev,IB12,&FDA903D_Status_IB[dev][12],1);
	}

	FDA903D_Status_IB[dev][11] = (FDA903D_Status_IB[dev][11] & 0xF7) | IB11_PWM_SLOW_SLOPE ;
	ret = AEK_903D_Write_IB(dev, IB11, &FDA903D_Status_IB[dev][11],1);
	/*The slow slope PWM requires thermal warning shift -15 ï¿½C*/
	FDA903D_Status_IB[dev][12] = (FDA903D_Status_IB[dev][12] & 0x7F) | IB12_THERMAL_WARNING_SHIFT;
	ret |= AEK_903D_Write_IB(dev, IB12, &FDA903D_Status_IB[dev][12],1);

	return  ret;
}

/**
 * @brief   	This function sets the default PWM configuration. Please observe that standard thermal warning (IB12[D7] = 0) is required.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return   	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetDefaultPWMConfiguration(AEK_AUD_D903V1_DEVICE dev)
{
	i2c_result_t ret;
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev, IB11,&FDA903D_Status_IB[dev][11],1);
		/*The standard PWM requires standard thermal warning*/
		AEK_903D_Read_IB(dev, IB12,&FDA903D_Status_IB[dev][12],1);
	}

	FDA903D_Status_IB[dev][11] = (FDA903D_Status_IB[dev][11] & 0xF7) | IB11_PWM_DEFAULT ;
	ret = AEK_903D_Write_IB(dev, IB11, &FDA903D_Status_IB[dev][11],1);
	/*The standard PWM requires standard thermal warning*/
	FDA903D_Status_IB[dev][12] = (FDA903D_Status_IB[dev][12] & 0x7F) | IB12_STANDART_THERMAL_WARNING;
	ret = AEK_903D_Write_IB(dev, IB12, &FDA903D_Status_IB[dev][12],1);

	return  ret;
}
//-------------------------------------------------------IB12---------------------------------------------------
/**
 * @brief      	This functions sets the thermal warning.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in]	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 * 		-	IB12_STANDART_THERMAL_WARNING
 *		-	IB12_THERMAL_WARNING_SHIFT
 *
 * @return     i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetThermalWarning(AEK_AUD_D903V1_DEVICE dev, uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev,IB12,&FDA903D_Status_IB[dev][12],1);
	}

	FDA903D_Status_IB[dev][12] = (FDA903D_Status_IB[dev][12] & 0x7F) | value ;
	return AEK_903D_Write_IB(dev,IB12, &FDA903D_Status_IB[dev][12], 1);
}
//-------------------------------------------------------IB13---------------------------------------------------
/**
 * @brief      	This functions enables the digital mute in play when Start Analog Mute without Thermal Warning 1 occurs.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return     	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_EnableDigitalMuteInPlayForTW1(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev,IB13,&FDA903D_Status_IB[dev][13],1);
	}

	FDA903D_Status_IB[dev][13] = (FDA903D_Status_IB[dev][13] & 0xBF) | IB13_DIGITAL_MUTE_IN_PLAY_EN ;
	return AEK_903D_Write_IB(dev,IB13, &FDA903D_Status_IB[dev][13], 1);
}

/**
 * @brief       This functions disables the digital mute in play when Start Analog Mute without Thermal Warning 1 occurs.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return     	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_DisableDigitalMuteInPlayForTW1(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev,IB13,&FDA903D_Status_IB[dev][13],1);
	}

	FDA903D_Status_IB[dev][13] = (FDA903D_Status_IB[dev][13] & 0xBF) | IB13_DIGITAL_MUTE_IN_PLAY_DISABLE ;
	return AEK_903D_Write_IB(dev,IB13, &FDA903D_Status_IB[dev][13], 1);
}
//-------------------------------------------------------IB14---------------------------------------------------
/**
 * @brief      	This functions sets feedback on LC filter.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return     	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetFeedbackOnLCfilter(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev,IB14,&FDA903D_Status_IB[dev][14],1);
	}

	FDA903D_Status_IB[dev][14] = (FDA903D_Status_IB[dev][14] & 0xEF) | IB14_SET_FEEDBACK_LC_FILTER ;
	return AEK_903D_Write_IB(dev,IB14, &FDA903D_Status_IB[dev][14], 1);
}

/**
 * @brief      	This functions sets feedback on Out pin.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return     	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetFeedbackOnOutPin(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev,IB14,&FDA903D_Status_IB[dev][14],1);
	}

	FDA903D_Status_IB[dev][14] = (FDA903D_Status_IB[dev][14] & 0xEF) | IB14_SET_FEEDBACK_OUT_PIN ;
	return AEK_903D_Write_IB(dev,IB14, &FDA903D_Status_IB[dev][14], 1);
}

/**
 * @brief      	This function sets up the LC filter.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in]	value (Choose one of these parameters and copy it into the 'value' field of the function):
 *
 *		-	IB14_LC_FILTER_1_OUTPHASE 		(10 ï¿½H + 2.2 ï¿½F Out Phase)
 *     	-	IB14_LC_FILTER_1_INPHASE 		(10 ï¿½H + 2.2 ï¿½F In Phase)
 *     	-	IB14_LC_FILTER_2_OUTPHASE		(10 ï¿½H + 3.3 ï¿½F In Phase)
 *     	-	IB14_LC_FILTER_2_INPHASE 		(10 ï¿½H + 3.3 ï¿½F In Phase)
 *     	-	IB14_LC_FILTER_3_OUTPHASE		(10 ï¿½H + 4.7 ï¿½F In Phase)
 *		-	IB14_LC_FILTER_3_INPHASE 		(10 ï¿½H + 4.7 ï¿½F In Phase)
 *
 * @return     	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_SetupLCFilter(AEK_AUD_D903V1_DEVICE dev,uint8_t value)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev,IB14,&FDA903D_Status_IB[dev][14],1);
	}

	FDA903D_Status_IB[dev][14] = (FDA903D_Status_IB[dev][14] & 0xF1) | value ;
	return AEK_903D_Write_IB(dev,IB14, &FDA903D_Status_IB[dev][14], 1);
}

/**
 * @brief      	This functions enables the device to be programmed via I2C.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return     	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_Enable903ToBeProgramViaI2C(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev,IB14,&FDA903D_Status_IB[dev][14],1);
	}

	FDA903D_Status_IB[dev][14] = (FDA903D_Status_IB[dev][14] & 0xFE) | IB14_SET_FDA_PROGRAMMED_VIA_I2C ;
	return AEK_903D_Write_IB(dev,IB14, &FDA903D_Status_IB[dev][14], 1);
}

/**
 * @brief      	This functions disables the device to be programmed via I2C.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @return     	i2c_result_t
 *
 * @api
 */
i2c_result_t AEK_903D_Disable903ToBeProgramViaI2C(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_IB(dev,IB14,&FDA903D_Status_IB[dev][14],1);
	}

	FDA903D_Status_IB[dev][14] = (FDA903D_Status_IB[dev][14] & 0xFE) | IB14_SET_FDA_NOT_PROGRAMMED_VIA_I2C ;
	return AEK_903D_Write_IB(dev,IB14, &FDA903D_Status_IB[dev][14], 1);
}

/*******************************************************************************
 ****************** Functions to check the diagnostic results  *****************
 *******************************************************************************/

/**
 * @brief   	This function checks the Offset Current. The result of Offset Current is reported into the FDA903D_Error structure. This check can be executed both MUTE and PLAY status.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @api
 */
void AEK_903D_CheckOffsetCurrent(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_DB(dev, DB0, &FDA903D_Status_DB[dev][0],1);
		if(((FDA903D_Status_DB[dev][0] & DB0_OUTPUT_CURRENT_VALID) == DB0_OUTPUT_CURRENT_VALID )) // Offset Current test data not valid)
		{
			FDA903_Errors[dev].B.CURR_OUT_OFF_TEST_VALID = (((FDA903D_Status_DB[dev][0] & DB0_OUTPUT_CURRENT_VALID) == DB0_OUTPUT_CURRENT_VALID ) ? 1 : 0);
			FDA903_Errors[dev].B.CURRENTOFFSET = (((FDA903D_Status_DB[dev][0] & DB0_OUTPUT_CURRENT_OFFSET) == DB0_OUTPUT_CURRENT_OFFSET ) ? 1 : 0); // Output Current Offset
		}
	}
	else
	{
		if(((FDA903D_Status_DB[dev][0] & DB0_OUTPUT_CURRENT_VALID) == DB0_OUTPUT_CURRENT_VALID )) // Offset Current test data not valid)
		{
			FDA903_Errors[dev].B.CURR_OUT_OFF_TEST_VALID = (((FDA903D_Status_DB[dev][0] & DB0_OUTPUT_CURRENT_VALID) == DB0_OUTPUT_CURRENT_VALID ) ? 1 : 0);
			FDA903_Errors[dev].B.CURRENTOFFSET = (((FDA903D_Status_DB[dev][0] & DB0_OUTPUT_CURRENT_OFFSET) == DB0_OUTPUT_CURRENT_OFFSET ) ? 1 : 0); // Output Current Offset
		}
	}
}

/**
 * @brief   	This function checks the Input Offset. The result of Input Offset is reported into the FDA903D_Error structure.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @api
 */
void AEK_903D_CheckInputOffsetDetector(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_DB(dev, DB0, &FDA903D_Status_DB[dev][0],1);
	}
	FDA903_Errors[dev].B.INPUTOFFSET = (((FDA903D_Status_DB[dev][0] & DB0_INPUT_OFFSET) == DB0_INPUT_OFFSET ) ? 1 : 0);   // Input Offsets
}

/**
 * @brief   	This function checks the Output Voltage Offset. The result of Output Voltage Offset is reported into the FDA903D_Error structure.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @api
 */
void AEK_903D_CheckOutputVoltageOffsetDetector(AEK_AUD_D903V1_DEVICE dev)
{
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_DB(dev, DB0, &FDA903D_Status_DB[dev][0],1);
	}
	FDA903_Errors[dev].B.OUTPUTOFFSET = (((FDA903D_Status_DB[dev][0] & DB0_OUTPUT_VOLTAGE_OFFSET) == DB0_OUTPUT_VOLTAGE_OFFSET ) ? 1 : 0);  // Output Voltage offset
}

/**
 * @brief   	This function checks the open load in play detection. The result of Open Load in Play detection is reported into the FDA903D_Error structure.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @api
 */
void AEK_903D_CheckOpenLoadInPlayDetection(AEK_AUD_D903V1_DEVICE dev)
{
	if(NO_READ_DB_AND_IB_REG_DURING_PLAY == 1)
	{
	   AEK_903D_Read_DB(dev, DB2, &FDA903D_Status_DB[dev][2],1);
	   AEK_903D_Read_DB(dev, DB0, &FDA903D_Status_DB[dev][0],1);
	}

	if((FDA903D_Status_DB[dev][2] & DB2_CHANNEL_PLAY) == DB2_CHANNEL_PLAY)  // If system is in Play - channel in play
	{
		// Check Open Load test ended
		 if((FDA903D_Status_DB[dev][0] & DB0_OPENLOAD_ENDED) == DB0_OPENLOAD_ENDED)
		 {	 // Check Open Load Test valid
			 FDA903_Errors[dev].B.OPENLOAD_IN_PLAY_TEST_IS_VALID = ((FDA903D_Status_DB[dev][0] & DB0_OPENLOAD_VALID) == DB0_OPENLOAD_VALID) ? 1 : 0;
			 if((FDA903D_Status_DB[dev][0] & DB0_OPENLOAD_VALID) == DB0_OPENLOAD_VALID)
			 {	 // Check Open Load detected
				 FDA903_Errors[dev].B.OPENLOAD_PLAY = ((FDA903D_Status_DB[dev][0] & DB0_OPENLOAD) == DB0_OPENLOAD) ? 1 : 0 ;
			 }
		 }

	}
}

/**
 * @brief   	This function checks the DC Diagnostic. The result of DC Diagnostic is reported into the FDA903D_Error structure.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @param[in]  	boolean runDCDiag:
 *
 * 		-	true		to restart DCdiag continuosly
 * 		- 	false		to not restart DCdiag continuosly
 *
 * @api
 */
void AEK_903D_CheckDCDiagnostic(AEK_AUD_D903V1_DEVICE dev, boolean runDCDiag)
{
	osalThreadDelayMilliseconds(350);
	if((AEK_903D_Read_DB(dev, DB2, &FDA903D_Status_DB[dev][2],1) != I2C_NO_ERROR)) return ;

	if((FDA903D_Status_DB[dev][2] & DB2_CHANNEL_MUTE) == DB2_CHANNEL_MUTE)
	{
		// Check  DC Diagnostic ended
		if((FDA903D_Status_DB[dev][2] & DB2_DC_DIAGNOSTIC_ENDED) == DB2_DC_DIAGNOSTIC_ENDED)
		{   // Check if DC diagnostic is valid
			if((FDA903D_Status_DB[dev][2] & DB2_DC_DIAGNOSTIC_VALID) == DB2_DC_DIAGNOSTIC_VALID)
			{
				//evaluate if OPENLOAD has been detected and if short load has been detected.
				 FDA903_Errors[dev].B.OPENLOAD_DC= ((FDA903D_Status_DB[dev][2] & DB2_DC_OPENLOAD) == DB2_DC_OPENLOAD) ? 1 : 0 ;
				 FDA903_Errors[dev].B.SHORTLOAD_DC= ((FDA903D_Status_DB[dev][2] & DB2_DC_SHORTLOAD) == DB2_DC_SHORTLOAD) ? 1 : 0 ;
			}
			else
			{
				if(runDCDiag)
				{
					AEK_903D_StartDCDiag(dev);
				}
			 }
		}
	}
}

/**
 * @brief   	This function execute the following diagnostic check:
 *
 *		- Short to GND
 *  	- Short to VCC
 *  	- OverCurrent
 *  	- UnderVoltage
 *  	- Thermal Shutdown
 *  	- Over Voltage
 *
 *  			updating every time a field of FADA903_Error structure according to the check executed.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @api
 */
void AEK_903D_Diagnostic(AEK_AUD_D903V1_DEVICE dev)
{

	// read all BD register
	if(FDA_Status[dev]  != PLAY)
	{
		AEK_903D_Read_DB(dev, DB2, &FDA903D_Status_DB[dev][2],1);
		AEK_903D_Read_DB(dev, DB6, &FDA903D_Status_DB[dev][6],1);
	}

	FDA903_Errors[dev].B.SHORT2GND = (((FDA903D_Status_DB[dev][2] & DB2_SHORT_TO_GND) == DB2_SHORT_TO_GND) ? 1 : 0);   // Short to GND
	FDA903_Errors[dev].B.SHORT2VCC = (((FDA903D_Status_DB[dev][2] & DB2_SHORT_TO_VCC) == DB2_SHORT_TO_VCC) ? 1 : 0);   // Short to VCC
	FDA903_Errors[dev].B.OVERCURRENT = (((FDA903D_Status_DB[dev][2] & DB2_OVERCURRENT) == DB2_OVERCURRENT ) ? 1 : 0);   //OverCurrent
    FDA903_Errors[dev].B.UNDERVOLTAGE =(((FDA903D_Status_DB[dev][6] & DB6_UNDERVOLTAGE) == DB6_UNDERVOLTAGE ) ? 1 : 0);   //UnderVoltage
    FDA903_Errors[dev].B.OVERTEMPERATURE = (((FDA903D_Status_DB[dev][6] & DB6_THERMSHUTDOWN) == DB6_THERMSHUTDOWN) ? 1 : 0); // Thermal Shutdown
    FDA903_Errors[dev].B.OVERVOLTAGE = (((FDA903D_Status_DB[dev][6] & DB1_OVERVOLTAGE) == DB1_OVERVOLTAGE) ? 1 : 0); // Over Voltage
}


/**
 * @brief  This function updates the array contained in the structure CurrentSensingElement,
 * 		   with the current sensing value retrieved by I2S.
 *
 *  	   Applying the following formula to each element of the array, the user will be able to estimate the current sensing value in amperes(A).
 *
 * 		   - Current read[A] = current range selected * (array value converted decimal / saturation code)
 *
 * 		   where:
 * 		   			 saturation code = (2^(15-1) * saturation).
 *                   current range selected is the value that has been set in the IB8 D[7-6] register.
 * 		             saturation = 437.5 mFs  if WS=44.1 kHz or 48 kHz and IB1[4,3]= '00'
 * 		   				          500   mFs  if WS=44.1 kHz or 48 kHz and IB1[4,3]= '01'
 * 		   				          562.5 mFs  if WS=44.1 kHz or 48 kHz and IB1[4,3]= '10'
 * 		   				          250   mFs  if WS=96  kHz
 * 		   				          125   mFs  if WS=192 kHz
 *
 *		   Note: The array elements are coded with two's complement notation.
 *
 * @api
 */
void AEK_903D_UpdateCurrentSensingBuffer()
{
	uint16_t count = 0;
	uint16_t i;

	for (i = 0; i < 1008; i+=4)
	{
		FDA903_CurrentSensingBuff[0].currentSensBuffer[count] = rxbuf[i] << 8 | rxbuf[i+1] ;
		count++;
	}
	FDA903_CurrentSensingBuff[0].arrayLenght = count;
}


/**
 * @brief  This function returns the current sensing value in ampere [A].
 *
 *         Note: In order to retrieve a correct current value,set saturation_code
 *         and current_sensing_full_scale using respectively AEK_903D_SetSaturationCodeForCurrentSensing and
 *		   AEK_903D_SetCurrentSensingFullScale functions.
 *
 * @param[in]  	AEK_AUD_D903V1_DEVICE dev
 *
 * @ return float
 *
 * @api
 */
float AEK_903D_GetCurrentSensingValue(AEK_AUD_D903V1_DEVICE dev)
{
	float currentValue = 0;
	uint8_t negNumber=0;
	uint16_t tmp = 0;

	if(FDA_Status[dev]  != PLAY)
	{
			AEK_903D_Read_DB(dev,DB4,&FDA903D_Status_DB[dev][4],1);
			AEK_903D_Read_DB(dev,DB5,&FDA903D_Status_DB[dev][5],1);
	}

	/*Taken only 11 bits D[2-0] from DB4 and all bits from DB5*/
	tmp = (FDA903D_Status_DB[dev][4] & 0x7) << 8 | FDA903D_Status_DB[dev][5];

	tmp = tmp & 0x7FF ;
	if(((tmp >> 10) & 1) == 1)
	{
		negNumber = 1;
		tmp = tmp & 0x3FF;
	}

	currentValue = (current_sensing_full_scale * ((float)tmp/saturation_code));

	if(negNumber == 1)
	{
		negNumber = 0 ;
		return -currentValue;
	}
	else
		return currentValue;

}

/**
* @brief This function set saturation_code used to calculate the current sensing value.
*
* * @param[in]  value (Choose one of these parameters according to the schema below and copy it into the 'saturation' field of the function):
*
*  where saturation value is choice according to the following schema.
*  saturation = 0.4375 Fs  if WS=44.1 kHz or 48 kHz and IB1[4,3]= '00'
*               0.500  Fs  if WS=44.1 kHz or 48 kHz and IB1[4,3]= '01'
* 	  	   	    0.5625 Fs  if WS=44.1 kHz or 48 kHz and IB1[4,3]= '10'
* 		   	    0.250  Fs  if WS=96  kHz
* 		   	    0.125  Fs  if WS=192 kHz
*/
void AEK_903D_SetSaturationCodeForCurrentSensing(float saturation)
{

	//saturation_code = (2^(11-1) * saturation).
	saturation_code = (1024 * saturation);
}

/**
 * @brief  This function disables the read of IBs and DBs registers in Play Sound function.
		   It is used when the samples to sound are generated mathematically and no provided by wave file
 *
 * @api
 */
void AEK_903D_DisableReadRegisterInPlayFunction()
{
	NO_READ_DB_AND_IB_REG_DURING_PLAY = 1;
}

/**
 * @brief  This function Enables the read of IBs and DBs registers in Play Sound function.
		   It is used when the samples to sound are provided by wave file
 *
 * @api
 */
void AEK_903D_EnabledReadRegisterInPlayFunction()
{
	NO_READ_DB_AND_IB_REG_DURING_PLAY = 0;
}

#endif
/** @} */

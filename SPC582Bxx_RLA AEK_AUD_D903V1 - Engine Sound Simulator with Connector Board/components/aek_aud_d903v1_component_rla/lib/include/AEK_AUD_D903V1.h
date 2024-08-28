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
* EVALUATION ONLY � NOT FOR USE IN PRODUCTION
*
*****************************************************************************/

/**
 * @file    AEK_AUD_D903V1.h
 * @brief   SPC5xx AEK_AUD_D903V1 header file.
 *
 * @addtogroup AEK_AUD_D903V1
 * @{
 */

#ifndef aek_903DDRV_H
#define aek_903DDRV_H



#include <AEK_AUD_D903V1_cfg.h>
#ifdef Allocation_Executed

#include <i2s_lld_cfg.h>
#include <i2c_lld_cfg.h>
#include "pit_lld_cfg.h"
#include "components.h"
#include <string.h>
#include <math.h>

typedef unsigned char boolean;

#define FDA903D_IB_ADDR_MIN		(uint8_t)0x00
#define FDA903D_IB_ADDR_MAX		(uint8_t)0x0E
#define FDA903D_DB_ADDR_MIN		(uint8_t)0x20
#define FDA903D_DB_ADDR_MAX		(uint8_t)0x26

/********** Instruction bytes (IB) addresses **********/
#define IB0			(uint8_t)0x00
#define IB1			(uint8_t)0x01
#define IB2			(uint8_t)0x02
#define IB3			(uint8_t)0x03
#define IB4			(uint8_t)0x04
#define IB5			(uint8_t)0x05
#define IB6			(uint8_t)0x06
#define IB7			(uint8_t)0x07
#define IB8			(uint8_t)0x08
#define IB9			(uint8_t)0x09
#define IB10		(uint8_t)0x0A
#define IB11		(uint8_t)0x0B
#define IB12		(uint8_t)0x0C
#define IB13		(uint8_t)0x0D
#define IB14		(uint8_t)0x0E
/*********** Data bytes (IB) addresses ***********/
#define DB0			(uint8_t)0x20
#define DB1         (uint8_t)0x21
#define DB2			(uint8_t)0x22
#define DB3			(uint8_t)0x23
#define DB4			(uint8_t)0x24
#define DB5     	(uint8_t)0x25
#define DB6  		(uint8_t)0x26

/******* Default configuration IB register *******/
#define IB0_DEFAULT			0x00    // Write on IBs enable, I2S standard, slot 0, Standard Voltage.
#define IB1_DEFAULT         0x00    // WS=44.1kHz, I2S PWM switching frequency = 308.7, PWM not dithered, PWM in phase.
#define IB2_DEFAULT         0x00    // Timing=90ms, Low Radiation OFF, Power Limitation OFF.
#define IB3_DEFAULT			0x30    // OVOD ON, IOD ON, OCOD OFF, no high-pass filter , noise gating disable, OpenLoad in Play OFF.
#define IB4_DEFAULT			0x00    // No information on CD DIAG pin.
#define IB5_DEFAULT     	0x00    // No information on CD DIAG pin.
#define IB6_DEFAULT         0x00    // Mute very fast, standard digital audio gain, standard gain.
#define IB7_DEFAULT         0x03	// Diagnostic ramp time NORMAL, Diagnostic Hold time NORMAL, current sensing data on I2S falling edge, Force I2Stest at'0' on other slots.
#define IB8_DEFAULT         0x86    // C0 Current sensing Full scale 8 A, PWM OFF, DC Diag OFF, high impedance configuration, start in MUTE.
#define IB9_DEFAULT         0x00    // Watch-dog for word select managing.
#define IB10_DEFAULT    	0x50    // Short load impedance threshold =0.75, open load impedance threshold = 25Ohm,  Output current Offset threshold = 0.5 A.
#define IB11_DEFAULT      	0x20    // Over Current 6 A, PWM Slope default configuration.
#define IB12_DEFAULT		0x08    // Standard thermal Warning.
#define IB13_DEFAULT		0x20    // Digital Mute enabled in PLAY when start analog mute without TW1 occurs.
#define IB14_DEFAULT   		0x09    // Feedback on LC filter, LC filter setting: 10 uH + 3.3 uF in Phase, first setup programmed: ready to work.


/******* Mask section *******/

/*IB0 Mask*/
#define IB0_WRITE_ON_IBS_ENABLE						(0x00 << 7)
#define IB0_WRITE_ON_IBS_DISABLE					(0x01 << 7)
/*___________________________________________________________*/
#define IB0_DIGITAL_INPUT_I2S_STANDARD				(0x00 << 5)
#define IB0_DIGITAL_INPUT_TDM_4_CHs					(0x01 << 5)
#define IB0_DIGITAL_INPUT_TDM_8_CHs					(0x02 << 5)
#define IB0_DIGITAL_INPUT_TDM_16_CHs				(0x03 << 5)
/*___________________________________________________________*/
#define IB0_SLOT_0_TDM_MODE_OR_I2S_MODE_RIGHT_CH	(0x00 << 1)
#define IB0_SLOT_1_TDM_MODE_OR_I2S_MODE_LEFT_CH		(0x01 << 1)
#define IB0_SLOT_2_TDM_MODE							(0x02 << 1)
#define IB0_SLOT_3_TDM_MODE							(0x03 << 1)
#define IB0_SLOT_4_TDM_8_16_MODE					(0x04 << 1)
#define IB0_SLOT_5_TDM_8_16_MODE					(0x05 << 1)
#define IB0_SLOT_6_TDM_8_16_MODE					(0x06 << 1)
#define IB0_SLOT_7_TDM_8_16_MODE					(0x07 << 1)
#define IB0_PSLOT_8_TDM_16_MODE						(0x08 << 1)
#define IB0_SLOT_9_TDM_16_MODE						(0x09 << 1)
#define IB0_SLOT_10_TDM_16_MODE						(0x0A << 1)
#define IB0_SLOT_11_TDM_16_MODE						(0x0B << 1)
#define IB0_SLOT_12_TDM_16_MODE						(0x0C << 1)
#define IB0_SLOT_13_TDM_16_ONLY						(0x0D << 1)
#define IB0_SLOT_14_TDM_16_ONLY						(0x0E << 1)
#define IB0_SLOT_15_TDM_16_ONLY						(0x0F << 1)
/*___________________________________________________________*/
#define IB0_STANDARD_VOLTAGE_MODE					(0x00 << 0)
#define IB0_LOW_VOLTAGE_MODE						(0x01 << 0)
/*IB1 Mask*/
#define IB1_FRAME_SYNC_WS_FREQ_44_1_kHz				(0x00 << 6)
#define IB1_FRAME_SYNC_WS_FREQ_48_kHz				(0x01 << 6)
#define IB1_FRAME_SYNC_WS_FREQ_96_kHz				(0x02 << 6)
#define IB1_FRAME_SYNC_WS_FREQ_192_kHz				(0x03 << 6)
/*___________________________________________________________*/
#define IB1_PWM_SWITCH_FREQ_308_7_336_384_384_kHz	(0x00 << 3)	// 308.7 (if ws = 44.1 kHz); 336 (48 kHz); 384(96 kHz and 192 kHz)
#define IB1_PWM_SWITCH_FREQ_352_8_384_384_384_kHz	(0x01 << 3)	// 352.8 (44.1 kHz); 384 (48 kHz); 384(96 kHz and 192 kHz)
#define IB1_PWM_SWITCH_FREQ_396_9_432_384_384_kHz	(0x02 << 3)	// 396.9 (44.1 kHz); 432 (48 kHz); 384(96 kHz and 192 kHz)
/*___________________________________________________________*/
#define IB1_PWM_AMPLIFIER_CLOCK_NOT_DITHERED		(0x00 << 2)
#define IB1_PWM_AMPLIFIER_CLOCK_DITHERED			(0x01 << 2)
/*___________________________________________________________*/
#define IB1_PWM_IN_PHASE							(0x00 << 0)
#define IB1_PWM_OUT_PHASE							(0x01 << 0)
/*IB2 Mask*/
#define IB2_DIAGSHORT2SUPPLY_90MS					(0x00 << 6)
#define IB2_DIAGSHORT2SUPPLY_70MS					(0x01 << 6)
#define IB2_DIAGSHORT2SUPPLY_45MS					(0x02 << 6)
#define IB2_DIAGSHORT2SUPPLY_20MS					(0x03 << 6)
/*___________________________________________________________*/
#define IB2_LOW_RADIATION_FUNCTION_OFF				(0x00 << 4)
#define IB2_LOW_RADIATION_FUNCTION_ON				(0x10 << 4)
/*___________________________________________________________*/
#define IB2_POWER_LIMITER_DISABLED					(0x00 << 0)
#define IB2_POWER_LIMITER_MAX_SCALE_15				(0x01 << 0)
#define IB2_POWER_LIMITER_MAX_SCALE_20				(0x02 << 0)
#define IB2_POWER_LIMITER_MAX_SCALE_25   			(0x03 << 0)
#define IB2_POWER_LIMITER_MAX_SCALE_30				(0x04 << 0)
#define IB2_POWER_LIMITER_MAX_SCALE_35				(0x05 << 0)
#define IB2_POWER_LIMITER_MAX_SCALE_40				(0x06 << 0)
#define IB2_POWER_LIMITER_MAX_SCALE_45				(0x07 << 0)
#define IB2_POWER_LIMITER_MAX_SCALE_50				(0x08 << 0)
#define IB2_POWER_LIMITER_MAX_SCALE_60				(0x09 << 0)
#define IB2_POWER_LIMITER_MAX_SCALE_70				(0x0A << 0)
#define IB2_POWER_LIMITER_MAX_SCALE_80				(0x0B << 0)
/*IB3 Mask*/
#define IB3_OUTPUT_VOLTAGE_OFFSET_DETECTOR_DISABLE	(0x00 << 5)
#define IB3_OUTPUT_VOLTAGE_OFFSET_DETECTOR_EN		(0x01 << 5)
/*___________________________________________________________*/
#define IB3_INPUT_OFFSET_DETECTOR_DISABLE			(0x00 << 4)
#define IB3_INPUT_OFFSET_DETECTOR_EN				(0x01 << 4)
/*___________________________________________________________*/
#define IB3_OUTPUT_CURRENT_OFFSET_DETECTOR_EN		(0x01 << 3)
#define IB3_OUTPUT_CURRENT_OFFSET_DETECTOR_DISABLE	(0x00 << 3)
/*___________________________________________________________*/
#define IB3_HI_PASS_DAC_ENABLED						(0x01 << 2)
#define IB3_HI_PASS_DAC_DISABLED					(0x00 << 2)
/*___________________________________________________________*/
#define IB3_NOISE_GATING_EN							(0x01 << 1)
#define IB3_NOISE_GATING_DISABLE					(0x00 << 1)
/*___________________________________________________________*/
#define IB3_OPENLOAD_PLAY_EN						(0x01 << 0)
#define IB3_OPENLOAD_PLAY_DISABLE					(0x00 << 0)
/*IB4 Mask*/
#define IB4_NO_OUTPUT_VOLTAGE_OFFSET_INFO_ON_CDDIAG (0x00 << 7)
#define IB4_OUTPUT_VOLTAGE_OFFSET_INFO_ON_CDDIAG	(0x01 << 7)
/*___________________________________________________________*/
#define IB4_NO_THERMAL_WARNING_ON_CDDIAG 			(0x00 << 4)
#define IB4_TW_LEVEL_1_INFO_ON_CDDIAG 				(0x01 << 4)
#define IB4_TW_LEVEL_2_INFO_ON_CDDIAG 				(0x02 << 4)
#define IB4_TW_LEVEL_3_INFO_ON_CDDIAG 				(0x03 << 4)
#define IB4_TW_LEVEL_4_INFO_ON_CDDIAG 				(0x04 << 4)
/*___________________________________________________________*/
#define IB4_NO_OVERCURRENT_INFO_ON_CDDIAG			(0x00 << 3)
#define IB4_OVERCURRENT_INFO_ON_CDDIAG				(0x01 << 3)
/*___________________________________________________________*/
#define IB4_NO_INPUT_OFFSET_INFO_ON_CDDIAG 			(0x00 << 2)
#define IB4_INPUT_OFFSET_INFO_ON_CDDIAG 			(0x01 << 2)
/*___________________________________________________________*/
#define IB4_NO_SHORT_TO_VCC_OR_GND_INFO_ON_CDDIAG 	(0x00 << 1)
#define IB4_SHORT_TO_VCC_OR_GND_INFO_ON_CDDIAG 		(0x01 << 1)
/*___________________________________________________________*/
#define IB4_NO_HIGH_VOLTAGE_MUTE_INFO_ON_CDDIAG 	(0x00 << 0)
#define IB4_HIGH_VOLTAGE_MUTE_INFO_ON_CDDIAG 		(0x01 << 0)
/*IB5 Mask*/
#define IB5_NO_UVLOVCC_INFO_ON_CDDIAG				(0x00 << 7)
#define IB5_UVLOVCC_INFO_ON_CDDIAG					(0x01 << 7)
/*___________________________________________________________*/
#define IB5_NO_THERMAL_SHUTDOWN_INFO_ON_CDDIAG	 	(0x00 << 6)
#define IB5_THERMAL_SHUTDOWN_INFO_ON_CDDIAG	 		(0x01 << 6)
/*___________________________________________________________*/
#define IB5_NO_CLIPPING_INFORMATION		 			(0x00 << 4)
#define IB5_PWM_PULSE_SKIPPING_DETECTOR 			(0x01 << 4)
/*IB6 Mask*/
#define IB6_VERY_FAST_MUTE_TIMING_SETUP				(0x00 << 6)
#define IB6_FAST_MUTE_TIMING_SETUP					(0x01 << 6)
#define IB6_SLOW_MUTE_TIMING_SETUP					(0x02 << 6)
#define IB6_VERY_SLOW_MUTE_TIMING_SETUP				(0x03 << 6)
/*___________________________________________________________*/
#define IB6_STANDARD_DIGITAL_AUDIO_GAIN				(0x00 << 5)
#define IB6_6DB_DIGITAL_AUDIO_GAIN			 		(0x01 << 5)
/*___________________________________________________________*/
#define IB6_STANDARD_GAIN 							(0x00 << 4)
#define IB6_LOW_GAIN 								(0x01 << 4)
/*IB7 Mask*/
#define IB7_DIAGNOSTIC_RAMP_TIME_NORMAL				(0x00 << 6)
#define IB7_DIAGNOSTIC_RAMP_TIME_x2					(0x01 << 6)
#define IB7_DIAGNOSTIC_RAMP_TIME_x4					(0x02 << 6)
#define IB7_DIAGNOSTIC_RAMP_TIME_x0_5				(0x03 << 6)
/*___________________________________________________________*/
#define IB7_DIAGNOSTIC_HOLD_TIME_NORMAL				(0x00 << 4)
#define IB7_DIAGNOSTIC_HOLD_TIME_x2					(0x01 << 4)
#define IB7_DIAGNOSTIC_HOLD_TIME_x4					(0x02 << 4)
#define IB7_DIAGNOSTIC_HOLD_TIME_x0_5				(0x03 << 4)
/*___________________________________________________________*/
#define IB7_DATA_OUT_ON_I2SCLK_FALLING_EDGE			(0x00 << 1)
#define IB7_DATA_OUT_ON_I2SCLK_RISING_EDGE 			(0x01 << 1)
/*___________________________________________________________*/
#define IB7_I2STEST_AT_ZERO_ON_OTHER_SLOTS			(0x00 << 0)
#define IB7_TRANSMITTER_IN_HiZ_STATE_OTHER_SLOTS	(0x01 << 0)
/*IB8 Mask*/
#define IB8_Imax1A									(0x00 << 6)
#define IB8_Imax2A									(0x01 << 6)
#define IB8_Imax4A									(0x02 << 6)
#define IB8_Imax8A									(0x03 << 6)
/*___________________________________________________________*/
#define IB8_PWM_OFF                                 (0x00 << 5)
#define IB8_PWM_ON									(0x01 << 5)
/*___________________________________________________________*/
#define IB8_DC_DIAG_DISABLE 						(0x00 << 4)
#define IB8_START_DIAG 								(0x01 << 4)
/*___________________________________________________________*/
#define IB8_HIGH_IMPEDENCE_CONFIG					(0x00 << 1)
#define IB8_CURRENT_SENSING_ENABLED					(0x03 << 1)
#define IB8_PWM_SYNCHRO_SIGNAL						(0x05 << 1)
/*___________________________________________________________*/
#define IB8_MUTE									(0x00 << 0)
#define IB8_PLAY									(0x01 << 0)
/*IB9 Mask*/
#define IB9_ENABLE_WATCH_DOG_FOR_WORDSELECT 		(0x00 << 4)
#define IB9_DISABLE_WATCH_DOG_FOR_WORDSELECT 		(0x01 << 4)
/*IB10 Mask*/
#define IB10_SHORT_LOAD_IMP_THRESOLD_075_Ohm		(0x00 << 7)
#define IB10_SHORT_LOAD_IMP_THRESOLD_05O_Ohm		(0x01 << 7)
/*___________________________________________________________*/
#define IB10_OPEN_LOAD_IMP_THRESOLD_25_Ohm			(0x00 << 6)
#define IB10_OPEN_LOAD_IMP_THRESOLD_15_0hm			(0x01 << 6)
/*___________________________________________________________*/
#define IB10_CURRENT_OFFSET_025A					(0x01 << 3)
#define IB10_CURRENT_OFFSET_05A						(0x02 << 3)
#define IB10_CURRENT_OFFSET_1A						(0x03 << 3)
/*IB11 Mask*/
#define IB11_OVER_CURRENT_PROTECTION_11A 			(0x00 << 4)
#define IB11_OVER_CURRENT_PROTECTION_8A				(0x01 << 4)
#define IB11_OVER_CURRENT_PROTECTION_6A				(0x02 << 4)
#define IB11_OVER_CURRENT_PROTECTION_4A				(0x03 << 4)
/*___________________________________________________________*/
#define IB11_PWM_DEFAULT							(0x00 << 3)
#define IB11_PWM_SLOW_SLOPE							(0x01 << 3)
/*IB12 Mask*/
#define IB12_STANDART_THERMAL_WARNING				(0x00 << 7)
#define IB12_THERMAL_WARNING_SHIFT					(0x01 << 7)
/*IB13 Mask*/
#define IB13_DIGITAL_MUTE_IN_PLAY_EN				(0x00 << 6)
#define IB13_DIGITAL_MUTE_IN_PLAY_DISABLE			(0x01 << 6)
/*IB14 Mask*/
#define IB14_SET_FEEDBACK_LC_FILTER					(0x00 << 4)
#define IB14_SET_FEEDBACK_OUT_PIN					(0x01 << 4)
/*___________________________________________________________*/
#define IB14_LC_FILTER_1_OUTPHASE					(0x01 << 1)
#define IB14_LC_FILTER_1_INPHASE					(0x02 << 1)
#define IB14_LC_FILTER_2_OUTPHASE					(0x03 << 1)
#define IB14_LC_FILTER_2_INPHASE					(0x04 << 1)
#define IB14_LC_FILTER_3_OUTPHASE					(0x05 << 1)
#define IB14_LC_FILTER_3_INPHASE					(0x06 << 1)
/*___________________________________________________________*/
#define IB14_SET_FDA_NOT_PROGRAMMED_VIA_I2C 		(0x00 << 0)
#define IB14_SET_FDA_PROGRAMMED_VIA_I2C				(0x01 << 0)

/*DB0 Mask*/
#define DB0_INPUT_OFFSET							(0x01 << 7)
#define DB0_OUTPUT_CURRENT_VALID					(0x01 << 6)
#define DB0_OUTPUT_CURRENT_OFFSET					(0x01 << 5)
#define DB0_OUTPUT_VOLTAGE_OFFSET 					(0x01 << 3)
#define DB0_OPENLOAD_ENDED         					(0x01 << 2)
#define DB0_OPENLOAD_VALID          				(0x01 << 1)
#define DB0_OPENLOAD                				(0x01 << 0)
/*DB1 Mask*/
#define DB1_THERMAL_WARNING_1						(0x01 << 7)
#define DB1_THERMAL_WARNING_2						(0x01 << 6)
#define DB1_THERMAL_WARNING_3						(0x01 << 5)
#define DB1_THERMAL_WARNING_4						(0x01 << 4)
#define DB1_UVLOALL									(0x01 << 2)
#define DB1_OVERVOLTAGE  							(0x01 << 1)
#define DB1_PWM_PULSE_SKIPPING						(0x01 << 0)
/*DB2 Mask*/
#define DB2_DC_DIAGNOSTIC_ENDED 					(0x01 << 7)
#define DB2_DC_DIAGNOSTIC_VALID	 					(0x01 << 6)
#define DB2_OVERCURRENT     						(0x01 << 5)
#define DB2_DC_SHORTLOAD							(0x01 << 4)
#define DB2_SHORT_TO_VCC 							(0x01 << 3)
#define DB2_SHORT_TO_GND 							(0x01 << 2)
#define DB2_DC_OPENLOAD								(0x01 << 1)
#define DB2_CHANNEL_PLAY            				(0x01 << 0)
#define DB2_CHANNEL_MUTE							(0x00 << 0)
/*DB6 Mask*/
#define DB6_UNDERVOLTAGE 							(0x01 << 6)
#define DB6_THERMSHUTDOWN 							(0x01 << 5)

/**
 * @brief	Type of a structure in which each bit represents a fault/not fault condition.
 */
typedef union fda_errors_t {
	vuint16_t R;
    struct {
        volatile uint32_t OPENLOAD_DC:1;
        volatile uint32_t SHORT2GND:1;
        volatile uint32_t SHORT2VCC:1;
        volatile uint32_t SHORTLOAD_DC:1;
        volatile uint32_t OPENLOAD_IN_PLAY_TEST_IS_VALID:1;     // solo per la fase di test. Voglio vede se il segnale e' valido
        volatile uint32_t OPENLOAD_PLAY:1;
        volatile uint32_t UNDERVOLTAGE:1;
        volatile uint32_t OVERVOLTAGE:1;
        volatile uint32_t OVERTEMPERATURE:1;
        volatile uint32_t INPUTOFFSET:1;
        volatile uint32_t OUTPUTOFFSET:1;
        volatile uint32_t CURR_OUT_OFF_TEST_VALID:1;    // solo per la fase di test. Voglio vede se il TEST e' valido
        volatile uint32_t CURRENTOFFSET:1;
        volatile uint32_t CLIPPING:1;
        volatile uint32_t OVERCURRENT:1;
        volatile uint32_t empty0:1;
        volatile uint32_t empty1:1;
        volatile uint32_t empty2:1;
	}B;
} FDA_Errors_t;

extern FDA_Errors_t FDA903_Errors[AUD_LIST_ELEMENT];
extern uint8_t FDA903D_Status_DB[AUD_LIST_ELEMENT][FDA903D_DB_ADDR_MAX - FDA903D_DB_ADDR_MIN + 1];
extern uint8_t FDA903D_Status_IB[AUD_LIST_ELEMENT][FDA903D_IB_ADDR_MAX - FDA903D_IB_ADDR_MIN + 1];


/**
 * @brief Type of a structure representing the possible audio amplifier working states.
 */
typedef enum
{
	ECO_MODE = 1, 				/**< @brief   State Eco-Mode*/
	MUTE = 2,           		/**< @brief   State Mute */
    PLAY = 3,            		/**< @brief   State Play */
    DIAG_DC = 4,     			/**< @brief   State DC Diagnostic */
	PLAY_NO_READ_REGISTER = 5 	/**< @brief   State Play but the register DB and IB are not read and update in a play sound function */
} FDA_State_t;

/**
 * 	@brief	Type of a structure in which the value contained in currentSensingBuffer appropriately manipulated provide
 * 	 		the Current sensing Value.
 *			The fist element of the array represent the value retrieved by the right channel while
 *			the second the value retrieved by the channel left and so on.
 */
typedef struct currentSensingElement
{
	uint16_t arrayLenght;
	uint16_t currentSensBuffer[252];
} CurrentSensingElement;

extern CurrentSensingElement FDA903_CurrentSensingBuff[1];
extern uint8_t NO_READ_DB_AND_IB_REG_DURING_PLAY;
/*******************************************************************************
***************************** Function definition ******************************
*******************************************************************************/
i2c_result_t AEK_903D_Read_All_DB(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_Read_All_IB(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_Write_IB(AEK_AUD_D903V1_DEVICE dev, uint8_t reg_addr, uint8_t * data, uint8_t size);
i2c_result_t AEK_903D_Read_IB(AEK_AUD_D903V1_DEVICE dev, uint8_t reg_addr, uint8_t * data, uint8_t size);
i2c_result_t AEK_903D_Read_DB(AEK_AUD_D903V1_DEVICE dev, uint8_t reg_addr, uint8_t * data, uint8_t size);
i2c_result_t AEK_903D_SetDefaultRegisters(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_Init(AEK_AUD_D903V1_DEVICE DEV);
i2c_result_t AEK_903D_EnableWritingOnIBs(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_DisableWritingOnIBs(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_SetInputDataFormats(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_SelectChannelPosition(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_SetVoltageMode(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_SetI2SWordSelect(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_SetPWMSwitchingFrequency(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_SetPwmAplifierDithered(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_SetPwmAplifierNotDithered(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_SetPwmInPhase(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_SetPwmOutOfPhase(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_SetDiagShort2SupplyTiming(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_DisableLowRadiationFunction(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_EnableLowRadiationFunction(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_ConfigurePowerLimit(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_DisableOutputVoltageOffsetDetector(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_EnableOutputVoltageOffsetDetector(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_DisableInputOffsetDetector(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_EnableInputOffsetDetector(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_DisableOutputOffsetCurrentDetector(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_TriggerOutputOffsetCurrentDetector(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_DisableHighPassInDAC(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_EnableHighPassInDAC(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_DisableNoiseGating(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_EnableNoiseGating(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_DisableOpenLoadInPlayDetection(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_TriggerOpenLoadInPlayDetection(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_EnableOutputVoltageOffsetInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_DisableOutputVoltageOffsetInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_ConfigureThermalWarningInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_EnableOvercurrentInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_DisableOvercurrentInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_EnableInputOffsetInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_DisableInputOffsetInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_EnableShortToVccOrGndInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_DisableShortToVccOrGndInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_EnableHighVoltageMuteInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_DisableHighVoltageMuteInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_EnableUvlovccInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_DisableUvlovccInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_EnableThermalShutdownInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_DisableThermalShutdownInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_EnablePwmPulseSkippingInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_DisablePwmPulseSkippingInfoOnCDDIAG(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_SelectMuteTimingsetup(AEK_AUD_D903V1_DEVICE dev,uint8_t value);
i2c_result_t AEK_903D_SelectAudioSignalGainControl(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_SelectGainSetting(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_SelectDiagnosticRampTime(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_SelectDiagnosticHoldTime(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_SelectCurrentSensingCommunication(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_SelectCurrentSensingProtocolConfiguration(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_SetCurrentSensingFullScale(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_SetChannelWithPWMoff(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_SetChannelWithPWMon(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_Eco_Mode(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_StartDCDiag(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_DisableDCDiag(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_I2TestPinConfiguration(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_Play(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_Mute(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_EnableWatchDogForWordSelect(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_DisableWatchDogForWordSelect(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_SetShortLoadImpedanceThreshold(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_SetOpenLoadImpedanceThreshold(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_SetCurrentOffsetThreshold(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_SelectOverCurrentProtectionLevel(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_SetSlowSlopePWMConfiguration(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_SetDefaultPWMConfiguration(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_SetThermalWarning(AEK_AUD_D903V1_DEVICE dev,uint8_t value);
i2c_result_t AEK_903D_EnableDigitalMuteInPlayForTW1(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_DisableDigitalMuteInPlayForTW1(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_SetFeedbackOnLCfilter(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_SetFeedbackOnOutPin(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_SetupLCFilter(AEK_AUD_D903V1_DEVICE dev, uint8_t value);
i2c_result_t AEK_903D_Enable903ToBeProgramViaI2C(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_Disable903ToBeProgramViaI2C(AEK_AUD_D903V1_DEVICE dev);
void AEK_903D_CheckOffsetCurrent(AEK_AUD_D903V1_DEVICE dev);
void AEK_903D_CheckInputOffsetDetector(AEK_AUD_D903V1_DEVICE dev);
void AEK_903D_CheckOutputVoltageOffsetDetector(AEK_AUD_D903V1_DEVICE dev);
void AEK_903D_CheckDCDiagnostic(AEK_AUD_D903V1_DEVICE dev, boolean runDCDiag);
void AEK_903D_Diagnostic(AEK_AUD_D903V1_DEVICE dev);
void AEK_903D_SetEnables(AEK_AUD_D903V1_DEVICE dev);
i2c_result_t AEK_903D_I2C_Init(AEK_AUD_D903V1_DEVICE dev);
void AEK_903D_I2S_Init(AEK_AUD_D903V1_DEVICE dev);
void AEK_903D_CheckOpenLoadInPlayDetection(AEK_AUD_D903V1_DEVICE dev);
void AEK_903D_UpdateCurrentSensingBuffer(void);
float AEK_903D_GetCurrentSensingValue(AEK_AUD_D903V1_DEVICE dev);
void AEK_903D_EnabledReadRegisterInPlayFunction(void);
void AEK_903D_DisableReadRegisterInPlayFunction(void);
void AEK_903D_SetSaturationCodeForCurrentSensing(float saturation);
#endif
#endif
/** @} */

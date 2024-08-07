/****************************************************************************
*
* Copyright � 2015-2019 STMicroelectronics - All Rights Reserved
*
* License terms: STMicroelectronics Proprietary in accordance with licensing
* terms SLA0098 at www.st.com.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* EVALUATION ONLY � NOT FOR USE IN PRODUCTION
*****************************************************************************/


/* Inclusion of the main header files of all the imported components in the
   order specified in the application wizard. The file is generated
   automatically.*/

#include "components.h"
#include "sound.h"
#include "AEK_AUD_D903V1.h"
#include "saradc_lld_cfg.h"
#include "can_lld_cfg.h"

/* Define application states*/
#define STOP		0U     // STOP =
#define START 		1U

/* Define LED error */
#define ERROR_BOARD0_TURN_ON_LED()     	siul_lld_setpad(PORT_LED_4, LED_4)
#define ERROR_BOARD1_LED_TOGGLE()     	siul_lld_setpad(PORT_LED_3, LED_3)

/* DISTRIBUTED_AVAS_SYSTEM = FALSE for use AVAS-System alone
 * DISTRIBUTED_AVAS_SYSTEM = TRUE for using AVAS-System connected to main ECU (e.g. Chorus 4M)*/
#define DISTRIBUTED_AVAS_SYSTEM   TRUE

#if DISTRIBUTED_AVAS_SYSTEM == TRUE
#define FAULT_OPEN_LOAD_PLAY 0x1A1B1C1DUL
#define FAULT_OPEN_LOAD_MUTE 0x2A2B2C2DUL
#define NO_FAULT_PLAY 0x3A3B3C3DUL
#define NO_FAULT_MUTE 0x4A4B4C4DUL
#endif
/************************ variables section ************************/
extern uint32_t* engine_start1;

boolean acc_first_time = TRUE;
int16_t* wavfileBeginPtr;   //pointer to wave file data (the first data)
int16_t* wavfileEndPtr;     //pointer to wave file data (the last data)
int16_t* wavfilePtr;		//pointer to wave file data (current wave file header)

uint8_t vol = 1;			//there exists a volume threshold under which the Open Load in Play Detection Test is not valid.
							//Thus, if you perform this Test, you have to increase the volume until you overcome this threshold.

uint32_t rpm1 = 800;

int16_t j=0; // j identifies when the algorithm implemented have to skip some samples in order to simulate the engine acceleration/deceleration

uint8_t channel_1 = 55;
uint8_t channel_2 = 82;
uint16_t value_ch_1 = 0U;
uint16_t value_ch_2 = 0U;
SARADCDriver* sarAdc    = &SARADC12DSV;

uint32_t state = 0;
uint8_t avasFault = 0; // no fault.


/*********************** end variables section ***********************/


/************************ Function definition ************************/
uint32_t userFunction(void);
uint32_t muteSamples(void);
void saradcconf_adc_callback(SARADCDriver* saradcp);
void readADC(void);
void detectVolumeRange(void);
void detectRpmRange(void);
void DiagnosticInPlay(void);
void DiagnosticInMute(void);
void LoadStatusDetectionInMute(void);
void LoadStatusDetectionInPlay(void);
/*********************************************************************/

#if (DISTRIBUTED_AVAS_SYSTEM == TRUE)
uint32_t sendCanMessage(uint32_t message)
{
	 CANTxFrame txf;

	 /* prepare frame to be transmitted on MCAN SUB 0 CAN 1*/
	 txf.TYPE = CAN_ID_STD;
	 txf.ID = 0x7f0U;
	 txf.DLC = 8U;
	 txf.data32[0] = message;  // STOP

	 return can_lld_transmit(&CAND4, CAN_ANY_TXBUFFER, &txf);
}
#endif

/**
 * @brief	Aim of this function is to switch the application status between START/STOP engine
 */
void key_press(void)
{
	if (state == STOP)
	{
		state = START;
	}
	else if (state == START)
	{
		state = STOP;
	}
}

/*receive CAN callback */
void mcanconf_rxreceive(uint32_t msgbuf, CANRxFrame crfp)
{
	(void)msgbuf;

	if (crfp.ID == 0x7f0U)
	{
		if (crfp.data32[0] == 0xAABBCCDDUL) //START
		{
			state = START;
		}
		else
		{
			state = STOP;
		}
	}

}

void mcanconf_errorcb(CANDriver *canp, uint32_t psr){
  /* write error management code here */
  (void)canp;
  (void)psr;
}

/**
 * @brief	Aim of this function is to read the actual value coming from volume and rpm channels
 */
void saradcconf_adc_callback(SARADCDriver *saradcp)
{
	value_ch_1 = saradc_lld_readchannel(saradcp, channel_1);
	value_ch_2 = saradc_lld_readchannel(saradcp, channel_2);
}

/**
 * @brief	Aim of this function is to convert the actual value coming from volume and rpm trimmer each time it is invoked
 */
void readADC()
{
	int i;
	saradc_lld_start_conversion(sarAdc);
	for (i=0; i<10; i++)
	{

	}
	saradc_lld_stop_conversion(sarAdc);
}

/**
 * @brief	This function assigns to the volume a value from 0 to 10, depending on the value read by the ADC associated with the volume trimmer.
 */
void detectVolumeRange()
{
	if (value_ch_1 < 1727)  //100
	{
		vol = 0;
	}
	/************** VOLUME = 1 **************/
	if (value_ch_1 > 1757 && value_ch_1 < 1907)   // -150   -350
	{
		vol =  1;
	}
	/************** VOLUME = 2 **************/
	if (value_ch_1 > 1937 && value_ch_1 < 2087)     //-400  -600
	{
		vol =  2;
	}
	/************** VOLUME = 3 **************/
	if (value_ch_1 > 2117 && value_ch_1 < 2267)		//-650  -850
	{
		vol =  4;
	}
	/************** VOLUME = 4 **************/
	if (value_ch_1 > 2397 && value_ch_1 < 2447)		//-900  -1100
	{
		vol =  6;
	}
	/************** VOLUME = 5 **************/
	if (value_ch_1 > 2477 && value_ch_1 < 2627)		//-1150		-1350
	{
		vol =  8;
	}
	/************** VOLUME = 6 **************/
	if (value_ch_1 > 2657 && value_ch_1 < 2807)		//-1400		-1600
	{
		vol =  10;
	}
	/************** VOLUME = 7 **************/
	if (value_ch_1 > 2837 && value_ch_1 < 2987)		//-1650		-1850
	{
		vol =  12;
	}
	/************** VOLUME = 8 **************/
	if (value_ch_1 > 3017 && value_ch_1 < 3167)		//-1900		-2100
	{
		vol =  14;
	}
	/************** VOLUME = 9 **************/
	if (value_ch_1 > 3197 && value_ch_1 < 3347)
	{
		vol =  16;
	}
	/************** VOLUME = 10 **************/
	if (value_ch_1 > 3377 && value_ch_1 < 3527)
	{
		vol =  18;
	}
	/************** VOLUME = 10 **************/
	if (value_ch_1 > 3557 && value_ch_1 < 3707)
	{
		vol =  25;
	}
	/************** VOLUME = 11 **************/
	if (value_ch_1 > 3737)
	{
		vol =  28;
	}
}

/**
 * @brief	This function assigns an rpm value from 800 to 3500, depending on the value read by the ADC associated with the rpm trimmer.
 */
void detectRpmRange()
{
	if (value_ch_2 < 1743)	//100
	{
		rpm1 = 800;
	}

	else if (value_ch_2 > 1765 && value_ch_2 < 1825) //	-150	-250 || 1765   1825
	{
		rpm1 = 900;
	}

	else if (value_ch_2 > 1840 && value_ch_2 < 1900) 	//	-300	-400 || 1840 1900
	{
		rpm1 = 1000;
	}

	else if (value_ch_2 > 1915 && value_ch_2 < 1975)	//	-450	-550
	{
		rpm1 = 1100;
	}

	else if (value_ch_2 > 1990 && value_ch_2 < 2050)	//	-600	700
	{
		rpm1 = 1200;
	}

	else if (value_ch_2 > 2065 && value_ch_2 < 2105)	//	-750	-850
	{
		rpm1 = 1300;
	}

	else if (value_ch_2 > 2120 && value_ch_2 < 2180)	//	-900	-1000
	{
		rpm1 = 1400;
	}

	else if (value_ch_2 > 2195 && value_ch_2 < 2255)	//	-1050	-1150
	{
		rpm1 = 1500;
	}

	else if (value_ch_2 > 2270 && value_ch_2 < 2330)	//	-1200	-1300
	{
		rpm1 = 1600;
	}

	else if (value_ch_2 > 2345 && value_ch_2 < 2405)	//	-1350	-1450
	{
		rpm1 = 1700;
	}

	else if (value_ch_2 > 2420 && value_ch_2 < 2480)	//	-1500	-1600
	{
		rpm1 = 1800;
	}

	else if (value_ch_2 > 2495 && value_ch_2 < 2555)	//	-1650	-1750
	{
		rpm1 = 1900;
	}

	else if (value_ch_2 > 2570 && value_ch_2 < 2630)	//	-1800	-1900
	{
		rpm1 = 2000;
	}

	else if (value_ch_2 > 2645 && value_ch_2 < 2705)	//	-1950	-2050
	{
		rpm1 = 2100;
	}

	else if (value_ch_2 > 2720 && value_ch_2 < 2780)	//	-2100	-2200
	{
		rpm1 = 2200;
	}

	else if (value_ch_2 > 2795 && value_ch_2 < 2855)	//	-2250	-2350
	{
		rpm1 = 2300;
	}

	else if (value_ch_2 > 2870 && value_ch_2 < 2930)	//	-2400	-2500
	{
		rpm1 = 2400;
	}

	else if (value_ch_2 > 2945 && value_ch_2 < 3005)	//	-2550	-2650
	{
		rpm1 = 2500;
	}

	else if (value_ch_2 > 3020 && value_ch_2 < 3080)	//	-2700	-2800
	{
		rpm1 = 2600;
	}

	else if (value_ch_2 > 3095 && value_ch_2 < 3155)	//	-2850	-2950
	{
		rpm1 = 2700;
	}

	else if (value_ch_2 > 3170 && value_ch_2 < 3230)	//	-3000	-3100
	{
		rpm1 = 2800;
	}

	else if (value_ch_2 > 3245 && value_ch_2 < 3305)	//	-3150	-3250
	{
		rpm1 = 2900;
	}

	else if (value_ch_2 > 3320 && value_ch_2 < 3380)	//	-3300	-3400
	{
		rpm1 = 3000;
	}

	else if (value_ch_2 > 3395 && value_ch_2 < 3455)	//	-3450	-3550
	{
		rpm1 = 3100;
	}

	else if (value_ch_2 > 3470 && value_ch_2 < 3530)	//	-3600	-3700
	{
		rpm1 = 3200;
	}

	else if (value_ch_2 > 3545 && value_ch_2 < 3605)	//	-3750	-3850
	{
	rpm1 = 3300;
	}

	else if (value_ch_2 > 3620)	//-3900
	{
		rpm1 = 3400;
	}
}

/**
 * @brief	This function provides mute samples.
 */
uint32_t muteSamples()
{
	return 0;
}

/**
 * @brief	This function provides samples to play. Depending by the rpm detected, it skips some samples in order to simulate the engine acceleration/deceleration
 */
uint32_t userFunction()
{
	// Identify the pointer to the start and the end of the wave file, using the api functions "getStartWavFile" and "getEndWaveFile"
	if(acc_first_time)
	{
		wavfilePtr = wavfileBeginPtr = getStartWavFile(0);
		wavfileEndPtr = getEndWavFile(0);
		acc_first_time = false;
	}

	if(wavfilePtr > wavfileEndPtr)
	{
		wavfilePtr =  wavfileBeginPtr + 90000;
	}

	int32_t amplitude = 0;
	uint16_t sampleWav;
	sampleWav = ( *wavfilePtr << 8) | ((*wavfilePtr >> 8) & 0xFF);       //row data sample, change endian
	amplitude = (int32_t)sampleWav;

	if (rpm1 <= 2200)
	{
		if(rpm1 == 900)
		{
			if( j  < 23 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 1000)
		{
			if( j  < 20 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 1100)
		{
			if( j  < 17 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 1200)
		{
			if( j  < 14 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 1300)
		{
			if( j  < 11 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 1400)
		{
			if( j  <  9 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 1500)
		{
			if( j  < 8 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 1600)
		{
			if( j  < 13 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 1700)
		{
			if( j  < 12 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 1800)
		{
			if( j  < 11 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 1900)
		{
			if( j  < 10 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 2000)
		{
			if( j  < 14 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 2100)
		{
			if( j  < 13 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 2200)
		{
			if( j  < 12)
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}
		else //800 rpm
		{
			wavfilePtr++;
		}
	}
	else
	{
		if(rpm1 == 2300)
		{
			if( j  < 15 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 2400)
		{
			if( j  < 14 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 2500)
		{
			if( j  < 13 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 2600)
		{
			if( j  < 16 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 2700)
		{
			if( j  < 15 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 2800)
		{
			if( j  < 14 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 2900)
		{
			if( j  < 13 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 3000)
		{
			if( j  < 15 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 3100)
		{
			if( j  < 14 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 3200)
		{
			if( j  < 13 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 3300)
		{
			if( j  < 12 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}

		else if(rpm1 == 3400)
		{
			if( j  < 11 )
			{
				wavfilePtr++;
			}
			else
			{
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				wavfilePtr++;
				j = 0;
			}
		}
	}
j++;
	return amplitude;
}

/**
 * @brief	This function enables The Diagnostic in Play and Checks if some fault conditions occurs
 */
void DiagnosticInPlay()
{
	  /**************** OLPD ****************/
	  AEK_903D_TriggerOpenLoadInPlayDetection(AEK_AUD_D903V1_DEV0);
	  AEK_903D_CheckOpenLoadInPlayDetection(AEK_AUD_D903V1_DEV0);
	  /**************************************/

	  /**************** OVOD ****************/
	  AEK_903D_CheckOutputVoltageOffsetDetector(AEK_AUD_D903V1_DEV0);
	  /**************************************/

	  /**************** OCOD ****************/
	  AEK_903D_TriggerOutputOffsetCurrentDetector(AEK_AUD_D903V1_DEV0);
	  AEK_903D_CheckOffsetCurrent(AEK_AUD_D903V1_DEV0);
	  /**************************************/

	  /***************** IOD ****************/
	  AEK_903D_CheckInputOffsetDetector(AEK_AUD_D903V1_DEV0);
	  /**************************************/

	  AEK_903D_Diagnostic(AEK_AUD_D903V1_DEV0);
}

/**
 * @brief	This function enables The Diagnostic in Mute and Checks if some fault conditions occurs
 */
void DiagnosticInMute()
{
	  AEK_903D_Mute(AEK_AUD_D903V1_DEV0);

	  AEK_903D_StartDCDiag(AEK_AUD_D903V1_DEV0);

	  AEK_903D_CheckDCDiagnostic(AEK_AUD_D903V1_DEV0, 0);

	  AEK_903D_Diagnostic(AEK_AUD_D903V1_DEV0);
}

/**
 * @brief	This function reports the load status in Mute. Led ON for Open Load. Led OFF for Normal Load.
 */
void LoadStatusDetectionInMute()
{
	if ( FDA903_Errors[AEK_AUD_D903V1_DEV0].B.OPENLOAD_DC == 1)
	{
		ERROR_BOARD0_TURN_ON_LED();
		if(avasFault != 1)
		{
			avasFault = 1;
			#if (DISTRIBUTED_AVAS_SYSTEM == TRUE)
			sendCanMessage(FAULT_OPEN_LOAD_MUTE);
			#endif
		}
	}
	else
	{
		if(avasFault == 1)
		{
			siul_lld_clearpad(PORT_LED_4, LED_4);
			avasFault = 0;
			#if (DISTRIBUTED_AVAS_SYSTEM == TRUE)
			 sendCanMessage(NO_FAULT_MUTE);
			#endif
		}
	}
}

/**
 * @brief	This function reports the load status in Play. Led ON for Open Load. Led OFF for Normal Load.
 */
void LoadStatusDetectionInPlay()
{
	if ( FDA903_Errors[AEK_AUD_D903V1_DEV0].B.OPENLOAD_IN_PLAY_TEST_IS_VALID == 1 && FDA903_Errors[AEK_AUD_D903V1_DEV0].B.OPENLOAD_PLAY == 1)
	{
		ERROR_BOARD0_TURN_ON_LED();
		if(avasFault != 1)
		{
			avasFault = 1;
			#if (DISTRIBUTED_AVAS_SYSTEM == TRUE)
			sendCanMessage(FAULT_OPEN_LOAD_PLAY);
			#endif
		}
	}
	else
	{
		if(avasFault == 1)
		{
			siul_lld_clearpad(PORT_LED_4, LED_4);
			avasFault = 0;
			#if (DISTRIBUTED_AVAS_SYSTEM == TRUE)
			 sendCanMessage(NO_FAULT_PLAY);
			#endif
		}
	}
}

/* ************************************************************************************************************** */
/* *********************************************** MAIN FUNCTION ************************************************ */
/* ************************************************************************************************************** */
/*
 * @brief Application entry point. The application simulates: the start/stop , acceleration /deceleration  and real time diagnostic of car engine
 */
int main(void)
{
//	 CANTxFrame txf;

  /* Initialization of all the imported components in the order specified in
     the application wizard. The function is generated automatically.*/
  componentsInit();

  irqIsrEnable();

  initWaveFile(&engine_start1, 6);

  AEK_903D_Init(AEK_AUD_D903V1_DEV0);

  AEK_903D_SetDefaultRegisters(AEK_AUD_D903V1_DEV0);

  AEK_903D_Play(AEK_AUD_D903V1_DEV0);

  //Disable hardware Mute.
  pal_lld_setpad(PORT_PIN_AEK_AUD_D903V1Board0_J10_MUTE_MUTE_GPIO33,PIN_AEK_AUD_D903V1Board0_J10_MUTE_MUTE_GPIO33);
  
  saradc_lld_start(sarAdc, &saradc_config_saradcconf);

  can_lld_start(&CAND4, &can_config_mcanconf); /*MCAN SUB  0 CAN 1*/

  /* Application main loop.*/
  for ( ; ; )
    {

	  switch (state)
	      	{
				case STOP:
				acc_first_time = true;
				AEK_903D_Mute(AEK_AUD_D903V1_DEV0);
				while (state == STOP)
				{
					playSound(vol, muteSamples);
					DiagnosticInMute();
					LoadStatusDetectionInMute();
				}
				break;

				case START:
				AEK_903D_Play(AEK_AUD_D903V1_DEV0);
				while (state == START)
				{
					playSound(vol, userFunction);
					DiagnosticInPlay();
					LoadStatusDetectionInPlay();
					detectVolumeRange();
					detectRpmRange();
					readADC();
				}
	      	}
    }
}

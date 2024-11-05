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
 * @file    sound.c
 * @brief   sound library for AEK-AUD-D903V1.
 *
 * @addtogroup AEK_AUD_D903V1
 * @{
 */

#include "sound.h"
#include "math.h"

#ifdef Allocation_Executed

/*******************************************************************************
 ********************************** Variables **********************************
 *******************************************************************************/

size_t i =0;

sound_db_t sound_db[DIM] ;

uint32_t sample = 0;

uint8_t devNumberStereo = 0;

/*******************************************************************************
 ********************************** Functions ***********************************
 *******************************************************************************/

/**
 * @brief   	This function initializes the sound_db structure defined in the sounddb.s file.
 *
 * @param[in]   startfile : start file address.
 *
 * @param[in]   dim: number of files
 *
 * @api
 */
void initWaveFile(uint32_t**  startfile, uint8_t dim)
{
	uint8_t i;
	char * str = "Engine_";

	for (i=0; i < dim;  i++)
	{
		sound_db[i].name 		= str;
		sound_db[i].start 		=  startfile;
		sound_db[i].end 		=  startfile;
		sound_db[i].half 		=  startfile;
	}
	checkWavFile(((waveHeaderType*)sound_db->start), (uint8_t)dim);
}

/**
 * @brief   	This function returns the start address of the wave file.
 *
 * @param[in]   WaveFileNumber number belonging to the range [0 n-1] where n is the number of wafe file loaded in flash.
 * 				for default N = DIM = 10;
 *
 * @return   	(*void) pointer to start wave file
 *
 * @api
 */
void* getStartWavFile(int WaveFileNumber)
{
	return sound_db[WaveFileNumber].start;
}

/**
 * @brief   	This function returns the half address of the wave file.
 *
 * @param[in]   WaveFileNumber number belonging to the range [0 n-1] where n is the number of wafe file loaded in flash.
 * 				for default N = DIM = 10;
 *
 * @return   	(*void) pointer to half wave file
 *
 * @api
 */
void* getHalfWavFile(int WaveFileNumber)
{
	return sound_db[WaveFileNumber].half;
}

/**
 * @brief   	This function returns the end address of the wave file.
 *
 * @param[in]   WaveFileNumber number belonging to the range [0 n-1] where n is the number of wafe file loaded in flash.
 * 				for default N = DIM = 10;
 *
 * @return   	(*void) pointer to end wave file
 *
 * @api
 */
void* getEndWavFile(int WaveFileNumber)
{
	return sound_db[WaveFileNumber].end;
}

/**
 * @brief   	This function swaps the bits order. From litte(big) endian to big(little) endian
 *
 * @param[in]   32 bit data in little (big) endian to swap.
 *
 * @return   	32 bit swapped data in big (little) endian.
 *
 * @api
 */
uint32_t swapEndian32(uint32_t data)
{
    uint32_t ret = data>>24;
    ret |= (data>>8) & 0x0000FF00;
    ret |= (data<<8) & 0x00FF0000;
    ret |= data << 24;
    return ret;
}

/**
 * @brief   	This function validates the WAV file by checking the WAV file descriptor parameters
 *
 * @param[in]   whPtr - pointer to WAV file.
 *
 * @return   	error code. 0 = OK, bitfield of errors during wav file parsing
 *
 * @api
 */
uint32_t validate_wav_file(waveHeaderType* whPtr)
{
    uint32_t ret = 0;

    //check wav file format
    if (*(whPtr->riff) != 0x52)                 //'RIFF' text is mandatory here in wav file
	{
	   ret |= 1;
	}
	if ((whPtr->riff[3]) != 0x46)              //'RIFF' text is mandatory here in wav file
	{
		ret |= 1;
	}
    if (*(whPtr->wave) != 0x57)                //'WAVE' text is mandatory in here in wav file
	{
		ret |= 2;
	}
	if ((whPtr->wave[3]) != 0x45)               //'WAVE' text is mandatory in here in wav file
	{
		ret |= 2;
	}
	if (*(whPtr->fmt_chunk_marker) != 0x66 )   //'fmt ' text is mandatory in here in wav file
	{
		ret |= 4;
	}
	if ((whPtr->fmt_chunk_marker[3]) != 0x20 ) //'fmt ' text is mandatory in here in wav file
	{
	   ret |= 4;
	}
    if (whPtr->length_of_fmt != 0x10000000)                     //is mandatory in here in wav file
    {
        ret |= 8;
    }
    if (whPtr->format_type != 0x100)                           //is mandatory in here in wav file
    {
        ret |= 16;
    }
    if (whPtr->channels != 0x100 && whPtr->channels != 0x200) //0x0100-mono; 0x0200-stereo is mandatory in here in wav file
    {
        ret |= 32;
    }
    if (whPtr->sample_rate != 0x44ac0000)                       //sample rate 44100 is mandatory in here in wav file
    {
        ret |= 64;
    }
    if (whPtr->block_align != 0x200 && whPtr->block_align != 0x400)  //is mandatory in here in wav file
    {
        ret |= 256;
    }
    if (whPtr->bits_per_sample != 0x1000)                       //is mandatory in here in wav file
    {
        ret |= 512;
    }
    if (*(whPtr->data_chunk_header) != 0x64)   					//'data' text  is mandatory in here in wav file
	{
    	ret |= 1024;
	}
	if ((whPtr->data_chunk_header[3]) != 0x61)   				//'data' text  is mandatory in here in wav file
	{
		ret |= 1024;
	}

    return ret;
}

/**
 * @brief   	This function checks the WAV file and identifies the start, half and end of each WAV file removing the WAV file header
 *
 * @param[in]   whPtr: pointer to WAV file
 *
 * @param[in] 	fileNumber: Number of files
 *
 * @api
 */
void checkWavFile(waveHeaderType* whPtr, uint8_t fileNumber)
{
	 int i;

	   osalExitCritical();
	   for (i = 0; i< fileNumber; i++)
	   {
		    validate_wav_file(whPtr);
			if(i == 0)
			{
				sound_db[i].start = (int16_t*)((uint32_t)whPtr + sizeof(waveHeaderType));
				sound_db[i].half  =  sound_db[i].start + ((swapEndian32(whPtr->data_size)/2)-1);
				sound_db[i].end  = sound_db[i].start + (swapEndian32(whPtr->data_size)-1);
			}
			else
			{
				sound_db[i].start = (int16_t*)((uint32_t)(sound_db[i-1].end+1) + sizeof(waveHeaderType));
				whPtr = (waveHeaderType*)((int16_t*)((uint32_t)(sound_db[i-1].end+1)));
				sound_db[i].end = sound_db[i].start + (swapEndian32(whPtr->data_size)-1) ;
				sound_db[i].half  =  sound_db[i].start + ((swapEndian32(whPtr->data_size)/2)-1);
			}
		}

	    osalEnterCritical();
}

/**
 * @brief   	This function loads new data to transmit buffer
 *
 * @param[in]   sample: data to transmit
 *
 * @param[in]   *dst: destination
 *
 * @api
 */
static inline void load_channel_data(uint32_t sample, uint8_t *dst)
{
  uint8_t *p = (uint8_t*)&sample;

  *dst++ = *p++;
  *dst++ = *p++;
  *dst++ = *p++;
  *dst   = *p;
}

/**
 * @brief   	This function plays the samples provided in MONO mode.
 *
 * @param[in]   volume: integer which determines the sound volume
 *
 * @param[in]   (*sample_source)(void): function which provides the samples to be played.
 *
 * @api
 */
void playSound( int volume, uint32_t (*sample_source)(void))
{
	uint8_t *new_sample;

	if (load_new_sample == 1U)
    {

  	   new_sample = &txbuf[which_buffer * (sizeof(txbuf) >> 1)];
	   for ( i = 0; i < ((sizeof(txbuf) >> 1)); i += 8U)
	   {
		   sample = (*sample_source)();
		   sample = (sample*volume) << 16;

		   /**********Load right channel***********/
		   load_channel_data(sample , new_sample);
		   new_sample += 4;

		   /**********Load left channel**********/
		   load_channel_data(sample, new_sample);
		   new_sample += 4;
	   }
	   
	   #if (AUD_LIST_ELEMENT != 2)
	   if(NO_READ_DB_AND_IB_REG_DURING_PLAY == 1)
	   {
		   FDA_Status[0] = PLAY_NO_READ_REGISTER;
	   }
	   else
	   {
		   FDA_Status[0] = PLAY;
		   AEK_903D_Read_All_DB(0);
		   AEK_903D_Read_All_IB(0);
	   }
	   #endif
  	   
	   #if (AUD_LIST_ELEMENT == 2)
	   if(devNumberStereo == 0)
	   {
			if(NO_READ_DB_AND_IB_REG_DURING_PLAY == 1)
			{
			   FDA_Status[0] = PLAY_NO_READ_REGISTER;
			}
			else
			{
			   FDA_Status[devNumberStereo] = PLAY;
			   AEK_903D_Read_All_DB(devNumberStereo);
			   AEK_903D_Read_All_IB(devNumberStereo);
			}

			devNumberStereo = 1;
	   }
	   else
	   {
			if(NO_READ_DB_AND_IB_REG_DURING_PLAY == 1)
			{
			   FDA_Status[0] = PLAY_NO_READ_REGISTER;
			}
			else
			{
			   FDA_Status[devNumberStereo] = PLAY;
			   AEK_903D_Read_All_DB(devNumberStereo);
			   AEK_903D_Read_All_IB(devNumberStereo);
			}

			devNumberStereo = 0;
	   }
	   #endif
	   
	   load_new_sample = 0;
    }
}

/**
 * @brief   	This function plays the samples provided in STEREO mode.
 *
 * @param[in]   volume: integer which determines the sound volume
 *
 * @param[in]   (*sample_source)(void): function which provides the samples to be played.
 *
 * @api
 */
void playSoundStereo( int volume, uint32_t (*sample_source)(void))
{
	uint8_t *new_sample;

	if (load_new_sample == 1U && AUD_LIST_ELEMENT == 2)
    {
  	   new_sample = &txbuf[which_buffer * (sizeof(txbuf) >> 1)];
	   for ( i = 0; i < ((sizeof(txbuf) >> 1)); i += 4U)
	   {
		   sample = (*sample_source)();
		   sample = (sample*volume) << 16;

		   /************Load channel************/
		   load_channel_data(sample , new_sample);
		   new_sample += 4;
		}

	   if(devNumberStereo == 0)
	   {
		   if(NO_READ_DB_AND_IB_REG_DURING_PLAY == 1)
		   {
			   FDA_Status[0] = PLAY_NO_READ_REGISTER;
		   }
		   else
		   {
			   FDA_Status[devNumberStereo] = PLAY;
			   AEK_903D_Read_All_DB(devNumberStereo);
			   AEK_903D_Read_All_IB(devNumberStereo);
		   }

		   devNumberStereo = 1;
	   }
	   else
	   {
		   if(NO_READ_DB_AND_IB_REG_DURING_PLAY == 1)
		   {
			   FDA_Status[0] = PLAY_NO_READ_REGISTER;
		   }
		   else
		   {
			   FDA_Status[devNumberStereo] = PLAY;
			   AEK_903D_Read_All_DB(devNumberStereo);
			   AEK_903D_Read_All_IB(devNumberStereo);
		   }

		   devNumberStereo = 0;
	   }

	   load_new_sample = 0;
    }
}

/**
 * @brief   	This function plays the samples provided in MONO mode.
 *
 * @param[in]   volume: integer which determines the sound volume
 *
 * @param[in]   (*sample_source)(void): function which provides the samples to be played.
 *
 * @param[in]   gain: integer which determines the amplitude/gain of the sound.
 *
 * @api
 */
void playSoundWithGain( int volume, uint32_t (*sample_source)(void),uint8_t gain)
{
	uint8_t *new_sample;

	if (load_new_sample == 1U)
    {

  	   new_sample = &txbuf[which_buffer * (sizeof(txbuf) >> 1)];
	   for ( i = 0; i < ((sizeof(txbuf) >> 1)); i += 8U)
	   {
		   sample = (*sample_source)();
		   sample = (sample*volume) << gain;

		   /**********Load right channel***********/
		   load_channel_data(sample , new_sample);
		   new_sample += 4;

		   /**********Load left channel**********/
		   load_channel_data(sample, new_sample);
		   new_sample += 4;
	   }

	   #if (AUD_LIST_ELEMENT != 2)
	   if(NO_READ_DB_AND_IB_REG_DURING_PLAY == 1)
	   {
		   FDA_Status[0] = PLAY_NO_READ_REGISTER;
	   }
	   else
	   {
		   FDA_Status[0] = PLAY;
		   AEK_903D_Read_All_DB(0);
		   AEK_903D_Read_All_IB(0);
	   }
	   #endif

	   #if (AUD_LIST_ELEMENT == 2)
	   if(devNumberStereo == 0)
	   {
			if(NO_READ_DB_AND_IB_REG_DURING_PLAY == 1)
			{
			   FDA_Status[0] = PLAY_NO_READ_REGISTER;
			}
			else
			{
			   FDA_Status[devNumberStereo] = PLAY;
			   AEK_903D_Read_All_DB(devNumberStereo);
			   AEK_903D_Read_All_IB(devNumberStereo);
			}

			devNumberStereo = 1;
	   }
	   else
	   {
			if(NO_READ_DB_AND_IB_REG_DURING_PLAY == 1)
			{
			   FDA_Status[0] = PLAY_NO_READ_REGISTER;
			}
			else
			{
			   FDA_Status[devNumberStereo] = PLAY;
			   AEK_903D_Read_All_DB(devNumberStereo);
			   AEK_903D_Read_All_IB(devNumberStereo);
			}

			devNumberStereo = 0;
	   }
	   #endif


	   load_new_sample = 0;
    }
}

/**
 * @brief   	This function plays the samples provided in STEREO mode.
 *
 * @param[in]   volume: integer which determines the sound volume
 *
 * @param[in]   (*sample_source)(void): function which provides the samples to be played.
 *
 * @param[in]   gain: integer which determines the amplitude/gain of the sound.
 * @api
 */
void playSoundStereoWithGain( int volume, uint32_t (*sample_source)(void), uint8_t gain)
{
	uint8_t *new_sample;

	if (load_new_sample == 1U && AUD_LIST_ELEMENT == 2)
    {
  	   new_sample = &txbuf[which_buffer * (sizeof(txbuf) >> 1)];
	   for ( i = 0; i < ((sizeof(txbuf) >> 1)); i += 4U)
	   {
		   sample = (*sample_source)();
		   sample = (sample*volume) << gain;

		   /************Load channel************/
		   load_channel_data(sample , new_sample);
		   new_sample += 4;
		}

	   if(devNumberStereo == 0)
	   {
		   if(NO_READ_DB_AND_IB_REG_DURING_PLAY == 1)
		   {
			   FDA_Status[0] = PLAY_NO_READ_REGISTER;
		   }
		   else
		   {
			   FDA_Status[devNumberStereo] = PLAY;
			   AEK_903D_Read_All_DB(devNumberStereo);
			   AEK_903D_Read_All_IB(devNumberStereo);
		   }

		   devNumberStereo = 1;
	   }
	   else
	   {
		   if(NO_READ_DB_AND_IB_REG_DURING_PLAY == 1)
		   {
			   FDA_Status[0] = PLAY_NO_READ_REGISTER;
		   }
		   else
		   {
			   FDA_Status[devNumberStereo] = PLAY;
			   AEK_903D_Read_All_DB(devNumberStereo);
			   AEK_903D_Read_All_IB(devNumberStereo);
		   }

		   devNumberStereo = 0;
	   }

	   load_new_sample = 0;
    }
}
#endif
/** @} */

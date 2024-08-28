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
 * @file    sound.h
 * @brief   sound header for AEK-AUD-D903V1.
 *
 * @addtogroup AEK_AUD_D903V1
 * @{
 */
#ifndef AUDIO_SOUND_H_
#define AUDIO_SOUND_H_

#include "components.h"
#include "AEK_AUD_D903V1.h"

#ifdef Allocation_Executed

#define DIM 10

/******************* Wave File Section*******************************/
/**
 * @brief Type of a structure representing the sound database addresses.
 */
typedef struct sound_db_s {
  char *name;
  void *start;
  void *end;
  void *half;
}  sound_db_t;

extern sound_db_t sound_db[];
extern volatile uint8_t which_buffer;
extern volatile uint32_t load_new_sample;
extern uint8_t txbuf[1008] __attribute__ ((aligned (256)));
extern FDA_State_t  FDA_Status[AUD_LIST_ELEMENT];
extern uint8_t NO_READ_DB_AND_IB_REG_DURING_PLAY;
/**
 * @brief Type of a structure representing the WAVE file header format. It is followed by data defined in the header.
 */
typedef struct
{
    uint8_t riff[4];                		// RIFF string/
    uint32_t overall_size;             		// overall size of file in bytes
    uint8_t wave[4];                	   	// WAVE string/
    uint8_t fmt_chunk_marker[4];    		// fmt string with trailing null char/
    uint32_t length_of_fmt;         	   	// length of the format data
    uint16_t format_type;           	   	// format type. 1-PCM, 3- IEEE float, 6 - 8bit A law, 7 - 8bit mu law
    uint16_t channels;              		// no.of channels
    uint32_t sample_rate;           	   	// sampling rate (blocks per second)
    uint32_t byte_rate;                     // SampleRate * NumChannels * BitsPerSample/8
    uint16_t block_align;           		// NumChannels * BitsPerSample/8
    uint16_t bits_per_sample;           	// bits per sample, 8- 8bits, 16- 16 bits etc.
    uint8_t data_chunk_header [4];  		// DATA string or FLLR string/
    uint32_t data_size;                     // NumSamples * NumChannels * BitsPerSample/8 - size of the next chunk that will be read
}waveHeaderType;

/*******************************************************************************
***************************** Function definition ******************************
*******************************************************************************/
void playSound( int volume, uint32_t (*sample_source)(void));
void playSoundStereo( int volume, uint32_t (*sample_source)(void));
void playSoundWithGain( int volume, uint32_t (*sample_source)(void),uint8_t gain);
void playSoundStereoWithGain( int volume, uint32_t (*sample_source)(void), uint8_t gain);

void checkWavFile(waveHeaderType* whPtr, uint8_t fileNumber);
uint32_t validate_wav_file(waveHeaderType* whPtr);
uint32_t swapEndian32(uint32_t data);
void initWaveFile(uint32_t** startfile, uint8_t dim);
void* getStartWavFile(int WaveFileNumber);
void* getHalfWavFile(int WaveFileNumber);
void* getEndWavFile(int WaveFileNumber);

#endif
#endif /* AUDIO_SOUND_H_ */

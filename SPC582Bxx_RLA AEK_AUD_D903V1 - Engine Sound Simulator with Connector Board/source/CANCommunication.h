/****************************************************************************
*
* Copyright Â© 2015-2020 STMicroelectronics - All Rights Reserved
*
* License terms: STMicroelectronics Proprietary in accordance with licensing
* terms SLA0089 at www.st.com.
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* EVALUATION ONLY - NOT FOR USE IN PRODUCTION
*****************************************************************************/

/**
 * @file    CANCommunication.h
 * @brief   CAN communication with AVAS system driver header.
 *
 * @addtogroup
 * @{
 */

#ifndef _CANCommunication_LLD_H_
#define _CANCommunication_LLD_H_


/* Receive message. */
// START - STOP Sound
#define START_STOP_SID 		0x7f0U
#define PLAY_SOUND 			0xAABBCCDDUL
#define STOP_SOUND 			0xDDEEFFAAUL

//Increase or  Decrease RPM. Each command will increment or decrement RPM value of 100.
#define CHANGE_RPM_SID		0x7f1U
#define TURN_UP_RPM 		0xBBAACCDDUL
#define TURN_DOWN_RPM		0xBBAADDCCUL
//KMS241112_1 : To Add Source Change
#define SOURCE_CHANGE_CMD_FOR_DSP	0x22334455UL

//KMS241025_1 : To Seperate Speed up/down action between MCU AVAS and DSP AVAS, we add CAN CMD.
#define SPEED_UP_CMD_FOR_DSP	0x11223344UL 
#define SPEED_DOWN_CMD_FOR_DSP	0x99887766UL

// Turn Up and Down Volume. The value received by Avas system have to be in the range [0 - 100]
#define VOLUME_SID		0x7f2U

/* end receive message */

/* Send message to main ECU */
#define SID_SEND_MESSAGE 0x7f0U
#define FAULT_OPEN_LOAD_PLAY 0x1A1B1C1DUL
#define FAULT_OPEN_LOAD_MUTE 0x2A2B2C2DUL
#define NO_FAULT_PLAY 0x3A3B3C3DUL
#define NO_FAULT_MUTE 0x4A4B4C4DUL
/* end send message */

#endif

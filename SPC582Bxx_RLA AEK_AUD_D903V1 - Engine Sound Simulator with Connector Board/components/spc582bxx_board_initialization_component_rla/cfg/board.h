/****************************************************************************
*
* Copyright © 2017-2022 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/

#ifndef _BOARD_H_
#define _BOARD_H_

#include "pal.h"

/*
 * Setup for a generic SPC582Bxx board.
 */

/*
 * Board identifiers.
 */
#define BOARD_GENERIC_SPC582BXX
#define BOARD_NAME                  "Generic SPC582Bxx"

/*
 * Support macros.
 */
#define MSCR_IO_INDEX(port, pin)    (((port) * 16U) + (pin))

/*
 * I/O definitions.
 */
#define PIN_CAN_RX_2_0              1U
#define PIN_FLASH_CS0_3             10U
#define PIN_FLASH_SCK_3             11U
#define PIN_CAN_TX_2_0              2U
#define PIN_PIN_MCU_AUDIO_OUT_I2S_LRCK_0 11U
#define PIN_I2C_SCL                 8U
#define PIN_I2C_SDA                 9U
#define PIN_DSP_RESET_GPIO44        12U
#define PIN_DSP_SPI_SIN_1           13U
#define PIN_DSP_SPI_SCK_1           14U
#define PIN_DSP_SPI_SOUT_1          15U
#define PIN_AMP_EN2_GPIO35          3U
#define PIN_AMP_MUTE_GPIO36         4U
#define PIN_MCU_AUDIO_OUT_I2S_TEST_0 11U
#define PIN_FLASH_SIN_3             10U
#define PIN_FLASH_SOUT_3            11U
#define PIN_MCU_AUDIO_OUT_I2S_SCK_0 11U
#define PIN_MCU_AUDIO_OUT_I2S_DOUT_0 12U

/*
 * PORT definitions.
 */
#define PORT_PIN_CAN_RX_2_0         PORT_A
#define PORT_PIN_FLASH_CS0_3        PORT_A
#define PORT_PIN_FLASH_SCK_3        PORT_A
#define PORT_PIN_CAN_TX_2_0         PORT_A
#define PORT_PIN_PIN_MCU_AUDIO_OUT_I2S_LRCK_0 PORT_B
#define PORT_PIN_I2C_SCL            PORT_B
#define PORT_PIN_I2C_SDA            PORT_B
#define PORT_PIN_DSP_RESET_GPIO44   PORT_C
#define PORT_PIN_DSP_SPI_SIN_1      PORT_C
#define PORT_PIN_DSP_SPI_SCK_1      PORT_C
#define PORT_PIN_DSP_SPI_SOUT_1     PORT_C
#define PORT_PIN_AMP_EN2_GPIO35     PORT_C
#define PORT_PIN_AMP_MUTE_GPIO36    PORT_C
#define PORT_PIN_MCU_AUDIO_OUT_I2S_TEST_0 PORT_D
#define PORT_PIN_FLASH_SIN_3        PORT_E
#define PORT_PIN_FLASH_SOUT_3       PORT_E
#define PORT_PIN_MCU_AUDIO_OUT_I2S_SCK_0 PORT_G
#define PORT_PIN_MCU_AUDIO_OUT_I2S_DOUT_0 PORT_G

/*
 * MSCR_IO definitions.
 */
#define MSCR_IO_PIN_CAN_RX_2_0      MSCR_IO_INDEX(PORT_PIN_CAN_RX_2_0, PIN_CAN_RX_2_0)
#define MSCR_IO_PIN_FLASH_CS0_3     MSCR_IO_INDEX(PORT_PIN_FLASH_CS0_3, PIN_FLASH_CS0_3)
#define MSCR_IO_PIN_FLASH_SCK_3     MSCR_IO_INDEX(PORT_PIN_FLASH_SCK_3, PIN_FLASH_SCK_3)
#define MSCR_IO_PIN_CAN_TX_2_0      MSCR_IO_INDEX(PORT_PIN_CAN_TX_2_0, PIN_CAN_TX_2_0)
#define MSCR_IO_PIN_PIN_MCU_AUDIO_OUT_I2S_LRCK_0 MSCR_IO_INDEX(PORT_PIN_PIN_MCU_AUDIO_OUT_I2S_LRCK_0, PIN_PIN_MCU_AUDIO_OUT_I2S_LRCK_0)
#define MSCR_IO_PIN_I2C_SCL         MSCR_IO_INDEX(PORT_PIN_I2C_SCL, PIN_I2C_SCL)
#define MSCR_IO_PIN_I2C_SDA         MSCR_IO_INDEX(PORT_PIN_I2C_SDA, PIN_I2C_SDA)
#define MSCR_IO_PIN_DSP_RESET_GPIO44 MSCR_IO_INDEX(PORT_PIN_DSP_RESET_GPIO44, PIN_DSP_RESET_GPIO44)
#define MSCR_IO_PIN_DSP_SPI_SIN_1   MSCR_IO_INDEX(PORT_PIN_DSP_SPI_SIN_1, PIN_DSP_SPI_SIN_1)
#define MSCR_IO_PIN_DSP_SPI_SCK_1   MSCR_IO_INDEX(PORT_PIN_DSP_SPI_SCK_1, PIN_DSP_SPI_SCK_1)
#define MSCR_IO_PIN_DSP_SPI_SOUT_1  MSCR_IO_INDEX(PORT_PIN_DSP_SPI_SOUT_1, PIN_DSP_SPI_SOUT_1)
#define MSCR_IO_PIN_AMP_EN2_GPIO35  MSCR_IO_INDEX(PORT_PIN_AMP_EN2_GPIO35, PIN_AMP_EN2_GPIO35)
#define MSCR_IO_PIN_AMP_MUTE_GPIO36 MSCR_IO_INDEX(PORT_PIN_AMP_MUTE_GPIO36, PIN_AMP_MUTE_GPIO36)
#define MSCR_IO_PIN_MCU_AUDIO_OUT_I2S_TEST_0 MSCR_IO_INDEX(PORT_PIN_MCU_AUDIO_OUT_I2S_TEST_0, PIN_MCU_AUDIO_OUT_I2S_TEST_0)
#define MSCR_IO_PIN_FLASH_SIN_3     MSCR_IO_INDEX(PORT_PIN_FLASH_SIN_3, PIN_FLASH_SIN_3)
#define MSCR_IO_PIN_FLASH_SOUT_3    MSCR_IO_INDEX(PORT_PIN_FLASH_SOUT_3, PIN_FLASH_SOUT_3)
#define MSCR_IO_PIN_MCU_AUDIO_OUT_I2S_SCK_0 MSCR_IO_INDEX(PORT_PIN_MCU_AUDIO_OUT_I2S_SCK_0, PIN_MCU_AUDIO_OUT_I2S_SCK_0)
#define MSCR_IO_PIN_MCU_AUDIO_OUT_I2S_DOUT_0 MSCR_IO_INDEX(PORT_PIN_MCU_AUDIO_OUT_I2S_DOUT_0, PIN_MCU_AUDIO_OUT_I2S_DOUT_0)

/*
 * MSCR_MUX definitions.
 */
#define MSCR_MUX_PIN_CAN_RX_2_0     247U
#define MSCR_MUX_PIN_I2C_SCL        297U
#define MSCR_MUX_PIN_I2C_SDA        296U
#define MSCR_MUX_PIN_DSP_SPI_SIN_1  371U
#define MSCR_MUX_PIN_MCU_AUDIO_OUT_I2S_TEST_0 368U
#define MSCR_MUX_PIN_FLASH_SIN_3    377U

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */

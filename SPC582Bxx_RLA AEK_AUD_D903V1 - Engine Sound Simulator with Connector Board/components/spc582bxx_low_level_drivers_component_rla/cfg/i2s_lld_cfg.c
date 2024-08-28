/****************************************************************************
*
* Copyright © 2018-2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    i2s_lld_cfg.c
 * @brief   I2S Driver configuration code.
 *
 * @addtogroup I2S
 * @{
 */

#include "i2s_lld_cfg.h"

#if (LLD_USE_I2S == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   Structure defining the I2S configuration "AEK_AUD_D903V1Board0_J10_WS_LABEL_I2SCR_I2SSDA1_SCL".
 */
I2SConfig i2s_config_AEK_AUD_D903V1Board0_J10_WS_LABEL_I2SCR_I2SSDA1_SCL = {
  EndTransmitCallback,
  HalfTransmitCallback,
  EndTransmitCallback,
  HalfTransmitCallback,
  0UL | SPC5_CTAR_FMSZ(16) |
        SPC5_CTAR_PCSSCK_PRE5 | SPC5_CTAR_PASC_PRE5 |
        SPC5_CTAR_PDT_PRE5 | SPC5_CTAR_PBR_PRE7 |
        SPC5_CTAR_CSSCK_DIV16 | SPC5_CTAR_ASC_DIV16 |
        SPC5_CTAR_DT_DIV16 | SPC5_CTAR_BR_DIV4,
  0UL | SPC5_PUSHR_CONT | SPC5_PUSHR_CTAS(0),                      /* I2S standard: left channel, WS is low   */
  0UL | SPC5_PUSHR_CONT | SPC5_PUSHR_CTAS(0) | SPC5_PUSHR_PCS(0),  /* I2S standard: right channel, WS is high */
  SPC5_I2S_STANDARD_WS_SL,
  SPC5_I2S_BPS_32
};

 /*===========================================================================*/
/* Driver local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

 /*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

#endif /* LLD_USE_I2S */

/** @} */

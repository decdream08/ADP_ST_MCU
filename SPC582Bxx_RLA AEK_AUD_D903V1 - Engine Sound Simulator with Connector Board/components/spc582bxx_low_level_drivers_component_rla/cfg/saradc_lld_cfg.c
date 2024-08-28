/****************************************************************************
*
* Copyright © 2015-2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    saradc_lld_cfg.c
 * @brief   SARADC Driver configuration code.
 *
 * @addtogroup SARADC
 * @{
 */

#include "saradc_lld_cfg.h"

#if (LLD_USE_SARADC == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/


  /* Channels Configurations (DMA is not used)*/
static channelConfig _saradcconf_ch_configs[SPC5_SARADC_MAX_NUMOFCHANNELS] =
{
  {SARADC_CHANNEL_INTERNAL, 55U,SARADC_REFERENCE_DEFAULT, SARADC_PRECHARGE_DISABLED, SARADC_CTR0, SARADC_WATCHDOG_REGISTER_NONE,NULL},
  {SARADC_CHANNEL_INTERNAL, 82U,SARADC_REFERENCE_DEFAULT, SARADC_PRECHARGE_DISABLED, SARADC_CTR0, SARADC_WATCHDOG_REGISTER_NONE,NULL},
};


/**
 * @brief   Structure defining the configuration "saradcconf".
 */
SARADCConfig saradc_config_saradcconf = {
   /* conversion mode */
  SARADC_MODE_ONESHOT,
  
  /* Trigger Mode */
  SARADC_TRIGGER_DISABLED,
  
  /* CTR registers configuration (CRES,PRECHG,INPSAMP) */
  {
  /* CTR0 */ {SARADC_CRES_HIGH, 0U, 100U},
  /* CTR1 */ {SARADC_CRES_HIGH, 0U, 100U},
  /* CTR2 */ {SARADC_CRES_HIGH, 0U, 100U},
  /* CTR3 */ {SARADC_CRES_HIGH, 0U, 100U},
  },
  /* No DMA configuration */
  FALSE,
  {0U, 0U, 0U, 0U, 0U, 0U, 0U},
  NULL,
  
  /* Channels Configurations */
  _saradcconf_ch_configs,
  
  /* Number of channels */
  2U,
  
  /* Conversion callback */
  saradcconf_adc_callback,

  /* No analog watchdog configured */
  {
  {(float)0,(float)0},
  },
  (float)0,
  0U,
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


#endif /* LLD_USE_SARADC */

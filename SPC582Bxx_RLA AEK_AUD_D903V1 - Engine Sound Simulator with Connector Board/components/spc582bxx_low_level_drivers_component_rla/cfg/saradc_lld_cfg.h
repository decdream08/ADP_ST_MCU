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
 * @file    saradc_lld_cfg.h
 * @brief   SARADC Driver configuration macros and structures.
 *
 * @addtogroup SARADC
 * @{
 */

#ifndef _SARADC_LLD_CFG_H_
#define _SARADC_LLD_CFG_H_

#include "spc5_lld.h"
#include "saradc_lld.h"

#if (LLD_USE_SARADC == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* List of the SARADCConfig structures defined in saradc_lld_cfg.c.*/
extern SARADCConfig saradc_config_saradcconf;

#ifdef __cplusplus
extern "C" {
#endif
 /* List of the callback functions referenced from the SARADCConfig
     structures in saradc_lld_cfg.c.*/
  void saradcconf_adc_callback(SARADCDriver *saradcp);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_SARADC */

#endif /* _SARADC_LLD_CFG_H_ */

/** @} */

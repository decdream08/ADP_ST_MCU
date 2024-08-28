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
 * @file    can_lld_cfg.h
 * @brief   CAN Driver configuration macros and structures.
 *
 * @addtogroup CAN
 * @{
 */

#ifndef _CAN_LLD_CFG_H_
#define _CAN_LLD_CFG_H_

#include "spc5_lld.h"
#include "can_lld.h"

#if (LLD_USE_CAN == TRUE) || defined(__DOXYGEN__)

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

/* List of the CANConfig structures defined in can_lld_cfg.c.*/
extern CANConfig can_config_mcanconf;

#ifdef __cplusplus
extern "C" {
#endif
  /* List of the callback functions referenced from the CANConfig
     structures in can_lld_cfg.c.*/
void mcanconf_rxreceive(uint32_t msgbuf, CANRxFrame crfp);
void mcanconf_errorcb(CANDriver *canp, uint32_t psr);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_CAN */

#endif /* _CAN_LLD_CFG_H_ */

/** @} */

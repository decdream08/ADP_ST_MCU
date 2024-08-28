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
 * @file    pit_lld_cfg.c
 * @brief   PIT Driver configuration code.
 *
 * @addtogroup PIT
 * @{
 */

#include "pit_lld_cfg.h"

#if (LLD_USE_PIT == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/
PIT_CH_Config pit0_config[SPC5_PIT0_CHANNELS] ={
  {FALSE,0,NULL}
  ,
  {FALSE,0,NULL}
  ,
  {FALSE,0,NULL}
  ,
  {FALSE,0,NULL}
  ,
  {FALSE,0,NULL}
  ,
  {FALSE,0,NULL}
  ,
  {FALSE,0,NULL}
  ,
  {FALSE,0,NULL}
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

#endif /* LLD_USE_PIT */

/** @} */

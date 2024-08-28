/****************************************************************************
*
* Copyright (c) 2015-2020 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    eirq.h
 * @brief   SPC5xx EIRQ header.
 *
 * @addtogroup EIRQ
 * @{
 */

#ifndef _EIRQ_H_
#define _EIRQ_H_

#include <stddef.h>
#include "vectors.h"
#include "irq.h"
#include "platform.h"
#include "eirq_cfg.h"


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

/**
 * @brief   EIRQ notification callback type.
 *
 */
typedef void (*eirqcallback_t)(void);

/**
 * @brief   Structure representing a PIT Channel configuration
 */
typedef struct {
  /**
   * @brief   eirq number.
   */  
  int8_t eirqNumber;
  /**
   * @brief   rising edge trigger event
   */
  uint8_t risingEdge;
  /**
   * @brief    falling edge trigger event
   */
  uint8_t fallingEdge;
  /**
   * @brief    Antiglitch filter enable on PIN
   */
  uint8_t filterEnable;
   /**
   * @brief   callback function.
   */
  eirqcallback_t callback;
}eirq_config;

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

extern eirq_config eirqconf[];

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* IRQ Handlers                                                              */
/*===========================================================================*/
#if (SPC5_SIUL_EIRQ_HAS_GROUP_0 == TRUE)
IRQ_HANDLER(SPC5_SIUL_EIRQ_GROUP_0_HANDLER);
#endif
#if (SPC5_SIUL_EIRQ_HAS_GROUP_1 == TRUE)
IRQ_HANDLER(SPC5_SIUL_EIRQ_GROUP_1_HANDLER);
#endif
#if (SPC5_SIUL_EIRQ_HAS_GROUP_2 == TRUE)
IRQ_HANDLER(SPC5_SIUL_EIRQ_GROUP_2_HANDLER);
#endif
#if (SPC5_SIUL_EIRQ_HAS_GROUP_3 == TRUE)
IRQ_HANDLER(SPC5_SIUL_EIRQ_GROUP_3_HANDLER);
#endif

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
void eirqInit(void);
#ifdef __cplusplus
}
#endif

#endif
/** @} */

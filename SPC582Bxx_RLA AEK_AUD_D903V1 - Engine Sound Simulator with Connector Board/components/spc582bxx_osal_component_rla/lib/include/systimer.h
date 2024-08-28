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
 * @file    systimer.h
 * @brief   OSAL module header.
 *
 * @addtogroup OSAL
 * @{
 */

#ifndef _SYSTIMER_H_
#define _SYSTIMER_H_

#include "irq.h"
#include "clock.h"
#include "platform.h"

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @brief   System Timer (PIT channel 0) IRQ handler.
 * @note    PIT channel 0 is allocated permanently for system tick
 *          generation.
 */
#if !defined(OSAL_SYSTIMER_IRQ_HANDLER) || defined(__DOXYGEN__)
#define SPC5_SYSTIMER_IRQ_HANDLER           SPC5_PIT0_CH0_HANDLER
#endif

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* Inline functions.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* IRQ Handlers                                                              */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/
#ifdef __cplusplus
extern "C" {
#endif
  void sysTimeSetup(uint32_t ticks_per_sec);
  void sysTimeReset(void);
#ifdef __cplusplus
}
#endif
#endif /* _SYSTIMER_H_ */

/** @} */

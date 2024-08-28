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
 * @file    systimer_cfg.h
 * @brief   OSAL configuration macros and structures.
 *
 * @addtogroup OSAL
 * @{
 */

#ifndef _SYSTIMER_CFG_H_
#define _SYSTIMER_CFG_H_

#include "platform.h"

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   System Timer (PIT channel 0) IRQ priority.
 * @note    PIT channel 0 is allocated permanently for system tick
 *          generation.
 */
#if !defined(SPC5_SYSTIMER_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_SYSTIMER_IRQ_PRIORITY          4
#endif

/**
 * @brief   Core on which the system timer (PIT channel 0) interrupts are
 *          dispatched.
 */
#if !defined(SPC5_SYSTIMER_CORE) || defined(__DOXYGEN__)
#define SPC5_SYSTIMER_CORE                  INTC_PSR_MAINCORE
#endif

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
/* External declarations.                                                    */
/*===========================================================================*/

#endif /* _SYSTIMER_CFG_H_ */

/** @} */

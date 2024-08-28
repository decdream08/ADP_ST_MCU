/****************************************************************************
*
* Copyright (c) 2021 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    swirq.h
 * @brief   Software IRQ module header.
 *
 * @addtogroup SWIRQ
 * @{
 */

#ifndef _SWIRQ_H_
#define _SWIRQ_H_

#include "platform.h"

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* Inline functions.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/
#ifdef __cplusplus
extern "C" {
#endif

void swirqInit(void);
void swirq_enable(uint8_t irq, uint8_t prio, uint32_t core);
void swirq_disable(uint8_t irq);
void swirq_set(uint8_t irq);
void swirq_clear(uint8_t irq);

#ifdef __cplusplus
}
#endif

#endif /* _SWIRQ_H_ */

/** @} */

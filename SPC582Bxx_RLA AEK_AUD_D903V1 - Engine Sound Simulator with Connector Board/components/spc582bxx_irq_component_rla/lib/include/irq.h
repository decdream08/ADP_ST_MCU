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
 * @file    irq.h
 * @brief   IRQ module header.
 *
 * @addtogroup IRQ
 * @{
 */

#ifndef _IRQ_H_
#define _IRQ_H_

#include "vectors.h"
#include "irq_cfg.h"
#include "platform.h"
#ifdef __ghs__
#include <ppc_ghs.h>
#endif
/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/**
 * @brief   IRQ prologue code.
 * @details This macro must be inserted at the start of all IRQ handlers.
 */
#define IRQ_PROLOGUE()

/**
 * @brief   IRQ epilogue code.
 * @details This macro must be inserted at the end of all IRQ handlers.
 */
#define IRQ_EPILOGUE()

/**
 * @brief   IRQ handler function declaration.
 * @details This macro hides the details of an ISR function declaration.
 *
 * @param[in] id        a vector name as defined in @p vectors.s
 */
#define IRQ_HANDLER(id) void id(void)

/*===========================================================================*/
/* Inline functions.                                                            */
/*===========================================================================*/

/**
 * @brief   Globally enables interrupts.
 *
 * @special
 */
 #define irqIsrEnable()  asm volatile("wrteei  1" : : : "memory");
 
/**
 * @brief   Globally disables interrupts.
 *
 * @special
 */
#define irqIsrDisable() asm volatile ("wrteei  0" : : : "memory");

/**
 * @brief   Returns the value of the Machine State Register (MSR).
 *
 * @special
 */
#ifdef __ghs__
#define irqGetMsr() __GETSR()
#else
static inline uint32_t irqGetMsr(void) {

  uint32_t msr = 0UL;

  asm volatile("mfmsr %0" : "=r" (msr) :);

  return msr;
}
#endif
/**
 * @brief   Returns the value of the External Interrupt Enable (MSR[EE]) bit.
 *
 * @special
 */
static inline
uint32_t irqGetExtIntEnable(void) {

  uint32_t msr;

  msr = irqGetMsr();

  return (0x1UL & (msr >> 15U));
}

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/
#ifdef __cplusplus
extern "C" {
#endif
  void irqInit(void);
  void irqSysHalt(void);
#ifdef __cplusplus
}
#endif

#endif /* _IRQ_H_ */

/** @} */

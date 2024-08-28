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
 * @file    irq.c
 * @brief   IRQ module code.
 *
 * @addtogroup IRQ
 * @{
 */

#include "irq.h"

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   IRQ module initialization.
 *
 * @api
 */
void irqInit(void) {

  irq_cfg_init();
  
  /* Method of accessing memory-mapped registers at fixed addresses does not 
     comply with MISRA C because it involves converting an integer to a 
	 pointer. */
  /*lint -e9033 */
  /* INTC initialization, software vector mode, 4 bytes vectors, starting
     at priority 0.*/
     
  INTC_BCR = 0;

  /* Configure IRQ for main core.*/
  INTC_CPR(MAIN_CORE)   = 0;
  INTC_IACKR(MAIN_CORE) = (uint32_t)_vectors;

#if defined(BOOT_CORE0) && (BOOT_CORE0 == 1)
  /* Configure IRQ for secondary core 0.*/
  INTC_CPR(0)   = 0;
  INTC_IACKR(0) = (uint32_t)_vectors;
#endif /* BOOT_CORE0 */

#if defined(BOOT_CORE1) && (BOOT_CORE1 == 1)
  /* Configure IRQ for secondary core 1.*/
  INTC_CPR(1)   = 0;
  INTC_IACKR(1) = (uint32_t)_vectors;
#endif /* BOOT_CORE1 */

#if defined(BOOT_CORE2) && (BOOT_CORE2 == 1)
  /* Configure IRQ for secondary core 2.*/
  INTC_CPR(2)   = 0;
  INTC_IACKR(2) = (uint32_t)_vectors;
#endif /* BOOT_CORE2 */

  /*lint +e9033 */
}

/**
 * @brief   System halt 
 *
 * @api
 */

#if !defined(__DOXYGEN__)
__attribute__((weak, noreturn))
#endif
void irqSysHalt(void) {

  irqIsrDisable();
  for ( ; ; ) {
  }
}

/** @} */

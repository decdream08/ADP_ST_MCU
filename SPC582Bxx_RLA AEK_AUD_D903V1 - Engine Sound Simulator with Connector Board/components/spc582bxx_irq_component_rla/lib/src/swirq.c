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
 * @file    swirq.c
 * @brief   SPC5xx Software IRQ code.
 *
 * @addtogroup SWIRQ
 * @{
 */

#include "platform.h"
#include "swirq.h"
#include "swirq_cfg.h"

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/	

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/
/*lint -e9033 */

/**
 * @brief   Software IRQ initialization.
 *
 * @note Automatically called at startup.
 *
 * @init
 */
void swirqInit(void) {

  /* Initialize priority of configured software interrupts */
  swirq_init_prio();
}


/**
 * @brief   Enable software IRQ.
 *
 * @param[in] irq   software irq number
 * @param[in] prio  interrupt priority
 * @param[in] core  core to dispatch interrupt
 *
 * @sa
 * INTC_PSR_CORE0, INTC_PSR_CORE1, INTC_PSR_CORE2,
 * swirq_disable
 *
 * @notapi
 */
void swirq_enable(uint8_t irq, uint8_t prio, uint32_t core) {
  irq &= 0x1FU;
  INTC_PSR((irq)) = INTC_PSR_ENABLE(core, prio);
}

/**
 * @brief   Disable software IRQ.
 *
 * @param[in] irq   software irq number
 *
 * @sa
 * swirq_enable
 *
 * @notapi
 */
void swirq_disable(uint8_t irq) {
  irq &= 0x1FU;
  INTC_PSR((irq)) = 0U;
}

/**
 * @brief   Set software IRQ.
 *
 * @param[in] irq   software irq number
 *
 * @sa
 * swirq_clear
 *
 * @notapi
 */
void swirq_set(uint8_t irq) {
  irq &= 0x1FU;
  INTC_SSCIR(irq) = 2U;
}

/**
 * @brief   Clear software IRQ.
 *
 * @param[in] irq   software irq number
 *
 * @sa
 * swirq_set
 *
 * @notapi
 */
void swirq_clear(uint8_t irq) {
  irq &= 0x1FU;
  INTC_SSCIR(irq) = 1U;
}
/*lint +e9033 */
/** @} */

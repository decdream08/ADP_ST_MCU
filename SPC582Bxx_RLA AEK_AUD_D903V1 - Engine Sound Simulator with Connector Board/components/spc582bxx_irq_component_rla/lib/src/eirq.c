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
 * @file    eirq.c
 * @brief   SPC5xx EIRQ code.
 *
 * @addtogroup EIRQ
 * @{
 */

#include "eirq.h"
#include "osal.h"

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/
void manage_eirq_interrupt(uint8_t eirqnum);

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/	

/**
 * @brief  manage external interrupt occurred and call related callback
 *
 * @param[in] eirqnum number of External Interrupt Occurred
 */
void manage_eirq_interrupt(uint8_t eirqnum) {
  uint8_t i;
  i = 0U;
  while (eirqconf[i].eirqNumber != -1) {
    if (eirqnum == (uint8_t)eirqconf[i].eirqNumber) {
      /* call related callback */
      if (eirqconf[i].callback != NULL) {
        eirqconf[i].callback();
      }
    }
    i++;
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if (SPC5_SIUL_EIRQ_HAS_GROUP_0 == TRUE)
/**
 * @brief  EIRQ 0-7 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_SIUL_EIRQ_GROUP_0_HANDLER) {
  uint8_t i;

  IRQ_PROLOGUE();

  for (i = SPC5_SIUL_EIRQ_GROUP_0_MIN; i < (SPC5_SIUL_EIRQ_GROUP_0_MAX + 1U); i++) {
    /*check eirq occurred */
    if (((SIUL2.DISR0.R >> i) & 0x01U) == 1U) {
      /*call management function*/
      manage_eirq_interrupt(i);
      /*reset interrupt flag*/
      SIUL2.DISR0.R = (1UL << i);
    }
  }

  IRQ_EPILOGUE();
}
#endif /* SPC5_SIUL_EIRQ_HAS_GROUP_0 */

#if (SPC5_SIUL_EIRQ_HAS_GROUP_1 == TRUE)
/**
 * @brief  EIRQ 8-15 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_SIUL_EIRQ_GROUP_1_HANDLER) {
  uint8_t i;

  IRQ_PROLOGUE();

  for (i = SPC5_SIUL_EIRQ_GROUP_1_MIN; i < (SPC5_SIUL_EIRQ_GROUP_1_MAX + 1U); i++) {
    /*check eirq occurred */
    if (((SIUL2.DISR0.R >> i) & 0x01U) == 1U) {
      /*call management function*/
      manage_eirq_interrupt(i);
      /*reset interrupt flag*/
      SIUL2.DISR0.R = (1UL << i);
    }
  }

  IRQ_EPILOGUE();
}
#endif /* SPC5_SIUL_EIRQ_HAS_GROUP_1 */

#if (SPC5_SIUL_EIRQ_HAS_GROUP_2 == TRUE)
/**
 * @brief  EIRQ 16-23 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_SIUL_EIRQ_GROUP_2_HANDLER) {
  uint8_t i;

  IRQ_PROLOGUE();

  for (i = SPC5_SIUL_EIRQ_GROUP_2_MIN; i < (SPC5_SIUL_EIRQ_GROUP_2_MAX + 1U); i++) {
    /*check eirq occurred */
    if (((SIUL2.DISR0.R >> i) & 0x01U) == 1U) {
      /*call management function*/
      manage_eirq_interrupt(i);
      /*reset interrupt flag*/
      SIUL2.DISR0.R = (1UL << i);
    }
  }

  IRQ_EPILOGUE();
}
#endif /* SPC5_SIUL_EIRQ_HAS_GROUP_2 */

#if (SPC5_SIUL_EIRQ_HAS_GROUP_3 == TRUE)
/**
 * @brief  EIRQ 24-31 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_SIUL_EIRQ_GROUP_3_HANDLER) {
  uint8_t i;

  IRQ_PROLOGUE();

  for (i = SPC5_SIUL_EIRQ_GROUP_3_MIN; i < (SPC5_SIUL_EIRQ_GROUP_3_MAX + 1U); i++) {
    /*check eirq occurred */
    if (((SIUL2.DISR0.R >> i) & 0x01U) == 1U) {
      /*call management function*/
      manage_eirq_interrupt(i);
      /*reset interrupt flag*/
      SIUL2.DISR0.R = (1UL << i);
    }
  }

  IRQ_EPILOGUE();
}
#endif /* SPC5_SIUL_EIRQ_HAS_GROUP_3 */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Eirq initialization.
 *
 * @init
 */
void eirqInit(void) {
  uint8_t i;
  uint8_t eirqnum;

  /* Priority settings */
  SPC5_SIUL_EIRQ_GROUP_0_SET_PRIO();
  SPC5_SIUL_EIRQ_GROUP_1_SET_PRIO();
  SPC5_SIUL_EIRQ_GROUP_2_SET_PRIO();
  SPC5_SIUL_EIRQ_GROUP_3_SET_PRIO();

  /* Registers Configuration */
  i = 0;
  while (eirqconf[i].eirqNumber != -1) {
    eirqnum = (uint8_t)eirqconf[i].eirqNumber;
    /* set rising edge event flag*/
    if (eirqconf[i].risingEdge == TRUE) {
      SIUL2.IREER0.R |= (1UL << eirqnum);
    }
    /* set falling edge event flag*/
    if (eirqconf[i].fallingEdge == TRUE) {
      SIUL2.IFEER0.R |= (1UL << eirqnum);
    }
    /* set antiglitch filter */
    if (eirqconf[i].filterEnable == TRUE) {
      SIUL2.IFER0.R |= (1UL << eirqnum);
    }
    /* enable eirq interrupt */
    SIUL2.DIRER0.R |= (1UL << eirqnum);
    i++;
  }
}

/** @} */

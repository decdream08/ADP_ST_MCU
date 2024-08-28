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
 * @file    eirq_cfg.h
 * @brief   External Interrupt configuration and management.
 *
 * @addtogroup EIRQ
 * @{
 */ 
 
#ifndef _EIRQ_CFG_H_
#define _EIRQ_CFG_H_

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
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

#define SPC5_EIRQ_GROUP_0_IRQ_PRIORITY      INTC_PSR_ENABLE(INTC_PSR_MAINCORE,6)
#define SPC5_EIRQ_GROUP_1_IRQ_PRIORITY      INTC_PSR_ENABLE(INTC_PSR_MAINCORE,6)
#define SPC5_EIRQ_GROUP_2_IRQ_PRIORITY      INTC_PSR_ENABLE(INTC_PSR_MAINCORE,6)
#define SPC5_EIRQ_GROUP_3_IRQ_PRIORITY      INTC_PSR_ENABLE(INTC_PSR_MAINCORE,6)

/* Interrupt groups */
#define SPC5_SIUL_EIRQ_HAS_GROUP_0          TRUE
#define SPC5_SIUL_EIRQ_HAS_GROUP_1          TRUE
#define SPC5_SIUL_EIRQ_HAS_GROUP_2          TRUE
#define SPC5_SIUL_EIRQ_HAS_GROUP_3          TRUE
 
/* Interrupt handlers and vector numbers */
#define SPC5_SIUL_EIRQ_GROUP_0_HANDLER      vector243
#define SPC5_SIUL_EIRQ_GROUP_1_HANDLER      vector244
#define SPC5_SIUL_EIRQ_GROUP_2_HANDLER      vector245
#define SPC5_SIUL_EIRQ_GROUP_3_HANDLER      vector246
#define SPC5_SIUL_EIRQ_GROUP_0_INT_NUMBER   243
#define SPC5_SIUL_EIRQ_GROUP_1_INT_NUMBER   244
#define SPC5_SIUL_EIRQ_GROUP_2_INT_NUMBER   245
#define SPC5_SIUL_EIRQ_GROUP_3_INT_NUMBER   246

/* Interrupt handlers and vector numbers */
#define SPC5_SIUL_EIRQ_GROUP_0_SET_PRIO()   INTC_PSR(SPC5_SIUL_EIRQ_GROUP_0_INT_NUMBER) = SPC5_EIRQ_GROUP_0_IRQ_PRIORITY
#define SPC5_SIUL_EIRQ_GROUP_1_SET_PRIO()   INTC_PSR(SPC5_SIUL_EIRQ_GROUP_1_INT_NUMBER) = SPC5_EIRQ_GROUP_1_IRQ_PRIORITY
#define SPC5_SIUL_EIRQ_GROUP_2_SET_PRIO()   INTC_PSR(SPC5_SIUL_EIRQ_GROUP_2_INT_NUMBER) = SPC5_EIRQ_GROUP_2_IRQ_PRIORITY
#define SPC5_SIUL_EIRQ_GROUP_3_SET_PRIO()   INTC_PSR(SPC5_SIUL_EIRQ_GROUP_3_INT_NUMBER) = SPC5_EIRQ_GROUP_3_IRQ_PRIORITY

/* Interrupt number (min/max) per group */
#define SPC5_SIUL_EIRQ_GROUP_0_MIN          0U
#define SPC5_SIUL_EIRQ_GROUP_0_MAX          3U
#define SPC5_SIUL_EIRQ_GROUP_1_MIN          4U
#define SPC5_SIUL_EIRQ_GROUP_1_MAX          7U
#define SPC5_SIUL_EIRQ_GROUP_2_MIN          8U
#define SPC5_SIUL_EIRQ_GROUP_2_MAX          11U
#define SPC5_SIUL_EIRQ_GROUP_3_MIN          12U
#define SPC5_SIUL_EIRQ_GROUP_3_MAX          15U


/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/
#ifdef __cplusplus
extern "C" {
#endif
  void key_press(void);
#ifdef __cplusplus
}
#endif

#endif /* _EIRQ_CFG_H_ */

/** @} */

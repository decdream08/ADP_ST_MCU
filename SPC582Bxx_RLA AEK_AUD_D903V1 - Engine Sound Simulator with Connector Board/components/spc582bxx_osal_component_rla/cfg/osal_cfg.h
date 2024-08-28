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
 * @file    osal_cfg.h
 * @brief   OSAL configuration macros and structures.
 *
 * @addtogroup OSAL
 * @{
 */

#ifndef _OSAL_CFG_H_
#define _OSAL_CFG_H_

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   FreeRTOS Operating System enable switch.
 * @details If set to @p TRUE the support for FreeRTOS Operating System is 
 *          included.
 */
#define OSAL_FREERTOS_ENABLE                FALSE

/**
 * @brief   Operating System enable switch.
 * @details It is set to @p TRUE if one of the supported Operating System is 
 *          included.
 */
#if (OSAL_FREERTOS_ENABLE == TRUE)
#define OSAL_OS_ENABLE                      TRUE
#else
#define OSAL_OS_ENABLE                      FALSE
#endif

/**
 * @brief   IRQ preemption enable switch.
 * @details If set to @p TRUE the IRQ preemption is enabled.
 */
#if !defined(OSAL_ENABLE_IRQ_PREEMPTION)
#define OSAL_ENABLE_IRQ_PREEMPTION          FALSE
#endif

/**
 * @brief   System Timer enable.
 * @details If set to @p TRUE the System Timer is enabled.
 */
#if !defined(OSAL_SYSTIMER_ENABLE) || defined(__DOXYGEN__)
#define OSAL_SYSTIMER_ENABLE                TRUE
#endif

/**
 * @brief   System timer tick frequency [Hz].
 * @details Number of system timer ticks in a second.
 */
#if !defined(OSAL_SYSTIMER_TICK_FREQ_HZ) || defined(__DOXYGEN__)
#define OSAL_SYSTIMER_TICK_FREQ_HZ          1000
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

#if !defined(_FROM_ASM_)
/**
 * @brief   Returns processor identification.
 *
 * @details This function returns the processor identification number.
 * For single core devices returns MAIN_CORE definition.
 * For multicore devices reads the SPR PIR register.
 *  
 * @notapi
 */
#define osal_getpir()                       MAIN_CORE
#endif /* _FROM_ASM_ */

#endif /* _OSAL_CFG_H_ */

/** @} */

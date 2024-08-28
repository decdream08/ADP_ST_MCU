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
 * @file    intc.h
 * @brief   INTC module header.
 *
 * @addtogroup PLATFORM
 * @{
 */

#ifndef _INTC_H_
#define _INTC_H_

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @brief   INTC base address.
 */
#define INTC_BASE                           0xF4044000U

/*lint -e9048 */
/* The following macros are include in assembler file. So suffixs 'U' or 'UL'
   are not allowed.*/
/**
 * @brief   Interrupt Acknowledge register base address.
 */
#define INTC_IACKR_BASE                     0xF4044020

/**
 * @brief   End of Interrupt register base address.
 */
#define INTC_EOIR_BASE                      0xF4044030
/*lint +e9048 */

/**
 * @brief   INTC PSR register definitions
 */
/* TODO    Some platforms support more than 16 priority levels.*/
#define INTC_PSR_PRIO_MASK                  0x000F

/**
 * @brief   Core selection macro for PSR register.
 */
#define INTC_PSR_CORE0                      0x8000

/**
 * @brief   Main Core selection macro for PSR register.
 */
#define INTC_PSR_MAINCORE                   INTC_PSR_CORE0

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

/**
 * @brief   INTC-related macros
 */
#define INTC_BCR                            (*((volatile uint32_t *)(INTC_BASE + 0U)))
#define INTC_CPR(n)                         (*((volatile uint32_t *)(INTC_BASE + 0x10U + ((uint8_t)(n) * sizeof (uint32_t)))))
#define INTC_IACKR(n)                       (*((volatile uint32_t *)(INTC_BASE + 0x20U + ((uint8_t)(n) * sizeof (uint32_t)))))
#define INTC_EOIR(n)                        (*((volatile uint32_t *)(INTC_BASE + 0x30U + ((uint8_t)(n) * sizeof (uint32_t)))))
#define INTC_SSCIR(n)                       (*((volatile uint8_t *) (INTC_BASE + 0x40U + ((uint8_t)(n) * sizeof (uint8_t)))))
#define INTC_PSR(n)                         (*((volatile uint16_t *)(INTC_BASE + 0x60U + ((uint16_t)(n) * sizeof (uint16_t)))))

/**
 * @brief   PSR register content helper
 */
#define INTC_PSR_ENABLE(cores, prio)        ((uint16_t)(cores) | (uint16_t)(prio))


/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

#endif /* _INTC_H_ */

/** @} */

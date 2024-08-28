/****************************************************************************
*
* Copyright © 2016-2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/

/**
 * @file    core.h
 * @brief   Core parameters for the SPC582Bxx.
 * @{
 */

#ifndef _CORE_H_
#define _CORE_H_

/**
 * @brief   Specific model identification macro.
 */
#define _SPC582B60E1_

/**
 * @brief   Family identification macro.
 */
#define _SPC582Bxx_

/**
 * @brief   Power e200z core model.
 */
#define CORE_VARIANT                2

/**
 * @brief   Main core number.
 */
#define MAIN_CORE                   0

/**
 * @brief   Number of writable bits in IVPR register.
 */
#define CORE_IVPR_BITS              24

/**
 * @brief   IVORx registers support.
 */
#define CORE_SUPPORTS_IVORS         0

/**
 * @brief   Book E instruction set support.
 */
#define CORE_SUPPORTS_BOOKE         0

/**
 * @brief   VLE instruction set support.
 */
#define CORE_SUPPORTS_VLE           1

/**
 * @brief   Supports VLS Load/Store Multiple Volatile instructions.
 */
#define CORE_SUPPORTS_VLE_MULTI     1

/**
 * @brief   Supports the decrementer timer.
 */
#define CORE_SUPPORTS_DECREMENTER   0

/**
 * @brief   Number of pins.
 */
#define CORE_PINS_NUMBER            64U

/**
 * @brief   type of package.
 */
#define CORE_MCU_PACKAGE            eTQFP64

#endif /* _CORE_H_ */

/** @} */

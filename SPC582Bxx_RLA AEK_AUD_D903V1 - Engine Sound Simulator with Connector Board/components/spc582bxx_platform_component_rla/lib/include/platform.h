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
 * @file    platform.h
 * @brief   platform file.
 */

#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include "core.h"
#include "toolchain.h"
#include "intc.h"
#if !defined(_FROM_ASM_)
#include "typedefs.h"
#include "spr.h"
#include "spc582b_registry.h"
#include "spc582b.h"
#endif

/**
 * @name    MCAN subsystems references
 * @{
 */
#define MCAN_IP_VER		         3U 
#define spc5_mcan                M_CAN_tag			 
#define CAN_SUB_0_RAM	         0xF7ED4000UL
#define CAN_SUB_0_RAM_SIZE		 7936U
#define CAN_SUB_1_RAM	         0xFBED4000UL
#define CAN_SUB_1_RAM_SIZE		 7936U
#define SPC5_MCAN_0              CAN_SUB_0_M_CAN_0
#define SPC5_MCAN_1              CAN_SUB_0_M_CAN_1
#define SPC5_MCAN_2              CAN_SUB_0_M_CAN_2
#define SPC5_MCAN_3              CAN_SUB_0_M_CAN_3
#define SPC5_MCAN_6              CAN_SUB_1_M_CAN_1
#define SPC5_MCAN_7              CAN_SUB_1_M_CAN_2
#define SPC5_MCAN_8              CAN_SUB_1_M_CAN_3
#define MCAN_ERROR_MASK          0x3FF60000UL
/** @} */

/**
 * @name    Clock Calibration Unit references
 * @{
 */
#define SPC5_CCCU_0              CCCU_0 
/** @} */

/**
 * @name    SARDADC References
 *
 * @{
 */
#define SPC5_SARADC_HAS_ALT_REFERENCE  FALSE
#define spc5_saradc	                   SARADC_tag
#define SPC5_SARADC12_SV			   SAR_ADC_12BIT_B0
/** @} */

#endif /* _PLATFORM_H_ */

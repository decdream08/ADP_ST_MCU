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
 * @file    aic_lld.h
 * @brief   SPC5xx AIC low level driver header.
 *
 * @addtogroup AIC
 * @{
 */
#ifndef _AIC_LLD_H_
#define _AIC_LLD_H_

#include <spc5_lld.h>
#include <lldconf.h>

#if (LLD_USE_AIC == TRUE) || defined(__DOXYGEN__)

/*******************************************************************************
* Includes
*******************************************************************************/

/*******************************************************************************
* Constants
*******************************************************************************/

#define SPC5_AIC_USER_WRITE_TEST_PASSWORD     0xF9F99999U

#define SPC5_AIC_ARRAY_INTEGRITY_DONE         0x00000001U
#define SPC5_AIC_ARRAY_INTEGRITY_ENABLE       0x00000002U
#define SPC5_AIC_ARRAY_INTEGRITY_SEQUENCE     0x00000004U
#define SPC5_AIC_USER_TEST_ENABLE             0x80000000U


/*******************************************************************************
* Macros 
*******************************************************************************/

#define SPC5_AIC_SELECT_BIT(_bit_)     (1UL << (_bit_))

/*******************************************************************************
* Types
*******************************************************************************/
/**
 * @brief   Type of a structure representing an AIC driver.
 */
typedef struct AICDriver AICDriver;

/**
 * @brief   Driver configuration structure for AIC.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
typedef struct {
  /**
   * @brief   Low address space blocks.
   */
  uint32_t    low;
  /**
   * @brief   Mid address space blocks.
   */
  uint32_t    mid;
  /**
   * @brief   High address space blocks.
   */
  uint32_t    high;
  /**
   * @brief   256 KB address space blocks (low).
   */
  uint32_t    A256;
  /**
   * @brief   256 KB address space blocks (high).
   */
  uint32_t    A256_H;
} AICConfig;


/*******************************************************************************
* Global variables
*******************************************************************************/

#ifndef __DOXYGEN__
extern AICDriver AICD1;
#endif /* __DOXYGEN__ */

/*******************************************************************************
* Global functions
*******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

void aic_lld_init(void);
void aic_lld_start(AICDriver *aicd, AICConfig *config);
void aic_lld_stop(AICDriver *aicd);
void aic_lld_calculate(AICDriver *aicd, uint32_t *signature);

#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_AIC */

#endif /* _AIC_LLD_H_ */
/** @} */

/****************************************************************************
*
* Copyright (c) 2017-2020 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    crc_lld.h
 * @brief   SPC5xx CRC low level driver header.
 *
 * @addtogroup CRC
 * @{
 */

#ifndef _CRC_LLD_H_
#define _CRC_LLD_H_

#include <spc5_lld.h>
#include <lldconf.h>

#if (LLD_USE_CRC == TRUE) || defined(__DOXYGEN__)

/**
 * @brief   CRCD1 Driver selection.
 */
#if !defined(SPC5_CRC_USE_CRC0) || defined(__DOXYGEN__)
#define SPC5_CRC_USE_CRC0        FALSE
#endif

/**
 * @brief   CRCD2 Driver selection.
 */
#if !defined(SPC5_CRC_USE_CRC1) || defined(__DOXYGEN__)
#define SPC5_CRC_USE_CRC1        FALSE
#endif

/**
 * @brief   CRCD3 Driver selection.
 */
#if !defined(SPC5_CRC_USE_CRC2) || defined(__DOXYGEN__)
#define SPC5_CRC_USE_CRC2        FALSE
#endif


/*******************************************************************************
* Types
*******************************************************************************/
/**
 * @brief   Type of a structure representing an CRC driver.
 */
typedef struct CRCDriver CRCDriver;

/**
 * @brief   Driver configuration structure for CRC Context.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
typedef struct {
  /**
   * @brief   CRC Context configuration.
   */
  uint32_t ctx_config;

  /**
   * @brief   Context polynomial seed.
   */
  uint32_t poly_seed;

} CRCContextConfig;


/**
 * @brief    CRC computation results
 */
typedef enum
{
  CRC_NO_ERROR,       /**< @brief   no errors. */
  CRC_ERROR_STATUS,   /**< @brief   some error happened on HW computation. */
  CRC_ERROR_MODULE,   /**< @brief   module not available. */
  CRC_ERROR_CONTEXT,  /**< @brief   context not available. */
  CRC_ERROR_DISABLED  /**< @brief   CRC not configured. */
} crc_result_t;

/*******************************************************************************
* Global variables
*******************************************************************************/

#if (SPC5_CRC_USE_CRC0 == TRUE) && !defined(__DOXYGEN__)
extern CRCDriver CRCD1;
#endif

#if (SPC5_CRC_USE_CRC1 == TRUE) && !defined(__DOXYGEN__)
extern CRCDriver CRCD2;
#endif

#if (SPC5_CRC_USE_CRC2 == TRUE) && !defined(__DOXYGEN__)
extern CRCDriver CRCD3;
#endif

/*******************************************************************************
* Global functions
*******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

void crc_lld_init(void);
crc_result_t crc_lld_start(CRCDriver *crcd);
crc_result_t crc_lld_stop(CRCDriver *crcd);
crc_result_t crc_lld_start_context(CRCDriver *crcd, uint8_t ctx_no, CRCContextConfig *config);
crc_result_t crc_lld_stop_context(CRCDriver *crcd, uint8_t ctx_no);
crc_result_t crc_lld_calc(CRCDriver *crcd, uint8_t ctx_no, uint8_t *msg, uint32_t msg_size, uint32_t *sign);

#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_CRC */
#endif /* _CRC_LLD_H_ */

/** @} */

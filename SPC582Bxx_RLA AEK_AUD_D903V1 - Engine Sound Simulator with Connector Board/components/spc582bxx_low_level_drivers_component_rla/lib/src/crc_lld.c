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
 * @file    crc_lld.c
 * @brief   SPC5xx CRC low level driver code.
 *
 * @addtogroup CRC
 * @{
 */
#include <crc_lld.h>

#if (LLD_USE_CRC == TRUE) || defined(__DOXYGEN__)

#include <crc_lld_cfg.h>

/*******************************************************************************
* Constants and macros
*******************************************************************************/
#define CRC_SEED_RESET		0xFFFFFFFFU


/*******************************************************************************
* Local types
*******************************************************************************/

/**
 * @brief   Structure representing a CRC driver.
 */
struct CRCDriver {

  volatile struct CRC_tag *crc;
  /**
   * @brief   CRC driver PCTL.
   */
  uint32_t   pctl;

  /**
   * @brief   Number of contexts for this driver instance.
   */
  uint32_t   no_ctx;

  /**
   * @brief   Active context configurations.
   */
  CRCContextConfig  *ctx_cfg;
};



/**
 * @brief   CRC driver instance #1.
 */
#if (SPC5_CRC_USE_CRC0 == TRUE)
CRCDriver CRCD1;
#endif
/**
 * @brief   CRC driver instance #2.
 */
#if (SPC5_CRC_USE_CRC1 == TRUE)
CRCDriver CRCD2;
#endif
/**
 * @brief   CRC driver instance #3.
 */
#if (SPC5_CRC_USE_CRC2 == TRUE)
CRCDriver CRCD3;
#endif

/*******************************************************************************
* Local functions
*******************************************************************************/

/*******************************************************************************
* Global functions
*******************************************************************************/
/**
 * @brief   Configure CRC system modules
 *
 * @api
 */
void crc_lld_init(void) {

#if (SPC5_CRC_USE_CRC0 == TRUE)
  CRCD1.crc = &CRC_0;
  CRCD1.pctl = SPC5_CRC_0_PTCL;
#endif
#if (SPC5_CRC_USE_CRC1 == TRUE)
  CRCD2.crc = &CRC_1;
  CRCD2.pctl = SPC5_CRC_1_PTCL;
#endif
#if (SPC5_CRC_USE_CRC2 == TRUE)
  CRCD3.crc = &CRC_2;
  CRCD3.pctl = SPC5_CRC_2_PTCL;
#endif
}


/**
 * @brief   Starts CRC module for signature calculation (enables peripheral clock)
 *
 * @param[in] crcd      pointer to the @p CRCDriver object
 *
 * @return              operation result
 *
 * @api
 */
crc_result_t crc_lld_start(CRCDriver *crcd) {
  SPCSetPeripheralClockMode(crcd->pctl, (SPC5_ME_PCTL_RUN(2) | SPC5_ME_PCTL_LP(2)));
  return CRC_NO_ERROR;
}


/**
 * @brief   Stops CRC module for signature calculation  (disables peripheral clock)
 *
 * @param[in] crcd      pointer to the @p CRCDriver object
 *
 * @return              operation result
 *
 * @api
 */
crc_result_t crc_lld_stop(CRCDriver *crcd) {
  SPCSetPeripheralClockMode(crcd->pctl, (SPC5_ME_PCTL_RUN(0) | SPC5_ME_PCTL_LP(0)));
  return CRC_NO_ERROR;
}


/**
 * @brief   Starts CRC context for signature calculation, applying a context configuration
 *
 * @param[in] crcd      pointer to the @p CRCDriver object
 * @param[in] ctx_no    number of Context to use for selected CRC module instance.
 * @param[in] config    pointer to the @p CRCContextConfig object
 *
 * @return              operation result
 *
 * @api
 */
crc_result_t crc_lld_start_context(CRCDriver *crcd, uint8_t ctx_no, CRCContextConfig *config) {

  if (ctx_no >= SPC5_CRC_CONTEXTS) {
    return CRC_ERROR_CONTEXT;
  }

  crcd->crc->CONTEXT[ctx_no].CFG.R = config->ctx_config;
  crcd->crc->CONTEXT[ctx_no].CSTAT.R = config->poly_seed;
  return CRC_NO_ERROR;
}


/**
 * @brief   Stops CRC context for signature calculation
 *
 * @param[in] crcd      pointer to the @p CRCDriver object
 * @param[in] ctx_no    number of Context to use for selected CRC module instance.
 *
 * @return              operation result
 *
 * @api
 */
crc_result_t crc_lld_stop_context(CRCDriver *crcd, uint8_t ctx_no) {

  if (ctx_no >= SPC5_CRC_CONTEXTS) {
    return CRC_ERROR_CONTEXT;
  }

  crcd->crc->CONTEXT[ctx_no].CFG.R = 0U;
  crcd->crc->CONTEXT[ctx_no].CSTAT.R = CRC_SEED_RESET;
  return CRC_NO_ERROR;
}


/**
 * @brief   Calculate CRC signature 
 *
 * @param[in] crcd      pointer to the @p CRCDriver object
 * @param[in] ctx_no    number of Context to use for selected CRC module instance.
 * @param[in] msg    	message to compute.
 * @param[in] msg_size  size of message to compute.
 * @param[out] sign     the final signature computed.
 *
 * @return              operation result
 *
 * @api
 */
crc_result_t crc_lld_calc(CRCDriver *crcd, uint8_t ctx_no, uint8_t *msg, uint32_t msg_size, uint32_t *sign) {
  uint32_t i;

  if (ctx_no >= SPC5_CRC_CONTEXTS) {
    return CRC_ERROR_CONTEXT;
  }

  for (i = 0U; i < msg_size; i++) {
    crcd->crc->CONTEXT[ctx_no].INP.BYTE[0] = msg[i];
  }
  *sign = crcd->crc->CONTEXT[ctx_no].OUTP.R;
  return CRC_NO_ERROR;
}

#endif /* LLD_USE_CRC */
/** @} */

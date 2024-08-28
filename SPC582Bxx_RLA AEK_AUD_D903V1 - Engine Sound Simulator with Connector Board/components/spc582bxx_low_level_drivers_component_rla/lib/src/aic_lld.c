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
 * @brief   SPC5xx AIC control unit.
 *
 * @addtogroup AIC
 * @{
 */

#include <aic_lld.h>

#if (LLD_USE_AIC == TRUE) || defined(__DOXYGEN__)

#include <aic_lld_cfg.h>

/*******************************************************************************
* External objects
*******************************************************************************/

/*******************************************************************************
* Global variables
*******************************************************************************/

/*******************************************************************************
* Constants and macros
*******************************************************************************/

/*******************************************************************************
* Local types
*******************************************************************************/

/**
 * @brief   AIC exec function (executed from run).
 */
typedef void (*AICExec)(vuint32_t *ut0);

/**
 * @brief   Structure representing an AIC driver.
 */
struct AICDriver {
  /**
   * @brief   Current AIC driver configuration.
   */
  AICConfig *config;

  /**
   * @brief   Flash driver register.
   */
  volatile struct FLASH_tag *flashp;
};

/*******************************************************************************
* Local function prototypes
*******************************************************************************/

/*******************************************************************************
* Local variables
*******************************************************************************/
/**
 * @brief   AIC driver instance.
 */
AICDriver AICD1;

/*******************************************************************************
* Local functions
*******************************************************************************/

static uint32_t aic_ram[32];

static void copy_to_ram(uint32_t *dst_addr) {
  extern uint32_t __start_aic_ram_section;
  extern uint32_t __stop_aic_ram_section;
  vuint8_t *dst = (vuint8_t *)dst_addr;
  vuint8_t *src;
  vuint8_t *end;

  src = (uint8_t *)(&__start_aic_ram_section);
  end = (uint8_t *)(&__stop_aic_ram_section);

  while (src <= end) {
    *dst++ = *src++;
  }
}


void start_aic_sequence(vuint32_t *ut0);
__attribute__((noinline, section("aic_ram_section"))) void start_aic_sequence(vuint32_t *ut0) {
  /*
   * Write the configuration on UT0, and then start the Integrity Check
   * with another write operation.
   */
  *ut0 = SPC5_AIC_USER_TEST_ENABLE | SPC5_AIC_ARRAY_INTEGRITY_SEQUENCE;
  *ut0 = SPC5_AIC_USER_TEST_ENABLE | SPC5_AIC_ARRAY_INTEGRITY_SEQUENCE | SPC5_AIC_ARRAY_INTEGRITY_ENABLE;

  /* Wait for the Array Integrity Check to finish. */
  while((*ut0 & SPC5_AIC_ARRAY_INTEGRITY_DONE) == 0U) { ; }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*******************************************************************************
* Global functions
*******************************************************************************/

/**
 * @brief   Initialize AIC driver
 *
 * @api
 */
void aic_lld_init(void) {
  AICD1.config = NULL;
  AICD1.flashp = &FLASH_0;
}


/**
 * @brief    AIC driver initialization.
 *
 * @details  The module will be initialized with a provided configuration structure.
 *
 * @param[in] aicd      pointer to the @p AICDriver object
 * @param[in] config    pointer to the @p AICConfig object
 *
 * @api
 */
void aic_lld_start(AICDriver *aicd, AICConfig *config) {
  aicd->config = config;
}


/**
 * @brief   Stops AIC module.
 *
 * @param[in] aicd      pointer to the @p AICDriver object
 *
 * @api
 */
void aic_lld_stop(AICDriver *aicd) {
  aicd->config = NULL;
}

/**
 * @brief   AIC calculate routine
 *
 * @param[in]     aicd         pointer to the @p AICDriver object
 * @param[out]    signature    pointer to the input seed and output signature
 *
 * @api
 */
void aic_lld_calculate(AICDriver *aicd, uint32_t *signature) {

  vuint32_t *p;
  uint32_t i;
  AICExec exec_aic_sequence;

  /* Set UTE in UTO:enable User test */
  aicd->flashp->UT0.R = SPC5_AIC_USER_WRITE_TEST_PASSWORD;

  /*
   * Select the block(s) to be checked by writing 1’s to the appropriate
   * register(s) in SEL0, SEL1 and/or SEL2 registers
   * See Reference Manual, section "Flash array memory map".
   */

  /*
   * Low/Mid Address Space Block Select 0
   * Mid Address Space Block Select 0
   */
  aicd->flashp->SEL0.R = ((aicd->config->low << 16U) & 0xFFFF0000U) | (aicd->config->mid & 0x0000FFFFU);

  /* High Address Space Block Select Register 1 */
  aicd->flashp->SEL1.R = aicd->config->high;

  /* 256K Address Space Block Select 2 */
  aicd->flashp->SEL2.R = aicd->config->A256;

  /* 256K Address Space Block Select 3 */
  aicd->flashp->SEL3.R = aicd->config->A256_H;

  /* Feed UM0-UM9 with desired values */
  p = &aicd->flashp->UM0.R;
  for (i = 0U; i < 10U; i++) {
    if (((SPC5_AIC_UM_REGS_MASK >> i) & 1U) != 0U) {
      *p = signature[i];
    }
    p++;
  }

  /*lint -e740 */
  /*lint -e9074 */
  /*lint -e9087 */
  exec_aic_sequence = (AICExec)aic_ram;
  /*lint +e9087 */
  /*lint +e9074 */
  /*lint +e740 */

  copy_to_ram(aic_ram);

  /* No interrupts are allowed in this function */
  irqIsrDisable();

  exec_aic_sequence(&aicd->flashp->UT0.R);

  /* Enable interrupts */
  irqIsrEnable();

  /* Return UM0–UM9 content with the expected result. */
  p = &aicd->flashp->UM0.R;
  for (i = 0U; i < 10U; i++) {
    if (((SPC5_AIC_UM_REGS_MASK >> i) & 1U) != 0U) {
      signature[i] = *p;
    } else {
      signature[i] = 0U;
    }
    p++;
  }

  /* Write a logic '0' to the UT0.AIE bit. */
  aicd->flashp->UT0.R = SPC5_AIC_USER_TEST_ENABLE | SPC5_AIC_ARRAY_INTEGRITY_SEQUENCE;
}

#endif /* LLD_USE_AIC */
/** @} */


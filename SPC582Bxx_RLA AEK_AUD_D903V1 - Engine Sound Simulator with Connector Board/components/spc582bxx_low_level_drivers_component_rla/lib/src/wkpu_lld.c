/****************************************************************************
*
* Copyright © 2018-2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    wkpu_lld.c
 * @brief   SPC5xx WKPU low level driver code.
 *
 * @addtogroup WKPU
 * @{
 */

#include "wkpu_lld.h"

#if (LLD_USE_WKPU == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   WKPU0 driver identifier.
 */
#if (SPC5_WKPU_USE_WKPU0 == TRUE) || defined(__DOXYGEN__)
WKPUDriver WKPUD1;
#endif

/**
 * @brief   WKPU1 driver identifier.
 */
#if (SPC5_WKPU_USE_WKPU1 == TRUE) || defined(__DOXYGEN__)
WKPUDriver WKPUD2;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if (SPC5_WKPU_SUPPORT_EXT_SRC == TRUE) || defined(__DOXYGEN__)
#if (SPC5_WKPU_USE_WKPU0 == TRUE) || defined(__DOXYGEN__)
#if !defined(SPC5_WKPU0_IRQ0_HANDLER)
#error "SPC5_WKPU0_IRQ0_HANDLER not defined"
#endif
/**
 * @brief   WKPU0 interrupt 0 handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_WKPU0_IRQ0_HANDLER) {

  uint8_t wisr, i;

  IRQ_PROLOGUE();

  wisr = (uint8_t)(WKPUD1.wkpup->WISR.R & 0x000000FFUL);

  for (i = 0; i < 8U; i++) {
    if ((((wisr >> i) & 0x1U) == 1U) && (WKPUD1.config->wk_config[i]->irq_en == TRUE)){
      /* Clear interrupt.*/
      WKPUD1.wkpup->WISR.R = 0x1UL << i;
      /* If defined, invoke the interrupt callback function.*/
      if (WKPUD1.config->wk_config[i]->irq_cb != NULL) {
        WKPUD1.config->wk_config[i]->irq_cb(&WKPUD1);
      }
    }
  }

  IRQ_EPILOGUE();
}

#if !defined(SPC5_WKPU0_IRQ1_HANDLER)
#error "SPC5_WKPU0_IRQ1_HANDLER not defined"
#endif
/**
 * @brief   WKPU0 interrupt 1 handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_WKPU0_IRQ1_HANDLER) {

  uint8_t wisr, i;

  IRQ_PROLOGUE();

  wisr = (uint8_t)((WKPUD1.wkpup->WISR.R & 0x0000FF00UL) >> 8U);

  for (i = 0; i < 8U; i++) {
    if ((((wisr >> i) & 0x1U) == 1U) && (WKPUD1.config->wk_config[i + 8U]->irq_en == TRUE)){
      /* Clear interrupt.*/
      WKPUD1.wkpup->WISR.R = 0x1UL << (i + 8U);
      /* If defined, invoke the interrupt callback function.*/
      if (WKPUD1.config->wk_config[i + 8U]->irq_cb != NULL) {
        WKPUD1.config->wk_config[i + 8U]->irq_cb(&WKPUD1);
      }
    }
  }

  IRQ_EPILOGUE();
}

#if !defined(SPC5_WKPU0_IRQ2_HANDLER)
#error "SPC5_WKPU0_IRQ2_HANDLER not defined"
#endif
/**
 * @brief   WKPU0 interrupt 2 handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_WKPU0_IRQ2_HANDLER) {

  uint8_t wisr, i;

  IRQ_PROLOGUE();

  wisr = (uint8_t)((WKPUD1.wkpup->WISR.R & 0x00FF0000UL) >> 16U);

  for (i = 0; i < 8U; i++) {
    if ((((wisr >> i) & 0x1U) == 1U) && (WKPUD1.config->wk_config[i + 16U]->irq_en == TRUE)){
      /* Clear interrupt.*/
      WKPUD1.wkpup->WISR.R = 0x1UL << (i + 16U);
      /* If defined, invoke the interrupt callback function.*/
      if (WKPUD1.config->wk_config[i + 16U]->irq_cb != NULL) {
        WKPUD1.config->wk_config[i + 16U]->irq_cb(&WKPUD1);
      }
    }
  }

  IRQ_EPILOGUE();
}

#if !defined(SPC5_WKPU0_IRQ3_HANDLER)
#error "SPC5_WKPU0_IRQ3_HANDLER not defined"
#endif
/**
 * @brief   WKPU0 interrupt 3 handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_WKPU0_IRQ3_HANDLER) {

  uint8_t wisr, i;

  IRQ_PROLOGUE();

  wisr = (uint8_t)((WKPUD1.wkpup->WISR.R & 0xFF000000UL) >> 24U);

  for (i = 0; i < 8U; i++) {
    if ((((wisr >> i) & 0x1U) == 1U) && (WKPUD1.config->wk_config[i + 24U]->irq_en == TRUE)){
      /* Clear interrupt.*/
      WKPUD1.wkpup->WISR.R = 0x1UL << (i + 24U);
      /* If defined, invoke the interrupt callback function.*/
      if (WKPUD1.config->wk_config[i + 24U]->irq_cb != NULL) {
        WKPUD1.config->wk_config[i + 24U]->irq_cb(&WKPUD1);
      }
    }
  }

  IRQ_EPILOGUE();
}
#endif /* SPC5_WKPU_USE_WKPU0 */

#if (SPC5_WKPU_USE_WKPU1 == TRUE) || defined(__DOXYGEN__)
#if !defined(SPC5_WKPU1_IRQ0_HANDLER)
#error "SPC5_WKPU1_IRQ0_HANDLER not defined"
#endif
/**
 * @brief   WKPU1 interrupt 0 handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_WKPU1_IRQ0_HANDLER) {

  uint8_t wisr, i;

  IRQ_PROLOGUE();

  wisr = (uint8_t)(WKPUD2.wkpup->WISR.R & 0x000000FFUL);

  for (i = 0; i < 8U; i++) {
    if ((((wisr >> i) & 0x1U) == 1U) && (WKPUD2.config->wk_config[i]->irq_en == TRUE)){
      /* Clear interrupt.*/
      WKPUD2.wkpup->WISR.R = 0x1UL << i;
      /* If defined, invoke the interrupt callback function.*/
      if (WKPUD2.config->wk_config[i]->irq_cb != NULL) {
        WKPUD2.config->wk_config[i]->irq_cb(&WKPUD2);
      }
    }
  }

  IRQ_EPILOGUE();
}

#if !defined(SPC5_WKPU1_IRQ1_HANDLER)
#error "SPC5_WKPU1_IRQ1_HANDLER not defined"
#endif
/**
 * @brief   WKPU1 interrupt 1 handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_WKPU1_IRQ1_HANDLER) {

  uint8_t wisr, i;

  IRQ_PROLOGUE();

  wisr = (uint8_t)((WKPUD2.wkpup->WISR.R & 0x0000FF00UL) >> 8U);

  for (i = 0; i < 8U; i++) {
    if ((((wisr >> i) & 0x1U) == 1U) && (WKPUD2.config->wk_config[i + 8U]->irq_en == TRUE)){
      /* Clear interrupt.*/
      WKPUD2.wkpup->WISR.R = 0x1UL << (i + 8U);
      /* If defined, invoke the interrupt callback function.*/
      if (WKPUD2.config->wk_config[i + 8U]->irq_cb != NULL) {
        WKPUD2.config->wk_config[i + 8U]->irq_cb(&WKPUD2);
      }
    }
  }

  IRQ_EPILOGUE();
}

#if !defined(SPC5_WKPU1_IRQ2_HANDLER)
#error "SPC5_WKPU1_IRQ2_HANDLER not defined"
#endif
/**
 * @brief   WKPU1 interrupt 2 handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_WKPU1_IRQ2_HANDLER) {

  uint8_t wisr, i;

  IRQ_PROLOGUE();

  wisr = (uint8_t)((WKPUD2.wkpup->WISR.R & 0x00FF0000UL) >> 16U);

  for (i = 0; i < 8U; i++) {
    if ((((wisr >> i) & 0x1U) == 1U) && (WKPUD2.config->wk_config[i + 16U]->irq_en == TRUE)){
      /* Clear interrupt.*/
      WKPUD2.wkpup->WISR.R = 0x1UL << (i + 16U);
      /* If defined, invoke the interrupt callback function.*/
      if (WKPUD2.config->wk_config[i + 16U]->irq_cb != NULL) {
        WKPUD2.config->wk_config[i + 16U]->irq_cb(&WKPUD2);
      }
    }
  }

  IRQ_EPILOGUE();
}

#if !defined(SPC5_WKPU1_IRQ3_HANDLER)
#error "SPC5_WKPU1_IRQ3_HANDLER not defined"
#endif
/**
 * @brief   WKPU1 interrupt 3 handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_WKPU1_IRQ3_HANDLER) {

  uint8_t wisr, i;

  IRQ_PROLOGUE();

  wisr = (uint8_t)((WKPUD2.wkpup->WISR.R & 0xFF000000UL) >> 24U);

  for (i = 0; i < 8U; i++) {
    if ((((wisr >> i) & 0x1U) == 1U) && (WKPUD2.config->wk_config[i + 24U]->irq_en == TRUE)){
      /* Clear interrupt.*/
      WKPUD2.wkpup->WISR.R = 0x1UL << (i + 24U);
      /* If defined, invoke the interrupt callback function.*/
      if (WKPUD2.config->wk_config[i + 24U]->irq_cb != NULL) {
        WKPUD2.config->wk_config[i + 24U]->irq_cb(&WKPUD2);
      }
    }
  }

  IRQ_EPILOGUE();
}
#endif /* SPC5_WKPU_USE_WKPU1 */
#endif /* SPC5_WKPU_SUPPORT_EXT_SRC */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level WKPU driver initialization.
 *
 * @init
 */
void wkpu_lld_init(void) {

#if (SPC5_WKPU_USE_WKPU0 == TRUE)
  /* Set driver registers base address.*/
  WKPUD1.wkpup = &SPC5_WKPU0;

  /* Disable NMI interrupts.*/
  WKPUD1.wkpup->NCR.R = 0x0UL;

#if (SPC5_WKPU_SUPPORT_EXT_SRC == TRUE)
  /* Disable interrupt requests.*/
  WKPUD1.wkpup->IRER.R = 0x0UL;

  /* Disable wakeup requests.*/
  WKPUD1.wkpup->WRER.R = 0x0UL;

  /* Disable wakeup/interrupt rising-edge events.*/
  WKPUD1.wkpup->WIREER.R = 0x0UL;

  /* Disable wakeup/interrupt falling-edge events.*/
  WKPUD1.wkpup->WIFEER.R = 0x0UL;

  /* Disable wakeup/interrupt filters.*/
  WKPUD1.wkpup->WIFER.R = 0x0UL;

  /* Disable wakeup/interrupt pullups.*/
  WKPUD1.wkpup->WIPUER.R = 0x0UL;
#endif /* SPC5_WKPU_SUPPORT_EXT_SRC */

  /* Clear NMI Status Flag Register.*/
  WKPUD1.wkpup->NSR.R = 0xC0C0C0C0UL;

#if (SPC5_WKPU_SUPPORT_EXT_SRC == TRUE)
  /* Clear Wakeup/Interrupt Status Flag Register.*/
  WKPUD1.wkpup->WISR.R = 0xFFFFFFFFUL;

  /* Initialize interrupt priorities.*/
  INTC_PSR(SPC5_WKPU0_IRQ0_INT_NUMBER) = SPC5_WKPU0_IRQ0_PRIORITY;
  INTC_PSR(SPC5_WKPU0_IRQ1_INT_NUMBER) = SPC5_WKPU0_IRQ1_PRIORITY;
  INTC_PSR(SPC5_WKPU0_IRQ2_INT_NUMBER) = SPC5_WKPU0_IRQ2_PRIORITY;
  INTC_PSR(SPC5_WKPU0_IRQ3_INT_NUMBER) = SPC5_WKPU0_IRQ3_PRIORITY;
#endif /* SPC5_WKPU_SUPPORT_EXT_SRC */
#endif /* SPC5_WKPU_USE_WKPU0 */

#if (SPC5_WKPU_USE_WKPU1 == TRUE)
  /* Set driver registers base address.*/
  WKPUD2.wkpup = &SPC5_WKPU1;

#if (SPC5_WKPU_SUPPORT_EXT_SRC == TRUE)
  /* Disable interrupt requests.*/
  WKPUD2.wkpup->IRER.R = 0x0UL;

  /* Disable wakeup requests.*/
  WKPUD2.wkpup->WRER.R = 0x0UL;

  /* Disable wakeup/interrupt rising-edge events.*/
  WKPUD2.wkpup->WIREER.R = 0x0UL;

  /* Disable wakeup/interrupt falling-edge events.*/
  WKPUD2.wkpup->WIFEER.R = 0x0UL;

  /* Disable wakeup/interrupt filters.*/
  WKPUD2.wkpup->WIFER.R = 0x0UL;

  /* Disable wakeup/interrupt pullups.*/
  WKPUD2.wkpup->WIPUER.R = 0x0UL;

  /* Clear Wakeup/Interrupt Status Flag Register.*/
  WKPUD2.wkpup->WISR.R = 0xFFFFFFFFUL;

  /* Initialize interrupt priorities.*/
  INTC_PSR(SPC5_WKPU1_IRQ0_INT_NUMBER) = SPC5_WKPU1_IRQ0_PRIORITY;
  INTC_PSR(SPC5_WKPU1_IRQ1_INT_NUMBER) = SPC5_WKPU1_IRQ1_PRIORITY;
  INTC_PSR(SPC5_WKPU1_IRQ2_INT_NUMBER) = SPC5_WKPU1_IRQ2_PRIORITY;
  INTC_PSR(SPC5_WKPU1_IRQ3_INT_NUMBER) = SPC5_WKPU1_IRQ3_PRIORITY;
#endif /* SPC5_WKPU_SUPPORT_EXT_SRC */
#endif /* SPC5_WKPU_USE_WKPU1 */
}

/**
 * @brief   Low level WKPU driver configuration and start.
 *
 * @param[in] wkpudp    pointer to a @p WKPUDriver object
 * @param[in] config    the architecture-dependent WKPU driver configuration.
 *
 * @api
 */
void wkpu_lld_start(WKPUDriver *wkpudp, WKPUConfig *config) {

  uint8_t i;
#if (SPC5_WKPU_USE_WKPU0 == TRUE)
  uint32_t nmi_src_cfg;
#endif

  wkpudp->config = config;

#if (SPC5_WKPU_USE_WKPU0 == TRUE)
  if (&WKPUD1 == wkpudp) {
    /* Configure NMI sources.*/
    for (i = 0; i < 4U; i++) {
      nmi_src_cfg = 0UL;
      if (wkpudp->config->nmi_config[i] != NULL ) {
        /* NMI Filter enable.*/
        if (wkpudp->config->nmi_config[i]->filter_en == TRUE) {
          nmi_src_cfg |= 0x1UL;
        }
        /* NMI Falling-Edge Events enable.*/
        if (wkpudp->config->nmi_config[i]->fe_en == TRUE) {
          nmi_src_cfg |= 0x2UL;
        }
        /* NMI Rising-Edge Events enable.*/
        if (wkpudp->config->nmi_config[i]->re_en == TRUE) {
          nmi_src_cfg |= 0x4UL;
        }
        /* NMI Wakeup Request enable.*/
        if (wkpudp->config->nmi_config[i]->wk_en == TRUE) {
          nmi_src_cfg |= 0x10UL;
        }
        /* NMI Destination source selection.*/
        nmi_src_cfg |= (uint32_t)wkpudp->config->nmi_config[i]->destination << 5U;
        /* NMI Lock enable.*/
        if (wkpudp->config->nmi_config[i]->lock_en == TRUE) {
          nmi_src_cfg |= 0x80UL;
        }
        wkpudp->wkpup->NCR.R |= nmi_src_cfg << (i * 8U);
      }
    }
  }
#endif

#if (SPC5_WKPU_SUPPORT_EXT_SRC == TRUE)
  /* Configure Wakeup sources.*/
  for (i = 0; i < 32U; i++) {
    if (wkpudp->config->wk_config[i] != NULL ) {
      /* Wakeup Request enable.*/
      if (wkpudp->config->wk_config[i]->wk_en == TRUE) {
        wkpudp->wkpup->WRER.R |= (1UL << i);
      }
      /* Interrupt Request enable.*/
      if (wkpudp->config->wk_config[i]->irq_en == TRUE) {
        wkpudp->wkpup->IRER.R |= (1UL << i);
      }
      /* Wakeup/Interrupt Rising-Edge enable.*/
      if (wkpudp->config->wk_config[i]->re_en == TRUE) {
        wkpudp->wkpup->WIREER.R |= (1UL << i);
      }
      /* Wakeup/Interrupt Falling-Edge enable.*/
      if (wkpudp->config->wk_config[i]->fe_en == TRUE) {
        wkpudp->wkpup->WIFEER.R |= (1UL << i);
      }
      /* Wakeup/Interrupt Filter enable.*/
      if (wkpudp->config->wk_config[i]->filter_en == TRUE) {
        wkpudp->wkpup->WIFER.R |= (1UL << i);
      }
      /* Wakeup/Interrupt Pullup enable.*/
      if (wkpudp->config->wk_config[i]->pu_en == TRUE) {
        wkpudp->wkpup->WIPUER.R |= (1UL << i);
      }
    }
  }
#endif /* SPC5_WKPU_SUPPORT_EXT_SRC */
}

/**
 * @brief   Low level WKPU driver stop.
 *
 * @param[in] wkpudp    pointer to a @p WKPUDriver object
 *
 * @api
 */
void wkpu_lld_stop(WKPUDriver *wkpudp) {

#if (SPC5_WKPU_USE_WKPU0 == TRUE)
  if (&WKPUD1 == wkpudp) {
    /* Disable NMI interrupts.*/
    wkpudp->wkpup->NCR.R = 0x0UL;
  }
#endif /* SPC5_WKPU_USE_WKPU0 */

#if (SPC5_WKPU_SUPPORT_EXT_SRC == TRUE)
  /* Disable interrupt requests.*/
  wkpudp->wkpup->IRER.R = 0x0UL;

  /* Disable wakeup requests.*/
  wkpudp->wkpup->WRER.R = 0x0UL;

  /* Disable wakeup/interrupt rising-edge events.*/
  wkpudp->wkpup->WIREER.R = 0x0UL;

  /* Disable wakeup/interrupt falling-edge events.*/
  wkpudp->wkpup->WIFEER.R = 0x0UL;

  /* Disable wakeup/interrupt filters.*/
  wkpudp->wkpup->WIFER.R = 0x0UL;

  /* Disable wakeup/interrupt pullups.*/
  wkpudp->wkpup->WIPUER.R = 0x0UL;
#endif /* SPC5_WKPU_SUPPORT_EXT_SRC */

#if (SPC5_WKPU_USE_WKPU0 == TRUE)
  if (&WKPUD1 == wkpudp) {
    /* Clear NMI Status Flag Register.*/
    wkpudp->wkpup->NSR.R = 0xC0C0C0C0UL;
  }
#endif /* SPC5_WKPU_USE_WKPU0 */

#if (SPC5_WKPU_SUPPORT_EXT_SRC == TRUE)
  /* Clear Wakeup/Interrupt Status Flag Register.*/
  wkpudp->wkpup->WISR.R = 0xFFFFFFFFUL;
#endif /* SPC5_WKPU_SUPPORT_EXT_SRC */
}

#endif /* LLD_USE_WKPU */

/** @} */

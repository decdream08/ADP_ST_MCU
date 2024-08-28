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
 * @file    wkpu_lld.h
 * @brief   SPC5xx WKPU low level driver header.
 *
 * @addtogroup WKPU
 * @{
 */

#ifndef _WKPU_LLD_H_
#define _WKPU_LLD_H_

#include "spc5_lld.h"
#include "lldconf.h"

#if (LLD_USE_WKPU == TRUE) || defined(__DOXYGEN__)

#include "spc5_wkpu.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    WKPU NMI Destination Source Selection
 * @{
 */
#define SPC5_WKPU_DES_NON_MASKABLE_INT      0x0U
#define SPC5_WKPU_DES_CRITICAL_INT          0x1U
#define SPC5_WKPU_DES_MACHINE_CHECK_REQ     0x2U
#define SPC5_WKPU_DES_RESET_REQ             0x3U
#define SPC5_WKPU_DES_RESET_REQ_TO_RGM      0x0U
#define SPC5_WKPU_DES_NO_REACTION           0x1U
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   WKPU0 driver enable switch.
 * @details If set to @p TRUE the support for WKPU0 is included.
 */
#if !defined(SPC5_WKPU_USE_WKPU0) || defined(__DOXYGEN__)
#define SPC5_WKPU_USE_WKPU0                 FALSE
#endif

/**
 * @brief   WKPU1 driver enable switch.
 * @details If set to @p TRUE the support for WKPU1 is included.
 */
#if !defined(SPC5_WKPU_USE_WKPU1) || defined(__DOXYGEN__)
#define SPC5_WKPU_USE_WKPU1                 FALSE
#endif

#if (SPC5_WKPU_SUPPORT_EXT_SRC == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   WKPU0 interrupt 0 priority level setting.
 */
#if !defined(SPC5_WKPU0_IRQ0_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_WKPU0_IRQ0_PRIORITY            INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#endif

/**
 * @brief   WKPU0 interrupt 1 priority level setting.
 */
#if !defined(SPC5_WKPU0_IRQ1_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_WKPU0_IRQ1_PRIORITY            INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#endif

/**
 * @brief   WKPU0 interrupt 2 priority level setting.
 */
#if !defined(SPC5_WKPU0_IRQ2_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_WKPU0_IRQ2_PRIORITY            INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#endif

/**
 * @brief   WKPU0 interrupt 3 priority level setting.
 */
#if !defined(SPC5_WKPU0_IRQ3_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_WKPU0_IRQ3_PRIORITY            INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#endif

/**
 * @brief   WKPU1 interrupt 0 priority level setting.
 */
#if !defined(SPC5_WKPU1_IRQ0_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_WKPU1_IRQ0_PRIORITY            INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#endif

/**
 * @brief   WKPU1 interrupt 1 priority level setting.
 */
#if !defined(SPC5_WKPU1_IRQ1_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_WKPU1_IRQ1_PRIORITY            INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#endif

/**
 * @brief   WKPU1 interrupt 2 priority level setting.
 */
#if !defined(SPC5_WKPU1_IRQ2_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_WKPU1_IRQ2_PRIORITY            INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#endif

/**
 * @brief   WKPU1 interrupt 3 priority level setting.
 */
#if !defined(SPC5_WKPU1_IRQ3_PRIORITY) || defined(__DOXYGEN__)
#define SPC5_WKPU1_IRQ3_PRIORITY            INTC_PSR_ENABLE(INTC_PSR_MAINCORE, 8)
#endif
#endif /* SPC5_WKPU_SUPPORT_EXT_SRC */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if (SPC5_WKPU_USE_WKPU0 == TRUE) && (SPC5_HAS_WKPU0 == FALSE)
#error "WKPU0 not present in the selected device"
#endif

#if (SPC5_WKPU_USE_WKPU1 == TRUE) && (SPC5_HAS_WKPU1 == FALSE)
#error "WKPU1 not present in the selected device"
#endif

#if (SPC5_WKPU_USE_WKPU0 == FALSE) && (SPC5_WKPU_USE_WKPU1 == FALSE)
#error "WKPU driver activated but no WKPU peripheral assigned"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a structure representing a WKPU driver.
 */
typedef struct WKPUDriver WKPUDriver;

/**
 * @brief   WKPU notification callback type.
 *
 * @param[in] wkpup     pointer to the @p WKPUDriver object triggering the
 *                      callback
 */
typedef void (*wkpucallback_t)(WKPUDriver *wkpudp);

/**
 * @brief   NMI configuration structure.
 */
typedef struct {
  /**
   * @brief   Flag set if the Wakeup Request is enabled.
   */
  uint8_t                   wk_en;
  /**
   * @brief   Destination source selection.
   */
  uint8_t                   destination;
  /**
   * @brief   Flag set if the Rising-Edge Event is enabled.
   */
  uint8_t                   re_en;
  /**
   * @brief   Flag set if the Falling-Edge Event is enabled.
   */
  uint8_t                   fe_en;
  /**
   * @brief   Flag set if the Filter is enabled.
   */
  uint8_t                   filter_en;
  /**
   * @brief   Flag set if the Lock is enabled.
   */
  uint8_t                   lock_en;
} NMIConfig;

#if (SPC5_WKPU_SUPPORT_EXT_SRC == TRUE)
/**
 * @brief   Wakeup configuration structure.
 */
typedef struct {
  /**
   * @brief   Flag set if the Wakeup Request is enabled.
   */
  uint8_t                   wk_en;
  /**
   * @brief   Flag set if the Interrupt Request is enabled.
   */
  uint8_t                   irq_en;
  /**
   * @brief   Callback function related to the IRQ.
   */
  wkpucallback_t            irq_cb;
  /**
   * @brief   Flag set if the Rising-Edge Event is enabled.
   */
  uint8_t                   re_en;
  /**
   * @brief   Flag set if the Falling-Edge Event is enabled.
   */
  uint8_t                   fe_en;
  /**
   * @brief   Flag set if the Filter is enabled.
   */
  uint8_t                   filter_en;
  /**
   * @brief   Flag set if the Pullup is enabled.
   */
  uint8_t                   pu_en;
} WakeupConfig;
#endif /* SPC5_WKPU_SUPPORT_EXT_SRC */

/**
 * @brief   WKPU driver configuration structure.
 */
typedef struct {
  /**
   * @brief   NMI configuration.
   */
  NMIConfig           *nmi_config[4];
#if (SPC5_WKPU_SUPPORT_EXT_SRC == TRUE)
  /**
   * @brief   Wakeup configuration.
   */
  WakeupConfig        *wk_config[32];
#endif /* SPC5_WKPU_SUPPORT_EXT_SRC */

} WKPUConfig;

/**
 * @brief   Structure representing an WKPU driver.
 */
struct WKPUDriver {
  /**
   * @brief   Current configuration data.
   */
  WKPUConfig          *config;
  /**
   * @brief   Pointer to the WKPU registers block.
   */
  volatile struct spc5_wkpu *wkpup;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* IRQ Handlers                                                              */
/*===========================================================================*/

#if (SPC5_WKPU_SUPPORT_EXT_SRC == TRUE) || defined(__DOXYGEN__)
#if (SPC5_WKPU_USE_WKPU0 == TRUE) || defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_WKPU0_IRQ0_HANDLER);
IRQ_HANDLER(SPC5_WKPU0_IRQ1_HANDLER);
IRQ_HANDLER(SPC5_WKPU0_IRQ2_HANDLER);
IRQ_HANDLER(SPC5_WKPU0_IRQ3_HANDLER);
#endif /* SPC5_WKPU_USE_WKPU0 */
#if (SPC5_WKPU_USE_WKPU1 == TRUE) || defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_WKPU1_IRQ0_HANDLER);
IRQ_HANDLER(SPC5_WKPU1_IRQ1_HANDLER);
IRQ_HANDLER(SPC5_WKPU1_IRQ2_HANDLER);
IRQ_HANDLER(SPC5_WKPU1_IRQ3_HANDLER);
#endif /* SPC5_WKPU_USE_WKPU1 */
#endif /* SPC5_WKPU_SUPPORT_EXT_SRC */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (SPC5_WKPU_USE_WKPU0 == TRUE) && !defined(__DOXYGEN__)
extern WKPUDriver WKPUD1;
#endif
#if (SPC5_WKPU_USE_WKPU1 == TRUE) && !defined(__DOXYGEN__)
extern WKPUDriver WKPUD2;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void wkpu_lld_init(void);
  void wkpu_lld_start(WKPUDriver *wkpudp, WKPUConfig *config);
  void wkpu_lld_stop(WKPUDriver *wkpudp);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_WKPU */

#endif /* _WKPU_LLD_H_ */

/** @} */

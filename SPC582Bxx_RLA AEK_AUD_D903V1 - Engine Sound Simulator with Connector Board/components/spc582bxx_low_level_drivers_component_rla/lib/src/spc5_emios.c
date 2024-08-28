/****************************************************************************
*
* Copyright © 2017-2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    spc5_emios.c
 * @brief   SPC5xx ICU-PWM low level drivers common code.
 *
 * @addtogroup SPC5xx_eMIOS
 * @{
 */

#include "spc5_emios.h"
#include "pwm_lld.h"
#include "icu_lld.h"

#if (LLD_USE_ICU == TRUE) || (LLD_USE_PWM == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   EMIOS0 data identifier.
 */
#if (SPC5_HAS_EMIOS0 == TRUE) && !defined(__DOXYGEN__)
EMIOSData EMIOS0D;
#endif

/**
 * @brief   EMIOS1 data identifier.
 */
#if (SPC5_HAS_EMIOS1 == TRUE) && !defined(__DOXYGEN__)
EMIOSData EMIOS1D;
#endif

/**
 * @brief   EMIOS2 data identifier.
 */
#if (SPC5_HAS_EMIOS2 == TRUE) && !defined(__DOXYGEN__)
EMIOSData EMIOS2D;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Returnes the eMIOSx GFLAG register value.
 *
 * @param[in] emiosdp   pointer to the eMIOSx registers block.
 *
 * @notapi
 */
static uint32_t emios_get_gfr(EMIOSData *emiosdp) {

  return emiosdp->emiosp->GFLAG.R;
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if (SPC5_ICU_USE_EMIOS0_CH0 == TRUE) || (SPC5_ICU_USE_EMIOS0_CH1 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_CH0 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH1 == TRUE)
#if !defined(SPC5_EMIOS0_GFR_F0F1_HANDLER)
#error "SPC5_EMIOS0_GFR_F0F1_HANDLER not defined"
#endif
/**
 * @brief   eMIOS0 Channels 0 and 1 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS0_GFR_F0F1_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS0D);

  if ((gfr & (1UL << 0U)) != 0U) {
#if (SPC5_ICU_USE_EMIOS0_CH0 == TRUE)
    icu_lld_serve_interrupt(&ICUD1);
#elif (SPC5_PWM_USE_EMIOS0_CH0 == TRUE)
    pwm_lld_serve_single_channel_interrupt(&PWMD1);
#endif
  }
  if ((gfr & (1UL << 1U)) != 0U) {
#if (SPC5_ICU_USE_EMIOS0_CH1 == TRUE)
    icu_lld_serve_interrupt(&ICUD2);
#elif (SPC5_PWM_USE_EMIOS0_CH1 == TRUE)
    pwm_lld_serve_single_channel_interrupt(&PWMD2);
#endif
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_ICU_USE_EMIOS0_CH2 == TRUE) || (SPC5_ICU_USE_EMIOS0_CH3 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_CH2 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH3 == TRUE)
#if !defined(SPC5_EMIOS0_GFR_F2F3_HANDLER)
#error "SPC5_EMIOS0_GFR_F2F3_HANDLER not defined"
#endif
/**
 * @brief   eMIOS0 Channels 2 and 3 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS0_GFR_F2F3_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS0D);

  if ((gfr & (1UL << 2U)) != 0U) {
#if (SPC5_ICU_USE_EMIOS0_CH2 == TRUE)
    icu_lld_serve_interrupt(&ICUD3);
#elif (SPC5_PWM_USE_EMIOS0_CH2 == TRUE)
    pwm_lld_serve_single_channel_interrupt(&PWMD3);
#endif
  }
  if ((gfr & (1UL << 3U)) != 0U) {
#if (SPC5_ICU_USE_EMIOS0_CH3 == TRUE)
    icu_lld_serve_interrupt(&ICUD4);
#elif (SPC5_PWM_USE_EMIOS0_CH3 == TRUE)
    pwm_lld_serve_single_channel_interrupt(&PWMD4);
#endif
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_ICU_USE_EMIOS0_CH4 == TRUE) || (SPC5_ICU_USE_EMIOS0_CH5 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_CH4 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH5 == TRUE)
#if !defined(SPC5_EMIOS0_GFR_F4F5_HANDLER)
#error "SPC5_EMIOS0_GFR_F4F5_HANDLER not defined"
#endif
/**
 * @brief   eMIOS0 Channels 4 and 5 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS0_GFR_F4F5_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS0D);

  if ((gfr & (1UL << 4U)) != 0U) {
#if (SPC5_ICU_USE_EMIOS0_CH4 == TRUE)
    icu_lld_serve_interrupt(&ICUD5);
#elif (SPC5_PWM_USE_EMIOS0_CH4 == TRUE)
    pwm_lld_serve_single_channel_interrupt(&PWMD5);
#endif
  }
  if ((gfr & (1UL << 5U)) != 0U) {
#if (SPC5_ICU_USE_EMIOS0_CH5 == TRUE)
    icu_lld_serve_interrupt(&ICUD6);
#elif (SPC5_PWM_USE_EMIOS0_CH5 == TRUE)
    pwm_lld_serve_single_channel_interrupt(&PWMD6);
#endif
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_ICU_USE_EMIOS0_CH6 == TRUE) || (SPC5_ICU_USE_EMIOS0_CH7 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_CH6 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH7 == TRUE)
#if !defined(SPC5_EMIOS0_GFR_F6F7_HANDLER)
#error "SPC5_EMIOS0_GFR_F6F7_HANDLER not defined"
#endif
/**
 * @brief   eMIOS0 Channels 6 and 7 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS0_GFR_F6F7_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS0D);

  if ((gfr & (1UL << 6U)) != 0U) {
#if (SPC5_ICU_USE_EMIOS0_CH6 == TRUE)
    icu_lld_serve_interrupt(&ICUD7);
#elif (SPC5_PWM_USE_EMIOS0_CH6 == TRUE)
    pwm_lld_serve_single_channel_interrupt(&PWMD7);
#endif
  }
  if ((gfr & (1UL << 7U)) != 0U) {
#if (SPC5_ICU_USE_EMIOS0_CH7 == TRUE)
    icu_lld_serve_interrupt(&ICUD8);
#elif (SPC5_PWM_USE_EMIOS0_CH7 == TRUE)
    pwm_lld_serve_single_channel_interrupt(&PWMD8);
#endif
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE)
#if !defined(SPC5_EMIOS0_GFR_F8F9_HANDLER)
#error "SPC5_EMIOS0_GFR_F8F9_HANDLER not defined"
#endif
/**
 * @brief   eMIOS0 Channels 8 and 9 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS0_GFR_F8F9_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS0D);

  if ((gfr & (1UL << 8U)) != 0U) {
    pwm_lld_serve_group_period_interrupt(&PWMD9);
  }
  if ((gfr & (1UL << 9U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD9, 0U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE)
#if !defined(SPC5_EMIOS0_GFR_F10F11_HANDLER)
#error "SPC5_EMIOS0_GFR_F10F11_HANDLER not defined"
#endif
/**
 * @brief   eMIOS0 Channels 10 and 11 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS0_GFR_F10F11_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS0D);

  if ((gfr & (1UL << 10U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD9, 1U);
  }
  if ((gfr & (1UL << 11U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD9, 2U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE)
#if !defined(SPC5_EMIOS0_GFR_F12F13_HANDLER)
#error "SPC5_EMIOS0_GFR_F12F13_HANDLER not defined"
#endif
/**
 * @brief   eMIOS0 Channels 12 and 13 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS0_GFR_F12F13_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS0D);

  if ((gfr & (1UL << 12U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD9, 3U);
  }
  if ((gfr & (1UL << 13U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD9, 4U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE)
#if !defined(SPC5_EMIOS0_GFR_F14F15_HANDLER)
#error "SPC5_EMIOS0_GFR_F14F15_HANDLER not defined"
#endif
/**
 * @brief   eMIOS0 Channels 14 and 15 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS0_GFR_F14F15_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS0D);

  if ((gfr & (1UL << 14U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD9, 5U);
  }
  if ((gfr & (1UL << 15U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD9, 6U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE)
#if !defined(SPC5_EMIOS0_GFR_F16F17_HANDLER)
#error "SPC5_EMIOS0_GFR_F16F17_HANDLER not defined"
#endif
/**
 * @brief   eMIOS0 Channels 16 and 17 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS0_GFR_F16F17_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS0D);

  if ((gfr & (1UL << 16U)) != 0U) {
    pwm_lld_serve_group_period_interrupt(&PWMD10);
  }
  if ((gfr & (1UL << 17U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD10, 0U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE)
#if !defined(SPC5_EMIOS0_GFR_F18F19_HANDLER)
#error "SPC5_EMIOS0_GFR_F18F19_HANDLER not defined"
#endif
/**
 * @brief   eMIOS0 Channels 18 and 19 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS0_GFR_F18F19_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS0D);

  if ((gfr & (1UL << 18U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD10, 1U);
  }
  if ((gfr & (1UL << 19U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD10, 2U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE)
#if !defined(SPC5_EMIOS0_GFR_F20F21_HANDLER)
#error "SPC5_EMIOS0_GFR_F20F21_HANDLER not defined"
#endif
/**
 * @brief   eMIOS0 Channels 20 and 21 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS0_GFR_F20F21_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS0D);

  if ((gfr & (1UL << 20U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD10, 3U);
  }
  if ((gfr & (1UL << 21U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD10, 4U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE)
#if !defined(SPC5_EMIOS0_GFR_F22F23_HANDLER)
#error "SPC5_EMIOS0_GFR_F22F23_HANDLER not defined"
#endif
/**
 * @brief   eMIOS0 Channels 22 and 23 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS0_GFR_F22F23_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS0D);

  if ((gfr & (1UL << 22U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD10, 5U);
  }
  if ((gfr & (1UL << 23U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD10, 6U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE)
#if !defined(SPC5_EMIOS0_GFR_F24F25_HANDLER)
#error "SPC5_EMIOS0_GFR_F24F25_HANDLER not defined"
#endif
/**
 * @brief   eMIOS0 Channels 24 and 25 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS0_GFR_F24F25_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS0D);

  if ((gfr & (1UL << 24U)) != 0U) {
    pwm_lld_serve_group_period_interrupt(&PWMD11);
  }
  if ((gfr & (1UL << 25U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD11, 0U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE)
#if !defined(SPC5_EMIOS0_GFR_F26F27_HANDLER)
#error "SPC5_EMIOS0_GFR_F26F27_HANDLER not defined"
#endif
/**
 * @brief   eMIOS0 Channels 26 and 27 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS0_GFR_F26F27_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS0D);

  if ((gfr & (1UL << 26U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD11, 1U);
  }
  if ((gfr & (1UL << 27U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD11, 2U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE)
#if !defined(SPC5_EMIOS0_GFR_F28F29_HANDLER)
#error "SPC5_EMIOS0_GFR_F28F29_HANDLER not defined"
#endif
/**
 * @brief   eMIOS0 Channels 28 and 29 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS0_GFR_F28F29_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS0D);

  if ((gfr & (1UL << 28U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD11, 3U);
  }
  if ((gfr & (1UL << 29U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD11, 4U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE)
#if !defined(SPC5_EMIOS0_GFR_F30F31_HANDLER)
#error "SPC5_EMIOS0_GFR_F30F31_HANDLER not defined"
#endif
/**
 * @brief   eMIOS0 Channels 30 and 31 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS0_GFR_F30F31_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS0D);

  if ((gfr & (1UL << 30U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD11, 5U);
  }
  if ((gfr & (1UL << 31U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD11, 6U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE)
#if !defined(SPC5_EMIOS1_GFR_F0F1_HANDLER)
#error "SPC5_EMIOS1_GFR_F0F1_HANDLER not defined"
#endif
/**
 * @brief   eMIOS1 Channels 0 and 1 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS1_GFR_F0F1_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS1D);

  if ((gfr & (1UL << 0U)) != 0U) {
    pwm_lld_serve_group_period_interrupt(&PWMD12);
  }
  if ((gfr & (1UL << 1U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD12, 0U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE)
#if !defined(SPC5_EMIOS1_GFR_F2F3_HANDLER)
#error "SPC5_EMIOS1_GFR_F2F3_HANDLER not defined"
#endif
/**
 * @brief   eMIOS1 Channels 2 and 3 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS1_GFR_F2F3_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS1D);

  if ((gfr & (1UL << 2U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD12, 1U);
  }
  if ((gfr & (1UL << 3U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD12, 2U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE)
#if !defined(SPC5_EMIOS1_GFR_F4F5_HANDLER)
#error "SPC5_EMIOS1_GFR_F4F5_HANDLER not defined"
#endif
/**
 * @brief   eMIOS1 Channels 4 and 5 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS1_GFR_F4F5_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS1D);

  if ((gfr & (1UL << 4U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD12, 3U);
  }
  if ((gfr & (1UL << 5U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD12, 4U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE)
#if !defined(SPC5_EMIOS1_GFR_F6F7_HANDLER)
#error "SPC5_EMIOS1_GFR_F6F7_HANDLER not defined"
#endif
/**
 * @brief   eMIOS1 Channels 6 and 7 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS1_GFR_F6F7_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS1D);

  if ((gfr & (1UL << 6U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD12, 5U);
  }
  if ((gfr & (1UL << 7U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD12, 6U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE)
#if !defined(SPC5_EMIOS1_GFR_F8F9_HANDLER)
#error "SPC5_EMIOS1_GFR_F8F9_HANDLER not defined"
#endif
/**
 * @brief   eMIOS1 Channels 8 and 9 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS1_GFR_F8F9_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS1D);

  if ((gfr & (1UL << 8U)) != 0U) {
    pwm_lld_serve_group_period_interrupt(&PWMD13);
  }
  if ((gfr & (1UL << 9U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD13, 0U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE)
#if !defined(SPC5_EMIOS1_GFR_F10F11_HANDLER)
#error "SPC5_EMIOS1_GFR_F10F11_HANDLER not defined"
#endif
/**
 * @brief   eMIOS1 Channels 10 and 11 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS1_GFR_F10F11_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS1D);

  if ((gfr & (1UL << 10U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD13, 1U);
  }
  if ((gfr & (1UL << 11U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD13, 2U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE)
#if !defined(SPC5_EMIOS1_GFR_F12F13_HANDLER)
#error "SPC5_EMIOS1_GFR_F12F13_HANDLER not defined"
#endif
/**
 * @brief   eMIOS1 Channels 12 and 13 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS1_GFR_F12F13_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS1D);

  if ((gfr & (1UL << 12U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD13, 3U);
  }
  if ((gfr & (1UL << 13U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD13, 4U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE)
#if !defined(SPC5_EMIOS1_GFR_F14F15_HANDLER)
#error "SPC5_EMIOS1_GFR_F14F15_HANDLER not defined"
#endif
/**
 * @brief   eMIOS1 Channels 14 and 15 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS1_GFR_F14F15_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS1D);

  if ((gfr & (1UL << 14U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD13, 5U);
  }
  if ((gfr & (1UL << 15U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD13, 6U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE)
#if !defined(SPC5_EMIOS1_GFR_F16F17_HANDLER)
#error "SPC5_EMIOS1_GFR_F16F17_HANDLER not defined"
#endif
/**
 * @brief   eMIOS1 Channels 16 and 17 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS1_GFR_F16F17_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS1D);

  if ((gfr & (1UL << 16U)) != 0U) {
    pwm_lld_serve_group_period_interrupt(&PWMD14);
  }
  if ((gfr & (1UL << 17U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD14, 0U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE)
#if !defined(SPC5_EMIOS1_GFR_F18F19_HANDLER)
#error "SPC5_EMIOS1_GFR_F18F19_HANDLER not defined"
#endif
/**
 * @brief   eMIOS1 Channels 18 and 19 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS1_GFR_F18F19_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS1D);

  if ((gfr & (1UL << 18U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD14, 1U);
  }
  if ((gfr & (1UL << 19U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD14, 2U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE)
#if !defined(SPC5_EMIOS1_GFR_F20F21_HANDLER)
#error "SPC5_EMIOS1_GFR_F20F21_HANDLER not defined"
#endif
/**
 * @brief   eMIOS1 Channels 20 and 21 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS1_GFR_F20F21_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS1D);

  if ((gfr & (1UL << 20U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD14, 3U);
  }
  if ((gfr & (1UL << 21U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD14, 4U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE)
#if !defined(SPC5_EMIOS1_GFR_F22F23_HANDLER)
#error "SPC5_EMIOS1_GFR_F22F23_HANDLER not defined"
#endif
/**
 * @brief   eMIOS1 Channels 22 and 23 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS1_GFR_F22F23_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS1D);

  if ((gfr & (1UL << 22U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD14, 5U);
  }
  if ((gfr & (1UL << 23U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD14, 6U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE)
#if !defined(SPC5_EMIOS1_GFR_F24F25_HANDLER)
#error "SPC5_EMIOS1_GFR_F24F25_HANDLER not defined"
#endif
/**
 * @brief   eMIOS1 Channels 24 and 25 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS1_GFR_F24F25_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS1D);

  if ((gfr & (1UL << 24U)) != 0U) {
    pwm_lld_serve_group_period_interrupt(&PWMD15);
  }
  if ((gfr & (1UL << 25U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD15, 0U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE)
#if !defined(SPC5_EMIOS1_GFR_F26F27_HANDLER)
#error "SPC5_EMIOS1_GFR_F26F27_HANDLER not defined"
#endif
/**
 * @brief   eMIOS1 Channels 26 and 27 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS1_GFR_F26F27_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS1D);

  if ((gfr & (1UL << 26U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD15, 1U);
  }
  if ((gfr & (1UL << 27U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD15, 2U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE)
#if !defined(SPC5_EMIOS1_GFR_F28F29_HANDLER)
#error "SPC5_EMIOS1_GFR_F28F29_HANDLER not defined"
#endif
/**
 * @brief   eMIOS1 Channels 28 and 29 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS1_GFR_F28F29_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS1D);

  if ((gfr & (1UL << 28U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD15, 3U);
  }
  if ((gfr & (1UL << 29U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD15, 4U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE)
#if !defined(SPC5_EMIOS1_GFR_F30F31_HANDLER)
#error "SPC5_EMIOS1_GFR_F30F31_HANDLER not defined"
#endif
/**
 * @brief   eMIOS1 Channels 30 and 31 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS1_GFR_F30F31_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS1D);

  if ((gfr & (1UL << 30U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD15, 5U);
  }
  if ((gfr & (1UL << 31U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD15, 6U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE)
#if !defined(SPC5_EMIOS2_GFR_F0F1_HANDLER)
#error "SPC5_EMIOS2_GFR_F0F1_HANDLER not defined"
#endif
/**
 * @brief   eMIOS2 Channels 0 and 1 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS2_GFR_F0F1_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS2D);

  if ((gfr & (1UL << 0U)) != 0U) {
    pwm_lld_serve_group_period_interrupt(&PWMD16);
  }
  if ((gfr & (1UL << 1U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD16, 0U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE)
#if !defined(SPC5_EMIOS2_GFR_F2F3_HANDLER)
#error "SPC5_EMIOS2_GFR_F2F3_HANDLER not defined"
#endif
/**
 * @brief   eMIOS2 Channels 2 and 3 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS2_GFR_F2F3_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS2D);

  if ((gfr & (1UL << 2U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD16, 1U);
  }
  if ((gfr & (1UL << 3U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD16, 2U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE)
#if !defined(SPC5_EMIOS2_GFR_F4F5_HANDLER)
#error "SPC5_EMIOS2_GFR_F4F5_HANDLER not defined"
#endif
/**
 * @brief   eMIOS2 Channels 4 and 5 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS2_GFR_F4F5_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS2D);

  if ((gfr & (1UL << 4U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD16, 3U);
  }
  if ((gfr & (1UL << 5U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD16, 4U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE)
#if !defined(SPC5_EMIOS2_GFR_F6F7_HANDLER)
#error "SPC5_EMIOS2_GFR_F6F7_HANDLER not defined"
#endif
/**
 * @brief   eMIOS2 Channels 6 and 7 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS2_GFR_F6F7_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS2D);

  if ((gfr & (1UL << 6U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD16, 5U);
  }
  if ((gfr & (1UL << 7U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD16, 6U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE)
#if !defined(SPC5_EMIOS2_GFR_F8F9_HANDLER)
#error "SPC5_EMIOS2_GFR_F8F9_HANDLER not defined"
#endif
/**
 * @brief   eMIOS2 Channels 8 and 9 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS2_GFR_F8F9_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS2D);

  if ((gfr & (1UL << 8U)) != 0U) {
    pwm_lld_serve_group_period_interrupt(&PWMD17);
  }
  if ((gfr & (1UL << 9U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD17, 0U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE)
#if !defined(SPC5_EMIOS2_GFR_F10F11_HANDLER)
#error "SPC5_EMIOS2_GFR_F10F11_HANDLER not defined"
#endif
/**
 * @brief   eMIOS2 Channels 10 and 11 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS2_GFR_F10F11_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS2D);

  if ((gfr & (1UL << 10U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD17, 1U);
  }
  if ((gfr & (1UL << 11U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD17, 2U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE)
#if !defined(SPC5_EMIOS2_GFR_F12F13_HANDLER)
#error "SPC5_EMIOS2_GFR_F12F13_HANDLER not defined"
#endif
/**
 * @brief   eMIOS2 Channels 12 and 13 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS2_GFR_F12F13_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS2D);

  if ((gfr & (1UL << 12U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD17, 3U);
  }
  if ((gfr & (1UL << 13U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD17, 4U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE)
#if !defined(SPC5_EMIOS2_GFR_F14F15_HANDLER)
#error "SPC5_EMIOS2_GFR_F14F15_HANDLER not defined"
#endif
/**
 * @brief   eMIOS2 Channels 14 and 15 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS2_GFR_F14F15_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS2D);

  if ((gfr & (1UL << 14U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD17, 5U);
  }
  if ((gfr & (1UL << 15U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD17, 6U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE)
#if !defined(SPC5_EMIOS2_GFR_F16F17_HANDLER)
#error "SPC5_EMIOS2_GFR_F16F17_HANDLER not defined"
#endif
/**
 * @brief   eMIOS2 Channels 16 and 17 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS2_GFR_F16F17_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS2D);

  if ((gfr & (1UL << 16U)) != 0U) {
    pwm_lld_serve_group_period_interrupt(&PWMD18);
  }
  if ((gfr & (1UL << 17U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD18, 0U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE)
#if !defined(SPC5_EMIOS2_GFR_F18F19_HANDLER)
#error "SPC5_EMIOS2_GFR_F18F19_HANDLER not defined"
#endif
/**
 * @brief   eMIOS2 Channels 18 and 19 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS2_GFR_F18F19_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS2D);

  if ((gfr & (1UL << 18U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD18, 1U);
  }
  if ((gfr & (1UL << 19U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD18, 2U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE)
#if !defined(SPC5_EMIOS2_GFR_F20F21_HANDLER)
#error "SPC5_EMIOS2_GFR_F20F21_HANDLER not defined"
#endif
/**
 * @brief   eMIOS2 Channels 20 and 21 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS2_GFR_F20F21_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS2D);

  if ((gfr & (1UL << 20U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD18, 3U);
  }
  if ((gfr & (1UL << 21U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD18, 4U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE)
#if !defined(SPC5_EMIOS2_GFR_F22F23_HANDLER)
#error "SPC5_EMIOS2_GFR_F22F23_HANDLER not defined"
#endif
/**
 * @brief   eMIOS2 Channels 22 and 23 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS2_GFR_F22F23_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS2D);

  if ((gfr & (1UL << 22U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD18, 5U);
  }
  if ((gfr & (1UL << 23U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD18, 6U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
#if !defined(SPC5_EMIOS2_GFR_F24F25_HANDLER)
#error "SPC5_EMIOS2_GFR_F24F25_HANDLER not defined"
#endif
/**
 * @brief   eMIOS2 Channels 24 and 25 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS2_GFR_F24F25_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS2D);

  if ((gfr & (1UL << 24U)) != 0U) {
    pwm_lld_serve_group_period_interrupt(&PWMD19);
  }
  if ((gfr & (1UL << 25U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD19, 0U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
#if !defined(SPC5_EMIOS2_GFR_F26F27_HANDLER)
#error "SPC5_EMIOS2_GFR_F26F27_HANDLER not defined"
#endif
/**
 * @brief   eMIOS2 Channels 26 and 27 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS2_GFR_F26F27_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS2D);

  if ((gfr & (1UL << 26U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD19, 1U);
  }
  if ((gfr & (1UL << 27U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD19, 2U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
#if !defined(SPC5_EMIOS2_GFR_F28F29_HANDLER)
#error "SPC5_EMIOS2_GFR_F28F29_HANDLER not defined"
#endif
/**
 * @brief   eMIOS2 Channels 28 and 29 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS2_GFR_F28F29_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS2D);

  if ((gfr & (1UL << 28U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD19, 3U);
  }
  if ((gfr & (1UL << 29U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD19, 4U);
  }

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
#if !defined(SPC5_EMIOS2_GFR_F30F31_HANDLER)
#error "SPC5_EMIOS2_GFR_F30F31_HANDLER not defined"
#endif
/**
 * @brief   eMIOS2 Channels 30 and 31 interrupt handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_EMIOS2_GFR_F30F31_HANDLER) {

  uint32_t gfr;

  IRQ_PROLOGUE();

  gfr = emios_get_gfr(&EMIOS2D);

  if ((gfr & (1UL << 30U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD19, 5U);
  }
  if ((gfr & (1UL << 31U)) != 0U) {
    pwm_lld_serve_group_channel_interrupt(&PWMD19, 6U);
  }

  IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Enables the eMIOSx clock and sets the related Global Prescaler.
 *
 * @param[in] emiosdp   pointer to the eMIOSx registers block.
 *
 * @notapi
 */
void emios_enable_clock(EMIOSData *emiosdp) {
  /* If this is the first eMIOSx channel activated, 
     then the eMIOS module is enabled.*/
  if (emiosdp->emios_active_channels == 1U) {
    /* Enable peripheral.*/
#if (SPC5_HAS_EMIOS0 == TRUE)
    if (emiosdp == &EMIOS0D) {
      SPCSetPeripheralClockMode(SPC5_EMIOS0_PCTL,
                                   SPC5_EMIOS0_START_PCTL);
    }
#endif /* SPC5_HAS_EMIOS0 */
#if (SPC5_HAS_EMIOS1 == TRUE)
    if (emiosdp == &EMIOS1D) {
      SPCSetPeripheralClockMode(SPC5_EMIOS1_PCTL,
                                   SPC5_EMIOS1_START_PCTL);
    }
#endif /* SPC5_HAS_EMIOS1 */
#if (SPC5_HAS_EMIOS2 == TRUE)
    if (emiosdp == &EMIOS2D) {
      SPCSetPeripheralClockMode(SPC5_EMIOS2_PCTL,
                                   SPC5_EMIOS2_START_PCTL);
    }
#endif /* SPC5_HAS_EMIOS2 */

    /*Setup the Global Prescaler.*/
    emiosdp->emiosp->MCR.B.GPREN = 0U;
#if (SPC5_HAS_EMIOS0 == TRUE)
    if (emiosdp == &EMIOS0D) {
      emiosdp->emiosp->MCR.R = EMIOSMCR_GPRE(SPC5_EMIOS0_GPRE_VALUE - 1UL);
    }
#endif /* SPC5_HAS_EMIOS0 */
#if (SPC5_HAS_EMIOS1 == TRUE)
    if (emiosdp == &EMIOS1D) {
      emiosdp->emiosp->MCR.R = EMIOSMCR_GPRE(SPC5_EMIOS1_GPRE_VALUE - 1UL);
    }
#endif /* SPC5_HAS_EMIOS1 */
#if (SPC5_HAS_EMIOS2 == TRUE)
    if (emiosdp == &EMIOS2D) {
      emiosdp->emiosp->MCR.R = EMIOSMCR_GPRE(SPC5_EMIOS2_GPRE_VALUE - 1UL);
    }
#endif /* SPC5_HAS_EMIOS2 */
    emiosdp->emiosp->MCR.R |= EMIOSMCR_GPREN;

    emiosdp->emiosp->MCR.B.GTBE = 1U;

    /* Disable all unified channels.*/
    emiosdp->emiosp->UCDIS.R = 0xFFFFFFFFUL;
  }
}

/**
 * @brief   Disables the eMIOSx clock.
 *
 * @param[in] emiosdp   pointer to the eMIOSx registers block.
 *
 * @notapi
 */
void emios_disable_clock(EMIOSData *emiosdp) {
  /* If this is the last active channel then the eMIOS module is disabled.*/
  if (emiosdp->emios_active_channels == 0U) {
    if (emiosdp->emiosp->UCDIS.R == 0xFFFFFFFFUL) {
#if (SPC5_HAS_EMIOS0 == TRUE)
      if (emiosdp == &EMIOS0D) {
        SPCSetPeripheralClockMode(SPC5_EMIOS0_PCTL,
                                     SPC5_EMIOS0_STOP_PCTL);
      }
#endif /* SPC5_HAS_EMIOS0 */
#if (SPC5_HAS_EMIOS1 == TRUE)
      if (emiosdp == &EMIOS1D) {
        SPCSetPeripheralClockMode(SPC5_EMIOS1_PCTL,
                                     SPC5_EMIOS1_STOP_PCTL);
      }
#endif /* SPC5_HAS_EMIOS1 */
#if (SPC5_HAS_EMIOS2 == TRUE)
      if (emiosdp == &EMIOS2D) {
        SPCSetPeripheralClockMode(SPC5_EMIOS2_PCTL,
                                     SPC5_EMIOS2_STOP_PCTL);
      }
#endif /* SPC5_HAS_EMIOS2 */
    }
  }
}

#endif /* LLD_USE_ICU || LLD_USE_PWM */

/** @} */

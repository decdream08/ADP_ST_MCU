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
 * @file    pwm_lld.c
 * @brief   SPC5xx PWM low level driver code.
 *
 * @addtogroup PWM
 * @{
 */

#include "pwm_lld.h"

#if (LLD_USE_PWM == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   PWMD1 driver identifier.
 * @note    The driver PWMD1 allocates the unified channel EMIOS0_CH0
 *          when enabled.
 */
#if (SPC5_PWM_USE_EMIOS0_CH0 == TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD1;
#endif

/**
 * @brief   PWMD2 driver identifier.
 * @note    The driver PWMD2 allocates the unified channel EMIOS0_CH1
 *          when enabled.
 */
#if (SPC5_PWM_USE_EMIOS0_CH1 == TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD2;
#endif

/**
 * @brief   PWMD3 driver identifier.
 * @note    The driver PWMD3 allocates the unified channel EMIOS0_CH2
 *          when enabled.
 */
#if (SPC5_PWM_USE_EMIOS0_CH2 == TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD3;
#endif

/**
 * @brief   PWMD4 driver identifier.
 * @note    The driver PWMD4 allocates the unified channel EMIOS0_CH3
 *          when enabled.
 */
#if (SPC5_PWM_USE_EMIOS0_CH3 == TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD4;
#endif

/**
 * @brief   PWMD5 driver identifier.
 * @note    The driver PWMD5 allocates the unified channel EMIOS0_CH4
 *          when enabled.
 */
#if (SPC5_PWM_USE_EMIOS0_CH4 == TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD5;
#endif

/**
 * @brief   PWMD6 driver identifier.
 * @note    The driver PWMD6 allocates the unified channel EMIOS0_CH5
 *          when enabled.
 */
#if (SPC5_PWM_USE_EMIOS0_CH5 == TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD6;
#endif

/**
 * @brief   PWMD7 driver identifier.
 * @note    The driver PWMD7 allocates the unified channel EMIOS0_CH6
 *          when enabled.
 */
#if (SPC5_PWM_USE_EMIOS0_CH6 == TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD7;
#endif

/**
 * @brief   PWMD8 driver identifier.
 * @note    The driver PWMD8 allocates the unified channel EMIOS0_CH7
 *          when enabled.
 */
#if (SPC5_PWM_USE_EMIOS0_CH7 == TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD8;
#endif

/**
 * @brief   PWMD9 driver identifier.
 * @note    The driver PWMD9 allocates the unified channels eMIOS0_CH9 -
 *          eMIOS0_CH15 when enabled.
 */
#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD9;
#endif

/**
 * @brief   PWMD10 driver identifier.
 * @note    The driver PWMD10 allocates the unified channels eMIOS0_CH17 -
 *          eMIOS0_CH23 when enabled.
 */
#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD10;
#endif

/**
 * @brief   PWMD11 driver identifier.
 * @note    The driver PWMD11 allocates the unified channels eMIOS0_CH25 -
 *          eMIOS0_CH31 when enabled.
 */
#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD11;
#endif

/**
 * @brief   PWMD12 driver identifier.
 * @note    The driver PWMD12 allocates the unified channels eMIOS1_CH1 -
 *          eMIOS1_CH7 when enabled.
 */
#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD12;
#endif

/**
 * @brief   PWMD13 driver identifier.
 * @note    The driver PWMD13 allocates the unified channels eMIOS1_CH9 -
 *          eMIOS1_CH15 when enabled.
 */
#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD13;
#endif

/**
 * @brief   PWMD14 driver identifier.
 * @note    The driver PWMD14 allocates the unified channels eMIOS1_CH17 -
 *          eMIOS1_CH23 when enabled.
 */
#if (SPC5_PWM_USE_EMIOS1_GROUP2== TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD14;
#endif

/**
 * @brief   PWMD15 driver identifier.
 * @note    The driver PWMD15 allocates the unified channels eMIOS1_CH25 -
 *          eMIOS1_CH31 when enabled.
 */
#if (SPC5_PWM_USE_EMIOS1_GROUP3== TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD15;
#endif

/**
 * @brief   PWMD16 driver identifier.
 * @note    The driver PWMD16 allocates the unified channels eMIOS2_CH1 -
 *          eMIOS2_CH7 when enabled.
 */
#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD16;
#endif

/**
 * @brief   PWMD17 driver identifier.
 * @note    The driver PWMD17 allocates the unified channels eMIOS2_CH9 -
 *          eMIOS2_CH15 when enabled.
 */
#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD17;
#endif

/**
 * @brief   PWMD18 driver identifier.
 * @note    The driver PWMD18 allocates the unified channels eMIOS2_CH17 -
 *          eMIOS2_CH23 when enabled.
 */
#if (SPC5_PWM_USE_EMIOS2_GROUP2== TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD18;
#endif

/**
 * @brief   PWMD19 driver identifier.
 * @note    The driver PWMD19 allocates the unified channels eMIOS2_CH25 -
 *          eMIOS2_CH31 when enabled.
 */
#if (SPC5_PWM_USE_EMIOS2_GROUP3== TRUE) || defined(__DOXYGEN__)
PWMDriver PWMD19;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/


/**
 * @brief               PWM IRQ handler related to the single channels (eMIOS0
 *                      Group0).
 *
 * @param[in] pwmp      pointer to the @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_serve_single_channel_interrupt(PWMDriver *pwmp) {

  uint32_t sr = pwmp->emiosp->CH[pwmp->period_ch].S.R;

  if ((sr & EMIOSS_OVFL) != 0U) {
    pwmp->emiosp->CH[pwmp->period_ch].S.R |= EMIOSS_OVFLC;
  }
  if ((sr & EMIOSS_OVR) != 0U) {
    pwmp->emiosp->CH[pwmp->period_ch].S.R |= EMIOSS_OVRC;
  }
  if ((sr & EMIOSS_FLAG) != 0U) {
    pwmp->emiosp->CH[pwmp->period_ch].S.R |= EMIOSS_FLAGC;
    if (pwmp->config->ch_config[0]->mode == (pwmoutmode_t)(PWM_OUTPUT_ACTIVE_HIGH)) {
      if ((pwmp->emiosp->CH[pwmp->period_ch].S.B.UCOUT == 1U) &&          \
          (pwmp->config->period_callback != NULL)) {
        pwmp->config->period_callback(pwmp);
      } else if ((pwmp->emiosp->CH[pwmp->period_ch].S.B.UCOUT == 0U) &&   \
          (pwmp->config->ch_config[0]->channel_callback != NULL)) {
        pwmp->config->ch_config[0]->channel_callback(pwmp);
      } else {
        ; /* close if...else if as per MISRA rules */
      }
    } else if (pwmp->config->ch_config[0]->mode == (pwmoutmode_t)(PWM_OUTPUT_ACTIVE_LOW)) {
      if ((pwmp->emiosp->CH[pwmp->period_ch].S.B.UCOUT == 0U)  &&         \
          (pwmp->config->period_callback != NULL)) {
        pwmp->config->period_callback(pwmp);
      } else if ((pwmp->emiosp->CH[pwmp->period_ch].S.B.UCOUT == 1U) &&   \
          (pwmp->config->ch_config[0]->channel_callback != NULL)) {
        pwmp->config->ch_config[0]->channel_callback(pwmp);
      } else {
        ; /* close if...else if as per MISRA rules */
      }
    } else {
      ; /* close if...else if as per MISRA rules */
    }
  }
}

/**
 * @brief               IRQ handler related to the channel used as counter within
 *                      a group (CH0 for eMIOS1/2 Group0, CH8 for eMIOS0/1/2 Group1,
 *                      CH16 for eMIOS0/1/2 Group2 and CH24 for eMIOS0/1/2 Group3).
 *
 * @param[in] pwmp      pointer to the @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_serve_group_period_interrupt(PWMDriver *pwmp) {

  uint32_t sr;

  sr = pwmp->emiosp->CH[pwmp->period_ch].S.R;
  if ((sr & EMIOSS_OVFL) != 0U) {
    pwmp->emiosp->CH[pwmp->period_ch].S.R |= EMIOSS_OVFLC;
  }
  if ((sr & EMIOSS_OVR) != 0U) {
    pwmp->emiosp->CH[pwmp->period_ch].S.R |= EMIOSS_OVRC;
  }
  if ((sr & EMIOSS_FLAG) != 0U) {
    pwmp->emiosp->CH[pwmp->period_ch].S.R |= EMIOSS_FLAGC;
    if (pwmp->config->period_callback != NULL) {
      pwmp->config->period_callback(pwmp);
    }
  }
}

/**
 * @brief               IRQ handler for the other channels within a group.
 *
 * @param[in] pwmp      pointer to the @p PWMDriver object
 * @param[in] channel   channel number within the group (0-6).
 *
 * @notapi
 */
void pwm_lld_serve_group_channel_interrupt(PWMDriver *pwmp, pwmchannel_t channel) {

  uint32_t sr;

  sr = pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].S.R;
  if ((sr & EMIOSS_OVFL) != 0U) {
    pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].S.R |= EMIOSS_OVFLC;
  }
  if ((sr & EMIOSS_OVR) != 0U) {
    pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].S.R |= EMIOSS_OVRC;
  }
  if ((sr & EMIOSS_FLAG) != 0U) {
    pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].S.R |= EMIOSS_FLAGC;
    if (pwmp->config->ch_config[channel]->channel_callback != NULL) {
      pwmp->config->ch_config[channel]->channel_callback(pwmp);
    }
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level PWM driver initialization.
 *
 * @init
 */
void pwm_lld_init(void) {
  /* eMIOSx data initialization. Initially all channels are not in use.*/
#if (SPC5_HAS_EMIOS0 == TRUE)
  EMIOS0D.emios_active_channels = 0U;
  EMIOS0D.emiosp = &SPC5_EMIOS_0;
#endif
#if (SPC5_HAS_EMIOS1 == TRUE)
  EMIOS1D.emios_active_channels = 0U;
  EMIOS1D.emiosp = &SPC5_EMIOS_1;
#endif
#if (SPC5_HAS_EMIOS2 == TRUE)
  EMIOS2D.emios_active_channels = 0U;
  EMIOS2D.emiosp = &SPC5_EMIOS_2;
#endif

#if (SPC5_PWM_USE_EMIOS0_CH0 == TRUE)
  /* Driver initialization.*/
  PWMD1.period_ch = 0U;
  PWMD1.config = NULL;
  PWMD1.emiosp = &SPC5_EMIOS_0;
#endif /* SPC5_PWM_USE_EMIOS0_CH0 */

#if (SPC5_PWM_USE_EMIOS0_CH1 == TRUE)
  /* Driver initialization.*/
  PWMD2.period_ch = 1U;
  PWMD2.config = NULL;
  PWMD2.emiosp = &SPC5_EMIOS_0;
#endif /* SPC5_PWM_USE_EMIOS0_CH1 */

#if (SPC5_PWM_USE_EMIOS0_CH2 == TRUE)
  /* Driver initialization.*/
  PWMD3.period_ch = 2U;
  PWMD3.config = NULL;
  PWMD3.emiosp = &SPC5_EMIOS_0;
#endif /* SPC5_PWM_USE_EMIOS0_CH2 */

#if (SPC5_PWM_USE_EMIOS0_CH3 == TRUE)
  /* Driver initialization.*/
  PWMD4.period_ch = 3U;
  PWMD4.config = NULL;
  PWMD4.emiosp = &SPC5_EMIOS_0;
#endif /* SPC5_PWM_USE_EMIOS0_CH3 */

#if (SPC5_PWM_USE_EMIOS0_CH4 == TRUE)
  /* Driver initialization.*/
  PWMD5.period_ch = 4U;
  PWMD5.config = NULL;
  PWMD5.emiosp = &SPC5_EMIOS_0;
#endif /* SPC5_PWM_USE_EMIOS0_CH4 */

#if (SPC5_PWM_USE_EMIOS0_CH5 == TRUE)
  /* Driver initialization.*/
  PWMD6.period_ch = 5U;
  PWMD6.config = NULL;
  PWMD6.emiosp = &SPC5_EMIOS_0;
#endif /* SPC5_PWM_USE_EMIOS0_CH5 */

#if (SPC5_PWM_USE_EMIOS0_CH6 == TRUE)
  /* Driver initialization.*/
  PWMD7.period_ch = 6U;
  PWMD7.config = NULL;
  PWMD7.emiosp = &SPC5_EMIOS_0;
#endif /* SPC5_PWM_USE_EMIOS0_CH6 */

#if (SPC5_PWM_USE_EMIOS0_CH7 == TRUE)
  /* Driver initialization.*/
  PWMD8.period_ch = 7U;
  PWMD8.config = NULL;
  PWMD8.emiosp = &SPC5_EMIOS_0;
#endif /* SPC5_PWM_USE_EMIOS0_CH7 */

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE)
  /* Driver initialization.*/
  PWMD9.mode = SPC5_PWM_EMIOS0_GROUP1_MODE;
  PWMD9.period_ch = 8U;
  PWMD9.config = NULL;
  PWMD9.emiosp = &SPC5_EMIOS_0;
#endif /* SPC5_PWM_USE_EMIOS0_GROUP1 */

#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE)
  /* Driver initialization.*/
  PWMD10.mode = SPC5_PWM_EMIOS0_GROUP2_MODE;
  PWMD10.period_ch = 16U;
  PWMD10.config = NULL;
  PWMD10.emiosp = &SPC5_EMIOS_0;
#endif /* SPC5_PWM_USE_EMIOS0_GROUP2 */

#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE)
  /* Driver initialization.*/
  PWMD11.mode = SPC5_PWM_EMIOS0_GROUP3_MODE;
  PWMD11.period_ch = 24U;
  PWMD11.config = NULL;
  PWMD11.emiosp = &SPC5_EMIOS_0;
#endif /* SPC5_PWM_USE_EMIOS0_GROUP3 */

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE)
  /* Driver initialization.*/
  PWMD12.mode = SPC5_PWM_EMIOS1_GROUP0_MODE;
  PWMD12.period_ch = 0U;
  PWMD12.config = NULL;
  PWMD12.emiosp = &SPC5_EMIOS_1;
#endif /* SPC5_PWM_USE_EMIOS1_GROUP0 */

#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE)
  /* Driver initialization.*/
  PWMD13.mode = SPC5_PWM_EMIOS1_GROUP1_MODE;
  PWMD13.period_ch = 8U;
  PWMD13.config = NULL;
  PWMD13.emiosp = &SPC5_EMIOS_1;
#endif /* SPC5_PWM_USE_EMIOS1_GROUP1 */

#if (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE)
  /* Driver initialization.*/
  PWMD14.mode = SPC5_PWM_EMIOS1_GROUP2_MODE;
  PWMD14.period_ch = 16U;
  PWMD14.config = NULL;
  PWMD14.emiosp = &SPC5_EMIOS_1;
#endif /* SPC5_PWM_USE_EMIOS1_GROUP2 */

#if (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE)
  /* Driver initialization.*/
  PWMD15.mode = SPC5_PWM_EMIOS1_GROUP3_MODE;
  PWMD15.period_ch = 24U;
  PWMD15.config = NULL;
  PWMD15.emiosp = &SPC5_EMIOS_1;
#endif /* SPC5_PWM_USE_EMIOS1_GROUP3 */

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE)
  /* Driver initialization.*/
  PWMD16.mode = SPC5_PWM_EMIOS2_GROUP0_MODE;
  PWMD16.period_ch = 0U;
  PWMD16.config = NULL;
  PWMD16.emiosp = &SPC5_EMIOS_2;
#endif /* SPC5_PWM_USE_EMIOS2_GROUP0 */

#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE)
  /* Driver initialization.*/
  PWMD17.mode = SPC5_PWM_EMIOS2_GROUP1_MODE;
  PWMD17.period_ch = 8U;
  PWMD17.config = NULL;
  PWMD17.emiosp = &SPC5_EMIOS_2;
#endif /* SPC5_PWM_USE_EMIOS2_GROUP1 */

#if (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE)
  /* Driver initialization.*/
  PWMD18.mode = SPC5_PWM_EMIOS2_GROUP2_MODE;
  PWMD18.period_ch = 16U;
  PWMD18.config = NULL;
  PWMD18.emiosp = &SPC5_EMIOS_2;
#endif /* SPC5_PWM_USE_EMIOS2_GROUP2 */

#if (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
  /* Driver initialization.*/
  PWMD19.mode = SPC5_PWM_EMIOS2_GROUP3_MODE;
  PWMD19.period_ch = 24U;
  PWMD19.config = NULL;
  PWMD19.emiosp = &SPC5_EMIOS_2;
#endif /* SPC5_PWM_USE_EMIOS2_GROUP3 */

#if (SPC5_PWM_USE_EMIOS0_CH0 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH1 == TRUE)
  INTC_PSR(SPC5_EMIOS0_GFR_F0F1_NUMBER) = SPC5_EMIOS0_GFR_F0F1_PRIORITY;
#endif /* SPC5_PWM_USE_EMIOS0_CH0 || SPC5_PWM_USE_EMIOS0_CH1 */

#if (SPC5_PWM_USE_EMIOS0_CH2 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH3 == TRUE)
  INTC_PSR(SPC5_EMIOS0_GFR_F2F3_NUMBER) = SPC5_EMIOS0_GFR_F2F3_PRIORITY;
#endif /* SPC5_PWM_USE_EMIOS0_CH2 || SPC5_PWM_USE_EMIOS0_CH3 */

#if (SPC5_PWM_USE_EMIOS0_CH4 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH5 == TRUE)
  INTC_PSR(SPC5_EMIOS0_GFR_F4F5_NUMBER) = SPC5_EMIOS0_GFR_F4F5_PRIORITY;
#endif /* SPC5_PWM_USE_EMIOS0_CH4 || SPC5_PWM_USE_EMIOS0_CH5 */

#if (SPC5_PWM_USE_EMIOS0_CH6 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH7 == TRUE)
  INTC_PSR(SPC5_EMIOS0_GFR_F6F7_NUMBER) = SPC5_EMIOS0_GFR_F6F7_PRIORITY;
#endif /* SPC5_PWM_USE_EMIOS0_CH6 || SPC5_PWM_USE_EMIOS0_CH7 */

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE)
  INTC_PSR(SPC5_EMIOS0_GFR_F8F9_NUMBER)   = SPC5_EMIOS0_GFR_F8F9_PRIORITY;
  INTC_PSR(SPC5_EMIOS0_GFR_F10F11_NUMBER) = SPC5_EMIOS0_GFR_F10F11_PRIORITY;
  INTC_PSR(SPC5_EMIOS0_GFR_F12F13_NUMBER) = SPC5_EMIOS0_GFR_F12F13_PRIORITY;
  INTC_PSR(SPC5_EMIOS0_GFR_F14F15_NUMBER) = SPC5_EMIOS0_GFR_F14F15_PRIORITY;
#endif /* SPC5_PWM_USE_EMIOS0_GROUP1 */

#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE)
  INTC_PSR(SPC5_EMIOS0_GFR_F16F17_NUMBER) = SPC5_EMIOS0_GFR_F16F17_PRIORITY;
  INTC_PSR(SPC5_EMIOS0_GFR_F18F19_NUMBER) = SPC5_EMIOS0_GFR_F18F19_PRIORITY;
  INTC_PSR(SPC5_EMIOS0_GFR_F20F21_NUMBER) = SPC5_EMIOS0_GFR_F20F21_PRIORITY;
  INTC_PSR(SPC5_EMIOS0_GFR_F22F23_NUMBER) = SPC5_EMIOS0_GFR_F22F23_PRIORITY;
#endif /* SPC5_PWM_USE_EMIOS0_GROUP2 */

#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE)
  INTC_PSR(SPC5_EMIOS0_GFR_F24F25_NUMBER) = SPC5_EMIOS0_GFR_F24F25_PRIORITY;
  INTC_PSR(SPC5_EMIOS0_GFR_F26F27_NUMBER) = SPC5_EMIOS0_GFR_F26F27_PRIORITY;
  INTC_PSR(SPC5_EMIOS0_GFR_F28F29_NUMBER) = SPC5_EMIOS0_GFR_F28F29_PRIORITY;
  INTC_PSR(SPC5_EMIOS0_GFR_F30F31_NUMBER) = SPC5_EMIOS0_GFR_F30F31_PRIORITY;
#endif /* SPC5_PWM_USE_EMIOS0_GROUP3 */

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE)
  INTC_PSR(SPC5_EMIOS1_GFR_F0F1_NUMBER) = SPC5_EMIOS1_GFR_F0F1_PRIORITY;
  INTC_PSR(SPC5_EMIOS1_GFR_F2F3_NUMBER) = SPC5_EMIOS1_GFR_F2F3_PRIORITY;
  INTC_PSR(SPC5_EMIOS1_GFR_F4F5_NUMBER) = SPC5_EMIOS1_GFR_F4F5_PRIORITY;
  INTC_PSR(SPC5_EMIOS1_GFR_F6F7_NUMBER) = SPC5_EMIOS1_GFR_F6F7_PRIORITY;
#endif /* SPC5_PWM_USE_EMIOS1_GROUP0 */

#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE)
  INTC_PSR(SPC5_EMIOS1_GFR_F8F9_NUMBER)   = SPC5_EMIOS1_GFR_F8F9_PRIORITY;
  INTC_PSR(SPC5_EMIOS1_GFR_F10F11_NUMBER) = SPC5_EMIOS1_GFR_F10F11_PRIORITY;
  INTC_PSR(SPC5_EMIOS1_GFR_F12F13_NUMBER) = SPC5_EMIOS1_GFR_F12F13_PRIORITY;
  INTC_PSR(SPC5_EMIOS1_GFR_F14F15_NUMBER) = SPC5_EMIOS1_GFR_F14F15_PRIORITY;
#endif /* SPC5_PWM_USE_EMIOS1_GROUP1 */

#if (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE)
  INTC_PSR(SPC5_EMIOS1_GFR_F16F17_NUMBER) = SPC5_EMIOS1_GFR_F16F17_PRIORITY;
  INTC_PSR(SPC5_EMIOS1_GFR_F18F19_NUMBER) = SPC5_EMIOS1_GFR_F18F19_PRIORITY;
  INTC_PSR(SPC5_EMIOS1_GFR_F20F21_NUMBER) = SPC5_EMIOS1_GFR_F20F21_PRIORITY;
  INTC_PSR(SPC5_EMIOS1_GFR_F22F23_NUMBER) = SPC5_EMIOS1_GFR_F22F23_PRIORITY;
#endif /* SPC5_PWM_USE_EMIOS1_GROUP2 */

#if (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE)
  INTC_PSR(SPC5_EMIOS1_GFR_F24F25_NUMBER) = SPC5_EMIOS1_GFR_F24F25_PRIORITY;
  INTC_PSR(SPC5_EMIOS1_GFR_F26F27_NUMBER) = SPC5_EMIOS1_GFR_F26F27_PRIORITY;
  INTC_PSR(SPC5_EMIOS1_GFR_F28F29_NUMBER) = SPC5_EMIOS1_GFR_F28F29_PRIORITY;
  INTC_PSR(SPC5_EMIOS1_GFR_F30F31_NUMBER) = SPC5_EMIOS1_GFR_F30F31_PRIORITY;
#endif /* SPC5_PWM_USE_EMIOS1_GROUP3 */

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE)
  INTC_PSR(SPC5_EMIOS2_GFR_F0F1_NUMBER) = SPC5_EMIOS2_GFR_F0F1_PRIORITY;
  INTC_PSR(SPC5_EMIOS2_GFR_F2F3_NUMBER) = SPC5_EMIOS2_GFR_F2F3_PRIORITY;
  INTC_PSR(SPC5_EMIOS2_GFR_F4F5_NUMBER) = SPC5_EMIOS2_GFR_F4F5_PRIORITY;
  INTC_PSR(SPC5_EMIOS2_GFR_F6F7_NUMBER) = SPC5_EMIOS2_GFR_F6F7_PRIORITY;
#endif /* SPC5_PWM_USE_EMIOS2_GROUP0 */

#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE)
  INTC_PSR(SPC5_EMIOS2_GFR_F8F9_NUMBER)   = SPC5_EMIOS2_GFR_F8F9_PRIORITY;
  INTC_PSR(SPC5_EMIOS2_GFR_F10F11_NUMBER) = SPC5_EMIOS2_GFR_F10F11_PRIORITY;
  INTC_PSR(SPC5_EMIOS2_GFR_F12F13_NUMBER) = SPC5_EMIOS2_GFR_F12F13_PRIORITY;
  INTC_PSR(SPC5_EMIOS2_GFR_F14F15_NUMBER) = SPC5_EMIOS2_GFR_F14F15_PRIORITY;
#endif /* SPC5_PWM_USE_EMIOS2_GROUP1 */

#if (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE)
  INTC_PSR(SPC5_EMIOS2_GFR_F16F17_NUMBER) = SPC5_EMIOS2_GFR_F16F17_PRIORITY;
  INTC_PSR(SPC5_EMIOS2_GFR_F18F19_NUMBER) = SPC5_EMIOS2_GFR_F18F19_PRIORITY;
  INTC_PSR(SPC5_EMIOS2_GFR_F20F21_NUMBER) = SPC5_EMIOS2_GFR_F20F21_PRIORITY;
  INTC_PSR(SPC5_EMIOS2_GFR_F22F23_NUMBER) = SPC5_EMIOS2_GFR_F22F23_PRIORITY;
#endif /* SPC5_PWM_USE_EMIOS2_GROUP2 */

#if (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
  INTC_PSR(SPC5_EMIOS2_GFR_F24F25_NUMBER) = SPC5_EMIOS2_GFR_F24F25_PRIORITY;
  INTC_PSR(SPC5_EMIOS2_GFR_F26F27_NUMBER) = SPC5_EMIOS2_GFR_F26F27_PRIORITY;
  INTC_PSR(SPC5_EMIOS2_GFR_F28F29_NUMBER) = SPC5_EMIOS2_GFR_F28F29_PRIORITY;
  INTC_PSR(SPC5_EMIOS2_GFR_F30F31_NUMBER) = SPC5_EMIOS2_GFR_F30F31_PRIORITY;
#endif /* SPC5_PWM_USE_EMIOS2_GROUP3 */

}

#if (SPC5_PWM_USE_EMIOS0_CH0 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH1 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_CH2 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH3 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_CH4 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH5 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_CH6 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH7 == TRUE)
/**
 * @brief   Configures and activates a single channel (eMIOS0 Group0).
 *
 * @param[in] pwmp      pointer to the @p PWMDriver object
 *
 * @notapi
 */
static void pwm_lld_start_single_channel(PWMDriver *pwmp) {

  if (pwmp->config->ch_config[0]->mode != (pwmoutmode_t)(PWM_OUTPUT_DISABLED)) {

    /* Enable channel.*/
    pwmp->emiosp->UCDIS.R &= ~(1UL << pwmp->period_ch);
    
    /* Clear pending IRQs (if any).*/
    pwmp->emiosp->CH[pwmp->period_ch].S.R = EMIOSS_OVRC | EMIOSS_OVFLC | 
        EMIOSS_FLAGC;
    
    /* Set period.*/
    pwmp->emiosp->CH[pwmp->period_ch].C.B.UCPREN = 0;
    pwmp->emiosp->CH[pwmp->period_ch].A.R = 0;
    pwmp->emiosp->CH[pwmp->period_ch].B.R = pwmp->period;
    pwmp->emiosp->CH[pwmp->period_ch].CNT.R = 1U;
    
    /* Set output polarity.*/
    if (pwmp->config->ch_config[0]->mode == (pwmoutmode_t)(PWM_OUTPUT_ACTIVE_HIGH)) {
      pwmp->emiosp->CH[pwmp->period_ch].C.R &= ~EMIOSC_EDPOL;
    } else {
      pwmp->emiosp->CH[pwmp->period_ch].C.R |= EMIOSC_EDPOL;
    }
    
    /* Set bus select.*/
    pwmp->emiosp->CH[pwmp->period_ch].C.R |= EMIOSC_BSL(EMIOS_BSL_INTERNAL_COUNTER);
    
    /* Set mode selection.*/
    /* MODE[30] is set to 1, so FLAGs are generate both on A1 and B1 matches. This
       allows to manage both the period and the channel callbacks.*/
    pwmp->emiosp->CH[pwmp->period_ch].C.R |= (EMIOS_CCR_MODE_OPWFMB | 0x2U);
    
    /* Set prescaler.*/
    pwmp->emiosp->CH[pwmp->period_ch].C.B.UCPRE = (pwmpsc_t)(pwmp->config->psc - 1U);
    pwmp->emiosp->CH[pwmp->period_ch].C.R |= EMIOSC_UCPREN;
    
    /* Disable channel.*/
    pwmp->emiosp->UCDIS.R |= (1UL << pwmp->period_ch);
  }
}
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE) || (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE) || (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE) || \
    (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE) || (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE) || \
    (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE) || (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE) || \
    (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE) || (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE) || \
    (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
/**
 * @brief   Configures and activates a group channel (eMIOS0 Group1-Group3,
 *          eMIOS1/2 Group0-Group3).
 *
 * @param[in] pwmp      pointer to the @p PWMDriver object
 *
 * @notapi
 */
static void pwm_lld_start_channel_group(PWMDriver *pwmp) {

  uint8_t i;

  /* Configure the period channel (first channel of the group).*/
  /* Enable channel.*/
  pwmp->emiosp->UCDIS.R &= ~(1UL << pwmp->period_ch);
  
  /* Clear pending IRQs (if any).*/
  pwmp->emiosp->CH[pwmp->period_ch].S.R = EMIOSS_OVRC | EMIOSS_OVFLC | 
      EMIOSS_FLAGC;

  /* Setup period.*/
  pwmp->emiosp->CH[pwmp->period_ch].C.B.UCPREN = 0;
  pwmp->emiosp->CH[pwmp->period_ch].A.R = pwmp->period;
  pwmp->emiosp->CH[pwmp->period_ch].B.R = 1U;
  pwmp->emiosp->CH[pwmp->period_ch].CNT.R = 1U;

  /* Set bus select.*/
  pwmp->emiosp->CH[pwmp->period_ch].C.R |= EMIOSC_BSL(EMIOS_BSL_INTERNAL_COUNTER);

  /* Set mode selection.*/
  pwmp->emiosp->CH[pwmp->period_ch].C.R |= EMIOS_CCR_MODE_MCB_UP;

  /* If enabled, set the external clock.*/
  if (pwmp->config->ext_clk == TRUE) {
    pwmp->emiosp->CH[pwmp->period_ch].C.R |= 0x1U;
  } else {
	pwmp->emiosp->CH[pwmp->period_ch].C.R &= ~0x1U;
  }

  /* Set prescaler.*/
  pwmp->emiosp->CH[pwmp->period_ch].C.B.UCPRE = (pwmpsc_t)(pwmp->config->psc - 1U);
  pwmp->emiosp->CH[pwmp->period_ch].C.R |= EMIOSC_UCPREN;
  
  /* Disable channel.*/
  pwmp->emiosp->UCDIS.R |= (1UL << pwmp->period_ch);
 
  /* Configure the other group channels.*/
  for (i = 0; i < 7U; i++) {
    if (pwmp->config->ch_config[i]->mode != (pwmoutmode_t)(PWM_OUTPUT_DISABLED)) {
      /* Enable channel.*/
      pwmp->emiosp->UCDIS.R &= ~(1UL << (pwmp->period_ch + i + 1U));
      
      /* Clear pending IRQs (if any).*/
      pwmp->emiosp->CH[pwmp->period_ch + i + 1U].S.R = EMIOSS_OVRC | 
          EMIOSS_OVFLC | EMIOSS_FLAGC;
      
      pwmp->emiosp->CH[pwmp->period_ch + i + 1U].A.R = 0;
      pwmp->emiosp->CH[pwmp->period_ch + i + 1U].B.R = 0;
      
      /* Set bus select.*/
      pwmp->emiosp->CH[pwmp->period_ch + i + 1U].C.R |= EMIOSC_BSL(EMIOS_BSL_COUNTER_BUS_BCDE);
      
      /* Set mode selection.*/
      if(pwmp->mode == (pwmmode_t)SPC5_PWM_MODE_OPWMB) {
        pwmp->emiosp->CH[pwmp->period_ch + i + 1U].C.R |= EMIOS_CCR_MODE_OPWMB;
      } else if (pwmp->mode == (pwmmode_t)SPC5_PWM_MODE_OPWMT) {
        pwmp->emiosp->CH[pwmp->period_ch + i + 1U].C.R |= EMIOS_CCR_MODE_OPWMT;
      } else {
        ; /* close if...else if as per MISRA rules */
      }

      /* Disable channel.*/
      pwmp->emiosp->UCDIS.R |= (1UL << (pwmp->period_ch + i + 1U));
    }
  }
}
#endif

/**
 * @brief   Configures and activates the PWM peripheral.
 *
 * @param[in] pwmp      pointer to the @p PWMDriver object
 * @param[in] config    pointer to a @p PWMConfig object
 *
 * @api
 */
void pwm_lld_start(PWMDriver *pwmp, PWMConfig *config) {

  osalEnterCritical();

  pwmp->config = config;
  pwmp->period = config->period;

  /* Update the number of active ICU channels.*/
#if (SPC5_PWM_USE_EMIOS0_CH0 == TRUE)
  if (&PWMD1 == pwmp) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH0 */

#if (SPC5_PWM_USE_EMIOS0_CH1 == TRUE)
  if (&PWMD2 == pwmp) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH1 */

#if (SPC5_PWM_USE_EMIOS0_CH2 == TRUE)
  if (&PWMD3 == pwmp) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH2 */

#if (SPC5_PWM_USE_EMIOS0_CH3 == TRUE)
  if (&PWMD4 == pwmp) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH3 */

#if (SPC5_PWM_USE_EMIOS0_CH4 == TRUE)
  if (&PWMD5 == pwmp) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH4 */

#if (SPC5_PWM_USE_EMIOS0_CH5 == TRUE)
  if (&PWMD6 == pwmp) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH5 */

#if (SPC5_PWM_USE_EMIOS0_CH6 == TRUE)
  if (&PWMD7 == pwmp) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH6 */

#if (SPC5_PWM_USE_EMIOS0_CH7 == TRUE)
  if (&PWMD8== pwmp) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH7 */

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE)
  if (&PWMD9 == pwmp) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP1 */

#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE)
  if (&PWMD10 == pwmp) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP2 */

#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE)
  if (&PWMD11 == pwmp) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP3 */

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE)
  if (&PWMD12 == pwmp) {
    EMIOS1D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP0 */

#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE)
  if (&PWMD13 == pwmp) {
    EMIOS1D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP1 */

#if (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE)
  if (&PWMD14 == pwmp) {
    EMIOS1D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP2 */

#if (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE)
  if (&PWMD15 == pwmp) {
    EMIOS1D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP3 */

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE)
  if (&PWMD16 == pwmp) {
    EMIOS2D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP0 */

#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE)
  if (&PWMD17 == pwmp) {
    EMIOS2D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP1 */

#if (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE)
  if (&PWMD18 == pwmp) {
    EMIOS2D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP2 */

#if (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
  if (&PWMD19 == pwmp) {
    EMIOS2D.emios_active_channels++;
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP3 */

  /* Enable eMIOS0 Clock.*/
#if (SPC5_HAS_EMIOS0 == TRUE)
  if (pwmp->emiosp == &SPC5_EMIOS_0) {
    emios_enable_clock(&EMIOS0D);
  }
#endif /* SPC5_HAS_EMIOS0 */

  /* Enable eMIOS1 Clock.*/
#if (SPC5_HAS_EMIOS1 == TRUE)
  if (pwmp->emiosp == &SPC5_EMIOS_1) {
    emios_enable_clock(&EMIOS1D);
  }
#endif /* SPC5_HAS_EMIOS1 */

  /* Enable eMIOS2 Clock.*/
#if (SPC5_HAS_EMIOS2 == TRUE)
  if (pwmp->emiosp == &SPC5_EMIOS_2) {
    emios_enable_clock(&EMIOS2D);
  }
#endif /* SPC5_HAS_EMIOS2 */

#if (SPC5_PWM_USE_EMIOS0_CH0 == TRUE)
  if (&PWMD1 == pwmp) {
    pwm_lld_start_single_channel(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH0 */

#if (SPC5_PWM_USE_EMIOS0_CH1 == TRUE)
  if (&PWMD2 == pwmp) {
    pwm_lld_start_single_channel(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH1 */

#if (SPC5_PWM_USE_EMIOS0_CH2 == TRUE)
  if (&PWMD3 == pwmp) {
    pwm_lld_start_single_channel(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH2 */

#if (SPC5_PWM_USE_EMIOS0_CH3 == TRUE)
  if (&PWMD4 == pwmp) {
    pwm_lld_start_single_channel(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH3 */

#if (SPC5_PWM_USE_EMIOS0_CH4 == TRUE)
  if (&PWMD5 == pwmp) {
    pwm_lld_start_single_channel(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH4 */

#if (SPC5_PWM_USE_EMIOS0_CH5 == TRUE)
  if (&PWMD6 == pwmp) {
    pwm_lld_start_single_channel(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH5 */

#if (SPC5_PWM_USE_EMIOS0_CH6 == TRUE)
  if (&PWMD7 == pwmp) {
    pwm_lld_start_single_channel(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH6 */

#if (SPC5_PWM_USE_EMIOS0_CH7 == TRUE)
  if (&PWMD8 == pwmp) {
    pwm_lld_start_single_channel(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH7 */

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE)
  if (&PWMD9 == pwmp) {
    pwm_lld_start_channel_group(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP1 */

#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE)
  if (&PWMD10 == pwmp) {
    pwm_lld_start_channel_group(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP2 */

#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE)
  if (&PWMD11 == pwmp) {
    pwm_lld_start_channel_group(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP3 */

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE)
  if (&PWMD12 == pwmp) {
    pwm_lld_start_channel_group(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP0 */

#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE)
  if (&PWMD13 == pwmp) {
    pwm_lld_start_channel_group(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP1 */

#if (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE)
  if (&PWMD14 == pwmp) {
    pwm_lld_start_channel_group(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP2 */

#if (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE)
  if (&PWMD15 == pwmp) {
    pwm_lld_start_channel_group(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP3 */

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE)
  if (&PWMD16 == pwmp) {
    pwm_lld_start_channel_group(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP0 */

#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE)
  if (&PWMD17 == pwmp) {
    pwm_lld_start_channel_group(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP1 */

#if (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE)
  if (&PWMD18 == pwmp) {
    pwm_lld_start_channel_group(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP2 */

#if (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
  if (&PWMD19 == pwmp) {
    pwm_lld_start_channel_group(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP3 */

  osalExitCritical();
}

/**
 * @brief   Deactivates the PWM peripheral.
 *
 * @param[in] pwmp      pointer to the @p PWMDriver object
 *
 * @api
 */
void pwm_lld_stop(PWMDriver *pwmp) {

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE) || (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE) || (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE) || \
    (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE) || (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE) || \
    (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE) || (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE) || \
    (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE) || (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE) || \
    (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
  uint8_t i;
#endif

  osalEnterCritical();

  /* Disables the peripheral.*/

#if (SPC5_PWM_USE_EMIOS0_CH0 == TRUE)
  if (&PWMD1 == pwmp) {
    /* Reset Control Register.*/
	/* In order to clear the Control Register, the channel
	   must be temporary re-enabled.*/
    pwmp->emiosp->UCDIS.R &= ~(1UL << pwmp->period_ch);
    pwmp->emiosp->CH[pwmp->period_ch].C.R = 0;
	pwmp->emiosp->UCDIS.R |= (1UL << pwmp->period_ch);
    EMIOS0D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH0 */

#if (SPC5_PWM_USE_EMIOS0_CH1 == TRUE)
  if (&PWMD2 == pwmp) {
    /* Reset Control Register.*/
	/* In order to clear the Control Register, the channel
	   must be temporary re-enabled.*/
    pwmp->emiosp->UCDIS.R &= ~(1UL << pwmp->period_ch);
    pwmp->emiosp->CH[pwmp->period_ch].C.R = 0;
	pwmp->emiosp->UCDIS.R |= (1UL << pwmp->period_ch);
    EMIOS0D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH1 */

#if (SPC5_PWM_USE_EMIOS0_CH2 == TRUE)
  if (&PWMD3 == pwmp) {
    /* Reset Control Register.*/
	/* In order to clear the Control Register, the channel
	   must be temporary re-enabled.*/
    pwmp->emiosp->UCDIS.R &= ~(1UL << pwmp->period_ch);
    pwmp->emiosp->CH[pwmp->period_ch].C.R = 0;
	pwmp->emiosp->UCDIS.R |= (1UL << pwmp->period_ch);
    EMIOS0D.emios_active_channels--;;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH2 */

#if (SPC5_PWM_USE_EMIOS0_CH3 == TRUE)
  if (&PWMD4 == pwmp) {
    /* Reset Control Register.*/
	/* In order to clear the Control Register, the channel
	   must be temporary re-enabled.*/
    pwmp->emiosp->UCDIS.R &= ~(1UL << pwmp->period_ch);
    pwmp->emiosp->CH[pwmp->period_ch].C.R = 0;
	pwmp->emiosp->UCDIS.R |= (1UL << pwmp->period_ch);
    EMIOS0D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH3 */

#if (SPC5_PWM_USE_EMIOS0_CH4 == TRUE)
  if (&PWMD5 == pwmp) {
    /* Reset Control Register.*/
	/* In order to clear the Control Register, the channel
	   must be temporary re-enabled.*/
    pwmp->emiosp->UCDIS.R &= ~(1UL << pwmp->period_ch);
    pwmp->emiosp->CH[pwmp->period_ch].C.R = 0;
	pwmp->emiosp->UCDIS.R |= (1UL << pwmp->period_ch);
    EMIOS0D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH4 */

#if (SPC5_PWM_USE_EMIOS0_CH5 == TRUE)
  if (&PWMD6 == pwmp) {
    /* Reset Control Register.*/
	/* In order to clear the Control Register, the channel
	   must be temporary re-enabled.*/
    pwmp->emiosp->UCDIS.R &= ~(1UL << pwmp->period_ch);
    pwmp->emiosp->CH[pwmp->period_ch].C.R = 0;
	pwmp->emiosp->UCDIS.R |= (1UL << pwmp->period_ch);
    EMIOS0D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH5 */

#if (SPC5_PWM_USE_EMIOS0_CH6 == TRUE)
  if (&PWMD7 == pwmp) {
    /* Reset Control Register.*/
	/* In order to clear the Control Register, the channel
	   must be temporary re-enabled.*/
    pwmp->emiosp->UCDIS.R &= ~(1UL << pwmp->period_ch);
    pwmp->emiosp->CH[pwmp->period_ch].C.R = 0;
	pwmp->emiosp->UCDIS.R |= (1UL << pwmp->period_ch);
    EMIOS0D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH6 */

#if (SPC5_PWM_USE_EMIOS0_CH7 == TRUE)
  if (&PWMD8== pwmp) {
    /* Reset Control Register.*/
	/* In order to clear the Control Register, the channel
	   must be temporary re-enabled.*/
    pwmp->emiosp->UCDIS.R &= ~(1UL << pwmp->period_ch);
    pwmp->emiosp->CH[pwmp->period_ch].C.R = 0;
	pwmp->emiosp->UCDIS.R |= (1UL << pwmp->period_ch);
    EMIOS0D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH7 */

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE)
  if (&PWMD9 == pwmp) {
    /* Reset Control Register for all the channels within the group.*/
	/* In order to clear the Control Register, the channels must be
	   temporary re-enabled.*/
    for (i = 0U; i <= 7U; i++) {
      pwmp->emiosp->UCDIS.R &= ~(1UL << (pwmp->period_ch + i));
      pwmp->emiosp->CH[pwmp->period_ch + i].C.R = 0;
      pwmp->emiosp->UCDIS.R |= (1UL << (pwmp->period_ch + i));
	}
    EMIOS0D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP1 */

#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE)
  if (&PWMD10 == pwmp) {
    /* Reset Control Register for all the channels within the group.*/
	/* In order to clear the Control Register, the channels must be
	   temporary re-enabled.*/
    for (i = 0U; i <= 7U; i++) {
      pwmp->emiosp->UCDIS.R &= ~(1UL << (pwmp->period_ch + i));
      pwmp->emiosp->CH[pwmp->period_ch + i].C.R = 0;
      pwmp->emiosp->UCDIS.R |= (1UL << (pwmp->period_ch + i));
	}
    EMIOS0D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP2 */

#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE)
  if (&PWMD11 == pwmp) {
    /* Reset Control Register for all the channels within the group.*/
	/* In order to clear the Control Register, the channels must be
	   temporary re-enabled.*/
    for (i = 0U; i <= 7U; i++) {
      pwmp->emiosp->UCDIS.R &= ~(1UL << (pwmp->period_ch + i));
      pwmp->emiosp->CH[pwmp->period_ch + i].C.R = 0;
      pwmp->emiosp->UCDIS.R |= (1UL << (pwmp->period_ch + i));
	}
    EMIOS0D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP3 */

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE)
  if (&PWMD12 == pwmp) {
    /* Reset Control Register for all the channels within the group.*/
	/* In order to clear the Control Register, the channels must be
	   temporary re-enabled.*/
    for (i = 0U; i <= 7U; i++) {
      pwmp->emiosp->UCDIS.R &= ~(1UL << (pwmp->period_ch + i));
      pwmp->emiosp->CH[pwmp->period_ch + i].C.R = 0;
      pwmp->emiosp->UCDIS.R |= (1UL << (pwmp->period_ch + i));
	}
    EMIOS1D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP0 */

#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE)
  if (&PWMD13 == pwmp) {
    /* Reset Control Register for all the channels within the group.*/
	/* In order to clear the Control Register, the channels must be
	   temporary re-enabled.*/
    for (i = 0U; i <= 7U; i++) {
      pwmp->emiosp->UCDIS.R &= ~(1UL << (pwmp->period_ch + i));
      pwmp->emiosp->CH[pwmp->period_ch + i].C.R = 0;
      pwmp->emiosp->UCDIS.R |= (1UL << (pwmp->period_ch + i));
	}
    EMIOS1D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP1 */

#if (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE)
  if (&PWMD14 == pwmp) {
    /* Reset Control Register for all the channels within the group.*/
	/* In order to clear the Control Register, the channels must be
	   temporary re-enabled.*/
    for (i = 0U; i <= 7U; i++) {
      pwmp->emiosp->UCDIS.R &= ~(1UL << (pwmp->period_ch + i));
      pwmp->emiosp->CH[pwmp->period_ch + i].C.R = 0;
      pwmp->emiosp->UCDIS.R |= (1UL << (pwmp->period_ch + i));
	}
    EMIOS1D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP2 */

#if (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE)
  if (&PWMD15 == pwmp) {
    /* Reset Control Register for all the channels within the group.*/
	/* In order to clear the Control Register, the channels must be
	   temporary re-enabled.*/
    for (i = 0U; i <= 7U; i++) {
      pwmp->emiosp->UCDIS.R &= ~(1UL << (pwmp->period_ch + i));
      pwmp->emiosp->CH[pwmp->period_ch + i].C.R = 0;
      pwmp->emiosp->UCDIS.R |= (1UL << (pwmp->period_ch + i));
	}
    EMIOS1D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP3 */

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE)
  if (&PWMD16 == pwmp) {
    /* Reset Control Register for all the channels within the group.*/
	/* In order to clear the Control Register, the channels must be
	   temporary re-enabled.*/
    for (i = 0U; i <= 7U; i++) {
      pwmp->emiosp->UCDIS.R &= ~(1UL << (pwmp->period_ch + i));
      pwmp->emiosp->CH[pwmp->period_ch + i].C.R = 0;
      pwmp->emiosp->UCDIS.R |= (1UL << (pwmp->period_ch + i));
	}
    EMIOS2D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP0 */

#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE)
  if (&PWMD17 == pwmp) {
    /* Reset Control Register for all the channels within the group.*/
	/* In order to clear the Control Register, the channels must be
	   temporary re-enabled.*/
    for (i = 0U; i <= 7U; i++) {
      pwmp->emiosp->UCDIS.R &= ~(1UL << (pwmp->period_ch + i));
      pwmp->emiosp->CH[pwmp->period_ch + i].C.R = 0;
      pwmp->emiosp->UCDIS.R |= (1UL << (pwmp->period_ch + i));
	}
    EMIOS2D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP1 */

#if (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE)
  if (&PWMD18 == pwmp) {
    /* Reset Control Register for all the channels within the group.*/
	/* In order to clear the Control Register, the channels must be
	   temporary re-enabled.*/
    for (i = 0U; i <= 7U; i++) {
      pwmp->emiosp->UCDIS.R &= ~(1UL << (pwmp->period_ch + i));
      pwmp->emiosp->CH[pwmp->period_ch + i].C.R = 0;
      pwmp->emiosp->UCDIS.R |= (1UL << (pwmp->period_ch + i));
	}
    EMIOS2D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP2 */

#if (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
  if (&PWMD19 == pwmp) {
    /* Reset Control Register for all the channels within the group.*/
	/* In order to clear the Control Register, the channels must be
	   temporary re-enabled.*/
    for (i = 0U; i <= 7U; i++) {
      pwmp->emiosp->UCDIS.R &= ~(1UL << (pwmp->period_ch + i));
      pwmp->emiosp->CH[pwmp->period_ch + i].C.R = 0;
      pwmp->emiosp->UCDIS.R |= (1UL << (pwmp->period_ch + i));
	}
    EMIOS2D.emios_active_channels--;
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP3 */

  /* Disable eMIOS0 Clock.*/
#if (SPC5_PWM_USE_EMIOS0 == TRUE)
  if (pwmp->emiosp == &SPC5_EMIOS_0) {
    emios_disable_clock(&EMIOS0D);
  }
#endif /* SPC5_PWM_USE_EMIOS0 */

  /* Disable eMIOS1 Clock.*/
#if (SPC5_PWM_USE_EMIOS1 == TRUE)
  if (pwmp->emiosp == &SPC5_EMIOS_1) {
    emios_disable_clock(&EMIOS1D);
  }
#endif /* SPC5_PWM_USE_EMIOS1 */

  /* Disable eMIOS2 Clock.*/
#if (SPC5_PWM_USE_EMIOS2 == TRUE)
  if (pwmp->emiosp == &SPC5_EMIOS_2) {
    emios_disable_clock(&EMIOS2D);
  }
#endif /* SPC5_PWM_USE_EMIOS2 */
  
  osalExitCritical();
}

/**
 * @brief   Changes the period of the PWM peripheral.
 * @details This function changes the period of a PWM channels that has already
 *          been activated using @p pwm_lld_start().
 * @pre     The PWM channel must have been activated using @p pwm_lld_start().
 * @post    The PWM channel period is changed to the new value.
 * @note    The function has effect at the next cycle start. For the channel
 *          within a channel group, this function changes the period of the 
 *          whole channel group.
 * @note    If a period is specified that is shorter than the pulse width
 *          programmed in one of the channels then the behavior is not
 *          guaranteed.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] period    new period in ticks
 *
 * @api
 */
void pwm_lld_change_period(PWMDriver *pwmp, pwmcnt_t period) {

  pwmp->period = period;

#if (SPC5_PWM_USE_EMIOS0_CH0 == TRUE)
  if (&PWMD1 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].B.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH0 */

#if (SPC5_PWM_USE_EMIOS0_CH1 == TRUE)
  if (&PWMD2 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].B.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH1 */

#if (SPC5_PWM_USE_EMIOS0_CH2 == TRUE)
  if (&PWMD3 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].B.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH2 */

#if (SPC5_PWM_USE_EMIOS0_CH3 == TRUE)
  if (&PWMD4 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].B.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH3 */

#if (SPC5_PWM_USE_EMIOS0_CH4 == TRUE)
  if (&PWMD5 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].B.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH4 */

#if (SPC5_PWM_USE_EMIOS0_CH5 == TRUE)
  if (&PWMD6 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].B.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH5 */

#if (SPC5_PWM_USE_EMIOS0_CH6 == TRUE)
  if (&PWMD7 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].B.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH6 */

#if (SPC5_PWM_USE_EMIOS0_CH7 == TRUE)
  if (&PWMD8== pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].B.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH7 */

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE)
  if (&PWMD9 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].A.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP1 */

#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE)
  if (&PWMD10 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].A.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP2 */

#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE)
  if (&PWMD11 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].A.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP3 */

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE)
  if (&PWMD12 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].A.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP0 */

#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE)
  if (&PWMD13 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].A.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP1 */

#if (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE)
  if (&PWMD14 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].A.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP2 */

#if (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE)
  if (&PWMD15 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].A.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP3 */

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE)
  if (&PWMD16 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].A.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP0 */

#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE)
  if (&PWMD17 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].A.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP1 */

#if (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE)
  if (&PWMD18 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].A.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP2 */

#if (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
  if (&PWMD19 == pwmp) {
    pwmp->emiosp->CH[pwmp->period_ch].A.R = period;
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP3 */

}

#if (SPC5_PWM_USE_EMIOS0_CH0 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH1 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_CH2 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH3 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_CH4 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH5 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_CH6 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH7 == TRUE)
/**
 * @brief   Enables a PWM single channel (eMIOS0 Group0).
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] width     PWM pulse width in ticks
 *
 * @notapi
 */
static void pwm_lld_enable_single_channel(PWMDriver *pwmp,
                                          pwmcnt_t width) {

  /* Enable channel.*/
  pwmp->emiosp->UCDIS.R &= ~(1UL << pwmp->period_ch);

  /* Clear pending IRQs (if any).*/
  pwmp->emiosp->CH[pwmp->period_ch].S.R = EMIOSS_OVRC | EMIOSS_OVFLC | 
      EMIOSS_FLAGC;

  /* Set PWM width.*/
  pwmp->emiosp->CH[pwmp->period_ch].A.R = width;
  
  /* Active interrupts.*/
  if ((pwmp->config->period_callback != NULL) || 
      (pwmp->config->ch_config[0]->channel_callback != NULL)) {
    pwmp->emiosp->CH[pwmp->period_ch].C.B.FEN = 1U;
  }
}
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE) || (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE) || (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE) || \
    (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE) || (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE) || \
    (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE) || (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE) || \
    (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE) || (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE) || \
    (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
/**
 * @brief   Enables a PWM channel within a channel group (eMIOS0 Group1-3, 
 *          eMIOS1/2 Group0-3).
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier. This parameter identifies the
 *                      channel in a channel group to be enabled.
 * @param[in] width     PWM pulse width in ticks
 * @param[in] deadtime  PWM deadtime in ticks
 * @param[in] delay     PWM channel delay in ticks.
 * @param[in] trigger   Number of ticks between the start of the PWM pulse and
 *                      the trigger generation. This parameter is relevant only
 *                      when the OPWMT mode is selected.
 *
 * @notapi
 */
static void pwm_lld_enable_group_channel(PWMDriver *pwmp,
                                         pwmchannel_t channel,
                                         pwmcnt_t width,
                                         pwmcnt_t deadtime,
                                         pwmcnt_t delay,
                                         pwmcnt_t trigger) {

  /* Enable channel.*/
  pwmp->emiosp->UCDIS.R &= ~(1UL << (pwmp->period_ch + channel + 1U));

  /* Clear pending IRQs (if any).*/
  pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].S.R = EMIOSS_OVRC |
      EMIOSS_OVFLC | EMIOSS_FLAGC;

  /* Set PWM width, deadtime, delay and polarity.*/
  if ((width + delay) < pwmp->period) {
    /* Output polarity is not changed.*/
    if (pwmp->config->ch_config[channel]->mode == (pwmoutmode_t)(PWM_OUTPUT_ACTIVE_HIGH)) {
      pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].C.R |= EMIOSC_EDPOL;
    } else {
      pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].C.R &= ~EMIOSC_EDPOL;
    }
    pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].A.R = 1U + delay + deadtime;
    pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].B.R = delay + width;
  } else {
    /* Output polarity is inverted.*/
    if (pwmp->config->ch_config[channel]->mode == (pwmoutmode_t)(PWM_OUTPUT_ACTIVE_HIGH)) {
      pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].C.R &= ~EMIOSC_EDPOL;
      //pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].B.R = (width + delay - pwmp->period) + width + deadtime;
    } else {
      pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].C.R |= EMIOSC_EDPOL;
      //pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].B.R = delay + deadtime;
    }
    pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].A.R = 1U + (width + delay - pwmp->period);
	pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].B.R = delay + deadtime;
  }

  /* Set PWM trigger.*/
  if (pwmp->mode == (pwmmode_t)SPC5_PWM_MODE_OPWMT) {
    pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].ALTA.R = trigger;
  }

  /* Active interrupts.*/
  if (pwmp->config->ch_config[channel]->channel_callback != NULL) {
    pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].C.B.FEN = 1U;
  }

  /* Enable the period channel if disable.*/
  if ((pwmp->emiosp->UCDIS.R & (1UL << pwmp->period_ch)) != 0U) {
    /* Enable channel.*/
    pwmp->emiosp->UCDIS.R &= ~(1UL << pwmp->period_ch);

    /* Active interrupts.*/
    if (pwmp->config->period_callback != NULL ) {
      pwmp->emiosp->CH[pwmp->period_ch].C.B.FEN = 1U;
    }
  }
}
#endif

/**
 * @brief   Enables a PWM channel.
 * @pre     The PWM unit must have been activated using @p pwm_lld_start().
 * @post    The channel is active using the specified configuration.
 * @note    Depending on the hardware implementation this function has
 *          effect starting on the next cycle (recommended implementation)
 *          or immediately (fallback implementation).
 * @note    If a period is shorter than pulse width, then the behavior is
 *          not guaranteed.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier. This parameter identifies the
 *                      channel (0-6) in a channel group to be enabled. It is
 *                      not relevant for the channels of the eMIOS0 Group0.
 * @param[in] width     PWM pulse width in ticks
 * @param[in] deadtime  PWM deadtime in ticks. This parameter is not relevant
 *                      for the the channels of the eMIOS0 Group0.
 * @param[in] delay     PWM channel delay in ticks. This parameter is not
 *                      relevant for the the channels of the eMIOS0 Group0.
 * @param[in] trigger   Number of ticks between the start of the PWM pulse and
 *                      the trigger generation. This parameter is not relevant
 *                      for the the channels of the eMIOS0 Group0, and is used
 *                      only when the OPWMT mode is selected.
 *
 * @api
 */
void pwm_lld_enable_channel(PWMDriver *pwmp,
                            pwmchannel_t channel,
                            pwmcnt_t width,
                            pwmcnt_t deadtime,
                            pwmcnt_t delay,
                            pwmcnt_t trigger) {

  osalEnterCritical();

#if ((SPC5_PWM_USE_EMIOS0_GROUP1 == FALSE) && \
     (SPC5_PWM_USE_EMIOS0_GROUP2 == FALSE) && (SPC5_PWM_USE_EMIOS0_GROUP3 == FALSE) && \
     (SPC5_PWM_USE_EMIOS1_GROUP0 == FALSE) && (SPC5_PWM_USE_EMIOS1_GROUP1 == FALSE) && \
	 (SPC5_PWM_USE_EMIOS1_GROUP2 == FALSE) && (SPC5_PWM_USE_EMIOS1_GROUP3 == FALSE) && \
     (SPC5_PWM_USE_EMIOS2_GROUP0 == FALSE) && (SPC5_PWM_USE_EMIOS2_GROUP1 == FALSE) && \
	 (SPC5_PWM_USE_EMIOS2_GROUP2 == FALSE) && (SPC5_PWM_USE_EMIOS2_GROUP3 == FALSE))
  (void)channel;
  (void)deadtime;
  (void)delay;
  (void)trigger;
#endif

#if (SPC5_PWM_USE_EMIOS0_CH0 == TRUE)
  if (&PWMD1 == pwmp) {
    pwm_lld_enable_single_channel(pwmp, width);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH0 */

#if (SPC5_PWM_USE_EMIOS0_CH1 == TRUE)
  if (&PWMD2 == pwmp) {
    pwm_lld_enable_single_channel(pwmp, width);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH1 */

#if (SPC5_PWM_USE_EMIOS0_CH2 == TRUE)
  if (&PWMD3 == pwmp) {
    pwm_lld_enable_single_channel(pwmp, width);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH2 */

#if (SPC5_PWM_USE_EMIOS0_CH3 == TRUE)
  if (&PWMD4 == pwmp) {
    pwm_lld_enable_single_channel(pwmp, width);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH3 */

#if (SPC5_PWM_USE_EMIOS0_CH4 == TRUE)
  if (&PWMD5 == pwmp) {
    pwm_lld_enable_single_channel(pwmp, width);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH4 */

#if (SPC5_PWM_USE_EMIOS0_CH5 == TRUE)
  if (&PWMD6 == pwmp) {
    pwm_lld_enable_single_channel(pwmp, width);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH5 */

#if (SPC5_PWM_USE_EMIOS0_CH6 == TRUE)
  if (&PWMD7 == pwmp) {
    pwm_lld_enable_single_channel(pwmp, width);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH6 */

#if (SPC5_PWM_USE_EMIOS0_CH7 == TRUE)
  if (&PWMD8 == pwmp) {
    pwm_lld_enable_single_channel(pwmp, width);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH7 */

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE)
  if (&PWMD9 == pwmp) {
    pwm_lld_enable_group_channel(pwmp, channel, width, deadtime, delay, trigger);
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP1 */

#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE)
  if (&PWMD10 == pwmp) {
    pwm_lld_enable_group_channel(pwmp, channel, width, deadtime, delay, trigger);
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP2 */

#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE)
  if (&PWMD11 == pwmp) {
    pwm_lld_enable_group_channel(pwmp, channel, width, deadtime, delay, trigger);
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP3 */

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE)
  if (&PWMD12 == pwmp) {
    pwm_lld_enable_group_channel(pwmp, channel, width, deadtime, delay, trigger);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP0 */

#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE)
  if (&PWMD13 == pwmp) {
    pwm_lld_enable_group_channel(pwmp, channel, width, deadtime, delay, trigger);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP1 */

#if (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE)
  if (&PWMD14 == pwmp) {
    pwm_lld_enable_group_channel(pwmp, channel, width, deadtime, delay, trigger);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP2 */

#if (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE)
  if (&PWMD15 == pwmp) {
    pwm_lld_enable_group_channel(pwmp, channel, width, deadtime, delay, trigger);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP3 */

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE)
  if (&PWMD16 == pwmp) {
    pwm_lld_enable_group_channel(pwmp, channel, width, deadtime, delay, trigger);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP0 */

#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE)
  if (&PWMD17 == pwmp) {
    pwm_lld_enable_group_channel(pwmp, channel, width, deadtime, delay, trigger);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP1 */

#if (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE)
  if (&PWMD18 == pwmp) {
    pwm_lld_enable_group_channel(pwmp, channel, width, deadtime, delay, trigger);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP2 */

#if (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
  if (&PWMD19 == pwmp) {
    pwm_lld_enable_group_channel(pwmp, channel, width, deadtime, delay, trigger);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP3 */

  osalExitCritical();
}

#if (SPC5_PWM_USE_EMIOS0_CH0 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH1 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_CH2 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH3 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_CH4 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH5 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_CH6 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH7 == TRUE)
/**
 * @brief   Disable a PWM single channel (eMIOS0 Group0).
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
static void pwm_lld_disable_single_channel(PWMDriver *pwmp) {

  /* Clear pending IRQs (if any).*/
  pwmp->emiosp->CH[pwmp->period_ch].S.R = EMIOSS_OVRC | EMIOSS_OVFLC | 
      EMIOSS_FLAGC;

  /* Disable interrupts.*/
  pwmp->emiosp->CH[pwmp->period_ch].C.B.FEN = 0;
  
  /* Disable channel.*/
  pwmp->emiosp->UCDIS.R |= (1UL << pwmp->period_ch);
}
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE) || (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE) || \
    (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE) || (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE) || \
    (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE) || (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE) || \
    (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE) || (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE) || \
    (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE) || (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE) || \
    (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
/**
 * @brief   Disables a PWM channel within a specific channels group (eMIOS0
 *          Group1-3, eMIOS1/2 Group0-3).
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier. This parameter identifies the
 *                      channel (0-6) in a channel group to be disabled.
 *
 * @notapi
 */
static void pwm_lld_disable_group_channel(PWMDriver *pwmp,
                                          pwmchannel_t channel) {

  uint32_t ucdis_reg_value;

  /* Clear pending IRQs (if any).*/
  pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].S.R = EMIOSS_OVRC |
        EMIOSS_OVFLC | EMIOSS_FLAGC;
  
  /* Disable interrupts.*/
  pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].C.B.FEN = 0;
  
  /* Disable channel.*/
  pwmp->emiosp->UCDIS.R |= (1UL << (pwmp->period_ch + channel + 1U));

  /* The ucdis_reg_value is a temporary variable used in the following
     if-structure to make it compatible with the MISRA rules.*/
  ucdis_reg_value = pwmp->emiosp->UCDIS.R;

  /* Disable timer base channel if all PWM channels are disabled.*/
  if ((ucdis_reg_value & (0xFEUL << pwmp->period_ch)) == (0xFEUL << pwmp->period_ch)) {
    /* Deactive interrupts.*/
    pwmp->emiosp->CH[pwmp->period_ch].C.B.FEN = 0;
  
    /* Disable channel.*/
    pwmp->emiosp->UCDIS.R |= (1UL << pwmp->period_ch);
  }
}
#endif

/**
 * @brief   Disables a PWM channel.
 * @pre     The PWM channel must have been activated using @p pwm_lld_start().
 * @post    The channel is disabled and its output line returned to the
 *          idle state.
 * @note    Depending on the hardware implementation this function has
 *          effect starting on the next cycle (recommended implementation)
 *          or immediately (fallback implementation).
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier. This parameter identifies the
 *                      channel in a channel group to be enabled. It is not 
 *                      relevant for the channels of the eMIOS0 Group0.
 *
 * @api
 */
void pwm_lld_disable_channel(PWMDriver *pwmp, pwmchannel_t channel) {

  osalEnterCritical();

#if ((SPC5_PWM_USE_EMIOS0_GROUP1 == FALSE) && \
     (SPC5_PWM_USE_EMIOS0_GROUP2 == FALSE) && (SPC5_PWM_USE_EMIOS0_GROUP3 == FALSE) && \
     (SPC5_PWM_USE_EMIOS1_GROUP0 == FALSE) && (SPC5_PWM_USE_EMIOS1_GROUP1 == FALSE) && \
	 (SPC5_PWM_USE_EMIOS1_GROUP2 == FALSE) && (SPC5_PWM_USE_EMIOS1_GROUP3 == FALSE) && \
     (SPC5_PWM_USE_EMIOS2_GROUP0 == FALSE) && (SPC5_PWM_USE_EMIOS2_GROUP1 == FALSE) && \
	 (SPC5_PWM_USE_EMIOS2_GROUP2 == FALSE) && (SPC5_PWM_USE_EMIOS2_GROUP3 == FALSE))

  (void)channel;
#endif

#if (SPC5_PWM_USE_EMIOS0_CH0 == TRUE)
  if (&PWMD1 == pwmp) {
    pwm_lld_disable_single_channel(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH0 */

#if (SPC5_PWM_USE_EMIOS0_CH1 == TRUE)
  if (&PWMD2 == pwmp) {
    pwm_lld_disable_single_channel(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH1 */

#if (SPC5_PWM_USE_EMIOS0_CH2 == TRUE)
  if (&PWMD3 == pwmp) {
    pwm_lld_disable_single_channel(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH2 */

#if (SPC5_PWM_USE_EMIOS0_CH3 == TRUE)
  if (&PWMD4 == pwmp) {
    pwm_lld_disable_single_channel(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH3 */

#if (SPC5_PWM_USE_EMIOS0_CH4 == TRUE)
  if (&PWMD5 == pwmp) {
    pwm_lld_disable_single_channel(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH4 */

#if (SPC5_PWM_USE_EMIOS0_CH5 == TRUE)
  if (&PWMD6 == pwmp) {
    pwm_lld_disable_single_channel(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH5 */

#if (SPC5_PWM_USE_EMIOS0_CH6 == TRUE)
  if (&PWMD7 == pwmp) {
    pwm_lld_disable_single_channel(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH6 */

#if (SPC5_PWM_USE_EMIOS0_CH7 == TRUE)
  if (&PWMD8 == pwmp) {
    pwm_lld_disable_single_channel(pwmp);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH7 */

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE)
  if (&PWMD9 == pwmp) {
    pwm_lld_disable_group_channel(pwmp, channel);
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP1 */

#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE)
  if (&PWMD10 == pwmp) {
    pwm_lld_disable_group_channel(pwmp, channel);
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP2 */

#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE)
  if (&PWMD11 == pwmp) {
    pwm_lld_disable_group_channel(pwmp, channel);
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP3 */

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE)
  if (&PWMD12 == pwmp) {
    pwm_lld_disable_group_channel(pwmp, channel);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP0 */

#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE)
  if (&PWMD13 == pwmp) {
    pwm_lld_disable_group_channel(pwmp, channel);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP1 */

#if (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE)
  if (&PWMD14 == pwmp) {
    pwm_lld_disable_group_channel(pwmp, channel);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP2 */

#if (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE)
  if (&PWMD15 == pwmp) {
    pwm_lld_disable_group_channel(pwmp, channel);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP3 */

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE)
  if (&PWMD16 == pwmp) {
    pwm_lld_disable_group_channel(pwmp, channel);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP0 */

#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE)
  if (&PWMD17 == pwmp) {
    pwm_lld_disable_group_channel(pwmp, channel);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP1 */

#if (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE)
  if (&PWMD18 == pwmp) {
    pwm_lld_disable_group_channel(pwmp, channel);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP2 */

#if (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
  if (&PWMD19 == pwmp) {
    pwm_lld_disable_group_channel(pwmp, channel);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP3 */

  osalExitCritical();
}

#if ((SPC5_PWM_USE_EMIOS0_CH0 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH1 == TRUE) || \
     (SPC5_PWM_USE_EMIOS0_CH2 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH3 == TRUE) || \
     (SPC5_PWM_USE_EMIOS0_CH4 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH5 == TRUE) || \
	 (SPC5_PWM_USE_EMIOS0_CH6 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH7 == TRUE))
/**
 * @brief   Set the channel callback of a PWM single channel (eMIOS0 Group0).
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel_callback   PWM channel callback. This parameter defines
 *                      the channel callback to be invoked when a channel
 *                      interrupt occurs.
 *
 * @noapi
 */
static void pwm_lld_set_single_channel_chcb(PWMDriver *pwmp,
                                            pwmcallback_t channel_callback) {

  /* Set the callback function.*/
  pwmp->config->ch_config[0]->channel_callback = channel_callback;

  /* Deactivate interrupt if no callbacks are defined.*/
  if ((pwmp->config->period_callback == NULL) &&
      (pwmp->config->ch_config[0]->channel_callback == NULL)) {
      pwmp->emiosp->CH[pwmp->period_ch].C.B.FEN = 0U;
  }

  /* Active interrupt if channel callback is defined.*/
  if (pwmp->config->ch_config[0]->channel_callback != NULL) {
    pwmp->emiosp->CH[pwmp->period_ch].C.B.FEN = 1U;
  }
}
#endif

#if ((SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE) || \
     (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE) || (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE) || \
     (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE) || (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE) || \
	 (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE) || (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE) || \
     (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE) || (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE) || \
	 (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE) || (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE))
/**
 * @brief   Set the channel callback of a PWM channel within a specific
 *          channels group (eMIOS0 Group1-3, eMIOS1/2 Group0-3).
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier. This parameter identifies the
 *                      channel (0-6) in a channel group for which the callback
 *                      has to be set.
 * @param[in] channel_callback   PWM channel callback. This parameter defines
 *                      the channel callback to be invoked when a channel
 *                      interrupt occurs.
 *
 * @noapi
 */
static void pwm_lld_set_group_channel_chcb(PWMDriver *pwmp,
                                           pwmchannel_t channel,
                                           pwmcallback_t channel_callback) {

  /* Set the callback function.*/
  pwmp->config->ch_config[channel]->channel_callback = channel_callback;

  /* Deactivate interrupt if callback is not defined, otherwise active
     interrupt.*/
  if (pwmp->config->ch_config[channel]->channel_callback == NULL) {
      pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].C.B.FEN = 0U;
  } else {
      pwmp->emiosp->CH[pwmp->period_ch + channel + 1U].C.B.FEN = 1U;
  }
}
#endif

/**
 * @brief   Set the PWM channel callback.
 * @pre     The PWM channel must have been activated using @p pwm_lld_start().
 * @post    The channel callback is invoked when a channel interrupt occurs. If
 *          channel_callback is set to NULL, no channel callback is invoked.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier. This parameter identifies the
 *                      channel for which the callback has to be set. It is not
 *                      relevant for the channels of the eMIOS0 Group0.
 * @param[in] channel_callback   PWM channel callback. This parameter defines
 *                      the channel callback to be invoked when a channel
 *                      interrupt occurs.
 *
 * @api
 */
void pwm_lld_set_channel_callback(PWMDriver *pwmp,
                                  pwmchannel_t channel,
                                  pwmcallback_t channel_callback) {

  osalEnterCritical();

#if ((SPC5_PWM_USE_EMIOS0_GROUP1 == FALSE) && \
     (SPC5_PWM_USE_EMIOS0_GROUP2 == FALSE) && (SPC5_PWM_USE_EMIOS0_GROUP3 == FALSE) && \
     (SPC5_PWM_USE_EMIOS1_GROUP0 == FALSE) && (SPC5_PWM_USE_EMIOS1_GROUP1 == FALSE) && \
	 (SPC5_PWM_USE_EMIOS1_GROUP2 == FALSE) && (SPC5_PWM_USE_EMIOS1_GROUP3 == FALSE) && \
     (SPC5_PWM_USE_EMIOS2_GROUP0 == FALSE) && (SPC5_PWM_USE_EMIOS2_GROUP1 == FALSE) && \
	 (SPC5_PWM_USE_EMIOS2_GROUP2 == FALSE) && (SPC5_PWM_USE_EMIOS2_GROUP3 == FALSE))
  (void)channel;
#endif

#if (SPC5_PWM_USE_EMIOS0_CH0 == TRUE)
  if (&PWMD1 == pwmp) {
    pwm_lld_set_single_channel_chcb(pwmp, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH0 */

#if (SPC5_PWM_USE_EMIOS0_CH1 == TRUE)
  if (&PWMD2 == pwmp) {
    pwm_lld_set_single_channel_chcb(pwmp, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH1 */

#if (SPC5_PWM_USE_EMIOS0_CH2 == TRUE)
  if (&PWMD3 == pwmp) {
    pwm_lld_set_single_channel_chcb(pwmp, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH2 */

#if (SPC5_PWM_USE_EMIOS0_CH3 == TRUE)
  if (&PWMD4 == pwmp) {
    pwm_lld_set_single_channel_chcb(pwmp, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH3 */

#if (SPC5_PWM_USE_EMIOS0_CH4 == TRUE)
  if (&PWMD5 == pwmp) {
    pwm_lld_set_single_channel_chcb(pwmp, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH4 */

#if (SPC5_PWM_USE_EMIOS0_CH5 == TRUE)
  if (&PWMD6 == pwmp) {
    pwm_lld_set_single_channel_chcb(pwmp, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH5 */

#if (SPC5_PWM_USE_EMIOS0_CH6 == TRUE)
  if (&PWMD7 == pwmp) {
    pwm_lld_set_single_channel_chcb(pwmp, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH6 */

#if (SPC5_PWM_USE_EMIOS0_CH7 == TRUE)
  if (&PWMD8 == pwmp) {
    pwm_lld_set_single_channel_chcb(pwmp, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH7 */

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE)
  if (&PWMD9 == pwmp) {
    pwm_lld_set_group_channel_chcb(pwmp, channel, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP1 */

#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE)
  if (&PWMD10 == pwmp) {
    pwm_lld_set_group_channel_chcb(pwmp, channel, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP2 */

#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE)
  if (&PWMD11 == pwmp) {
    pwm_lld_set_group_channel_chcb(pwmp, channel, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP3 */

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE)
  if (&PWMD12 == pwmp) {
    pwm_lld_set_group_channel_chcb(pwmp, channel, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP0 */

#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE)
  if (&PWMD13 == pwmp) {
    pwm_lld_set_group_channel_chcb(pwmp, channel, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP1 */

#if (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE)
  if (&PWMD14 == pwmp) {
    pwm_lld_set_group_channel_chcb(pwmp, channel, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP2 */

#if (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE)
  if (&PWMD15 == pwmp) {
    pwm_lld_set_group_channel_chcb(pwmp, channel, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP3 */

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE)
  if (&PWMD16 == pwmp) {
    pwm_lld_set_group_channel_chcb(pwmp, channel, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP0 */

#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE)
  if (&PWMD17 == pwmp) {
    pwm_lld_set_group_channel_chcb(pwmp, channel, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP1 */

#if (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE)
  if (&PWMD18 == pwmp) {
    pwm_lld_set_group_channel_chcb(pwmp, channel, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP2 */

#if (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
  if (&PWMD19 == pwmp) {
    pwm_lld_set_group_channel_chcb(pwmp, channel, channel_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP3 */

  osalExitCritical();
}

#if ((SPC5_PWM_USE_EMIOS0_CH0 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH1 == TRUE) || \
     (SPC5_PWM_USE_EMIOS0_CH2 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH3 == TRUE) || \
     (SPC5_PWM_USE_EMIOS0_CH4 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH5 == TRUE) || \
	 (SPC5_PWM_USE_EMIOS0_CH6 == TRUE) || (SPC5_PWM_USE_EMIOS0_CH7 == TRUE))
/**
 * @brief   Set the period callback of a PWM single channel (eMIOS0 Group0).
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] period_callback   PWM period callback. This parameter defines
 *                      the period callback to be invoked when a period
 *                      interrupt occurs.
 *
 * @noapi
 */
static void pwm_lld_set_single_channel_pcb(PWMDriver *pwmp,
                                           pwmcallback_t period_callback) {

  /* Set the callback function.*/
  pwmp->config->period_callback = period_callback;

  /* Deactivate interrupt if no callbacks are defined.*/
  if ((pwmp->config->period_callback == NULL) &&
      (pwmp->config->ch_config[0]->channel_callback == NULL)) {
      pwmp->emiosp->CH[pwmp->period_ch].C.B.FEN = 0U;
  }

  /* Active interrupt if period callback is defined.*/
  if (pwmp->config->period_callback != NULL) {
    pwmp->emiosp->CH[pwmp->period_ch].C.B.FEN = 1U;
  }
}
#endif

#if ((SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE) || \
     (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE) || (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE) || \
     (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE) || (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE) || \
	 (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE) || (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE) || \
     (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE) || (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE) || \
	 (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE) || (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE))
/**
 * @brief   Set the period callback of a PWM channel within a specific
 *          channels group (eMIOS0 Group1-3, eMIOS1/2 Group0-3).
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] period_callback   PWM period callback. This parameter defines
 *                      the period callback to be invoked when a period
 *                      interrupt occurs.
 *
 * @noapi
 */
static void pwm_lld_set_group_channel_pcb(PWMDriver *pwmp,
                                          pwmcallback_t period_callback) {

  /* Set the callback function.*/
  pwmp->config->period_callback = period_callback;

  /* Deactivate interrupt if callback is not defined, otherwise active
     interrupt.*/
  if (pwmp->config->period_callback == NULL) {
      pwmp->emiosp->CH[pwmp->period_ch].C.B.FEN = 0U;
  } else {
      pwmp->emiosp->CH[pwmp->period_ch].C.B.FEN = 1U;
  }
}
#endif

/**
 * @brief   Set the PWM period callback.
 * @pre     The PWM channel must have been activated using @p pwm_lld_start().
 * @post    The period callback is invoked when a period interrupt occurs. If
 *          period_callback is set to NULL, no period callback is invoked.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] period_callback   PWM period callback. This parameter defines
 *                      the period callback to be invoked when a period
 *                      interrupt occurs.
 *
 * @api
 */
void pwm_lld_set_period_callback(PWMDriver *pwmp,
                                 pwmcallback_t period_callback) {

  osalEnterCritical();

#if (SPC5_PWM_USE_EMIOS0_CH0 == TRUE)
  if (&PWMD1 == pwmp) {
    pwm_lld_set_single_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH0 */

#if (SPC5_PWM_USE_EMIOS0_CH1 == TRUE)
  if (&PWMD2 == pwmp) {
    pwm_lld_set_single_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH1 */

#if (SPC5_PWM_USE_EMIOS0_CH2 == TRUE)
  if (&PWMD3 == pwmp) {
    pwm_lld_set_single_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH2 */

#if (SPC5_PWM_USE_EMIOS0_CH3 == TRUE)
  if (&PWMD4 == pwmp) {
    pwm_lld_set_single_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH3 */

#if (SPC5_PWM_USE_EMIOS0_CH4 == TRUE)
  if (&PWMD5 == pwmp) {
    pwm_lld_set_single_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH4 */

#if (SPC5_PWM_USE_EMIOS0_CH5 == TRUE)
  if (&PWMD6 == pwmp) {
    pwm_lld_set_single_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH5 */

#if (SPC5_PWM_USE_EMIOS0_CH6 == TRUE)
  if (&PWMD7 == pwmp) {
    pwm_lld_set_single_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH6 */

#if (SPC5_PWM_USE_EMIOS0_CH7 == TRUE)
  if (&PWMD8 == pwmp) {
    pwm_lld_set_single_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_CH7 */

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE)
  if (&PWMD9 == pwmp) {
    pwm_lld_set_group_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP1 */

#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE)
  if (&PWMD10 == pwmp) {
    pwm_lld_set_group_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP2 */

#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE)
  if (&PWMD11 == pwmp) {
    pwm_lld_set_group_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS0_GROUP3 */

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE)
  if (&PWMD12 == pwmp) {
    pwm_lld_set_group_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP0 */

#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE)
  if (&PWMD13 == pwmp) {
    pwm_lld_set_group_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP1 */

#if (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE)
  if (&PWMD14 == pwmp) {
    pwm_lld_set_group_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP2 */

#if (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE)
  if (&PWMD15 == pwmp) {
    pwm_lld_set_group_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS1_GROUP3 */

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE)
  if (&PWMD16 == pwmp) {
    pwm_lld_set_group_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP0 */

#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE)
  if (&PWMD17 == pwmp) {
    pwm_lld_set_group_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP1 */

#if (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE)
  if (&PWMD18 == pwmp) {
    pwm_lld_set_group_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP2 */

#if (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
  if (&PWMD19 == pwmp) {
    pwm_lld_set_group_channel_pcb(pwmp, period_callback);
  }
#endif /* SPC5_PWM_USE_EMIOS2_GROUP3 */

  osalExitCritical();
}

#endif /* LLD_USE_PWM */

/** @} */

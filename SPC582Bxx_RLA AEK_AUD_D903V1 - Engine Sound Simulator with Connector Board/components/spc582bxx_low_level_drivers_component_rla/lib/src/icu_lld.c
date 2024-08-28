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
 * @file    icu_lld.c
 * @brief   SPC5xx ICU low level driver code.
 *
 * @addtogroup ICU
 * @{
 */

#include "icu_lld.h"

#if (LLD_USE_ICU == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   ICUD1 driver identifier.
 * @note    The driver ICUD1 allocates the unified channel eMIOS0_CH0
 *          when enabled.
 */
#if (SPC5_ICU_USE_EMIOS0_CH0 == TRUE) || defined(__DOXYGEN__)
ICUDriver ICUD1;
#endif

/**
 * @brief   ICUD2 driver identifier.
 * @note    The driver ICUD2 allocates the unified channel eMIOS0_CH1
 *          when enabled.
 */
#if (SPC5_ICU_USE_EMIOS0_CH1 == TRUE) || defined(__DOXYGEN__)
ICUDriver ICUD2;
#endif

/**
 * @brief   ICUD3 driver identifier.
 * @note    The driver ICUD3 allocates the unified channel eMIOS0_CH2
 *          when enabled.
 */
#if (SPC5_ICU_USE_EMIOS0_CH2 == TRUE) || defined(__DOXYGEN__)
ICUDriver ICUD3;
#endif

/**
 * @brief   ICUD4 driver identifier.
 * @note    The driver ICUD4 allocates the unified channel eMIOS0_CH3
 *          when enabled.
 */
#if (SPC5_ICU_USE_EMIOS0_CH3 == TRUE) || defined(__DOXYGEN__)
ICUDriver ICUD4;
#endif

/**
 * @brief   ICUD5 driver identifier.
 * @note    The driver ICUD5 allocates the unified channel eMIOS0_CH4
 *          when enabled.
 */
#if (SPC5_ICU_USE_EMIOS0_CH4 == TRUE) || defined(__DOXYGEN__)
ICUDriver ICUD5;
#endif

/**
 * @brief   ICUD6 driver identifier.
 * @note    The driver ICUD6 allocates the unified channel eMIOS0_CH5
 *          when enabled.
 */
#if (SPC5_ICU_USE_EMIOS0_CH5 == TRUE) || defined(__DOXYGEN__)
ICUDriver ICUD6;
#endif

/**
 * @brief   ICUD7 driver identifier.
 * @note    The driver ICUD7 allocates the unified channel eMIOS0_CH6
 *          when enabled.
 */
#if (SPC5_ICU_USE_EMIOS0_CH6 == TRUE) || defined(__DOXYGEN__)
ICUDriver ICUD7;
#endif

/**
 * @brief   ICUD8 driver identifier.
 * @note    The driver ICUD8 allocates the unified channel eMIOS0_CH7
 *          when enabled.
 */
#if (SPC5_ICU_USE_EMIOS0_CH7 == TRUE) || defined(__DOXYGEN__)
ICUDriver ICUD8;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/**
 * @brief               ICU IRQ handler.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 *
 * @notapi
 */
void icu_lld_serve_interrupt(ICUDriver *icup) {
  uint32_t gfr = icup->emiosp->GFLAG.R;
  int16_t period, width;

  if ((gfr & (1UL << icup->emios_ch)) != 0U) {
    uint32_t sr = icup->emiosp->CH[icup->emios_ch].S.R;

    if (((sr & EMIOSS_OVFL) != 0U) && (icup->config->overflow_cb != NULL)) {
      icup->emiosp->CH[icup->emios_ch].S.R |= EMIOSS_OVFLC;
      icup->config->overflow_cb(icup);
    }
    if ((sr & EMIOSS_FLAG) != 0U) {
      icup->emiosp->CH[icup->emios_ch].S.R |= EMIOSS_FLAGC;
      if (icup->config->mode == ICU_INPUT_ACTIVE_HIGH) {
        if ((icup->emiosp->CH[icup->emios_ch].S.B.UCIN == 1U)  &&        \
            (icup->config->period_cb != NULL)) {
          icup->pe.a2_3 = (int16_t)icup->emiosp->CH[icup->emios_ch].A.R;
          period = (icup->pe.a2_3 - icup->pe.a2_1);
          icup->period = (uint16_t)(period);
          icup->config->period_cb(icup);
          icup->pe.a2_1 = icup->pe.a2_3;
        } else if ((icup->emiosp->CH[icup->emios_ch].S.B.UCIN == 0UL) && \
            (icup->config->width_cb != NULL)) {
          icup->pe.a2_2 = (int16_t)icup->emiosp->CH[icup->emios_ch].A.R;
          width = (icup->pe.a2_2 - icup->pe.a2_1);
          icup->width = (uint16_t)(width);
          icup->config->width_cb(icup); 
        } else {
          ; /*close if...else if as per MISRA rules*/
        }
      } else if (icup->config->mode == ICU_INPUT_ACTIVE_LOW) {
        if ((icup->emiosp->CH[icup->emios_ch].S.B.UCIN == 1U) &&         \
            (icup->config->width_cb != NULL)) {
          icup->pe.a2_2 = (int16_t)icup->emiosp->CH[icup->emios_ch].A.R;
          width = (icup->pe.a2_2 - icup->pe.a2_1);
          icup->width = (uint16_t)(width);
          icup->config->width_cb(icup); 
        } else if ((icup->emiosp->CH[icup->emios_ch].S.B.UCIN == 0UL) && \
            (icup->config->period_cb != NULL)) {
          icup->pe.a2_3 = (int16_t)icup->emiosp->CH[icup->emios_ch].A.R;
          period = (icup->pe.a2_3 - icup->pe.a2_1);
          icup->period = (uint16_t)(period);
          icup->config->period_cb(icup);
          icup->pe.a2_1 = icup->pe.a2_3;
        } else {
          ; /*close if...else if as per MISRA rules*/
        }
      } else {
        ; /*close if...else if as per MISRA rules*/
      }
    }
    if ((sr & EMIOSS_OVR) != 0U) {
      icup->emiosp->CH[icup->emios_ch].S.R |= EMIOSS_OVRC;
    }
  }
}

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Low level ICU driver initialization.
 *
 * @init
 */
void icu_lld_init(void) {

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

#if (SPC5_ICU_USE_EMIOS0_CH0 == TRUE)
  /* Driver initialization.*/
  ICUD1.config = NULL;
  ICUD1.emiosp = &SPC5_EMIOS_0;
  ICUD1.emios_ch = 0U;
  ICUD1.pe.a2_1 = 0;
  ICUD1.pe.a2_2 = 0;
  ICUD1.pe.a2_3 = 0;
#endif /* SPC5_ICU_USE_EMIOS0_CH0 */

#if (SPC5_ICU_USE_EMIOS0_CH1 == TRUE)
  /* Driver initialization.*/
  ICUD2.config = NULL;
  ICUD2.emiosp = &SPC5_EMIOS_0;
  ICUD2.emios_ch = 1U;
  ICUD2.pe.a2_1 = 0;
  ICUD2.pe.a2_2 = 0;
  ICUD2.pe.a2_3 = 0;
#endif /* SPC5_ICU_USE_EMIOS0_CH1 */

#if (SPC5_ICU_USE_EMIOS0_CH2 == TRUE)
  /* Driver initialization.*/
  ICUD3.config = NULL;
  ICUD3.emiosp = &SPC5_EMIOS_0;
  ICUD3.emios_ch = 2U;
  ICUD3.pe.a2_1 = 0;
  ICUD3.pe.a2_2 = 0;
  ICUD3.pe.a2_3 = 0;
#endif /* SPC5_ICU_USE_EMIOS0_CH2 */

#if (SPC5_ICU_USE_EMIOS0_CH3 == TRUE)
  /* Driver initialization.*/
  ICUD4.config = NULL;
  ICUD4.emiosp = &SPC5_EMIOS_0;
  ICUD4.emios_ch = 3U;
  ICUD4.pe.a2_1 = 0;
  ICUD4.pe.a2_2 = 0;
  ICUD4.pe.a2_3 = 0;
#endif /* SPC5_ICU_USE_EMIOS0_CH3 */

#if (SPC5_ICU_USE_EMIOS0_CH4 == TRUE)
  /* Driver initialization.*/
  ICUD5.config = NULL;
  ICUD5.emiosp = &SPC5_EMIOS_0;
  ICUD5.emios_ch = 4U;
  ICUD5.pe.a2_1 = 0;
  ICUD5.pe.a2_2 = 0;
  ICUD5.pe.a2_3 = 0;
#endif /* SPC5_ICU_USE_EMIOS0_CH4 */

#if (SPC5_ICU_USE_EMIOS0_CH5 == TRUE)
  /* Driver initialization.*/
  ICUD6.config = NULL;
  ICUD6.emiosp = &SPC5_EMIOS_0;
  ICUD6.emios_ch = 5U;
  ICUD6.pe.a2_1 = 0;
  ICUD6.pe.a2_2 = 0;
  ICUD6.pe.a2_3 = 0;
#endif /* SPC5_ICU_USE_EMIOS0_CH5 */

#if (SPC5_ICU_USE_EMIOS0_CH6 == TRUE)
  /* Driver initialization.*/
  ICUD7.config = NULL;
  ICUD7.emiosp = &SPC5_EMIOS_0;
  ICUD7.emios_ch = 6U;
  ICUD7.pe.a2_1 = 0;
  ICUD7.pe.a2_2 = 0;
  ICUD7.pe.a2_3 = 0;
#endif /* SPC5_ICU_USE_EMIOS0_CH6 */

#if (SPC5_ICU_USE_EMIOS0_CH7 == TRUE)
  /* Driver initialization.*/
  ICUD8.config = NULL;
  ICUD8.emiosp = &SPC5_EMIOS_0;
  ICUD8.emios_ch = 7U;
  ICUD8.pe.a2_1 = 0;
  ICUD8.pe.a2_2 = 0;
  ICUD8.pe.a2_3 = 0;
#endif /* SPC5_ICU_USE_EMIOS0_CH7 */

#if (SPC5_ICU_USE_EMIOS0_CH0 == TRUE || SPC5_ICU_USE_EMIOS0_CH1 == TRUE)
  INTC_PSR(SPC5_EMIOS0_GFR_F0F1_NUMBER) = SPC5_EMIOS0_GFR_F0F1_PRIORITY;
#endif /* SPC5_ICU_USE_EMIOS0_CH0 || SPC5_ICU_USE_EMIOS0_CH1 */

#if (SPC5_ICU_USE_EMIOS0_CH2 == TRUE || SPC5_ICU_USE_EMIOS0_CH3 == TRUE)
  INTC_PSR(SPC5_EMIOS0_GFR_F2F3_NUMBER) = SPC5_EMIOS0_GFR_F2F3_PRIORITY;
#endif /* SPC5_ICU_USE_EMIOS0_CH2 || SPC5_ICU_USE_EMIOS0_CH3 */	

#if (SPC5_ICU_USE_EMIOS0_CH4 == TRUE || SPC5_ICU_USE_EMIOS0_CH5 == TRUE)
  INTC_PSR(SPC5_EMIOS0_GFR_F4F5_NUMBER) = SPC5_EMIOS0_GFR_F4F5_PRIORITY;
#endif /* SPC5_ICU_USE_EMIOS0_CH4 || SPC5_ICU_USE_EMIOS0_CH5 */	

#if (SPC5_ICU_USE_EMIOS0_CH6 == TRUE || SPC5_ICU_USE_EMIOS0_CH7 == TRUE)
  INTC_PSR(SPC5_EMIOS0_GFR_F6F7_NUMBER) = SPC5_EMIOS0_GFR_F6F7_PRIORITY;
#endif /* SPC5_ICU_USE_EMIOS0_CH6 || SPC5_ICU_USE_EMIOS0_CH7 */

}

/**
 * @brief   Configures and activates the ICU peripheral.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 * @param[in] config    pointer to the @p ICUConfig object
 *
 * @api
 */
void icu_lld_start(ICUDriver *icup, ICUConfig *config) {
  
  osalEnterCritical();
  
  icup->config = config;

  /* Update the number of active ICU channels.*/
#if (SPC5_ICU_USE_EMIOS0_CH0 == TRUE)
  if (&ICUD1 == icup) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH0 */

#if (SPC5_ICU_USE_EMIOS0_CH1 == TRUE)
  if (&ICUD2 == icup) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH1 */

#if (SPC5_ICU_USE_EMIOS0_CH2 == TRUE)
  if (&ICUD3 == icup) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH2 */

#if (SPC5_ICU_USE_EMIOS0_CH3 == TRUE)
  if (&ICUD4 == icup) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH3 */

#if (SPC5_ICU_USE_EMIOS0_CH4 == TRUE)
  if (&ICUD5 == icup) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH4 */

#if (SPC5_ICU_USE_EMIOS0_CH5 == TRUE)
  if (&ICUD6 == icup) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH5 */

#if (SPC5_ICU_USE_EMIOS0_CH6 == TRUE)
  if (&ICUD7 == icup) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH6 */

#if (SPC5_ICU_USE_EMIOS0_CH7 == TRUE)
  if (&ICUD8== icup) {
    EMIOS0D.emios_active_channels++;
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH7 */

  /* Enable eMIOS0 Clock.*/
#if (SPC5_HAS_EMIOS0 == TRUE)
  if (icup->emiosp == &SPC5_EMIOS_0) {
    emios_enable_clock(&EMIOS0D);
  }
#endif /* SPC5_HAS_EMIOS0 */

  /* Configures the peripheral.*/

  /* Channel enables.*/
  icup->emiosp->UCDIS.R &= ~(1UL << icup->emios_ch);

  /* Clear pending IRQs (if any).*/
  icup->emiosp->CH[icup->emios_ch].S.R = EMIOSS_OVRC |
      EMIOSS_OVFLC | EMIOSS_FLAGC;

  icup->emiosp->CH[icup->emios_ch].C.B.UCPREN = 0;
  icup->emiosp->CH[icup->emios_ch].C.R |=
      EMIOSC_BSL(EMIOS_BSL_INTERNAL_COUNTER) |
      EMIOSC_EDSEL | EMIOS_CCR_MODE_SAIC;
  icup->emiosp->CH[icup->emios_ch].C.B.UCPRE = (icupsc_t)(icup->config->psc - 1UL);
  icup->emiosp->CH[icup->emios_ch].C.R |= EMIOSC_UCPREN;

  /* Set source polarity.*/
  if(icup->config->mode == ICU_INPUT_ACTIVE_HIGH){
    icup->emiosp->CH[icup->emios_ch].C.R |= EMIOSC_EDPOL;
  } else {
    icup->emiosp->CH[icup->emios_ch].C.R &= ~EMIOSC_EDPOL;
  }

  /* Channel disables.*/
  icup->emiosp->UCDIS.R |= (1UL << icup->emios_ch);

  osalExitCritical();
}

/**
 * @brief   Deactivates the ICU peripheral.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 *
 * @api
 */
void icu_lld_stop(ICUDriver *icup) {

  osalEnterCritical();


#if (SPC5_ICU_USE_EMIOS0_CH0 == TRUE)
  if (&ICUD1 == icup) {
    /* Reset UC Control Register.*/
    /* In order to clear the Control Register, the channel
       must be temporary re-enabled.*/
    icup->emiosp->UCDIS.R &= ~(1UL << icup->emios_ch);
    icup->emiosp->CH[icup->emios_ch].C.R = 0;
    icup->emiosp->UCDIS.R |= (1UL << icup->emios_ch);
    EMIOS0D.emios_active_channels--;
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH0 */

#if (SPC5_ICU_USE_EMIOS0_CH1 == TRUE)
  if (&ICUD2 == icup) {
    /* Reset UC Control Register.*/
    /* In order to clear the Control Register, the channel
       must be temporary re-enabled.*/
    icup->emiosp->UCDIS.R &= ~(1UL << icup->emios_ch);
    icup->emiosp->CH[icup->emios_ch].C.R = 0;
    icup->emiosp->UCDIS.R |= (1UL << icup->emios_ch);
    EMIOS0D.emios_active_channels--;
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH1 */

#if (SPC5_ICU_USE_EMIOS0_CH2 == TRUE)
  if (&ICUD3 == icup) {
    /* Reset UC Control Register.*/
    /* In order to clear the Control Register, the channel
       must be temporary re-enabled.*/
    icup->emiosp->UCDIS.R &= ~(1UL << icup->emios_ch);
    icup->emiosp->CH[icup->emios_ch].C.R = 0;
    icup->emiosp->UCDIS.R |= (1UL << icup->emios_ch);
    EMIOS0D.emios_active_channels--;;
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH2 */

#if (SPC5_ICU_USE_EMIOS0_CH3 == TRUE)
  if (&ICUD4 == icup) {
    /* Reset UC Control Register.*/
    /* In order to clear the Control Register, the channel
       must be temporary re-enabled.*/
    icup->emiosp->UCDIS.R &= ~(1UL << icup->emios_ch);
    icup->emiosp->CH[icup->emios_ch].C.R = 0;
    icup->emiosp->UCDIS.R |= (1UL << icup->emios_ch);
    EMIOS0D.emios_active_channels--;
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH3 */

#if (SPC5_ICU_USE_EMIOS0_CH4 == TRUE)
  if (&ICUD5 == icup) {
    /* Reset UC Control Register.*/
    /* In order to clear the Control Register, the channel
       must be temporary re-enabled.*/
    icup->emiosp->UCDIS.R &= ~(1UL << icup->emios_ch);
    icup->emiosp->CH[icup->emios_ch].C.R = 0;
    icup->emiosp->UCDIS.R |= (1UL << icup->emios_ch);
    EMIOS0D.emios_active_channels--;
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH4 */

#if (SPC5_ICU_USE_EMIOS0_CH5 == TRUE)
  if (&ICUD6 == icup) {
    /* Reset UC Control Register.*/
    /* In order to clear the Control Register, the channel
       must be temporary re-enabled.*/
    icup->emiosp->UCDIS.R &= ~(1UL << icup->emios_ch);
    icup->emiosp->CH[icup->emios_ch].C.R = 0;
    icup->emiosp->UCDIS.R |= (1UL << icup->emios_ch);
    EMIOS0D.emios_active_channels--;
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH5 */

#if (SPC5_ICU_USE_EMIOS0_CH6 == TRUE)
  if (&ICUD7 == icup) {
    /* Reset UC Control Register.*/
    /* In order to clear the Control Register, the channel
       must be temporary re-enabled.*/
    icup->emiosp->UCDIS.R &= ~(1UL << icup->emios_ch);
    icup->emiosp->CH[icup->emios_ch].C.R = 0;
    icup->emiosp->UCDIS.R |= (1UL << icup->emios_ch);
    EMIOS0D.emios_active_channels--;
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH6 */

#if (SPC5_ICU_USE_EMIOS0_CH7 == TRUE)
  if (&ICUD8== icup) {
    /* Reset UC Control Register.*/
    /* In order to clear the Control Register, the channel
       must be temporary re-enabled.*/
    icup->emiosp->UCDIS.R &= ~(1UL << icup->emios_ch);
    icup->emiosp->CH[icup->emios_ch].C.R = 0;
    icup->emiosp->UCDIS.R |= (1UL << icup->emios_ch);
    EMIOS0D.emios_active_channels--;
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH7 */

  /* Disable eMIOS0 Clock.*/
#if (SPC5_HAS_EMIOS0 == TRUE)
  if (icup->emiosp == &SPC5_EMIOS_0) {
    emios_disable_clock(&EMIOS0D);
  }
#endif /* SPC5_HAS_EMIOS0 */

  osalExitCritical();
}

/**
 * @brief   Enables a ICU single channel (Group0).
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 *
 * @api
 */
static void icu_enable_single_channel(ICUDriver *icup) {

  /* Channel enables.*/
  icup->emiosp->UCDIS.R &= ~(1UL << icup->emios_ch);

  /* Clear pending IRQs (if any).*/
  icup->emiosp->CH[icup->emios_ch].S.R = EMIOSS_OVRC |
      EMIOSS_OVFLC | EMIOSS_FLAGC;

  /* Active interrupts.*/
  if (icup->config->period_cb != NULL || icup->config->width_cb != NULL ||  \
      icup->config->overflow_cb != NULL) {
    icup->emiosp->CH[icup->emios_ch].C.B.FEN = 1U;
  }
}
	  
/**
 * @brief   Enables the input capture.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 *
 * @api
 */
void icu_lld_enable(ICUDriver *icup) {

  osalEnterCritical();

#if (SPC5_ICU_USE_EMIOS0_CH0 == TRUE)
  if (&ICUD1 == icup) {
    icu_enable_single_channel(icup);
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH0 */

#if (SPC5_ICU_USE_EMIOS0_CH1 == TRUE)
  if (&ICUD2 == icup) {
    icu_enable_single_channel(icup);
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH1 */

#if (SPC5_ICU_USE_EMIOS0_CH2 == TRUE)
  if (&ICUD3 == icup) {
    icu_enable_single_channel(icup);
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH2 */

#if (SPC5_ICU_USE_EMIOS0_CH3 == TRUE)
  if (&ICUD4 == icup) {
    icu_enable_single_channel(icup);
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH3 */

#if (SPC5_ICU_USE_EMIOS0_CH4 == TRUE)
  if (&ICUD5 == icup) {
    icu_enable_single_channel(icup);
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH4 */

#if (SPC5_ICU_USE_EMIOS0_CH5 == TRUE)
  if (&ICUD6 == icup) {
    icu_enable_single_channel(icup);
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH5 */

#if (SPC5_ICU_USE_EMIOS0_CH6 == TRUE)
  if (&ICUD7 == icup) {
    icu_enable_single_channel(icup);
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH6 */

#if (SPC5_ICU_USE_EMIOS0_CH7 == TRUE)
  if (&ICUD8 == icup) {
    icu_enable_single_channel(icup);
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH7 */

  osalExitCritical();
}

/**
 * @brief   Disables a ICU single channel (Group0).
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 *
 * @api
 */
static void icu_disable_single_channel(ICUDriver *icup) {

  /* Clear pending IRQs (if any).*/
  icup->emiosp->CH[icup->emios_ch].S.R = EMIOSS_OVRC |
        EMIOSS_OVFLC | EMIOSS_FLAGC;

  /* Disable interrupts.*/
  icup->emiosp->CH[icup->emios_ch].C.B.FEN = 0;

  /* Channel disables.*/
  icup->emiosp->UCDIS.R |= (1UL << icup->emios_ch);
}

/**
 * @brief   Disables the input capture.
 *
 * @param[in] icup      pointer to the @p ICUDriver object
 *
 * @api
 */
void icu_lld_disable(ICUDriver *icup) {

  osalEnterCritical();

#if (SPC5_ICU_USE_EMIOS0_CH0 == TRUE)
  if (&ICUD1 == icup) {
    icu_disable_single_channel(icup);
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH0 */

#if (SPC5_ICU_USE_EMIOS0_CH1 == TRUE)
  if (&ICUD2 == icup) {
    icu_disable_single_channel(icup);
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH1 */

#if (SPC5_ICU_USE_EMIOS0_CH2 == TRUE)
  if (&ICUD3 == icup) {
    icu_disable_single_channel(icup);
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH2 */

#if (SPC5_ICU_USE_EMIOS0_CH3 == TRUE)
  if (&ICUD4 == icup) {
    icu_disable_single_channel(icup);
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH3 */

#if (SPC5_ICU_USE_EMIOS0_CH4 == TRUE)
  if (&ICUD5 == icup) {
    icu_disable_single_channel(icup);
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH4 */

#if (SPC5_ICU_USE_EMIOS0_CH5 == TRUE)
  if (&ICUD6 == icup) {
    icu_disable_single_channel(icup);
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH5 */

#if (SPC5_ICU_USE_EMIOS0_CH6 == TRUE)
  if (&ICUD7 == icup) {
    icu_disable_single_channel(icup);
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH6 */

#if (SPC5_ICU_USE_EMIOS0_CH7 == TRUE)
  if (&ICUD8 == icup) {
    icu_disable_single_channel(icup);
  }
#endif /* SPC5_ICU_USE_EMIOS0_CH7 */

  osalExitCritical();
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

#endif /* LLD_USE_ICU */

/** @} */

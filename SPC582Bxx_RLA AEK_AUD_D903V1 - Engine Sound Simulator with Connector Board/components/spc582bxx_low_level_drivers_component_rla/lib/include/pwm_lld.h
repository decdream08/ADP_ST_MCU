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
 * @file    pwm_lld.h
 * @brief   SPC5xx PWM low level driver header.
 *
 * @addtogroup PWM
 * @{
 */

#ifndef _PWM_LLD_H_
#define _PWM_LLD_H_

#include "spc5_lld.h"
#include "lldconf.h"

#if (LLD_USE_PWM == TRUE) || defined(__DOXYGEN__)

#include "spc5_emios.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    PWM output mode macros
 * @{
 */
/**
 * @brief   Standard output modes mask.
 */
#define PWM_OUTPUT_MASK                         0x0F

/**
 * @brief   Output not driven, callback only.
 */
#define PWM_OUTPUT_DISABLED                     0x00

/**
 * @brief   Positive PWM logic, active is logic level one.
 */
#define PWM_OUTPUT_ACTIVE_HIGH                  0x01

/**
 * @brief   Inverse PWM logic, active is logic level zero.
 */
#define PWM_OUTPUT_ACTIVE_LOW                   0x02

/**
 * @brief   PWM Output Pulse Width and Frequency Modulation Buffered (OPWFMB) mode.
 */
#define SPC5_PWM_MODE_OPWFMB                    0x00

/**
 * @brief   PWM Output Pulse Width Modulation Buffered (OPWMB) mode.
 */
#define SPC5_PWM_MODE_OPWMB                     0x01

/**
 * @brief   PWM Output Pulse Width Modulation with Trigger (OPWFMB) mode.
 */
#define SPC5_PWM_MODE_OPWMT                     0x02
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   EMIOS0 PWM CH9-CH15 mode.
 * @note    The default is @p SPC5_PWM_MODE_OPWMB.
 */
#if !defined(SPC5_PWM_EMIOS0_GROUP1_MODE) || defined(__DOXYGEN__)
#define SPC5_PWM_EMIOS0_GROUP1_MODE         SPC5_PWM_MODE_OPWMB
#endif

/**
 * @brief   EMIOS0 PWM CH17-CH23 mode.
 * @note    The default is @p SPC5_PWM_MODE_OPWMB.
 */
#if !defined(SPC5_PWM_EMIOS0_GROUP2_MODE) || defined(__DOXYGEN__)
#define SPC5_PWM_EMIOS0_GROUP2_MODE         SPC5_PWM_MODE_OPWMB
#endif

/**
 * @brief   EMIOS0 PWM CH25-CH31 mode.
 * @note    The default is @p SPC5_PWM_MODE_OPWMB.
 */
#if !defined(SPC5_PWM_EMIOS0_GROUP3_MODE) || defined(__DOXYGEN__)
#define SPC5_PWM_EMIOS0_GROUP3_MODE         SPC5_PWM_MODE_OPWMB
#endif

/**
 * @brief   EMIOS1 PWM CH1-CH7 mode.
 * @note    The default is @p SPC5_PWM_MODE_OPWMB.
 */
#if !defined(SPC5_PWM_EMIOS1_GROUP0_MODE) || defined(__DOXYGEN__)
#define SPC5_PWM_EMIOS1_GROUP0_MODE         SPC5_PWM_MODE_OPWMB
#endif

/**
 * @brief   EMIOS1 PWM CH9-CH15 mode.
 * @note    The default is @p SPC5_PWM_MODE_OPWMB.
 */
#if !defined(SPC5_PWM_EMIOS1_GROUP1_MODE) || defined(__DOXYGEN__)
#define SPC5_PWM_EMIOS1_GROUP1_MODE         SPC5_PWM_MODE_OPWMB
#endif

/**
 * @brief   EMIOS1 PWM CH17-CH23 mode.
 * @note    The default is @p SPC5_PWM_MODE_OPWMB.
 */
#if !defined(SPC5_PWM_EMIOS1_GROUP2_MODE) || defined(__DOXYGEN__)
#define SPC5_PWM_EMIOS1_GROUP2_MODE         SPC5_PWM_MODE_OPWMB
#endif

/**
 * @brief   EMIOS1 PWM CH25-CH31 mode.
 * @note    The default is @p SPC5_PWM_MODE_OPWMB.
 */
#if !defined(SPC5_PWM_EMIOS1_GROUP3_MODE) || defined(__DOXYGEN__)
#define SPC5_PWM_EMIOS1_GROUP3_MODE         SPC5_PWM_MODE_OPWMB
#endif

/**
 * @brief   eMIOS2 PWM CH1-CH7 mode.
 * @note    The default is @p SPC5_PWM_MODE_OPWMB.
 */
#if !defined(SPC5_PWM_eMIOS2_GROUP0_MODE) || defined(__DOXYGEN__)
#define SPC5_PWM_eMIOS2_GROUP0_MODE         SPC5_PWM_MODE_OPWMB
#endif

/**
 * @brief   eMIOS2 PWM CH9-CH15 mode.
 * @note    The default is @p SPC5_PWM_MODE_OPWMB.
 */
#if !defined(SPC5_PWM_eMIOS2_GROUP1_MODE) || defined(__DOXYGEN__)
#define SPC5_PWM_eMIOS2_GROUP1_MODE         SPC5_PWM_MODE_OPWMB
#endif

/**
 * @brief   eMIOS2 PWM CH17-CH23 mode.
 * @note    The default is @p SPC5_PWM_MODE_OPWMB.
 */
#if !defined(SPC5_PWM_eMIOS2_GROUP2_MODE) || defined(__DOXYGEN__)
#define SPC5_PWM_eMIOS2_GROUP2_MODE         SPC5_PWM_MODE_OPWMB
#endif

/**
 * @brief   eMIOS2 PWM CH25-CH31 mode.
 * @note    The default is @p SPC5_PWM_MODE_OPWMB.
 */
#if !defined(SPC5_PWM_eMIOS2_GROUP3_MODE) || defined(__DOXYGEN__)
#define SPC5_PWM_eMIOS2_GROUP3_MODE         SPC5_PWM_MODE_OPWMB
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if (SPC5_PWM_USE_EMIOS0_CH0    == TRUE || SPC5_PWM_USE_EMIOS0_CH1    == TRUE || \
     SPC5_PWM_USE_EMIOS0_CH2    == TRUE || SPC5_PWM_USE_EMIOS0_CH3    == TRUE || \
     SPC5_PWM_USE_EMIOS0_CH4    == TRUE || SPC5_PWM_USE_EMIOS0_CH5    == TRUE || \
     SPC5_PWM_USE_EMIOS0_CH6    == TRUE || SPC5_PWM_USE_EMIOS0_CH7    == TRUE || \
     SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE || SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE || \
     SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE)
#define SPC5_PWM_USE_EMIOS0                 TRUE
#else
#define SPC5_PWM_USE_EMIOS0                 FALSE
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE || SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE || \
     SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE || SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE)
#define SPC5_PWM_USE_EMIOS1                 TRUE
#else
#define SPC5_PWM_USE_EMIOS1                 FALSE
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE || SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE || \
     SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE || SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE)
#define SPC5_PWM_USE_EMIOS2                 TRUE
#else
#define SPC5_PWM_USE_EMIOS2                 FALSE
#endif

#if (SPC5_HAS_EMIOS0 == FALSE) && (SPC5_PWM_USE_EMIOS0 == TRUE)
#error "EMIOS0 not present in the selected device"
#endif

#if (SPC5_HAS_EMIOS1 == FALSE) && (SPC5_PWM_USE_EMIOS1 == TRUE)
#error "EMIOS1 not present in the selected device"
#endif

#if (SPC5_HAS_EMIOS2 == FALSE) && (SPC5_PWM_USE_EMIOS2 == TRUE)
#error "EMIOS2 not present in the selected device"
#endif

#if (SPC5_PWM_USE_EMIOS0 == FALSE) && (SPC5_PWM_USE_EMIOS1 == FALSE) && \
    (SPC5_PWM_USE_EMIOS2 == FALSE)
#error "PWM driver activated but no Channels assigned"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a structure representing a PWM driver.
 */
typedef struct PWMDriver PWMDriver;

/**
 * @brief   PWM notification callback type.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 */
typedef void (*pwmcallback_t)(PWMDriver *pwmp);

/**
 * @brief   PWM output mode type.
 */
typedef uint32_t pwmoutmode_t;

/**
 * @brief   PWM prescaler type.
 */
typedef uint8_t  pwmpsc_t;

/**
 * @brief   PWM counter type.
 */
typedef uint32_t pwmcnt_t;

/**
 * @brief   PWM channel type.
 */
typedef uint8_t pwmchannel_t;

/**
 * @brief   PWM mode type.
 */
typedef uint32_t pwmmode_t;

/**
 * @brief   Channel configuration structure.
 */
typedef struct {
  /**
   * @brief Channel active logic level.
   */
  pwmoutmode_t              mode;
  /**
   * @brief Channel callback pointer.
   * @note  This callback is invoked on the channel compare event. If set to
   *        @p NULL then the callback is disabled.
   */
  pwmcallback_t             channel_callback;

} PWMChannelConfig;

/**
 * @brief   Driver configuration structure.
 */
typedef struct {
  /**
   * @brief Flag set if the External clock is selected.
   * @note  This parameter is taken into account only for the channel groups 
   *        (eMIOS0 Group1-Group3, eMIOS1 Group0-Group3).
   */
  uint8_t                   ext_clk;
  /**
   * @brief Counter prescaler.
   */
  pwmpsc_t                  psc;
  /**
   * @brief Period in ticks.
   */
  pwmcnt_t                  period;
  /**
   * @brief Periodic callback pointer.
   * @note  This callback is invoked on PWM counter reset. If set to
   *        @p NULL then the callback is disabled.
   */
  pwmcallback_t             period_callback;
  /**
   * @brief Current configuration data.
   */
  PWMChannelConfig          *ch_config[7];
} PWMConfig;

/**
 * @brief   Structure representing an PWM driver.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
struct PWMDriver {
  /**
   * @brief eMIOS channel used as period for related to the driver.
   * @note  This parameter is the channel number for the PWM drivers related to
   *        a single channel (PWD1 - PWD8) and is the number of first channel
   *        of the group for the PWM drivers related to a group channel (PWD9 -
   *        PW11).
   */
  pwmchannel_t              period_ch;
  /**
   * @brief PWM mode.
   */
  pwmmode_t                 mode;
  /**
   * @brief Current PWM period in ticks.
   */
  pwmcnt_t                  period;
  /**
   * @brief Current configuration data.
   */
  PWMConfig                 *config;
  /**
   * @brief Pointer to the eMIOSx registers block.
   */
  volatile struct spc5_emios *emiosp;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @name    PWM duty cycle conversion
 * @{
 */
/**
 * @brief   Converts from period fraction to counter ticks.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] denominator denominator of the fraction
 * @param[in] numerator numerator of the fraction
 * @return              The counter ticks as fraction of the period.
 *
 * @api
 */
#define PWM_PERIOD_FRACTION(pwmp, denominator, numerator)                   \
  ((pwmcnt_t)((((pwmcnt_t)(pwmp)->period) *                                 \
               (pwmcnt_t)(numerator)) / (pwmcnt_t)(denominator)))

/**
 * @brief   Converts from degrees to pulse width.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] degrees   degrees as an integer between 0 and 36000
 * @return              The pulse width to be passed to @p pwm_lld_enable_channel().
 *
 * @api
 */
#define PWM_DEGREES_TO_WIDTH(pwmp, degrees)                                 \
  PWM_PERIOD_FRACTION(pwmp, 36000, degrees)

/**
 * @brief   Converts from percentage of the period to pulse width in ticks.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] percentage percentage as an integer between 0 and 10000
 * @return              The pulse width to be passed to @p pwm_lld_enable_channel().
 *
 * @api
 */
#define PWM_PERCENTAGE_TO_WIDTH(pwmp, percentage)                           \
  PWM_PERIOD_FRACTION(pwmp, 10000, percentage)

/**
 * @brief   Converts from percentage of the period to dead time in ticks.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] percentage percentage as an integer between 0 and 10000
 * @return              The dead time to be passed to @p pwm_lld_enable_channel().
 *
 * @api
 */
#define PWM_PERCENTAGE_TO_DEADTIME(pwmp, percentage)                        \
  PWM_PERIOD_FRACTION(pwmp, 10000, percentage)

/**
 * @brief   Converts from percentage of the period to delay in ticks.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] percentage percentage as an integer between 0 and 10000
 * @return              The dealy to be passed to @p pwm_lld_enable_channel().
 *
 * @api
 */
#define PWM_PERCENTAGE_TO_DELAY(pwmp, percentage)                           \
  PWM_PERIOD_FRACTION(pwmp, 10000, percentage)

/**
 * @brief   Converts from percentage of the period to trigger delay in ticks.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] percentage percentage as an integer between 0 and 10000
 * @return              The number of ticks between the start of the PWM pulse
 *                      and the trigger generation to be passed to @p 
 *                      pwm_lld_enable_channel().
 *
 * @api
 */
#define PWM_PERCENTAGE_TO_TRIGGER(pwmp, percentage)                         \
  PWM_PERIOD_FRACTION(pwmp, 10000, percentage)
/** @} */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/**
 * @brief   PWM drivers.
 */
#if (SPC5_PWM_USE_EMIOS0_CH0 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD1;
#endif

#if (SPC5_PWM_USE_EMIOS0_CH1 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD2;
#endif

#if (SPC5_PWM_USE_EMIOS0_CH2 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD3;
#endif

#if (SPC5_PWM_USE_EMIOS0_CH3 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD4;
#endif

#if (SPC5_PWM_USE_EMIOS0_CH4 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD5;
#endif

#if (SPC5_PWM_USE_EMIOS0_CH5 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD6;
#endif

#if (SPC5_PWM_USE_EMIOS0_CH6 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD7;
#endif

#if (SPC5_PWM_USE_EMIOS0_CH7 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD8;
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD9;
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD10;
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD11;
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD12;
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD13;
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD14;
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD15;
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD16;
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD17;
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD18;
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE) && !defined(__DOXYGEN__)
extern PWMDriver PWMD19;
#endif

/**
 * @brief   PWM channel groups drivers.
 */
#if (SPC5_PWM_USE_EMIOS0_GROUP1 == TRUE) || defined(__DOXYGEN__)
#define PWMGRD1                             PWMD9
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP2 == TRUE) || defined(__DOXYGEN__)
#define PWMGRD2                             PWMD10
#endif

#if (SPC5_PWM_USE_EMIOS0_GROUP3 == TRUE) || defined(__DOXYGEN__)
#define PWMGRD3                             PWMD11
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP0 == TRUE) || defined(__DOXYGEN__)
#define PWMGRD4                             PWMD12
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP1 == TRUE) || defined(__DOXYGEN__)
#define PWMGRD5                             PWMD13
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP2 == TRUE) || defined(__DOXYGEN__)
#define PWMGRD6                             PWMD14
#endif

#if (SPC5_PWM_USE_EMIOS1_GROUP3 == TRUE) || defined(__DOXYGEN__)
#define PWMGRD7                             PWMD15
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP0 == TRUE) || defined(__DOXYGEN__)
#define PWMGRD8                             PWMD16
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP1 == TRUE) || defined(__DOXYGEN__)
#define PWMGRD9                             PWMD17
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP2 == TRUE) || defined(__DOXYGEN__)
#define PWMGRD10                            PWMD18
#endif

#if (SPC5_PWM_USE_EMIOS2_GROUP3 == TRUE) || defined(__DOXYGEN__)
#define PWMGRD11                            PWMD19
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void pwm_lld_init(void);
  void pwm_lld_start(PWMDriver *pwmp, PWMConfig *config);
  void pwm_lld_stop(PWMDriver *pwmp);
  void pwm_lld_change_period(PWMDriver *pwmp, pwmcnt_t period);
  void pwm_lld_enable_channel(PWMDriver *pwmp,
                              pwmchannel_t channel,
                              pwmcnt_t width,
                              pwmcnt_t deadtime,
                              pwmcnt_t delay,
                              pwmcnt_t trigger);
  void pwm_lld_disable_channel(PWMDriver *pwmp, pwmchannel_t channel);
  void pwm_lld_set_channel_callback(PWMDriver *pwmp,
                                    pwmchannel_t channel,
                                    pwmcallback_t channel_callback);
  void pwm_lld_set_period_callback(PWMDriver *pwmp,
                                   pwmcallback_t period_callback);
  void pwm_lld_serve_single_channel_interrupt(PWMDriver *pwmp);
  void pwm_lld_serve_group_period_interrupt(PWMDriver *pwmp);
  void pwm_lld_serve_group_channel_interrupt(PWMDriver *pwmp, pwmchannel_t channel);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_PWM */

#endif /* _PWM_LLD_H_ */

/** @} */

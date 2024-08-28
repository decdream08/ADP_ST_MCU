/****************************************************************************
*
* Copyright © 2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    bctu_lld.h
 * @brief   SPC5xx BCTU low level driver header.
 *
 * @addtogroup BCTU
 * @{
 */

#ifndef _BCTU_LLD_H_
#define _BCTU_LLD_H_

#include "spc5_lld.h"
#include "lldconf.h"

#if (LLD_USE_BCTU == TRUE) || defined(__DOXYGEN__)

#include "spc5_bctu.h"

#if (LLD_USE_PWM == TRUE || LLD_USE_ICU == TRUE)
#include "spc5_emios.h"
#endif

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   BCTU peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_BCTU_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_BCTU_START_PCTL                (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   BCTU peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if !defined(SPC5_BCTU_STOP_PCTL) || defined(__DOXYGEN__)
#define SPC5_BCTU_STOP_PCTL                 (SPC5_ME_PCTL_RUN(0) |          \
                                             SPC5_ME_PCTL_LP(0))
#endif

/**
 * @brief   BCTU EMIOS0 trigger enable switch.
 * @note    The default configuration is FALSE (EMIOS0 not used as trigger).
 */
#if !defined(SPC5_BCTU_USE_EMIOS0_TRIGGER) || defined(__DOXYGEN__)
#define SPC5_BCTU_USE_EMIOS0_TRIGGER        FALSE
#endif

/**
 * @brief   BCTU EMIOS1 trigger enable switch.
 * @note    The default configuration is FALSE (EMIOS1 not used as trigger).
 */
#if !defined(SPC5_BCTU_USE_EMIOS1_TRIGGER) || defined(__DOXYGEN__)
#define SPC5_BCTU_USE_EMIOS1_TRIGGER        FALSE
#endif

/**
 * @brief   BCTU EMIOS2 trigger enable switch.
 * @note    The default configuration is FALSE (EMIOS2 not used as trigger).
 */
#if !defined(SPC5_BCTU_USE_EMIOS2_TRIGGER) || defined(__DOXYGEN__)
#define SPC5_BCTU_USE_EMIOS2_TRIGGER        FALSE
#endif

/**
 * @brief   EMIOS0 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_EMIOS0_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_EMIOS0_START_PCTL              (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   EMIOS1 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_EMIOS1_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_EMIOS1_START_PCTL              (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   EMIOS2 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_EMIOS2_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_EMIOS2_START_PCTL              (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/**
 * @brief   BCTU PIT0 trigger enable switch.
 * @note    The default configuration is FALSE (PIT0 not used as trigger).
 */
#if !defined(SPC5_BCTU_USE_PIT0_TRIGGER) || defined(__DOXYGEN__)
#define SPC5_BCTU_USE_PIT0_TRIGGER          FALSE
#endif

/**
 * @brief   BCTU PIT1 trigger enable switch.
 * @note    The default configuration is FALSE (PIT1 not used as trigger).
 */
#if !defined(SPC5_BCTU_USE_PIT1_TRIGGER) || defined(__DOXYGEN__)
#define SPC5_BCTU_USE_PIT1_TRIGGER          FALSE
#endif

/**
 * @brief   SARADC SV peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if !defined(SPC5_SARADC12_SV_START_PCTL) || defined(__DOXYGEN__)
#define SPC5_SARADC12_SV_START_PCTL         (SPC5_ME_PCTL_RUN(1) |          \
                                             SPC5_ME_PCTL_LP(2))
#endif

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if (SPC5_BCTU_USE_EMIOS0_TRIGGER == TRUE || SPC5_BCTU_USE_EMIOS1_TRIGGER == TRUE || \
     SPC5_BCTU_USE_EMIOS2_TRIGGER == TRUE)
#define SPC5_BCTU_USE_EMIOS_TRIGGER         TRUE
#else
#define SPC5_BCTU_USE_EMIOS_TRIGGER         FALSE
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/* If BCTU uses the eMIOS as trigger and the eMIOS low level driver is disabled,
   the eMIOS register definitions and base addresses has to be defined.*/
#if ((SPC5_BCTU_USE_EMIOS_TRIGGER == TRUE) && (LLD_USE_PWM == FALSE && LLD_USE_ICU == FALSE))
/* PPC register definitions not compatible with MISRA rules on bit-fields 
   (Rules 6.1). */
/*lint -e46 */
struct spc5_emios {
  union {
    vuint32_t R;
    struct {
      vuint32_t unused_3:1;
      vuint32_t MDIS:1;
      vuint32_t FRZ:1;
      vuint32_t GTBE:1;
      vuint32_t unused_2:1;
      vuint32_t GPREN:1;
      vuint32_t unused_1:10;
      vuint32_t GPRE:8;
      vuint32_t unused_0:8;
    } B;
  } MCR;

  union {
    vuint32_t R;
    struct {
      vuint32_t F31:1;
      vuint32_t F30:1;
      vuint32_t F29:1;
      vuint32_t F28:1;
      vuint32_t F27:1;
      vuint32_t F26:1;
      vuint32_t F25:1;
      vuint32_t F24:1;
      vuint32_t F23:1;
      vuint32_t F22:1;
      vuint32_t F21:1;
      vuint32_t F20:1;
      vuint32_t F19:1;
      vuint32_t F18:1;
      vuint32_t F17:1;
      vuint32_t F16:1;
      vuint32_t F15:1;
      vuint32_t F14:1;
      vuint32_t F13:1;
      vuint32_t F12:1;
      vuint32_t F11:1;
      vuint32_t F10:1;
      vuint32_t F9:1;
      vuint32_t F8:1;
      vuint32_t F7:1;
      vuint32_t F6:1;
      vuint32_t F5:1;
      vuint32_t F4:1;
      vuint32_t F3:1;
      vuint32_t F2:1;
      vuint32_t F1:1;
      vuint32_t F0:1;
    } B;
  } GFLAG;

  union {
    vuint32_t R;
    struct {
      vuint32_t OU31:1;
      vuint32_t OU30:1;
      vuint32_t OU29:1;
      vuint32_t OU28:1;
      vuint32_t OU27:1;
      vuint32_t OU26:1;
      vuint32_t OU25:1;
      vuint32_t OU24:1;
      vuint32_t OU23:1;
      vuint32_t OU22:1;
      vuint32_t OU21:1;
      vuint32_t OU20:1;
      vuint32_t OU19:1;
      vuint32_t OU18:1;
      vuint32_t OU17:1;
      vuint32_t OU16:1;
      vuint32_t OU15:1;
      vuint32_t OU14:1;
      vuint32_t OU13:1;
      vuint32_t OU12:1;
      vuint32_t OU11:1;
      vuint32_t OU10:1;
      vuint32_t OU9:1;
      vuint32_t OU8:1;
      vuint32_t OU7:1;
      vuint32_t OU6:1;
      vuint32_t OU5:1;
      vuint32_t OU4:1;
      vuint32_t OU3:1;
      vuint32_t OU2:1;
      vuint32_t OU1:1;
      vuint32_t OU0:1;
    } B;
  } OUDIS;

  union {
    vuint32_t R;
    struct {
      vuint32_t CHDIS31:1;
      vuint32_t CHDIS30:1;
      vuint32_t CHDIS29:1;
      vuint32_t CHDIS28:1;
      vuint32_t CHDIS27:1;
      vuint32_t CHDIS26:1;
      vuint32_t CHDIS25:1;
      vuint32_t CHDIS24:1;
      vuint32_t CHDIS23:1;
      vuint32_t CHDIS22:1;
      vuint32_t CHDIS21:1;
      vuint32_t CHDIS20:1;
      vuint32_t CHDIS19:1;
      vuint32_t CHDIS18:1;
      vuint32_t CHDIS17:1;
      vuint32_t CHDIS16:1;
      vuint32_t CHDIS15:1;
      vuint32_t CHDIS14:1;
      vuint32_t CHDIS13:1;
      vuint32_t CHDIS12:1;
      vuint32_t CHDIS11:1;
      vuint32_t CHDIS10:1;
      vuint32_t CHDIS9:1;
      vuint32_t CHDIS8:1;
      vuint32_t CHDIS7:1;
      vuint32_t CHDIS6:1;
      vuint32_t CHDIS5:1;
      vuint32_t CHDIS4:1;
      vuint32_t CHDIS3:1;
      vuint32_t CHDIS2:1;
      vuint32_t CHDIS1:1;
      vuint32_t CHDIS0:1;
    } B;
  } UCDIS;

  vuint8_t ADR_reserved0[16];

  struct {
    union {
      vuint32_t R;
      struct {
        vuint32_t unused_0:16;
        vuint32_t A:16;
      } B;
    } A;

    union {
      vuint32_t R;
      struct {
        vuint32_t unused_0:16;
        vuint32_t B:16;
      } B;
    } B;

    union {
      vuint32_t R;
      struct {
        vuint32_t unused_0:16;
        vuint32_t C:16;
      } B;
    } CNT;

    union {
      vuint32_t R;
      struct {
        vuint32_t FREN:1;
        vuint32_t ODIS:1;
        vuint32_t ODISSL:2;
        vuint32_t UCPRE:2;
        vuint32_t UCPREN:1;
        vuint32_t DMA:1;
        vuint32_t unused_2:1;
        vuint32_t IF:4;
        vuint32_t FCK:1;
        vuint32_t FEN:1;
        vuint32_t unused_1:3;
        vuint32_t FORCMA:1;
        vuint32_t FORCMB:1;
        vuint32_t unused_0:1;
        vuint32_t BSL:2;
        vuint32_t EDSEL:1;
        vuint32_t EDPOL:1;
        vuint32_t MODE:7;
      } B;
    } C;

    union {
      vuint32_t R;
      struct {
        vuint32_t OVR:1;
        vuint32_t unused_1:15;
        vuint32_t OVFL:1;
        vuint32_t unused_0:12;
        vuint32_t UCIN:1;
        vuint32_t UCOUT:1;
        vuint32_t FLAG:1;
      } B;
    } S;

    union {
      vuint32_t R;
      struct {
        vuint32_t unused_0:16;
        vuint32_t ALTA:16;
      } B;
    } ALTA;

    vuint8_t EMIOS_reserved1[8];

  } CH[32];
};
/*lint +e46 */

#if (SPC5_HAS_EMIOS0 == TRUE) || defined(__DOXYGEN__)
#define SPC5_EMIOS_0        (*(volatile struct spc5_emios *)SPC5_EMIOS0_BASE)
#endif

#if (SPC5_HAS_EMIOS1 == TRUE) || defined(__DOXYGEN__)
#define SPC5_EMIOS_1        (*(volatile struct spc5_emios *)SPC5_EMIOS1_BASE)
#endif

#if (SPC5_HAS_EMIOS2 == TRUE) || defined(__DOXYGEN__)
#define SPC5_EMIOS_2        (*(volatile struct spc5_emios *)SPC5_EMIOS2_BASE)
#endif

#endif

/**
 * @brief   Type of a structure representing the BCTU data.
 */
typedef struct BCTUDriver BCTUDriver;

/**
 * @brief   BCTU trigger source type.
 */
typedef enum {
  SPC5_BCTU_TRIGGER_SRC_EMIOS0 = 0,
  SPC5_BCTU_TRIGGER_SRC_EMIOS1 = 1,
  SPC5_BCTU_TRIGGER_SRC_EMIOS2 = 2,
  SPC5_BCTU_TRIGGER_SRC_PIT0 = 3,
  SPC5_BCTU_TRIGGER_SRC_PIT1 = 4
} bctutrgsrc_t;

/**
 * @brief   BCTU channel type.
 */
typedef uint8_t  bctuch_t;

/**
 * @brief   BCTU trigger configuration structure.
 */
typedef struct {
  /**
   * @brief BCTU trigger source (EMIOS0/1/2, PIT0/PIT1)
   */
  bctutrgsrc_t              source;
  /**
   * @brief BCTU channel number
   */
  bctuch_t                  channel;
} BCTUTriggerConfig;

/**
 * @brief   Driver configuration structure.
 */
typedef struct {
  /**
   * @brief   BCTU trigger configurations.
   */
  BCTUTriggerConfig   *trigger[SPC5_BCTU_TRIGGER_NUMBER];
} BCTUConfig;

/**
 * @brief   Structure representing an BTCU driver.
 */
struct BCTUDriver {
  /**
   * @brief   Current configuration data.
   */
  BCTUConfig				*config;
  /**
   * @brief   Pointer to the BCTU registers block.
   */
  volatile struct spc5_bctu *bctup;
#if (SPC5_BCTU_USE_EMIOS0_TRIGGER == TRUE)
  /**
   * @brief Pointer to the eMIOS0 registers block.
   */
  volatile struct spc5_emios *emiosp0;
#endif
#if (SPC5_BCTU_USE_EMIOS1_TRIGGER == TRUE)
  /**
   * @brief Pointer to the eMIOS1 registers block.
   */
  volatile struct spc5_emios *emiosp1;
#endif
#if (SPC5_BCTU_USE_EMIOS2_TRIGGER == TRUE)
  /**
   * @brief Pointer to the eMIOS2 registers block.
   */
  volatile struct spc5_emios *emiosp2;
#endif
  /**
   * @brief Pointer to the SARADC SV registers block.
   */
  volatile struct spc5_saradc *saradcp;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* IRQ Handlers                                                              */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(__DOXYGEN__)
extern BCTUDriver BCTUD1;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void bctu_lld_init(void);
  void bctu_lld_start(BCTUDriver *bctudp, BCTUConfig *config);
  uint8_t bctu_lld_get_trigger_int_flag(BCTUDriver *bctudp);
  void bctu_clear_trigger_int_flag(BCTUDriver *bctudp);
  void bctu_lld_stop(BCTUDriver *bctudp);
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_BCTU */

#endif /* _BCTU_LLD_H_ */

/** @} */

/****************************************************************************
*
* Copyright (c) 2015-2020 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/**
 * @file    osal.c
 * @brief   OSAL module code.
 *
 * @addtogroup OSAL
 * @{
 */

#include <string.h>

#include "osal.h"

#if (OSAL_FREERTOS_ENABLE == TRUE)
#include "FreeRTOS.h"
#include "task.h"
#endif /* (OSAL_FREERTOS_ENABLE == FALSE) */

/*===========================================================================*/
/* Module local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Module exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Module local types.                                                       */
/*===========================================================================*/

typedef void (*delayTicks_t)(osalsystime_t delay);
typedef uint32_t (*getTicks_t)(void);
typedef void (*enterCritical_t)(void);
typedef void (*exitCritical_t)(void);

typedef struct osalTime_s {
  delayTicks_t    delayTicks;
  getTicks_t      getTicks;
  enterCritical_t enterCritical;
  exitCritical_t  exitCritical;
} osalTime_t;


/*===========================================================================*/
/* Module local variables.                                                   */
/*===========================================================================*/

/* Max three cores */
static osalTime_t osalTimeOps[3U];

#if (OSAL_SYSTIMER_ENABLE == TRUE)
/**
 * @brief   System time number of ticks per second.
 */
static uint32_t osal_ticks_per_sec = 0;


/**
 * @brief   System time.
 */
static volatile osalsystime_t osalsystime;

#endif /* OSAL_SYSTIMER_ENABLE */

#if (OSAL_OS_ENABLE == FALSE) || (OSAL_CORE_CONFIG == OSAL_MULTI_CORE)
/**
 * @brief   Interrupt enable/disable count.
 */
static uint32_t osalIsrCnt = 0;

/**
 * @brief   Interrupt enable/disable status.
 */
static uint32_t osalIsExtIntEnable = 0;

#endif /* OSAL_OS_ENABLE == FALSE */

/*===========================================================================*/
/* Module local functions.                                                   */
/*===========================================================================*/

#if (OSAL_SYSTIMER_ENABLE == TRUE)
/**
 * @brief   Configures and enables the System Timer.
 *
 * @param[in] ticks_per_sec      number of ticks per second
 *
 * @notapi
 */

volatile uint32_t *osalSysTimeSetup(uint32_t ticks_per_sec)
{

  osal_ticks_per_sec = ticks_per_sec;

  sysTimeSetup(ticks_per_sec);

  return &osalsystime;
}

/**
 * @brief   Reset the System Timer.
 *
 * @notapi
 */
void osalSysTimeReset(void)
{
  /* Resets the PIT channel 0 IRQ flag.*/
  sysTimeReset();
}

/**
 * @brief   Seconds to system ticks.
 * @details Converts from seconds to system ticks number.
 * @note    The result is rounded upward to the next tick boundary.
 *
 * @param[in] sec       number of seconds
 * @return              The number of ticks.
 *
 * @noapi
 */
static inline osalsystime_t osalSysTime_S2ST(uint32_t sec) {
  return ((osalsystime_t)((sec) * (osal_ticks_per_sec)));
}

/**
 * @brief   Milliseconds to system ticks.
 * @details Converts from milliseconds to system ticks number.
 * @note    The result is rounded upward to the next tick boundary.
 *
 * @param[in] msec      number of milliseconds
 * @return              The number of ticks.
 *
 * @noapi
 */
static inline osalsystime_t osalSysTime_MS2ST(uint32_t msec) {
  return ((msec == 0U) ? ((osalsystime_t) 0) :
                         ((osalsystime_t)((((msec) * (osal_ticks_per_sec) - 1UL) / 1000UL) + 1UL)));
}

/**
 * @brief   Microseconds to system ticks.
 * @details Converts from microseconds to system ticks number.
 * @note    The result is rounded upward to the next tick boundary.
 *
 * @param[in] usec      number of microseconds
 * @return              The number of ticks.
 *
 * @noapi
 */
static inline osalsystime_t osalSysTime_US2ST(uint32_t usec) {
  return ((usec == 0U) ? ((osalsystime_t) 0) :
                         ((osalsystime_t)((((usec) * (osal_ticks_per_sec) - 1UL) / 1000000UL) + 1UL)));
}

/**
 * @brief   System ticks to seconds.
 * @details Converts from system ticks number to seconds.
 * @note    The result is rounded downward.
 *
 * @param[in] ticks     number of ticks
 * @return              The number of seconds.
 *
 * @noapi
 */
static inline uint32_t osalSysTime_ST2S(osalsystime_t ticks) {
  return ((uint32_t)(((osalsystime_t)ticks) / osal_ticks_per_sec));
}

/**
 * @brief   System ticks to milliseconds.
 * @details Converts from system ticks number to milliseconds.
 * @note    The result is rounded downward.
 *
 * @param[in] ticks     number of ticks
 * @return              The number of milliseconds.
 *
 * @noapi
 */
static inline uint32_t osalSysTime_ST2MS(osalsystime_t ticks) {
  return ((uint32_t)((((osalsystime_t)ticks) * 1000UL) / osal_ticks_per_sec));
}

/**
 * @brief   System ticks to microseconds.
 * @details Converts from system ticks number to microseconds.
 * @note    The result is rounded downward.
 *
 * @param[in] ticks     number of ticks
 * @return              The number of microseconds.
 *
 * @noapi
 */
static inline uint32_t osalSysTime_ST2US(osalsystime_t ticks) {
  return ((uint32_t)((((osalsystime_t)ticks) * 1000000UL) / osal_ticks_per_sec));
}

#if (OSAL_OS_ENABLE == FALSE)  || (OSAL_CORE_CONFIG == OSAL_MULTI_CORE)
/**
 * @brief   System Time Initialization.
 *
 * @notapi
 */
static void osalSysTimeInit(void) {

  /* System time initialization.*/
  osalsystime = 0;

  (void)osalSysTimeSetup((uint32_t)OSAL_SYSTIMER_TICK_FREQ_HZ);
}

/**
 * @brief   Delays for the specified number of ticks.
 *
 * @param[in] ticks     number of ticks
 *
 * @notapi
 */
static void osalSysTimeDelayTicks(osalsystime_t ticks) {

  osalsystime_t current;
  
  current = osalsystime;
  while (osalsystime < current + ticks) {
  }

}

/**
 * @brief   Returns the current number of ticks.
 *
 * @return              The number of ticks.
 *
 * @notapi
 */
static uint32_t osalSysTimeGetTicks(void) {

  return osalsystime;
}
#endif /* OSAL_OS_ENABLE == FALSE */
#endif /* OSAL_SYSTIMER_ENABLE */


#if (OSAL_OS_ENABLE == FALSE) || (OSAL_CORE_CONFIG == OSAL_MULTI_CORE)
/**
 * @brief   If enabled, disables the interrupts.
 *
 * @notapi
 */
static void osalIsrDisable(void) {

  osalIsrCnt++;
  if (osalIsrCnt == 1U) {
    osalIsExtIntEnable = irqGetExtIntEnable();
    if (osalIsExtIntEnable != 0U) {
      irqIsrDisable();
    }
  }
}

/**
 * @brief   If previously enabled, re-enables the interrupts.
 *
 * @notapi
 */
static void osalIsrEnable(void) {

  osalIsrCnt--;
  if ((osalIsExtIntEnable != 0U) && (osalIsrCnt == 0U)) {
    irqIsrEnable();
  }
}
#endif /* OSAL_OS_ENABLE == FALSE */

/*===========================================================================*/
/* Module interrupt handlers.                                                */
/*===========================================================================*/

#if (OSAL_SYSTIMER_ENABLE == TRUE)
#if (OSAL_OS_ENABLE == FALSE)
/**
 * @brief   PIT channel 0 interrupt handler.
 *
 * @isr
 */
IRQ_HANDLER(OSAL_SYSTIMER_IRQ_HANDLER) {

  IRQ_PROLOGUE();

  osalEnterCriticalFromISR();
  
  osalsystime++;
  
  osalExitCriticalFromISR();

  osalSysTimeReset();

  IRQ_EPILOGUE();
}
#endif /* OSAL_OS_ENABLE == FALSE */
#endif /* OSAL_SYSTIMER_ENABLE */

/*===========================================================================*/
/* Module exported functions.                                                */
/*===========================================================================*/

#if (OSAL_SYSTIMER_ENABLE == TRUE)
/**
 * @brief   Delays for the specified number of seconds.
 * @note    The specified time is rounded up to a value allowed by the real
 *          system tick clock.
 * @note    The maximum specifiable value is implementation dependent.
 *
 * @param[in] sec       time in seconds, must be different from zero
 *
 * @api
 */
void osalThreadDelaySeconds(uint32_t sec) {
  osalTimeOps[osal_getpir()].delayTicks(osalSysTime_S2ST(sec));
}

/**
 * @brief   Delays for the specified number of milliseconds.
 * @note    The specified time is rounded up to a value allowed by the real
 *          system tick clock.
 * @note    The maximum specifiable value is implementation dependent.
 *
 * @param[in] msec      time in milliseconds, must be different from zero
 *
 * @api
 */
void osalThreadDelayMilliseconds(uint32_t msec) {
  osalTimeOps[osal_getpir()].delayTicks(osalSysTime_MS2ST(msec));
}

/**
 * @brief   Delays for the specified number of microseconds.
 * @note    The specified time is rounded up to a value allowed by the real
 *          system tick clock.
 * @note    The maximum specifiable value is implementation dependent.
 *
 * @param[in] usec      time in microseconds, must be different from zero
 *
 * @api
 */
void osalThreadDelayMicroseconds(uint32_t usec) {
  osalTimeOps[osal_getpir()].delayTicks(osalSysTime_US2ST(usec));
}

/**
 * @brief   Returns the number of seconds since System Timer init.
 *
 * @return              number of seconds.
 *
 * @api
 */
uint32_t osalThreadGetSeconds(void) {
  return osalSysTime_ST2S(osalTimeOps[osal_getpir()].getTicks());
}

/**
 * @brief   Returns the number of milliseconds since System Timer init.
 *
 * @return              number of milliseconds.
 *
 * @api
 */
uint32_t osalThreadGetMilliseconds(void) {
  return osalSysTime_ST2MS(osalTimeOps[osal_getpir()].getTicks());
}

/**
 * @brief   Returns the number of microseconds since System Timer init.
 *
 * @return              number of microseconds.
 *
 * @api
 */
uint32_t osalThreadGetMicroseconds(void) {
  return osalSysTime_ST2US(osalTimeOps[osal_getpir()].getTicks());
}
#endif /* OSAL_SYSTIMER_ENABLE */

/**
 * @brief   Enters a critical zone.
 *
 * @api
 */
void osalEnterCritical(void) {
  osalTimeOps[osal_getpir()].enterCritical();
}

/**
 * @brief   Leaves a critical zone.
 *
 * @api
 */
void osalExitCritical(void) {
  osalTimeOps[osal_getpir()].exitCritical();
}

/**
 * @brief   Enters a critical zone from ISR.
 *
 * @api
 */
void osalEnterCriticalFromISR(void) {

#if (OSAL_ENABLE_IRQ_PREEMPTION == TRUE)
  osalTimeOps[osal_getpir()].enterCritical();
#endif
}

/**
 * @brief   Leaves a critical zone from ISR.
 *
 * @api
 */
void osalExitCriticalFromISR(void) {

#if (OSAL_ENABLE_IRQ_PREEMPTION == TRUE)
  osalTimeOps[osal_getpir()].exitCritical();
#endif
}


/**
 * @brief   OSAL module initialization (automatically called at init time).
 *
 * @api
 */
void osalInit(void) {

  /* This function is always executed on CORE_2 */

#if CORE_SUPPORTS_IVORS
  extern void _spr_init(void);
  _spr_init();
#endif

  /* Set to NULL */
  memset(osalTimeOps, 0, sizeof(osalTimeOps));

#if (MAIN_CORE == 0)
#ifndef BOOT_CORE0
#define BOOT_CORE0   1
#endif
#ifndef BOOT_CORE1
#define BOOT_CORE1   0
#endif
#ifndef BOOT_CORE2
#define BOOT_CORE2   0
#endif
#elif (MAIN_CORE == 1)
#ifndef BOOT_CORE0
#define BOOT_CORE0   0
#endif
#ifndef BOOT_CORE1
#define BOOT_CORE1   1
#endif
#ifndef BOOT_CORE2
#define BOOT_CORE2   0
#endif
#elif (MAIN_CORE == 2)
#ifndef BOOT_CORE0
#define BOOT_CORE0   0
#endif
#ifndef BOOT_CORE1
#define BOOT_CORE1   0
#endif
#ifndef BOOT_CORE2
#define BOOT_CORE2   1
#endif
#else
#error "Wrong MAIN_CORE definition."
#endif

#if (OSAL_OS_ENABLE == TRUE)
  #if (BOOT_CORE0 == 1)
    #if (configUSE_CORE_0 == 1)
#if (OSAL_SYSTIMER_ENABLE == TRUE)
      osalTimeOps[0U].delayTicks = vTaskDelay;
      osalTimeOps[0U].getTicks = xTaskGetTickCount;
#endif /* OSAL_SYSTIMER_ENABLE */
      osalTimeOps[0U].enterCritical = vTaskEnterCritical;
      osalTimeOps[0U].exitCritical = vTaskExitCritical;
    #else
#if (OSAL_SYSTIMER_ENABLE == TRUE)
      osalTimeOps[0U].delayTicks = osalSysTimeDelayTicks;
      osalTimeOps[0U].getTicks = osalSysTimeGetTicks;
#endif /* OSAL_SYSTIMER_ENABLE */
      osalTimeOps[0U].enterCritical = osalIsrDisable;
      osalTimeOps[0U].exitCritical = osalIsrEnable;
    #endif
  #endif

  #if (BOOT_CORE1 == 1)
    #if (configUSE_CORE_1 == 1)
#if (OSAL_SYSTIMER_ENABLE == TRUE)
      osalTimeOps[1U].delayTicks = vTaskDelay;
      osalTimeOps[1U].getTicks = xTaskGetTickCount;
#endif /* OSAL_SYSTIMER_ENABLE */
      osalTimeOps[1U].enterCritical = vTaskEnterCritical;
      osalTimeOps[1U].exitCritical = vTaskExitCritical;
    #else
#if (OSAL_SYSTIMER_ENABLE == TRUE)
      osalTimeOps[1U].delayTicks = osalSysTimeDelayTicks;
      osalTimeOps[1U].getTicks = osalSysTimeGetTicks;
#endif /* OSAL_SYSTIMER_ENABLE */
      osalTimeOps[1U].enterCritical = osalIsrDisable;
      osalTimeOps[1U].exitCritical = osalIsrEnable;
    #endif
  #endif

  #if (BOOT_CORE2 == 1)
    #if (configUSE_CORE_2 == 1)
#if (OSAL_SYSTIMER_ENABLE == TRUE)
      osalTimeOps[2U].delayTicks = vTaskDelay;
      osalTimeOps[2U].getTicks = xTaskGetTickCount;
#endif /* OSAL_SYSTIMER_ENABLE */
      osalTimeOps[2U].enterCritical = vTaskEnterCritical;
      osalTimeOps[2U].exitCritical = vTaskExitCritical;
    #else
#if (OSAL_SYSTIMER_ENABLE == TRUE)
      osalTimeOps[2U].delayTicks = osalSysTimeDelayTicks;
      osalTimeOps[2U].getTicks = osalSysTimeGetTicks;
#endif /* OSAL_SYSTIMER_ENABLE */
      osalTimeOps[2U].enterCritical = osalIsrDisable;
      osalTimeOps[2U].exitCritical = osalIsrEnable;
    #endif
  #endif

  #if (OSAL_CORE_CONFIG == OSAL_MULTI_CORE)
    #if (OSAL_SYSTIMER_ENABLE == TRUE)
      osalSysTimeInit();
    #endif
  #endif
#endif

#if (OSAL_OS_ENABLE == FALSE)
  #if (BOOT_CORE0 == 1)
#if (OSAL_SYSTIMER_ENABLE == TRUE)
    osalTimeOps[0U].delayTicks = osalSysTimeDelayTicks;
    osalTimeOps[0U].getTicks = osalSysTimeGetTicks;
#endif /* OSAL_SYSTIMER_ENABLE */
    osalTimeOps[0U].enterCritical = osalIsrDisable;
    osalTimeOps[0U].exitCritical = osalIsrEnable;
  #endif

  #if (BOOT_CORE1 == 1)
#if (OSAL_SYSTIMER_ENABLE == TRUE)
    osalTimeOps[1U].delayTicks = osalSysTimeDelayTicks;
    osalTimeOps[1U].getTicks = osalSysTimeGetTicks;
#endif /* OSAL_SYSTIMER_ENABLE */
    osalTimeOps[1U].enterCritical = osalIsrDisable;
    osalTimeOps[1U].exitCritical = osalIsrEnable;
  #endif

  #if (BOOT_CORE2 == 1)
#if (OSAL_SYSTIMER_ENABLE == TRUE)
    osalTimeOps[2U].delayTicks = osalSysTimeDelayTicks;
    osalTimeOps[2U].getTicks = osalSysTimeGetTicks;
#endif /* OSAL_SYSTIMER_ENABLE */
    osalTimeOps[2U].enterCritical = osalIsrDisable;
    osalTimeOps[2U].exitCritical = osalIsrEnable;
  #endif

  #if (OSAL_SYSTIMER_ENABLE == TRUE)
    osalSysTimeInit();
  #endif
#endif
}

/** @} */

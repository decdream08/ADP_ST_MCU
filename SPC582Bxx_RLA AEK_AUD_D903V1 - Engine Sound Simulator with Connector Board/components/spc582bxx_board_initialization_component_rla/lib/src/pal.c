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
 * @file    pal.c
 * @brief   SPC5xx SIUL2 low level driver code.
 *
 * @addtogroup PAL
 * @{
 */

#include "pal.h"

/**
 * @brief   SPC5xx I/O ports configuration.
 *
 * @param[in] config    the SPC5xx ports configuration
 *
 * @notapi
 */
void pal_init(PALConfig *config) {
  // art #804106 Coredump issue on freegcc
  volatile uint16_t i;

#if defined(SPC5_SIUL2_PCTL)
  /* SIUL clock gating if present.*/
  SPCSetPeripheralClockMode(SPC5_SIUL2_PCTL,
                            SPC5_ME_PCTL_RUN(2) | SPC5_ME_PCTL_LP(2));
#endif

  /* Initialize MSCR_IO registers for defined pins.*/
  i = 0;
  while (config->mscr_io[i].index != -1) {
    SIUL2.GPDO[config->mscr_io[i].index].R = config->mscr_io[i].gpdo;
    SIUL2.MSCR_IO[config->mscr_io[i].index].R = config->mscr_io[i].value;
    i++;
  }

  /* Initialize MSCR_MUX registers for defined pins.*/
  i = 0;
  while (config->mscr_mux[i].index != -1) {
    SIUL2.MSCR_MUX[config->mscr_mux[i].index].R = config->mscr_mux[i].value;
    i++;
  }
}

/**
 * @brief   Reads a group of bits.
 *
 * @param[in] port      port identifier
 * @param[in] mask      group mask
 * @param[in] offset    group bit offset within the port
 * @return              The group logical states.
 *
 * @notapi
 */
ioportmask_t _pal_readgroup(ioportid_t port, ioportmask_t mask,
                            uint_fast8_t offset) {

  (void)port;
  (void)mask;
  (void)offset;
  return 0;
}

/**
 * @brief   Writes a group of bits.
 *
 * @param[in] port      port identifier
 * @param[in] mask      group mask
 * @param[in] offset    group bit offset within the port
 * @param[in] bits      bits to be written. Values exceeding the group width
 *                      are masked.
 *
 * @notapi
 */
void _pal_writegroup(ioportid_t port, ioportmask_t mask, uint_fast8_t offset,
                     ioportmask_t bits) {

  (void)port;
  (void)mask;
  (void)offset;
  (void)bits;
}

/**
 * @brief   Pads mode setup.
 * @details This function programs a pads group belonging to the same port
 *          with the specified mode.
 *
 * @param[in] port      the port identifier
 * @param[in] mask      the group mask. A '0' in the position i means that the
 *                      mode of pad i will be not changed, a '1' means that the
 *                      mode of pad i will be updated.
 * @param[in] mode      the mode
 *
 * @notapi
 */
void _pal_setgroupmode(ioportid_t port, ioportmask_t mask, iomode_t mode) {
  uint32_t pcr_index = (uint32_t)(port * PAL_IOPORTS_WIDTH);
  ioportmask_t m1 = 0x8000U;
  while (m1 != 0U) {
    if ((mask & m1) != 0U) {
      SIUL2.MSCR_IO[pcr_index].R = mode;
    }
    m1 >>= 1;
    ++pcr_index;
  }
}

/** @} */

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
 * @file    spc5_bctu.h
 * @brief   BCTU helper driver header.
 *
 * @addtogroup BCTU
 * @{
 */

#ifndef _SPC5_BCTU_H_
#define _SPC5_BCTU_H_

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/* PPC register definitions not compatible with MISRA rules on bit-fields 
 (Rules 6.1). */
/*lint -e46 */
struct spc5_bctu {

  union {
    vuint32_t R;
    struct {
      vuint32_t unused_1:24;
      vuint32_t TRGIEN:1;
      vuint32_t TRGI:1;
      vuint32_t unused_0:6;
    } B;
  } CSR;

  vuint8_t ADR_reserved0[44];

  union {
    vuint32_t R;
    struct {
      vuint32_t unused_1:16;
      vuint32_t TM:1;
      vuint32_t CLR_FLAG:1;
      vuint32_t unused_0:6;
      vuint32_t CHANNEL_VALUE:8;
    } B;
  } EVTCFGR[96];

};
/*lint +e46 */

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/**
 * @name    BCTU unit reference
 * @{
 */
#define SPC5_BCTU       (*(struct spc5_bctu *)SPC5_BCTU_BASE)

/** @} */

#endif /* _SPC5_BCTU_H_ */

/** @} */

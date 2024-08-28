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
 * @file    spc5_wkpu.h
 * @brief   WKPU helper driver header.
 *
 * @addtogroup WKPU
 * @{
 */

#ifndef _SPC5_WKPU_H_
#define _SPC5_WKPU_H_

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
struct spc5_wkpu {

  union {
    vuint32_t R;
    struct {
      vuint32_t NIF0:1;
      vuint32_t NOVF0:1;
      vuint32_t unused_3:6;
      vuint32_t NIF1:1;
      vuint32_t NOVF1:1;
      vuint32_t unused_2:6;
      vuint32_t NIF2:1;
      vuint32_t NOVF2:1;
      vuint32_t unused_1:6;
      vuint32_t RIF:1;
      vuint32_t ROVF:1;
      vuint32_t unused_0:6;
    } B;
  } NSR;

  vuint8_t ADR_reserved0[4];

  union {
    vuint32_t R;
    struct {
      vuint32_t NLOCK0:1;
      vuint32_t NDSS0:2;
      vuint32_t NWRE0:1;
      vuint32_t unused_3:1;
      vuint32_t NREE0:1;
      vuint32_t NFEE0:1;
      vuint32_t NFE0:1;
      vuint32_t NLOCK1:1;
      vuint32_t NDSS1:2;
      vuint32_t NWRE1:1;
      vuint32_t unused_2:1;
      vuint32_t NREE1:1;
      vuint32_t NFEE1:1;
      vuint32_t NFE1:1;
      vuint32_t NLOCK2:1;
      vuint32_t NDSS2:2;
      vuint32_t NWRE2:1;
      vuint32_t unused_1:1;
      vuint32_t NREE2:1;
      vuint32_t NFEE2:1;
      vuint32_t NFE2:1;
      vuint32_t RLOCK:1;
      vuint32_t RDSS:2;
      vuint32_t RWRE:1;
      vuint32_t unused_0:1;
      vuint32_t RREE:1;
      vuint32_t RFEE:1;
      vuint32_t RFE:1;
    } B;
  } NCR;

  vuint8_t ADR_reserved1[8];

  union {
    vuint32_t R;
    struct {
      vuint32_t EIF31:1;
      vuint32_t EIF30:1;
      vuint32_t EIF29:1;
      vuint32_t EIF28:1;
      vuint32_t EIF27:1;
      vuint32_t EIF26:1;
      vuint32_t EIF25:1;
      vuint32_t EIF24:1;
      vuint32_t EIF23:1;
      vuint32_t EIF22:1;
      vuint32_t EIF21:1;
      vuint32_t EIF20:1;
      vuint32_t EIF19:1;
      vuint32_t EIF18:1;
      vuint32_t EIF17:1;
      vuint32_t EIF16:1;
      vuint32_t EIF15:1;
      vuint32_t EIF14:1;
      vuint32_t EIF13:1;
      vuint32_t EIF12:1;
      vuint32_t EIF11:1;
      vuint32_t EIF10:1;
      vuint32_t EIF9:1;
      vuint32_t EIF8:1;
      vuint32_t EIF7:1;
      vuint32_t EIF6:1;
      vuint32_t EIF5:1;
      vuint32_t EIF4:1;
      vuint32_t EIF3:1;
      vuint32_t EIF2:1;
      vuint32_t EIF1:1;
      vuint32_t EIF0:1;
    } B;
  } WISR;

  union {
    vuint32_t R;
    struct {
      vuint32_t EIRE31:1;
      vuint32_t EIRE30:1;
      vuint32_t EIRE29:1;
      vuint32_t EIRE28:1;
      vuint32_t EIRE27:1;
      vuint32_t EIRE26:1;
      vuint32_t EIRE25:1;
      vuint32_t EIRE24:1;
      vuint32_t EIRE23:1;
      vuint32_t EIRE22:1;
      vuint32_t EIRE21:1;
      vuint32_t EIRE20:1;
      vuint32_t EIRE19:1;
      vuint32_t EIRE18:1;
      vuint32_t EIRE17:1;
      vuint32_t EIRE16:1;
      vuint32_t EIRE15:1;
      vuint32_t EIRE14:1;
      vuint32_t EIRE13:1;
      vuint32_t EIRE12:1;
      vuint32_t EIRE11:1;
      vuint32_t EIRE10:1;
      vuint32_t EIRE9:1;
      vuint32_t EIRE8:1;
      vuint32_t EIRE7:1;
      vuint32_t EIRE6:1;
      vuint32_t EIRE5:1;
      vuint32_t EIRE4:1;
      vuint32_t EIRE3:1;
      vuint32_t EIRE2:1;
      vuint32_t EIRE1:1;
      vuint32_t EIRE0:1;
    } B;
  } IRER;

  union {
    vuint32_t R;
    struct {
      vuint32_t WRE31:1;
      vuint32_t WRE30:1;
      vuint32_t WRE29:1;
      vuint32_t WRE28:1;
      vuint32_t WRE27:1;
      vuint32_t WRE26:1;
      vuint32_t WRE25:1;
      vuint32_t WRE24:1;
      vuint32_t WRE23:1;
      vuint32_t WRE22:1;
      vuint32_t WRE21:1;
      vuint32_t WRE20:1;
      vuint32_t WRE19:1;
      vuint32_t WRE18:1;
      vuint32_t WRE17:1;
      vuint32_t WRE16:1;
      vuint32_t WRE15:1;
      vuint32_t WRE14:1;
      vuint32_t WRE13:1;
      vuint32_t WRE12:1;
      vuint32_t WRE11:1;
      vuint32_t WRE10:1;
      vuint32_t WRE9:1;
      vuint32_t WRE8:1;
      vuint32_t WRE7:1;
      vuint32_t WRE6:1;
      vuint32_t WRE5:1;
      vuint32_t WRE4:1;
      vuint32_t WRE3:1;
      vuint32_t WRE2:1;
      vuint32_t WRE1:1;
      vuint32_t WRE0:1;
    } B;
  } WRER;

  vuint8_t ADR_reserved2[8];

  union {
    vuint32_t R;
    struct {
      vuint32_t IREE31:1;
      vuint32_t IREE30:1;
      vuint32_t IREE29:1;
      vuint32_t IREE28:1;
      vuint32_t IREE27:1;
      vuint32_t IREE26:1;
      vuint32_t IREE25:1;
      vuint32_t IREE24:1;
      vuint32_t IREE23:1;
      vuint32_t IREE22:1;
      vuint32_t IREE21:1;
      vuint32_t IREE20:1;
      vuint32_t IREE19:1;
      vuint32_t IREE18:1;
      vuint32_t IREE17:1;
      vuint32_t IREE16:1;
      vuint32_t IREE15:1;
      vuint32_t IREE14:1;
      vuint32_t IREE13:1;
      vuint32_t IREE12:1;
      vuint32_t IREE11:1;
      vuint32_t IREE10:1;
      vuint32_t IREE9:1;
      vuint32_t IREE8:1;
      vuint32_t IREE7:1;
      vuint32_t IREE6:1;
      vuint32_t IREE5:1;
      vuint32_t IREE4:1;
      vuint32_t IREE3:1;
      vuint32_t IREE2:1;
      vuint32_t IREE1:1;
      vuint32_t IREE0:1;
    } B;
  } WIREER;

  union {
    vuint32_t R;
    struct {
      vuint32_t IFEE31:1;
      vuint32_t IFEE30:1;
      vuint32_t IFEE29:1;
      vuint32_t IFEE28:1;
      vuint32_t IFEE27:1;
      vuint32_t IFEE26:1;
      vuint32_t IFEE25:1;
      vuint32_t IFEE24:1;
      vuint32_t IFEE23:1;
      vuint32_t IFEE22:1;
      vuint32_t IFEE21:1;
      vuint32_t IFEE20:1;
      vuint32_t IFEE19:1;
      vuint32_t IFEE18:1;
      vuint32_t IFEE17:1;
      vuint32_t IFEE16:1;
      vuint32_t IFEE15:1;
      vuint32_t IFEE14:1;
      vuint32_t IFEE13:1;
      vuint32_t IFEE12:1;
      vuint32_t IFEE11:1;
      vuint32_t IFEE10:1;
      vuint32_t IFEE9:1;
      vuint32_t IFEE8:1;
      vuint32_t IFEE7:1;
      vuint32_t IFEE6:1;
      vuint32_t IFEE5:1;
      vuint32_t IFEE4:1;
      vuint32_t IFEE3:1;
      vuint32_t IFEE2:1;
      vuint32_t IFEE1:1;
      vuint32_t IFEE0:1;
    } B;
  } WIFEER;

  union {
    vuint32_t R;
    struct {
      vuint32_t IFE31:1;
      vuint32_t IFE30:1;
      vuint32_t IFE29:1;
      vuint32_t IFE28:1;
      vuint32_t IFE27:1;
      vuint32_t IFE26:1;
      vuint32_t IFE25:1;
      vuint32_t IFE24:1;
      vuint32_t IFE23:1;
      vuint32_t IFE22:1;
      vuint32_t IFE21:1;
      vuint32_t IFE20:1;
      vuint32_t IFE19:1;
      vuint32_t IFE18:1;
      vuint32_t IFE17:1;
      vuint32_t IFE16:1;
      vuint32_t IFE15:1;
      vuint32_t IFE14:1;
      vuint32_t IFE13:1;
      vuint32_t IFE12:1;
      vuint32_t IFE11:1;
      vuint32_t IFE10:1;
      vuint32_t IFE9:1;
      vuint32_t IFE8:1;
      vuint32_t IFE7:1;
      vuint32_t IFE6:1;
      vuint32_t IFE5:1;
      vuint32_t IFE4:1;
      vuint32_t IFE3:1;
      vuint32_t IFE2:1;
      vuint32_t IFE1:1;
      vuint32_t IFE0:1;
    } B;
  } WIFER;

  union {
    vuint32_t R;
    struct {
      vuint32_t IPUE31:1;
      vuint32_t IPUE30:1;
      vuint32_t IPUE29:1;
      vuint32_t IPUE28:1;
      vuint32_t IPUE27:1;
      vuint32_t IPUE26:1;
      vuint32_t IPUE25:1;
      vuint32_t IPUE24:1;
      vuint32_t IPUE23:1;
      vuint32_t IPUE22:1;
      vuint32_t IPUE21:1;
      vuint32_t IPUE20:1;
      vuint32_t IPUE19:1;
      vuint32_t IPUE18:1;
      vuint32_t IPUE17:1;
      vuint32_t IPUE16:1;
      vuint32_t IPUE15:1;
      vuint32_t IPUE14:1;
      vuint32_t IPUE13:1;
      vuint32_t IPUE12:1;
      vuint32_t IPUE11:1;
      vuint32_t IPUE10:1;
      vuint32_t IPUE9:1;
      vuint32_t IPUE8:1;
      vuint32_t IPUE7:1;
      vuint32_t IPUE6:1;
      vuint32_t IPUE5:1;
      vuint32_t IPUE4:1;
      vuint32_t IPUE3:1;
      vuint32_t IPUE2:1;
      vuint32_t IPUE1:1;
      vuint32_t IPUE0:1;
    } B;
  } WIPUER;
};
/*lint +e46 */

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/**
 * @name    Wakeup unit references
 * @{
 */
#if (SPC5_HAS_WKPU0 == TRUE) || defined(__DOXYGEN__)
#define SPC5_WKPU0      (*(struct spc5_wkpu *)SPC5_WKPU0_BASE)
#endif
#if (SPC5_HAS_WKPU1 == TRUE) || defined(__DOXYGEN__)
#define SPC5_WKPU1      (*(struct spc5_wkpu *)SPC5_WKPU1_BASE)
#endif
/** @} */

#endif /* _SPC5_WKPU_H_ */

/** @} */

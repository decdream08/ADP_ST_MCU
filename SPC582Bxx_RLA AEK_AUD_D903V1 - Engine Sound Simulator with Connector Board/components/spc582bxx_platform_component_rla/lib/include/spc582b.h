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

#ifndef _SPC582B_H_
#define _SPC582B_H_

#include <typedefs.h>

/**************************************************************************/
/*                 Module: BODY_CTU            */
/**************************************************************************/
struct BODY_CTU_tag {
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
            vuint32_t unused_0:7;
            vuint32_t CHANNEL_VALUE:7;
        } B;
    } EVTCFGR[64];

};

/**************************************************************************/
/*                 Module: M_CAN            */
/**************************************************************************/
struct M_CAN_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t REL:4;
            vuint32_t STEP:4;
            vuint32_t SUBSTEP:4;
            vuint32_t YEAR:4;
            vuint32_t MON:8;
            vuint32_t DAY:8;
        } B;
    } CREL;

    union {
        vuint32_t R;
        struct {
            vuint32_t ETV:32;
        } B;
    } ENDN;

    vuint8_t ADR_reserved0[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:8;
            vuint32_t TDC:1;
            vuint32_t unused_1:2;
            vuint32_t DBRP:5;
            vuint32_t unused_0:3;
            vuint32_t DTSEG1:5;
            vuint32_t DTSEG2:4;
            vuint32_t DSJW:4;
        } B;
    } DBTP;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:24;
            vuint32_t RX:1;
            vuint32_t TX:2;
            vuint32_t LBCK:1;
            vuint32_t unused_0:4;
        } B;
    } TEST;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t WDV:8;
            vuint32_t WDC:8;
        } B;
    } RWD;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:16;
            vuint32_t NISO:1;
            vuint32_t TXP:1;
            vuint32_t EFBI:1;
            vuint32_t PXHD:1;
            vuint32_t unused_0:2;
            vuint32_t BRSE:1;
            vuint32_t FDOE:1;
            vuint32_t TEST:1;
            vuint32_t DAR:1;
            vuint32_t MON:1;
            vuint32_t CSR:1;
            vuint32_t CSA:1;
            vuint32_t ASM:1;
            vuint32_t CCE:1;
            vuint32_t INIT:1;
        } B;
    } CCCR;

    union {
        vuint32_t R;
        struct {
            vuint32_t NSJW:7;
            vuint32_t NBRP:9;
            vuint32_t NTSEG1:8;
            vuint32_t unused_0:1;
            vuint32_t NTSEG2:7;
        } B;
    } NBTP;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:12;
            vuint32_t TCP:4;
            vuint32_t unused_0:14;
            vuint32_t TSS:2;
        } B;
    } TSCC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t TSC:16;
        } B;
    } TSCV;

    union {
        vuint32_t R;
        struct {
            vuint32_t TOP:16;
            vuint32_t unused_0:13;
            vuint32_t TOS:2;
            vuint32_t ETOC:1;
        } B;
    } TOCC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t TOC:16;
        } B;
    } TOCV;

    vuint8_t ADR_reserved1[16];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:8;
            vuint32_t CEL:8;
            vuint32_t RP:1;
            vuint32_t REC:7;
            vuint32_t TEC:8;
        } B;
    } ECR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:9;
            vuint32_t TDCV:7;
            vuint32_t unused_0:1;
            vuint32_t PXE:1;
            vuint32_t RFDF:1;
            vuint32_t RBRS:1;
            vuint32_t RESI:1;
            vuint32_t DLEC:3;
            vuint32_t BO:1;
            vuint32_t EW:1;
            vuint32_t EP:1;
            vuint32_t ACT:2;
            vuint32_t LEC:3;
        } B;
    } PSR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:17;
            vuint32_t TDCO:7;
            vuint32_t unused_0:1;
            vuint32_t TDCF:7;
        } B;
    } TDCR;

    vuint8_t ADR_reserved2[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:2;
            vuint32_t ARA:1;
            vuint32_t PED:1;
            vuint32_t PEA:1;
            vuint32_t WDI:1;
            vuint32_t BO:1;
            vuint32_t EW:1;
            vuint32_t EP:1;
            vuint32_t ELO:1;
            vuint32_t BEU:1;
            vuint32_t BEC:1;
            vuint32_t DRX:1;
            vuint32_t TOO:1;
            vuint32_t MRAF:1;
            vuint32_t TSW:1;
            vuint32_t TEFL:1;
            vuint32_t TEFF:1;
            vuint32_t TEFW:1;
            vuint32_t TEFN:1;
            vuint32_t TFE:1;
            vuint32_t TCF:1;
            vuint32_t TC:1;
            vuint32_t HPM:1;
            vuint32_t RF1L:1;
            vuint32_t RF1F:1;
            vuint32_t RF1W:1;
            vuint32_t RF1N:1;
            vuint32_t RF0L:1;
            vuint32_t RF0F:1;
            vuint32_t RF0W:1;
            vuint32_t RF0N:1;
        } B;
    } IR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:2;
            vuint32_t ARAE:1;
            vuint32_t PEDE:1;
            vuint32_t PEAE:1;
            vuint32_t WDIE:1;
            vuint32_t BOE:1;
            vuint32_t EWE:1;
            vuint32_t EPE:1;
            vuint32_t ELOE:1;
            vuint32_t BEUE:1;
            vuint32_t BECE:1;
            vuint32_t DRXE:1;
            vuint32_t TOOE:1;
            vuint32_t MRAFE:1;
            vuint32_t TSWE:1;
            vuint32_t TEFLE:1;
            vuint32_t TEFFE:1;
            vuint32_t TEFWE:1;
            vuint32_t TEFNE:1;
            vuint32_t TFEE:1;
            vuint32_t TCFE:1;
            vuint32_t TCE:1;
            vuint32_t HPME:1;
            vuint32_t RF1LE:1;
            vuint32_t RF1FE:1;
            vuint32_t RF1WE:1;
            vuint32_t RF1NE:1;
            vuint32_t RF0LE:1;
            vuint32_t RF0FE:1;
            vuint32_t RF0WE:1;
            vuint32_t RF0NE:1;
        } B;
    } IE;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:2;
            vuint32_t ARAL:1;
            vuint32_t PEDL:1;
            vuint32_t PEAL:1;
            vuint32_t WDIL:1;
            vuint32_t BOL:1;
            vuint32_t EWL:1;
            vuint32_t EPL:1;
            vuint32_t ELOL:1;
            vuint32_t BEUL:1;
            vuint32_t BECL:1;
            vuint32_t DRXL:1;
            vuint32_t TOOL:1;
            vuint32_t MRAFL:1;
            vuint32_t TSWL:1;
            vuint32_t TEFLL:1;
            vuint32_t TEFFL:1;
            vuint32_t TEFWL:1;
            vuint32_t TEFNL:1;
            vuint32_t TFEL:1;
            vuint32_t TCFL:1;
            vuint32_t TCL:1;
            vuint32_t HPML:1;
            vuint32_t RF1LL:1;
            vuint32_t RF1FL:1;
            vuint32_t RF1WL:1;
            vuint32_t RF1NL:1;
            vuint32_t RF0LL:1;
            vuint32_t RF0FL:1;
            vuint32_t RF0WL:1;
            vuint32_t RF0NL:1;
        } B;
    } ILS;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:30;
            vuint32_t EINT1:1;
            vuint32_t EINT0:1;
        } B;
    } ILE;

    vuint8_t ADR_reserved3[32];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:26;
            vuint32_t ANFS:2;
            vuint32_t ANFE:2;
            vuint32_t RRFS:1;
            vuint32_t RRFE:1;
        } B;
    } GFC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:8;
            vuint32_t LSS:8;
            vuint32_t FLSSA:14;
            vuint32_t unused_0:2;
        } B;
    } SIDFC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:9;
            vuint32_t LSE:7;
            vuint32_t FLESA:14;
            vuint32_t unused_0:2;
        } B;
    } XIDFC;

    vuint8_t ADR_reserved4[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:3;
            vuint32_t EIDM:29;
        } B;
    } XIDAM;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t FLST:1;
            vuint32_t FIDX:7;
            vuint32_t MSI:2;
            vuint32_t BIDX:6;
        } B;
    } HPMS;

    union {
        vuint32_t R;
        struct {
            vuint32_t ND31:1;
            vuint32_t ND30:1;
            vuint32_t ND29:1;
            vuint32_t ND28:1;
            vuint32_t ND27:1;
            vuint32_t ND26:1;
            vuint32_t ND25:1;
            vuint32_t ND24:1;
            vuint32_t ND23:1;
            vuint32_t ND22:1;
            vuint32_t ND21:1;
            vuint32_t ND20:1;
            vuint32_t ND19:1;
            vuint32_t ND18:1;
            vuint32_t ND17:1;
            vuint32_t ND16:1;
            vuint32_t ND15:1;
            vuint32_t ND14:1;
            vuint32_t ND13:1;
            vuint32_t ND12:1;
            vuint32_t ND11:1;
            vuint32_t ND10:1;
            vuint32_t ND9:1;
            vuint32_t ND8:1;
            vuint32_t ND7:1;
            vuint32_t ND6:1;
            vuint32_t ND5:1;
            vuint32_t ND4:1;
            vuint32_t ND3:1;
            vuint32_t ND2:1;
            vuint32_t ND1:1;
            vuint32_t ND0:1;
        } B;
    } NDAT1;

    union {
        vuint32_t R;
        struct {
            vuint32_t ND63:1;
            vuint32_t ND62:1;
            vuint32_t ND61:1;
            vuint32_t ND60:1;
            vuint32_t ND59:1;
            vuint32_t ND58:1;
            vuint32_t ND57:1;
            vuint32_t ND56:1;
            vuint32_t ND55:1;
            vuint32_t ND54:1;
            vuint32_t ND53:1;
            vuint32_t ND52:1;
            vuint32_t ND51:1;
            vuint32_t ND50:1;
            vuint32_t ND49:1;
            vuint32_t ND48:1;
            vuint32_t ND47:1;
            vuint32_t ND46:1;
            vuint32_t ND45:1;
            vuint32_t ND44:1;
            vuint32_t ND43:1;
            vuint32_t ND42:1;
            vuint32_t ND41:1;
            vuint32_t ND40:1;
            vuint32_t ND39:1;
            vuint32_t ND38:1;
            vuint32_t ND37:1;
            vuint32_t ND36:1;
            vuint32_t ND35:1;
            vuint32_t ND34:1;
            vuint32_t ND33:1;
            vuint32_t ND32:1;
        } B;
    } NDAT2;

    union {
        vuint32_t R;
        struct {
            vuint32_t F0OM:1;
            vuint32_t F0WM:7;
            vuint32_t unused_1:1;
            vuint32_t F0S:7;
            vuint32_t F0SA:14;
            vuint32_t unused_0:2;
        } B;
    } RXF0C;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:6;
            vuint32_t RF0L:1;
            vuint32_t F0F:1;
            vuint32_t unused_2:2;
            vuint32_t F0PI:6;
            vuint32_t unused_1:2;
            vuint32_t F0GI:6;
            vuint32_t unused_0:1;
            vuint32_t F0FL:7;
        } B;
    } RXF0S;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:26;
            vuint32_t F0AI:6;
        } B;
    } RXF0A;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:16;
            vuint32_t RBSA:14;
            vuint32_t unused_0:2;
        } B;
    } RXBC;

    union {
        vuint32_t R;
        struct {
            vuint32_t F1OM:1;
            vuint32_t F1WM:7;
            vuint32_t unused_1:1;
            vuint32_t F1S:7;
            vuint32_t F1SA:14;
            vuint32_t unused_0:2;
        } B;
    } RXF1C;

    union {
        vuint32_t R;
        struct {
            vuint32_t DMS:2;
            vuint32_t unused_3:4;
            vuint32_t RF1L:1;
            vuint32_t F1F:1;
            vuint32_t unused_2:2;
            vuint32_t F1PI:6;
            vuint32_t unused_1:2;
            vuint32_t F1GI:6;
            vuint32_t unused_0:1;
            vuint32_t F1FL:7;
        } B;
    } RXF1S;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:26;
            vuint32_t F1AI:6;
        } B;
    } RXF1A;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:21;
            vuint32_t RBDS:3;
            vuint32_t unused_1:1;
            vuint32_t F1DS:3;
            vuint32_t unused_0:1;
            vuint32_t F0DS:3;
        } B;
    } RXESC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:1;
            vuint32_t TFQM:1;
            vuint32_t TFQS:6;
            vuint32_t unused_1:2;
            vuint32_t NDTB:6;
            vuint32_t TBSA:14;
            vuint32_t unused_0:2;
        } B;
    } TXBC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:10;
            vuint32_t TFQF:1;
            vuint32_t TFQPI:5;
            vuint32_t unused_1:3;
            vuint32_t TFGI:5;
            vuint32_t unused_0:2;
            vuint32_t TFFL:6;
        } B;
    } TXFQS;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:29;
            vuint32_t TBDS:3;
        } B;
    } TXESC;

    union {
        vuint32_t R;
        struct {
            vuint32_t TRP31:1;
            vuint32_t TRP30:1;
            vuint32_t TRP29:1;
            vuint32_t TRP28:1;
            vuint32_t TRP27:1;
            vuint32_t TRP26:1;
            vuint32_t TRP25:1;
            vuint32_t TRP24:1;
            vuint32_t TRP23:1;
            vuint32_t TRP22:1;
            vuint32_t TRP21:1;
            vuint32_t TRP20:1;
            vuint32_t TRP19:1;
            vuint32_t TRP18:1;
            vuint32_t TRP17:1;
            vuint32_t TRP16:1;
            vuint32_t TRP15:1;
            vuint32_t TRP14:1;
            vuint32_t TRP13:1;
            vuint32_t TRP12:1;
            vuint32_t TRP11:1;
            vuint32_t TRP10:1;
            vuint32_t TRP9:1;
            vuint32_t TRP8:1;
            vuint32_t TRP7:1;
            vuint32_t TRP6:1;
            vuint32_t TRP5:1;
            vuint32_t TRP4:1;
            vuint32_t TRP3:1;
            vuint32_t TRP2:1;
            vuint32_t TRP1:1;
            vuint32_t TRP0:1;
        } B;
    } TXBRP;

    union {
        vuint32_t R;
        struct {
            vuint32_t AR31:1;
            vuint32_t AR30:1;
            vuint32_t AR29:1;
            vuint32_t AR28:1;
            vuint32_t AR27:1;
            vuint32_t AR26:1;
            vuint32_t AR25:1;
            vuint32_t AR24:1;
            vuint32_t AR23:1;
            vuint32_t AR22:1;
            vuint32_t AR21:1;
            vuint32_t AR20:1;
            vuint32_t AR19:1;
            vuint32_t AR18:1;
            vuint32_t AR17:1;
            vuint32_t AR16:1;
            vuint32_t AR15:1;
            vuint32_t AR14:1;
            vuint32_t AR13:1;
            vuint32_t AR12:1;
            vuint32_t AR11:1;
            vuint32_t AR10:1;
            vuint32_t AR9:1;
            vuint32_t AR8:1;
            vuint32_t AR7:1;
            vuint32_t AR6:1;
            vuint32_t AR5:1;
            vuint32_t AR4:1;
            vuint32_t AR3:1;
            vuint32_t AR2:1;
            vuint32_t AR1:1;
            vuint32_t AR0:1;
        } B;
    } TXBAR;

    union {
        vuint32_t R;
        struct {
            vuint32_t CR31:1;
            vuint32_t CR30:1;
            vuint32_t CR29:1;
            vuint32_t CR28:1;
            vuint32_t CR27:1;
            vuint32_t CR26:1;
            vuint32_t CR25:1;
            vuint32_t CR24:1;
            vuint32_t CR23:1;
            vuint32_t CR22:1;
            vuint32_t CR21:1;
            vuint32_t CR20:1;
            vuint32_t CR19:1;
            vuint32_t CR18:1;
            vuint32_t CR17:1;
            vuint32_t CR16:1;
            vuint32_t CR15:1;
            vuint32_t CR14:1;
            vuint32_t CR13:1;
            vuint32_t CR12:1;
            vuint32_t CR11:1;
            vuint32_t CR10:1;
            vuint32_t CR9:1;
            vuint32_t CR8:1;
            vuint32_t CR7:1;
            vuint32_t CR6:1;
            vuint32_t CR5:1;
            vuint32_t CR4:1;
            vuint32_t CR3:1;
            vuint32_t CR2:1;
            vuint32_t CR1:1;
            vuint32_t CR0:1;
        } B;
    } TXBCR;

    union {
        vuint32_t R;
        struct {
            vuint32_t TO31:1;
            vuint32_t TO30:1;
            vuint32_t TO29:1;
            vuint32_t TO28:1;
            vuint32_t TO27:1;
            vuint32_t TO26:1;
            vuint32_t TO25:1;
            vuint32_t TO24:1;
            vuint32_t TO23:1;
            vuint32_t TO22:1;
            vuint32_t TO21:1;
            vuint32_t TO20:1;
            vuint32_t TO19:1;
            vuint32_t TO18:1;
            vuint32_t TO17:1;
            vuint32_t TO16:1;
            vuint32_t TO15:1;
            vuint32_t TO14:1;
            vuint32_t TO13:1;
            vuint32_t TO12:1;
            vuint32_t TO11:1;
            vuint32_t TO10:1;
            vuint32_t TO9:1;
            vuint32_t TO8:1;
            vuint32_t TO7:1;
            vuint32_t TO6:1;
            vuint32_t TO5:1;
            vuint32_t TO4:1;
            vuint32_t TO3:1;
            vuint32_t TO2:1;
            vuint32_t TO1:1;
            vuint32_t TO0:1;
        } B;
    } TXBTO;

    union {
        vuint32_t R;
        struct {
            vuint32_t CF31:1;
            vuint32_t CF30:1;
            vuint32_t CF29:1;
            vuint32_t CF28:1;
            vuint32_t CF27:1;
            vuint32_t CF26:1;
            vuint32_t CF25:1;
            vuint32_t CF24:1;
            vuint32_t CF23:1;
            vuint32_t CF22:1;
            vuint32_t CF21:1;
            vuint32_t CF20:1;
            vuint32_t CF19:1;
            vuint32_t CF18:1;
            vuint32_t CF17:1;
            vuint32_t CF16:1;
            vuint32_t CF15:1;
            vuint32_t CF14:1;
            vuint32_t CF13:1;
            vuint32_t CF12:1;
            vuint32_t CF11:1;
            vuint32_t CF10:1;
            vuint32_t CF9:1;
            vuint32_t CF8:1;
            vuint32_t CF7:1;
            vuint32_t CF6:1;
            vuint32_t CF5:1;
            vuint32_t CF4:1;
            vuint32_t CF3:1;
            vuint32_t CF2:1;
            vuint32_t CF1:1;
            vuint32_t CF0:1;
        } B;
    } TXBCF;

    union {
        vuint32_t R;
        struct {
            vuint32_t TIE31:1;
            vuint32_t TIE30:1;
            vuint32_t TIE29:1;
            vuint32_t TIE28:1;
            vuint32_t TIE27:1;
            vuint32_t TIE26:1;
            vuint32_t TIE25:1;
            vuint32_t TIE24:1;
            vuint32_t TIE23:1;
            vuint32_t TIE22:1;
            vuint32_t TIE21:1;
            vuint32_t TIE20:1;
            vuint32_t TIE19:1;
            vuint32_t TIE18:1;
            vuint32_t TIE17:1;
            vuint32_t TIE16:1;
            vuint32_t TIE15:1;
            vuint32_t TIE14:1;
            vuint32_t TIE13:1;
            vuint32_t TIE12:1;
            vuint32_t TIE11:1;
            vuint32_t TIE10:1;
            vuint32_t TIE9:1;
            vuint32_t TIE8:1;
            vuint32_t TIE7:1;
            vuint32_t TIE6:1;
            vuint32_t TIE5:1;
            vuint32_t TIE4:1;
            vuint32_t TIE3:1;
            vuint32_t TIE2:1;
            vuint32_t TIE1:1;
            vuint32_t TIE0:1;
        } B;
    } TXBTIE;

    union {
        vuint32_t R;
        struct {
            vuint32_t CFIE31:1;
            vuint32_t CFIE30:1;
            vuint32_t CFIE29:1;
            vuint32_t CFIE28:1;
            vuint32_t CFIE27:1;
            vuint32_t CFIE26:1;
            vuint32_t CFIE25:1;
            vuint32_t CFIE24:1;
            vuint32_t CFIE23:1;
            vuint32_t CFIE22:1;
            vuint32_t CFIE21:1;
            vuint32_t CFIE20:1;
            vuint32_t CFIE19:1;
            vuint32_t CFIE18:1;
            vuint32_t CFIE17:1;
            vuint32_t CFIE16:1;
            vuint32_t CFIE15:1;
            vuint32_t CFIE14:1;
            vuint32_t CFIE13:1;
            vuint32_t CFIE12:1;
            vuint32_t CFIE11:1;
            vuint32_t CFIE10:1;
            vuint32_t CFIE9:1;
            vuint32_t CFIE8:1;
            vuint32_t CFIE7:1;
            vuint32_t CFIE6:1;
            vuint32_t CFIE5:1;
            vuint32_t CFIE4:1;
            vuint32_t CFIE3:1;
            vuint32_t CFIE2:1;
            vuint32_t CFIE1:1;
            vuint32_t CFIE0:1;
        } B;
    } TXBCIE;

    vuint8_t ADR_reserved5[8];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:2;
            vuint32_t EFWM:6;
            vuint32_t unused_1:2;
            vuint32_t EFS:6;
            vuint32_t EFSA:14;
            vuint32_t unused_0:2;
        } B;
    } TXEFC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:6;
            vuint32_t TEFL:1;
            vuint32_t EFF:1;
            vuint32_t unused_2:3;
            vuint32_t EFPI:5;
            vuint32_t unused_1:3;
            vuint32_t EFGI:5;
            vuint32_t unused_0:2;
            vuint32_t EFFL:6;
        } B;
    } TXEFS;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:27;
            vuint32_t EFAI:5;
        } B;
    } TXEFA;

};

/**************************************************************************/
/*                 Module: CCCU            */
/**************************************************************************/
struct CCCU_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t REL:4;
            vuint32_t STEP:4;
            vuint32_t SUBSTEP:4;
            vuint32_t YEAR:4;
            vuint32_t MON:8;
            vuint32_t DAY:8;
        } B;
    } CREL;

    union {
        vuint32_t R;
        struct {
            vuint32_t SWR:1;
            vuint32_t unused_1:11;
            vuint32_t CDIV:4;
            vuint32_t OCPM:8;
            vuint32_t CFL:1;
            vuint32_t BCC:1;
            vuint32_t unused_0:1;
            vuint32_t TQBT:5;
        } B;
    } CCFG;

    union {
        vuint32_t R;
        struct {
            vuint32_t CALS:2;
            vuint32_t unused_0:1;
            vuint32_t TQC:11;
            vuint32_t OCPC:18;
        } B;
    } CSTAT;

    union {
        vuint32_t R;
        struct {
            vuint32_t WDV:16;
            vuint32_t WDC:16;
        } B;
    } CWD;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:30;
            vuint32_t CSC:1;
            vuint32_t CWE:1;
        } B;
    } CUIR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:30;
            vuint32_t CSCE:1;
            vuint32_t CWEE:1;
        } B;
    } CUIE;

};

/**************************************************************************/
/*                 Module: CMU            */
/**************************************************************************/
struct CMU_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:8;
            vuint32_t SFM:1;
            vuint32_t unused_1:13;
            vuint32_t CKSEL1:2;
            vuint32_t unused_0:5;
            vuint32_t RCDIV:2;
            vuint32_t CME:1;
        } B;
    } CSR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:12;
            vuint32_t FD:20;
        } B;
    } FDR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:20;
            vuint32_t HFREF:12;
        } B;
    } HFREFR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:20;
            vuint32_t LFREF:12;
        } B;
    } LFREFR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:28;
            vuint32_t FLCI:1;
            vuint32_t FHHI:1;
            vuint32_t FLLI:1;
            vuint32_t OLRI:1;
        } B;
    } ISR;

    vuint8_t ADR_reserved0[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:12;
            vuint32_t MD:20;
        } B;
    } MDR;

};

/**************************************************************************/
/*                 Module: CRC            */
/**************************************************************************/
struct CRC_tag {
    struct {
        union {
            vuint32_t R;
            struct {
                vuint32_t unused_0:26;
                vuint32_t SWAP_BYTEWISE:1;
                vuint32_t SWAP_BITWISE:1;
                vuint32_t POLYG:2;
                vuint32_t SWAP:1;
                vuint32_t INV:1;
            } B;
        } CFG;

        union {
            vuint32_t R;
            vuint16_t H[2];  /* Data buffer in Half-words (16 bits) */                           
            vuint8_t BYTE[4];  /* Data buffer in Bytes (8 bits) */
            struct {
                vuint32_t INP:32;
            } B;
        } INP;

        union {
            vuint32_t R;
            struct {
                vuint32_t CSTAT:32;
            } B;
        } CSTAT;

        union {
            vuint32_t R;
            struct {
                vuint32_t OUTP:32;
            } B;
        } OUTP;

    } CONTEXT[4];

};

/**************************************************************************/
/*                 Module: DMAMUX            */
/**************************************************************************/
struct DMAMUX_tag {
    union {
        vuint8_t R;
        struct {
            vuint8_t ENBL:1;
            vuint8_t TRIG:1;
            vuint8_t SOURCE:6;
        } B;
    } CHCFG[16];

};

/**************************************************************************/
/*                 Module: DSPI            */
/**************************************************************************/
struct DSPI_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t MSTR:1;
            vuint32_t CONT_SCKE:1;
            vuint32_t DCONF:2;
            vuint32_t FRZ:1;
            vuint32_t MTFE:1;
            vuint32_t PCSSE:1;
            vuint32_t ROOE:1;
            vuint32_t PCSIS7:1;
            vuint32_t PCSIS6:1;
            vuint32_t PCSIS5:1;
            vuint32_t PCSIS4:1;
            vuint32_t PCSIS3:1;
            vuint32_t PCSIS2:1;
            vuint32_t PCSIS1:1;
            vuint32_t PCSIS0:1;
            vuint32_t unused_1:1;
            vuint32_t MDIS:1;
            vuint32_t DIS_TXF:1;
            vuint32_t DIS_RXF:1;
            vuint32_t CLR_TXF:1;
            vuint32_t CLR_RXF:1;
            vuint32_t SMPL_PT:2;
            vuint32_t unused_0:4;
            vuint32_t XSPI:1;
            vuint32_t FCPCS:1;
            vuint32_t PES:1;
            vuint32_t HALT:1;
        } B;
    } MCR;

    union {
        vuint32_t R;
        struct {
            vuint32_t DSI:1;
            vuint32_t PISR:1;
            vuint32_t DSI64:1;
            vuint32_t PISR_EX:1;
            vuint32_t XSPI:1;
            vuint32_t CTAR:3;
            vuint32_t TXFR:4;
            vuint32_t RXFR:4;
            vuint32_t CMDFR:5;
            vuint32_t MSTR_MODE:1;
            vuint32_t SLV_MODE:1;
            vuint32_t TSB_EN:1;
            vuint32_t ITSB_EN:1;
            vuint32_t unused_0:7;
        } B;
    } HCR;

    union {
        vuint32_t R;
        struct {
            vuint32_t SPI_TCNT:16;
            vuint32_t unused_0:16;
        } B;
    } TCR;

    union {
        vuint32_t R;
        struct {
            vuint32_t DBR:1;
            vuint32_t FMSZ:4;
            vuint32_t CPOL:1;
            vuint32_t CPHA:1;
            vuint32_t LSBFE:1;
            vuint32_t PCSSCK:2;
            vuint32_t PASC:2;
            vuint32_t PDT:2;
            vuint32_t PBR:2;
            vuint32_t CSSCK:4;
            vuint32_t ASC:4;
            vuint32_t DT:4;
            vuint32_t BR:4;
        } B;
        struct {
            vuint32_t FMSZ:5;
            vuint32_t CPOL:1;
            vuint32_t CPHA:1;
            vuint32_t PE:1;
            vuint32_t PP:1;
            vuint32_t FMSZ5:1;
            vuint32_t unused_0:22;
        } B_SLAVE;
    } CTAR0;

    union {
        vuint32_t R;
        struct {
            vuint32_t DBR:1;
            vuint32_t FMSZ:4;
            vuint32_t CPOL:1;
            vuint32_t CPHA:1;
            vuint32_t LSBFE:1;
            vuint32_t PCSSCK:2;
            vuint32_t PASC:2;
            vuint32_t PDT:2;
            vuint32_t PBR:2;
            vuint32_t CSSCK:4;
            vuint32_t ASC:4;
            vuint32_t DT:4;
            vuint32_t BR:4;
        } B;
        struct {
            vuint32_t FMSZ:5;
            vuint32_t CPOL:1;
            vuint32_t CPHA:1;
            vuint32_t PE:1;
            vuint32_t PP:1;
            vuint32_t FMSZ5:1;
            vuint32_t unused_0:22;
        } B_SLAVE;
    } CTAR1;

    union {
        vuint32_t R;
        struct {
            vuint32_t DBR:1;
            vuint32_t FMSZ:4;
            vuint32_t CPOL:1;
            vuint32_t CPHA:1;
            vuint32_t LSBFE:1;
            vuint32_t PCSSCK:2;
            vuint32_t PASC:2;
            vuint32_t PDT:2;
            vuint32_t PBR:2;
            vuint32_t CSSCK:4;
            vuint32_t ASC:4;
            vuint32_t DT:4;
            vuint32_t BR:4;
        } B;
    } CTAR2;

    union {
        vuint32_t R;
        struct {
            vuint32_t DBR:1;
            vuint32_t FMSZ:4;
            vuint32_t CPOL:1;
            vuint32_t CPHA:1;
            vuint32_t LSBFE:1;
            vuint32_t PCSSCK:2;
            vuint32_t PASC:2;
            vuint32_t PDT:2;
            vuint32_t PBR:2;
            vuint32_t CSSCK:4;
            vuint32_t ASC:4;
            vuint32_t DT:4;
            vuint32_t BR:4;
        } B;
    } CTAR3;

    union {
        vuint32_t R;
        struct {
            vuint32_t DBR:1;
            vuint32_t FMSZ:4;
            vuint32_t CPOL:1;
            vuint32_t CPHA:1;
            vuint32_t LSBFE:1;
            vuint32_t PCSSCK:2;
            vuint32_t PASC:2;
            vuint32_t PDT:2;
            vuint32_t PBR:2;
            vuint32_t CSSCK:4;
            vuint32_t ASC:4;
            vuint32_t DT:4;
            vuint32_t BR:4;
        } B;
    } CTAR4;

    union {
        vuint32_t R;
        struct {
            vuint32_t DBR:1;
            vuint32_t FMSZ:4;
            vuint32_t CPOL:1;
            vuint32_t CPHA:1;
            vuint32_t LSBFE:1;
            vuint32_t PCSSCK:2;
            vuint32_t PASC:2;
            vuint32_t PDT:2;
            vuint32_t PBR:2;
            vuint32_t CSSCK:4;
            vuint32_t ASC:4;
            vuint32_t DT:4;
            vuint32_t BR:4;
        } B;
    } CTAR5;

    union {
        vuint32_t R;
        struct {
            vuint32_t DBR:1;
            vuint32_t FMSZ:4;
            vuint32_t CPOL:1;
            vuint32_t CPHA:1;
            vuint32_t LSBFE:1;
            vuint32_t PCSSCK:2;
            vuint32_t PASC:2;
            vuint32_t PDT:2;
            vuint32_t PBR:2;
            vuint32_t CSSCK:4;
            vuint32_t ASC:4;
            vuint32_t DT:4;
            vuint32_t BR:4;
        } B;
    } CTAR6;

    union {
        vuint32_t R;
        struct {
            vuint32_t DBR:1;
            vuint32_t FMSZ:4;
            vuint32_t CPOL:1;
            vuint32_t CPHA:1;
            vuint32_t LSBFE:1;
            vuint32_t PCSSCK:2;
            vuint32_t PASC:2;
            vuint32_t PDT:2;
            vuint32_t PBR:2;
            vuint32_t CSSCK:4;
            vuint32_t ASC:4;
            vuint32_t DT:4;
            vuint32_t BR:4;
        } B;
    } CTAR7;

    union {
        vuint32_t R;
        struct {
            vuint32_t TCF:1;
            vuint32_t TXRXS:1;
            vuint32_t unused_3:1;
            vuint32_t EOQF:1;
            vuint32_t TFUF:1;
            vuint32_t unused_2:1;
            vuint32_t TFFF:1;
            vuint32_t BSYF:1;
            vuint32_t CMDTCF:1;
            vuint32_t unused_1:1;
            vuint32_t SPEF:1;
            vuint32_t unused_0:1;
            vuint32_t RFOF:1;
            vuint32_t TFIWF:1;
            vuint32_t RFDF:1;
            vuint32_t CMDFFF:1;
            vuint32_t TXCTR:4;
            vuint32_t TXNXTPTR:4;
            vuint32_t RXCTR:4;
            vuint32_t POPNXTPTR:4;
        } B;
    } SR;

    union {
        vuint32_t R;
        struct {
            vuint32_t TCF_RE:1;
            vuint32_t CMDFFF_RE:1;
            vuint32_t SPITCF_RE:1;
            vuint32_t EOQF_RE:1;
            vuint32_t TFUF_RE:1;
            vuint32_t unused_3:1;
            vuint32_t TFFF_RE:1;
            vuint32_t TFFF_DIRS:1;
            vuint32_t CMDTCF_RE:1;
            vuint32_t unused_2:1;
            vuint32_t SPEF_RE:1;
            vuint32_t unused_1:1;
            vuint32_t RFOF_RE:1;
            vuint32_t TFIWF_RE:1;
            vuint32_t RFDF_RE:1;
            vuint32_t RFDF_DIRS:1;
            vuint32_t CMDFFF_DIRS:1;
            vuint32_t unused_0:15;
        } B;
    } RSER;

    union {
        vuint32_t R;
        struct {
            vuint32_t CONT:1;
            vuint32_t CTAS:3;
            vuint32_t EOQ:1;
            vuint32_t CTCNT:1;
            vuint32_t PE_MASC:1;
            vuint32_t PP_MCSC:1;
            vuint32_t PCS:8;
            vuint32_t TXDATA:16;
        } B;
        struct {
            vuint32_t unused_0:16;
            vuint32_t TXDATA:16;
        } B_SLAVE;
    } PUSHR;

    union {
        vuint32_t R;
        struct {
            vuint32_t RXDATA:32;
        } B;
    } POPR;

    union {
        vuint32_t R;
        struct {
            vuint32_t TXCMD_TXDATA:16;
            vuint32_t TXDATA:16;
        } B;
    } TXFR[4];

    vuint8_t ADR_reserved3[48];

    union {
        vuint32_t R;
        struct {
            vuint32_t RXDATA:32;
        } B;
    } RXFR[4];

    vuint8_t ADR_reserved4[144];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:15;
            vuint32_t FMSZE:1;
            vuint32_t unused_0:5;
            vuint32_t DTCP:11;
        } B;
    } CTARE[8];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:24;
            vuint32_t CMDCTR:4;
            vuint32_t CMDNXTPTR:4;
        } B;
    } SREX;

};

/**************************************************************************/
/*                 Module: DTS            */
/**************************************************************************/
struct DTS_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:30;
            vuint32_t DTS_EN_B:1;
            vuint32_t DTS_EN:1;
        } B;
    } ENABLE;

    union {
        vuint32_t R;
        struct {
            vuint32_t AD:32;
        } B;
    } STARTUP;

    union {
        vuint32_t R;
        struct {
            vuint32_t ST:32;
        } B;
    } SEMAPHORE;

    union {
        vuint32_t R;
        struct {
            vuint32_t ST_B:32;
        } B;
    } SEMAPHORE_B;

};

/**************************************************************************/
/*                 Module: EDMA            */
/**************************************************************************/
struct EDMA_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:14;
            vuint32_t CX:1;
            vuint32_t ECX:1;
            vuint32_t unused_1:6;
            vuint32_t GRP0PRI:2;
            vuint32_t EMLM:1;
            vuint32_t CLM:1;
            vuint32_t HALT:1;
            vuint32_t HOE:1;
            vuint32_t ERGA:1;
            vuint32_t ERCA:1;
            vuint32_t EDBG:1;
            vuint32_t unused_0:1;
        } B;
    } CR;

    union {
        vuint32_t R;
        struct {
            vuint32_t VLD:1;
            vuint32_t unused_1:13;
            vuint32_t UCE:1;
            vuint32_t ECX:1;
            vuint32_t unused_0:1;
            vuint32_t CPE:1;
            vuint32_t ERRCHN:6;
            vuint32_t SAE:1;
            vuint32_t SOE:1;
            vuint32_t DAE:1;
            vuint32_t DOE:1;
            vuint32_t NCE:1;
            vuint32_t SGE:1;
            vuint32_t SBE:1;
            vuint32_t DBE:1;
        } B;
    } ES;

    vuint8_t ADR_reserved0[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t ERQ15:1;
            vuint32_t ERQ14:1;
            vuint32_t ERQ13:1;
            vuint32_t ERQ12:1;
            vuint32_t ERQ11:1;
            vuint32_t ERQ10:1;
            vuint32_t ERQ9:1;
            vuint32_t ERQ8:1;
            vuint32_t ERQ7:1;
            vuint32_t ERQ6:1;
            vuint32_t ERQ5:1;
            vuint32_t ERQ4:1;
            vuint32_t ERQ3:1;
            vuint32_t ERQ2:1;
            vuint32_t ERQ1:1;
            vuint32_t ERQ0:1;
        } B;
    } ERQL;

    vuint8_t ADR_reserved1[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t EEI15:1;
            vuint32_t EEI14:1;
            vuint32_t EEI13:1;
            vuint32_t EEI12:1;
            vuint32_t EEI11:1;
            vuint32_t EEI10:1;
            vuint32_t EEI9:1;
            vuint32_t EEI8:1;
            vuint32_t EEI7:1;
            vuint32_t EEI6:1;
            vuint32_t EEI5:1;
            vuint32_t EEI4:1;
            vuint32_t EEI3:1;
            vuint32_t EEI2:1;
            vuint32_t EEI1:1;
            vuint32_t EEI0:1;
        } B;
    } EEIL;

    union {
        vuint8_t R;
        struct {
            vuint8_t NOP:1;
            vuint8_t SAER:1;
            vuint8_t SERQ:6;
        } B;
    } SERQ;

    union {
        vuint8_t R;
        struct {
            vuint8_t NOP:1;
            vuint8_t CAER:1;
            vuint8_t CERQ:6;
        } B;
    } CERQ;

    union {
        vuint8_t R;
        struct {
            vuint8_t NOP:1;
            vuint8_t SAEE:1;
            vuint8_t SEEI:6;
        } B;
    } SEEI;

    union {
        vuint8_t R;
        struct {
            vuint8_t NOP:1;
            vuint8_t CAEE:1;
            vuint8_t CEEI:6;
        } B;
    } CEEI;

    union {
        vuint8_t R;
        struct {
            vuint8_t NOP:1;
            vuint8_t CAIR:1;
            vuint8_t CINT:6;
        } B;
    } CINT;

    union {
        vuint8_t R;
        struct {
            vuint8_t NOP:1;
            vuint8_t CAEI:1;
            vuint8_t CERR:6;
        } B;
    } CERR;

    union {
        vuint8_t R;
        struct {
            vuint8_t NOP:1;
            vuint8_t SAST:1;
            vuint8_t SSRT:6;
        } B;
    } SSRT;

    union {
        vuint8_t R;
        struct {
            vuint8_t NOP:1;
            vuint8_t CADN:1;
            vuint8_t CDNE:6;
        } B;
    } CDNE;

    vuint8_t ADR_reserved2[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t INT15:1;
            vuint32_t INT14:1;
            vuint32_t INT13:1;
            vuint32_t INT12:1;
            vuint32_t INT11:1;
            vuint32_t INT10:1;
            vuint32_t INT9:1;
            vuint32_t INT8:1;
            vuint32_t INT7:1;
            vuint32_t INT6:1;
            vuint32_t INT5:1;
            vuint32_t INT4:1;
            vuint32_t INT3:1;
            vuint32_t INT2:1;
            vuint32_t INT1:1;
            vuint32_t INT0:1;
        } B;
    } INTL;

    vuint8_t ADR_reserved3[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t ERR15:1;
            vuint32_t ERR14:1;
            vuint32_t ERR13:1;
            vuint32_t ERR12:1;
            vuint32_t ERR11:1;
            vuint32_t ERR10:1;
            vuint32_t ERR9:1;
            vuint32_t ERR8:1;
            vuint32_t ERR7:1;
            vuint32_t ERR6:1;
            vuint32_t ERR5:1;
            vuint32_t ERR4:1;
            vuint32_t ERR3:1;
            vuint32_t ERR2:1;
            vuint32_t ERR1:1;
            vuint32_t ERR0:1;
        } B;
    } ERRL;

    vuint8_t ADR_reserved4[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t HRS15:1;
            vuint32_t HRS14:1;
            vuint32_t HRS13:1;
            vuint32_t HRS12:1;
            vuint32_t HRS11:1;
            vuint32_t HRS10:1;
            vuint32_t HRS9:1;
            vuint32_t HRS8:1;
            vuint32_t HRS7:1;
            vuint32_t HRS6:1;
            vuint32_t HRS5:1;
            vuint32_t HRS4:1;
            vuint32_t HRS3:1;
            vuint32_t HRS2:1;
            vuint32_t HRS1:1;
            vuint32_t HRS0:1;
        } B;
    } HRSL;

    vuint8_t ADR_reserved5[200];

    union {
        vuint8_t R;
        struct {
            vuint8_t ECP:1;
            vuint8_t DPA:1;
            vuint8_t GRPPRI:2;
            vuint8_t CHPRI:4;
        } B;
    } DCHPRI[16];

    vuint8_t ADR_reserved6[48];

    union {
        vuint8_t R;
        struct {
            vuint8_t EMI:1;
            vuint8_t PAL:1;
            vuint8_t unused_0:2;
            vuint8_t MID:4;
        } B;
    } DCHMID[16];

    vuint8_t ADR_reserved7[3760];

    struct {
        union {
            vuint32_t R;
            struct {
                vuint32_t SADDR:32;
            } B;
        } TCD_SADDR;

        union {
            vuint16_t R;
            struct {
                vuint16_t SMOD:5;
                vuint16_t SSIZE:3;
                vuint16_t DMOD:5;
                vuint16_t DSIZE:3;
            } B;
        } TCD_ATTR;

        union {
            vuint16_t R;
            struct {
                vuint16_t SOFF:16;
            } B;
        } TCD_SOFF;

        union {
            vuint32_t R;
            struct {
                vuint32_t SMLOE:1;
                vuint32_t DMLOE:1;
                vuint32_t MLOFF:20;
                vuint32_t NBYTES:10;
            } B_MLOFFYES;
            struct {
                vuint32_t SMLOE:1;
                vuint32_t DMLOE:1;
                vuint32_t NBYTES:30;
            } B_MLOFFNO;
            struct {
                vuint32_t NBYTES:32;
            } B_MLNO;
        } TCD_NBYTES;

        union {
            vuint32_t R;
            struct {
                vuint32_t SLAST:32;
            } B;
        } TCD_SLAST;

        union {
            vuint32_t R;
            struct {
                vuint32_t DADDR:32;
            } B;
        } TCD_DADDR;

        union {
            vuint16_t R;
            struct {
                vuint16_t ELINK:1;
                vuint16_t LINKCH:6;
                vuint16_t CITER:9;
            } B_ELINKYES;
            struct {
                vuint16_t ELINK:1;
                vuint16_t CITER:15;
            } B_ELINKNO;
        } TCD_CITER;

        union {
            vuint16_t R;
            struct {
                vuint16_t DOFF:16;
            } B;
        } TCD_DOFF;

        union {
            vuint32_t R;
            struct {
                vuint32_t DLASTSGA:32;
            } B;
        } TCD_DLASTSGA;

        union {
            vuint16_t R;
            struct {
                vuint16_t ELINK:1;
                vuint16_t LINKCH:6;
                vuint16_t BITER:9;
            } B_ELINKYES;
            struct {
                vuint16_t ELINK:1;
                vuint16_t BITER:15;
            } B_ELINKNO;
        } TCD_BITER;

        union {
            vuint16_t R;
            struct {
                vuint16_t BWC:2;
                vuint16_t MAJORLINKCH:6;
                vuint16_t DONE:1;
                vuint16_t ACTIVE:1;
                vuint16_t MAJORELINK:1;
                vuint16_t ESG:1;
                vuint16_t DREQ:1;
                vuint16_t INTHALF:1;
                vuint16_t INTMAJOR:1;
                vuint16_t START:1;
            } B;
        } TCD_CSR;

    } CH[16];

};

/**************************************************************************/
/*                 Module: EMIOS            */
/**************************************************************************/
struct EMIOS_tag {
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

/**************************************************************************/
/*                 Module: FCCU            */
/**************************************************************************/
struct FCCU_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t FILTER_BYPASS:1;
            vuint32_t FILTER_WIDTH:2;
            vuint32_t unused_2:19;
            vuint32_t DEBUG:1;
            vuint32_t unused_1:1;
            vuint32_t OPS:2;
            vuint32_t unused_0:1;
            vuint32_t OPR:5;
        } B;
    } CTRL;

    union {
        vuint32_t R;
        struct {
            vuint32_t CTRLK:32;
        } B;
    } CTRLK;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:7;
            vuint32_t FCCU_SET_AFTER_RESET:1;
            vuint32_t FCCU_SET_CLEAR:2;
            vuint32_t unused_2:9;
            vuint32_t OD:1;
            vuint32_t unused_1:1;
            vuint32_t SM:1;
            vuint32_t PS:1;
            vuint32_t FOM:3;
            vuint32_t unused_0:6;
        } B;
    } CFG;

    vuint8_t ADR_reserved0[16];

    union {
        vuint32_t R;
        struct {
            vuint32_t RFC31:1;
            vuint32_t RFC30:1;
            vuint32_t RFC29:1;
            vuint32_t RFC28:1;
            vuint32_t RFC27:1;
            vuint32_t RFC26:1;
            vuint32_t RFC25:1;
            vuint32_t RFC24:1;
            vuint32_t RFC23:1;
            vuint32_t RFC22:1;
            vuint32_t RFC21:1;
            vuint32_t RFC20:1;
            vuint32_t RFC19:1;
            vuint32_t RFC18:1;
            vuint32_t RFC17:1;
            vuint32_t RFC16:1;
            vuint32_t RFC15:1;
            vuint32_t RFC14:1;
            vuint32_t RFC13:1;
            vuint32_t RFC12:1;
            vuint32_t RFC11:1;
            vuint32_t RFC10:1;
            vuint32_t RFC9:1;
            vuint32_t RFC8:1;
            vuint32_t RFC7:1;
            vuint32_t RFC6:1;
            vuint32_t RFC5:1;
            vuint32_t RFC4:1;
            vuint32_t RFC3:1;
            vuint32_t RFC2:1;
            vuint32_t RFC1:1;
            vuint32_t RFC0:1;
        } B;
    } RF_CFG[4];

    vuint8_t ADR_reserved1[32];

    union {
        vuint32_t R;
        struct {
            vuint32_t RFSC15:2;
            vuint32_t RFSC14:2;
            vuint32_t RFSC13:2;
            vuint32_t RFSC12:2;
            vuint32_t RFSC11:2;
            vuint32_t RFSC10:2;
            vuint32_t RFSC9:2;
            vuint32_t RFSC8:2;
            vuint32_t RFSC7:2;
            vuint32_t RFSC6:2;
            vuint32_t RFSC5:2;
            vuint32_t RFSC4:2;
            vuint32_t RFSC3:2;
            vuint32_t RFSC2:2;
            vuint32_t RFSC1:2;
            vuint32_t RFSC0:2;
        } B;
    } RFS_CFG[8];

    vuint8_t ADR_reserved2[20];

    union {
        vuint32_t R;
        struct {
            vuint32_t RFS31:1;
            vuint32_t RFS30:1;
            vuint32_t RFS29:1;
            vuint32_t RFS28:1;
            vuint32_t RFS27:1;
            vuint32_t RFS26:1;
            vuint32_t RFS25:1;
            vuint32_t RFS24:1;
            vuint32_t RFS23:1;
            vuint32_t RFS22:1;
            vuint32_t RFS21:1;
            vuint32_t RFS20:1;
            vuint32_t RFS19:1;
            vuint32_t RFS18:1;
            vuint32_t RFS17:1;
            vuint32_t RFS16:1;
            vuint32_t RFS15:1;
            vuint32_t RFS14:1;
            vuint32_t RFS13:1;
            vuint32_t RFS12:1;
            vuint32_t RFS11:1;
            vuint32_t RFS10:1;
            vuint32_t RFS9:1;
            vuint32_t RFS8:1;
            vuint32_t RFS7:1;
            vuint32_t RFS6:1;
            vuint32_t RFS5:1;
            vuint32_t RFS4:1;
            vuint32_t RFS3:1;
            vuint32_t RFS2:1;
            vuint32_t RFS1:1;
            vuint32_t RFS0:1;
        } B;
    } RF_S[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t RFK:32;
        } B;
    } RFK;

    union {
        vuint32_t R;
        struct {
            vuint32_t RFE31:1;
            vuint32_t RFE30:1;
            vuint32_t RFE29:1;
            vuint32_t RFE28:1;
            vuint32_t RFE27:1;
            vuint32_t RFE26:1;
            vuint32_t RFE25:1;
            vuint32_t RFE24:1;
            vuint32_t RFE23:1;
            vuint32_t RFE22:1;
            vuint32_t RFE21:1;
            vuint32_t RFE20:1;
            vuint32_t RFE19:1;
            vuint32_t RFE18:1;
            vuint32_t RFE17:1;
            vuint32_t RFE16:1;
            vuint32_t RFE15:1;
            vuint32_t RFE14:1;
            vuint32_t RFE13:1;
            vuint32_t RFE12:1;
            vuint32_t RFE11:1;
            vuint32_t RFE10:1;
            vuint32_t RFE9:1;
            vuint32_t RFE8:1;
            vuint32_t RFE7:1;
            vuint32_t RFE6:1;
            vuint32_t RFE5:1;
            vuint32_t RFE4:1;
            vuint32_t RFE3:1;
            vuint32_t RFE2:1;
            vuint32_t RFE1:1;
            vuint32_t RFE0:1;
        } B;
    } RF_E[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t RFTOE31:1;
            vuint32_t RFTOE30:1;
            vuint32_t RFTOE29:1;
            vuint32_t RFTOE28:1;
            vuint32_t RFTOE27:1;
            vuint32_t RFTOE26:1;
            vuint32_t RFTOE25:1;
            vuint32_t RFTOE24:1;
            vuint32_t RFTOE23:1;
            vuint32_t RFTOE22:1;
            vuint32_t RFTOE21:1;
            vuint32_t RFTOE20:1;
            vuint32_t RFTOE19:1;
            vuint32_t RFTOE18:1;
            vuint32_t RFTOE17:1;
            vuint32_t RFTOE16:1;
            vuint32_t RFTOE15:1;
            vuint32_t RFTOE14:1;
            vuint32_t RFTOE13:1;
            vuint32_t RFTOE12:1;
            vuint32_t RFTOE11:1;
            vuint32_t RFTOE10:1;
            vuint32_t RFTOE9:1;
            vuint32_t RFTOE8:1;
            vuint32_t RFTOE7:1;
            vuint32_t RFTOE6:1;
            vuint32_t RFTOE5:1;
            vuint32_t RFTOE4:1;
            vuint32_t RFTOE3:1;
            vuint32_t RFTOE2:1;
            vuint32_t RFTOE1:1;
            vuint32_t RFTOE0:1;
        } B;
    } RF_TOE[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t TO:32;
        } B;
    } RF_TO;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:29;
            vuint32_t TO:3;
        } B;
    } CFG_TO;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:26;
            vuint32_t EIN1:1;
            vuint32_t EIN0:1;
            vuint32_t unused_0:2;
            vuint32_t EOUT1:1;
            vuint32_t EOUT0:1;
        } B;
    } EINOUT;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:26;
            vuint32_t PHYSICERRORPIN:2;
            vuint32_t ESTAT:1;
            vuint32_t STATUS:3;
        } B;
    } STAT;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:24;
            vuint32_t NAFS:8;
        } B;
    } N2AF_STATUS;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:22;
            vuint32_t AF_SRC:2;
            vuint32_t AFFS:8;
        } B;
    } A2FF_STATUS;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:22;
            vuint32_t NF_SRC:2;
            vuint32_t NFFS:8;
        } B;
    } N2FF_STATUS;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:24;
            vuint32_t FAFS:8;
        } B;
    } F2A_STATUS;

    vuint8_t ADR_reserved3[8];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:25;
            vuint32_t FRFC:7;
        } B;
    } RFF;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:29;
            vuint32_t NMI_STAT:1;
            vuint32_t ALRM_STAT:1;
            vuint32_t CFG_TO_STAT:1;
        } B;
    } IRQ_STAT;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:31;
            vuint32_t CFG_TO_IEN:1;
        } B;
    } IRQ_EN;

    union {
        vuint32_t R;
        struct {
            vuint32_t XTMR:32;
        } B;
    } XTMR;

    union {
        vuint32_t R;
        struct {
            vuint32_t VL3:1;
            vuint32_t FS3:1;
            vuint32_t unused_3:2;
            vuint32_t MCS3:4;
            vuint32_t VL2:1;
            vuint32_t FS2:1;
            vuint32_t unused_2:2;
            vuint32_t MCS2:4;
            vuint32_t VL1:1;
            vuint32_t FS1:1;
            vuint32_t unused_1:2;
            vuint32_t MCS1:4;
            vuint32_t VL0:1;
            vuint32_t FS0:1;
            vuint32_t unused_0:2;
            vuint32_t MCS0:4;
        } B;
    } MCS;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:24;
            vuint32_t TRANSKEY:8;
        } B;
    } TRANS_LOCK;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:24;
            vuint32_t PERMNTKEY:8;
        } B;
    } PERMNT_LOCK;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:18;
            vuint32_t DELTA_T:14;
        } B;
    } DELTA_T;

    union {
        vuint32_t R;
        struct {
            vuint32_t IRQEN31:1;
            vuint32_t IRQEN30:1;
            vuint32_t IRQEN29:1;
            vuint32_t IRQEN28:1;
            vuint32_t IRQEN27:1;
            vuint32_t IRQEN26:1;
            vuint32_t IRQEN25:1;
            vuint32_t IRQEN24:1;
            vuint32_t IRQEN23:1;
            vuint32_t IRQEN22:1;
            vuint32_t IRQEN21:1;
            vuint32_t IRQEN20:1;
            vuint32_t IRQEN19:1;
            vuint32_t IRQEN18:1;
            vuint32_t IRQEN17:1;
            vuint32_t IRQEN16:1;
            vuint32_t IRQEN15:1;
            vuint32_t IRQEN14:1;
            vuint32_t IRQEN13:1;
            vuint32_t IRQEN12:1;
            vuint32_t IRQEN11:1;
            vuint32_t IRQEN10:1;
            vuint32_t IRQEN9:1;
            vuint32_t IRQEN8:1;
            vuint32_t IRQEN7:1;
            vuint32_t IRQEN6:1;
            vuint32_t IRQEN5:1;
            vuint32_t IRQEN4:1;
            vuint32_t IRQEN3:1;
            vuint32_t IRQEN2:1;
            vuint32_t IRQEN1:1;
            vuint32_t IRQEN0:1;
        } B;
    } IRQ_ALARM_EN[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t NMIEN31:1;
            vuint32_t NMIEN30:1;
            vuint32_t NMIEN29:1;
            vuint32_t NMIEN28:1;
            vuint32_t NMIEN27:1;
            vuint32_t NMIEN26:1;
            vuint32_t NMIEN25:1;
            vuint32_t NMIEN24:1;
            vuint32_t NMIEN23:1;
            vuint32_t NMIEN22:1;
            vuint32_t NMIEN21:1;
            vuint32_t NMIEN20:1;
            vuint32_t NMIEN19:1;
            vuint32_t NMIEN18:1;
            vuint32_t NMIEN17:1;
            vuint32_t NMIEN16:1;
            vuint32_t NMIEN15:1;
            vuint32_t NMIEN14:1;
            vuint32_t NMIEN13:1;
            vuint32_t NMIEN12:1;
            vuint32_t NMIEN11:1;
            vuint32_t NMIEN10:1;
            vuint32_t NMIEN9:1;
            vuint32_t NMIEN8:1;
            vuint32_t NMIEN7:1;
            vuint32_t NMIEN6:1;
            vuint32_t NMIEN5:1;
            vuint32_t NMIEN4:1;
            vuint32_t NMIEN3:1;
            vuint32_t NMIEN2:1;
            vuint32_t NMIEN1:1;
            vuint32_t NMIEN0:1;
        } B;
    } NMI_EN[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t EOUTEN31:1;
            vuint32_t EOUTEN30:1;
            vuint32_t EOUTEN29:1;
            vuint32_t EOUTEN28:1;
            vuint32_t EOUTEN27:1;
            vuint32_t EOUTEN26:1;
            vuint32_t EOUTEN25:1;
            vuint32_t EOUTEN24:1;
            vuint32_t EOUTEN23:1;
            vuint32_t EOUTEN22:1;
            vuint32_t EOUTEN21:1;
            vuint32_t EOUTEN20:1;
            vuint32_t EOUTEN19:1;
            vuint32_t EOUTEN18:1;
            vuint32_t EOUTEN17:1;
            vuint32_t EOUTEN16:1;
            vuint32_t EOUTEN15:1;
            vuint32_t EOUTEN14:1;
            vuint32_t EOUTEN13:1;
            vuint32_t EOUTEN12:1;
            vuint32_t EOUTEN11:1;
            vuint32_t EOUTEN10:1;
            vuint32_t EOUTEN9:1;
            vuint32_t EOUTEN8:1;
            vuint32_t EOUTEN7:1;
            vuint32_t EOUTEN6:1;
            vuint32_t EOUTEN5:1;
            vuint32_t EOUTEN4:1;
            vuint32_t EOUTEN3:1;
            vuint32_t EOUTEN2:1;
            vuint32_t EOUTEN1:1;
            vuint32_t EOUTEN0:1;
        } B;
    } EOUT_SIG_EN[4];

};

/**************************************************************************/
/*                 Module: FLASH            */
/**************************************************************************/
struct FLASH_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:1;
            vuint32_t RRE:1;
            vuint32_t AEE:1;
            vuint32_t EEE:1;
            vuint32_t unused_2:2;
            vuint32_t DWEE:2;
            vuint32_t unused_1:3;
            vuint32_t SBC1:1;
            vuint32_t SAK:1;
            vuint32_t LSW:1;
            vuint32_t PEP:1;
            vuint32_t PES:1;
            vuint32_t EER:1;
            vuint32_t RWE:1;
            vuint32_t SBC:1;
            vuint32_t RE:1;
            vuint32_t PEAS:1;
            vuint32_t DONE:1;
            vuint32_t PEG:1;
            vuint32_t PECIE:1;
            vuint32_t FERS:1;
            vuint32_t unused_0:2;
            vuint32_t PGM:1;
            vuint32_t PSUS:1;
            vuint32_t ERS:1;
            vuint32_t ESUS:1;
            vuint32_t EHV:1;
        } B;
    } MCR;

    vuint8_t ADR_reserved0[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:1;
            vuint32_t N8KH:2;
            vuint32_t N256K:5;
            vuint32_t N64KH:3;
            vuint32_t N32KH:2;
            vuint32_t N16KH:3;
            vuint32_t N64KM:3;
            vuint32_t N32KM:2;
            vuint32_t N16KM:3;
            vuint32_t N64KL:3;
            vuint32_t N32KL:2;
            vuint32_t N16KL:3;
        } B;
    } MCRE;

    vuint8_t ADR_reserved1[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t TSLOCK:1;
            vuint32_t unused_0:1;
            vuint32_t LOWLOCK:14;
            vuint32_t MIDLOCK:16;
        } B;
    } LOCK0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t HIGHLOCK:16;
        } B;
    } LOCK1;

    union {
        vuint32_t R;
        struct {
            vuint32_t A256KLOCK:32;
        } B;
    } LOCK2;

    union {
        vuint32_t R;
        struct {
            vuint32_t A256KLOCK:32;
        } B;
    } LOCK3;

    vuint8_t ADR_reserved2[24];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:2;
            vuint32_t LOWSEL:14;
            vuint32_t MIDSEL:16;
        } B;
    } SEL0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t HIGHSEL:16;
        } B;
    } SEL1;

    union {
        vuint32_t R;
        struct {
            vuint32_t A256KSEL:32;
        } B;
    } SEL2;

    union {
        vuint32_t R;
        struct {
            vuint32_t A256KSEL:32;
        } B;
    } SEL3;

    vuint8_t ADR_reserved3[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:8;
            vuint32_t PAR:21;
            vuint32_t unused_0:3;
        } B;
    } PAR;

    union {
        vuint32_t R;
        struct {
            vuint32_t SAD:1;
            vuint32_t unused_1:7;
            vuint32_t ADDR:21;
            vuint32_t unused_0:3;
        } B;
    } ADR;

    union {
        vuint32_t R;
        struct {
            vuint32_t UTE:1;
            vuint32_t SBCE:1;
            vuint32_t unused_5:6;
            vuint32_t SBCE1:1;
            vuint32_t unused_4:4;
            vuint32_t CPR:1;
            vuint32_t CPA:1;
            vuint32_t CPE:1;
            vuint32_t unused_3:3;
            vuint32_t VTD:1;
            vuint32_t unused_2:2;
            vuint32_t NAIBP:1;
            vuint32_t AIBPE:1;
            vuint32_t unused_1:1;
            vuint32_t AISUS:1;
            vuint32_t MRE:1;
            vuint32_t MRV:1;
            vuint32_t unused_0:1;
            vuint32_t AIS:1;
            vuint32_t AIE:1;
            vuint32_t AID:1;
        } B;
    } UT0;

    union {
        vuint32_t R;
        struct {
            vuint32_t MISR31:1;
            vuint32_t MISR30:1;
            vuint32_t MISR29:1;
            vuint32_t MISR28:1;
            vuint32_t MISR27:1;
            vuint32_t MISR26:1;
            vuint32_t MISR25:1;
            vuint32_t MISR24:1;
            vuint32_t MISR23:1;
            vuint32_t MISR22:1;
            vuint32_t MISR21:1;
            vuint32_t MISR20:1;
            vuint32_t MISR19:1;
            vuint32_t MISR18:1;
            vuint32_t MISR17:1;
            vuint32_t MISR16:1;
            vuint32_t MISR15:1;
            vuint32_t MISR14:1;
            vuint32_t MISR13:1;
            vuint32_t MISR12:1;
            vuint32_t MISR11:1;
            vuint32_t MISR10:1;
            vuint32_t MISR9:1;
            vuint32_t MISR8:1;
            vuint32_t MISR7:1;
            vuint32_t MISR6:1;
            vuint32_t MISR5:1;
            vuint32_t MISR4:1;
            vuint32_t MISR3:1;
            vuint32_t MISR2:1;
            vuint32_t MISR1:1;
            vuint32_t MISR0:1;
        } B;
    } UM0;

    union {
        vuint32_t R;
        struct {
            vuint32_t MISR63:1;
            vuint32_t MISR62:1;
            vuint32_t MISR61:1;
            vuint32_t MISR60:1;
            vuint32_t MISR59:1;
            vuint32_t MISR58:1;
            vuint32_t MISR57:1;
            vuint32_t MISR56:1;
            vuint32_t MISR55:1;
            vuint32_t MISR54:1;
            vuint32_t MISR53:1;
            vuint32_t MISR52:1;
            vuint32_t MISR51:1;
            vuint32_t MISR50:1;
            vuint32_t MISR49:1;
            vuint32_t MISR48:1;
            vuint32_t MISR47:1;
            vuint32_t MISR46:1;
            vuint32_t MISR45:1;
            vuint32_t MISR44:1;
            vuint32_t MISR43:1;
            vuint32_t MISR42:1;
            vuint32_t MISR41:1;
            vuint32_t MISR40:1;
            vuint32_t MISR39:1;
            vuint32_t MISR38:1;
            vuint32_t MISR37:1;
            vuint32_t MISR36:1;
            vuint32_t MISR35:1;
            vuint32_t MISR34:1;
            vuint32_t MISR33:1;
            vuint32_t MISR32:1;
        } B;
    } UM1;

    union {
        vuint32_t R;
        struct {
            vuint32_t MISR95:1;
            vuint32_t MISR94:1;
            vuint32_t MISR93:1;
            vuint32_t MISR92:1;
            vuint32_t MISR91:1;
            vuint32_t MISR90:1;
            vuint32_t MISR89:1;
            vuint32_t MISR88:1;
            vuint32_t MISR87:1;
            vuint32_t MISR86:1;
            vuint32_t MISR85:1;
            vuint32_t MISR84:1;
            vuint32_t MISR83:1;
            vuint32_t MISR82:1;
            vuint32_t MISR81:1;
            vuint32_t MISR80:1;
            vuint32_t MISR79:1;
            vuint32_t MISR78:1;
            vuint32_t MISR77:1;
            vuint32_t MISR76:1;
            vuint32_t MISR75:1;
            vuint32_t MISR74:1;
            vuint32_t MISR73:1;
            vuint32_t MISR72:1;
            vuint32_t MISR71:1;
            vuint32_t MISR70:1;
            vuint32_t MISR69:1;
            vuint32_t MISR68:1;
            vuint32_t MISR67:1;
            vuint32_t MISR66:1;
            vuint32_t MISR65:1;
            vuint32_t MISR64:1;
        } B;
    } UM2;

    union {
        vuint32_t R;
        struct {
            vuint32_t MISR127:1;
            vuint32_t MISR126:1;
            vuint32_t MISR125:1;
            vuint32_t MISR124:1;
            vuint32_t MISR123:1;
            vuint32_t MISR122:1;
            vuint32_t MISR121:1;
            vuint32_t MISR120:1;
            vuint32_t MISR119:1;
            vuint32_t MISR118:1;
            vuint32_t MISR117:1;
            vuint32_t MISR116:1;
            vuint32_t MISR115:1;
            vuint32_t MISR114:1;
            vuint32_t MISR113:1;
            vuint32_t MISR112:1;
            vuint32_t MISR111:1;
            vuint32_t MISR110:1;
            vuint32_t MISR109:1;
            vuint32_t MISR108:1;
            vuint32_t MISR107:1;
            vuint32_t MISR106:1;
            vuint32_t MISR105:1;
            vuint32_t MISR104:1;
            vuint32_t MISR103:1;
            vuint32_t MISR102:1;
            vuint32_t MISR101:1;
            vuint32_t MISR100:1;
            vuint32_t MISR99:1;
            vuint32_t MISR98:1;
            vuint32_t MISR97:1;
            vuint32_t MISR96:1;
        } B;
    } UM3;

    vuint8_t ADR_reserved4[16];

    union {
        vuint32_t R;
        struct {
            vuint32_t MISR287:1;
            vuint32_t MISR286:1;
            vuint32_t MISR285:1;
            vuint32_t MISR284:1;
            vuint32_t MISR283:1;
            vuint32_t MISR282:1;
            vuint32_t MISR281:1;
            vuint32_t MISR280:1;
            vuint32_t MISR279:1;
            vuint32_t MISR278:1;
            vuint32_t MISR277:1;
            vuint32_t MISR276:1;
            vuint32_t MISR275:1;
            vuint32_t MISR274:1;
            vuint32_t MISR273:1;
            vuint32_t MISR272:1;
            vuint32_t MISR271:1;
            vuint32_t MISR270:1;
            vuint32_t MISR269:1;
            vuint32_t MISR268:1;
            vuint32_t MISR267:1;
            vuint32_t MISR266:1;
            vuint32_t MISR265:1;
            vuint32_t MISR264:1;
            vuint32_t MISR263:1;
            vuint32_t MISR262:1;
            vuint32_t MISR261:1;
            vuint32_t MISR260:1;
            vuint32_t MISR259:1;
            vuint32_t MISR258:1;
            vuint32_t MISR257:1;
            vuint32_t MISR256:1;
        } B;
    } UM8;

    union {
        vuint32_t R;
        struct {
            vuint32_t MISR319:1;
            vuint32_t MISR318:1;
            vuint32_t MISR317:1;
            vuint32_t MISR316:1;
            vuint32_t MISR315:1;
            vuint32_t MISR314:1;
            vuint32_t MISR313:1;
            vuint32_t MISR312:1;
            vuint32_t MISR311:1;
            vuint32_t MISR310:1;
            vuint32_t MISR309:1;
            vuint32_t MISR308:1;
            vuint32_t MISR307:1;
            vuint32_t MISR306:1;
            vuint32_t MISR305:1;
            vuint32_t MISR304:1;
            vuint32_t MISR303:1;
            vuint32_t MISR302:1;
            vuint32_t MISR301:1;
            vuint32_t MISR300:1;
            vuint32_t MISR299:1;
            vuint32_t MISR298:1;
            vuint32_t MISR297:1;
            vuint32_t MISR296:1;
            vuint32_t MISR295:1;
            vuint32_t MISR294:1;
            vuint32_t MISR293:1;
            vuint32_t MISR292:1;
            vuint32_t MISR291:1;
            vuint32_t MISR290:1;
            vuint32_t MISR289:1;
            vuint32_t MISR288:1;
        } B;
    } UM9;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:2;
            vuint32_t LOWOPP:14;
            vuint32_t MIDOPP:16;
        } B;
    } OPP0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t HIGHOPP:16;
        } B;
    } OPP1;

    union {
        vuint32_t R;
        struct {
            vuint32_t A256KOPP:32;
        } B;
    } OPP2;

    union {
        vuint32_t R;
        struct {
            vuint32_t A256KOPP:32;
        } B;
    } OPP3;

    union {
        vuint32_t R;
        struct {
            vuint32_t PWD:32;
        } B;
    } TMD;

    vuint8_t ADR_reserved5[108];

    union {
        vuint32_t R;
        struct {
            vuint32_t LOWELOCK:16;
            vuint32_t MIDELOCK:16;
        } B;
    } ELOCK0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t HIGHELOCK:16;
        } B;
    } ELOCK1;

    union {
        vuint32_t R;
        struct {
            vuint32_t A256KELOCK:32;
        } B;
    } ELOCK2;

    union {
        vuint32_t R;
        struct {
            vuint32_t A256KELOCK:32;
        } B;
    } ELOCK3;

    union {
        vuint32_t R;
        struct {
            vuint32_t LOWPLOCK:16;
            vuint32_t MIDPLOCK:16;
        } B;
    } PLOCK0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t HIGHPLOCK:16;
        } B;
    } PLOCK1;

    union {
        vuint32_t R;
        struct {
            vuint32_t A256KPLOCK:32;
        } B;
    } PLOCK2;

    union {
        vuint32_t R;
        struct {
            vuint32_t A256KPLOCK:32;
        } B;
    } PLOCK3;

};

/**************************************************************************/
/*                 Module: IIC            */
/**************************************************************************/
struct IIC_tag {
    union {
        vuint8_t R;
        struct {
            vuint8_t ADR:7;
            vuint8_t unused_0:1;
        } B;
    } IBAD;

    union {
        vuint8_t R;
        struct {
            vuint8_t IBC:8;
        } B;
    } IBFD;

    union {
        vuint8_t R;
        struct {
            vuint8_t MDIS:1;
            vuint8_t IBIE:1;
            vuint8_t MSSL:1;
            vuint8_t TXRX:1;
            vuint8_t NOACK:1;
            vuint8_t RSTA:1;
            vuint8_t DMAEN:1;
            vuint8_t unused_0:1;
        } B;
    } IBCR;

    union {
        vuint8_t R;
        struct {
            vuint8_t TCF:1;
            vuint8_t IAAS:1;
            vuint8_t IBB:1;
            vuint8_t IBAL:1;
            vuint8_t unused_0:1;
            vuint8_t SRW:1;
            vuint8_t IBIF:1;
            vuint8_t RXAK:1;
        } B;
    } IBSR;

    union {
        vuint8_t R;
        struct {
            vuint8_t DATA:8;
        } B;
    } IBDR;

    union {
        vuint8_t R;
        struct {
            vuint8_t BIIE:1;
            vuint8_t BYTERXIE:1;
            vuint8_t unused_0:6;
        } B;
    } IBIC;

    union {
        vuint8_t R;
        struct {
            vuint8_t unused_0:6;
            vuint8_t IPG_DEBUG_HALTED:1;
            vuint8_t IPG_DEBUG_EN:1;
        } B;
    } IBDBG;

};

/**************************************************************************/
/*                 Module: IMA            */
/**************************************************************************/
struct IMA_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:31;
            vuint32_t READ:1;
        } B;
    } CTRL;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:31;
            vuint32_t EN:1;
        } B;
    } ENABLE;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:23;
            vuint32_t WRITE_LOCK:1;
            vuint32_t unused_0:7;
            vuint32_t READ_LOCK:1;
        } B;
    } STATUS;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:3;
            vuint32_t ROW_SLCT:13;
            vuint32_t unused_0:10;
            vuint32_t ARRAY_SLCT:6;
        } B;
    } SLCT;

    union {
        vuint32_t R;
        struct {
            vuint32_t WRITE_KEY:32;
        } B;
    } WRITE_UNLOCK;

    union {
        vuint32_t R;
        struct {
            vuint32_t READ_KEY:32;
        } B;
    } READ_UNLOCK;

    vuint8_t ADR_reserved0[20];

    union {
        vuint32_t R;
        struct {
            vuint32_t WRITE:32;
        } B;
    } WRITE_DATA_4;

    union {
        vuint32_t R;
        struct {
            vuint32_t WRITE:32;
        } B;
    } WRITE_DATA_3;

    union {
        vuint32_t R;
        struct {
            vuint32_t WRITE:32;
        } B;
    } WRITE_DATA_2;

    union {
        vuint32_t R;
        struct {
            vuint32_t WRITE:32;
        } B;
    } WRITE_DATA_1;

    union {
        vuint32_t R;
        struct {
            vuint32_t WRITE:32;
        } B;
    } WRITE_DATA_0;

    vuint8_t ADR_reserved1[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t READ:32;
        } B;
    } READ_DATA_4;

    union {
        vuint32_t R;
        struct {
            vuint32_t READ:32;
        } B;
    } READ_DATA_3;

    union {
        vuint32_t R;
        struct {
            vuint32_t READ:32;
        } B;
    } READ_DATA_2;

    union {
        vuint32_t R;
        struct {
            vuint32_t READ:32;
        } B;
    } READ_DATA_1;

    union {
        vuint32_t R;
        struct {
            vuint32_t READ:32;
        } B;
    } READ_DATA_0;

};

/**************************************************************************/
/*                 Module: INTC            */
/**************************************************************************/
struct INTC_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:31;
            vuint32_t HVEN0:1;
        } B;
    } BCR;

    vuint8_t ADR_reserved0[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:26;
            vuint32_t PRI:6;
        } B;
    } CPR[1];

    vuint8_t ADR_reserved1[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t VTBA:20;
            vuint32_t INTVEC:10;
            vuint32_t unused_0:2;
        } B;
    } IACKR[1];

    vuint8_t ADR_reserved2[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t EOI:32;
        } B;
    } EOIR[1];

    vuint8_t ADR_reserved3[12];

    union {
        vuint8_t R;
        struct {
            vuint8_t unused_0:6;
            vuint8_t SET:1;
            vuint8_t CLR:1;
        } B;
    } SSCIR[32];

    union {
        struct {
            union {
                vuint16_t R;
                union {
                    struct {
                        vuint16_t PRC_SEL:4;
                        vuint16_t unused_0:6;
                        vuint16_t PRI:6;
                    } B;
                    struct {
                        vuint16_t PRC_SEL0:1;
                        vuint16_t unused_0:9;
                        vuint16_t PRI:6;
                    } B_PRC_SEL_BITS;
                };
            } PSR_NOSWT[32];
            union {
                vuint16_t R;
                union {
                    struct {
                        vuint16_t PRC_SEL:4;
                        vuint16_t unused_1:3;
                        vuint16_t SWT:1;
                        vuint16_t unused_0:2;
                        vuint16_t PRI:6;
                    } B;
                    struct {
                        vuint16_t PRC_SEL0:1;
                        vuint16_t unused_1:6;
                        vuint16_t SWT:1;
                        vuint16_t unused_0:2;
                        vuint16_t PRI:6;
                    } B_PRC_SEL_BITS;
                };
            } PSR_SWT[992];
        };
        struct {
            vuint16_t R;
            
        } PSR[1024];
    };            

};

/**************************************************************************/
/*                 Module: JDC            */
/**************************************************************************/
struct JDC_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:15;
            vuint32_t JIN_IEN:1;
            vuint32_t unused_0:15;
            vuint32_t JOUT_IEN:1;
        } B;
    } MCR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:13;
            vuint32_t JIN_RDY:1;
            vuint32_t unused_2:1;
            vuint32_t JIN_INT:1;
            vuint32_t unused_1:13;
            vuint32_t JOUT_RDY:1;
            vuint32_t unused_0:1;
            vuint32_t JOUT_INT:1;
        } B;
    } MSR;

    union {
        vuint32_t R;
        struct {
            vuint32_t DATA:32;
        } B;
    } JOUT_IPS;

    union {
        vuint32_t R;
        struct {
            vuint32_t DATA:32;
        } B;
    } JIN_IPS;

};

/**************************************************************************/
/*                 Module: JTAGM            */
/**************************************************************************/
struct JTAGM_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t SWRESET:1;
            vuint32_t EVTO0_SENSE:2;
            vuint32_t EVTO1_SENSE:2;
            vuint32_t EVTO_IE:1;
            vuint32_t EVTI0_ASSERT:1;
            vuint32_t EVTI1_ASSERT:1;
            vuint32_t unused_1:10;
            vuint32_t INTER_JTAG_FRAME_TIMER:6;
            vuint32_t unused_0:1;
            vuint32_t SIE:1;
            vuint32_t IIE:1;
            vuint32_t TCKSEL:3;
            vuint32_t JTAGM_JCOMP:1;
            vuint32_t DTM:1;
        } B;
    } MCR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:8;
            vuint32_t DCI_STATUS:8;
            vuint32_t EVTO0_EDGE:1;
            vuint32_t EVTO1_EDGE:1;
            vuint32_t SPU_INT_CLR:1;
            vuint32_t SPU_INT:1;
            vuint32_t unused_1:1;
            vuint32_t NEXUS_ERR:1;
            vuint32_t IDLE:1;
            vuint32_t NR:1;
            vuint32_t EVTO0_CLR:1;
            vuint32_t EVTO1_CLR:1;
            vuint32_t unused_0:6;
        } B;
    } SR;

    union {
        vuint32_t R;
        struct {
            vuint32_t TMS_HIGH:32;
        } B;
    } DOR0;

    union {
        vuint32_t R;
        struct {
            vuint32_t TMS_LOW:28;
            vuint32_t unused_0:4;
        } B;
    } DOR1;

    union {
        vuint32_t R;
        struct {
            vuint32_t TDI_HIGH:32;
        } B;
    } DOR2;

    union {
        vuint32_t R;
        struct {
            vuint32_t TDI_LOW:28;
            vuint32_t unused_0:3;
            vuint32_t SEND:1;
        } B;
    } DOR3;

    vuint8_t ADR_reserved0[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t TDO_LOW:32;
        } B;
    } DIR0;

    union {
        vuint32_t R;
        struct {
            vuint32_t TDO_HIGH:28;
            vuint32_t unused_0:4;
        } B;
    } DIR1;

};

/**************************************************************************/
/*                 Module: LINFLEXD            */
/**************************************************************************/
struct LINFLEXD_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:16;
            vuint32_t CCD:1;
            vuint32_t CFD:1;
            vuint32_t LASE:1;
            vuint32_t AUTOWU:1;
            vuint32_t MBL:4;
            vuint32_t BF:1;
            vuint32_t unused_0:1;
            vuint32_t LBKM:1;
            vuint32_t MME:1;
            vuint32_t SSBL:1;
            vuint32_t RBLM:1;
            vuint32_t SLEEP:1;
            vuint32_t INIT:1;
        } B;
    } LINCR1;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:16;
            vuint32_t SZIE:1;
            vuint32_t OCIE:1;
            vuint32_t BEIE:1;
            vuint32_t CEIE:1;
            vuint32_t HEIE:1;
            vuint32_t unused_0:2;
            vuint32_t FEIE:1;
            vuint32_t BOIE:1;
            vuint32_t LSIE:1;
            vuint32_t WUIE:1;
            vuint32_t DBFIE:1;
            vuint32_t DBEIE_TOIE:1;
            vuint32_t DRIE:1;
            vuint32_t DTIE:1;
            vuint32_t HRIE:1;
        } B;
    } LINIER;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:12;
            vuint32_t AUTOSYNC_COMP:1;
            vuint32_t RDC:3;
            vuint32_t LINS:4;
            vuint32_t unused_0:2;
            vuint32_t RMB:1;
            vuint32_t DRBNE:1;
            vuint32_t RXBUSY:1;
            vuint32_t RDI:1;
            vuint32_t WUF:1;
            vuint32_t DBFF:1;
            vuint32_t DBEF:1;
            vuint32_t DRF:1;
            vuint32_t DTF:1;
            vuint32_t HRF:1;
        } B;
    } LINSR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:16;
            vuint32_t SZF:1;
            vuint32_t OCF:1;
            vuint32_t BEF:1;
            vuint32_t CEF:1;
            vuint32_t SFEF:1;
            vuint32_t SDEF:1;
            vuint32_t IDPEF:1;
            vuint32_t FEF:1;
            vuint32_t BOF:1;
            vuint32_t unused_0:6;
            vuint32_t NF:1;
        } B;
    } LINESR;

    union {
        vuint32_t R;
        struct {
            vuint32_t MIS:1;
            vuint32_t CSP:3;
            vuint32_t OSR:4;
            vuint32_t ROSE:1;
            vuint32_t NEF:3;
            vuint32_t DTU_PCETX:1;
            vuint32_t SBUR:2;
            vuint32_t WLS:1;
            vuint32_t TDFL_TFC:3;
            vuint32_t RDFL_RFC:3;
            vuint32_t RFBM:1;
            vuint32_t TFBM:1;
            vuint32_t WL1:1;
            vuint32_t PC1:1;
            vuint32_t RXEN:1;
            vuint32_t TXEN:1;
            vuint32_t PC0:1;
            vuint32_t PCE:1;
            vuint32_t WL0:1;
            vuint32_t UART:1;
        } B;
    } UARTCR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t SZF:1;
            vuint32_t OCF:1;
            vuint32_t PE:4;
            vuint32_t RMB:1;
            vuint32_t FEF:1;
            vuint32_t BOF:1;
            vuint32_t RDI:1;
            vuint32_t WUF:1;
            vuint32_t RFNE:1;
            vuint32_t TO:1;
            vuint32_t DRF_RFE:1;
            vuint32_t DTF_TFF:1;
            vuint32_t NF:1;
        } B;
    } UARTSR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:21;
            vuint32_t MODE:1;
            vuint32_t IOT:1;
            vuint32_t TOCE:1;
            vuint32_t CNT:8;
        } B;
    } LINTCSR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t OC2:8;
            vuint32_t OC1:8;
        } B;
    } LINOCR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:20;
            vuint32_t RTO:4;
            vuint32_t unused_0:1;
            vuint32_t HTO:7;
        } B;
    } LINTOCR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:28;
            vuint32_t FBR:4;
        } B;
    } LINFBRR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:12;
            vuint32_t IBR:20;
        } B;
    } LINIBRR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:24;
            vuint32_t CF:8;
        } B;
    } LINCFR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:16;
            vuint32_t TBDE:1;
            vuint32_t IOBE:1;
            vuint32_t IOPE:1;
            vuint32_t WURQ:1;
            vuint32_t DDRQ:1;
            vuint32_t DTRQ:1;
            vuint32_t ABRQ:1;
            vuint32_t HTRQ:1;
            vuint32_t unused_0:8;
        } B;
    } LINCR2;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:16;
            vuint32_t DFL:6;
            vuint32_t DIR:1;
            vuint32_t CCS:1;
            vuint32_t unused_0:2;
            vuint32_t ID:6;
        } B;
    } BIDR;

    union {
        vuint32_t R;
        struct {
            vuint32_t DATA3:8;
            vuint32_t DATA2:8;
            vuint32_t DATA1:8;
            vuint32_t DATA0:8;
        } B;
    } BDRL;

    union {
        vuint32_t R;
        struct {
            vuint32_t DATA7:8;
            vuint32_t DATA6:8;
            vuint32_t DATA5:8;
            vuint32_t DATA4:8;
        } B;
    } BDRM;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t FACT:16;
        } B;
    } IFER;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:27;
            vuint32_t IFMI:5;
        } B;
    } IFMI;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:24;
            vuint32_t IFM:8;
        } B;
    } IFMR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:16;
            vuint32_t DFL:6;
            vuint32_t DIR:1;
            vuint32_t CCS:1;
            vuint32_t unused_0:2;
            vuint32_t ID:6;
        } B;
    } IFCR[16];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:26;
            vuint32_t TDFBM:1;
            vuint32_t RDFBM:1;
            vuint32_t TDLIS:1;
            vuint32_t RDLIS:1;
            vuint32_t STOP:1;
            vuint32_t SR:1;
        } B;
    } GCR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:20;
            vuint32_t PTO:12;
        } B;
    } UARTPTO;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:20;
            vuint32_t CTO:12;
        } B;
    } UARTCTO;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t DTE:16;
        } B;
    } DMATXE;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t DRE:16;
        } B;
    } DMARXE;

};

/**************************************************************************/
/*                 Module: MC_CGM            */
/**************************************************************************/
struct MC_CGM_tag {
    vuint8_t ADR_reserved0[256];

    union {
        vuint8_t R;
        struct {
            vuint8_t SDUR:8;
        } B;
    } PCS_SDUR;

    vuint8_t ADR_reserved1[3];

    union {
        vuint32_t R;
        struct {
            vuint32_t INIT:16;
            vuint32_t unused_0:8;
            vuint32_t RATE:8;
        } B;
    } PCS_DIVC1;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:12;
            vuint32_t DIVE:20;
        } B;
    } PCS_DIVE1;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:12;
            vuint32_t DIVS:20;
        } B;
    } PCS_DIVS1;

    union {
        vuint32_t R;
        struct {
            vuint32_t INIT:16;
            vuint32_t unused_0:8;
            vuint32_t RATE:8;
        } B;
    } PCS_DIVC2;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:12;
            vuint32_t DIVE:20;
        } B;
    } PCS_DIVE2;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:12;
            vuint32_t DIVS:20;
        } B;
    } PCS_DIVS2;

    vuint8_t ADR_reserved2[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t INIT:16;
            vuint32_t unused_0:8;
            vuint32_t RATE:8;
        } B;
    } PCS_DIVC4;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:12;
            vuint32_t DIVE:20;
        } B;
    } PCS_DIVE4;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:12;
            vuint32_t DIVS:20;
        } B;
    } PCS_DIVS4;

    vuint8_t ADR_reserved3[156];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:31;
            vuint32_t SYS_DIV_RATIO_CHNG:1;
        } B;
    } SC_DIV_RC;

    union {
        vuint32_t R;
        struct {
            vuint32_t SYS_UPD_TYPE:1;
            vuint32_t unused_0:31;
        } B;
    } DIV_UPD_TYPE;

    union {
        vuint32_t R;
        struct {
            vuint32_t DIV_UPD_TRIGGER:32;
        } B;
    } DIV_UPD_TRIG;

    union {
        vuint32_t R;
        struct {
            vuint32_t SYS_UPD_STAT:1;
            vuint32_t unused_0:31;
        } B;
    } DIV_UPD_STAT;

    vuint8_t ADR_reserved4[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:4;
            vuint32_t SELSTAT:4;
            vuint32_t unused_1:4;
            vuint32_t SWTRG:3;
            vuint32_t SWIP:1;
            vuint32_t unused_0:16;
        } B;
    } SC_SS;

    union {
        vuint32_t R;
        struct {
            vuint32_t DE:1;
            vuint32_t unused_1:9;
            vuint32_t DIV:6;
            vuint32_t unused_0:16;
        } B;
    } SC_DC0;

    union {
        vuint32_t R;
        struct {
            vuint32_t DE:1;
            vuint32_t unused_1:9;
            vuint32_t DIV:6;
            vuint32_t unused_0:16;
        } B;
    } SC_DC1;

    union {
        vuint32_t R;
        struct {
            vuint32_t DE:1;
            vuint32_t unused_1:9;
            vuint32_t DIV:6;
            vuint32_t unused_0:16;
        } B;
    } SC_DC2;

    union {
        vuint32_t R;
        struct {
            vuint32_t DE:1;
            vuint32_t unused_1:9;
            vuint32_t DIV:6;
            vuint32_t unused_0:16;
        } B;
    } SC_DC3;

    union {
        vuint32_t R;
        struct {
            vuint32_t DE:1;
            vuint32_t unused_1:9;
            vuint32_t DIV:6;
            vuint32_t unused_0:16;
        } B;
    } SC_DC4;

    vuint8_t ADR_reserved5[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t SELCTL:4;
            vuint32_t unused_0:24;
        } B;
    } AC0_SC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t SELSTAT:4;
            vuint32_t unused_0:24;
        } B;
    } AC0_SS;

    union {
        vuint32_t R;
        struct {
            vuint32_t DE:1;
            vuint32_t unused_1:11;
            vuint32_t DIV:4;
            vuint32_t unused_0:16;
        } B;
    } AC0_DC0;

    union {
        vuint32_t R;
        struct {
            vuint32_t DE:1;
            vuint32_t unused_1:8;
            vuint32_t DIV:7;
            vuint32_t unused_0:16;
        } B;
    } AC0_DC1;

    vuint8_t ADR_reserved6[80];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t SELCTL:4;
            vuint32_t unused_0:24;
        } B;
    } AC3_SC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t SELSTAT:4;
            vuint32_t unused_0:24;
        } B;
    } AC3_SS;

    vuint8_t ADR_reserved7[24];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t SELCTL:4;
            vuint32_t unused_0:24;
        } B;
    } AC4_SC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t SELSTAT:4;
            vuint32_t unused_0:24;
        } B;
    } AC4_SS;

    vuint8_t ADR_reserved8[56];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t SELCTL:4;
            vuint32_t unused_0:24;
        } B;
    } AC6_SC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t SELSTAT:4;
            vuint32_t unused_0:24;
        } B;
    } AC6_SS;

    union {
        vuint32_t R;
        struct {
            vuint32_t DE:1;
            vuint32_t unused_1:6;
            vuint32_t DIV:9;
            vuint32_t unused_0:16;
        } B;
    } AC6_DC0;

    vuint8_t ADR_reserved9[52];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t SELCTL:4;
            vuint32_t unused_0:24;
        } B;
    } AC8_SC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t SELSTAT:4;
            vuint32_t unused_0:24;
        } B;
    } AC8_SS;

    union {
        vuint32_t R;
        struct {
            vuint32_t DE:1;
            vuint32_t unused_1:9;
            vuint32_t DIV:6;
            vuint32_t unused_0:16;
        } B;
    } AC8_DC0;

    vuint8_t ADR_reserved10[20];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t SELCTL:4;
            vuint32_t unused_0:24;
        } B;
    } AC9_SC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t SELSTAT:4;
            vuint32_t unused_0:24;
        } B;
    } AC9_SS;

    union {
        vuint32_t R;
        struct {
            vuint32_t DE:1;
            vuint32_t unused_1:9;
            vuint32_t DIV:6;
            vuint32_t unused_0:16;
        } B;
    } AC9_DC0;

    vuint8_t ADR_reserved11[52];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t SELCTL:4;
            vuint32_t unused_0:24;
        } B;
    } AC11_SC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t SELSTAT:4;
            vuint32_t unused_0:24;
        } B;
    } AC11_SS;

    union {
        vuint32_t R;
        struct {
            vuint32_t DE:1;
            vuint32_t unused_1:9;
            vuint32_t DIV:6;
            vuint32_t unused_0:16;
        } B;
    } AC11_DC0;

    vuint8_t ADR_reserved12[20];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t SELCTL:4;
            vuint32_t unused_0:24;
        } B;
    } AC12_SC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t SELSTAT:4;
            vuint32_t unused_0:24;
        } B;
    } AC12_SS;

    union {
        vuint32_t R;
        struct {
            vuint32_t DE:1;
            vuint32_t unused_1:6;
            vuint32_t DIV:9;
            vuint32_t unused_0:14;
            vuint32_t DIV_FMT:2;
        } B;
    } AC12_DC0;

    union {
        vuint32_t R;
        struct {
            vuint32_t DE:1;
            vuint32_t unused_1:11;
            vuint32_t DIV:4;
            vuint32_t unused_0:16;
        } B;
    } AC12_DC1;

    union {
        vuint32_t R;
        struct {
            vuint32_t DE:1;
            vuint32_t unused_1:11;
            vuint32_t DIV:4;
            vuint32_t unused_0:16;
        } B;
    } AC12_DC2;

};

/**************************************************************************/
/*                 Module: MC_ME            */
/**************************************************************************/
struct MC_ME_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t S_CURRENT_MODE:4;
            vuint32_t S_MTRANS:1;
            vuint32_t unused_3:3;
            vuint32_t S_PDO:1;
            vuint32_t unused_2:2;
            vuint32_t S_MVR:1;
            vuint32_t unused_1:2;
            vuint32_t S_FLA:2;
            vuint32_t unused_0:8;
            vuint32_t S_PLL1:1;
            vuint32_t S_PLL0:1;
            vuint32_t S_XOSC:1;
            vuint32_t S_IRC:1;
            vuint32_t S_SYSCLK:4;
        } B;
    } GS;

    union {
        vuint32_t R;
        struct {
            vuint32_t TARGET_MODE:4;
            vuint32_t unused_0:12;
            vuint32_t KEY:16;
        } B;
    } MCTL;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:16;
            vuint32_t RESET_DEST:1;
            vuint32_t unused_2:1;
            vuint32_t STANDBY0:1;
            vuint32_t unused_1:2;
            vuint32_t STOP0:1;
            vuint32_t unused_0:1;
            vuint32_t HALT0:1;
            vuint32_t RUN3:1;
            vuint32_t RUN2:1;
            vuint32_t RUN1:1;
            vuint32_t RUN0:1;
            vuint32_t DRUN:1;
            vuint32_t SAFE:1;
            vuint32_t TEST:1;
            vuint32_t RESET_FUNC:1;
        } B;
    } ME;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:26;
            vuint32_t I_ICONF_CC:1;
            vuint32_t I_ICONF_CU:1;
            vuint32_t I_ICONF:1;
            vuint32_t I_IMODE:1;
            vuint32_t I_SAFE:1;
            vuint32_t I_MTC:1;
        } B;
    } IS;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:26;
            vuint32_t M_ICONF_CC:1;
            vuint32_t M_ICONF_CU:1;
            vuint32_t M_ICONF:1;
            vuint32_t M_IMODE:1;
            vuint32_t M_SAFE:1;
            vuint32_t M_MTC:1;
        } B;
    } IM;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:26;
            vuint32_t S_MRIG:1;
            vuint32_t S_MTI:1;
            vuint32_t S_MRI:1;
            vuint32_t S_DMA:1;
            vuint32_t S_NMA:1;
            vuint32_t S_SEA:1;
        } B;
    } IMTS;

    union {
        vuint32_t R;
        struct {
            vuint32_t PREVIOUS_MODE:4;
            vuint32_t unused_2:4;
            vuint32_t MPH_BUSY:1;
            vuint32_t unused_1:2;
            vuint32_t PMC_PROG:1;
            vuint32_t DBG_MODE:1;
            vuint32_t CCKL_PROG:1;
            vuint32_t PCS_PROG:1;
            vuint32_t SMR:1;
            vuint32_t CDP_PRPH_0_255:1;
            vuint32_t VREG_CSRC_SC:1;
            vuint32_t CSRC_CSRC_SC:1;
            vuint32_t IRC_SC:1;
            vuint32_t SCSRC_SC:1;
            vuint32_t SYSCLK_SW:1;
            vuint32_t unused_0:1;
            vuint32_t FLASH_SC:1;
            vuint32_t CDP_PRPH_224_255:1;
            vuint32_t CDP_PRPH_192_223:1;
            vuint32_t CDP_PRPH_160_191:1;
            vuint32_t CDP_PRPH_128_159:1;
            vuint32_t CDP_PRPH_96_127:1;
            vuint32_t CDP_PRPH_64_95:1;
            vuint32_t CDP_PRPH_32_63:1;
            vuint32_t CDP_PRPH_0_31:1;
        } B;
    } DMTS;

    vuint8_t ADR_reserved0[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:8;
            vuint32_t PDO:1;
            vuint32_t unused_2:2;
            vuint32_t MVRON:1;
            vuint32_t unused_1:2;
            vuint32_t FLAON:2;
            vuint32_t unused_0:8;
            vuint32_t PLL1ON:1;
            vuint32_t PLL0ON:1;
            vuint32_t XOSCON:1;
            vuint32_t IRCON:1;
            vuint32_t SYSCLK:4;
        } B;
    } RESET_MC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_4:1;
            vuint32_t PWRLVL:3;
            vuint32_t unused_3:4;
            vuint32_t PDO:1;
            vuint32_t unused_2:2;
            vuint32_t MVRON:1;
            vuint32_t unused_1:2;
            vuint32_t FLAON:2;
            vuint32_t unused_0:8;
            vuint32_t PLL1ON:1;
            vuint32_t PLL0ON:1;
            vuint32_t XOSCON:1;
            vuint32_t IRCON:1;
            vuint32_t SYSCLK:4;
        } B;
    } TEST_MC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_4:1;
            vuint32_t PWRLVL:3;
            vuint32_t unused_3:4;
            vuint32_t PDO:1;
            vuint32_t unused_2:2;
            vuint32_t MVRON:1;
            vuint32_t unused_1:2;
            vuint32_t FLAON:2;
            vuint32_t unused_0:8;
            vuint32_t PLL1ON:1;
            vuint32_t PLL0ON:1;
            vuint32_t XOSCON:1;
            vuint32_t IRCON:1;
            vuint32_t SYSCLK:4;
        } B;
    } SAFE_MC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_4:1;
            vuint32_t PWRLVL:3;
            vuint32_t unused_3:4;
            vuint32_t PDO:1;
            vuint32_t unused_2:2;
            vuint32_t MVRON:1;
            vuint32_t unused_1:2;
            vuint32_t FLAON:2;
            vuint32_t unused_0:8;
            vuint32_t PLL1ON:1;
            vuint32_t PLL0ON:1;
            vuint32_t XOSCON:1;
            vuint32_t IRCON:1;
            vuint32_t SYSCLK:4;
        } B;
    } DRUN_MC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_4:1;
            vuint32_t PWRLVL:3;
            vuint32_t unused_3:4;
            vuint32_t PDO:1;
            vuint32_t unused_2:2;
            vuint32_t MVRON:1;
            vuint32_t unused_1:2;
            vuint32_t FLAON:2;
            vuint32_t unused_0:8;
            vuint32_t PLL1ON:1;
            vuint32_t PLL0ON:1;
            vuint32_t XOSCON:1;
            vuint32_t IRCON:1;
            vuint32_t SYSCLK:4;
        } B;
    } RUN_MC[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:8;
            vuint32_t PDO:1;
            vuint32_t unused_2:2;
            vuint32_t MVRON:1;
            vuint32_t unused_1:2;
            vuint32_t FLAON:2;
            vuint32_t unused_0:8;
            vuint32_t PLL1ON:1;
            vuint32_t PLL0ON:1;
            vuint32_t XOSCON:1;
            vuint32_t IRCON:1;
            vuint32_t SYSCLK:4;
        } B;
    } HALT0_MC;

    vuint8_t ADR_reserved1[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:8;
            vuint32_t PDO:1;
            vuint32_t unused_2:2;
            vuint32_t MVRON:1;
            vuint32_t unused_1:2;
            vuint32_t FLAON:2;
            vuint32_t unused_0:8;
            vuint32_t PLL1ON:1;
            vuint32_t PLL0ON:1;
            vuint32_t XOSCON:1;
            vuint32_t IRCON:1;
            vuint32_t SYSCLK:4;
        } B;
    } STOP0_MC;

    vuint8_t ADR_reserved2[8];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:8;
            vuint32_t PDO:1;
            vuint32_t unused_2:2;
            vuint32_t MVRON:1;
            vuint32_t unused_1:2;
            vuint32_t FLAON:2;
            vuint32_t unused_0:8;
            vuint32_t PLL1ON:1;
            vuint32_t PLL0ON:1;
            vuint32_t XOSCON:1;
            vuint32_t IRCON:1;
            vuint32_t SYSCLK:4;
        } B;
    } STANDBY0_MC;

    vuint8_t ADR_reserved3[8];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:1;
            vuint32_t S_PIT_0:1;
            vuint32_t unused_1:14;
            vuint32_t S_SIUL:1;
            vuint32_t unused_0:15;
        } B;
    } PS0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:1;
            vuint32_t S_CCCU:1;
            vuint32_t unused_2:23;
            vuint32_t S_CRC_0:1;
            vuint32_t unused_1:1;
            vuint32_t S_DMAMUX_0:1;
            vuint32_t unused_0:4;
        } B;
    } PS1;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_5:3;
            vuint32_t S_LINFLEXD_0:1;
            vuint32_t S_LINFLEXD_2:1;
            vuint32_t unused_4:3;
            vuint32_t S_LINFLEXD_10:1;
            vuint32_t unused_3:12;
            vuint32_t S_CANSUBSYS0_CAN_RAM_CTR:1;
            vuint32_t unused_2:1;
            vuint32_t S_CANSUBSYS0_MCAN_0:1;
            vuint32_t unused_1:2;
            vuint32_t S_CANSUBSYS0_MCAN_1:1;
            vuint32_t S_CANSUBSYS0_MCAN_2:1;
            vuint32_t S_CANSUBSYS0_MCAN_3:1;
            vuint32_t unused_0:3;
        } B;
    } PS2;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:15;
            vuint32_t S_SAR_ADC_B:1;
            vuint32_t unused_2:10;
            vuint32_t S_IIC_0:1;
            vuint32_t unused_1:1;
            vuint32_t S_DSPI_0:1;
            vuint32_t S_DSPI_2:1;
            vuint32_t unused_0:2;
        } B;
    } PS3;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:30;
            vuint32_t S_SAR_ADC_SEQ_B:1;
            vuint32_t unused_0:1;
        } B;
    } PS4;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:25;
            vuint32_t S_CRC_1:1;
            vuint32_t unused_0:6;
        } B;
    } PS5;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_5:3;
            vuint32_t S_LINFLEXD_1:1;
            vuint32_t unused_4:2;
            vuint32_t S_LINFLEXD_7:1;
            vuint32_t unused_3:3;
            vuint32_t S_LINFLEXD_15:1;
            vuint32_t unused_2:10;
            vuint32_t S_CANSUBSYS1_CAN_RAM_CTR:1;
            vuint32_t unused_1:3;
            vuint32_t S_CANSUBSYS1_MCAN_1:1;
            vuint32_t S_CANSUBSYS1_MCAN_2:1;
            vuint32_t S_CANSUBSYS1_MCAN_3:1;
            vuint32_t unused_0:4;
        } B;
    } PS6;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:12;
            vuint32_t S_BODY_CTU_0:1;
            vuint32_t unused_2:1;
            vuint32_t S_EMIOS_0:1;
            vuint32_t unused_1:13;
            vuint32_t S_DSPI_1:1;
            vuint32_t S_DSPI_3:1;
            vuint32_t unused_0:2;
        } B;
    } PS7;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:24;
            vuint32_t RUN3:1;
            vuint32_t RUN2:1;
            vuint32_t RUN1:1;
            vuint32_t RUN0:1;
            vuint32_t DRUN:1;
            vuint32_t SAFE:1;
            vuint32_t TEST:1;
            vuint32_t RESET:1;
        } B;
    } RUN_PC[8];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:18;
            vuint32_t STANDBY0:1;
            vuint32_t unused_2:2;
            vuint32_t STOP0:1;
            vuint32_t unused_1:1;
            vuint32_t HALT0:1;
            vuint32_t unused_0:8;
        } B;
    } LP_PC[8];

    union {
        vuint8_t R;
        struct {
            vuint8_t unused_0:2;
            vuint8_t LP_CFG:3;
            vuint8_t RUN_CFG:3;
        } B;
    } PCTL[256];

    vuint8_t ADR_reserved4[4];

    union {
        vuint16_t R;
        struct {
            vuint16_t unused_2:2;
            vuint16_t STANDBY0:1;
            vuint16_t unused_1:2;
            vuint16_t STOP0:1;
            vuint16_t unused_0:1;
            vuint16_t HALT0:1;
            vuint16_t RUN3:1;
            vuint16_t RUN2:1;
            vuint16_t RUN1:1;
            vuint16_t RUN0:1;
            vuint16_t DRUN:1;
            vuint16_t SAFE:1;
            vuint16_t TEST:1;
            vuint16_t RESET:1;
        } B;
    } CCTL0;

    vuint8_t ADR_reserved5[26];

    union {
        vuint32_t R;
        struct {
            vuint32_t ADDR:30;
            vuint32_t unused_0:1;
            vuint32_t RMC:1;
        } B;
    } CADDR0;

};

/**************************************************************************/
/*                 Module: MC_PCU            */
/**************************************************************************/
struct MC_PCU_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:18;
            vuint32_t STBY0:1;
            vuint32_t unused_1:2;
            vuint32_t STOP:1;
            vuint32_t unused_0:1;
            vuint32_t HALT:1;
            vuint32_t RUN3:1;
            vuint32_t RUN2:1;
            vuint32_t RUN1:1;
            vuint32_t RUN0:1;
            vuint32_t DRUN:1;
            vuint32_t SAFE:1;
            vuint32_t TEST:1;
            vuint32_t RST:1;
        } B;
    } PCONF0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:18;
            vuint32_t STBY0:1;
            vuint32_t unused_1:2;
            vuint32_t STOP:1;
            vuint32_t unused_0:1;
            vuint32_t HALT:1;
            vuint32_t RUN3:1;
            vuint32_t RUN2:1;
            vuint32_t RUN1:1;
            vuint32_t RUN0:1;
            vuint32_t DRUN:1;
            vuint32_t SAFE:1;
            vuint32_t TEST:1;
            vuint32_t RST:1;
        } B;
    } PCONF1;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:18;
            vuint32_t STBY0:1;
            vuint32_t unused_1:2;
            vuint32_t STOP:1;
            vuint32_t unused_0:1;
            vuint32_t HALT:1;
            vuint32_t RUN3:1;
            vuint32_t RUN2:1;
            vuint32_t RUN1:1;
            vuint32_t RUN0:1;
            vuint32_t DRUN:1;
            vuint32_t SAFE:1;
            vuint32_t TEST:1;
            vuint32_t RST:1;
        } B;
    } PCONF2;

    vuint8_t ADR_reserved0[52];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:29;
            vuint32_t PD2:1;
            vuint32_t PD1:1;
            vuint32_t PD0:1;
        } B;
    } PSTAT;

};

/**************************************************************************/
/*                 Module: MC_RGM            */
/**************************************************************************/
struct MC_RGM_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_4:6;
            vuint32_t F_VOR_STDBY:1;
            vuint32_t F_VOR_DEST:1;
            vuint32_t F_TSR_DEST:1;
            vuint32_t unused_3:8;
            vuint32_t F_SSCM_DEST:1;
            vuint32_t unused_2:3;
            vuint32_t F_JTAG_DEST:1;
            vuint32_t F_FIF:1;
            vuint32_t F_EDR:1;
            vuint32_t unused_1:2;
            vuint32_t F_SUF:1;
            vuint32_t F_FFRR:1;
            vuint32_t F_SOFT_DEST:1;
            vuint32_t unused_0:1;
            vuint32_t F_PORST:1;
            vuint32_t F_POR:1;
        } B;
    } DES;

    vuint8_t ADR_reserved0[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_4:6;
            vuint32_t D_VOR_STDBY:1;
            vuint32_t D_VOR_DEST:1;
            vuint32_t D_TSR_DEST:1;
            vuint32_t unused_3:8;
            vuint32_t D_SSCM_DEST:1;
            vuint32_t unused_2:3;
            vuint32_t D_JTAG_DEST:1;
            vuint32_t D_FIF:1;
            vuint32_t D_EDR:1;
            vuint32_t unused_1:2;
            vuint32_t D_SUF:1;
            vuint32_t D_FFRR:1;
            vuint32_t D_SOFT_DEST:1;
            vuint32_t unused_0:1;
            vuint32_t D_PORST:1;
            vuint32_t D_POR:1;
        } B;
    } DERD;

    vuint8_t ADR_reserved1[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:30;
            vuint32_t AR_PORST:1;
            vuint32_t unused_0:1;
        } B;
    } DEAR;

    vuint8_t ADR_reserved2[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_4:6;
            vuint32_t BE_VOR_STDBY:1;
            vuint32_t BE_VOR_DEST:1;
            vuint32_t BE_TSR_DEST:1;
            vuint32_t unused_3:8;
            vuint32_t BE_SSCM_DEST:1;
            vuint32_t unused_2:3;
            vuint32_t BE_JTAG_DEST:1;
            vuint32_t BE_FIF:1;
            vuint32_t BE_EDR:1;
            vuint32_t unused_1:2;
            vuint32_t BE_SUF:1;
            vuint32_t BE_FFRR:1;
            vuint32_t BE_SOFT_DEST:1;
            vuint32_t unused_0:1;
            vuint32_t BE_PORST:1;
            vuint32_t BE_POR:1;
        } B;
    } DBRE;

    vuint8_t ADR_reserved3[716];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_4:6;
            vuint32_t F_VOR_FUNC_STDBY:1;
            vuint32_t F_VOR_FUNC:1;
            vuint32_t F_TSR_FUNC:1;
            vuint32_t unused_3:12;
            vuint32_t F_JTAG_FUNC:1;
            vuint32_t unused_2:3;
            vuint32_t F_FCCU_SOFT:1;
            vuint32_t F_FCCU_HARD:1;
            vuint32_t unused_1:1;
            vuint32_t F_SOFT_FUNC:1;
            vuint32_t F_ST_DONE:1;
            vuint32_t F_ESR1:1;
            vuint32_t unused_0:1;
        } B;
    } FES;

    vuint8_t ADR_reserved4[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_4:6;
            vuint32_t D_VOR_FUNC_STDBY:1;
            vuint32_t D_VOR_FUNC:1;
            vuint32_t D_TSR_FUNC:1;
            vuint32_t unused_3:12;
            vuint32_t D_JTAG_FUNC:1;
            vuint32_t unused_2:4;
            vuint32_t D_FCCU_HARD:1;
            vuint32_t unused_1:1;
            vuint32_t D_SOFT_FUNC:1;
            vuint32_t D_ST_DONE:1;
            vuint32_t D_ESR1:1;
            vuint32_t unused_0:1;
        } B;
    } FERD;

    vuint8_t ADR_reserved5[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:6;
            vuint32_t AR_VOR_FUNC_STDBY:1;
            vuint32_t AR_VOR_FUNC:1;
            vuint32_t AR_TSR_FUNC:1;
            vuint32_t unused_1:21;
            vuint32_t AR_ESR1:1;
            vuint32_t unused_0:1;
        } B;
    } FEAR;

    vuint8_t ADR_reserved6[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_4:6;
            vuint32_t BE_VOR_FUNC_STDBY:1;
            vuint32_t BE_VOR_FUNC:1;
            vuint32_t BE_TSR_FUNC:1;
            vuint32_t unused_3:12;
            vuint32_t BE_JTAG_FUNC:1;
            vuint32_t unused_2:3;
            vuint32_t BE_FCCU_SOFT:1;
            vuint32_t BE_FCCU_HARD:1;
            vuint32_t unused_1:1;
            vuint32_t BE_SOFT_FUNC:1;
            vuint32_t BE_ST_DONE:1;
            vuint32_t BE_ESR1:1;
            vuint32_t unused_0:1;
        } B;
    } FBRE;

    vuint8_t ADR_reserved7[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_4:6;
            vuint32_t SS_VOR_FUNC_STDBY:1;
            vuint32_t SS_VOR_FUNC:1;
            vuint32_t SS_TSR_FUNC:1;
            vuint32_t unused_3:12;
            vuint32_t SS_JTAG_FUNC:1;
            vuint32_t unused_2:3;
            vuint32_t SS_FCCU_SOFT:1;
            vuint32_t SS_FCCU_HARD:1;
            vuint32_t unused_1:1;
            vuint32_t SS_SOFT_FUNC:1;
            vuint32_t SS_ST_DONE:1;
            vuint32_t SS_ESR1:1;
            vuint32_t unused_0:1;
        } B;
    } FESS;

    vuint8_t ADR_reserved8[704];

    union {
        vuint8_t R;
        struct {
            vuint8_t unused_0:4;
            vuint8_t FRET:4;
        } B;
    } FRET;

    vuint8_t ADR_reserved9[3];

    union {
        vuint8_t R;
        struct {
            vuint8_t unused_0:4;
            vuint8_t DRET:4;
        } B;
    } DRET;

    vuint8_t ADR_reserved10[7];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:1;
            vuint32_t PIT_0_RST:1;
            vuint32_t unused_1:14;
            vuint32_t SIUL_RST:1;
            vuint32_t unused_0:15;
        } B;
    } PRST0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:1;
            vuint32_t CCCU_RST:1;
            vuint32_t unused_2:23;
            vuint32_t CRC_0_RST:1;
            vuint32_t unused_1:1;
            vuint32_t DMAMUX_0_RST:1;
            vuint32_t unused_0:4;
        } B;
    } PRST1;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_5:3;
            vuint32_t LINFLEXD_0_RST:1;
            vuint32_t LINFLEXD_2_RST:1;
            vuint32_t unused_4:3;
            vuint32_t LINFLEXD_10_RST:1;
            vuint32_t unused_3:12;
            vuint32_t CAN_RAM_SUB_0_CTR_RST:1;
            vuint32_t unused_2:1;
            vuint32_t M_CAN_0_SUB_0_RST:1;
            vuint32_t unused_1:2;
            vuint32_t M_CAN_1_SUB_0_RST:1;
            vuint32_t M_CAN_2_SUB_0_RST:1;
            vuint32_t M_CAN_3_SUB_0_RST:1;
            vuint32_t unused_0:3;
        } B;
    } PRST2;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:15;
            vuint32_t SAR_ADC_12BIT_B_RST:1;
            vuint32_t unused_2:10;
            vuint32_t IIC_0_RST:1;
            vuint32_t unused_1:1;
            vuint32_t DSPI_0_RST:1;
            vuint32_t DSPI_2_RST:1;
            vuint32_t unused_0:2;
        } B;
    } PRST3;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:30;
            vuint32_t SAR_ADC_12BIT_B_SEQ_RST:1;
            vuint32_t unused_0:1;
        } B;
    } PRST4;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:22;
            vuint32_t FCCU_RST:1;
            vuint32_t unused_1:2;
            vuint32_t CRC_1_RST:1;
            vuint32_t unused_0:6;
        } B;
    } PRST5;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_5:3;
            vuint32_t LINFLEXD_1_RST:1;
            vuint32_t unused_4:2;
            vuint32_t LINFLEXD_7_RST:1;
            vuint32_t unused_3:3;
            vuint32_t LINFLEXD_15_RST:1;
            vuint32_t unused_2:10;
            vuint32_t CAN_RAM_SUB_1_CTR_RST:1;
            vuint32_t unused_1:3;
            vuint32_t M_CAN_1_SUB_1_RST:1;
            vuint32_t M_CAN_2_SUB_1_RST:1;
            vuint32_t M_CAN_3_SUB_1_RST:1;
            vuint32_t unused_0:4;
        } B;
    } PRST6;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:12;
            vuint32_t BODY_CTU_0_RST:1;
            vuint32_t unused_2:1;
            vuint32_t EMIOS_0_RST:1;
            vuint32_t unused_1:13;
            vuint32_t DSPI_1_RST:1;
            vuint32_t DSPI_3_RST:1;
            vuint32_t unused_0:2;
        } B;
    } PRST7;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:1;
            vuint32_t PIT_0_STAT:1;
            vuint32_t unused_1:14;
            vuint32_t SIUL_STAT:1;
            vuint32_t unused_0:15;
        } B;
    } PSTAT0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:1;
            vuint32_t CCCU_STAT:1;
            vuint32_t unused_2:23;
            vuint32_t CRC_0_STAT:1;
            vuint32_t unused_1:1;
            vuint32_t DMAMUX_0_STAT:1;
            vuint32_t unused_0:4;
        } B;
    } PSTAT1;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_5:3;
            vuint32_t LINFLEXD_0_STAT:1;
            vuint32_t LINFLEXD_2_STAT:1;
            vuint32_t unused_4:3;
            vuint32_t LINFLEXD_10_STAT:1;
            vuint32_t unused_3:12;
            vuint32_t CAN_RAM_SUB_0_CTR_STAT:1;
            vuint32_t unused_2:1;
            vuint32_t M_CAN_0_SUB_0_STAT:1;
            vuint32_t unused_1:2;
            vuint32_t M_CAN_1_SUB_0_STAT:1;
            vuint32_t M_CAN_2_SUB_0_STAT:1;
            vuint32_t M_CAN_3_SUB_0_STAT:1;
            vuint32_t unused_0:3;
        } B;
    } PSTAT2;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:15;
            vuint32_t SAR_ADC_12BIT_B_STAT:1;
            vuint32_t unused_2:10;
            vuint32_t IIC_0_STAT:1;
            vuint32_t unused_1:1;
            vuint32_t DSPI_0_STAT:1;
            vuint32_t DSPI_2_STAT:1;
            vuint32_t unused_0:2;
        } B;
    } PSTAT3;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:30;
            vuint32_t SAR_ADC_12BIT_B_SEQ_STAT:1;
            vuint32_t unused_0:1;
        } B;
    } PSTAT4;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:22;
            vuint32_t FCCU_STAT:1;
            vuint32_t unused_1:2;
            vuint32_t CRC_1_STAT:1;
            vuint32_t unused_0:6;
        } B;
    } PSTAT5;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_5:3;
            vuint32_t LINFLEXD_1_STAT:1;
            vuint32_t unused_4:2;
            vuint32_t LINFLEXD_7_STAT:1;
            vuint32_t unused_3:3;
            vuint32_t LINFLEXD_15_STAT:1;
            vuint32_t unused_2:10;
            vuint32_t CAN_RAM_SUB_1_CTR_STAT:1;
            vuint32_t unused_1:3;
            vuint32_t M_CAN_1_SUB_1_STAT:1;
            vuint32_t M_CAN_2_SUB_1_STAT:1;
            vuint32_t M_CAN_3_SUB_1_STAT:1;
            vuint32_t unused_0:4;
        } B;
    } PSTAT6;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:12;
            vuint32_t BODY_CTU_0_STAT:1;
            vuint32_t unused_2:1;
            vuint32_t EMIOS_0_STAT:1;
            vuint32_t unused_1:13;
            vuint32_t DSPI_1_STAT:1;
            vuint32_t DSPI_3_STAT:1;
            vuint32_t unused_0:2;
        } B;
    } PSTAT7;

};

/**************************************************************************/
/*                 Module: MEMU            */
/**************************************************************************/
struct MEMU_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:16;
            vuint32_t SWR:1;
            vuint32_t unused_0:13;
            vuint32_t FLASH_ERR_SELECT:2;
        } B;
    } CTRL;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:11;
            vuint32_t PR_CE:1;
            vuint32_t PR_UCE:1;
            vuint32_t PR_CEO:1;
            vuint32_t PR_UCO:1;
            vuint32_t PR_EBO:1;
            vuint32_t unused_1:3;
            vuint32_t F_CE:1;
            vuint32_t F_UCE:1;
            vuint32_t F_CEO:1;
            vuint32_t F_UCO:1;
            vuint32_t F_EBO:1;
            vuint32_t unused_0:3;
            vuint32_t SR_CE:1;
            vuint32_t SR_UCE:1;
            vuint32_t SR_CEO:1;
            vuint32_t SR_UCO:1;
            vuint32_t SR_EBO:1;
        } B;
    } ERR_FLAG;

    vuint8_t ADR_reserved0[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:11;
            vuint32_t FR_PR_CE:1;
            vuint32_t FR_PR_UCE:1;
            vuint32_t FR_PR_CEO:1;
            vuint32_t FR_PR_UCO:1;
            vuint32_t FR_PR_EBO:1;
            vuint32_t unused_1:3;
            vuint32_t FR_F_CE:1;
            vuint32_t FR_F_UCE:1;
            vuint32_t FR_F_CEO:1;
            vuint32_t FR_F_UCO:1;
            vuint32_t FR_F_EBO:1;
            vuint32_t unused_0:3;
            vuint32_t FR_SR_CE:1;
            vuint32_t FR_SR_UCE:1;
            vuint32_t FR_SR_CEO:1;
            vuint32_t FR_SR_UCO:1;
            vuint32_t FR_SR_EBO:1;
        } B;
    } DEBUG;

    vuint8_t ADR_reserved1[16];

    struct {
        union {
            vuint32_t R;
            struct {
                vuint32_t VLD:1;
                vuint32_t unused_0:23;
                vuint32_t BAD_BIT:8;
            } B;
        } CERR_STS;

        union {
            vuint32_t R;
            struct {
                vuint32_t ERR_ADD:32;
            } B;
        } CERR_ADDR;

    } SYS_RAM[10];

    union {
        vuint32_t R;
        struct {
            vuint32_t VLD:1;
            vuint32_t unused_0:31;
        } B;
    } SYS_RAM_UNCERR_STS;

    union {
        vuint32_t R;
        struct {
            vuint32_t ERR_ADD:32;
        } B;
    } SYS_RAM_UNCERR_ADDR;

    union {
        vuint32_t R;
        struct {
            vuint32_t OFLW:32;
        } B;
    } SYS_RAM_OFLW[4];

    vuint8_t ADR_reserved2[1432];

    struct {
        union {
            vuint32_t R;
            struct {
                vuint32_t VLD:1;
                vuint32_t unused_0:23;
                vuint32_t BAD_BIT:8;
            } B;
        } CERR_STS;

        union {
            vuint32_t R;
            struct {
                vuint32_t ERR_ADD:32;
            } B;
        } CERR_ADDR;

    } PERIPH_RAM[2];

    union {
        vuint32_t R;
        struct {
            vuint32_t VLD:1;
            vuint32_t unused_0:31;
        } B;
    } PERIPH_RAM_UNCERR_STS;

    union {
        vuint32_t R;
        struct {
            vuint32_t ERR_ADD:32;
        } B;
    } PERIPH_RAM_UNCERR_ADDR;

    union {
        vuint32_t R;
        struct {
            vuint32_t OFLW:32;
        } B;
    } PERIPH_RAM_OFLW[1];

    vuint8_t ADR_reserved3[1508];

    struct {
        union {
            vuint32_t R;
            struct {
                vuint32_t VLD:1;
                vuint32_t unused_0:15;
                vuint32_t BAD_BIT:16;
            } B;
        } CERR_STS;

        union {
            vuint32_t R;
            struct {
                vuint32_t ERR_ADD:32;
            } B;
        } CERR_ADDR;

    } FLASH[20];

    union {
        vuint32_t R;
        struct {
            vuint32_t VLD:1;
            vuint32_t unused_0:31;
        } B;
    } FLASH_UNCERR_STS;

    union {
        vuint32_t R;
        struct {
            vuint32_t ERR_ADD:32;
        } B;
    } FLASH_UNCERR_ADDR;

    union {
        vuint32_t R;
        struct {
            vuint32_t OFLW:32;
        } B;
    } FLASH_OFLW[1];

};

/**************************************************************************/
/*                 Module: OSC40M_DIG            */
/**************************************************************************/
struct OSC40M_DIG_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t OSCBYP:1;
            vuint32_t unused_2:7;
            vuint32_t EOCV:8;
            vuint32_t M_OSC:1;
            vuint32_t unused_1:7;
            vuint32_t I_OSC:1;
            vuint32_t unused_0:7;
        } B;
    } CTL;

};

/**************************************************************************/
/*                 Module: PASS            */
/**************************************************************************/
struct PASS_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t CNS:1;
            vuint32_t JUN:1;
            vuint32_t FBE:1;
            vuint32_t unused_0:26;
            vuint32_t LIFE:3;
        } B;
    } LCSTAT;

    vuint8_t ADR_reserved0[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:30;
            vuint32_t GRP:2;
        } B;
    } CHSEL;

    vuint8_t ADR_reserved1[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:28;
            vuint32_t CMST:4;
        } B;
    } CSTAT;

    vuint8_t ADR_reserved2[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t PW32:32;
        } B;
    } CIN[8];

    vuint8_t ADR_reserved3[192];

    struct {
        union {
            vuint32_t R;
            struct {
                vuint32_t TSLOCK:1;
                vuint32_t unused_0:1;
                vuint32_t LOWLOCK:14;
                vuint32_t MIDLOCK:16;
            } B;
        } LOCK0_PG;

        union {
            vuint32_t R;
            struct {
                vuint32_t unused_0:16;
                vuint32_t HIGHLOCK:16;
            } B;
        } LOCK1_PG;

        union {
            vuint32_t R;
            struct {
                vuint32_t A256KLOCK:32;
            } B;
        } LOCK2_PG;

        union {
            vuint32_t R;
            struct {
                vuint32_t PGL:1;
                vuint32_t DBL:1;
                vuint32_t MO:1;
                vuint32_t unused_1:1;
                vuint32_t MSTR:4;
                vuint32_t unused_0:3;
                vuint32_t RL4:1;
                vuint32_t RL3:1;
                vuint32_t RL2:1;
                vuint32_t RL1:1;
                vuint32_t RL0:1;
                vuint32_t A256KLOCK:16;
            } B;
        } LOCK3_PG;

    } PG[4];

};

/**************************************************************************/
/*                 Module: PBRIDGE            */
/**************************************************************************/
struct PBRIDGE_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t MPROT0:4;
            vuint32_t MPROT1:4;
            vuint32_t MPROT2:4;
            vuint32_t MPROT3:4;
            vuint32_t MPROT4:4;
            vuint32_t MPROT5:4;
            vuint32_t MPROT6:4;
            vuint32_t MPROT7:4;
        } B;
    } MPRA;

    vuint8_t ADR_reserved0[252];

    union {
        vuint32_t R;
        struct {
            vuint32_t PACR0:4;
            vuint32_t PACR1:4;
            vuint32_t PACR2:4;
            vuint32_t PACR3:4;
            vuint32_t PACR4:4;
            vuint32_t PACR5:4;
            vuint32_t PACR6:4;
            vuint32_t PACR7:4;
        } B;
    } PACRA;

    union {
        vuint32_t R;
        struct {
            vuint32_t PACR8:4;
            vuint32_t PACR9:4;
            vuint32_t PACR10:4;
            vuint32_t PACR11:4;
            vuint32_t PACR12:4;
            vuint32_t PACR13:4;
            vuint32_t PACR14:4;
            vuint32_t PACR15:4;
        } B;
    } PACRB;

    union {
        vuint32_t R;
        struct {
            vuint32_t PACR16:4;
            vuint32_t PACR17:4;
            vuint32_t PACR18:4;
            vuint32_t PACR19:4;
            vuint32_t PACR20:4;
            vuint32_t PACR21:4;
            vuint32_t PACR22:4;
            vuint32_t PACR23:4;
        } B;
    } PACRC;

    union {
        vuint32_t R;
        struct {
            vuint32_t PACR24:4;
            vuint32_t PACR25:4;
            vuint32_t PACR26:4;
            vuint32_t PACR27:4;
            vuint32_t PACR28:4;
            vuint32_t PACR29:4;
            vuint32_t PACR30:4;
            vuint32_t PACR31:4;
        } B;
    } PACRD;

    union {
        vuint32_t R;
        struct {
            vuint32_t PACR32:4;
            vuint32_t PACR33:4;
            vuint32_t PACR34:4;
            vuint32_t PACR35:4;
            vuint32_t PACR36:4;
            vuint32_t PACR37:4;
            vuint32_t PACR38:4;
            vuint32_t PACR39:4;
        } B;
    } PACRE;

    union {
        vuint32_t R;
        struct {
            vuint32_t PACR40:4;
            vuint32_t PACR41:4;
            vuint32_t PACR42:4;
            vuint32_t PACR43:4;
            vuint32_t PACR44:4;
            vuint32_t PACR45:4;
            vuint32_t PACR46:4;
            vuint32_t PACR47:4;
        } B;
    } PACRF;

    union {
        vuint32_t R;
        struct {
            vuint32_t PACR48:4;
            vuint32_t PACR49:4;
            vuint32_t PACR50:4;
            vuint32_t PACR51:4;
            vuint32_t PACR52:4;
            vuint32_t PACR53:4;
            vuint32_t PACR54:4;
            vuint32_t PACR55:4;
        } B;
    } PACRG;

    union {
        vuint32_t R;
        struct {
            vuint32_t PACR56:4;
            vuint32_t PACR57:4;
            vuint32_t PACR58:4;
            vuint32_t PACR59:4;
            vuint32_t PACR60:4;
            vuint32_t PACR61:4;
            vuint32_t PACR62:4;
            vuint32_t PACR63:4;
        } B;
    } PACRH;

    vuint8_t ADR_reserved1[32];

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR0:4;
            vuint32_t OPACR1:4;
            vuint32_t OPACR2:4;
            vuint32_t OPACR3:4;
            vuint32_t OPACR4:4;
            vuint32_t OPACR5:4;
            vuint32_t OPACR6:4;
            vuint32_t OPACR7:4;
        } B;
    } OPACRA;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR8:4;
            vuint32_t OPACR9:4;
            vuint32_t OPACR10:4;
            vuint32_t OPACR11:4;
            vuint32_t OPACR12:4;
            vuint32_t OPACR13:4;
            vuint32_t OPACR14:4;
            vuint32_t OPACR15:4;
        } B;
    } OPACRB;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR16:4;
            vuint32_t OPACR17:4;
            vuint32_t OPACR18:4;
            vuint32_t OPACR19:4;
            vuint32_t OPACR20:4;
            vuint32_t OPACR21:4;
            vuint32_t OPACR22:4;
            vuint32_t OPACR23:4;
        } B;
    } OPACRC;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR24:4;
            vuint32_t OPACR25:4;
            vuint32_t OPACR26:4;
            vuint32_t OPACR27:4;
            vuint32_t OPACR28:4;
            vuint32_t OPACR29:4;
            vuint32_t OPACR30:4;
            vuint32_t OPACR31:4;
        } B;
    } OPACRD;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR32:4;
            vuint32_t OPACR33:4;
            vuint32_t OPACR34:4;
            vuint32_t OPACR35:4;
            vuint32_t OPACR36:4;
            vuint32_t OPACR37:4;
            vuint32_t OPACR38:4;
            vuint32_t OPACR39:4;
        } B;
    } OPACRE;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR40:4;
            vuint32_t OPACR41:4;
            vuint32_t OPACR42:4;
            vuint32_t OPACR43:4;
            vuint32_t OPACR44:4;
            vuint32_t OPACR45:4;
            vuint32_t OPACR46:4;
            vuint32_t OPACR47:4;
        } B;
    } OPACRF;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR48:4;
            vuint32_t OPACR49:4;
            vuint32_t OPACR50:4;
            vuint32_t OPACR51:4;
            vuint32_t OPACR52:4;
            vuint32_t OPACR53:4;
            vuint32_t OPACR54:4;
            vuint32_t OPACR55:4;
        } B;
    } OPACRG;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR56:4;
            vuint32_t OPACR57:4;
            vuint32_t OPACR58:4;
            vuint32_t OPACR59:4;
            vuint32_t OPACR60:4;
            vuint32_t OPACR61:4;
            vuint32_t OPACR62:4;
            vuint32_t OPACR63:4;
        } B;
    } OPACRH;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR64:4;
            vuint32_t OPACR65:4;
            vuint32_t OPACR66:4;
            vuint32_t OPACR67:4;
            vuint32_t OPACR68:4;
            vuint32_t OPACR69:4;
            vuint32_t OPACR70:4;
            vuint32_t OPACR71:4;
        } B;
    } OPACRI;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR72:4;
            vuint32_t OPACR73:4;
            vuint32_t OPACR74:4;
            vuint32_t OPACR75:4;
            vuint32_t OPACR76:4;
            vuint32_t OPACR77:4;
            vuint32_t OPACR78:4;
            vuint32_t OPACR79:4;
        } B;
    } OPACRJ;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR80:4;
            vuint32_t OPACR81:4;
            vuint32_t OPACR82:4;
            vuint32_t OPACR83:4;
            vuint32_t OPACR84:4;
            vuint32_t OPACR85:4;
            vuint32_t OPACR86:4;
            vuint32_t OPACR87:4;
        } B;
    } OPACRK;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR88:4;
            vuint32_t OPACR89:4;
            vuint32_t OPACR90:4;
            vuint32_t OPACR91:4;
            vuint32_t OPACR92:4;
            vuint32_t OPACR93:4;
            vuint32_t OPACR94:4;
            vuint32_t OPACR95:4;
        } B;
    } OPACRL;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR96:4;
            vuint32_t OPACR97:4;
            vuint32_t OPACR98:4;
            vuint32_t OPACR99:4;
            vuint32_t OPACR100:4;
            vuint32_t OPACR101:4;
            vuint32_t OPACR102:4;
            vuint32_t OPACR103:4;
        } B;
    } OPACRM;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR104:4;
            vuint32_t OPACR105:4;
            vuint32_t OPACR106:4;
            vuint32_t OPACR107:4;
            vuint32_t OPACR108:4;
            vuint32_t OPACR109:4;
            vuint32_t OPACR110:4;
            vuint32_t OPACR111:4;
        } B;
    } OPACRN;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR112:4;
            vuint32_t OPACR113:4;
            vuint32_t OPACR114:4;
            vuint32_t OPACR115:4;
            vuint32_t OPACR116:4;
            vuint32_t OPACR117:4;
            vuint32_t OPACR118:4;
            vuint32_t OPACR119:4;
        } B;
    } OPACRO;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR120:4;
            vuint32_t OPACR121:4;
            vuint32_t OPACR122:4;
            vuint32_t OPACR123:4;
            vuint32_t OPACR124:4;
            vuint32_t OPACR125:4;
            vuint32_t OPACR126:4;
            vuint32_t OPACR127:4;
        } B;
    } OPACRP;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR128:4;
            vuint32_t OPACR129:4;
            vuint32_t OPACR130:4;
            vuint32_t OPACR131:4;
            vuint32_t OPACR132:4;
            vuint32_t OPACR133:4;
            vuint32_t OPACR134:4;
            vuint32_t OPACR135:4;
        } B;
    } OPACRQ;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR136:4;
            vuint32_t OPACR137:4;
            vuint32_t OPACR138:4;
            vuint32_t OPACR139:4;
            vuint32_t OPACR140:4;
            vuint32_t OPACR141:4;
            vuint32_t OPACR142:4;
            vuint32_t OPACR143:4;
        } B;
    } OPACRR;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR144:4;
            vuint32_t OPACR145:4;
            vuint32_t OPACR146:4;
            vuint32_t OPACR147:4;
            vuint32_t OPACR148:4;
            vuint32_t OPACR149:4;
            vuint32_t OPACR150:4;
            vuint32_t OPACR151:4;
        } B;
    } OPACRS;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR152:4;
            vuint32_t OPACR153:4;
            vuint32_t OPACR154:4;
            vuint32_t OPACR155:4;
            vuint32_t OPACR156:4;
            vuint32_t OPACR157:4;
            vuint32_t OPACR158:4;
            vuint32_t OPACR159:4;
        } B;
    } OPACRT;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR160:4;
            vuint32_t OPACR161:4;
            vuint32_t OPACR162:4;
            vuint32_t OPACR163:4;
            vuint32_t OPACR164:4;
            vuint32_t OPACR165:4;
            vuint32_t OPACR166:4;
            vuint32_t OPACR167:4;
        } B;
    } OPACRU;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR168:4;
            vuint32_t OPACR169:4;
            vuint32_t OPACR170:4;
            vuint32_t OPACR171:4;
            vuint32_t OPACR172:4;
            vuint32_t OPACR173:4;
            vuint32_t OPACR174:4;
            vuint32_t OPACR175:4;
        } B;
    } OPACRV;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR176:4;
            vuint32_t OPACR177:4;
            vuint32_t OPACR178:4;
            vuint32_t OPACR179:4;
            vuint32_t OPACR180:4;
            vuint32_t OPACR181:4;
            vuint32_t OPACR182:4;
            vuint32_t OPACR183:4;
        } B;
    } OPACRW;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR184:4;
            vuint32_t OPACR185:4;
            vuint32_t OPACR186:4;
            vuint32_t OPACR187:4;
            vuint32_t OPACR188:4;
            vuint32_t OPACR189:4;
            vuint32_t OPACR190:4;
            vuint32_t OPACR191:4;
        } B;
    } OPACRX;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR192:4;
            vuint32_t OPACR193:4;
            vuint32_t OPACR194:4;
            vuint32_t OPACR195:4;
            vuint32_t OPACR196:4;
            vuint32_t OPACR197:4;
            vuint32_t OPACR198:4;
            vuint32_t OPACR199:4;
        } B;
    } OPACRY;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR200:4;
            vuint32_t OPACR201:4;
            vuint32_t OPACR202:4;
            vuint32_t OPACR203:4;
            vuint32_t OPACR204:4;
            vuint32_t OPACR205:4;
            vuint32_t OPACR206:4;
            vuint32_t OPACR207:4;
        } B;
    } OPACRZ;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR208:4;
            vuint32_t OPACR209:4;
            vuint32_t OPACR210:4;
            vuint32_t OPACR211:4;
            vuint32_t OPACR212:4;
            vuint32_t OPACR213:4;
            vuint32_t OPACR214:4;
            vuint32_t OPACR215:4;
        } B;
    } OPACRAA;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR216:4;
            vuint32_t OPACR217:4;
            vuint32_t OPACR218:4;
            vuint32_t OPACR219:4;
            vuint32_t OPACR220:4;
            vuint32_t OPACR221:4;
            vuint32_t OPACR222:4;
            vuint32_t OPACR223:4;
        } B;
    } OPACRAB;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR224:4;
            vuint32_t OPACR225:4;
            vuint32_t OPACR226:4;
            vuint32_t OPACR227:4;
            vuint32_t OPACR228:4;
            vuint32_t OPACR229:4;
            vuint32_t OPACR230:4;
            vuint32_t OPACR231:4;
        } B;
    } OPACRAC;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR232:4;
            vuint32_t OPACR233:4;
            vuint32_t OPACR234:4;
            vuint32_t OPACR235:4;
            vuint32_t OPACR236:4;
            vuint32_t OPACR237:4;
            vuint32_t OPACR238:4;
            vuint32_t OPACR239:4;
        } B;
    } OPACRAD;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR240:4;
            vuint32_t OPACR241:4;
            vuint32_t OPACR242:4;
            vuint32_t OPACR243:4;
            vuint32_t OPACR244:4;
            vuint32_t OPACR245:4;
            vuint32_t OPACR246:4;
            vuint32_t OPACR247:4;
        } B;
    } OPACRAE;

    union {
        vuint32_t R;
        struct {
            vuint32_t OPACR248:4;
            vuint32_t OPACR249:4;
            vuint32_t OPACR250:4;
            vuint32_t OPACR251:4;
            vuint32_t OPACR252:4;
            vuint32_t OPACR253:4;
            vuint32_t OPACR254:4;
            vuint32_t OPACR255:4;
        } B;
    } OPACRAF;

};

/**************************************************************************/
/*                 Module: PCM            */
/**************************************************************************/
struct PCM_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:22;
            vuint32_t DMA_STALL_NXMC_OVF:1;
            vuint32_t EN_HSIZE_MUX:1;
            vuint32_t PRE_DMA:1;
            vuint32_t BRE_DMA:1;
            vuint32_t BWE_DMA:1;
            vuint32_t unused_0:5;
        } B;
    } PCM0;

};

/**************************************************************************/
/*                 Module: PFLASH            */
/**************************************************************************/
struct PFLASH_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t P0_M15PFE:1;
            vuint32_t P0_M14PFE:1;
            vuint32_t P0_M13PFE:1;
            vuint32_t P0_M12PFE:1;
            vuint32_t P0_M11PFE:1;
            vuint32_t P0_M10PFE:1;
            vuint32_t P0_M9PFE:1;
            vuint32_t P0_M8PFE:1;
            vuint32_t P0_M7PFE:1;
            vuint32_t P0_M6PFE:1;
            vuint32_t P0_M5PFE:1;
            vuint32_t P0_M4PFE:1;
            vuint32_t P0_M3PFE:1;
            vuint32_t P0_M2PFE:1;
            vuint32_t P0_M1PFE:1;
            vuint32_t P0_M0PFE:1;
            vuint32_t APC:3;
            vuint32_t RWSC:5;
            vuint32_t unused_2:1;
            vuint32_t P0_DPFEN:1;
            vuint32_t unused_1:1;
            vuint32_t P0_IPFEN:1;
            vuint32_t unused_0:1;
            vuint32_t P0_PFLIM:2;
            vuint32_t P0_BFEN:1;
        } B;
    } PFCR1;

    union {
        vuint32_t R;
        struct {
            vuint32_t P1_M15PFE:1;
            vuint32_t P1_M14PFE:1;
            vuint32_t P1_M13PFE:1;
            vuint32_t P1_M12PFE:1;
            vuint32_t P1_M11PFE:1;
            vuint32_t P1_M10PFE:1;
            vuint32_t P1_M9PFE:1;
            vuint32_t P1_M8PFE:1;
            vuint32_t P1_M7PFE:1;
            vuint32_t P1_M6PFE:1;
            vuint32_t P1_M5PFE:1;
            vuint32_t P1_M4PFE:1;
            vuint32_t P1_M3PFE:1;
            vuint32_t P1_M2PFE:1;
            vuint32_t P1_M1PFE:1;
            vuint32_t P1_M0PFE:1;
            vuint32_t unused_2:9;
            vuint32_t P1_DPFEN:1;
            vuint32_t unused_1:1;
            vuint32_t P1_IPFEN:1;
            vuint32_t unused_0:1;
            vuint32_t P1_PFLIM:2;
            vuint32_t P1_BFEN:1;
        } B;
    } PFCR2;

    union {
        vuint32_t R;
        struct {
            vuint32_t P0_WCFG:2;
            vuint32_t P1_WCFG:2;
            vuint32_t unused_1:11;
            vuint32_t BAF_DIS:1;
            vuint32_t ARBM:2;
            vuint32_t unused_0:14;
        } B;
    } PFCR3;

    union {
        vuint32_t R;
        struct {
            vuint32_t M0AP:2;
            vuint32_t M1AP:2;
            vuint32_t M2AP:2;
            vuint32_t M3AP:2;
            vuint32_t M4AP:2;
            vuint32_t M5AP:2;
            vuint32_t M6AP:2;
            vuint32_t M7AP:2;
            vuint32_t M8AP:2;
            vuint32_t M9AP:2;
            vuint32_t M10AP:2;
            vuint32_t M11AP:2;
            vuint32_t M12AP:2;
            vuint32_t M13AP:2;
            vuint32_t M14AP:2;
            vuint32_t M15AP:2;
        } B;
    } PFAPR;

};

/**************************************************************************/
/*                 Module: PIT            */
/**************************************************************************/
struct PIT_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:29;
            vuint32_t MDIS_RTI:1;
            vuint32_t MDIS:1;
            vuint32_t FRZ:1;
        } B;
    } MCR;

    vuint8_t ADR_reserved0[236];

    union {
        vuint32_t R;
        struct {
            vuint32_t TSV:32;
        } B;
    } RTI_LDVAL;

    union {
        vuint32_t R;
        struct {
            vuint32_t TVL:32;
        } B;
    } RTI_CVAL;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:30;
            vuint32_t TIE:1;
            vuint32_t TEN:1;
        } B;
    } RTI_TCTRL;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:31;
            vuint32_t TIF:1;
        } B;
    } RTI_TFLG;

    struct {
        union {
            vuint32_t R;
            struct {
                vuint32_t TSV:32;
            } B;
        } LDVAL;

        union {
            vuint32_t R;
            struct {
                vuint32_t TVL:32;
            } B;
        } CVAL;

        union {
            vuint32_t R;
            struct {
                vuint32_t unused_0:29;
                vuint32_t CHN:1;
                vuint32_t TIE:1;
                vuint32_t TEN:1;
            } B;
        } TCTRL;

        union {
            vuint32_t R;
            struct {
                vuint32_t unused_0:31;
                vuint32_t TIF:1;
            } B;
        } TFLG;

    } CH[8];

};

/**************************************************************************/
/*                 Module: PLLDIG            */
/**************************************************************************/
struct PLLDIG_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:22;
            vuint32_t CLKCFG:2;
            vuint32_t EXPDIE:1;
            vuint32_t unused_1:3;
            vuint32_t LOLIE:1;
            vuint32_t unused_0:3;
        } B;
    } PLL0CR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:24;
            vuint32_t EXTPDF:1;
            vuint32_t unused_1:3;
            vuint32_t LOLF:1;
            vuint32_t LOCK:1;
            vuint32_t unused_0:2;
        } B;
    } PLL0SR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:1;
            vuint32_t RFDPHI1:4;
            vuint32_t unused_2:5;
            vuint32_t RFDPHI:6;
            vuint32_t unused_1:1;
            vuint32_t PREDIV:3;
            vuint32_t unused_0:5;
            vuint32_t MFD:7;
        } B;
    } PLL0DV;

    vuint8_t ADR_reserved0[20];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:22;
            vuint32_t CLKCFG:2;
            vuint32_t EXPDIE:1;
            vuint32_t unused_1:3;
            vuint32_t LOLIE:1;
            vuint32_t unused_0:3;
        } B;
    } PLL1CR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:24;
            vuint32_t EXTPDF:1;
            vuint32_t unused_1:3;
            vuint32_t LOLF:1;
            vuint32_t LOCK:1;
            vuint32_t unused_0:2;
        } B;
    } PLL1SR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:10;
            vuint32_t RFDPHI:6;
            vuint32_t unused_0:9;
            vuint32_t MFD:7;
        } B;
    } PLL1DV;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:1;
            vuint32_t MODEN:1;
            vuint32_t MODSEL:1;
            vuint32_t MODPRD:13;
            vuint32_t unused_0:1;
            vuint32_t INCSTP:15;
        } B;
    } PLL1FM;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:1;
            vuint32_t FDEN:1;
            vuint32_t unused_1:12;
            vuint32_t DTHDIS:2;
            vuint32_t unused_0:4;
            vuint32_t FRCDIV:12;
        } B;
    } PLL1FD;

};

/**************************************************************************/
/*                 Module: PMCDIG            */
/**************************************************************************/
struct PMCDIG_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:3;
            vuint32_t LVD3_SB:1;
            vuint32_t unused_2:1;
            vuint32_t LVD3_FL:1;
            vuint32_t unused_1:1;
            vuint32_t LVD3_C:1;
            vuint32_t unused_0:24;
        } B;
    } EPR_LV0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:3;
            vuint32_t REE3_SB:1;
            vuint32_t unused_2:1;
            vuint32_t REE3_FL:1;
            vuint32_t unused_1:1;
            vuint32_t REE3_C:1;
            vuint32_t unused_0:24;
        } B;
    } REE_LV0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:3;
            vuint32_t RES3_SB:1;
            vuint32_t unused_2:1;
            vuint32_t RES3_FL:1;
            vuint32_t unused_1:1;
            vuint32_t RES3_C:1;
            vuint32_t unused_0:24;
        } B;
    } RES_LV0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:3;
            vuint32_t VD3IE_SB:1;
            vuint32_t unused_2:1;
            vuint32_t VD3IE_FL:1;
            vuint32_t unused_1:1;
            vuint32_t VD3IE_C:1;
            vuint32_t unused_0:24;
        } B;
    } IE_LV0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:3;
            vuint32_t FEE3_SB:1;
            vuint32_t unused_2:1;
            vuint32_t FEE3_FL:1;
            vuint32_t unused_1:1;
            vuint32_t FEE3_C:1;
            vuint32_t unused_0:24;
        } B;
    } FEE_LV0;

    vuint8_t ADR_reserved0[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:15;
            vuint32_t HVD6_C:1;
            vuint32_t unused_0:16;
        } B;
    } EPR_LV1;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:15;
            vuint32_t REE6_C:1;
            vuint32_t unused_0:16;
        } B;
    } REE_LV1;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:15;
            vuint32_t RES6_C:1;
            vuint32_t unused_0:16;
        } B;
    } RES_LV1;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:15;
            vuint32_t HVD6IE_C:1;
            vuint32_t unused_0:16;
        } B;
    } IE_LV1;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:15;
            vuint32_t FEE6_C:1;
            vuint32_t unused_0:16;
        } B;
    } FEE_LV1;

    vuint8_t ADR_reserved1[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:2;
            vuint32_t LVD11_AS:1;
            vuint32_t unused_1:3;
            vuint32_t LVD11_FL:1;
            vuint32_t LVD11_C:1;
            vuint32_t unused_0:24;
        } B;
    } EPR_HV0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:2;
            vuint32_t REE11_AS:1;
            vuint32_t unused_1:3;
            vuint32_t REE11_FL:1;
            vuint32_t REE11_C:1;
            vuint32_t unused_0:24;
        } B;
    } REE_HV0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:2;
            vuint32_t RES11_AS:1;
            vuint32_t unused_1:3;
            vuint32_t RES11_FL:1;
            vuint32_t RES11_C:1;
            vuint32_t unused_0:24;
        } B;
    } RES_HV0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:2;
            vuint32_t LVD11IE_AS:1;
            vuint32_t unused_1:3;
            vuint32_t LVD11IE_FL:1;
            vuint32_t LVD11IE_C:1;
            vuint32_t unused_0:24;
        } B;
    } IE_HV0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:2;
            vuint32_t FEE11_AS:1;
            vuint32_t unused_1:3;
            vuint32_t FEE11_FL:1;
            vuint32_t FEE11_C:1;
            vuint32_t unused_0:24;
        } B;
    } FEE_HV0;

    vuint8_t ADR_reserved2[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:10;
            vuint32_t LVD14_AS:1;
            vuint32_t unused_1:3;
            vuint32_t LVD14_IM:1;
            vuint32_t unused_0:17;
        } B;
    } EPR_HV1;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:10;
            vuint32_t REE14_AS:1;
            vuint32_t unused_1:3;
            vuint32_t REE14_IM:1;
            vuint32_t unused_0:17;
        } B;
    } REE_HV1;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:10;
            vuint32_t RES14_AS:1;
            vuint32_t unused_1:3;
            vuint32_t RES14_IM:1;
            vuint32_t unused_0:17;
        } B;
    } RES_HV1;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:10;
            vuint32_t LVDIE14_AS:1;
            vuint32_t unused_1:3;
            vuint32_t LVDIE14_IM:1;
            vuint32_t unused_0:17;
        } B;
    } IE_HV1;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:10;
            vuint32_t FEE14_AS:1;
            vuint32_t unused_1:3;
            vuint32_t FEE14_IM:1;
            vuint32_t unused_0:17;
        } B;
    } FEE_HV1;

    vuint8_t ADR_reserved3[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_6:1;
            vuint32_t TEMP_2:1;
            vuint32_t TEMP_1:1;
            vuint32_t TEMP_0:1;
            vuint32_t unused_5:4;
            vuint32_t VD14_AS:1;
            vuint32_t unused_4:2;
            vuint32_t VD14_IM:1;
            vuint32_t unused_3:9;
            vuint32_t VD11_AS:1;
            vuint32_t unused_2:2;
            vuint32_t VD11_FL:1;
            vuint32_t VD11_C:1;
            vuint32_t unused_1:1;
            vuint32_t VD6_C:1;
            vuint32_t unused_0:1;
            vuint32_t VD3_SB:1;
            vuint32_t VD3_FL:1;
            vuint32_t VD3_C:1;
        } B;
    } GR_S;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_7:8;
            vuint32_t VD14_AS:1;
            vuint32_t unused_6:2;
            vuint32_t VD14_IM:1;
            vuint32_t unused_5:6;
            vuint32_t VD11_AS:1;
            vuint32_t unused_4:2;
            vuint32_t VD11_FL:1;
            vuint32_t VD11_C:1;
            vuint32_t unused_3:1;
            vuint32_t VD6_C:1;
            vuint32_t unused_2:1;
            vuint32_t VD3_SB:1;
            vuint32_t VD3_FL:1;
            vuint32_t VD3_C:1;
            vuint32_t unused_1:1;
            vuint32_t IRQ_ST:1;
            vuint32_t unused_0:1;
        } B;
    } GR_P;

    union {
        vuint32_t R;
        struct {
            vuint32_t IE_EN:1;
            vuint32_t unused_7:7;
            vuint32_t VD14IE_AS:1;
            vuint32_t unused_6:2;
            vuint32_t VD14IE_C:1;
            vuint32_t unused_5:6;
            vuint32_t VD11IE_AS:1;
            vuint32_t unused_4:2;
            vuint32_t VD11IE_FL:1;
            vuint32_t VD11IE_C:1;
            vuint32_t unused_3:1;
            vuint32_t VD6IE_C:1;
            vuint32_t unused_2:1;
            vuint32_t VD3IE_SB:1;
            vuint32_t VD3IE_FL:1;
            vuint32_t VD3IE_C:1;
            vuint32_t unused_1:1;
            vuint32_t IRQ_EN:1;
            vuint32_t unused_0:1;
        } B;
    } IE_G;

    vuint8_t ADR_reserved4[120];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:29;
            vuint32_t VSIO_IM:1;
            vuint32_t unused_0:2;
        } B;
    } VSIO;

    vuint8_t ADR_reserved5[320];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:28;
            vuint32_t RCREG1M_ENB:1;
            vuint32_t RCOSC1M_ENB:1;
            vuint32_t unused_0:2;
        } B;
    } MISC_CTRL_REG;

    vuint8_t ADR_reserved6[180];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:29;
            vuint32_t TEMP_2:1;
            vuint32_t TEMP_1:1;
            vuint32_t TEMP_0:1;
        } B;
    } EPR_TD;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:29;
            vuint32_t TEMP_2:1;
            vuint32_t TEMP_1:1;
            vuint32_t TEMP_0:1;
        } B;
    } REE_TD;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:29;
            vuint32_t TEMP_2:1;
            vuint32_t TEMP_1:1;
            vuint32_t TEMP_0:1;
        } B;
    } RES_TD;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:12;
            vuint32_t TRIM_ADJ_OVER1:4;
            vuint32_t TS2IE:1;
            vuint32_t TS1IE:1;
            vuint32_t TS0IE:1;
            vuint32_t unused_2:1;
            vuint32_t TRIM_ADJ_OVER:4;
            vuint32_t unused_1:2;
            vuint32_t TRIM_ADJ_UNDER:4;
            vuint32_t unused_0:1;
            vuint32_t AOUT_EN:1;
        } B;
    } CTL_TD;

    vuint8_t ADR_reserved7[8];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:29;
            vuint32_t FEE_TS2:1;
            vuint32_t FEE_TS1:1;
            vuint32_t FEE_TS0:1;
        } B;
    } FEE_TD;

    vuint8_t ADR_reserved8[8];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:31;
            vuint32_t ESR0_CFG:1;
        } B;
    } ESR0_CFG;

    vuint8_t ADR_reserved9[164];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t FLAGS_P1:16;
        } B;
    } BIST_FLAGS_PHASE1;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t FLAGS_P2:16;
        } B;
    } BIST_FLAGS_PHASE2;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_5:11;
            vuint32_t IRQST:1;
            vuint32_t unused_4:3;
            vuint32_t IRQEN:1;
            vuint32_t unused_3:3;
            vuint32_t NCFST:1;
            vuint32_t unused_2:3;
            vuint32_t NCFEN:1;
            vuint32_t unused_1:1;
            vuint32_t STATUS:3;
            vuint32_t unused_0:3;
            vuint32_t START:1;
        } B;
    } BIST_CTRL;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:3;
            vuint32_t TIME_1:13;
            vuint32_t unused_0:3;
            vuint32_t TIME_0:13;
        } B;
    } BIST_TIME10;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:3;
            vuint32_t TIME_3:13;
            vuint32_t unused_0:3;
            vuint32_t TIME_2:13;
        } B;
    } BIST_TIME32;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:3;
            vuint32_t TIME_6:13;
            vuint32_t unused_0:3;
            vuint32_t TIME_5:13;
        } B;
    } BIST_TIME65;

    union {
        vuint32_t R;
        struct {
            vuint32_t LVD100_SB_MASK_STATUS:1;
            vuint32_t MVD094_FA_MASK_STATUS:1;
            vuint32_t MVD094_FB_MASK_STATUS:1;
            vuint32_t MVD094_C_MASK_STATUS:1;
            vuint32_t LVD100_C_MASK_STATUS:1;
            vuint32_t LVD100_FL_MASK_STATUS:1;
            vuint32_t MVD270_FL_MASK_STATUS:1;
            vuint32_t MVD270_C_MASK_STATUS:1;
            vuint32_t LVD290_FL_MASK_STATUS:1;
            vuint32_t LVD290_AS_MASK_STATUS:1;
            vuint32_t LVD290_C_MASK_STATUS:1;
            vuint32_t LVD400_C_MASK_STATUS:1;
            vuint32_t LVD400_AS_MASK_STATUS:1;
            vuint32_t HVD134_C_MASK_STATUS:1;
            vuint32_t UVD140_C_MASK_STATUS:1;
            vuint32_t unused_0:11;
            vuint32_t VD_MON:6;
        } B;
    } BIST_DEBUG;

};

/**************************************************************************/
/*                 Module: PRAM            */
/**************************************************************************/
struct PRAM_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:22;
            vuint32_t PRI1:1;
            vuint32_t PRI0:1;
            vuint32_t P1_BO_DIS:1;
            vuint32_t P0_BO_DIS:1;
            vuint32_t unused_0:5;
            vuint32_t FT_DIS:1;
        } B;
    } PRCR1;

};

/**************************************************************************/
/*                 Module: RC1024K_DIG            */
/**************************************************************************/
struct RC1024K_DIG_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:19;
            vuint32_t LPRCDIV:5;
            vuint32_t unused_1:3;
            vuint32_t S_LPRC:1;
            vuint32_t unused_0:4;
        } B;
    } CTL;

};

/**************************************************************************/
/*                 Module: RC16M_DIG            */
/**************************************************************************/
struct RC16M_DIG_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:10;
            vuint32_t USER_TRIM:6;
            vuint32_t unused_0:16;
        } B;
    } CTL;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:2;
            vuint32_t FT_CODE:6;
            vuint32_t unused_1:12;
            vuint32_t REG_EN:1;
            vuint32_t unused_0:3;
            vuint32_t RCTRIM:8;
        } B;
    } NT;

};

/**************************************************************************/
/*                 Module: RTC_API            */
/**************************************************************************/
struct RTC_API_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t SUPV:1;
            vuint32_t unused_0:31;
        } B;
    } RTCSUPV;

    union {
        vuint32_t R;
        struct {
            vuint32_t CNTEN:1;
            vuint32_t RTCIE:1;
            vuint32_t FRZEN:1;
            vuint32_t ROVREN:1;
            vuint32_t unused_1:12;
            vuint32_t APIEN:1;
            vuint32_t APIIE:1;
            vuint32_t CLKSEL:2;
            vuint32_t DIV512EN:1;
            vuint32_t DIV32EN:1;
            vuint32_t unused_0:9;
            vuint32_t TRIG_EN:1;
        } B;
    } RTCC;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_4:2;
            vuint32_t RTCF:1;
            vuint32_t unused_3:10;
            vuint32_t INV_RTC:1;
            vuint32_t INV_API:1;
            vuint32_t INV_ANL:1;
            vuint32_t unused_2:2;
            vuint32_t APIF:1;
            vuint32_t unused_1:2;
            vuint32_t ROVRF:1;
            vuint32_t unused_0:10;
        } B;
    } RTCS;

    union {
        vuint32_t R;
        struct {
            vuint32_t RTCCNT:32;
        } B;
    } RTCCNT;

    union {
        vuint32_t R;
        struct {
            vuint32_t APIVAL:32;
        } B;
    } APIVAL;

    union {
        vuint32_t R;
        struct {
            vuint32_t RTCVAL:32;
        } B;
    } RTCVAL;

    union {
        vuint32_t R;
        struct {
            vuint32_t ANLCMP:32;
        } B;
    } ANLCMP_CNT;

};

/**************************************************************************/
/*                 Module: SARADC            */
/**************************************************************************/
struct SARADC_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t OWREN:1;
            vuint32_t WLSIDE:1;
            vuint32_t MODE:1;
            vuint32_t unused_4:1;
            vuint32_t NSTART:1;
            vuint32_t NTRGEN:1;
            vuint32_t NEDGESEL:2;
            vuint32_t JSTART:1;
            vuint32_t JTRGEN:1;
            vuint32_t JEDGESEL:2;
            vuint32_t JTRGSEQ:1;
            vuint32_t unused_3:1;
            vuint32_t CTUEN:1;
            vuint32_t CTU_MODE:1;
            vuint32_t WTRIGOUT:1;
            vuint32_t unused_2:3;
            vuint32_t JTRGSEL:4;
            vuint32_t ABORTCHAIN:1;
            vuint32_t ABORT:1;
            vuint32_t unused_1:1;
            vuint32_t FRZ:1;
            vuint32_t unused_0:2;
            vuint32_t EDCSELF:1;
            vuint32_t PWDN:1;
        } B;
    } MCR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_4:4;
            vuint32_t NSTART:1;
            vuint32_t unused_3:3;
            vuint32_t JSTART:1;
            vuint32_t unused_2:4;
            vuint32_t JABORTCHAIN:1;
            vuint32_t unused_1:1;
            vuint32_t CTUSTART:1;
            vuint32_t CHADDR:8;
            vuint32_t unused_0:5;
            vuint32_t ADCSTATUS:3;
        } B;
    } MSR;

    vuint8_t ADR_reserved0[8];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:26;
            vuint32_t CTUTRGERR:1;
            vuint32_t EOCTU:1;
            vuint32_t JEOC:1;
            vuint32_t JECH:1;
            vuint32_t NEOC:1;
            vuint32_t NECH:1;
        } B;
    } ISR;

    union {
        vuint32_t R;
        struct {
            vuint32_t EOC_CH31:1;
            vuint32_t EOC_CH30:1;
            vuint32_t EOC_CH29:1;
            vuint32_t EOC_CH28:1;
            vuint32_t EOC_CH27:1;
            vuint32_t EOC_CH26:1;
            vuint32_t EOC_CH25:1;
            vuint32_t EOC_CH24:1;
            vuint32_t EOC_CH23:1;
            vuint32_t EOC_CH22:1;
            vuint32_t EOC_CH21:1;
            vuint32_t EOC_CH20:1;
            vuint32_t EOC_CH19:1;
            vuint32_t EOC_CH18:1;
            vuint32_t EOC_CH17:1;
            vuint32_t EOC_CH16:1;
            vuint32_t EOC_CH15:1;
            vuint32_t EOC_CH14:1;
            vuint32_t EOC_CH13:1;
            vuint32_t EOC_CH12:1;
            vuint32_t EOC_CH11:1;
            vuint32_t EOC_CH10:1;
            vuint32_t EOC_CH9:1;
            vuint32_t EOC_CH8:1;
            vuint32_t EOC_CH7:1;
            vuint32_t EOC_CH6:1;
            vuint32_t EOC_CH5:1;
            vuint32_t EOC_CH4:1;
            vuint32_t EOC_CH3:1;
            vuint32_t EOC_CH2:1;
            vuint32_t EOC_CH1:1;
            vuint32_t EOC_CH0:1;
        } B;
    } ICIPR0;

    union {
        vuint32_t R;
        struct {
            vuint32_t EOC_CH63:1;
            vuint32_t EOC_CH62:1;
            vuint32_t EOC_CH61:1;
            vuint32_t EOC_CH60:1;
            vuint32_t EOC_CH59:1;
            vuint32_t EOC_CH58:1;
            vuint32_t EOC_CH57:1;
            vuint32_t EOC_CH56:1;
            vuint32_t EOC_CH55:1;
            vuint32_t EOC_CH54:1;
            vuint32_t EOC_CH53:1;
            vuint32_t EOC_CH52:1;
            vuint32_t EOC_CH51:1;
            vuint32_t EOC_CH50:1;
            vuint32_t EOC_CH49:1;
            vuint32_t EOC_CH48:1;
            vuint32_t EOC_CH47:1;
            vuint32_t EOC_CH46:1;
            vuint32_t EOC_CH45:1;
            vuint32_t EOC_CH44:1;
            vuint32_t EOC_CH43:1;
            vuint32_t EOC_CH42:1;
            vuint32_t EOC_CH41:1;
            vuint32_t EOC_CH40:1;
            vuint32_t EOC_CH39:1;
            vuint32_t EOC_CH38:1;
            vuint32_t EOC_CH37:1;
            vuint32_t EOC_CH36:1;
            vuint32_t EOC_CH35:1;
            vuint32_t EOC_CH34:1;
            vuint32_t EOC_CH33:1;
            vuint32_t EOC_CH32:1;
        } B;
    } ICIPR1;

    union {
        vuint32_t R;
        struct {
            vuint32_t EOC_CH95:1;
            vuint32_t EOC_CH94:1;
            vuint32_t EOC_CH93:1;
            vuint32_t EOC_CH92:1;
            vuint32_t EOC_CH91:1;
            vuint32_t EOC_CH90:1;
            vuint32_t EOC_CH89:1;
            vuint32_t EOC_CH88:1;
            vuint32_t EOC_CH87:1;
            vuint32_t EOC_CH86:1;
            vuint32_t EOC_CH85:1;
            vuint32_t EOC_CH84:1;
            vuint32_t EOC_CH83:1;
            vuint32_t EOC_CH82:1;
            vuint32_t EOC_CH81:1;
            vuint32_t EOC_CH80:1;
            vuint32_t EOC_CH79:1;
            vuint32_t EOC_CH78:1;
            vuint32_t EOC_CH77:1;
            vuint32_t EOC_CH76:1;
            vuint32_t EOC_CH75:1;
            vuint32_t EOC_CH74:1;
            vuint32_t EOC_CH73:1;
            vuint32_t EOC_CH72:1;
            vuint32_t EOC_CH71:1;
            vuint32_t EOC_CH70:1;
            vuint32_t EOC_CH69:1;
            vuint32_t EOC_CH68:1;
            vuint32_t EOC_CH67:1;
            vuint32_t EOC_CH66:1;
            vuint32_t EOC_CH65:1;
            vuint32_t EOC_CH64:1;
        } B;
    } ICIPR2;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:27;
            vuint32_t MSKEOCTU:1;
            vuint32_t MSKJEOC:1;
            vuint32_t MSKJECH:1;
            vuint32_t MSKNEOC:1;
            vuint32_t MSKNECH:1;
        } B;
    } IMR;

    union {
        vuint32_t R;
        struct {
            vuint32_t IM_CH:32;
        } B;
    } ICIMR[3];

    union {
        vuint32_t R;
        struct {
            vuint32_t WDG15H:1;
            vuint32_t WDG15L:1;
            vuint32_t WDG14H:1;
            vuint32_t WDG14L:1;
            vuint32_t WDG13H:1;
            vuint32_t WDG13L:1;
            vuint32_t WDG12H:1;
            vuint32_t WDG12L:1;
            vuint32_t WDG11H:1;
            vuint32_t WDG11L:1;
            vuint32_t WDG10H:1;
            vuint32_t WDG10L:1;
            vuint32_t WDG9H:1;
            vuint32_t WDG9L:1;
            vuint32_t WDG8H:1;
            vuint32_t WDG8L:1;
            vuint32_t WDG7H:1;
            vuint32_t WDG7L:1;
            vuint32_t WDG6H:1;
            vuint32_t WDG6L:1;
            vuint32_t WDG5H:1;
            vuint32_t WDG5L:1;
            vuint32_t WDG4H:1;
            vuint32_t WDG4L:1;
            vuint32_t WDG3H:1;
            vuint32_t WDG3L:1;
            vuint32_t WDG2H:1;
            vuint32_t WDG2L:1;
            vuint32_t WDG1H:1;
            vuint32_t WDG1L:1;
            vuint32_t WDG0H:1;
            vuint32_t WDG0L:1;
        } B;
    } WTISR;

    union {
        vuint32_t R;
        struct {
            vuint32_t MSKWDG15H:1;
            vuint32_t MSKWDG15L:1;
            vuint32_t MSKWDG14H:1;
            vuint32_t MSKWDG14L:1;
            vuint32_t MSKWDG13H:1;
            vuint32_t MSKWDG13L:1;
            vuint32_t MSKWDG12H:1;
            vuint32_t MSKWDG12L:1;
            vuint32_t MSKWDG11H:1;
            vuint32_t MSKWDG11L:1;
            vuint32_t MSKWDG10H:1;
            vuint32_t MSKWDG10L:1;
            vuint32_t MSKWDG9H:1;
            vuint32_t MSKWDG9L:1;
            vuint32_t MSKWDG8H:1;
            vuint32_t MSKWDG8L:1;
            vuint32_t MSKWDG7H:1;
            vuint32_t MSKWDG7L:1;
            vuint32_t MSKWDG6H:1;
            vuint32_t MSKWDG6L:1;
            vuint32_t MSKWDG5H:1;
            vuint32_t MSKWDG5L:1;
            vuint32_t MSKWDG4H:1;
            vuint32_t MSKWDG4L:1;
            vuint32_t MSKWDG3H:1;
            vuint32_t MSKWDG3L:1;
            vuint32_t MSKWDG2H:1;
            vuint32_t MSKWDG2L:1;
            vuint32_t MSKWDG1H:1;
            vuint32_t MSKWDG1L:1;
            vuint32_t MSKWDG0H:1;
            vuint32_t MSKWDG0L:1;
        } B;
    } WTIMR;

    vuint8_t ADR_reserved1[8];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:30;
            vuint32_t DCLR:1;
            vuint32_t DMAEN:1;
        } B;
    } DMAE;

    union {
        vuint32_t R;
        struct {
            vuint32_t DS_CH:32;
        } B;
    } ICDSR[3];

    vuint8_t ADR_reserved2[16];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t THRH:12;
            vuint32_t unused_0:4;
            vuint32_t THRL:12;
        } B;
    } WTHRHLR[4];

    vuint8_t ADR_reserved3[36];

    union {
        vuint32_t R;
        struct {
            vuint32_t CRES:1;
            vuint32_t unused_0:19;
            vuint32_t PRECHG:4;
            vuint32_t INPSAMP:8;
        } B;
    } CTR[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t NCE_CH:32;
        } B;
    } ICNCMR[3];

    vuint8_t ADR_reserved4[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t JCE_CH:32;
        } B;
    } ICJCMR[3];

    vuint8_t ADR_reserved5[8];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:24;
            vuint32_t PDED:8;
        } B;
    } PDEDR;

    vuint8_t ADR_reserved6[52];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:4;
            vuint32_t PCE:1;
            vuint32_t unused_1:1;
            vuint32_t CTSEL:2;
            vuint32_t unused_0:4;
            vuint32_t VALID:1;
            vuint32_t OVERW:1;
            vuint32_t RESULT:2;
            vuint32_t CDATA:16;
        } B;
    } ICDR[96];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t THRH:12;
            vuint32_t unused_0:4;
            vuint32_t THRL:12;
        } B;
    } WTHRHLR4;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t THRH:12;
            vuint32_t unused_0:4;
            vuint32_t THRL:12;
        } B;
    } WTHRHLR5;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t THRH:12;
            vuint32_t unused_0:4;
            vuint32_t THRL:12;
        } B;
    } WTHRHLR6;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t THRH:12;
            vuint32_t unused_0:4;
            vuint32_t THRL:12;
        } B;
    } WTHRHLR7;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t THRH:12;
            vuint32_t unused_0:4;
            vuint32_t THRL:12;
        } B;
    } WTHRHLR8;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t THRH:12;
            vuint32_t unused_0:4;
            vuint32_t THRL:12;
        } B;
    } WTHRHLR9;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t THRH:12;
            vuint32_t unused_0:4;
            vuint32_t THRL:12;
        } B;
    } WTHRHLR10;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t THRH:12;
            vuint32_t unused_0:4;
            vuint32_t THRL:12;
        } B;
    } WTHRHLR11;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t THRH:12;
            vuint32_t unused_0:4;
            vuint32_t THRL:12;
        } B;
    } WTHRHLR12;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t THRH:12;
            vuint32_t unused_0:4;
            vuint32_t THRL:12;
        } B;
    } WTHRHLR13;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t THRH:12;
            vuint32_t unused_0:4;
            vuint32_t THRL:12;
        } B;
    } WTHRHLR14;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:4;
            vuint32_t THRH:12;
            vuint32_t unused_0:4;
            vuint32_t THRL:12;
        } B;
    } WTHRHLR15;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH7:4;
            vuint32_t WSEL_CH6:4;
            vuint32_t WSEL_CH5:4;
            vuint32_t WSEL_CH4:4;
            vuint32_t WSEL_CH3:4;
            vuint32_t WSEL_CH2:4;
            vuint32_t WSEL_CH1:4;
            vuint32_t WSEL_CH0:4;
        } B;
    } ICWSELR[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t WEN_CH31:1;
            vuint32_t WEN_CH30:1;
            vuint32_t WEN_CH29:1;
            vuint32_t WEN_CH28:1;
            vuint32_t WEN_CH27:1;
            vuint32_t WEN_CH26:1;
            vuint32_t WEN_CH25:1;
            vuint32_t WEN_CH24:1;
            vuint32_t WEN_CH23:1;
            vuint32_t WEN_CH22:1;
            vuint32_t WEN_CH21:1;
            vuint32_t WEN_CH20:1;
            vuint32_t WEN_CH19:1;
            vuint32_t WEN_CH18:1;
            vuint32_t WEN_CH17:1;
            vuint32_t WEN_CH16:1;
            vuint32_t WEN_CH15:1;
            vuint32_t WEN_CH14:1;
            vuint32_t WEN_CH13:1;
            vuint32_t WEN_CH12:1;
            vuint32_t WEN_CH11:1;
            vuint32_t WEN_CH10:1;
            vuint32_t WEN_CH9:1;
            vuint32_t WEN_CH8:1;
            vuint32_t WEN_CH7:1;
            vuint32_t WEN_CH6:1;
            vuint32_t WEN_CH5:1;
            vuint32_t WEN_CH4:1;
            vuint32_t WEN_CH3:1;
            vuint32_t WEN_CH2:1;
            vuint32_t WEN_CH1:1;
            vuint32_t WEN_CH0:1;
        } B;
    } ICWENR[3];

    vuint8_t ADR_reserved7[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t AWOR_CH31:1;
            vuint32_t AWOR_CH30:1;
            vuint32_t AWOR_CH29:1;
            vuint32_t AWOR_CH28:1;
            vuint32_t AWOR_CH27:1;
            vuint32_t AWOR_CH26:1;
            vuint32_t AWOR_CH25:1;
            vuint32_t AWOR_CH24:1;
            vuint32_t AWOR_CH23:1;
            vuint32_t AWOR_CH22:1;
            vuint32_t AWOR_CH21:1;
            vuint32_t AWOR_CH20:1;
            vuint32_t AWOR_CH19:1;
            vuint32_t AWOR_CH18:1;
            vuint32_t AWOR_CH17:1;
            vuint32_t AWOR_CH16:1;
            vuint32_t AWOR_CH15:1;
            vuint32_t AWOR_CH14:1;
            vuint32_t AWOR_CH13:1;
            vuint32_t AWOR_CH12:1;
            vuint32_t AWOR_CH11:1;
            vuint32_t AWOR_CH10:1;
            vuint32_t AWOR_CH9:1;
            vuint32_t AWOR_CH8:1;
            vuint32_t AWOR_CH7:1;
            vuint32_t AWOR_CH6:1;
            vuint32_t AWOR_CH5:1;
            vuint32_t AWOR_CH4:1;
            vuint32_t AWOR_CH3:1;
            vuint32_t AWOR_CH2:1;
            vuint32_t AWOR_CH1:1;
            vuint32_t AWOR_CH0:1;
        } B;
    } ICAWORR[3];

    vuint8_t ADR_reserved8[260];

    union {
        vuint32_t R;
        struct {
            vuint32_t EOC_CH127:1;
            vuint32_t EOC_CH126:1;
            vuint32_t EOC_CH125:1;
            vuint32_t EOC_CH124:1;
            vuint32_t EOC_CH123:1;
            vuint32_t EOC_CH122:1;
            vuint32_t EOC_CH121:1;
            vuint32_t EOC_CH120:1;
            vuint32_t EOC_CH119:1;
            vuint32_t EOC_CH118:1;
            vuint32_t EOC_CH117:1;
            vuint32_t EOC_CH116:1;
            vuint32_t EOC_CH115:1;
            vuint32_t EOC_CH114:1;
            vuint32_t EOC_CH113:1;
            vuint32_t EOC_CH112:1;
            vuint32_t EOC_CH111:1;
            vuint32_t EOC_CH110:1;
            vuint32_t EOC_CH109:1;
            vuint32_t EOC_CH108:1;
            vuint32_t EOC_CH107:1;
            vuint32_t EOC_CH106:1;
            vuint32_t EOC_CH105:1;
            vuint32_t EOC_CH104:1;
            vuint32_t EOC_CH103:1;
            vuint32_t EOC_CH102:1;
            vuint32_t EOC_CH101:1;
            vuint32_t EOC_CH100:1;
            vuint32_t EOC_CH99:1;
            vuint32_t EOC_CH98:1;
            vuint32_t EOC_CH97:1;
            vuint32_t EOC_CH96:1;
        } B;
    } TCIPR;

    union {
        vuint32_t R;
        struct {
            vuint32_t IM_CH127:1;
            vuint32_t IM_CH126:1;
            vuint32_t IM_CH125:1;
            vuint32_t IM_CH124:1;
            vuint32_t IM_CH123:1;
            vuint32_t IM_CH122:1;
            vuint32_t IM_CH121:1;
            vuint32_t IM_CH120:1;
            vuint32_t IM_CH119:1;
            vuint32_t IM_CH118:1;
            vuint32_t IM_CH117:1;
            vuint32_t IM_CH116:1;
            vuint32_t IM_CH115:1;
            vuint32_t IM_CH114:1;
            vuint32_t IM_CH113:1;
            vuint32_t IM_CH112:1;
            vuint32_t IM_CH111:1;
            vuint32_t IM_CH110:1;
            vuint32_t IM_CH109:1;
            vuint32_t IM_CH108:1;
            vuint32_t IM_CH107:1;
            vuint32_t IM_CH106:1;
            vuint32_t IM_CH105:1;
            vuint32_t IM_CH104:1;
            vuint32_t IM_CH103:1;
            vuint32_t IM_CH102:1;
            vuint32_t IM_CH101:1;
            vuint32_t IM_CH100:1;
            vuint32_t IM_CH99:1;
            vuint32_t IM_CH98:1;
            vuint32_t IM_CH97:1;
            vuint32_t IM_CH96:1;
        } B;
    } TCIMR;

    union {
        vuint32_t R;
        struct {
            vuint32_t DS_CH127:1;
            vuint32_t DS_CH126:1;
            vuint32_t DS_CH125:1;
            vuint32_t DS_CH124:1;
            vuint32_t DS_CH123:1;
            vuint32_t DS_CH122:1;
            vuint32_t DS_CH121:1;
            vuint32_t DS_CH120:1;
            vuint32_t DS_CH119:1;
            vuint32_t DS_CH118:1;
            vuint32_t DS_CH117:1;
            vuint32_t DS_CH116:1;
            vuint32_t DS_CH115:1;
            vuint32_t DS_CH114:1;
            vuint32_t DS_CH113:1;
            vuint32_t DS_CH112:1;
            vuint32_t DS_CH111:1;
            vuint32_t DS_CH110:1;
            vuint32_t DS_CH109:1;
            vuint32_t DS_CH108:1;
            vuint32_t DS_CH107:1;
            vuint32_t DS_CH106:1;
            vuint32_t DS_CH105:1;
            vuint32_t DS_CH104:1;
            vuint32_t DS_CH103:1;
            vuint32_t DS_CH102:1;
            vuint32_t DS_CH101:1;
            vuint32_t DS_CH100:1;
            vuint32_t DS_CH99:1;
            vuint32_t DS_CH98:1;
            vuint32_t DS_CH97:1;
            vuint32_t DS_CH96:1;
        } B;
    } TCDSR;

    union {
        vuint32_t R;
        struct {
            vuint32_t NCE_CH127:1;
            vuint32_t NCE_CH126:1;
            vuint32_t NCE_CH125:1;
            vuint32_t NCE_CH124:1;
            vuint32_t NCE_CH123:1;
            vuint32_t NCE_CH122:1;
            vuint32_t NCE_CH121:1;
            vuint32_t NCE_CH120:1;
            vuint32_t NCE_CH119:1;
            vuint32_t NCE_CH118:1;
            vuint32_t NCE_CH117:1;
            vuint32_t NCE_CH116:1;
            vuint32_t NCE_CH115:1;
            vuint32_t NCE_CH114:1;
            vuint32_t NCE_CH113:1;
            vuint32_t NCE_CH112:1;
            vuint32_t NCE_CH111:1;
            vuint32_t NCE_CH110:1;
            vuint32_t NCE_CH109:1;
            vuint32_t NCE_CH108:1;
            vuint32_t NCE_CH107:1;
            vuint32_t NCE_CH106:1;
            vuint32_t NCE_CH105:1;
            vuint32_t NCE_CH104:1;
            vuint32_t NCE_CH103:1;
            vuint32_t NCE_CH102:1;
            vuint32_t NCE_CH101:1;
            vuint32_t NCE_CH100:1;
            vuint32_t NCE_CH99:1;
            vuint32_t NCE_CH98:1;
            vuint32_t NCE_CH97:1;
            vuint32_t NCE_CH96:1;
        } B;
    } TCNCMR;

    union {
        vuint32_t R;
        struct {
            vuint32_t JCE_CH127:1;
            vuint32_t JCE_CH126:1;
            vuint32_t JCE_CH125:1;
            vuint32_t JCE_CH124:1;
            vuint32_t JCE_CH123:1;
            vuint32_t JCE_CH122:1;
            vuint32_t JCE_CH121:1;
            vuint32_t JCE_CH120:1;
            vuint32_t JCE_CH119:1;
            vuint32_t JCE_CH118:1;
            vuint32_t JCE_CH117:1;
            vuint32_t JCE_CH116:1;
            vuint32_t JCE_CH115:1;
            vuint32_t JCE_CH114:1;
            vuint32_t JCE_CH113:1;
            vuint32_t JCE_CH112:1;
            vuint32_t JCE_CH111:1;
            vuint32_t JCE_CH110:1;
            vuint32_t JCE_CH109:1;
            vuint32_t JCE_CH108:1;
            vuint32_t JCE_CH107:1;
            vuint32_t JCE_CH106:1;
            vuint32_t JCE_CH105:1;
            vuint32_t JCE_CH104:1;
            vuint32_t JCE_CH103:1;
            vuint32_t JCE_CH102:1;
            vuint32_t JCE_CH101:1;
            vuint32_t JCE_CH100:1;
            vuint32_t JCE_CH99:1;
            vuint32_t JCE_CH98:1;
            vuint32_t JCE_CH97:1;
            vuint32_t JCE_CH96:1;
        } B;
    } TCJCMR;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH103:4;
            vuint32_t WSEL_CH102:4;
            vuint32_t WSEL_CH101:4;
            vuint32_t WSEL_CH100:4;
            vuint32_t WSEL_CH99:4;
            vuint32_t WSEL_CH98:4;
            vuint32_t WSEL_CH97:4;
            vuint32_t WSEL_CH96:4;
        } B;
    } TCWSELR[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t WEN_CH127:1;
            vuint32_t WEN_CH126:1;
            vuint32_t WEN_CH125:1;
            vuint32_t WEN_CH124:1;
            vuint32_t WEN_CH123:1;
            vuint32_t WEN_CH122:1;
            vuint32_t WEN_CH121:1;
            vuint32_t WEN_CH120:1;
            vuint32_t WEN_CH119:1;
            vuint32_t WEN_CH118:1;
            vuint32_t WEN_CH117:1;
            vuint32_t WEN_CH116:1;
            vuint32_t WEN_CH115:1;
            vuint32_t WEN_CH114:1;
            vuint32_t WEN_CH113:1;
            vuint32_t WEN_CH112:1;
            vuint32_t WEN_CH111:1;
            vuint32_t WEN_CH110:1;
            vuint32_t WEN_CH109:1;
            vuint32_t WEN_CH108:1;
            vuint32_t WEN_CH107:1;
            vuint32_t WEN_CH106:1;
            vuint32_t WEN_CH105:1;
            vuint32_t WEN_CH104:1;
            vuint32_t WEN_CH103:1;
            vuint32_t WEN_CH102:1;
            vuint32_t WEN_CH101:1;
            vuint32_t WEN_CH100:1;
            vuint32_t WEN_CH99:1;
            vuint32_t WEN_CH98:1;
            vuint32_t WEN_CH97:1;
            vuint32_t WEN_CH96:1;
        } B;
    } TCWENR;

    union {
        vuint32_t R;
        struct {
            vuint32_t AWOR_CH127:1;
            vuint32_t AWOR_CH126:1;
            vuint32_t AWOR_CH125:1;
            vuint32_t AWOR_CH124:1;
            vuint32_t AWOR_CH123:1;
            vuint32_t AWOR_CH122:1;
            vuint32_t AWOR_CH121:1;
            vuint32_t AWOR_CH120:1;
            vuint32_t AWOR_CH119:1;
            vuint32_t AWOR_CH118:1;
            vuint32_t AWOR_CH117:1;
            vuint32_t AWOR_CH116:1;
            vuint32_t AWOR_CH115:1;
            vuint32_t AWOR_CH114:1;
            vuint32_t AWOR_CH113:1;
            vuint32_t AWOR_CH112:1;
            vuint32_t AWOR_CH111:1;
            vuint32_t AWOR_CH110:1;
            vuint32_t AWOR_CH109:1;
            vuint32_t AWOR_CH108:1;
            vuint32_t AWOR_CH107:1;
            vuint32_t AWOR_CH106:1;
            vuint32_t AWOR_CH105:1;
            vuint32_t AWOR_CH104:1;
            vuint32_t AWOR_CH103:1;
            vuint32_t AWOR_CH102:1;
            vuint32_t AWOR_CH101:1;
            vuint32_t AWOR_CH100:1;
            vuint32_t AWOR_CH99:1;
            vuint32_t AWOR_CH98:1;
            vuint32_t AWOR_CH97:1;
            vuint32_t AWOR_CH96:1;
        } B;
    } TCAWORR;

    vuint8_t ADR_reserved9[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t ESIC_TCH3:1;
            vuint32_t ICSEL_TCH3:7;
            vuint32_t ESIC_TCH2:1;
            vuint32_t ICSEL_TCH2:7;
            vuint32_t ESIC_TCH1:1;
            vuint32_t ICSEL_TCH1:7;
            vuint32_t ESIC_TCH0:1;
            vuint32_t ICSEL_TCH0:7;
        } B;
    } TCCAPR0;

    union {
        vuint32_t R;
        struct {
            vuint32_t ESIC_TCH7:1;
            vuint32_t ICSEL_TCH7:7;
            vuint32_t ESIC_TCH6:1;
            vuint32_t ICSEL_TCH6:7;
            vuint32_t ESIC_TCH5:1;
            vuint32_t ICSEL_TCH5:7;
            vuint32_t ESIC_TCH4:1;
            vuint32_t ICSEL_TCH4:7;
        } B;
    } TCCAPR1;

    union {
        vuint32_t R;
        struct {
            vuint32_t ESIC_TCH11:1;
            vuint32_t ICSEL_TCH11:7;
            vuint32_t ESIC_TCH10:1;
            vuint32_t ICSEL_TCH10:7;
            vuint32_t ESIC_TCH9:1;
            vuint32_t ICSEL_TCH9:7;
            vuint32_t ESIC_TCH8:1;
            vuint32_t ICSEL_TCH8:7;
        } B;
    } TCCAPR2;

    union {
        vuint32_t R;
        struct {
            vuint32_t ESIC_TCH15:1;
            vuint32_t ICSEL_TCH15:7;
            vuint32_t ESIC_TCH14:1;
            vuint32_t ICSEL_TCH14:7;
            vuint32_t ESIC_TCH13:1;
            vuint32_t ICSEL_TCH13:7;
            vuint32_t ESIC_TCH12:1;
            vuint32_t ICSEL_TCH12:7;
        } B;
    } TCCAPR3;

    union {
        vuint32_t R;
        struct {
            vuint32_t ESIC_TCH19:1;
            vuint32_t ICSEL_TCH19:7;
            vuint32_t ESIC_TCH18:1;
            vuint32_t ICSEL_TCH18:7;
            vuint32_t ESIC_TCH17:1;
            vuint32_t ICSEL_TCH17:7;
            vuint32_t ESIC_TCH16:1;
            vuint32_t ICSEL_TCH16:7;
        } B;
    } TCCAPR4;

    union {
        vuint32_t R;
        struct {
            vuint32_t ESIC_TCH23:1;
            vuint32_t ICSEL_TCH23:7;
            vuint32_t ESIC_TCH22:1;
            vuint32_t ICSEL_TCH22:7;
            vuint32_t ESIC_TCH21:1;
            vuint32_t ICSEL_TCH21:7;
            vuint32_t ESIC_TCH20:1;
            vuint32_t ICSEL_TCH20:7;
        } B;
    } TCCAPR5;

    union {
        vuint32_t R;
        struct {
            vuint32_t ESIC_TCH27:1;
            vuint32_t ICSEL_TCH27:7;
            vuint32_t ESIC_TCH26:1;
            vuint32_t ICSEL_TCH26:7;
            vuint32_t ESIC_TCH25:1;
            vuint32_t ICSEL_TCH25:7;
            vuint32_t ESIC_TCH24:1;
            vuint32_t ICSEL_TCH24:7;
        } B;
    } TCCAPR6;

    union {
        vuint32_t R;
        struct {
            vuint32_t ESIC_TCH31:1;
            vuint32_t ICSEL_TCH31:7;
            vuint32_t ESIC_TCH30:1;
            vuint32_t ICSEL_TCH30:7;
            vuint32_t ESIC_TCH29:1;
            vuint32_t ICSEL_TCH29:7;
            vuint32_t ESIC_TCH28:1;
            vuint32_t ICSEL_TCH28:7;
        } B;
    } TCCAPR7;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:4;
            vuint32_t PCE:1;
            vuint32_t unused_1:1;
            vuint32_t CTSEL:2;
            vuint32_t unused_0:3;
            vuint32_t FCERR:1;
            vuint32_t VALID:1;
            vuint32_t OVERW:1;
            vuint32_t RESULT:2;
            vuint32_t CDATA:16;
        } B;
    } TCDR[32];

    vuint8_t ADR_reserved10[48];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:20;
            vuint32_t DSD:12;
        } B;
    } ECDSDR;

    vuint8_t ADR_reserved11[12];

    union {
        vuint32_t R;
        struct {
            vuint32_t EOC_CH159:1;
            vuint32_t EOC_CH158:1;
            vuint32_t EOC_CH157:1;
            vuint32_t EOC_CH156:1;
            vuint32_t EOC_CH155:1;
            vuint32_t EOC_CH154:1;
            vuint32_t EOC_CH153:1;
            vuint32_t EOC_CH152:1;
            vuint32_t EOC_CH151:1;
            vuint32_t EOC_CH150:1;
            vuint32_t EOC_CH149:1;
            vuint32_t EOC_CH148:1;
            vuint32_t EOC_CH147:1;
            vuint32_t EOC_CH146:1;
            vuint32_t EOC_CH145:1;
            vuint32_t EOC_CH144:1;
            vuint32_t EOC_CH143:1;
            vuint32_t EOC_CH142:1;
            vuint32_t EOC_CH141:1;
            vuint32_t EOC_CH140:1;
            vuint32_t EOC_CH139:1;
            vuint32_t EOC_CH138:1;
            vuint32_t EOC_CH137:1;
            vuint32_t EOC_CH136:1;
            vuint32_t EOC_CH135:1;
            vuint32_t EOC_CH134:1;
            vuint32_t EOC_CH133:1;
            vuint32_t EOC_CH132:1;
            vuint32_t EOC_CH131:1;
            vuint32_t EOC_CH130:1;
            vuint32_t EOC_CH129:1;
            vuint32_t EOC_CH128:1;
        } B;
    } ECIPR0;

    union {
        vuint32_t R;
        struct {
            vuint32_t EOC_CH191:1;
            vuint32_t EOC_CH190:1;
            vuint32_t EOC_CH189:1;
            vuint32_t EOC_CH188:1;
            vuint32_t EOC_CH187:1;
            vuint32_t EOC_CH186:1;
            vuint32_t EOC_CH185:1;
            vuint32_t EOC_CH184:1;
            vuint32_t EOC_CH183:1;
            vuint32_t EOC_CH182:1;
            vuint32_t EOC_CH181:1;
            vuint32_t EOC_CH180:1;
            vuint32_t EOC_CH179:1;
            vuint32_t EOC_CH178:1;
            vuint32_t EOC_CH177:1;
            vuint32_t EOC_CH176:1;
            vuint32_t EOC_CH175:1;
            vuint32_t EOC_CH174:1;
            vuint32_t EOC_CH173:1;
            vuint32_t EOC_CH172:1;
            vuint32_t EOC_CH171:1;
            vuint32_t EOC_CH170:1;
            vuint32_t EOC_CH169:1;
            vuint32_t EOC_CH168:1;
            vuint32_t EOC_CH167:1;
            vuint32_t EOC_CH166:1;
            vuint32_t EOC_CH165:1;
            vuint32_t EOC_CH164:1;
            vuint32_t EOC_CH163:1;
            vuint32_t EOC_CH162:1;
            vuint32_t EOC_CH161:1;
            vuint32_t EOC_CH160:1;
        } B;
    } ECIPR1;

    union {
        vuint32_t R;
        struct {
            vuint32_t EOC_CH223:1;
            vuint32_t EOC_CH222:1;
            vuint32_t EOC_CH221:1;
            vuint32_t EOC_CH220:1;
            vuint32_t EOC_CH219:1;
            vuint32_t EOC_CH218:1;
            vuint32_t EOC_CH217:1;
            vuint32_t EOC_CH216:1;
            vuint32_t EOC_CH215:1;
            vuint32_t EOC_CH214:1;
            vuint32_t EOC_CH213:1;
            vuint32_t EOC_CH212:1;
            vuint32_t EOC_CH211:1;
            vuint32_t EOC_CH210:1;
            vuint32_t EOC_CH209:1;
            vuint32_t EOC_CH208:1;
            vuint32_t EOC_CH207:1;
            vuint32_t EOC_CH206:1;
            vuint32_t EOC_CH205:1;
            vuint32_t EOC_CH204:1;
            vuint32_t EOC_CH203:1;
            vuint32_t EOC_CH202:1;
            vuint32_t EOC_CH201:1;
            vuint32_t EOC_CH200:1;
            vuint32_t EOC_CH199:1;
            vuint32_t EOC_CH198:1;
            vuint32_t EOC_CH197:1;
            vuint32_t EOC_CH196:1;
            vuint32_t EOC_CH195:1;
            vuint32_t EOC_CH194:1;
            vuint32_t EOC_CH193:1;
            vuint32_t EOC_CH192:1;
        } B;
    } ECIPR2;

    union {
        vuint32_t R;
        struct {
            vuint32_t EOC_CH255:1;
            vuint32_t EOC_CH254:1;
            vuint32_t EOC_CH253:1;
            vuint32_t EOC_CH252:1;
            vuint32_t EOC_CH251:1;
            vuint32_t EOC_CH250:1;
            vuint32_t EOC_CH249:1;
            vuint32_t EOC_CH248:1;
            vuint32_t EOC_CH247:1;
            vuint32_t EOC_CH246:1;
            vuint32_t EOC_CH245:1;
            vuint32_t EOC_CH244:1;
            vuint32_t EOC_CH243:1;
            vuint32_t EOC_CH242:1;
            vuint32_t EOC_CH241:1;
            vuint32_t EOC_CH240:1;
            vuint32_t EOC_CH239:1;
            vuint32_t EOC_CH238:1;
            vuint32_t EOC_CH237:1;
            vuint32_t EOC_CH236:1;
            vuint32_t EOC_CH235:1;
            vuint32_t EOC_CH234:1;
            vuint32_t EOC_CH233:1;
            vuint32_t EOC_CH232:1;
            vuint32_t EOC_CH231:1;
            vuint32_t EOC_CH230:1;
            vuint32_t EOC_CH229:1;
            vuint32_t EOC_CH228:1;
            vuint32_t EOC_CH227:1;
            vuint32_t EOC_CH226:1;
            vuint32_t EOC_CH225:1;
            vuint32_t EOC_CH224:1;
        } B;
    } ECIPR3;

    union {
        vuint32_t R;
        struct {
            vuint32_t IM_CH159:1;
            vuint32_t IM_CH158:1;
            vuint32_t IM_CH157:1;
            vuint32_t IM_CH156:1;
            vuint32_t IM_CH155:1;
            vuint32_t IM_CH154:1;
            vuint32_t IM_CH153:1;
            vuint32_t IM_CH152:1;
            vuint32_t IM_CH151:1;
            vuint32_t IM_CH150:1;
            vuint32_t IM_CH149:1;
            vuint32_t IM_CH148:1;
            vuint32_t IM_CH147:1;
            vuint32_t IM_CH146:1;
            vuint32_t IM_CH145:1;
            vuint32_t IM_CH144:1;
            vuint32_t IM_CH143:1;
            vuint32_t IM_CH142:1;
            vuint32_t IM_CH141:1;
            vuint32_t IM_CH140:1;
            vuint32_t IM_CH139:1;
            vuint32_t IM_CH138:1;
            vuint32_t IM_CH137:1;
            vuint32_t IM_CH136:1;
            vuint32_t IM_CH135:1;
            vuint32_t IM_CH134:1;
            vuint32_t IM_CH133:1;
            vuint32_t IM_CH132:1;
            vuint32_t IM_CH131:1;
            vuint32_t IM_CH130:1;
            vuint32_t IM_CH129:1;
            vuint32_t IM_CH128:1;
        } B;
    } ECIMR0;

    union {
        vuint32_t R;
        struct {
            vuint32_t IM_CH191:1;
            vuint32_t IM_CH190:1;
            vuint32_t IM_CH189:1;
            vuint32_t IM_CH188:1;
            vuint32_t IM_CH187:1;
            vuint32_t IM_CH186:1;
            vuint32_t IM_CH185:1;
            vuint32_t IM_CH184:1;
            vuint32_t IM_CH183:1;
            vuint32_t IM_CH182:1;
            vuint32_t IM_CH181:1;
            vuint32_t IM_CH180:1;
            vuint32_t IM_CH179:1;
            vuint32_t IM_CH178:1;
            vuint32_t IM_CH177:1;
            vuint32_t IM_CH176:1;
            vuint32_t IM_CH175:1;
            vuint32_t IM_CH174:1;
            vuint32_t IM_CH173:1;
            vuint32_t IM_CH172:1;
            vuint32_t IM_CH171:1;
            vuint32_t IM_CH170:1;
            vuint32_t IM_CH169:1;
            vuint32_t IM_CH168:1;
            vuint32_t IM_CH167:1;
            vuint32_t IM_CH166:1;
            vuint32_t IM_CH165:1;
            vuint32_t IM_CH164:1;
            vuint32_t IM_CH163:1;
            vuint32_t IM_CH162:1;
            vuint32_t IM_CH161:1;
            vuint32_t IM_CH160:1;
        } B;
    } ECIMR1;

    union {
        vuint32_t R;
        struct {
            vuint32_t IM_CH223:1;
            vuint32_t IM_CH222:1;
            vuint32_t IM_CH221:1;
            vuint32_t IM_CH220:1;
            vuint32_t IM_CH219:1;
            vuint32_t IM_CH218:1;
            vuint32_t IM_CH217:1;
            vuint32_t IM_CH216:1;
            vuint32_t IM_CH215:1;
            vuint32_t IM_CH214:1;
            vuint32_t IM_CH213:1;
            vuint32_t IM_CH212:1;
            vuint32_t IM_CH211:1;
            vuint32_t IM_CH210:1;
            vuint32_t IM_CH209:1;
            vuint32_t IM_CH208:1;
            vuint32_t IM_CH207:1;
            vuint32_t IM_CH206:1;
            vuint32_t IM_CH205:1;
            vuint32_t IM_CH204:1;
            vuint32_t IM_CH203:1;
            vuint32_t IM_CH202:1;
            vuint32_t IM_CH201:1;
            vuint32_t IM_CH200:1;
            vuint32_t IM_CH199:1;
            vuint32_t IM_CH198:1;
            vuint32_t IM_CH197:1;
            vuint32_t IM_CH196:1;
            vuint32_t IM_CH195:1;
            vuint32_t IM_CH194:1;
            vuint32_t IM_CH193:1;
            vuint32_t IM_CH192:1;
        } B;
    } ECIMR2;

    union {
        vuint32_t R;
        struct {
            vuint32_t IM_CH255:1;
            vuint32_t IM_CH254:1;
            vuint32_t IM_CH253:1;
            vuint32_t IM_CH252:1;
            vuint32_t IM_CH251:1;
            vuint32_t IM_CH250:1;
            vuint32_t IM_CH249:1;
            vuint32_t IM_CH248:1;
            vuint32_t IM_CH247:1;
            vuint32_t IM_CH246:1;
            vuint32_t IM_CH245:1;
            vuint32_t IM_CH244:1;
            vuint32_t IM_CH243:1;
            vuint32_t IM_CH242:1;
            vuint32_t IM_CH241:1;
            vuint32_t IM_CH240:1;
            vuint32_t IM_CH239:1;
            vuint32_t IM_CH238:1;
            vuint32_t IM_CH237:1;
            vuint32_t IM_CH236:1;
            vuint32_t IM_CH235:1;
            vuint32_t IM_CH234:1;
            vuint32_t IM_CH233:1;
            vuint32_t IM_CH232:1;
            vuint32_t IM_CH231:1;
            vuint32_t IM_CH230:1;
            vuint32_t IM_CH229:1;
            vuint32_t IM_CH228:1;
            vuint32_t IM_CH227:1;
            vuint32_t IM_CH226:1;
            vuint32_t IM_CH225:1;
            vuint32_t IM_CH224:1;
        } B;
    } ECIMR3;

    union {
        vuint32_t R;
        struct {
            vuint32_t DS_CH159:1;
            vuint32_t DS_CH158:1;
            vuint32_t DS_CH157:1;
            vuint32_t DS_CH156:1;
            vuint32_t DS_CH155:1;
            vuint32_t DS_CH154:1;
            vuint32_t DS_CH153:1;
            vuint32_t DS_CH152:1;
            vuint32_t DS_CH151:1;
            vuint32_t DS_CH150:1;
            vuint32_t DS_CH149:1;
            vuint32_t DS_CH148:1;
            vuint32_t DS_CH147:1;
            vuint32_t DS_CH146:1;
            vuint32_t DS_CH145:1;
            vuint32_t DS_CH144:1;
            vuint32_t DS_CH143:1;
            vuint32_t DS_CH142:1;
            vuint32_t DS_CH141:1;
            vuint32_t DS_CH140:1;
            vuint32_t DS_CH139:1;
            vuint32_t DS_CH138:1;
            vuint32_t DS_CH137:1;
            vuint32_t DS_CH136:1;
            vuint32_t DS_CH135:1;
            vuint32_t DS_CH134:1;
            vuint32_t DS_CH133:1;
            vuint32_t DS_CH132:1;
            vuint32_t DS_CH131:1;
            vuint32_t DS_CH130:1;
            vuint32_t DS_CH129:1;
            vuint32_t DS_CH128:1;
        } B;
    } ECDSR0;

    union {
        vuint32_t R;
        struct {
            vuint32_t DS_CH191:1;
            vuint32_t DS_CH190:1;
            vuint32_t DS_CH189:1;
            vuint32_t DS_CH188:1;
            vuint32_t DS_CH187:1;
            vuint32_t DS_CH186:1;
            vuint32_t DS_CH185:1;
            vuint32_t DS_CH184:1;
            vuint32_t DS_CH183:1;
            vuint32_t DS_CH182:1;
            vuint32_t DS_CH181:1;
            vuint32_t DS_CH180:1;
            vuint32_t DS_CH179:1;
            vuint32_t DS_CH178:1;
            vuint32_t DS_CH177:1;
            vuint32_t DS_CH176:1;
            vuint32_t DS_CH175:1;
            vuint32_t DS_CH174:1;
            vuint32_t DS_CH173:1;
            vuint32_t DS_CH172:1;
            vuint32_t DS_CH171:1;
            vuint32_t DS_CH170:1;
            vuint32_t DS_CH169:1;
            vuint32_t DS_CH168:1;
            vuint32_t DS_CH167:1;
            vuint32_t DS_CH166:1;
            vuint32_t DS_CH165:1;
            vuint32_t DS_CH164:1;
            vuint32_t DS_CH163:1;
            vuint32_t DS_CH162:1;
            vuint32_t DS_CH161:1;
            vuint32_t DS_CH160:1;
        } B;
    } ECDSR1;

    union {
        vuint32_t R;
        struct {
            vuint32_t DS_CH223:1;
            vuint32_t DS_CH222:1;
            vuint32_t DS_CH221:1;
            vuint32_t DS_CH220:1;
            vuint32_t DS_CH219:1;
            vuint32_t DS_CH218:1;
            vuint32_t DS_CH217:1;
            vuint32_t DS_CH216:1;
            vuint32_t DS_CH215:1;
            vuint32_t DS_CH214:1;
            vuint32_t DS_CH213:1;
            vuint32_t DS_CH212:1;
            vuint32_t DS_CH211:1;
            vuint32_t DS_CH210:1;
            vuint32_t DS_CH209:1;
            vuint32_t DS_CH208:1;
            vuint32_t DS_CH207:1;
            vuint32_t DS_CH206:1;
            vuint32_t DS_CH205:1;
            vuint32_t DS_CH204:1;
            vuint32_t DS_CH203:1;
            vuint32_t DS_CH202:1;
            vuint32_t DS_CH201:1;
            vuint32_t DS_CH200:1;
            vuint32_t DS_CH199:1;
            vuint32_t DS_CH198:1;
            vuint32_t DS_CH197:1;
            vuint32_t DS_CH196:1;
            vuint32_t DS_CH195:1;
            vuint32_t DS_CH194:1;
            vuint32_t DS_CH193:1;
            vuint32_t DS_CH192:1;
        } B;
    } ECDSR2;

    union {
        vuint32_t R;
        struct {
            vuint32_t DS_CH255:1;
            vuint32_t DS_CH254:1;
            vuint32_t DS_CH253:1;
            vuint32_t DS_CH252:1;
            vuint32_t DS_CH251:1;
            vuint32_t DS_CH250:1;
            vuint32_t DS_CH249:1;
            vuint32_t DS_CH248:1;
            vuint32_t DS_CH247:1;
            vuint32_t DS_CH246:1;
            vuint32_t DS_CH245:1;
            vuint32_t DS_CH244:1;
            vuint32_t DS_CH243:1;
            vuint32_t DS_CH242:1;
            vuint32_t DS_CH241:1;
            vuint32_t DS_CH240:1;
            vuint32_t DS_CH239:1;
            vuint32_t DS_CH238:1;
            vuint32_t DS_CH237:1;
            vuint32_t DS_CH236:1;
            vuint32_t DS_CH235:1;
            vuint32_t DS_CH234:1;
            vuint32_t DS_CH233:1;
            vuint32_t DS_CH232:1;
            vuint32_t DS_CH231:1;
            vuint32_t DS_CH230:1;
            vuint32_t DS_CH229:1;
            vuint32_t DS_CH228:1;
            vuint32_t DS_CH227:1;
            vuint32_t DS_CH226:1;
            vuint32_t DS_CH225:1;
            vuint32_t DS_CH224:1;
        } B;
    } ECDSR3;

    union {
        vuint32_t R;
        struct {
            vuint32_t NCE_CH159:1;
            vuint32_t NCE_CH158:1;
            vuint32_t NCE_CH157:1;
            vuint32_t NCE_CH156:1;
            vuint32_t NCE_CH155:1;
            vuint32_t NCE_CH154:1;
            vuint32_t NCE_CH153:1;
            vuint32_t NCE_CH152:1;
            vuint32_t NCE_CH151:1;
            vuint32_t NCE_CH150:1;
            vuint32_t NCE_CH149:1;
            vuint32_t NCE_CH148:1;
            vuint32_t NCE_CH147:1;
            vuint32_t NCE_CH146:1;
            vuint32_t NCE_CH145:1;
            vuint32_t NCE_CH144:1;
            vuint32_t NCE_CH143:1;
            vuint32_t NCE_CH142:1;
            vuint32_t NCE_CH141:1;
            vuint32_t NCE_CH140:1;
            vuint32_t NCE_CH139:1;
            vuint32_t NCE_CH138:1;
            vuint32_t NCE_CH137:1;
            vuint32_t NCE_CH136:1;
            vuint32_t NCE_CH135:1;
            vuint32_t NCE_CH134:1;
            vuint32_t NCE_CH133:1;
            vuint32_t NCE_CH132:1;
            vuint32_t NCE_CH131:1;
            vuint32_t NCE_CH130:1;
            vuint32_t NCE_CH129:1;
            vuint32_t NCE_CH128:1;
        } B;
    } ECNCMR0;

    union {
        vuint32_t R;
        struct {
            vuint32_t NCE_CH191:1;
            vuint32_t NCE_CH190:1;
            vuint32_t NCE_CH189:1;
            vuint32_t NCE_CH188:1;
            vuint32_t NCE_CH187:1;
            vuint32_t NCE_CH186:1;
            vuint32_t NCE_CH185:1;
            vuint32_t NCE_CH184:1;
            vuint32_t NCE_CH183:1;
            vuint32_t NCE_CH182:1;
            vuint32_t NCE_CH181:1;
            vuint32_t NCE_CH180:1;
            vuint32_t NCE_CH179:1;
            vuint32_t NCE_CH178:1;
            vuint32_t NCE_CH177:1;
            vuint32_t NCE_CH176:1;
            vuint32_t NCE_CH175:1;
            vuint32_t NCE_CH174:1;
            vuint32_t NCE_CH173:1;
            vuint32_t NCE_CH172:1;
            vuint32_t NCE_CH171:1;
            vuint32_t NCE_CH170:1;
            vuint32_t NCE_CH169:1;
            vuint32_t NCE_CH168:1;
            vuint32_t NCE_CH167:1;
            vuint32_t NCE_CH166:1;
            vuint32_t NCE_CH165:1;
            vuint32_t NCE_CH164:1;
            vuint32_t NCE_CH163:1;
            vuint32_t NCE_CH162:1;
            vuint32_t NCE_CH161:1;
            vuint32_t NCE_CH160:1;
        } B;
    } ECNCMR1;

    union {
        vuint32_t R;
        struct {
            vuint32_t NCE_CH223:1;
            vuint32_t NCE_CH222:1;
            vuint32_t NCE_CH221:1;
            vuint32_t NCE_CH220:1;
            vuint32_t NCE_CH219:1;
            vuint32_t NCE_CH218:1;
            vuint32_t NCE_CH217:1;
            vuint32_t NCE_CH216:1;
            vuint32_t NCE_CH215:1;
            vuint32_t NCE_CH214:1;
            vuint32_t NCE_CH213:1;
            vuint32_t NCE_CH212:1;
            vuint32_t NCE_CH211:1;
            vuint32_t NCE_CH210:1;
            vuint32_t NCE_CH209:1;
            vuint32_t NCE_CH208:1;
            vuint32_t NCE_CH207:1;
            vuint32_t NCE_CH206:1;
            vuint32_t NCE_CH205:1;
            vuint32_t NCE_CH204:1;
            vuint32_t NCE_CH203:1;
            vuint32_t NCE_CH202:1;
            vuint32_t NCE_CH201:1;
            vuint32_t NCE_CH200:1;
            vuint32_t NCE_CH199:1;
            vuint32_t NCE_CH198:1;
            vuint32_t NCE_CH197:1;
            vuint32_t NCE_CH196:1;
            vuint32_t NCE_CH195:1;
            vuint32_t NCE_CH194:1;
            vuint32_t NCE_CH193:1;
            vuint32_t NCE_CH192:1;
        } B;
    } ECNCMR2;

    union {
        vuint32_t R;
        struct {
            vuint32_t NCE_CH255:1;
            vuint32_t NCE_CH254:1;
            vuint32_t NCE_CH253:1;
            vuint32_t NCE_CH252:1;
            vuint32_t NCE_CH251:1;
            vuint32_t NCE_CH250:1;
            vuint32_t NCE_CH249:1;
            vuint32_t NCE_CH248:1;
            vuint32_t NCE_CH247:1;
            vuint32_t NCE_CH246:1;
            vuint32_t NCE_CH245:1;
            vuint32_t NCE_CH244:1;
            vuint32_t NCE_CH243:1;
            vuint32_t NCE_CH242:1;
            vuint32_t NCE_CH241:1;
            vuint32_t NCE_CH240:1;
            vuint32_t NCE_CH239:1;
            vuint32_t NCE_CH238:1;
            vuint32_t NCE_CH237:1;
            vuint32_t NCE_CH236:1;
            vuint32_t NCE_CH235:1;
            vuint32_t NCE_CH234:1;
            vuint32_t NCE_CH233:1;
            vuint32_t NCE_CH232:1;
            vuint32_t NCE_CH231:1;
            vuint32_t NCE_CH230:1;
            vuint32_t NCE_CH229:1;
            vuint32_t NCE_CH228:1;
            vuint32_t NCE_CH227:1;
            vuint32_t NCE_CH226:1;
            vuint32_t NCE_CH225:1;
            vuint32_t NCE_CH224:1;
        } B;
    } ECNCMR3;

    union {
        vuint32_t R;
        struct {
            vuint32_t JCE_CH159:1;
            vuint32_t JCE_CH158:1;
            vuint32_t JCE_CH157:1;
            vuint32_t JCE_CH156:1;
            vuint32_t JCE_CH155:1;
            vuint32_t JCE_CH154:1;
            vuint32_t JCE_CH153:1;
            vuint32_t JCE_CH152:1;
            vuint32_t JCE_CH151:1;
            vuint32_t JCE_CH150:1;
            vuint32_t JCE_CH149:1;
            vuint32_t JCE_CH148:1;
            vuint32_t JCE_CH147:1;
            vuint32_t JCE_CH146:1;
            vuint32_t JCE_CH145:1;
            vuint32_t JCE_CH144:1;
            vuint32_t JCE_CH143:1;
            vuint32_t JCE_CH142:1;
            vuint32_t JCE_CH141:1;
            vuint32_t JCE_CH140:1;
            vuint32_t JCE_CH139:1;
            vuint32_t JCE_CH138:1;
            vuint32_t JCE_CH137:1;
            vuint32_t JCE_CH136:1;
            vuint32_t JCE_CH135:1;
            vuint32_t JCE_CH134:1;
            vuint32_t JCE_CH133:1;
            vuint32_t JCE_CH132:1;
            vuint32_t JCE_CH131:1;
            vuint32_t JCE_CH130:1;
            vuint32_t JCE_CH129:1;
            vuint32_t JCE_CH128:1;
        } B;
    } ECJCMR0;

    union {
        vuint32_t R;
        struct {
            vuint32_t JCE_CH191:1;
            vuint32_t JCE_CH190:1;
            vuint32_t JCE_CH189:1;
            vuint32_t JCE_CH188:1;
            vuint32_t JCE_CH187:1;
            vuint32_t JCE_CH186:1;
            vuint32_t JCE_CH185:1;
            vuint32_t JCE_CH184:1;
            vuint32_t JCE_CH183:1;
            vuint32_t JCE_CH182:1;
            vuint32_t JCE_CH181:1;
            vuint32_t JCE_CH180:1;
            vuint32_t JCE_CH179:1;
            vuint32_t JCE_CH178:1;
            vuint32_t JCE_CH177:1;
            vuint32_t JCE_CH176:1;
            vuint32_t JCE_CH175:1;
            vuint32_t JCE_CH174:1;
            vuint32_t JCE_CH173:1;
            vuint32_t JCE_CH172:1;
            vuint32_t JCE_CH171:1;
            vuint32_t JCE_CH170:1;
            vuint32_t JCE_CH169:1;
            vuint32_t JCE_CH168:1;
            vuint32_t JCE_CH167:1;
            vuint32_t JCE_CH166:1;
            vuint32_t JCE_CH165:1;
            vuint32_t JCE_CH164:1;
            vuint32_t JCE_CH163:1;
            vuint32_t JCE_CH162:1;
            vuint32_t JCE_CH161:1;
            vuint32_t JCE_CH160:1;
        } B;
    } ECJCMR1;

    union {
        vuint32_t R;
        struct {
            vuint32_t JCE_CH223:1;
            vuint32_t JCE_CH222:1;
            vuint32_t JCE_CH221:1;
            vuint32_t JCE_CH220:1;
            vuint32_t JCE_CH219:1;
            vuint32_t JCE_CH218:1;
            vuint32_t JCE_CH217:1;
            vuint32_t JCE_CH216:1;
            vuint32_t JCE_CH215:1;
            vuint32_t JCE_CH214:1;
            vuint32_t JCE_CH213:1;
            vuint32_t JCE_CH212:1;
            vuint32_t JCE_CH211:1;
            vuint32_t JCE_CH210:1;
            vuint32_t JCE_CH209:1;
            vuint32_t JCE_CH208:1;
            vuint32_t JCE_CH207:1;
            vuint32_t JCE_CH206:1;
            vuint32_t JCE_CH205:1;
            vuint32_t JCE_CH204:1;
            vuint32_t JCE_CH203:1;
            vuint32_t JCE_CH202:1;
            vuint32_t JCE_CH201:1;
            vuint32_t JCE_CH200:1;
            vuint32_t JCE_CH199:1;
            vuint32_t JCE_CH198:1;
            vuint32_t JCE_CH197:1;
            vuint32_t JCE_CH196:1;
            vuint32_t JCE_CH195:1;
            vuint32_t JCE_CH194:1;
            vuint32_t JCE_CH193:1;
            vuint32_t JCE_CH192:1;
        } B;
    } ECJCMR2;

    union {
        vuint32_t R;
        struct {
            vuint32_t JCE_CH255:1;
            vuint32_t JCE_CH254:1;
            vuint32_t JCE_CH253:1;
            vuint32_t JCE_CH252:1;
            vuint32_t JCE_CH251:1;
            vuint32_t JCE_CH250:1;
            vuint32_t JCE_CH249:1;
            vuint32_t JCE_CH248:1;
            vuint32_t JCE_CH247:1;
            vuint32_t JCE_CH246:1;
            vuint32_t JCE_CH245:1;
            vuint32_t JCE_CH244:1;
            vuint32_t JCE_CH243:1;
            vuint32_t JCE_CH242:1;
            vuint32_t JCE_CH241:1;
            vuint32_t JCE_CH240:1;
            vuint32_t JCE_CH239:1;
            vuint32_t JCE_CH238:1;
            vuint32_t JCE_CH237:1;
            vuint32_t JCE_CH236:1;
            vuint32_t JCE_CH235:1;
            vuint32_t JCE_CH234:1;
            vuint32_t JCE_CH233:1;
            vuint32_t JCE_CH232:1;
            vuint32_t JCE_CH231:1;
            vuint32_t JCE_CH230:1;
            vuint32_t JCE_CH229:1;
            vuint32_t JCE_CH228:1;
            vuint32_t JCE_CH227:1;
            vuint32_t JCE_CH226:1;
            vuint32_t JCE_CH225:1;
            vuint32_t JCE_CH224:1;
        } B;
    } ECJCMR3;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH135:4;
            vuint32_t WSEL_CH134:4;
            vuint32_t WSEL_CH133:4;
            vuint32_t WSEL_CH132:4;
            vuint32_t WSEL_CH131:4;
            vuint32_t WSEL_CH130:4;
            vuint32_t WSEL_CH129:4;
            vuint32_t WSEL_CH128:4;
        } B;
    } ECWSELR0;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH143:4;
            vuint32_t WSEL_CH142:4;
            vuint32_t WSEL_CH141:4;
            vuint32_t WSEL_CH140:4;
            vuint32_t WSEL_CH139:4;
            vuint32_t WSEL_CH138:4;
            vuint32_t WSEL_CH137:4;
            vuint32_t WSEL_CH136:4;
        } B;
    } ECWSELR1;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH151:4;
            vuint32_t WSEL_CH150:4;
            vuint32_t WSEL_CH149:4;
            vuint32_t WSEL_CH148:4;
            vuint32_t WSEL_CH147:4;
            vuint32_t WSEL_CH146:4;
            vuint32_t WSEL_CH145:4;
            vuint32_t WSEL_CH144:4;
        } B;
    } ECWSELR2;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH159:4;
            vuint32_t WSEL_CH158:4;
            vuint32_t WSEL_CH157:4;
            vuint32_t WSEL_CH156:4;
            vuint32_t WSEL_CH155:4;
            vuint32_t WSEL_CH154:4;
            vuint32_t WSEL_CH153:4;
            vuint32_t WSEL_CH152:4;
        } B;
    } ECWSELR3;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH167:4;
            vuint32_t WSEL_CH166:4;
            vuint32_t WSEL_CH165:4;
            vuint32_t WSEL_CH164:4;
            vuint32_t WSEL_CH163:4;
            vuint32_t WSEL_CH162:4;
            vuint32_t WSEL_CH161:4;
            vuint32_t WSEL_CH160:4;
        } B;
    } ECWSELR4;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH175:4;
            vuint32_t WSEL_CH174:4;
            vuint32_t WSEL_CH173:4;
            vuint32_t WSEL_CH172:4;
            vuint32_t WSEL_CH171:4;
            vuint32_t WSEL_CH170:4;
            vuint32_t WSEL_CH169:4;
            vuint32_t WSEL_CH168:4;
        } B;
    } ECWSELR5;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH183:4;
            vuint32_t WSEL_CH182:4;
            vuint32_t WSEL_CH181:4;
            vuint32_t WSEL_CH180:4;
            vuint32_t WSEL_CH179:4;
            vuint32_t WSEL_CH178:4;
            vuint32_t WSEL_CH177:4;
            vuint32_t WSEL_CH176:4;
        } B;
    } ECWSELR6;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH191:4;
            vuint32_t WSEL_CH190:4;
            vuint32_t WSEL_CH189:4;
            vuint32_t WSEL_CH188:4;
            vuint32_t WSEL_CH187:4;
            vuint32_t WSEL_CH186:4;
            vuint32_t WSEL_CH185:4;
            vuint32_t WSEL_CH184:4;
        } B;
    } ECWSELR7;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH199:4;
            vuint32_t WSEL_CH198:4;
            vuint32_t WSEL_CH197:4;
            vuint32_t WSEL_CH196:4;
            vuint32_t WSEL_CH195:4;
            vuint32_t WSEL_CH194:4;
            vuint32_t WSEL_CH193:4;
            vuint32_t WSEL_CH192:4;
        } B;
    } ECWSELR8;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH207:4;
            vuint32_t WSEL_CH206:4;
            vuint32_t WSEL_CH205:4;
            vuint32_t WSEL_CH204:4;
            vuint32_t WSEL_CH203:4;
            vuint32_t WSEL_CH202:4;
            vuint32_t WSEL_CH201:4;
            vuint32_t WSEL_CH200:4;
        } B;
    } ECWSELR9;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH215:4;
            vuint32_t WSEL_CH214:4;
            vuint32_t WSEL_CH213:4;
            vuint32_t WSEL_CH212:4;
            vuint32_t WSEL_CH211:4;
            vuint32_t WSEL_CH210:4;
            vuint32_t WSEL_CH209:4;
            vuint32_t WSEL_CH208:4;
        } B;
    } ECWSELR10;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH223:4;
            vuint32_t WSEL_CH222:4;
            vuint32_t WSEL_CH221:4;
            vuint32_t WSEL_CH220:4;
            vuint32_t WSEL_CH219:4;
            vuint32_t WSEL_CH218:4;
            vuint32_t WSEL_CH217:4;
            vuint32_t WSEL_CH216:4;
        } B;
    } ECWSELR11;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH231:4;
            vuint32_t WSEL_CH230:4;
            vuint32_t WSEL_CH229:4;
            vuint32_t WSEL_CH228:4;
            vuint32_t WSEL_CH227:4;
            vuint32_t WSEL_CH226:4;
            vuint32_t WSEL_CH225:4;
            vuint32_t WSEL_CH224:4;
        } B;
    } ECWSELR12;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH239:4;
            vuint32_t WSEL_CH238:4;
            vuint32_t WSEL_CH237:4;
            vuint32_t WSEL_CH236:4;
            vuint32_t WSEL_CH235:4;
            vuint32_t WSEL_CH234:4;
            vuint32_t WSEL_CH233:4;
            vuint32_t WSEL_CH232:4;
        } B;
    } ECWSELR13;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH247:4;
            vuint32_t WSEL_CH246:4;
            vuint32_t WSEL_CH245:4;
            vuint32_t WSEL_CH244:4;
            vuint32_t WSEL_CH243:4;
            vuint32_t WSEL_CH242:4;
            vuint32_t WSEL_CH241:4;
            vuint32_t WSEL_CH240:4;
        } B;
    } ECWSELR14;

    union {
        vuint32_t R;
        struct {
            vuint32_t WSEL_CH255:4;
            vuint32_t WSEL_CH254:4;
            vuint32_t WSEL_CH253:4;
            vuint32_t WSEL_CH252:4;
            vuint32_t WSEL_CH251:4;
            vuint32_t WSEL_CH250:4;
            vuint32_t WSEL_CH249:4;
            vuint32_t WSEL_CH248:4;
        } B;
    } ECWSELR15;

    union {
        vuint32_t R;
        struct {
            vuint32_t WEN_CH159:1;
            vuint32_t WEN_CH158:1;
            vuint32_t WEN_CH157:1;
            vuint32_t WEN_CH156:1;
            vuint32_t WEN_CH155:1;
            vuint32_t WEN_CH154:1;
            vuint32_t WEN_CH153:1;
            vuint32_t WEN_CH152:1;
            vuint32_t WEN_CH151:1;
            vuint32_t WEN_CH150:1;
            vuint32_t WEN_CH149:1;
            vuint32_t WEN_CH148:1;
            vuint32_t WEN_CH147:1;
            vuint32_t WEN_CH146:1;
            vuint32_t WEN_CH145:1;
            vuint32_t WEN_CH144:1;
            vuint32_t WEN_CH143:1;
            vuint32_t WEN_CH142:1;
            vuint32_t WEN_CH141:1;
            vuint32_t WEN_CH140:1;
            vuint32_t WEN_CH139:1;
            vuint32_t WEN_CH138:1;
            vuint32_t WEN_CH137:1;
            vuint32_t WEN_CH136:1;
            vuint32_t WEN_CH135:1;
            vuint32_t WEN_CH134:1;
            vuint32_t WEN_CH133:1;
            vuint32_t WEN_CH132:1;
            vuint32_t WEN_CH131:1;
            vuint32_t WEN_CH130:1;
            vuint32_t WEN_CH129:1;
            vuint32_t WEN_CH128:1;
        } B;
    } ECWENR0;

    union {
        vuint32_t R;
        struct {
            vuint32_t WEN_CH191:1;
            vuint32_t WEN_CH190:1;
            vuint32_t WEN_CH189:1;
            vuint32_t WEN_CH188:1;
            vuint32_t WEN_CH187:1;
            vuint32_t WEN_CH186:1;
            vuint32_t WEN_CH185:1;
            vuint32_t WEN_CH184:1;
            vuint32_t WEN_CH183:1;
            vuint32_t WEN_CH182:1;
            vuint32_t WEN_CH181:1;
            vuint32_t WEN_CH180:1;
            vuint32_t WEN_CH179:1;
            vuint32_t WEN_CH178:1;
            vuint32_t WEN_CH177:1;
            vuint32_t WEN_CH176:1;
            vuint32_t WEN_CH175:1;
            vuint32_t WEN_CH174:1;
            vuint32_t WEN_CH173:1;
            vuint32_t WEN_CH172:1;
            vuint32_t WEN_CH171:1;
            vuint32_t WEN_CH170:1;
            vuint32_t WEN_CH169:1;
            vuint32_t WEN_CH168:1;
            vuint32_t WEN_CH167:1;
            vuint32_t WEN_CH166:1;
            vuint32_t WEN_CH165:1;
            vuint32_t WEN_CH164:1;
            vuint32_t WEN_CH163:1;
            vuint32_t WEN_CH162:1;
            vuint32_t WEN_CH161:1;
            vuint32_t WEN_CH160:1;
        } B;
    } ECWENR1;

    union {
        vuint32_t R;
        struct {
            vuint32_t WEN_CH223:1;
            vuint32_t WEN_CH222:1;
            vuint32_t WEN_CH221:1;
            vuint32_t WEN_CH220:1;
            vuint32_t WEN_CH219:1;
            vuint32_t WEN_CH218:1;
            vuint32_t WEN_CH217:1;
            vuint32_t WEN_CH216:1;
            vuint32_t WEN_CH215:1;
            vuint32_t WEN_CH214:1;
            vuint32_t WEN_CH213:1;
            vuint32_t WEN_CH212:1;
            vuint32_t WEN_CH211:1;
            vuint32_t WEN_CH210:1;
            vuint32_t WEN_CH209:1;
            vuint32_t WEN_CH208:1;
            vuint32_t WEN_CH207:1;
            vuint32_t WEN_CH206:1;
            vuint32_t WEN_CH205:1;
            vuint32_t WEN_CH204:1;
            vuint32_t WEN_CH203:1;
            vuint32_t WEN_CH202:1;
            vuint32_t WEN_CH201:1;
            vuint32_t WEN_CH200:1;
            vuint32_t WEN_CH199:1;
            vuint32_t WEN_CH198:1;
            vuint32_t WEN_CH197:1;
            vuint32_t WEN_CH196:1;
            vuint32_t WEN_CH195:1;
            vuint32_t WEN_CH194:1;
            vuint32_t WEN_CH193:1;
            vuint32_t WEN_CH192:1;
        } B;
    } ECWENR2;

    union {
        vuint32_t R;
        struct {
            vuint32_t WEN_CH255:1;
            vuint32_t WEN_CH254:1;
            vuint32_t WEN_CH253:1;
            vuint32_t WEN_CH252:1;
            vuint32_t WEN_CH251:1;
            vuint32_t WEN_CH250:1;
            vuint32_t WEN_CH249:1;
            vuint32_t WEN_CH248:1;
            vuint32_t WEN_CH247:1;
            vuint32_t WEN_CH246:1;
            vuint32_t WEN_CH245:1;
            vuint32_t WEN_CH244:1;
            vuint32_t WEN_CH243:1;
            vuint32_t WEN_CH242:1;
            vuint32_t WEN_CH241:1;
            vuint32_t WEN_CH240:1;
            vuint32_t WEN_CH239:1;
            vuint32_t WEN_CH238:1;
            vuint32_t WEN_CH237:1;
            vuint32_t WEN_CH236:1;
            vuint32_t WEN_CH235:1;
            vuint32_t WEN_CH234:1;
            vuint32_t WEN_CH233:1;
            vuint32_t WEN_CH232:1;
            vuint32_t WEN_CH231:1;
            vuint32_t WEN_CH230:1;
            vuint32_t WEN_CH229:1;
            vuint32_t WEN_CH228:1;
            vuint32_t WEN_CH227:1;
            vuint32_t WEN_CH226:1;
            vuint32_t WEN_CH225:1;
            vuint32_t WEN_CH224:1;
        } B;
    } ECWENR3;

    union {
        vuint32_t R;
        struct {
            vuint32_t AWOR_CH159:1;
            vuint32_t AWOR_CH158:1;
            vuint32_t AWOR_CH157:1;
            vuint32_t AWOR_CH156:1;
            vuint32_t AWOR_CH155:1;
            vuint32_t AWOR_CH154:1;
            vuint32_t AWOR_CH153:1;
            vuint32_t AWOR_CH152:1;
            vuint32_t AWOR_CH151:1;
            vuint32_t AWOR_CH150:1;
            vuint32_t AWOR_CH149:1;
            vuint32_t AWOR_CH148:1;
            vuint32_t AWOR_CH147:1;
            vuint32_t AWOR_CH146:1;
            vuint32_t AWOR_CH145:1;
            vuint32_t AWOR_CH144:1;
            vuint32_t AWOR_CH143:1;
            vuint32_t AWOR_CH142:1;
            vuint32_t AWOR_CH141:1;
            vuint32_t AWOR_CH140:1;
            vuint32_t AWOR_CH139:1;
            vuint32_t AWOR_CH138:1;
            vuint32_t AWOR_CH137:1;
            vuint32_t AWOR_CH136:1;
            vuint32_t AWOR_CH135:1;
            vuint32_t AWOR_CH134:1;
            vuint32_t AWOR_CH133:1;
            vuint32_t AWOR_CH132:1;
            vuint32_t AWOR_CH131:1;
            vuint32_t AWOR_CH130:1;
            vuint32_t AWOR_CH129:1;
            vuint32_t AWOR_CH128:1;
        } B;
    } ECAWORR0;

    union {
        vuint32_t R;
        struct {
            vuint32_t AWOR_CH191:1;
            vuint32_t AWOR_CH190:1;
            vuint32_t AWOR_CH189:1;
            vuint32_t AWOR_CH188:1;
            vuint32_t AWOR_CH187:1;
            vuint32_t AWOR_CH186:1;
            vuint32_t AWOR_CH185:1;
            vuint32_t AWOR_CH184:1;
            vuint32_t AWOR_CH183:1;
            vuint32_t AWOR_CH182:1;
            vuint32_t AWOR_CH181:1;
            vuint32_t AWOR_CH180:1;
            vuint32_t AWOR_CH179:1;
            vuint32_t AWOR_CH178:1;
            vuint32_t AWOR_CH177:1;
            vuint32_t AWOR_CH176:1;
            vuint32_t AWOR_CH175:1;
            vuint32_t AWOR_CH174:1;
            vuint32_t AWOR_CH173:1;
            vuint32_t AWOR_CH172:1;
            vuint32_t AWOR_CH171:1;
            vuint32_t AWOR_CH170:1;
            vuint32_t AWOR_CH169:1;
            vuint32_t AWOR_CH168:1;
            vuint32_t AWOR_CH167:1;
            vuint32_t AWOR_CH166:1;
            vuint32_t AWOR_CH165:1;
            vuint32_t AWOR_CH164:1;
            vuint32_t AWOR_CH163:1;
            vuint32_t AWOR_CH162:1;
            vuint32_t AWOR_CH161:1;
            vuint32_t AWOR_CH160:1;
        } B;
    } ECAWORR1;

    union {
        vuint32_t R;
        struct {
            vuint32_t AWOR_CH223:1;
            vuint32_t AWOR_CH222:1;
            vuint32_t AWOR_CH221:1;
            vuint32_t AWOR_CH220:1;
            vuint32_t AWOR_CH219:1;
            vuint32_t AWOR_CH218:1;
            vuint32_t AWOR_CH217:1;
            vuint32_t AWOR_CH216:1;
            vuint32_t AWOR_CH215:1;
            vuint32_t AWOR_CH214:1;
            vuint32_t AWOR_CH213:1;
            vuint32_t AWOR_CH212:1;
            vuint32_t AWOR_CH211:1;
            vuint32_t AWOR_CH210:1;
            vuint32_t AWOR_CH209:1;
            vuint32_t AWOR_CH208:1;
            vuint32_t AWOR_CH207:1;
            vuint32_t AWOR_CH206:1;
            vuint32_t AWOR_CH205:1;
            vuint32_t AWOR_CH204:1;
            vuint32_t AWOR_CH203:1;
            vuint32_t AWOR_CH202:1;
            vuint32_t AWOR_CH201:1;
            vuint32_t AWOR_CH200:1;
            vuint32_t AWOR_CH199:1;
            vuint32_t AWOR_CH198:1;
            vuint32_t AWOR_CH197:1;
            vuint32_t AWOR_CH196:1;
            vuint32_t AWOR_CH195:1;
            vuint32_t AWOR_CH194:1;
            vuint32_t AWOR_CH193:1;
            vuint32_t AWOR_CH192:1;
        } B;
    } ECAWORR2;

    union {
        vuint32_t R;
        struct {
            vuint32_t AWOR_CH255:1;
            vuint32_t AWOR_CH254:1;
            vuint32_t AWOR_CH253:1;
            vuint32_t AWOR_CH252:1;
            vuint32_t AWOR_CH251:1;
            vuint32_t AWOR_CH250:1;
            vuint32_t AWOR_CH249:1;
            vuint32_t AWOR_CH248:1;
            vuint32_t AWOR_CH247:1;
            vuint32_t AWOR_CH246:1;
            vuint32_t AWOR_CH245:1;
            vuint32_t AWOR_CH244:1;
            vuint32_t AWOR_CH243:1;
            vuint32_t AWOR_CH242:1;
            vuint32_t AWOR_CH241:1;
            vuint32_t AWOR_CH240:1;
            vuint32_t AWOR_CH239:1;
            vuint32_t AWOR_CH238:1;
            vuint32_t AWOR_CH237:1;
            vuint32_t AWOR_CH236:1;
            vuint32_t AWOR_CH235:1;
            vuint32_t AWOR_CH234:1;
            vuint32_t AWOR_CH233:1;
            vuint32_t AWOR_CH232:1;
            vuint32_t AWOR_CH231:1;
            vuint32_t AWOR_CH230:1;
            vuint32_t AWOR_CH229:1;
            vuint32_t AWOR_CH228:1;
            vuint32_t AWOR_CH227:1;
            vuint32_t AWOR_CH226:1;
            vuint32_t AWOR_CH225:1;
            vuint32_t AWOR_CH224:1;
        } B;
    } ECAWORR3;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:1;
            vuint32_t ICSEL_ECH159_152:7;
            vuint32_t unused_2:1;
            vuint32_t ICSEL_ECH151_144:7;
            vuint32_t unused_1:1;
            vuint32_t ICSEL_ECH143_136:7;
            vuint32_t unused_0:1;
            vuint32_t ICSEL_ECH135_128:7;
        } B;
    } ECMICR0;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:1;
            vuint32_t ICSEL_ECH191_184:7;
            vuint32_t unused_2:1;
            vuint32_t ICSEL_ECH183_176:7;
            vuint32_t unused_1:1;
            vuint32_t ICSEL_ECH175_168:7;
            vuint32_t unused_0:1;
            vuint32_t ICSEL_ECH167_160:7;
        } B;
    } ECMICR1;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:1;
            vuint32_t ICSEL_ECH223_216:7;
            vuint32_t unused_2:1;
            vuint32_t ICSEL_ECH215_208:7;
            vuint32_t unused_1:1;
            vuint32_t ICSEL_ECH207_200:7;
            vuint32_t unused_0:1;
            vuint32_t ICSEL_ECH199_192:7;
        } B;
    } ECMICR2;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:1;
            vuint32_t ICSEL_ECH255_248:7;
            vuint32_t unused_2:1;
            vuint32_t ICSEL_ECH247_240:7;
            vuint32_t unused_1:1;
            vuint32_t ICSEL_ECH239_232:7;
            vuint32_t unused_0:1;
            vuint32_t ICSEL_ECH231_224:7;
        } B;
    } ECMICR3;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:4;
            vuint32_t PCE:1;
            vuint32_t unused_1:1;
            vuint32_t CTSEL:2;
            vuint32_t unused_0:3;
            vuint32_t FCERR:1;
            vuint32_t VALID:1;
            vuint32_t OVERW:1;
            vuint32_t RESULT:2;
            vuint32_t CDATA:16;
        } B;
    } ECDR[128];

};

/**************************************************************************/
/*                 Module: SIUL2            */
/**************************************************************************/
struct SIUL2_tag {
    vuint8_t ADR_reserved0[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t PARTNUM:16;
            vuint32_t unused_1:1;
            vuint32_t PKG:5;
            vuint32_t unused_0:2;
            vuint32_t MAJOR_MASK:4;
            vuint32_t MINOR_MASK:4;
        } B;
    } MIDR1;

    union {
        vuint32_t R;
        struct {
            vuint32_t SF:1;
            vuint32_t FLASH_SIZE_1:4;
            vuint32_t FLASH_SIZE_2:4;
            vuint32_t unused_1:7;
            vuint32_t FAMILYNUM:8;
            vuint32_t unused_0:8;
        } B;
    } MIDR2;

    vuint8_t ADR_reserved1[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
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
    } DISR0;

    vuint8_t ADR_reserved2[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
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
    } DIRER0;

    vuint8_t ADR_reserved3[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t DIRS15:1;
            vuint32_t DIRS14:1;
            vuint32_t DIRS13:1;
            vuint32_t DIRS12:1;
            vuint32_t DIRS11:1;
            vuint32_t DIRS10:1;
            vuint32_t DIRS9:1;
            vuint32_t DIRS8:1;
            vuint32_t DIRS7:1;
            vuint32_t DIRS6:1;
            vuint32_t DIRS5:1;
            vuint32_t DIRS4:1;
            vuint32_t DIRS3:1;
            vuint32_t DIRS2:1;
            vuint32_t DIRS1:1;
            vuint32_t DIRS0:1;
        } B;
    } DIRSR0;

    vuint8_t ADR_reserved4[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
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
    } IREER0;

    vuint8_t ADR_reserved5[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
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
    } IFEER0;

    vuint8_t ADR_reserved6[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
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
    } IFER0;

    vuint8_t ADR_reserved7[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:28;
            vuint32_t MAXCNT:4;
        } B;
    } IFMCR[32];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:28;
            vuint32_t IFCP:4;
        } B;
    } IFCPR;

    vuint8_t ADR_reserved8[60];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:28;
            vuint32_t PAD_53:1;
            vuint32_t unused_1:1;
            vuint32_t PAD_25:1;
            vuint32_t unused_0:1;
        } B;
    } SCR0;

    vuint8_t ADR_reserved9[316];

	union {
		vuint32_t R;
			struct {
			vuint32_t unused_4:2;
			vuint32_t OERC:2;
			vuint32_t unused_3:1;
			vuint32_t ODC:3;
			vuint32_t SMC:1;
			vuint32_t unused_2:1;
			vuint32_t ILS:2;
			vuint32_t IBE:1;
			vuint32_t unused_1:1;
			vuint32_t WPDE:1;
			vuint32_t WPUE:1;
			vuint32_t INV:1;
			vuint32_t unused_0:7;
			vuint32_t SSS:8;
		} B;
	} MSCR_IO[512];
	union {
		vuint32_t R;
		struct {
			vuint32_t unused_1:16;
			vuint32_t INV:1;
			vuint32_t unused_0:7;
			vuint32_t SSS:8;
		} B;
	} MSCR_MUX[512];
	
    vuint8_t ADR_reserved10[192];

    union {
        vuint8_t R;
        struct {
            vuint8_t unused_0:7;
            vuint8_t PDO:1;
        } B;
    } GPDO[512];

    union {
        vuint8_t R;
        struct {
            vuint8_t unused_0:7;
            vuint8_t PDI:1;
        } B;
    } GPDI[512];

    union {
        vuint16_t R;
        struct {
            vuint16_t PPDO:16;
        } B;
    } PGPDO[13];

    vuint8_t ADR_reserved11[38];

    union {
        vuint16_t R;
        struct {
            vuint16_t PPDI:16;
        } B;
    } PGPDI[13];

    vuint8_t ADR_reserved12[38];

    union {
        vuint32_t R;
        struct {
            vuint32_t MASK:16;
            vuint32_t MPPDO:16;
        } B;
    } MPGPDO[13];

};

/**************************************************************************/
/*                 Module: SMPU            */
/**************************************************************************/
struct SMPU_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t MERR:16;
            vuint32_t unused_0:12;
            vuint32_t HRL:3;
            vuint32_t GVLD:1;
        } B;
    } CESR0;

    union {
        vuint32_t R;
        struct {
            vuint32_t MEOVR:16;
            vuint32_t unused_0:12;
            vuint32_t NRGD:4;
        } B;
    } CESR1;

    vuint8_t ADR_reserved0[248];

    struct {
        union {
            vuint32_t R;
            struct {
                vuint32_t EADDR:32;
            } B;
        } EAR;

        union {
            vuint32_t R;
            struct {
                vuint32_t EACD:24;
                vuint32_t unused_0:1;
                vuint32_t EATTR:2;
                vuint32_t ERW:1;
                vuint32_t EMN:4;
            } B;
        } EDR;

    } ERROR[16];

    vuint8_t ADR_reserved1[640];

    struct {
        union {
            vuint32_t R;
            struct {
                vuint32_t SRTADDR:32;
            } B;
        } WORD0;

        union {
            vuint32_t R;
            struct {
                vuint32_t ENDADDR:32;
            } B;
        } WORD1;

        union {
            vuint32_t R;
            struct {
                vuint32_t M0P:2;
                vuint32_t M1P:2;
                vuint32_t M2P:2;
                vuint32_t M3P:2;
                vuint32_t M4P:2;
                vuint32_t M5P:2;
                vuint32_t M6P:2;
                vuint32_t M7P:2;
                vuint32_t M8P:2;
                vuint32_t M9P:2;
                vuint32_t M10P:2;
                vuint32_t M11P:2;
                vuint32_t M12P:2;
                vuint32_t M13P:2;
                vuint32_t M14P:2;
                vuint32_t M15P:2;
            } B;
        } WORD2_FMT0;

        union {
            vuint32_t R;
            struct {
                vuint32_t unused_1:27;
                vuint32_t FMT:1;
                vuint32_t RO:1;
                vuint32_t unused_0:1;
                vuint32_t CI:1;
                vuint32_t VLD:1;
            } B;
        } WORD3;

    } RGD[12];

};

/**************************************************************************/
/*                 Module: SSCM            */
/**************************************************************************/
struct SSCM_tag {
    union {
        vuint16_t R;
        struct {
            vuint16_t unused_3:1;
            vuint16_t CER:1;
            vuint16_t unused_2:1;
            vuint16_t NXEN1:1;
            vuint16_t NXEN:1;
            vuint16_t unused_1:3;
            vuint16_t BMODE:3;
            vuint16_t VLE:1;
            vuint16_t unused_0:4;
        } B;
    } STATUS;

    union {
        vuint16_t R;
        struct {
            vuint16_t JPIN:10;
            vuint16_t unused_1:1;
            vuint16_t MREV:4;
            vuint16_t unused_0:1;
        } B;
    } MEMCONFIG;

    vuint8_t ADR_reserved0[2];

    union {
        vuint16_t R;
        struct {
            vuint16_t unused_0:14;
            vuint16_t PAE:1;
            vuint16_t RAE:1;
        } B;
    } ERROR;

    vuint8_t ADR_reserved1[32];

    union {
        vuint32_t R;
        struct {
            vuint32_t SADR:32;
        } B;
    } PSA;

    vuint8_t ADR_reserved2[8];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:29;
            vuint32_t LC:3;
        } B;
    } LCSTAT;

};

/**************************************************************************/
/*                 Module: STCU2            */
/**************************************************************************/
struct STCU2_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:21;
            vuint32_t BYP:1;
            vuint32_t MBPLLEN:1;
            vuint32_t LBPLLEN:1;
            vuint32_t unused_0:7;
            vuint32_t RUN:1;
        } B;
    } RUN;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:20;
            vuint32_t MBIE:1;
            vuint32_t LBIE:1;
            vuint32_t MBSWPLLEN:1;
            vuint32_t LBSWPLLEN:1;
            vuint32_t unused_0:7;
            vuint32_t RUNSW:1;
        } B;
    } RUNSW;

    union {
        vuint32_t R;
        struct {
            vuint32_t SKC:32;
        } B;
    } SKC;

    union {
        vuint32_t R;
        struct {
            vuint32_t PTR:8;
            vuint32_t LB_DELAY:8;
            vuint32_t unused_1:7;
            vuint32_t WRP:1;
            vuint32_t unused_0:2;
            vuint32_t CRCEN:1;
            vuint32_t PMOSEN:1;
            vuint32_t MBU:1;
            vuint32_t CLK_CFG:3;
        } B;
    } CFG;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:2;
            vuint32_t PLLODF:6;
            vuint32_t unused_1:5;
            vuint32_t PLLIDF:3;
            vuint32_t unused_0:9;
            vuint32_t PLLLDF:7;
        } B;
    } PLL_CFG;

    union {
        vuint32_t R;
        struct {
            vuint32_t WDGEOC:32;
        } B;
    } WDG;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:30;
            vuint32_t MBIFLG:1;
            vuint32_t LBIFLG:1;
        } B;
    } INT_FLG;

    union {
        vuint32_t R;
        struct {
            vuint32_t CRCE:32;
        } B;
    } CRCE;

    union {
        vuint32_t R;
        struct {
            vuint32_t CRCR:32;
        } B;
    } CRCR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_3:6;
            vuint32_t ABORTHW:1;
            vuint32_t unused_2:4;
            vuint32_t LOCKESW:1;
            vuint32_t WDTOSW:1;
            vuint32_t CRCSSW:1;
            vuint32_t ENGESW:1;
            vuint32_t INVPSW:1;
            vuint32_t unused_1:6;
            vuint32_t UFSF:1;
            vuint32_t RFSF:1;
            vuint32_t unused_0:3;
            vuint32_t LOCKE:1;
            vuint32_t WDTO:1;
            vuint32_t CRCS:1;
            vuint32_t ENGE:1;
            vuint32_t INVP:1;
        } B;
    } ERR_STAT;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:27;
            vuint32_t LOCKEUFM:1;
            vuint32_t WDTOUFM:1;
            vuint32_t CRCSUFM:1;
            vuint32_t ENGEUFM:1;
            vuint32_t INVPUFM:1;
        } B;
    } ERR_FM;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:24;
            vuint32_t LBS7:1;
            vuint32_t LBS6:1;
            vuint32_t LBS5:1;
            vuint32_t LBS4:1;
            vuint32_t LBS3:1;
            vuint32_t LBS2:1;
            vuint32_t LBS1:1;
            vuint32_t LBS0:1;
        } B;
    } LBS;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:24;
            vuint32_t LBE7:1;
            vuint32_t LBE6:1;
            vuint32_t LBE5:1;
            vuint32_t LBE4:1;
            vuint32_t LBE3:1;
            vuint32_t LBE2:1;
            vuint32_t LBE1:1;
            vuint32_t LBE0:1;
        } B;
    } LBE;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:24;
            vuint32_t LBSSW7:1;
            vuint32_t LBSSW6:1;
            vuint32_t LBSSW5:1;
            vuint32_t LBSSW4:1;
            vuint32_t LBSSW3:1;
            vuint32_t LBSSW2:1;
            vuint32_t LBSSW1:1;
            vuint32_t LBSSW0:1;
        } B;
    } LBSSW;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t LBESW15:1;
            vuint32_t LBESW14:1;
            vuint32_t LBESW13:1;
            vuint32_t LBESW12:1;
            vuint32_t LBESW11:1;
            vuint32_t LBESW10:1;
            vuint32_t LBESW9:1;
            vuint32_t LBESW8:1;
            vuint32_t LBESW7:1;
            vuint32_t LBESW6:1;
            vuint32_t LBESW5:1;
            vuint32_t LBESW4:1;
            vuint32_t LBESW3:1;
            vuint32_t LBESW2:1;
            vuint32_t LBESW1:1;
            vuint32_t LBESW0:1;
        } B;
    } LBESW;

    vuint8_t ADR_reserved0[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t LBUFM15:1;
            vuint32_t LBUFM14:1;
            vuint32_t LBUFM13:1;
            vuint32_t LBUFM12:1;
            vuint32_t LBUFM11:1;
            vuint32_t LBUFM10:1;
            vuint32_t LBUFM9:1;
            vuint32_t LBUFM8:1;
            vuint32_t LBUFM7:1;
            vuint32_t LBUFM6:1;
            vuint32_t LBUFM5:1;
            vuint32_t LBUFM4:1;
            vuint32_t LBUFM3:1;
            vuint32_t LBUFM2:1;
            vuint32_t LBUFM1:1;
            vuint32_t LBUFM0:1;
        } B;
    } LBUFM;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBS31:1;
            vuint32_t MBS30:1;
            vuint32_t MBS29:1;
            vuint32_t MBS28:1;
            vuint32_t MBS27:1;
            vuint32_t MBS26:1;
            vuint32_t MBS25:1;
            vuint32_t MBS24:1;
            vuint32_t MBS23:1;
            vuint32_t MBS22:1;
            vuint32_t MBS21:1;
            vuint32_t MBS20:1;
            vuint32_t MBS19:1;
            vuint32_t MBS18:1;
            vuint32_t MBS17:1;
            vuint32_t MBS16:1;
            vuint32_t MBS15:1;
            vuint32_t MBS14:1;
            vuint32_t MBS13:1;
            vuint32_t MBS12:1;
            vuint32_t MBS11:1;
            vuint32_t MBS10:1;
            vuint32_t MBS9:1;
            vuint32_t MBS8:1;
            vuint32_t MBS7:1;
            vuint32_t MBS6:1;
            vuint32_t MBS5:1;
            vuint32_t MBS4:1;
            vuint32_t MBS3:1;
            vuint32_t MBS2:1;
            vuint32_t MBS1:1;
            vuint32_t MBS0:1;
        } B;
    } MBS1;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBS63:1;
            vuint32_t MBS62:1;
            vuint32_t MBS61:1;
            vuint32_t MBS60:1;
            vuint32_t MBS59:1;
            vuint32_t MBS58:1;
            vuint32_t MBS57:1;
            vuint32_t MBS56:1;
            vuint32_t MBS55:1;
            vuint32_t MBS54:1;
            vuint32_t MBS53:1;
            vuint32_t MBS52:1;
            vuint32_t MBS51:1;
            vuint32_t MBS50:1;
            vuint32_t MBS49:1;
            vuint32_t MBS48:1;
            vuint32_t MBS47:1;
            vuint32_t MBS46:1;
            vuint32_t MBS45:1;
            vuint32_t MBS44:1;
            vuint32_t MBS43:1;
            vuint32_t MBS42:1;
            vuint32_t MBS41:1;
            vuint32_t MBS40:1;
            vuint32_t MBS39:1;
            vuint32_t MBS38:1;
            vuint32_t MBS37:1;
            vuint32_t MBS36:1;
            vuint32_t MBS35:1;
            vuint32_t MBS34:1;
            vuint32_t MBS33:1;
            vuint32_t MBS32:1;
        } B;
    } MBS2;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBS95:1;
            vuint32_t MBS94:1;
            vuint32_t MBS93:1;
            vuint32_t MBS92:1;
            vuint32_t MBS91:1;
            vuint32_t MBS90:1;
            vuint32_t MBS89:1;
            vuint32_t MBS88:1;
            vuint32_t MBS87:1;
            vuint32_t MBS86:1;
            vuint32_t MBS85:1;
            vuint32_t MBS84:1;
            vuint32_t MBS83:1;
            vuint32_t MBS82:1;
            vuint32_t MBS81:1;
            vuint32_t MBS80:1;
            vuint32_t MBS79:1;
            vuint32_t MBS78:1;
            vuint32_t MBS77:1;
            vuint32_t MBS76:1;
            vuint32_t MBS75:1;
            vuint32_t MBS74:1;
            vuint32_t MBS73:1;
            vuint32_t MBS72:1;
            vuint32_t MBS71:1;
            vuint32_t MBS70:1;
            vuint32_t MBS69:1;
            vuint32_t MBS68:1;
            vuint32_t MBS67:1;
            vuint32_t MBS66:1;
            vuint32_t MBS65:1;
            vuint32_t MBS64:1;
        } B;
    } MBS3;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBS127:1;
            vuint32_t MBS126:1;
            vuint32_t MBS125:1;
            vuint32_t MBS124:1;
            vuint32_t MBS123:1;
            vuint32_t MBS122:1;
            vuint32_t MBS121:1;
            vuint32_t MBS120:1;
            vuint32_t MBS119:1;
            vuint32_t MBS118:1;
            vuint32_t MBS117:1;
            vuint32_t MBS116:1;
            vuint32_t MBS115:1;
            vuint32_t MBS114:1;
            vuint32_t MBS113:1;
            vuint32_t MBS112:1;
            vuint32_t MBS111:1;
            vuint32_t MBS110:1;
            vuint32_t MBS109:1;
            vuint32_t MBS108:1;
            vuint32_t MBS107:1;
            vuint32_t MBS106:1;
            vuint32_t MBS105:1;
            vuint32_t MBS104:1;
            vuint32_t MBS103:1;
            vuint32_t MBS102:1;
            vuint32_t MBS101:1;
            vuint32_t MBS100:1;
            vuint32_t MBS99:1;
            vuint32_t MBS98:1;
            vuint32_t MBS97:1;
            vuint32_t MBS96:1;
        } B;
    } MBS4;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBE31:1;
            vuint32_t MBE30:1;
            vuint32_t MBE29:1;
            vuint32_t MBE28:1;
            vuint32_t MBE27:1;
            vuint32_t MBE26:1;
            vuint32_t MBE25:1;
            vuint32_t MBE24:1;
            vuint32_t MBE23:1;
            vuint32_t MBE22:1;
            vuint32_t MBE21:1;
            vuint32_t MBE20:1;
            vuint32_t MBE19:1;
            vuint32_t MBE18:1;
            vuint32_t MBE17:1;
            vuint32_t MBE16:1;
            vuint32_t MBE15:1;
            vuint32_t MBE14:1;
            vuint32_t MBE13:1;
            vuint32_t MBE12:1;
            vuint32_t MBE11:1;
            vuint32_t MBE10:1;
            vuint32_t MBE9:1;
            vuint32_t MBE8:1;
            vuint32_t MBE7:1;
            vuint32_t MBE6:1;
            vuint32_t MBE5:1;
            vuint32_t MBE4:1;
            vuint32_t MBE3:1;
            vuint32_t MBE2:1;
            vuint32_t MBE1:1;
            vuint32_t MBE0:1;
        } B;
    } MBE1;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBE63:1;
            vuint32_t MBE62:1;
            vuint32_t MBE61:1;
            vuint32_t MBE60:1;
            vuint32_t MBE59:1;
            vuint32_t MBE58:1;
            vuint32_t MBE57:1;
            vuint32_t MBE56:1;
            vuint32_t MBE55:1;
            vuint32_t MBE54:1;
            vuint32_t MBE53:1;
            vuint32_t MBE52:1;
            vuint32_t MBE51:1;
            vuint32_t MBE50:1;
            vuint32_t MBE49:1;
            vuint32_t MBE48:1;
            vuint32_t MBE47:1;
            vuint32_t MBE46:1;
            vuint32_t MBE45:1;
            vuint32_t MBE44:1;
            vuint32_t MBE43:1;
            vuint32_t MBE42:1;
            vuint32_t MBE41:1;
            vuint32_t MBE40:1;
            vuint32_t MBE39:1;
            vuint32_t MBE38:1;
            vuint32_t MBE37:1;
            vuint32_t MBE36:1;
            vuint32_t MBE35:1;
            vuint32_t MBE34:1;
            vuint32_t MBE33:1;
            vuint32_t MBE32:1;
        } B;
    } MBE2;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBE95:1;
            vuint32_t MBE94:1;
            vuint32_t MBE93:1;
            vuint32_t MBE92:1;
            vuint32_t MBE91:1;
            vuint32_t MBE90:1;
            vuint32_t MBE89:1;
            vuint32_t MBE88:1;
            vuint32_t MBE87:1;
            vuint32_t MBE86:1;
            vuint32_t MBE85:1;
            vuint32_t MBE84:1;
            vuint32_t MBE83:1;
            vuint32_t MBE82:1;
            vuint32_t MBE81:1;
            vuint32_t MBE80:1;
            vuint32_t MBE79:1;
            vuint32_t MBE78:1;
            vuint32_t MBE77:1;
            vuint32_t MBE76:1;
            vuint32_t MBE75:1;
            vuint32_t MBE74:1;
            vuint32_t MBE73:1;
            vuint32_t MBE72:1;
            vuint32_t MBE71:1;
            vuint32_t MBE70:1;
            vuint32_t MBE69:1;
            vuint32_t MBE68:1;
            vuint32_t MBE67:1;
            vuint32_t MBE66:1;
            vuint32_t MBE65:1;
            vuint32_t MBE64:1;
        } B;
    } MBE3;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBE127:1;
            vuint32_t MBE126:1;
            vuint32_t MBE125:1;
            vuint32_t MBE124:1;
            vuint32_t MBE123:1;
            vuint32_t MBE122:1;
            vuint32_t MBE121:1;
            vuint32_t MBE120:1;
            vuint32_t MBE119:1;
            vuint32_t MBE118:1;
            vuint32_t MBE117:1;
            vuint32_t MBE116:1;
            vuint32_t MBE115:1;
            vuint32_t MBE114:1;
            vuint32_t MBE113:1;
            vuint32_t MBE112:1;
            vuint32_t MBE111:1;
            vuint32_t MBE110:1;
            vuint32_t MBE109:1;
            vuint32_t MBE108:1;
            vuint32_t MBE107:1;
            vuint32_t MBE106:1;
            vuint32_t MBE105:1;
            vuint32_t MBE104:1;
            vuint32_t MBE103:1;
            vuint32_t MBE102:1;
            vuint32_t MBE101:1;
            vuint32_t MBE100:1;
            vuint32_t MBE99:1;
            vuint32_t MBE98:1;
            vuint32_t MBE97:1;
            vuint32_t MBE96:1;
        } B;
    } MBE4;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBSSW31:1;
            vuint32_t MBSSW30:1;
            vuint32_t MBSSW29:1;
            vuint32_t MBSSW28:1;
            vuint32_t MBSSW27:1;
            vuint32_t MBSSW26:1;
            vuint32_t MBSSW25:1;
            vuint32_t MBSSW24:1;
            vuint32_t MBSSW23:1;
            vuint32_t MBSSW22:1;
            vuint32_t MBSSW21:1;
            vuint32_t MBSSW20:1;
            vuint32_t MBSSW19:1;
            vuint32_t MBSSW18:1;
            vuint32_t MBSSW17:1;
            vuint32_t MBSSW16:1;
            vuint32_t MBSSW15:1;
            vuint32_t MBSSW14:1;
            vuint32_t MBSSW13:1;
            vuint32_t MBSSW12:1;
            vuint32_t MBSSW11:1;
            vuint32_t MBSSW10:1;
            vuint32_t MBSSW9:1;
            vuint32_t MBSSW8:1;
            vuint32_t MBSSW7:1;
            vuint32_t MBSSW6:1;
            vuint32_t MBSSW5:1;
            vuint32_t MBSSW4:1;
            vuint32_t MBSSW3:1;
            vuint32_t MBSSW2:1;
            vuint32_t MBSSW1:1;
            vuint32_t MBSSW0:1;
        } B;
    } MBS1SW;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBSSW63:1;
            vuint32_t MBSSW62:1;
            vuint32_t MBSSW61:1;
            vuint32_t MBSSW60:1;
            vuint32_t MBSSW59:1;
            vuint32_t MBSSW58:1;
            vuint32_t MBSSW57:1;
            vuint32_t MBSSW56:1;
            vuint32_t MBSSW55:1;
            vuint32_t MBSSW54:1;
            vuint32_t MBSSW53:1;
            vuint32_t MBSSW52:1;
            vuint32_t MBSSW51:1;
            vuint32_t MBSSW50:1;
            vuint32_t MBSSW49:1;
            vuint32_t MBSSW48:1;
            vuint32_t MBSSW47:1;
            vuint32_t MBSSW46:1;
            vuint32_t MBSSW45:1;
            vuint32_t MBSSW44:1;
            vuint32_t MBSSW43:1;
            vuint32_t MBSSW42:1;
            vuint32_t MBSSW41:1;
            vuint32_t MBSSW40:1;
            vuint32_t MBSSW39:1;
            vuint32_t MBSSW38:1;
            vuint32_t MBSSW37:1;
            vuint32_t MBSSW36:1;
            vuint32_t MBSSW35:1;
            vuint32_t MBSSW34:1;
            vuint32_t MBSSW33:1;
            vuint32_t MBSSW32:1;
        } B;
    } MBS2SW;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBSSW95:1;
            vuint32_t MBSSW94:1;
            vuint32_t MBSSW93:1;
            vuint32_t MBSSW92:1;
            vuint32_t MBSSW91:1;
            vuint32_t MBSSW90:1;
            vuint32_t MBSSW89:1;
            vuint32_t MBSSW88:1;
            vuint32_t MBSSW87:1;
            vuint32_t MBSSW86:1;
            vuint32_t MBSSW85:1;
            vuint32_t MBSSW84:1;
            vuint32_t MBSSW83:1;
            vuint32_t MBSSW82:1;
            vuint32_t MBSSW81:1;
            vuint32_t MBSSW80:1;
            vuint32_t MBSSW79:1;
            vuint32_t MBSSW78:1;
            vuint32_t MBSSW77:1;
            vuint32_t MBSSW76:1;
            vuint32_t MBSSW75:1;
            vuint32_t MBSSW74:1;
            vuint32_t MBSSW73:1;
            vuint32_t MBSSW72:1;
            vuint32_t MBSSW71:1;
            vuint32_t MBSSW70:1;
            vuint32_t MBSSW69:1;
            vuint32_t MBSSW68:1;
            vuint32_t MBSSW67:1;
            vuint32_t MBSSW66:1;
            vuint32_t MBSSW65:1;
            vuint32_t MBSSW64:1;
        } B;
    } MBS3SW;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBSSW127:1;
            vuint32_t MBSSW126:1;
            vuint32_t MBSSW125:1;
            vuint32_t MBSSW124:1;
            vuint32_t MBSSW123:1;
            vuint32_t MBSSW122:1;
            vuint32_t MBSSW121:1;
            vuint32_t MBSSW120:1;
            vuint32_t MBSSW119:1;
            vuint32_t MBSSW118:1;
            vuint32_t MBSSW117:1;
            vuint32_t MBSSW116:1;
            vuint32_t MBSSW115:1;
            vuint32_t MBSSW114:1;
            vuint32_t MBSSW113:1;
            vuint32_t MBSSW112:1;
            vuint32_t MBSSW111:1;
            vuint32_t MBSSW110:1;
            vuint32_t MBSSW109:1;
            vuint32_t MBSSW108:1;
            vuint32_t MBSSW107:1;
            vuint32_t MBSSW106:1;
            vuint32_t MBSSW105:1;
            vuint32_t MBSSW104:1;
            vuint32_t MBSSW103:1;
            vuint32_t MBSSW102:1;
            vuint32_t MBSSW101:1;
            vuint32_t MBSSW100:1;
            vuint32_t MBSSW99:1;
            vuint32_t MBSSW98:1;
            vuint32_t MBSSW97:1;
            vuint32_t MBSSW96:1;
        } B;
    } MBS4SW;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBESW31:1;
            vuint32_t MBESW30:1;
            vuint32_t MBESW29:1;
            vuint32_t MBESW28:1;
            vuint32_t MBESW27:1;
            vuint32_t MBESW26:1;
            vuint32_t MBESW25:1;
            vuint32_t MBESW24:1;
            vuint32_t MBESW23:1;
            vuint32_t MBESW22:1;
            vuint32_t MBESW21:1;
            vuint32_t MBESW20:1;
            vuint32_t MBESW19:1;
            vuint32_t MBESW18:1;
            vuint32_t MBESW17:1;
            vuint32_t MBESW16:1;
            vuint32_t MBESW15:1;
            vuint32_t MBESW14:1;
            vuint32_t MBESW13:1;
            vuint32_t MBESW12:1;
            vuint32_t MBESW11:1;
            vuint32_t MBESW10:1;
            vuint32_t MBESW9:1;
            vuint32_t MBESW8:1;
            vuint32_t MBESW7:1;
            vuint32_t MBESW6:1;
            vuint32_t MBESW5:1;
            vuint32_t MBESW4:1;
            vuint32_t MBESW3:1;
            vuint32_t MBESW2:1;
            vuint32_t MBESW1:1;
            vuint32_t MBESW0:1;
        } B;
    } MBE1SW;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBESW63:1;
            vuint32_t MBESW62:1;
            vuint32_t MBESW61:1;
            vuint32_t MBESW60:1;
            vuint32_t MBESW59:1;
            vuint32_t MBESW58:1;
            vuint32_t MBESW57:1;
            vuint32_t MBESW56:1;
            vuint32_t MBESW55:1;
            vuint32_t MBESW54:1;
            vuint32_t MBESW53:1;
            vuint32_t MBESW52:1;
            vuint32_t MBESW51:1;
            vuint32_t MBESW50:1;
            vuint32_t MBESW49:1;
            vuint32_t MBESW48:1;
            vuint32_t MBESW47:1;
            vuint32_t MBESW46:1;
            vuint32_t MBESW45:1;
            vuint32_t MBESW44:1;
            vuint32_t MBESW43:1;
            vuint32_t MBESW42:1;
            vuint32_t MBESW41:1;
            vuint32_t MBESW40:1;
            vuint32_t MBESW39:1;
            vuint32_t MBESW38:1;
            vuint32_t MBESW37:1;
            vuint32_t MBESW36:1;
            vuint32_t MBESW35:1;
            vuint32_t MBESW34:1;
            vuint32_t MBESW33:1;
            vuint32_t MBESW32:1;
        } B;
    } MBE2SW;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBESW95:1;
            vuint32_t MBESW94:1;
            vuint32_t MBESW93:1;
            vuint32_t MBESW92:1;
            vuint32_t MBESW91:1;
            vuint32_t MBESW90:1;
            vuint32_t MBESW89:1;
            vuint32_t MBESW88:1;
            vuint32_t MBESW87:1;
            vuint32_t MBESW86:1;
            vuint32_t MBESW85:1;
            vuint32_t MBESW84:1;
            vuint32_t MBESW83:1;
            vuint32_t MBESW82:1;
            vuint32_t MBESW81:1;
            vuint32_t MBESW80:1;
            vuint32_t MBESW79:1;
            vuint32_t MBESW78:1;
            vuint32_t MBESW77:1;
            vuint32_t MBESW76:1;
            vuint32_t MBESW75:1;
            vuint32_t MBESW74:1;
            vuint32_t MBESW73:1;
            vuint32_t MBESW72:1;
            vuint32_t MBESW71:1;
            vuint32_t MBESW70:1;
            vuint32_t MBESW69:1;
            vuint32_t MBESW68:1;
            vuint32_t MBESW67:1;
            vuint32_t MBESW66:1;
            vuint32_t MBESW65:1;
            vuint32_t MBESW64:1;
        } B;
    } MBE3SW;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBESW127:1;
            vuint32_t MBESW126:1;
            vuint32_t MBESW125:1;
            vuint32_t MBESW124:1;
            vuint32_t MBESW123:1;
            vuint32_t MBESW122:1;
            vuint32_t MBESW121:1;
            vuint32_t MBESW120:1;
            vuint32_t MBESW119:1;
            vuint32_t MBESW118:1;
            vuint32_t MBESW117:1;
            vuint32_t MBESW116:1;
            vuint32_t MBESW115:1;
            vuint32_t MBESW114:1;
            vuint32_t MBESW113:1;
            vuint32_t MBESW112:1;
            vuint32_t MBESW111:1;
            vuint32_t MBESW110:1;
            vuint32_t MBESW109:1;
            vuint32_t MBESW108:1;
            vuint32_t MBESW107:1;
            vuint32_t MBESW106:1;
            vuint32_t MBESW105:1;
            vuint32_t MBESW104:1;
            vuint32_t MBESW103:1;
            vuint32_t MBESW102:1;
            vuint32_t MBESW101:1;
            vuint32_t MBESW100:1;
            vuint32_t MBESW99:1;
            vuint32_t MBESW98:1;
            vuint32_t MBESW97:1;
            vuint32_t MBESW96:1;
        } B;
    } MBE4SW;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBUFM31:1;
            vuint32_t MBUFM30:1;
            vuint32_t MBUFM29:1;
            vuint32_t MBUFM28:1;
            vuint32_t MBUFM27:1;
            vuint32_t MBUFM26:1;
            vuint32_t MBUFM25:1;
            vuint32_t MBUFM24:1;
            vuint32_t MBUFM23:1;
            vuint32_t MBUFM22:1;
            vuint32_t MBUFM21:1;
            vuint32_t MBUFM20:1;
            vuint32_t MBUFM19:1;
            vuint32_t MBUFM18:1;
            vuint32_t MBUFM17:1;
            vuint32_t MBUFM16:1;
            vuint32_t MBUFM15:1;
            vuint32_t MBUFM14:1;
            vuint32_t MBUFM13:1;
            vuint32_t MBUFM12:1;
            vuint32_t MBUFM11:1;
            vuint32_t MBUFM10:1;
            vuint32_t MBUFM9:1;
            vuint32_t MBUFM8:1;
            vuint32_t MBUFM7:1;
            vuint32_t MBUFM6:1;
            vuint32_t MBUFM5:1;
            vuint32_t MBUFM4:1;
            vuint32_t MBUFM3:1;
            vuint32_t MBUFM2:1;
            vuint32_t MBUFM1:1;
            vuint32_t MBUFM0:1;
        } B;
    } MBUFM1;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBUFM63:1;
            vuint32_t MBUFM62:1;
            vuint32_t MBUFM61:1;
            vuint32_t MBUFM60:1;
            vuint32_t MBUFM59:1;
            vuint32_t MBUFM58:1;
            vuint32_t MBUFM57:1;
            vuint32_t MBUFM56:1;
            vuint32_t MBUFM55:1;
            vuint32_t MBUFM54:1;
            vuint32_t MBUFM53:1;
            vuint32_t MBUFM52:1;
            vuint32_t MBUFM51:1;
            vuint32_t MBUFM50:1;
            vuint32_t MBUFM49:1;
            vuint32_t MBUFM48:1;
            vuint32_t MBUFM47:1;
            vuint32_t MBUFM46:1;
            vuint32_t MBUFM45:1;
            vuint32_t MBUFM44:1;
            vuint32_t MBUFM43:1;
            vuint32_t MBUFM42:1;
            vuint32_t MBUFM41:1;
            vuint32_t MBUFM40:1;
            vuint32_t MBUFM39:1;
            vuint32_t MBUFM38:1;
            vuint32_t MBUFM37:1;
            vuint32_t MBUFM36:1;
            vuint32_t MBUFM35:1;
            vuint32_t MBUFM34:1;
            vuint32_t MBUFM33:1;
            vuint32_t MBUFM32:1;
        } B;
    } MBUFM2;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBUFM95:1;
            vuint32_t MBUFM94:1;
            vuint32_t MBUFM93:1;
            vuint32_t MBUFM92:1;
            vuint32_t MBUFM91:1;
            vuint32_t MBUFM90:1;
            vuint32_t MBUFM89:1;
            vuint32_t MBUFM88:1;
            vuint32_t MBUFM87:1;
            vuint32_t MBUFM86:1;
            vuint32_t MBUFM85:1;
            vuint32_t MBUFM84:1;
            vuint32_t MBUFM83:1;
            vuint32_t MBUFM82:1;
            vuint32_t MBUFM81:1;
            vuint32_t MBUFM80:1;
            vuint32_t MBUFM79:1;
            vuint32_t MBUFM78:1;
            vuint32_t MBUFM77:1;
            vuint32_t MBUFM76:1;
            vuint32_t MBUFM75:1;
            vuint32_t MBUFM74:1;
            vuint32_t MBUFM73:1;
            vuint32_t MBUFM72:1;
            vuint32_t MBUFM71:1;
            vuint32_t MBUFM70:1;
            vuint32_t MBUFM69:1;
            vuint32_t MBUFM68:1;
            vuint32_t MBUFM67:1;
            vuint32_t MBUFM66:1;
            vuint32_t MBUFM65:1;
            vuint32_t MBUFM64:1;
        } B;
    } MBUFM3;

    union {
        vuint32_t R;
        struct {
            vuint32_t MBUFM127:1;
            vuint32_t MBUFM126:1;
            vuint32_t MBUFM125:1;
            vuint32_t MBUFM124:1;
            vuint32_t MBUFM123:1;
            vuint32_t MBUFM122:1;
            vuint32_t MBUFM121:1;
            vuint32_t MBUFM120:1;
            vuint32_t MBUFM119:1;
            vuint32_t MBUFM118:1;
            vuint32_t MBUFM117:1;
            vuint32_t MBUFM116:1;
            vuint32_t MBUFM115:1;
            vuint32_t MBUFM114:1;
            vuint32_t MBUFM113:1;
            vuint32_t MBUFM112:1;
            vuint32_t MBUFM111:1;
            vuint32_t MBUFM110:1;
            vuint32_t MBUFM109:1;
            vuint32_t MBUFM108:1;
            vuint32_t MBUFM107:1;
            vuint32_t MBUFM106:1;
            vuint32_t MBUFM105:1;
            vuint32_t MBUFM104:1;
            vuint32_t MBUFM103:1;
            vuint32_t MBUFM102:1;
            vuint32_t MBUFM101:1;
            vuint32_t MBUFM100:1;
            vuint32_t MBUFM99:1;
            vuint32_t MBUFM98:1;
            vuint32_t MBUFM97:1;
            vuint32_t MBUFM96:1;
        } B;
    } MBUFM4;

    vuint8_t ADR_reserved1[108];

    struct {
        union {
            vuint32_t R;
            struct {
                vuint32_t PTR:8;
                vuint32_t CSM:1;
                vuint32_t unused_1:3;
                vuint32_t PRPGEN:1;
                vuint32_t SHS:3;
                vuint32_t SCEN_OFF:4;
                vuint32_t SCEN_ON:4;
                vuint32_t unused_0:2;
                vuint32_t PFT:1;
                vuint32_t CWS:5;
            } B;
        } CTRL;

        union {
            vuint32_t R;
            struct {
                vuint32_t unused_0:6;
                vuint32_t PCS:26;
            } B;
        } PCS;

        union {
            vuint32_t R;
            struct {
                vuint32_t PRPG31:1;
                vuint32_t PRPG30:1;
                vuint32_t PRPG29:1;
                vuint32_t PRPG28:1;
                vuint32_t PRPG27:1;
                vuint32_t PRPG26:1;
                vuint32_t PRPG25:1;
                vuint32_t PRPG24:1;
                vuint32_t PRPG23:1;
                vuint32_t PRPG22:1;
                vuint32_t PRPG21:1;
                vuint32_t PRPG20:1;
                vuint32_t PRPG19:1;
                vuint32_t PRPG18:1;
                vuint32_t PRPG17:1;
                vuint32_t PRPG16:1;
                vuint32_t PRPG15:1;
                vuint32_t PRPG14:1;
                vuint32_t PRPG13:1;
                vuint32_t PRPG12:1;
                vuint32_t PRPG11:1;
                vuint32_t PRPG10:1;
                vuint32_t PRPG9:1;
                vuint32_t PRPG8:1;
                vuint32_t PRPG7:1;
                vuint32_t PRPG6:1;
                vuint32_t PRPG5:1;
                vuint32_t PRPG4:1;
                vuint32_t PRPG3:1;
                vuint32_t PRPG2:1;
                vuint32_t PRPG1:1;
                vuint32_t PRPG0:1;
            } B;
        } PRPGL;

        union {
            vuint32_t R;
            struct {
                vuint32_t PRPG63:1;
                vuint32_t PRPG62:1;
                vuint32_t PRPG61:1;
                vuint32_t PRPG60:1;
                vuint32_t PRPG59:1;
                vuint32_t PRPG58:1;
                vuint32_t PRPG57:1;
                vuint32_t PRPG56:1;
                vuint32_t PRPG55:1;
                vuint32_t PRPG54:1;
                vuint32_t PRPG53:1;
                vuint32_t PRPG52:1;
                vuint32_t PRPG51:1;
                vuint32_t PRPG50:1;
                vuint32_t PRPG49:1;
                vuint32_t PRPG48:1;
                vuint32_t PRPG47:1;
                vuint32_t PRPG46:1;
                vuint32_t PRPG45:1;
                vuint32_t PRPG44:1;
                vuint32_t PRPG43:1;
                vuint32_t PRPG42:1;
                vuint32_t PRPG41:1;
                vuint32_t PRPG40:1;
                vuint32_t PRPG39:1;
                vuint32_t PRPG38:1;
                vuint32_t PRPG37:1;
                vuint32_t PRPG36:1;
                vuint32_t PRPG35:1;
                vuint32_t PRPG34:1;
                vuint32_t PRPG33:1;
                vuint32_t PRPG32:1;
            } B;
        } PRPGH;

        union {
            vuint32_t R;
            struct {
                vuint32_t MISRE31:1;
                vuint32_t MISRE30:1;
                vuint32_t MISRE29:1;
                vuint32_t MISRE28:1;
                vuint32_t MISRE27:1;
                vuint32_t MISRE26:1;
                vuint32_t MISRE25:1;
                vuint32_t MISRE24:1;
                vuint32_t MISRE23:1;
                vuint32_t MISRE22:1;
                vuint32_t MISRE21:1;
                vuint32_t MISRE20:1;
                vuint32_t MISRE19:1;
                vuint32_t MISRE18:1;
                vuint32_t MISRE17:1;
                vuint32_t MISRE16:1;
                vuint32_t MISRE15:1;
                vuint32_t MISRE14:1;
                vuint32_t MISRE13:1;
                vuint32_t MISRE12:1;
                vuint32_t MISRE11:1;
                vuint32_t MISRE10:1;
                vuint32_t MISRE9:1;
                vuint32_t MISRE8:1;
                vuint32_t MISRE7:1;
                vuint32_t MISRE6:1;
                vuint32_t MISRE5:1;
                vuint32_t MISRE4:1;
                vuint32_t MISRE3:1;
                vuint32_t MISRE2:1;
                vuint32_t MISRE1:1;
                vuint32_t MISRE0:1;
            } B;
        } MISREL;

        union {
            vuint32_t R;
            struct {
                vuint32_t MISRE63:1;
                vuint32_t MISRE62:1;
                vuint32_t MISRE61:1;
                vuint32_t MISRE60:1;
                vuint32_t MISRE59:1;
                vuint32_t MISRE58:1;
                vuint32_t MISRE57:1;
                vuint32_t MISRE56:1;
                vuint32_t MISRE55:1;
                vuint32_t MISRE54:1;
                vuint32_t MISRE53:1;
                vuint32_t MISRE52:1;
                vuint32_t MISRE51:1;
                vuint32_t MISRE50:1;
                vuint32_t MISRE49:1;
                vuint32_t MISRE48:1;
                vuint32_t MISRE47:1;
                vuint32_t MISRE46:1;
                vuint32_t MISRE45:1;
                vuint32_t MISRE44:1;
                vuint32_t MISRE43:1;
                vuint32_t MISRE42:1;
                vuint32_t MISRE41:1;
                vuint32_t MISRE40:1;
                vuint32_t MISRE39:1;
                vuint32_t MISRE38:1;
                vuint32_t MISRE37:1;
                vuint32_t MISRE36:1;
                vuint32_t MISRE35:1;
                vuint32_t MISRE34:1;
                vuint32_t MISRE33:1;
                vuint32_t MISRE32:1;
            } B;
        } MISREH;

        union {
            vuint32_t R;
            struct {
                vuint32_t MISRR31:1;
                vuint32_t MISRR30:1;
                vuint32_t MISRR29:1;
                vuint32_t MISRR28:1;
                vuint32_t MISRR27:1;
                vuint32_t MISRR26:1;
                vuint32_t MISRR25:1;
                vuint32_t MISRR24:1;
                vuint32_t MISRR23:1;
                vuint32_t MISRR22:1;
                vuint32_t MISRR21:1;
                vuint32_t MISRR20:1;
                vuint32_t MISRR19:1;
                vuint32_t MISRR18:1;
                vuint32_t MISRR17:1;
                vuint32_t MISRR16:1;
                vuint32_t MISRR15:1;
                vuint32_t MISRR14:1;
                vuint32_t MISRR13:1;
                vuint32_t MISRR12:1;
                vuint32_t MISRR11:1;
                vuint32_t MISRR10:1;
                vuint32_t MISRR9:1;
                vuint32_t MISRR8:1;
                vuint32_t MISRR7:1;
                vuint32_t MISRR6:1;
                vuint32_t MISRR5:1;
                vuint32_t MISRR4:1;
                vuint32_t MISRR3:1;
                vuint32_t MISRR2:1;
                vuint32_t MISRR1:1;
                vuint32_t MISRR0:1;
            } B;
        } MISRRL;

        union {
            vuint32_t R;
            struct {
                vuint32_t MISRR63:1;
                vuint32_t MISRR62:1;
                vuint32_t MISRR61:1;
                vuint32_t MISRR60:1;
                vuint32_t MISRR59:1;
                vuint32_t MISRR58:1;
                vuint32_t MISRR57:1;
                vuint32_t MISRR56:1;
                vuint32_t MISRR55:1;
                vuint32_t MISRR54:1;
                vuint32_t MISRR53:1;
                vuint32_t MISRR52:1;
                vuint32_t MISRR51:1;
                vuint32_t MISRR50:1;
                vuint32_t MISRR49:1;
                vuint32_t MISRR48:1;
                vuint32_t MISRR47:1;
                vuint32_t MISRR46:1;
                vuint32_t MISRR45:1;
                vuint32_t MISRR44:1;
                vuint32_t MISRR43:1;
                vuint32_t MISRR42:1;
                vuint32_t MISRR41:1;
                vuint32_t MISRR40:1;
                vuint32_t MISRR39:1;
                vuint32_t MISRR38:1;
                vuint32_t MISRR37:1;
                vuint32_t MISRR36:1;
                vuint32_t MISRR35:1;
                vuint32_t MISRR34:1;
                vuint32_t MISRR33:1;
                vuint32_t MISRR32:1;
            } B;
        } MISRRH;

        union {
            vuint32_t R;
            struct {
                vuint32_t MISRESW31:1;
                vuint32_t MISRESW30:1;
                vuint32_t MISRESW29:1;
                vuint32_t MISRESW28:1;
                vuint32_t MISRESW27:1;
                vuint32_t MISRESW26:1;
                vuint32_t MISRESW25:1;
                vuint32_t MISRESW24:1;
                vuint32_t MISRESW23:1;
                vuint32_t MISRESW22:1;
                vuint32_t MISRESW21:1;
                vuint32_t MISRESW20:1;
                vuint32_t MISRESW19:1;
                vuint32_t MISRESW18:1;
                vuint32_t MISRESW17:1;
                vuint32_t MISRESW16:1;
                vuint32_t MISRESW15:1;
                vuint32_t MISRESW14:1;
                vuint32_t MISRESW13:1;
                vuint32_t MISRESW12:1;
                vuint32_t MISRESW11:1;
                vuint32_t MISRESW10:1;
                vuint32_t MISRESW9:1;
                vuint32_t MISRESW8:1;
                vuint32_t MISRESW7:1;
                vuint32_t MISRESW6:1;
                vuint32_t MISRESW5:1;
                vuint32_t MISRESW4:1;
                vuint32_t MISRESW3:1;
                vuint32_t MISRESW2:1;
                vuint32_t MISRESW1:1;
                vuint32_t MISRESW0:1;
            } B;
        } MISRELSW;

        union {
            vuint32_t R;
            struct {
                vuint32_t MISRESW63:1;
                vuint32_t MISRESW62:1;
                vuint32_t MISRESW61:1;
                vuint32_t MISRESW60:1;
                vuint32_t MISRESW59:1;
                vuint32_t MISRESW58:1;
                vuint32_t MISRESW57:1;
                vuint32_t MISRESW56:1;
                vuint32_t MISRESW55:1;
                vuint32_t MISRESW54:1;
                vuint32_t MISRESW53:1;
                vuint32_t MISRESW52:1;
                vuint32_t MISRESW51:1;
                vuint32_t MISRESW50:1;
                vuint32_t MISRESW49:1;
                vuint32_t MISRESW48:1;
                vuint32_t MISRESW47:1;
                vuint32_t MISRESW46:1;
                vuint32_t MISRESW45:1;
                vuint32_t MISRESW44:1;
                vuint32_t MISRESW43:1;
                vuint32_t MISRESW42:1;
                vuint32_t MISRESW41:1;
                vuint32_t MISRESW40:1;
                vuint32_t MISRESW39:1;
                vuint32_t MISRESW38:1;
                vuint32_t MISRESW37:1;
                vuint32_t MISRESW36:1;
                vuint32_t MISRESW35:1;
                vuint32_t MISRESW34:1;
                vuint32_t MISRESW33:1;
                vuint32_t MISRESW32:1;
            } B;
        } MISREHSW;

        union {
            vuint32_t R;
            struct {
                vuint32_t MISRRSW31:1;
                vuint32_t MISRRSW30:1;
                vuint32_t MISRRSW29:1;
                vuint32_t MISRRSW28:1;
                vuint32_t MISRRSW27:1;
                vuint32_t MISRRSW26:1;
                vuint32_t MISRRSW25:1;
                vuint32_t MISRRSW24:1;
                vuint32_t MISRRSW23:1;
                vuint32_t MISRRSW22:1;
                vuint32_t MISRRSW21:1;
                vuint32_t MISRRSW20:1;
                vuint32_t MISRRSW19:1;
                vuint32_t MISRRSW18:1;
                vuint32_t MISRRSW17:1;
                vuint32_t MISRRSW16:1;
                vuint32_t MISRRSW15:1;
                vuint32_t MISRRSW14:1;
                vuint32_t MISRRSW13:1;
                vuint32_t MISRRSW12:1;
                vuint32_t MISRRSW11:1;
                vuint32_t MISRRSW10:1;
                vuint32_t MISRRSW9:1;
                vuint32_t MISRRSW8:1;
                vuint32_t MISRRSW7:1;
                vuint32_t MISRRSW6:1;
                vuint32_t MISRRSW5:1;
                vuint32_t MISRRSW4:1;
                vuint32_t MISRRSW3:1;
                vuint32_t MISRRSW2:1;
                vuint32_t MISRRSW1:1;
                vuint32_t MISRRSW0:1;
            } B;
        } MISRRLSW;

        union {
            vuint32_t R;
            struct {
                vuint32_t MISRRSW63:1;
                vuint32_t MISRRSW62:1;
                vuint32_t MISRRSW61:1;
                vuint32_t MISRRSW60:1;
                vuint32_t MISRRSW59:1;
                vuint32_t MISRRSW58:1;
                vuint32_t MISRRSW57:1;
                vuint32_t MISRRSW56:1;
                vuint32_t MISRRSW55:1;
                vuint32_t MISRRSW54:1;
                vuint32_t MISRRSW53:1;
                vuint32_t MISRRSW52:1;
                vuint32_t MISRRSW51:1;
                vuint32_t MISRRSW50:1;
                vuint32_t MISRRSW49:1;
                vuint32_t MISRRSW48:1;
                vuint32_t MISRRSW47:1;
                vuint32_t MISRRSW46:1;
                vuint32_t MISRRSW45:1;
                vuint32_t MISRRSW44:1;
                vuint32_t MISRRSW43:1;
                vuint32_t MISRRSW42:1;
                vuint32_t MISRRSW41:1;
                vuint32_t MISRRSW40:1;
                vuint32_t MISRRSW39:1;
                vuint32_t MISRRSW38:1;
                vuint32_t MISRRSW37:1;
                vuint32_t MISRRSW36:1;
                vuint32_t MISRRSW35:1;
                vuint32_t MISRRSW34:1;
                vuint32_t MISRRSW33:1;
                vuint32_t MISRRSW32:1;
            } B;
        } MISRRHSW;

        vuint8_t STCU2_reserved2[16];
    } LB[8];

    vuint8_t ADR_reserved3[768];

    union {
        vuint32_t R;
        struct {
            vuint32_t PTR:8;
            vuint32_t CSM:1;
            vuint32_t unused_0:23;
        } B;
    } MB_CTRL[10];

};

/**************************************************************************/
/*                 Module: STM            */
/**************************************************************************/
struct STM_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_1:16;
            vuint32_t CPS:8;
            vuint32_t unused_0:6;
            vuint32_t FRZ:1;
            vuint32_t TEN:1;
        } B;
    } CR;

    union {
        vuint32_t R;
        struct {
            vuint32_t CNT:32;
        } B;
    } CNT;

    vuint8_t ADR_reserved0[8];

    struct {
        union {
            vuint32_t R;
            struct {
                vuint32_t unused_0:31;
                vuint32_t CEN:1;
            } B;
        } CCR;

        union {
            vuint32_t R;
            struct {
                vuint32_t unused_0:31;
                vuint32_t CIF:1;
            } B;
        } CIR;

        union {
            vuint32_t R;
            struct {
                vuint32_t CMP:32;
            } B;
        } CMP;

        vuint8_t STM_reserved1[4];
    } CH[4];

};

/**************************************************************************/
/*                 Module: SWT            */
/**************************************************************************/
struct SWT_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t MAP0:1;
            vuint32_t MAP1:1;
            vuint32_t MAP2:1;
            vuint32_t MAP3:1;
            vuint32_t MAP4:1;
            vuint32_t MAP5:1;
            vuint32_t MAP6:1;
            vuint32_t MAP7:1;
            vuint32_t unused_1:13;
            vuint32_t SMD:2;
            vuint32_t RIA:1;
            vuint32_t WND:1;
            vuint32_t ITR:1;
            vuint32_t HLK:1;
            vuint32_t SLK:1;
            vuint32_t unused_0:1;
            vuint32_t STP:1;
            vuint32_t FRZ:1;
            vuint32_t WEN:1;
        } B;
    } CR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:31;
            vuint32_t TIF:1;
        } B;
    } IR;

    union {
        vuint32_t R;
        struct {
            vuint32_t WTO:32;
        } B;
    } TO;

    union {
        vuint32_t R;
        struct {
            vuint32_t WST:32;
        } B;
    } WN;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t WSC:16;
        } B;
    } SR;

    union {
        vuint32_t R;
        struct {
            vuint32_t CNT:32;
        } B;
    } CO;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:16;
            vuint32_t SK:16;
        } B;
    } SK;

};

/**************************************************************************/
/*                 Module: TDM            */
/**************************************************************************/
struct TDM_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:26;
            vuint32_t TDRSR5:1;
            vuint32_t TDRSR4:1;
            vuint32_t TDRSR3:1;
            vuint32_t TDRSR2:1;
            vuint32_t TDRSR1:1;
            vuint32_t TDRSR0:1;
        } B;
    } TDRSR;

    union {
        vuint32_t R;
        struct {
            vuint32_t unused_0:8;
            vuint32_t LFPAR:24;
        } B;
    } LFPAR;

    union {
        vuint32_t R;
        struct {
            vuint32_t DBA:32;
        } B;
    } DBA;

    vuint8_t ADR_reserved0[4];

    union {
        vuint32_t R;
        struct {
            vuint32_t STO_KEY:32;
        } B;
    } STO_KEY[6];

};

/**************************************************************************/
/*                 Module: WKPU            */
/**************************************************************************/
struct WKPU_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t unused_2:16;
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
            vuint32_t unused_2:16;
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

/**************************************************************************/
/*                 Module: XBAR            */
/**************************************************************************/
struct XBAR_tag {
    struct {
        union {
            vuint32_t R;
            struct {
                vuint32_t unused_7:1;
                vuint32_t M7:3;
                vuint32_t unused_6:1;
                vuint32_t M6:3;
                vuint32_t unused_5:1;
                vuint32_t M5:3;
                vuint32_t unused_4:1;
                vuint32_t M4:3;
                vuint32_t unused_3:1;
                vuint32_t M3:3;
                vuint32_t unused_2:1;
                vuint32_t M2:3;
                vuint32_t unused_1:1;
                vuint32_t M1:3;
                vuint32_t unused_0:1;
                vuint32_t M0:3;
            } B;
        } PRS;

        vuint8_t XBAR_reserved0[12];

        union {
            vuint32_t R;
            struct {
                vuint32_t RO:1;
                vuint32_t HRP:1;
                vuint32_t unused_3:6;
                vuint32_t HPEX:8;
                vuint32_t unused_2:6;
                vuint32_t ARB:2;
                vuint32_t unused_1:2;
                vuint32_t PCTL:2;
                vuint32_t unused_0:1;
                vuint32_t PARK:3;
            } B;
        } CRS;

        vuint8_t XBAR_reserved1[236];
    } SLAVE[8];

};

/**************************************************************************/
/*                 Module: XBIC            */
/**************************************************************************/
struct XBIC_tag {
    union {
        vuint32_t R;
        struct {
            vuint32_t SE0:1;
            vuint32_t SE1:1;
            vuint32_t SE2:1;
            vuint32_t SE3:1;
            vuint32_t SE4:1;
            vuint32_t SE5:1;
            vuint32_t SE6:1;
            vuint32_t SE7:1;
            vuint32_t ME0:1;
            vuint32_t ME1:1;
            vuint32_t ME2:1;
            vuint32_t ME3:1;
            vuint32_t ME4:1;
            vuint32_t ME5:1;
            vuint32_t ME6:1;
            vuint32_t ME7:1;
            vuint32_t unused_0:16;
        } B;
    } MCR;

    union {
        vuint32_t R;
        struct {
            vuint32_t EIE:1;
            vuint32_t unused_0:16;
            vuint32_t SLV:3;
            vuint32_t MST:4;
            vuint32_t SYN:8;
        } B;
    } EIR;

    union {
        vuint32_t R;
        struct {
            vuint32_t VLD:1;
            vuint32_t DPSE0:1;
            vuint32_t DPSE1:1;
            vuint32_t DPSE2:1;
            vuint32_t DPSE3:1;
            vuint32_t DPSE4:1;
            vuint32_t unused_1:3;
            vuint32_t DPME0:1;
            vuint32_t DPME1:1;
            vuint32_t DPME2:1;
            vuint32_t unused_0:5;
            vuint32_t SLV:3;
            vuint32_t MST:4;
            vuint32_t SYN:8;
        } B;
    } ESR;

    union {
        vuint32_t R;
        struct {
            vuint32_t ADDR:32;
        } B;
    } EAR;

};


#define BODY_CTU_0                         (*(volatile struct BODY_CTU_tag *) 0xf7c30000UL)
#define CAN_SUB_0_M_CAN_0                     (*(volatile struct M_CAN_tag *) 0xf7edc000UL)
#define CAN_SUB_0_M_CAN_1                     (*(volatile struct M_CAN_tag *) 0xf7ee8000UL)
#define CAN_SUB_0_M_CAN_2                     (*(volatile struct M_CAN_tag *) 0xf7eec000UL)
#define CAN_SUB_0_M_CAN_3                     (*(volatile struct M_CAN_tag *) 0xf7ef0000UL)
#define CAN_SUB_1_M_CAN_1                     (*(volatile struct M_CAN_tag *) 0xfbee4000UL)
#define CAN_SUB_1_M_CAN_2                     (*(volatile struct M_CAN_tag *) 0xfbee8000UL)
#define CAN_SUB_1_M_CAN_3                     (*(volatile struct M_CAN_tag *) 0xfbeec000UL)
#define CCCU_0                                 (*(volatile struct CCCU_tag *) 0xf7f04000UL)
#define CMU_0                                   (*(volatile struct CMU_tag *) 0xf7fb0200UL)
#define CMU_1                                   (*(volatile struct CMU_tag *) 0xfbfb0200UL)
#define CMU_2                                   (*(volatile struct CMU_tag *) 0xfbfb0240UL)
#define CMU_3                                   (*(volatile struct CMU_tag *) 0xfbfb0280UL)
#define CMU_6                                   (*(volatile struct CMU_tag *) 0xfbfb0340UL)
#define CMU_11                                  (*(volatile struct CMU_tag *) 0xfbfb0480UL)
#define CMU_12                                  (*(volatile struct CMU_tag *) 0xfbfb04c0UL)
#define CMU_14                                  (*(volatile struct CMU_tag *) 0xfbfb0540UL)
#define CRC_0                                   (*(volatile struct CRC_tag *) 0xf7f64000UL)
#define CRC_1                                   (*(volatile struct CRC_tag *) 0xfbf64000UL)
#define DMAMUX_0                             (*(volatile struct DMAMUX_tag *) 0xf7f6c000UL)
#define DSPI_0                                 (*(volatile struct DSPI_tag *) 0xf7e70000UL)
#define DSPI_1                                 (*(volatile struct DSPI_tag *) 0xfbe70000UL)
#define DSPI_2                                 (*(volatile struct DSPI_tag *) 0xf7e74000UL)
#define DSPI_3                                 (*(volatile struct DSPI_tag *) 0xfbe74000UL)
#define DTS                                     (*(volatile struct DTS_tag *) 0xf7f38000UL)
#define EDMA_1                                 (*(volatile struct EDMA_tag *) 0xf40a4000UL)
#define EMIOS_0                               (*(volatile struct EMIOS_tag *) 0xf7c38000UL)
#define FCCU                                   (*(volatile struct FCCU_tag *) 0xfbf58000UL)
#define FLASH_0                               (*(volatile struct FLASH_tag *) 0xf7fe0000UL)
#define IIC_0                                   (*(volatile struct IIC_tag *) 0xf7e68000UL)
#define IMA                                     (*(volatile struct IMA_tag *) 0xf7f54000UL)
#define INTC_1                                 (*(volatile struct INTC_tag *) 0xf4044000UL)
#define JDC                                     (*(volatile struct JDC_tag *) 0xf7f3c000UL)
#define JTAGM                                 (*(volatile struct JTAGM_tag *) 0xf7f48000UL)
#define LINFLEXD_0                         (*(volatile struct LINFLEXD_tag *) 0xf7e8c000UL)
#define LINFLEXD_1                         (*(volatile struct LINFLEXD_tag *) 0xfbe8c000UL)
#define LINFLEXD_2                         (*(volatile struct LINFLEXD_tag *) 0xf7e90000UL)
#define LINFLEXD_7                         (*(volatile struct LINFLEXD_tag *) 0xfbe98000UL)
#define LINFLEXD_10                        (*(volatile struct LINFLEXD_tag *) 0xf7ea0000UL)
#define LINFLEXD_15                        (*(volatile struct LINFLEXD_tag *) 0xfbea8000UL)
#define MC_CGM                               (*(volatile struct MC_CGM_tag *) 0xf7fb0600UL)
#define MC_ME                                 (*(volatile struct MC_ME_tag *) 0xf7fb8000UL)
#define MC_PCU                               (*(volatile struct MC_PCU_tag *) 0xf7fa0000UL)
#define MC_RGM                               (*(volatile struct MC_RGM_tag *) 0xf7fa8000UL)
#define MEMU                                   (*(volatile struct MEMU_tag *) 0xf7f50000UL)
#define OSC40M_DIG                       (*(volatile struct OSC40M_DIG_tag *) 0xf7fb0080UL)
#define PASS                                   (*(volatile struct PASS_tag *) 0xf7ff4000UL)
#define PBRIDGE_1                           (*(volatile struct PBRIDGE_tag *) 0xf8000000UL)
#define PBRIDGE_2                           (*(volatile struct PBRIDGE_tag *) 0xf4000000UL)
#define PCM_0                                   (*(volatile struct PCM_tag *) 0xf4028000UL)
#define PFLASH_1                             (*(volatile struct PFLASH_tag *) 0xf4034000UL)
#define PIT_0                                   (*(volatile struct PIT_tag *) 0xf7f84000UL)
#define PLLDIG                               (*(volatile struct PLLDIG_tag *) 0xf7fb0100UL)
#define PMCDIG                               (*(volatile struct PMCDIG_tag *) 0xf7fa0400UL)
#define PRAM_2                                 (*(volatile struct PRAM_tag *) 0xf40a8000UL)
#define RC1024K_DIG                     (*(volatile struct RC1024K_DIG_tag *) 0xf7fb0040UL)
#define RC16M_DIG                         (*(volatile struct RC16M_DIG_tag *) 0xf7fb0000UL)
#define RTC_API                             (*(volatile struct RTC_API_tag *) 0xf7f94000UL)
#define SAR_ADC_12BIT_B0                     (*(volatile struct SARADC_tag *) 0xf7e3c000UL)
#define SIUL2                                 (*(volatile struct SIUL2_tag *) 0xf7fc0000UL)
#define SMPU_1                                 (*(volatile struct SMPU_tag *) 0xf4014000UL)
#define SSCM                                   (*(volatile struct SSCM_tag *) 0xf7ff8000UL)
#define STCU2                                 (*(volatile struct STCU2_tag *) 0xf7f44000UL)
#define STM_2                                   (*(volatile struct STM_tag *) 0xf4070000UL)
#define SWT_2                                   (*(volatile struct SWT_tag *) 0xf4058000UL)
#define TDM_0                                   (*(volatile struct TDM_tag *) 0xf40e4000UL)
#define WKPU                                   (*(volatile struct WKPU_tag *) 0xf7f98000UL)
#define XBAR_1                                 (*(volatile struct XBAR_tag *) 0xf4008000UL)
#define XBIC_1                                 (*(volatile struct XBIC_tag *) 0xf401c000UL)



#endif /* _SPC582B_H_ */
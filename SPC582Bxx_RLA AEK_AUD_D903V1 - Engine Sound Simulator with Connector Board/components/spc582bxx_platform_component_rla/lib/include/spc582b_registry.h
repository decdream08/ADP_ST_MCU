/****************************************************************************
*
* Copyright © 2015-2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/

/**
 * @file    spc582b_registry.h
 * @brief   SPC582Bxx capabilities registry.
 *
 * @addtogroup PLATFORM
 * @{
 */

#ifndef SPC5_REGISTRY_H
#define SPC5_REGISTRY_H

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @name    SPC582Bxx capabilities
 * @{
 */
/* eDMA attributes.*/
#define SPC5_HAS_EDMA                       TRUE
#define SPC5_HAS_EDMA0                      FALSE
#define SPC5_HAS_EDMA1                      TRUE
#define SPC5_EDMA_DMA1_BASE                 0xF40A4000UL
#define SPC5_EDMA_NCHANNELS                 16U
#define SPC5_EDMA_COMBO_CH_ERR_HANDLER      vector52
#define SPC5_EDMA_CH0_HANDLER               vector53
#define SPC5_EDMA_CH1_HANDLER               vector54
#define SPC5_EDMA_CH2_HANDLER               vector55
#define SPC5_EDMA_CH3_HANDLER               vector56
#define SPC5_EDMA_CH4_HANDLER               vector57
#define SPC5_EDMA_CH5_HANDLER               vector58
#define SPC5_EDMA_CH6_HANDLER               vector59
#define SPC5_EDMA_CH7_HANDLER               vector60
#define SPC5_EDMA_CH8_HANDLER               vector61
#define SPC5_EDMA_CH9_HANDLER               vector62
#define SPC5_EDMA_CH10_HANDLER              vector63
#define SPC5_EDMA_CH11_HANDLER              vector64
#define SPC5_EDMA_CH12_HANDLER              vector65
#define SPC5_EDMA_CH13_HANDLER              vector66
#define SPC5_EDMA_CH14_HANDLER              vector67
#define SPC5_EDMA_CH15_HANDLER              vector68
#define SPC5_EDMA_COMBO_CH_ERR_NUMBER       52U
#define SPC5_EDMA_CH0_NUMBER                53U
#define SPC5_EDMA_HAS_MUX                   TRUE
#define SPC5_EDMA_NUM_OF_MUX                1U
#define SPC5_EDMA_MUX0_BASE                 0xF7F6C000UL
#define SPC5_EDMA_MUX0_CH_NUM               16U
#define SPC5_EDMA_MUX0_PCTL                 36

/* DSPI attributes.*/
#define SPC5_HAS_DSPI0                      TRUE
#define SPC5_DSPI0_BASE                     0xF7E70000UL
#define SPC5_HAS_DSPI1                      TRUE
#define SPC5_DSPI1_BASE                     0xFBE70000UL
#define SPC5_HAS_DSPI2                      TRUE
#define SPC5_DSPI2_BASE                     0xF7E74000UL
#define SPC5_HAS_DSPI3                      TRUE
#define SPC5_DSPI3_BASE                     0xFBE74000UL
#define SPC5_HAS_DSPI4                      FALSE
#define SPC5_HAS_DSPI5                      FALSE
#define SPC5_HAS_DSPI6                      FALSE
#define SPC5_HAS_DSPI7                      FALSE
#define SPC5_HAS_DSPI8                      FALSE
#define SPC5_HAS_DSPI9                      FALSE

#define SPC5_DSPI_FIFO_DEPTH                4U

#define SPC5_DSPI0_EOQF_HANDLER             vector260
#define SPC5_DSPI0_EOQF_NUMBER              260
#define SPC5_DSPI0_TFFF_HANDLER             vector261
#define SPC5_DSPI0_TFFF_NUMBER              261
#define SPC5_DSPI0_RFDF_HANDLER             vector263
#define SPC5_DSPI0_RFDF_NUMBER              263

#define SPC5_DSPI1_EOQF_HANDLER             vector269
#define SPC5_DSPI1_EOQF_NUMBER              269
#define SPC5_DSPI1_TFFF_HANDLER             vector270
#define SPC5_DSPI1_TFFF_NUMBER              270
#define SPC5_DSPI1_RFDF_HANDLER             vector272
#define SPC5_DSPI1_RFDF_NUMBER              272

#define SPC5_DSPI2_EOQF_HANDLER             vector278
#define SPC5_DSPI2_EOQF_NUMBER              278
#define SPC5_DSPI2_TFFF_HANDLER             vector279
#define SPC5_DSPI2_TFFF_NUMBER              279
#define SPC5_DSPI2_RFDF_HANDLER             vector281
#define SPC5_DSPI2_RFDF_NUMBER              281

#define SPC5_DSPI3_EOQF_HANDLER             vector287
#define SPC5_DSPI3_EOQF_NUMBER              287
#define SPC5_DSPI3_TFFF_HANDLER             vector288
#define SPC5_DSPI3_TFFF_NUMBER              288
#define SPC5_DSPI3_RFDF_HANDLER             vector290
#define SPC5_DSPI3_RFDF_NUMBER              290

#define SPC5_DSPI0_PCTL                     99
#define SPC5_DSPI1_PCTL                     227
#define SPC5_DSPI2_PCTL                     98
#define SPC5_DSPI3_PCTL                     226

#define SPC5_DSPI0_RX_DMA_MUX0_DEV_ID       3
#define SPC5_DSPI0_TX1_DMA_MUX0_DEV_ID      4
#define SPC5_DSPI0_TX2_DMA_MUX0_DEV_ID      5

#define SPC5_DSPI1_RX_DMA_MUX0_DEV_ID       6
#define SPC5_DSPI1_TX1_DMA_MUX0_DEV_ID      7
#define SPC5_DSPI1_TX2_DMA_MUX0_DEV_ID      8

#define SPC5_DSPI2_RX_DMA_MUX0_DEV_ID       9
#define SPC5_DSPI2_TX1_DMA_MUX0_DEV_ID      10
#define SPC5_DSPI2_TX2_DMA_MUX0_DEV_ID      11

#define SPC5_DSPI3_RX_DMA_MUX0_DEV_ID       12
#define SPC5_DSPI3_TX1_DMA_MUX0_DEV_ID      13
#define SPC5_DSPI3_TX2_DMA_MUX0_DEV_ID      14

#define SPC5_DSPI0_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI0_PCTL, SPC5_SPI_DSPI0_START_PCTL)
#define SPC5_DSPI0_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI0_PCTL, SPC5_SPI_DSPI0_STOP_PCTL)
#define SPC5_DSPI1_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI1_PCTL, SPC5_SPI_DSPI1_START_PCTL)
#define SPC5_DSPI1_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI1_PCTL, SPC5_SPI_DSPI1_STOP_PCTL)
#define SPC5_DSPI2_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI2_PCTL, SPC5_SPI_DSPI2_START_PCTL)
#define SPC5_DSPI2_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI2_PCTL, SPC5_SPI_DSPI2_STOP_PCTL)
#define SPC5_DSPI3_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI3_PCTL, SPC5_SPI_DSPI3_START_PCTL)
#define SPC5_DSPI3_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI3_PCTL, SPC5_SPI_DSPI3_STOP_PCTL)

/*
 * I2S attributes
 */
#define SPC5_I2S_DSPI0_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI0_PCTL, SPC5_I2S_DSPI0_START_PCTL)
#define SPC5_I2S_DSPI0_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI0_PCTL, SPC5_I2S_DSPI0_STOP_PCTL)
#define SPC5_I2S_DSPI1_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI1_PCTL, SPC5_I2S_DSPI1_START_PCTL)
#define SPC5_I2S_DSPI1_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI1_PCTL, SPC5_I2S_DSPI1_STOP_PCTL)
#define SPC5_I2S_DSPI2_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI2_PCTL, SPC5_I2S_DSPI2_START_PCTL)
#define SPC5_I2S_DSPI2_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI2_PCTL, SPC5_I2S_DSPI2_STOP_PCTL)
#define SPC5_I2S_DSPI3_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI3_PCTL, SPC5_I2S_DSPI3_START_PCTL)
#define SPC5_I2S_DSPI3_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI3_PCTL, SPC5_I2S_DSPI3_STOP_PCTL)


/* LINFlex attributes.*/
#define SPC5_HAS_LINFLEX0                   TRUE
#define SPC5_LINFLEX0_BASE                  0xF7E8C000UL
#define SPC5_LINFLEX0L_BASE                 0xF7E8C000UL
#define SPC5_LINFLEX0H_BASE                 0xF7E8C08CUL
#define SPC5_LINFLEX0_PCTL                  92
#define SPC5_LINFLEX0_RXI_HANDLER           vector376
#define SPC5_LINFLEX0_TXI_HANDLER           vector377
#define SPC5_LINFLEX0_ERR_HANDLER           vector378
#define SPC5_LINFLEX0_RXI_NUMBER            376
#define SPC5_LINFLEX0_TXI_NUMBER            377
#define SPC5_LINFLEX0_ERR_NUMBER            378
#define SPC5_LINFLEX0_DMA_SUPPORTED         TRUE
#define SPC5_LINFLEX0_RX_DMA_MUX0_DEV_ID    15
#define SPC5_LINFLEX0_TX_DMA_MUX0_DEV_ID    16
#define SPC5_LINFLEX0_CLK                   SPC5_LIN_CLK

#define SPC5_HAS_LINFLEX1                   TRUE
#define SPC5_LINFLEX1_BASE                  0xFBE8C000UL
#define SPC5_LINFLEX1L_BASE                 0xFBE8C000UL
#define SPC5_LINFLEX1H_BASE                 0xFBE8C08CUL
#define SPC5_LINFLEX1_PCTL                  220
#define SPC5_LINFLEX1_RXI_HANDLER           vector380
#define SPC5_LINFLEX1_TXI_HANDLER           vector381
#define SPC5_LINFLEX1_ERR_HANDLER           vector382
#define SPC5_LINFLEX1_RXI_NUMBER            380
#define SPC5_LINFLEX1_TXI_NUMBER            381
#define SPC5_LINFLEX1_ERR_NUMBER            382
#define SPC5_LINFLEX1_DMA_SUPPORTED         TRUE
#define SPC5_LINFLEX1_RX_DMA_MUX0_DEV_ID    17
#define SPC5_LINFLEX1_TX_DMA_MUX0_DEV_ID    18
#define SPC5_LINFLEX1_CLK                   SPC5_LIN_CLK

#define SPC5_HAS_LINFLEX2                   TRUE
#define SPC5_LINFLEX2_BASE                  0xF7E90000UL
#define SPC5_LINFLEX2L_BASE                 0xF7E90000UL
#define SPC5_LINFLEX2H_BASE                 0xF7E9008CUL
#define SPC5_LINFLEX2_PCTL                  91
#define SPC5_LINFLEX2_RXI_HANDLER           vector384
#define SPC5_LINFLEX2_TXI_HANDLER           vector385
#define SPC5_LINFLEX2_ERR_HANDLER           vector386
#define SPC5_LINFLEX2_RXI_NUMBER            384
#define SPC5_LINFLEX2_TXI_NUMBER            385
#define SPC5_LINFLEX2_ERR_NUMBER            386
#define SPC5_LINFLEX2_DMA_SUPPORTED         TRUE
#define SPC5_LINFLEX2_RX_DMA_MUX0_DEV_ID    19
#define SPC5_LINFLEX2_TX_DMA_MUX0_DEV_ID    20
#define SPC5_LINFLEX2_CLK                   SPC5_LIN_CLK

#define SPC5_HAS_LINFLEX3                   FALSE
#define SPC5_HAS_LINFLEX4                   FALSE
#define SPC5_HAS_LINFLEX5                   FALSE
#define SPC5_HAS_LINFLEX6                   FALSE

#define SPC5_HAS_LINFLEX7                   TRUE
#define SPC5_LINFLEX7_BASE                  0xFBE98000UL
#define SPC5_LINFLEX7L_BASE                 0xFBE98000UL
#define SPC5_LINFLEX7H_BASE                 0xFBE9808CUL
#define SPC5_LINFLEX7_PCTL                  217
#define SPC5_LINFLEX7_RXI_HANDLER           vector404
#define SPC5_LINFLEX7_TXI_HANDLER           vector405
#define SPC5_LINFLEX7_ERR_HANDLER           vector406
#define SPC5_LINFLEX7_RXI_NUMBER            404
#define SPC5_LINFLEX7_TXI_NUMBER            405
#define SPC5_LINFLEX7_ERR_NUMBER            406
#define SPC5_LINFLEX7_DMA_SUPPORTED         TRUE
#define SPC5_LINFLEX7_RX_DMA_MUX0_DEV_ID    21
#define SPC5_LINFLEX7_TX_DMA_MUX0_DEV_ID    22
#define SPC5_LINFLEX7_CLK                   SPC5_LIN_CLK

#define SPC5_HAS_LINFLEX8                   FALSE
#define SPC5_HAS_LINFLEX9                   FALSE

#define SPC5_HAS_LINFLEX10                  TRUE
#define SPC5_LINFLEX10_BASE                 0xF7EA0000UL
#define SPC5_LINFLEX10L_BASE                0xF7EA0000UL
#define SPC5_LINFLEX10H_BASE                0xF7EA008CUL
#define SPC5_LINFLEX10_PCTL                 87
#define SPC5_LINFLEX10_RXI_HANDLER          vector416
#define SPC5_LINFLEX10_TXI_HANDLER          vector417
#define SPC5_LINFLEX10_ERR_HANDLER          vector418
#define SPC5_LINFLEX10_RXI_NUMBER           416
#define SPC5_LINFLEX10_TXI_NUMBER           417
#define SPC5_LINFLEX10_ERR_NUMBER           418
#define SPC5_LINFLEX10_DMA_SUPPORTED        TRUE
#define SPC5_LINFLEX10_RX_DMA_MUX0_DEV_ID   23
#define SPC5_LINFLEX10_TX_DMA_MUX0_DEV_ID   24
#define SPC5_LINFLEX10_CLK                  SPC5_LIN_CLK

#define SPC5_HAS_LINFLEX11                  FALSE
#define SPC5_HAS_LINFLEX12                  FALSE
#define SPC5_HAS_LINFLEX13                  FALSE
#define SPC5_HAS_LINFLEX14                  FALSE

#define SPC5_HAS_LINFLEX15                  TRUE
#define SPC5_LINFLEX15_BASE                 0xFBEA8000UL
#define SPC5_LINFLEX15L_BASE                0xFBEA8000UL
#define SPC5_LINFLEX15H_BASE                0xFBEA808CUL
#define SPC5_LINFLEX15_PCTL                 213
#define SPC5_LINFLEX15_RXI_HANDLER          vector436
#define SPC5_LINFLEX15_TXI_HANDLER          vector437
#define SPC5_LINFLEX15_ERR_HANDLER          vector438
#define SPC5_LINFLEX15_RXI_NUMBER           436
#define SPC5_LINFLEX15_TXI_NUMBER           437
#define SPC5_LINFLEX15_ERR_NUMBER           438
#define SPC5_LINFLEX15_DMA_SUPPORTED        TRUE
#define SPC5_LINFLEX15_RX_DMA_MUX0_DEV_ID   25
#define SPC5_LINFLEX15_TX_DMA_MUX0_DEV_ID   26
#define SPC5_LINFLEX15_CLK                  SPC5_LIN_CLK

#define SPC5_HAS_LINFLEX16                  FALSE
#define SPC5_HAS_LINFLEX17                  FALSE
#define SPC5_HAS_LINFLEX18                  FALSE
#define SPC5_HAS_LINFLEX19                  FALSE
#define SPC5_HAS_LINFLEX20                  FALSE
#define SPC5_HAS_LINFLEX21                  FALSE
#define SPC5_HAS_LINFLEX22                  FALSE
#define SPC5_HAS_LINFLEX23                  FALSE

/* SIUL2 attributes.*/
#define SPC5_HAS_SIUL2                      TRUE
#define SPC5_HAS_SIUL_PARALLEL_PORT_REG     TRUE
#define SPC5_SIUL2_PCTL                     15
#define SPC5_SIUL2_NUM_PORTS                10
#define SPC5_SIUL2_NUM_MUXES                420

/* PIT attributes. PITv2 driver support*/
#define SPC5_HAS_PIT0                       TRUE
#define SPC5_PIT0_BASE                      0xF7F84000UL
#define SPC5_PIT0_CHANNELS                  8
#define SPC5_PIT0_PCTL                      30
#define SPC5_PIT0_ENABLE_CLOCK()            SPCSetPeripheralClockMode(SPC5_PIT0_PCTL, SPC5_PIT0_START_PCTL);
#define SPC5_PIT0_DISABLE_CLOCK()           SPCSetPeripheralClockMode(SPC5_PIT0_PCTL, SPC5_PIT0_STOP_PCTL);
#define SPC5_HAS_PIT0_CH0                   TRUE
#define SPC5_HAS_PIT0_CH1                   TRUE
#define SPC5_HAS_PIT0_CH2                   TRUE
#define SPC5_HAS_PIT0_CH3                   TRUE
#define SPC5_HAS_PIT0_CH4                   TRUE
#define SPC5_HAS_PIT0_CH5                   TRUE
#define SPC5_HAS_PIT0_CH6                   TRUE
#define SPC5_HAS_PIT0_CH7                   TRUE
#define SPC5_PIT0_CH0_HANDLER               vector226
#define SPC5_PIT0_CH1_HANDLER               vector227
#define SPC5_PIT0_CH2_HANDLER               vector228
#define SPC5_PIT0_CH3_HANDLER               vector229
#define SPC5_PIT0_CH4_HANDLER               vector230
#define SPC5_PIT0_CH5_HANDLER               vector231
#define SPC5_PIT0_CH6_HANDLER               vector232
#define SPC5_PIT0_CH7_HANDLER               vector233
#define SPC5_PIT0_CH0_INT_NUMBER            226
#define SPC5_PIT0_CH1_INT_NUMBER            227
#define SPC5_PIT0_CH2_INT_NUMBER            228
#define SPC5_PIT0_CH3_INT_NUMBER            229
#define SPC5_PIT0_CH4_INT_NUMBER            230
#define SPC5_PIT0_CH5_INT_NUMBER            231
#define SPC5_PIT0_CH6_INT_NUMBER            232
#define SPC5_PIT0_CH7_INT_NUMBER            233

#define SPC5_HAS_PIT1                       FALSE


/* STM attributes.*/
#define SPC5_HAS_STM0                       FALSE
#define SPC5_HAS_STM1                       FALSE
#define SPC5_HAS_STM2                       TRUE

#define SPC5_STM2_BASE                      0xF4070000UL
#define SPC5_STM2_CHANNELS                  4
#define SPC5_HAS_STM2_CH0                   TRUE
#define SPC5_HAS_STM2_CH1                   TRUE
#define SPC5_HAS_STM2_CH2                   TRUE
#define SPC5_HAS_STM2_CH3                   TRUE
#define SPC5_STM0_CH1_CH3_SHARED_INT        FALSE
#define SPC5_STM2_CH0_HANDLER               vector44
#define SPC5_STM2_CH1_HANDLER               vector45
#define SPC5_STM2_CH2_HANDLER               vector46
#define SPC5_STM2_CH3_HANDLER               vector47
#define SPC5_STM2_CH0_INT_NUMBER            44
#define SPC5_STM2_CH1_INT_NUMBER            45
#define SPC5_STM2_CH2_INT_NUMBER            46
#define SPC5_STM2_CH3_INT_NUMBER            47

/* CAN SUBSYSTEM 0 attributes.*/
#define SPC5_HAS_CAN_SUB_0_M_CAN_0             TRUE
#define SPC5_CAN_SUB_0_M_CAN_0_PTCL            72
#define SPC5_CAN_SUB_0_M_CAN_0_ENABLE_CLOCK()  SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_M_CAN_0_PTCL, SPC5_CAN_SUB_0_M_CAN_0_START_PTCL);
#define SPC5_CAN_SUB_0_M_CAN_0_DISABLE_CLOCK() SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_M_CAN_0_PTCL, SPC5_CAN_SUB_0_M_CAN_0_STOP_PTCL);
#define SPC5_CAN_SUB_0_M_CAN_0_L0_HANDLER      vector686
#define SPC5_CAN_SUB_0_M_CAN_0_L1_HANDLER      vector687
#define SPC5_CAN_SUB_0_M_CAN_0_L0_NUMBER       686
#define SPC5_CAN_SUB_0_M_CAN_0_L1_NUMBER       687

#define SPC5_HAS_CAN_SUB_0_M_CAN_1             TRUE
#define SPC5_CAN_SUB_0_M_CAN_1_PTCL            69
#define SPC5_CAN_SUB_0_M_CAN_1_ENABLE_CLOCK()  SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_M_CAN_1_PTCL, SPC5_CAN_SUB_0_M_CAN_1_START_PTCL);
#define SPC5_CAN_SUB_0_M_CAN_1_DISABLE_CLOCK() SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_M_CAN_1_PTCL, SPC5_CAN_SUB_0_M_CAN_1_STOP_PTCL);
#define SPC5_CAN_SUB_0_M_CAN_1_L0_HANDLER      vector688
#define SPC5_CAN_SUB_0_M_CAN_1_L1_HANDLER      vector689
#define SPC5_CAN_SUB_0_M_CAN_1_L0_NUMBER       688
#define SPC5_CAN_SUB_0_M_CAN_1_L1_NUMBER       689

#define SPC5_HAS_CAN_SUB_0_M_CAN_2             TRUE
#define SPC5_CAN_SUB_0_M_CAN_2_PTCL            68
#define SPC5_CAN_SUB_0_M_CAN_2_ENABLE_CLOCK()  SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_M_CAN_2_PTCL, SPC5_CAN_SUB_0_M_CAN_2_START_PTCL);
#define SPC5_CAN_SUB_0_M_CAN_2_DISABLE_CLOCK() SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_M_CAN_2_PTCL, SPC5_CAN_SUB_0_M_CAN_2_STOP_PTCL);
#define SPC5_CAN_SUB_0_M_CAN_2_L0_HANDLER      vector690
#define SPC5_CAN_SUB_0_M_CAN_2_L1_HANDLER      vector691
#define SPC5_CAN_SUB_0_M_CAN_2_L0_NUMBER       690
#define SPC5_CAN_SUB_0_M_CAN_2_L1_NUMBER       691

#define SPC5_HAS_CAN_SUB_0_M_CAN_3             TRUE
#define SPC5_CAN_SUB_0_M_CAN_3_PTCL            67
#define SPC5_CAN_SUB_0_M_CAN_3_ENABLE_CLOCK()  SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_M_CAN_3_PTCL, SPC5_CAN_SUB_0_M_CAN_3_START_PTCL);
#define SPC5_CAN_SUB_0_M_CAN_3_DISABLE_CLOCK() SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_M_CAN_3_PTCL, SPC5_CAN_SUB_0_M_CAN_3_STOP_PTCL);
#define SPC5_CAN_SUB_0_M_CAN_3_L0_HANDLER      vector692
#define SPC5_CAN_SUB_0_M_CAN_3_L1_HANDLER      vector693
#define SPC5_CAN_SUB_0_M_CAN_3_L0_NUMBER       692
#define SPC5_CAN_SUB_0_M_CAN_3_L1_NUMBER       693

#define SPC5_HAS_CAN_SUB_0_M_CAN_4             FALSE

#define SPC5_HAS_CAN_SUB_0_RAM                 TRUE
#define SPC5_CAN_SUB_0_RAM_PTCL                74
#define SPC5_CAN_SUB_0_RAM_ENABLE_CLOCK()      SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_RAM_PTCL, SPC5_CAN_SUB_0_RAM_START_PTCL);
#define SPC5_CAN_SUB_0_RAM_DISABLE_CLOCK()     SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_RAM_PTCL, SPC5_CAN_SUB_0_RAM_STOP_PTCL);

/* CAN SUBSYSTEM 1 attributes.*/
#define SPC5_HAS_CAN_SUB_1_M_CAN_0             FALSE

#define SPC5_HAS_CAN_SUB_1_M_CAN_1             TRUE
#define SPC5_CAN_SUB_1_M_CAN_1_PTCL            198
#define SPC5_CAN_SUB_1_M_CAN_1_ENABLE_CLOCK()  SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_M_CAN_1_PTCL, SPC5_CAN_SUB_1_M_CAN_1_START_PTCL);
#define SPC5_CAN_SUB_1_M_CAN_1_DISABLE_CLOCK() SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_M_CAN_1_PTCL, SPC5_CAN_SUB_1_M_CAN_1_STOP_PTCL);
#define SPC5_CAN_SUB_1_M_CAN_1_L0_HANDLER      vector694
#define SPC5_CAN_SUB_1_M_CAN_1_L1_HANDLER      vector695
#define SPC5_CAN_SUB_1_M_CAN_1_L0_NUMBER       694
#define SPC5_CAN_SUB_1_M_CAN_1_L1_NUMBER       695

#define SPC5_HAS_CAN_SUB_1_M_CAN_2             TRUE
#define SPC5_CAN_SUB_1_M_CAN_2_PTCL            197
#define SPC5_CAN_SUB_1_M_CAN_2_ENABLE_CLOCK()  SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_M_CAN_2_PTCL, SPC5_CAN_SUB_1_M_CAN_2_START_PTCL);
#define SPC5_CAN_SUB_1_M_CAN_2_DISABLE_CLOCK() SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_M_CAN_2_PTCL, SPC5_CAN_SUB_1_M_CAN_2_STOP_PTCL);
#define SPC5_CAN_SUB_1_M_CAN_2_L0_HANDLER      vector696
#define SPC5_CAN_SUB_1_M_CAN_2_L1_HANDLER      vector697
#define SPC5_CAN_SUB_1_M_CAN_2_L0_NUMBER       696
#define SPC5_CAN_SUB_1_M_CAN_2_L1_NUMBER       697

#define SPC5_HAS_CAN_SUB_1_M_CAN_3             TRUE
#define SPC5_CAN_SUB_1_M_CAN_3_PTCL            196
#define SPC5_CAN_SUB_1_M_CAN_3_ENABLE_CLOCK()  SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_M_CAN_3_PTCL, SPC5_CAN_SUB_1_M_CAN_3_START_PTCL);
#define SPC5_CAN_SUB_1_M_CAN_3_DISABLE_CLOCK() SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_M_CAN_3_PTCL, SPC5_CAN_SUB_1_M_CAN_3_STOP_PTCL);
#define SPC5_CAN_SUB_1_M_CAN_3_L0_HANDLER      vector698
#define SPC5_CAN_SUB_1_M_CAN_3_L1_HANDLER      vector699
#define SPC5_CAN_SUB_1_M_CAN_3_L0_NUMBER       698
#define SPC5_CAN_SUB_1_M_CAN_3_L1_NUMBER       699

#define SPC5_HAS_CAN_SUB_1_M_CAN_4             FALSE

#define SPC5_HAS_CAN_SUB_1_RAM                 TRUE
#define SPC5_CAN_SUB_1_RAM_PTCL                202
#define SPC5_CAN_SUB_1_RAM_ENABLE_CLOCK()      SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_RAM_PTCL, SPC5_CAN_SUB_1_RAM_START_PTCL);
#define SPC5_CAN_SUB_1_RAM_DISABLE_CLOCK()     SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_RAM_PTCL, SPC5_CAN_SUB_1_RAM_STOP_PTCL);

/* CAN SUBSYSTEM 2 attributes.*/       
#define SPC5_HAS_CAN_SUB_2_M_CAN_0             FALSE
#define SPC5_HAS_CAN_SUB_2_M_CAN_1             FALSE
#define SPC5_HAS_CAN_SUB_2_M_CAN_2             FALSE
#define SPC5_HAS_CAN_SUB_2_M_CAN_3             FALSE
#define SPC5_HAS_CAN_SUB_2_M_CAN_4             FALSE
#define SPC5_HAS_CAN_SUB_2_RAM                 FALSE

/* CLOCK CALIBRATION CONTROL UNIT */
#define SPC5_HAS_CCCU_0                        TRUE
#define SPC5_CCCU_0_PTCL                       62
#define SPC5_CCCU_0_ENABLE_CLOCK()             SPCSetPeripheralClockMode(SPC5_CCCU_0_PTCL, SPC5_CCCU_0_START_PTCL);
#define SPC5_CCCU_0_DISABLE_CLOCK()            SPCSetPeripheralClockMode(SPC5_CCCU_0_PTCL, SPC5_CCCU_0_STOP_PTCL);

#define SPC5_HAS_CCCU_1                        FALSE

/* I2C attributes.*/
#define SPC5_HAS_I2C                        1
#define SPC5_I2C0_PCTL                       101
#define SPC5_I2C0_HANDLER                    vector448
#define	SPC5_I2C0_INT_NUMBER                 448

/* SWT attributes.*/
#define SPC5_HAS_SWT0                       FALSE
#define SPC5_HAS_SWT1                       FALSE
#define SPC5_HAS_SWT2                       TRUE
#define SPC5_SWT2_FCCU_CHANNEL              18U
#define SPC5_SWT2_BASE                      0xF4058000UL
#define SPC5_SWT2_HANDLER                   vector34
#define SPC5_SWT2_INT_NUMBER                34
#define SPC5_HAS_SWT3                       FALSE

/* SARADC attributes.*/
#define SPC5_HAS_SARADC12_0                 FALSE
#define SPC5_HAS_SARADC12_1                 FALSE
#define SPC5_HAS_SARADC12_2                 FALSE
#define SPC5_HAS_SARADC12_3                 FALSE
#define SPC5_HAS_SARADC12_4                 FALSE
#define SPC5_HAS_SARADC12_5                 FALSE
#define SPC5_HAS_SARADC12_6                 FALSE

#define SPC5_HAS_SARADC12_SV                TRUE
#define SPC5_SARADC12_SV_PCTL               112
#define SPC5_SARADC12_SV_HANDLER            vector543
#define SPC5_SARADC12_SV_INT_NUMBER         543
#define SPC5_SARADC12_SV_DMA_MUX0_DEV_ID    1

#define SPC5_HAS_SARADC12_SV_1              FALSE
#define SPC5_HAS_SARADC10_0                 FALSE
#define SPC5_HAS_SARADC10_1                 FALSE
#define SPC5_HAS_SARADC10_STANDBY           FALSE

#define SPC5_SARADC_MASK_REG_NUM            3U
/** @} */

/* FCCU attributes.*/
#define SPC5_HAS_FCCU                       TRUE
#define SPC5_FCCU_BASE                      0xFBF58000UL
#define SPC5_FCCU_CH_NUMBER                 128U
#define SPC5_FCCU_ALARM_HANDLER             vector488
#define SPC5_FCCU_CONFIG_HANDLER            vector489
#define SPC5_FCCU_ALARM_INT_NUMBER          488
#define SPC5_FCCU_CONFIG_INT_NUMBER         489
#define SPC5_FCCU_HAS_ERR_INPUT_PIN         TRUE
#define SPC5_FCCU_EIN_ERR_CH                96U
#define SPC5_FCCU_EIN_MSCR_IO               27U
#define SPC5_FCCU_RF_E_REG_RESET_VAL        {0x00040040UL, 0x00000000UL, 0x00000000UL, 0x00000000UL}
#define SPC5_FCCU_MAX_DELTA_T_US            10000UL

#define MC_RGM_FCCU_RST                     MC_RGM.PRST5.B.FCCU_RST

/* eMIOS attributes.*/
#define SPC5_HAS_EMIOS0                     TRUE
#define SPC5_EMIOS0_BASE                    0xF7C38000UL
#define SPC5_EMIOS0_PCTL                    241
#define SPC5_EMIOS0_GFR_F0F1_HANDLER        vector900
#define SPC5_EMIOS0_GFR_F2F3_HANDLER        vector901
#define SPC5_EMIOS0_GFR_F4F5_HANDLER        vector902
#define SPC5_EMIOS0_GFR_F6F7_HANDLER        vector903
#define SPC5_EMIOS0_GFR_F8F9_HANDLER        vector904
#define SPC5_EMIOS0_GFR_F10F11_HANDLER      vector905
#define SPC5_EMIOS0_GFR_F12F13_HANDLER      vector906
#define SPC5_EMIOS0_GFR_F14F15_HANDLER      vector907
#define SPC5_EMIOS0_GFR_F16F17_HANDLER      vector908
#define SPC5_EMIOS0_GFR_F18F19_HANDLER      vector909
#define SPC5_EMIOS0_GFR_F20F21_HANDLER      vector910
#define SPC5_EMIOS0_GFR_F22F23_HANDLER      vector911
#define SPC5_EMIOS0_GFR_F24F25_HANDLER      vector912
#define SPC5_EMIOS0_GFR_F26F27_HANDLER      vector913
#define SPC5_EMIOS0_GFR_F28F29_HANDLER      vector914
#define SPC5_EMIOS0_GFR_F30F31_HANDLER      vector915
#define SPC5_EMIOS0_GFR_F0F1_NUMBER         900
#define SPC5_EMIOS0_GFR_F2F3_NUMBER         901
#define SPC5_EMIOS0_GFR_F4F5_NUMBER         902
#define SPC5_EMIOS0_GFR_F6F7_NUMBER         903
#define SPC5_EMIOS0_GFR_F8F9_NUMBER         904
#define SPC5_EMIOS0_GFR_F10F11_NUMBER       905
#define SPC5_EMIOS0_GFR_F12F13_NUMBER       906
#define SPC5_EMIOS0_GFR_F14F15_NUMBER       907
#define SPC5_EMIOS0_GFR_F16F17_NUMBER       908
#define SPC5_EMIOS0_GFR_F18F19_NUMBER       909
#define SPC5_EMIOS0_GFR_F20F21_NUMBER       910
#define SPC5_EMIOS0_GFR_F22F23_NUMBER       911
#define SPC5_EMIOS0_GFR_F24F25_NUMBER       912
#define SPC5_EMIOS0_GFR_F26F27_NUMBER       913
#define SPC5_EMIOS0_GFR_F28F29_NUMBER       914
#define SPC5_EMIOS0_GFR_F30F31_NUMBER       915

#define SPC5_HAS_EMIOS1                     FALSE
#define SPC5_HAS_EMIOS2                     FALSE

/* WKPU Attributes */
#define SPC5_HAS_WKPU0                      TRUE
#define SPC5_WKPU0_BASE                     0xF7F98000UL
#define SPC5_WKPU0_IRQ0_HANDLER             vector247
#define SPC5_WKPU0_IRQ1_HANDLER             vector248
#define SPC5_WKPU0_IRQ2_HANDLER             vector249
#define SPC5_WKPU0_IRQ3_HANDLER             vector250
#define SPC5_WKPU0_IRQ0_INT_NUMBER          247
#define SPC5_WKPU0_IRQ1_INT_NUMBER          248
#define SPC5_WKPU0_IRQ2_INT_NUMBER          249
#define SPC5_WKPU0_IRQ3_INT_NUMBER          250

#define SPC5_HAS_WKPU1                      FALSE

#define SPC5_WKPU_SUPPORT_EXT_SRC           TRUE

/* BCTU Attributes */
#define SPC5_BCTU_BASE                      0xF7C30000UL
#define SPC5_BCTU_PCTL                      243
#define SPC5_BCTU_TRIGGER_NUMBER            32U

/* RTC attributes.*/
#define SCP5_RTC_RTC_HANDLER                vector224
#define SCP5_RTC_API_HANDLER                vector225
#define SCP5_RTC_RTC_INT_NUMBER             224
#define SCP5_RTC_API_INT_NUMBER             225

/** @} */

#endif /* SPC5_REGISTRY_H */

/** @} */

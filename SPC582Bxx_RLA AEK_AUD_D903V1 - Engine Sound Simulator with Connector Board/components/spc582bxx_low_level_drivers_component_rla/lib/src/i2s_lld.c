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
 * @file    i2s_lld.c
 * @brief   SPC5xx I2S low level driver code.
 *
 * @addtogroup I2S
 * @{
 */

#include "i2s_lld.h"

#if (LLD_USE_I2S == TRUE) || defined(__DOXYGEN__)

/* Some forward declarations.*/
static void i2s_serve_tx_dma_irq(edma_channel_t channel, void *p);
static void i2s_serve_rx_dma_irq(edma_channel_t channel, void *p);
static void i2s_serve_dma_error_irq(edma_channel_t channel, void *p, uint32_t esr);

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/* Set of macros dealing with the variable number of DMAs depending on
   the chosen mode.*/
#define i2s_lld_setdma(i2sp, tx1_cfg, tx2_cfg, rx_cfg) {                    \
  (i2sp)->tx1_channel = edmaChannelAllocate(&(tx1_cfg));                    \
  (i2sp)->tx2_channel = edmaChannelAllocate(&(tx2_cfg));                    \
  (i2sp)->rx_channel = edmaChannelAllocate(&(rx_cfg));                      \
}

#define i2s_lld_resetdma(tx1_cfg, tx2_cfg, rx_cfg) {                        \
  edmaChannelRelease(&(tx1_cfg));                                           \
  edmaChannelRelease(&(tx2_cfg));                                           \
  edmaChannelRelease(&(rx_cfg));                                            \
}

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   I2SD1 driver identifier.
 */
#if (SPC5_I2S_USE_DSPI0 == TRUE) || defined(__DOXYGEN__)
I2SDriver I2SD1;
#endif

/**
 * @brief   I2SD2 driver identifier.
 */
#if (SPC5_I2S_USE_DSPI1 == TRUE) || defined(__DOXYGEN__)
I2SDriver I2SD2;
#endif

/**
 * @brief   I2SD3 driver identifier.
 */
#if (SPC5_I2S_USE_DSPI2 == TRUE) || defined(__DOXYGEN__)
I2SDriver I2SD3;
#endif

/**
 * @brief   I2SD4 driver identifier.
 */
#if (SPC5_I2S_USE_DSPI3 == TRUE) || defined(__DOXYGEN__)
I2SDriver I2SD4;
#endif

/**
 * @brief   I2SD5 driver identifier.
 */
#if (SPC5_I2S_USE_DSPI4 == TRUE) || defined(__DOXYGEN__)
I2SDriver I2SD5;
#endif

/**
 * @brief   I2SD6 driver identifier.
 */
#if (SPC5_I2S_USE_DSPI5 == TRUE) || defined(__DOXYGEN__)
I2SDriver I2SD6;
#endif

/**
 * @brief   I2SD7 driver identifier.
 */
#if (SPC5_I2S_USE_DSPI6 == TRUE) || defined(__DOXYGEN__)
I2SDriver I2SD7;
#endif

/**
 * @brief   I2SD8 driver identifier.
 */
#if (SPC5_I2S_USE_DSPI7 == TRUE) || defined(__DOXYGEN__)
I2SDriver I2SD8;
#endif

/**
 * @brief   I2SD9 driver identifier.
 */
#if (SPC5_I2S_USE_DSPI8 == TRUE) || defined(__DOXYGEN__)
I2SDriver I2SD9;
#endif

/**
 * @brief   I2SD10 driver identifier.
 */
#if (SPC5_I2S_USE_DSPI9 == TRUE) || defined(__DOXYGEN__)
I2SDriver I2SD10;
#endif


/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

#if (SPC5_I2S_USE_DSPI0 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   DMA configuration for DSPI0 TX1.
 */
static edma_channel_config_t i2s_dspi0_tx1_dma_config = {
  SPC5_I2S_DSPI0_TX1_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX  == TRUE)
  SPC5_DSPI0_TX1_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI0_TX1_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI0_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD1
};

/**
 * @brief   DMA configuration for DSPI0 TX2.
 */
static edma_channel_config_t i2s_dspi0_tx2_dma_config = {
  SPC5_I2S_DSPI0_TX2_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI0_TX2_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI0_TX2_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI0_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD1
};

/**
 * @brief   DMA configuration for DSPI0 RX.
 */
static edma_channel_config_t i2s_dspi0_rx_dma_config = {
  SPC5_I2S_DSPI0_RX_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI0_RX_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI0_RX_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI0_DMA_IRQ_PRIO,
  i2s_serve_rx_dma_irq, i2s_serve_dma_error_irq, &I2SD1
};
#endif /* SPC5_I2S_USE_DSPI0 */

#if (SPC5_I2S_USE_DSPI1 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   DMA configuration for DSPI1 TX1.
 */
static edma_channel_config_t i2s_dspi1_tx1_dma_config = {
  SPC5_I2S_DSPI1_TX1_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX  == TRUE)
  SPC5_DSPI1_TX1_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI1_TX1_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI1_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD2
};

/**
 * @brief   DMA configuration for DSPI1 TX2.
 */
static edma_channel_config_t i2s_dspi1_tx2_dma_config = {
  SPC5_I2S_DSPI1_TX2_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI1_TX2_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI1_TX2_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI1_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD2
};

/**
 * @brief   DMA configuration for DSPI1 RX.
 */
static edma_channel_config_t i2s_dspi1_rx_dma_config = {
  SPC5_I2S_DSPI1_RX_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI1_RX_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI1_RX_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI1_DMA_IRQ_PRIO,
  i2s_serve_rx_dma_irq, i2s_serve_dma_error_irq, &I2SD2
};
#endif /* SPC5_I2S_USE_DSPI1 */

#if (SPC5_I2S_USE_DSPI2 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   DMA configuration for DSPI2 TX1.
 */
static edma_channel_config_t i2s_dspi2_tx1_dma_config = {
  SPC5_I2S_DSPI2_TX1_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX  == TRUE)
  SPC5_DSPI2_TX1_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI2_TX1_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI2_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD3
};

/**
 * @brief   DMA configuration for DSPI2 TX2.
 */
static edma_channel_config_t i2s_dspi2_tx2_dma_config = {
  SPC5_I2S_DSPI2_TX2_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI2_TX2_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI2_TX2_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI2_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD3
};

/**
 * @brief   DMA configuration for DSPI2 RX.
 */
static edma_channel_config_t i2s_dspi2_rx_dma_config = {
  SPC5_I2S_DSPI2_RX_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI2_RX_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI2_RX_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI2_DMA_IRQ_PRIO,
  i2s_serve_rx_dma_irq, i2s_serve_dma_error_irq, &I2SD3
};
#endif /* SPC5_I2S_USE_DSPI2 */

#if (SPC5_I2S_USE_DSPI3 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   DMA configuration for DSPI3 TX1.
 */
static edma_channel_config_t i2s_dspi3_tx1_dma_config = {
  SPC5_I2S_DSPI3_TX1_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX  == TRUE)
  SPC5_DSPI3_TX1_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI3_TX1_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI3_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD4
};

/**
 * @brief   DMA configuration for DSPI3 TX2.
 */
static edma_channel_config_t i2s_dspi3_tx2_dma_config = {
  SPC5_I2S_DSPI3_TX2_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI3_TX2_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI3_TX2_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI3_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD4
};

/**
 * @brief   DMA configuration for DSPI3 RX.
 */
static edma_channel_config_t i2s_dspi3_rx_dma_config = {
  SPC5_I2S_DSPI3_RX_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI3_RX_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI3_RX_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI3_DMA_IRQ_PRIO,
  i2s_serve_rx_dma_irq, i2s_serve_dma_error_irq, &I2SD4
};
#endif /* SPC5_I2S_USE_DSPI3 */

#if (SPC5_I2S_USE_DSPI4 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   DMA configuration for DSPI4 TX1.
 */
static edma_channel_config_t i2s_dspi4_tx1_dma_config = {
  SPC5_I2S_DSPI4_TX1_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX  == TRUE)
  SPC5_DSPI4_TX1_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI4_TX1_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI4_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD5
};

/**
 * @brief   DMA configuration for DSPI4 TX2.
 */
static edma_channel_config_t i2s_dspi4_tx2_dma_config = {
  SPC5_I2S_DSPI4_TX2_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI4_TX2_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI4_TX2_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI4_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD5
};

/**
 * @brief   DMA configuration for DSPI4 RX.
 */
static edma_channel_config_t i2s_dspi4_rx_dma_config = {
  SPC5_I2S_DSPI4_RX_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI4_RX_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI4_RX_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI4_DMA_IRQ_PRIO,
  i2s_serve_rx_dma_irq, i2s_serve_dma_error_irq, &I2SD5
};
#endif /* SPC5_I2S_USE_DSPI4 */

#if (SPC5_I2S_USE_DSPI5 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   DMA configuration for DSPI5 TX1.
 */
static edma_channel_config_t i2s_dspi5_tx1_dma_config = {
  SPC5_I2S_DSPI5_TX1_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX  == TRUE)
  SPC5_DSPI5_TX1_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI5_TX1_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI5_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD6
};

/**
 * @brief   DMA configuration for DSPI5 TX2.
 */
static edma_channel_config_t i2s_dspi5_tx2_dma_config = {
  SPC5_I2S_DSPI5_TX2_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI5_TX2_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI5_TX2_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI5_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD6
};

/**
 * @brief   DMA configuration for DSPI5 RX.
 */
static edma_channel_config_t i2s_dspi5_rx_dma_config = {
  SPC5_I2S_DSPI5_RX_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI5_RX_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI5_RX_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI5_DMA_IRQ_PRIO,
  i2s_serve_rx_dma_irq, i2s_serve_dma_error_irq, &I2SD6
};
#endif /* SPC5_I2S_USE_DSPI5 */

#if (SPC5_I2S_USE_DSPI6 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   DMA configuration for DSPI6 TX1.
 */
static edma_channel_config_t i2s_dspi6_tx1_dma_config = {
  SPC5_I2S_DSPI6_TX1_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX  == TRUE)
  SPC5_DSPI6_TX1_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI6_TX1_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI6_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD7
};

/**
 * @brief   DMA configuration for DSPI6 TX2.
 */
static edma_channel_config_t i2s_dspi6_tx2_dma_config = {
  SPC5_I2S_DSPI6_TX2_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI6_TX2_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI6_TX2_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI6_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD7
};

/**
 * @brief   DMA configuration for DSPI6 RX.
 */
static edma_channel_config_t i2s_dspi6_rx_dma_config = {
  SPC5_I2S_DSPI6_RX_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI6_RX_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI6_RX_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI6_DMA_IRQ_PRIO,
  i2s_serve_rx_dma_irq, i2s_serve_dma_error_irq, &I2SD7
};
#endif /* SPC5_I2S_USE_DSPI6 */

#if (SPC5_I2S_USE_DSPI7 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   DMA configuration for DSPI7 TX1.
 */
static edma_channel_config_t i2s_dspi7_tx1_dma_config = {
  SPC5_I2S_DSPI7_TX1_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX  == TRUE)
  SPC5_DSPI7_TX1_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI7_TX1_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI7_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD8
};

/**
 * @brief   DMA configuration for DSPI7 TX2.
 */
static edma_channel_config_t i2s_dspi7_tx2_dma_config = {
  SPC5_I2S_DSPI7_TX2_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI7_TX2_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI7_TX2_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI7_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD8
};

/**
 * @brief   DMA configuration for DSPI7 RX.
 */
static edma_channel_config_t i2s_dspi7_rx_dma_config = {
  SPC5_I2S_DSPI7_RX_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI7_RX_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI7_RX_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI7_DMA_IRQ_PRIO,
  i2s_serve_rx_dma_irq, i2s_serve_dma_error_irq, &I2SD8
};
#endif /* SPC5_I2S_USE_DSPI7 */

#if (SPC5_I2S_USE_DSPI8 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   DMA configuration for DSPI8 TX1.
 */
static edma_channel_config_t i2s_dspi8_tx1_dma_config = {
  SPC5_I2S_DSPI8_TX1_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX  == TRUE)
  SPC5_DSPI8_TX1_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI8_TX1_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI8_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD9
};

/**
 * @brief   DMA configuration for DSPI8 TX2.
 */
static edma_channel_config_t i2s_dspi8_tx2_dma_config = {
  SPC5_I2S_DSPI8_TX2_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI8_TX2_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI8_TX2_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI8_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD9
};

/**
 * @brief   DMA configuration for DSPI8 RX.
 */
static edma_channel_config_t i2s_dspi8_rx_dma_config = {
  SPC5_I2S_DSPI8_RX_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI8_RX_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI8_RX_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI8_DMA_IRQ_PRIO,
  i2s_serve_rx_dma_irq, i2s_serve_dma_error_irq, &I2SD9
};
#endif /* SPC5_I2S_USE_DSPI8 */

#if (SPC5_I2S_USE_DSPI9 == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   DMA configuration for DSPI9 TX1.
 */
static edma_channel_config_t i2s_DSPI9_tx1_dma_config = {
  SPC5_I2S_DSPI9_TX1_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX  == TRUE)
  SPC5_DSPI9_TX1_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI9_TX1_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI9_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD10
};

/**
 * @brief   DMA configuration for DSPI9 TX2.
 */
static edma_channel_config_t i2s_DSPI9_tx2_dma_config = {
  SPC5_I2S_DSPI9_TX2_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI9_TX2_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI9_TX2_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI9_DMA_IRQ_PRIO,
  i2s_serve_tx_dma_irq, i2s_serve_dma_error_irq, &I2SD10
};
/**
 * @brief   DMA configuration for DSPI9 RX.
 */
static edma_channel_config_t i2s_dspi9_rx_dma_config = {
  SPC5_I2S_DSPI9_RX_DMA_CH_ID,
#if (SPC5_EDMA_HAS_MUX == TRUE)
  SPC5_DSPI9_RX_DMA_DEV_ID,
#if (SPC5_EDMA_NUM_OF_MUX > 1U)
  SPC5_DSPI9_RX_DMA_MUX,
#endif /* (SPC5_EDMA_NUM_OF_MUX > 1U) */
#endif /* SPC5_EDMA_HAS_MUX */
  SPC5_I2S_DSPI9_DMA_IRQ_PRIO,
  i2s_serve_rx_dma_irq, i2s_serve_dma_error_irq, &I2SD10
};
#endif /* SPC5_I2S_USE_DSPI9 */

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Initializes the invariant part of the @p I2SDriver structure.
 *
 * @param[in] i2sp      pointer to the @p I2SDriver object
 * @param[in] dspi      the physical DSPI unit to be associated to the object
 *
 * @notapi
 */
static void i2s_lld_obj_init(I2SDriver *i2sp, struct spc5_dspi *dspi) {

  i2sp->dspi = dspi;
  i2sp->tx1_channel = EDMA_ERROR;
  i2sp->tx2_channel = EDMA_ERROR;
  i2sp->rx_channel = EDMA_ERROR;
}

/**
 * @brief   DSPI unit setup for transfer.
 *
 * @param[in] i2sp      pointer to the @p I2SDriver object
 *
 * @notapi
 */
static void i2s_dspi_start(I2SDriver *i2sp) {

  i2sp->dspi->SR.R = 0xFFFFFFFFUL;
  i2sp->dspi->MCR.B.HALT = 0;
}

/**
 * @brief   DSPI unit transfer stop.
 *
 * @param[in] i2sp      pointer to the @p I2SDriver object
 *
 * @notapi
 */
static void i2s_dspi_stop(I2SDriver *i2sp) {

  /* Stops the DSPI and clears the queues.*/
  i2sp->dspi->MCR.R |= SPC5_MCR_HALT | SPC5_MCR_CLR_TXF | SPC5_MCR_CLR_RXF;
}

/**
 * @brief   Starts transmission using DMA for frames up to 8 bits.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of words to be exchanged
 * @param[in] txbuf     the pointer to the transmit buffer
 *
 * @notapi
 */
static uint32_t i2s_start_playback(I2SDriver *i2sp, size_t n, uint8_t *txbuf) {

  uint8_t *src, *dst;
  uint32_t mode;
  int32_t len = ((int32_t)n) * -1;

  /* Preparing the TX intermediate buffer with the fixed part.*/
  if (i2sp->config->sample_size == 32U) {
    i2sp->tx_intermediate_buffer[0] = i2sp->config->pushr_left;
    i2sp->tx_intermediate_buffer[1] = i2sp->config->pushr_left;
    i2sp->tx_intermediate_buffer[2] = i2sp->config->pushr_right;
    i2sp->tx_intermediate_buffer[3] = i2sp->config->pushr_right;
  } else {
    /* Not supported */
    return 1;
  }

  /* Set interrupts */
  mode = EDMA_TCD_MODE_DREQ | EDMA_TCD_MODE_INT_END;
  if (i2sp->config->half_cb != NULL) {
    mode |= EDMA_TCD_MODE_INT_HALF;
  }
  /* Setting up TX1 DMA TCD parameters for 32 bits transfers.*/
  src = txbuf;
  dst = ((uint8_t *)&i2sp->tx_intermediate_buffer[0]) + 2;
  edmaChannelSetupLinked(
                   i2sp->tx1_channel,           /* channel.                 */
                   i2sp->tx2_channel,           /* linkch.                  */
                   src,                         /* src.                     */
                   dst,                         /* dst.                     */
                   2,                           /* soff, advance by 1.      */
                   4,                           /* doff, advance by 4.      */
                   1,                           /* ssize, 8 bits transfers. */
                   0x21,                        /* dsize, 8 bits transfers. */
                   2,                           /* nbytes, always 2.        */
                   n >> 1,                      /* iter.                    */
                   len,                         /* slast, no source adjust. */
                   0,                           /* dlast, no dest.adjust.   */
                   mode);                       /* mode.                    */

  /* Setting up TX2 DMA TCD parameters for 32 bits transfers.*/
  edmaChannelSetup(
                   i2sp->tx2_channel,           /* channel.                 */
                   &i2sp->tx_intermediate_buffer[0],               /* src.                     */
                   &i2sp->dspi->PUSHR.R,        /* dst.                     */
                   4,                           /* soff, advance by 4.      */
                   0,                           /* doff, do not advance.    */
                   0x22,                        /* ssize, 32 bits transfers.*/
                   2,                           /* dsize, 32 bits transfers.*/
                   4,                           /* nbytes, always four.     */
                   1,                           /* iter.                    */
                   0,                           /* slast, no source adjust. */
                   0,                           /* dlast, no dest.adjust.   */
                   EDMA_TCD_MODE_DREQ);         /* mode.    */


  edmaChannelStart(i2sp->tx1_channel);
  edmaChannelStart(i2sp->tx2_channel);

  return 0;
}


static uint32_t i2s_start_receive(I2SDriver *i2sp, size_t n, uint8_t *rxbuf) {

  uint8_t *src, *dst;
  uint32_t mode;
  int32_t len = ((int32_t)n) * (-1);

  /* Set interrupts */
  mode = EDMA_TCD_MODE_DREQ | EDMA_TCD_MODE_INT_END | EDMA_TCD_MODE_INT_HALF;

  dst = rxbuf;
  src = (((uint8_t *)&(i2sp)->dspi->POPR.R) + 2U);

  /* Setting up RX DMA TCD parameters for 32 bits transfers.*/
  edmaChannelSetup(
                   i2sp->rx_channel,            /* channel.                 */
                   src,                         /* src.                     */
                   dst,                         /* dst.                     */
                   0,                           /* soff, do not advance.    */
                   2,                           /* doff, advance by 2.      */
                   1,                           /* ssize, 16 bits transfers.*/
                   1,                           /* dsize, 16 bits transfers.*/
                   2,                           /* nbytes, always two.     */
                   n >> 1,                      /* iter.                    */
                   0,                           /* slast, no source adjust. */
                   len,                         /* dlast, no dest.adjust.   */
                   mode);                       /* mode.    */

  edmaChannelStart(i2sp->rx_channel);

  return 0;
}


/**
 * @brief   Shared TX1/TX2 DMA events service routine.
 *
 * @param[in] channel   the channel number
 * @param[in] p         parameter for the registered function
 *
 * @notapi
 */
static void i2s_serve_tx_dma_irq(edma_channel_t channel, void *p) {

  /*lint -e9087 */
  I2SDriver *i2sp = (I2SDriver *)p;
  /*lint +e9087 */

  edma_tcd_t *tcdp = edmaGetTCD(channel);
  uint32_t current_iter;

  current_iter = (tcdp->word[5] >> 16) & 0x1FFU;

  if (current_iter == (i2sp->buf_len >> 2)) {

    if (i2sp->config->half_cb != NULL) {
      /* Call half transmit callback */
      i2sp->config->half_cb(i2sp);
    }

  } else {

    /* End interrupt is always enabled */
    if ((i2sp)->config->end_cb != NULL) {
      (i2sp)->config->end_cb(i2sp);
    }

    if (i2sp->playback_opts == SPC5_I2S_LOOP_FOREVER) {
      /* Playing forever, restart DMA.*/
      edmaChannelStart(i2sp->tx1_channel);
      edmaChannelStart(i2sp->tx2_channel);
    } else if (--i2sp->playback_opts == 0) {
      /* Clearing TX channels state.*/
      edmaChannelStop(i2sp->tx1_channel);
      edmaChannelStop(i2sp->tx2_channel);

      /* Call end callback and unblock caller */
      _i2s_isr_code(i2sp);
    } else {
      /* Misra */
    }

  }
}

/**
 * @brief   Shared RX DMA events service routine.
 *
 * @param[in] channel   the channel number
 * @param[in] p         parameter for the registered function
 *
 * @notapi
 */
static void i2s_serve_rx_dma_irq(edma_channel_t channel, void *p) {
  /*Casting of void pointer needful for using the same DMA driver
    in different drivers. */
  /*lint -e9087 */
  I2SDriver *i2sp = (I2SDriver *)p;
  /*lint +e9087 */

  edma_tcd_t *tcdp = edmaGetTCD(channel);
  uint32_t current_iter;

  current_iter = (tcdp->word[5] >> 16) & 0x1FFU;

  if (current_iter == (i2sp->buf_len >> 2)) {

    if (i2sp->config->half_rx_cb != NULL) {
      /* Call half receive callback */
      i2sp->config->half_rx_cb(i2sp);
    }

  } else {

    /* End interrupt is always enabled */
    if ((i2sp)->config->end_rx_cb != NULL) {
      (i2sp)->config->end_rx_cb(i2sp);
    }

    if (i2sp->playback_opts == SPC5_I2S_LOOP_FOREVER) {
      /* Playing forever, restart DMA.*/
      edmaChannelStart(i2sp->rx_channel);
    } else if (--i2sp->playback_opts == 0) {
      /* Clearing RX channels state.*/
      edmaChannelStop(i2sp->rx_channel);
    } else {
      /* Misra */
    }
  }
}

/**
 * @brief   Shared ISR for DMA error events.
 *
 * @param[in] channel   the channel number
 * @param[in] p         parameter for the registered function
 * @param[in] esr       content of the ESR register
 *
 * @notapi
 */
static void i2s_serve_dma_error_irq(edma_channel_t channel,
                                    void *p,
                                    uint32_t esr) {
  /*lint -e9087 */
  I2SDriver *i2sp = (I2SDriver *)p;
  /*lint +e9087 */

  (void)channel;
  (void)esr;

  /* Stops the transfer.*/
  i2s_dspi_stop(i2sp);

  edmaChannelStop(i2sp->tx1_channel);
  edmaChannelStop(i2sp->tx2_channel);

  SPC5_I2S_DMA_ERROR_HOOK(i2sp);
}


/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level I2S driver initialization.
 *
 * @init
 */
void i2s_lld_init(void) {

#if (SPC5_I2S_USE_DSPI0 == TRUE)
  /* Driver initialization.*/
  SPC5_I2S_DSPI0_ENABLE_CLOCK();
  I2SD1.config = NULL;
  i2s_lld_obj_init(&I2SD1, &SPC5_DSPI0);
  SPC5_DSPI0.MCR.R  = SPC5_MCR_MSTR |
                      SPC5_MCR_HALT |
                      SPC5_MCR_MDIS |
                      SPC5_MCR_CONT_SCKE |
                      SPC5_I2S_DSPI0_MCR;
  INTC_PSR(SPC5_DSPI0_TFFF_NUMBER) = SPC5_I2S_DSPI0_IRQ_PRIO;
#endif /* SPC5_I2S_USE_DSPI0 */

#if (SPC5_I2S_USE_DSPI1 == TRUE)
  /* Driver initialization.*/
  SPC5_I2S_DSPI1_ENABLE_CLOCK();
  I2SD2.config = NULL;
  i2s_lld_obj_init(&I2SD2, &SPC5_DSPI1);
  SPC5_DSPI1.MCR.R  = SPC5_MCR_MSTR |
                      SPC5_MCR_HALT |
					  SPC5_MCR_MDIS |
					  SPC5_MCR_CONT_SCKE |
                      SPC5_I2S_DSPI1_MCR;
  INTC_PSR(SPC5_DSPI1_TFFF_NUMBER) = SPC5_I2S_DSPI1_DMA_IRQ_PRIO;
#endif /* SPC5_I2S_USE_DSPI1 */

#if (SPC5_I2S_USE_DSPI2 == TRUE)
  /* Driver initialization.*/
  SPC5_I2S_DSPI2_ENABLE_CLOCK();
  I2SD3.config = NULL;
  i2s_lld_obj_init(&I2SD3, &SPC5_DSPI2);
  SPC5_DSPI2.MCR.R  = SPC5_MCR_MSTR |
                      SPC5_MCR_HALT |
					  SPC5_MCR_MDIS |
					  SPC5_MCR_CONT_SCKE |
                      SPC5_I2S_DSPI2_MCR;
  INTC_PSR(SPC5_DSPI2_TFFF_NUMBER) = SPC5_I2S_DSPI2_DMA_IRQ_PRIO;
#endif /* SPC5_I2S_USE_DSPI2 */

#if (SPC5_I2S_USE_DSPI3 == TRUE)
  /* Driver initialization.*/
  SPC5_I2S_DSPI3_ENABLE_CLOCK();
  I2SD4.config = NULL;
  i2s_lld_obj_init(&I2SD4, &SPC5_DSPI3);
  SPC5_DSPI3.MCR.R  = SPC5_MCR_MSTR |
                      SPC5_MCR_HALT |
					  SPC5_MCR_MDIS |
					  SPC5_MCR_CONT_SCKE |
                      SPC5_I2S_DSPI3_MCR;
  INTC_PSR(SPC5_DSPI3_TFFF_NUMBER) = SPC5_I2S_DSPI3_IRQ_PRIO;
#endif /* SPC5_I2S_USE_DSPI3 */

#if (SPC5_I2S_USE_DSPI4 == TRUE)
  /* Driver initialization.*/
  SPC5_I2S_DSPI4_ENABLE_CLOCK();
  I2SD5.config = NULL;
  i2s_lld_obj_init(&I2SD5, &SPC5_DSPI4);
  SPC5_DSPI4.MCR.R  = SPC5_MCR_MSTR |
                      SPC5_MCR_HALT |
					  SPC5_MCR_MDIS |
					  SPC5_MCR_CONT_SCKE |
                      SPC5_I2S_DSPI4_MCR;
  INTC_PSR(SPC5_DSPI4_TFFF_NUMBER) = SPC5_I2S_DSPI4_IRQ_PRIO;
#endif /* SPC5_I2S_USE_DSPI4 */

#if (SPC5_I2S_USE_DSPI5 == TRUE)
  /* Driver initialization.*/
  SPC5_I2S_DSPI5_ENABLE_CLOCK();
  I2SD6.config = NULL;
  i2s_lld_obj_init(&I2SD6, &SPC5_DSPI5);
  SPC5_DSPI5.MCR.R  = SPC5_MCR_MSTR |
                      SPC5_MCR_HALT |
					  SPC5_MCR_MDIS |
					  SPC5_MCR_CONT_SCKE |
                      SPC5_I2S_DSPI5_MCR;
  INTC_PSR(SPC5_DSPI5_TFFF_NUMBER) = SPC5_I2S_DSPI5_IRQ_PRIO;
#endif /* SPC5_I2S_USE_DSPI5 */

#if (SPC5_I2S_USE_DSPI6 == TRUE)
  /* Driver initialization.*/
  SPC5_I2S_DSPI6_ENABLE_CLOCK();
  I2SD7.config = NULL;
  i2s_lld_obj_init(&I2SD7, &SPC5_DSPI6);
  SPC5_DSPI6.MCR.R  = SPC5_MCR_MSTR |
                      SPC5_MCR_HALT |
					  SPC5_MCR_MDIS |
					  SPC5_MCR_CONT_SCKE |
                      SPC5_I2S_DSPI6_MCR;
  INTC_PSR(SPC5_DSPI6_TFFF_NUMBER) = SPC5_I2S_DSPI6_IRQ_PRIO;
#endif /* SPC5_I2S_USE_DSPI6 */

#if (SPC5_I2S_USE_DSPI7 == TRUE)
  /* Driver initialization.*/
  SPC5_I2S_DSPI7_ENABLE_CLOCK();
  I2SD8.config = NULL;
  i2s_lld_obj_init(&I2SD8, &SPC5_DSPI7);
  SPC5_DSPI7.MCR.R  = SPC5_MCR_MSTR |
                      SPC5_MCR_HALT |
					  SPC5_MCR_MDIS |
					  SPC5_MCR_CONT_SCKE |
                      SPC5_I2S_DSPI7_MCR;
  INTC_PSR(SPC5_DSPI7_TFFF_NUMBER) = SPC5_I2S_DSPI7_IRQ_PRIO;
#endif /* SPC5_I2S_USE_DSPI7 */

#if (SPC5_I2S_USE_DSPI8 == TRUE)
  /* Driver initialization.*/
  SPC5_I2S_DSPI8_ENABLE_CLOCK();
  I2SD9.config = NULL;
  i2s_lld_obj_init(&I2SD9, &SPC5_DSPI8);
  SPC5_DSPI8.MCR.R  = SPC5_MCR_MSTR |
                      SPC5_MCR_HALT |
					  SPC5_MCR_MDIS |
					  SPC5_MCR_CONT_SCKE |
                      SPC5_I2S_DSPI8_MCR;
  INTC_PSR(SPC5_DSPI8_TFFF_NUMBER) = SPC5_I2S_DSPI8_IRQ_PRIO;
#endif /* SPC5_I2S_USE_DSPI8 */

#if (SPC5_I2S_USE_DSPI9 == TRUE)
  /* Driver initialization.*/
  SPC5_I2S_DSPI9_ENABLE_CLOCK();
  I2SD10.config = NULL;
  i2s_lld_obj_init(&I2SD10, &SPC5_DSPI9);
  SPC5_DSPI9.MCR.R  = SPC5_MCR_MSTR |
                      SPC5_MCR_HALT |
					  SPC5_MCR_MDIS |
					  SPC5_MCR_CONT_SCKE |
                      SPC5_I2S_DSPI9_MCR;
  INTC_PSR(SPC5_DSPI9_TFFF_NUMBER) = SPC5_I2S_DSPI9_IRQ_PRIO;
#endif /* SPC5_I2S_USE_DSPI9 */

}

/**
 * @brief   Configures and activates the I2S peripheral.
 *
 * @param[in] i2sp      pointer to the @p I2SDriver object
 * @param[in] config    pointer to the @p I2SConfig object
 *
 * @api
 */
void i2s_lld_start(I2SDriver *i2sp, I2SConfig *config) {

  i2sp->config = config;

  /* Enables the peripheral.*/
#if (SPC5_I2S_USE_DSPI0 == TRUE)
  if (&I2SD1 == i2sp) {
    i2s_lld_setdma(i2sp,
                   i2s_dspi0_tx1_dma_config,
                   i2s_dspi0_tx2_dma_config,
                   i2s_dspi0_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI0 */

#if (SPC5_I2S_USE_DSPI1 == TRUE)
  if (&I2SD2 == i2sp) {
    i2s_lld_setdma(i2sp,
                   i2s_dspi1_tx1_dma_config,
                   i2s_dspi1_tx2_dma_config,
                   i2s_dspi1_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI1 */

#if (SPC5_I2S_USE_DSPI2 == TRUE)
  if (&I2SD3 == i2sp) {
    i2s_lld_setdma(i2sp,
                   i2s_dspi2_tx1_dma_config,
                   i2s_dspi2_tx2_dma_config,
                   i2s_dspi2_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI2 */

#if (SPC5_I2S_USE_DSPI3 == TRUE)
  if (&I2SD4 == i2sp) {
    i2s_lld_setdma(i2sp,
                   i2s_dspi3_tx1_dma_config,
                   i2s_dspi3_tx2_dma_config,
                   i2s_dspi3_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI3 */

#if (SPC5_I2S_USE_DSPI4 == TRUE)
  if (&I2SD5 == i2sp) {
    i2s_lld_setdma(i2sp,
                   i2s_dspi4_tx1_dma_config,
                   i2s_dspi4_tx2_dma_config,
                   i2s_dspi4_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI4 */

#if (SPC5_I2S_USE_DSPI5 == TRUE)
  if (&I2SD6 == i2sp) {
    i2s_lld_setdma(i2sp,
                   i2s_dspi5_tx1_dma_config,
                   i2s_dspi5_tx2_dma_config,
                   i2s_dspi5_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI5 */

#if (SPC5_I2S_USE_DSPI6 == TRUE)
  if (&I2SD7 == i2sp) {
    i2s_lld_setdma(i2sp,
                   i2s_dspi6_tx1_dma_config,
                   i2s_dspi6_tx2_dma_config,
                   i2s_dspi6_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI6 */

#if (SPC5_I2S_USE_DSPI7 == TRUE)
  if (&I2SD8 == i2sp) {
    i2s_lld_setdma(i2sp,
                   i2s_dspi7_tx1_dma_config,
                   i2s_dspi7_tx2_dma_config,
                   i2s_dspi7_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI7 */

#if (SPC5_I2S_USE_DSPI8 == TRUE)
  if (&I2SD9 == i2sp) {
    i2s_lld_setdma(i2sp,
                   i2s_dspi8_tx1_dma_config,
                   i2s_dspi8_tx2_dma_config,
                   i2s_dspi8_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI8 */

#if (SPC5_I2S_USE_DSPI9 == TRUE)
  if (&I2SD10 == i2sp) {
    i2s_lld_setdma(i2sp,
                   i2s_dspi9_tx1_dma_config,
                   i2s_dspi9_tx2_dma_config,
                   i2s_dspi9_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI9 */

  /* Configures the peripheral, the RSER register setting depend on the
     chosen DMA use mode.*/
  i2sp->dspi->MCR.B.MDIS = 0;
  i2sp->dspi->CTAR[0].R  = i2sp->config->ctar0;
  i2sp->dspi->RSER.R     = SPC5_RSER_TFFF_RE | SPC5_RSER_TFFF_DIRS |
                           SPC5_RSER_RFDF_RE | SPC5_RSER_RFDF_DIRS;
  i2sp->dspi->SR.R       = 0xFFFFFFFFUL;
}

/**
 * @brief   Deactivates the I2S peripheral.
 *
 * @param[in] i2sp      pointer to the @p I2SDriver object
 *
 * @api
 */
void i2s_lld_stop(I2SDriver *i2sp) {

  /* Releases the allocated EDMA channels.*/
#if (SPC5_I2S_USE_DSPI0 == TRUE)
  if (&I2SD1 == i2sp) {
    i2s_lld_resetdma(i2s_dspi0_tx1_dma_config,
                     i2s_dspi0_tx2_dma_config,
                     i2s_dspi0_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI0 */

#if (SPC5_I2S_USE_DSPI1 == TRUE)
  if (&I2SD2 == i2sp) {
    i2s_lld_resetdma(i2s_dspi1_tx1_dma_config,
                     i2s_dspi1_tx2_dma_config,
                     i2s_dspi1_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI1 */

#if (SPC5_I2S_USE_DSPI2 == TRUE)
  if (&I2SD3 == i2sp) {
    i2s_lld_resetdma(i2s_dspi2_tx1_dma_config,
                     i2s_dspi2_tx2_dma_config,
                     i2s_dspi2_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI2 */

#if (SPC5_I2S_USE_DSPI3 == TRUE)
  if (&I2SD4 == i2sp) {
    i2s_lld_resetdma(i2s_dspi3_tx1_dma_config,
                     i2s_dspi3_tx2_dma_config,
                     i2s_dspi3_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI3 */

#if (SPC5_I2S_USE_DSPI4 == TRUE)
  if (&I2SD5 == i2sp) {
    i2s_lld_resetdma(i2s_dspi4_tx1_dma_config,
                     i2s_dspi4_tx2_dma_config,
                     i2s_dspi4_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI4 */

#if (SPC5_I2S_USE_DSPI5 == TRUE)
  if (&I2SD6 == i2sp) {
    i2s_lld_resetdma(i2s_dspi5_tx1_dma_config,
                     i2s_dspi5_tx2_dma_config,
                     i2s_dspi5_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI5 */

#if (SPC5_I2S_USE_DSPI6 == TRUE)
  if (&I2SD7 == i2sp) {
    i2s_lld_resetdma(i2s_dspi6_tx1_dma_config,
                     i2s_dspi6_tx2_dma_config,
                     i2s_dspi6_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI6 */

#if (SPC5_I2S_USE_DSPI7 == TRUE)
  if (&I2SD8 == i2sp) {
    i2s_lld_resetdma(i2s_dspi7_tx1_dma_config,
                     i2s_dspi7_tx2_dma_config,
                     i2s_dspi7_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI7 */

#if (SPC5_I2S_USE_DSPI8 == TRUE)
  if (&I2SD9 == i2sp) {
    i2s_lld_resetdma(i2s_dspi8_tx1_dma_config,
                     i2s_dspi8_tx2_dma_config,
                     i2s_dspi8_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI8 */

#if (SPC5_I2S_USE_DSPI9 == TRUE)
  if (&I2SD10 == i2sp) {
    i2s_lld_resetdma(i2s_dspi9_tx1_dma_config,
                     i2s_dspi9_tx2_dma_config,
                     i2s_dspi9_rx_dma_config)
  }
#endif /* SPC5_I2S_USE_DSPI9 */

  /* Resets the peripheral.*/
  i2sp->dspi->CTAR[0].R  = 0;
  i2sp->dspi->RSER.R     = 0;
  i2sp->dspi->SR.R       = 0xFFFFFFFFUL;
  i2sp->dspi->MCR.R     |= SPC5_MCR_HALT |
                           SPC5_MCR_CLR_TXF | SPC5_MCR_CLR_RXF;
  i2sp->dspi->MCR.B.MDIS = 1;
}

/**
 * @brief   Sends data over the I2S bus.
 * @details This asynchronous function starts a transmit operation.
 * @post    At the end of the operation the configured callback is invoked.
 * @note    The buffers are organized as uint8_t arrays for data sizes below or
 *          equal to 8 bits else it is organized as uint16_t arrays.
 *
 * @param[in] i2sp      pointer to the @p I2SDriver object
 * @param[in] n         number of words to send
 * @param[in] buffer    the pointer to the transmit buffer
 * @param[in] options   playback options
 *
 * @api
 */
void i2s_lld_playback(I2SDriver *i2sp, size_t n, void *buffer, int32_t options) {

  uint32_t ret;

  i2sp->ready = FALSE;

  i2sp->playback_opts = options;
  i2sp->buf_len = n;

  /* Starting transfer.*/
  i2s_dspi_start(i2sp);

  /* DMA setup. */
  ret = i2s_start_playback(i2sp, n, buffer);

  if ((ret == 0U) && (i2sp->playback_opts != SPC5_I2S_LOOP_FOREVER)) {
    _i2s_wait_s(i2sp);
  }
}


void i2s_lld_playbackEx(I2SDriver *i2sp, size_t n, void *tx_buf, int32_t options, void *rx_buf) {

  uint32_t ret;

  i2sp->ready = FALSE;

  i2sp->playback_opts = options;
  i2sp->buf_len = n;

  /* Starting transfer.*/
  i2s_dspi_start(i2sp);

  /* DMA setup. */
  ret = i2s_start_playback(i2sp, n, tx_buf);
  ret = i2s_start_receive(i2sp, n, rx_buf);

  if ((ret == 0U) && (i2sp->playback_opts != SPC5_I2S_LOOP_FOREVER)) {
    _i2s_wait_s(i2sp);
  }
}

void i2s_lld_stop_playback(I2SDriver *i2sp) {

  osalEnterCritical();
  i2sp->playback_opts = 1;
  osalExitCritical();

  _i2s_wait_s(i2sp);
}
#endif /* LLD_USE_I2S */

/** @} */

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
 * @file    can_lld.h
 * @brief   SPC5xx CAN low level driver header.
 *
 * @addtogroup CAN
 * @{
 */

#ifndef _CAN_LLD_H_
#define _CAN_LLD_H_

#include "spc5_lld.h"
#include "lldconf.h"

#if (LLD_USE_CAN == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/
/**
 * @name    CAN macros
 * @{
 */
#define CAN_DEDICATED_RXBUFFER   0xFCU
#define CAN_FIFO0_RXBUFFER       0xFDU
#define CAN_FIFO1_RXBUFFER       0xFEU
#define CAN_DEDICATED_TXBUFFER   0xFFU
#define CAN_FIFO_TXBUFFER        0xFBU
#define CAN_QUEUE_TXBUFFER       0xFCU
#define CAN_MIXED_FIFO_TXBUFFER  0xFDU
#define CAN_MIXED_QUEUE_TXBUFFER 0xFEU
#define CAN_ANY_TXBUFFER         0xFFUL
#define CAN_ANY_RXBUFFER         0xFFUL
#define CAN_NO_LOOPBACK          0x00U
#define CAN_INTERNAL_LOOPBACK    0x01U
#define CAN_EXTERNAL_LOOPBACK    0x02U
#define CAN_RX_INT_DISABLE       0xFFU
#define CAN_TX_INT_DISABLE       0xFFU
#define CAN_FIFO0_INT_DISABLE    0xFFU
#define CAN_FIFO1_INT_DISABLE    0xFFU
#define CAN_LINE0_INT            0x00U
#define CAN_LINE1_INT            0x01U
#define CAN_ID_STD               0x00U
#define CAN_ID_XTD               0x01U
#define CAN_OP_NORMAL            0x00U
#define CAN_OP_CANFD             0x01U
#define CAN_MSG_WAIT             1U
#define CAN_MSG_OK               0U
#define CAN_TXMODE_NOT_SUPPORTED 2U
#define CAN_SIZE_NOT_SUPPORTED   3U
#define CAN_INTERRUPT_ENABLED    1U
#define CAN_INTERRUPT_DISABLED   0U
#define CAN_FILTER_RANGE         0U
#define CAN_FILTER_DUALID        1U
#define CAN_FILTER_CLASSIC       2U
#define CAN_FIFO0				 1U
#define CAN_FIFO1				 2U
#define CAN_ROUND16(x) ((uint32_t)x%16UL==0UL? (uint32_t)x:(((uint32_t)x/16UL)+1UL)*16UL)
#define CAN_LITTLE_ENDIAN        0U
#define CAN_BIG_ENDIAN           1U
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */

/**
 * @brief   CAND1 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_0_M_CAN_0) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_0_M_CAN_0        FALSE
#endif

/**
 * @brief   CAND2 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_0_M_CAN_1) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_0_M_CAN_1        FALSE
#endif
/**
 * @brief   CAND3 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_0_M_CAN_2) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_0_M_CAN_2      FALSE
#endif
/**
 * @brief   CAND4 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_0_M_CAN_3) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_0_M_CAN_3        FALSE
#endif

/**
 * @brief   CAND5 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_0_M_CAN_4) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_0_M_CAN_4        FALSE
#endif

/**
 * @brief   CAND6 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_1_M_CAN_0) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_1_M_CAN_0        FALSE
#endif

/**
 * @brief   CAND7 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_1_M_CAN_1) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_1_M_CAN_1        FALSE
#endif

/**
 * @brief   CAND8 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_1_M_CAN_2) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_1_M_CAN_2        FALSE
#endif
/**
 * @brief   CAND9 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_1_M_CAN_3) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_1_M_CAN_3        FALSE
#endif

/**
 * @brief   CAND10 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_1_M_CAN_4) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_1_M_CAN_4        FALSE
#endif

/**
 * @brief   CAND11 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_2_M_CAN_0) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_2_M_CAN_0        FALSE
#endif

/**
 * @brief   CAND12 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_2_M_CAN_1) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_2_M_CAN_1        FALSE
#endif

/**
 * @brief   CAND13 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_2_M_CAN_2) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_2_M_CAN_2        FALSE
#endif
/**
 * @brief   CAND14 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_2_M_CAN_3) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_2_M_CAN_3        FALSE
#endif

/**
 * @brief   CAND15 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_2_M_CAN_4) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_2_M_CAN_4        FALSE
#endif

/**
 * @brief   CAND16 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_3_M_CAN_0) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_3_M_CAN_0        FALSE
#endif

/**
 * @brief   CAND17 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_3_M_CAN_1) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_3_M_CAN_1        FALSE
#endif

/**
 * @brief   CAND18 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_3_M_CAN_2) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_3_M_CAN_2        FALSE
#endif
/**
 * @brief   CAND19 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_3_M_CAN_3) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_3_M_CAN_3        FALSE
#endif

/**
 * @brief   CAND20 Driver selection.
 */
#if !defined(SPC5_USE_CAN_SUB_3_M_CAN_4) || defined(__DOXYGEN__)
#define SPC5_USE_CAN_SUB_3_M_CAN_4        FALSE
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if (SPC5_USE_CAN_SUB_0_M_CAN_0 == TRUE) && (SPC5_HAS_CAN_SUB_0_M_CAN_0 == FALSE)
#error "CAN1 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_1 == TRUE) && (SPC5_HAS_CAN_SUB_0_M_CAN_1 == FALSE)
#error "CAN2 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_2 == TRUE) && (SPC5_HAS_CAN_SUB_0_M_CAN_2 == FALSE)
#error "CAN3 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_3 == TRUE) && (SPC5_HAS_CAN_SUB_0_M_CAN_3 == FALSE)
#error "CAN4 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_4 == TRUE) && (SPC5_HAS_CAN_SUB_0_M_CAN_4 == FALSE)
#error "CAN5 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_0 == TRUE) && (SPC5_HAS_CAN_SUB_1_M_CAN_0 == FALSE)
#error "CAN6 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_1 == TRUE) && (SPC5_HAS_CAN_SUB_1_M_CAN_1 == FALSE)
#error "CAN7 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_2 == TRUE) && (SPC5_HAS_CAN_SUB_1_M_CAN_2 == FALSE)
#error "CAN8 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_3 == TRUE) && (SPC5_HAS_CAN_SUB_1_M_CAN_3 == FALSE)
#error "CAN9 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_4 == TRUE) && (SPC5_HAS_CAN_SUB_1_M_CAN_4 == FALSE)
#error "CAN10 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_0 == TRUE) && (SPC5_HAS_CAN_SUB_2_M_CAN_0 == FALSE)
#error "CAN11 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_1 == TRUE) && (SPC5_HAS_CAN_SUB_2_M_CAN_1 == FALSE)
#error "CAN12 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_2 == TRUE) && (SPC5_HAS_CAN_SUB_2_M_CAN_2 == FALSE)
#error "CAN13 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_3 == TRUE) && (SPC5_HAS_CAN_SUB_2_M_CAN_3 == FALSE)
#error "CAN14 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_4 == TRUE) && (SPC5_HAS_CAN_SUB_2_M_CAN_4 == FALSE)
#error "CAN15 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_0 == TRUE) && (SPC5_HAS_CAN_SUB_3_M_CAN_0 == FALSE)
#error "CAN16 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_1 == TRUE) && (SPC5_HAS_CAN_SUB_3_M_CAN_1 == FALSE)
#error "CAN17 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_2 == TRUE) && (SPC5_HAS_CAN_SUB_3_M_CAN_2 == FALSE)
#error "CAN18 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_3 == TRUE) && (SPC5_HAS_CAN_SUB_3_M_CAN_3 == FALSE)
#error "CAN19 not present in the selected device"
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_4 == TRUE) && (SPC5_HAS_CAN_SUB_3_M_CAN_4 == FALSE)
#error "CAN20 not present in the selected device"
#endif

#if    (SPC5_USE_CAN_SUB_0_M_CAN_0 == FALSE) && (SPC5_USE_CAN_SUB_0_M_CAN_1 == FALSE)                    \
    && (SPC5_USE_CAN_SUB_0_M_CAN_2 == FALSE) && (SPC5_USE_CAN_SUB_0_M_CAN_3 == FALSE)                    \
    && (SPC5_USE_CAN_SUB_0_M_CAN_4 == FALSE) && (SPC5_USE_CAN_SUB_1_M_CAN_0 == FALSE)                    \
    && (SPC5_USE_CAN_SUB_1_M_CAN_1 == FALSE) && (SPC5_USE_CAN_SUB_1_M_CAN_2 == FALSE)                    \
    && (SPC5_USE_CAN_SUB_1_M_CAN_3 == FALSE) && (SPC5_USE_CAN_SUB_1_M_CAN_4 == FALSE)                    \
    && (SPC5_USE_CAN_SUB_2_M_CAN_0 == FALSE) && (SPC5_USE_CAN_SUB_2_M_CAN_1 == FALSE)                    \
    && (SPC5_USE_CAN_SUB_2_M_CAN_2 == FALSE) && (SPC5_USE_CAN_SUB_2_M_CAN_3 == FALSE)                    \
    && (SPC5_USE_CAN_SUB_2_M_CAN_4 == FALSE) && (SPC5_USE_CAN_SUB_3_M_CAN_0 == FALSE)                    \
    && (SPC5_USE_CAN_SUB_3_M_CAN_1 == FALSE) && (SPC5_USE_CAN_SUB_3_M_CAN_2 == FALSE)                    \
    && (SPC5_USE_CAN_SUB_3_M_CAN_3 == FALSE) && (SPC5_USE_CAN_SUB_3_M_CAN_4 == FALSE)
    #error "CAN driver activated but no CAN peripheral assigned"
#endif

/**
 * @brief   Start address bit position in CAN register. default is 2. for some devices is defined in the platform.h
 */
#if !defined(CAN_SA_BIT_POSITION) || defined(__DOXYGEN__)
#define CAN_SA_BIT_POSITION        2U
#endif

/**
 * @brief   Second digit of MCAN IP version. default is MCAN ver 3.2 
 */
#if !defined(MCAN_IP_SUB) || defined(__DOXYGEN__)
#define MCAN_IP_SUB              2U
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/
 /* PPC register definitions not compatible with MISRA rules on bit-fields 
   (Rules 6.1). this is necessary to ensure compatibility when porting code 
    from spc56 to spc57/58 (FLEXCAN to MCAN driver)   */
/*lint -e46 */

/**
 * @brief   Type of a structure representing a CAN driver.
 */
typedef struct CANDriver CANDriver;

/**
 * @brief   CAN transmission frame.
 *
 */
typedef struct {
  uint8_t  OPERATION;                                 /**< @brief operation type(NORMAL or CANFD) */
  uint8_t  RTR;                                       /**< @brief Frame type.         */
  union { 
    uint8_t TYPE;                                     /**< @brief Id type. STD or XTD */
    uint8_t IDE;                                      /**< @brief Id type. STD or XTD */  
  };
  union { 
    uint32_t SID;                                     /**< @brief Standard identifier.*/ 
    uint32_t EID;                                     /**< @brief Extended identifier.*/
    uint32_t ID;	                                  /**< @brief identifier.*/
  }; 
  union{  
    uint8_t  DLC;                                     /**< @brief Data Length C     */
	uint8_t  LENGTH;                                  /**< @brief Data length.      */
  };
  union {
    uint8_t  data8[SPC5_CAN_MAX_DATA_LENGHT];         /**< @brief Frame data.        */
    uint16_t data16[SPC5_CAN_MAX_DATA_LENGHT/2U];     /**< @brief Frame data.        */
    uint32_t data32[SPC5_CAN_MAX_DATA_LENGHT/4U];     /**< @brief Frame data.        */
  };
} CANTxFrame;

/**
 * @brief   CAN receive frame.
 *
 */
typedef struct {
  uint16_t TIME;                                      /**< @brief Time stamp.         */
  uint8_t  OPERATION;                                 /**< @brief operation type(NORMAL or CANFD) */
  uint8_t  RTR;                                       /**< @brief Frame type.         */
  union { 
    uint8_t TYPE;                                     /**< @brief Id type. STD or XTD */
    uint8_t IDE;                                      /**< @brief Id type. STD or XTD */  
  };
  union { 
    uint32_t SID;                                     /**< @brief Standard identifier.*/ 
    uint32_t EID;                                     /**< @brief Extended identifier.*/
    uint32_t ID;	                                  /**< @brief identifier.*/
  }; 
  union{  
    uint8_t  DLC;                                     /**< @brief Data Length       */
	uint8_t  LENGTH;                                  /**< @brief Data length.      */
  };
  union {
    uint8_t  data8[SPC5_CAN_MAX_DATA_LENGHT];         /**< @brief Frame data.        */
    uint16_t data16[SPC5_CAN_MAX_DATA_LENGHT/2U];     /**< @brief Frame data.        */
    uint32_t data32[SPC5_CAN_MAX_DATA_LENGHT/4U];     /**< @brief Frame data.        */
  };
} CANRxFrame;
/*lint +e46 */

/**
 * @brief   MCAN notification callback type for RX operation.
 *
 * @param[in] msgbuf      Message buffer (DEDICATED or FIFO0 or FIFO1) containing can frame received
 * @param[in] crfp        CAN frame received
 */
typedef void (*mcanrxcallback_t)(uint32_t msgbuf, CANRxFrame crfp);

/**
 * @brief   MCAN notification callback type for Events
 *
 */
typedef void (*mcaneventcallback_t)(void);

/**
 * @brief   MCAN Error callback type.
 *
 * @param[in] canp      pointer to the @p CAN Driver object triggering the error
 * @param[in] psr       Protocol Status Register logging  the error
 */
typedef void (*mcanerrorcallback_t)(CANDriver *canp, uint32_t psr);


/**
 * @brief   CAN standard  buffer filter.
 * @note    Refer to the SPC5 reference manual for info about filters.
 */
typedef struct {
  /**
   * @brief   Filter value 1
   */
  uint32_t SFID1;

  /**
   * @brief   Filter value 2.
   */
  uint32_t SFID2;

  /**
   * @brief   Standard Filter Type
   */
  uint8_t SFT;

  /**
   * @brief   Standard Filter Type
   */
  uint8_t SFEC;
} Standard_Filter;

/**
 * @brief   CAN Extended buffer filter.
 * @note    Refer to the SPC5 reference manual for info about filters.
 */
typedef struct {
  /**
   * @brief   Filter value 1
   */
  uint32_t EFID1;

  /**
   * @brief   Filter value 2.
   */
  uint32_t EFID2;

  /**
   * @brief   Standard Filter Type
   */
  uint8_t EFT;

  /**
   * @brief   Standard Filter Type
   */
  uint8_t EFEC;
} Extended_Filter;

/**
 * @brief   Driver configuration structure.
 */
typedef struct {
  /**
    * @brief   CAN LoopBack configuration
    * @note    activate internal, external loopback for test mode
    */
  uint8_t loopback;
  /**
    * @brief   CAN Endianness
    * @note    CAN endian format. For default, MCAN uses little endian format.
    */
  uint8_t endianness;
  /**
   * @brief   CAN Clock Configurations (NBTP register).
   * @note    Some bits in this register are enforced by the driver regardless
   *          their status in this field.
   */
  /* sync jump width */
  uint8_t nsjw;
  /* time segment before sample point */
  uint8_t ntseg1;
  /* time segment after sample point */
  uint8_t ntseg2;
  /* clock prescaler */
  uint16_t pres;

    /**
   * @brief   CANFD Configurations (NBTP register).
   * @note    if canfd_enabled is FALSE all other fields are don't care
   */
  /* CANFD operation enabled */
  uint8_t canfd_enabled;
  /* canfd bit rate switch */
  uint8_t canfd_brs;
  /* canfd sync jump width */
  uint8_t dsjw;
  /* canfd time segment before sample point */
  uint8_t dtseg1;
  /* canfd time segment after sample point */
  uint8_t dtseg2;
  /* canfd clock prescaler*/
  uint8_t canfd_pres;
  /* Transceiver delay compensation enabled */
  uint8_t tcd_enabled;
  /* Transmitter delay compensation value */
  uint8_t tcd_value;
  /* Transmitter delay compensation offset */
  uint8_t tcd_offset;
  /* Transmitter delay compensation filter window length */
  uint8_t tcd_filter_window_length;
 
 /**
   * @brief   CAN interrupts and callback configuration.
   */
  /*can rx interrupt line*/
  uint8_t can_rx_int_line;

  /*can rx interrupt call back */
  mcanrxcallback_t rx_callback;
  
  /*FIFO 0 interrupt line*/
  uint8_t can_fifo0_int_line;
  
  /*FIFO 0 new message interrupt*/
  uint8_t can_fifo0_new_message_interrupt;
  
  /*FIFO 0 new message interrupt call back */
  mcanrxcallback_t fifo0_new_message_callback;

  /*FIFO 0 watermark interrupt*/
  uint8_t can_fifo0_watermark_interrupt;
  
  /*FIFO 0 watermark interrupt call back */
  mcaneventcallback_t fifo0_watermark_callback;

   /*FIFO 0 full interrupt*/
  uint8_t can_fifo0_full_interrupt;
  
  /*FIFO 0 full interrupt call back */
  mcaneventcallback_t fifo0_full_callback;

  /*FIFO 0 lost interrupt*/
  uint8_t can_fifo0_lost_interrupt;
  
  /*FIFO 0 lost interrupt call back */
  mcaneventcallback_t fifo0_lost_callback;
 
 /*FIFO 1 interrupt line*/
  uint8_t can_fifo1_int_line;
  
  /*FIFO 1 new message interrupt*/
  uint8_t can_fifo1_new_message_interrupt;
  
  /*FIFO 1 new message interrupt call back */
  mcanrxcallback_t fifo1_new_message_callback;

  /*FIFO 1 watermark interrupt*/
  uint8_t can_fifo1_watermark_interrupt;
  
  /*FIFO 1 watermark interrupt call back */
  mcaneventcallback_t fifo1_watermark_callback;

   /*FIFO 1 full interrupt*/
  uint8_t can_fifo1_full_interrupt;
  
  /*FIFO 1 full interrupt call back */
  mcaneventcallback_t fifo1_full_callback;

  /*FIFO 1 lost interrupt*/
  uint8_t can_fifo1_lost_interrupt;
  
  /*FIFO 1 lost interrupt call back */
  mcaneventcallback_t fifo1_lost_callback;
 
 /**
   * @brief   CAN filters structure.
   */
  Standard_Filter STD_Filter[SPC5_CAN_SUB_MAX_STD_FILTERS];
  Extended_Filter XTD_Filter[SPC5_CAN_SUB_MAX_XTD_FILTERS];
  uint8_t numof_std_filters;
  uint8_t numof_xtd_filters;
  uint8_t num_of_rx_buffers;
  uint8_t num_of_fifo0_buffers;
  uint8_t num_of_fifo1_buffers;
  uint8_t tx_mode;
  uint8_t num_of_tx_buffers;
  uint8_t num_of_fifo_queue_buffers;

  /* Error Callback */
  mcanerrorcallback_t err_callback;
} CANConfig;

/**
 * @brief   Structure representing an CAN driver.
 */
struct CANDriver {
  /**
   * @brief   Current configuration data.
   */
  CANConfig 				*config;
  /**
   * @brief   Pointer to the CAN registers.
   */
  volatile struct spc5_mcan *mcan;
  /**
   * @brief   Shared RAM information.
   */
  uint32_t shared_ram_start_address;
  /**
   * @brief   Max data size for RX,FIFO and TX buffer
   */
  uint8_t max_data_size;

};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @name    CAN endianness inversion
 * @{
 */
/**
 * @brief   Invert the data endianness.
 *
 * @param[in] data      data to be inverted
 * @return              data with inverted endianness.
 *
 * @api
 */
#define CAN_ENDIANESS_INVERSION(data)     ((((uint32_t)(data) >> 24) & 0x000000FFUL) | (((uint32_t)(data) >> 8) & 0x0000FF00UL) | \
                                           (((uint32_t)(data) << 8) & 0x00FF0000UL) | (((uint32_t)(data) << 24) & 0xFF000000UL))
/** @} */

/*===========================================================================*/
/* IRQ Handlers                                                              */
/*===========================================================================*/

#if (SPC5_USE_CAN_SUB_0_M_CAN_0 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_0_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_0_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_0_M_CAN_1 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_1_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_1_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_0_M_CAN_2 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_2_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_2_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_0_M_CAN_3 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_3_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_3_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_0_M_CAN_4 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_4_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_4_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_1_M_CAN_0 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_0_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_0_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_1_M_CAN_1 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_1_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_1_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_1_M_CAN_2 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_2_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_2_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_1_M_CAN_3 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_3_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_3_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_1_M_CAN_4 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_4_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_4_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_2_M_CAN_0 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_0_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_0_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_2_M_CAN_1 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_1_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_1_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_2_M_CAN_2 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_2_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_2_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_2_M_CAN_3 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_3_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_3_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_2_M_CAN_4 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_4_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_4_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_3_M_CAN_0 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_0_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_0_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_3_M_CAN_1 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_1_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_1_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_3_M_CAN_2 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_2_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_2_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_3_M_CAN_3 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_3_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_3_L1_HANDLER);
#endif
#if (SPC5_USE_CAN_SUB_3_M_CAN_4 == TRUE) && !defined(__DOXYGEN__)
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_4_L0_HANDLER);
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_4_L1_HANDLER);
#endif

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if (SPC5_USE_CAN_SUB_0_M_CAN_0 == TRUE) && !defined(__DOXYGEN__)
extern CANDriver CAND1;
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_1 == TRUE) && !defined(__DOXYGEN__)
extern CANDriver CAND2;
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_2 == TRUE) && !defined(__DOXYGEN__)
extern CANDriver CAND3;
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_3 == TRUE) && !defined(__DOXYGEN__)
extern CANDriver CAND4;
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_1 == TRUE) && !defined(__DOXYGEN__)
extern CANDriver CAND7;
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_2 == TRUE) && !defined(__DOXYGEN__)
extern CANDriver CAND8;
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_3 == TRUE) && !defined(__DOXYGEN__)
extern CANDriver CAND9;
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_4 == TRUE) && !defined(__DOXYGEN__)
extern CANDriver CAND10;
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_1 == TRUE) && !defined(__DOXYGEN__)
extern CANDriver CAND12;
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_2 == TRUE) && !defined(__DOXYGEN__)
extern CANDriver CAND13;
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_3 == TRUE) && !defined(__DOXYGEN__)
extern CANDriver CAND14;
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_4 == TRUE) && !defined(__DOXYGEN__)
extern CANDriver CAND15;
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_1 == TRUE) && !defined(__DOXYGEN__)
extern CANDriver CAND17;
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_2 == TRUE) && !defined(__DOXYGEN__)
extern CANDriver CAND18;
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_3 == TRUE) && !defined(__DOXYGEN__)
extern CANDriver CAND19;
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_4 == TRUE) && !defined(__DOXYGEN__)
extern CANDriver CAND20;
#endif

#ifdef __cplusplus
extern "C" {
#endif
void can_lld_init(void);
void can_lld_start(CANDriver *canp, CANConfig *config);
void can_lld_stop(CANDriver *canp);
uint32_t can_lld_transmit(CANDriver *canp, uint32_t msgbuf, CANTxFrame *ctfp);
uint32_t can_lld_receive(CANDriver *canp, uint32_t msgbuf, CANRxFrame *crfp);
#if (CAN_DEBUG_RX_COUNTER == TRUE)
uint32_t can_lld_debug_getrxcounter(void);
#endif
#if (CAN_DEBUG_TX_COUNTER == TRUE)
uint32_t can_lld_debug_gettxcounter(void);
#endif
#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_CAN */

#endif /* _CAN_LLD_H_ */

/** @} */

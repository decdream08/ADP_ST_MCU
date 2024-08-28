/****************************************************************************
*
* Copyright © 2015-2022 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/

/**
 * @file    can_lld.c
 * @brief   SPC5xx CAN low level driver code.
 *
 * @addtogroup CAN
 * @{
 */

#include "can_lld.h"

#if (LLD_USE_CAN == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/
void can_lld_readBuffer(CANDriver *canp, uint8_t buffertype, uint32_t msgbuf, CANRxFrame *crfp);
void can_lld_writeTxBuffer(CANDriver *canp, uint32_t msgbuf, CANTxFrame *ctfp);
uint8_t can_lld_getframesize(uint8_t dlc_field);
uint8_t can_lld_getDLC(uint8_t frame_size);

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

#if (SPC5_USE_CAN_SUB_0_M_CAN_0 == TRUE) && !defined(__DOXYGEN__)
CANDriver CAND1;
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_1 == TRUE) && !defined(__DOXYGEN__)
CANDriver CAND2;
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_2 == TRUE) && !defined(__DOXYGEN__)
CANDriver CAND3;
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_3 == TRUE) && !defined(__DOXYGEN__)
CANDriver CAND4;
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_1 == TRUE) && !defined(__DOXYGEN__)
CANDriver CAND7;
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_2 == TRUE) && !defined(__DOXYGEN__)
CANDriver CAND8;
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_3 == TRUE) && !defined(__DOXYGEN__)
CANDriver CAND9;
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_4 == TRUE) && !defined(__DOXYGEN__)
CANDriver CAND10;
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_1 == TRUE) && !defined(__DOXYGEN__)
CANDriver CAND12;
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_2 == TRUE) && !defined(__DOXYGEN__)
CANDriver CAND13;
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_3 == TRUE) && !defined(__DOXYGEN__)
CANDriver CAND14;
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_4 == TRUE) && !defined(__DOXYGEN__)
CANDriver CAND15;
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_1 == TRUE) && !defined(__DOXYGEN__)
CANDriver CAND17;
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_2 == TRUE) && !defined(__DOXYGEN__)
CANDriver CAND18;
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_3 == TRUE) && !defined(__DOXYGEN__)
CANDriver CAND19;
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_4 == TRUE) && !defined(__DOXYGEN__)
CANDriver CAND20;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/
#if (CAN_DEBUG_RX_COUNTER == TRUE)
static uint32_t can_rx_counter;
#endif
#if (CAN_DEBUG_TX_COUNTER == TRUE)
static uint32_t can_tx_counter;
#endif

/**
 * @name    CAN IR write 1 to clear flags
 * @{
 */
#define CAN_IR_RF0N         (1UL << 0)
#define CAN_IR_RF0W         (1UL << 1)
#define CAN_IR_RF0F         (1UL << 2)
#define CAN_IR_RF0L         (1UL << 3)
#define CAN_IR_RF1N         (1UL << 4)
#define CAN_IR_RF1W         (1UL << 5)
#define CAN_IR_RF1F         (1UL << 6)
#define CAN_IR_RF1L         (1UL << 7)
#define CAN_IR_HPM          (1UL << 8)
#define CAN_IR_TC           (1UL << 9)
#define CAN_IR_TCF          (1UL << 10)
#define CAN_IR_TFE          (1UL << 11)
#define CAN_IR_TEFN         (1UL << 12)
#define CAN_IR_TEFW         (1UL << 13)
#define CAN_IR_TEFF         (1UL << 14)
#define CAN_IR_TEFL         (1UL << 15)
#define CAN_IR_TSW          (1UL << 16)
#define CAN_IR_MRAF         (1UL << 17)
#define CAN_IR_TOO          (1UL << 18)
#define CAN_IR_DRX          (1UL << 19)
#define CAN_IR_BEC          (1UL << 20)
#define CAN_IR_BEU          (1UL << 21)
#define CAN_IR_ELO          (1UL << 22)
#define CAN_IR_EP           (1UL << 23)
#define CAN_IR_EW           (1UL << 24)
#define CAN_IR_BO           (1UL << 25)
#define CAN_IR_WDI          (1UL << 26)
#define CAN_IR_CRCE         (1UL << 27)
#define CAN_IR_BE           (1UL << 28)
#define CAN_IR_ACKE         (1UL << 29)
#define CAN_IR_FOE          (1UL << 30)
#define CAN_IR_STE          (1UL << 31)
 /** @} */

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/
/**
 * @brief   Read data from RX Buffer
 *
 * @param[in] canp          pointer to the @p CANDriver object
 * @param[in] buffertype    buffer to read could be CAN_DEDICATED_RXBUFFER,CAN_FIFO0_RXBUFFER,CAN_FIFO1_RXBUFFER
 * @param[in] msgbuf        Rx buffer or FIFO message to be read
 * @param[out] crfp         Pointer to CANrxFrame
 * @notapi
 */
void can_lld_readBuffer(CANDriver *canp, uint8_t buffertype, uint32_t msgbuf, CANRxFrame *crfp) {
  uint32_t address_pointer = 0;
  uint32_t reg_value;
  uint8_t frame_size;
  uint8_t counter;
  uint8_t numofcycles;

  /* set address in shared RAM to read from depending on rx buffertype */
  switch (buffertype) {
  case CAN_DEDICATED_RXBUFFER:
    address_pointer = canp->shared_ram_start_address + ((uint32_t)(canp->mcan->RXBC.B.RBSA) << CAN_SA_BIT_POSITION)
        + ((8UL + canp->max_data_size) * msgbuf);
    break;
  case CAN_FIFO0_RXBUFFER:
    address_pointer = canp->shared_ram_start_address + ((uint32_t)(canp->mcan->RXF0C.B.F0SA) << CAN_SA_BIT_POSITION)
        + ((8UL + canp->max_data_size) * msgbuf);
    break;
  case CAN_FIFO1_RXBUFFER:
    address_pointer = canp->shared_ram_start_address + ((uint32_t)(canp->mcan->RXF1C.B.F1SA) << CAN_SA_BIT_POSITION)
        + ((8UL + canp->max_data_size) * msgbuf);
    break;
  default:
    /* comment here for MISRA Compliance */
    break;
  }

  /* read message */
  if ((*((vuint32_t*)(address_pointer)) >> 30U) == CAN_ID_XTD) {
    crfp->TYPE = CAN_ID_XTD;
    crfp->ID = (*((vuint32_t*)(address_pointer)) & 0x1FFFFFFFUL);
  }
  else {
    crfp->TYPE = CAN_ID_STD;
    crfp->ID = (*((vuint32_t*)(address_pointer)) >> 18U);
  }

  /* Data Lenght Code */
  address_pointer = address_pointer + 4UL;
  reg_value = *(vuint32_t*)(address_pointer);
  frame_size = can_lld_getframesize((uint8_t)((reg_value >> 16) & 0x0FU));
  crfp->DLC = frame_size;

  /* check CANFD frame */
  crfp->OPERATION = (uint8_t)((reg_value >> 21) & 0x01U);

  /* Time Stamp */
  crfp->TIME = (uint16_t)(reg_value & 0x000000FFUL);

  /* Data */
  address_pointer = address_pointer + 4UL;
  if ((frame_size % 4U) == 0U) {
    numofcycles = (frame_size / 4U);
  }
  else {
    numofcycles = (frame_size / 4U) + 1U;
  }
  for (counter = 0; counter < numofcycles; counter++) {
    reg_value = *(vuint32_t*)(address_pointer);
    /* If Big Endian is selected, data is inverted.*/
    if (canp->config->endianness == CAN_LITTLE_ENDIAN) {
      crfp->data32[counter] = reg_value;
    } else {
      crfp->data32[counter] = CAN_ENDIANESS_INVERSION(reg_value);
    }
    address_pointer = address_pointer + 4UL;
  }

#if (CAN_DEBUG_RX_COUNTER == TRUE)
  can_rx_counter++;
#endif
}

/**
 * @brief   Write data to RX Buffer
 *
 * @param[in] canp      pointer to the @p CANDriver object
 * @param[in] msgbuf    tx buffer message to write
 * @param[in] ctfp     Pointer to CANTxFrame to be write
 * @notapi
 */
void can_lld_writeTxBuffer(CANDriver *canp, uint32_t msgbuf, CANTxFrame *ctfp) {
  uint32_t address_pointer;
  uint32_t msgbuf_pointer;
  uint32_t reg_value;
  uint8_t dlc_value;
  uint8_t counter;
  uint8_t numofcycles;

  /* set the pointer to tx buffer address in shared ram */
  if (canp->max_data_size == 64U) {
    msgbuf_pointer = (8U + 64U) * (uint32_t)msgbuf;
  }
  else {
    msgbuf_pointer = (8U + 8U) * (uint32_t)msgbuf;
  }
  address_pointer = canp->shared_ram_start_address + ((uint32_t)(canp->mcan->TXBC.B.TBSA) << CAN_SA_BIT_POSITION) + msgbuf_pointer;

  /* Prepare message */
  if (ctfp->TYPE == CAN_ID_XTD) {
    *(vuint32_t*)(address_pointer) = (ctfp->ID | 0x40000000U);
  }
  else {
    *(vuint32_t*)(address_pointer) = (ctfp->ID << 18);
  }
  /* Data Length */
  address_pointer = address_pointer + 4UL;
  dlc_value = can_lld_getDLC(ctfp->DLC);
  reg_value = ((uint32_t)dlc_value << 16);
  *(vuint32_t*)(address_pointer) = reg_value;

  /* CANFD bit settings */
  if (ctfp->OPERATION == CAN_OP_CANFD) {
    *(vuint32_t*)(address_pointer) |= 0x00200000UL;
    if (canp->config->canfd_brs == TRUE) {
      *(vuint32_t*)(address_pointer) |= 0x00100000UL;
    }
  }

  /* Data */
  address_pointer = address_pointer + 4UL;
  if ((ctfp->DLC % 4U) == 0U) {
    numofcycles = (ctfp->DLC / 4U);
  }
  else {
    numofcycles = (ctfp->DLC / 4U) + 1U;
  }
  for (counter = 0; counter < numofcycles; counter++) {
    reg_value = ctfp->data32[counter];
    /* If Big Endian is selected, data is inverted.*/
    if (canp->config->endianness == CAN_LITTLE_ENDIAN) {
      *(vuint32_t*)(address_pointer) = reg_value;
    } else {
      *(vuint32_t*)(address_pointer) = CAN_ENDIANESS_INVERSION(reg_value);
    }
    address_pointer = address_pointer + 4UL;
  }
#if (CAN_DEBUG_TX_COUNTER == TRUE)
  can_tx_counter++;
#endif
}

/**
 * @brief   Convert DLC field value to number of bytes received
 *
 * @param[in] dlc_field     the value of DLC filed
 *
 * @return  size in byte of frame
 * @notapi
 */
uint8_t can_lld_getframesize(uint8_t dlc_field) {
  switch (dlc_field) {
  case 9U:
    return 12U;
  case 10U:
    return 16U;
  case 11:
    return 20U;
  case 12:
    return 24U;
  case 13:
    return 32U;
  case 14:
    return 48U;
  case 15:
    return 64U;
  default:
    return dlc_field;
  }
}

/**
 * @brief   Convert frame size to DLC field
 *
 * @param[in] frame_size    the frame size
 *
 * @return  DLC field value
 * @notapi
 */
uint8_t can_lld_getDLC(uint8_t frame_size) {
  if (frame_size <= 8U) {
    return frame_size;
  }
  else if (frame_size == 12U) {
    return 9U;
  }
  else if (frame_size == 16U) {
    return 10U;
  }
  else if (frame_size == 20U) {
    return 11U;
  }
  else if (frame_size == 24U) {
    return 12U;
  }
  else if (frame_size == 32U) {
    return 13U;
  }
  else if (frame_size == 48U) {
    return 14U;
  }
  else if (frame_size == 64U) {
    return 15U;
  }
  else {
    return 0U;
  }
}

/**
 * @brief   Common ISR handler for interrupt line 0.
 *
 * @param[in] canp      pointer to the @p CANDriver object
 *
 * @notapi
 */
/*lint -save -e* */
static void can_lld_l0_handler(CANDriver *canp) {
  /*lint restore */
  CANRxFrame crfp;
  uint32_t msgbuf = 0;

  /* check if Rx buffer interrupt occurred on line 0 */
  if ((canp->mcan->IR.R & CAN_IR_DRX) != 0U) {
    if ((canp->mcan->ILS.R & CAN_IR_DRX) == 0U) {
      /* callback if configured is called */
      if (canp->config->rx_callback != NULL) {
        for (msgbuf = 0; msgbuf < canp->config->num_of_rx_buffers; msgbuf++) {
          if (msgbuf < 32) {
              if (((canp->mcan->NDAT1.R) & (1UL << msgbuf)) != 0U) {
                break;
              }
          } else {
              if (((canp->mcan->NDAT2.R) & (1UL << (msgbuf-32))) != 0U) {
                break;
              }
          }
        }
        /* read message */
        can_lld_readBuffer(canp, CAN_DEDICATED_RXBUFFER, msgbuf, &crfp);
        /* callback */
        canp->config->rx_callback(msgbuf, crfp);
        /* release rx buffer */
        if (msgbuf < 32) {
            canp->mcan->NDAT1.R = (1UL << msgbuf);
        } else {
            canp->mcan->NDAT2.R = (1UL << (msgbuf-32));
        }
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_DRX;
    }
  }

  /* check if FIFO0 lost interrupt occurred on line 0 */
  if (((canp->mcan->IR.R & CAN_IR_RF0L) != 0U) && 
       (canp->config->can_fifo0_lost_interrupt == CAN_INTERRUPT_ENABLED)) {
    if ((canp->mcan->ILS.R & CAN_IR_RF0L) == 0U) {
      /* callback if configured is called */
      if (canp->config->fifo0_lost_callback != NULL) {
        /* callback */
        canp->config->fifo0_lost_callback();
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_RF0L;
    }
  }

  /* check if FIFO0 full interrupt occurred on line 0 */
  if (((canp->mcan->IR.R & CAN_IR_RF0F) != 0U) &&
       (canp->config->can_fifo0_full_interrupt == CAN_INTERRUPT_ENABLED)) {
    if ((canp->mcan->ILS.R & CAN_IR_RF0F) == 0U) {
      /* callback if configured is called */
      if (canp->config->fifo0_full_callback != NULL) {
        /* callback */
        canp->config->fifo0_full_callback();
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_RF0F;
    }
  }

  /* check if FIFO0 watermark interrupt occurred on line 0 */
  if (((canp->mcan->IR.R & CAN_IR_RF0W) != 0U) &&
       (canp->config->can_fifo0_watermark_interrupt != CAN_INTERRUPT_DISABLED)) {
    if ((canp->mcan->ILS.R & CAN_IR_RF0W) == 0U) {
      /* callback if configured is called */
      if (canp->config->fifo0_watermark_callback != NULL) {
        /* callback */
        canp->config->fifo0_watermark_callback();
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_RF0W;
    }
  }

  /* check if Rx FIFO0 interrupt occurred on line 0 */
  if (((canp->mcan->IR.R & CAN_IR_RF0N) != 0U) &&
       (canp->config->can_fifo0_new_message_interrupt == CAN_INTERRUPT_ENABLED)) {
    if ((canp->mcan->ILS.R & CAN_IR_RF0N) == 0U) {
      /* callback if configured is called */
      if (canp->config->fifo0_new_message_callback != NULL) {
        msgbuf = canp->mcan->RXF0S.B.F0GI;
        /* read message */
        can_lld_readBuffer(canp, CAN_FIFO0_RXBUFFER, msgbuf, &crfp);
        /* callback */
        canp->config->fifo0_new_message_callback(msgbuf, crfp);
        /* release rx buffer */
        canp->mcan->RXF0A.B.F0AI = canp->mcan->RXF0S.B.F0GI;
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_RF0N;
    }
  }

  /* check if FIFO1 lost interrupt occurred on line 0 */
  if (((canp->mcan->IR.R & CAN_IR_RF1L) != 0U) &&
       (canp->config->can_fifo1_lost_interrupt == CAN_INTERRUPT_ENABLED)) {
    if ((canp->mcan->ILS.R & CAN_IR_RF1L) == 0U) {
      /* callback if configured is called */
      if (canp->config->fifo1_lost_callback != NULL) {
        /* callback */
        canp->config->fifo1_lost_callback();
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_RF1L;
    }
  }

  /* check if FIFO1 full interrupt occurred on line 0 */
  if (((canp->mcan->IR.R & CAN_IR_RF1F) != 0U) &&
       (canp->config->can_fifo1_full_interrupt == CAN_INTERRUPT_ENABLED)) {
    if ((canp->mcan->ILS.R & CAN_IR_RF1F) == 0U) {
      /* callback if configured is called */
      if (canp->config->fifo1_full_callback != NULL) {
        /* callback */
        canp->config->fifo1_full_callback();
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_RF1F;
    }
  }

  /* check if FIFO1 watermark interrupt occurred on line 0 */
  if (((canp->mcan->IR.R & CAN_IR_RF1W) != 0U) &&
       (canp->config->can_fifo1_watermark_interrupt != CAN_INTERRUPT_DISABLED)) {
    if ((canp->mcan->ILS.R & CAN_IR_RF1W) == 0U) {
      /* callback if configured is called */
      if (canp->config->fifo1_watermark_callback != NULL) {
        /* callback */
        canp->config->fifo1_watermark_callback();
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_RF1W;
    }
  }

  /* check if Rx FIFO1 interrupt occurred on line 0 */
  if (((canp->mcan->IR.R & CAN_IR_RF1N) != 0U) &&
       (canp->config->can_fifo1_new_message_interrupt == CAN_INTERRUPT_ENABLED)) {
    if ((canp->mcan->ILS.R & CAN_IR_RF1N) == 0U) {
      /* callback if configured is called */
      if (canp->config->fifo1_new_message_callback != NULL) {
        msgbuf = canp->mcan->RXF1S.B.F1GI;
        /* read message */
        can_lld_readBuffer(canp, CAN_FIFO1_RXBUFFER, msgbuf, &crfp);
        /* callback */
        canp->config->fifo1_new_message_callback(msgbuf, crfp);
        /* release rx buffer */
        canp->mcan->RXF1A.B.F1AI = canp->mcan->RXF1S.B.F1GI;
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_RF1N;
    }
  }

  /* Error check */
  if ((canp->mcan->IR.R & MCAN_ERROR_MASK) != 0U) {
    uint32_t psr = (uint32_t)canp->mcan->PSR.R;
    if (canp->config->err_callback != NULL) {
      canp->config->err_callback(canp, psr);
    }
    /* BUSOFF interrupt management */
    if (canp->mcan->IR.B.BO == 1U) {
      /* Start Bus Off status exit sequence */
      canp->mcan->CCCR.B.INIT = 0;
    }
    /* reset all error bits checked */
    canp->mcan->IR.R = MCAN_ERROR_MASK;
  }
}

/**
 * @brief   Common ISR handler for interrupt line 1.
 *
 * @param[in] canp      pointer to the @p CANDriver object
 *
 * @notapi
 */
/*lint -save -e* */
static void can_lld_l1_handler(CANDriver *canp) {
  /*lint restore */
  CANRxFrame crfp;
  uint32_t msgbuf = 0;

  /* check if Rx buffer interrupt occurred */
  if ((canp->mcan->IR.R & CAN_IR_DRX) != 0U) {
    if ((canp->mcan->ILS.R & CAN_IR_DRX) != 0U) {
      /* callback if configured is called */
      if (canp->config->rx_callback != NULL) {
        for (msgbuf = 0; msgbuf < canp->config->num_of_rx_buffers; msgbuf++) {
          if (msgbuf < 32) {
              if (((canp->mcan->NDAT1.R) & (1UL << msgbuf)) != 0U) {
                break;
              }
          } else {
              if (((canp->mcan->NDAT2.R) & (1UL << (msgbuf-32))) != 0U) {
                break;
              }
          }
        }
        /* read message */
        can_lld_readBuffer(canp, CAN_DEDICATED_RXBUFFER, msgbuf, &crfp);
        /* callback */
        canp->config->rx_callback(msgbuf, crfp);
        /* release rx buffer */
        if (msgbuf < 32) {
            canp->mcan->NDAT1.R = (1UL << msgbuf);
        } else {
            canp->mcan->NDAT2.R = (1UL << (msgbuf-32));
        }
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_DRX;
    }
  }

  /* check if FIFO0 lost interrupt occurred on line 1 */
  if (((canp->mcan->IR.R & CAN_IR_RF0L) != 0U) && 
       (canp->config->can_fifo0_lost_interrupt == CAN_INTERRUPT_ENABLED)) {
    if ((canp->mcan->ILS.R & CAN_IR_RF0L) != 0U) {
      /* callback if configured is called */
      if (canp->config->fifo0_lost_callback != NULL) {
        /* callback */
        canp->config->fifo0_lost_callback();
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_RF0L;
    }
  }

  /* check if FIFO0 full interrupt occurred on line 1 */
  if (((canp->mcan->IR.R & CAN_IR_RF0F) != 0U) &&
       (canp->config->can_fifo0_full_interrupt == CAN_INTERRUPT_ENABLED)) {
    if ((canp->mcan->ILS.R & CAN_IR_RF0F) != 0U) {
      /* callback if configured is called */
      if (canp->config->fifo0_full_callback != NULL) {
        /* callback */
        canp->config->fifo0_full_callback();
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_RF0F;
    }
  }

  /* check if FIFO0 watermark interrupt occurred on line 1 */
  if (((canp->mcan->IR.R & CAN_IR_RF0W) != 0U) &&
       (canp->config->can_fifo0_watermark_interrupt != CAN_INTERRUPT_DISABLED)) {
    if ((canp->mcan->ILS.R & CAN_IR_RF0W) != 0U) {
      /* callback if configured is called */
      if (canp->config->fifo0_watermark_callback != NULL) {
        /* callback */
        canp->config->fifo0_watermark_callback();
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_RF0W;
    }
  }

  /* check if Rx FIFO0 interrupt occurred on line 1 */
  if (((canp->mcan->IR.R & CAN_IR_RF0N) != 0U) &&
       (canp->config->can_fifo0_new_message_interrupt == CAN_INTERRUPT_ENABLED)) {
    if ((canp->mcan->ILS.R & CAN_IR_RF0N) != 0U) {
      /* callback if configured is called */
      if (canp->config->fifo0_new_message_callback != NULL) {
        msgbuf = canp->mcan->RXF0S.B.F0GI;
        /* read message */
        can_lld_readBuffer(canp, CAN_FIFO0_RXBUFFER, msgbuf, &crfp);
        /* callback */
        canp->config->fifo0_new_message_callback(msgbuf, crfp);
        /* release rx buffer */
        canp->mcan->RXF0A.B.F0AI = canp->mcan->RXF0S.B.F0GI;
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_RF0N;
    }
  }
  
  /* check if FIFO1 lost interrupt occurred on line 1 */
  if (((canp->mcan->IR.R & CAN_IR_RF1L) != 0U) &&
       (canp->config->can_fifo1_lost_interrupt == CAN_INTERRUPT_ENABLED)) {
    if ((canp->mcan->ILS.R & CAN_IR_RF1L) != 0U) {
      /* callback if configured is called */
      if (canp->config->fifo1_lost_callback != NULL) {
        /* callback */
        canp->config->fifo1_lost_callback();
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_RF1L;
    }
  }

  /* check if FIFO1 full interrupt occurred on line 1 */
  if (((canp->mcan->IR.R & CAN_IR_RF1F) != 0U) &&
       (canp->config->can_fifo1_full_interrupt == CAN_INTERRUPT_ENABLED)) {
    if ((canp->mcan->ILS.R & CAN_IR_RF1F) != 0U) {
      /* callback if configured is called */
      if (canp->config->fifo1_full_callback != NULL) {
        /* callback */
        canp->config->fifo1_full_callback();
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_RF1F;
    }
  }

  /* check if FIFO1 watermark interrupt occurred on line 1 */
  if (((canp->mcan->IR.R & CAN_IR_RF1W) != 0U) &&
       (canp->config->can_fifo1_watermark_interrupt != CAN_INTERRUPT_DISABLED)) {
    if ((canp->mcan->ILS.R & CAN_IR_RF1W) != 0U) {
      /* callback if configured is called */
      if (canp->config->fifo1_watermark_callback != NULL) {
        /* callback */
        canp->config->fifo1_watermark_callback();
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_RF1W;
    }
  }

  /* check if Rx FIFO1 interrupt occurred on line 1 */
  if (((canp->mcan->IR.R & CAN_IR_RF1N) != 0U) &&
       (canp->config->can_fifo1_new_message_interrupt == CAN_INTERRUPT_ENABLED)) {
    if ((canp->mcan->ILS.R & CAN_IR_RF1N) == 0U) {
      /* callback if configured is called */
      if (canp->config->fifo1_new_message_callback != NULL) {
        msgbuf = canp->mcan->RXF1S.B.F1GI;
        /* read message */
        can_lld_readBuffer(canp, CAN_FIFO1_RXBUFFER, msgbuf, &crfp);
        /* callback */
        canp->config->fifo1_new_message_callback(msgbuf, crfp);
        /* release rx buffer */
        canp->mcan->RXF1A.B.F1AI = canp->mcan->RXF1S.B.F1GI;
      }
      /* clear flag */
      canp->mcan->IR.R = CAN_IR_RF1N;
    }
  }
}

#if (SPC5_USE_CAN_SUB_0_M_CAN_0 == TRUE)
/**
 * @brief   CAN_SUB_0_M_CAN_0 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_0_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND1);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_0_M_CAN_0 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_0_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND1);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_1 == TRUE)
/**
 * @brief   CAN_SUB_0_M_CAN_1 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_1_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND2);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_0_M_CAN_1 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_1_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND2);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_2 == TRUE)
/**
 * @brief   CAN_SUB_0_M_CAN_2 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_2_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND3);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_0_M_CAN_2 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_2_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND3);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_3 == TRUE)
/**
 * @brief   CAN_SUB_0_M_CAN_3 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_3_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND4);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_0_M_CAN_3 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_3_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND4);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_4 == TRUE)
/**
 * @brief   CAN_SUB_0_M_CAN_4 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_4_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND5);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_0_M_CAN_4 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_0_M_CAN_4_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND5);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_0 == TRUE)
/**
 * @brief   CAN_SUB_1_M_CAN_0 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_0_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND6);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_1_M_CAN_0 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_0_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND6);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_1 == TRUE)
/**
 * @brief   CAN_SUB_1_M_CAN_1 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_1_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND7);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_1_M_CAN_1 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_1_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND7);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_2 == TRUE)
/**
 * @brief   CAN_SUB_1_M_CAN_2 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_2_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND8);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_1_M_CAN_2 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_2_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND8);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_3 == TRUE)
/**
 * @brief   CAN_SUB_1_M_CAN_3 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_3_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND9);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_1_M_CAN_3 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_3_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND9);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_4 == TRUE)
/**
 * @brief   CAN_SUB_1_M_CAN_4 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_4_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND10);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_1_M_CAN_4 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_1_M_CAN_4_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND10);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_0 == TRUE)
/**
 * @brief   CAN_SUB_2_M_CAN_0 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_0_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND11);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_2_M_CAN_0 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_0_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND11);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_1 == TRUE)
/**
 * @brief   CAN_SUB_2_M_CAN_1 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_1_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND12);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_2_M_CAN_1 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_1_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND12);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_2 == TRUE)
/**
 * @brief   CAN_SUB_2_M_CAN_2 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_2_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND13);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_2_M_CAN_2 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_2_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND13);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_3 == TRUE)
/**
 * @brief   CAN_SUB_2_M_CAN_3 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_3_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND14);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_2_M_CAN_3 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_3_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND14);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_4 == TRUE)
/**
 * @brief   CAN_SUB_2_M_CAN_4 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_4_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND15);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_2_M_CAN_4 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_2_M_CAN_4_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND15);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_0 == TRUE)
/**
 * @brief   CAN_SUB_3_M_CAN_0 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_0_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND16);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_3_M_CAN_0 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_0_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND16);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_1 == TRUE)
/**
 * @brief   CAN_SUB_3_M_CAN_1 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_1_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND17);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_3_M_CAN_1 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_1_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND17);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_2 == TRUE)
/**
 * @brief   CAN_SUB_3_M_CAN_2 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_2_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND18);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_3_M_CAN_2 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_2_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND18);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_3 == TRUE)
/**
 * @brief   CAN_SUB_3_M_CAN_3 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_3_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND19);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_3_M_CAN_3 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_3_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND19);

  IRQ_EPILOGUE();
}
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_4 == TRUE)
/**
 * @brief   CAN_SUB_3_M_CAN_4 interrupt handler for Line 0.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_4_L0_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l0_handler(&CAND20);

  IRQ_EPILOGUE();
}

/**
 * @brief   CAN_SUB_3_M_CAN_4 interrupt handler for Line 1.
 *
 * @isr
 */
IRQ_HANDLER(SPC5_CAN_SUB_3_M_CAN_4_L1_HANDLER) {

  IRQ_PROLOGUE();

  can_lld_l1_handler(&CAND20);

  IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/
/**
 * @brief   Low level CAN driver initialization.
 *
 * @notapi
 */
void can_lld_init(void) {

  uint32_t i;
  uint32_t address_pointer;

#if (CAN_DEBUG_RX_COUNTER == TRUE)
  can_rx_counter = 0UL;
#endif
#if (CAN_DEBUG_TX_COUNTER == TRUE)
  can_tx_counter = 0UL;
#endif

  /* MCAN SUBSYSTEM 0 */
#if (SPC5_USE_CAN_SUB_0_M_CAN_0 == TRUE)  
  CAND1.config = NULL;
  CAND1.mcan = &SPC5_MCAN_0;
  INTC_PSR(SPC5_CAN_SUB_0_M_CAN_0_L0_NUMBER) = SPC5_CAN_SUB_0_M_CAN_0_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_0_M_CAN_0_L1_NUMBER) = SPC5_CAN_SUB_0_M_CAN_0_L1_PRIORITY;
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_1 == TRUE)  
  CAND2.config = NULL;
  CAND2.mcan = &SPC5_MCAN_1;
  INTC_PSR(SPC5_CAN_SUB_0_M_CAN_1_L0_NUMBER) = SPC5_CAN_SUB_0_M_CAN_1_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_0_M_CAN_1_L1_NUMBER) = SPC5_CAN_SUB_0_M_CAN_1_L1_PRIORITY;
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_2 == TRUE)  
  CAND3.config = NULL;
  CAND3.mcan = &SPC5_MCAN_2;
  INTC_PSR(SPC5_CAN_SUB_0_M_CAN_2_L0_NUMBER) = SPC5_CAN_SUB_0_M_CAN_2_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_0_M_CAN_2_L1_NUMBER) = SPC5_CAN_SUB_0_M_CAN_2_L1_PRIORITY;
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_3 == TRUE)  
  CAND4.config = NULL;
  CAND4.mcan = &SPC5_MCAN_3;
  INTC_PSR(SPC5_CAN_SUB_0_M_CAN_3_L0_NUMBER) = SPC5_CAN_SUB_0_M_CAN_3_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_0_M_CAN_3_L1_NUMBER) = SPC5_CAN_SUB_0_M_CAN_3_L1_PRIORITY;
#endif

#if (SPC5_USE_CAN_SUB_0_M_CAN_4 == TRUE)  
  CAND5.config = NULL;
  CAND5.mcan = &SPC5_MCAN_4;
  INTC_PSR(SPC5_CAN_SUB_0_M_CAN_4_L0_NUMBER) = SPC5_CAN_SUB_0_M_CAN_4_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_0_M_CAN_4_L1_NUMBER) = SPC5_CAN_SUB_0_M_CAN_4_L1_PRIORITY;
#endif

  /* MCAN SUBSYSTEM 1*/
#if (SPC5_USE_CAN_SUB_1_M_CAN_0 == TRUE)  
  CAND6.config = NULL;
  CAND6.mcan = &SPC5_MCAN_5;
  INTC_PSR(SPC5_CAN_SUB_1_M_CAN_0_L0_NUMBER) = SPC5_CAN_SUB_1_M_CAN_0_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_1_M_CAN_0_L1_NUMBER) = SPC5_CAN_SUB_1_M_CAN_0_L1_PRIORITY;
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_1 == TRUE)  
  CAND7.config = NULL;
  CAND7.mcan = &SPC5_MCAN_6;
  INTC_PSR(SPC5_CAN_SUB_1_M_CAN_1_L0_NUMBER) = SPC5_CAN_SUB_1_M_CAN_1_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_1_M_CAN_1_L1_NUMBER) = SPC5_CAN_SUB_1_M_CAN_1_L1_PRIORITY;
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_2 == TRUE)  
  CAND8.config = NULL;
  CAND8.mcan = &SPC5_MCAN_7;
  INTC_PSR(SPC5_CAN_SUB_1_M_CAN_2_L0_NUMBER) = SPC5_CAN_SUB_1_M_CAN_2_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_1_M_CAN_2_L1_NUMBER) = SPC5_CAN_SUB_1_M_CAN_2_L1_PRIORITY;
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_3 == TRUE)  
  CAND9.config = NULL;
  CAND9.mcan = &SPC5_MCAN_8;
  INTC_PSR(SPC5_CAN_SUB_1_M_CAN_3_L0_NUMBER) = SPC5_CAN_SUB_1_M_CAN_3_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_1_M_CAN_3_L1_NUMBER) = SPC5_CAN_SUB_1_M_CAN_3_L1_PRIORITY;
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_4 == TRUE)  
  CAND10.config = NULL;
  CAND10.mcan = &SPC5_MCAN_9;
  INTC_PSR(SPC5_CAN_SUB_1_M_CAN_4_L0_NUMBER) = SPC5_CAN_SUB_1_M_CAN_4_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_1_M_CAN_4_L1_NUMBER) = SPC5_CAN_SUB_1_M_CAN_4_L1_PRIORITY;
#endif

  /* MCAN SUBSYSTEM 2*/
#if (SPC5_USE_CAN_SUB_2_M_CAN_0 == TRUE)  
  CAND11.config = NULL;
  CAND11.mcan = &SPC5_MCAN_10;
  INTC_PSR(SPC5_CAN_SUB_2_M_CAN_0_L0_NUMBER) = SPC5_CAN_SUB_2_M_CAN_0_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_2_M_CAN_0_L1_NUMBER) = SPC5_CAN_SUB_2_M_CAN_0_L1_PRIORITY;
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_1 == TRUE)  
  CAND12.config = NULL;
  CAND12.mcan = &SPC5_MCAN_11;
  INTC_PSR(SPC5_CAN_SUB_2_M_CAN_1_L0_NUMBER) = SPC5_CAN_SUB_2_M_CAN_1_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_2_M_CAN_1_L1_NUMBER) = SPC5_CAN_SUB_2_M_CAN_1_L1_PRIORITY;
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_2 == TRUE)  
  CAND13.config = NULL;
  CAND13.mcan = &SPC5_MCAN_12;
  INTC_PSR(SPC5_CAN_SUB_2_M_CAN_2_L0_NUMBER) = SPC5_CAN_SUB_2_M_CAN_2_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_2_M_CAN_2_L1_NUMBER) = SPC5_CAN_SUB_2_M_CAN_2_L1_PRIORITY;
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_3 == TRUE)  
  CAND14.config = NULL;
  CAND14.mcan = &SPC5_MCAN_13;
  INTC_PSR(SPC5_CAN_SUB_2_M_CAN_3_L0_NUMBER) = SPC5_CAN_SUB_2_M_CAN_3_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_2_M_CAN_3_L1_NUMBER) = SPC5_CAN_SUB_2_M_CAN_3_L1_PRIORITY;
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_4 == TRUE)  
  CAND15.config = NULL;
  CAND15.mcan = &SPC5_MCAN_14;
  INTC_PSR(SPC5_CAN_SUB_2_M_CAN_4_L0_NUMBER) = SPC5_CAN_SUB_2_M_CAN_4_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_2_M_CAN_4_L1_NUMBER) = SPC5_CAN_SUB_2_M_CAN_4_L1_PRIORITY;
#endif

  /* MCAN SUBSYSTEM 3*/
#if (SPC5_USE_CAN_SUB_3_M_CAN_0 == TRUE)  
  CAND16.config = NULL;
  CAND16.mcan = &SPC5_MCAN_15;
  INTC_PSR(SPC5_CAN_SUB_3_M_CAN_0_L0_NUMBER) = SPC5_CAN_SUB_3_M_CAN_0_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_3_M_CAN_0_L1_NUMBER) = SPC5_CAN_SUB_3_M_CAN_0_L1_PRIORITY;
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_1 == TRUE)  
  CAND17.config = NULL;
  CAND17.mcan = &SPC5_MCAN_16;
  INTC_PSR(SPC5_CAN_SUB_3_M_CAN_1_L0_NUMBER) = SPC5_CAN_SUB_3_M_CAN_1_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_3_M_CAN_1_L1_NUMBER) = SPC5_CAN_SUB_3_M_CAN_1_L1_PRIORITY;
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_2 == TRUE)  
  CAND18.config = NULL;
  CAND18.mcan = &SPC5_MCAN_17;
  INTC_PSR(SPC5_CAN_SUB_3_M_CAN_2_L0_NUMBER) = SPC5_CAN_SUB_3_M_CAN_2_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_3_M_CAN_2_L1_NUMBER) = SPC5_CAN_SUB_3_M_CAN_2_L1_PRIORITY;
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_3 == TRUE)  
  CAND19.config = NULL;
  CAND19.mcan = &SPC5_MCAN_18;
  INTC_PSR(SPC5_CAN_SUB_3_M_CAN_3_L0_NUMBER) = SPC5_CAN_SUB_3_M_CAN_3_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_3_M_CAN_3_L1_NUMBER) = SPC5_CAN_SUB_3_M_CAN_3_L1_PRIORITY;
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_4 == TRUE)  
  CAND20.config = NULL;
  CAND20.mcan = &SPC5_MCAN_19;
  INTC_PSR(SPC5_CAN_SUB_3_M_CAN_4_L0_NUMBER) = SPC5_CAN_SUB_3_M_CAN_4_L0_PRIORITY;
  INTC_PSR(SPC5_CAN_SUB_3_M_CAN_4_L1_NUMBER) = SPC5_CAN_SUB_3_M_CAN_4_L1_PRIORITY;
#endif

  /* Shared RAM Subsystem 0 initialization */
#if (SPC5_HAS_CAN_SUB_0_RAM == TRUE)
#if   ((SPC5_USE_CAN_SUB_0_M_CAN_0 == TRUE)  || (SPC5_USE_CAN_SUB_0_M_CAN_1 == TRUE) \
    || (SPC5_USE_CAN_SUB_0_M_CAN_2 == TRUE)  || (SPC5_USE_CAN_SUB_0_M_CAN_3 == TRUE) \
    || (SPC5_USE_CAN_SUB_0_M_CAN_4 == TRUE))
  /* Shared RAM 0 initialization */
  SPC5_CAN_SUB_0_RAM_ENABLE_CLOCK();
  for (i = 0; i < CAN_SUB_0_RAM_SIZE; i += 4UL) {
    address_pointer = CAN_SUB_0_RAM + i;
    *(vuint32_t*)(address_pointer) = 0x00000000UL;
  }
#endif
#endif

  /* Shared RAM Subsystem 1 initialization */
#if (SPC5_HAS_CAN_SUB_1_RAM == TRUE)
#if   ((SPC5_USE_CAN_SUB_1_M_CAN_0 == TRUE)  || (SPC5_USE_CAN_SUB_1_M_CAN_1 == TRUE) \
    || (SPC5_USE_CAN_SUB_1_M_CAN_2 == TRUE)  || (SPC5_USE_CAN_SUB_1_M_CAN_3 == TRUE) \
    || (SPC5_USE_CAN_SUB_1_M_CAN_4 == TRUE))
  /* Shared RAM 1 initialization */
  SPC5_CAN_SUB_1_RAM_ENABLE_CLOCK();
  for (i = 0; i < CAN_SUB_1_RAM_SIZE; i += 4UL) {
    address_pointer = CAN_SUB_1_RAM + i;
    *(vuint32_t*)(address_pointer) = 0x00000000UL;
  }
#endif
#endif

  /* Shared RAM Subsystem 2 initialization */
#if (SPC5_HAS_CAN_SUB_2_RAM == TRUE)
#if   ((SPC5_USE_CAN_SUB_2_M_CAN_0 == TRUE)  || (SPC5_USE_CAN_SUB_2_M_CAN_1 == TRUE) \
    || (SPC5_USE_CAN_SUB_2_M_CAN_2 == TRUE)  || (SPC5_USE_CAN_SUB_2_M_CAN_3 == TRUE) \
    || (SPC5_USE_CAN_SUB_2_M_CAN_4 == TRUE))
  /* Shared RAM 2 initialization */
  SPC5_CAN_SUB_2_RAM_ENABLE_CLOCK();
  for (i = 0; i < CAN_SUB_2_RAM_SIZE; i += 4UL) {
    address_pointer = CAN_SUB_2_RAM + i;
    *(vuint32_t*)(address_pointer) = 0x00000000UL;
  }
#endif
#endif

  /* Shared RAM Subsystem 3 initialization */
#if (SPC5_HAS_CAN_SUB_3_RAM == TRUE)
#if   ((SPC5_USE_CAN_SUB_3_M_CAN_0 == TRUE)  || (SPC5_USE_CAN_SUB_3_M_CAN_1 == TRUE) \
    || (SPC5_USE_CAN_SUB_3_M_CAN_2 == TRUE)  || (SPC5_USE_CAN_SUB_3_M_CAN_3 == TRUE) \
    || (SPC5_USE_CAN_SUB_3_M_CAN_4 == TRUE))
  /* Shared RAM 3 initialization */
  SPC5_CAN_SUB_3_RAM_ENABLE_CLOCK();
  for (i = 0; i < CAN_SUB_3_RAM_SIZE; i += 4UL) {
    address_pointer = CAN_SUB_3_RAM + i;
    *(vuint32_t*)(address_pointer) = 0x00000000UL;
  }
#endif
#endif
}

/**
 * @brief   Configures and activates the CAN peripheral.
 *
 * @param[in] canp      pointer to the @p CANDriver object
 * @param[in] config    pointer to the @p CANconfig configuration
 *
 * @notapi
 */
void can_lld_start(CANDriver *canp, CANConfig *config) {

  uint32_t count;
  uint32_t ram_address_pointer;

#if (MCAN_IP_VER == 2U)
  /* MCAN IP version 2 has a fixed tx buffer address */
  /*define a variable to store it */
  uint32_t txbuf_offset = 0UL;;
#endif
  ram_address_pointer = 0UL;

  canp->config = config;

#if (SPC5_USE_CAN_SUB_0_M_CAN_0 == TRUE)
  if (&CAND1 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_0_M_CAN_0_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_0_RAM;
	SPC5_CAN_SUB_0_M_CAN_0_ENABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_0_M_CAN_1 == TRUE)
  if (&CAND2 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_0_M_CAN_1_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_0_RAM;
	SPC5_CAN_SUB_0_M_CAN_1_ENABLE_CLOCK();
    /* Tx Buffer OffSet is fixed for MCAN IP version 2 */
#if (MCAN_IP_VER == 2U)
    txbuf_offset = 0xD00UL;
#endif
  }
#endif
#if (SPC5_USE_CAN_SUB_0_M_CAN_2 == TRUE)
  if (&CAND3 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_0_M_CAN_2_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_0_RAM;
	SPC5_CAN_SUB_0_M_CAN_2_ENABLE_CLOCK();
    /* Tx Buffer OffSet is fixed for MCAN IP version 2 */
#if (MCAN_IP_VER == 2U)
    txbuf_offset = 0x1C00UL;
#endif
  }
#endif
#if (SPC5_USE_CAN_SUB_0_M_CAN_3 == TRUE)
  if (&CAND4 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_0_M_CAN_3_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_0_RAM;
	SPC5_CAN_SUB_0_M_CAN_3_ENABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_0_M_CAN_4 == TRUE)
  if(&CAND5 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_0_M_CAN_4_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_0_RAM;
	SPC5_CAN_SUB_0_M_CAN_4_ENABLE_CLOCK();
  }
#endif

#if (SPC5_USE_CAN_SUB_1_M_CAN_0 == TRUE)
  if(&CAND6 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_1_M_CAN_0_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_1_RAM;
	SPC5_CAN_SUB_1_M_CAN_0_ENABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_1_M_CAN_1 == TRUE)
  if (&CAND7 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_1_M_CAN_1_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_1_RAM;
	SPC5_CAN_SUB_1_M_CAN_1_ENABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_1_M_CAN_2 == TRUE)
  if (&CAND8 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_1_M_CAN_2_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_1_RAM;
	SPC5_CAN_SUB_1_M_CAN_2_ENABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_1_M_CAN_3 == TRUE)
  if (&CAND9 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_1_M_CAN_3_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_1_RAM;
	SPC5_CAN_SUB_1_M_CAN_3_ENABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_1_M_CAN_4 == TRUE)
  if (&CAND10 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_1_M_CAN_4_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_1_RAM;
	SPC5_CAN_SUB_1_M_CAN_4_ENABLE_CLOCK();
  }
#endif

#if (SPC5_USE_CAN_SUB_2_M_CAN_0 == TRUE)
  if(&CAND11 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_2_M_CAN_0_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_2_RAM;
	SPC5_CAN_SUB_2_M_CAN_0_ENABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_2_M_CAN_1 == TRUE)
  if (&CAND12 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_2_M_CAN_1_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_2_RAM;
 	SPC5_CAN_SUB_2_M_CAN_1_ENABLE_CLOCK();
 }
#endif
#if (SPC5_USE_CAN_SUB_2_M_CAN_2 == TRUE)
  if (&CAND13 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_2_M_CAN_2_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_2_RAM;
	SPC5_CAN_SUB_2_M_CAN_2_ENABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_2_M_CAN_3 == TRUE)
  if (&CAND14 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_2_M_CAN_3_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_2_RAM;
	SPC5_CAN_SUB_2_M_CAN_3_ENABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_2_M_CAN_4 == TRUE)
  if (&CAND15 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_2_M_CAN_4_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_2_RAM;
	SPC5_CAN_SUB_2_M_CAN_4_ENABLE_CLOCK();
  }
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_0 == TRUE)
  if(&CAND16 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_3_M_CAN_0_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_3_RAM;
	SPC5_CAN_SUB_3_M_CAN_0_ENABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_3_M_CAN_1 == TRUE)
  if (&CAND17 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_3_M_CAN_1_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_3_RAM;
	SPC5_CAN_SUB_3_M_CAN_1_ENABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_3_M_CAN_2 == TRUE)
  if (&CAND18 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_3_M_CAN_2_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_3_RAM;
	SPC5_CAN_SUB_3_M_CAN_2_ENABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_3_M_CAN_3 == TRUE)
  if (&CAND19 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_3_M_CAN_3_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_3_RAM;
	SPC5_CAN_SUB_3_M_CAN_3_ENABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_3_M_CAN_4 == TRUE)
  if (&CAND20 == canp) {
    ram_address_pointer = SPC5_CAN_SUB_3_M_CAN_4_RAM_START;
    canp->shared_ram_start_address = CAN_SUB_3_RAM;
	SPC5_CAN_SUB_3_M_CAN_4_ENABLE_CLOCK();
  }
#endif

  /* Switch in configuration and Initialization mode */
  canp->mcan->CCCR.R = 3U;
  while (canp->mcan->CCCR.B.INIT != 1U) {
  }

  /* Enable CCCU_0 unit only in case device has a CCCU0 for SUBSYSTEM 0 */
#if (SPC5_HAS_CCCU_0 == TRUE)
  SPC5_CCCU_0_ENABLE_CLOCK();
  /* Bypass Clock Calibration on CAN unit for CCCU_0 */
  if (SPC5_CCCU_0.CCFG.R != 0x444U) {
    SPC5_CCCU_0.CCFG.R = 0x444U;
  }
  SPC5_CCCU_0_DISABLE_CLOCK();
#endif

  /* Enable CCCU_1 unit only in case device has a CCCU1 for SUBSYSTEM 1 */
#if (SPC5_HAS_CCCU_1 == TRUE)
#if ((SPC5_USE_CAN_SUB_1_M_CAN_0 == TRUE)  || (SPC5_USE_CAN_SUB_1_M_CAN_1 == TRUE) || \
     (SPC5_USE_CAN_SUB_1_M_CAN_2 == TRUE)  || (SPC5_USE_CAN_SUB_1_M_CAN_3 == TRUE) || \
     (SPC5_USE_CAN_SUB_1_M_CAN_4 == TRUE))
  SPC5_CCCU_1_ENABLE_CLOCK();
  /* * Bypass Clock Calibration on CAN unit for CCCU_1 */
  if (SPC5_CCCU_1.CCFG.R != 0x444U) {
    SPC5_CCCU_1.CCFG.R = 0x444U;
  }
  SPC5_CCCU_1_DISABLE_CLOCK();
#endif
#endif

  /* enable loop back */
  if (canp->config->loopback != CAN_NO_LOOPBACK) {
    canp->mcan->CCCR.B.TEST = 1U;
    canp->mcan->TEST.B.LBCK = 1U;
    if (canp->config->loopback == CAN_INTERNAL_LOOPBACK) {
      canp->mcan->CCCR.B.MON = 1U;
    }
  }

#if (MCAN_IP_VER == 3U && MCAN_IP_SUB == 0U)
  if (canp->config->canfd_enabled == TRUE) {
    if (canp->config->canfd_brs == TRUE) {
      canp->mcan->CCCR.B.CME = 2U;
      canp->mcan->CCCR.B.CMR = 2U;
    }
    else {
      canp->mcan->CCCR.B.CME = 1U;
      canp->mcan->CCCR.B.CME = 1U;
    }
  }
  /* Bit rate setting. DBTP register */
  canp->mcan->FBTP.B.FSJW = canp->config->dsjw;
  canp->mcan->FBTP.B.FTSEG1 = canp->config->dtseg1;
  canp->mcan->FBTP.B.FTSEG2 = canp->config->dtseg2;
  canp->mcan->FBTP.B.FBRP = canp->config->canfd_pres - 1U;
#endif
#if (MCAN_IP_VER == 3U && MCAN_IP_SUB == 2U)
  /* Bit rate setting. NBTP register */
  canp->mcan->NBTP.B.NSJW = canp->config->nsjw;
  canp->mcan->NBTP.B.NTSEG1 = canp->config->ntseg1;
  canp->mcan->NBTP.B.NTSEG2 = canp->config->ntseg2;
  canp->mcan->NBTP.B.NBRP = canp->config->pres - 1U;

  /* CANFD Settings */
  if (canp->config->canfd_enabled == TRUE) {
    canp->mcan->CCCR.B.FDOE = 1U;
    if (canp->config->canfd_brs == TRUE) {
      canp->mcan->CCCR.B.BRSE = 1U;
    }
    else {
      canp->mcan->CCCR.B.BRSE = 0U;
    }

    /* Bit rate setting. DBTP register */
    canp->mcan->DBTP.B.DSJW = canp->config->dsjw;
    canp->mcan->DBTP.B.DTSEG1 = canp->config->dtseg1;
    canp->mcan->DBTP.B.DTSEG2 = canp->config->dtseg2;
    canp->mcan->DBTP.B.DBRP = canp->config->canfd_pres - 1U;

    /* Transceiver compensation delay */
    if (canp->config->tcd_enabled == TRUE) {
      canp->mcan->DBTP.B.TDC = 1U;
      canp->mcan->PSR.B.TDCV = canp->config->tcd_value;
      canp->mcan->TDCR.B.TDCO = canp->config->tcd_offset;
      canp->mcan->TDCR.B.TDCF = canp->config->tcd_filter_window_length;
    }
    else {
      canp->mcan->DBTP.B.TDC = 0U;
      canp->mcan->PSR.B.TDCV = 0U;
      canp->mcan->TDCR.B.TDCO = 0U;
      canp->mcan->TDCR.B.TDCF = 0U;
    }

    /*set Driver, RX and TX buffer size to max 64byte*/
    canp->max_data_size = 64U;
    canp->mcan->RXESC.B.F0DS = 7U;
    canp->mcan->RXESC.B.F1DS = 7U;
    canp->mcan->RXESC.B.RBDS = 7U;
    canp->mcan->TXESC.B.TBDS = 7U;

  }
  else {
    /*set Driver, RX and TX buffer size to max 64byte*/
    canp->max_data_size = 8U;
    canp->mcan->RXESC.B.F0DS = 0U;
    canp->mcan->RXESC.B.F1DS = 0U;
    canp->mcan->RXESC.B.RBDS = 0U;
    canp->mcan->TXESC.B.TBDS = 0U;
  }
#endif
  /* Global Filter Initialization */
  canp->mcan->GFC.B.ANFS = 0x03U; /*reject messages don't match filtering */

  /* Shared RAM Initialization */
  /*standard filters*/
  canp->mcan->SIDFC.B.FLSSA = (uint16_t)(ram_address_pointer >> CAN_SA_BIT_POSITION);
  canp->mcan->SIDFC.B.LSS = canp->config->numof_std_filters;
  ram_address_pointer = ram_address_pointer + (4UL * (uint32_t)canp->config->numof_std_filters);
  /* if Start address bit position is 4 then round the pointer to multiple of 16 */
#if (CAN_SA_BIT_POSITION == 0x04U)
  ram_address_pointer = CAN_ROUND16(ram_address_pointer);
#endif

  /*extended filters*/
  canp->mcan->XIDFC.B.FLESA = (uint16_t)(ram_address_pointer >> CAN_SA_BIT_POSITION);
  canp->mcan->XIDFC.B.LSE = canp->config->numof_xtd_filters;
  ram_address_pointer = ram_address_pointer + (8UL * (uint32_t)canp->config->numof_xtd_filters);
#if (CAN_SA_BIT_POSITION == 0x04U)
  ram_address_pointer = CAN_ROUND16(ram_address_pointer);
#endif

  /*Rx FIFO0 */
  canp->mcan->RXF0C.B.F0SA = (uint16_t)(ram_address_pointer >> CAN_SA_BIT_POSITION); /* word adrress */
  canp->mcan->RXF0C.B.F0S = canp->config->num_of_fifo0_buffers;
  /* if lost interrupt is enabled overwrite is not set. Otherwise is enabled */
  if (canp->config->can_fifo0_lost_interrupt == CAN_INTERRUPT_ENABLED) {
    canp->mcan->RXF0C.B.F0OM = 0U;
  }
  else {
    canp->mcan->RXF0C.B.F0OM = 1U;
  }
  if (canp->config->can_fifo0_watermark_interrupt != CAN_INTERRUPT_DISABLED) {
    canp->mcan->RXF0C.B.F0WM = canp->config->can_fifo0_watermark_interrupt;
  }
  ram_address_pointer = ram_address_pointer + ((8UL + canp->max_data_size) * (uint32_t)canp->config->num_of_fifo0_buffers);
#if (CAN_SA_BIT_POSITION == 0x04U)
  ram_address_pointer = CAN_ROUND16(ram_address_pointer);
#endif

  /*Rx FIFO1 */
  canp->mcan->RXF1C.B.F1SA = (uint16_t)(ram_address_pointer >> CAN_SA_BIT_POSITION); /* word adrress */
  canp->mcan->RXF1C.B.F1S = canp->config->num_of_fifo1_buffers;
  /* if lost interrupt is enabled overwrite is not set. Otherwise is enabled */
  if (canp->config->can_fifo1_lost_interrupt == CAN_INTERRUPT_ENABLED) {
    canp->mcan->RXF1C.B.F1OM = 0U;
  }
  else {
    canp->mcan->RXF1C.B.F1OM = 1U;
  }
  if (canp->config->can_fifo1_watermark_interrupt != CAN_INTERRUPT_DISABLED) {
    canp->mcan->RXF1C.B.F1WM = canp->config->can_fifo1_watermark_interrupt;
  }
  ram_address_pointer = ram_address_pointer + ((8UL + canp->max_data_size) * (uint32_t)canp->config->num_of_fifo1_buffers);
#if (CAN_SA_BIT_POSITION == 0x04U)
  ram_address_pointer = CAN_ROUND16(ram_address_pointer);
#endif

  /* Rx buffers */
  canp->mcan->RXBC.B.RBSA = (uint16_t)(ram_address_pointer >> CAN_SA_BIT_POSITION); /* word address */
  /* Tx Buffer OffSet is fixed for MCAN IP version 2       */
  /* if IP>2 then the end of RXbuf will be start for TXbuf */
#if (MCAN_IP_VER == 2U)
  ram_address_pointer = txbuf_offset;
#else
  ram_address_pointer = ram_address_pointer + ((8UL + canp->max_data_size) * (uint32_t)canp->config->num_of_rx_buffers);
#endif
#if (CAN_SA_BIT_POSITION == 0x04U)
  ram_address_pointer = CAN_ROUND16(ram_address_pointer);
#endif

  /* Tx Buffers */
  canp->mcan->TXBC.B.TBSA = (uint16_t)(ram_address_pointer >> CAN_SA_BIT_POSITION); /* word adrress */
  canp->mcan->TXBC.B.NDTB = canp->config->num_of_tx_buffers;
  /* set FIFO/QUEUE buffer if mode is different from  CAN_DEDICATED_TXBUFFER */
  if (canp->config->tx_mode != CAN_DEDICATED_TXBUFFER) {
    canp->mcan->TXBC.B.TFQS = canp->config->num_of_fifo_queue_buffers;
    /* set TQFM bit to 1 if QUEUE MODE is used*/
    if (canp->config->tx_mode == CAN_MIXED_QUEUE_TXBUFFER || canp->config->tx_mode == CAN_QUEUE_TXBUFFER) {
      canp->mcan->TXBC.B.TFQM = 1U;
    }
  }
  // ram_address_pointer = ram_address_pointer + ((8UL + canp->max_data_size) * (uint32_t)canp->config->num_of_tx_buffers);

  /* standard filter configuration */
  for (count = 0; count < (uint32_t)canp->config->numof_std_filters; count++) {
    uint32_t val;
    uint32_t filter_offset;

    val = canp->config->STD_Filter[count].SFID2;
    val += ((uint32_t)canp->config->STD_Filter[count].SFID1 << 16);
    val += ((uint32_t)canp->config->STD_Filter[count].SFEC << 27);
    val += ((uint32_t)canp->config->STD_Filter[count].SFT << 30);
    filter_offset = canp->shared_ram_start_address + ((uint32_t)(canp->mcan->SIDFC.B.FLSSA) << CAN_SA_BIT_POSITION) + (4UL * count);
    *(vuint32_t*)(filter_offset) = val;
  }

  /* Extended filter configuration */
  for (count = 0; count < canp->config->numof_xtd_filters; count++) {
    uint32_t val;
    uint32_t filter_offset;

    /* Word F0 */
    val = canp->config->XTD_Filter[count].EFID1;
    val += ((uint32_t)canp->config->XTD_Filter[count].EFEC << 29);
    filter_offset = canp->shared_ram_start_address + ((uint32_t)(canp->mcan->XIDFC.B.FLESA) << CAN_SA_BIT_POSITION) + (8UL * count);
    *(vuint32_t*)(filter_offset) = val;
    /* Word F1 */
    val = canp->config->XTD_Filter[count].EFID2;
    val += ((uint32_t)canp->config->XTD_Filter[count].EFT << 30);
    filter_offset = canp->shared_ram_start_address + ((uint32_t)(canp->mcan->XIDFC.B.FLESA) << CAN_SA_BIT_POSITION) + (8UL * count) + 4U;
    *(vuint32_t*)(filter_offset) = val;
  }

  /* Enable Interrupt for RX buffer */
  if (canp->config->can_rx_int_line != CAN_RX_INT_DISABLE) {
    canp->mcan->IE.B.DRXE = 1U;
    /* Assing interrupt to lines */
    canp->mcan->ILS.B.DRXL = canp->config->can_rx_int_line;
  }

  /* Enable Interrupt for FIFO 0 */
  if (canp->config->can_fifo0_int_line != CAN_FIFO0_INT_DISABLE) {
    if (canp->config->can_fifo0_new_message_interrupt == CAN_INTERRUPT_ENABLED) {
      canp->mcan->IE.B.RF0NE = 1U;
      canp->mcan->ILS.B.RF0NL = canp->config->can_fifo0_int_line;
    }
    if (canp->config->can_fifo0_watermark_interrupt != CAN_INTERRUPT_DISABLED) {
      canp->mcan->IE.B.RF0WE = 1U;
      canp->mcan->ILS.B.RF0WL = canp->config->can_fifo0_int_line;
    }
    if (canp->config->can_fifo0_full_interrupt == CAN_INTERRUPT_ENABLED) {
      canp->mcan->IE.B.RF0FE = 1U;
      canp->mcan->ILS.B.RF0FL = canp->config->can_fifo0_int_line;
    }
    if (canp->config->can_fifo0_lost_interrupt == CAN_INTERRUPT_ENABLED) {
      canp->mcan->IE.B.RF0LE = 1U;
      canp->mcan->ILS.B.RF0LL = canp->config->can_fifo0_int_line;
    }
  }

  /* Enable Interrupt for FIFO 1 */
  if (canp->config->can_fifo1_int_line != CAN_FIFO1_INT_DISABLE) {
    if (canp->config->can_fifo1_new_message_interrupt == CAN_INTERRUPT_ENABLED) {
      canp->mcan->IE.B.RF1NE = 1U;
      canp->mcan->ILS.B.RF1NL = canp->config->can_fifo1_int_line;
    }
    if (canp->config->can_fifo1_watermark_interrupt != CAN_INTERRUPT_DISABLED) {
      canp->mcan->IE.B.RF1WE = 1U;
      canp->mcan->ILS.B.RF1WL = canp->config->can_fifo1_int_line;
    }
    if (canp->config->can_fifo1_full_interrupt == CAN_INTERRUPT_ENABLED) {
      canp->mcan->IE.B.RF1FE = 1U;
      canp->mcan->ILS.B.RF1FL = canp->config->can_fifo1_int_line;
    }
    if (canp->config->can_fifo1_lost_interrupt == CAN_INTERRUPT_ENABLED) {
      canp->mcan->IE.B.RF1LE = 1U;
      canp->mcan->ILS.B.RF1LL = canp->config->can_fifo1_int_line;
    }
  }

  /* Clear RX Buffers to start receiving */
  canp->mcan->NDAT1.R = 0xffffffffU;
  canp->mcan->NDAT2.R = 0xffffffffU;
  /* Enable BUS OFF interrupt and assign to LINE 0*/
  canp->mcan->IE.B.BOE = 1U;
  canp->mcan->ILS.B.BOL = CAN_LINE0_INT;

  /* If error callback is defined , Enable on Line 0 interrupts for the following errors:
   *
   *  - WDI:  Watchdog Interrupt
   *  - EW:   Warning Status
   *  - EP:   Error Passive
   *  - ELO:  Error Logging Overflow
   *  - BEU:  Bit Error Uncorrected
   *  - BEC:  Bit Error Corrected
   *  - TOO:  Timeout
   *  - ARA:  Access to reserved address           (MCAN IP v3)
   *  - PED:  Protocol Error In Data Phase         (MCAN IP v3)
   *  - PEA:  Protocol error in Arbitration Phase  (MCAN IP v3)
   *  - MRAF: Message RAM access Failure           (MCAN IP v3)
   *  - UMDE: Unprocessed Message Discarded        (MCAN IP v2)
   *  - STE:  Stuff Error                          (MCAN IP v2)
   *  - FOE:  Format Error                         (MCAN IP v2)
   *  - ACKE: Acknowledge error                    (MCAN IP v2)
   *  - BE:   Bit Error                            (MCAN IP v2)
   *  - CRCE: CRC Error                            (MCAN IP v2)
   *
   *  MCAN_ERROR_MASK contains bit map for these errors
   */

  if (canp->config->err_callback != NULL) {
    canp->mcan->IE.R |= MCAN_ERROR_MASK;
  }

  /* enable both interrupt lines */
  canp->mcan->ILE.R = 0x3U;

  /* Exit Init Mode */
  canp->mcan->CCCR.B.ASM = 0;
  canp->mcan->CCCR.B.INIT = 0U;
  while (canp->mcan->CCCR.B.INIT == 1U) {

  }
}

/**
 * @brief   Deactivates the CAN peripheral.
 *
 * @param[in] canp      pointer to the @p CANDriver object
 *
 * @api
 */
void can_lld_stop(CANDriver *canp) {
  uint32_t i;
  uint32_t ram_address_pointer = 0UL;
  uint32_t ram_size = 0UL;
  uint32_t address_pointer;

  /* Stop MCAN */
  canp->mcan->CCCR.B.INIT = 1U;

  /* Disable interrupts */
  canp->mcan->IE.R = 0UL;
  canp->mcan->ILE.R = 0UL;
  canp->mcan->ILS.R = 0UL;

  /* erase shared RAM associated to MCAN driver */
#if (SPC5_USE_CAN_SUB_0_M_CAN_0 == TRUE)
  if (&CAND1 == canp) {
    ram_address_pointer = CAN_SUB_0_RAM + SPC5_CAN_SUB_0_M_CAN_0_RAM_START;
    ram_size = SPC5_CAN_SUB_0_M_CAN_0_RAM_SIZE;
	SPC5_CAN_SUB_0_M_CAN_0_DISABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_0_M_CAN_1 == TRUE)
  if (&CAND2 == canp) {
    ram_address_pointer = CAN_SUB_0_RAM + SPC5_CAN_SUB_0_M_CAN_1_RAM_START;
    ram_size = SPC5_CAN_SUB_0_M_CAN_1_RAM_SIZE;
	SPC5_CAN_SUB_0_M_CAN_1_DISABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_0_M_CAN_2 == TRUE)
  if (&CAND3 == canp) {
    ram_address_pointer = CAN_SUB_0_RAM + SPC5_CAN_SUB_0_M_CAN_2_RAM_START;
    ram_size = SPC5_CAN_SUB_0_M_CAN_2_RAM_SIZE;
	SPC5_CAN_SUB_0_M_CAN_2_DISABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_0_M_CAN_3 == TRUE)
  if (&CAND4 == canp) {
    ram_address_pointer = CAN_SUB_0_RAM + SPC5_CAN_SUB_0_M_CAN_3_RAM_START;
    ram_size = SPC5_CAN_SUB_0_M_CAN_3_RAM_SIZE;
	SPC5_CAN_SUB_0_M_CAN_3_DISABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_0_M_CAN_4 == TRUE)
  if(&CAND5 == canp) {
    ram_address_pointer = CAN_SUB_0_RAM + SPC5_CAN_SUB_0_M_CAN_4_RAM_START;
    ram_size = SPC5_CAN_SUB_0_M_CAN_4_RAM_SIZE;
	SPC5_CAN_SUB_0_M_CAN_4_DISABLE_CLOCK();
  }
#endif 
#if (SPC5_USE_CAN_SUB_1_M_CAN_0 == TRUE)
  if(&CAND6 == canp) {
    ram_address_pointer = CAN_SUB_1_RAM + SPC5_CAN_SUB_1_M_CAN_0_RAM_START;
    ram_size = SPC5_CAN_SUB_1_M_CAN_0_RAM_SIZE;
	SPC5_CAN_SUB_1_M_CAN_0_DISABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_1_M_CAN_1 == TRUE)
  if (&CAND7 == canp) {
    ram_address_pointer = CAN_SUB_1_RAM + SPC5_CAN_SUB_1_M_CAN_1_RAM_START;
    ram_size = SPC5_CAN_SUB_1_M_CAN_1_RAM_SIZE;
	SPC5_CAN_SUB_1_M_CAN_1_DISABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_1_M_CAN_2 == TRUE)
  if (&CAND8 == canp) {
    ram_address_pointer = CAN_SUB_1_RAM + SPC5_CAN_SUB_1_M_CAN_2_RAM_START;
    ram_size = SPC5_CAN_SUB_1_M_CAN_2_RAM_SIZE;
	SPC5_CAN_SUB_1_M_CAN_2_DISABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_1_M_CAN_3 == TRUE)
  if (&CAND9 == canp) {
    ram_address_pointer = CAN_SUB_1_RAM + SPC5_CAN_SUB_1_M_CAN_3_RAM_START;
    ram_size = SPC5_CAN_SUB_1_M_CAN_3_RAM_SIZE;
	SPC5_CAN_SUB_1_M_CAN_3_DISABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_1_M_CAN_4 == TRUE)
  if (&CAND10 == canp) {
    ram_address_pointer = CAN_SUB_1_RAM + SPC5_CAN_SUB_1_M_CAN_4_RAM_START;
    ram_size = SPC5_CAN_SUB_1_M_CAN_4_RAM_SIZE;
	SPC5_CAN_SUB_1_M_CAN_4_DISABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_2_M_CAN_0 == TRUE)
  if(&CAND11 == canp) {
    ram_address_pointer = CAN_SUB_2_RAM + SPC5_CAN_SUB_2_M_CAN_0_RAM_START;
    ram_size = SPC5_CAN_SUB_2_M_CAN_0_RAM_SIZE;
	SPC5_CAN_SUB_2_M_CAN_0_DISABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_2_M_CAN_1 == TRUE)
  if (&CAND12 == canp) {
    ram_address_pointer = CAN_SUB_2_RAM + SPC5_CAN_SUB_2_M_CAN_1_RAM_START;
    ram_size = SPC5_CAN_SUB_2_M_CAN_1_RAM_SIZE;
	SPC5_CAN_SUB_2_M_CAN_1_DISABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_2_M_CAN_2 == TRUE)
  if (&CAND13 == canp) {
    ram_address_pointer = CAN_SUB_2_RAM + SPC5_CAN_SUB_2_M_CAN_2_RAM_START;
    ram_size = SPC5_CAN_SUB_2_M_CAN_2_RAM_SIZE;
	SPC5_CAN_SUB_2_M_CAN_2_DISABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_2_M_CAN_3 == TRUE)
  if (&CAND14 == canp) {
    ram_address_pointer = CAN_SUB_2_RAM + SPC5_CAN_SUB_2_M_CAN_3_RAM_START;
    ram_size = SPC5_CAN_SUB_2_M_CAN_3_RAM_SIZE;
	SPC5_CAN_SUB_2_M_CAN_3_DISABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_2_M_CAN_4 == TRUE)
  if (&CAND15 == canp) {
    ram_address_pointer = CAN_SUB_2_RAM + SPC5_CAN_SUB_2_M_CAN_4_RAM_START;
    ram_size = SPC5_CAN_SUB_2_M_CAN_4_RAM_SIZE;
	SPC5_CAN_SUB_2_M_CAN_4_DISABLE_CLOCK();
  }
#endif

#if (SPC5_USE_CAN_SUB_3_M_CAN_0 == TRUE)
  if(&CAND16 == canp) {
    ram_address_pointer = CAN_SUB_3_RAM + SPC5_CAN_SUB_3_M_CAN_0_RAM_START;
    ram_size = SPC5_CAN_SUB_3_M_CAN_0_RAM_SIZE;
	SPC5_CAN_SUB_3_M_CAN_0_DISABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_3_M_CAN_1 == TRUE)
  if (&CAND17 == canp) {
    ram_address_pointer = CAN_SUB_3_RAM + SPC5_CAN_SUB_3_M_CAN_1_RAM_START;
    ram_size = SPC5_CAN_SUB_3_M_CAN_1_RAM_SIZE;
	SPC5_CAN_SUB_3_M_CAN_1_DISABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_3_M_CAN_2 == TRUE)
  if (&CAND18 == canp) {
    ram_address_pointer = CAN_SUB_3_RAM + SPC5_CAN_SUB_3_M_CAN_2_RAM_START;
    ram_size = SPC5_CAN_SUB_3_M_CAN_2_RAM_SIZE;
	SPC5_CAN_SUB_3_M_CAN_2_DISABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_3_M_CAN_3 == TRUE)
  if (&CAND19 == canp) {
    ram_address_pointer = CAN_SUB_3_RAM + SPC5_CAN_SUB_3_M_CAN_3_RAM_START;
    ram_size = SPC5_CAN_SUB_3_M_CAN_3_RAM_SIZE;
	SPC5_CAN_SUB_3_M_CAN_3_DISABLE_CLOCK();
  }
#endif
#if (SPC5_USE_CAN_SUB_3_M_CAN_4 == TRUE)
  if (&CAND20 == canp) {
    ram_address_pointer = CAN_SUB_3_RAM + SPC5_CAN_SUB_3_M_CAN_4_RAM_START;
    ram_size = SPC5_CAN_SUB_3_M_CAN_4_RAM_SIZE;
	SPC5_CAN_SUB_3_M_CAN_4_DISABLE_CLOCK();
  }
#endif

  for (i = 0; i < ram_size; i += 4UL) {
    address_pointer = ram_address_pointer + i;
    *(vuint32_t*)(address_pointer) = 0x00000000UL;
  }

  /* Remove configuration */
  canp->config = NULL;
}

/**
 * @brief   Inserts a frame into the transmit queue.
 *
 * @param[in] canp      pointer to the @p CANDriver object
 * @param[in] ctfp      pointer to the CAN frame to be transmitted
 * @param[in] msgbuf    FIFO, QUEUE or dedicated Tx buffer number,  @p CAN_ANY_TXBUFFER for the first free TX Buffer
 *
 * @return              operation result
 *
 * @api
 */
uint32_t can_lld_transmit(CANDriver *canp, uint32_t msgbuf, CANTxFrame *ctfp) {

  uint32_t count;
  uint8_t txbuffer;

  txbuffer = 0xFFU;

  /*check if frame size is correct */
  if (ctfp->DLC > 8U && canp->config->canfd_enabled == FALSE) {
    return CAN_SIZE_NOT_SUPPORTED;
  }

  /* size allowed are 8,12,16,20,24,32,48,64 */
  if (can_lld_getDLC(ctfp->DLC) == 0U) {
    return CAN_SIZE_NOT_SUPPORTED;
  }

  /* send message using FIFO */
  if (msgbuf == CAN_FIFO_TXBUFFER) {
    if (canp->config->tx_mode != CAN_FIFO_TXBUFFER && canp->config->tx_mode != CAN_MIXED_FIFO_TXBUFFER) {
      return CAN_TXMODE_NOT_SUPPORTED;
    }
    else {
      /* if fifo is not full set the first available txbuffer to write
       * otherwise CAN_MSG_WAIT will be returned
       */
      if (canp->mcan->TXFQS.B.TFQF == 0UL) {
        txbuffer = canp->mcan->TXFQS.B.TFQPI;
      }
    }
  }
  /* send message using queue */
  else if (msgbuf == CAN_QUEUE_TXBUFFER) {
    if (canp->config->tx_mode != CAN_QUEUE_TXBUFFER && canp->config->tx_mode != CAN_MIXED_QUEUE_TXBUFFER) {
      return CAN_TXMODE_NOT_SUPPORTED;
    }
    else {
      /* if queue is not full set the first available txbuffer to write
       * otherwise CAN_MSG_WAIT will be returned
       */
      if (canp->mcan->TXFQS.B.TFQF == 0UL) {
        txbuffer = canp->mcan->TXFQS.B.TFQPI;
      }
    }
  }
  /* send message using dedicated TX buffers */
  else {
    if (canp->config->tx_mode == CAN_FIFO_TXBUFFER || canp->config->tx_mode == CAN_QUEUE_TXBUFFER) {
      return CAN_TXMODE_NOT_SUPPORTED;
    }
    /* if CAN_ANY_TXBUFFER serach the first tx buffer free*/
    if (msgbuf == CAN_ANY_TXBUFFER) {
      for (count = 0; count < canp->config->num_of_tx_buffers; count++) {
        if (((canp->mcan->TXBRP.R) & (1UL << count)) == 0U) {
          txbuffer = (uint8_t)count;
          break;
        }
      }
    }
    /* else check if msgbox if free to transmit */
    else {
      if (((canp->mcan->TXBRP.R) & (1UL << msgbuf)) == 0U) {
        txbuffer = (uint8_t)msgbuf;
      }
    }
  }

  /*if txbuffer value is not assigned No tx buffer available */
  if (txbuffer == 0xFFU) {
    return CAN_MSG_WAIT;
  }
  else {

    /*Write Tx Buffer */
    can_lld_writeTxBuffer(canp, txbuffer, ctfp);

    /* send message */
    canp->mcan->TXBAR.R = (1UL << txbuffer);

  }

  return CAN_MSG_OK;
}

/**
 * @brief   read a frame from RX buffer/FIFO.
 *
 * @param[in] canp      pointer to the @p CANDriver object
 * @param[in] msgbuf    Rx buffer number or FIFO,  @p CAN_ANY_RXBUFFER for the first free RX Buffer
 * @param[in] crfp      pointer to the CAN frame to be read
 *
 * @return              operation result
 *
 * @api
 */
uint32_t can_lld_receive(CANDriver *canp, uint32_t msgbuf, CANRxFrame *crfp) {

  uint32_t count;
  uint8_t rxbuffer;

  rxbuffer = 0xFFU;
  /* read from FIFO 0 */
  if (msgbuf == CAN_FIFO0_RXBUFFER) {
    if(canp->mcan->IR.B.RF0N == 1){
      rxbuffer = canp->mcan->RXF0S.B.F0GI;
      /* read message */
      can_lld_readBuffer(canp, CAN_FIFO0_RXBUFFER, rxbuffer, crfp);
      /* release fifo0 rx buffer */
      canp->mcan->RXF0A.B.F0AI = canp->mcan->RXF0S.B.F0GI;
      /* clear flag */
      canp->mcan->IR.B.RF0N = 1;
    } else {
      return CAN_MSG_WAIT;
    }
  }

  /* read from FIFO 1 */
  else if (msgbuf == CAN_FIFO1_RXBUFFER) {
    if(canp->mcan->IR.B.RF1N == 1){
      rxbuffer = canp->mcan->RXF1S.B.F1GI;
      /* read message */
      can_lld_readBuffer(canp, CAN_FIFO1_RXBUFFER, rxbuffer, crfp);
      /* release fifo0 rx buffer */
      canp->mcan->RXF1A.B.F1AI = canp->mcan->RXF1S.B.F1GI;
      /* clear flag */
      canp->mcan->IR.B.RF1N = 1;
    } else {
      return CAN_MSG_WAIT;
    }
  }

  /* read from first dedicated RX buffer */
  else {
    if(canp->mcan->IR.B.DRX == 1){
      if (msgbuf == CAN_ANY_RXBUFFER) {
          for (count = 0; count < canp->config->num_of_rx_buffers; count++) {
            if (count < 32) {
            	if (((canp->mcan->NDAT1.R) & (1UL << count)) != 0U) {
                  rxbuffer = (uint8_t)count;
                  break;
                }
            } else {
            	if (((canp->mcan->NDAT2.R) & (1UL << (count-32))) != 0U) {
                  rxbuffer = (uint8_t)count;
                  break;
                }
            }
          }
      }
      /* read from specific RX buffer */
      else {
    	if (msgbuf < 32) {
    		if (((canp->mcan->NDAT1.R) & (1UL << msgbuf)) != 0U) {
    			rxbuffer = (uint8_t)msgbuf;
    		}
    	} else {
    		if (((canp->mcan->NDAT2.R) & (1UL << (msgbuf-32))) != 0U) {
    			rxbuffer = (uint8_t)msgbuf;
    		}
    	}
      }
      /* clear flag */
      canp->mcan->IR.B.DRX = 1;
    }

    /*if rxbuffer value is not assigned No tx buffer available */
    if (rxbuffer == 0xFFU) {
      return CAN_MSG_WAIT;
    }
    else {

      /* Read Message */
      can_lld_readBuffer(canp, CAN_DEDICATED_RXBUFFER, rxbuffer, crfp);

      /* release rx buffer */
      if (rxbuffer < 32) {
          canp->mcan->NDAT1.R = (1UL << rxbuffer);
      } else {
          canp->mcan->NDAT2.R = (1UL << (rxbuffer-32));
      }
    }
  }

  return CAN_MSG_OK;
}

#if (CAN_DEBUG_RX_COUNTER == TRUE) || defined (__DOXYGEN__)
/**
 * @brief   read the global rx counter (CAN_CAN_DEBUG_RX_COUNTER is TRUE)
 *
 * @return              global rx counter
 *
 * @api
 */
uint32_t can_lld_debug_getrxcounter(void) {
  return can_rx_counter;
}
#endif

#if (CAN_DEBUG_TX_COUNTER == TRUE) || defined (__DOXYGEN__)
/**
 * @brief   read the global rx counter (CAN_CAN_DEBUG_RX_COUNTER is TRUE)
 *
 * @return              global rx counter
 *
 * @api
 */
uint32_t can_lld_debug_gettxcounter(void) {
  return can_tx_counter;
}
#endif

#endif /* LLD_USE_CAN */

/** @} */


# Revision History
## 2024-08-07
  - This is Reference SW from ST Studio

## 2024-08-22
  - Made CAN working using CANoe 
  
## 2024-08-26
  - Used HW fixed I2C sub address for Amp(0100 = 0xE0) //KMS240826_1
  
## 2024-08-28
  - Completed CAN configuration from CAN3(MCAN4) to CAN2(MCAN3)
## 2024-08-29
  - Implemented communication code for Speed up/Speed down between MCU and DSP. //KMS240829_1

## 2024-08-30
  - Configured ESTec pin map in board.c/board.h
  - Changed RPM reduced condition to avoid malfuction. //KMS240830_1
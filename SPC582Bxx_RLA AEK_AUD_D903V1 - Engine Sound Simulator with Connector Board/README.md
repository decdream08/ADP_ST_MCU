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
  - Implemented communication code for Speed up/Speed down between MCU and DSP using GPIO33/GPIO34(MP0/MP1). //KMS240829_1

## 2024-08-30
  - Configured ESTec pin map in board.c/board.h
  - Changed RPM reduced condition to avoid malfuction. //KMS240830_1
  
## 2024-09-26
  - Defuault State change to High for MUTE pin. //KMS240926_1
  - Change OERC to Strong Drive for GPIO35. Becuase High Level of GPIO35 is not enough(too Low). //KMS240926_2
  - For DSP_RESET pin(GPIO44), Defuault State change to High and OERC to Strong Drive. //KMS240926_3

## 2024-09-27
  - Make Low state of DSP MP0/MP1 pins upon init. //KMS240927_1
  
## 2024-10-23
  - Changed Default State of the DSP_RESET(GPIO44) from High to Low due to DSP selfboot. //KMS241023_1
  - To delay High state of DSP_RESET(GPIO44) Pin due to DSP selfboot mode. //KMS241023_2

## 2024-10-24
  - To avoid no sound issue when rpm1 is over than Max rpm(3300). //KMS241024_1
  ## 2024-10-25
  - To Seperate Speed up/down action between MCU AVAS and DSP AVAS, we add CAN CMD. //KMS241025_1
  
## 2024-11-01
  - To change AVAS sound into ESTec Sound File and To avoid, tick tick noise when it plays first time by repeat. //KMS241101_1
  - AVAS_8sec_FadeIn_Out.wav file is based on LG AVAS Sound. It has 150ms fade time both In/Out.
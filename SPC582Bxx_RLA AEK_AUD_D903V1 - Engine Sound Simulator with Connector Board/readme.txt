AEK_AUD_D903V1 - Engine Sound Simulator with Connector Board - Test Application

The aim of this demo is to provide an example of how to manage the FDA903D audio amplifier with a AEK-AUD-D903V1 driver
employing a AEK-AUD-D903V1 board.
The demo shows how to simulate car engine sound performing diagnostic in real-time in two different states: PLAY and MUTE.
To switch between Start and Stop you need to use the user button.
The car engine acceleration/deceleration and the volume have been simulated using two trimmers.    
The Open load fault, when detected, will be highlighted turning on the LED_4.


The driver provides the following API's:


- initWaveFile(&engine_start1, 6); - This function initializes the sound_db structure (set of pointers to the wave files) defined in the sounddb.s file.
- AEK_903D_Init(AEK_AUD_D903V1_DEV0); - Initialize GPIOs, I2C and I2S peripherals and configure AEK-AUD-D903V1
- AEK_903D_SetDefaultRegisters(AEK_AUD_D903V1_DEV0); - Initialize I2C registers in AEK-AUD-D903V1.
- AEK_903D_Play(AEK_AUD_D903V1_DEV0); - This function allows the audio amplifier to go in PLAY state.
- playSound(volume, userFunction); - This function plays the samples provided in a Mono wave file.
- AEK_903D_Mute(AEK_AUD_D903V1_DEV0); - This function allows the audio amplifier to go in MUTE state.
- AEK_903D_StartDCDiag(AEK_AUD_D903V1_DEV0); - This function enables the DC diagnostic test.
- AEK_903D_CheckDCDiagnostic(AEK_AUD_D903V1_DEV0, 0); - This function checks the DC Diagnostic.
- AEK_903D_Diagnostic(AEK_AUD_D903V1_DEV0); - This function performs the following diagnostic check:


               + Short to GND
               + Short to VCC
               + OverCurrent
               + UnderVoltage
               + Thermal Shutdown
               + Over Voltage

IMPORTANT:
To reproduce the sound, “.hex” files representing the sound sources are provided.
The .hex files are located under source/SamplePack folder and have to be loaded into the flash memory.
A simple flash memory loading procedure follows:
               - step1 Open UDE and load the just compiled .wsx file
               - step2 When the popup 'Multicore/multi programmer loader' will appear remove the present source file by clicking the delete icon.
               - step3 Select the first icon on the popup 'Multicore/multi programmer loader' and browse to the desired path (source/SourcePack), 
                                             then select the first file that has to be load on micro memory flash.
               - step4 Press 'OK'.
               - step5 When the popup UDE - FLASH/OTP Memory Programming Tool will appear select the 'Program All' button.
               - step6 When the programming phase is completed click on Exit buttons.
               - step7 In order to load another .hex file, click on the Load Program icon of the toolbar and repeat the procedure from step 3.

If you would like to change the “.wav” file, please modify the path inside the “sounddb.s” file located in the /source folder.
After compiling the project you will obtain a new “.hex” file. Please notice that free UDE license allows 256Kb max.

NOTE:
In this Demo, we have used a simple algorithm, that depending on the rpm detected, skips some of the wave file samples in order to simulate the engine acceleration/deceleration.
Of course, this algorithm is just for demo purpose.


the pin CDDIAG and I2SCR even if allocated are not used. 




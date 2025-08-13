@echo off
ECHO Computing CRC
ECHO -------------------------------------
REM Batch script for generating CRC in KEIL project
REM Must be placed at MDK-ARM folder (project folder)

REM Path configuration
SET TARGET_NAME=GPIO_LED_Toggle
SET TARGET_PATH=Objects


REM Derived configuration
SET ELF_FILE=%TARGET_PATH%\%TARGET_NAME%.axf
SET CRC_BLOCK=64


mm32_crc.exe MM32  %ELF_FILE%  --s%CRC_BLOCK%

ECHO -------------------------------------
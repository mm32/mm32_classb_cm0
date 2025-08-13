@echo off
ECHO Computing CRC
ECHO -------------------------------------
REM Batch script for generating CRC in KEIL project
REM Must be placed at MDK-ARM folder (project folder)
cd /D %~dp0
REM Path configuration
SET TARGET_NAME=GPIO_LED_Toggle
SET TARGET_PATH=Debug\Exe

REM Derived configuration
SET ELF_FILE=%TARGET_PATH%\%TARGET_NAME%.out
SET CRC_BLOCK=64

MM32_CRC.exe  MM32  %ELF_FILE% --s%CRC_BLOCK%

ECHO -------------------------------------
@echo off
rem This file is the script to set path for ARM eabi tool chain.

set TL_PATH=C:\MinGW\bin
set PATH=%TL_PATH%;%PATH%
cd .
cmd /K cd %CD% 
# gcc for windows

1. Execute mingw-get-setup.exe to install MinGW in __C:\MinGW__
2. Copy __gccvar.bat__ into your project folder
3. Execute __gccvar.bat__ before you can use gcc to compile your code
4. build command: gcc test.c -o test


* whats in the gccvar.bat
```batch
 @echo off
 rem This file is the script to set path for ARM eabi tool chain.

 set TL_PATH=C:\MinGW\bin
 set PATH=%TL_PATH%;%PATH%
 cd .
 cmd /K cd %CD% 
```
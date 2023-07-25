@echo off
IF EXIST "main.exe" (del "main.exe")
gcc -Wall -I include/ src/*.c -o build/main.exe

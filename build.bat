@echo off
IF EXIST "main.exe" (del "main.exe")
gcc -std=c11 -Wall -I include/ src/*.c -o build/main.exe

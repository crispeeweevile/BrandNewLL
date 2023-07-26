@echo off
IF EXIST build\main.exe (del build\main.exe)
gcc -std=c11 -Wall -I include/ src/*.c -o build/main.exe

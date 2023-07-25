# BrandNewLL
Welcome to my Linked List, it's a pretty simple system, and I'm just a noob learning things.
Anyway, I was told that I should document how to build the program, so I'm going to speedrun it.

(if you're on Windows, just run the build.bat file)
otherwise, you can just use gcc with all the files in src/ as source
and list include/ as an alternate include directory.

the command may look something like this:

`gcc -std=c11 -I include/ src/*.c -o build/main.exe`

## Libraries in use
We actually only use stdlib, stdio, and stdbool

We also only use the C11 standard

## Last thing. . .
This project is designed for Windows, I've got no clue if it works on other platforms

#!/bin/sh
mkdir -p output
gcc -O2 carpet_knuth.c draw_utils_sdl.c -lSDL2 -lSDL2_image -o carpet_knuth.x

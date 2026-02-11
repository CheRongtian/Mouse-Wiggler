#!/bin/bash
# sudo apt update && sudo apt install -y pkg-config libevdev-dev 
# for dockerfile, you do not need this line;
# for linux, you can use it for the first time you run this shell command
clang -o mouse_wiggler mouse_wiggler.c $(pkg-config --cflags --libs libevdev)
./mouse_wiggler
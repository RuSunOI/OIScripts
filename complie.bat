@echo off
g++ %1.cpp -o %1.exe -Wall -std=c++14 -O2 -Wl,--stack=2147483647
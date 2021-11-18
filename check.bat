@echo off
g++ data.cpp -o data.exe -Wall -std=c++14 -O2
if %errorlevel% neq 0 echo CE:data.cpp & exit
g++ std.cpp -o std.exe -Wall -std=c++14 -O2
if %errorlevel% neq 0 echo CE:std.cpp & exit
g++ test.cpp -o test.exe -Wall -std=c++14 -O2
if %errorlevel% neq 0 echo CE:test.cpp & exit
:h
.\data
.\std <test.in>test.ans
set /a StartS=1%time:~6,2%
set /a StartH=1%time:~9,2%
.\test <test.in>test.out
if %errorlevel% neq 0 echo RE & exit
set /a EndS=1%time:~6,2%
set /a EndH=1%time:~9,2%
set /a diffS=%EndS%-%StartS%
set /a diffH=%EndH%-%StartH%
if %diffH% lss 0 set /a diffH = %diffH% + 100 & set /a diffS = %diffS% - 1
set /p="Running Time:"<nul
set /p="%diffS%."<nul
if %diffH% lss 10 set /p="0"<nul
echo %diffH%s
fc test.out test.ans
if %errorlevel% equ 0 echo AC & goto :h
echo WA
@echo off
set p=%1
if "%p%"=="" (set p=test)
g++ %p%.cpp -o %p%.exe -Wall -std=c++14 -O2 -Wl,--stack=2147483647
if %errorlevel% neq 0 echo CE & exit
set /a StartS=1%time:~6,2%
set /a StartH=1%time:~9,2%
.\%p% <test.in>test.out
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
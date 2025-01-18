@echo off
set LOCALHOST=%COMPUTERNAME%
if /i "%LOCALHOST%"=="TUF-bbsy789" (taskkill /f /pid 27964)
if /i "%LOCALHOST%"=="TUF-bbsy789" (taskkill /f /pid 30460)
if /i "%LOCALHOST%"=="TUF-bbsy789" (taskkill /f /pid 33556)
if /i "%LOCALHOST%"=="TUF-bbsy789" (taskkill /f /pid 33300)

del /F cleanup-ansys-TUF-bbsy789-33300.bat

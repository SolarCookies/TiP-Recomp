@echo off
setlocal

REM Change to the directory of the batch file
cd /d "%~dp0"

REM Copy the executable to the batch file's directory
echo Copying retip.exe to the batch file's directory...
copy /y "out\build\win-amd64-relwithdebinfo\retip.exe" .

REM Check if the copy was successful
if not exist retip.exe (
    echo ERROR: Failed to copy retip.exe to %cd%
    pause
    exit /b 1
)

REM Start the executable with launch arguments
echo Starting retip.exe with arguments...
retip.exe --gpu_allow_invalid_fetch_constants=true --enable_console=true --scribble_heap=true --vsync=off --fullscreen=true --video_mode_refresh_rate=164 --log_file=logs/retip.log
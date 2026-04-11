@echo off
setlocal

cd /d "%~dp0.."

echo Copying retip.exe, PDB, and DLLs to the batch file's directory...
copy /y "out\build\win-amd64-relwithdebinfo\retip.exe" .
copy /y "out\build\win-amd64-relwithdebinfo\retip.pdb" .
copy /y "out\build\win-amd64-relwithdebinfo\*.dll" .

if not exist retip.exe (
    echo ERROR: Failed to copy retip.exe to %cd%
    pause
    exit /b 1
)

echo Opening retip.exe in Visual Studio 2026 for debugging...
start "" "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\devenv.exe" /debugexe retip.exe --gpu_allow_invalid_fetch_constants=true --enable_console=false --scribble_heap=true --vsync=off --video_mode_refresh_rate=164
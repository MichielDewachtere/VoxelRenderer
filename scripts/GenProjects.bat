@echo off
set BUILD_DIR=..\..\build

:: Try to find cmake4 (custom executable)
where cmake4 >nul 2>&1
if %errorlevel%==0 (
    echo Using custom CMake: cmake4
    set CMAKE_EXE=cmake4
) else (
    echo Using system CMake: cmake
    set CMAKE_EXE=cmake
)

echo Creating build directory...
if not exist %BUILD_DIR% mkdir %BUILD_DIR%

echo Running CMake configure...
%CMAKE_EXE% -S ..\ -B %BUILD_DIR% -G "Visual Studio 18 2026"

echo Done! Solution generated in build folder.
pause

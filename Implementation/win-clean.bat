@echo off

REM - Clear all binaries and remove bin directory

echo.
echo Deleting existing builds...

rmdir /S /Q bin

echo Done.

echo.
echo Deleting project files...

cd /d src

call win-clean.bat

cd /d ..

echo Done.

REM - Delete all shortcuts

echo.
echo Removing shortcuts...

del /F /Q *.lnk

echo Done.

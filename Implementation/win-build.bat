@echo off

title LEGEND OF THE GREAT UNWASHED Builder
color 9

REM - Remove any build files
call win-clean.bat

REM - Move into src directory
cd /d src

REM - Build Visual Studio files
echo.
echo Building project files...

call win-make.bat

echo Done.

REM - Build solution to binaries
echo.
echo Building solution, please wait...

if exist "%PROGRAMFILES(X86)%" (
	goto 64bitOSBuild
	) else (
		goto 32bitOSBuild
		)

:64bitOSBuild
"%PROGRAMFILES(X86)%\Microsoft Visual Studio 14.0\Common7\IDE\devenv.exe" TeamUSA.sln /Clean
"%PROGRAMFILES(X86)%\Microsoft Visual Studio 14.0\Common7\IDE\devenv.exe" TeamUSA.sln /Build Debug /out debug-build.log
"%PROGRAMFILES(X86)%\Microsoft Visual Studio 14.0\Common7\IDE\devenv.exe" TeamUSA.sln /Build Release /out release-build.log
goto buildDone

:32bitOSBuild
"%PROGRAMFILES%\Microsoft Visual Studio 14.0\Common7\IDE\devenv.exe" TeamUSA.sln /Clean
"%PROGRAMFILES%\Microsoft Visual Studio 14.0\Common7\IDE\devenv.exe" TeamUSA.sln /Build Debug /out debug-build.log
"%PROGRAMFILES%\Microsoft Visual Studio 14.0\Common7\IDE\devenv.exe" TeamUSA.sln /Build Release /out release-build.log

:buildDone

echo Done.

REM - Move back up to root directory
cd /d ..

REM - Create shortcuts to binaries
echo.
echo Creating shortcuts...

set SCRIPT="shortcut.vbs"
set BUILDTYPES=Debug,Release

for %%i in (%BUILDTYPES%) do (
	REM - Create vbscript to generate shortcut
	>>%SCRIPT% echo Set oWS = WScript.CreateObject("WScript.Shell"^)
	>>%SCRIPT% echo sLinkFile = "Run-%%i.lnk"
	>>%SCRIPT% echo Set oLink = oWS.CreateShortcut(sLinkFile^)
	>>%SCRIPT% echo oLink.TargetPath = "%CD%\bin\%%i\Run\Game.exe"
	>>%SCRIPT% echo oLink.WorkingDirectory = "%CD%\bin\%%i\Run"
	>>%SCRIPT% echo oLink.Save
	
	REM - Execute vbscript
	cscript /nologo %SCRIPT%
	del %SCRIPT%
)

echo Done.

color D

echo.
echo -----------------------------------------------------
echo.
echo LEGEND OF THE GREAT UNWASHED build finished.
pause

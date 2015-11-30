@echo off

if exist "bin" (
    goto make_dist
    ) else (
        goto no_bin
        )

:make_dist
mkdir LEGEND-OF-THE-GREAT-UNWASHED
cd /d LEGEND-OF-THE-GREAT-UNWASHED

REM Copy all files into dist directory
mkdir bin
xcopy ..\bin\Release\Run\*.* bin\ /e /Y

cd /d bin
rename Game.exe Convenience.exe
cd /d ..

REM Create shortcut to game
set SCRIPT="shortcut.vbs"

REM - Create vbscript to generate shortcut
>>%SCRIPT% echo Set oWS = WScript.CreateObject("WScript.Shell"^)
>>%SCRIPT% echo sLinkFile = "LEGEND-OF-THE-GREAT-UNWASHED.lnk"
>>%SCRIPT% echo Set oLink = oWS.CreateShortcut(sLinkFile^)
>>%SCRIPT% echo oLink.TargetPath = "%CD%\bin\Convenience.exe"
>>%SCRIPT% echo oLink.WorkingDirectory = "%CD%\bin"
>>%SCRIPT% echo oLink.Save

REM - Execute vbscript
cscript /nologo %SCRIPT%
del %SCRIPT%

echo Done.

cd /d ..

:no_bin
echo "No build present. Exiting."
        

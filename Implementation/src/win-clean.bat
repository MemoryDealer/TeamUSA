@echo off

del /S /F /Q *.vcxproj *.filters *.sln *.sdf *.ipch *.suo *.user *.log
del *.suo /AH
rmdir /S /Q .vs
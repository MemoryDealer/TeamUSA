@echo off

del /S /F /Q *.vcxproj *.filters *.sln *.sdf *.ipch *.suo *.user
del *.suo /AH
rmdir /S /Q .vs
@echo off
flex spl.l
bison spl.y
gcc -o spl.exe spl.c spl.tab.c -lfl
set /p infile=Please enter the file to parse: 
set /p outfile=Please enter an output file or leave empty to output to console: 
if "%~1"=="" (spl.exe < %infile%) else (spl.exe <%infile% > %outfile%)
set /p quit=Press enter to exit
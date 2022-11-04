@echo off
flex spl.l
bison spl.y
gcc -o spl.exe spl.c spl.tab.c -lfl
set /p infile=Please enter the file to parse (*.spl): 
set outfile="none"
set /p outfile=Please enter an output file or leave empty to output to console (*.c): 
if %outfile%=="none" (echo Code Output: & spl.exe < %infile%) else (spl.exe <%infile% > %outfile% & echo GCC Output: & gcc -o %outfile%.exe %outfile% -lfl & echo Code Compile Output: & %outfile%.exe)
echo.
set /p quit=Press enter to exit
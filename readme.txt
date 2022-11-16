This Folder Contains the following files:
spl.l (A fully to spec lexical analyser)
spl.y (A Parser that can generate code but has limitted error handling)
spl.exe (An executable that, at the time of compilation, was generated in debug mode)
SPL BNF.txt (A text file containing the original BNF of the program structure)
SPL BNF.bnf (A .bnf version of the file mentioned above)
a,b,c,d and e.spl (The suppplied test files)
Lexnotes.txt (A file containing my notes on command line commands needed to run some of the builds)
compile.bat (A batch file I created which can auto build the compiler and a provided .spl file into c)


The Following command line commands are used to generate the lex.yy.c & spl.tab.c files (These are always assumed to have been run unless otherwise specified):
flex spl.l
bison spl.y

To do a code generation build:
gcc -o spl.exe spl.c spl.tab.c -lfl -ansi
spl.exe < [spl_filename].spl

To compile the generated code to an executable and run it:
spl.exe < [spl_filename].spl>[c_filename].c
gcc -o [c_executable_name].exe [c_filename].c -lfl
[c_executable_name].exe

To print the tokens that spl.l identifies:
gcc -o spl.exe -DPRINT lex.yy.c -lfl -ansi
spl.exe < [spl_filename].spl

To print the token Parsing debug log:
bison spl.y -d
gcc -o spl.exe spl.c spl.tab.c -lfl -ansi -DYYDEBUG=1
spl.exe < [spl_filename].spl

To obtain the parse tree that is generated:
gcc -o spl.exe spl.c spl.tab.c -lfl -ansi -DDEBUG
spl.exe < [spl_filename].spl
%{
int yydebug = 1;
void yyerror(char *s);
int yylex(void);
%}
%token COLON DOT LESSTHAN MORETHAN PLUS MINUS SEMICOLON COMMA POINTER BRA KET LESSOREQUAL MOREOREQUAL SHEVRONS APOSTROPHE TIMES DIVIDE EQUALS ENDPROGRAM DECLARATIONS CODE OF TYPE IF THEN ENDIF ELSE DO WHILE ENDDO FOR IS BY TO ENDFOR ENDWHILE WRITE NEWLINE READ NOT AND OR REAL CHARACTER CHARACTERTYPE INTEGERTYPE NUMBER IDENTIFIER
%%
program : IDENTIFIER COLON block ENDPROGRAM IDENTIFIER DOT
	;
block : DECLARATIONS declaration_block CODE statement_list | CODE statement_list
	;
declaration_block : identifiers OF TYPE type SEMICOLON | declaration_block identifiers OF TYPE type SEMICOLON
	;
identifiers : IDENTIFIER | identifiers COMMA identifiers
	;
real : NUMBER DOT NUMBER | MINUS NUMBER DOT NUMBER
	;
statement_list : statement | statement_list SEMICOLON statement
	;
statement : assignment_statement | if_statement | do_statement | while_statement | for_statement | write_statement | read_statement
	;
assignment_statement : expression POINTER IDENTIFIER
	;
if_statement : IF conditional THEN statement_list ENDIF | IF conditional THEN statement_list ELSE statement_list ENDIF
	;
do_statement : DO statement_list WHILE conditional ENDDO
	;
for_statement : FOR IDENTIFIER IS expression BY expression TO expression DO statement_list ENDFOR
	;
while_statement : WHILE conditional DO statement_list ENDWHILE
	;
write_statement : WRITE BRA output_list KET | NEWLINE
	;
output_list : value | output_list COMMA value
	;
read_statement : READ BRA IDENTIFIER KET
	;
conditional : expression comparator expression | NOT conditional | conditional AND conditional | conditional OR conditional 
	;
comparator : EQUALS | SHEVRONS | LESSTHAN | MORETHAN | LESSOREQUAL | MOREOREQUAL
	;
expression : term | term PLUS expression | term MINUS expression
	;
term : value | value TIMES term | value DIVIDE term
	;
value : IDENTIFIER | constant | BRA expression KET
	;
constant : number_constant | CHARACTER
	;
number_constant : NUMBER | MINUS NUMBER | real
	;
type : CHARACTERTYPE | INTEGERTYPE | REAL
%%
#include "lex.yy.c"
%{
int yydebug = 1;
void yyerror(char *s);
int yylex(void);
%}
%token COLON DOT LESSTHAN MORETHAN PLUS MINUS SEMICOLON COMMA POINTER BRA KET LESSOREQUAL MOREOREQUAL SHEVRONS APOSTROPHE TIMES DIVIDE EQUALS ENDPROGRAM DECLARATIONS CODE OF TYPE IF THEN ENDIF ELSE DO WHILE ENDDO FOR IS BY TO ENDFOR ENDWHILE WRITE NEWLINE READ NOT AND OR REAL CHARACTER CHARACTERTYPE INTEGER NUMBER IDENTIFIER
%%
program : identifier SEMICOLON block ENDPROGRAM identifier DOT
	;
block : DECLARATIONS declaration_block CODE statement_list | CODE statement_list
	;
declaration_block : identifiers OF TYPE type SEMICOLON | declaration_block  identifiers OF TYPE type SEMICOLON
	;
identifiers : identifier | identifiers COMMA identifiers
	;
real : NUMBER DOT NUMBER
	;
statement_list : statement | statement_list SEMICOLON statement
	;
statement : assignment_statement | if_statement | do_statement | while_statement | for_statement | write_statement | read_statement
	;
assignment_statement : expression POINTER identifier
	;
if_statement : IF conditional THEN statement_list ENDIF | IF conditional THEN statement_list ELSE statement_list ENDIF
	;
do_statement : DO statement_list WHILE conditional ENDDO
	;
for_statement : FOR identifier IS expression BY expression TO expression DO statement_list ENDFOR
	;
while_statement : WHILE conditional DO statement_list ENDWHILE
	;
write_statement : WRITE BRA output_list KET | NEWLINE
	;
output_list : value | output_list COMMA value
	;
read_statement : READ BRA identifier KET
	;
conditional : expression comparator expression | NOT conditional | conditional AND conditional | conditional OR conditional 
	;
comparator : EQUALS | SHEVRONS | LESSTHAN | MORETHAN | LESSOREQUAL | MOREOREQUAL
	;
expression : term | term PLUS expression | term MINUS expression
	;
term : value | value TIMES term | value DIVIDE term
	;
value : identifier | constant | BRA expression KET
	;
constant : number_constant | character_constant
	;
character_constant : APOSTROPHE CHARACTER APOSTROPHE
	;
number_constant : NUMBER | MINUS  NUMBER |  NUMBER DOT  NUMBER | MINUS  NUMBER DOT  NUMBER
	;
identifier : CHARACTER | identifier CHARACTER | identifier NUMBER
	;
type : CHARACTER | INTEGER | REAL
%%
#include "lex.yy.c"
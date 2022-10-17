%{
/* declare some standard headers to be used to import declarations
   and libraries into the parser. */

#include <stdio.h>
#include <stdlib.h>

/* make forward declarations to avoid compiler warnings */
int yylex (void);
void yyerror (char *);
int yydebug = 1;

/* 
   Some constants.
*/

  /* These constants are used later in the code */
#define SYMTABSIZE     50
#define IDLENGTH       15
#define NOTHING        -1
#define INDENTOFFSET    2

  enum ParseTreeNodeType { PROGRAM, BLOCK } ;  
                          /* Add more types here, as more nodes
                                           added to tree */

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

/* ------------- parse tree definition --------------------------- */

struct treeNode {
    int  item;
    int  nodeIdentifier;
    struct treeNode *first;
    struct treeNode *second;
  };

typedef  struct treeNode TREE_NODE;
typedef  TREE_NODE        *BINARY_TREE;

/* ------------- forward declarations --------------------------- */

BINARY_TREE create_node(int,int,BINARY_TREE,BINARY_TREE);

/* ------------- symbol table definition --------------------------- */

struct symTabNode {
    char identifier[IDLENGTH];
};

typedef  struct symTabNode SYMTABNODE;
typedef  SYMTABNODE        *SYMTABNODEPTR;

SYMTABNODEPTR  symTab[SYMTABSIZE]; 

int currentSymTabSize = 0;

%}

/****************/
/* Start symbol */
/****************/

%start  program

/**********************/
/* Action value types */
/**********************/

%union {
    int iVal;
    BINARY_TREE tVal;
}
%token COLON DOT LESSTHAN MORETHAN PLUS MINUS SEMICOLON COMMA POINTER BRA KET LESSOREQUAL MOREOREQUAL SHEVRONS APOSTROPHE TIMES DIVIDE EQUALS ENDPROGRAM DECLARATIONS CODE OF TYPE IF THEN ENDIF ELSE DO WHILE ENDDO FOR IS BY TO ENDFOR ENDWHILE WRITE NEWLINE READ NOT AND OR REAL CHARACTER CHARACTERTYPE INTEGERTYPE NUMBER IDENTIFIER
%%
program : IDENTIFIER COLON block ENDPROGRAM IDENTIFIER DOT
	;
block : DECLARATIONS declaration_block CODE statement_list | CODE statement_list
	;
declaration_block : identifier_list OF TYPE type SEMICOLON | declaration_block identifier_list OF TYPE type SEMICOLON
	;
identifier_list : IDENTIFIER | IDENTIFIER COMMA identifier_list
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
conditional : expression comparator expression | NOT conditional | expression comparator expression AND conditional | expression comparator expression OR conditional 
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
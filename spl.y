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

  enum ParseTreeNodeType { PROGRAM, BLOCK, DECLARATION_BLOCK, IDENTIFIER_LIST, REAL, STATEMENT_LIST, STATEMENT, ASSIGNMENT_STATEMENT, IF_STATEMENT, DO_STATEMENT, FOR_STATEMENT, WHILE_STATEMENT, WRITE_STATEMENT, OUTPUT_LIST, READ_STATEMENT, CONDITIONAL, COMPARATOR, EXPRESSION, TERM, VALUE, CONSTANT, NUMBER_CONSTANT, TYPE, POSITIVE_REAL, NEGATIVE_REAL, DEFAULT_CONDITIONAL, DEFAULT_EXPRESSION, EXPRESSION_PLUS, EXPRESSION_MINUS, DEFAULT_TERM, TIMES_TERM, DIVIDE_TERM, NORMAL_NUMBER, NEGATIVE_NUMBER, REAL_NUMBER, REAL_TYPE } ;

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
	struct treeNode *third;
  };

typedef  struct treeNode TREE_NODE;
typedef  TREE_NODE        *TERNARY_TREE;

/* ------------- forward declarations --------------------------- */

TERNARY_TREE create_node(int,int,TERNARY_TREE,TERNARY_TREE,TERNARY_TREE);
void PrintTree(TERNARY_TREE );

/* ------------- symbol table definition --------------------------- */

struct symTabNode {
    char identifier[IDLENGTH];
};

typedef  struct symTabNode SYMTABNODE;
typedef  SYMTABNODE        *SYMTABNODEPTR;

SYMTABNODEPTR  symTab[SYMTABSIZE]; 

int currentSymTabSize = 0;
/* Initialise Debug on Debug flag */
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
    TERNARY_TREE tVal;
}
%token COLON DOT LESSTHAN MORETHAN PLUS MINUS SEMICOLON COMMA POINTER BRA KET LESSOREQUAL MOREOREQUAL SHEVRONS APOSTROPHE TIMES DIVIDE EQUALS ENDPROGRAM DECLARATIONS CODE OF TYPEVAR IF THEN ENDIF ELSE DO WHILE ENDDO FOR IS BY TO ENDFOR ENDWHILE WRITE NEWLINE READ NOT AND OR REALTYPE CHARACTER CHARACTERTYPE INTEGERTYPE
%token<iVal> IDENTIFIER NUMBER
%type<tVal> program block declaration_block identifier_list real statement_list statement assignment_statement if_statement do_statement for_statement while_statement write_statement output_list read_statement conditional comparator expression term value constant number_constant type
%%
program : IDENTIFIER COLON block ENDPROGRAM IDENTIFIER DOT
			{
				TERNARY_TREE ParseTree;
				ParseTree= create_node(NOTHING,PROGRAM,$3,NULL,NULL);
				#ifdef DEBUG
				PrintTree(ParseTree);
				#endif
			}
	;
block : DECLARATIONS declaration_block CODE statement_list
		{
			$$=create_node(NOTHING,BLOCK,$2,$4,NULL);
		}
		| CODE statement_list
		{
			$$=create_node(NOTHING,BLOCK,$2,NULL,NULL);
		}
	;
declaration_block : identifier_list OF TYPEVAR type SEMICOLON
					{
						$$=create_node(NOTHING,DECLARATION_BLOCK,$1,$4,NULL);
					}
					| declaration_block identifier_list OF TYPEVAR type SEMICOLON
					{
						$$=create_node(NOTHING,DECLARATION_BLOCK,$1,$2,$5);
					}
	;
identifier_list : IDENTIFIER
				{
					$$=create_node(NOTHING,IDENTIFIER_LIST,NULL,NULL,NULL);
				}
				| IDENTIFIER COMMA identifier_list
				{
					$$=create_node(NOTHING,IDENTIFIER_LIST,$3,NULL,NULL);
				}
	;
real : NUMBER DOT NUMBER
		{
			$$=create_node(POSITIVE_REAL,REAL,NULL,NULL,NULL);
		}
		| MINUS NUMBER DOT NUMBER
		{
			$$=create_node(NEGATIVE_REAL,REAL,NULL,NULL,NULL);
		}
	;
statement_list : statement
		{
			$$=create_node(NOTHING,STATEMENT_LIST,$1,NULL,NULL);
		}
| statement_list SEMICOLON statement
		{
			$$=create_node(NOTHING,STATEMENT_LIST,$1,$3,NULL);
		}
	;
statement : assignment_statement
		{
			$$=create_node(ASSIGNMENT_STATEMENT,STATEMENT,$1,NULL,NULL);
		}
| if_statement
		{
			$$=create_node(IF_STATEMENT,STATEMENT,$1,NULL,NULL);
		}
| do_statement
		{
			$$=create_node(DO_STATEMENT,STATEMENT,$1,NULL,NULL);
		}
| while_statement
		{
			$$=create_node(WHILE_STATEMENT,STATEMENT,$1,NULL,NULL);
		}
| for_statement
		{
			$$=create_node(FOR_STATEMENT,STATEMENT,$1,NULL,NULL);
		}
| write_statement
		{
			$$=create_node(WRITE_STATEMENT,STATEMENT,$1,NULL,NULL);
		}
| read_statement
		{
			$$=create_node(READ_STATEMENT,STATEMENT,$1,NULL,NULL);
		}
	;
assignment_statement : expression POINTER IDENTIFIER
		{
			$$=create_node(NOTHING,ASSIGNMENT_STATEMENT,$1,NULL,NULL);
		}
	;
if_statement : IF conditional THEN statement_list ENDIF
		{
			$$=create_node(NOTHING,IF_STATEMENT,$2,$4,NULL);
		}
| IF conditional THEN statement_list ELSE statement_list ENDIF
		{
			$$=create_node(NOTHING,IF_STATEMENT,$2,$4,$6);
		}
	;
do_statement : DO statement_list WHILE conditional ENDDO
		{
			$$=create_node(NOTHING,DO_STATEMENT,$2,$4,NULL);
		}
	;
for_statement : FOR IDENTIFIER IS expression BY expression TO expression DO statement_list ENDFOR
		{
			$$=create_node(NOTHING,FOR_STATEMENT,create_node(NOTHING,FOR_STATEMENT,$4,$6,$8),$10,NULL);
		}
	;
while_statement : WHILE conditional DO statement_list ENDWHILE
		{
			$$=create_node(NOTHING,WHILE_STATEMENT,$2,$4,NULL);
		}
	;
write_statement : WRITE BRA output_list KET
		{
			$$=create_node(NOTHING,WRITE_STATEMENT,$3,NULL,NULL);
		}
| NEWLINE
		{
			$$=create_node(NOTHING,WRITE_STATEMENT,NULL,NULL,NULL);
		}
	;
output_list : value
		{
			$$=create_node(NOTHING,OUTPUT_LIST,$1,NULL,NULL);
		}
| output_list COMMA value
		{
			$$=create_node(NOTHING,OUTPUT_LIST,$1,$3,NULL);
		}
	;
read_statement : READ BRA IDENTIFIER KET
		{
			$$=create_node(NOTHING,READ_STATEMENT,NULL,NULL,NULL);
		}
	;
conditional : expression comparator expression
		{
			$$=create_node(DEFAULT_CONDITIONAL,CONDITIONAL,$1,$2,$3);
		}
| NOT conditional
		{
			$$=create_node(NOT,CONDITIONAL,$2,NULL,NULL);
		}
| expression comparator expression AND conditional
		{
			$$=create_node(AND,CONDITIONAL,create_node(AND,CONDITIONAL,$1,$2,$3),$5,NULL);
		}
| expression comparator expression OR conditional
		{
			$$=create_node(OR,CONDITIONAL,create_node(OR,CONDITIONAL,$1,$2,$3),$5,NULL);
		}
	;
comparator : EQUALS
		{
			$$=create_node(EQUALS,COMPARATOR,NULL,NULL,NULL);
		}
| SHEVRONS
		{
			$$=create_node(SHEVRONS,COMPARATOR,NULL,NULL,NULL);
		}
| LESSTHAN
		{
			$$=create_node(LESSTHAN,COMPARATOR,NULL,NULL,NULL);
		}
| MORETHAN
		{
			$$=create_node(MORETHAN,COMPARATOR,NULL,NULL,NULL);
		}
| LESSOREQUAL
		{
			$$=create_node(LESSOREQUAL,COMPARATOR,NULL,NULL,NULL);
		}
| MOREOREQUAL
		{
			$$=create_node(MOREOREQUAL,COMPARATOR,NULL,NULL,NULL);
		}
	;
expression : term
		{
			$$=create_node(DEFAULT_EXPRESSION,EXPRESSION,$1,NULL,NULL);
		}
| term PLUS expression
		{
			$$=create_node(EXPRESSION_PLUS,EXPRESSION,$1,$3,NULL);
		}
| term MINUS expression
		{
			$$=create_node(EXPRESSION_MINUS,EXPRESSION,$1,$3,NULL);
		}
	;
term : value
		{
			$$=create_node(DEFAULT_TERM,TERM,$1,NULL,NULL);
		}
| value TIMES term
		{
			$$=create_node(TIMES_TERM,TERM,$1,$3,NULL);
		}
| value DIVIDE term
		{
			$$=create_node(DIVIDE_TERM,TERM,$1,$3,NULL);
		}
	;
value : IDENTIFIER
		{
			$$=create_node(NOTHING,VALUE,NULL,NULL,NULL);
		}
| constant
		{
			$$=create_node(NOTHING,VALUE,$1,NULL,NULL);
		}
| BRA expression KET
		{
			$$=create_node(NOTHING,VALUE,$2,NULL,NULL);
		}
	;
constant : number_constant
		{
			$$=create_node(NOTHING,CONSTANT,$1,NULL,NULL);
		}
| CHARACTER
		{
			$$=create_node(NOTHING,CONSTANT,NULL,NULL,NULL);
		}
	;
number_constant : NUMBER
		{
			$$=create_node(NORMAL_NUMBER,NUMBER_CONSTANT,NULL,NULL,NULL);
		}
| MINUS NUMBER
		{
			$$=create_node(NEGATIVE_NUMBER,NUMBER_CONSTANT,NULL,NULL,NULL);
		}
| real
		{
			$$=create_node(REAL_NUMBER,NUMBER_CONSTANT,$1,NULL,NULL);
		}
	;
type : CHARACTERTYPE
		{
			$$=create_node(CHARACTERTYPE,TYPE,NULL,NULL,NULL);
		}
| INTEGERTYPE
		{
			$$=create_node(INTEGERTYPE,TYPE,NULL,NULL,NULL);
		}
| REALTYPE
		{
			$$=create_node(REAL_TYPE,TYPE,NULL,NULL,NULL);
		}
%%
/* Code for routines for managing the Parse Tree */
TERNARY_TREE create_node(int ival, int case_identifier, TERNARY_TREE p1,
			 TERNARY_TREE  p2, TERNARY_TREE  p3)
{
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
    if (t == NULL) { 
	    fprintf(stderr, "create_node:Out of memory: %d %d bytes\n", case_identifier, sizeof(TREE_NODE));
		return(t); 
		} 
    t->item = ival;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;
    return (t);
}

void PrintTree(TERNARY_TREE t)
{
   if (t == NULL) return;
   if(t->item==-1)
   {
   printf("Item: Nothing");
   }
   else{
      printf("Item: %d", t->item);
   }
   printf(" nodeIdentifier: %d", t->nodeIdentifier);
   if(t->first!=NULL)
   {
		printf(" firstChildID: %d",t->first->nodeIdentifier);
   }
   else
   {
		printf(" firstChildID: NULL");
   }
   if(t->second!=NULL)
   {
		printf(" secondChildID: %d",t->second->nodeIdentifier);
   }
   else
   {
		printf(" secondChildID: NULL");
   }
      if(t->third!=NULL)
   {
		printf(" thirdChildID: %d\n",t->third->nodeIdentifier);
   }
   else
   {
		printf(" thirdChildID: NULL\n");
   }
   PrintTree(t->first);
   PrintTree(t->second);
   PrintTree(t->third);
}
#include "lex.yy.c"
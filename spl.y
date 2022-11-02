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

  enum ParseTreeNodeType { PROGRAM, BLOCK, DECLARATION_BLOCK, IDENTIFIER_LIST, REAL, STATEMENT_LIST, STATEMENT,
  ASSIGNMENT_STATEMENT, IF_STATEMENT, DO_STATEMENT, FOR_STATEMENT, WHILE_STATEMENT, WRITE_STATEMENT, OUTPUT_LIST, READ_STATEMENT, CONDITIONAL, COMPARATOR,
  EXPRESSION, TERM, VALUE, CONSTANT, NUMBER_CONSTANT, TYPE, POSITIVE_REAL, NEGATIVE_REAL, DEFAULT_CONDITIONAL, DEFAULT_EXPRESSION, EXPRESSION_PLUS, EXPRESSION_MINUS,
  DEFAULT_TERM, TIMES_TERM, DIVIDE_TERM, NORMAL_NUMBER, NEGATIVE_NUMBER, REAL_NUMBER, REAL_TYPE,e_EQUALS,e_SHEVRONS,e_LESSTHAN,e_MORETHAN,e_LESSOREQUAL,e_MOREOREQUAL};
  
  const char *ParseTreeValues[]={"PROGRAM", "BLOCK", "DECLARATION_BLOCK", "IDENTIFIER_LIST", "REAL", "STATEMENT_LIST", "STATEMENT",
  "ASSIGNMENT_STATEMENT", "IF_STATEMENT", "DO_STATEMENT", "FOR_STATEMENT", "WHILE_STATEMENT", "WRITE_STATEMENT", "OUTPUT_LIST", "READ_STATEMENT", "CONDITIONAL", "COMPARATOR",
  "EXPRESSION", "TERM", "VALUE", "CONSTANT", "NUMBER_CONSTANT", "TYPE", "POSITIVE_REAL", "NEGATIVE_REAL", "DEFAULT_CONDITIONAL", "DEFAULT_EXPRESSION", "EXPRESSION_PLUS", "EXPRESSION_MINUS",
  "DEFAULT_TERM", "TIMES_TERM", "DIVIDE_TERM", "NORMAL_NUMBER", "NEGATIVE_NUMBER", "REAL_NUMBER", "REAL_TYPE","e_EQUALS","e_SHEVRONS","e_LESSTHAN","e_MORETHAN","e_LESSOREQUAL","e_MOREOREQUAL"};

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
#ifdef DEBUG
void PrintTree(TERNARY_TREE,int);
#endif
void GenerateCode(TERNARY_TREE);
/* ------------- symbol table definition --------------------------- */

struct symTabNode {
    char identifier[IDLENGTH];
	int number[IDLENGTH];
	char comparator[IDLENGTH];
	char type[IDLENGTH];
	char value[IDLENGTH];
	char operator[IDLENGTH];
	char character[IDLENGTH];
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
%token COLON DOT LESSTHAN MORETHAN PLUS MINUS SEMICOLON COMMA POINTER BRA KET LESSOREQUAL MOREOREQUAL
	SHEVRONS APOSTROPHE TIMES DIVIDE EQUALS ENDPROGRAM DECLARATIONS CODE OF TYPEVAR IF THEN ENDIF ELSE DO WHILE ENDDO
	FOR IS BY TO ENDFOR ENDWHILE WRITE NEWLINE READ NOT AND OR REALTYPE CHARACTERTYPE INTEGERTYPE

%token<iVal> IDENTIFIER NUMBER CHARACTER

%type<tVal> program block declaration_block identifier_list real statement_list statement assignment_statement
	if_statement do_statement for_statement while_statement write_statement
	output_list read_statement conditional comparator expression term value constant number_constant type
%%
program : IDENTIFIER COLON block ENDPROGRAM IDENTIFIER DOT
			{
				TERNARY_TREE ParseTree;
				if($1==$5)
				{
					ParseTree= create_node($1,PROGRAM,$3,NULL,NULL);
					#ifdef DEBUG
					PrintTree(ParseTree,0);
					#endif
					GenerateCode(ParseTree);
				}
				else
				{
					fprintf(stderr,"Program IDENTIFIER is not called at the start and end of the program!");
				}
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
					$$=create_node($1,IDENTIFIER_LIST,NULL,NULL,NULL);
				}
				| identifier_list COMMA IDENTIFIER
				{
					$$=create_node($3,IDENTIFIER_LIST,$1,NULL,NULL);
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
			$$=create_node($3,ASSIGNMENT_STATEMENT,$1,NULL,NULL);
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
			$$=create_node(NOTHING,FOR_STATEMENT,create_node($2,FOR_STATEMENT,$4,$6,$8),$10,NULL);
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
			$$=create_node($3,READ_STATEMENT,NULL,NULL,NULL);
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
			$$=create_node(e_EQUALS,COMPARATOR,NULL,NULL,NULL);
		}
| SHEVRONS
		{
			$$=create_node(e_SHEVRONS,COMPARATOR,NULL,NULL,NULL);
		}
| LESSTHAN
		{
			$$=create_node(e_LESSTHAN,COMPARATOR,NULL,NULL,NULL);
		}
| MORETHAN
		{
			$$=create_node(e_MORETHAN,COMPARATOR,NULL,NULL,NULL);
		}
| LESSOREQUAL
		{
			$$=create_node(e_LESSOREQUAL,COMPARATOR,NULL,NULL,NULL);
		}
| MOREOREQUAL
		{
			$$=create_node(e_MOREOREQUAL,COMPARATOR,NULL,NULL,NULL);
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
			$$=create_node($1,VALUE,NULL,NULL,NULL);
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
#ifdef DEBUG
void PrintTree(TERNARY_TREE t,int pIndent)
{
   if (t == NULL) return;
   for(int i=0;i<pIndent; i++)
   {
		printf(" ");
   }
      printf("nodeID:%s",ParseTreeValues[t->nodeIdentifier]);
   if(t->item!=NOTHING){
      printf(" Item_Name:%s", ParseTreeValues[t->item]);
   }
   printf("\n");
   pIndent++;
   PrintTree(t->first,pIndent);
   PrintTree(t->second,pIndent);
   PrintTree(t->third,pIndent);
}
#endif
void GenerateCode(TERNARY_TREE t)
{
	if(t==NULL) return;
	switch(t->nodeIdentifier)
	{
		case(PROGRAM):
			printf("int main(void) {\n");
			GenerateCode(t->first);
			printf("}\n");
			return;
		case(BLOCK):
			GenerateCode(t->first);
			printf(";\n");
			GenerateCode(t->second);
			return;
		case(DECLARATION_BLOCK):
			GenerateCode(t->first);
			printf("OF TYPE");
			GenerateCode(t->second);
			printf(";");
			return;
		case(IDENTIFIER_LIST):
			GenerateCode(t->first);
			printf(",");
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s", symTab[t->item]->identifier);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			return;
		case(REAL):
			GenerateCode(t->first);
			return;
		case(STATEMENT_LIST):
			GenerateCode(t->first);
			printf(";");
			GenerateCode(t->second);
			return;
		case(STATEMENT):
			GenerateCode(t->first);
			return;
		case(ASSIGNMENT_STATEMENT):
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s", symTab[t->item]->identifier);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			printf(" = ");
			GenerateCode(t->first);
			return;
		case(IF_STATEMENT):
			printf("if (");
			GenerateCode(t->first);
			printf(") {\n");
			GenerateCode(t->second);
			printf("}\n");
			return;
		case(DO_STATEMENT):
			printf("do {\n");
			GenerateCode(t->first);
			printf("} while (");
			GenerateCode(t->second);
			printf(")");
			return;
		case(FOR_STATEMENT):
			printf("for (");
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s", symTab[t->item]->type);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			printf(" ");
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s", symTab[t->item]->identifier);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			printf("=");
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s", symTab[t->item]->value);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			printf(";");
			GenerateCode(t->first->first);
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s", symTab[t->item]->comparator);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			GenerateCode(t->first->second);
			printf(";");
			GenerateCode(t->first->third);
			printf("){\n");
			GenerateCode(t->second);
			printf("\n}");
			return;
		case(WHILE_STATEMENT):
			printf("while (");
			GenerateCode(t->first);
			printf(") {\n");
			GenerateCode(t->second);
			printf("}\n");
			return;
		case(WRITE_STATEMENT):
			printf("printf(");
			GenerateCode(t->first);
			printf(")");
			return;
		case(OUTPUT_LIST):
			GenerateCode(t->first);
			printf(",");
			GenerateCode(t->second);
			return;
		case(READ_STATEMENT):
			printf("scanf(\"%s\",");
			GenerateCode(t->first);
			printf(")");
			return;
		case(CONDITIONAL):
			GenerateCode(t->first);
			GenerateCode(t->second);
			GenerateCode(t->third);
			return;
		case(COMPARATOR):
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s",symTab[t->item]->comparator);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			return;
		case(EXPRESSION):
			GenerateCode(t->first);
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s",symTab[t->item]->operator);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			GenerateCode(t->second);
			return;
		case(TERM):
			GenerateCode(t->first);
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s",symTab[t->item]->operator);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			GenerateCode(t->second);
			return;
		case(VALUE):
			GenerateCode(t->first);
			return;
		case(CONSTANT):
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s",symTab[t->item]->character);
			}
			else
			{
				GenerateCode(t->first);
			}
			return;
		case(NUMBER_CONSTANT):
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%d",symTab[t->item]->number);
			}
			else
			{
				GenerateCode(t->first);
			}
			return;
		case(TYPE):
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s",symTab[t->item]->type);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			return;
	}
	GenerateCode(t->first);
	GenerateCode(t->second);
	GenerateCode(t->third);
}
#include "lex.yy.c"
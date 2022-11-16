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
  enum ParseTreeNodeType {e_PROGRAM, e_BLOCK, e_DECLARATION_BLOCK, e_IDENTIFIER_LIST, e_STATEMENT_LIST, e_STATEMENT,
  e_ASSIGNMENT_STATEMENT, e_IF_STATEMENT, e_DO_STATEMENT, e_FOR_STATEMENT, e_WHILE_STATEMENT, e_WRITE_STATEMENT, e_OUTPUT_LIST, e_READ_STATEMENT, e_CONDITIONAL,
  e_EXPRESSION, e_TERM, e_NUMBER_CONSTANT, e_NEGATIVE_REAL, e_DEFAULT_EXPRESSION, e_EXPRESSION_PLUS, e_EXPRESSION_MINUS,
  e_TIMES_TERM, e_DIVIDE_TERM, e_REALTYPE,e_EQUALS,e_SHEVRONS,e_LESSTHAN,e_MORETHAN,e_LESSOREQUAL,e_MOREOREQUAL,e_CHARACTER_CONSTANT,e_NEWLINE_WRITE_STATEMENT,
  e_INTEGERTYPE,e_CHARACTERTYPE,e_IF_ELSE_STATEMENT,e_NOT_CONDITION,e_AND_CONDITIONAL,e_OR_CONDITIONAL,e_IDENTIFIER_VALUE,e_CONSTANT_VALUE,e_EXPRESSION_VALUE,
  e_DECLARATION_BLOCK_EXTEND,e_IDENTIFIER_LIST_EXTEND,e_REAL,e_NEGATIVE_NUMBER_CONSTANT};
  const char *ParseTreeValues[]={"PROGRAM", "BLOCK", "DECLARATION_BLOCK", "IDENTIFIER_LIST", "STATEMENT_LIST", "STATEMENT",
  "ASSIGNMENT_STATEMENT", "IF_STATEMENT", "DO_STATEMENT", "FOR_STATEMENT", "WHILE_STATEMENT", "WRITE_STATEMENT", "OUTPUT_LIST", "READ_STATEMENT", "CONDITIONAL",
  "EXPRESSION", "TERM", "NUMBER_CONSTANT", "NEGATIVE_REAL", "DEFAULT_EXPRESSION", "EXPRESSION_PLUS", "EXPRESSION_MINUS",
  "TIMES_TERM", "DIVIDE_TERM", "REALTYPE","EQUALS","SHEVRONS","LESSTHAN","MORETHAN","LESSOREQUAL","MOREOREQUAL","CHARACTER_CONSTANT","NEWLINE_WRITE_STATEMENT",
  "INTEGERTYPE","CHARACTERTYPE","IF_ELSE_STATEMENT","NOT_CONDITION","AND_CONDITIONAL","OR_CONDITIONAL","IDENTIFIER_VALUE","CONSTANT_VALUE","EXPRESSION_VALUE",
  "DECLARATION_BLOCK_EXTEND","IDENTIFIER_LIST_EXTEND","REAL","NEGATIVE_NUMBER_CONSTANT"};
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
#ifndef DEBUG
void GenerateCode(TERNARY_TREE,int);
void GetIdentifier(TERNARY_TREE);
void createIndent(int);
void loopIdentifier(TERNARY_TREE,int);
void handleError(char*);
#endif
/* ------------- symbol table definition --------------------------- */
struct symTabNode {
    char identifier[IDLENGTH];
	int variableType;
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
/*create tokens needed for program operation*/
%token COLON DOT LESSTHAN MORETHAN PLUS MINUS SEMICOLON COMMA POINTER BRA KET LESSOREQUAL MOREOREQUAL
	SHEVRONS APOSTROPHE TIMES DIVIDE EQUALS ENDPROGRAM DECLARATIONS CODE OF TYPEVAR IF THEN ENDIF ELSE DO WHILE ENDDO
	FOR IS BY TO ENDFOR ENDWHILE WRITE NEWLINE READ NOT AND OR

%token<iVal> IDENTIFIER NUMBER CHARACTER_ACTUAL DECIMAL_NUMBER INTEGERTYPE REALTYPE CHARACTERTYPE

%type<tVal> program block declaration_block identifier_list statement_list statement assignment_statement
	if_statement do_statement for_statement while_statement write_statement
	output_list read_statement conditional comparator expression term value constant type
/*create conditions and nodes of tree for each command that can be entered*/
%%
program : IDENTIFIER COLON block ENDPROGRAM IDENTIFIER DOT
		{
			/*Begins the parse tree and if in debug mode prints the tree if not generates code ensures identifiers are connsistent*/
			/*Each definition after this defines a node that is added to this tree*/
			TERNARY_TREE ParseTree;
			if($1==$5)
			{
				ParseTree= create_node($1,e_PROGRAM,$3,NULL,NULL);
				#ifdef DEBUG
				PrintTree(ParseTree,0);
				#endif
				#ifndef DEBUG
				GenerateCode(ParseTree,0);
				#endif
			}
			else
			{
				handleError("Program IDENTIFIER is not called at the start and end of the program!");
			}
		}
	;
block : DECLARATIONS declaration_block CODE statement_list
		{
			$$=create_node(NOTHING,e_BLOCK,$2,$4,NULL);
		}
		| CODE statement_list
		{
			$$=create_node(NOTHING,e_BLOCK,$2,NULL,NULL);
		}
	;
declaration_block : identifier_list OF TYPEVAR type SEMICOLON
		{
			$$=create_node(NOTHING,e_DECLARATION_BLOCK,NULL,$1,$4);
		}
		| declaration_block identifier_list OF TYPEVAR type SEMICOLON
		{
			$$=create_node(NOTHING,e_DECLARATION_BLOCK,$1,$2,$5);
		}
	;
identifier_list : IDENTIFIER
		{
			$$=create_node($1,e_IDENTIFIER_LIST,NULL,NULL,NULL);
		}
		| identifier_list COMMA IDENTIFIER
		{
			$$=create_node($3,e_IDENTIFIER_LIST_EXTEND,$1,NULL,NULL);
		}
	;
statement_list : statement
		{
			$$=create_node(NOTHING,e_STATEMENT_LIST,$1,NULL,NULL);
		}
		| statement_list SEMICOLON statement
		{
			$$=create_node(NOTHING,e_STATEMENT_LIST,$1,$3,NULL);
		}
	;
statement : assignment_statement
		{
			$$=create_node(e_ASSIGNMENT_STATEMENT,e_STATEMENT,$1,NULL,NULL);
		}
		| if_statement
		{
			$$=create_node(e_IF_STATEMENT,e_STATEMENT,$1,NULL,NULL);
		}
		| do_statement
		{
			$$=create_node(e_DO_STATEMENT,e_STATEMENT,$1,NULL,NULL);
		}
		| while_statement
		{
			$$=create_node(e_WHILE_STATEMENT,e_STATEMENT,$1,NULL,NULL);
		}
		| for_statement
		{
			$$=create_node(e_FOR_STATEMENT,e_STATEMENT,$1,NULL,NULL);
		}
		| write_statement
		{
			$$=create_node(e_WRITE_STATEMENT,e_STATEMENT,$1,NULL,NULL);
		}
		| read_statement
		{
			$$=create_node(e_READ_STATEMENT,e_STATEMENT,$1,NULL,NULL);
		}
	;
assignment_statement : expression POINTER IDENTIFIER
		{
			$$=create_node($3,e_ASSIGNMENT_STATEMENT,$1,NULL,NULL);
		}
	;
if_statement : IF conditional THEN statement_list ENDIF
		{
			$$=create_node(NOTHING,e_IF_STATEMENT,$2,$4,NULL);
		}
		| IF conditional THEN statement_list ELSE statement_list ENDIF
		{
			$$=create_node(NOTHING,e_IF_ELSE_STATEMENT,$2,$4,$6);
		}
	;
do_statement : DO statement_list WHILE conditional ENDDO
		{
			$$=create_node(NOTHING,e_DO_STATEMENT,$2,$4,NULL);
		}
	;
for_statement : FOR IDENTIFIER IS expression BY expression TO expression DO statement_list ENDFOR
		{
			$$=create_node($2,e_FOR_STATEMENT,create_node(NOTHING,e_FOR_STATEMENT,$4,$6,$8),$10,NULL);
		}
	;
while_statement : WHILE conditional DO statement_list ENDWHILE
		{
			$$=create_node(NOTHING,e_WHILE_STATEMENT,$2,$4,NULL);
		}
	;
write_statement : WRITE BRA output_list KET
		{
			$$=create_node(NOTHING,e_WRITE_STATEMENT,$3,NULL,NULL);
		}
		| NEWLINE
		{
			$$=create_node(NOTHING,e_NEWLINE_WRITE_STATEMENT,NULL,NULL,NULL);
		}
	;
output_list : value
		{
			$$=create_node(NOTHING,e_OUTPUT_LIST,$1,NULL,NULL);
		}
		| value COMMA output_list
		{
			$$=create_node(NOTHING,e_OUTPUT_LIST,$1,$3,NULL);
		}
	;
read_statement : READ BRA IDENTIFIER KET
		{
			$$=create_node($3,e_READ_STATEMENT,NULL,NULL,NULL);
		}
	;
conditional : expression comparator expression
		{
			$$=create_node(e_CONDITIONAL,e_CONDITIONAL,$1,$2,$3);
		}
		| NOT conditional
		{
			$$=create_node(e_NOT_CONDITION,e_NOT_CONDITION,$2,NULL,NULL);
		}
		| expression comparator expression AND conditional
		{
			$$=create_node(e_AND_CONDITIONAL,e_AND_CONDITIONAL,create_node(e_AND_CONDITIONAL,e_CONDITIONAL,$1,$2,$3),$5,NULL);
		}
		| expression comparator expression OR conditional
		{
			$$=create_node(e_OR_CONDITIONAL,e_OR_CONDITIONAL,create_node(e_OR_CONDITIONAL,e_CONDITIONAL,$1,$2,$3),$5,NULL);
		}
	;
comparator : EQUALS
		{
			$$=create_node(e_EQUALS,e_EQUALS,NULL,NULL,NULL);
		}
		| SHEVRONS
		{
			$$=create_node(e_SHEVRONS,e_SHEVRONS,NULL,NULL,NULL);
		}
		| LESSTHAN
		{
			$$=create_node(e_LESSTHAN,e_LESSTHAN,NULL,NULL,NULL);
		}
		| MORETHAN
		{
			$$=create_node(e_MORETHAN,e_MORETHAN,NULL,NULL,NULL);
		}
		| LESSOREQUAL
		{
			$$=create_node(e_LESSOREQUAL,e_LESSOREQUAL,NULL,NULL,NULL);
		}
		| MOREOREQUAL
		{
			$$=create_node(e_MOREOREQUAL,e_MOREOREQUAL,NULL,NULL,NULL);
		}
expression : term
		{
			$$=create_node(e_DEFAULT_EXPRESSION,e_EXPRESSION,$1,NULL,NULL);
		}
		| term PLUS expression
		{
			$$=create_node(e_EXPRESSION_PLUS,e_EXPRESSION_PLUS,$1,$3,NULL);
		}
		| term MINUS expression
		{
			$$=create_node(e_EXPRESSION_MINUS,e_EXPRESSION_MINUS,$1,$3,NULL);
		}
	;
term : value
		{
			$$=create_node(e_TERM,e_TERM,$1,NULL,NULL);
		}
		| value TIMES term
		{
			$$=create_node(e_TIMES_TERM,e_TIMES_TERM,$1,$3,NULL);
		}
		| value DIVIDE term
		{
			$$=create_node(e_DIVIDE_TERM,e_DIVIDE_TERM,$1,$3,NULL);
		}
	;
value : IDENTIFIER
		{
			$$=create_node($1,e_CONSTANT_VALUE,NULL,NULL,NULL);
		}
		| constant
		{
			$$=create_node(NOTHING,e_CONSTANT_VALUE,$1,NULL,NULL);
		}
		| BRA expression KET
		{
			$$=create_node(NOTHING,e_EXPRESSION_VALUE,$2,NULL,NULL);
		}
	;
constant : CHARACTER_ACTUAL
		{
			$$=create_node($1,e_CHARACTER_CONSTANT,NULL,NULL,NULL);
		}
		|
		NUMBER
		{
			$$=create_node($1,e_NUMBER_CONSTANT,NULL,NULL,NULL);
		}
		| MINUS NUMBER
		{
			$$=create_node($2,e_NEGATIVE_NUMBER_CONSTANT,NULL,NULL,NULL);
		}
		|DECIMAL_NUMBER
		{
			$$=create_node($1,e_REAL,NULL,NULL,NULL);
		}
		| MINUS DECIMAL_NUMBER
		{
			$$=create_node($2,e_NEGATIVE_REAL,NULL,NULL,NULL);
		}
	;
type : CHARACTERTYPE
		{
			$$=create_node($1,e_CHARACTERTYPE,NULL,NULL,NULL);
		}
		| INTEGERTYPE
		{
			$$=create_node($1,e_INTEGERTYPE,NULL,NULL,NULL);
		}
		| REALTYPE
		{
			$$=create_node($1,e_REALTYPE,NULL,NULL,NULL);
		}
%%
/* Code for routines for managing the Parse Tree */
TERNARY_TREE create_node(int ival, int case_identifier, TERNARY_TREE p1,
			 TERNARY_TREE  p2, TERNARY_TREE  p3)
{
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
    if (t == NULL) 
	{ 
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
/*Code Routine for printing the parse tree if the debug flag is used*/
#ifdef DEBUG
void PrintTree(TERNARY_TREE t,int pIndent)
{
	int index;
	if (t == NULL) return;
	for(index=0; index<pIndent; index++)
	{
		printf(" ");
	}
	printf("nodeID:%s",ParseTreeValues[t->nodeIdentifier]);
   	if(t->item!=NOTHING)
	{
		if(t->nodeIdentifier==e_CHARACTER_CONSTANT)
		{
			printf(" Item_Name:%c",t->item);			
		}
		else
		{
    		printf(" Item_Name:%s", ParseTreeValues[t->item]);
		}
   	}
   	printf("\n");
   	pIndent++;
   	PrintTree(t->first,pIndent);
   	PrintTree(t->second,pIndent);
   	PrintTree(t->third,pIndent);
}
#endif
/*code routine to generate the C code translation of the SPL file*/
#ifndef DEBUG
void GenerateCode(TERNARY_TREE t,int indent)
{
	if(t==NULL) return;
	switch(t->nodeIdentifier)
	{
		case(e_PROGRAM):/*Generates Basic Program shell that is later filled with commands*/
			printf("#include <stdio.h>\n");
			printf("#include <stdlib.h>\n");
			printf("int main(void) \n{\n");
			indent++;
			GenerateCode(t->first,indent);
			indent--;
			printf("}");
			return;
		case(e_BLOCK):/*Recursively Builds the nessassary blocks of code*/
			GenerateCode(t->first,indent);
			GenerateCode(t->second,indent);
			return;
		case(e_DECLARATION_BLOCK):/*Recursively generates all forward declarations and adds types to each variable as the types are viewable at this stage*/
			GenerateCode(t->first,indent);
			GenerateCode(t->third,indent);
			if(t->third->nodeIdentifier==e_INTEGERTYPE)
			{
				symTab[t->third->item]->variableType=e_INTEGERTYPE;
				if(t->second->first!=NULL)
				{
					loopIdentifier(t->second,e_INTEGERTYPE);
				}
			}
			else if(t->third->nodeIdentifier==e_CHARACTERTYPE)
			{
				symTab[t->third->item]->variableType=e_CHARACTERTYPE;
				if(t->second->first!=NULL)
				{
					loopIdentifier(t->second,e_CHARACTERTYPE);
				}
			}
			else if(t->third->nodeIdentifier==e_REALTYPE)
			{
				symTab[t->third->item]->variableType=e_REALTYPE;
				if(t->second->first!=NULL)
				{
					loopIdentifier(t->second,e_REALTYPE);
				}
			}
			printf(" ");
			GenerateCode(t->second,indent);
			printf(";\n");
			return;
		case(e_IDENTIFIER_LIST):/*Retrieves idnentifier*/
			GetIdentifier(t);
			return;
		case(e_IDENTIFIER_LIST_EXTEND):/*Recurses to retrieve further identifier and current identifier*/
			GenerateCode(t->first,indent);
			printf(",");
			GetIdentifier(t);
			return;
		case(e_ASSIGNMENT_STATEMENT):/*generates an assignmet statment as well as adding in '' around the value if it is a character*/
			createIndent(indent);
			GetIdentifier(t);
			printf(" = ");
			if(symTab[t->item]->variableType==e_CHARACTERTYPE)
			{
				printf("'");
				GenerateCode(t->first,indent);
				printf("'");
			}
			else
			{
				GenerateCode(t->first,indent);
			}
			printf(";\n");
			return;
		case(e_IF_STATEMENT):/*generates a simple if statment*/
			createIndent(indent);
			printf("if (");
			GenerateCode(t->first,indent);
			printf(") \n");
			createIndent(indent);
			printf("{\n");
			indent++;
			GenerateCode(t->second,indent);
			indent--;
			createIndent(indent);
			printf("}\n");
			return;
		case(e_IF_ELSE_STATEMENT):/*generates an if statment with an else clause*/
			createIndent(indent);
			printf("if (");
			GenerateCode(t->first,indent);
			printf(") \n");
			createIndent(indent);
			printf("{\n");
			indent++;
			GenerateCode(t->second,indent);
			indent--;
			createIndent(indent);
			printf("}\n");
			createIndent(indent);
			printf("else\n");
			createIndent(indent);
			printf("{\n");
			indent++;
			GenerateCode(t->third,indent);
			indent--;
			createIndent(indent);
			printf("}\n");
			return;
		case(e_DO_STATEMENT):/*generates a do statment*/
			createIndent(indent);
			printf("do \n");
			createIndent(indent);
			printf("{\n");
			indent++;
			GenerateCode(t->first,indent);
			indent--;
			createIndent(indent);
			printf("} while (");
			GenerateCode(t->second,indent);
			printf(");\n");
			return;
		case(e_FOR_STATEMENT):/*generates a for loop that evaluates its condition to decide whether to use a < or > symbol*/
			if(symTab[t->item]->variableType==e_CHARACTERTYPE)
			{
				handleError("Character cannot be used as loop iterator must be int!");
			}
			createIndent(indent);
            printf("for (");
            GetIdentifier(t);
            printf("=");
            GenerateCode(t->first->first, indent);
            printf(";");
            printf("(");
            GetIdentifier(t);
            printf("-(");
            GenerateCode(t->first->third, indent);
            printf(")");
            printf(")*((");
            GenerateCode(t->first->second, indent);
            printf(">0)-(");
            GenerateCode(t->first->second, indent);
            printf("<0))<=0; ");
            GetIdentifier(t);
            printf(" += ");
            GenerateCode(t->first->second, indent);
            printf(")\n");
            createIndent(indent);
            printf("{\n");
            indent++;
            GenerateCode(t->second, indent);
            indent--;
            createIndent(indent);
            printf("}\n");
            return;
		case(e_WHILE_STATEMENT):/*Generates a while loop*/
			createIndent(indent);
			printf("while (");
			GenerateCode(t->first,indent);
			printf(") \n");
			createIndent(indent);
			printf("{\n");
			indent++;
			GenerateCode(t->second,indent);
			indent--;
			createIndent(indent);
			printf("}\n");
			return;
		case(e_WRITE_STATEMENT):/*Generates a write statment that dynamically changes its % value*/
			createIndent(indent);
			printf("printf(\"");
			
			if(t->first->first->nodeIdentifier==e_EXPRESSION_VALUE)
			{
				printf("%%d\",");
				GenerateCode(t->first,indent);
				printf(");\n");	
			}
			else if(t->first->first->nodeIdentifier == e_CONSTANT_VALUE && t->first->first->first == NULL)
            {
                if(t->first->first->item != NOTHING)
                {
                    if(symTab[t->first->first->item]->variableType == e_INTEGERTYPE)
                    {
                        printf("%%d\",");
                        GenerateCode(t->first, indent);
                        printf(");");
                        printf("\n");
                    }
                    else if(symTab[t->first->first->item]->variableType == e_CHARACTERTYPE)
                    {
                        printf("%%c\",");
                        GenerateCode(t->first, indent);
                        printf(");");
                        printf("\n");
                    }
                    else if(symTab[t->first->first->item]->variableType == e_REALTYPE)
                    {
                        printf("%%.2f\",");
                        GenerateCode(t->first, indent);
                        printf(");");
                        printf("\n");
                    }
                    else
                    {
                        printf("%%s\",");
                        GenerateCode(t->first, indent);
                        printf(");");
                        printf("\n");
                    }
                }
                else
                {
                    printf("%%s\",");
                    GenerateCode(t->first, indent);
                    printf(");");
                    printf("\n");
                }
            }
            else
            {
                GenerateCode(t->first, indent);
                printf("\");");
                printf("\n");
            }
			return;
		case(e_NEWLINE_WRITE_STATEMENT):/*Generates a newline write statment*/
			createIndent(indent);
			printf("printf(\"\\n\");\n"); 
			return;
		case(e_CONDITIONAL):/*Generates a conditional statment*/
			printf("(");
			GenerateCode(t->first,indent);
			GenerateCode(t->second,indent);
			GenerateCode(t->third,indent);
			printf(")");
			return;
		case(e_READ_STATEMENT):/*generates a read statment that dynamically changes its type*/
			createIndent(indent);
			if(symTab[t->item]->variableType==e_INTEGERTYPE)
			{
				printf("scanf(\"%%d\",&");
			}
			else if(symTab[t->item]->variableType==e_REALTYPE)
			{
				printf("scanf(\"%%f\",&");
			}
			else if(symTab[t->item]->variableType==e_CHARACTERTYPE)
			{
				printf("scanf(\" %%c\",&");
			}
			else
			{
				printf("scanf(\"%%s\",&");
			}
			GetIdentifier(t);
			printf(");\n");
			return;
		case(e_NOT_CONDITION):/*Generates a Not Condition*/
			printf("!");
			GenerateCode(t->first,indent);
			return;
		case(e_AND_CONDITIONAL):/*Generates an and condition*/
			GenerateCode(t->first,indent);
			printf(" && ");
			GenerateCode(t->second,indent);
			return;
		case(e_OR_CONDITIONAL):/*Generates an or condition*/
			GenerateCode(t->first,indent);
			printf(" || ");
			GenerateCode(t->second,indent);
			return;
		case(e_EQUALS):/*Generates an equal to condition*/
			printf(" == ");
			return;
		case(e_SHEVRONS):/*Generates a not equal condition*/
			printf(" != ");
			return;
		case(e_LESSTHAN):/*Generates a less than condition*/
			printf(" < ");
			return;
		case(e_MORETHAN):/*Generates a more than condition*/
			printf(" > ");
			return;
		case(e_LESSOREQUAL):/*Generates a less than or equal to condition*/
			printf(" <= ");
			return;
		case(e_MOREOREQUAL):/*Generates a more than or equal to condition*/
			printf(" >= ");
			return;
		case(e_EXPRESSION_PLUS):/*Generates an addition expression*/
			GenerateCode(t->first,indent);
			printf(" + ");
			GenerateCode(t->second,indent);
			return;
		case(e_EXPRESSION_MINUS):/*Generates a minus expression condition*/
			GenerateCode(t->first,indent);
			printf(" - ");
			GenerateCode(t->second,indent);
			return;
		case(e_TIMES_TERM):/*Generates a times expression*/
			GenerateCode(t->first,indent);
			printf(" * ");
			GenerateCode(t->second,indent);
			return;
		case(e_DIVIDE_TERM):/*Generates a divide expression*/
			GenerateCode(t->first,indent);
			printf(" / ");
			GenerateCode(t->second,indent);
			return;
		case(e_CONSTANT_VALUE):/*Generates a constant value based on its first child*/
			if(t->first==NULL)
			{
				GetIdentifier(t);
			}
			else
			{
				GenerateCode(t->first,indent);
			}
			return;
		case(e_EXPRESSION_VALUE):/*generates an expression*/
			printf("(");
			GenerateCode(t->first,indent);
			printf(")");
			return;
		case(e_CHARACTER_CONSTANT):/*Generates a character constant*/
			printf("%c",t->item);
			return;
		case(e_NEGATIVE_NUMBER_CONSTANT):/*Generates a negative number constant*/
			printf("-");
		case(e_NUMBER_CONSTANT):/*Generates a number constant*/
			printf("%d",t->item);
			return;
		case(e_NEGATIVE_REAL):/*Generates a negative decimal*/
			printf("-");
		case(e_REAL):/*Generates a decimal*/
			GetIdentifier(t);
			return;
		case(e_CHARACTERTYPE):/*Generates a character type*/
			createIndent(indent);
			printf("char");
			return;
		case(e_INTEGERTYPE):/*Generates a integer type*/
			createIndent(indent);
			printf("int");
			return;
		case (e_REALTYPE):/*Generates a decimal type*/
			createIndent(indent);
			printf("float");
			return;
	}
	GenerateCode(t->first,indent);/*if any statments only generate children they are handled here rather than having their own case to save writting unnessasary lines of code*/
	GenerateCode(t->second,indent);
	GenerateCode(t->third,indent);
}
/*Gets the identifier from the symbol table*/
void GetIdentifier(TERNARY_TREE t)
{
	if(t->item>=0 && t->item<SYMTABSIZE)
	{
		printf("%s",symTab[t->item]->identifier);
	}
	else
	{
		printf("UnknownIdentifier: %d",t->item);
	}
}
/*Creates the indentation of the code as it is needed*/
void createIndent(int indent)
{
	int index;
	for(index=0;index<indent;index++)
	{
		printf("    ");
	}
}/*Loops through the identifier list to apply types to each identifier*/
void loopIdentifier(TERNARY_TREE t,int identifier)
{
	if (t->first==NULL) return;
	else
	{
		if(identifier==e_INTEGERTYPE)
		{
			symTab[t->first->item]->variableType=e_INTEGERTYPE;
		}
		else if(identifier==e_CHARACTERTYPE)
		{
			symTab[t->first->item]->variableType=e_CHARACTERTYPE;
		}
		else if(identifier==e_REALTYPE)
		{
			symTab[t->first->item]->variableType=e_REALTYPE;
		}
		loopIdentifier(t->first,identifier);
	}	
}
void handleError(char *errorMessage)
{
	fprintf(stderr,"\nError Occured: %s",errorMessage);
	exit(0);
}
#endif
#include "lex.yy.c"
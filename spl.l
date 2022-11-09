delim [\t\r\n" "]
ws {delim}+
digit [0-9]
number {digit}+
letter [A-Za-z]
character_actual "'"{letter}"'"
decimal [.]
decimal_number {number}"."{number}
negative_decimal_number "-"{number}"."{number}
negative_number "-"{number}
identifier {letter}({letter}|{number})*
%{
#ifdef PRINT
#define TOKEN(t) printf("Token: " #t "\n");
#define NUMBER_TOKEN(t) printf("Number %d Token: " #t "\n",yytext);
#define NEGATIVE_NUMBER_TOKEN(t) printf("Negative Number %d Token: " #t "\n",yytext);
#define DECIMAL_TOKEN(t) printf("decimal %d Token: " #t "\n",yytext);
#define NEGATIVE_DECIMAL_TOKEN(t) printf("Negative decimal %d Token: " #t "\n",yytext);
#define CHARACTER_TOKEN(t) printf("Character %c Token: " #t "\n", yytext);
#define IDENTIFIER_TOKEN(t) printf("Identifier %s Token: " #t "\n", yytext);
#else
#define TOKEN(t) return(t);
#define NUMBER_TOKEN(t) yylval.iVal = installId(yytext); return(t);
#define NEGATIVE_NUMBER_TOKEN(t) yylval.iVal = installId(yytext); return(t);
#define DECIMAL_TOKEN(t) yylval.iVal = installId(yytext); return(t);
#define NEGATIVE_DECIMAL_TOKEN(t) yylval.iVal = installId(yytext); return(t);
#define CHARACTER_TOKEN(t) yylval.iVal = installId(yytext); return(t);
#define IDENTIFIER_TOKEN(t) yylval.iVal = installId(yytext); return(t);
#endif
#ifndef PRINT
#include <string.h>
extern SYMTABNODEPTR symTab[SYMTABSIZE];
extern int currentSymTabSize;
int installId(char*);
#endif
%}

%%

{ws} ;
":"  TOKEN(COLON)
"."  TOKEN(DOT)
"<"  TOKEN(LESSTHAN)
">"  TOKEN(MORETHAN)
"+"  TOKEN(PLUS)
"-"  TOKEN(MINUS)
";"  TOKEN(SEMICOLON)
","  TOKEN(COMMA)
"->" TOKEN(POINTER)
"(" TOKEN(BRA)
")" TOKEN(KET)
"<=" TOKEN(LESSOREQUAL)
">=" TOKEN(MOREOREQUAL)
"<>" TOKEN(SHEVRONS)
"'" TOKEN(APOSTROPHE)
"*" TOKEN(TIMES)
"/" TOKEN(DIVIDE)
"=" TOKEN(EQUALS)
ENDP TOKEN(ENDPROGRAM)
DECLARATIONS TOKEN(DECLARATIONS)
CODE TOKEN(CODE)
OF TOKEN(OF)
TYPE TOKEN(TYPEVAR)
IF TOKEN(IF)
THEN TOKEN(THEN)
ENDIF TOKEN(ENDIF)
ELSE TOKEN(ELSE)
DO TOKEN(DO)
WHILE TOKEN(WHILE)
ENDDO TOKEN(ENDDO)
FOR TOKEN(FOR)
IS TOKEN (IS)
BY TOKEN(BY)
TO TOKEN(TO)
ENDFOR TOKEN(ENDFOR)
ENDWHILE TOKEN(ENDWHILE)
WRITE TOKEN(WRITE)
NEWLINE TOKEN(NEWLINE)
READ TOKEN(READ)
NOT TOKEN(NOT)
AND TOKEN(AND)
OR TOKEN(OR)
REAL TOKEN(REALTYPE)
CHARACTER TOKEN(CHARACTERTYPE)
INTEGER TOKEN (INTEGERTYPE)
{identifier} IDENTIFIER_TOKEN(IDENTIFIER)
{character_actual} CHARACTER_TOKEN(CHARACTER_ACTUAL)
{negative_decimal_number} NEGATIVE_DECIMAL_TOKEN(NEGATIVE_DECIMAL_NUMBER)
{decimal_number} DECIMAL_TOKEN(DECIMAL_NUMBER)
{negative_number} NEGATIVE_NUMBER_TOKEN(NEGATIVE_NUMBER)
{number} NUMBER_TOKEN(NUMBER)
 
%%
#ifndef PRINT
/* Here is the code for the library of symbol table routines */

/* code for a simple symbol table, which is an array of pointers to
   structs, each of which contains an identifier.
*/


SYMTABNODEPTR newSymTabNode()
{
    return ((SYMTABNODEPTR)malloc(sizeof(SYMTABNODE)));
}

int lookup(char *s)
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE];
    extern int currentSymTabSize;
    int i;

    for(i=0; i<currentSymTabSize; i++)
    {
        if(strncmp(s,symTab[i]->identifier,IDLENGTH) == 0)
        {
            return (i);
        }
    }
    return (-1);    
}

/* Look up an identifier in the symbol table, if its there return
   its index.  If its not there, put it in the end position,
   as long as the table isn't full, and return its index.
*/

int installId(char *id) 
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE]; 
    extern int currentSymTabSize;
    int index;

    index = lookup(id);
    if (index >= 0)
    {
        return (index);
    }
    else 
       if (currentSymTabSize >= SYMTABSIZE) 
          /* SYMTAB is full */
          return (NOTHING) ;
    else
    {
       symTab[currentSymTabSize] = newSymTabNode();
	   if (symTab[currentSymTabSize] == NULL) { 
	      fprintf(stderr, "installId:Out of memory: %s %d\n", id, (int)sizeof(SYMTABNODEPTR)); 
		  return(NOTHING);
		  }
       /* Recommended code for preventing buffer overrun on bounded strings */
       strncpy(symTab[currentSymTabSize]->identifier,id,IDLENGTH);
       symTab[currentSymTabSize]->identifier[IDLENGTH-1] = '\0';
       return(currentSymTabSize++);
    }
}
#endif
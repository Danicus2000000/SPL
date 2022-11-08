
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "spl.y"

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

  enum ParseTreeNodeType {e_PROGRAM, e_BLOCK, e_DECLARATION_BLOCK, e_IDENTIFIER_LIST, e_REAL, e_STATEMENT_LIST, e_STATEMENT,
  e_ASSIGNMENT_STATEMENT, e_IF_STATEMENT, e_DO_STATEMENT, e_FOR_STATEMENT, e_WHILE_STATEMENT, e_WRITE_STATEMENT, e_OUTPUT_LIST, e_READ_STATEMENT, e_CONDITIONAL, e_COMPARATOR,
  e_EXPRESSION, e_TERM, e_VALUE, e_CONSTANT, e_NUMBER_CONSTANT, e_TYPE, e_POSITIVE_REAL, e_NEGATIVE_REAL, e_DEFAULT_CONDITIONAL, e_DEFAULT_EXPRESSION, e_EXPRESSION_PLUS, e_EXPRESSION_MINUS,
  e_DEFAULT_TERM, e_TIMES_TERM, e_DIVIDE_TERM, e_NORMAL_NUMBER, e_NEGATIVE_NUMBER, e_REAL_NUMBER, e_REALTYPE,e_EQUALS,e_SHEVRONS,e_LESSTHAN,e_MORETHAN,e_LESSOREQUAL,e_MOREOREQUAL,e_CHARACTER_CONSTANT,e_NEWLINE_WRITE_STATEMENT,e_INTEGERTYPE,e_CHARACTERTYPE,e_IF_ELSE_STATEMENT,e_NOT_CONDITION,e_AND_CONDITIONAL,e_OR_CONDITIONAL,e_IDENTIFIER_VALUE,e_CONSTANT_VALUE,e_EXPRESSION_VALUE,e_DECLARATION_BLOCK_EXTEND,e_IDENTIFIER_LIST_EXTEND};
  
  const char *ParseTreeValues[]={"PROGRAM", "BLOCK", "DECLARATION_BLOCK", "IDENTIFIER_LIST", "REAL", "STATEMENT_LIST", "STATEMENT",
  "ASSIGNMENT_STATEMENT", "IF_STATEMENT", "DO_STATEMENT", "FOR_STATEMENT", "WHILE_STATEMENT", "WRITE_STATEMENT", "OUTPUT_LIST", "READ_STATEMENT", "CONDITIONAL", "COMPARATOR",
  "EXPRESSION", "TERM", "VALUE", "CONSTANT", "NUMBER_CONSTANT", "TYPE", "POSITIVE_REAL", "NEGATIVE_REAL", "DEFAULT_CONDITIONAL", "DEFAULT_EXPRESSION", "EXPRESSION_PLUS", "EXPRESSION_MINUS",
  "DEFAULT_TERM", "TIMES_TERM", "DIVIDE_TERM", "NORMAL_NUMBER", "NEGATIVE_NUMBER", "REAL_NUMBER", "REALTYPE","EQUALS","SHEVRONS","LESSTHAN","MORETHAN","LESSOREQUAL","MOREOREQUAL","CHARACTER_CONSTANT","NEWLINE_WRITE_STATEMENT","INTEGERTYPE","CHARACTERTYPE","IF_ELSE_STATEMENT","NOT_CONDITION","AND_CONDITIONAL","OR_CONDITIONAL","IDENTIFIER_VALUE","CONSTANT_VALUE","EXPRESSION_VALUE","DECLARATION_BLOCK_EXTEND","IDENTIFIER_LIST_EXTEND"};

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
};

typedef  struct symTabNode SYMTABNODE;
typedef  SYMTABNODE        *SYMTABNODEPTR;

SYMTABNODEPTR  symTab[SYMTABSIZE]; 

int currentSymTabSize = 0;
/* Initialise Debug on Debug flag */


/* Line 189 of yacc.c  */
#line 151 "spl.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     COLON = 258,
     DOT = 259,
     LESSTHAN = 260,
     MORETHAN = 261,
     PLUS = 262,
     MINUS = 263,
     SEMICOLON = 264,
     COMMA = 265,
     POINTER = 266,
     BRA = 267,
     KET = 268,
     LESSOREQUAL = 269,
     MOREOREQUAL = 270,
     SHEVRONS = 271,
     APOSTROPHE = 272,
     TIMES = 273,
     DIVIDE = 274,
     EQUALS = 275,
     ENDPROGRAM = 276,
     DECLARATIONS = 277,
     CODE = 278,
     OF = 279,
     TYPEVAR = 280,
     IF = 281,
     THEN = 282,
     ENDIF = 283,
     ELSE = 284,
     DO = 285,
     WHILE = 286,
     ENDDO = 287,
     FOR = 288,
     IS = 289,
     BY = 290,
     TO = 291,
     ENDFOR = 292,
     ENDWHILE = 293,
     WRITE = 294,
     NEWLINE = 295,
     READ = 296,
     NOT = 297,
     AND = 298,
     OR = 299,
     IDENTIFIER = 300,
     NUMBER = 301,
     CHARACTER_ACTUAL = 302,
     DECIMAL_NUMBER = 303,
     NEGATIVE_DECIMAL_NUMBER = 304,
     NEGATIVE_NUMBER = 305,
     INTEGERTYPE = 306,
     REALTYPE = 307,
     CHARACTERTYPE = 308
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 88 "spl.y"

    int iVal;
    TERNARY_TREE tVal;



/* Line 214 of yacc.c  */
#line 247 "spl.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 259 "spl.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNRULES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    10,    15,    18,    24,    31,    33,    37,
      39,    41,    43,    47,    49,    51,    53,    55,    57,    59,
      61,    65,    71,    79,    85,    97,   103,   108,   110,   112,
     116,   121,   125,   128,   134,   140,   142,   144,   146,   148,
     150,   152,   154,   158,   162,   164,   168,   172,   174,   176,
     180,   182,   184,   186,   188,   190,   192,   194,   196
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    45,     3,    56,    21,    45,     4,    -1,
      22,    57,    23,    60,    -1,    23,    60,    -1,    58,    24,
      25,    77,     9,    -1,    57,    58,    24,    25,    77,     9,
      -1,    45,    -1,    58,    10,    45,    -1,    48,    -1,    49,
      -1,    61,    -1,    60,     9,    61,    -1,    62,    -1,    63,
      -1,    64,    -1,    66,    -1,    65,    -1,    67,    -1,    69,
      -1,    72,    11,    45,    -1,    26,    70,    27,    60,    28,
      -1,    26,    70,    27,    60,    29,    60,    28,    -1,    30,
      60,    31,    70,    32,    -1,    33,    45,    34,    72,    35,
      72,    36,    72,    30,    60,    37,    -1,    31,    70,    30,
      60,    38,    -1,    39,    12,    68,    13,    -1,    40,    -1,
      74,    -1,    68,    10,    74,    -1,    41,    12,    45,    13,
      -1,    72,    71,    72,    -1,    42,    70,    -1,    72,    71,
      72,    43,    70,    -1,    72,    71,    72,    44,    70,    -1,
      20,    -1,    16,    -1,     5,    -1,     6,    -1,    14,    -1,
      15,    -1,    73,    -1,    73,     7,    72,    -1,    73,     8,
      72,    -1,    74,    -1,    74,    18,    73,    -1,    74,    19,
      73,    -1,    45,    -1,    75,    -1,    12,    72,    13,    -1,
      76,    -1,    78,    -1,    46,    -1,    50,    -1,    59,    -1,
      53,    -1,    51,    -1,    52,    -1,    47,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   120,   124,   129,   133,   138,   142,   147,
     151,   156,   160,   165,   169,   173,   177,   181,   185,   189,
     194,   199,   203,   208,   213,   218,   223,   227,   232,   236,
     241,   246,   250,   254,   258,   263,   267,   271,   275,   279,
     283,   287,   291,   295,   300,   304,   308,   313,   317,   321,
     326,   330,   335,   339,   343,   348,   352,   356,   360
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COLON", "DOT", "LESSTHAN", "MORETHAN",
  "PLUS", "MINUS", "SEMICOLON", "COMMA", "POINTER", "BRA", "KET",
  "LESSOREQUAL", "MOREOREQUAL", "SHEVRONS", "APOSTROPHE", "TIMES",
  "DIVIDE", "EQUALS", "ENDPROGRAM", "DECLARATIONS", "CODE", "OF",
  "TYPEVAR", "IF", "THEN", "ENDIF", "ELSE", "DO", "WHILE", "ENDDO", "FOR",
  "IS", "BY", "TO", "ENDFOR", "ENDWHILE", "WRITE", "NEWLINE", "READ",
  "NOT", "AND", "OR", "IDENTIFIER", "NUMBER", "CHARACTER_ACTUAL",
  "DECIMAL_NUMBER", "NEGATIVE_DECIMAL_NUMBER", "NEGATIVE_NUMBER",
  "INTEGERTYPE", "REALTYPE", "CHARACTERTYPE", "$accept", "program",
  "block", "declaration_block", "identifier_list", "real",
  "statement_list", "statement", "assignment_statement", "if_statement",
  "do_statement", "for_statement", "while_statement", "write_statement",
  "output_list", "read_statement", "conditional", "comparator",
  "expression", "term", "value", "constant", "number_constant", "type",
  "character_constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      62,    63,    63,    64,    65,    66,    67,    67,    68,    68,
      69,    70,    70,    70,    70,    71,    71,    71,    71,    71,
      71,    72,    72,    72,    73,    73,    73,    74,    74,    74,
      75,    75,    76,    76,    76,    77,    77,    77,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     4,     2,     5,     6,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     5,     7,     5,    11,     5,     4,     1,     1,     3,
       4,     3,     2,     5,     5,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,    47,
      52,    58,     9,    10,    53,    54,     4,    11,    13,    14,
      15,    17,    16,    18,    19,     0,    41,    44,    48,    50,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     8,     0,    49,    32,     0,    37,
      38,    39,    40,    36,    35,     0,     0,     0,     0,     0,
      28,     0,    12,    20,    42,    43,    45,    46,     2,     0,
      56,    57,    55,     0,     0,    31,     0,     0,     0,     0,
      26,    30,     0,     5,    21,     0,     0,     0,    23,    25,
       0,    29,     6,     0,    33,    34,     0,    22,     0,     0,
       0,     0,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     9,    10,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    79,    34,    48,    75,    35,    36,
      37,    38,    39,    93,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -52
static const yytype_int8 yypact[] =
{
     -31,    16,    25,    17,   -52,   -18,    42,    24,   -52,   -17,
      13,    74,    68,    42,    68,    12,    41,   -52,    46,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,    50,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,    51,     9,    31,   -52,   -52,
     -52,    18,    42,    14,    21,    36,    58,    68,    47,     6,
       0,    48,    43,    74,    34,    42,    39,    74,    74,    74,
      74,    72,    50,    60,   -52,    -9,   -52,   -52,    42,   -52,
     -52,   -52,   -52,   -52,   -52,    74,    68,    42,    74,     5,
     -52,    80,   -52,   -52,   -52,   -52,   -52,   -52,   -52,    -9,
     -52,   -52,   -52,    85,     1,     8,    66,    -5,    67,    74,
     -52,   -52,    94,   -52,   -52,    42,    68,    68,   -52,   -52,
      74,   -52,   -52,     4,   -52,   -52,    69,   -52,    74,    76,
      42,    -2,   -52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,   -52,   -52,    95,   -52,    -8,    53,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,    -6,   -52,   -11,    -4,
     -51,   -52,   -52,    20,   -52
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      46,    49,    80,    49,    55,    50,    42,    55,    51,    55,
      55,    69,    70,    55,     1,    99,    57,    58,   100,     3,
      71,    72,    73,    44,    44,     4,    74,     8,     8,   104,
     105,    76,   117,   109,    62,   122,    49,    45,    63,     5,
       6,    67,    90,    91,    92,    41,    84,    85,   111,    59,
      60,   106,   107,    53,    11,    86,    87,    52,    54,    55,
      94,    65,    56,    61,    95,    49,    64,    98,    12,    97,
      96,    66,    13,    14,    68,    15,    88,    78,    77,    81,
      11,    16,    17,    18,    83,    89,    11,    19,    20,    21,
      22,    23,    24,   101,   103,    49,    49,   113,   108,   116,
     114,   115,   110,   112,    43,   118,   120,   119,    82,   102,
      47,     0,   121,    19,    20,    21,    22,    23,    24,    19,
      20,    21,    22,    23,    24
};

static const yytype_int8 yycheck[] =
{
      11,    12,    53,    14,     9,    13,    23,     9,    14,     9,
       9,     5,     6,     9,    45,    10,     7,     8,    13,     3,
      14,    15,    16,    10,    10,     0,    20,    45,    45,    28,
      29,    31,    28,    38,    42,    37,    47,    24,    24,    22,
      23,    47,    51,    52,    53,    21,    57,    58,    99,    18,
      19,    43,    44,    12,    12,    59,    60,    45,    12,     9,
      68,    25,    11,    45,    75,    76,    45,    78,    26,    77,
      76,    13,    30,    31,    27,    33,     4,    34,    30,    45,
      12,    39,    40,    41,    45,    25,    12,    45,    46,    47,
      48,    49,    50,    13,     9,   106,   107,   105,    32,   110,
     106,   107,    35,     9,     9,    36,    30,   118,    55,    89,
      42,    -1,   120,    45,    46,    47,    48,    49,    50,    45,
      46,    47,    48,    49,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    55,     3,     0,    22,    23,    56,    45,    57,
      58,    12,    26,    30,    31,    33,    39,    40,    41,    45,
      46,    47,    48,    49,    50,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    69,    72,    73,    74,    75,    76,
      78,    21,    23,    58,    10,    24,    72,    42,    70,    72,
      60,    70,    45,    12,    12,     9,    11,     7,     8,    18,
      19,    45,    60,    24,    45,    25,    13,    70,    27,     5,
       6,    14,    15,    16,    20,    71,    31,    30,    34,    68,
      74,    45,    61,    45,    72,    72,    73,    73,     4,    25,
      51,    52,    53,    77,    60,    72,    70,    60,    72,    10,
      13,    13,    77,     9,    28,    29,    43,    44,    32,    38,
      35,    74,     9,    60,    70,    70,    72,    28,    36,    72,
      30,    60,    37
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 103 "spl.y"
    {
				TERNARY_TREE ParseTree;
				if((yyvsp[(1) - (6)].iVal)==(yyvsp[(5) - (6)].iVal))
				{
					ParseTree= create_node((yyvsp[(1) - (6)].iVal),e_PROGRAM,(yyvsp[(3) - (6)].tVal),NULL,NULL);
					#ifdef DEBUG
					PrintTree(ParseTree,0);
					#endif
					GenerateCode(ParseTree);
				}
				else
				{
					fprintf(stderr,"Program IDENTIFIER is not called at the start and end of the program!");
					exit(0);
				}
			;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 121 "spl.y"
    {
			(yyval.tVal)=create_node(NOTHING,e_BLOCK,(yyvsp[(2) - (4)].tVal),(yyvsp[(4) - (4)].tVal),NULL);
		;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 125 "spl.y"
    {
			(yyval.tVal)=create_node(NOTHING,e_BLOCK,(yyvsp[(2) - (2)].tVal),NULL,NULL);
		;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 130 "spl.y"
    {
						(yyval.tVal)=create_node(NOTHING,e_DECLARATION_BLOCK,(yyvsp[(1) - (5)].tVal),(yyvsp[(4) - (5)].tVal),NULL);
					;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 134 "spl.y"
    {
						(yyval.tVal)=create_node(NOTHING,e_DECLARATION_BLOCK_EXTEND,(yyvsp[(1) - (6)].tVal),(yyvsp[(2) - (6)].tVal),(yyvsp[(5) - (6)].tVal));
					;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 139 "spl.y"
    {
					(yyval.tVal)=create_node((yyvsp[(1) - (1)].iVal),e_IDENTIFIER_LIST,NULL,NULL,NULL);
				;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 143 "spl.y"
    {
					(yyval.tVal)=create_node((yyvsp[(3) - (3)].iVal),e_IDENTIFIER_LIST_EXTEND,(yyvsp[(1) - (3)].tVal),NULL,NULL);
				;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 148 "spl.y"
    {
			(yyval.tVal)=create_node((yyvsp[(1) - (1)].iVal),e_REAL,NULL,NULL,NULL);
		;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 152 "spl.y"
    {
			(yyval.tVal)=create_node((yyvsp[(1) - (1)].iVal),e_REAL,NULL,NULL,NULL);
		;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 157 "spl.y"
    {
			(yyval.tVal)=create_node(NOTHING,e_STATEMENT_LIST,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 161 "spl.y"
    {
			(yyval.tVal)=create_node(NOTHING,e_STATEMENT_LIST,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL);
		;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 166 "spl.y"
    {
			(yyval.tVal)=create_node(e_ASSIGNMENT_STATEMENT,e_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 170 "spl.y"
    {
			(yyval.tVal)=create_node(e_IF_STATEMENT,e_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 174 "spl.y"
    {
			(yyval.tVal)=create_node(e_DO_STATEMENT,e_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 178 "spl.y"
    {
			(yyval.tVal)=create_node(e_WHILE_STATEMENT,e_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 182 "spl.y"
    {
			(yyval.tVal)=create_node(e_FOR_STATEMENT,e_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 186 "spl.y"
    {
			(yyval.tVal)=create_node(e_WRITE_STATEMENT,e_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 190 "spl.y"
    {
			(yyval.tVal)=create_node(e_READ_STATEMENT,e_STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 195 "spl.y"
    {
			(yyval.tVal)=create_node((yyvsp[(3) - (3)].iVal),e_ASSIGNMENT_STATEMENT,(yyvsp[(1) - (3)].tVal),NULL,NULL);
		;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 200 "spl.y"
    {
			(yyval.tVal)=create_node(NOTHING,e_IF_STATEMENT,(yyvsp[(2) - (5)].tVal),(yyvsp[(4) - (5)].tVal),NULL);
		;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 204 "spl.y"
    {
			(yyval.tVal)=create_node(NOTHING,e_IF_ELSE_STATEMENT,(yyvsp[(2) - (7)].tVal),(yyvsp[(4) - (7)].tVal),(yyvsp[(6) - (7)].tVal));
		;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 209 "spl.y"
    {
			(yyval.tVal)=create_node(NOTHING,e_DO_STATEMENT,(yyvsp[(2) - (5)].tVal),(yyvsp[(4) - (5)].tVal),NULL);
		;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 214 "spl.y"
    {
			(yyval.tVal)=create_node((yyvsp[(2) - (11)].iVal),e_FOR_STATEMENT,create_node(NOTHING,e_FOR_STATEMENT,(yyvsp[(4) - (11)].tVal),(yyvsp[(6) - (11)].tVal),(yyvsp[(8) - (11)].tVal)),(yyvsp[(10) - (11)].tVal),NULL);
		;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 219 "spl.y"
    {
			(yyval.tVal)=create_node(NOTHING,e_WHILE_STATEMENT,(yyvsp[(2) - (5)].tVal),(yyvsp[(4) - (5)].tVal),NULL);
		;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 224 "spl.y"
    {
			(yyval.tVal)=create_node(NOTHING,e_WRITE_STATEMENT,(yyvsp[(3) - (4)].tVal),NULL,NULL);
		;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 228 "spl.y"
    {
			(yyval.tVal)=create_node(NOTHING,e_NEWLINE_WRITE_STATEMENT,NULL,NULL,NULL);
		;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 233 "spl.y"
    {
			(yyval.tVal)=create_node(NOTHING,e_OUTPUT_LIST,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 237 "spl.y"
    {
			(yyval.tVal)=create_node(NOTHING,e_OUTPUT_LIST,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL);
		;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 242 "spl.y"
    {
			(yyval.tVal)=create_node((yyvsp[(3) - (4)].iVal),e_READ_STATEMENT,NULL,NULL,NULL);
		;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 247 "spl.y"
    {
			(yyval.tVal)=create_node(e_DEFAULT_CONDITIONAL,e_CONDITIONAL,(yyvsp[(1) - (3)].tVal),(yyvsp[(2) - (3)].tVal),(yyvsp[(3) - (3)].tVal));
		;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 251 "spl.y"
    {
			(yyval.tVal)=create_node(e_NOT_CONDITION,e_NOT_CONDITION,(yyvsp[(2) - (2)].tVal),NULL,NULL);
		;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 255 "spl.y"
    {
			(yyval.tVal)=create_node(e_AND_CONDITIONAL,e_AND_CONDITIONAL,create_node(e_AND_CONDITIONAL,e_CONDITIONAL,(yyvsp[(1) - (5)].tVal),(yyvsp[(2) - (5)].tVal),(yyvsp[(3) - (5)].tVal)),(yyvsp[(5) - (5)].tVal),NULL);
		;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 259 "spl.y"
    {
			(yyval.tVal)=create_node(e_OR_CONDITIONAL,e_OR_CONDITIONAL,create_node(e_OR_CONDITIONAL,e_CONDITIONAL,(yyvsp[(1) - (5)].tVal),(yyvsp[(2) - (5)].tVal),(yyvsp[(3) - (5)].tVal)),(yyvsp[(5) - (5)].tVal),NULL);
		;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 264 "spl.y"
    {
			(yyval.tVal)=create_node(e_EQUALS,e_EQUALS,NULL,NULL,NULL);
		;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 268 "spl.y"
    {
			(yyval.tVal)=create_node(e_SHEVRONS,e_SHEVRONS,NULL,NULL,NULL);
		;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 272 "spl.y"
    {
			(yyval.tVal)=create_node(e_LESSTHAN,e_LESSTHAN,NULL,NULL,NULL);
		;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 276 "spl.y"
    {
			(yyval.tVal)=create_node(e_MORETHAN,e_MORETHAN,NULL,NULL,NULL);
		;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 280 "spl.y"
    {
			(yyval.tVal)=create_node(e_LESSOREQUAL,e_LESSOREQUAL,NULL,NULL,NULL);
		;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 284 "spl.y"
    {
			(yyval.tVal)=create_node(e_MOREOREQUAL,e_MOREOREQUAL,NULL,NULL,NULL);
		;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 288 "spl.y"
    {
			(yyval.tVal)=create_node(e_DEFAULT_EXPRESSION,e_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 292 "spl.y"
    {
			(yyval.tVal)=create_node(e_EXPRESSION_PLUS,e_EXPRESSION_PLUS,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL);
		;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 296 "spl.y"
    {
			(yyval.tVal)=create_node(e_EXPRESSION_MINUS,e_EXPRESSION_MINUS,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL);
		;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 301 "spl.y"
    {
			(yyval.tVal)=create_node(e_DEFAULT_TERM,e_TERM,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 305 "spl.y"
    {
			(yyval.tVal)=create_node(e_TIMES_TERM,e_TIMES_TERM,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL);
		;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 309 "spl.y"
    {
			(yyval.tVal)=create_node(e_DIVIDE_TERM,e_DIVIDE_TERM,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL);
		;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 314 "spl.y"
    {
			(yyval.tVal)=create_node((yyvsp[(1) - (1)].iVal),e_IDENTIFIER_VALUE,NULL,NULL,NULL);
		;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 318 "spl.y"
    {
			(yyval.tVal)=create_node(NOTHING,e_CONSTANT_VALUE,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 322 "spl.y"
    {
			(yyval.tVal)=create_node(NOTHING,e_EXPRESSION_VALUE,(yyvsp[(2) - (3)].tVal),NULL,NULL);
		;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 327 "spl.y"
    {
			(yyval.tVal)=create_node(e_NORMAL_NUMBER,e_CONSTANT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 331 "spl.y"
    {
			(yyval.tVal)=create_node(e_CHARACTER_CONSTANT,e_CONSTANT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 336 "spl.y"
    {
			(yyval.tVal)=create_node((yyvsp[(1) - (1)].iVal),e_NUMBER_CONSTANT,NULL,NULL,NULL);
		;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 340 "spl.y"
    {
			(yyval.tVal)=create_node((yyvsp[(1) - (1)].iVal),e_NUMBER_CONSTANT,NULL,NULL,NULL);
		;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 344 "spl.y"
    {
			(yyval.tVal)=create_node(e_REAL_NUMBER,e_NUMBER_CONSTANT,(yyvsp[(1) - (1)].tVal),NULL,NULL);
		;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 349 "spl.y"
    {
			(yyval.tVal)=create_node((yyvsp[(1) - (1)].iVal),e_CHARACTERTYPE,NULL,NULL,NULL);
		;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 353 "spl.y"
    {
			(yyval.tVal)=create_node((yyvsp[(1) - (1)].iVal),e_INTEGERTYPE,NULL,NULL,NULL);
		;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 357 "spl.y"
    {
			(yyval.tVal)=create_node((yyvsp[(1) - (1)].iVal),e_REALTYPE,NULL,NULL,NULL);
		;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 361 "spl.y"
    {
	(yyval.tVal)=create_node((yyvsp[(1) - (1)].iVal),e_CHARACTER_CONSTANT,NULL,NULL,NULL);
;}
    break;



/* Line 1455 of yacc.c  */
#line 2088 "spl.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 364 "spl.y"

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
		case(e_PROGRAM):
			printf("#include <stdio.h>\n");
			printf("#include <stdlib.h>\n");
			printf("int main(void) \n{\n");
			GenerateCode(t->first);
			printf("}");
			return;
		case(e_BLOCK):
			GenerateCode(t->first);
			printf("\n");
			GenerateCode(t->second);
			return;
		case(e_DECLARATION_BLOCK):
			GenerateCode(t->second);
			printf(" ");
			GenerateCode(t->first);
			printf(";\n");
			return;
		case(e_DECLARATION_BLOCK_EXTEND):
			GenerateCode(t->first);
			GenerateCode(t->third);
			printf(" ");
			GenerateCode(t->second);
			printf(";\n");
			return;
		case(e_IDENTIFIER_LIST):
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s", symTab[t->item]->identifier);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			return;
		case(e_IDENTIFIER_LIST_EXTEND):
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
		case(e_REAL):
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s", symTab[t->item]->identifier);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			return;
		case(e_STATEMENT_LIST):
			GenerateCode(t->first);
			GenerateCode(t->second);
			return;
		case(e_STATEMENT):
			GenerateCode(t->first);
			return;
		case(e_ASSIGNMENT_STATEMENT):
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
			printf(";\n");
			return;
		case(e_IF_STATEMENT):
			printf("if (");
			GenerateCode(t->first);
			printf(") \n{\n");
			GenerateCode(t->second);
			printf("}\n");
			return;
		case(e_IF_ELSE_STATEMENT):
			printf("if (");
			GenerateCode(t->first);
			printf(") \n{\n");
			GenerateCode(t->second);
			printf("}\n");
			printf("else\n{\n");
			GenerateCode(t->third);
			printf("}\n");
			return;
		case(e_DO_STATEMENT):
			printf("do {\n");
			GenerateCode(t->first);
			printf("} while (");
			GenerateCode(t->second);
			printf(");\n");
			return;
		case(e_FOR_STATEMENT):
			printf("for (");
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s", symTab[t->item]->identifier);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			printf("=");
			GenerateCode(t->first->first);
			printf(";");
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s", symTab[t->item]->identifier);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			printf("<");
			GenerateCode(t->first->third);
			printf(";");
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s", symTab[t->item]->identifier);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			printf("+=");
			GenerateCode(t->first->second);
			printf(")\n{\n");
			GenerateCode(t->second);
			printf("}\n");
			return;
		case(e_WHILE_STATEMENT):
			printf("while (");
			GenerateCode(t->first);
			printf(") \n{\n");
			GenerateCode(t->second);
			printf("}\n");
			return;
		case(e_WRITE_STATEMENT):
			printf("printf(\"");
			GenerateCode(t->first);
			printf("\");\n");
			return;
		case(e_NEWLINE_WRITE_STATEMENT):
			printf("printf(\"\\n\");\n");
			return;
		case(e_OUTPUT_LIST):
			GenerateCode(t->first);
			GenerateCode(t->second);
			return;
		case(e_READ_STATEMENT):
			printf("scanf(\"%%s\",");
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s", symTab[t->item]->identifier);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			printf(");\n");
			return;
		case(e_CONDITIONAL):
			GenerateCode(t->first);
			GenerateCode(t->second);
			GenerateCode(t->third);
			return;
		case(e_NOT_CONDITION):
			printf("!(");
			GenerateCode(t->first);
			printf(")");
			return;
		case(e_AND_CONDITIONAL):
			GenerateCode(t->first);
			printf(" && ");
			GenerateCode(t->second);
			return;
		case(e_OR_CONDITIONAL):
			GenerateCode(t->first);
			printf(" || ");
			GenerateCode(t->second);
			return;
		case(e_EQUALS):
			printf(" == ");
			return;
		case(e_SHEVRONS):
			printf(" <> ");
			return;
		case(e_LESSTHAN):
			printf(" < ");
			return;
		case(e_MORETHAN):
			printf(" > ");
			return;
		case(e_LESSOREQUAL):
			printf(" <= ");
			return;
		case(e_MOREOREQUAL):
			printf(" >= ");
			return;
		case(e_EXPRESSION):
			GenerateCode(t->first);
			return;
		case(e_EXPRESSION_PLUS):
			GenerateCode(t->first);
			printf("+");
			GenerateCode(t->second);
			return;
		case(e_EXPRESSION_MINUS):
			GenerateCode(t->first);
			printf("-");
			GenerateCode(t->second);
			return;
		case(e_TERM):
			GenerateCode(t->first);
			return;
		case(e_TIMES_TERM):
			GenerateCode(t->first);
			printf("*");
			GenerateCode(t->second);
			return;
		case(e_DIVIDE_TERM):
			GenerateCode(t->first);
			printf("/");
			GenerateCode(t->second);
			return;
		case(e_IDENTIFIER_VALUE):
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s", symTab[t->item]->identifier);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			return;
		case(e_CONSTANT_VALUE):
			GenerateCode(t->first);
			return;
		case(e_EXPRESSION_VALUE):
			printf("(");
			GenerateCode(t->first);
			printf(")");
			return;
		case(e_CONSTANT):
			GenerateCode(t->first);
			return;
		case(e_NUMBER_CONSTANT):
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%s",symTab[t->item]->identifier);
			}
			else
			{
				printf("UnknownIdentifier: %d",t->item);
			}
			return;
		case (e_REALTYPE):
			printf("double");
			return;
		case(e_INTEGERTYPE):
			printf("int");
			return;
		case(e_CHARACTERTYPE):
			printf("char");
			return;
		case(e_CHARACTER_CONSTANT):
			if(t->item>=0 && t->item<SYMTABSIZE)
			{
				printf("%c",symTab[t->item]->identifier[1]);
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

/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170430

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "minic.y"
#include "definition.h"
extern char *yytext;
extern int yylineno;
extern int lex_err;
int funcount, gcount, syntax_err, prg_err, total_err;
struct allFunc **ALL;
struct globalVar **gVar;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 33 "minic.y"
typedef union {
    char *text;         /* 终结符语义值类型 */
    struct AST *node;	/* 非终结符语义值类型 */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 41 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define IDENT 257
#define VOID 258
#define INT 259
#define WHILE 260
#define IF 261
#define ELSE 262
#define RETURN 263
#define EQ 264
#define NE 265
#define LE 266
#define GE 267
#define AND 268
#define OR 269
#define DECNUM 270
#define CONTINUE 271
#define BREAK 272
#define HEXNUM 273
#define LSHIFT 274
#define RSHIFT 275
#define UMINUS 276
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,    2,    2,    2,    3,    3,    3,
    4,    4,    4,    5,    5,    5,    6,    6,    6,    7,
    7,    7,    8,    8,    8,    9,    9,    9,   10,   10,
   10,   10,   10,   10,   10,   10,   11,   11,   11,   11,
   11,   11,   12,   12,   13,   13,   14,   14,   14,   14,
   14,   15,   15,   15,   16,   16,   16,   17,   17,   17,
   18,   18,   18,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   20,   20,   20,   21,   21,   21,   22,
   22,   23,   23,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    1,    1,    1,    1,    3,    6,    1,
    1,    1,    1,    6,    6,    1,    1,    1,    1,    3,
    1,    1,    2,    5,    1,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    4,    7,    5,    5,
    4,    1,    5,    1,    3,    1,    4,    3,    3,    2,
    1,    2,    1,    1,    3,    6,    1,    5,    7,    1,
    2,    3,    1,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    2,    2,    2,
    3,    1,    4,    4,    3,    1,    3,    3,    2,    3,
    3,    3,    1,    1,    1,    1,    3,    1,    1,    2,
    1,    2,    1,
};
static const YYINT yydefred[] = {                         0,
    0,   11,   12,    0,    0,    3,    5,    0,    6,    0,
    2,    0,    8,    0,    0,    0,    0,    0,    0,    0,
    0,   21,    0,    0,    0,    0,    9,    0,   51,   15,
    0,   14,    0,   20,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   50,    0,    0,   27,   29,   32,
   30,    0,   53,   31,   33,   34,   35,   24,    0,    0,
    0,    0,    0,   93,    0,   94,   95,    0,    0,    0,
    0,   61,    0,    0,    0,   86,  100,  102,    0,   28,
    0,    0,   36,   49,   26,    0,   48,    0,   52,    0,
   93,    0,    0,    0,    0,    0,    0,    0,    0,   79,
   78,   77,   89,    0,   80,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   62,    0,   45,   55,    0,   47,    0,
   41,    0,    0,   37,    0,    0,    0,   85,    0,   81,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   40,    0,   43,    0,   83,   84,   39,    0,    0,
    0,   56,   38,   59,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,    8,    9,   20,   21,   22,   47,   48,
   49,   50,   51,   32,   52,   53,   54,   55,   93,   76,
   94,   56,   57,
};
static const YYINT yysindex[] = {                      -128,
    0,    0,    0,    0, -116,    0,    0, -249,    0,    0,
    0,  -15,    0, -259, -102,  -72,    0,    0, -205,   13,
   15,    0,    7,  -31,  -55,  -98,    0, -193,    0,    0,
  283,    0,    0,    0,   19,    0,  -16,   38,   43,  -33,
   32,   49, -160,  220,    0, -140,  471,    0,    0,    0,
    0,  363,    0,    0,    0,    0,    0,    0, -144,  -27,
   10,   10,   10,    0,  -10,    0,    0,   10,   10,   10,
   10,    0,   10, -146,   47,    0,    0,    0,   76,    0,
  490,  -40,    0,    0,    0,    0,    0,  513,    0,   45,
    0,   88,  379,   -7,   73,  108,  145, -122,   -5,    0,
    0,    0,    0,  263,    0,   10,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   10,    0,   10,    0,    0, -111,    0,  101,
    0,  104,   10,    0,  329,  329,   72,    0,   -2,    0,
  234,  234,  234,  234,  412,  391, -227, -227,  234,  234,
   87,   87,   58,  -20,  -20, -227, -227, -227,  307,   79,
   10,    0,  379,    0,  -96,    0,    0,    0,  105,  343,
  329,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    1,    0,    0,    0,  169,    0,    0,    0,    0,    5,
    0,    0,    0,    0,    0,    0,  -21,  -39,    0,    0,
  132,    0,    0,   30,    0,    0,    0,    0,    0,    0,
    0,    0,  -12,    0,    0,  433,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   20,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  454,    0,    0,    0,    0,
    0,    0,   57,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  434,  704,  731,  888,   28,   29,  758,  769,  917,  923,
  403,  677,  854,  842,  865,  795,  806,  832,    0,    0,
    0,    0,   78,    0,  526,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  170,    0,   71,    0,    0,    0,  148,  -11,  -32,
    0,    0,    0,    0,    0,  124,    0,    0, 1097,    0,
   80,    0,    0,
};
#define YYTABLESIZE 1258
static const YYINT yytable[] = {                         70,
    4,   18,   74,   30,    7,   70,   73,   12,   74,   68,
   16,   69,   73,   92,   85,   68,  123,   69,  127,   19,
   23,  121,   22,   60,   15,   72,  122,   70,   25,   99,
   74,   25,   81,  132,   73,  138,  133,   68,  167,   69,
   88,  133,   70,   13,   61,   74,  112,  113,   85,   73,
  128,   24,   68,   25,   69,   85,   82,   82,   26,   28,
   82,   82,   82,   82,   82,   27,   82,   31,   71,   64,
   23,   71,   64,   23,   59,   14,   35,   62,   82,   82,
   98,   82,   63,  123,  119,   19,   71,   64,  121,  116,
   77,  117,   71,  122,  123,  119,   19,   98,   71,  121,
   98,   46,  164,  165,  122,  124,  114,   78,  115,  123,
  119,   58,   79,   82,  121,  116,   82,  117,   97,  122,
   71,   97,   46,  123,  119,   90,  105,    1,  121,    2,
    3,  134,  114,  122,  115,   71,  125,  130,  174,   10,
  120,    2,    3,   82,  123,  119,  131,  137,  135,  121,
  116,  120,  117,   17,  122,   18,    3,   33,  160,    2,
    3,  161,  162,  172,  166,  171,  120,  114,    1,  115,
  118,  169,   17,   34,   11,   89,    0,    0,  139,    0,
  120,  123,  119,    0,    0,  136,  121,  116,    0,  117,
    0,  122,    0,    0,    0,    0,  118,    0,    0,    0,
   29,  120,    0,    0,  114,    0,  115,    0,    0,    0,
  118,    0,    0,    0,    0,    0,    0,   11,    0,    0,
    0,    0,   64,   65,    0,    0,    0,    0,   91,   65,
    0,  118,    0,    0,    0,   13,   66,    0,  120,   67,
    0,    0,   66,    0,   13,   67,    0,    0,    0,    0,
   91,   65,    0,  112,  113,   43,    4,   13,    4,    4,
    7,   13,    7,    7,   66,   64,   65,   67,  118,    0,
  123,  119,    0,    0,    0,  121,  116,    0,  117,   66,
  122,    0,   67,   82,   82,   82,   82,   82,   82,    0,
    0,    0,    0,   82,   82,   71,   71,   64,    0,  123,
  119,    0,    0,  140,  121,  116,    0,  117,    0,  122,
  106,  107,  108,  109,  110,  111,    0,    0,   43,    0,
  112,  113,  114,    0,  115,    0,    0,  120,    0,    0,
    0,  112,  113,    0,    0,    0,  106,  107,  108,  109,
  110,  111,   44,  123,  119,    0,  112,  113,  121,  116,
    0,  117,    0,  122,    0,    0,  120,  118,    0,    0,
  112,  113,    0,    0,   43,  168,  114,    0,  115,    0,
    0,  106,  107,  108,  109,  110,  111,    0,    0,  123,
  119,  112,  113,    0,  121,  116,  118,  117,    0,  122,
    0,    0,    0,    0,    0,    0,    0,    0,   43,    0,
  120,  173,  114,    0,  115,   44,    0,   45,  106,  107,
  108,  109,  110,  111,    0,  123,  119,    0,  112,  113,
  121,  116,    0,  117,    0,  122,    0,  123,  119,    0,
  118,    0,  121,  116,    0,  117,  120,  122,  114,    0,
  115,    0,    0,   72,    0,   72,   72,   72,  123,  119,
  114,   44,  115,  121,  116,    0,  117,    0,  122,    0,
    0,   72,   72,    0,   72,    0,  118,    0,   28,    0,
    0,  114,  120,  115,   65,   80,   37,   65,    0,   38,
   39,    0,   40,    0,  120,   44,    0,   87,    0,   28,
   41,   42,   65,   65,    0,   65,    0,    0,    0,    0,
    0,    0,  118,    0,    0,  120,   43,  112,  113,    0,
    0,    0,    0,    0,  118,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   43,  106,  107,  108,  109,
  110,  111,    0,    0,    0,  118,  112,  113,   36,   37,
    2,    3,   38,   39,    0,   40,    0,    0,   43,    0,
    0,    0,    0,   41,   42,   28,    0,   28,    0,    0,
    0,   58,    0,    0,    0,    0,    0,    0,    0,    0,
  106,  107,  108,  109,  110,  111,   28,    0,   28,    0,
  112,  113,    0,    0,   83,   37,    0,    0,   38,   39,
    0,   40,    0,   44,    0,   84,    0,    0,    0,   41,
   42,    0,    0,    0,    0,    0,  106,  107,  108,  109,
  110,  111,   44,    0,  126,    0,  112,  113,   86,   37,
    2,    3,   38,   39,    0,   40,    0,    0,    0,    0,
    0,    0,    0,   41,   42,   44,    0,  129,    0,    0,
    0,    0,  106,  107,  108,  109,  110,  111,   58,    0,
   58,    0,  112,  113,  106,  107,  108,  109,  110,    0,
    0,    0,    0,    0,  112,  113,   72,   72,   72,   72,
   72,   72,    0,    0,    0,  106,  107,  108,  109,    0,
    0,    0,    0,    0,    0,  112,  113,    0,   28,   13,
   54,   54,   28,   28,    0,   28,    0,   65,   65,   65,
   65,   65,   65,   28,   28,    0,    0,    0,    0,   28,
   13,   57,   57,   28,   28,    0,   28,   73,    0,   73,
   73,   73,    0,    0,   28,   28,   83,   37,    0,    0,
   38,   39,    0,   40,    0,   73,   73,    0,   73,    0,
    0,   41,   42,    0,   66,   83,   37,   66,    0,   38,
   39,    0,   40,    0,    0,    0,    0,    0,    0,    0,
   41,   42,   66,   66,    0,   66,    0,    0,   83,   37,
    0,   67,   38,   39,   67,   40,    0,    0,    0,    0,
    0,   58,   58,   41,   42,   58,   58,    0,   58,   67,
   67,    0,   67,    0,   90,   90,   58,   58,   90,   90,
   90,   90,   90,    0,   90,   91,   91,    0,    0,   91,
   91,   91,   91,   91,    0,   91,   90,   90,    0,   90,
    0,    0,    0,    0,    0,    0,    0,   91,   91,    0,
   91,   74,   74,    0,    0,   74,   74,   74,   74,   74,
    0,   74,   75,   75,    0,    0,   75,   75,   75,   75,
   75,   90,   75,   74,   74,    0,   74,    0,    0,    0,
    0,    0,   91,    0,   75,   75,    0,   75,   76,   76,
    0,    0,   76,   76,   76,   76,   76,    0,   76,   87,
    0,   90,   87,    0,   87,   87,   87,    0,   74,    0,
   76,   76,   91,   76,   92,    0,   92,   92,   92,   75,
   87,   87,   88,   87,    0,   88,    0,   88,   88,   88,
    0,    0,   92,   92,    0,   92,    0,    0,   74,    0,
    0,    0,    0,   88,   88,   76,   88,    0,   69,   75,
    0,   69,    0,    0,    0,   87,    0,    0,    0,    0,
   73,   73,   73,   73,   73,   73,   69,   69,    0,   69,
    0,    0,    0,    0,    0,   76,    0,   68,   88,    0,
   68,    0,    0,   70,    0,   87,   70,   66,   66,   66,
   66,   66,   66,    0,    0,   68,   68,   92,   68,    0,
    0,   70,   70,    0,   70,    0,    0,    0,   88,    0,
    0,    0,    0,    0,   67,   67,   67,   67,   67,   67,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   90,   90,   90,   90,   90,   90,    0,    0,    0,
    0,    0,   91,   91,   91,   91,   91,   91,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   74,   74,
   74,   74,   74,   74,    0,    0,    0,    0,    0,   75,
   75,   75,   75,   75,   75,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   76,   76,   76,   76,   76,
   76,    0,    0,    0,    0,   87,   87,   87,   87,   87,
   87,    0,    0,    0,    0,    0,    0,   92,   92,   92,
   92,   92,   92,    0,    0,    0,    0,    0,   88,   88,
   88,   88,   88,   88,    0,    0,   75,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   69,   69,   69,   69,   69,   69,   95,   96,   97,
    0,    0,    0,    0,  100,  101,  102,  103,    0,  104,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   68,   68,   68,   68,   68,   68,   70,   70,   70,   70,
   70,   70,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  141,  142,  143,  144,  145,  146,  147,  148,
  149,  150,  151,  152,  153,  154,  155,  156,  157,  158,
    0,  159,    0,    0,    0,    0,    0,    0,    0,  163,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  170,
};
static const YYINT yycheck[] = {                         33,
    0,   41,   36,   59,    0,   33,   40,  257,   36,   43,
  270,   45,   40,   41,   47,   43,   37,   45,   59,   41,
   93,   42,   44,   40,   40,   59,   47,   33,   41,   40,
   36,   44,   44,   41,   40,   41,   44,   43,   41,   45,
   52,   44,   33,   59,   61,   36,  274,  275,   81,   40,
   91,  257,   43,   41,   45,   88,   37,   38,   44,   91,
   41,   42,   43,   44,   45,   59,   47,  123,   41,   41,
   41,   44,   44,   44,   91,   91,  270,   40,   59,   60,
   91,   62,   40,   37,   38,   15,   59,   59,   42,   43,
   59,   45,  126,   47,   37,   38,   26,   41,  126,   42,
   44,   31,  135,  136,   47,   59,   60,   59,   62,   37,
   38,   93,  273,   94,   42,   43,  257,   45,   41,   47,
  126,   44,   52,   37,   38,  270,  273,  256,   42,  258,
  259,   59,   60,   47,   62,  126,   61,   93,  171,  256,
   94,  258,  259,  124,   37,   38,   59,  270,   41,   42,
   43,   94,   45,  256,   47,  258,  259,  256,  270,  258,
  259,   61,   59,   59,   93,  262,   94,   60,    0,   62,
  124,   93,   41,   26,    5,   52,   -1,   -1,   99,   -1,
   94,   37,   38,   -1,   -1,   41,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,
  256,   94,   -1,   -1,   60,   -1,   62,   -1,   -1,   -1,
  124,   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,   -1,
   -1,   -1,  256,  257,   -1,   -1,   -1,   -1,  256,  257,
   -1,  124,   -1,   -1,   -1,  257,  270,   -1,   94,  273,
   -1,   -1,  270,   -1,  257,  273,   -1,   -1,   -1,   -1,
  256,  257,   -1,  274,  275,   36,  256,  257,  258,  259,
  256,  257,  258,  259,  270,  256,  257,  273,  124,   -1,
   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,  270,
   47,   -1,  273,  264,  265,  266,  267,  268,  269,   -1,
   -1,   -1,   -1,  274,  275,  268,  269,  269,   -1,   37,
   38,   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,
  264,  265,  266,  267,  268,  269,   -1,   -1,   36,   -1,
  274,  275,   60,   -1,   62,   -1,   -1,   94,   -1,   -1,
   -1,  274,  275,   -1,   -1,   -1,  264,  265,  266,  267,
  268,  269,  123,   37,   38,   -1,  274,  275,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   94,  124,   -1,   -1,
  274,  275,   -1,   -1,   36,   59,   60,   -1,   62,   -1,
   -1,  264,  265,  266,  267,  268,  269,   -1,   -1,   37,
   38,  274,  275,   -1,   42,   43,  124,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   36,   -1,
   94,   59,   60,   -1,   62,  123,   -1,  125,  264,  265,
  266,  267,  268,  269,   -1,   37,   38,   -1,  274,  275,
   42,   43,   -1,   45,   -1,   47,   -1,   37,   38,   -1,
  124,   -1,   42,   43,   -1,   45,   94,   47,   60,   -1,
   62,   -1,   -1,   41,   -1,   43,   44,   45,   37,   38,
   60,  123,   62,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   59,   60,   -1,   62,   -1,  124,   -1,   36,   -1,
   -1,   60,   94,   62,   41,  256,  257,   44,   -1,  260,
  261,   -1,  263,   -1,   94,  123,   -1,  125,   -1,   36,
  271,  272,   59,   60,   -1,   62,   -1,   -1,   -1,   -1,
   -1,   -1,  124,   -1,   -1,   94,   36,  274,  275,   -1,
   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   36,  264,  265,  266,  267,
  268,  269,   -1,   -1,   -1,  124,  274,  275,  256,  257,
  258,  259,  260,  261,   -1,  263,   -1,   -1,   36,   -1,
   -1,   -1,   -1,  271,  272,  123,   -1,  125,   -1,   -1,
   -1,   36,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  264,  265,  266,  267,  268,  269,  123,   -1,  125,   -1,
  274,  275,   -1,   -1,  256,  257,   -1,   -1,  260,  261,
   -1,  263,   -1,  123,   -1,  125,   -1,   -1,   -1,  271,
  272,   -1,   -1,   -1,   -1,   -1,  264,  265,  266,  267,
  268,  269,  123,   -1,  125,   -1,  274,  275,  256,  257,
  258,  259,  260,  261,   -1,  263,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  271,  272,  123,   -1,  125,   -1,   -1,
   -1,   -1,  264,  265,  266,  267,  268,  269,  123,   -1,
  125,   -1,  274,  275,  264,  265,  266,  267,  268,   -1,
   -1,   -1,   -1,   -1,  274,  275,  264,  265,  266,  267,
  268,  269,   -1,   -1,   -1,  264,  265,  266,  267,   -1,
   -1,   -1,   -1,   -1,   -1,  274,  275,   -1,  256,  257,
  258,  259,  260,  261,   -1,  263,   -1,  264,  265,  266,
  267,  268,  269,  271,  272,   -1,   -1,   -1,   -1,  256,
  257,  258,  259,  260,  261,   -1,  263,   41,   -1,   43,
   44,   45,   -1,   -1,  271,  272,  256,  257,   -1,   -1,
  260,  261,   -1,  263,   -1,   59,   60,   -1,   62,   -1,
   -1,  271,  272,   -1,   41,  256,  257,   44,   -1,  260,
  261,   -1,  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  271,  272,   59,   60,   -1,   62,   -1,   -1,  256,  257,
   -1,   41,  260,  261,   44,  263,   -1,   -1,   -1,   -1,
   -1,  256,  257,  271,  272,  260,  261,   -1,  263,   59,
   60,   -1,   62,   -1,   37,   38,  271,  272,   41,   42,
   43,   44,   45,   -1,   47,   37,   38,   -1,   -1,   41,
   42,   43,   44,   45,   -1,   47,   59,   60,   -1,   62,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,
   62,   37,   38,   -1,   -1,   41,   42,   43,   44,   45,
   -1,   47,   37,   38,   -1,   -1,   41,   42,   43,   44,
   45,   94,   47,   59,   60,   -1,   62,   -1,   -1,   -1,
   -1,   -1,   94,   -1,   59,   60,   -1,   62,   37,   38,
   -1,   -1,   41,   42,   43,   44,   45,   -1,   47,   38,
   -1,  124,   41,   -1,   43,   44,   45,   -1,   94,   -1,
   59,   60,  124,   62,   41,   -1,   43,   44,   45,   94,
   59,   60,   38,   62,   -1,   41,   -1,   43,   44,   45,
   -1,   -1,   59,   60,   -1,   62,   -1,   -1,  124,   -1,
   -1,   -1,   -1,   59,   60,   94,   62,   -1,   41,  124,
   -1,   44,   -1,   -1,   -1,   94,   -1,   -1,   -1,   -1,
  264,  265,  266,  267,  268,  269,   59,   60,   -1,   62,
   -1,   -1,   -1,   -1,   -1,  124,   -1,   41,   94,   -1,
   44,   -1,   -1,   41,   -1,  124,   44,  264,  265,  266,
  267,  268,  269,   -1,   -1,   59,   60,  124,   62,   -1,
   -1,   59,   60,   -1,   62,   -1,   -1,   -1,  124,   -1,
   -1,   -1,   -1,   -1,  264,  265,  266,  267,  268,  269,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  264,  265,  266,  267,  268,  269,   -1,   -1,   -1,
   -1,   -1,  264,  265,  266,  267,  268,  269,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  264,  265,
  266,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,  264,
  265,  266,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  264,  265,  266,  267,  268,
  269,   -1,   -1,   -1,   -1,  264,  265,  266,  267,  268,
  269,   -1,   -1,   -1,   -1,   -1,   -1,  264,  265,  266,
  267,  268,  269,   -1,   -1,   -1,   -1,   -1,  264,  265,
  266,  267,  268,  269,   -1,   -1,   40,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  264,  265,  266,  267,  268,  269,   61,   62,   63,
   -1,   -1,   -1,   -1,   68,   69,   70,   71,   -1,   73,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  264,  265,  266,  267,  268,  269,  264,  265,  266,  267,
  268,  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  106,  107,  108,  109,  110,  111,  112,  113,
  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,
   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  133,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  161,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 276
#define YYUNDFTOKEN 302
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,"'$'","'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,
0,0,0,0,0,0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"IDENT","VOID","INT",
"WHILE","IF","ELSE","RETURN","EQ","NE","LE","GE","AND","OR","DECNUM","CONTINUE",
"BREAK","HEXNUM","LSHIFT","RSHIFT","UMINUS",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : decl_list",
"decl_list : decl_list decl",
"decl_list : decl",
"decl_list : error",
"decl : var_decl",
"decl : fun_decl",
"decl : error",
"var_decl : type_spec IDENT ';'",
"var_decl : type_spec IDENT '[' DECNUM ']' ';'",
"var_decl : error",
"type_spec : VOID",
"type_spec : INT",
"type_spec : error",
"fun_decl : type_spec IDENT '(' params ')' compound_stmt",
"fun_decl : type_spec IDENT '(' params ')' ';'",
"fun_decl : error",
"params : param_list",
"params : VOID",
"params : error",
"param_list : param_list ',' param",
"param_list : param",
"param_list : error",
"param : type_spec IDENT",
"param : type_spec IDENT '[' DECNUM ']'",
"param : error",
"stmt_list : stmt_list stmt",
"stmt_list : stmt",
"stmt_list : error",
"stmt : expr_stmt",
"stmt : block_stmt",
"stmt : if_stmt",
"stmt : while_stmt",
"stmt : return_stmt",
"stmt : continue_stmt",
"stmt : break_stmt",
"stmt : error",
"expr_stmt : IDENT '=' expr ';'",
"expr_stmt : IDENT '[' DECNUM ']' '=' expr ';'",
"expr_stmt : '$' HEXNUM '=' expr ';'",
"expr_stmt : IDENT '(' arg_list ')' ';'",
"expr_stmt : IDENT '(' ')' ';'",
"expr_stmt : error",
"while_stmt : WHILE '(' expr ')' stmt",
"while_stmt : error",
"block_stmt : '{' stmt_list '}'",
"block_stmt : error",
"compound_stmt : '{' local_decls stmt_list '}'",
"compound_stmt : '{' local_decls '}'",
"compound_stmt : '{' stmt_list '}'",
"compound_stmt : '{' '}'",
"compound_stmt : error",
"local_decls : local_decls local_decl",
"local_decls : local_decl",
"local_decls : error",
"local_decl : type_spec IDENT ';'",
"local_decl : type_spec IDENT '[' DECNUM ']' ';'",
"local_decl : error",
"if_stmt : IF '(' expr ')' stmt",
"if_stmt : IF '(' expr ')' stmt ELSE stmt",
"if_stmt : error",
"return_stmt : RETURN ';'",
"return_stmt : RETURN expr ';'",
"return_stmt : error",
"expr : expr OR expr",
"expr : expr EQ expr",
"expr : expr NE expr",
"expr : expr LE expr",
"expr : expr '<' expr",
"expr : expr GE expr",
"expr : expr '>' expr",
"expr : expr AND expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : '!' expr",
"expr : '-' expr",
"expr : '+' expr",
"expr : '$' HEXNUM",
"expr : '(' expr ')'",
"expr : IDENT",
"expr : IDENT '[' DECNUM ']'",
"expr : IDENT '(' arg_list ')'",
"expr : IDENT '(' ')'",
"expr : int_literal",
"expr : expr '&' expr",
"expr : expr '^' expr",
"expr : '~' expr",
"expr : expr LSHIFT expr",
"expr : expr RSHIFT expr",
"expr : expr '|' expr",
"expr : error",
"int_literal : DECNUM",
"int_literal : HEXNUM",
"int_literal : error",
"arg_list : arg_list ',' expr",
"arg_list : expr",
"arg_list : error",
"continue_stmt : CONTINUE ';'",
"continue_stmt : error",
"break_stmt : BREAK ';'",
"break_stmt : error",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 575 "minic.y"
/* 错误处理 */
yyerror(s)
char *s;
{
    fprintf(stderr, "line %d: syntax error: unexpected token '%s'\n", yylineno, yytext);
    syntax_err++;
}

int main()
{
    syntax_err = 0;
    funcount = 0;
    gcount = 0;
    ALL = (struct allFunc **)malloc(20 * sizeof(struct allFunc *));
    gVar = (struct globalVar **)malloc(20 * sizeof(struct globalVar *));
    printf("Generating MIPS code...\n");
    yyparse();
    prg_err = generateMIPS();
    total_err = lex_err + syntax_err + prg_err;
    if (total_err > 0)
        fprintf(stderr, "%d error(s) generated.\n", total_err);
    else
        printf("MIPS code generated.\n");
    return 0;
}
#line 639 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 1:
#line 70 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 1; yyval.node->procno = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 2:
#line 77 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 2; yyval.node->procno = 1;
                                    yyval.node->multiplicity = yystack.l_mark[-1].node->multiplicity + 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 3:
#line 83 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 2; yyval.node->procno = 2;
                                    yyval.node->multiplicity = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 5:
#line 92 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 3; yyval.node->procno = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 6:
#line 96 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 3; yyval.node->procno = 2;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 8:
#line 104 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->ntno = 4; yyval.node->procno = 1;
                                    strcpy(yyval.node->txt, yystack.l_mark[-1].text);
                                    yyval.node->lineno = yylineno;
                                    gVar[gcount] = (struct globalVar *)malloc(sizeof(struct globalVar));
                                    strcpy(gVar[gcount]->name, yystack.l_mark[-1].text); gVar[gcount]->space = 1;
                                    gVar[gcount]->t = yyval.node; gcount++;
                                }
break;
case 9:
#line 113 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-5].node; yystack.l_mark[-5].node->parent = yyval.node;
                                    yyval.node->ntno = 4; yyval.node->procno = 2;
                                    strcpy(yyval.node->txt, yystack.l_mark[-4].text); strcpy(yyval.node->numtxt, yystack.l_mark[-2].text);
                                    yyval.node->lineno = yylineno;
                                    gVar[gcount] = (struct globalVar *)malloc(sizeof(struct globalVar));
                                    strcpy(gVar[gcount]->name, yystack.l_mark[-4].text); gVar[gcount]->space = atoi(yystack.l_mark[-2].text);
                                    gVar[gcount]->t = yyval.node; gcount++;
                                }
break;
case 11:
#line 125 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 5; yyval.node->procno = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 12:
#line 128 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 5; yyval.node->procno = 2;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 14:
#line 136 "minic.y"
	{   yyval.node = makeNode(3); yyval.node->child[0] = yystack.l_mark[-5].node; yystack.l_mark[-5].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[2] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 6; yyval.node->procno = 1; strcpy(yyval.node->txt, yystack.l_mark[-4].text);
                                    ALL[funcount] = (struct allFunc *)malloc(sizeof(struct allFunc));
                                    strcpy(ALL[funcount]->name, yystack.l_mark[-4].text);
                                    ALL[funcount]->t = yyval.node; funcount++;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 15:
#line 146 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-5].node; yystack.l_mark[-5].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->ntno = 6; yyval.node->procno = 2; strcpy(yyval.node->txt, yystack.l_mark[-4].text);
                                    yyval.node->lineno = yylineno;
                                }
break;
case 17:
#line 155 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 7; yyval.node->procno = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 18:
#line 159 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 7; yyval.node->procno = 2;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 20:
#line 166 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 8; yyval.node->procno = 1;
                                    yyval.node->multiplicity = yystack.l_mark[-2].node->multiplicity + 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 21:
#line 172 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 8; yyval.node->procno = 2;
                                    yyval.node->multiplicity = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 23:
#line 181 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 9; yyval.node->procno = 1;
                                    strcpy(yyval.node->txt, yystack.l_mark[0].text);
                                    yyval.node->lineno = yylineno;
                                }
break;
case 24:
#line 187 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-4].node; yystack.l_mark[-4].node->parent = yyval.node;
                                    yyval.node->ntno = 9; yyval.node->procno = 2;
                                    strcpy(yyval.node->txt, yystack.l_mark[-3].text); strcpy(yyval.node->numtxt, yystack.l_mark[-1].text);
                                    yyval.node->lineno = yylineno;
                                }
break;
case 26:
#line 196 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 10; yyval.node->procno = 1;
                                    yyval.node->multiplicity = yystack.l_mark[-1].node->multiplicity + 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 27:
#line 202 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 10; yyval.node->procno = 2;
                                    yyval.node->multiplicity = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 29:
#line 211 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 30:
#line 215 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 2;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 31:
#line 219 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 3;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 32:
#line 223 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 4;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 33:
#line 227 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 5;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 34:
#line 231 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 6;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 35:
#line 235 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 7;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 37:
#line 243 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 12; yyval.node->procno = 1;
                                    strcpy(yyval.node->txt, yystack.l_mark[-3].text);
                                    yyval.node->lineno = yylineno;
                                }
break;
case 38:
#line 249 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 12; yyval.node->procno = 2;
                                    strcpy(yyval.node->txt, yystack.l_mark[-6].text); strcpy(yyval.node->numtxt, yystack.l_mark[-4].text);
                                    yyval.node->lineno = yylineno;
                                }
break;
case 39:
#line 254 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 12; yyval.node->procno = 3;
                                    strcpy(yyval.node->numtxt, yystack.l_mark[-3].text);
                                    yyval.node->lineno = yylineno;
                                }
break;
case 40:
#line 260 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->ntno = 12; yyval.node->procno = 4;
                                    strcpy(yyval.node->txt, yystack.l_mark[-4].text);
                                    yyval.node->lineno = yylineno;
                                }
break;
case 41:
#line 266 "minic.y"
	{   yyval.node = makeNode(0);
                                    yyval.node->ntno = 12; yyval.node->procno = 5;
                                    strcpy(yyval.node->txt, yystack.l_mark[-3].text);
                                    yyval.node->lineno = yylineno;
                                }
break;
case 43:
#line 275 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 13; yyval.node->procno = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 45:
#line 284 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 14; yyval.node->procno = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 47:
#line 293 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 15; yyval.node->procno = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 48:
#line 298 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 15; yyval.node->procno = 2;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 49:
#line 302 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 15; yyval.node->procno = 3;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 50:
#line 306 "minic.y"
	{   yyval.node = makeNode(0);
                                    yyval.node->ntno = 15; yyval.node->procno = 4;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 52:
#line 314 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 16; yyval.node->procno = 1;
                                    yyval.node->multiplicity = yystack.l_mark[-1].node->multiplicity + 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 53:
#line 320 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 16; yyval.node->procno = 2;
                                    yyval.node->multiplicity = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 55:
#line 329 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->ntno = 17; yyval.node->procno = 1;
                                    strcpy(yyval.node->txt, yystack.l_mark[-1].text);
                                    yyval.node->lineno = yylineno;
                                }
break;
case 56:
#line 335 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-5].node; yystack.l_mark[-5].node->parent = yyval.node;
                                    yyval.node->ntno = 17; yyval.node->procno = 2;
                                    strcpy(yyval.node->txt, yystack.l_mark[-4].text); strcpy(yyval.node->numtxt, yystack.l_mark[-2].text);
                                    yyval.node->lineno = yylineno;
                                }
break;
case 58:
#line 345 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 18; yyval.node->procno = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 59:
#line 351 "minic.y"
	{   yyval.node = makeNode(3); yyval.node->child[0] = yystack.l_mark[-4].node; yystack.l_mark[-4].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[2] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 18; yyval.node->procno = 2;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 61:
#line 361 "minic.y"
	{   yyval.node = makeNode(0);
                                    yyval.node->ntno = 19; yyval.node->procno = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 62:
#line 365 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 19; yyval.node->procno = 2;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 64:
#line 373 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 1;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 65:
#line 379 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 2;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 66:
#line 385 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 3;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 67:
#line 391 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 4;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 68:
#line 397 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 5;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 69:
#line 403 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 6;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 70:
#line 409 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 7;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 71:
#line 415 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 8;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 72:
#line 421 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 9;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 73:
#line 427 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 10;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 74:
#line 433 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 11;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 75:
#line 439 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 12;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 76:
#line 445 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 13;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 77:
#line 451 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 14;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 78:
#line 456 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 15;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 79:
#line 461 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 16;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 80:
#line 466 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 20; yyval.node->procno = 17;
                                    strcpy(yyval.node->numtxt, yystack.l_mark[0].text);
                                    yyval.node->lineno = yylineno;
                                }
break;
case 81:
#line 470 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 18;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 82:
#line 475 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 20; yyval.node->procno = 19;
                                    strcpy(yyval.node->txt, yystack.l_mark[0].text);
                                    yyval.node->lineno = yylineno;
                                }
break;
case 83:
#line 479 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 20; yyval.node->procno = 20;
                                    strcpy(yyval.node->txt, yystack.l_mark[-3].text); strcpy(yyval.node->numtxt, yystack.l_mark[-1].text);
                                    yyval.node->lineno = yylineno;
        
                                }
break;
case 84:
#line 484 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 21; strcpy(yyval.node->txt, yystack.l_mark[-3].text);
                                    yyval.node->lineno = yylineno;
                                }
break;
case 85:
#line 488 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 20; yyval.node->procno = 22;
                                    strcpy(yyval.node->txt, yystack.l_mark[-2].text);
                                    yyval.node->lineno = yylineno;
                                }
break;
case 86:
#line 492 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 23;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 87:
#line 496 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 24;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 88:
#line 502 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 25;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 89:
#line 508 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 26;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 90:
#line 513 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 27;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 91:
#line 519 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 28;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 92:
#line 525 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 29;
                                    yyval.node->contain_expr = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 94:
#line 535 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 21; yyval.node->procno = 1;
                                    strcpy(yyval.node->numtxt, yystack.l_mark[0].text);
                                    yyval.node->lineno = yylineno;
                                }
break;
case 95:
#line 539 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 21; yyval.node->procno = 2;
                                    strcpy(yyval.node->numtxt, yystack.l_mark[0].text);
                                    yyval.node->lineno = yylineno;
                                }
break;
case 97:
#line 547 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 22; yyval.node->procno = 1;
                                    yyval.node->multiplicity = yystack.l_mark[-2].node->multiplicity + 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 98:
#line 553 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 22; yyval.node->procno = 2;
                                    yyval.node->multiplicity = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 100:
#line 562 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 23; yyval.node->procno = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
case 102:
#line 569 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 24; yyval.node->procno = 1;
                                    yyval.node->lineno = yylineno;
                                }
break;
#line 1478 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}

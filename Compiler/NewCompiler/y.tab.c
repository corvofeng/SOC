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
extern char * yytext;
extern int yylineno;
extern int totalError;
int syntaxError, funcount, gcount;
struct allFunc **ALL;
struct globalVar **gVar;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 33 "minic.y"
typedef union{
        struct AST *node;	/* 非终结符语义值类型*/

        struct terminal{	/* 终结符语义值类型*/
            char *text;
        } Sval;

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 45 "y.tab.c"

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
   12,   12,   13,   13,   14,   14,   14,   14,   14,   15,
   15,   15,   16,   16,   16,   17,   17,   17,   18,   18,
   18,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   20,   20,   20,   21,   21,   21,   22,   22,   23,
   23,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    1,    1,    1,    1,    3,    6,    1,
    1,    1,    1,    6,    6,    1,    1,    1,    1,    3,
    1,    1,    2,    5,    1,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    4,    7,    5,    1,
    5,    1,    3,    1,    4,    3,    3,    2,    1,    2,
    1,    1,    3,    6,    1,    5,    7,    1,    2,    3,
    1,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    2,    2,    2,    2,    3,    1,
    4,    4,    3,    1,    3,    3,    2,    3,    3,    3,
    1,    1,    1,    1,    3,    1,    1,    2,    1,    2,
    1,
};
static const YYINT yydefred[] = {                         0,
    0,   11,   12,    0,    0,    3,    5,    0,    6,    0,
    2,    0,    8,    0,    0,    0,    0,    0,    0,    0,
    0,   21,    0,    0,    0,    0,    9,    0,   49,   15,
    0,   14,    0,   20,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   48,    0,    0,   27,   29,   32,
   30,    0,   51,   31,   33,   34,   35,   24,    0,    0,
    0,    0,   91,    0,   92,   93,    0,    0,    0,    0,
   59,    0,    0,    0,   84,   98,  100,    0,   28,    0,
    0,   36,   46,   26,    0,   47,    0,   50,    0,    0,
    0,    0,    0,    0,   77,   76,   75,   87,    0,   78,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   60,    0,
   43,   53,    0,   45,    0,   37,    0,    0,    0,   91,
   83,    0,    0,   79,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   41,    0,   81,   82,    0,
   39,    0,    0,    0,    0,   54,   38,   57,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,    8,    9,   20,   21,   22,   47,   48,
   49,   50,   51,   32,   52,   53,   54,   55,   74,   75,
  133,   56,   57,
};
static const YYINT yysindex[] = {                      -169,
    0,    0,    0,    0, -139,    0,    0, -249,    0,    0,
    0,  -13,    0, -245, -134,  -56,    0,    0, -215,   11,
   13,    0,   -1,  -28,  -35,  -86,    0, -197,    0,    0,
  249,    0,    0,    0,   -9,    0,  -50,   45,   56,  -33,
   38,   42,   -5,  519,    0, -155,  293,    0,    0,    0,
    0,  339,    0,    0,    0,    0,    0,    0, -163,   -5,
   -5,   -5,    0,  -19,    0,    0,   -5,   -5,   -5,   -5,
    0,   -5,   -5,   32,    0,    0,    0,   67,    0,  376,
  -55,    0,    0,    0,    0,    0,  411,    0,   15,   95,
  121,  160, -152,  -27,    0,    0,    0,    0,  277,    0,
   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,
   -5,   -5,   -5,   -5,   -5,   -5,   -5,   -5,    0,   -5,
    0,    0, -147,    0,   74,    0,  532,  532,   43,    0,
    0,  395,   39,    0,   17,   17,   17,   17,  435,  423,
 -242, -242,   17,   17,   -8,   -8,  106,   34,   34, -242,
 -242, -242,  306,   46,   -5,    0, -117,    0,    0,   -5,
    0,   87,  360,  532,  395,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    1,    0,    0,    0,  147,    0,    0,    0,    0,    5,
    0,    0,    0,    0,    0,    0,  -24,  -39,    0,    0,
  109,    0,    0,   62,    0,    0,    0,    0,    0,    0,
    0,    0,  -22,    0,    0,  460,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    6,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  478,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   90,    0,    0,  737,  823,  896,  910,  108,   54,
  764,  775,  953,  975,  699,  724,  872,  859,  885,  801,
  812,  849,    0,    0,    0,    0,  491,    0,    0,    0,
    0,    0,    0,    0,  130,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  146,    0,   30,    0,    0,    0,  134,  -29,  161,
    0,    0,    0,    0,    0,  113,    0,    0, 1163,    0,
    0,    0,    0,
};
#define YYTABLESIZE 1323
static const YYINT yytable[] = {                         69,
    4,   18,   73,  122,    7,   69,   72,   12,   73,   67,
   60,   68,   72,  131,   80,   67,   19,   68,   25,   22,
   94,   25,   87,   30,   16,   71,   15,   69,  118,  114,
   73,  107,  108,  116,   72,  123,   23,   67,  117,   68,
   59,   24,   80,   80,   19,   13,   80,   80,   80,   80,
   80,   25,   80,  118,  114,   19,   26,   27,  116,  111,
   46,  112,   28,  117,   80,   80,   80,   80,  118,  114,
  118,   93,   35,  116,  111,  116,  112,   14,  117,  159,
  117,   46,  160,   58,   61,  115,    1,   31,    2,    3,
  119,  109,   70,  110,   62,   62,   76,   62,   70,   80,
   77,   81,   23,  118,  114,   23,   89,  125,  116,  111,
  115,  112,   62,  117,   62,  113,   10,  129,    2,    3,
   70,   17,  154,   18,    3,  115,  109,  120,  110,   80,
   96,  118,  114,   96,  155,  158,  116,  111,  162,  112,
  113,  117,  118,  114,  164,  166,    1,  116,   69,   17,
   11,   69,  117,  126,  109,  113,  110,  118,  114,   34,
  115,  127,  116,  111,   88,  112,   69,  117,   69,   33,
   95,    2,    3,   95,    0,    0,    0,    0,    0,    0,
  109,    0,  110,    0,    0,    0,    0,    0,  115,    0,
  113,    0,    0,    0,    0,    0,  118,  114,    0,  115,
  128,  116,  111,    0,  112,    0,  117,   84,    0,    0,
    0,    0,    0,    0,  115,    0,    0,   11,  113,  109,
   29,  110,   63,   64,    0,    0,    0,    0,  130,   64,
    0,    0,   13,    0,   13,    0,   65,    0,    0,   66,
   84,    0,   65,    0,  113,   66,    0,   84,    0,    0,
   63,   64,    0,  115,    0,    0,    4,   13,    4,    4,
    7,   13,    7,    7,   65,  107,  108,   66,    0,   80,
   80,   80,   80,   80,   80,    0,    0,    0,    0,   80,
   80,    0,    0,  113,   43,    0,    0,  156,  157,    0,
  107,  108,    0,    0,    0,  101,  102,  103,  104,  105,
  106,    0,    0,    0,    0,  107,  108,  107,  108,    0,
    0,    0,    0,  118,  114,    0,    0,  134,  116,  111,
    0,  112,   62,  117,  168,    0,    0,    0,   43,    0,
  101,  102,  103,  104,  105,  106,  109,    0,  110,    0,
  107,  108,  118,  114,    0,    0,    0,  116,  111,    0,
  112,    0,  117,    0,    0,    0,    0,    0,  101,  102,
  103,  104,  105,  106,  161,  109,    0,  110,  107,  108,
  115,   44,    0,   45,   43,   69,   69,    0,    0,  107,
  108,    0,    0,    0,  101,  102,  103,  104,  105,  106,
    0,    0,    0,    0,  107,  108,  118,  114,    0,  115,
  113,  116,  111,    0,  112,    0,  117,    0,    0,    0,
    0,   43,    0,    0,    0,   44,    0,   83,  167,  109,
    0,  110,    0,  101,  102,  103,  104,  105,  106,  113,
    0,  118,  114,  107,  108,    0,  116,  111,    0,  112,
    0,  117,    0,    0,    0,    0,   43,    0,    0,    0,
    0,    0,    0,  115,  109,    0,  110,    0,    0,  118,
  114,   44,    0,   86,  116,  111,    0,  112,    0,  117,
    0,  118,  114,    0,    0,    0,  116,  111,    0,  112,
    0,  117,  109,  113,  110,    0,    0,    0,  115,    0,
    0,    0,    0,    0,  109,   28,  110,    0,   44,    0,
  121,    0,    0,    0,   36,   37,    2,    3,   38,   39,
    0,   40,    0,   28,    0,    0,  115,    0,  113,   41,
   42,    0,    0,    0,    0,    0,   56,    0,  115,    0,
    0,    0,    0,   44,    0,  124,    0,    0,    0,    0,
  101,  102,  103,  104,  105,  106,  113,    0,   82,   37,
  107,  108,   38,   39,   43,   40,    0,    0,  113,    0,
    0,    0,    0,   41,   42,    0,    0,   43,    0,  101,
  102,  103,  104,  105,  106,    0,    0,    0,    0,  107,
  108,    0,   28,    0,   28,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   85,   37,    2,    3,   38,   39,
   28,   40,   28,    0,    0,    0,    0,    0,    0,   41,
   42,    0,    0,   56,    0,   56,    0,    0,    0,    0,
    0,    0,    0,  101,  102,  103,  104,  105,  106,    0,
    0,   82,   37,  107,  108,   38,   39,    0,   40,    0,
    0,   44,    0,    0,    0,    0,   41,   42,    0,    0,
    0,    0,    0,    0,   44,    0,    0,    0,  101,  102,
  103,  104,  105,  106,    0,    0,   82,   37,  107,  108,
   38,   39,    0,   40,    0,    0,    0,    0,    0,    0,
    0,   41,   42,    0,    0,    0,  101,  102,  103,  104,
  105,    0,    0,    0,    0,    0,  107,  108,  101,  102,
  103,  104,    0,    0,    0,    0,    0,    0,  107,  108,
    0,    0,    0,    0,    0,   28,   13,   52,   52,   28,
   28,    0,   28,    0,    0,    0,    0,    0,    0,    0,
   28,   28,    0,   28,   13,   55,   55,   28,   28,   70,
   28,   70,   70,   70,    0,    0,   56,   56,   28,   28,
   56,   56,    0,   56,    0,    0,    0,   70,   70,   70,
   70,   56,   56,    0,   71,    0,   71,   71,   71,    0,
    0,    0,    0,    0,   79,   37,    0,   63,   38,   39,
   63,   40,   71,   71,   71,   71,    0,   82,   37,   41,
   42,   38,   39,    0,   40,   63,   63,   63,   63,    0,
   88,   88,   41,   42,   88,   88,   88,   88,   88,    0,
   88,   89,   89,    0,    0,   89,   89,   89,   89,   89,
    0,   89,   88,   88,   88,   88,    0,    0,    0,    0,
    0,    0,    0,   89,   89,   89,   89,   72,   72,    0,
    0,   72,   72,   72,   72,   72,    0,   72,   73,   73,
    0,    0,   73,   73,   73,   73,   73,   88,   73,   72,
   72,   72,   72,   64,    0,    0,   64,    0,   89,    0,
   73,   73,   73,   73,    0,    0,    0,    0,    0,    0,
    0,   64,   64,   64,   64,   74,   74,   88,    0,   74,
   74,   74,   74,   74,   72,   74,   85,    0,   89,   85,
    0,   85,   85,   85,    0,   73,    0,   74,   74,   74,
   74,    0,   90,    0,   90,   90,   90,   85,   85,   85,
   85,    0,   86,    0,   72,   86,    0,   86,   86,   86,
   90,   90,   90,   90,    0,   73,   65,    0,    0,   65,
    0,    0,   74,   86,   86,   86,   86,    0,    0,    0,
   67,    0,   85,   67,   65,   65,   65,   65,    0,    0,
    0,    0,   70,   70,   70,   70,   70,   70,   67,   67,
   67,   67,   74,    0,    0,    0,    0,    0,   86,    0,
    0,    0,   85,    0,    0,    0,    0,   71,   71,   71,
   71,   71,   71,   66,    0,   90,   66,    0,    0,    0,
   63,   63,   63,   63,   63,   63,    0,    0,   86,    0,
    0,   66,   66,   66,   66,   68,    0,    0,   68,    0,
    0,    0,    0,    0,    0,    0,    0,   88,   88,   88,
   88,   88,   88,   68,   68,   68,   68,    0,   89,   89,
   89,   89,   89,   89,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   72,   72,   72,   72,   72,   72,
    0,    0,    0,    0,    0,   73,   73,   73,   73,   73,
   73,    0,    0,    0,    0,    0,   64,   64,   64,   64,
   64,   64,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   74,   74,   74,   74,   74,   74,    0,    0,
    0,    0,   85,   85,   85,   85,   85,   85,    0,    0,
    0,    0,    0,    0,    0,   90,   90,   90,   90,   90,
   90,    0,    0,    0,    0,    0,    0,    0,   86,   86,
   86,   86,   86,   86,    0,    0,    0,    0,    0,   65,
   65,   65,   65,   65,   65,    0,    0,    0,    0,    0,
    0,    0,    0,   67,   67,   67,   67,   67,   67,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   78,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   66,   66,   66,   66,
   66,   66,   90,   91,   92,    0,    0,    0,    0,   95,
   96,   97,   98,    0,   99,  100,    0,    0,   68,   68,
   68,   68,   68,   68,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  132,    0,    0,    0,
    0,    0,    0,  135,  136,  137,  138,  139,  140,  141,
  142,  143,  144,  145,  146,  147,  148,  149,  150,  151,
  152,    0,  153,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  163,    0,    0,
    0,    0,  165,
};
static const YYINT yycheck[] = {                         33,
    0,   41,   36,   59,    0,   33,   40,  257,   36,   43,
   61,   45,   40,   41,   44,   43,   41,   45,   41,   44,
   40,   44,   52,   59,  270,   59,   40,   33,   37,   38,
   36,  274,  275,   42,   40,   91,   93,   43,   47,   45,
   91,  257,   37,   38,   15,   59,   41,   42,   43,   44,
   45,   41,   47,   37,   38,   26,   44,   59,   42,   43,
   31,   45,   91,   47,   59,   60,   61,   62,   37,   38,
   37,   91,  270,   42,   43,   42,   45,   91,   47,   41,
   47,   52,   44,   93,   40,   94,  256,  123,  258,  259,
   59,   60,  126,   62,   41,   40,   59,   44,  126,   94,
   59,  257,   41,   37,   38,   44,  270,   93,   42,   43,
   94,   45,   59,   47,   61,  124,  256,  270,  258,  259,
  126,  256,  270,  258,  259,   94,   60,   61,   62,  124,
   41,   37,   38,   44,   61,   93,   42,   43,   93,   45,
  124,   47,   37,   38,  262,   59,    0,   42,   41,   41,
    5,   44,   47,   59,   60,  124,   62,   37,   38,   26,
   94,   41,   42,   43,   52,   45,   59,   47,   61,  256,
   41,  258,  259,   44,   -1,   -1,   -1,   -1,   -1,   -1,
   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,   94,   -1,
  124,   -1,   -1,   -1,   -1,   -1,   37,   38,   -1,   94,
   41,   42,   43,   -1,   45,   -1,   47,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   94,   -1,   -1,  257,  124,   60,
  256,   62,  256,  257,   -1,   -1,   -1,   -1,  256,  257,
   -1,   -1,  257,   -1,  257,   -1,  270,   -1,   -1,  273,
   80,   -1,  270,   -1,  124,  273,   -1,   87,   -1,   -1,
  256,  257,   -1,   94,   -1,   -1,  256,  257,  258,  259,
  256,  257,  258,  259,  270,  274,  275,  273,   -1,  264,
  265,  266,  267,  268,  269,   -1,   -1,   -1,   -1,  274,
  275,   -1,   -1,  124,   36,   -1,   -1,  127,  128,   -1,
  274,  275,   -1,   -1,   -1,  264,  265,  266,  267,  268,
  269,   -1,   -1,   -1,   -1,  274,  275,  274,  275,   -1,
   -1,   -1,   -1,   37,   38,   -1,   -1,   41,   42,   43,
   -1,   45,  269,   47,  164,   -1,   -1,   -1,   36,   -1,
  264,  265,  266,  267,  268,  269,   60,   -1,   62,   -1,
  274,  275,   37,   38,   -1,   -1,   -1,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,  264,  265,
  266,  267,  268,  269,   59,   60,   -1,   62,  274,  275,
   94,  123,   -1,  125,   36,  268,  269,   -1,   -1,  274,
  275,   -1,   -1,   -1,  264,  265,  266,  267,  268,  269,
   -1,   -1,   -1,   -1,  274,  275,   37,   38,   -1,   94,
  124,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
   -1,   36,   -1,   -1,   -1,  123,   -1,  125,   59,   60,
   -1,   62,   -1,  264,  265,  266,  267,  268,  269,  124,
   -1,   37,   38,  274,  275,   -1,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   -1,   36,   -1,   -1,   -1,
   -1,   -1,   -1,   94,   60,   -1,   62,   -1,   -1,   37,
   38,  123,   -1,  125,   42,   43,   -1,   45,   -1,   47,
   -1,   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,
   -1,   47,   60,  124,   62,   -1,   -1,   -1,   94,   -1,
   -1,   -1,   -1,   -1,   60,   36,   62,   -1,  123,   -1,
  125,   -1,   -1,   -1,  256,  257,  258,  259,  260,  261,
   -1,  263,   -1,   36,   -1,   -1,   94,   -1,  124,  271,
  272,   -1,   -1,   -1,   -1,   -1,   36,   -1,   94,   -1,
   -1,   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,
  264,  265,  266,  267,  268,  269,  124,   -1,  256,  257,
  274,  275,  260,  261,   36,  263,   -1,   -1,  124,   -1,
   -1,   -1,   -1,  271,  272,   -1,   -1,   36,   -1,  264,
  265,  266,  267,  268,  269,   -1,   -1,   -1,   -1,  274,
  275,   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  256,  257,  258,  259,  260,  261,
  123,  263,  125,   -1,   -1,   -1,   -1,   -1,   -1,  271,
  272,   -1,   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  264,  265,  266,  267,  268,  269,   -1,
   -1,  256,  257,  274,  275,  260,  261,   -1,  263,   -1,
   -1,  123,   -1,   -1,   -1,   -1,  271,  272,   -1,   -1,
   -1,   -1,   -1,   -1,  123,   -1,   -1,   -1,  264,  265,
  266,  267,  268,  269,   -1,   -1,  256,  257,  274,  275,
  260,  261,   -1,  263,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  271,  272,   -1,   -1,   -1,  264,  265,  266,  267,
  268,   -1,   -1,   -1,   -1,   -1,  274,  275,  264,  265,
  266,  267,   -1,   -1,   -1,   -1,   -1,   -1,  274,  275,
   -1,   -1,   -1,   -1,   -1,  256,  257,  258,  259,  260,
  261,   -1,  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  271,  272,   -1,  256,  257,  258,  259,  260,  261,   41,
  263,   43,   44,   45,   -1,   -1,  256,  257,  271,  272,
  260,  261,   -1,  263,   -1,   -1,   -1,   59,   60,   61,
   62,  271,  272,   -1,   41,   -1,   43,   44,   45,   -1,
   -1,   -1,   -1,   -1,  256,  257,   -1,   41,  260,  261,
   44,  263,   59,   60,   61,   62,   -1,  256,  257,  271,
  272,  260,  261,   -1,  263,   59,   60,   61,   62,   -1,
   37,   38,  271,  272,   41,   42,   43,   44,   45,   -1,
   47,   37,   38,   -1,   -1,   41,   42,   43,   44,   45,
   -1,   47,   59,   60,   61,   62,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,   60,   61,   62,   37,   38,   -1,
   -1,   41,   42,   43,   44,   45,   -1,   47,   37,   38,
   -1,   -1,   41,   42,   43,   44,   45,   94,   47,   59,
   60,   61,   62,   41,   -1,   -1,   44,   -1,   94,   -1,
   59,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   59,   60,   61,   62,   37,   38,  124,   -1,   41,
   42,   43,   44,   45,   94,   47,   38,   -1,  124,   41,
   -1,   43,   44,   45,   -1,   94,   -1,   59,   60,   61,
   62,   -1,   41,   -1,   43,   44,   45,   59,   60,   61,
   62,   -1,   38,   -1,  124,   41,   -1,   43,   44,   45,
   59,   60,   61,   62,   -1,  124,   41,   -1,   -1,   44,
   -1,   -1,   94,   59,   60,   61,   62,   -1,   -1,   -1,
   41,   -1,   94,   44,   59,   60,   61,   62,   -1,   -1,
   -1,   -1,  264,  265,  266,  267,  268,  269,   59,   60,
   61,   62,  124,   -1,   -1,   -1,   -1,   -1,   94,   -1,
   -1,   -1,  124,   -1,   -1,   -1,   -1,  264,  265,  266,
  267,  268,  269,   41,   -1,  124,   44,   -1,   -1,   -1,
  264,  265,  266,  267,  268,  269,   -1,   -1,  124,   -1,
   -1,   59,   60,   61,   62,   41,   -1,   -1,   44,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  264,  265,  266,
  267,  268,  269,   59,   60,   61,   62,   -1,  264,  265,
  266,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  264,  265,  266,  267,  268,  269,
   -1,   -1,   -1,   -1,   -1,  264,  265,  266,  267,  268,
  269,   -1,   -1,   -1,   -1,   -1,  264,  265,  266,  267,
  268,  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  264,  265,  266,  267,  268,  269,   -1,   -1,
   -1,   -1,  264,  265,  266,  267,  268,  269,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  264,  265,  266,  267,  268,
  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  264,  265,
  266,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,  264,
  265,  266,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  264,  265,  266,  267,  268,  269,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   43,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  264,  265,  266,  267,
  268,  269,   60,   61,   62,   -1,   -1,   -1,   -1,   67,
   68,   69,   70,   -1,   72,   73,   -1,   -1,  264,  265,
  266,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   94,   -1,   -1,   -1,
   -1,   -1,   -1,  101,  102,  103,  104,  105,  106,  107,
  108,  109,  110,  111,  112,  113,  114,  115,  116,  117,
  118,   -1,  120,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  155,   -1,   -1,
   -1,   -1,  160,
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
"expr_stmt : '$' expr '=' expr ';'",
"expr_stmt : error",
"while_stmt : WHILE '(' expr ')' stmt",
"while_stmt : error",
"block_stmt : '{' stmt_list '}'",
"block_stmt : error",
"compound_stmt : '{' local_decls stmt_list '}'",
"compound_stmt : '{' stmt_list '}'",
"compound_stmt : '{' local_decls '}'",
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
"expr : '$' expr",
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
#line 486 "minic.y"
// 错误处理
yyerror(s)
char *s;
{
    printf("line %d: syntax error: unexpected token '%s'\n", yylineno, yytext);
    fflush(stdout);
    syntaxError++;
    return 0;
}

int main()
{
    syntaxError = 0;
    funcount = 0;
    gcount = 0;
    ALL = (struct allFunc **)malloc(20 * sizeof(struct allFunc *));
    gVar = (struct globalVar **)malloc(20 * sizeof(struct globalVar *));
    yyparse();
    if (syntaxError > 0) {
        printf("Total count of syntax error: %d\n", syntaxError);
        fflush(stdout);
    }
    else if (totalError == 0) {
        printf("Generating MIPS code...\n");
        GenerateMIPS();
        printf("MIPS code generated.\n");
    }
    return 0;
}
#line 656 "y.tab.c"

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
#line 75 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 1; yyval.node->procno = 1;
                                }
break;
case 2:
#line 81 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 2; yyval.node->procno = 1;
                                    yyval.node->multiplicity = yystack.l_mark[-1].node->multiplicity + 1;
                                }
break;
case 3:
#line 86 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 2; yyval.node->procno = 2;
                                    yyval.node->multiplicity = 1;
                                }
break;
case 5:
#line 94 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 3; yyval.node->procno = 1;
                                }
break;
case 6:
#line 97 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 3; yyval.node->procno = 2;
                                }
break;
case 8:
#line 104 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->ntno = 4; yyval.node->procno = 1;
                                    strcpy(yyval.node->txt, yystack.l_mark[-1].Sval.text);
                                    gVar[gcount] = (struct globalVar *)malloc(sizeof(struct globalVar));
                                    strcpy(gVar[gcount]->name, yystack.l_mark[-1].Sval.text);
                                    gVar[gcount]->space = 1; gcount++;
                                }
break;
case 9:
#line 112 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-5].node; yystack.l_mark[-5].node->parent = yyval.node;
                                    yyval.node->ntno = 4; yyval.node->procno = 2;
                                    strcpy(yyval.node->txt, yystack.l_mark[-4].Sval.text); strcpy(yyval.node->numtxt, yystack.l_mark[-2].Sval.text);
                                    gVar[gcount] = (struct globalVar *)malloc(sizeof(struct globalVar));
                                    strcpy(gVar[gcount]->name, yystack.l_mark[-4].Sval.text);
                                    gVar[gcount]->space = atoi(yystack.l_mark[-2].Sval.text); gcount++;
                                }
break;
case 11:
#line 123 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 5; yyval.node->procno = 1; }
break;
case 12:
#line 124 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 5; yyval.node->procno = 2; }
break;
case 14:
#line 130 "minic.y"
	{   yyval.node = makeNode(3); yyval.node->child[0] = yystack.l_mark[-5].node; yystack.l_mark[-5].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[2] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 6; yyval.node->procno = 1; strcpy(yyval.node->txt, yystack.l_mark[-4].Sval.text);
                                    ALL[funcount] = (struct allFunc *)malloc(sizeof(struct allFunc));
                                    strcpy(ALL[funcount]->name, yystack.l_mark[-4].Sval.text);
                                    ALL[funcount]->t = yyval.node; funcount++;
                                }
break;
case 15:
#line 139 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-5].node; yystack.l_mark[-5].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->ntno = 6; yyval.node->procno = 2; strcpy(yyval.node->txt, yystack.l_mark[-4].Sval.text);
                                }
break;
case 17:
#line 147 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 7; yyval.node->procno = 1;
                                }
break;
case 18:
#line 150 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 7; yyval.node->procno = 2; }
break;
case 20:
#line 155 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 8; yyval.node->procno = 1;
                                    yyval.node->multiplicity = yystack.l_mark[-2].node->multiplicity + 1;
                                }
break;
case 21:
#line 160 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 8; yyval.node->procno = 2;
                                    yyval.node->multiplicity = 1;
                                }
break;
case 23:
#line 168 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 9; yyval.node->procno = 1;
                                    strcpy(yyval.node->txt, yystack.l_mark[0].Sval.text);
                                }
break;
case 24:
#line 173 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-4].node; yystack.l_mark[-4].node->parent = yyval.node;
                                    yyval.node->ntno = 9; yyval.node->procno = 2;
                                    strcpy(yyval.node->txt, yystack.l_mark[-3].Sval.text); strcpy(yyval.node->numtxt, yystack.l_mark[-1].Sval.text);
                                }
break;
case 26:
#line 181 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 10; yyval.node->procno = 1;
                                    yyval.node->multiplicity = yystack.l_mark[-1].node->multiplicity + 1;
                                }
break;
case 27:
#line 186 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 10; yyval.node->procno = 2;
                                    yyval.node->multiplicity = 1;
                                }
break;
case 29:
#line 194 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 1;
                                }
break;
case 30:
#line 197 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 2;
                                }
break;
case 31:
#line 200 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 3;
                                }
break;
case 32:
#line 203 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 4;
                                }
break;
case 33:
#line 206 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 5;
                                }
break;
case 34:
#line 209 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 6;
                                }
break;
case 35:
#line 212 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 7;
                                }
break;
case 37:
#line 219 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 12; yyval.node->procno = 1;
                                    strcpy(yyval.node->txt, yystack.l_mark[-3].Sval.text);
                                }
break;
case 38:
#line 224 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 12; yyval.node->procno = 2;
                                    strcpy(yyval.node->txt, yystack.l_mark[-6].Sval.text); strcpy(yyval.node->numtxt, yystack.l_mark[-4].Sval.text);
                                }
break;
case 39:
#line 228 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-3].node; yystack.l_mark[-3].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 12; yyval.node->procno = 3;
                                }
break;
case 41:
#line 236 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 13; yyval.node->procno = 1;
                                }
break;
case 43:
#line 244 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 14; yyval.node->procno = 1;
                                }
break;
case 45:
#line 252 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 15; yyval.node->procno = 1;
                                }
break;
case 46:
#line 256 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 15; yyval.node->procno = 2;
                                }
break;
case 47:
#line 259 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 15; yyval.node->procno = 3;
                                }
break;
case 48:
#line 262 "minic.y"
	{   yyval.node = makeNode(0);
                                    yyval.node->ntno = 15; yyval.node->procno = 4;
                                }
break;
case 50:
#line 269 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 16; yyval.node->procno = 1;
                                    yyval.node->multiplicity = yystack.l_mark[-1].node->multiplicity + 1;
                                }
break;
case 51:
#line 274 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 16; yyval.node->procno = 2;
                                    yyval.node->multiplicity = 1;
                                }
break;
case 53:
#line 282 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->ntno = 17; yyval.node->procno = 1;
                                    strcpy(yyval.node->txt, yystack.l_mark[-1].Sval.text);
                                }
break;
case 54:
#line 287 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-5].node; yystack.l_mark[-5].node->parent = yyval.node;
                                    yyval.node->ntno = 17; yyval.node->procno = 2;
                                    strcpy(yyval.node->txt, yystack.l_mark[-4].Sval.text); strcpy(yyval.node->numtxt, yystack.l_mark[-2].Sval.text);
                                }
break;
case 56:
#line 296 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 18; yyval.node->procno = 1;
                                }
break;
case 57:
#line 301 "minic.y"
	{   yyval.node = makeNode(3); yyval.node->child[0] = yystack.l_mark[-4].node; yystack.l_mark[-4].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[2] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 18; yyval.node->procno = 2;
                                }
break;
case 59:
#line 310 "minic.y"
	{   yyval.node = makeNode(0);
                                    yyval.node->ntno = 19; yyval.node->procno = 1;
                                }
break;
case 60:
#line 313 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 19; yyval.node->procno = 2;
                                }
break;
case 62:
#line 320 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 1;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 63:
#line 325 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 2;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 64:
#line 330 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 3;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 65:
#line 335 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 4;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 66:
#line 340 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 5;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 67:
#line 345 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 6;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 68:
#line 350 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 7;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 69:
#line 355 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 8;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 70:
#line 360 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 9;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 71:
#line 365 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 10;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 72:
#line 370 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 11;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 73:
#line 375 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 12;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 74:
#line 380 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 13;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 75:
#line 385 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 14;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 76:
#line 389 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 15;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 77:
#line 393 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 16;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 78:
#line 397 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 17;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 79:
#line 401 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 18;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 80:
#line 405 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 20; yyval.node->procno = 19;
                                    strcpy(yyval.node->txt, yystack.l_mark[0].Sval.text);
                                }
break;
case 81:
#line 408 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 20; yyval.node->procno = 20;
                                    strcpy(yyval.node->txt, yystack.l_mark[-3].Sval.text); strcpy(yyval.node->numtxt, yystack.l_mark[-1].Sval.text);
        
                                }
break;
case 82:
#line 412 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 21; strcpy(yyval.node->txt, yystack.l_mark[-3].Sval.text);
                                }
break;
case 83:
#line 415 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 20; yyval.node->procno = 22;
                                    strcpy(yyval.node->txt, yystack.l_mark[-2].Sval.text);
                                }
break;
case 84:
#line 418 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 23;
                                }
break;
case 85:
#line 421 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 24;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 86:
#line 426 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 25;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 87:
#line 431 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 26;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 88:
#line 435 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 27;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 89:
#line 440 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 28;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 90:
#line 445 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 29;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 92:
#line 454 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 21; yyval.node->procno = 1;
                                    strcpy(yyval.node->numtxt, yystack.l_mark[0].Sval.text);
                                }
break;
case 93:
#line 457 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 21; yyval.node->procno = 2;
                                    strcpy(yyval.node->numtxt, yystack.l_mark[0].Sval.text);
                                }
break;
case 95:
#line 464 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 22; yyval.node->procno = 1;
                                    yyval.node->multiplicity = yystack.l_mark[-2].node->multiplicity + 1;
                                }
break;
case 96:
#line 469 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 22; yyval.node->procno = 2;
                                    yyval.node->multiplicity = 1;
                                }
break;
case 98:
#line 477 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 23; yyval.node->procno = 1; }
break;
case 100:
#line 482 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 24; yyval.node->procno = 1; }
break;
#line 1397 "y.tab.c"
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

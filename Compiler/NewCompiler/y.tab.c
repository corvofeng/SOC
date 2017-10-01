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
int Totalerrors, funcount, gcount;
struct allFunc **ALL;
struct globalVar **gVar;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 30 "minic.y"
typedef union{
        struct AST *node;	/* 非终结符语义值类型*/

        struct terminal{	/* 终结符语义值类型*/
            char *text;
        } Sval;

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 42 "y.tab.c"

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
    0,    1,    1,    2,    2,    3,    3,    4,    4,    5,
    5,    6,    6,    7,    7,    8,    8,    9,    9,   10,
   10,   10,   10,   10,   10,   10,   11,   11,   11,   12,
   13,   14,   14,   14,   14,   15,   15,   16,   16,   17,
   17,   18,   18,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   20,   20,   21,   21,   22,   23,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    1,    1,    3,    6,    1,    1,    6,
    6,    1,    1,    3,    1,    2,    5,    2,    1,    1,
    1,    1,    1,    1,    1,    1,    4,    7,    5,    5,
    3,    4,    3,    3,    2,    2,    1,    3,    6,    5,
    7,    2,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    2,    2,    2,
    3,    1,    4,    4,    3,    1,    3,    3,    2,    3,
    3,    3,    1,    1,    3,    1,    2,    2,
};
static const YYINT yydefred[] = {                         0,
    8,    9,    0,    0,    3,    4,    0,    5,    2,    0,
    6,    0,    0,    0,    0,    0,    0,    0,   15,    0,
    0,    0,    0,    7,    0,   11,    0,   10,   14,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   35,    0,
    0,   19,   20,   23,   21,    0,   37,   22,   24,   25,
   26,   17,    0,    0,    0,    0,    0,   73,   74,    0,
    0,    0,    0,   42,    0,    0,    0,   66,   77,   78,
    0,    0,    0,   33,   18,   34,    0,   36,    0,    0,
    0,    0,    0,    0,   59,   58,   57,   69,    0,   60,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   43,    0,
   31,   38,    0,   32,    0,   27,    0,    0,    0,   65,
    0,    0,   61,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   30,    0,   63,   64,    0,   29,
    0,    0,    0,    0,   39,   28,   41,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,    6,    7,    8,   17,   18,   19,   41,   42,
   43,   44,   45,   28,   46,   47,   48,   49,   67,   68,
  122,   50,   51,
};
static const YYINT yysindex[] = {                      -217,
    0,    0,    0, -217,    0,    0, -240,    0,    0,  -21,
    0, -249, -200,  -61,    0, -213,   21,   29,    0,   12,
  -12,  -57, -217,    0, -186,    0,  286,    0,    0,   -4,
  -41,   51,   56,  -33,   26,   38,  -18,  407,    0, -158,
  309,    0,    0,    0,    0,  293,    0,    0,    0,    0,
    0,    0, -170,  -18,  -18,  -18,  -34,    0,    0,  -18,
  -18,  -18,  -18,    0,  -18,  -18,   18,    0,    0,    0,
   45,  326,  -43,    0,    0,    0,  359,    0,    8,   72,
  103,  138, -168,  -32,    0,    0,    0,    0,  171,    0,
  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,
  -18,  -18,  -18,  -18,  -18,  -18,  -18,  -18,    0,  -18,
    0,    0, -167,    0,   43,    0,  407,  407,   20,    0,
  234,   -1,    0,  206,  206,  206,  206,  410,  261, -207,
 -207,  206,  206,  140,  140,  117,   27,   27, -207, -207,
 -207,  337,   25,  -18,    0, -151,    0,    0,  -18,    0,
   61,  382,  407,  234,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,  123,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -36,    0,    0,   83,    0,    0,
    5,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   -8,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   31,    0,    0,  582,  811,  821,  834,   92,  129,  645,
  656,  843,  856,  704,  777,  753,  740,  766,  682,  693,
  730,    0,    0,    0,    0,  364,    0,    0,    0,    0,
    0,    0,    0,   54,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  121,    0,    1,    0,    0,    0,  104,  -15,    4,
    0,    0,    0,    0,    0,   80,    0,    0, 1076,    0,
    0,    0,    0,
};
#define YYTABLESIZE 1225
static const YYINT yytable[] = {                         62,
   62,   26,   66,   66,   13,   84,   65,   65,  120,   60,
   60,   61,   61,   16,   62,  112,   10,   66,   13,   54,
   14,   65,   72,   16,   60,   64,   61,   40,   62,   62,
   77,   20,   62,   62,   62,   62,   62,   11,   62,  148,
    1,    2,  149,   21,   75,   16,   40,  113,   16,   53,
   62,   62,   62,   62,  108,  104,   83,   15,    2,  106,
  101,   22,  102,  108,  107,   27,   97,   98,  106,   12,
   24,   76,   23,  107,   76,   75,  109,   99,   25,  100,
   75,  108,  104,   30,   69,   62,  106,  101,   52,  102,
   55,  107,   63,   63,   75,   56,   70,   75,   73,   79,
  115,  119,  143,  144,   99,  110,  100,   63,  108,  104,
  153,  105,  147,  106,  101,   62,  102,  151,  107,  155,
  145,  146,    1,   12,    9,   78,   29,    0,    0,    0,
  116,   99,   51,  100,    0,   51,    0,    0,  105,  108,
  104,  103,    0,  117,  106,  101,    0,  102,    0,  107,
   51,    0,   51,  108,  104,    0,  157,    0,  106,    0,
    0,    0,   99,  107,  100,  105,    0,    0,  103,   44,
    0,    0,   44,    0,  108,  104,  108,  104,  118,  106,
  101,  106,  102,    0,  107,    0,  107,   44,    0,   44,
    0,    0,    0,    0,    0,  103,  105,   99,    0,  100,
    0,    0,    0,    0,    0,    0,    0,  108,  104,    0,
  105,  123,  106,  101,    0,  102,    0,  107,    0,    0,
    8,    0,    0,   57,   57,    0,  103,    0,    0,    0,
   99,  105,  100,  105,    0,    0,   58,   58,   57,   59,
   59,    0,  108,  104,    0,    0,    0,  106,  101,    0,
  102,   58,  107,    0,   59,   62,   62,   62,   62,   62,
   62,  103,    0,  103,  105,   62,   62,    0,    0,    0,
  108,  104,    0,    0,    0,  106,  101,    0,  102,    0,
  107,   91,   92,   93,   94,   95,   96,    0,    0,    0,
    0,   97,   98,   99,  103,  100,    0,  108,  104,  105,
   97,   98,  106,  101,    0,  102,    0,  107,   91,   92,
   93,   94,   95,   96,    0,    0,    0,    0,   97,   98,
   99,   37,  100,    0,    0,    0,    0,  105,   37,  103,
    0,    0,    0,    0,    0,   91,   92,   93,   94,   95,
   96,    0,    0,    0,   37,   97,   98,    0,    0,    0,
    0,    0,    0,    0,  105,    0,    0,  103,    0,   51,
   51,   37,    0,    0,    0,    0,   91,   92,   93,   94,
   95,   96,    0,  108,  104,    0,   97,   98,  106,  101,
    0,  102,    0,  107,  103,    0,    0,    0,    0,    0,
   97,   98,    0,    0,   37,  150,   99,   44,  100,   40,
    0,   91,   92,   93,   94,   95,   96,    0,   38,    0,
   39,   97,   98,   97,   98,   38,    0,   76,  108,  104,
    0,    0,    0,  106,  101,    0,  102,    0,  107,    0,
  105,   38,    0,   74,   91,   92,   93,   94,   95,   96,
  156,   99,   37,  100,   97,   98,  108,  104,   38,    0,
  111,  106,  101,    0,  102,    0,  107,    0,    0,    0,
  103,    0,    0,    0,    0,    0,    0,    0,    0,   99,
    0,  100,    0,    0,    0,  105,    0,    0,    0,   97,
   98,   38,    0,  114,    0,    0,   40,    0,   40,    0,
    0,    0,    0,    0,    0,    0,    0,   91,   92,   93,
   94,   95,   96,  105,    0,  103,    0,   97,   98,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   91,   92,   93,   94,   95,   38,
    0,    0,    0,  103,   97,   98,    0,    0,    0,    0,
    0,    0,   31,    1,    2,   32,   33,    0,   34,   31,
    1,    2,   32,   33,    0,   34,   35,   36,    0,    0,
    0,    0,    0,   35,   36,   31,    0,    0,   32,   33,
    0,   34,    0,    0,    0,    0,    0,    0,    0,   35,
   36,    0,   31,    0,    0,   32,   33,    0,   34,    0,
    0,    0,    0,    0,    0,    0,   35,   36,    0,    0,
   91,   92,   93,   94,   95,   96,    0,    0,    0,    0,
   97,   98,    0,    0,    0,   31,    0,    0,   32,   33,
   40,   34,   45,   40,   40,   45,   40,    0,    0,   35,
   36,    0,    0,    0,   40,   40,    0,    0,    0,    0,
   45,   45,   45,   45,    0,   91,   92,   93,   94,   95,
   96,    0,    0,    0,    0,   97,   98,    0,    0,    0,
    0,    0,    0,   31,    0,    0,   32,   33,    0,   34,
    0,    0,    0,   91,   92,   93,   94,   35,   36,    0,
    0,   70,   70,   97,   98,   70,   70,   70,   70,   70,
    0,   70,   71,   71,    0,    0,   71,   71,   71,   71,
   71,    0,   71,   70,   70,   70,   70,    0,    0,    0,
    0,    0,    0,    0,   71,   71,   71,   71,   54,   54,
    0,    0,   54,   54,   54,   54,   54,    0,   54,   55,
   55,    0,    0,   55,   55,   55,   55,   55,   70,   55,
   54,   54,   54,   54,   52,    0,   52,   52,   52,   71,
    0,   55,   55,   55,   55,    0,    0,    0,    0,    0,
    0,    0,   52,   52,   52,   52,   56,   56,   70,    0,
   56,   56,   56,   56,   56,   54,   56,   67,    0,   71,
   67,    0,   67,   67,   67,    0,   55,    0,   56,   56,
   56,   56,    0,   72,    0,   72,   72,   72,   67,   67,
   67,   67,    0,   68,    0,   54,   68,    0,   68,   68,
   68,   72,   72,   72,   72,    0,   55,   53,    0,   53,
   53,   53,    0,   56,   68,   68,   68,   68,    0,    0,
    0,    0,    0,   67,    0,   53,   53,   53,   53,    0,
    0,    0,    0,    0,    0,   45,   45,   45,   45,   45,
   45,   46,    0,   56,   46,    0,    0,    0,    0,   68,
    0,   47,    0,   67,   47,    0,    0,    0,    0,   46,
   46,   46,   46,    0,   49,    0,   72,   49,    0,   47,
   47,   47,   47,   48,    0,    0,   48,    0,    0,   68,
    0,    0,   49,   49,   49,   49,   50,    0,    0,   50,
    0,   48,   48,   48,   48,    0,    0,    0,   70,   70,
   70,   70,   70,   70,   50,   50,   50,   50,    0,   71,
   71,   71,   71,   71,   71,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   54,   54,   54,   54,   54,
   54,    0,    0,    0,    0,    0,   55,   55,   55,   55,
   55,   55,    0,    0,    0,    0,    0,   52,   52,   52,
   52,   52,   52,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   56,   56,   56,   56,   56,   56,    0,
    0,    0,    0,   67,   67,   67,   67,   67,   67,    0,
    0,    0,    0,    0,    0,    0,   72,   72,   72,   72,
   72,   72,    0,    0,    0,    0,    0,    0,    0,   68,
   68,   68,   68,   68,   68,    0,    0,    0,    0,    0,
   53,   53,   53,   53,   53,   53,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   46,   46,   46,   46,   46,   46,
    0,    0,    0,    0,   47,   47,   47,   47,   47,   47,
    0,    0,    0,    0,    0,    0,    0,   49,   49,   49,
   49,   49,   49,    0,    0,    0,   48,   48,   48,   48,
   48,   48,   71,    0,    0,    0,    0,    0,    0,   50,
   50,   50,   50,   50,   50,    0,    0,    0,    0,   80,
   81,   82,    0,    0,    0,   85,   86,   87,   88,    0,
   89,   90,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  121,
    0,    0,    0,    0,    0,    0,  124,  125,  126,  127,
  128,  129,  130,  131,  132,  133,  134,  135,  136,  137,
  138,  139,  140,  141,    0,  142,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  152,
    0,    0,    0,    0,  154,
};
static const YYINT yycheck[] = {                         33,
   33,   59,   36,   36,   41,   40,   40,   40,   41,   43,
   43,   45,   45,   13,   33,   59,  257,   36,   40,   61,
  270,   40,   38,   23,   43,   59,   45,   27,   37,   38,
   46,   93,   41,   42,   43,   44,   45,   59,   47,   41,
  258,  259,   44,  257,   41,   41,   46,   91,   44,   91,
   59,   60,   61,   62,   37,   38,   91,  258,  259,   42,
   43,   41,   45,   37,   47,  123,  274,  275,   42,   91,
   59,   41,   44,   47,   44,   72,   59,   60,   91,   62,
   77,   37,   38,  270,   59,   94,   42,   43,   93,   45,
   40,   47,  126,  126,   41,   40,   59,   44,  257,  270,
   93,  270,  270,   61,   60,   61,   62,  126,   37,   38,
  262,   94,   93,   42,   43,  124,   45,   93,   47,   59,
  117,  118,    0,   41,    4,   46,   23,   -1,   -1,   -1,
   59,   60,   41,   62,   -1,   44,   -1,   -1,   94,   37,
   38,  124,   -1,   41,   42,   43,   -1,   45,   -1,   47,
   59,   -1,   61,   37,   38,   -1,  153,   -1,   42,   -1,
   -1,   -1,   60,   47,   62,   94,   -1,   -1,  124,   41,
   -1,   -1,   44,   -1,   37,   38,   37,   38,   41,   42,
   43,   42,   45,   -1,   47,   -1,   47,   59,   -1,   61,
   -1,   -1,   -1,   -1,   -1,  124,   94,   60,   -1,   62,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   37,   38,   -1,
   94,   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
  257,   -1,   -1,  257,  257,   -1,  124,   -1,   -1,   -1,
   60,   94,   62,   94,   -1,   -1,  270,  270,  257,  273,
  273,   -1,   37,   38,   -1,   -1,   -1,   42,   43,   -1,
   45,  270,   47,   -1,  273,  264,  265,  266,  267,  268,
  269,  124,   -1,  124,   94,  274,  275,   -1,   -1,   -1,
   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,
   47,  264,  265,  266,  267,  268,  269,   -1,   -1,   -1,
   -1,  274,  275,   60,  124,   62,   -1,   37,   38,   94,
  274,  275,   42,   43,   -1,   45,   -1,   47,  264,  265,
  266,  267,  268,  269,   -1,   -1,   -1,   -1,  274,  275,
   60,   36,   62,   -1,   -1,   -1,   -1,   94,   36,  124,
   -1,   -1,   -1,   -1,   -1,  264,  265,  266,  267,  268,
  269,   -1,   -1,   -1,   36,  274,  275,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   94,   -1,   -1,  124,   -1,  268,
  269,   36,   -1,   -1,   -1,   -1,  264,  265,  266,  267,
  268,  269,   -1,   37,   38,   -1,  274,  275,   42,   43,
   -1,   45,   -1,   47,  124,   -1,   -1,   -1,   -1,   -1,
  274,  275,   -1,   -1,   36,   59,   60,  269,   62,   36,
   -1,  264,  265,  266,  267,  268,  269,   -1,  123,   -1,
  125,  274,  275,  274,  275,  123,   -1,  125,   37,   38,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   94,  123,   -1,  125,  264,  265,  266,  267,  268,  269,
   59,   60,   36,   62,  274,  275,   37,   38,  123,   -1,
  125,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
  124,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   60,
   -1,   62,   -1,   -1,   -1,   94,   -1,   -1,   -1,  274,
  275,  123,   -1,  125,   -1,   -1,  123,   -1,  125,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  264,  265,  266,
  267,  268,  269,   94,   -1,  124,   -1,  274,  275,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  264,  265,  266,  267,  268,  123,
   -1,   -1,   -1,  124,  274,  275,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,  259,  260,  261,   -1,  263,  257,
  258,  259,  260,  261,   -1,  263,  271,  272,   -1,   -1,
   -1,   -1,   -1,  271,  272,  257,   -1,   -1,  260,  261,
   -1,  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  271,
  272,   -1,  257,   -1,   -1,  260,  261,   -1,  263,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  271,  272,   -1,   -1,
  264,  265,  266,  267,  268,  269,   -1,   -1,   -1,   -1,
  274,  275,   -1,   -1,   -1,  257,   -1,   -1,  260,  261,
  257,  263,   41,  260,  261,   44,  263,   -1,   -1,  271,
  272,   -1,   -1,   -1,  271,  272,   -1,   -1,   -1,   -1,
   59,   60,   61,   62,   -1,  264,  265,  266,  267,  268,
  269,   -1,   -1,   -1,   -1,  274,  275,   -1,   -1,   -1,
   -1,   -1,   -1,  257,   -1,   -1,  260,  261,   -1,  263,
   -1,   -1,   -1,  264,  265,  266,  267,  271,  272,   -1,
   -1,   37,   38,  274,  275,   41,   42,   43,   44,   45,
   -1,   47,   37,   38,   -1,   -1,   41,   42,   43,   44,
   45,   -1,   47,   59,   60,   61,   62,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   59,   60,   61,   62,   37,   38,
   -1,   -1,   41,   42,   43,   44,   45,   -1,   47,   37,
   38,   -1,   -1,   41,   42,   43,   44,   45,   94,   47,
   59,   60,   61,   62,   41,   -1,   43,   44,   45,   94,
   -1,   59,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   59,   60,   61,   62,   37,   38,  124,   -1,
   41,   42,   43,   44,   45,   94,   47,   38,   -1,  124,
   41,   -1,   43,   44,   45,   -1,   94,   -1,   59,   60,
   61,   62,   -1,   41,   -1,   43,   44,   45,   59,   60,
   61,   62,   -1,   38,   -1,  124,   41,   -1,   43,   44,
   45,   59,   60,   61,   62,   -1,  124,   41,   -1,   43,
   44,   45,   -1,   94,   59,   60,   61,   62,   -1,   -1,
   -1,   -1,   -1,   94,   -1,   59,   60,   61,   62,   -1,
   -1,   -1,   -1,   -1,   -1,  264,  265,  266,  267,  268,
  269,   41,   -1,  124,   44,   -1,   -1,   -1,   -1,   94,
   -1,   41,   -1,  124,   44,   -1,   -1,   -1,   -1,   59,
   60,   61,   62,   -1,   41,   -1,  124,   44,   -1,   59,
   60,   61,   62,   41,   -1,   -1,   44,   -1,   -1,  124,
   -1,   -1,   59,   60,   61,   62,   41,   -1,   -1,   44,
   -1,   59,   60,   61,   62,   -1,   -1,   -1,  264,  265,
  266,  267,  268,  269,   59,   60,   61,   62,   -1,  264,
  265,  266,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  264,  265,  266,  267,  268,
  269,   -1,   -1,   -1,   -1,   -1,  264,  265,  266,  267,
  268,  269,   -1,   -1,   -1,   -1,   -1,  264,  265,  266,
  267,  268,  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  264,  265,  266,  267,  268,  269,   -1,
   -1,   -1,   -1,  264,  265,  266,  267,  268,  269,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  264,  265,  266,  267,
  268,  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  264,
  265,  266,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,
  264,  265,  266,  267,  268,  269,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  264,  265,  266,  267,  268,  269,
   -1,   -1,   -1,   -1,  264,  265,  266,  267,  268,  269,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  264,  265,  266,
  267,  268,  269,   -1,   -1,   -1,  264,  265,  266,  267,
  268,  269,   37,   -1,   -1,   -1,   -1,   -1,   -1,  264,
  265,  266,  267,  268,  269,   -1,   -1,   -1,   -1,   54,
   55,   56,   -1,   -1,   -1,   60,   61,   62,   63,   -1,
   65,   66,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   84,
   -1,   -1,   -1,   -1,   -1,   -1,   91,   92,   93,   94,
   95,   96,   97,   98,   99,  100,  101,  102,  103,  104,
  105,  106,  107,  108,   -1,  110,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  144,
   -1,   -1,   -1,   -1,  149,
};
#define YYFINAL 3
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
"decl : var_decl",
"decl : fun_decl",
"var_decl : type_spec IDENT ';'",
"var_decl : type_spec IDENT '[' DECNUM ']' ';'",
"type_spec : VOID",
"type_spec : INT",
"fun_decl : type_spec IDENT '(' params ')' compound_stmt",
"fun_decl : type_spec IDENT '(' params ')' ';'",
"params : param_list",
"params : VOID",
"param_list : param_list ',' param",
"param_list : param",
"param : type_spec IDENT",
"param : type_spec IDENT '[' DECNUM ']'",
"stmt_list : stmt_list stmt",
"stmt_list : stmt",
"stmt : expr_stmt",
"stmt : block_stmt",
"stmt : if_stmt",
"stmt : while_stmt",
"stmt : return_stmt",
"stmt : continue_stmt",
"stmt : break_stmt",
"expr_stmt : IDENT '=' expr ';'",
"expr_stmt : IDENT '[' DECNUM ']' '=' expr ';'",
"expr_stmt : '$' expr '=' expr ';'",
"while_stmt : WHILE '(' expr ')' stmt",
"block_stmt : '{' stmt_list '}'",
"compound_stmt : '{' local_decls stmt_list '}'",
"compound_stmt : '{' stmt_list '}'",
"compound_stmt : '{' local_decls '}'",
"compound_stmt : '{' '}'",
"local_decls : local_decls local_decl",
"local_decls : local_decl",
"local_decl : type_spec IDENT ';'",
"local_decl : type_spec IDENT '[' DECNUM ']' ';'",
"if_stmt : IF '(' expr ')' stmt",
"if_stmt : IF '(' expr ')' stmt ELSE stmt",
"return_stmt : RETURN ';'",
"return_stmt : RETURN expr ';'",
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
"int_literal : DECNUM",
"int_literal : HEXNUM",
"arg_list : arg_list ',' expr",
"arg_list : expr",
"continue_stmt : CONTINUE ';'",
"break_stmt : BREAK ';'",

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
#line 464 "minic.y"
// 错误处理函数
yyerror(s)
char *s;
{
    fflush(stdout);
    printf("Parse Error\n");
    Totalerrors++;
    return 0;
}

int main()
{
    Totalerrors = 0;
    funcount = 0;
    gcount = 0;
    ALL = (struct allFunc **)malloc(20 * sizeof(struct allFunc *));
    gVar = (struct globalVar **)malloc(20 * sizeof(struct globalVar *));
    yyparse();
    if (Totalerrors > 0)
        printf("Total symantic errors: %d\n", Totalerrors);
    else {
        printf("Generating MIPS code...\n");
        GenerateMIPS();
    }
    return 0;
}
#line 598 "y.tab.c"

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
#line 72 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 1; yyval.node->procno = 1;
                                }
break;
case 2:
#line 78 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 2; yyval.node->procno = 1;
                                    yyval.node->multiplicity = yystack.l_mark[-1].node->multiplicity + 1;
                                }
break;
case 3:
#line 83 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 2; yyval.node->procno = 2;
                                    yyval.node->multiplicity = 1;
                                }
break;
case 4:
#line 90 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 3; yyval.node->procno = 1;
                                }
break;
case 5:
#line 93 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 3; yyval.node->procno = 2;
                                }
break;
case 6:
#line 99 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->ntno = 4; yyval.node->procno = 1;
                                    strcpy(yyval.node->txt, yystack.l_mark[-1].Sval.text);
                                    gVar[gcount] = (struct globalVar *)malloc(sizeof(struct globalVar));
                                    strcpy(gVar[gcount]->name, yystack.l_mark[-1].Sval.text);
                                    gVar[gcount]->space = 1; gcount++;
                                }
break;
case 7:
#line 107 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-5].node; yystack.l_mark[-5].node->parent = yyval.node;
                                    yyval.node->ntno = 4; yyval.node->procno = 2;
                                    strcpy(yyval.node->txt, yystack.l_mark[-4].Sval.text); strcpy(yyval.node->numtxt, yystack.l_mark[-2].Sval.text);
                                    gVar[gcount] = (struct globalVar *)malloc(sizeof(struct globalVar));
                                    strcpy(gVar[gcount]->name, yystack.l_mark[-4].Sval.text);
                                    gVar[gcount]->space = atoi(yystack.l_mark[-2].Sval.text); gcount++;
                                }
break;
case 8:
#line 117 "minic.y"
	{   yyval.node = makeNode(0);
                                    yyval.node->ntno = 5; yyval.node->procno = 1;
                                }
break;
case 9:
#line 120 "minic.y"
	{   yyval.node = makeNode(0);
                                    yyval.node->ntno = 5; yyval.node->procno = 2;
                                }
break;
case 10:
#line 127 "minic.y"
	{   yyval.node = makeNode(3); yyval.node->child[0] = yystack.l_mark[-5].node; yystack.l_mark[-5].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[2] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 6; yyval.node->procno = 1; strcpy(yyval.node->txt, yystack.l_mark[-4].Sval.text);
                                    ALL[funcount] = (struct allFunc *)malloc(sizeof(struct allFunc));
                                    strcpy(ALL[funcount]->name, yystack.l_mark[-4].Sval.text);
                                    ALL[funcount]->t = yyval.node; funcount++;
                                }
break;
case 11:
#line 136 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-5].node; yystack.l_mark[-5].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->ntno = 6; yyval.node->procno = 2; strcpy(yyval.node->txt, yystack.l_mark[-4].Sval.text);
                                }
break;
case 12:
#line 143 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 7; yyval.node->procno = 1;
                                }
break;
case 13:
#line 146 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 7; yyval.node->procno = 2; }
break;
case 14:
#line 150 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 8; yyval.node->procno = 1;
                                    yyval.node->multiplicity = yystack.l_mark[-2].node->multiplicity + 1;
                                }
break;
case 15:
#line 155 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 8; yyval.node->procno = 2;
                                    yyval.node->multiplicity = 1;
                                }
break;
case 16:
#line 162 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 9; yyval.node->procno = 1;
                                    strcpy(yyval.node->txt, yystack.l_mark[0].Sval.text);
                                }
break;
case 17:
#line 167 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-4].node; yystack.l_mark[-4].node->parent = yyval.node;
                                    yyval.node->ntno = 9; yyval.node->procno = 2;
                                    strcpy(yyval.node->txt, yystack.l_mark[-3].Sval.text); strcpy(yyval.node->numtxt, yystack.l_mark[-1].Sval.text);
                                }
break;
case 18:
#line 174 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 10; yyval.node->procno = 1;
                                    yyval.node->multiplicity = yystack.l_mark[-1].node->multiplicity + 1;
                                }
break;
case 19:
#line 179 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 10; yyval.node->procno = 2;
                                    yyval.node->multiplicity = 1;
                                }
break;
case 20:
#line 186 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 1;
                                }
break;
case 21:
#line 189 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 2;
                                }
break;
case 22:
#line 192 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 3;
                                }
break;
case 23:
#line 195 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 4;
                                }
break;
case 24:
#line 198 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 5;
                                }
break;
case 25:
#line 201 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 6;
                                }
break;
case 26:
#line 204 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 11; yyval.node->procno = 7;
                                }
break;
case 27:
#line 210 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 12; yyval.node->procno = 1;
                                    strcpy(yyval.node->txt, yystack.l_mark[-3].Sval.text);
                                }
break;
case 28:
#line 215 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 12; yyval.node->procno = 2;
                                    strcpy(yyval.node->txt, yystack.l_mark[-6].Sval.text); strcpy(yyval.node->numtxt, yystack.l_mark[-4].Sval.text);
                                }
break;
case 29:
#line 219 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-3].node; yystack.l_mark[-3].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 12; yyval.node->procno = 3;
                                }
break;
case 30:
#line 226 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 13; yyval.node->procno = 1;
                                }
break;
case 31:
#line 233 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 14; yyval.node->procno = 1;
                                }
break;
case 32:
#line 240 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 15; yyval.node->procno = 1;
                                }
break;
case 33:
#line 244 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 15; yyval.node->procno = 2;
                                }
break;
case 34:
#line 247 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 15; yyval.node->procno = 3;
                                }
break;
case 35:
#line 250 "minic.y"
	{   yyval.node = makeNode(0);
                                    yyval.node->ntno = 15; yyval.node->procno = 4;
                                }
break;
case 36:
#line 256 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 16; yyval.node->procno = 1;
                                    yyval.node->multiplicity = yystack.l_mark[-1].node->multiplicity + 1;
                                }
break;
case 37:
#line 261 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 16; yyval.node->procno = 2;
                                    yyval.node->multiplicity = 1;
                                }
break;
case 38:
#line 268 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->ntno = 17; yyval.node->procno = 1;
                                    strcpy(yyval.node->txt, yystack.l_mark[-1].Sval.text);
                                }
break;
case 39:
#line 273 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-5].node; yystack.l_mark[-5].node->parent = yyval.node;
                                    yyval.node->ntno = 17; yyval.node->procno = 2;
                                    strcpy(yyval.node->txt, yystack.l_mark[-4].Sval.text); strcpy(yyval.node->numtxt, yystack.l_mark[-2].Sval.text);
                                }
break;
case 40:
#line 281 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 18; yyval.node->procno = 1;
                                }
break;
case 41:
#line 286 "minic.y"
	{   yyval.node = makeNode(3); yyval.node->child[0] = yystack.l_mark[-4].node; yystack.l_mark[-4].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[2] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 18; yyval.node->procno = 2;
                                }
break;
case 42:
#line 294 "minic.y"
	{   yyval.node = makeNode(0);
                                    yyval.node->ntno = 19; yyval.node->procno = 1;
                                }
break;
case 43:
#line 297 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 19; yyval.node->procno = 2;
                                }
break;
case 44:
#line 303 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 1;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 45:
#line 308 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 2;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 46:
#line 313 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 3;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 47:
#line 318 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 4;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 48:
#line 323 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 5;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 49:
#line 328 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 6;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 50:
#line 333 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 7;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 51:
#line 338 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 8;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 52:
#line 343 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 9;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 53:
#line 348 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 10;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 54:
#line 353 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 11;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 55:
#line 358 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 12;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 56:
#line 363 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 13;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 57:
#line 368 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 14;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 58:
#line 372 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 15;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 59:
#line 376 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 16;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 60:
#line 380 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 17;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 61:
#line 384 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 18;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 62:
#line 388 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 20; yyval.node->procno = 19;
                                    strcpy(yyval.node->txt, yystack.l_mark[0].Sval.text);
                                }
break;
case 63:
#line 391 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 20; yyval.node->procno = 20;
                                    strcpy(yyval.node->txt, yystack.l_mark[-3].Sval.text); strcpy(yyval.node->numtxt, yystack.l_mark[-1].Sval.text);
        
                                }
break;
case 64:
#line 395 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[-1].node; yystack.l_mark[-1].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 21; strcpy(yyval.node->txt, yystack.l_mark[-3].Sval.text);
                                }
break;
case 65:
#line 398 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 20; yyval.node->procno = 22;
                                    strcpy(yyval.node->txt, yystack.l_mark[-2].Sval.text);
                                }
break;
case 66:
#line 401 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 23;
                                }
break;
case 67:
#line 404 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 24;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 68:
#line 409 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 25;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 69:
#line 414 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 26;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 70:
#line 418 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 27;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 71:
#line 423 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 28;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 72:
#line 428 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 20; yyval.node->procno = 29;
                                    yyval.node->contain_expr = 1;
                                }
break;
case 73:
#line 436 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 21; yyval.node->procno = 1;
                                    strcpy(yyval.node->numtxt, yystack.l_mark[0].Sval.text);
                                }
break;
case 74:
#line 439 "minic.y"
	{   yyval.node = makeNode(0); yyval.node->ntno = 21; yyval.node->procno = 2;
                                    strcpy(yyval.node->numtxt, yystack.l_mark[0].Sval.text);
                                }
break;
case 75:
#line 445 "minic.y"
	{   yyval.node = makeNode(2); yyval.node->child[0] = yystack.l_mark[-2].node; yystack.l_mark[-2].node->parent = yyval.node;
                                    yyval.node->child[1] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 22; yyval.node->procno = 1;
                                    yyval.node->multiplicity = yystack.l_mark[-2].node->multiplicity + 1;
                                }
break;
case 76:
#line 450 "minic.y"
	{   yyval.node = makeNode(1); yyval.node->child[0] = yystack.l_mark[0].node; yystack.l_mark[0].node->parent = yyval.node;
                                    yyval.node->ntno = 22; yyval.node->procno = 2;
                                    yyval.node->multiplicity = 1;
                                }
break;
case 77:
#line 457 "minic.y"
	{   yyval.node = makeNode(0); }
break;
case 78:
#line 461 "minic.y"
	{   yyval.node = makeNode(0); }
break;
#line 1343 "y.tab.c"
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

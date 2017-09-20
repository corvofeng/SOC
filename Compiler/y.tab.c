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

#line 2 "sample.y"
    #include <stdio.h>
    #include <string.h>
    #include "minic_ast.h"
    #include "minic.h"
    #include "ucode.h"
    extern FILE *yyin;
    int yylex();
    void yyerror(const char *s);
    Node* root;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 12 "sample.y"
typedef union {
    struct nodeType *ast;
    int ival;
    char* string;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 44 "y.tab.c"

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

#define TCONST 257
#define TELSE 258
#define TIF 259
#define TINT 260
#define TRETURN 261
#define TVOID 262
#define TWHILE 263
#define TEQUAL 264
#define TNOTEQU 265
#define TLESSE 266
#define TGREATE 267
#define TAND 268
#define TOR 269
#define TINC 270
#define TDEC 271
#define TADDASSIGN 272
#define TSUBASSIGN 273
#define TMULASSIGN 274
#define TDIVASSIGN 275
#define TMODASSIGN 276
#define TIDENT 277
#define TNUMBER 278
#define LOWER_THAN_TELSE 279
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    2,    2,    3,    3,    1,    5,    7,   12,   12,
   13,   13,   15,   14,   14,    4,    8,   16,   16,   17,
   17,   18,    6,    9,    9,   10,   10,   11,   19,   19,
   20,   20,   21,   21,   22,   22,   23,   23,   24,   24,
   25,   25,   25,   25,   25,   26,   27,   27,   28,   28,
   29,   30,   31,   32,   32,   32,   32,   32,   32,   32,
   38,   38,   39,   39,   40,   40,   40,   41,   41,   41,
   41,   41,   42,   42,   42,   43,   43,   43,   43,   35,
   35,   35,   35,   35,   36,   36,   36,   36,   36,   44,
   44,   33,   34,   34,   37,   37,   37,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    1,    1,    2,    3,    1,    1,    2,
    1,    1,    1,    1,    1,    1,    3,    1,    0,    1,
    3,    2,    4,    1,    0,    1,    2,    3,    1,    3,
    1,    3,    1,    4,    1,    0,    1,    0,    1,    2,
    1,    1,    1,    1,    1,    2,    1,    0,    5,    7,
    5,    3,    1,    1,    3,    3,    3,    3,    3,    3,
    1,    3,    1,    3,    1,    3,    3,    1,    3,    3,
    3,    3,    1,    3,    3,    1,    3,    3,    3,    1,
    2,    2,    2,    2,    1,    4,    4,    2,    2,    1,
    0,    1,    1,    3,    1,    1,    3,
};
static const YYINT yydefred[] = {                         0,
   13,   14,   15,    0,    4,    0,    2,    0,    0,    5,
    0,    9,   12,   11,    3,    0,    6,    0,    0,    0,
   29,    0,   10,    0,    0,    0,   26,    0,    0,    7,
    0,   28,    0,    0,    0,    0,    0,    0,    0,   95,
   96,    0,    0,    0,   41,    0,    0,   39,   42,    0,
   43,   44,   45,   47,   53,    0,    0,   85,    0,    0,
    0,    0,    0,    0,   27,   35,    0,    0,    0,    0,
   20,   30,   32,    0,    0,    0,   83,   84,    0,   81,
   82,   23,   40,   46,    0,    0,    0,    0,    0,    0,
   88,   89,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   34,   22,   17,
    0,    0,   52,    0,   97,   56,   57,   58,   59,   60,
   55,   93,   90,    0,    0,    0,   76,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   77,   78,   79,
   21,    0,    0,    0,   87,   86,    0,   51,   94,    0,
   50,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,   19,    8,   45,    9,   30,   25,   26,
   10,   11,   12,   13,   14,   69,   70,   71,   20,   21,
   22,   67,   46,   47,   48,   49,   50,   51,   52,   53,
   54,   55,  123,  124,   56,   57,   58,   59,   60,   61,
   62,   63,   64,  125,
};
static const YYINT yysindex[] = {                      -163,
    0,    0,    0,    0,    0, -163,    0, -106, -239,    0,
 -163,    0,    0,    0,    0, -163,    0,  -70,   10,  -31,
    0,   -8,    0, -211,    3, -163,    0, -209, -163,    0,
 -211,    0, -206,  -70,   33,   -1,   35,   -1,   -1,    0,
    0,   -1,   -1,   -1,    0,  -27,    3,    0,    0,   24,
    0,    0,    0,    0,    0,  -59,   16,    0, -172, -169,
 -256,  -42,    2,   63,    0,    0,   28, -211,   93,   92,
    0,    0,    0,   -1,   81,   -1,    0,    0,  101,    0,
    0,    0,    0,    0,   -1,   -1,   -1,   -1,   -1,   -1,
    0,    0,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,    0,    0,    0,
 -163,  104,    0,  106,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  110,  107,   57,    0, -169, -256,  -42,
  -42,    2,    2,    2,    2,   63,   63,    0,    0,    0,
    0,    3,    3,   -1,    0,    0, -102,    0,    0,    3,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,  157,    0,    0,    0,    0,
 -118,    0,    0,    0,    0,  -33,    0,   -7,    0,    0,
    0,  -13,    0,    0,  -55,  -30,    0,   68,  121,    0,
    0,    0,    0,   23,    0,  105,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -54,    0,    0,    0,
    0,    0,    0,    0,    0,   44,   18,    0,  -19,  -17,
  -25,  139,  108,   73,    0,    0,    0,    0,    0,  124,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  128,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  134,    0,    0,    0,  263,  259,  141,
  213,  114,  119,  143,  149,   79,   84,    0,    0,    0,
    0,  105,  105,    0,    0,    0,  -10,    0,    0,  105,
    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  180,    0,    0,  181,  -15,    0,    0,    0,
   25,    0,  177,    0,    0,    0,    0,   80,    0,  161,
  131,    0,    0,    0,  -41,    0,  168,    0,    0,    0,
   77,  227,    0,    0,  353,    0,    0,    0,  111,  122,
  -40,   95,   27,    0,
};
#define YYTABLESIZE 543
static const YYINT yytable[] = {                         25,
   24,   90,   24,   48,   48,   83,   25,   97,   98,   24,
   24,   25,   31,   68,   24,   63,   16,  102,   63,  101,
   28,   54,   49,   61,   54,   25,   61,   32,   24,   49,
   31,   44,   16,   63,   49,   44,   33,   18,   42,   54,
   27,   61,   42,   43,  103,   31,  104,   43,   49,   29,
   65,   33,   33,   33,   80,   93,  130,  131,   80,   80,
   80,   80,   80,   33,   80,   34,   33,   63,   66,   38,
   37,   73,   74,   54,   76,   61,   80,   80,   80,   80,
   76,   33,   84,   33,   76,   76,   76,   76,   76,   25,
   76,   25,   24,    1,   24,   68,    2,   82,    3,  107,
  147,  148,   76,   76,  105,   76,   94,   95,  151,  106,
   80,   96,   49,   73,   49,   73,   73,   73,   79,   74,
  108,   74,   74,   74,   75,   16,   75,   75,   75,  136,
  137,   73,   73,  110,   73,  111,   76,   74,   74,  113,
   74,  115,   75,   75,  142,   75,  143,  145,   68,  146,
  112,   68,  114,  144,   72,  150,    1,   72,    8,   71,
   36,   19,   71,   48,   18,   73,   68,   68,   91,   68,
  126,   74,   72,   72,   92,   72,   75,   71,   71,   65,
   71,   66,   65,   69,   66,   15,   69,   23,   17,   70,
  141,   72,   70,  132,  133,  134,  135,   65,  109,   66,
   68,   69,   69,   75,   69,  128,   72,   70,   70,    0,
   70,   71,   85,   86,   87,   88,   89,  129,    0,    0,
    0,    0,    0,   99,  100,   25,    0,   25,   24,   25,
   24,   65,   24,   66,    0,   69,   25,   25,    0,   24,
   24,   70,    0,   25,   25,    0,   24,   24,   49,    0,
   49,    0,   49,   67,   63,   63,   67,    0,    0,   49,
   49,   35,   61,   36,    0,   37,   49,   49,   38,   39,
    0,   67,   38,   39,    0,   40,   41,    0,    0,   40,
   41,   80,   80,   80,   80,   91,   92,    0,    0,   80,
   80,   80,   80,   80,    0,    0,    0,   80,   80,   64,
    0,    0,   64,   62,    0,   67,   62,   76,   76,   76,
   76,  116,  117,  118,  119,  120,  121,   64,    0,  122,
    0,   62,    0,   76,   76,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   73,   73,   73,   73,
    0,    0,   74,   74,   74,   74,    0,   75,   75,   75,
   75,   64,   73,   73,    0,   62,    0,    0,   74,   74,
    0,    0,    0,   75,   75,    0,    0,    0,    0,    0,
  149,   68,   68,   68,   68,    0,    0,   72,   72,   72,
   72,    0,   71,   71,   71,   71,    0,   68,   68,    0,
   77,   78,    0,   72,   72,   80,   81,    0,   71,   71,
    0,    0,   65,   65,   66,   66,   69,   69,   69,   69,
    0,    0,   70,   70,   70,   70,    0,    0,   65,   65,
   66,   66,   69,   69,    0,    0,    0,    0,   70,   70,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  127,  127,  127,
  127,  127,  127,  127,  127,  127,  127,  138,  139,  140,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   67,   67,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   67,   67,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   64,   64,
    0,    0,   62,
};
static const YYINT yycheck[] = {                         33,
   16,   61,   33,   59,   59,   47,   40,  264,  265,   40,
   26,   45,   44,   29,   45,   41,  123,   60,   44,   62,
   91,   41,   33,   41,   44,   59,   44,   59,   59,   40,
   44,   33,   40,   59,   45,   33,   44,  277,   40,   59,
   16,   59,   40,   45,   43,   59,   45,   45,   59,   40,
   26,   59,   61,   61,   37,   40,   97,   98,   41,   42,
   43,   44,   45,   41,   47,  277,   44,   93,  278,  125,
  125,  278,   40,   93,   40,   93,   59,   60,   61,   62,
   37,   59,   59,   61,   41,   42,   43,   44,   45,  123,
   47,  125,  123,  257,  125,  111,  260,  125,  262,   37,
  142,  143,   59,   60,   42,   62,   91,  280,  150,   47,
   93,  281,  123,   41,  125,   43,   44,   45,   42,   41,
   93,   43,   44,   45,   41,  123,   43,   44,   45,  103,
  104,   59,   60,   41,   62,   44,   93,   59,   60,   59,
   62,   41,   59,   60,   41,   62,   41,   41,   41,   93,
   74,   44,   76,   44,   41,  258,    0,   44,  277,   41,
   93,   41,   44,   59,   41,   93,   59,   60,   41,   62,
   94,   93,   59,   60,   41,   62,   93,   59,   60,   41,
   62,   41,   44,   41,   44,    6,   44,   11,    8,   41,
  111,   31,   44,   99,  100,  101,  102,   59,   68,   59,
   93,   59,   60,   36,   62,   95,   93,   59,   60,   -1,
   62,   93,  272,  273,  274,  275,  276,   96,   -1,   -1,
   -1,   -1,   -1,  266,  267,  259,   -1,  261,  259,  263,
  261,   93,  263,   93,   -1,   93,  270,  271,   -1,  270,
  271,   93,   -1,  277,  278,   -1,  277,  278,  259,   -1,
  261,   -1,  263,   41,  280,  281,   44,   -1,   -1,  270,
  271,  259,  280,  261,   -1,  263,  277,  278,  270,  271,
   -1,   59,  270,  271,   -1,  277,  278,   -1,   -1,  277,
  278,  264,  265,  266,  267,  270,  271,   -1,   -1,  272,
  273,  274,  275,  276,   -1,   -1,   -1,  280,  281,   41,
   -1,   -1,   44,   41,   -1,   93,   44,  264,  265,  266,
  267,   85,   86,   87,   88,   89,   90,   59,   -1,   93,
   -1,   59,   -1,  280,  281,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  264,  265,  266,  267,
   -1,   -1,  264,  265,  266,  267,   -1,  264,  265,  266,
  267,   93,  280,  281,   -1,   93,   -1,   -1,  280,  281,
   -1,   -1,   -1,  280,  281,   -1,   -1,   -1,   -1,   -1,
  144,  264,  265,  266,  267,   -1,   -1,  264,  265,  266,
  267,   -1,  264,  265,  266,  267,   -1,  280,  281,   -1,
   38,   39,   -1,  280,  281,   43,   44,   -1,  280,  281,
   -1,   -1,  264,  265,  264,  265,  264,  265,  266,  267,
   -1,   -1,  264,  265,  266,  267,   -1,   -1,  280,  281,
  280,  281,  280,  281,   -1,   -1,   -1,   -1,  280,  281,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   95,   96,   97,
   98,   99,  100,  101,  102,  103,  104,  105,  106,  107,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  264,  265,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  280,  281,
   -1,   -1,  280,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 281
#define YYUNDFTOKEN 328
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"TCONST","TELSE","TIF","TINT","TRETURN",
"TVOID","TWHILE","TEQUAL","TNOTEQU","TLESSE","TGREATE","TAND","TOR","TINC",
"TDEC","TADDASSIGN","TSUBASSIGN","TMULASSIGN","TDIVASSIGN","TMODASSIGN",
"TIDENT","TNUMBER","LOWER_THAN_TELSE","\"||\"","\"&&\"",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : mini_c",
"mini_c : translation_unit",
"translation_unit : external_dcl",
"translation_unit : translation_unit external_dcl",
"external_dcl : function_def",
"external_dcl : declaration",
"function_def : function_header compound_st",
"function_header : dcl_spec function_name formal_param",
"dcl_spec : dcl_specifiers",
"dcl_specifiers : dcl_specifier",
"dcl_specifiers : dcl_specifiers dcl_specifier",
"dcl_specifier : type_qualifier",
"dcl_specifier : type_specifier",
"type_qualifier : TCONST",
"type_specifier : TINT",
"type_specifier : TVOID",
"function_name : TIDENT",
"formal_param : '(' opt_formal_param ')'",
"opt_formal_param : formal_param_list",
"opt_formal_param :",
"formal_param_list : param_dcl",
"formal_param_list : formal_param_list ',' param_dcl",
"param_dcl : dcl_spec declarator",
"compound_st : '{' opt_dcl_list opt_stat_list '}'",
"opt_dcl_list : declaration_list",
"opt_dcl_list :",
"declaration_list : declaration",
"declaration_list : declaration_list declaration",
"declaration : dcl_spec init_dcl_list ';'",
"init_dcl_list : init_declarator",
"init_dcl_list : init_dcl_list ',' init_declarator",
"init_declarator : declarator",
"init_declarator : declarator '=' TNUMBER",
"declarator : TIDENT",
"declarator : TIDENT '[' opt_number ']'",
"opt_number : TNUMBER",
"opt_number :",
"opt_stat_list : statement_list",
"opt_stat_list :",
"statement_list : statement",
"statement_list : statement_list statement",
"statement : compound_st",
"statement : expression_st",
"statement : if_st",
"statement : while_st",
"statement : return_st",
"expression_st : opt_expression ';'",
"opt_expression : expression",
"opt_expression :",
"if_st : TIF '(' expression ')' statement",
"if_st : TIF '(' expression ')' statement TELSE statement",
"while_st : TWHILE '(' expression ')' statement",
"return_st : TRETURN opt_expression ';'",
"expression : assignment_exp",
"assignment_exp : logical_or_exp",
"assignment_exp : unary_exp '=' assignment_exp",
"assignment_exp : unary_exp TADDASSIGN assignment_exp",
"assignment_exp : unary_exp TSUBASSIGN assignment_exp",
"assignment_exp : unary_exp TMULASSIGN assignment_exp",
"assignment_exp : unary_exp TDIVASSIGN assignment_exp",
"assignment_exp : unary_exp TMODASSIGN assignment_exp",
"logical_or_exp : logical_and_exp",
"logical_or_exp : logical_or_exp \"||\" logical_and_exp",
"logical_and_exp : equality_exp",
"logical_and_exp : logical_and_exp \"&&\" equality_exp",
"equality_exp : relational_exp",
"equality_exp : equality_exp TEQUAL relational_exp",
"equality_exp : equality_exp TNOTEQU relational_exp",
"relational_exp : additive_exp",
"relational_exp : relational_exp '>' additive_exp",
"relational_exp : relational_exp '<' additive_exp",
"relational_exp : relational_exp TGREATE additive_exp",
"relational_exp : relational_exp TLESSE additive_exp",
"additive_exp : multiplicative_exp",
"additive_exp : additive_exp '+' multiplicative_exp",
"additive_exp : additive_exp '-' multiplicative_exp",
"multiplicative_exp : unary_exp",
"multiplicative_exp : multiplicative_exp '*' unary_exp",
"multiplicative_exp : multiplicative_exp '/' unary_exp",
"multiplicative_exp : multiplicative_exp '%' unary_exp",
"unary_exp : postfix_exp",
"unary_exp : '-' unary_exp",
"unary_exp : '!' unary_exp",
"unary_exp : TINC unary_exp",
"unary_exp : TDEC unary_exp",
"postfix_exp : primary_exp",
"postfix_exp : postfix_exp '[' expression ']'",
"postfix_exp : postfix_exp '(' opt_actual_param ')'",
"postfix_exp : postfix_exp TINC",
"postfix_exp : postfix_exp TDEC",
"opt_actual_param : actual_param",
"opt_actual_param :",
"actual_param : actual_param_list",
"actual_param_list : assignment_exp",
"actual_param_list : actual_param_list ',' assignment_exp",
"primary_exp : TIDENT",
"primary_exp : TNUMBER",
"primary_exp : '(' expression ')'",

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
#line 407 "sample.y"

char* toString(char* string)
{
    char* str;
    str = (char*)malloc(strlen(string) + 1);
    strcpy(str, string);
    return str;
}

Node* parse(FILE *sourceFile)
{
    yyin = sourceFile;
    do{
        yyparse();
    } while(!feof(yyin));

    return root;
}

int main(int argc, char *argv[]){
    FILE *sourceFile;
    FILE *astFile, *ucoFile;

    char filename[100];
    Node *root;

    if (argc != 2) {
        fprintf(stderr, "arguments not valid.");
        return -1;
    }

    strcpy(filename, argv[1]);

    sourceFile = fopen(filename, "r");
    astFile = fopen(strcat(strtok(filename, "."), ".ast"), "w");
    ucoFile = fopen(strcat(strtok(filename, "."), ".uco"), "w");

    if(!sourceFile) {
        fprintf(stderr, "source file not open!\n");
        return -1;
    }
    if(!astFile) {
        fprintf(stderr, "ast file not not open!\n");
        return -1;
    }
    if(!ucoFile) {
        fprintf(stderr, "uco file not not open!\n");
        return -1;
    }

    printf("Start Parsing..\n");
    root = parse(sourceFile);
    printTree(root, 0, astFile);
    printf("End Parsing!\n");

    printf("Start Code Generate..\n");
    codeGen(root, ucoFile);
    printf("End Code Generate!\n");

    fclose(sourceFile);
    fclose(astFile);
    fclose(ucoFile);
    return 1;
}
#line 534 "y.tab.c"

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
#line 33 "sample.y"
	{
        root = buildTree(PROGRAM, yystack.l_mark[0].ast);
    }
break;
case 2:
#line 38 "sample.y"
	{
        yyval.ast = yystack.l_mark[0].ast;
    }
break;
case 3:
#line 41 "sample.y"
	{
        appendNext(yystack.l_mark[-1].ast, yystack.l_mark[0].ast);
        yyval.ast = yystack.l_mark[-1].ast;
    }
break;
case 4:
#line 47 "sample.y"
	{
        yyval.ast = yystack.l_mark[0].ast;
    }
break;
case 5:
#line 50 "sample.y"
	{
        yyval.ast = yystack.l_mark[0].ast;
    }
break;
case 6:
#line 55 "sample.y"
	{
        appendNext(yystack.l_mark[-1].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(FUNC_DEF, yystack.l_mark[-1].ast);
    }
break;
case 7:
#line 61 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[-1].ast);
        appendNext(yystack.l_mark[-1].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(FUNC_HEAD, yystack.l_mark[-2].ast);
    }
break;
case 8:
#line 68 "sample.y"
	{
        yyval.ast = buildTree(DCL_SPEC, yystack.l_mark[0].ast);
    }
break;
case 9:
#line 73 "sample.y"
	{
        yyval.ast = yystack.l_mark[0].ast;
    }
break;
case 10:
#line 76 "sample.y"
	{
        appendNext(yystack.l_mark[-1].ast, yystack.l_mark[0].ast);
        yyval.ast = yystack.l_mark[-1].ast;
    }
break;
case 11:
#line 82 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 12:
#line 83 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 13:
#line 86 "sample.y"
	{
        yyval.ast = buildTree(CONST_NODE, NULL);
    }
break;
case 14:
#line 91 "sample.y"
	{
        yyval.ast = buildTree(INT_NODE, NULL);
    }
break;
case 15:
#line 94 "sample.y"
	{
        yyval.ast = buildTree(VOID_NODE, NULL);
    }
break;
case 16:
#line 99 "sample.y"
	{ yyval.ast = buildNode(IDENT, yystack.l_mark[0].string); }
break;
case 17:
#line 102 "sample.y"
	{
        yyval.ast = buildTree(FORMAL_PARA, yystack.l_mark[-1].ast);
    }
break;
case 18:
#line 107 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 19:
#line 108 "sample.y"
	{ yyval.ast = NULL; }
break;
case 20:
#line 111 "sample.y"
	{
        yyval.ast = yystack.l_mark[0].ast;
    }
break;
case 21:
#line 114 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = yystack.l_mark[-2].ast;
    }
break;
case 22:
#line 120 "sample.y"
	{
        appendNext(yystack.l_mark[-1].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(PARAM_DCL, yystack.l_mark[-1].ast);
    }
break;
case 23:
#line 126 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[-1].ast);
        yyval.ast = buildTree(COMPOUND_ST, yystack.l_mark[-2].ast);
    }
break;
case 24:
#line 132 "sample.y"
	{
        yyval.ast = buildTree(DCL_LIST, yystack.l_mark[0].ast);
    }
break;
case 25:
#line 135 "sample.y"
	{
        yyval.ast = buildTree(DCL_LIST, NULL);
    }
break;
case 26:
#line 140 "sample.y"
	{
        yyval.ast = yystack.l_mark[0].ast;
    }
break;
case 27:
#line 143 "sample.y"
	{
        appendNext(yystack.l_mark[-1].ast, yystack.l_mark[0].ast);
        yyval.ast = yystack.l_mark[-1].ast;
    }
break;
case 28:
#line 149 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[-1].ast);
        yyval.ast = buildTree(DCL, yystack.l_mark[-2].ast);
    }
break;
case 29:
#line 155 "sample.y"
	{
        yyval.ast = yystack.l_mark[0].ast;
    }
break;
case 30:
#line 158 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = yystack.l_mark[-2].ast;
    }
break;
case 31:
#line 164 "sample.y"
	{
        yyval.ast = yystack.l_mark[0].ast;
    }
break;
case 32:
#line 167 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast->son, buildNode(IDENT, yystack.l_mark[0].string)); /* @todo 이거 구조 맞나?*/
        yyval.ast = yystack.l_mark[-2].ast;
    }
break;
case 33:
#line 173 "sample.y"
	{
        Node* ptr = buildTree(SIMPLE_VAR, buildNode(IDENT, yystack.l_mark[0].string));
        yyval.ast = buildTree(DCL_ITEM, ptr);
    }
break;
case 34:
#line 177 "sample.y"
	{
        Node* ptr = buildNode(IDENT, yystack.l_mark[-3].string);
        appendNext(ptr, yystack.l_mark[-1].ast);
        yyval.ast = buildTree(DCL_ITEM, buildTree(ARRAY_VAR, ptr));
    }
break;
case 35:
#line 184 "sample.y"
	{
        yyval.ast = buildNode(NUMBER, yystack.l_mark[0].string);
    }
break;
case 36:
#line 187 "sample.y"
	{
        yyval.ast = NULL;
    }
break;
case 37:
#line 192 "sample.y"
	{
        yyval.ast = buildTree(STAT_LIST, yystack.l_mark[0].ast);
    }
break;
case 38:
#line 195 "sample.y"
	{ yyval.ast = NULL; }
break;
case 39:
#line 198 "sample.y"
	{
        yyval.ast = yystack.l_mark[0].ast;
    }
break;
case 40:
#line 201 "sample.y"
	{
        appendNext(yystack.l_mark[-1].ast, yystack.l_mark[0].ast);
        yyval.ast = yystack.l_mark[-1].ast;
    }
break;
case 41:
#line 207 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 42:
#line 208 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 43:
#line 209 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 44:
#line 210 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 45:
#line 211 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 46:
#line 214 "sample.y"
	{
        yyval.ast = buildTree(EXP_ST, yystack.l_mark[-1].ast);
    }
break;
case 47:
#line 219 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 48:
#line 220 "sample.y"
	{ yyval.ast = NULL }
break;
case 49:
#line 223 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(IF_ST, yystack.l_mark[-2].ast);
    }
break;
case 50:
#line 227 "sample.y"
	{
        appendNext(yystack.l_mark[-4].ast, yystack.l_mark[-2].ast);
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(IF_ELSE_ST, yystack.l_mark[-4].ast);
    }
break;
case 51:
#line 234 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(WHILE_ST, yystack.l_mark[-2].ast);
    }
break;
case 52:
#line 240 "sample.y"
	{
        yyval.ast = buildTree(RETURN_ST, yystack.l_mark[-1].ast);
    }
break;
case 53:
#line 245 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 54:
#line 248 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 55:
#line 249 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(ASSIGN_OP, yystack.l_mark[-2].ast);
    }
break;
case 56:
#line 253 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(ADD_ASSIGN, yystack.l_mark[-2].ast);
    }
break;
case 57:
#line 257 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(SUB_ASSIGN, yystack.l_mark[-2].ast);
    }
break;
case 58:
#line 261 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(MUL_ASSIGN, yystack.l_mark[-2].ast);
    }
break;
case 59:
#line 265 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(DIV_ASSIGN, yystack.l_mark[-2].ast);
    }
break;
case 60:
#line 269 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(MOD_ASSIGN, yystack.l_mark[-2].ast);
    }
break;
case 61:
#line 275 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 62:
#line 276 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(LOGICAL_OR, yystack.l_mark[-2].ast);
    }
break;
case 63:
#line 282 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 64:
#line 283 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(LOGICAL_AND, yystack.l_mark[-2].ast);
    }
break;
case 65:
#line 289 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 66:
#line 290 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(EQ, yystack.l_mark[-2].ast);
    }
break;
case 67:
#line 294 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(NE, yystack.l_mark[-2].ast);
    }
break;
case 68:
#line 300 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 69:
#line 301 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(GT, yystack.l_mark[-2].ast);
    }
break;
case 70:
#line 305 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(LT, yystack.l_mark[-2].ast);
    }
break;
case 71:
#line 309 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(GE, yystack.l_mark[-2].ast);
    }
break;
case 72:
#line 313 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(LE, yystack.l_mark[-2].ast);
    }
break;
case 73:
#line 319 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 74:
#line 320 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(ADD, yystack.l_mark[-2].ast);
    }
break;
case 75:
#line 324 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(SUB, yystack.l_mark[-2].ast);
    }
break;
case 76:
#line 330 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 77:
#line 331 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(MUL, yystack.l_mark[-2].ast);
    }
break;
case 78:
#line 335 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(DIV, yystack.l_mark[-2].ast);
    }
break;
case 79:
#line 339 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = buildTree(MOD, yystack.l_mark[-2].ast);
    }
break;
case 80:
#line 345 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 81:
#line 346 "sample.y"
	{
        yyval.ast = buildTree(UNARY_MINUS, yystack.l_mark[0].ast);
    }
break;
case 82:
#line 349 "sample.y"
	{
        yyval.ast = buildTree(LOGICAL_NOT, yystack.l_mark[0].ast);
    }
break;
case 83:
#line 352 "sample.y"
	{
        yyval.ast = buildTree(PRE_INC, yystack.l_mark[0].ast);
    }
break;
case 84:
#line 355 "sample.y"
	{
        yyval.ast = buildTree(PRE_DEC, yystack.l_mark[0].ast);
    }
break;
case 85:
#line 360 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 86:
#line 361 "sample.y"
	{
        appendNext(yystack.l_mark[-3].ast, yystack.l_mark[-1].ast);
        yyval.ast = buildTree(INDEX, yystack.l_mark[-3].ast);
    }
break;
case 87:
#line 365 "sample.y"
	{
        appendNext(yystack.l_mark[-3].ast, yystack.l_mark[-1].ast);
        yyval.ast = buildTree(CALL, yystack.l_mark[-3].ast);
    }
break;
case 88:
#line 369 "sample.y"
	{
        yyval.ast = buildTree(POST_INC, yystack.l_mark[-1].ast);
    }
break;
case 89:
#line 372 "sample.y"
	{
        yyval.ast = buildTree(POST_DEC, yystack.l_mark[-1].ast);
    }
break;
case 90:
#line 377 "sample.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 91:
#line 378 "sample.y"
	{ yyval.ast = NULL; }
break;
case 92:
#line 381 "sample.y"
	{
        yyval.ast = buildTree(ACTUAL_PARAM, yystack.l_mark[0].ast);
    }
break;
case 93:
#line 386 "sample.y"
	{
        yyval.ast = yystack.l_mark[0].ast;
    }
break;
case 94:
#line 389 "sample.y"
	{
        appendNext(yystack.l_mark[-2].ast, yystack.l_mark[0].ast);
        yyval.ast = yystack.l_mark[-2].ast;
    }
break;
case 95:
#line 395 "sample.y"
	{
        yyval.ast = buildNode(IDENT, yystack.l_mark[0].string);
    }
break;
case 96:
#line 398 "sample.y"
	{
        yyval.ast = buildNode(NUMBER, yystack.l_mark[0].string);
    }
break;
case 97:
#line 401 "sample.y"
	{ /* ex. (30 * 20) + 4*/
        yyval.ast = yystack.l_mark[-1].ast;
    }
break;
#line 1307 "y.tab.c"
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

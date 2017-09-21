/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     PTR_OP = 262,
     INC_OP = 263,
     DEC_OP = 264,
     LEFT_OP = 265,
     RIGHT_OP = 266,
     LE_OP = 267,
     GE_OP = 268,
     EQ_OP = 269,
     NE_OP = 270,
     AND_OP = 271,
     OR_OP = 272,
     MUL_ASSIGN = 273,
     DIV_ASSIGN = 274,
     MOD_ASSIGN = 275,
     ADD_ASSIGN = 276,
     SUB_ASSIGN = 277,
     LEFT_ASSIGN = 278,
     RIGHT_ASSIGN = 279,
     AND_ASSIGN = 280,
     XOR_ASSIGN = 281,
     OR_ASSIGN = 282,
     IF = 283,
     ELSE = 284,
     WHILE = 285,
     FOR = 286,
     CONTINUE = 287,
     BREAK = 288,
     RETURN = 289,
     READ = 290,
     PRINT = 291,
     CHAR = 292,
     INT = 293,
     FLOAT = 294,
     VOID = 295,
     STRUCT = 296,
     MIN = 297,
     MAX = 298,
     SWAP = 299
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define PTR_OP 262
#define INC_OP 263
#define DEC_OP 264
#define LEFT_OP 265
#define RIGHT_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define AND_OP 271
#define OR_OP 272
#define MUL_ASSIGN 273
#define DIV_ASSIGN 274
#define MOD_ASSIGN 275
#define ADD_ASSIGN 276
#define SUB_ASSIGN 277
#define LEFT_ASSIGN 278
#define RIGHT_ASSIGN 279
#define AND_ASSIGN 280
#define XOR_ASSIGN 281
#define OR_ASSIGN 282
#define IF 283
#define ELSE 284
#define WHILE 285
#define FOR 286
#define CONTINUE 287
#define BREAK 288
#define RETURN 289
#define READ 290
#define PRINT 291
#define CHAR 292
#define INT 293
#define FLOAT 294
#define VOID 295
#define STRUCT 296
#define MIN 297
#define MAX 298
#define SWAP 299




/* Copy the first part of user declarations.  */
#line 1 "cparser.y"

#include"definition.h"

struct global my,check;
int open;
int jumpcount,returntype,returnpointer;
char returnchar[100];
int Totalerrors,funcount;
struct allFunc **ALL;
struct structure
{
	char in[100];
	int s;
}maxi[100];


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 27 "cparser.y"
{
        struct AST *node;	//non-terminals

        struct terminal{	//terminals
                        char *text;
                        int type;
                        int line;
        } Sval;

}
/* Line 193 of yacc.c.  */
#line 211 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 224 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   413

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNRULES -- Number of states.  */
#define YYNSTATES  271

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,     2,     2,    62,    60,     2,
      52,    53,    47,    56,    48,    57,    55,    61,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
      63,    54,    64,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,    65,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,    66,    51,    59,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    10,    18,    20,    23,    27,    32,
      34,    36,    38,    40,    43,    45,    50,    54,    61,    63,
      67,    71,    73,    76,    82,    86,    89,    94,    98,   103,
     106,   112,   119,   126,   133,   140,   147,   150,   153,   156,
     158,   160,   162,   164,   166,   168,   170,   172,   174,   182,
     191,   201,   207,   215,   218,   221,   224,   228,   230,   232,
     234,   236,   238,   240,   242,   244,   246,   248,   250,   252,
     255,   257,   261,   263,   265,   267,   271,   273,   275,   277,
     282,   290,   294,   299,   303,   310,   312,   314,   316,   318,
     320,   322,   324,   327,   332,   334,   338,   342,   346,   348,
     352,   356,   358,   362,   366,   368,   372,   376,   380,   384,
     386,   390,   394,   396,   400,   402,   406,   408,   412,   414,
     418,   420,   424,   426,   428,   432,   434,   437,   439,   441,
     445,   448,   452,   456,   462,   467,   469,   471,   474
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
     116,     0,    -1,     3,    -1,     3,    45,     4,    46,    -1,
       3,    45,     4,    46,    45,     4,    46,    -1,    68,    -1,
      47,    68,    -1,    69,    48,    68,    -1,    69,    48,    47,
      68,    -1,    38,    -1,    37,    -1,    40,    -1,     3,    -1,
      47,     3,    -1,     3,    -1,     3,    45,     4,    46,    -1,
      72,    48,     3,    -1,    72,    48,     3,    45,     4,    46,
      -1,     3,    -1,    73,    48,     3,    -1,    70,    73,    49,
      -1,    74,    -1,    75,    74,    -1,    41,     3,    50,    75,
      51,    -1,    70,    69,    49,    -1,    76,    49,    -1,    41,
       3,    72,    49,    -1,    76,    72,    49,    -1,    78,    48,
      70,    71,    -1,    70,    71,    -1,    78,    48,    41,     3,
       3,    -1,    35,    52,    70,    48,     3,    53,    -1,    36,
      52,    70,    48,     3,    53,    -1,    43,    52,     3,    48,
       3,    53,    -1,    42,    52,     3,    48,     3,    53,    -1,
      44,    52,     3,    48,     3,    53,    -1,    79,    49,    -1,
      80,    49,    -1,    83,    49,    -1,   113,    -1,    90,    -1,
      88,    -1,    89,    -1,    92,    -1,    77,    -1,    84,    -1,
      50,    -1,    51,    -1,    30,    52,   109,    53,    86,   110,
      87,    -1,    31,    52,    92,    92,    53,    86,   110,    87,
      -1,    31,    52,    92,    92,   109,    53,    86,   110,    87,
      -1,    28,    52,   109,    53,   113,    -1,    28,    52,   109,
      53,   113,    29,    85,    -1,    32,    49,    -1,    33,    49,
      -1,    34,    49,    -1,    34,   109,    49,    -1,    54,    -1,
      18,    -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,
      23,    -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,
      49,    -1,   109,    49,    -1,   109,    -1,    93,    48,   109,
      -1,     3,    -1,     4,    -1,     5,    -1,    52,   109,    53,
      -1,    81,    -1,    82,    -1,    94,    -1,     3,    45,   109,
      46,    -1,     3,    45,   109,    46,    45,   109,    46,    -1,
       3,    52,    53,    -1,     3,    52,    93,    53,    -1,     3,
      55,     3,    -1,     3,    45,   109,    46,    55,     3,    -1,
      56,    -1,    57,    -1,    58,    -1,    59,    -1,    47,    -1,
      60,    -1,    95,    -1,    96,    97,    -1,     6,    52,    70,
      53,    -1,    97,    -1,    98,    47,    97,    -1,    98,    61,
      97,    -1,    98,    62,    97,    -1,    98,    -1,    99,    56,
      98,    -1,    99,    57,    98,    -1,    99,    -1,   100,    10,
      99,    -1,   100,    11,    99,    -1,   100,    -1,   101,    63,
     100,    -1,   101,    64,   100,    -1,   101,    12,   100,    -1,
     101,    13,   100,    -1,   101,    -1,   102,    14,   101,    -1,
     102,    15,   101,    -1,   102,    -1,   103,    60,   102,    -1,
     103,    -1,   104,    65,   103,    -1,   104,    -1,   105,    66,
     104,    -1,   105,    -1,   106,    16,   105,    -1,   106,    -1,
     107,    17,   106,    -1,   107,    -1,   108,    -1,    97,    91,
     109,    -1,    85,    -1,   110,    85,    -1,    50,    -1,    51,
      -1,   111,   110,   112,    -1,    70,     3,    -1,    41,     3,
       3,    -1,    70,    47,     3,    -1,   114,    52,    78,    53,
     113,    -1,   114,    52,    53,   113,    -1,    77,    -1,   115,
      -1,   116,    77,    -1,   116,   115,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,   100,   104,   111,   114,   117,   122,   130,
     132,   133,   137,   141,   165,   170,   176,   185,   199,   202,
     210,   218,   220,   228,   251,   254,   258,   283,   293,   305,
     313,   330,   348,   363,   392,   420,   451,   455,   458,   463,
     464,   465,   466,   467,   468,   469,   472,   477,   485,   497,
     512,   531,   538,   550,   556,   562,   569,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   596,   597,
     600,   601,   607,   623,   630,   636,   640,   643,   649,   650,
     669,   689,   702,   721,   755,   794,   795,   796,   797,   798,
     799,   802,   803,   826,   834,   835,   847,   860,   873,   874,
     886,   901,   902,   913,   928,   929,   942,   956,   968,   983,
     984,   997,  1012,  1013,  1028,  1029,  1044,  1045,  1059,  1060,
    1074,  1075,  1090,  1093,  1094,  1124,  1125,  1133,  1143,  1150,
    1154,  1170,  1188,  1206,  1221,  1239,  1240,  1241,  1242
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "IF", "ELSE", "WHILE", "FOR", "CONTINUE", "BREAK", "RETURN", "READ",
  "PRINT", "CHAR", "INT", "FLOAT", "VOID", "STRUCT", "MIN", "MAX", "SWAP",
  "'['", "']'", "'*'", "','", "';'", "'{'", "'}'", "'('", "')'", "'='",
  "'.'", "'+'", "'-'", "'!'", "'~'", "'&'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "$accept", "var", "variables", "type", "arg_var",
  "struct_var", "inside_dec", "struct_declaration", "struct_list",
  "struct", "declaration", "argument_list", "read", "print", "max", "min",
  "swap", "myfunction", "statement", "istart", "iend",
  "iteration_statement", "selection_statement", "jump_statement",
  "ass_operator", "expression_statement", "arg_list", "starting",
  "main_exp", "unary_op", "unary_exp", "mul_div_mod", "plus_minus",
  "shift", "lt_gt_lte_gte", "eq_neq", "and", "xor", "or", "andand", "oror",
  "conditional_exp", "expression", "statement_list", "openB", "closeB",
  "body", "function_name", "function", "program", 0
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
     295,   296,   297,   298,   299,    91,    93,    42,    44,    59,
     123,   125,    40,    41,    61,    46,    43,    45,    33,   126,
      38,    47,    37,    60,    62,    94,   124
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    68,    68,    69,    69,    69,    69,    70,
      70,    70,    71,    71,    72,    72,    72,    72,    73,    73,
      74,    75,    75,    76,    77,    77,    77,    77,    78,    78,
      78,    79,    80,    81,    82,    83,    84,    84,    84,    85,
      85,    85,    85,    85,    85,    85,    86,    87,    88,    88,
      88,    89,    89,    90,    90,    90,    90,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    92,    92,
      93,    93,    94,    94,    94,    94,    94,    94,    95,    95,
      95,    95,    95,    95,    95,    96,    96,    96,    96,    96,
      96,    97,    97,    97,    98,    98,    98,    98,    99,    99,
      99,   100,   100,   100,   101,   101,   101,   101,   101,   102,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   107,   108,   109,   109,   110,   110,   111,   112,   113,
     114,   114,   114,   115,   115,   116,   116,   116,   116
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     7,     1,     2,     3,     4,     1,
       1,     1,     1,     2,     1,     4,     3,     6,     1,     3,
       3,     1,     2,     5,     3,     2,     4,     3,     4,     2,
       5,     6,     6,     6,     6,     6,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     7,     8,
       9,     5,     7,     2,     2,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     4,
       7,     3,     4,     3,     6,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     3,     1,     2,     1,     1,     3,
       2,     3,     3,     5,     4,     1,     1,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,     9,    11,     0,     0,     0,   135,     0,   136,
       0,     0,     2,     0,     5,     0,    14,    25,     0,     0,
       1,   137,   138,    14,     0,     0,     0,     2,     6,     0,
      24,     0,     0,    27,     0,     0,     0,     0,    21,     0,
      26,     0,     2,     0,     7,     0,    16,   127,     0,   134,
      12,     0,    29,     0,     0,    18,     0,    23,    22,     3,
       8,    15,     0,    72,    73,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
      68,     0,    85,    86,    87,    88,    90,     0,    44,     0,
       0,    76,    77,     0,    45,   125,    41,    42,    40,    43,
      78,    91,     0,    94,    98,   101,   104,   109,   112,   114,
     116,   118,   120,   122,   123,     0,     0,    39,    13,     0,
       0,   133,     0,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    37,    38,    92,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
     128,   126,   129,     0,    28,    19,     0,    17,     0,    81,
       0,    70,    83,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,    75,   124,    95,    96,    97,    94,    99,
     100,   102,   103,   107,   108,   105,   106,   110,   111,   113,
     115,   117,   119,   121,    30,     4,    79,     0,    82,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    51,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,    31,    32,    34,
      33,    35,    80,    52,    47,    48,     0,     0,    49,     0,
      50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    87,    52,    25,    56,    38,    39,     6,
      88,    36,    89,    90,    91,    92,    93,    94,    95,   243,
     265,    96,    97,    98,   160,    99,   190,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    48,   182,   117,     8,     9,    10
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -231
static const yytype_int16 yypact[] =
{
     172,  -231,  -231,  -231,     6,    14,     5,  -231,   -45,  -231,
      87,     3,    84,    27,  -231,    58,   -13,  -231,   146,   -22,
    -231,  -231,  -231,    85,   149,   159,    54,    86,  -231,    39,
    -231,   104,    33,  -231,    76,    45,    43,   129,  -231,   -11,
    -231,    89,    59,   140,  -231,   105,   109,  -231,   257,  -231,
    -231,   154,  -231,   177,    76,  -231,   175,  -231,  -231,   115,
    -231,  -231,   164,    50,  -231,  -231,   118,   128,   176,   186,
     167,   198,    41,   202,   214,   268,   220,   221,   222,  -231,
    -231,   353,  -231,  -231,  -231,  -231,  -231,    47,  -231,   226,
     227,  -231,  -231,   228,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,   353,    96,   -23,   169,   234,    -1,   238,   218,
     219,   217,   270,   279,  -231,   253,   141,  -231,  -231,   300,
      45,  -231,   302,  -231,   304,   264,   353,   106,   308,   149,
     353,   353,   276,  -231,  -231,  -231,   263,   149,   149,    32,
     317,   318,   319,   271,   140,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,  -231,
    -231,  -231,  -231,   323,  -231,  -231,   281,  -231,   283,  -231,
     158,  -231,  -231,   277,   278,   288,   276,  -231,   294,   295,
     296,   297,   298,  -231,  -231,  -231,  -231,  -231,  -231,   -23,
     -23,   169,   169,   234,   234,   234,   234,    -1,    -1,   238,
     218,   219,   217,   270,  -231,  -231,    -4,   353,  -231,  -231,
      76,   299,   334,   344,   345,   347,   348,   349,   353,   350,
    -231,   325,  -231,   257,   299,   307,   309,   310,   311,   312,
     313,   315,  -231,   257,   199,   257,   299,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,   199,   257,  -231,   199,
    -231
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,   -10,  -231,     4,   235,   361,  -231,   329,  -231,  -231,
     103,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -114,  -222,
    -217,  -231,  -231,  -231,  -231,  -111,  -231,  -231,  -231,  -231,
     -97,   100,   101,    51,    97,   195,   196,   194,   197,   200,
    -231,  -231,   -71,  -230,  -231,  -231,   -34,  -231,   362,  -231
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -133
static const yytype_int16 yytable[] =
{
      49,   136,   181,    28,     5,   148,    23,    19,    16,    11,
     143,   168,   169,   254,     5,     1,     2,    12,     3,    44,
     121,   196,   255,    35,   161,   266,     1,     2,    37,     3,
      27,    34,    31,    60,   267,    16,    46,   269,   162,   163,
      57,   238,    42,    37,    63,    64,    65,    66,    50,   268,
      42,   239,   270,    24,    17,   188,   191,   120,    41,   194,
     195,    13,   170,   171,   205,   206,   207,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,    24,    76,    77,   232,    43,    20,    79,   204,
     135,    53,    51,    81,   144,   126,    54,    82,    83,    84,
      85,    86,   127,     7,    26,   128,    29,    30,    45,    63,
      64,    65,    66,    21,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     1,     2,    47,     3,     4,    26,
      31,    26,    55,   193,    28,    59,  -130,  -131,  -132,   263,
     181,   198,   199,    42,    63,    64,    65,    66,    76,    77,
     159,    61,   181,    79,    62,   181,   240,   118,    81,   189,
     124,   245,    82,    83,    84,    85,    86,   251,   125,    67,
     129,    68,    69,    70,    71,    72,    73,    74,     1,     2,
     130,     3,    75,    76,    77,    78,     1,     2,    79,     3,
      80,    47,   180,    81,    32,    33,   241,    82,    83,    84,
      85,    86,    63,    64,    65,    66,   227,    32,    40,     1,
       2,   228,     3,     4,     1,     2,   133,     3,   119,   213,
     214,   215,   216,   122,   123,   164,   165,    67,   131,    68,
      69,    70,    71,    72,    73,    74,     1,     2,   132,     3,
      75,    76,    77,    78,   166,   167,    79,   134,    80,    47,
     264,    81,   172,   173,   137,    82,    83,    84,    85,    86,
      63,    64,    65,    66,   209,   210,   138,   211,   212,   217,
     218,   139,   140,   141,   142,   145,   146,   147,   174,    63,
      64,    65,    66,   176,   175,    67,   177,    68,    69,    70,
      71,    72,    73,    74,     1,     2,   178,     3,    75,    76,
      77,    78,   179,   183,    79,   185,    80,    47,   186,    81,
     187,   192,   197,    82,    83,    84,    85,    86,    76,    77,
     200,   201,   202,    79,   203,    80,   224,   225,    81,   226,
     229,   230,    82,    83,    84,    85,    86,    63,    64,    65,
      66,   231,   233,   234,   235,   236,   237,   246,   247,   242,
     248,   249,   250,   252,   253,   184,    63,    64,    65,    66,
     256,   262,   257,   258,   259,   260,   261,    18,    58,   219,
     221,   220,    22,     0,   222,     0,    76,    77,   223,     0,
       0,    79,     0,     0,     0,     0,    81,   244,     0,     0,
      82,    83,    84,    85,    86,    76,    77,     0,     0,     0,
      79,     0,     0,     0,     0,    81,     0,     0,     0,    82,
      83,    84,    85,    86
};

static const yytype_int16 yycheck[] =
{
      34,    72,   116,    13,     0,   102,     3,    52,     3,     3,
      81,    12,    13,   243,    10,    37,    38,     3,    40,    29,
      54,   132,   244,    19,    47,   255,    37,    38,    24,    40,
       3,    53,    45,    43,   256,     3,     3,   267,    61,    62,
      51,    45,     3,    39,     3,     4,     5,     6,     3,   266,
       3,    55,   269,    50,    49,   126,   127,    53,     4,   130,
     131,    47,    63,    64,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,    50,    42,    43,   196,    47,     0,    47,   160,
      49,    48,    47,    52,    47,    45,    53,    56,    57,    58,
      59,    60,    52,     0,    45,    55,    48,    49,     4,     3,
       4,     5,     6,    10,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    37,    38,    50,    40,    41,    45,
      45,    45,     3,   129,   144,    46,    52,    52,    52,   253,
     254,   137,   138,     3,     3,     4,     5,     6,    42,    43,
      54,    46,   266,    47,    45,   269,   227,     3,    52,    53,
      45,   232,    56,    57,    58,    59,    60,   238,     4,    28,
      52,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      52,    40,    41,    42,    43,    44,    37,    38,    47,    40,
      49,    50,    51,    52,    48,    49,   230,    56,    57,    58,
      59,    60,     3,     4,     5,     6,    48,    48,    49,    37,
      38,    53,    40,    41,    37,    38,    49,    40,    41,   168,
     169,   170,   171,    48,    49,    56,    57,    28,    52,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    52,    40,
      41,    42,    43,    44,    10,    11,    47,    49,    49,    50,
      51,    52,    14,    15,    52,    56,    57,    58,    59,    60,
       3,     4,     5,     6,   164,   165,    52,   166,   167,   172,
     173,     3,    52,    52,    52,    49,    49,    49,    60,     3,
       4,     5,     6,    66,    65,    28,    16,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    17,    40,    41,    42,
      43,    44,    49,     3,    47,     3,    49,    50,     4,    52,
      46,     3,    49,    56,    57,    58,    59,    60,    42,    43,
       3,     3,     3,    47,    53,    49,     3,    46,    52,    46,
      53,    53,    56,    57,    58,    59,    60,     3,     4,     5,
       6,    53,    48,    48,    48,    48,    48,     3,     3,    50,
       3,     3,     3,     3,    29,   120,     3,     4,     5,     6,
      53,    46,    53,    53,    53,    53,    53,     6,    39,   174,
     176,   175,    10,    -1,   177,    -1,    42,    43,   178,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    52,    53,    -1,    -1,
      56,    57,    58,    59,    60,    42,    43,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    56,
      57,    58,    59,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    38,    40,    41,    70,    76,    77,   114,   115,
     116,     3,     3,    47,    68,    69,     3,    49,    72,    52,
       0,    77,   115,     3,    50,    72,    45,     3,    68,    48,
      49,    45,    48,    49,    53,    70,    78,    70,    74,    75,
      49,     4,     3,    47,    68,     4,     3,    50,   111,   113,
       3,    47,    71,    48,    53,     3,    73,    51,    74,    46,
      68,    46,    45,     3,     4,     5,     6,    28,    30,    31,
      32,    33,    34,    35,    36,    41,    42,    43,    44,    47,
      49,    52,    56,    57,    58,    59,    60,    70,    77,    79,
      80,    81,    82,    83,    84,    85,    88,    89,    90,    92,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   113,     3,    41,
      70,   113,    48,    49,    45,     4,    45,    52,    55,    52,
      52,    52,    52,    49,    49,    49,   109,    52,    52,     3,
      52,    52,    52,   109,    47,    49,    49,    49,    97,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    54,
      91,    47,    61,    62,    56,    57,    10,    11,    12,    13,
      63,    64,    14,    15,    60,    65,    66,    16,    17,    49,
      51,    85,   112,     3,    71,     3,     4,    46,   109,    53,
      93,   109,     3,    70,   109,   109,    92,    49,    70,    70,
       3,     3,     3,    53,   109,    97,    97,    97,    97,    98,
      98,    99,    99,   100,   100,   100,   100,   101,   101,   102,
     103,   104,   105,   106,     3,    46,    46,    48,    53,    53,
      53,    53,    92,    48,    48,    48,    48,    48,    45,    55,
     109,   113,    50,    86,    53,   109,     3,     3,     3,     3,
       3,   109,     3,    29,   110,    86,    53,    53,    53,    53,
      53,    53,    46,    85,    51,    87,   110,    86,    87,   110,
      87
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 97 "cparser.y"
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);
								(yyval.node)->array = 0;
								}
    break;

  case 3:
#line 101 "cparser.y"
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(1) - (4)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (4)].Sval).text);
								(yyval.node)->array = 1; (yyval.node)->dim1 = atoi((yyvsp[(3) - (4)].Sval).text);
								}
    break;

  case 4:
#line 105 "cparser.y"
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(1) - (7)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (7)].Sval).text);
								(yyval.node)->array = 2; (yyval.node)->dim1 = atoi((yyvsp[(3) - (7)].Sval).text); (yyval.node)->dim2 = atoi((yyvsp[(6) - (7)].Sval).text);
							}
    break;

  case 5:
#line 111 "cparser.y"
    {
									(yyval.node) = (yyvsp[(1) - (1)].node); (yyval.node)->pointer = 0;
								}
    break;

  case 6:
#line 114 "cparser.y"
    {
									(yyval.node) = (yyvsp[(2) - (2)].node); (yyval.node)->pointer = 1;
								}
    break;

  case 7:
#line 117 "cparser.y"
    {
									(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,",");
									(yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node); 
									(yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);  (yyvsp[(3) - (3)].node)->pointer = 0; 
							   }
    break;

  case 8:
#line 122 "cparser.y"
    {
									(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,",");
									(yyval.node)->child[0] = (yyvsp[(1) - (4)].node); (yyvsp[(1) - (4)].node)->parent = (yyval.node); 
									(yyval.node)->child[1] = (yyvsp[(4) - (4)].node); (yyvsp[(4) - (4)].node)->parent = (yyval.node);  (yyvsp[(4) - (4)].node)->pointer = 1;
							   }
    break;

  case 9:
#line 130 "cparser.y"
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);}
    break;

  case 10:
#line 132 "cparser.y"
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);}
    break;

  case 11:
#line 133 "cparser.y"
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);}
    break;

  case 12:
#line 137 "cparser.y"
    {
							(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);
							(yyval.node)->array = 0; (yyval.node)->pointer = 0;
						}
    break;

  case 13:
#line 141 "cparser.y"
    {
							(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(2) - (2)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(2) - (2)].Sval).text);
							(yyval.node)->array = 0; (yyval.node)->pointer = 1;
						}
    break;

  case 14:
#line 166 "cparser.y"
    {
							(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);
							(yyval.node)->array = 0; (yyval.node)->pointer = 0;
						}
    break;

  case 15:
#line 171 "cparser.y"
    {
							(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(1) - (4)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (4)].Sval).text);
							(yyval.node)->array = 1; (yyval.node)->dim1 = atoi((yyvsp[(3) - (4)].Sval).text);
							(yyval.node)->pointer = 0;
						}
    break;

  case 16:
#line 177 "cparser.y"
    {
							(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,",");
							(yyval.node)->child[1] = MakeNode(0); (yyval.node)->child[1]->type = (yyvsp[(3) - (3)].Sval).type; strcpy((yyval.node)->child[1]->lexeme,(yyvsp[(3) - (3)].Sval).text);
							(yyval.node)->child[1]->parent = (yyval.node);
							(yyval.node)->child[1]->array = 0; (yyval.node)->child[1]->pointer = 0;
							(yyval.node)->child[0] = (yyvsp[(1) - (3)].node);
							(yyvsp[(1) - (3)].node)->parent = (yyval.node);	
						}
    break;

  case 17:
#line 186 "cparser.y"
    {
							(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,",");
							(yyval.node)->child[1] = MakeNode(0); (yyval.node)->child[1]->type = (yyvsp[(3) - (6)].Sval).type; strcpy((yyval.node)->child[1]->lexeme,(yyvsp[(3) - (6)].Sval).text);
							(yyval.node)->child[1]->parent = (yyval.node);
							(yyval.node)->child[1]->array = 1; (yyval.node)->child[1]->pointer = 0;
							(yyval.node)->child[1]->dim1 = atoi((yyvsp[(5) - (6)].Sval).text);
							(yyval.node)->child[0] = (yyvsp[(1) - (6)].node);
							(yyvsp[(1) - (6)].node)->parent = (yyval.node);

						}
    break;

  case 18:
#line 199 "cparser.y"
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);
									(yyval.node)->array = 0; (yyval.node)->pointer = 0;
									}
    break;

  case 19:
#line 202 "cparser.y"
    {
									(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,",");
									(yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node); 
									(yyval.node)->child[1] = MakeNode(0); (yyval.node)->child[1]->type = (yyvsp[(3) - (3)].Sval).type; strcpy((yyval.node)->child[1]->lexeme,(yyvsp[(3) - (3)].Sval).text);
									(yyval.node)->child[1]->array=0; (yyval.node)->child[1]->pointer=0;  
								   }
    break;

  case 20:
#line 210 "cparser.y"
    {
										(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,";");
										(yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
										(yyval.node)->child[1] = (yyvsp[(2) - (3)].node); (yyvsp[(2) - (3)].node)->parent = (yyval.node);
									}
    break;

  case 21:
#line 218 "cparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);
									}
    break;

  case 22:
#line 221 "cparser.y"
    {
										(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,"#"); 
										(yyval.node)->child[0] = (yyvsp[(1) - (2)].node); (yyvsp[(1) - (2)].node)->parent = (yyval.node);
										(yyval.node)->child[1] = (yyvsp[(2) - (2)].node); (yyvsp[(2) - (2)].node)->parent = (yyval.node);
									}
    break;

  case 23:
#line 229 "cparser.y"
    {
									strcpy(maxi[init_count].in,(yyvsp[(2) - (5)].Sval).text);
									(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(2) - (5)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(2) - (5)].Sval).text);
									my.type = 6;
									
									AddSymbol((yyvsp[(2) - (5)].Sval).text,my,currentT);
									
									//AST_print($4);
									my.struct_member = 1;
									strcpy(my.structName,(yyvsp[(2) - (5)].Sval).text);
									order=0;
									addVar(my,(yyvsp[(4) - (5)].node),currentT);
									(yyval.node)->order = order;
									check.array = 6; check.struct_member = 0; 
									maxi[init_count].s=order;
									init_count++;
								//	struct symbolTable *temp = FindSymbol($2.text,check,currentT);
								//	temp->order = $$->order;
								}
    break;

  case 24:
#line 251 "cparser.y"
    {
								my.type = (yyvsp[(1) - (3)].node)->type; my.struct_member = 0; addVar(my,(yyvsp[(2) - (3)].node),currentT);
							}
    break;

  case 25:
#line 255 "cparser.y"
    {

							}
    break;

  case 26:
#line 259 "cparser.y"
    {
									int aman=0;
									for(;aman<init_count;aman++){
										if(strcmp(maxi[aman].in,(yyvsp[(2) - (4)].Sval).text)==0)	break;
									}
									if(aman==init_count){
											printf("Kat Gaya\n");
									}
									else{
										my.order=maxi[aman].s;
									}
									my.struct_member=0;
									strcpy(my.structID,(yyvsp[(2) - (4)].Sval).text);
									/*check.array = 6; check.struct_member = 0; 
									struct symbolTable *temp = FindSymbol($2.text,check,currentT);
									if(temp == NULL){
										printf("struct %s not found\n",$2.text );
										Totalerrors++;
									}else{
										my.order = temp->order;
									}*/
									my.type = 5;
									addVar(my,(yyvsp[(3) - (4)].node),currentT);
								}
    break;

  case 27:
#line 284 "cparser.y"
    {
									my.struct_member=0;
									strcpy(my.structID,(yyvsp[(1) - (3)].node)->lexeme);
									my.type = 5;
									my.order = (yyvsp[(1) - (3)].node)->order;
									addVar(my,(yyvsp[(2) - (3)].node),currentT);
							}
    break;

  case 28:
#line 294 "cparser.y"
    {
								currentT->parent->t->array  = 4;	
								(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,",");
								(yyval.node)->child[0] = (yyvsp[(1) - (4)].node); (yyvsp[(1) - (4)].node)->parent = (yyval.node);
								(yyval.node)->child[1] = (yyvsp[(3) - (4)].node); (yyvsp[(3) - (4)].node)->parent = (yyval.node);

								// add arg_var to symboltable
								my.type = (yyvsp[(3) - (4)].node)->type; my.struct_member = 0;
								addVar(my,(yyvsp[(4) - (4)].node),currentT);

							}
    break;

  case 29:
#line 305 "cparser.y"
    { 
								currentT->parent->t->array  = 4;
								(yyval.node) = (yyvsp[(1) - (2)].node);

								my.type = (yyvsp[(1) - (2)].node)->type; my.struct_member = 0;
								addVar(my,(yyvsp[(2) - (2)].node),currentT);

							}
    break;

  case 30:
#line 314 "cparser.y"
    {
								currentT->parent->t->array  = 4;
								(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,",");
								(yyval.node)->child[0] = (yyvsp[(1) - (5)].node); (yyvsp[(1) - (5)].node)->parent = (yyval.node);
								(yyval.node)->child[1] = MakeNode(0); (yyval.node)->child[1]->parent = (yyval.node);
								(yyval.node)->child[1]->type = (yyvsp[(4) - (5)].Sval).type;
								strcpy((yyval.node)->child[1]->lexeme,(yyvsp[(4) - (5)].Sval).text);	
								(yyval.node)->child[1]->array = 60;	

								my.type = 5; strcpy(my.structID,(yyvsp[(4) - (5)].Sval).text); my.struct_member = 0;
								AddSymbol((yyvsp[(5) - (5)].Sval).text,my,currentT);
							}
    break;

  case 31:
#line 331 "cparser.y"
    {
								(yyval.node) = MakeNode(2); (yyval.node)->type = 4; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (6)].Sval).text);
								(yyval.node)->child[0] = (yyvsp[(3) - (6)].node); (yyvsp[(3) - (6)].node)->parent = (yyval.node);
								(yyval.node)->child[1] = MakeNode(0); strcpy((yyval.node)->child[1]->lexeme,(yyvsp[(5) - (6)].Sval).text);
								(yyval.node)->child[1]->type = (yyvsp[(5) - (6)].Sval).type;
								(yyval.node)->child[1]->parent = (yyval.node);

								check.array = 0; check.struct_member = 0; 
								struct symbolTable *temp = FindSymbol((yyvsp[(5) - (6)].Sval).text,check,currentT);
								if(temp==NULL) printf("not found %s\n",(yyvsp[(5) - (6)].Sval).text);
								else if(temp->type != (yyvsp[(3) - (6)].node)->type) printf("READ type mismatch\n");
								(yyval.node)->child[1]->where = temp;

							}
    break;

  case 32:
#line 349 "cparser.y"
    {
								(yyval.node) = MakeNode(2); (yyval.node)->type = 4; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (6)].Sval).text);
								(yyval.node)->child[0] = (yyvsp[(3) - (6)].node); (yyvsp[(3) - (6)].node)->parent = (yyval.node);
								(yyval.node)->child[1] = MakeNode(0); strcpy((yyval.node)->child[1]->lexeme,(yyvsp[(5) - (6)].Sval).text);
								(yyval.node)->child[1]->type = (yyvsp[(5) - (6)].Sval).type;
								(yyval.node)->child[1]->parent = (yyval.node);

								check.array = 0; check.struct_member = 0; 
								struct symbolTable *temp = FindSymbol((yyvsp[(5) - (6)].Sval).text,check,currentT);
								if(temp==NULL) printf("not found %s\n",(yyvsp[(5) - (6)].Sval).text);	
								else if(temp->type != (yyvsp[(3) - (6)].node)->type) printf("PRINT type mismatch\n");
								(yyval.node)->child[1]->where = temp;
							}
    break;

  case 33:
#line 364 "cparser.y"
    {
								(yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(3) - (6)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (6)].Sval).text);
								(yyval.node)->child[0] = MakeNode(0); strcpy((yyval.node)->child[0]->lexeme,(yyvsp[(3) - (6)].Sval).text);
								(yyval.node)->child[1] = MakeNode(0); strcpy((yyval.node)->child[1]->lexeme,(yyvsp[(5) - (6)].Sval).text);
								
								(yyval.node)->child[1]->type = (yyvsp[(5) - (6)].Sval).type;
								(yyval.node)->child[1]->parent = (yyval.node);
								(yyval.node)->child[0]->type = (yyvsp[(3) - (6)].Sval).type;
								(yyval.node)->child[0]->parent = (yyval.node);

								if((yyvsp[(3) - (6)].Sval).type != (yyvsp[(5) - (6)].Sval).type){
									printf("max type error");
									Totalerrors++;
								}

								struct symbolTable *temp = FindSymbol((yyvsp[(3) - (6)].Sval).text,check,currentT);
								if(temp==NULL) printf("not found %s\n",(yyvsp[(3) - (6)].Sval).text);	
								(yyval.node)->child[0]->where = temp;

								temp = FindSymbol((yyvsp[(5) - (6)].Sval).text,check,currentT);
								if(temp==NULL) printf("not found %s\n",(yyvsp[(5) - (6)].Sval).text);	
								(yyval.node)->child[1]->where = temp;

								(yyval.node)->type = temp->type;

							}
    break;

  case 34:
#line 393 "cparser.y"
    {
								(yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(3) - (6)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (6)].Sval).text);
								(yyval.node)->child[0] = MakeNode(0); strcpy((yyval.node)->child[0]->lexeme,(yyvsp[(3) - (6)].Sval).text);
								(yyval.node)->child[1] = MakeNode(0); strcpy((yyval.node)->child[1]->lexeme,(yyvsp[(5) - (6)].Sval).text);
								
								(yyval.node)->child[1]->type = (yyvsp[(5) - (6)].Sval).type;
								(yyval.node)->child[1]->parent = (yyval.node);
								(yyval.node)->child[0]->type = (yyvsp[(3) - (6)].Sval).type;
								(yyval.node)->child[0]->parent = (yyval.node);

								if((yyvsp[(3) - (6)].Sval).type != (yyvsp[(5) - (6)].Sval).type){
									printf("min type error");
									Totalerrors++;
								}

								struct symbolTable *temp = FindSymbol((yyvsp[(3) - (6)].Sval).text,check,currentT);
								if(temp==NULL) printf("not found %s\n",(yyvsp[(3) - (6)].Sval).text);	
								(yyval.node)->child[0]->where = temp;

								temp = FindSymbol((yyvsp[(5) - (6)].Sval).text,check,currentT);
								if(temp==NULL) printf("not found %s\n",(yyvsp[(5) - (6)].Sval).text);	
								(yyval.node)->child[1]->where = temp;

								(yyval.node)->type = temp->type;
							}
    break;

  case 35:
#line 421 "cparser.y"
    {
								(yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(3) - (6)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (6)].Sval).text);
								(yyval.node)->child[0] = MakeNode(0); strcpy((yyval.node)->child[0]->lexeme,(yyvsp[(3) - (6)].Sval).text);
								(yyval.node)->child[1] = MakeNode(0); strcpy((yyval.node)->child[1]->lexeme,(yyvsp[(5) - (6)].Sval).text);
								
								(yyval.node)->child[1]->type = (yyvsp[(5) - (6)].Sval).type;
								(yyval.node)->child[1]->parent = (yyval.node);
								(yyval.node)->child[0]->type = (yyvsp[(3) - (6)].Sval).type;
								(yyval.node)->child[0]->parent = (yyval.node);

								if((yyvsp[(3) - (6)].Sval).type != (yyvsp[(5) - (6)].Sval).type){
									printf("swap type error");
									Totalerrors++;
								}

								struct symbolTable *temp = FindSymbol((yyvsp[(3) - (6)].Sval).text,check,currentT);
								if(temp==NULL) printf("not found %s\n",(yyvsp[(3) - (6)].Sval).text);	
								(yyval.node)->child[0]->where = temp;

								temp = FindSymbol((yyvsp[(5) - (6)].Sval).text,check,currentT);
								if(temp==NULL) printf("not found %s\n",(yyvsp[(5) - (6)].Sval).text);	
								(yyval.node)->child[1]->where = temp;

								(yyval.node)->type = temp->type;

							}
    break;

  case 36:
#line 452 "cparser.y"
    {
						(yyval.node) = (yyvsp[(1) - (2)].node);
					}
    break;

  case 37:
#line 455 "cparser.y"
    {
						(yyval.node) = (yyvsp[(1) - (2)].node);
					}
    break;

  case 38:
#line 458 "cparser.y"
    {
						(yyval.node) = (yyvsp[(1) - (2)].node);
					}
    break;

  case 39:
#line 463 "cparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 40:
#line 464 "cparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 41:
#line 465 "cparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 42:
#line 466 "cparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 43:
#line 467 "cparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 44:
#line 468 "cparser.y"
    {(yyval.node)=MakeNode(0); (yyval.node)->type = -1;strcpy((yyval.node)->lexeme,"dec");}
    break;

  case 45:
#line 469 "cparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 46:
#line 472 "cparser.y"
    {
						jumpcount++;
						currentT = EnterScope(currentT);
					}
    break;

  case 47:
#line 477 "cparser.y"
    {
						currentT = ExitScope(currentT);
					//	$$ = MakeNode(0); $$->type = 100; strcpy($$->lexeme,"}");
						jumpcount--;
						
					}
    break;

  case 48:
#line 486 "cparser.y"
    {
      						(yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(1) - (7)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (7)].Sval).text);
      						(yyval.node)->child[0] = (yyvsp[(3) - (7)].node); (yyvsp[(3) - (7)].node)->parent = (yyval.node); 
      						(yyval.node)->child[1] = (yyvsp[(6) - (7)].node); (yyvsp[(6) - (7)].node)->parent = (yyval.node);
      					//	$$->child[2] = $7; $7->parent = $$;
      						(yyval.node)->array = 10;			

      						(yyval.node)->scope = (yyvsp[(6) - (7)].node)->scope;
      						(yyval.node)->scopenode = (yyvsp[(6) - (7)].node)->scopenode;
      						propagate((yyvsp[(3) - (7)].node),(yyvsp[(6) - (7)].node)->scope,(yyvsp[(6) - (7)].node)->scopenode);	
      					}
    break;

  case 49:
#line 498 "cparser.y"
    {
      						(yyval.node) = MakeNode(3); (yyval.node)->type = (yyvsp[(1) - (8)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (8)].Sval).text);
      						(yyval.node)->child[0] = (yyvsp[(3) - (8)].node); (yyvsp[(3) - (8)].node)->parent = (yyval.node); 
      						(yyval.node)->child[1] = (yyvsp[(4) - (8)].node); (yyvsp[(4) - (8)].node)->parent = (yyval.node);
      						(yyval.node)->child[2] = (yyvsp[(7) - (8)].node); (yyvsp[(7) - (8)].node)->parent = (yyval.node);
      					//	$$->child[3] = $8; $8->parent = $$;
      						(yyval.node)->array = 11;				
      					
      						(yyval.node)->scope  = (yyvsp[(7) - (8)].node)->scope;
      						(yyval.node)->scopenode = (yyvsp[(7) - (8)].node)->scopenode;
      						propagate((yyvsp[(3) - (8)].node),(yyvsp[(7) - (8)].node)->scope,(yyvsp[(7) - (8)].node)->scopenode);
      						propagate((yyvsp[(4) - (8)].node),(yyvsp[(7) - (8)].node)->scope,(yyvsp[(7) - (8)].node)->scopenode);

      					}
    break;

  case 50:
#line 513 "cparser.y"
    {
      						(yyval.node) = MakeNode(4); (yyval.node)->type = (yyvsp[(1) - (9)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (9)].Sval).text);
      						(yyval.node)->child[0] = (yyvsp[(3) - (9)].node); (yyvsp[(3) - (9)].node)->parent = (yyval.node); 
      						(yyval.node)->child[1] = (yyvsp[(4) - (9)].node); (yyvsp[(4) - (9)].node)->parent = (yyval.node);
      						(yyval.node)->child[2] = (yyvsp[(5) - (9)].node); (yyvsp[(5) - (9)].node)->parent = (yyval.node);
      						(yyval.node)->child[3] = (yyvsp[(8) - (9)].node); (yyvsp[(8) - (9)].node)->parent = (yyval.node);
      				//		$$->child[4] = $9; $9->parent = $$;
      						(yyval.node)->array = 12;				

      						(yyval.node)->scope = (yyvsp[(8) - (9)].node)->scope;
      						(yyval.node)->scopenode = (yyvsp[(8) - (9)].node)->scopenode;
      						
      						propagate((yyvsp[(3) - (9)].node),(yyvsp[(8) - (9)].node)->scope,(yyvsp[(8) - (9)].node)->scopenode);
      						propagate((yyvsp[(4) - (9)].node),(yyvsp[(8) - (9)].node)->scope,(yyvsp[(8) - (9)].node)->scopenode);
      						propagate((yyvsp[(5) - (9)].node),(yyvsp[(8) - (9)].node)->scope,(yyvsp[(8) - (9)].node)->scopenode);
      					}
    break;

  case 51:
#line 532 "cparser.y"
    {
      						(yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(1) - (5)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (5)].Sval).text);
      						(yyval.node)->child[0] = (yyvsp[(3) - (5)].node); (yyvsp[(3) - (5)].node)->parent = (yyval.node); 
      						(yyval.node)->child[1] = (yyvsp[(5) - (5)].node); (yyvsp[(5) - (5)].node)->parent = (yyval.node);
      						(yyval.node)->array = 15;				
      					}
    break;

  case 52:
#line 540 "cparser.y"
    {
      						(yyval.node) = MakeNode(3); (yyval.node)->type = (yyvsp[(1) - (7)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (7)].Sval).text);
      						(yyval.node)->child[0] = (yyvsp[(3) - (7)].node); (yyvsp[(3) - (7)].node)->parent = (yyval.node); 
      						(yyval.node)->child[1] = (yyvsp[(5) - (7)].node); (yyvsp[(5) - (7)].node)->parent = (yyval.node);
      						(yyval.node)->child[2] = (yyvsp[(7) - (7)].node); (yyvsp[(7) - (7)].node)->parent = (yyval.node);
      						(yyval.node)->array = 16;				
      					}
    break;

  case 53:
#line 550 "cparser.y"
    { (yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(1) - (2)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (2)].Sval).text);
        								if(jumpcount<=0){
        									printf("CONTINUE without iteration_statement\n");
        									Totalerrors++;
        								}	
        							}
    break;

  case 54:
#line 556 "cparser.y"
    { (yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(1) - (2)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (2)].Sval).text);
        								if(jumpcount<=0){
        									printf("BREAK without iteration_statement\n");
        									Totalerrors++;
        								}
        							}
    break;

  case 55:
#line 562 "cparser.y"
    { (yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(1) - (2)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (2)].Sval).text);

        								if(returntype != VOID ){
        									printf("Invalid Return type\n");
        									Totalerrors++;
        								}	
        							}
    break;

  case 56:
#line 569 "cparser.y"
    { (yyval.node) = MakeNode(1); (yyval.node)->type = (yyvsp[(1) - (3)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (3)].Sval).text);
        								(yyval.node)->child[0] = (yyvsp[(2) - (3)].node); (yyvsp[(2) - (3)].node)->parent = (yyval.node);

        								if(returntype != (yyvsp[(2) - (3)].node)->type){
        									printf("Invalid Return type\n");
        									Totalerrors++;
        								}
        							}
    break;

  case 57:
#line 581 "cparser.y"
    { (yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,"=");}
    break;

  case 58:
#line 582 "cparser.y"
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);}
    break;

  case 59:
#line 583 "cparser.y"
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);}
    break;

  case 60:
#line 584 "cparser.y"
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);}
    break;

  case 61:
#line 585 "cparser.y"
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);}
    break;

  case 62:
#line 586 "cparser.y"
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);}
    break;

  case 63:
#line 587 "cparser.y"
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);}
    break;

  case 64:
#line 588 "cparser.y"
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);}
    break;

  case 65:
#line 589 "cparser.y"
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);}
    break;

  case 66:
#line 590 "cparser.y"
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);}
    break;

  case 67:
#line 591 "cparser.y"
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);}
    break;

  case 68:
#line 596 "cparser.y"
    {(yyval.node) = MakeNode(0); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,";");}
    break;

  case 69:
#line 597 "cparser.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node);}
    break;

  case 70:
#line 600 "cparser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 71:
#line 601 "cparser.y"
    {(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,",");
									 (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
									 (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);}
    break;

  case 72:
#line 607 "cparser.y"
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);

        								check.array = 0; check.struct_member = 0; 
        								//printf("parser :: %s %d\n",$1.text,$1.type);
        								struct symbolTable *temp = FindSymbol((yyvsp[(1) - (1)].Sval).text,check,currentT);
        								if(temp==NULL) printf("not found %s\n",(yyvsp[(1) - (1)].Sval).text);
        								else{
        										(yyval.node)->type = temp->type;
        										(yyval.node)->pointer = temp->pointer;
        									}
        								(yyval.node)->array = 300;	
        								(yyval.node)->where = temp;
        								(yyval.node)->lval = 1;


        							}
    break;

  case 73:
#line 623 "cparser.y"
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);

        								(yyval.node)->type = (yyvsp[(1) - (1)].Sval).type;
        								(yyval.node)->pointer = 0;
        								(yyval.node)->lval = 0;
        								(yyval.node)->array  = 200;
        							}
    break;

  case 74:
#line 630 "cparser.y"
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[(1) - (1)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (1)].Sval).text);

        								// not sure
        								(yyval.node)->lval = 0;
        								(yyval.node)->pointer = 0;
        							}
    break;

  case 75:
#line 636 "cparser.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node);

        								//$$->type = $2->type;
        							}
    break;

  case 76:
#line 640 "cparser.y"
    {
							(yyval.node) = (yyvsp[(1) - (1)].node);
						}
    break;

  case 77:
#line 643 "cparser.y"
    {
							(yyval.node) = (yyvsp[(1) - (1)].node);
						}
    break;

  case 78:
#line 649 "cparser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 79:
#line 650 "cparser.y"
    {(yyval.node)=MakeNode(1); (yyval.node)->type = (yyvsp[(1) - (4)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (4)].Sval).text);
										  (yyval.node)->child[0] = (yyvsp[(3) - (4)].node); (yyvsp[(3) - (4)].node)->parent = (yyval.node); (yyval.node)->array=1;

										  check.array = 1; check.struct_member = 0;
										  struct symbolTable *temp = FindSymbol((yyvsp[(1) - (4)].Sval).text,check,currentT);
        								  if(temp==NULL) printf("not found %s\n",(yyvsp[(1) - (4)].Sval).text);
        								  else{
	        								  if((yyvsp[(3) - (4)].node)->type != INT){
	        								  	printf("Array index must be integer\n");
	        								  	Totalerrors++;
	        								  }
	        								  else
	        								  	(yyval.node)->type = temp->type;
	        								  	(yyval.node)->pointer = temp->pointer;
        									}
        									(yyval.node)->array = 301;
        									(yyval.node)->where = temp;
        									(yyval.node)->lval = 1;	
										}
    break;

  case 80:
#line 669 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[(1) - (7)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (7)].Sval).text);
										  			(yyval.node)->child[0] = (yyvsp[(3) - (7)].node); (yyvsp[(3) - (7)].node)->parent = (yyval.node); 
										  			(yyval.node)->child[1] = (yyvsp[(6) - (7)].node); (yyvsp[(6) - (7)].node)->parent = (yyval.node); (yyval.node)->array=2;
										  			
										  			check.array = 2; check.struct_member = 0;
										  			struct symbolTable *temp = FindSymbol((yyvsp[(1) - (7)].Sval).text,check,currentT);
        											if(temp==NULL) printf("not found %s\n",(yyvsp[(1) - (7)].Sval).text);
        											else{
        											if((yyvsp[(3) - (7)].node)->type != INT || (yyvsp[(6) - (7)].node)->type != INT){
			        								  	printf("Array index must be integer\n");
			        								  	Totalerrors++;
			        								  }
			        								  else
			        								  	(yyval.node)->type = temp->type;
			        								  (yyval.node)->pointer = temp->pointer;
			        								}
			        								(yyval.node)->array = 302;
			        								(yyval.node)->where = temp;
			        								(yyval.node)->lval = 1;
										  		}
    break;

  case 81:
#line 689 "cparser.y"
    {(yyval.node)=MakeNode(0); (yyval.node)->type = (yyvsp[(1) - (3)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (3)].Sval).text);
										 (yyval.node)->array = 3;

										 	check.array = 3; check.struct_member = 0;
										 	struct symbolTable *temp = FindSymbol((yyvsp[(1) - (3)].Sval).text,check,currentT);
        									if(temp==NULL) printf("not found %s\n",(yyvsp[(1) - (3)].Sval).text);
        									else{
        										(yyval.node)->type = temp->type;
        										(yyval.node)->pointer = temp->pointer;
        									}
        									(yyval.node)->where = temp;
        									(yyval.node)->lval = 0;
										}
    break;

  case 82:
#line 702 "cparser.y"
    {(yyval.node)=MakeNode(1); (yyval.node)->type = (yyvsp[(1) - (4)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(1) - (4)].Sval).text);
										 (yyval.node)->array = 4; (yyval.node)->child[0]= (yyvsp[(3) - (4)].node); (yyvsp[(3) - (4)].node)->parent = (yyval.node);

										 check.array = 4; check.struct_member = 0;
										 struct symbolTable *temp = FindSymbol((yyvsp[(1) - (4)].Sval).text,check,currentT);
        								 if(temp==NULL) printf("not found %s\n",(yyvsp[(1) - (4)].Sval).text);

        								 else{
        										(yyval.node)->type = temp->type;
        										(yyval.node)->pointer = temp->pointer;
        									}
        									// check definition of function 
        									(yyval.node)->where = temp;
        									(yyval.node)->lval = 0;
							if(check_arg((yyvsp[(1) - (4)].Sval).text,(yyvsp[(3) - (4)].node))){
								printf("Argument type does not match\n");
							}	///calling parameter
										}
    break;

  case 83:
#line 721 "cparser.y"
    {(yyval.node) = MakeNode(2); (yyval.node)->type=100; strcpy((yyval.node)->lexeme,".") ;
										 (yyval.node)->child[0]=MakeNode(0); (yyval.node)->child[0]->type = (yyvsp[(1) - (3)].Sval).type; (yyval.node)->child[0]->parent = (yyval.node); 
										 (yyval.node)->child[1]=MakeNode(0); (yyval.node)->child[1]->type = (yyvsp[(3) - (3)].Sval).type; (yyval.node)->child[1]->parent = (yyval.node);
										 strcpy((yyval.node)->child[0]->lexeme,(yyvsp[(1) - (3)].Sval).text);strcpy((yyval.node)->child[1]->lexeme,(yyvsp[(3) - (3)].Sval).text);


										 check.array = 0; check.struct_member = 0; 
										 struct symbolTable *temp = FindSymbol((yyvsp[(1) - (3)].Sval).text,check,currentT);
        								 if(temp==NULL )
        								 	 printf("not found %s\n",(yyvsp[(1) - (3)].Sval).text);
        								 else if(temp->type != 5){	
        								 	 printf("not found %s\n",(yyvsp[(1) - (3)].Sval).text);
        								 	 Totalerrors++;
        								 	}
        								 else {
        								 	(yyval.node)->child[0]->where = temp;
        								 	char s[100];
        								 	check.array = 0; check.struct_member = 1; 
        								 	strcpy(s,"."); strcat(s,(yyvsp[(3) - (3)].Sval).text);
        								 	strcpy(check.structName,temp->structID);
        								 	temp = FindSymbol(s,check,currentT);
        								 	if(temp==NULL) printf("not found %s\n",s);
        								 	else{
        										(yyval.node)->type = temp->type;
        										(yyval.node)->pointer = temp->pointer;
        									}
        									(yyval.node)->child[1]->where = temp;

        								 }
        								 (yyval.node)->array = 303;
        								 (yyval.node)->lval = 1;

										}
    break;

  case 84:
#line 755 "cparser.y"
    { (yyval.node) = MakeNode(2); (yyval.node)->type=100; strcpy((yyval.node)->lexeme,".");
													 (yyval.node)->child[0]=MakeNode(1); (yyval.node)->child[1]=MakeNode(0);
													 (yyval.node)->child[0]->parent = (yyval.node); (yyval.node)->child[1]->parent = (yyval.node);
													 (yyval.node)->child[1]->type = (yyvsp[(6) - (6)].Sval).type; strcpy((yyval.node)->child[1]->lexeme,(yyvsp[(6) - (6)].Sval).text);
													 (yyval.node)->child[0]->type = (yyvsp[(1) - (6)].Sval).type; strcpy((yyval.node)->child[0]->lexeme,(yyvsp[(1) - (6)].Sval).text);
													 (yyval.node)->child[0]->child[0] = (yyvsp[(3) - (6)].node); (yyvsp[(3) - (6)].node)->parent = (yyval.node)->child[0];
													 (yyval.node)->child[0]->array = 1;

													 check.array = 1; check.struct_member = 0; 
													 struct symbolTable *temp = FindSymbol((yyvsp[(1) - (6)].Sval).text,check,currentT);
			        								 if(temp==NULL )
			        								 	 printf("not found %s\n",(yyvsp[(1) - (6)].Sval).text);
			        								 else if(temp->type != 5)	{
			        								 	 printf("not found %s\n",(yyvsp[(1) - (6)].Sval).text);
			        								 	 Totalerrors++;
			        								 }
			        								 else{
			        								 	(yyval.node)->child[0]->where = temp;
			        								 	char s[100];
			        								 	check.array = 0; check.struct_member = 1; 
			        								 	strcpy(s,"."); strcat(s,(yyvsp[(6) - (6)].Sval).text);
			        								 	strcpy(check.structName,temp->structID);
			        								 	temp = FindSymbol(s,check,currentT);
			        								 	if(temp==NULL) printf("not found %s\n",(yyvsp[(1) - (6)].Sval).text);
			        								 	else if((yyvsp[(3) - (6)].node)->type == INT){
			        										(yyval.node)->type = temp->type;
			        										(yyval.node)->pointer = temp->pointer;
			        									}
			        									else{
			        										printf("Array index must be integer\n");
			        										Totalerrors++;
			        									}
			        									(yyval.node)->child[1]->where = temp;
			        								 }
			        								 (yyval.node)->array = 304;
			        								 (yyval.node)->lval = 1;
													}
    break;

  case 85:
#line 794 "cparser.y"
    {(yyval.node)=MakeNode(0); (yyval.node)->type=100; strcpy((yyval.node)->lexeme,"+"); }
    break;

  case 86:
#line 795 "cparser.y"
    {(yyval.node)=MakeNode(0); (yyval.node)->type=100; strcpy((yyval.node)->lexeme,"-"); }
    break;

  case 87:
#line 796 "cparser.y"
    {(yyval.node)=MakeNode(0); (yyval.node)->type=100; strcpy((yyval.node)->lexeme,"!"); }
    break;

  case 88:
#line 797 "cparser.y"
    {(yyval.node)=MakeNode(0); (yyval.node)->type=100; strcpy((yyval.node)->lexeme,"~"); }
    break;

  case 89:
#line 798 "cparser.y"
    {(yyval.node)=MakeNode(0); (yyval.node)->type=100; strcpy((yyval.node)->lexeme,"*"); }
    break;

  case 90:
#line 799 "cparser.y"
    {(yyval.node)=MakeNode(0); (yyval.node)->type=100; strcpy((yyval.node)->lexeme,"&"); }
    break;

  case 91:
#line 802 "cparser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 92:
#line 803 "cparser.y"
    {(yyval.node)=MakeNode(1); (yyval.node)->type = (yyvsp[(1) - (2)].node)->type;	strcpy((yyval.node)->lexeme,(yyvsp[(1) - (2)].node)->lexeme);
							 (yyval.node)->child[0]=(yyvsp[(2) - (2)].node); (yyvsp[(2) - (2)].node)->parent = (yyval.node); 
							 
							 	(yyval.node)->lval = 0;
							 	if(strcmp((yyvsp[(1) - (2)].node)->lexeme,"+")==0 ||strcmp((yyvsp[(1) - (2)].node)->lexeme,"-")==0||strcmp((yyvsp[(1) - (2)].node)->lexeme,"!")==0)
							 		(yyval.node)->type = (yyvsp[(2) - (2)].node)->type;
							 	else if(strcmp((yyvsp[(1) - (2)].node)->lexeme,"~")==0 && (yyvsp[(2) - (2)].node)->type == INT)
							 		(yyval.node)->type = INT;
							 	else if(strcmp((yyvsp[(1) - (2)].node)->lexeme,"*")==0 && (yyvsp[(2) - (2)].node)->pointer == 1){
							 		(yyval.node)->type = (yyvsp[(2) - (2)].node)->type;
							 		if((yyvsp[(2) - (2)].node)->lval == 1)
							 			(yyval.node)->lval = 1;
							 	}
							 	else if(strcmp((yyvsp[(1) - (2)].node)->lexeme,"&")==0 && (yyvsp[(2) - (2)].node)->lval==1){ // to be modified
							 		(yyval.node)->type = (yyvsp[(2) - (2)].node)->type;
							 		(yyval.node)->pointer = 1;
							 	}	
							 	else{
							 		printf("Invalid operands for %s\n",(yyvsp[(1) - (2)].node)->lexeme);	
							 		Totalerrors++;
							 	}

							 	}
    break;

  case 93:
#line 826 "cparser.y"
    {(yyval.node)=MakeNode(1); (yyval.node)->type = (yyvsp[(1) - (4)].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[(1) - (4)].Sval).text);
							 (yyval.node)->child[0]=(yyvsp[(3) - (4)].node); (yyvsp[(3) - (4)].node)->parent = (yyval.node);

							 	(yyval.node)->type = INT;
							 	(yyval.node)->lval = 0;
							 	}
    break;

  case 94:
#line 834 "cparser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 95:
#line 835 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"*");
							 (yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);

							 if(((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type)){
							 			printf("Invalid operands for *\n");
							 			Totalerrors++;
							 	}		
					 		else	
							(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;

							 	}
    break;

  case 96:
#line 847 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"/");
							 (yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);

									if(((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type)){
							 			printf("Invalid operands for /\n");
										Totalerrors++;
									}
							 		else	
									(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;					 


							 	}
    break;

  case 97:
#line 860 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"%");
							 (yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);	

							 if(((yyvsp[(1) - (3)].node)->type != INT || (yyvsp[(3) - (3)].node)->type != INT)){
						 		printf("Invalid operands for modulus");
						 		Totalerrors++;
							 }else{
							 	(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;
							 }
							}
    break;

  case 98:
#line 873 "cparser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 99:
#line 874 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"+");
							 (yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);	

							 if((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type)	{
							 			printf("Invalid operands for +\n");
							 			Totalerrors++;
							 		}	
							 		else	
									(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;

							}
    break;

  case 100:
#line 886 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"-");
							 (yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);	

							 if((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type){
							 			Totalerrors++;
							 			printf("Invalid operands for -\n");
							 		}	
							 		else	
									(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;


							}
    break;

  case 101:
#line 901 "cparser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 102:
#line 902 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[(2) - (3)].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[(2) - (3)].Sval).text);
							 (yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);

								  if((yyvsp[(3) - (3)].node)->type != INT || (yyvsp[(1) - (3)].node)->type != INT ){
								 	printf("Invalid operands for %s\n",(yyvsp[(2) - (3)].Sval).text);
								 	Totalerrors++;
								 }else{
								 	(yyval.node)->type = INT;
								 }
							 	}
    break;

  case 103:
#line 913 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[(2) - (3)].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[(2) - (3)].Sval).text);
							 (yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);	


							 if((yyvsp[(3) - (3)].node)->type != INT  || (yyvsp[(1) - (3)].node)->type != INT){
							 	printf("Invalid operands for %s\n",(yyvsp[(2) - (3)].Sval).text);
							 	Totalerrors++;
							 }else{
							 	(yyval.node)->type = INT;
							 }
							}
    break;

  case 104:
#line 928 "cparser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 105:
#line 929 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"<");
							 (yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);


							 if((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type){
							 			printf("Invalid operands for <\n");
							 			Totalerrors++;
							 		}
							 		else	
									(yyval.node)->type = INT;

							 	}
    break;

  case 106:
#line 942 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,">");
							 (yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);

							 if((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type){
							 			printf("Invalid operands for >\n");
							 		Totalerrors++;
							 		}
							 		else	
									(yyval.node)->type = INT;

							 }
    break;

  case 107:
#line 956 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[(2) - (3)].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[(2) - (3)].Sval).text);
							 (yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);

							 if((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type){
							 			printf("Invalid operands for %s\n",(yyvsp[(2) - (3)].Sval).text);
							 		Totalerrors++;
							 	}
							 		else	
									(yyval.node)->type = INT;

							 	}
    break;

  case 108:
#line 968 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[(2) - (3)].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[(2) - (3)].Sval).text);
							 (yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);	

							 if((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type){
							 			printf("Invalid operands for %s\n",(yyvsp[(2) - (3)].Sval).text);
							 			Totalerrors++;
							 		}
							 		else	
									(yyval.node)->type = INT;

							}
    break;

  case 109:
#line 983 "cparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 110:
#line 985 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[(2) - (3)].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[(2) - (3)].Sval).text);
							 (yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);

							 	if((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type){
							 			printf("Invalid operands for %s\n",(yyvsp[(2) - (3)].Sval).text);
							 			Totalerrors++;
							 		}
							 		else	
									(yyval.node)->type = INT;

							 	}
    break;

  case 111:
#line 998 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[(2) - (3)].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[(2) - (3)].Sval).text);
							 		(yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 		(yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);	

							 		if((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type){
							 			printf("Invalid operands for %s\n",(yyvsp[(2) - (3)].Sval).text);
							 			Totalerrors++;
							 		}
							 		else	
									(yyval.node)->type = INT;
									 
							 	}
    break;

  case 112:
#line 1012 "cparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 113:
#line 1013 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"&");
							 (yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);	

							 if((yyvsp[(1) - (3)].node)->type != INT || (yyvsp[(3) - (3)].node)->type != INT){
							 	printf("Invalid operands for &\n");
							 	Totalerrors++;
							 }else{
							 	(yyval.node)->type = INT;
							 }


							}
    break;

  case 114:
#line 1028 "cparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 115:
#line 1029 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"^");
							 (yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);


							 if((yyvsp[(1) - (3)].node)->type != INT || (yyvsp[(3) - (3)].node)->type != INT){
							 	printf("Invalid operands for ^\n");
							 	Totalerrors++;
							 }else{
							 	(yyval.node)->type = INT;
							 }

							 }
    break;

  case 116:
#line 1044 "cparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 117:
#line 1045 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"|");
							 (yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);	

							 if((yyvsp[(1) - (3)].node)->type != INT || (yyvsp[(3) - (3)].node)->type != INT){
							 	printf("Invalid operands for |\n");
							 	Totalerrors++;
							 }else{
							 	(yyval.node)->type = INT;
							 }

							}
    break;

  case 118:
#line 1059 "cparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 119:
#line 1060 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[(2) - (3)].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[(2) - (3)].Sval).text);
							 (yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);

							 if((yyvsp[(1) - (3)].node)->type != INT || (yyvsp[(3) - (3)].node)->type != INT){
							 	printf("Invalid operands for %s\n",(yyvsp[(2) - (3)].Sval).text);
							 	Totalerrors++;
							 }else{
							 	(yyval.node)->type = INT;
							 }

							 }
    break;

  case 120:
#line 1074 "cparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 121:
#line 1075 "cparser.y"
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[(2) - (3)].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[(2) - (3)].Sval).text);
							 (yyval.node)->child[0]=(yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);	

							 if((yyvsp[(1) - (3)].node)->type != INT || (yyvsp[(3) - (3)].node)->type != INT){
							 	printf("Invalid operands for %s\n",(yyvsp[(2) - (3)].Sval).text);
							 	Totalerrors++;
							 }else{
							 	(yyval.node)->type = INT;
							 }

							}
    break;

  case 122:
#line 1090 "cparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 123:
#line 1093 "cparser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 124:
#line 1094 "cparser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
											 (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);

											 if((yyvsp[(1) - (3)].node)->lval != 1){
											 	printf("Not an Lvalue Expression\n");
											 	Totalerrors++;
											 }else{
												if((yyvsp[(2) - (3)].node)->type==100 || (yyvsp[(2) - (3)].node)->type == MUL_ASSIGN || (yyvsp[(2) - (3)].node)->type == DIV_ASSIGN || (yyvsp[(2) - (3)].node)->type == ADD_ASSIGN || (yyvsp[(2) - (3)].node)->type == SUB_ASSIGN){
													if((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type){
														printf("Invalid Operand for %s\n",(yyvsp[(2) - (3)].node)->lexeme);
														Totalerrors++;
														//printf("= %d %d",$1->type,$3->type);
													}
													else
														(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;
												}else{

													if((yyvsp[(1) - (3)].node)->type!=INT || (yyvsp[(3) - (3)].node)->type!=INT){
														printf("Invalid Operand for %s\n",(yyvsp[(2) - (3)].node)->lexeme);
														Totalerrors++;
													}
													else
														(yyval.node)->type = (yyvsp[(1) - (3)].node)->type;
												} 

											}
											(yyval.node)->lval = 0;
											}
    break;

  case 125:
#line 1124 "cparser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 126:
#line 1126 "cparser.y"
    { (yyval.node) = MakeNode(2); (yyval.node)->type =101; strcpy((yyval.node)->lexeme,";");
							  (yyval.node)->child[0] = (yyvsp[(1) - (2)].node); if((yyvsp[(1) - (2)].node) != NULL) (yyvsp[(1) - (2)].node)->parent = (yyval.node);
							  (yyval.node)->child[1] = (yyvsp[(2) - (2)].node);  if((yyvsp[(2) - (2)].node) != NULL) (yyvsp[(2) - (2)].node)->parent = (yyval.node);
							}
    break;

  case 127:
#line 1134 "cparser.y"
    {
			if(open == 0)
				currentT = EnterScope(currentT);
			else{
				open = 0;
			}
		}
    break;

  case 128:
#line 1144 "cparser.y"
    {
			currentT = ExitScope(currentT);
		}
    break;

  case 129:
#line 1150 "cparser.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 130:
#line 1155 "cparser.y"
    {
								open = 1;
								my.array = 3; my.pointer = 0; my.struct_member = 0; my.type = (yyvsp[(1) - (2)].node)->type;
								AddSymbol((yyvsp[(2) - (2)].Sval).text,my,currentT);

								currentT = EnterScope(currentT);

								(yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(2) - (2)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(2) - (2)].Sval).text);
								(yyval.node)->child[0] = (yyvsp[(1) - (2)].node); (yyvsp[(1) - (2)].node)->parent = (yyval.node);
								(yyval.node)->array = 50;

								returntype = (yyvsp[(1) - (2)].node)->type;
								returnpointer = 0;

							}
    break;

  case 131:
#line 1171 "cparser.y"
    {
								open = 1;

								my.array = 3; my.pointer = 0; my.struct_member = 0; my.type = 5;
								strcpy(my.structID,(yyvsp[(2) - (3)].Sval).text);
								AddSymbol((yyvsp[(3) - (3)].Sval).text,my,currentT);
								currentT = EnterScope(currentT);

								(yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(3) - (3)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(3) - (3)].Sval).text);
								(yyval.node)->child[0] = MakeNode(0); (yyval.node)->child[0]->type = (yyvsp[(2) - (3)].Sval).type; strcpy((yyval.node)->child[0]->lexeme,(yyvsp[(2) - (3)].Sval).text);
								(yyval.node)->child[0]->parent  = (yyval.node);
								(yyval.node)->array = 51;

								returntype = 5;
								returnpointer = 0;
								strcpy(returnchar,(yyvsp[(2) - (3)].Sval).text);
							}
    break;

  case 132:
#line 1189 "cparser.y"
    {
								open = 1;

								my.array = 3; my.pointer = 1; my.struct_member = 0; my.type = (yyvsp[(1) - (3)].node)->type;
								AddSymbol((yyvsp[(3) - (3)].Sval).text,my,currentT);
								currentT = EnterScope(currentT);

								(yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[(3) - (3)].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[(3) - (3)].Sval).text);
								(yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
								(yyval.node)->array = 52;

								returnpointer = 1;
								returntype = (yyvsp[(1) - (3)].node)->type;
							}
    break;

  case 133:
#line 1207 "cparser.y"
    {

									(yyval.node) = (yyvsp[(1) - (5)].node);
								//	$$->child[1] = $3; $3->parent = $$;
									(yyval.node)->child[1] = (yyvsp[(5) - (5)].node); (yyvsp[(5) - (5)].node)->parent = (yyval.node);

									ALL[funcount] = (struct allFunc *)malloc(sizeof(struct allFunc));
									strcpy(ALL[funcount]->name,(yyvsp[(1) - (5)].node)->lexeme);
									ALL[funcount]->t = (yyval.node);
									ALL[funcount]->arg = (yyvsp[(3) - (5)].node);
									ALL[funcount]->st = currentT->child[currentT->current - 1];
									funcount++;				
									//printf("I am in at %s %d\n",$1->lexeme,funcount);
								}
    break;

  case 134:
#line 1221 "cparser.y"
    {
									(yyval.node) = (yyvsp[(1) - (4)].node);
									(yyval.node)->child[1] = (yyvsp[(4) - (4)].node); (yyvsp[(4) - (4)].node)->parent = (yyval.node);
									//$$->NumChild -= 1;
									(yyval.node)->array += 3;	


									ALL[funcount] = (struct allFunc *)malloc(sizeof(struct allFunc));
									strcpy(ALL[funcount]->name,(yyvsp[(1) - (4)].node)->lexeme);
									ALL[funcount]->t = (yyval.node);
									ALL[funcount]->arg = NULL;
									ALL[funcount]->st = currentT->child[currentT->current - 1];		
									funcount++;						
									//printf("I am in at khali mei %s %d\n",$1->lexeme,funcount);
								}
    break;

  case 135:
#line 1239 "cparser.y"
    {(yyval.node)=MakeNode(0); (yyval.node)->type = -1;strcpy((yyval.node)->lexeme,"dec");}
    break;

  case 136:
#line 1240 "cparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node); tree = (yyval.node); }
    break;

  case 137:
#line 1241 "cparser.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node); tree = (yyval.node);}
    break;

  case 138:
#line 1243 "cparser.y"
    {(yyval.node) = MakeNode(2); (yyval.node)->type=1000; strcpy((yyval.node)->lexeme,"@");
					 (yyval.node)->child[0] = (yyvsp[(1) - (2)].node); (yyvsp[(1) - (2)].node)->parent = (yyval.node);
					 (yyval.node)->child[1] = (yyvsp[(2) - (2)].node); (yyvsp[(2) - (2)].node)->parent = (yyval.node);
					tree = (yyval.node);	}
    break;


/* Line 1267 of yacc.c.  */
#line 3220 "y.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 1250 "cparser.y"

yyerror(s)
char *s;
{
        fflush(stdout);
		printf("Parse Error\n");
		return 0;
}
int main()
{
	open = 0;
	jumpcount=0;
	returntype=0;
	returnpointer=0;
	Totalerrors=0;
	funcount = 0;
	init();
	yyparse();
	//AST_print(tree);
	depthSymbolTree(sym,1);
	printSymbolTree(sym);
	if(Totalerrors>0)
		printf("Total symantic errors: %d\n",Totalerrors);
	else{
		printf("Generating MIPS code...\n");
		GenerateMIPS();
	}
	
	return 0;
}


/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "cparser.y" /* yacc.c:339  */

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

#line 82 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "cparser.y" /* yacc.c:355  */

        struct AST *node;	// 非终结符语义值类型

        struct terminal{	// 终结符语义值类型
                        char *text;
                        int type;
                        int line;
        } Sval;


#line 221 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 238 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  271

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   108,   112,   119,   122,   125,   130,   138,
     140,   141,   145,   149,   173,   178,   184,   193,   207,   210,
     218,   226,   228,   236,   259,   262,   266,   291,   301,   313,
     321,   338,   356,   371,   400,   428,   459,   463,   466,   471,
     472,   473,   474,   475,   476,   477,   480,   485,   493,   505,
     520,   539,   546,   558,   564,   570,   577,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   604,   605,
     608,   609,   615,   631,   638,   644,   648,   651,   657,   658,
     677,   697,   710,   729,   763,   802,   803,   804,   805,   806,
     807,   810,   811,   834,   842,   843,   855,   868,   881,   882,
     894,   909,   910,   921,   936,   937,   950,   964,   976,   991,
     992,  1005,  1020,  1021,  1036,  1037,  1052,  1053,  1067,  1068,
    1082,  1083,  1098,  1101,  1102,  1132,  1133,  1141,  1151,  1158,
    1162,  1178,  1196,  1214,  1229,  1247,  1248,  1249,  1250
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "body", "function_name", "function", "program", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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

#define YYPACT_NINF -231

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-231)))

#define YYTABLE_NINF -133

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,   -10,  -231,     4,   235,   361,  -231,   329,  -231,  -231,
     103,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -114,  -222,
    -217,  -231,  -231,  -231,  -231,  -111,  -231,  -231,  -231,  -231,
     -97,   100,   101,    51,    97,   195,   196,   194,   197,   200,
    -231,  -231,   -71,  -230,  -231,  -231,   -34,  -231,   362,  -231
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

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 105 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);
								(yyval.node)->array = 0;
								}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 109 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[-3].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-3].Sval).text);
								(yyval.node)->array = 1; (yyval.node)->dim1 = atoi((yyvsp[-1].Sval).text);
								}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 113 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[-6].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-6].Sval).text);
								(yyval.node)->array = 2; (yyval.node)->dim1 = atoi((yyvsp[-4].Sval).text); (yyval.node)->dim2 = atoi((yyvsp[-1].Sval).text);
							}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 119 "cparser.y" /* yacc.c:1646  */
    {
									(yyval.node) = (yyvsp[0].node); (yyval.node)->pointer = 0;
								}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 122 "cparser.y" /* yacc.c:1646  */
    {
									(yyval.node) = (yyvsp[0].node); (yyval.node)->pointer = 1;
								}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 125 "cparser.y" /* yacc.c:1646  */
    {
									(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,",");
									(yyval.node)->child[0] = (yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node); 
									(yyval.node)->child[1] = (yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);  (yyvsp[0].node)->pointer = 0; 
							   }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 130 "cparser.y" /* yacc.c:1646  */
    {
									(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,",");
									(yyval.node)->child[0] = (yyvsp[-3].node); (yyvsp[-3].node)->parent = (yyval.node); 
									(yyval.node)->child[1] = (yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);  (yyvsp[0].node)->pointer = 1;
							   }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 138 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 140 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 141 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 145 "cparser.y" /* yacc.c:1646  */
    {
							(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);
							(yyval.node)->array = 0; (yyval.node)->pointer = 0;
						}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 149 "cparser.y" /* yacc.c:1646  */
    {
							(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);
							(yyval.node)->array = 0; (yyval.node)->pointer = 1;
						}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 174 "cparser.y" /* yacc.c:1646  */
    {
							(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);
							(yyval.node)->array = 0; (yyval.node)->pointer = 0;
						}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 179 "cparser.y" /* yacc.c:1646  */
    {
							(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[-3].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-3].Sval).text);
							(yyval.node)->array = 1; (yyval.node)->dim1 = atoi((yyvsp[-1].Sval).text);
							(yyval.node)->pointer = 0;
						}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 185 "cparser.y" /* yacc.c:1646  */
    {
							(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,",");
							(yyval.node)->child[1] = MakeNode(0); (yyval.node)->child[1]->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->child[1]->lexeme,(yyvsp[0].Sval).text);
							(yyval.node)->child[1]->parent = (yyval.node);
							(yyval.node)->child[1]->array = 0; (yyval.node)->child[1]->pointer = 0;
							(yyval.node)->child[0] = (yyvsp[-2].node);
							(yyvsp[-2].node)->parent = (yyval.node);	
						}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 194 "cparser.y" /* yacc.c:1646  */
    {
							(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,",");
							(yyval.node)->child[1] = MakeNode(0); (yyval.node)->child[1]->type = (yyvsp[-3].Sval).type; strcpy((yyval.node)->child[1]->lexeme,(yyvsp[-3].Sval).text);
							(yyval.node)->child[1]->parent = (yyval.node);
							(yyval.node)->child[1]->array = 1; (yyval.node)->child[1]->pointer = 0;
							(yyval.node)->child[1]->dim1 = atoi((yyvsp[-1].Sval).text);
							(yyval.node)->child[0] = (yyvsp[-5].node);
							(yyvsp[-5].node)->parent = (yyval.node);

						}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 207 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);
									(yyval.node)->array = 0; (yyval.node)->pointer = 0;
									}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 210 "cparser.y" /* yacc.c:1646  */
    {
									(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,",");
									(yyval.node)->child[0] = (yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node); 
									(yyval.node)->child[1] = MakeNode(0); (yyval.node)->child[1]->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->child[1]->lexeme,(yyvsp[0].Sval).text);
									(yyval.node)->child[1]->array=0; (yyval.node)->child[1]->pointer=0;  
								   }
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 218 "cparser.y" /* yacc.c:1646  */
    {
										(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,";");
										(yyval.node)->child[0] = (yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
										(yyval.node)->child[1] = (yyvsp[-1].node); (yyvsp[-1].node)->parent = (yyval.node);
									}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 226 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);
									}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 229 "cparser.y" /* yacc.c:1646  */
    {
										(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,"#"); 
										(yyval.node)->child[0] = (yyvsp[-1].node); (yyvsp[-1].node)->parent = (yyval.node);
										(yyval.node)->child[1] = (yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);
									}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 237 "cparser.y" /* yacc.c:1646  */
    {
									strcpy(maxi[init_count].in,(yyvsp[-3].Sval).text);
									(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[-3].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-3].Sval).text);
									my.type = 6;
									
									AddSymbol((yyvsp[-3].Sval).text,my,currentT);
									
									//AST_print($4);
									my.struct_member = 1;
									strcpy(my.structName,(yyvsp[-3].Sval).text);
									order=0;
									addVar(my,(yyvsp[-1].node),currentT);
									(yyval.node)->order = order;
									check.array = 6; check.struct_member = 0; 
									maxi[init_count].s=order;
									init_count++;
								//	struct symbolTable *temp = FindSymbol($2.text,check,currentT);
								//	temp->order = $$->order;
								}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 259 "cparser.y" /* yacc.c:1646  */
    {
								my.type = (yyvsp[-2].node)->type; my.struct_member = 0; addVar(my,(yyvsp[-1].node),currentT);
							}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 263 "cparser.y" /* yacc.c:1646  */
    {

							}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 267 "cparser.y" /* yacc.c:1646  */
    {
									int aman=0;
									for(;aman<init_count;aman++){
										if(strcmp(maxi[aman].in,(yyvsp[-2].Sval).text)==0)	break;
									}
									if(aman==init_count){
											printf("Kat Gaya\n");
									}
									else{
										my.order=maxi[aman].s;
									}
									my.struct_member=0;
									strcpy(my.structID,(yyvsp[-2].Sval).text);
									/*check.array = 6; check.struct_member = 0; 
									struct symbolTable *temp = FindSymbol($2.text,check,currentT);
									if(temp == NULL){
										printf("struct %s not found\n",$2.text );
										Totalerrors++;
									}else{
										my.order = temp->order;
									}*/
									my.type = 5;
									addVar(my,(yyvsp[-1].node),currentT);
								}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 292 "cparser.y" /* yacc.c:1646  */
    {
									my.struct_member=0;
									strcpy(my.structID,(yyvsp[-2].node)->lexeme);
									my.type = 5;
									my.order = (yyvsp[-2].node)->order;
									addVar(my,(yyvsp[-1].node),currentT);
							}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 302 "cparser.y" /* yacc.c:1646  */
    {
								currentT->parent->t->array  = 4;	
								(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,",");
								(yyval.node)->child[0] = (yyvsp[-3].node); (yyvsp[-3].node)->parent = (yyval.node);
								(yyval.node)->child[1] = (yyvsp[-1].node); (yyvsp[-1].node)->parent = (yyval.node);

								// add arg_var to symboltable
								my.type = (yyvsp[-1].node)->type; my.struct_member = 0;
								addVar(my,(yyvsp[0].node),currentT);

							}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 313 "cparser.y" /* yacc.c:1646  */
    { 
								currentT->parent->t->array  = 4;
								(yyval.node) = (yyvsp[-1].node);

								my.type = (yyvsp[-1].node)->type; my.struct_member = 0;
								addVar(my,(yyvsp[0].node),currentT);

							}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 322 "cparser.y" /* yacc.c:1646  */
    {
								currentT->parent->t->array  = 4;
								(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,",");
								(yyval.node)->child[0] = (yyvsp[-4].node); (yyvsp[-4].node)->parent = (yyval.node);
								(yyval.node)->child[1] = MakeNode(0); (yyval.node)->child[1]->parent = (yyval.node);
								(yyval.node)->child[1]->type = (yyvsp[-1].Sval).type;
								strcpy((yyval.node)->child[1]->lexeme,(yyvsp[-1].Sval).text);	
								(yyval.node)->child[1]->array = 60;	

								my.type = 5; strcpy(my.structID,(yyvsp[-1].Sval).text); my.struct_member = 0;
								AddSymbol((yyvsp[0].Sval).text,my,currentT);
							}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 339 "cparser.y" /* yacc.c:1646  */
    {
								(yyval.node) = MakeNode(2); (yyval.node)->type = 4; strcpy((yyval.node)->lexeme,(yyvsp[-5].Sval).text);
								(yyval.node)->child[0] = (yyvsp[-3].node); (yyvsp[-3].node)->parent = (yyval.node);
								(yyval.node)->child[1] = MakeNode(0); strcpy((yyval.node)->child[1]->lexeme,(yyvsp[-1].Sval).text);
								(yyval.node)->child[1]->type = (yyvsp[-1].Sval).type;
								(yyval.node)->child[1]->parent = (yyval.node);

								check.array = 0; check.struct_member = 0; 
								struct symbolTable *temp = FindSymbol((yyvsp[-1].Sval).text,check,currentT);
								if(temp==NULL) printf("not found %s\n",(yyvsp[-1].Sval).text);
								else if(temp->type != (yyvsp[-3].node)->type) printf("READ type mismatch\n");
								(yyval.node)->child[1]->where = temp;

							}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 357 "cparser.y" /* yacc.c:1646  */
    {
								(yyval.node) = MakeNode(2); (yyval.node)->type = 4; strcpy((yyval.node)->lexeme,(yyvsp[-5].Sval).text);
								(yyval.node)->child[0] = (yyvsp[-3].node); (yyvsp[-3].node)->parent = (yyval.node);
								(yyval.node)->child[1] = MakeNode(0); strcpy((yyval.node)->child[1]->lexeme,(yyvsp[-1].Sval).text);
								(yyval.node)->child[1]->type = (yyvsp[-1].Sval).type;
								(yyval.node)->child[1]->parent = (yyval.node);

								check.array = 0; check.struct_member = 0; 
								struct symbolTable *temp = FindSymbol((yyvsp[-1].Sval).text,check,currentT);
								if(temp==NULL) printf("not found %s\n",(yyvsp[-1].Sval).text);	
								else if(temp->type != (yyvsp[-3].node)->type) printf("PRINT type mismatch\n");
								(yyval.node)->child[1]->where = temp;
							}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 372 "cparser.y" /* yacc.c:1646  */
    {
								(yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[-3].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-5].Sval).text);
								(yyval.node)->child[0] = MakeNode(0); strcpy((yyval.node)->child[0]->lexeme,(yyvsp[-3].Sval).text);
								(yyval.node)->child[1] = MakeNode(0); strcpy((yyval.node)->child[1]->lexeme,(yyvsp[-1].Sval).text);
								
								(yyval.node)->child[1]->type = (yyvsp[-1].Sval).type;
								(yyval.node)->child[1]->parent = (yyval.node);
								(yyval.node)->child[0]->type = (yyvsp[-3].Sval).type;
								(yyval.node)->child[0]->parent = (yyval.node);

								if((yyvsp[-3].Sval).type != (yyvsp[-1].Sval).type){
									printf("max type error");
									Totalerrors++;
								}

								struct symbolTable *temp = FindSymbol((yyvsp[-3].Sval).text,check,currentT);
								if(temp==NULL) printf("not found %s\n",(yyvsp[-3].Sval).text);	
								(yyval.node)->child[0]->where = temp;

								temp = FindSymbol((yyvsp[-1].Sval).text,check,currentT);
								if(temp==NULL) printf("not found %s\n",(yyvsp[-1].Sval).text);	
								(yyval.node)->child[1]->where = temp;

								(yyval.node)->type = temp->type;

							}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 401 "cparser.y" /* yacc.c:1646  */
    {
								(yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[-3].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-5].Sval).text);
								(yyval.node)->child[0] = MakeNode(0); strcpy((yyval.node)->child[0]->lexeme,(yyvsp[-3].Sval).text);
								(yyval.node)->child[1] = MakeNode(0); strcpy((yyval.node)->child[1]->lexeme,(yyvsp[-1].Sval).text);
								
								(yyval.node)->child[1]->type = (yyvsp[-1].Sval).type;
								(yyval.node)->child[1]->parent = (yyval.node);
								(yyval.node)->child[0]->type = (yyvsp[-3].Sval).type;
								(yyval.node)->child[0]->parent = (yyval.node);

								if((yyvsp[-3].Sval).type != (yyvsp[-1].Sval).type){
									printf("min type error");
									Totalerrors++;
								}

								struct symbolTable *temp = FindSymbol((yyvsp[-3].Sval).text,check,currentT);
								if(temp==NULL) printf("not found %s\n",(yyvsp[-3].Sval).text);	
								(yyval.node)->child[0]->where = temp;

								temp = FindSymbol((yyvsp[-1].Sval).text,check,currentT);
								if(temp==NULL) printf("not found %s\n",(yyvsp[-1].Sval).text);	
								(yyval.node)->child[1]->where = temp;

								(yyval.node)->type = temp->type;
							}
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 429 "cparser.y" /* yacc.c:1646  */
    {
								(yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[-3].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-5].Sval).text);
								(yyval.node)->child[0] = MakeNode(0); strcpy((yyval.node)->child[0]->lexeme,(yyvsp[-3].Sval).text);
								(yyval.node)->child[1] = MakeNode(0); strcpy((yyval.node)->child[1]->lexeme,(yyvsp[-1].Sval).text);
								
								(yyval.node)->child[1]->type = (yyvsp[-1].Sval).type;
								(yyval.node)->child[1]->parent = (yyval.node);
								(yyval.node)->child[0]->type = (yyvsp[-3].Sval).type;
								(yyval.node)->child[0]->parent = (yyval.node);

								if((yyvsp[-3].Sval).type != (yyvsp[-1].Sval).type){
									printf("swap type error");
									Totalerrors++;
								}

								struct symbolTable *temp = FindSymbol((yyvsp[-3].Sval).text,check,currentT);
								if(temp==NULL) printf("not found %s\n",(yyvsp[-3].Sval).text);	
								(yyval.node)->child[0]->where = temp;

								temp = FindSymbol((yyvsp[-1].Sval).text,check,currentT);
								if(temp==NULL) printf("not found %s\n",(yyvsp[-1].Sval).text);	
								(yyval.node)->child[1]->where = temp;

								(yyval.node)->type = temp->type;

							}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 460 "cparser.y" /* yacc.c:1646  */
    {
						(yyval.node) = (yyvsp[-1].node);
					}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 463 "cparser.y" /* yacc.c:1646  */
    {
						(yyval.node) = (yyvsp[-1].node);
					}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 466 "cparser.y" /* yacc.c:1646  */
    {
						(yyval.node) = (yyvsp[-1].node);
					}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 471 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 472 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 473 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 474 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 475 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 476 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(0); (yyval.node)->type = -1;strcpy((yyval.node)->lexeme,"dec");}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 477 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 480 "cparser.y" /* yacc.c:1646  */
    {
						jumpcount++;
						currentT = EnterScope(currentT);
					}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 485 "cparser.y" /* yacc.c:1646  */
    {
						currentT = ExitScope(currentT);
					//	$$ = MakeNode(0); $$->type = 100; strcpy($$->lexeme,"}");
						jumpcount--;
						
					}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 494 "cparser.y" /* yacc.c:1646  */
    {
      						(yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[-6].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-6].Sval).text);
      						(yyval.node)->child[0] = (yyvsp[-4].node); (yyvsp[-4].node)->parent = (yyval.node); 
      						(yyval.node)->child[1] = (yyvsp[-1].node); (yyvsp[-1].node)->parent = (yyval.node);
      					//	$$->child[2] = $7; $7->parent = $$;
      						(yyval.node)->array = 10;			

      						(yyval.node)->scope = (yyvsp[-1].node)->scope;
      						(yyval.node)->scopenode = (yyvsp[-1].node)->scopenode;
      						propagate((yyvsp[-4].node),(yyvsp[-1].node)->scope,(yyvsp[-1].node)->scopenode);	
      					}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 506 "cparser.y" /* yacc.c:1646  */
    {
      						(yyval.node) = MakeNode(3); (yyval.node)->type = (yyvsp[-7].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-7].Sval).text);
      						(yyval.node)->child[0] = (yyvsp[-5].node); (yyvsp[-5].node)->parent = (yyval.node); 
      						(yyval.node)->child[1] = (yyvsp[-4].node); (yyvsp[-4].node)->parent = (yyval.node);
      						(yyval.node)->child[2] = (yyvsp[-1].node); (yyvsp[-1].node)->parent = (yyval.node);
      					//	$$->child[3] = $8; $8->parent = $$;
      						(yyval.node)->array = 11;				
      					
      						(yyval.node)->scope  = (yyvsp[-1].node)->scope;
      						(yyval.node)->scopenode = (yyvsp[-1].node)->scopenode;
      						propagate((yyvsp[-5].node),(yyvsp[-1].node)->scope,(yyvsp[-1].node)->scopenode);
      						propagate((yyvsp[-4].node),(yyvsp[-1].node)->scope,(yyvsp[-1].node)->scopenode);

      					}
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 521 "cparser.y" /* yacc.c:1646  */
    {
      						(yyval.node) = MakeNode(4); (yyval.node)->type = (yyvsp[-8].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-8].Sval).text);
      						(yyval.node)->child[0] = (yyvsp[-6].node); (yyvsp[-6].node)->parent = (yyval.node); 
      						(yyval.node)->child[1] = (yyvsp[-5].node); (yyvsp[-5].node)->parent = (yyval.node);
      						(yyval.node)->child[2] = (yyvsp[-4].node); (yyvsp[-4].node)->parent = (yyval.node);
      						(yyval.node)->child[3] = (yyvsp[-1].node); (yyvsp[-1].node)->parent = (yyval.node);
      				//		$$->child[4] = $9; $9->parent = $$;
      						(yyval.node)->array = 12;				

      						(yyval.node)->scope = (yyvsp[-1].node)->scope;
      						(yyval.node)->scopenode = (yyvsp[-1].node)->scopenode;
      						
      						propagate((yyvsp[-6].node),(yyvsp[-1].node)->scope,(yyvsp[-1].node)->scopenode);
      						propagate((yyvsp[-5].node),(yyvsp[-1].node)->scope,(yyvsp[-1].node)->scopenode);
      						propagate((yyvsp[-4].node),(yyvsp[-1].node)->scope,(yyvsp[-1].node)->scopenode);
      					}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 540 "cparser.y" /* yacc.c:1646  */
    {
      						(yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[-4].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-4].Sval).text);
      						(yyval.node)->child[0] = (yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node); 
      						(yyval.node)->child[1] = (yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);
      						(yyval.node)->array = 15;				
      					}
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 548 "cparser.y" /* yacc.c:1646  */
    {
      						(yyval.node) = MakeNode(3); (yyval.node)->type = (yyvsp[-6].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-6].Sval).text);
      						(yyval.node)->child[0] = (yyvsp[-4].node); (yyvsp[-4].node)->parent = (yyval.node); 
      						(yyval.node)->child[1] = (yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
      						(yyval.node)->child[2] = (yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);
      						(yyval.node)->array = 16;				
      					}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 558 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[-1].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-1].Sval).text);
        								if(jumpcount<=0){
        									printf("CONTINUE without iteration_statement\n");
        									Totalerrors++;
        								}	
        							}
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 564 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[-1].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-1].Sval).text);
        								if(jumpcount<=0){
        									printf("BREAK without iteration_statement\n");
        									Totalerrors++;
        								}
        							}
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 570 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[-1].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-1].Sval).text);

        								if(returntype != VOID ){
        									printf("Invalid Return type\n");
        									Totalerrors++;
        								}	
        							}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 577 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = MakeNode(1); (yyval.node)->type = (yyvsp[-2].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-2].Sval).text);
        								(yyval.node)->child[0] = (yyvsp[-1].node); (yyvsp[-1].node)->parent = (yyval.node);

        								if(returntype != (yyvsp[-1].node)->type){
        									printf("Invalid Return type\n");
        									Totalerrors++;
        								}
        							}
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 589 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,"=");}
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 590 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);}
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 591 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);}
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 592 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);}
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 593 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 594 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);}
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 595 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);}
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 596 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);}
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 597 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);}
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 598 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);}
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 599 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);}
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 604 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = MakeNode(0); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,";");}
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 605 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 608 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 609 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = MakeNode(2); (yyval.node)->type = 100; strcpy((yyval.node)->lexeme,",");
									 (yyval.node)->child[0] = (yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
									 (yyval.node)->child[1] = (yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);}
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 615 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);

        								check.array = 0; check.struct_member = 0; 
        								//printf("parser :: %s %d\n",$1.text,$1.type);
        								struct symbolTable *temp = FindSymbol((yyvsp[0].Sval).text,check,currentT);
        								if(temp==NULL) printf("not found %s\n",(yyvsp[0].Sval).text);
        								else{
        										(yyval.node)->type = temp->type;
        										(yyval.node)->pointer = temp->pointer;
        									}
        								(yyval.node)->array = 300;	
        								(yyval.node)->where = temp;
        								(yyval.node)->lval = 1;


        							}
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 631 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);

        								(yyval.node)->type = (yyvsp[0].Sval).type;
        								(yyval.node)->pointer = 0;
        								(yyval.node)->lval = 0;
        								(yyval.node)->array  = 200;
        							}
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 638 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = MakeNode(0); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);

        								// not sure
        								(yyval.node)->lval = 0;
        								(yyval.node)->pointer = 0;
        							}
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 644 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);

        								//$$->type = $2->type;
        							}
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 648 "cparser.y" /* yacc.c:1646  */
    {
							(yyval.node) = (yyvsp[0].node);
						}
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 651 "cparser.y" /* yacc.c:1646  */
    {
							(yyval.node) = (yyvsp[0].node);
						}
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 657 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 658 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(1); (yyval.node)->type = (yyvsp[-3].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-3].Sval).text);
										  (yyval.node)->child[0] = (yyvsp[-1].node); (yyvsp[-1].node)->parent = (yyval.node); (yyval.node)->array=1;

										  check.array = 1; check.struct_member = 0;
										  struct symbolTable *temp = FindSymbol((yyvsp[-3].Sval).text,check,currentT);
        								  if(temp==NULL) printf("not found %s\n",(yyvsp[-3].Sval).text);
        								  else{
	        								  if((yyvsp[-1].node)->type != INT){
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
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 677 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[-6].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-6].Sval).text);
										  			(yyval.node)->child[0] = (yyvsp[-4].node); (yyvsp[-4].node)->parent = (yyval.node); 
										  			(yyval.node)->child[1] = (yyvsp[-1].node); (yyvsp[-1].node)->parent = (yyval.node); (yyval.node)->array=2;
										  			
										  			check.array = 2; check.struct_member = 0;
										  			struct symbolTable *temp = FindSymbol((yyvsp[-6].Sval).text,check,currentT);
        											if(temp==NULL) printf("not found %s\n",(yyvsp[-6].Sval).text);
        											else{
        											if((yyvsp[-4].node)->type != INT || (yyvsp[-1].node)->type != INT){
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
#line 2407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 697 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(0); (yyval.node)->type = (yyvsp[-2].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-2].Sval).text);
										 (yyval.node)->array = 3;

										 	check.array = 3; check.struct_member = 0;
										 	struct symbolTable *temp = FindSymbol((yyvsp[-2].Sval).text,check,currentT);
        									if(temp==NULL) printf("not found %s\n",(yyvsp[-2].Sval).text);
        									else{
        										(yyval.node)->type = temp->type;
        										(yyval.node)->pointer = temp->pointer;
        									}
        									(yyval.node)->where = temp;
        									(yyval.node)->lval = 0;
										}
#line 2425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 710 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(1); (yyval.node)->type = (yyvsp[-3].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[-3].Sval).text);
										 (yyval.node)->array = 4; (yyval.node)->child[0]= (yyvsp[-1].node); (yyvsp[-1].node)->parent = (yyval.node);

										 check.array = 4; check.struct_member = 0;
										 struct symbolTable *temp = FindSymbol((yyvsp[-3].Sval).text,check,currentT);
        								 if(temp==NULL) printf("not found %s\n",(yyvsp[-3].Sval).text);

        								 else{
        										(yyval.node)->type = temp->type;
        										(yyval.node)->pointer = temp->pointer;
        									}
        									// check definition of function 
        									(yyval.node)->where = temp;
        									(yyval.node)->lval = 0;
							if(check_arg((yyvsp[-3].Sval).text,(yyvsp[-1].node))){
								printf("Argument type does not match\n");
							}	///calling parameter
										}
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 729 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = MakeNode(2); (yyval.node)->type=100; strcpy((yyval.node)->lexeme,".") ;
										 (yyval.node)->child[0]=MakeNode(0); (yyval.node)->child[0]->type = (yyvsp[-2].Sval).type; (yyval.node)->child[0]->parent = (yyval.node); 
										 (yyval.node)->child[1]=MakeNode(0); (yyval.node)->child[1]->type = (yyvsp[0].Sval).type; (yyval.node)->child[1]->parent = (yyval.node);
										 strcpy((yyval.node)->child[0]->lexeme,(yyvsp[-2].Sval).text);strcpy((yyval.node)->child[1]->lexeme,(yyvsp[0].Sval).text);


										 check.array = 0; check.struct_member = 0; 
										 struct symbolTable *temp = FindSymbol((yyvsp[-2].Sval).text,check,currentT);
        								 if(temp==NULL )
        								 	 printf("not found %s\n",(yyvsp[-2].Sval).text);
        								 else if(temp->type != 5){	
        								 	 printf("not found %s\n",(yyvsp[-2].Sval).text);
        								 	 Totalerrors++;
        								 	}
        								 else {
        								 	(yyval.node)->child[0]->where = temp;
        								 	char s[100];
        								 	check.array = 0; check.struct_member = 1; 
        								 	strcpy(s,"."); strcat(s,(yyvsp[0].Sval).text);
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
#line 2486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 763 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = MakeNode(2); (yyval.node)->type=100; strcpy((yyval.node)->lexeme,".");
													 (yyval.node)->child[0]=MakeNode(1); (yyval.node)->child[1]=MakeNode(0);
													 (yyval.node)->child[0]->parent = (yyval.node); (yyval.node)->child[1]->parent = (yyval.node);
													 (yyval.node)->child[1]->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->child[1]->lexeme,(yyvsp[0].Sval).text);
													 (yyval.node)->child[0]->type = (yyvsp[-5].Sval).type; strcpy((yyval.node)->child[0]->lexeme,(yyvsp[-5].Sval).text);
													 (yyval.node)->child[0]->child[0] = (yyvsp[-3].node); (yyvsp[-3].node)->parent = (yyval.node)->child[0];
													 (yyval.node)->child[0]->array = 1;

													 check.array = 1; check.struct_member = 0; 
													 struct symbolTable *temp = FindSymbol((yyvsp[-5].Sval).text,check,currentT);
			        								 if(temp==NULL )
			        								 	 printf("not found %s\n",(yyvsp[-5].Sval).text);
			        								 else if(temp->type != 5)	{
			        								 	 printf("not found %s\n",(yyvsp[-5].Sval).text);
			        								 	 Totalerrors++;
			        								 }
			        								 else{
			        								 	(yyval.node)->child[0]->where = temp;
			        								 	char s[100];
			        								 	check.array = 0; check.struct_member = 1; 
			        								 	strcpy(s,"."); strcat(s,(yyvsp[0].Sval).text);
			        								 	strcpy(check.structName,temp->structID);
			        								 	temp = FindSymbol(s,check,currentT);
			        								 	if(temp==NULL) printf("not found %s\n",(yyvsp[-5].Sval).text);
			        								 	else if((yyvsp[-3].node)->type == INT){
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
#line 2528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 802 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(0); (yyval.node)->type=100; strcpy((yyval.node)->lexeme,"+"); }
#line 2534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 803 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(0); (yyval.node)->type=100; strcpy((yyval.node)->lexeme,"-"); }
#line 2540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 804 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(0); (yyval.node)->type=100; strcpy((yyval.node)->lexeme,"!"); }
#line 2546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 805 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(0); (yyval.node)->type=100; strcpy((yyval.node)->lexeme,"~"); }
#line 2552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 806 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(0); (yyval.node)->type=100; strcpy((yyval.node)->lexeme,"*"); }
#line 2558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 807 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(0); (yyval.node)->type=100; strcpy((yyval.node)->lexeme,"&"); }
#line 2564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 810 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 811 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(1); (yyval.node)->type = (yyvsp[-1].node)->type;	strcpy((yyval.node)->lexeme,(yyvsp[-1].node)->lexeme);
							 (yyval.node)->child[0]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node); 
							 
							 	(yyval.node)->lval = 0;
							 	if(strcmp((yyvsp[-1].node)->lexeme,"+")==0 ||strcmp((yyvsp[-1].node)->lexeme,"-")==0||strcmp((yyvsp[-1].node)->lexeme,"!")==0)
							 		(yyval.node)->type = (yyvsp[0].node)->type;
							 	else if(strcmp((yyvsp[-1].node)->lexeme,"~")==0 && (yyvsp[0].node)->type == INT)
							 		(yyval.node)->type = INT;
							 	else if(strcmp((yyvsp[-1].node)->lexeme,"*")==0 && (yyvsp[0].node)->pointer == 1){
							 		(yyval.node)->type = (yyvsp[0].node)->type;
							 		if((yyvsp[0].node)->lval == 1)
							 			(yyval.node)->lval = 1;
							 	}
							 	else if(strcmp((yyvsp[-1].node)->lexeme,"&")==0 && (yyvsp[0].node)->lval==1){ // to be modified
							 		(yyval.node)->type = (yyvsp[0].node)->type;
							 		(yyval.node)->pointer = 1;
							 	}	
							 	else{
							 		printf("Invalid operands for %s\n",(yyvsp[-1].node)->lexeme);	
							 		Totalerrors++;
							 	}

							 	}
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 834 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(1); (yyval.node)->type = (yyvsp[-3].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[-3].Sval).text);
							 (yyval.node)->child[0]=(yyvsp[-1].node); (yyvsp[-1].node)->parent = (yyval.node);

							 	(yyval.node)->type = INT;
							 	(yyval.node)->lval = 0;
							 	}
#line 2609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 842 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 843 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"*");
							 (yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);

							 if(((yyvsp[-2].node)->type != (yyvsp[0].node)->type)){
							 			printf("Invalid operands for *\n");
							 			Totalerrors++;
							 	}		
					 		else	
							(yyval.node)->type = (yyvsp[-2].node)->type;

							 	}
#line 2632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 855 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"/");
							 (yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);

									if(((yyvsp[-2].node)->type != (yyvsp[0].node)->type)){
							 			printf("Invalid operands for /\n");
										Totalerrors++;
									}
							 		else	
									(yyval.node)->type = (yyvsp[-2].node)->type;					 


							 	}
#line 2650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 868 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"%");
							 (yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);	

							 if(((yyvsp[-2].node)->type != INT || (yyvsp[0].node)->type != INT)){
						 		printf("Invalid operands for modulus");
						 		Totalerrors++;
							 }else{
							 	(yyval.node)->type = (yyvsp[-2].node)->type;
							 }
							}
#line 2666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 881 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 882 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"+");
							 (yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);	

							 if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)	{
							 			printf("Invalid operands for +\n");
							 			Totalerrors++;
							 		}	
							 		else	
									(yyval.node)->type = (yyvsp[-2].node)->type;

							}
#line 2689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 894 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"-");
							 (yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);	

							 if((yyvsp[-2].node)->type != (yyvsp[0].node)->type){
							 			Totalerrors++;
							 			printf("Invalid operands for -\n");
							 		}	
							 		else	
									(yyval.node)->type = (yyvsp[-2].node)->type;


							}
#line 2707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 909 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 910 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[-1].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[-1].Sval).text);
							 (yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);

								  if((yyvsp[0].node)->type != INT || (yyvsp[-2].node)->type != INT ){
								 	printf("Invalid operands for %s\n",(yyvsp[-1].Sval).text);
								 	Totalerrors++;
								 }else{
								 	(yyval.node)->type = INT;
								 }
							 	}
#line 2729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 921 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[-1].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[-1].Sval).text);
							 (yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);	


							 if((yyvsp[0].node)->type != INT  || (yyvsp[-2].node)->type != INT){
							 	printf("Invalid operands for %s\n",(yyvsp[-1].Sval).text);
							 	Totalerrors++;
							 }else{
							 	(yyval.node)->type = INT;
							 }
							}
#line 2746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 936 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 937 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"<");
							 (yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);


							 if((yyvsp[-2].node)->type != (yyvsp[0].node)->type){
							 			printf("Invalid operands for <\n");
							 			Totalerrors++;
							 		}
							 		else	
									(yyval.node)->type = INT;

							 	}
#line 2770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 950 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,">");
							 (yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);

							 if((yyvsp[-2].node)->type != (yyvsp[0].node)->type){
							 			printf("Invalid operands for >\n");
							 		Totalerrors++;
							 		}
							 		else	
									(yyval.node)->type = INT;

							 }
#line 2787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 964 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[-1].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[-1].Sval).text);
							 (yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);

							 if((yyvsp[-2].node)->type != (yyvsp[0].node)->type){
							 			printf("Invalid operands for %s\n",(yyvsp[-1].Sval).text);
							 		Totalerrors++;
							 	}
							 		else	
									(yyval.node)->type = INT;

							 	}
#line 2804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 976 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[-1].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[-1].Sval).text);
							 (yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);	

							 if((yyvsp[-2].node)->type != (yyvsp[0].node)->type){
							 			printf("Invalid operands for %s\n",(yyvsp[-1].Sval).text);
							 			Totalerrors++;
							 		}
							 		else	
									(yyval.node)->type = INT;

							}
#line 2821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 991 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 993 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[-1].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[-1].Sval).text);
							 (yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);

							 	if((yyvsp[-2].node)->type != (yyvsp[0].node)->type){
							 			printf("Invalid operands for %s\n",(yyvsp[-1].Sval).text);
							 			Totalerrors++;
							 		}
							 		else	
									(yyval.node)->type = INT;

							 	}
#line 2844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1006 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[-1].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[-1].Sval).text);
							 		(yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 		(yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);	

							 		if((yyvsp[-2].node)->type != (yyvsp[0].node)->type){
							 			printf("Invalid operands for %s\n",(yyvsp[-1].Sval).text);
							 			Totalerrors++;
							 		}
							 		else	
									(yyval.node)->type = INT;
									 
							 	}
#line 2861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1020 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1021 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"&");
							 (yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);	

							 if((yyvsp[-2].node)->type != INT || (yyvsp[0].node)->type != INT){
							 	printf("Invalid operands for &\n");
							 	Totalerrors++;
							 }else{
							 	(yyval.node)->type = INT;
							 }


							}
#line 2885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1036 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1037 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"^");
							 (yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);


							 if((yyvsp[-2].node)->type != INT || (yyvsp[0].node)->type != INT){
							 	printf("Invalid operands for ^\n");
							 	Totalerrors++;
							 }else{
							 	(yyval.node)->type = INT;
							 }

							 }
#line 2909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1052 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1053 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = 100;	strcpy((yyval.node)->lexeme,"|");
							 (yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);	

							 if((yyvsp[-2].node)->type != INT || (yyvsp[0].node)->type != INT){
							 	printf("Invalid operands for |\n");
							 	Totalerrors++;
							 }else{
							 	(yyval.node)->type = INT;
							 }

							}
#line 2932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1067 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1068 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[-1].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[-1].Sval).text);
							 (yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);

							 if((yyvsp[-2].node)->type != INT || (yyvsp[0].node)->type != INT){
							 	printf("Invalid operands for %s\n",(yyvsp[-1].Sval).text);
							 	Totalerrors++;
							 }else{
							 	(yyval.node)->type = INT;
							 }

							 }
#line 2955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1082 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1083 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(2); (yyval.node)->type = (yyvsp[-1].Sval).type;	strcpy((yyval.node)->lexeme,(yyvsp[-1].Sval).text);
							 (yyval.node)->child[0]=(yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
							 (yyval.node)->child[1]=(yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);	

							 if((yyvsp[-2].node)->type != INT || (yyvsp[0].node)->type != INT){
							 	printf("Invalid operands for %s\n",(yyvsp[-1].Sval).text);
							 	Totalerrors++;
							 }else{
							 	(yyval.node)->type = INT;
							 }

							}
#line 2978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1098 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1101 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1102 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); (yyval.node)->child[0] = (yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
											 (yyval.node)->child[1] = (yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);

											 if((yyvsp[-2].node)->lval != 1){
											 	printf("Not an Lvalue Expression\n");
											 	Totalerrors++;
											 }else{
												if((yyvsp[-1].node)->type==100 || (yyvsp[-1].node)->type == MUL_ASSIGN || (yyvsp[-1].node)->type == DIV_ASSIGN || (yyvsp[-1].node)->type == ADD_ASSIGN || (yyvsp[-1].node)->type == SUB_ASSIGN){
													if((yyvsp[-2].node)->type != (yyvsp[0].node)->type){
														printf("Invalid Operand for %s\n",(yyvsp[-1].node)->lexeme);
														Totalerrors++;
														//printf("= %d %d",$1->type,$3->type);
													}
													else
														(yyval.node)->type = (yyvsp[-2].node)->type;
												}else{

													if((yyvsp[-2].node)->type!=INT || (yyvsp[0].node)->type!=INT){
														printf("Invalid Operand for %s\n",(yyvsp[-1].node)->lexeme);
														Totalerrors++;
													}
													else
														(yyval.node)->type = (yyvsp[-2].node)->type;
												} 

											}
											(yyval.node)->lval = 0;
											}
#line 3023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1132 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 3029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1134 "cparser.y" /* yacc.c:1646  */
    { (yyval.node) = MakeNode(2); (yyval.node)->type =101; strcpy((yyval.node)->lexeme,";");
							  (yyval.node)->child[0] = (yyvsp[-1].node); if((yyvsp[-1].node) != NULL) (yyvsp[-1].node)->parent = (yyval.node);
							  (yyval.node)->child[1] = (yyvsp[0].node);  if((yyvsp[0].node) != NULL) (yyvsp[0].node)->parent = (yyval.node);
							}
#line 3038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1142 "cparser.y" /* yacc.c:1646  */
    {
			if(open == 0)
				currentT = EnterScope(currentT);
			else{
				open = 0;
			}
		}
#line 3050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1152 "cparser.y" /* yacc.c:1646  */
    {
			currentT = ExitScope(currentT);
		}
#line 3058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1158 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 3064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1163 "cparser.y" /* yacc.c:1646  */
    {
								open = 1;
								my.array = 3; my.pointer = 0; my.struct_member = 0; my.type = (yyvsp[-1].node)->type;
								AddSymbol((yyvsp[0].Sval).text,my,currentT);

								currentT = EnterScope(currentT);

								(yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);
								(yyval.node)->child[0] = (yyvsp[-1].node); (yyvsp[-1].node)->parent = (yyval.node);
								(yyval.node)->array = 50;

								returntype = (yyvsp[-1].node)->type;
								returnpointer = 0;

							}
#line 3084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1179 "cparser.y" /* yacc.c:1646  */
    {
								open = 1;

								my.array = 3; my.pointer = 0; my.struct_member = 0; my.type = 5;
								strcpy(my.structID,(yyvsp[-1].Sval).text);
								AddSymbol((yyvsp[0].Sval).text,my,currentT);
								currentT = EnterScope(currentT);

								(yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);
								(yyval.node)->child[0] = MakeNode(0); (yyval.node)->child[0]->type = (yyvsp[-1].Sval).type; strcpy((yyval.node)->child[0]->lexeme,(yyvsp[-1].Sval).text);
								(yyval.node)->child[0]->parent  = (yyval.node);
								(yyval.node)->array = 51;

								returntype = 5;
								returnpointer = 0;
								strcpy(returnchar,(yyvsp[-1].Sval).text);
							}
#line 3106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1197 "cparser.y" /* yacc.c:1646  */
    {
								open = 1;

								my.array = 3; my.pointer = 1; my.struct_member = 0; my.type = (yyvsp[-2].node)->type;
								AddSymbol((yyvsp[0].Sval).text,my,currentT);
								currentT = EnterScope(currentT);

								(yyval.node) = MakeNode(2); (yyval.node)->type = (yyvsp[0].Sval).type; strcpy((yyval.node)->lexeme,(yyvsp[0].Sval).text);
								(yyval.node)->child[0] = (yyvsp[-2].node); (yyvsp[-2].node)->parent = (yyval.node);
								(yyval.node)->array = 52;

								returnpointer = 1;
								returntype = (yyvsp[-2].node)->type;
							}
#line 3125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1215 "cparser.y" /* yacc.c:1646  */
    {

									(yyval.node) = (yyvsp[-4].node);
								//	$$->child[1] = $3; $3->parent = $$;
									(yyval.node)->child[1] = (yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);

									ALL[funcount] = (struct allFunc *)malloc(sizeof(struct allFunc));
									strcpy(ALL[funcount]->name,(yyvsp[-4].node)->lexeme);
									ALL[funcount]->t = (yyval.node);
									ALL[funcount]->arg = (yyvsp[-2].node);
									ALL[funcount]->st = currentT->child[currentT->current - 1];
									funcount++;				
									//printf("I am in at %s %d\n",$1->lexeme,funcount);
								}
#line 3144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1229 "cparser.y" /* yacc.c:1646  */
    {
									(yyval.node) = (yyvsp[-3].node);
									(yyval.node)->child[1] = (yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);
									//$$->NumChild -= 1;
									(yyval.node)->array += 3;	


									ALL[funcount] = (struct allFunc *)malloc(sizeof(struct allFunc));
									strcpy(ALL[funcount]->name,(yyvsp[-3].node)->lexeme);
									ALL[funcount]->t = (yyval.node);
									ALL[funcount]->arg = NULL;
									ALL[funcount]->st = currentT->child[currentT->current - 1];		
									funcount++;						
									//printf("I am in at khali mei %s %d\n",$1->lexeme,funcount);
								}
#line 3164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1247 "cparser.y" /* yacc.c:1646  */
    {(yyval.node)=MakeNode(0); (yyval.node)->type = -1;strcpy((yyval.node)->lexeme,"dec");}
#line 3170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1248 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node); tree = (yyval.node); }
#line 3176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1249 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node); tree = (yyval.node);}
#line 3182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1251 "cparser.y" /* yacc.c:1646  */
    {(yyval.node) = MakeNode(2); (yyval.node)->type=1000; strcpy((yyval.node)->lexeme,"@");
					 (yyval.node)->child[0] = (yyvsp[-1].node); (yyvsp[-1].node)->parent = (yyval.node);
					 (yyval.node)->child[1] = (yyvsp[0].node); (yyvsp[0].node)->parent = (yyval.node);
					tree = (yyval.node);	}
#line 3191 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3195 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1258 "cparser.y" /* yacc.c:1906  */

// 错误处理函数
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
	AST_print(tree);
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

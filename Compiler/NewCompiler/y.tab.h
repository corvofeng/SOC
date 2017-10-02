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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    char *text;         /* 终结符语义值类型 */
    struct AST *node;	/* 非终结符语义值类型 */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

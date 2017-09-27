%{
#include "definition.h"
int Totalerrors, funcount;
struct allFunc **ALL;

// 终结符的定义
%token IDENT VOID INT WHILE IF ELSE RETURN EQ NE LE GE
%token AND OR DECNUM CONTINUE BREAK HEXNUM LSHIFT RSHIFT

// 定义运算符结合性
%left OR
%left AND
%left EQ NE LE GE '<' '>
%left '+' '-'
%left '|'
%left '&' '^'
%left '*' '/' '%'
%right LSHIFT RSHIFT
%right '!'
%right '~'
%nonassoc UMINUS
%nonassoc MPR

// 定义program为开始符号，所有推导从它开始
%start program

// 语义值类型定义为一个联合，包括2种可能用到的类型
%union{
        struct AST *node;	// 非终结符语义值类型

        struct terminal{	// 终结符语义值类型
            char *text;
        } Sval;

}

// 终结符语义值的类型说明
%type <Sval> IDENT VOID INT WHILE IF ELSE RETURN EQ NE LE GE
%type <Sval> AND OR DECNUM CONTINUE BREAK HEXNUM LSHIFT RSHIFT

// 非终结符语义值的类型说明
%type <node> program
%type <node> decl_list
%type <node> decl
%type <node> var_decl
%type <node> type_spec
%type <node> fun_decl
%type <node> params
%type <node> param_list
%type <node> param
%type <node> stmt_list
%type <node> stmt
%type <node> expr_stmt
%type <node> while_stmt
%type <node> block_stmt
%type <node> compound_stmt
%type <node> local_decls
%type <node> local_decl
%type <node> if_stmt
%type <node> return_stmt
%type <node> expr
%type <node> int_literal
%type <node> arg_list
%type <node> continue_stmt
%type <node> break_stmt

// 语法规则部分，产生式的语义动作是生成抽象语法树
%%
program
    : decl_list                 {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 1; $$->procno = 1;
                                }
    ;

decl_list
    : decl_list decl            {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $2; $2->parent = $$;
                                    $$->ntno = 2; $$->procno = 1;
                                    $$->multiplicity = $1->multiplicity + 1;
                                }
    | decl                      {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 2; $$->procno = 2;
                                    $$->multiplicity = 1;
                                }
    ;

decl
    : var_decl                  {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 3; $$->procno = 1;
                                }
    | fun_decl                  {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 3; $$->procno = 2;
                                }
    ;

var_decl
    : type_spec IDENT ';'       {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 4; $$->procno = 1;
                                    $$->txt = $2.text;
                                }
    | type_spec IDENT '[' int_literal ']' ';'
                                {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $4; $4->parent = $$;
                                    $$->ntno = 4; $$->procno = 2;
                                    $$->txt = $2.text;
                                }
    ;

type_spec
    : VOID                      {   $$ = makeNode(0);
                                    $$->ntno = 5; $$->procno = 1;
                                }
    | INT                       {   $$ = makeNode(0);
                                    $$->ntno = 5; $$->procno = 2;
                                }
    ;

fun_decl
    : type_spec IDENT '(' params ')' compound_stmt
                                {   $$ = makeNode(3); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $4; $4->parent = $$;
                                    $$->child[2] = $6; $6->parent = $$;
                                    $$->ntno = 6; $$->procno = 1; $$->txt = $2.text;
                                    ALL[funcount] = (struct allFunc *)malloc(sizeof(struct allFunc));
                                    strcpy(ALL[funcount]->name, $2.text);
                                    ALL[funcount]->t = $$;
                                    funcount++;
                                }
    | type_spec IDENT '(' params ')' ';'
                                {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $4; $4->parent = $$;
                                    $$->ntno = 6; $$->procno = 2; $$->txt = $2.text;
                                    ALL[funcount] = (struct allFunc *)malloc(sizeof(struct allFunc));
                                    strcpy(ALL[funcount]->name, $2.text);
                                    ALL[funcount]->t = $$;
                                    funcount++;
                                }
    ;

params
    : param_list                {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 7; $$->procno = 1;
                                }
    | VOID                      {   $$ = makeNode(0); $$->ntno = 7; $$->procno = 2; }
    ;
    
param_list
    : param_list ',' param      {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 8; $$->procno = 1;
                                    $$->multiplicity = $1->multiplicity + 1;
                                }
    | param                     {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 8; $$->procno = 2;
                                    $$->multiplicity = 1;
                                }
    ;
    
param
    : type_spec IDENT           {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 9; $$->procno = 1;
                                    $$->txt = $2.text;
                                }
    | type_spec IDENT '[' int_literal ']'
                                {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $4; $4->parent = $$;
                                    $$->ntno = 9; $$->procno = 2;
                                    $$->txt = $2.text;
                                }
    ;

stmt_list
    : stmt_list stmt            {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $2; $2->parent = $$;
                                    $$->ntno = 10; $$->procno = 1;
                                    $$->multiplicity = $1->multiplicity + 1;
                                }
    | stmt                      {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 10; $$->procno = 2;
                                    $$->multiplicity = 1;
                                }
    ;
    
stmt
    : expr_stmt                 {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 11; $$->procno = 1;
                                }
    | block_stmt                {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 11; $$->procno = 2;
                                }
    | if_stmt                   {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 11; $$->procno = 3;
                                }
    | while_stmt                {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 11; $$->procno = 4;
                                }
    | return_stmt               {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 11; $$->procno = 5;
                                }
    | continue_stmt             {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 11; $$->procno = 6;
                                }
    | break_stmt                {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 11; $$->procno = 7;
                                }
    ;
    
expr_stmt
    : IDENT '=' expr ';'        {   $$ = makeNode(1); $$->child[0] = $3; $3->parent = $$;
                                    $$->ntno = 12; $$->procno = 1;
                                    $$->txt = $1.text;
                                }
    | IDENT '[' expr ']' '=' expr ';'
                                {   $$ = makeNode(2); $$->child[0] = $3; $3->parent = $$;
                                    $$->child[1] = $6; $6->parent = $$;
                                    $$->ntno = 12; $$->procno = 2;
                                    $$->txt = $1.text;
                                }
    | '$' expr '=' expr ';'     {   $$ = makeNode(2); $$->child[0] = $2; $2->parent = $$;
                                    $$->child[1] = $4; $4->parent = $$;
                                    $$->ntno = 12; $$->procno = 3;
                                }
    ;

while_stmt
    : WHILE '(' expr ')' stmt   {   $$ = makeNode(2); $$->child[0] = $3; $3->parent = $$;
                                    $$->child[1] = $5; $5->parent = $$;
                                    $$->ntno = 13; $$->procno = 1;
                                }
    ;

block_stmt
    : '{' stmt_list '}'         {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 14; $$->procno = 1;
                                }
    ;
    
compound_stmt
    : '{' local_decls stmt_list '}'
                                {   $$ = makeNode(2); $$->child[0] = $2; $2->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 15; $$->procno = 1;
                                }
    | '{' stmt_list '}'         {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 15; $$->procno = 2;
                                }
    | '{' local_decls '}'       {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 15; $$->procno = 3;
                                }
    | '{' '}'                   {   $$ = makeNode(0);
                                    $$->ntno = 15; $$->procno = 4;
                                }
    ;

local_decls
    : local_decls local_decl    {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $2; $2->parent = $$;
                                    $$->ntno = 16; $$->procno = 1;
                                    $$->multiplicity = $1->multiplicity + 1;
                                }
    | local_decl                {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 16; $$->procno = 2;
                                    $$->multiplicity = 1;
                                }
    ;
    
local_decl
    : type_spec IDENT ';'       {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 17; $$->procno = 1;
                                    $$->txt = $2.text;
                                }
    | type_spec IDENT '[' int_literal ']' ';'
                                {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $4; $4->parent = $$;
                                    $$->ntno = 17; $$->procno = 2;
                                    $$->txt = $2.text;
                                }
    ;
    
if_stmt
    : IF '(' expr ')' stmt %prec UMINUS
                                {   $$ = makeNode(2); $$->child[0] = $3; $3->parent = $$;
                                    $$->child[1] = $5; $5->parent = $$;
                                    $$->ntno = 18; $$->procno = 1;
                                }
    | IF '(' expr ')' stmt ELSE stmt %prec MPR
                                {   $$ = makeNode(3); $$->child[0] = $3; $3->parent = $$;
                                    $$->child[1] = $5; $5->parent = $$;
                                    $$->child[2] = $7; $7->parent = $$;
                                    $$->ntno = 18; $$->procno = 2;
                                }
    ;

return_stmt
    : RETURN ';' 				{   $$ = makeNode(0);
                                    $$->ntno = 19; $$->procno = 1;
                                }
    | RETURN expr ';'           {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 19; $$->procno = 2;
                                }
    ;

expr
    : expr OR expr              {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 1;
                                    $$->contain_expr = 1;
                                }
    | expr EQ expr              {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 2;
                                    $$->contain_expr = 1;
                                }
    | expr NE expr              {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 3;
                                    $$->contain_expr = 1;
                                }
    | expr LE expr              {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 4;
                                    $$->contain_expr = 1;
                                }
    | expr '<' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 5;
                                    $$->contain_expr = 1;
                                }
    | expr GE expr              {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 6;
                                    $$->contain_expr = 1;
                                }
    | expr '>' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 7;
                                    $$->contain_expr = 1;
                                }
    | expr AND expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 8;
                                    $$->contain_expr = 1;
                                }
    | expr '+' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 9;
                                    $$->contain_expr = 1;
                                }
    | expr '-' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 10;
                                    $$->contain_expr = 1;
                                }
    | expr '*' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 11;
                                    $$->contain_expr = 1;
                                }
    | expr '/' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 12;
                                    $$->contain_expr = 1;
                                }
    | expr '%' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 13;
                                    $$->contain_expr = 1;
                                }
    | '!' expr %prec UMINUS     {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 20; $$->procno = 14;
                                    $$->contain_expr = 1;
                                }
    | '-' expr %prec UMINUS     {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 20; $$->procno = 15;
                                    $$->contain_expr = 1;
                                }
    | '+' expr %prec UMINUS     {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 20; $$->procno = 16;
                                    $$->contain_expr = 1;
                                }
    | '$' expr %prec UMINUS     {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 20; $$->procno = 17;
                                    $$->contain_expr = 1;
                                }
    | '(' expr ')'              {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 20; $$->procno = 18;
                                    $$->contain_expr = 1;
                                }
    | IDENT                     {   $$ = makeNode(0); $$->ntno = 20; $$->procno = 19;
                                    $$->txt = $1.text;
                                }
    | IDENT '[' expr ']' 		{   $$ = makeNode(1); $$->child[0] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 20;
                                    $$->contain_expr = 1; $$->txt = $1.text;
                                }
    | IDENT '(' arg_list ')'  	{   $$ = makeNode(1); $$->child[0] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 21; $$->txt = $1.text;
                                }
    | IDENT '(' ')'             {   $$ = makeNode(0); $$->ntno = 20; $$->procno = 22;
                                    $$->txt = $1.text;
                                }
    | int_literal               {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 20; $$->procno = 23;
                                }
    | expr '&' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 24;
                                    $$->contain_expr = 1;
                                }
    | expr '^' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 25;
                                    $$->contain_expr = 1;
                                }
    | '~' expr                  {   $$ = makeNode(1); $$->child[0] = $2; $2->parent = $$;
                                    $$->ntno = 20; $$->procno = 26;
                                    $$->contain_expr = 1;
                                }
    | expr LSHIFT expr          {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 27;
                                    $$->contain_expr = 1;
                                }
    | expr RSHIFT expr          {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 28;
                                    $$->contain_expr = 1;
                                }
    | expr '|' expr             {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 20; $$->procno = 29;
                                    $$->contain_expr = 1;
                                }
    ;
    
int_literal
    : DECNUM                    {   $$ = makeNode(0); $$->ntno = 21; $$->procno = 1;
                                    $$->txt = $1.text;
                                }
    | HEXNUM                    {   $$ = makeNode(0); $$->ntno = 21; $$->procno = 2;
                                    $$->txt = $1.text;
                                }
    ;

arg_list
    : arg_list ',' expr         {   $$ = makeNode(2); $$->child[0] = $1; $1->parent = $$;
                                    $$->child[1] = $3; $3->parent = $$;
                                    $$->ntno = 22; $$->procno = 1;
                                    $$->multiplicity = $1->multiplicity + 1;
                                }
    | expr                      {   $$ = makeNode(1); $$->child[0] = $1; $1->parent = $$;
                                    $$->ntno = 22; $$->procno = 2;
                                    $$->multiplicity = 1;
                                }
    ;

continue_stmt
    : CONTINUE ';'              {   $$ = makeNode(0); }
    ;

break_stmt
    : BREAK ';'                 {   $$ = makeNode(0); }
    ;
%%
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
	Totalerrors=0;
	funcount = 0;
	init();
	yyparse();
	if(Totalerrors>0)
		printf("Total symantic errors: %d\n", Totalerrors);
	else{
		printf("Generating MIPS code...\n");
		GenerateMIPS();
	}
	
	return 0;
}

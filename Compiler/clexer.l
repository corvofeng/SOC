D			[0-9]
L			[a-zA-Z_]

%{

#include "y.tab.h"
#include "definition.h"
extern YYSTYPE yylval;
int LINE=1;
%}

%%
"//"		{ comment2();}
"/*"		{ comment(); }
"break"		{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=BREAK;return(BREAK); }
"char"		{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=CHAR;return(CHAR); }
"continue"	{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=CONTINUE;return(CONTINUE);}
"else"		{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=ELSE;return(ELSE); }
"float"		{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=FLOAT;return(FLOAT); }
"for"		{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=FOR;return(FOR); }
"if"		{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=IF;return(IF); }
"int"		{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=INT;return(INT); }
"return"	{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=RETURN;return(RETURN); }
"sizeof"	{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=SIZEOF;return(SIZEOF); }	
"struct"	{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=STRUCT;return(STRUCT); }
"void"		{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=VOID;return(VOID); }
"while"		{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=WHILE;return(WHILE); }
"read"		{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=READ;return(READ); }
"print"		{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=PRINT;return(PRINT);}
"max"		{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=MAX;return(MAX);}
"min"		{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=MIN;return(MIN);}
"swap"		{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=SWAP;return(SWAP);}
{L}({L}|{D})*	{ yylval.Sval.text=strdup(yytext); yylval.Sval.type=IDENTIFIER;return(IDENTIFIER); }

{D}+		{ yylval.Sval.text=strdup(yytext); yylval.Sval.type=INT;return(CONSTANT); }
'(\\[t0n'"\\]|[^\\'])'	{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=CHAR;return(CONSTANT); }

{D}*"."{D}+	{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=FLOAT;return(CONSTANT); }

\"(\\.|[^\\"])*\"	{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=STRING_LITERAL;return(STRING_LITERAL); }

">>="			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=RIGHT_ASSIGN;return(RIGHT_ASSIGN); }
"<<="			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=LEFT_ASSIGN;return(LEFT_ASSIGN); }
"+="			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=AND_ASSIGN;return(ADD_ASSIGN); }
"-="			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=SUB_ASSIGN;return(SUB_ASSIGN); }
"*="			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=MUL_ASSIGN;return(MUL_ASSIGN); }
"/="			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=DIV_ASSIGN;return(DIV_ASSIGN); }
"%="			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=MOD_ASSIGN;return(MOD_ASSIGN); }
"&="			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=AND_ASSIGN;return(AND_ASSIGN); }
"^="			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=XOR_ASSIGN;return(XOR_ASSIGN); }
"|="			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=OR_ASSIGN;return(OR_ASSIGN); }
">>"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=RIGHT_OP;return(RIGHT_OP); }
"<<"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=LEFT_OP;return(LEFT_OP); }
"++"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=INC_OP;return(INC_OP); }
"--"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=DEC_OP;return(DEC_OP); }
"->"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=PTR_OP;return(PTR_OP); }
"&&"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=AND_OP;return(AND_OP); }
"||"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=OR_OP;return(OR_OP); }
"<="			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=LE_OP;return(LE_OP); }
">="			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=GE_OP;return(GE_OP); }
"=="			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=EQ_OP;return(EQ_OP); }
"!="			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=NE_OP;return(NE_OP); }
";"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return(';'); }
("{")			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1; return('{'); }
("}")			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return('}'); }
","			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return(','); }
"="			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return('='); }
"("			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return('('); }
")"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return(')'); }
("[")			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return('['); }
("]")			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return(']'); }
"."			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return('.'); }
"&"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return('&'); }
"!"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return('!'); }
"~"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return('~'); }
"-"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return('-'); }
"+"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return('+'); }
"*"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return('*'); }
"/"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return('/'); }
"%"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return('%'); }
"<"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return('<'); }
">"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return('>'); }
"^"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return('^'); }
"|"			{  yylval.Sval.text=strdup(yytext); yylval.Sval.type=-1;return('|'); }

[ \t\v\n\f]		{  }
.			{ /* 忽略错误 */ }

%%

yywrap()
{
	return(1);
}

// 处理/* */型的注释
comment()
{
	char c, c1;

	c=input();
	while(1){
		c1=input();
		if(c=='*' && c1=='/')	break;
		c=c1;
	}
}

// 处理//型的注释
comment2(){
	char c;
	while ((c = input()) != '\n');
}


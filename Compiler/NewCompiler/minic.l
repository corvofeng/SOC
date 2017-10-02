digit       ([0-9])|([1-9][0-9]*)
letter      [a-zA-Z]
id          {letter}({letter}|{digit})*
num         {digit}[1-9]*
hex         0(x|X)({letter}|[0-9])*

%{
#include "y.tab.h"
#include "definition.h"
extern YYSTYPE yylval;
int total_err = 0;
%}

%%
"void"          { yylval.text = strdup(yytext); return(VOID); }
"continue"      { yylval.text = strdup(yytext); return(CONTINUE); }
"if"            { yylval.text = strdup(yytext); return(IF); }
"while"         { yylval.text = strdup(yytext); return(WHILE); }
"else"          { yylval.text = strdup(yytext); return(ELSE); }
"break"         { yylval.text = strdup(yytext); return(BREAK); }
"int"           { yylval.text = strdup(yytext); return(INT); }
"return"        { yylval.text = strdup(yytext); return(RETURN); }
"||"            { yylval.text = strdup(yytext); return(OR); }
"&&"            { yylval.text = strdup(yytext); return(AND); }
{id}            { yylval.text = strdup(yytext); return(IDENT); }
{hex}           { yylval.text = strdup(yytext); return(HEXNUM); }
{num}           { yylval.text = strdup(yytext); return(DECNUM); }
"<="            { yylval.text = strdup(yytext); return(LE); }
">="            { yylval.text = strdup(yytext); return(GE); }
"=="            { yylval.text = strdup(yytext); return(EQ); }
"!="            { yylval.text = strdup(yytext); return(NE); }
">"             { yylval.text = strdup(yytext); return('>'); }
"<"             { yylval.text = strdup(yytext); return('<'); }
","             { yylval.text = strdup(yytext); return(','); }
";"             { yylval.text = strdup(yytext); return(';'); }
"{"             { yylval.text = strdup(yytext); return('{'); }
"}"             { yylval.text = strdup(yytext); return('}'); }
"+"             { yylval.text = strdup(yytext); return('+'); }
"-"             { yylval.text = strdup(yytext); return('-'); }
"*"             { yylval.text = strdup(yytext); return('*'); }
"/"             { yylval.text = strdup(yytext); return('/'); }
"%"             { yylval.text = strdup(yytext); return('%'); }
"="             { yylval.text = strdup(yytext); return('='); }
"("             { yylval.text = strdup(yytext); return('('); }
")"             { yylval.text = strdup(yytext); return(')'); }
"~"             { yylval.text = strdup(yytext); return('~'); }
"&"             { yylval.text = strdup(yytext); return('&'); }
"^"             { yylval.text = strdup(yytext); return('^'); }
"["             { yylval.text = strdup(yytext); return('['); }
"]"             { yylval.text = strdup(yytext); return(']'); }
"<<"            { yylval.text = strdup(yytext); return(LSHIFT); }
">>"            { yylval.text = strdup(yytext); return(RSHIFT); }
"|"             { yylval.text = strdup(yytext); return('|'); }
[ \t\v\f]       { }
\n              { yylineno++; }
\r              { yylineno++; }
"$"             { yylval.text = strdup(yytext); return('$'); }
"/*"            { comment1(); }
"//"            { comment2(); }
.               { lexerror(); }
%%
/* 处理多行注释 */
comment1()
{
    char c, c1;
    c = input();
    while(1){
        c1 = input();
        if (c == '*' && c1 == '/')
            break;
        else if (c == '\n')
            yylineno++;
        c = c1;
    }
}

/* 处理单行注释 */
comment2()
{
    char c;
    while ((c = input()) != '\n');
    yylineno++;
}

/* 错误处理 */
lexerror()
{
    fprintf(stderr, "line %d: lexical error: invalid '%s'\n", yylineno, yytext);
    total_err++;
}

int yywrap()
{
    if (total_err > 0)
    fprintf(stderr, "Total count of lexical error: %d\n", total_err);
    return 1;
}


digit		([0-9])|([1-9][0-9]*)
letter		[a-zA-Z]
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
"void"          { yylval.Sval.text = strdup(yytext); return(VOID); }
"continue"      { yylval.Sval.text = strdup(yytext); return(CONTINUE);}
"if"            { yylval.Sval.text = strdup(yytext); return(IF); }
"while"         { yylval.Sval.text = strdup(yytext); return(WHILE); }
"else"          { yylval.Sval.text = strdup(yytext); return(ELSE); }
"break"         { yylval.Sval.text = strdup(yytext); return(BREAK); }
"int"           { yylval.Sval.text = strdup(yytext); return(INT); }
"return"        { yylval.Sval.text = strdup(yytext); return(RETURN); }
"||"            { yylval.Sval.text = strdup(yytext); return(OR); }
"&&"            { yylval.Sval.text = strdup(yytext); return(AND); }
{id}            { yylval.Sval.text = strdup(yytext); return(IDENT); }
{hex}           { yylval.Sval.text = strdup(yytext); return(HEXNUM); }
{num}           { yylval.Sval.text = strdup(yytext); return(DECNUM); }
"<="            { yylval.Sval.text = strdup(yytext); return(LE); }
">="            { yylval.Sval.text = strdup(yytext); return(GE); }
"=="            { yylval.Sval.text = strdup(yytext); return(EQ); }
"!="            { yylval.Sval.text = strdup(yytext); return(NE); }
">"             { yylval.Sval.text = strdup(yytext); return('>'); }
"<"             { yylval.Sval.text = strdup(yytext); return('<'); }
","             { yylval.Sval.text = strdup(yytext); return(','); }
";"             { yylval.Sval.text = strdup(yytext); return(';'); }
"{"             { yylval.Sval.text = strdup(yytext); return('{'); }
"}"             { yylval.Sval.text = strdup(yytext); return('}'); }
"+"             { yylval.Sval.text = strdup(yytext); return('+'); }
"-"             { yylval.Sval.text = strdup(yytext); return('-'); }
"*"             { yylval.Sval.text = strdup(yytext); return('*'); }
"/"             { yylval.Sval.text = strdup(yytext); return('/'); }
"%"             { yylval.Sval.text = strdup(yytext); return('%'); }
"="             { yylval.Sval.text = strdup(yytext); return('='); }
"("             { yylval.Sval.text = strdup(yytext); return('('); }
")"             { yylval.Sval.text = strdup(yytext); return(')'); }
"~"             { yylval.Sval.text = strdup(yytext); return('~'); }
"&"             { yylval.Sval.text = strdup(yytext); return('&'); }
"^"             { yylval.Sval.text = strdup(yytext); return('^'); }
"["             { yylval.Sval.text = strdup(yytext); return('['); }
"]"             { yylval.Sval.text = strdup(yytext); return(']'); }
"<<"            { yylval.Sval.text = strdup(yytext); return(LSHIFT); }
">>"            { yylval.Sval.text = strdup(yytext); return(RSHIFT); }
"|"             { yylval.Sval.text = strdup(yytext); return('|'); }
[ \t\v\f]       { }
\n              { yylineno++; }
\r              { yylineno++; }
"$"             { yylval.Sval.text = strdup(yytext); return('$'); }
"/*"            { comment1(); }
"//"            { comment2(); }
.               { lexerror(); }
%%
// 处理/* */型的注释
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

// 处理//型的注释
comment2()
{
    char c;
    while ((c = input()) != '\n');
    yylineno++;
}

// 错误处理
lexerror()
{
    fprintf(stderr, "line %d: lexical error: invalid '%s'\n", yylineno, yytext);
    total_err++;
}

yywrap()
{
    if (total_err > 0)
    fprintf(stderr, "Total count of lexical error: %d\n", total_err);
    return(1);
}


digit		([0-9])|([1-9][0-9]*)
letter		[a-zA-Z]
id          {letter}({letter}|{digit})*
num         {digit}[1-9]*
hex         0(x|X)({letter}|[0-9])*

%{
//#include "y.tab.h"
//#include "definition.h"
//extern YYSTYPE yylval;
int totalError = 0;
%}

%%
"void"          { printf("void\n"); }
"continue"      { printf("continue\n");}
"if"            { printf("if\n"); }
"while"         { printf("while\n"); }
"else"          { printf("else\n"); }
"break"         { printf("break\n"); }
"int"           { printf("int\n"); }
"return"        { printf("return\n"); }
"||"            { printf("||\n"); }
"&&"            { printf("&&\n"); }
{id}            { printf("id\n"); }
{hex}           { printf("hex\n"); }
{num}           { printf("num\n"); }
"<="            { printf("<=\n"); }
">="            { printf(">=\n"); }
"=="            { printf("==\n"); }
"!="            { printf("!=\n"); }
">"             { printf(">\n"); }
"<"             { printf("<\n"); }
","             { printf(",\n"); }
";"             { printf(";\n"); }
"{"             { printf("{\n"); }
"}"             { printf("}\n"); }
"%"             { printf("%\n"); }
"*"             { printf("*\n"); }
"/"             { printf("/\n"); }
"="             { printf("=\n"); }
"("             { printf("(\n"); }
")"             { printf(")\n"); }
"~"             { printf("~\n"); }
"&"             { printf("&\n"); }
"^"             { printf("^\n"); }
"["             { printf("[\n"); }
"]"             { printf("]\n"); }
"<<"            { printf("<<\n"); }
">>"            { printf(">>\n"); }
"|"             { printf("|\n"); }
[ \t\v\f]       { }
\n              { yylineno++; }
\r              { yylineno++; }
"$"             { printf("$\n"); }
"/*"            { comment(); }
"//"            { comment2(); }
.               { lexerror(); }
%%

yywrap()
{
	if (totalError > 0)
        printf("Total count of lexical error: %d\n", totalError);
    return(1);
}

// 处理/* */型的注释
comment()
{
    char c, c1;
    c=input();
    while(1){
        c1 = input();
        if (c == '*' && c1 == '/')
            break;
        else if (c == '\n')
            yylineno++;
        c=c1;
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
    printf("Lexical error: invalid '%s' at line %d\n", yytext, yylineno);
    totalError++;
}


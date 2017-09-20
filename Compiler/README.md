
···
 
sample.lex
sample.lex是.lex文件的一个样例

···

lex.yy.c
lex.yy.c是Lex用sample.lex生成的文件，生成文件的命令如下：
$ flex sample.lex

...

sample.y
sample.y是.y文件的一个样例

...

y.tab.c
y.tab.c是Yacc用sample.y生成的文件，生成文件的命令如下：
$ byacc sample.y

...
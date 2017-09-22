## 对各个文件的说明

```bash
.
├── minic.l        	# minic.l : 根据“Mini C的有关规定.pdf”中的词法规则写成的Lex源程序。   
├── test.l        	# test.l : 为了单独测试Lex部分，根据minic.l修改的Lex源程序。
├── test.c      	# test.c : 用于测试的C程序，其中有两个test.l中未定义的符号。
├── Makefile
├── README.md
```

```bash
# 用法

$ flex test.l 
# 生成lex.yy.c。

$ cc lex.yy.c -ll
# 使用cc命令进行编译，如果不是在Mac上，是用参数-lfl。

$ ./a.out < test.c
# 运行文件
```

```bash
# 测试结果
void
id
(
int
id
[
num
]
,
int
id
,
int
id
)
{
id
[
id
]
=
id
Lexical error: invalid '.' at line 4
id
;
id
=
Lexical error: invalid '!' at line 8
id
;
id
=
hex
;
}
Total count of lexical error: 2
```
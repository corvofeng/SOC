## 对各个文件的说明

```bash
.
├── minic.l        	# minic.l : 根据“Mini C的有关规定.pdf”中的词法规则写成的Lex源程序。
├── minic.y         # minic.y : 根据“Mini C的有关规定.pdf”中的语法规则写成的Yacc源程序。
├── lex.yy.c        # lex.yy.c : minic.l输入flex生成的文件。
├── y.tab.c        	# y.tab.c : minic.y输入bison生成的文件。
├── y.tab.h        	# y.tab.h : minic.y输入bison生成的文件。
├── definition.h    # definition.h : 一些结构体的定义。
├── definition.c    # definition.c : definition.h中定义的函数的实现。
├── CtoMIPS.c    	# CtoMIPS.c : 生成MIPS代码的程序，根据抽象语法树完成代码生成所需的各种工作。
├── test.c      	# test.c : 用于测试的C程序，是编译器的输入。
├── mips_code.s     # mips_code.s : 生成的MIPS代码，是编译器的输出。
├── Makefile
├── README.md
```

```bash
# 用法

$ flex minic.l 
# 生成lex.yy.c。

$ byacc -d -v minic.y
# 生成y.tab.c，y.tab.h和y.output

$ gcc -c -g y.tab.c lex.yy.c definition.c CtoMIPS.c
# 编译，生成.o文件

$ gcc -o start y.tab.o lex.yy.o definition.o CtoMIPS.o
# 生成可执行文件start

$ ./start < test.c
# 以test.c为输入运行start
```


```bash
# Mini-Compiler

# 一个将C subset转换成MIPS汇编语言的编译器。

# 需要Lex, Yacc和SPIM emulator(测试MIPS代码)。
```

```bash
# 用法

$make 
# 生成一个名为start的可执行程序。

$./start < example.c 
# 为example.c生成MIPS代码，生成的代码在mips_code.s中。
```

```bash
# 对各个文件的说明

# cGrammer : 本项目使用的语法。

# clexer.l : Lex源程序，定义了合法的token。

# cparser.y : Yacc源程序。会进行出错处理，生成抽象语法树以及输出最终的MIPS代码。

# CtoMIPS.c : 接受抽象语法树作为输入，生成MIPS代码并输出到mips_code.s中。

# symbolTable.c : 定义了创建符号表需要的函数。

# definition.c : 生成抽象语法树需要的函数。

# definition.h : 定义了抽象语法树和符号表相关的结构体。 

# test.c : 测试程序。
```
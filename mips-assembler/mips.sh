#!/bin/bash

# 在需要编译的asm文件中加入BIOS程序以及中断处理程序

cat BIOS.asm        \
    ../Compiler/NewCompiler/mips_code.s \
    INT.asm         \
    ../Compiler/NewCompiler/mips_data.s \
    > test.asm

./mips-assembler
cat ./inttbl.coe ./data.coe > fin_data.coe
cat ./text.coe ./int.coe > fin_text.coe

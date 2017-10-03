#!/bin/bash



#cat /home/corvo/Learning/verilog/SOC/Compiler/NewCompiler/mips_code.s \
#    /home/corvo/Learning/verilog/SOC/Compiler/NewCompiler/mips_data.s \
#    > test.asm

./mips-assembler
cat ./inttbl.coe ./data.coe > fin_data.coe
cat ./text.coe ./int.coe > fin_text.coe

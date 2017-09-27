.text
fun: 
bgez t0,int1
j int0
jal int1
int0:
addi t0,t0,7
int1:
jal int0
int2:
mult t0,t1
.data
buf1: .word 3


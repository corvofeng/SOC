addi t0 t0 0x234
addi t1 t1 459
sll t0 t0 16
mult t0 t1
mfhi t3
addi t3 t3 5
mthi t3 
mflo t4
addi t4 t4 10
mflo t4
div t0 t1
mfhi t5
addi t5 t5 15
mthi t5 
mflo t6
addi t6 t6 20
mflo t6
eret 

addiu $t0, $t0, 0x7fff
sll $t0, $t0, 16
addiu $t0, $t0, 0xffff
addiu $t1, $t1, 0x0020
add $t0, $t0, $t1
j main
nop



addiu $t0, $t0, 0x7fff
sll $t0, $t0, 16
addiu $t0, $t0, 0xffff
addiu $t1, $t1, 0x0020
add $t0, $t0, $t1
j main
nop


.text
keyread:
	addi $sp, $sp, -32
	sw $s7, 28($sp)
	sw $s6, 24($sp)
	sw $s5, 20($sp)
	sw $s4, 16($sp)
	sw $s3, 12($sp)
	sw $s2, 8($sp)
	sw $s1, 4($sp)
	sw $s0, 0($sp)
	addi $t0, $zero, 10
	sw $t0, key($zero)
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	lw $s4, 16($sp)
	lw $s5, 20($sp)
	lw $s6, 24($sp)
	lw $s7, 28($sp)
	addi $sp, $sp, 32
	jr $ra
print:
	addi $sp, $sp, -32
	sw $s7, 28($sp)
	sw $s6, 24($sp)
	sw $s5, 20($sp)
	sw $s4, 16($sp)
	sw $s3, 12($sp)
	sw $s2, 8($sp)
	sw $s1, 4($sp)
	sw $s0, 0($sp)
	add $t0, $a0, $zero
	add $t1, $t0, $zero
	addi $t0, $zero, 0x0000ff00
	sw $t1, 0($t0)
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	lw $s4, 16($sp)
	lw $s5, 20($sp)
	lw $s6, 24($sp)
	lw $s7, 28($sp)
	addi $sp, $sp, 32
	jr $ra
fib:
	addi $sp, $sp, -32
	sw $s7, 28($sp)
	sw $s6, 24($sp)
	sw $s5, 20($sp)
	sw $s4, 16($sp)
	sw $s3, 12($sp)
	sw $s2, 8($sp)
	sw $s1, 4($sp)
	sw $s0, 0($sp)
	addi $t0, $zero, 2
	add $t1, $t0, $zero
	add $t0, $a0, $zero
	slt $t0, $t0, $t1
	beq $t0, $zero, L1
	add $t0, $a0, $zero
	add $v0, $t0, $zero
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	lw $s4, 16($sp)
	lw $s5, 20($sp)
	lw $s6, 24($sp)
	lw $s7, 28($sp)
	addi $sp, $sp, 32
	jr $ra
L1:
	addi $t0, $zero, 0
	add $s0, $t0, $zero
	addi $t0, $zero, 1
	add $s1, $t0, $zero
	addi $t0, $zero, 0
	add $s2, $t0, $zero
	addi $t0, $zero, 2
	add $s3, $t0, $zero
L2:
	add $t0, $a0, $zero
	add $t2, $t0, $zero
	add $t0, $s3, $zero
	add $t1, $t0, $zero
	addi $t0, $zero, 1
	beq $t1, $t2, L4
	slt $t0, $t1, $t2
L4:
	beq $t0, $zero, L3
	add $t0, $s1, $zero
	add $t1, $t0, $zero
	add $t0, $s0, $zero
	add $t0, $t0, $t1
	add $s2, $t0, $zero
	add $t0, $s1, $zero
	add $s0, $t0, $zero
	add $t0, $s2, $zero
	add $s1, $t0, $zero
	addi $t0, $zero, 1
	add $t1, $t0, $zero
	add $t0, $s3, $zero
	add $t0, $t0, $t1
	add $s3, $t0, $zero
	j L2
L3:
	add $t0, $s2, $zero
	add $v0, $t0, $zero
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	lw $s4, 16($sp)
	lw $s5, 20($sp)
	lw $s6, 24($sp)
	lw $s7, 28($sp)
	addi $sp, $sp, 32
	jr $ra
main:
	addi $t0, $zero, 5
	add $s0, $t0, $zero
L5:
	addi $t0, $zero, 1
	beq $t0, $zero, L6
	addi $t0, $zero, 0
	add $t1, $t0, $zero
	lw $t0, key($zero)
	slt $t0, $t1, $t0
	beq $t0, $zero, L7
	addi $sp, $sp, -24
	sw $ra, 20($sp)
	sw $t9, 16($sp)
	sw $a3, 12($sp)
	sw $a2, 8($sp)
	sw $a1, 4($sp)
	sw $a0, 0($sp)
	lw $t0, key($zero)
	add $a0, $t0, $zero
	jal fib
	lw $a0, 0($sp)
	lw $a1, 4($sp)
	lw $a2, 8($sp)
	lw $a3, 12($sp)
	lw $t9, 16($sp)
	lw $ra, 20($sp)
	addi $sp, $sp, 24
	add $t0, $v0, $zero
	add $s1, $t0, $zero
L7:
	addi $sp, $sp, -24
	sw $ra, 20($sp)
	sw $t9, 16($sp)
	sw $a3, 12($sp)
	sw $a2, 8($sp)
	sw $a1, 4($sp)
	sw $a0, 0($sp)
	add $t0, $s1, $zero
	add $a0, $t0, $zero
	jal print
	lw $a0, 0($sp)
	lw $a1, 4($sp)
	lw $a2, 8($sp)
	lw $a3, 12($sp)
	lw $t9, 16($sp)
	lw $ra, 20($sp)
	addi $sp, $sp, 24
	j L5
L6:
	jr $ra

EXC_BASE:
	mfc0    $k0, $cause         #读CP0 cause寄存器
	andi    $k1, $k0, 0xC000    #读取ExcCode
	srl     $k1, $k1, 14        #将ExcCode移到$k1最后两位
	andi    $k0, $k0, 0x00FF    #将vector存到$k0后八位
	add     $t0, $zero, $zero   #index变量
LOOP:
# t1 = { ExcCode1, ExcCode0,6'h0 ,vector(8'b),funciton_location(16'b)};
	lw      $t1, 0($t0)         #从存储器中取值
	beq     $t1, $t0, ERET      #如果全0,说明没找到，跳到返回
	srl     $t2, $t1, 16        #将$t1逻辑右移16位
	srl     $t3, $t2, 14        #将$t2逻辑右移14位，将ExcCode放置在$t3的最低两位
	andi    $t2, $t2, 0x00FF    #取$t2后八位vector

	bne     $k1, $t3, LOOP      #判断ExcCode是否相等，不相等则返回继续查找
	bne     $k1, $zero,  JUMP      #判断ExcCode是否为00，不相等则跳转到函数出口
	bne     $k0, $t2, LOOP      #判断vector是否相等，不相等则返回继续查找

JUMP:
	andi    $t4, $t1, 0x00FF    #获取中断向量
	jr      $t4
ERET:
eret

.data
	key: .word 0

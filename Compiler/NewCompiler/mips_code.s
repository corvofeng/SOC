.data
.text
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
	addi $sp, $sp, -24
	sw $ra, 20($sp)
	sw $t9, 16($sp)
	sw $a3, 12($sp)
	sw $a2, 8($sp)
	sw $a1, 4($sp)
	sw $a0, 0($sp)
	add $t0, $s0, $zero
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
	jr $ra

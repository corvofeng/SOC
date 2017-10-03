.text
main:
	addi $t0, $zero, 1
	add $t1, $t0, $zero
	la $t0, a
	sw $t1, 4($t0)
	addi $t0, $zero, 1
	add $t2, $t0, $zero
	la $t0, a
	lw $t0, 4($t0)
	add $t1, $t0, $zero
	addi $t0, $zero, 0
	beq $t1, $t2, L3
	j L4
L3:
	addi $t0, $zero, 1
L4:
	beq $t0, $zero, L1
	addi $t0, $zero, 2
	add $t1, $t0, $zero
	la $t0, a
	sw $t1, 4($t0)
	j L2
L1:
	addi $t0, $zero, 3
	add $t1, $t0, $zero
	la $t0, a
	sw $t1, 4($t0)
L2:
	jr $ra

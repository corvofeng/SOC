.data
global: .word 0
.text
fun:
	 li $t0, 8
	 sub $sp, $sp, $t0
	 move $t2, $sp
	 li $t3,4
	 sub $t2,$t2,$t3
	 # LOADING ..
	 add $t9,$sp,0
	 lw $t4, 0($t9)
	 sw $t4,0($t2)

	 li $t1, 0
	 li $t3,4
	 sub $t2,$t2,$t3
	 sw $t1,0($t2)

	 # ADDING ..
	 lw $t1,0($t2)
	 lw $t0,4($t2)
	 li $t3,4
	 add $t2,$t2,$t3
	# ==
	 seq $t1,$t0,$t1
	 sw $t1,0($t2)

	 lw $t0,0($t2)
	 add $t2,$t2,4
	 beq $0, $t0,fun0
#Scope Increased 2
	 li $t0, 0
	 sub $sp, $sp, $t0
	 move $t2, $sp
	 li $t1, 1
	 li $t3,4
	 sub $t2,$t2,$t3
	 sw $t1,0($t2)

	lw $v0,0($t2)
	 add $sp, $sp, 8
	 move $t2, $sp
	 jr $ra
#Scope decreased 2
	 li $t0, 0
	 add $sp, $sp, $t0
	 move $t2, $sp
fun0:
	 li $t3,4
	 sub $t2,$t2,$t3
	 # LOADING ..
	 add $t9,$sp,0
	 lw $t4, 0($t9)
	 sw $t4,0($t2)

	 li $t3,4
	 sub $t2,$t2,$t3
	 # LOADING ..
	 add $t9,$sp,0
	 lw $t4, 0($t9)
	 sw $t4,0($t2)

	 li $t1, 1
	 li $t3,4
	 sub $t2,$t2,$t3
	 sw $t1,0($t2)

	 # ADDING ..
	 lw $t1,0($t2)
	 lw $t0,4($t2)
	 li $t3,4
	 add $t2,$t2,$t3
	# -
	 sub $t1,$t0,$t1
	 sw $t1,0($t2)

	move $t0,$sp
	li $t1, 24
	sub $t0,$t0,$t1
	lw $t4,0($t2)
	sw $t4,0($t0)
	li $t0,4
	sub $sp,$sp,$t0
	sw $ra,0($sp)
	move $t2,$sp
	li $t0,12
	sub $sp,$sp,$t0
	jal fun

	add $sp,$sp,12
	lw $ra,0($sp)
	add $sp,$sp,4
	move $t2,$sp
	li $t0,4
	sub $t2,$t2,$t0
	sw $v0,0($t2)
	 # ADDING ..
	 lw $t1,0($t2)
	 lw $t0,4($t2)
	 li $t3,4
	 add $t2,$t2,$t3
	# *
	 mul $t1,$t0,$t1
	 sw $t1,0($t2)

	lw $v0,0($t2)
	 add $sp, $sp, 8
	 move $t2, $sp
	 jr $ra
	 li $t0, 8
	 add $sp, $sp, $t0
	 move $t2, $sp
	 jr $ra
main:
	 li $t0, 16
	 sub $sp, $sp, $t0
	 move $t2, $sp
	 li $v0,5
	 syscall
	 # STORING ..
	 add $t9,$sp,4
	 sw $v0, 0($t9)
	 li $t3,4
	 sub $t2,$t2,$t3
	 # LOADING ..
	 add $t9,$sp,4
	 lw $t4, 0($t9)
	 sw $t4,0($t2)

	move $t0,$sp
	li $t1, 24
	sub $t0,$t0,$t1
	lw $t4,0($t2)
	sw $t4,0($t0)
	li $t0,4
	sub $sp,$sp,$t0
	sw $ra,0($sp)
	move $t2,$sp
	li $t0,12
	sub $sp,$sp,$t0
	jal fun

	add $sp,$sp,12
	lw $ra,0($sp)
	add $sp,$sp,4
	move $t2,$sp
	li $t0,4
	sub $t2,$t2,$t0
	sw $v0,0($t2)
	 lw $t1,0($t2)
	 # STORING ..
	 add $t9,$sp,12
	 sw $t1, 0($t9)
	 add $t2,$t2,4
	 # LOADING ..
	 add $t9,$sp,12
	 lw $a0, 0($t9)
	 li $v0,1
	 syscall
	 li $a0,32
	 li $v0,11
	 syscall
	 li $t0, 16
	 add $sp, $sp, $t0
	 move $t2, $sp
	 jr $ra

.data
.text
main:
	addi $sp, $sp, -40
	add $t0, $sp, $zero
	add $s0, $t0, $zero
	addi $t0, $zero, 1
	add $t1, $t0, $zero
	add, $t0, $s0, $zero
	sw, $t1, 36($t0)
	addi $sp, $sp, 40
	jr $ra

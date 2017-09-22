.text
fun:
	 sub $t2,$t2,$t3
	 sw $t1,0($t2)
	 sub t0,t1,t2
	 addi t0,t1,t2
	 
.data
global: .word 0
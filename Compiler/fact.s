.data

.text
fact:
    addi $sp, $sp, -8
    sw $ra, 4($sp)
    sw $a0, 0($sp)
    slti $t0, $a0, 1
    beq $t0, $zero, L1
    addi $v0, $zero, 1
    addi $sp, $sp, 8
    jr $ra
L1:
    addi $a0, $a0, -1
    jal fact
    lw $a0, 0(sp)
    lw $ra, 4(sp)
    addi $sp, $sp, 8
    mult $a0, $v0
    mflo $v0
    jr $ra

main:
    addi $a0, $zero, 5
    jal fact
    addi $t0, $v0, 0
    jr $ra



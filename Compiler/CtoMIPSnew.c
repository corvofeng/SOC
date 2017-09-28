#include "definition.h"
#include "y.tab.h"

int labelno;

void deal_with_node(FILE *fp, struct AST *t, int funcno);
int getLabel();

void GenerateMIPS() {
    FILE *fp;
    fp = fopen("mips_code.s", "w");
    fprrintf(fp, ".data\n");
    //fprrintf(fp, "global: .word %d\n", sym->tableSize);
    fprintf(fp, ".text\n");
    labelno = 1;
    for (int i = 0; i < funcount; i++) {
        ALL[i]->st = makeST();
        deal_with_node(fp, ALL[i]->t, i);
    }
    fclose(fp);
}

void deal_with_node(FILE *fp, struct AST *t, int funcno) {
    if (t->ntno == 1) { // program
        printf("Error! A function should never include program!\n");
    } else if (t->ntno == 2) { // decl_list
        printf("Error! A function should never include decl_list!\n")
    } else if (t->ntno == 3) { // decl
        printf("Error! A function should never include decl!\n");
    } else if (t->ntno == 4) { // var_decl
        printf("Error! A function should never include var_decl!\n")
    } else if (t->ntno == 5) { // type_spec
        // 函数类型填入ALL，VOID为0，INT为1
        if (t->parent->ntno == 6) {
            if (t->procno == 1)
                ALL[funcno]->type = 0;
            else if (t->procno == 2)
                ALL[funcno]->type = 1;
        }
    } else if (t->ntno == 6) { // fun_decl
        if (t->procno == 1) {
            fprintf(fp, "%s:\n", t->txt);
            // 保存寄存器
            fprintf(fp, "\taddi $sp, $sp, -32\n");
            fprintf(fp, "\tsw $s7, 28($sp)\n"); // 保存寄存器s7
            fprintf(fp, "\tsw $s6, 24($sp)\n"); // 保存寄存器s6
            fprintf(fp, "\tsw $s5, 20($sp)\n"); // 保存寄存器s5
            fprintf(fp, "\tsw $s4, 16($sp)\n"); // 保存寄存器s4
            fprintf(fp, "\tsw $s3, 12($sp)\n"); // 保存寄存器s3
            fprintf(fp, "\tsw $s2, 8($sp)\n");  // 保存寄存器s2
            fprintf(fp, "\tsw $s1, 4($sp)\n");  // 保存寄存器s1
            fprintf(fp, "\tsw $s0, 0($sp)\n");  // 保存寄存器s0
            
            deal_with_node(fp, t->child[0], funcno); // type_spec部分，记录返回类型
            deal_with_node(fp, t->child[1], funcno); // param部分，参数填表
            deal_with_node(fp, t->child[2], funcno); // compound_stmt部分
            
            if (ALL[funcno]->type == 0) {
                // 恢复寄存器
                fprintf(fp, "\tlw $s0, 0($sp)\n");  // 恢复寄存器s0
                fprintf(fp, "\tlw $s1, 4($sp)\n");  // 恢复寄存器s1
                fprintf(fp, "\tlw $s2, 8($sp)\n");  // 恢复寄存器s2
                fprintf(fp, "\tlw $s3, 12($sp)\n"); // 恢复寄存器s3
                fprintf(fp, "\tlw $s4, 16($sp)\n"); // 恢复寄存器s4
                fprintf(fp, "\tlw $s5, 20($sp)\n"); // 恢复寄存器s5
                fprintf(fp, "\tlw $s6, 24($sp)\n"); // 恢复寄存器s6
                fprintf(fp, "\tlw $s7, 28($sp)\n"); // 恢复寄存器s7
                fprintf(fp, "\taddi $sp, $sp, 32\n");
                fprintf(fp, "\tjr $ra\n");
            }
        } else if (t->procno == 2) {
            printf("Error! A function should never include fun_decl!\n")
        }
    } else if (t->ntno == 7) { // params
        
    } else if (t->ntno == 8) { // param_list
        
    } else if (t->ntno == 9) { // param
        
    } else if (t->ntno == 10) { // stmt_list
        if (t->multiplicity > 1) {
            deal_with_node(fp, t->child[0], funcno);
            deal_with_node(fp, t->child[1], funcno);
        } else if (t->multiplicity == 1) {
            deal_with_node(fp, t->child[0], funcno);
        }
    } else if (t->ntno == 11) { // stmt
        deal_with_node(fp, t->child[0], funcno);
    } else if (t->ntno == 12) { // expr_stmt
        deal_with_node(fp, t->child[0], funcno);
        
    } else if (t->ntno == 13) { // while_stmt
        
    } else if (t->ntno == 14) { // block_stmt
        deal_with_node(fp, t->child[0], funcno);
    } else if (t->ntno == 15) { // compound_stmt
        
    } else if (t->ntno == 16) { // local_decls
        if (t->multiplicity > 1) {
            deal_with_node(fp, t->child[0], funcno);
            deal_with_node(fp, t->child[1], funcno);
        } else if (t->multiplicity == 1) {
            deal_with_node(fp, t->child[0], funcno);
        }
    } else if (t->ntno == 17) { // local_decl
        
    } else if (t->ntno == 18) { // if_stmt
        if (procno == 1) {
            int label1 = getLabel();
            deal_with_node(fp, t->child[0], funcno);
            fprintf(fp, "\tbeq $t0, $zero, L%d\n", label1);
            deal_with_node(fp, t->child[1], funcno);
            fprintf(fp, "L%d:\n", label1);
        } else if (procno == 2) {
            int label1 = getLabel();
            int label2 = getLabel();
            deal_with_node(fp, t->child[0], funcno);
            fprintf(fp, "\tbeq $t0, $zero, L%d\n", label1);
            deal_with_node(fp, t->child[1], funcno);
            fprintf(fp, "\tj L%d\n", label2);
            fprintf(fp, "L%d:\n", label1);
            deal_with_node(fp, t->child[2], funcno);
            fprintf(fp, "L%d:\n", label2);
        }
    } else if (t->ntno == 19) { // return_stmt
        if (procno == 1) {
            if (ALL[funcno]->type == 0) {
                // 恢复寄存器
                fprintf(fp, "\tlw $s0, 0($sp)\n");  // 恢复寄存器s0
                fprintf(fp, "\tlw $s1, 4($sp)\n");  // 恢复寄存器s1
                fprintf(fp, "\tlw $s2, 8($sp)\n");  // 恢复寄存器s2
                fprintf(fp, "\tlw $s3, 12($sp)\n"); // 恢复寄存器s3
                fprintf(fp, "\tlw $s4, 16($sp)\n"); // 恢复寄存器s4
                fprintf(fp, "\tlw $s5, 20($sp)\n"); // 恢复寄存器s5
                fprintf(fp, "\tlw $s6, 24($sp)\n"); // 恢复寄存器s6
                fprintf(fp, "\tlw $s7, 28($sp)\n"); // 恢复寄存器s7
                fprintf(fp, "\taddi $sp, $sp, 32\n");
                fprintf(fp, "\tjr $ra\n");
            } else {
                printf("Error! Return type mismatch!\n");
            }
        } else if (procno == 2) {
            if (ALL[funcno]->type == 1) {
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\taddi $v0, $t0, 0\n");
                // 恢复寄存器
                fprintf(fp, "\tlw $s0, 0($sp)\n");  // 恢复寄存器s0
                fprintf(fp, "\tlw $s1, 4($sp)\n");  // 恢复寄存器s1
                fprintf(fp, "\tlw $s2, 8($sp)\n");  // 恢复寄存器s2
                fprintf(fp, "\tlw $s3, 12($sp)\n"); // 恢复寄存器s3
                fprintf(fp, "\tlw $s4, 16($sp)\n"); // 恢复寄存器s4
                fprintf(fp, "\tlw $s5, 20($sp)\n"); // 恢复寄存器s5
                fprintf(fp, "\tlw $s6, 24($sp)\n"); // 恢复寄存器s6
                fprintf(fp, "\tlw $s7, 28($sp)\n"); // 恢复寄存器s7
                fprintf(fp, "\taddi $sp, $sp, 32\n");
                fprintf(fp, "\tjr $ra\n");
            } else {
                printf("Error! Return type mismatch!\n");
            }
        }
    } else if (t->ntno == 20) { // expr
        if (t->contain_expr) { // 如果t的产生式还含有expr
            if (t->procno == 1) { // ||
                
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t2, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                int label1 = getLabel();
                int label2 = getLabel();
                fprintf(fp, "\taddi $t0, $zero, 0\n");
                fprintf(fp, "\tbgtz $t1, L%d\n", label1);
                fprintf(fp, "\tbltz $t1, L%d\n", label1);
                fprintf(fp, "\tbgtz $t2, L%d\n", label1);
                fprintf(fp, "\tbltz $t2, L%d\n", label1);
                fprintf(fp, "\tj L%d\n", label2);
                fprintf(fp, "L%d:\n\taddi $t0, $zero, 1\n", label1);
                fprintf(fp, "L%d:\n", label2);
            
            } else if (t->procno == 2) { // ==
                
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t2, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                int label1 = getLabel();
                int label2 = getLabel();
                fprintf(fp, "\taddi $t0, $zero, 0\n");
                fprintf(fp, "\tbeq $t1, $t2, L%d\n", label1);
                fprintf(fp, "\tj L%d\n", label2);
                fprintf(fp, "L%d:\n\taddi $t0, $zero, 1\n", label1);
                fprintf(fp, "L%d:\n", label2);
            
            } else if (t->procno == 3) { // !=
                
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t2, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                int label1 = getLabel();
                int label2 = getLabel();
                fprintf(fp, "\taddi $t0, $zero, 0\n");
                fprintf(fp, "\tbne $t1, $t2, L%d\n", label1);
                fprintf(fp, "\tj L%d\n", label2);
                fprintf(fp, "L%d:\n\taddi $t0, $zero, 1\n", label1);
                fprintf(fp, "L%d:\n", label2);
            
            } else if (t->procno == 4) { // <=
                
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t2, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                int label1 = getLabel();
                fprintf(fp, "\taddi $t0, $zero, 1\n");
                fprintf(fp, "\tbeq $t1, $t2, L%d\n", label1);
                fprintf(fp, "\tslt $t0, $t1, $t2\n");
                fprintf(fp, "L%d:\n", label1);

            } else if (t->procno == 5) { // <
                
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tslt $t0, $t0, $t1\n");
            
            } else if (t->procno == 6) { // >=
                
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t2, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                int label1 = getLabel();
                fprintf(fp, "\taddi $t0, $zero, 1\n");
                fprintf(fp, "\tbeq $t1, $t2, L%d\n", label1);
                fprintf(fp, "\tslt $t0, $t2, $t1\n");
                fprintf(fp, "L%d:\n", label1);
            
            } else if (t->procno == 7) { // >
                
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tslt $t0, $t1, $t0\n");
            
            } else if (t->procno == 8){ // &&
                
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t2, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                int label1 = getLabel();
                int label2 = getLabel();
                fprintf(fp, "\taddi $t0, $zero, 1\n");
                fprintf(fp, "\tbeq $t1, $zero, L%d\n", label1);
                fprintf(fp, "\tbeq $t2, $zero, L%d\n", label1);
                fprintf(fp, "\tj L%d\n", label2);
                fprintf(fp, "L%d:\n\taddi $t0, $zero, 0\n", label1);
                fprintf(fp, "L%d:\n", label2);
            
            } else if (t->procno == 9) { // +
                
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tadd $t0, $t0, $t1\n");
            
            } else if (t->procno == 10) { // -
                
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tsub $t0, $t0, $t1\n");
            
            } else if (t->procno == 11) { // *
                
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tmult $t0, $t1\n");
                fprintf(fp, "\tmflo $t0\n");
            
            } else if (t->procno == 12) { // /
                
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tdiv $t0, $t1\n");
                fprintf(fp, "\tmflo $t0\n");
            
            } else if (t->procno == 13) { // %
                
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tdiv $t0, $t1\n");
                fprintf(fp, "\tmfhi $t0\n");
            
            } else if (t->procno == 14) { // !
            
                deal_with_node(fp, t->child[0], funcno);
                int label1 = getLabel();
                int label2 = getLabel();
                fprintf(fp, "\tbeq $t0, $zero, L%d\n", label1);
                fprintf(fp, "\taddi $t0, $zero, 0\n");
                fprintf(fp, "\tj L%d\n", label2);
                fprintf(fp, "L%d:\n\taddi $t0, $zero, 1\n", label1);
                fprintf(fp, "L%d:\n", label2);
            
            } else if (t->procno == 15) { // -(unary)
            
                deal_with_node(fp, t->child[0], funcno);
                
                
            } else if (t->procno == 16) { // +(unary)
            
                deal_with_node(fp, t->child[0], funcno);
            
            } else if (t->procno == 17) { // $
                
            } else if (t->procno == 18) { // ()
            
                deal_with_node(fp, t->child[0], funcno);
            
            } else if (t->procno == 20) { // IDENT[expr]
                
            } else if (t->procno == 24) { // &
            
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tand $t0, $t0, $t1\n");
            
            } else if (t->procno == 25) { // ^
            
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\txor $t0, $t0, $t1\n");
            
            } else if (t->procno == 26) { // ~
            
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tlui $t1, 0ffffh\n");
                fprintf(fp, "\tori $t1, 0ffffh\n");
                fprintf(fp, "\tnor $t0, $t0, $t1\n");
            
            } else if (t->procno == 27) { // <<
            
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tsllv $t0, $t0, $t1\n");
            
            } else if (t->procno == 28) { // >>
            
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tsrlv $t0, $t0, $t1\n");
            
            } else if (t->procno == 29) { // |
            
                deal_with_node(fp, t->child[1], funcno);
                fprintf(fp, "\tadd $t1, $t0, $zero\n");
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tor $t0, $t0, $t1\n");
            
            }
        } else {
            if (t->procno == 19) { // IDENT
                
            } else if (t->procno == 21) { // 函数调用，有参数
                // 保存寄存器
                fprintf(fp, "\taddi $sp, $sp, -24\n");
                fprintf(fp, "\tsw $ra, 20($sp)\n"); // 保存返回地址
                fprintf(fp, "\tsw $t7, 16($sp)\n"); // 保存参数部分指针地址
                fprintf(fp, "\tsw $a3, 12($sp)\n"); // 保存寄存器a3
                fprintf(fp, "\tsw $a2, 8($sp)\n");  // 保存寄存器a2
                fprintf(fp, "\tsw $a1, 4($sp)\n");  // 保存寄存器a1
                fprintf(fp, "\tsw $a0, 0($sp)\n");  // 保存寄存器a0
                
                int local_space = t->child[0]->multiplicity - 8; // 8个寄存器是否足够
                if (local_space > 0) {
                    local_space = local_space * 4;
                    fprintf(fp, "\taddi $sp, $sp, -%d\n", local_space); // 不够则分配栈空间
                    fprintf(fp, "\tadd $t7, $sp, $zero\n"); // 参数部分指针给t7
                }
                
                // 在处理arg_list的过程中完成参数赋值
                deal_with_node(fp, t->child[0], funcno);
                
                // 函数调用
                fprintf(fp, "\tjal %s\n", t->txt);
                
                // 参数部分退栈
                if (local_space > 0)
                    fprintf(fp, "\taddi $sp, $sp, %d\n", local_space);
                
                // 恢复寄存器
                fprintf(fp, "\tlw $a0, 0($sp)\n");  // 恢复寄存器a0
                fprintf(fp, "\tlw $a1, 4($sp)\n");  // 恢复寄存器a1
                fprintf(fp, "\tlw $a2, 8($sp)\n");  // 恢复寄存器a2
                fprintf(fp, "\tlw $a3, 12($sp)\n"); // 恢复寄存器a3
                fprintf(fp, "\tlw $t7, 16($sp)\n"); // 恢复参数部分指针地址
                fprintf(fp, "\tlw $ra, 20($sp)\n"); // 恢复返回地址
                fprintf(fp, "\taddi $sp, $sp, 24\n");
                
                fprintf(fp, "\taddi $t0, $v0, 0\n");
            } else if (t->procno == 22) { // 函数调用，无参数
                // 保存寄存器
                fprintf(fp, "\taddi $sp, $sp, -8\n");
                fprintf(fp, "\tsw $ra, 4($sp)\n"); // 保存返回地址
                fprintf(fp, "\tsw $t7, 0($sp)\n"); // 保存参数部分指针地址
                
                // 函数调用
                fprintf(fp, "\tjal %s\n", t->txt);
                
                // 恢复寄存器
                fprintf(fp, "\tlw $t7, 0($sp)\n"); // 恢复参数部分指针地址
                fprintf(fp, "\tlw $ra, 4($sp)\n"); // 恢复返回地址
                fprintf(fp, "\taddi $sp, $sp, 8\n");
                
                fprintf(fp, "\taddi $t0, $v0, 0\n");
            } else if (t->procno == 23) { // int_literal
                
            }
        }
    } else if (t->ntno == 21) { // int_literal
        
    } else if (t->ntno == 22) { // arg_list
        if (t->multiplicity > 1) {
            deal_with_node(fp, t->child[0], funcno);
            deal_with_node(fp, t->child[1], funcno);
            int select_space = t->child[0]->multiplicity;
            if (select_space < 4) // 如果是前四个参数
                fprintf(fp, "add $a%d, $t0, $zero\n", select_space);
            else
                fprintf(fp, "sw $t0, %d($sp)\n", (select_space - 4) * 8);
        } else if (t->multiplicity == 1) {
            deal_with_node(fp, t->child[0], funcno);
            fprintf(fp, "\tadd $a0, $t0, $zero\n"); // 第一个参数
        }
    } else if (t->ntno == 23) { // continue_stmt
        
    } else if (t->ntno == 24) { // break_stmt
        
    }
}

int getLabel() {
    return labelno++;
}




#include "definition.h"
#include "y.tab.h"

void deal_with_node(FILE *fp, struct AST *t, int funcno);

void GenerateMIPS() {
    FILE *fp;
    fp = fopen("mips_code.s", "w");
    fprrintf(fp, ".data\n");
    //fprrintf(fp, "global: .word %d\n", sym->tableSize);
    fprintf(fp, ".text\n");
    for (int i = 0; i < funcount; i++) {
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
        // 与类型检查有关
    } else if (t->ntno == 6) { // fun_decl
        if (t->procno == 1) {
            fprintf(fp, "%s:\n", t->name);
            // 保护寄存器
            fprintf(fp, "\taddi $sp, $sp, -32\n");
            fprintf(fp, "\tsw $s7, 28($sp)\n"); // 保存寄存器s7
            fprintf(fp, "\tsw $s6, 24($sp)\n"); // 保存寄存器s6
            fprintf(fp, "\tsw $s5, 20($sp)\n"); // 保存寄存器s5
            fprintf(fp, "\tsw $s4, 16($sp)\n"); // 保存寄存器s4
            fprintf(fp, "\tsw $s3, 12($sp)\n"); // 保存寄存器s3
            fprintf(fp, "\tsw $s2, 8($sp)\n");  // 保存寄存器s2
            fprintf(fp, "\tsw $s1, 4($sp)\n");  // 保存寄存器s1
            fprintf(fp, "\tsw $s0, 0($sp)\n");  // 保存寄存器s0
            
            deal_with_node(fp, t->child[0], funcno); // type_spec检查
            deal_with_node(fp, t->child[1], funcno); // param部分，参数填表
            deal_with_node(fp, t->child[2], funcno); // compound_stmt部分
            
            // 保护寄存器
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
        } else if (t->procno == 2) {
            printf("Error! A function should never include fun_decl!\n")
        }
    } else if (t->ntno == 7) { // params
        
    } else if (t->ntno == 8) { // param_list
        
    } else if (t->ntno == 9) { // param
        
    } else if (t->ntno == 10) { // stmt_list
        
    } else if (t->ntno == 11) { // stmt
        
    } else if (t->ntno == 12) { // expr_stmt
        
    } else if (t->ntno == 13) { // while_stmt
        
    } else if (t->ntno == 14) { // block_stmt
        
    } else if (t->ntno == 15) { // compound_stmt
        
    } else if (t->ntno == 16) { // local_decls
        
    } else if (t->ntno == 17) { // local_decl
        
    } else if (t->ntno == 18) { // if_stmt
        
    } else if (t->ntno == 19) { // return_stmt
        
    } else if (t->ntno == 20) { // expr
        if (t->contain_expr) { // 如果t的产生式还含有expr
            
        } else {
            if (t->procno == 19) {
                
            } else if (t->procno == 21) { // 函数调用，有参数
                // 保护寄存器
                fprintf(fp, "\taddi $sp, $sp, -24\n");
                fprintf(fp, "\tsw $ra, 20($sp)\n"); // 保存返回地址
                fprintf(fp, "\tsw $t2, 16($sp)\n"); // 保存参数部分指针地址
                fprintf(fp, "\tsw $a3, 12($sp)\n"); // 保存寄存器a3
                fprintf(fp, "\tsw $a2, 8($sp)\n");  // 保存寄存器a2
                fprintf(fp, "\tsw $a1, 4($sp)\n");  // 保存寄存器a1
                fprintf(fp, "\tsw $a0, 0($sp)\n");  // 保存寄存器a0
                
                int local_space = t->child[0]->multiplicity - 8; // 8个寄存器是否足够
                if (local_space > 0) {
                    local_space = local_space * 4;
                    fprintf(fp, "\taddi $sp, $sp, -%d\n", local_space); // 不够则分配栈空间
                    fprintf(fp, "\tadd $t2, $sp, $zero\n"); // 参数部分指针给t2
                }
                
                // 在处理arg_list的过程中完成参数赋值
                deal_with_node(fp, t->child[0], funcno);
                
                // 函数调用
                fprintf(fp, "\tjal %s\n", t->name);
                
                // 参数部分退栈
                if (local_space > 0)
                    fprintf(fp, "\taddi $sp, $sp, %d\n", local_space);
                
                // 恢复寄存器
                fprintf(fp, "\tlw $a0, 0($sp)\n");  // 恢复寄存器a0
                fprintf(fp, "\tlw $a1, 4($sp)\n");  // 恢复寄存器a1
                fprintf(fp, "\tlw $a2, 8($sp)\n");  // 恢复寄存器a2
                fprintf(fp, "\tlw $a3, 12($sp)\n"); // 恢复寄存器a3
                fprintf(fp, "\tlw $t2, 16($sp)\n"); // 恢复参数部分指针地址
                fprintf(fp, "\tlw $ra, 20($sp)\n"); // 恢复返回地址
                fprintf(fp, "\taddi $sp, $sp, 24\n");
            } else if (t->procno == 22) { // 函数调用，无参数
                
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

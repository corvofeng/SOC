#include "definition.h"
#include "y.tab.h"

int labelno;
int tno; // 临时存储数组指针的寄存器的编号
struct stack *while1;
struct stack *while2;

void deal_with_node(FILE *fp, struct AST *t, int funcno);
void alloc_array(FILE *fp, struct AST *t, int funcno);
void alloc_all(FILE *fp, struct AST *t, int funcno);
int getLabel();

void GenerateMIPS() {
    labelno = 1;
    tno = 0;
    while1 = init_stack();
    while2 = init_stack();
    for (int i = 0; i < funcount; i++) {
        if (ALL[i]->t->child[1]->procno == 1)
            ALL[i]->param_count = ALL[i]->t->child[1]->child[0]->multiplicity;
        else
            ALL[i]->param_count = 0;
    }
    FILE *fp;
    fp = fopen("mips_code.s", "w");
    fprintf(fp, ".data\n");
    for (int i = 0; i < gcount; i++) {
        if (gVar[i]->space == 1)
            fprintf(fp, "\t%s: .word 0\n", gVar[i]->name);
        else
            fprintf(fp, "\t%s: .word 0:%d\n", gVar[i]->name, gVar[i]->space);
    }
    fprintf(fp, ".text\n");
    for (int i = 0; i < funcount; i++) {
        ALL[i]->st = makeST();
        ALL[i]->local_space = 0;
        deal_with_node(fp, ALL[i]->t, i);
    }
    fclose(fp);
}

void deal_with_node(FILE *fp, struct AST *t, int funcno) {
    if (t->ntno == 1) { // program
        
        printf("Error! A function should never include program!\n");
    
    } else if (t->ntno == 2) { // decl_list
        
        printf("Error! A function should never include decl_list!\n");
    
    } else if (t->ntno == 3) { // decl
        
        printf("Error! A function should never include decl!\n");
    
    } else if (t->ntno == 4) { // var_decl
    
        printf("Error! A function should never include var_decl!\n");
    
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
            if (strcmp(ALL[funcno]->name, "main") != 0) {
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
            }
            
            deal_with_node(fp, t->child[0], funcno); // type_spec部分，记录返回类型
            deal_with_node(fp, t->child[1], funcno); // params部分，参数填表
            deal_with_node(fp, t->child[2], funcno); // compound_stmt部分
            
            // 局部变量出栈
            int ls = ALL[funcno]->local_space;
            if (ls > 0) {
                fprintf(fp, "\taddi $sp, $sp, %d\n", ls * 4);
            }
            
            if (ALL[funcno]->type == 0) {
                if (strcmp(ALL[funcno]->name, "main") != 0) {
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
                }
                fprintf(fp, "\tjr $ra\n");
            }
        } else if (t->procno == 2) {
            printf("Error! A function should never include fun_decl!\n");
        }
        
    } else if (t->ntno == 7) { // params
        
        if (t->procno == 1)
            deal_with_node(fp, t->child[0], funcno);
        
    } else if (t->ntno == 8) { // param_list
        
        if (t->multiplicity > 1) {
            deal_with_node(fp, t->child[0], funcno);
            int select_space = t->child[0]->multiplicity;
            if (select_space < 4) // 如果是前四个参数
                st_add(t->child[1]->txt, 1, select_space, funcno);
            else
                st_add(t->child[1]->txt, 2, select_space - 4, funcno);
        } else if (t->multiplicity == 1) {
            st_add(t->child[0]->txt, 1, 0, funcno); // 第一个参数
        }
        
    } else if (t->ntno == 9) { // param
        
        // do nothing
        
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
        
        if (t->procno == 1) { // IDENT = expr;
            deal_with_node(fp, t->child[0], funcno);
            struct messenger *m = lookup(t->txt, funcno);
            if (m->type == 1) {
                fprintf(fp, "\tadd %s, $t0, $zero\n", m->pos);
            } else if (m->type == 2) {
                fprintf(fp, "\tsw $t0, %s\n", m->pos);
            } else {
                if (lookup_global(t->txt) == 1)
                    fprintf(fp, "\tsw $t0, %s\n", t->txt);
                else
                    printf("Error! Undeclared variable '%s'\n", t->txt);
            }
        } else if (t->procno == 2) { // IDENT[DECNUM] = expr;
            deal_with_node(fp, t->child[0], funcno);
            fprintf(fp, "\tadd $t1 $t0, $zero\n");
            struct messenger *m = lookup(t->txt, funcno);
            if (m->type == 1) {
                fprintf(fp, "\tadd $t0, %s, $zero\n", m->pos); // 数组指针进t0
            } else if (m->type == 2) {
                fprintf(fp, "\tlw $t0, %s\n", m->pos); // 数组指针进t0
            } else {
                if (lookup_global(t->txt) == 1)
                    fprintf(fp, "\tla $t0, %s\n", t->txt);
                else
                    printf("Error! Undeclared variable '%s'\n", t->txt);
            }
            int o = atoi(t->numtxt);
            fprintf(fp, "\tsw $t1, %d($t0)\n", 4 * o);
        } else if (t->procno == 3) { // $expr = expr;
            deal_with_node(fp, t->child[1], funcno);
            fprintf(fp, "\tadd $t1, $t0, $zero\n");
            deal_with_node(fp, t->child[0], funcno);
            fprintf(fp, "\tsw $t1, ($t0)\n");
        }
        
    } else if (t->ntno == 13) { // while_stmt
        
        int label1 = getLabel();
        int label2 = getLabel();
        push(while1, label1);
        push(while2, label2);
        fprintf(fp, "L%d:\n", label1);
        deal_with_node(fp, t->child[0], funcno);
        fprintf(fp, "\tbeq $t0, $zero, L%d\n", label2);
        deal_with_node(fp, t->child[1], funcno);
        fprintf(fp, "\tj L%d\n", label1);
        fprintf(fp, "L%d:\n", label2);
        pop(while1);
        pop(while2);
    
    } else if (t->ntno == 14) { // block_stmt
        
        deal_with_node(fp, t->child[0], funcno);
        
    } else if (t->ntno == 15) { // compound_stmt
        
        if (t->procno == 1) {
            deal_with_node(fp, t->child[0], funcno);
            deal_with_node(fp, t->child[1], funcno);
        } else if (t->procno == 2 || t->procno == 3)
            deal_with_node(fp, t->child[0], funcno);
        
    } else if (t->ntno == 16) { // local_decls
        
        alloc_array(fp, t, funcno);
        tno = 0;
        int space = t->multiplicity - 8; // 8个寄存器是否足够
        if (space > 0) {
            fprintf(fp, "\taddi $sp, $sp, -%d\n", space * 4); // 不够则分配栈空间
            ALL[funcno]->local_space += space;
        }
        alloc_all(fp, t, funcno);
        tno = 0;
        
    } else if (t->ntno == 17) { // local_decl
        
        // do nothing
        
    } else if (t->ntno == 18) { // if_stmt
        
        if (t->procno == 1) {
            int label1 = getLabel();
            deal_with_node(fp, t->child[0], funcno);
            fprintf(fp, "\tbeq $t0, $zero, L%d\n", label1);
            deal_with_node(fp, t->child[1], funcno);
            fprintf(fp, "L%d:\n", label1);
        } else if (t->procno == 2) {
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
        
        if (t->procno == 1) {
            if (ALL[funcno]->type == 1) {
                printf("Error! Return type mismatch for function '%s'\n", ALL[funcno]->name);
            }
        } else if (t->procno == 2) {
            if (ALL[funcno]->type == 1) {
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tadd $v0, $t0, $zero\n");
            } else {
                printf("Error! Return type mismatch for function '%s'\n", ALL[funcno]->name);
            }
        }
        if (strcmp(ALL[funcno]->name, "main") != 0) {
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
        }
        fprintf(fp, "\tjr $ra\n");
        
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
                fprintf(fp, "\taddi $t1, $zero, -1\n");
                fprintf(fp, "\tmult $t0, $t1\n");
                fprintf(fp, "\tmflo $t0\n");
                
            } else if (t->procno == 16) { // +(unary)
            
                deal_with_node(fp, t->child[0], funcno);
            
            } else if (t->procno == 17) { // $
                
                deal_with_node(fp, t->child[0], funcno);
                fprintf(fp, "\tlw $t0, ($t0)\n");
                
            } else if (t->procno == 18) { // ()
            
                deal_with_node(fp, t->child[0], funcno);
            
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
                fprintf(fp, "\tnor $t0, $t0, $zero\n");
            
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
                
                struct messenger *m = lookup(t->txt, funcno);
                if (m->type == 1)
                    fprintf(fp, "\tadd $t0, %s, $zero\n", m->pos);
                else if (m->type == 2)
                    fprintf(fp, "\tlw $t0, %s\n", m->pos);
                else {
                    if (lookup_global(t->txt) == 1)
                        fprintf(fp, "\tlw $t0, %s\n", t->txt);
                    else
                        printf("Error! Undeclared variable '%s'\n", t->txt);
                }
            
            } else if (t->procno == 20) { // IDENT[DECNUM]
                
                struct messenger *m = lookup(t->txt, funcno);
                if (m->type == 1) {
                    fprintf(fp, "\tadd $t0, %s, $zero\n", m->pos); // 数组指针进t0
                } else if (m->type == 2) {
                    fprintf(fp, "\tlw $t0, %s\n", m->pos); // 数组指针进t0
                } else {
                    if (lookup_global(t->txt) == 1)
                        fprintf(fp, "\tla $t0, %s\n", t->txt);
                    else
                        printf("Error! Undclared variable '%s'\n", t->txt);
                }
                int o = atoi(t->numtxt);
                fprintf(fp, "\tlw $t0, %d($t0)\n", 4 * o);
            
            } else if (t->procno == 21) { // 函数调用，有参数
                
                int name_found = 0;
                int pcount_matched = 0;
                for (int i = 0; i < funcount; i++) {
                    if (strcmp(ALL[i]->name, t->txt) == 0) {
                        name_found = 1;
                        if (ALL[i]->param_count == t->child[0]->multiplicity)
                            pcount_matched = 1;
                    }
                }
                
                if (pcount_matched == 1) {
                    
                    // 保存寄存器
                    fprintf(fp, "\taddi $sp, $sp, -24\n");
                    fprintf(fp, "\tsw $ra, 20($sp)\n"); // 保存返回地址
                    fprintf(fp, "\tsw $t7, 16($sp)\n"); // 保存参数部分指针地址
                    fprintf(fp, "\tsw $a3, 12($sp)\n"); // 保存寄存器a3
                    fprintf(fp, "\tsw $a2, 8($sp)\n");  // 保存寄存器a2
                    fprintf(fp, "\tsw $a1, 4($sp)\n");  // 保存寄存器a1
                    fprintf(fp, "\tsw $a0, 0($sp)\n");  // 保存寄存器a0
                    
                    
                    int arg_space = t->child[0]->multiplicity - 4; // 4个寄存器是否足够
                    if (arg_space > 0) {
                        arg_space *= 4;
                        fprintf(fp, "\taddi $sp, $sp, -%d\n", arg_space); // 不够则分配栈空间
                        fprintf(fp, "\tadd $t7, $sp, $zero\n"); // 参数部分指针给t7
                    }
                    
                    // 在处理arg_list的过程中完成参数赋值
                    deal_with_node(fp, t->child[0], funcno);
                    
                    // 函数调用
                    fprintf(fp, "\tjal %s\n", t->txt);
                    
                    // 参数部分退栈
                    if (arg_space > 0)
                        fprintf(fp, "\taddi $sp, $sp, %d\n", arg_space);
                    
                    // 恢复寄存器
                    fprintf(fp, "\tlw $a0, 0($sp)\n");  // 恢复寄存器a0
                    fprintf(fp, "\tlw $a1, 4($sp)\n");  // 恢复寄存器a1
                    fprintf(fp, "\tlw $a2, 8($sp)\n");  // 恢复寄存器a2
                    fprintf(fp, "\tlw $a3, 12($sp)\n"); // 恢复寄存器a3
                    fprintf(fp, "\tlw $t7, 16($sp)\n"); // 恢复参数部分指针地址
                    fprintf(fp, "\tlw $ra, 20($sp)\n"); // 恢复返回地址
                    fprintf(fp, "\taddi $sp, $sp, 24\n");
                    
                    fprintf(fp, "\tadd $t0, $v0, $zero\n");
                    
                } else if (name_found == 1)
                    printf("Error! Parameter count mismatch for function '%s\n'", t->txt);
                else
                    printf("Error! Undeclared function '%s'\n", t->txt);
                
            } else if (t->procno == 22) { // 函数调用，无参数
                
                int name_found = 0;
                int pcount_matched = 0;
                for (int i = 0; i < funcount; i++) {
                    if (strcmp(ALL[i]->name, t->txt) == 0) {
                        name_found = 1;
                        if (ALL[i]->param_count == 0)
                            pcount_matched = 1;
                    }
                }

                if (pcount_matched == 1) {
                    
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
                    
                    fprintf(fp, "\tadd $t0, $v0, $zero\n");
                    
                } else if (name_found == 1)
                    printf("Error! Parameter count mismatch for function '%s\n'", t->txt);
                else
                    printf("Error! Undeclared function '%s'\n", t->txt);
                
            } else if (t->procno == 23) { // int_literal
                
                fprintf(fp, "\taddi $t0, $zero, %s\n", t->child[0]->numtxt);
            
            }
        }
        
    } else if (t->ntno == 21) { // int_literal
        
        // do nothing
        
    } else if (t->ntno == 22) { // arg_list
        
        if (t->multiplicity > 1) {
            deal_with_node(fp, t->child[0], funcno);
            deal_with_node(fp, t->child[1], funcno);
            int select_space = t->child[0]->multiplicity;
            if (select_space < 4) // 如果是前四个参数
                fprintf(fp, "\tadd $a%d, $t0, $zero\n", select_space);
            else
                fprintf(fp, "\tsw $t0, %d($sp)\n", (select_space - 4) * 4);
        } else if (t->multiplicity == 1) {
            deal_with_node(fp, t->child[0], funcno);
            fprintf(fp, "\tadd $a0, $t0, $zero\n"); // 第一个参数
        }
        
    } else if (t->ntno == 23) { // continue_stmt
        
        if (empty(while1) == 0) {
            int no = top(while1);
            fprintf(fp, "\tj L%d\n", no);
        }
        
    } else if (t->ntno == 24) { // break_stmt
        
        if (empty(while2) == 0) {
            int no = top(while2);
            fprintf(fp, "\tj L%d\n", no);
        }
        
    }
}

void alloc_array(FILE *fp, struct AST *t, int funcno) {
    
    if (t->multiplicity > 1) {
        alloc_array(fp, t->child[0], funcno);
        if (t->child[1]->procno == 2) { // 如果是数组
            int n = atoi(t->child[1]->numtxt);
            ALL[funcno]->local_space += n;
            n *= 4;
            fprintf(fp, "\taddi $sp, $sp, -%d\n", n);
            fprintf(fp, "\tadd $t%d, $sp, $zero\n", tno++); // 数组指针给t寄存器
        }
    } else if (t->multiplicity == 1) {
        if (t->child[0]->procno == 2) { // 如果是数组
            int n = atoi(t->child[0]->numtxt);
            ALL[funcno]->local_space += n;
            n *= 4;
            fprintf(fp, "\taddi $sp, $sp, -%d\n", n);
            fprintf(fp, "\tadd $t%d, $sp, $zero\n", tno++); // 数组指针给t寄存器
        }
    }
    
}

void alloc_all(FILE *fp, struct AST *t, int funcno) {
    
    if (t->multiplicity > 1) {
        alloc_all(fp, t->child[0], funcno);
        int select_space = t->child[0]->multiplicity;
        if (select_space < 8) { // 如果是前八个变量
            st_add(t->child[1]->txt, 3, select_space, funcno);
            if (t->child[1]->procno == 2)
                fprintf(fp, "\tadd $s%d, $t%d, $zero\n", select_space, tno++);
        }
        else {
            st_add(t->child[1]->txt, 4, select_space - 8, funcno);
            if (t->child[1]->procno == 2)
                fprintf(fp, "\tsw $t%d, %d($sp)\n", tno++, (select_space - 8) * 4);
        }
        
    } else if (t->multiplicity == 1) {
        st_add(t->child[0]->txt, 3, 0, funcno); // 第一个变量
        if (t->child[0]->procno == 2)
            fprintf(fp, "\tadd $s0, $t%d, $zero\n", tno++);
    }
    
}

int getLabel() {
    return labelno++;
}


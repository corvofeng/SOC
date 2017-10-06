#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <unistd.h>
#include "file_parser.h"
#include "tokenizer.h"
#include <errno.h>
/*
 * The structs below map a character to an integer.
 * They are used in order to map a specific instruciton/register to its binary format in ASCII
 */

// Struct that stores registers and their respective binary reference
static int isFirst = 1;
static int isFirst2 = 1;
static int isFirst3 = 1;

#define INT_START  400  // 中断处理程序从400行开始
#define DATA_START 100  // 数据段从第101行开始
#define INT_NAME   "EXC_BASE"   // 中断函数名称

struct {
    const char *name;
    char *address;
} registerMap[] = {
    { "zero", "00000" }, //常量0
    { "at", "00001" },	//保留给汇编器
    { "v0", "00010" },  //$v0-$v1函数调用返回值
    { "v1", "00011" },
    { "a0", "00100" },	//$a0-$a3函数调用参数
    { "a1", "00101" },
    { "a2", "00110" },
    { "a3", "00111" },
    { "t0", "01000" },	//$t0-$t9暂时寄存器
    { "t1", "01001" },
    { "t2", "01010" },
    { "t3", "01011" },
    { "t4", "01100" },
    { "t5", "01101" },
    { "t6", "01110" },
    { "t7", "01111" },
    { "s0", "10000" },	//$s0-$s7子程序寄存器
    { "s1", "10001" },
    { "s2", "10010" },
    { "s3", "10011" },
    { "s4", "10100" },
    { "s5", "10101" },
    { "s6", "10110" },
    { "s7", "10111" },
    { "t8", "11000" },
    { "t9", "11001" },
    { "k0", "11010" },  //$k0-$k1中断/异常处理保留
    { "k1", "11011" },
    { "gp", "11100" },	//全局指针
    { "sp", "11101" },	//堆栈指针
    { "fp", "11110" },	//帧指针
    { "ra", "11111" },	//返回地址
    { "status","01100"},
    { "cause", "01101"},
    { "epc", "01110"},
    { NULL, 0 }
};

// Struct for R-Type instructions mapping for the 'function' field in the instruction
struct {
    const char *name;
    char *function;
} rMap[] = {
    { "add", "100000" },
    { "sub", "100010" },
    { "and", "100100" },
    { "or",  "100101" },
    { "sll", "000000" },
    { "slt", "101010" },
    { "srl", "000010" },
    { "jr",  "001000" },
    { "xor", "100110" },
    { "addu", "100001" },
    { "subu", "100011" },
    { "nor",  "100111" },
    { "sra",  "000011"},
    { "sltu", "101011"},
    { "sllv", "000100"},
    { "srlv", "000110"},
    { "srav", "000111"},
    { "mult", "011000"},
    { "multu", "011001"},
    { "div",  "011010"},
    { "divu", "011011"},
    { "mfhi", "010000"},
    { "mflo", "010010"},
    { "mthi", "010001"},
    { "mtlo", "010011"},
    { "jalr", "001001"},
    { "break", "001101"},
    { "syscall", "001100"},
    { "eret", "011000"},
    { "mfc0", "000000"},
    { "mtc0", "000000"},

    { NULL, 0 }
};

// Struct for I-Type instructions
struct {
    const char *name;
    char *address;
} iMap[] = {
    { "lw",   "100011" },
    { "sw",   "101011" },
    { "andi", "001100" },
    { "ori",  "001101" },
    { "lui",  "001111" },
    { "beq",  "000100" },
    { "slti", "001010" },
    { "addi", "001000" },
    { "xori", "001110" },
    { "lb",   "100000" },
    { "lbu",  "100100" },
    { "lh",   "100001" },
    { "lhu",  "100101" },
    { "sb",   "101000" },
    { "sh",   "101001" },
    { "bne",   "000101" },
    { "sltiu", "001011" },
    { "bgez",  "000001" },
    { "bgtz",  "000111" },
    { "blez",  "000110" },
    { "bltz",  "000001" },
    { "bgezal", "000001" },
    { "bltzal", "000001" },
    { "addiu", "001001" },


    { NULL, 0 }
};

// Struct for J-Type instructions
struct {
    const char *name;
    char *address;
} jMap[] = {
    { "j", "000010" },
    { "jal", "000011" },
    { NULL, 0 }
};

struct {
    const char* src;
    const char dst;
} cvt_tbl[] = {
    { "0000", '0'},
    { "0001", '1'},
    { "0010", '2'},
    { "0011", '3'},
    { "0100", '4'},
    { "0101", '5'},
    { "0110", '6'},
    { "0111", '7'},
    { "1000", '8'},
    { "1001", '9'},
    { "1010", 'A'},
    { "1011", 'B'},
    { "1100", 'C'},
    { "1101", 'D'},
    { "1110", 'E'},
    { "1111", 'F'},

    {NULL, '0'}
};


void debug_print(const char *cmd, ...)
{
#ifdef __DEBUG__
    va_list args;       //定义一个va_list类型的变量，用来储存单个参数
    va_start(args,cmd); //使args指向可变参数的第一个参数
    vprintf(cmd,args);  //必须用vprintf等带V的
    va_end(args);       //结束可变参数的获取
#endif
}
// 去除字符串末尾的换行符
void trim_string(char *str)
{
    int len = strlen(str);
    //去掉最后的换行符
    if(str[len-1] == '\n')
        str[len - 1] = ';';   //给字符串最后一个字符赋0，即结束符
}

char intchar[20][40] = {0};
int printProgCnt = 0;       // 记录当前打印的代码段的行数
int printIntCnt = 0;        // 记录已经打印的中断处理程序的个数
int iline,j = 0;            // j, what?? 这啥意思
int intCnt = 0;             // 记录中断处理程序的个数

void parse_file(FILE *fptr, FILE *intptr, int pass, char *instructions[],
                size_t inst_len, hash_table_t *hash_table,
                FILE *outProg, FILE *outProgInt,        // 代码段, 中断处理程序
                FILE *outInt, FILE *outData             // 中断向量表, 用户数据段
               )
{
    char line[MAX_LINE_LENGTH + 1];
    char *tok_ptr, *ret, *token, *int_ptr, *intoken = NULL;
    char intLine[MAX_LINE_LENGTH + 1];
    int32_t line_num = 0;
    int32_t instruction_count = -4;        // 代码段偏移记录
    int32_t instruction_int_count = INT_START;     // 中断向量表中的偏移记录
    int32_t data_count = DATA_START;        // 数据段偏移
    int data_reached = 0;
    int prog_int_reach = 0;                     // 是否到达中断处理程序
    int curProgPos = 0;                             // 记录每个指令当前的地址, 方便进行beq, ben等的偏移运算
    int curIntPos  = INT_START;                     // 记录当前的中断程序地址

    int intnum = 0;

    // TODO: 关键代码注释啊, 为什么要读一遍, 这个时候要读读取扫描文件, 文档中要完善
    while(1 && pass == 1) {
        if(fgets(intLine, MAX_LINE_LENGTH, intptr) == NULL)
            break;
        intLine[MAX_LINE_LENGTH] = 0;

        iline ++;
        int_ptr = intLine;

        while (1) {
            intoken = parse_token(int_ptr, " \n\t$,", &int_ptr, NULL);

            if (intoken == NULL || *intoken == '#') {

                if(intoken != NULL)
                    free(intoken);
                break;
            }
            //printf("inttoken: %s\n", intoken);

            strcpy(intchar[j], intoken);
            j++;
            intCnt ++;
        }
    }

    if(pass  == 1) {
        debug_print("*************************\n");
        debug_print("In pass 1.\n");
        debug_print("*************************\n");
    } else {
        debug_print("*************************\n");
        debug_print("In pass 2.\n");
        debug_print("*************************\n");
    }

    while (1) {
        if ((ret = fgets(line, MAX_LINE_LENGTH, fptr)) == NULL)
            break;

        line_num++;
        line[MAX_LINE_LENGTH] = 0;

        tok_ptr = line;
        if (strlen(line) == MAX_LINE_LENGTH) {
            fprintf(outProg,
                    "line %d: line is too long. ignoring line ...\n", line_num);
            continue;
        }

        /* parse the tokens within a line */
        //while (1) {

        token = parse_token(tok_ptr, " \n\t$,", &tok_ptr, NULL);

        /* blank line or comment begins here. go to the next line */
        if (token == NULL || *token == '#') {
            if(token != NULL)
                free(token);
            continue;
        }

        trim_string(line);      // 去除行末空格
        debug_print("-----------------------\n");
        debug_print("In line %d:  %s %s\n", line_num, token, tok_ptr);

        int x = token_search(token);
        if (x >= 0) {
            if( prog_int_reach == 0)        // 尚未到达中断向量段
                instruction_count += 4;
            else
                instruction_int_count += 4;
        }

        // If token is ".data", reset instruction to .data starting address
        else if (strcmp(token, ".data") == 0) {
            data_reached = 1;
            free(token);
            continue;
        }  else if (strstr(token, INT_NAME)) {  // 检查是否到达中断处理程序
            prog_int_reach = 1;
            free(token);
            continue;
        }

        debug_print("Pc in: %d\n", instruction_count);

        // If first pass, then add labels to hash table
        if (pass == 1) {

            // if token has ':', then it is a label so add it to hash table
            if (strstr(token, ":") && data_reached == 0) {
                debug_print("label: %s\n", token);
                size_t token_len = strlen(token);
                token[token_len - 1] = '\0';

                // Insert variable to hash table
                uint32_t *inst_count;
                inst_count = (uint32_t *)malloc(sizeof(uint32_t));

                if(prog_int_reach == 1) {           // 中断入口函数采用不同的统计方式
                    *inst_count = instruction_int_count;
                } else {
                    *inst_count = instruction_count;
                }

                int32_t insert = hash_insert(hash_table, token, strlen(token)+1, inst_count);
            }

            // If .data has been reached, increment instruction count accordingly
            // and store to hash table
            // 数据段存放
            else if (data_reached == 1) {

                char *var_tok = NULL;
                char *var_tok_ptr = tok_ptr;

                // If variable is .word
                if (strstr(tok_ptr, ".word")) {

                    debug_print(".word\n");

                    // Variable is array
                    if (strstr(var_tok_ptr, ":")) {

                        debug_print("array\n");

                        // Store the number in var_tok and the occurance in var_tok_ptr
                        var_tok = parse_token(var_tok_ptr, ":", &var_tok_ptr, NULL);

                        // Convert char* to int
                        int freq = atoi(var_tok_ptr);

                        int num;
                        sscanf(var_tok, "%*s %d", &num);

                        // Strip out ':' from token
                        size_t token_len = strlen(token);
                        token[token_len - 1] = '\0';

                        // Insert variable to hash table
                        uint32_t *d_count;
                        d_count = (uint32_t *)malloc(sizeof(uint32_t));
                        *d_count = data_count;
                        int32_t insert = hash_insert(hash_table, token, strlen(token)+1, d_count);

                        // Increment instruction count by freq
                        data_count = data_count + (freq * 4);

                        debug_print("End array\n");
                    }

                    // Variable is a single variable
                    else {
                        // Strip out ':' from token
                        size_t token_len = strlen(token);
                        token[token_len - 1] = '\0';

                        // Insert variable to hash table
                        uint32_t *d_count;
                        d_count = (uint32_t *)malloc(sizeof(uint32_t));
                        *d_count = data_count;
                        int32_t insert = hash_insert(hash_table, token, strlen(token)+1, d_count);
                        //printf("The token is %s, The instCnt is %d\n", token, instruction_count);

                        data_count = data_count + 4;

                        /*
                        if (insert == 0) {
                            fprintf(outProg, "Error in hash table insertion\n");
                            exit(1);
                        }
                        */

                        debug_print("End singe var\n",insert);
                    }
                }

                // Variable is a string
                else if (strstr(tok_ptr, ".asciiz")) {

                    // Store the ascii in var_tok
                    var_tok_ptr += 8;
                    var_tok = parse_token(var_tok_ptr, "\"", &var_tok_ptr, NULL);

                    // Increment instruction count by string length
                    size_t str_byte_len = strlen(var_tok);

                    // Strip out ':' from token
                    size_t token_len = strlen(token);
                    token[token_len - 1] = '\0';

                    // Insert variable to hash table
                    uint32_t *d_count;
                    d_count = (uint32_t *)malloc(sizeof(uint32_t));
                    *d_count = data_count;
                    int32_t insert = hash_insert(hash_table, token, strlen(token)+1, d_count);
                    data_count = data_count + str_byte_len;
                }
            }
        }

        // If second pass, then interpret
        else if (pass == 2) {

            // start interpreting here
            // if j loop --> then instruction is: 000010 then immediate is insturction count in 26 bits??
            // If in .text section
            if (data_reached == 0) {

                // Check instruction type
                int instruction_supported = token_search(token);
                char inst_type;

                //  printf("This should not appear %d\n", instruction_count);
                if (instruction_supported != -1) {

                    FILE* tmpFile = outProg;
                    if(prog_int_reach == 1)     // 当我们到达中断程序段时, 修改文件输出
                        outProg = outProgInt;
                    else
                        printProgCnt += 1;

                    // token contains the instruction
                    // tok_ptr points to the rest of the line

                    // Determine instruction type
                    inst_type = instruction_type(token);

                    char ** reg_store = NULL;
                    reg_store = (char **)malloc(3 * sizeof(char*));

                    if (reg_store == NULL) {
                        fprintf(outProg, "outProg of memory\n");
                        exit(1);
                    }

                    // 申请足够的空间存储指令中可能的字符
                    for (int i = 0; i < 3; i++) {
                        reg_store[i] = malloc(20 * sizeof(char));
                        memset(reg_store[i], 0, 20);
                        if (reg_store[i] == NULL) {
                            fprintf(outProg, "outProg of memory\n");
                            exit(1);
                        }
                    }

                    // Parse the instructio - get rd, rs, rt registers
                    char *inst_ptr = tok_ptr;

                    // Keeps a reference to which register has been parsed for storage
                    // 分割指令中的参数, 并将其保存到reg_store数组中
                    int count = 0;
                    char *reg = NULL;
                    while (1) {
                        reg = parse_token(inst_ptr, " ;$,\n\t()", &inst_ptr, NULL);

                        if (reg == NULL || *reg == '#') {
                            if(reg != NULL) free(reg);
                            break;
                        }
                        strcpy(reg_store[count], reg);
                        count++;
                        free(reg);
                    }
                    debug_print("Split str to %s, %s, %s\n", reg_store[0], reg_store[1], reg_store[2]);

                    if (inst_type == 'r') {
                        //  printf("type r detected\n", data_reached);
                        // R-Type with $rd, $rs, $rt format
                        if (strcmp(token, "add")  == 0 || strcmp(token, "sub")  == 0
                                || strcmp(token, "and")  == 0 || strcmp(token, "srav") == 0
                                || strcmp(token, "or")   == 0 || strcmp(token, "slt")  == 0
                                || strcmp(token, "xor")  == 0 || strcmp(token, "addu") == 0
                                || strcmp(token, "subu") == 0 || strcmp(token, "nor")  == 0
                                || strcmp(token, "sltu") == 0 || strcmp(token, "sllv") == 0
                                || strcmp(token, "srlv") == 0 ) {


                            // rt in position 0, rs in position 1 and immediate in position 2
                            if (strcmp(token, "add")   == 0 || strcmp(token, "sub")  == 0
                                    || strcmp(token, "and")  == 0 || strcmp(token, "or")   == 0
                                    || strcmp(token, "slt")  == 0 || strcmp(token, "xor")  == 0
                                    || strcmp(token, "addu") == 0 || strcmp(token, "subu") == 0
                                    || strcmp(token, "nor")  == 0 || strcmp(token, "sltu") == 0) {
                                rtype_instruction(token, reg_store[1], reg_store[2], reg_store[0], 0, outProg);
                            }
                            if (strcmp(token, "sllv")    == 0|| strcmp(token, "srlv") == 0
                                    || strcmp(token, "srav") == 0) {
                                rtype_instruction(token, reg_store[2], reg_store[1], reg_store[0], 0, outProg);
                            }
                        }

                        // R-Type with $rd, $rs, shamt format
                        else if (strcmp(token, "sll")   == 0 || strcmp(token, "srl") == 0
                                 || strcmp(token, "sra") == 0) {

                            // Send reg_store for output
                            // rd is in position 0, rs is in position 1 and shamt is in position 2
                            rtype_instruction(token, "00000", reg_store[1], reg_store[0], atoi(reg_store[2]), outProg);
                        }

                        else if (strcmp(token, "mfc0") == 0 || strcmp(token, "mtc0") == 0) {

                            // Send reg_store for output
                            // rd is in position 0, rs is in position 1 and shamt is in position 2
                            if (strcmp(token, "mfc0") == 0 ) {
                                rtype_instruction(token, "00000", reg_store[0], reg_store[1], 0, outProg);
                            }

                            if (strcmp(token, "mtc0") == 0) {
                                rtype_instruction(token, "00100", reg_store[0], reg_store[1], 0, outProg);
                            }
                        }

                        else if (strcmp(token, "mult")  == 0 || strcmp(token, "multu") == 0
                                 || strcmp(token, "div") == 0 || strcmp(token, "divu")  == 0) {

                            // Send reg_store for output
                            // rd is in position 0, rs is in position 1 and shamt is in position 2
                            rtype_instruction(token, reg_store[0], reg_store[1], "00000", 0, outProg);

                        } else if (strcmp(token, "jalr") == 0) {
                            // Send reg_store for output
                            // rd is in position 0, rs is in position 1 and shamt is in position 2
                            rtype_instruction(token, reg_store[1], "00000", reg_store[0], 0, outProg);
                        } else if (strcmp(token, "jr") == 0) {
                            // Parse the instruction - rs is in tok_ptr
                            rtype_instruction(token, reg_store[0], "00000", "00000", 0, outProg);
                        } else if (strcmp(token, "mfhi") == 0 || strcmp(token, "mflo") == 0
                                   || strcmp(token, "mthi") == 0 || strcmp(token, "mtlo") == 0) {

                            if (strcmp(token, "mfhi") == 0 || strcmp(token, "mflo") == 0) {
                                // Send reg_store for output
                                // rd is in position 0, rs is in position 1 and shamt is in position 2
                                rtype_instruction(token, "00000", "00000", reg_store[0], 0, outProg);
                            }

                            if (strcmp(token, "mthi") == 0 || strcmp(token, "mtlo") == 0) {
                                // Send reg_store for output
                                // rd is in position 0, rs is in position 1 and shamt is in position 2
                                rtype_instruction(token, reg_store[0], "00000", "00000", 0, outProg);
                            }
                        } else if (strcmp(token, "eret") == 0) {

                            rtype_instruction(token, "10000", "00000", "00000", 0, outProg);
                        }
                    }   // inst_type = 'r'

                    // I-Type
                    else if (inst_type == 'i') {

                        // la is pseudo instruction for lui and ori
                        // Convert to lui and ori and pass those instructions
                        if (strcmp(token, "la") == 0) {

                            // Interpret la instruction.
                            // The register is at reg_store[0] and the variable is at reg_store[1]
                            // Find address of label in hash table
                            int *address = hash_find(hash_table, reg_store[1], strlen(reg_store[1])+1);

                            // Convert address to binary in char*
                            char addressBinary[33];
                            getBin(*address, addressBinary, 32);

                            // Get upper and lower bits of address
                            char upperBits[16];
                            char lowerBits[16];

                            for (int i = 0; i < 32; i++) {
                                if (i < 16)
                                    lowerBits[i] = addressBinary[i];
                                else
                                    upperBits[i-16] = addressBinary[i];
                            }

                            // Call the lui instruction with: lui $reg, upperBits
                            // Convert upperBits binary to int
                            int immediate = getDec(upperBits);
                            itype_instruction("lui", "00000", reg_store[0], immediate, outProg);


                            // Call the ori instruction with: ori $reg, $reg, lowerBits
                            // Convert lowerBits binary to int
                            immediate = getDec(lowerBits);
                            itype_instruction("ori", reg_store[0], reg_store[0], immediate, outProg);
                        }

                        // I-Type $rt, i($rs)
                        else if (strcmp(token, "lw") == 0 || strcmp(token, "sw")  == 0
                                 || strcmp(token, "lb") == 0 || strcmp(token, "lbu") == 0
                                 || strcmp(token, "lh") == 0 || strcmp(token, "lhu") == 0
                                 || strcmp(token, "sb") == 0 || strcmp(token, "sh")  == 0) {

                            // TODO: 这些命令均会判断该数字是否属于数据段, 如果属于数据段将会对其进行运算查找
                            int *address = hash_find(hash_table, reg_store[1], strlen(reg_store[1])+1); // 从hash表中寻找该字符串
                            int immediate = 0;
                            if(address != NULL) {
                                immediate = *address;
                                printf("The address is %d\n", *address);
                            } else {
                                immediate = atoi(reg_store[1]);
                                if(0 == strncmp(reg_store[1], "0x", 2)) {
                                    immediate = strtol(reg_store[1], NULL, 16);
                                } else {
                                    immediate = atoi(reg_store[1]);
                                }
                            }

                            // rt in position 0, immediate in position 1 and rs in position2
                            itype_instruction(token, reg_store[2], reg_store[0], immediate, outProg);
                        }

                        else if (strcmp(token, "li") == 0) {

                            // rt in position 0, rs in position 1 and immediate in position 2
                            int immediate = atoi(reg_store[1]);
                            itype_instruction("ori", "00000", reg_store[0], immediate, outProg);

                        }
                        // I-Type rt, rs, im
                        else if (strcmp(token, "andi") == 0 || strcmp( token, "ori")  == 0
                                 || strcmp(token, "slti")   == 0 || strcmp(token, "addi")  == 0
                                 || strcmp(token, "xori")   == 0 || strcmp(token, "sltiu") == 0
                                 || strcmp(token, "addiu")  == 0) {

                            // rt in position 0, rs in position 1 and immediate in position 2
                            int immediate = 0;
                            if(0 == strncmp(reg_store[2], "0x", 2)) {
                                immediate = strtol(reg_store[2], NULL, 16);
                            } else {
                                immediate = atoi(reg_store[2]);
                            }
                            itype_instruction(token, reg_store[1], reg_store[0], immediate, outProg);
                        }

                        // I-Type $rt, immediate
                        else if (strcmp(token, "lui") == 0) {

                            // rt in position 0, immediate in position 1
                            int immediate = atoi(reg_store[1]);
                            itype_instruction(token, "00000", reg_store[0], immediate, outProg);
                        }

                        else if (strcmp(token, "bgez") == 0 || strcmp(token, "bgtz")   == 0
                                 || strcmp(token, "blez")   == 0 || strcmp(token, "bltz")   == 0
                                 || strcmp(token, "bgezal") == 0 || strcmp(token, "bltzal") == 0) {

                            // Parse the instruction - rs, rt
                            char *inst_ptr = tok_ptr;
                            char *reg1 = reg_store[0];
                            char *reg2 = reg_store[1];

                            // Create an array of char* that stores rs

                            // Find hash address for a register and put in an immediate
                            int *address = hash_find(hash_table, reg2, strlen(reg2)+1);

                            int immediate;
                            if(prog_int_reach == 1) {       // 计算offset
                                immediate = instruction_int_count - *address ;
                            } else {
                                immediate = instruction_count - *address ;
                            }
                            immediate = immediate >> 2;     // 有符号的右移运算

                            if (strcmp(token, "bgez") == 0) {
                                // Send instruction to itype function
                                itype_instruction(token, reg1, "00001", immediate, outProg);
                            }
                            if (strcmp(token, "bgtz") == 0|| strcmp(token, "blez") == 0
                                    || strcmp(token, "bltz") == 0) {
                                // Send instruction to itype function
                                itype_instruction(token, reg1, "00000", immediate, outProg);
                            }
                            if (strcmp(token, "bgezal") == 0 ) {
                                // Send instruction to itype function
                                itype_instruction(token, reg1, "10001", immediate, outProg);
                            }
                            if (strcmp(token, "bltzal") == 0) {
                                // Send instruction to itype function
                                itype_instruction(token, reg1, "10000", immediate, outProg);
                            }
                        }

                        // I-Type $rs, $rt, label
                        else if (strcmp(token, "beq") == 0|| strcmp(token, "bne") == 0) {

                            // Find hash address for a register and put in an immediate
                            int *address = hash_find(hash_table, reg_store[2], strlen(reg_store[2])+1);

                            debug_print("The jump pos is %d\n", *address);  // 打印跳转地址

                            int immediate;
                            if(prog_int_reach == 1) {
                                immediate = *address - instruction_int_count;
                            } else {
                                immediate = *address - instruction_count;
                            }
                            //  immediate = immediate >> 2; CPU中实现有问题, 我也不打算解决了

                            // Send instruction to itype function
                           itype_instruction(token, reg_store[0], reg_store[1], immediate, outProg);
                        }
                    }

                    // J-Type
                    else if (inst_type == 'j') {
                        // Find hash address for a label and put in an immediate
                        int *address = hash_find(hash_table, reg_store[0], strlen(reg_store[0])+1);

                        int immediate = *address >> 2;

                        // Send to jtype function
                        jtype_instruction(token, immediate, outProg);
                    }

                    // NOP
                    else if(inst_type == 'n') {
                        fprintf(outProg, "00000000,\n");
                    }
                    outProg = tmpFile;

                   // Dealloc reg_store
                    for (int i = 0; i < 3; i++) {
                        free(reg_store[i]);
                         reg_store[i] = NULL;
                    }
                    free(reg_store);
                    reg_store = NULL;
                }

                // 遍历中断向量表, 查看该函数是否属于中断处理函数
                for(int i = 0; i < intCnt; i++) {

                    if (strcmp(token, intchar[i]) == 0) {
                        char s[50],out[50];
                        char opcode[20]= {0};

                        size_t token_len = strlen(token);
                        token[token_len - 1] = '\0';
                        intnum ++;
                        char immediate[17];
                        int *address = hash_find(hash_table, token, strlen(token)+1);
                        // char *opcode = intchar[i+1];
                        strcpy(opcode,intchar[i + 1]);
                        int immediateStr = *address;
                        getBin(immediateStr, immediate, 16);
                        sprintf(s, "%s%s\n", opcode, immediate);
                        parseHex(s,out);
                        fprintf(outInt, "%s,\n", out);
                    }
                }
            }

            // If .data part reached
            else {
                char *var_tok = NULL;
                char *var_tok_ptr = tok_ptr;

                /**
                 * for example:
                 *  In buf : .word 7
                 *      token is  buf
                 *      tok_ptr is .word 7
                 *
                 * In  buf buf1: .word 2:3
                 *      token is buf1
                 *      tok_ptr is .word 2:3
                 */

                // If variable is .word
                if (strstr(tok_ptr, ".word")) {

                    long long  var_value;

                    // Variable is array
                    if (strstr(var_tok_ptr, ":")) {

                        // Store the number in var_tok and the occurance in var_tok_ptr
                        var_tok = parse_token(var_tok_ptr, ":", &var_tok_ptr, NULL);

                        // Extract array size, or variable frequency
                        int freq = atoi(var_tok_ptr);

                        // Extract variable value
                        sscanf(var_tok, "%*s %d", &var_value);

                        // Value var_value is repeated freq times. Send to binary rep function
                        for (int i = 0; i < freq; i++) {
                            word_rep(var_value, outData);
                        }
                    }

                    // Variable is a single variable
                    else {
                        char *p = "0x";
                        char *q = NULL;
                        if (strstr(var_tok_ptr,p) != NULL) {
                            int len = 0;
                            char *s[8] = {0};
                            //	printf("var_tok_ptr1 %s\n", var_tok_ptr);
                            // Extract variable value
                            //var_tok_ptr = var_tok_ptr + 8;
                            // printf("uuuuuuuuuuuu %s\n", var_tok_ptr);
                            q = parse_token(var_tok_ptr, p, &var_tok_ptr, NULL);
                            // printf("strlen .%d.\n", strlen(q-1));
                            var_tok_ptr = var_tok_ptr + 1 ;
                            // printf("q .%s.....\n", q);
                            // printf("var_tok_ptr .%s.......\n", var_tok_ptr);
                            len = strlen(var_tok_ptr);
                            //	printf("len .%d.\n", len);
                            if(len <= 9) {
                                //	printf("len .%d.\n", len);
                                sscanf(var_tok_ptr,"%x", &var_value);
                                // Variable is in var_value. Send to binary rep function
                                word_rep(var_value, outData);
                            } else
                                fprintf(stderr, "error! Please intput the right size variable\n");

                        } else {
                            sscanf(var_tok_ptr, "%*s %d", &var_value);
                            word_rep(var_value, outData);
                        }
                    }
                }

                // Variable is a string
                else if (strstr(tok_ptr, ".asciiz")) {

                    printf("tok_ptr '%s\n", tok_ptr);

                    if (strncmp(".asciiz ", var_tok_ptr, 8) == 0) {

                        // Move var_tok_ptr to beginning of string
                        var_tok_ptr = var_tok_ptr + 9;

                        // Strip out quotation at the end
                        // Place string in var_tok
                        var_tok = parse_token(var_tok_ptr, "\"", &var_tok_ptr, NULL);

                        ascii_rep(var_tok, outData);
                    }
                }
            }

        }

        free(token);
        //}
    }

    if(pass == 2) { // 在第二次解析完成后, 各个文件中补充0

        // 填充用户程序
        for(int i = printProgCnt; i < INT_START; i++) {
            fprintf(outProg, "00000000,\n");
        }

        // 填充中断向量表
        for(int i = intnum; i < DATA_START; i++) {
            fprintf(outInt, "00000000,\n");
        }
    }
}

// Binary Search the Array
int binarySearch(char *instructions[], int low, int high, char *string)
{

    int mid = low + (high - low) / 2;
    int comp = strcmp(instructions[mid], string);

    if (comp == 0)
        return mid;

    // Not found
    if (high <= low)
        return -1;

    // If instructions[mid] is less than string
    else if (comp > 0)
        return binarySearch(instructions, low, mid - 1, string);

    // If instructions[mid] is larger than string
    else if (comp < 0)
        return binarySearch(instructions, mid + 1, high, string);

    // Return position
    else
        return mid;

    // Error
    return -2;
}

// Determine Instruction Type
char instruction_type(char *instruction)
{

    if (strcmp(instruction, "add")    == 0 || strcmp(instruction, "sub")   == 0
            || strcmp(instruction, "and")  == 0 || strcmp(instruction, "mtc0")  == 0
            || strcmp(instruction, "or")   == 0 || strcmp(instruction, "sll")   == 0
            || strcmp(instruction, "slt")  == 0 || strcmp(instruction, "srl")   == 0
            || strcmp(instruction, "jr")   == 0 || strcmp(instruction, "xor")   == 0
            || strcmp(instruction, "addu") == 0 || strcmp(instruction, "subu")  == 0
            || strcmp(instruction, "nor")  == 0 || strcmp(instruction, "sltu")  == 0
            || strcmp(instruction, "sra")  == 0 || strcmp(instruction, "sllv")  == 0
            || strcmp(instruction, "srlv") == 0 || strcmp(instruction, "srav")  == 0
            || strcmp(instruction, "mult") == 0 || strcmp(instruction, "multu") == 0
            || strcmp(instruction, "div")  == 0 || strcmp(instruction, "divu")  == 0
            || strcmp(instruction, "mthi") == 0 || strcmp(instruction, "mtlo")  == 0
            || strcmp(instruction, "mfhi") == 0 || strcmp(instruction, "mflo")  == 0
            || strcmp(instruction, "jalr") == 0 || strcmp(instruction, "eret")  == 0
            || strcmp(instruction, "MOV")  == 0 || strcmp(instruction, "mfc0")  == 0
       ) {

        return 'r';
    }

    else if (strcmp(instruction, "lw")  == 0 || strcmp(instruction, "sw")     == 0
             || strcmp(instruction, "andi") == 0 || strcmp(instruction, "bltzal") == 0
             || strcmp(instruction, "ori")  == 0 || strcmp(instruction, "lui")    == 0
             || strcmp(instruction, "beq")  == 0 || strcmp(instruction, "slti")   == 0
             || strcmp(instruction, "addi") == 0 || strcmp(instruction, "la")     == 0
             || strcmp(instruction, "xori") == 0 || strcmp(instruction, "lb")     == 0
             || strcmp(instruction, "lbu")  == 0 || strcmp(instruction, "lh")     == 0
             || strcmp(instruction, "lhu")  == 0 || strcmp(instruction, "sb")     == 0
             || strcmp(instruction, "sh")   == 0 || strcmp(instruction, "sltiu")  == 0
             || strcmp(instruction, "bne")  == 0 || strcmp(instruction, "bgez")   == 0
             || strcmp(instruction, "li")   == 0 || strcmp(instruction, "addiu")  == 0
             || strcmp(instruction, "bgtz") == 0 || strcmp(instruction, "blez")   == 0
             || strcmp(instruction, "bltz") == 0 || strcmp(instruction, "bgezal") == 0
            ) {

        return 'i';
    }

    else if (strcmp(instruction, "j") == 0 || strcmp(instruction, "jal") == 0) {
        return 'j';
    }

    else if (strcmp(instruction, "nop") == 0) {
        return 'n';
    }

    // Failsafe return statement
    return 0;
}

// Return the binary representation of the register
char *register_address(char *registerName)
{

    size_t i;
    for (i = 0; registerMap[i].name != NULL; i++) {
        if (strcmp(registerName, registerMap[i].name) == 0) {
            return registerMap[i].address;
        }
    }

    return NULL;
}

// Write out the R-Type instruction
void rtype_instruction(char *instruction, char *rs, char *rt, char *rd, int shamt, FILE *outProg)
{
    // Set the instruction bits
    char *opcode = "000000";
    char s[50],out[50];

    char *rdBin = "00000";
    if (strcmp(rd, "00000") != 0)
        rdBin = register_address(rd);

    char *rsBin = "00000";
    if (strcmp(rs, "00000") != 0 && strcmp(rs, "10000") != 0 && strcmp(rs, "00100") != 0 )
        rsBin = register_address(rs);
    if (strcmp(rs, "10000") == 0)
        rsBin = "10000";
    if (strcmp(rs, "00100") == 0)
        rsBin = "00100";

    char *rtBin = "00000";
    if (strcmp(rt, "00000") != 0)
        rtBin = register_address(rt);

    char *func = NULL;
    char shamtBin[6];

    // Convert shamt to binary and put in shamtBin as a char*
    getBin(shamt, shamtBin, 5);

    size_t i;
    for (i = 0; rMap[i].name != NULL; i++) {
        if (strcmp(instruction, rMap[i].name) == 0) {
            func = rMap[i].function;
        }
    }
    if (strcmp(func, "011000") == 0&&strcmp(rs, "10000") == 0)
        opcode = "010000";
    if (strcmp(func, "000000") == 0&&strcmp(rs, "00000") == 0 && shamt ==0)
        opcode = "010000";
    if (strcmp(func, "000000") == 0&&strcmp(rs, "00100") == 0)
        opcode = "010000";
    sprintf(s, "%s%s%s%s%s%s", opcode, rsBin, rtBin, rdBin, shamtBin, func);
    // Print out the instruction to the file
    parseHex(s,out);
    fprintf(outProg, "%s,\n",out);
    debug_print("write =>%s\n", out);
}

// Write out the I-Type instruction
void itype_instruction(char *instruction, char *rs, char *rt, int immediateNum, FILE *outProg)
{
    /*
    if(isFirst == 1 )
        isFirst = 0;
    else
        fprintf(outProg, "%s,\n","");
    */

    char s[50],out[50];
    // Set the instruction bit
    char *rsBin = "00000";
    if (strcmp(rs, "00000") != 0)
        rsBin = register_address(rs);

    char *rtBin = "00000";
    if (strcmp(rt, "00000") != 0 && strcmp(rt, "00001") != 0
            && strcmp(rt, "10001") != 0 && strcmp(rt, "10000") != 0)
        rtBin = register_address(rt);
    if (strcmp(rt, "00001") == 0)
        rtBin = "00001";
    if (strcmp(rt, "10001") == 0)
        rtBin = "10001";
    if (strcmp(rt, "10000") == 0)
        rtBin = "10000";

    char *opcode = NULL;
    char immediate[17];

    size_t i;
    for (i = 0; iMap[i].name != NULL; i++) {
        if (strcmp(instruction, iMap[i].name) == 0) {
            opcode = iMap[i].address;
        }
    }

    // Convert immediate to binary
    getBin(immediateNum, immediate, 16);
    sprintf(s, "%s%s%s%s,\n", opcode, rsBin, rtBin, immediate);
    // Print out the instruction to the file
    parseHex(s,out);
    fprintf(outProg, "%s,\n",out);
    debug_print("write =>%s\n", out);
}

// Write out the J-Type instruction
void jtype_instruction(char *instruction, int immediate, FILE *outProg)
{
    /*
    if(isFirst == 1 )
        isFirst = 0;
    else
        fprintf(outProg, "%s,\n","");
    */

    // Set the instruction bits
    char *opcode = NULL;
    char s[50],out[50];
    // Get opcode bits
    size_t i;
    for (i = 0; jMap[i].name != NULL; i++) {
        if (strcmp(instruction, jMap[i].name) == 0) {
            opcode = jMap[i].address;
        }
    }

    // Convert immediate to binary
    char immediateStr[27];
    getBin(immediate, immediateStr, 26);
    sprintf(s,"%s%s\n", opcode, immediateStr);
    // Print out the instruction to the file
    parseHex(s,out);
    fprintf(outProg, "%s,\n",out);
    debug_print("write =>%s\n", out);
}


// Write out the variable in binary
// input number
// output char[]
void word_rep(int binary_rep, FILE *outData)
{

    char s[33] =  {0};
    char out[33] = {0};
    int i = 31;

    while(i >= 0) {
        s[i] = (binary_rep & 0x1) ? '1' : '0';
        i --;
        binary_rep = binary_rep >> 1;
    }

    parseHex(s,out);
    fprintf(outData, "%s,\n",out);
}

// Write out the ascii string
void ascii_rep(char string[], FILE *outData)
{
//    if(isFirst3 == 1 )
//        isFirst3 = 0;
//    else
    // Separate the string, and put each four characters in an element of an array of strings
    size_t str_length = strlen(string);
    str_length++;
    int num_strs = str_length / 4;
    if ((str_length % 4) > 0)
        num_strs++;

    char *ptr;
    ptr = &string[0];

    // Create an array of strings which separates each 4-char string
    char **sep_str;
    sep_str = malloc(num_strs * sizeof(char*));
    if (sep_str == NULL) {
        fprintf(outData, "outProg of memory\n");
        exit(1);
    }

    for (int i = 0; i < num_strs; i++) {
        sep_str[i] = malloc(4 * sizeof(char));
        if (sep_str[i] == NULL) {
            fprintf(outData, "outProg of memory\n");
            exit(1);
        }
    }

    int count = 0;
    for (int i = 0; i < str_length; i++) {
        sep_str[i / 4][i % 4] = *ptr;
        ptr++;
        count++;
    }

    // Reverse each element in the array
    char temp;

    for (int i = 0; i < num_strs; i++) {

        for (int j = 0, k = 3; j < k; j++, k--) {

            temp = sep_str[i][j];
            sep_str[i][j] = sep_str[i][k];
            sep_str[i][k] = temp;
        }
    }

    char s[33] =  {0};
    char out[33] = {0};
    // Convert into binary
    for (int i = 0; i < num_strs; i++) {

        for (int j = 0; j < 4; j++) {
            char c = sep_str[i][j];
            for (int k = 7; k >= 0; k--) {
                fprintf(outData, "%c", (c & (1 << k)) ? '1' : '0');
            }
        }
    }
    fprintf(outData, ",\n");

    // Deallocate sep_str
    for (int i = 0; i < num_strs; i++) {
        free(sep_str[i]);
    }
    free(sep_str);
    sep_str = NULL;
}

void getBin(int num, char *str, int padding)
{

    *(str + padding) = '\0';

    long pos;
    if (padding == 5)
        pos = 0x10;
    else if (padding == 16)
        pos = 0x8000;
    else if (padding == 26)
        pos = 0x2000000;
    else if (padding == 32)
        pos = 0x80000000;

    long mask = pos << 1;
    while (mask >>= 1)
        *str++ = !!(mask & num) + '0';
}

// Convert a binary string to a decimal value
int getDec(char *bin)
{

    int  b, k, m, n;
    int  len, sum = 0;

    // Length - 1 to accomodate for null terminator
    len = strlen(bin) - 1;

    // Iterate the string
    for(k = 0; k <= len; k++) {

        // Convert char to numeric value
        n = (bin[k] - '0');

        // Check the character is binary
        if ((n > 1) || (n < 0))  {
            return 0;
        }

        for(b = 1, m = len; m > k; m--)
            b *= 2;

        // sum it up
        sum = sum + n * b;
    }

    return sum;
}

char getHex(char *bin)
{
    int i = 0;
    while(i <= 16) {
        if(strncmp(cvt_tbl[i].src, bin, 4) == 0)
            break;
        i++;
    }
    return cvt_tbl[i].dst;
}


/**
 * @brief 将2进制的字符串转换为16进制形式的表示
 *
 * @param bin 输入的32为字符串
 * @param hex 存放转换过后的字符串
 */
void parseHex(char *bin, char *hex)
{

    int len = strlen(bin);
    if(len < 32) {
        printf("err occured in input %s", bin);
        exit(-1);
    }
    bin[32] = 0;

    int i = 0;
    int j = 0;
    while(i < 32) {
        hex[j++] = getHex(bin+i);
        i += 4;
    }
    hex[8] = 0;
    return;
}

/*
 *=======================================================================
 *    Filename:unit_test.c
 *
 *     Version: 1.0
 *  Created on: September 23, 2017
 *
 *      Author: corvo
 *=======================================================================
 */

/**
 * 汇编器单元测试文件, 准备通过此程序进行单元测试,
 *   由于C程序单元测试引用第三方库较为复杂, 因此,
 *   选择自己编写简单的程序进行测试
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  16进制转换表
 */
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

/**
 *  @brief 获取4位二进制对应的字符
 */
char getHex(char *bin) {
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
void parseHex(char *bin, char *hex) {

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


#define MAX_LINE_LENGTH 1024

/**
 * @brief 测试主体函数
 *
 * @param out       由mips-compiler输出的文件
 * @param check     核对文件
 */
void unit_test(FILE* out, FILE* check) {
    char outLine[MAX_LINE_LENGTH + 1];
    char checkLine[MAX_LINE_LENGTH + 1];

    char outHex[10] = {0};        // 存放转换过后的的16进制字符串
    int line = 0;

    while(1) {
        if(fgets(outLine, MAX_LINE_LENGTH, out) == NULL)
            break;
        outLine[MAX_LINE_LENGTH] = 0;

        if(fgets(checkLine, MAX_LINE_LENGTH, check) == NULL)
            break;
        checkLine[MAX_LINE_LENGTH] = 0;

        line ++;
        parseHex(outLine, outHex);
        if(strncmp(outHex, checkLine, 8) != 0) {
            printf("In line %d, out: %s check : %s\n", line, outHex, checkLine);
            return;
        }
    }

    printf("all check pass\n");
    return;
}


int main() {
    FILE *out_txt = fopen("out.txt", "r");
    FILE *check_txt = fopen("check.txt", "r");

    unit_test(out_txt, check_txt);

    fclose(out_txt);
    fclose(check_txt);
    return 0;
}

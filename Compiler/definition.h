#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int Totalerrors, funcount;
extern struct allFunc **ALL;

struct AST {
    char txt[50];
    char numtxt[50];
    int ntno;
    int procno;
    int multiplicity;
    int contain_expr;
    struct AST *parent;
    struct AST **child;
};

struct allFunc {
    char name[50];
    int type;
    struct symbolTable *st;
    struct AST *t;
};

struct symbolTable {
    int count;
    struct symbolTableItem **item;
};

struct symbolTableItem {
    char name[50];
    int pos; // 1-a, 2-t7, 3-s, 4-sp
    int offset;
};

struct messenger {
    int type; // 1-reg, 2-stack
    char pos[10];
};

struct AST * makeNode(int num);
struct symbolTable * makeST();
struct symbolTableItem * makeSTitem();
void st_add(char *name, int pos, int offset, int funcno);
struct messenger * lookup(char *name, int funcno);
void GenerateMIPS();





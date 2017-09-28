#include "definition.h"
#include "y.tab.h"

struct AST * makeNode(int num) {
	struct AST * node = (struct AST *)malloc(sizeof(struct AST));
	node->parent = NULL;
    node->child = (struct AST **)malloc(num * sizeof(struct AST *));
	node->ntno = 0;
	node->procno = 0;
	node->multiplicity = 0;
    node->contain_expr = 0;
    return node;
}

struct symbolTable * makeST() {
    struct symbolTable * st = (struct symbolTable *)malloc(sizeof(struct symbolTable));
    st->item = (struct symbolTableItem **)malloc(30 * sizeof(struct symbolTableItem *));
    st->count = 0;
    return st;
}

struct symbolTableItem * makeSTitem() {
    struct symbolTableItem * item = (struct symbolTableItem *)malloc(sizeof(struct symbolTableItem));
    item->pos = 0;
    item->offset = -1;
    return item;
}

void st_add(char *n, int p, int o, int funcno) {
    ALL[funcno]->st->item[count] = makeSTitem();
    strcpy(ALL[funcno]->st->item[count]->name, n);
    ALL[funcno]->st->item[count]->pos = p;
    ALL[funcno]->st->item[count]->offset = o;
    ALL[funcno]->st->count++;
}

char * lookup(char *n, int funcno) {
    char a[10];
    char b[10];
    for (int i = 0; i < count; i++) {
        if (strcmp(ALL[funcno]->st->item[i]->name, n) == 0) {
            if (ALL[funcno]->st->item[count]->pos == 1) {
                strcpy(a, "$a");
                sprintf(b, "%d", ALL[funcno]->st->item[count]->offset);
            } else if (ALL[funcno]->st->item[count]->pos == 2) {
                sprintf(a, "%d", 4 * ALL[funcno]->st->item[count]->offset);
                strcpy(b, "($t7)");
            } else if (ALL[funcno]->st->item[count]->pos == 3) {
                strcpy(a, "$s");
                sprintf(b, "%d", ALL[funcno]->st->item[count]->offset);
            } else if (ALL[funcno]->st->item[count]->pos == 4) {
                sprintf(a, "%d", 4 * ALL[funcno]->st->item[count]->offset);
                strcpy(b, "($sp)");
            }
            strcat(a, b);
            return a;
        }
    }
    strcpy(a, "NULL");
    return a;
}

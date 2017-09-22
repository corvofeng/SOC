#include "definition.h"
#include "y.tab.h"

////////////////////////////////////
/// SYMBOL TABLE FUNCTIONS ////////
////////////////////////////////////
struct AST *tree;
struct symbolTree *sym=NULL, *currentT=NULL;		//  currentT is symboltree node where symbols are to be added

void init(){
	currentT = (struct symbolTree *)malloc(sizeof(struct symbolTree));
	currentT->t = NULL;
	currentT->scope = 0;	// global scope
	currentT->current = 0;
	currentT->parent = NULL;
	currentT->tableSize = 0;
	sym = currentT;
	ALL = (struct allFunc **)malloc(20*sizeof(struct allFunc *));
	return;
}
void AddSymbol(char *s,struct global add,struct symbolTree *p){

	/*if(mycheck(s,add.struct_member)==0){
		printf("%s is a special Character\n",s);
	}
	*/
	if(currentFind(s,add,p)==1){
		printf("Multiple definitions of %s\n",s);
		Totalerrors++;
	}

	struct symbolTable *tmp = (struct symbolTable *)malloc(sizeof(struct symbolTable));
	strcpy(tmp->name,s);
	tmp->offset = add.offset;
	tmp->type = add.type;
	tmp->pointer = add.pointer;
	tmp->array = add.array;
	tmp->dim1 = add.dim1;
	tmp->dim2 = add.dim2;
	tmp->struct_member = add.struct_member;
	tmp->order =0;
	if(add.type==5)	{				// if this is a struct variable 
		strcpy(tmp->structID,add.structID);
		tmp->var_size = add.order;
		tmp->order = add.order;
		if(add.array==1)
			tmp->var_size = tmp->var_size * add.dim1;
	}	
	if(add.struct_member==1){
		strcpy(tmp->structName,add.structName);
		tmp->order = add.order;
	}	
		// 32 bit address
	if((add.array == 0 || add.array ==1 || add.array == 2) && !add.struct_member){ 
		if(add.pointer == 1)
			tmp->var_size = 4;	
		else if(add.type == INT || add.type == FLOAT || add.type == CHAR){

			if(add.array == 0)
				tmp->var_size = 4;
			else if(add.array==1)
				tmp->var_size = 4 * add.dim1;
			else
				tmp->var_size = 4 * add.dim1 * add.dim2;
		}
	}
	else if(add.array == 111 || add.array == 222){
		tmp->var_size = 4;
	}
	else						
		tmp->var_size = 0;

	p->tableSize += tmp->var_size;
	tmp->parentT = p;

	if(p->t == NULL)
		tmp->offset = 0;
	else
		tmp->offset = p->t->offset + p->t->var_size ;

	tmp->down = p->t;
	p->t = tmp;
	
}



struct symbolTable * FindSymbol(char *s,struct global check, struct symbolTree* T){		// modify this for struct members
		
		struct symbolTree *t2 = T;
		while(t2 != NULL){
			struct symbolTable *tmp = t2->t;
			while(tmp != NULL){
				if(strcmp(tmp->name,s)==0){
					//printf("found %s %d %d\n",s,tmp->array,check.array );
					if(check.array == tmp->array){
						if(check.struct_member == 1){
							//printf("2");
							if(strcmp(tmp->structName,check.structName)==0)
								return tmp;
							//printf("3");
						}
						else
							return tmp;
					}
					//printf("1");	
				}
				tmp = tmp->down;
			}
			t2 = t2->parent;
		}
		Totalerrors++;
		return NULL;
}

struct symbolTree * EnterScope(struct symbolTree * t){
	struct symbolTree * t1;
	t->child[t->current] = (struct symbolTree *)malloc(sizeof(struct symbolTree));
	t1 = t->child[t->current];
	(t->current)++;
	t1->current = 0;
	t1->tableSize = 0;
	t1->t = NULL;
	t1->scope = t->scope + 1;
	t1->parent = t;
	return t1;

}

struct symbolTree * ExitScope(struct symbolTree * t){
	return t->parent;
}	

int currentFind(char *s,struct global g,struct symbolTree *t){ 		// only check for g.structName , if g.struct_member = 1
	struct symbolTable *tmp = t->t;
	while(tmp != NULL){
		if(strcmp(tmp->name,s)==0){
			if(tmp->struct_member==1){
				if(strcmp(tmp->structName,g.structName)==0)
					return 1;
			}
			else
				return 1;
		}
		tmp = tmp->down;
	}
	return 0;
}
//////////////////////////////////////////
/////////////////////////////////////////
///////////////////////////////////////////
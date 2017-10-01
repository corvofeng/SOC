#include "definition.h"
#include "y.tab.h"
int init_count=0;

struct AST * MakeNode(int num){
	struct AST * node = (struct AST*)malloc(sizeof(struct AST));
	node->parent = NULL;
	node->NumChild = num;
	node->child = (struct AST**)malloc(num*sizeof(struct AST *));
	node->array = 0;
	node->pointer = 0;
	node->dim1 =0;
	node->dim2 = 0;
	node->order = 0;
	node->where = NULL;
	node->scope=currentT->scope;
	node->scopenode = currentT;
	return node;
}

void TerminalChild(struct AST * p,int num,char *text,int type){
	p->child[num] = MakeNode(0);
	p->child[num]->parent = p;
	strcpy(p->child[num]->lexeme,text);
	p->child[num]->type = type;
}

void AST_print(struct AST *t){
	int i;
	if(t->NumChild==0) return;
	struct AST *t2=t;
	for(i=0;i<t2->NumChild;++i)
		AST_print(t->child[i]);
	printf("\n%s  -->",t2->lexeme);
	for(i=0;i<t2->NumChild;++i) printf("%s ",t2->child[i]->lexeme);
}
int G,order;
void addVar(struct global m, struct AST *p,struct symbolTree *t){
	// only m.type and m.struct_member is common for all childs
	// struct name, struct ID is also common
	if(p->type == 100 && m.struct_member == 1 && strcmp(p->lexeme,";")==0){
		G = p->child[0]->type;
	}
	if(p->type == 100){
		int i;
		for(i=0;i<p->NumChild;++i)
			addVar(m,p->child[i],t);
		free(p);
		return;
	}
	if(p->NumChild == 0 && p->type == IDENTIFIER){
		m.pointer = p->pointer;
		m.array	 = p->array;
		m.dim1 = p->dim1;
		m.dim2 = p->dim2;
		m.offset = 0; // to be calculated later
		if(m.struct_member == 1){
			m.type = G;
			m.order = order;
			order += 4;
			char s[100];
			strcpy(s,p->lexeme);
			strcpy(p->lexeme,".");
			strcat(p->lexeme,s);
		}
		else if(m.array == 5 || m.array == 6){
			m.order = p->order;
		}
		AddSymbol(p->lexeme,m,t);
		free(p);
		return;
	}
	else{
		int i;
		for(i=0;i<p->NumChild;++i)
			addVar(m,p->child[i],t);
		free(p);
		return;	
	}
}

void printSymbolTree(struct symbolTree *t){
	struct symbolTable *t1 = t->t;
	putchar('\n');
	printf("%d %d is size\n",t->tableSize,t->sumsize);	
	while(t1 != NULL){
		printf("%s %d %d:: ",t1->name,t1->offset,t1->var_size);
		t1 = t1->down;
	}
	int i;
	for(i=0;i<t->current;++i)
		printSymbolTree(t->child[i]);

}


void depthSymbolTree(struct symbolTree *t,int level){
	if(level==1){
		t->sumsize=t->tableSize;
	}
	int i;
	for(i=0;i<t->current;i++){
		t->child[i]->sumsize = t->child[i]->tableSize + t->sumsize ;
		depthSymbolTree(t->child[i],level+1);
	}
}

int mycheck(char *name,int struct_or_not){
	char arr[][100]={"auto","else",	"long",	"switch" ,"break","enum","register",	"typedef","case",	"extern",	"return",	"union", "char",	"float",	"short",	"unsigned",
"const","for","signed","void", "continue","goto","sizeof","volatile","default","if","static","while","do","int","struct","double"};
	int i,s;
	if(struct_or_not){	//structure element
		char name2[1000];
		if(name[0]!='.')	// if struct member not start with . err
			return 0;
		for(i=1;i<strlen(name);i++)	// remove .
			name2[i-1]=name[i];	
		name2[i]='\0';
		
		s=sizeof(arr)/sizeof(arr[0]);	
		for(i=0;i<s;i++){				//	match from arr 
			if(!strcmp(name2,arr[i]))
				return 0; 	// if match error 
		}	
		return 1;
	}
	else{	// check 
	s=sizeof(arr)/sizeof(arr[0]);
		for(i=0;i<s;i++){
			if(!strcmp(name,arr[i]))
				return 0; 	// if match error 
		}	
	}
	return 1;
}
int children;
void function1(int A[],struct AST *x)
{
	if(x->NumChild==0){
		A[children]=x->type;
		children++;
		return;
	}
	int i;
	for(i=0;i<x->NumChild;i++){
		function1(A,x->child[i]);	
	}
}
int check_arg(char *A,struct AST *x)
{
	//printf("%s is name\n",A);
	int B[100];
	int C[100],a,b;
	children=0;
	function1(B,x);
	a=children;
	//printf("%d is a\n",a);
	int i;
	printf("Print ut \n%s\nshjfhds\n",A);
	for(i=0;i<funcount;i++){
		printf("fun ::-- %s\n",ALL[i]->name);
		if(strcmp(ALL[i]->name,A)==0)	break;
	}
	if(i==funcount)	return 0;
	children=0;
	function1(C,ALL[i]->arg);
	b=children;
	//printf("%d is b\n",b);
	if(a!=b)	return 1;
	for(i=0;i<a;i++){
		//printf("%d %d\n",B[i],C[i]);
		if(B[i]!=C[i])	return 1;
	}
	return 0;
}

void propagate(struct AST *t,int scope,struct symbolTree *st){
	int i;
	t->scope = scope;
	t->scopenode = st;
	if(t->NumChild == 0 ) return;
	for(i=0;i<t->NumChild;++i)
		propagate(t->child[i],scope,st);
}

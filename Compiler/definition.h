#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int Totalerrors,funcount,order;
extern struct symbolTree *currentT, *sym;
extern struct AST *tree;
extern struct allFunc **ALL;
extern int init_count;
/*
	Always check type first for an identifier,,  if type == 6 ,, do nothing
*/
struct symbolTable{
	char name[50];
	
	int offset;			// to be calculated later
	int var_size;		// size of variable in bytes  4- int , 1- char , 4 - float ,, not defined for type 5 and 6

	int pointer;		// 1 if this is a pointer
	int array;			// 1 -- 1 d array, 2 -- 2d array ,, 3 - funtion no arg ,, 4-- funtion  with arg  

	int dim1,dim2;		// dimentions of array ,, if it is array

	int type;			/* type of identifier 
							VOID , INT , FLOAT , CHAR  , 5 struct or union  
							6 -- name contains ,, id -- struct id { ...} // to determine is struct with id exists or not.. 
							if type ==6 ,, donot allocate memory 
						*/
	char structID[50];		// if type = 5 , then struct identifier name
	int order;
	int struct_member;	// 0 false, 1 true .. if this variable is a member of struct
	char structName[50];	// if struct_member is true.. then name of parent struct
	struct symbolTree *parentT;
	struct symbolTable *down;
};

struct AST{
	char lexeme[100];
	int type ;		// type of statement  - 0 function, 1 iterative , 2 selection , 3 jump , 4 expression
	int NumChild;
	int lval;	// 0 not , 1 yes respectively
	int array;  	// 1 -- 1 d array, 2 -- 2d array ,, 3 - funtion no arg ,, 4-- funtion  with arg  
					// 10 - while,, 11 - for1, 12 -- for 2,,  
					// 15 -- if1 , 16 = if2
					// 50,51,52 function_name '(' argument_list ')' body
					// 53,54,55  function_name '(' ')' body
					// 60 -- struct .. argument_list ',' STRUCT IDENTIFIER IDENTIFIER 
					// 200 for constants 
					// 300 
	
	int pointer;	// pointer  --- used for putting variable in symbol table
	int dim1, dim2 ; // if this is array , the dim1 and dim2 tells its dimention
 	struct AST *parent;
	struct AST **child;
	int scope;
	int order;
	char l1[100],l2[100];
	struct symbolTree *scopenode;
	struct symbolTable *where;	// location of identifier in symbol table
	
};
struct symbolTree{
	int sumsize;
	int scope;					// 0 for global scope
	int current;				// current number of sub scopes; child[current] to be used next
	struct symbolTable *t;
	int tableSize;				// size of symbol table in terms of byte allocation
	struct symbolTree *parent;
	struct symbolTree *child[10];	// each scope can have at most 10 sub scopes .. 
									//this means at max 10 functions in a program
};

struct global{					
	int type,pointer,offset;
	int array,struct_member;
	int dim1,dim2;
	int order;
	char structName[100],structID[100];
};

struct allFunc{
	char name[100];
	struct symbolTree *st;
	struct AST *t,*arg;	
};



struct AST * MakeNode(int num);

void TerminalChild(struct AST * p,int num,char *text,int type);

void AST_print(struct AST *t);


///////////////////////////////////////////////////////////////////
// Stack Operations for symbolTable ( defined in symbolTable.c) ////
///////////////////////////////////////////////////////////////////

void init();
void AddSymbol(char *s,struct global add,struct symbolTree *p);
struct symbolTable * FindSymbol(char *s,struct global check, struct symbolTree* T);
struct symbolTree * EnterScope(struct symbolTree * t);
struct symbolTree * ExitScope(struct symbolTree * t);
int currentFind(char *s,struct global g,struct symbolTree *t);		// returns 1 if s is found in scope of t

////////////////////////////////////////////////////////////////
///////////////////  Others funtions ///////////////////////////

void addVar(struct global m, struct AST *p,struct symbolTree *t); // adds all identifiers  to symbol table 
int mycheck(char *name,int struct_or_not);
void GenerateMIPS();
int check_arg(char A[],struct AST *x);
void propagate(struct AST *t,int scope,struct symbolTree *st);

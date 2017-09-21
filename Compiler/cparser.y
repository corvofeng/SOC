%{
#include"definition.h"

struct global my,check;
int open;
int jumpcount,returntype,returnpointer;
char returnchar[100];
int Totalerrors,funcount;
struct allFunc **ALL;
struct structure
{
	char in[100];
	int s;
}maxi[100];
%}

// 终结符的定义
%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN 
%token IF ELSE WHILE FOR CONTINUE BREAK RETURN
%token READ PRINT
%token CHAR INT FLOAT VOID
%token STRUCT MIN MAX SWAP

// 定义program为开始符号，所有推导从它开始
%start program

// 语义值类型定义为一个联合，包括2种可能用到的类型
%union{
        struct AST *node;	// 非终结符语义值类型

        struct terminal{	// 终结符语义值类型
                        char *text;
                        int type;
                        int line;
        } Sval;

}

// 终结符语义值的类型说明
%type <Sval> IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%type <Sval> PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%type <Sval> AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%type <Sval> SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%type <Sval> XOR_ASSIGN OR_ASSIGN
%type <Sval> IF ELSE WHILE FOR CONTINUE BREAK RETURN
%type <Sval> READ PRINT
%type <Sval> CHAR INT FLOAT VOID
%type <Sval> STRUCT MIN MAX SWAP

// 非终结符语义值的类型说明
%type <node> var 
%type <node> arg_var
%type <node> variables
%type <node> struct_var
%type <node> type
%type <node> inside_dec 
%type <node> struct_declaration
%type <node> struct_list 
%type <node> struct 
%type <node> declaration 
%type <node> argument_list
%type <node> read
%type <node> print
%type <node> myfunction
%type <node> statement
%type <node> iteration_statement
%type <node> selection_statement
%type <node> jump_statement
%type <node> ass_operator
%type <node> expression_statement
%type <node> arg_list
%type <node> starting
%type <node> main_exp
%type <node> unary_op
%type <node> unary_exp
%type <node> mul_div_mod
%type <node> plus_minus
%type <node> shift
%type <node> lt_gt_lte_gte
%type <node> eq_neq
%type <node> and
%type <node> xor 
%type <node> or
%type <node> andand
%type <node> oror
%type <node> conditional_exp
%type <node> expression
%type <node> statement_list
%type <node> body
%type <node> function
%type <node> program
%type <node> function_name
%type <node> openB
%type <node> closeB
%type <node> istart
%type <node> iend max min swap

// 语法规则部分，产生式的语义动作是生成抽象语法树
%%
var 
	: IDENTIFIER				{$$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);
								$$->array = 0;
								}	
	| IDENTIFIER '[' CONSTANT ']'	
								{$$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);
								$$->array = 1; $$->dim1 = atoi($3.text);
								}
	| IDENTIFIER '[' CONSTANT ']' '[' CONSTANT ']'
								{$$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);
								$$->array = 2; $$->dim1 = atoi($3.text); $$->dim2 = atoi($6.text);
							}
	;

variables
	: var 						{
									$$ = $1; $$->pointer = 0;
								}
	| '*' var 					{
									$$ = $2; $$->pointer = 1;
								}
	| variables ',' var        {
									$$ = MakeNode(2); $$->type = 100; strcpy($$->lexeme,",");
									$$->child[0] = $1; $1->parent = $$; 
									$$->child[1] = $3; $3->parent = $$;  $3->pointer = 0; 
							   }
	| variables ',' '*' var 	{
									$$ = MakeNode(2); $$->type = 100; strcpy($$->lexeme,",");
									$$->child[0] = $1; $1->parent = $$; 
									$$->child[1] = $4; $4->parent = $$;  $4->pointer = 1;
							   }
	;

type
        : INT 			{$$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);}
      //  | FLOAT			{$$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);}
        | CHAR     		{$$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);}
        | VOID			{$$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);}
        ;

arg_var
	: IDENTIFIER 		{
							$$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);
							$$->array = 0; $$->pointer = 0;
						}
	| '*' IDENTIFIER    {
							$$ = MakeNode(0); $$->type = $2.type; strcpy($$->lexeme,$2.text);
							$$->array = 0; $$->pointer = 1;
						}
   /*     | IDENTIFIER '[' ']'
        				{
							$$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);
							$$->array = 111; $$->pointer = 0;
						}
	| '*' IDENTIFIER '[' CONSTANT ']' 
						{

							$$ = MakeNode(0); $$->type = $2.type; strcpy($$->lexeme,$2.text);
							$$->array = 222; $$->pointer = 0; $$->dim2 = atoi($4.text);
						}
        | IDENTIFIER '[' ']' '[' CONSTANT ']'
        				{
							$$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);
							$$->array = 222; $$->pointer = 0; $$->dim2 = atoi($5.text);
						}
     */
        ;

struct_var
	: IDENTIFIER
						{
							$$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);
							$$->array = 0; $$->pointer = 0;
						}
	| IDENTIFIER '[' CONSTANT ']'
						{
							$$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);
							$$->array = 1; $$->dim1 = atoi($3.text);
							$$->pointer = 0;
						}
	| struct_var ',' IDENTIFIER
						{
							$$ = MakeNode(2); $$->type = 100; strcpy($$->lexeme,",");
							$$->child[1] = MakeNode(0); $$->child[1]->type = $3.type; strcpy($$->child[1]->lexeme,$3.text);
							$$->child[1]->parent = $$;
							$$->child[1]->array = 0; $$->child[1]->pointer = 0;
							$$->child[0] = $1;
							$1->parent = $$;	
						}
	| struct_var ',' IDENTIFIER '[' CONSTANT ']'
						{
							$$ = MakeNode(2); $$->type = 100; strcpy($$->lexeme,",");
							$$->child[1] = MakeNode(0); $$->child[1]->type = $3.type; strcpy($$->child[1]->lexeme,$3.text);
							$$->child[1]->parent = $$;
							$$->child[1]->array = 1; $$->child[1]->pointer = 0;
							$$->child[1]->dim1 = atoi($5.text);
							$$->child[0] = $1;
							$1->parent = $$;

						}
	;

inside_dec 
	: IDENTIFIER					{$$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);
									$$->array = 0; $$->pointer = 0;
									}
	| inside_dec ',' IDENTIFIER     {
									$$ = MakeNode(2); $$->type = 100; strcpy($$->lexeme,",");
									$$->child[0] = $1; $1->parent = $$; 
									$$->child[1] = MakeNode(0); $$->child[1]->type = $3.type; strcpy($$->child[1]->lexeme,$3.text);
									$$->child[1]->array=0; $$->child[1]->pointer=0;  
								   }
	;
struct_declaration 
	: type inside_dec ';' 			{
										$$ = MakeNode(2); $$->type = 100; strcpy($$->lexeme,";");
										$$->child[0] = $1; $1->parent = $$;
										$$->child[1] = $2; $2->parent = $$;
									} 			
	;

struct_list 
	: struct_declaration  			{$$ = $1;
									}
	| struct_list struct_declaration 
									{
										$$ = MakeNode(2); $$->type = 100; strcpy($$->lexeme,"#"); 
										$$->child[0] = $1; $1->parent = $$;
										$$->child[1] = $2; $2->parent = $$;
									} 
	;
struct 
	: STRUCT IDENTIFIER '{' struct_list '}' 
								{
									strcpy(maxi[init_count].in,$2.text);
									$$ = MakeNode(0); $$->type = $2.type; strcpy($$->lexeme,$2.text);
									my.type = 6;
									
									AddSymbol($2.text,my,currentT);
									
									//AST_print($4);
									my.struct_member = 1;
									strcpy(my.structName,$2.text);
									order=0;
									addVar(my,$4,currentT);
									$$->order = order;
									check.array = 6; check.struct_member = 0; 
									maxi[init_count].s=order;
									init_count++;
								//	struct symbolTable *temp = FindSymbol($2.text,check,currentT);
								//	temp->order = $$->order;
								}
	; 

declaration 
	: type variables ';' 	{
								my.type = $1->type; my.struct_member = 0; addVar(my,$2,currentT);
							}
	| struct ';' 			
							{

							}
	| STRUCT IDENTIFIER struct_var ';' 
								{
									int aman=0;
									for(;aman<init_count;aman++){
										if(strcmp(maxi[aman].in,$2.text)==0)	break;
									}
									if(aman==init_count){
											printf("Kat Gaya\n");
									}
									else{
										my.order=maxi[aman].s;
									}
									my.struct_member=0;
									strcpy(my.structID,$2.text);
									/*check.array = 6; check.struct_member = 0; 
									struct symbolTable *temp = FindSymbol($2.text,check,currentT);
									if(temp == NULL){
										printf("struct %s not found\n",$2.text );
										Totalerrors++;
									}else{
										my.order = temp->order;
									}*/
									my.type = 5;
									addVar(my,$3,currentT);
								} 
	| struct struct_var ';' 
							{
									my.struct_member=0;
									strcpy(my.structID,$1->lexeme);
									my.type = 5;
									my.order = $1->order;
									addVar(my,$2,currentT);
							}
	;
argument_list					// to be modified
	: argument_list ',' type arg_var  
							{
								currentT->parent->t->array  = 4;	
								$$ = MakeNode(2); $$->type = 100; strcpy($$->lexeme,",");
								$$->child[0] = $1; $1->parent = $$;
								$$->child[1] = $3; $3->parent = $$;

								// add arg_var to symboltable
								my.type = $3->type; my.struct_member = 0;
								addVar(my,$4,currentT);

							}
	| type arg_var			{ 
								currentT->parent->t->array  = 4;
								$$ = $1;

								my.type = $1->type; my.struct_member = 0;
								addVar(my,$2,currentT);

							}
	| argument_list ',' STRUCT IDENTIFIER IDENTIFIER 
							{
								currentT->parent->t->array  = 4;
								$$ = MakeNode(2); $$->type = 100; strcpy($$->lexeme,",");
								$$->child[0] = $1; $1->parent = $$;
								$$->child[1] = MakeNode(0); $$->child[1]->parent = $$;
								$$->child[1]->type = $4.type;
								strcpy($$->child[1]->lexeme,$4.text);	
								$$->child[1]->array = 60;	

								my.type = 5; strcpy(my.structID,$4.text); my.struct_member = 0;
								AddSymbol($5.text,my,currentT);
							}
	//| STRUCT IDENTIFIER arg_var
	;

read
	: READ '(' type ',' IDENTIFIER ')'	
							{
								$$ = MakeNode(2); $$->type = 4; strcpy($$->lexeme,$1.text);
								$$->child[0] = $3; $3->parent = $$;
								$$->child[1] = MakeNode(0); strcpy($$->child[1]->lexeme,$5.text);
								$$->child[1]->type = $5.type;
								$$->child[1]->parent = $$;

								check.array = 0; check.struct_member = 0; 
								struct symbolTable *temp = FindSymbol($5.text,check,currentT);
								if(temp==NULL) printf("not found %s\n",$5.text);
								else if(temp->type != $3->type) printf("READ type mismatch\n");
								$$->child[1]->where = temp;

							}


print
        : PRINT '(' type ',' IDENTIFIER ')'
        					{
								$$ = MakeNode(2); $$->type = 4; strcpy($$->lexeme,$1.text);
								$$->child[0] = $3; $3->parent = $$;
								$$->child[1] = MakeNode(0); strcpy($$->child[1]->lexeme,$5.text);
								$$->child[1]->type = $5.type;
								$$->child[1]->parent = $$;

								check.array = 0; check.struct_member = 0; 
								struct symbolTable *temp = FindSymbol($5.text,check,currentT);
								if(temp==NULL) printf("not found %s\n",$5.text);	
								else if(temp->type != $3->type) printf("PRINT type mismatch\n");
								$$->child[1]->where = temp;
							}
max 
		: MAX '(' IDENTIFIER ',' IDENTIFIER ')'
							{
								$$ = MakeNode(2); $$->type = $3.type; strcpy($$->lexeme,$1.text);
								$$->child[0] = MakeNode(0); strcpy($$->child[0]->lexeme,$3.text);
								$$->child[1] = MakeNode(0); strcpy($$->child[1]->lexeme,$5.text);
								
								$$->child[1]->type = $5.type;
								$$->child[1]->parent = $$;
								$$->child[0]->type = $3.type;
								$$->child[0]->parent = $$;

								if($3.type != $5.type){
									printf("max type error");
									Totalerrors++;
								}

								struct symbolTable *temp = FindSymbol($3.text,check,currentT);
								if(temp==NULL) printf("not found %s\n",$3.text);	
								$$->child[0]->where = temp;

								temp = FindSymbol($5.text,check,currentT);
								if(temp==NULL) printf("not found %s\n",$5.text);	
								$$->child[1]->where = temp;

								$$->type = temp->type;

							}

min 
		: MIN '(' IDENTIFIER ',' IDENTIFIER ')'
							{
								$$ = MakeNode(2); $$->type = $3.type; strcpy($$->lexeme,$1.text);
								$$->child[0] = MakeNode(0); strcpy($$->child[0]->lexeme,$3.text);
								$$->child[1] = MakeNode(0); strcpy($$->child[1]->lexeme,$5.text);
								
								$$->child[1]->type = $5.type;
								$$->child[1]->parent = $$;
								$$->child[0]->type = $3.type;
								$$->child[0]->parent = $$;

								if($3.type != $5.type){
									printf("min type error");
									Totalerrors++;
								}

								struct symbolTable *temp = FindSymbol($3.text,check,currentT);
								if(temp==NULL) printf("not found %s\n",$3.text);	
								$$->child[0]->where = temp;

								temp = FindSymbol($5.text,check,currentT);
								if(temp==NULL) printf("not found %s\n",$5.text);	
								$$->child[1]->where = temp;

								$$->type = temp->type;
							}	

swap 
		: SWAP '(' IDENTIFIER ',' IDENTIFIER ')'
							{
								$$ = MakeNode(2); $$->type = $3.type; strcpy($$->lexeme,$1.text);
								$$->child[0] = MakeNode(0); strcpy($$->child[0]->lexeme,$3.text);
								$$->child[1] = MakeNode(0); strcpy($$->child[1]->lexeme,$5.text);
								
								$$->child[1]->type = $5.type;
								$$->child[1]->parent = $$;
								$$->child[0]->type = $3.type;
								$$->child[0]->parent = $$;

								if($3.type != $5.type){
									printf("swap type error");
									Totalerrors++;
								}

								struct symbolTable *temp = FindSymbol($3.text,check,currentT);
								if(temp==NULL) printf("not found %s\n",$3.text);	
								$$->child[0]->where = temp;

								temp = FindSymbol($5.text,check,currentT);
								if(temp==NULL) printf("not found %s\n",$5.text);	
								$$->child[1]->where = temp;

								$$->type = temp->type;

							}

	;

myfunction
	: read ';'			
					{
						$$ = $1;
					}
	| print ';'		{
						$$ = $1;
					}
	|swap ';'		{
						$$ = $1;
					}
	;
statement
        : body  			{$$ = $1;}
        | jump_statement   	{$$ = $1;}
		| iteration_statement   {$$ = $1;}
		| selection_statement    {$$ = $1;}
		| expression_statement   {$$ = $1;}
		| declaration     		{$$=MakeNode(0); $$->type = -1;strcpy($$->lexeme,"dec");}
		| myfunction 		{$$ = $1;}	 
        ;
istart
		:	'{'		{
						jumpcount++;
						currentT = EnterScope(currentT);
					}
iend
		:	'}'		{
						currentT = ExitScope(currentT);
					//	$$ = MakeNode(0); $$->type = 100; strcpy($$->lexeme,"}");
						jumpcount--;
						
					}

iteration_statement
        : WHILE '(' expression ')' istart statement_list iend
      					{
      						$$ = MakeNode(2); $$->type = $1.type; strcpy($$->lexeme,$1.text);
      						$$->child[0] = $3; $3->parent = $$; 
      						$$->child[1] = $6; $6->parent = $$;
      					//	$$->child[2] = $7; $7->parent = $$;
      						$$->array = 10;			

      						$$->scope = $6->scope;
      						$$->scopenode = $6->scopenode;
      						propagate($3,$6->scope,$6->scopenode);	
      					}
        | FOR '(' expression_statement expression_statement ')' istart statement_list iend
        				{
      						$$ = MakeNode(3); $$->type = $1.type; strcpy($$->lexeme,$1.text);
      						$$->child[0] = $3; $3->parent = $$; 
      						$$->child[1] = $4; $4->parent = $$;
      						$$->child[2] = $7; $7->parent = $$;
      					//	$$->child[3] = $8; $8->parent = $$;
      						$$->array = 11;				
      					
      						$$->scope  = $7->scope;
      						$$->scopenode = $7->scopenode;
      						propagate($3,$7->scope,$7->scopenode);
      						propagate($4,$7->scope,$7->scopenode);

      					}
        | FOR '(' expression_statement expression_statement expression ')' istart statement_list iend
        				{
      						$$ = MakeNode(4); $$->type = $1.type; strcpy($$->lexeme,$1.text);
      						$$->child[0] = $3; $3->parent = $$; 
      						$$->child[1] = $4; $4->parent = $$;
      						$$->child[2] = $5; $5->parent = $$;
      						$$->child[3] = $8; $8->parent = $$;
      				//		$$->child[4] = $9; $9->parent = $$;
      						$$->array = 12;				

      						$$->scope = $8->scope;
      						$$->scopenode = $8->scopenode;
      						
      						propagate($3,$8->scope,$8->scopenode);
      						propagate($4,$8->scope,$8->scopenode);
      						propagate($5,$8->scope,$8->scopenode);
      					}
        ;
selection_statement
        : IF '(' expression ')' body
        				{
      						$$ = MakeNode(2); $$->type = $1.type; strcpy($$->lexeme,$1.text);
      						$$->child[0] = $3; $3->parent = $$; 
      						$$->child[1] = $5; $5->parent = $$;
      						$$->array = 15;				
      					}
        | IF '(' expression ')' body ELSE statement

        				{
      						$$ = MakeNode(3); $$->type = $1.type; strcpy($$->lexeme,$1.text);
      						$$->child[0] = $3; $3->parent = $$; 
      						$$->child[1] = $5; $5->parent = $$;
      						$$->child[2] = $7; $7->parent = $$;
      						$$->array = 16;				
      					}
	;

jump_statement
        : CONTINUE ';'				{ $$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);
        								if(jumpcount<=0){
        									printf("CONTINUE without iteration_statement\n");
        									Totalerrors++;
        								}	
        							}		
        | BREAK ';' 				{ $$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);
        								if(jumpcount<=0){
        									printf("BREAK without iteration_statement\n");
        									Totalerrors++;
        								}
        							}
        | RETURN ';' 				{ $$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);

        								if(returntype != VOID ){
        									printf("Invalid Return type\n");
        									Totalerrors++;
        								}	
        							}
        | RETURN expression ';'      { $$ = MakeNode(1); $$->type = $1.type; strcpy($$->lexeme,$1.text);
        								$$->child[0] = $2; $2->parent = $$;

        								if(returntype != $2->type){
        									printf("Invalid Return type\n");
        									Totalerrors++;
        								}
        							}
        ;


ass_operator
        : '='         	{ $$ = MakeNode(2); $$->type = 100; strcpy($$->lexeme,"=");}
        | MUL_ASSIGN   	{ $$ = MakeNode(2); $$->type = $1.type; strcpy($$->lexeme,$1.text);}
        | DIV_ASSIGN	{ $$ = MakeNode(2); $$->type = $1.type; strcpy($$->lexeme,$1.text);}
        | MOD_ASSIGN	{ $$ = MakeNode(2); $$->type = $1.type; strcpy($$->lexeme,$1.text);}
        | ADD_ASSIGN	{ $$ = MakeNode(2); $$->type = $1.type; strcpy($$->lexeme,$1.text);}
        | SUB_ASSIGN	{ $$ = MakeNode(2); $$->type = $1.type; strcpy($$->lexeme,$1.text);}
        | LEFT_ASSIGN	{ $$ = MakeNode(2); $$->type = $1.type; strcpy($$->lexeme,$1.text);}
        | RIGHT_ASSIGN	{ $$ = MakeNode(2); $$->type = $1.type; strcpy($$->lexeme,$1.text);}
        | AND_ASSIGN	{ $$ = MakeNode(2); $$->type = $1.type; strcpy($$->lexeme,$1.text);}
        | XOR_ASSIGN	{ $$ = MakeNode(2); $$->type = $1.type; strcpy($$->lexeme,$1.text);}
        | OR_ASSIGN		{ $$ = MakeNode(2); $$->type = $1.type; strcpy($$->lexeme,$1.text);}
        ;


expression_statement
        : ';'					{$$ = MakeNode(0); $$->type = 100; strcpy($$->lexeme,";");}
        | expression ';'		{$$ = $1;}
        ;
arg_list
	: expression				{$$=$1;}
	| arg_list ',' expression 		{$$ = MakeNode(2); $$->type = 100; strcpy($$->lexeme,",");
									 $$->child[0] = $1; $1->parent = $$;
									 $$->child[1] = $3; $3->parent = $$;}
	;

starting
        : IDENTIFIER 				{$$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);

        								check.array = 0; check.struct_member = 0; 
        								//printf("parser :: %s %d\n",$1.text,$1.type);
        								struct symbolTable *temp = FindSymbol($1.text,check,currentT);
        								if(temp==NULL) printf("not found %s\n",$1.text);
        								else{
        										$$->type = temp->type;
        										$$->pointer = temp->pointer;
        									}
        								$$->array = 300;	
        								$$->where = temp;
        								$$->lval = 1;


        							}
        | CONSTANT 					{$$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);

        								$$->type = $1.type;
        								$$->pointer = 0;
        								$$->lval = 0;
        								$$->array  = 200;
        							}
        | STRING_LITERAL 			{$$ = MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);

        								// not sure
        								$$->lval = 0;
        								$$->pointer = 0;
        							}
        | '(' expression ')'        {$$ = $2;

        								//$$->type = $2->type;
        							}
       	| max 			{
							$$ = $1;
						}
	    | min 			{
							$$ = $1;
						}
		
        ;
main_exp
	: starting 							{$$=$1;}
	| IDENTIFIER '['expression']' 		{$$=MakeNode(1); $$->type = $1.type; strcpy($$->lexeme,$1.text);
										  $$->child[0] = $3; $3->parent = $$; $$->array=1;

										  check.array = 1; check.struct_member = 0;
										  struct symbolTable *temp = FindSymbol($1.text,check,currentT);
        								  if(temp==NULL) printf("not found %s\n",$1.text);
        								  else{
	        								  if($3->type != INT){
	        								  	printf("Array index must be integer\n");
	        								  	Totalerrors++;
	        								  }
	        								  else
	        								  	$$->type = temp->type;
	        								  	$$->pointer = temp->pointer;
        									}
        									$$->array = 301;
        									$$->where = temp;
        									$$->lval = 1;	
										}
	| IDENTIFIER '['expression']' '['expression']'  {$$=MakeNode(2); $$->type = $1.type; strcpy($$->lexeme,$1.text);
										  			$$->child[0] = $3; $3->parent = $$; 
										  			$$->child[1] = $6; $6->parent = $$; $$->array=2;
										  			
										  			check.array = 2; check.struct_member = 0;
										  			struct symbolTable *temp = FindSymbol($1.text,check,currentT);
        											if(temp==NULL) printf("not found %s\n",$1.text);
        											else{
        											if($3->type != INT || $6->type != INT){
			        								  	printf("Array index must be integer\n");
			        								  	Totalerrors++;
			        								  }
			        								  else
			        								  	$$->type = temp->type;
			        								  $$->pointer = temp->pointer;
			        								}
			        								$$->array = 302;
			        								$$->where = temp;
			        								$$->lval = 1;
										  		}
	| IDENTIFIER '(' ')' 				{$$=MakeNode(0); $$->type = $1.type; strcpy($$->lexeme,$1.text);
										 $$->array = 3;

										 	check.array = 3; check.struct_member = 0;
										 	struct symbolTable *temp = FindSymbol($1.text,check,currentT);
        									if(temp==NULL) printf("not found %s\n",$1.text);
        									else{
        										$$->type = temp->type;
        										$$->pointer = temp->pointer;
        									}
        									$$->where = temp;
        									$$->lval = 0;
										}
	| IDENTIFIER '(' arg_list ')'  		{$$=MakeNode(1); $$->type = $1.type; strcpy($$->lexeme,$1.text);
										 $$->array = 4; $$->child[0]= $3; $3->parent = $$;

										 check.array = 4; check.struct_member = 0;
										 struct symbolTable *temp = FindSymbol($1.text,check,currentT);
        								 if(temp==NULL) printf("not found %s\n",$1.text);

        								 else{
        										$$->type = temp->type;
        										$$->pointer = temp->pointer;
        									}
        									// check definition of function 
        									$$->where = temp;
        									$$->lval = 0;
							if(check_arg($1.text,$3)){
								printf("Argument type does not match\n");
							}	///calling parameter
										}

	| IDENTIFIER '.' IDENTIFIER  		{$$ = MakeNode(2); $$->type=100; strcpy($$->lexeme,".") ;
										 $$->child[0]=MakeNode(0); $$->child[0]->type = $1.type; $$->child[0]->parent = $$; 
										 $$->child[1]=MakeNode(0); $$->child[1]->type = $3.type; $$->child[1]->parent = $$;
										 strcpy($$->child[0]->lexeme,$1.text);strcpy($$->child[1]->lexeme,$3.text);


										 check.array = 0; check.struct_member = 0; 
										 struct symbolTable *temp = FindSymbol($1.text,check,currentT);
        								 if(temp==NULL )
        								 	 printf("not found %s\n",$1.text);
        								 else if(temp->type != 5){	
        								 	 printf("not found %s\n",$1.text);
        								 	 Totalerrors++;
        								 	}
        								 else {
        								 	$$->child[0]->where = temp;
        								 	char s[100];
        								 	check.array = 0; check.struct_member = 1; 
        								 	strcpy(s,"."); strcat(s,$3.text);
        								 	strcpy(check.structName,temp->structID);
        								 	temp = FindSymbol(s,check,currentT);
        								 	if(temp==NULL) printf("not found %s\n",s);
        								 	else{
        										$$->type = temp->type;
        										$$->pointer = temp->pointer;
        									}
        									$$->child[1]->where = temp;

        								 }
        								 $$->array = 303;
        								 $$->lval = 1;

										}
										 
	| IDENTIFIER '[' expression ']' '.' IDENTIFIER  { $$ = MakeNode(2); $$->type=100; strcpy($$->lexeme,".");
													 $$->child[0]=MakeNode(1); $$->child[1]=MakeNode(0);
													 $$->child[0]->parent = $$; $$->child[1]->parent = $$;
													 $$->child[1]->type = $6.type; strcpy($$->child[1]->lexeme,$6.text);
													 $$->child[0]->type = $1.type; strcpy($$->child[0]->lexeme,$1.text);
													 $$->child[0]->child[0] = $3; $3->parent = $$->child[0];
													 $$->child[0]->array = 1;

													 check.array = 1; check.struct_member = 0; 
													 struct symbolTable *temp = FindSymbol($1.text,check,currentT);
			        								 if(temp==NULL )
			        								 	 printf("not found %s\n",$1.text);
			        								 else if(temp->type != 5)	{
			        								 	 printf("not found %s\n",$1.text);
			        								 	 Totalerrors++;
			        								 }
			        								 else{
			        								 	$$->child[0]->where = temp;
			        								 	char s[100];
			        								 	check.array = 0; check.struct_member = 1; 
			        								 	strcpy(s,"."); strcat(s,$6.text);
			        								 	strcpy(check.structName,temp->structID);
			        								 	temp = FindSymbol(s,check,currentT);
			        								 	if(temp==NULL) printf("not found %s\n",$1.text);
			        								 	else if($3->type == INT){
			        										$$->type = temp->type;
			        										$$->pointer = temp->pointer;
			        									}
			        									else{
			        										printf("Array index must be integer\n");
			        										Totalerrors++;
			        									}
			        									$$->child[1]->where = temp;
			        								 }
			        								 $$->array = 304;
			        								 $$->lval = 1;
													}
	;
unary_op
	: '+' 					{$$=MakeNode(0); $$->type=100; strcpy($$->lexeme,"+"); }
	| '-' 					{$$=MakeNode(0); $$->type=100; strcpy($$->lexeme,"-"); }
	| '!' 					{$$=MakeNode(0); $$->type=100; strcpy($$->lexeme,"!"); }
	| '~' 					{$$=MakeNode(0); $$->type=100; strcpy($$->lexeme,"~"); }
	| '*' 					{$$=MakeNode(0); $$->type=100; strcpy($$->lexeme,"*"); }
	| '&'    				{$$=MakeNode(0); $$->type=100; strcpy($$->lexeme,"&"); }
	;
unary_exp
	: main_exp  			{$$=$1;}
	| unary_op unary_exp 	{$$=MakeNode(1); $$->type = $1->type;	strcpy($$->lexeme,$1->lexeme);
							 $$->child[0]=$2; $2->parent = $$; 
							 
							 	$$->lval = 0;
							 	if(strcmp($1->lexeme,"+")==0 ||strcmp($1->lexeme,"-")==0||strcmp($1->lexeme,"!")==0)
							 		$$->type = $2->type;
							 	else if(strcmp($1->lexeme,"~")==0 && $2->type == INT)
							 		$$->type = INT;
							 	else if(strcmp($1->lexeme,"*")==0 && $2->pointer == 1){
							 		$$->type = $2->type;
							 		if($2->lval == 1)
							 			$$->lval = 1;
							 	}
							 	else if(strcmp($1->lexeme,"&")==0 && $2->lval==1){ // to be modified
							 		$$->type = $2->type;
							 		$$->pointer = 1;
							 	}	
							 	else{
							 		printf("Invalid operands for %s\n",$1->lexeme);	
							 		Totalerrors++;
							 	}

							 	}
	| SIZEOF '(' type ')'   {$$=MakeNode(1); $$->type = $1.type;	strcpy($$->lexeme,$1.text);
							 $$->child[0]=$3; $3->parent = $$;

							 	$$->type = INT;
							 	$$->lval = 0;
							 	}
	;
mul_div_mod
	: unary_exp					{$$=$1;}
	| mul_div_mod '*' unary_exp  {$$=MakeNode(2); $$->type = 100;	strcpy($$->lexeme,"*");
							 $$->child[0]=$1; $1->parent = $$;
							 $$->child[1]=$3; $3->parent = $$;

							 if(($1->type != $3->type)){
							 			printf("Invalid operands for *\n");
							 			Totalerrors++;
							 	}		
					 		else	
							$$->type = $1->type;

							 	}
	| mul_div_mod '/' unary_exp	{$$=MakeNode(2); $$->type = 100;	strcpy($$->lexeme,"/");
							 $$->child[0]=$1; $1->parent = $$;
							 $$->child[1]=$3; $3->parent = $$;

									if(($1->type != $3->type)){
							 			printf("Invalid operands for /\n");
										Totalerrors++;
									}
							 		else	
									$$->type = $1->type;					 


							 	}
	| mul_div_mod '%' unary_exp  {$$=MakeNode(2); $$->type = 100;	strcpy($$->lexeme,"%");
							 $$->child[0]=$1; $1->parent = $$;
							 $$->child[1]=$3; $3->parent = $$;	

							 if(($1->type != INT || $3->type != INT)){
						 		printf("Invalid operands for modulus");
						 		Totalerrors++;
							 }else{
							 	$$->type = $1->type;
							 }
							}
	;
plus_minus
	: mul_div_mod  				{$$=$1;}
	| plus_minus '+' mul_div_mod  {$$=MakeNode(2); $$->type = 100;	strcpy($$->lexeme,"+");
							 $$->child[0]=$1; $1->parent = $$;
							 $$->child[1]=$3; $3->parent = $$;	

							 if($1->type != $3->type)	{
							 			printf("Invalid operands for +\n");
							 			Totalerrors++;
							 		}	
							 		else	
									$$->type = $1->type;

							}
	| plus_minus '-' mul_div_mod  {$$=MakeNode(2); $$->type = 100;	strcpy($$->lexeme,"-");
							 $$->child[0]=$1; $1->parent = $$;
							 $$->child[1]=$3; $3->parent = $$;	

							 if($1->type != $3->type){
							 			Totalerrors++;
							 			printf("Invalid operands for -\n");
							 		}	
							 		else	
									$$->type = $1->type;


							}
	;
shift
	: plus_minus				{$$=$1;}
	| shift LEFT_OP plus_minus     {$$=MakeNode(2); $$->type = $2.type;	strcpy($$->lexeme,$2.text);
							 $$->child[0]=$1; $1->parent = $$;
							 $$->child[1]=$3; $3->parent = $$;

								  if($3->type != INT || $1->type != INT ){
								 	printf("Invalid operands for %s\n",$2.text);
								 	Totalerrors++;
								 }else{
								 	$$->type = INT;
								 }
							 	}
	| shift RIGHT_OP plus_minus		{$$=MakeNode(2); $$->type = $2.type;	strcpy($$->lexeme,$2.text);
							 $$->child[0]=$1; $1->parent = $$;
							 $$->child[1]=$3; $3->parent = $$;	


							 if($3->type != INT  || $1->type != INT){
							 	printf("Invalid operands for %s\n",$2.text);
							 	Totalerrors++;
							 }else{
							 	$$->type = INT;
							 }
							}
	;
	
lt_gt_lte_gte
	: shift     				{$$=$1;}
	| lt_gt_lte_gte '<' shift   {$$=MakeNode(2); $$->type = 100;	strcpy($$->lexeme,"<");
							 $$->child[0]=$1; $1->parent = $$;
							 $$->child[1]=$3; $3->parent = $$;


							 if($1->type != $3->type){
							 			printf("Invalid operands for <\n");
							 			Totalerrors++;
							 		}
							 		else	
									$$->type = INT;

							 	}
	| lt_gt_lte_gte '>' shift   {$$=MakeNode(2); $$->type = 100;	strcpy($$->lexeme,">");
							 $$->child[0]=$1; $1->parent = $$;
							 $$->child[1]=$3; $3->parent = $$;

							 if($1->type != $3->type){
							 			printf("Invalid operands for >\n");
							 		Totalerrors++;
							 		}
							 		else	
									$$->type = INT;

							 }

							 	
	| lt_gt_lte_gte LE_OP shift  {$$=MakeNode(2); $$->type = $2.type;	strcpy($$->lexeme,$2.text);
							 $$->child[0]=$1; $1->parent = $$;
							 $$->child[1]=$3; $3->parent = $$;

							 if($1->type != $3->type){
							 			printf("Invalid operands for %s\n",$2.text);
							 		Totalerrors++;
							 	}
							 		else	
									$$->type = INT;

							 	}
	| lt_gt_lte_gte GE_OP shift  {$$=MakeNode(2); $$->type = $2.type;	strcpy($$->lexeme,$2.text);
							 $$->child[0]=$1; $1->parent = $$;
							 $$->child[1]=$3; $3->parent = $$;	

							 if($1->type != $3->type){
							 			printf("Invalid operands for %s\n",$2.text);
							 			Totalerrors++;
							 		}
							 		else	
									$$->type = INT;

							}
	;
	
eq_neq
	: lt_gt_lte_gte 				{$$ = $1;}
	| eq_neq EQ_OP lt_gt_lte_gte 	
							{$$=MakeNode(2); $$->type = $2.type;	strcpy($$->lexeme,$2.text);
							 $$->child[0]=$1; $1->parent = $$;
							 $$->child[1]=$3; $3->parent = $$;

							 	if($1->type != $3->type){
							 			printf("Invalid operands for %s\n",$2.text);
							 			Totalerrors++;
							 		}
							 		else	
									$$->type = INT;

							 	}
	| eq_neq NE_OP	lt_gt_lte_gte 
								 {$$=MakeNode(2); $$->type = $2.type;	strcpy($$->lexeme,$2.text);
							 		$$->child[0]=$1; $1->parent = $$;
							 		$$->child[1]=$3; $3->parent = $$;	

							 		if($1->type != $3->type){
							 			printf("Invalid operands for %s\n",$2.text);
							 			Totalerrors++;
							 		}
							 		else	
									$$->type = INT;
									 
							 	}
	;
and
	: eq_neq 				{$$ = $1;}
	| and '&' eq_neq 		{$$=MakeNode(2); $$->type = 100;	strcpy($$->lexeme,"&");
							 $$->child[0]=$1; $1->parent = $$;
							 $$->child[1]=$3; $3->parent = $$;	

							 if($1->type != INT || $3->type != INT){
							 	printf("Invalid operands for &\n");
							 	Totalerrors++;
							 }else{
							 	$$->type = INT;
							 }


							}
	;
xor 
	: and 					{$$ = $1;}
	| xor '^' and  			{$$=MakeNode(2); $$->type = 100;	strcpy($$->lexeme,"^");
							 $$->child[0]=$1; $1->parent = $$;
							 $$->child[1]=$3; $3->parent = $$;


							 if($1->type != INT || $3->type != INT){
							 	printf("Invalid operands for ^\n");
							 	Totalerrors++;
							 }else{
							 	$$->type = INT;
							 }

							 }
	;
or
	: xor 					{$$ = $1;}
	| or '|' xor 			{$$=MakeNode(2); $$->type = 100;	strcpy($$->lexeme,"|");
							 $$->child[0]=$1; $1->parent = $$;
							 $$->child[1]=$3; $3->parent = $$;	

							 if($1->type != INT || $3->type != INT){
							 	printf("Invalid operands for |\n");
							 	Totalerrors++;
							 }else{
							 	$$->type = INT;
							 }

							}
	;
andand
	: or 					{$$ = $1;}
	| andand AND_OP or 		{$$=MakeNode(2); $$->type = $2.type;	strcpy($$->lexeme,$2.text);
							 $$->child[0]=$1; $1->parent = $$;
							 $$->child[1]=$3; $3->parent = $$;

							 if($1->type != INT || $3->type != INT){
							 	printf("Invalid operands for %s\n",$2.text);
							 	Totalerrors++;
							 }else{
							 	$$->type = INT;
							 }

							 }
	;
oror
	: andand				{$$ = $1;}
	| oror OR_OP andand		{$$=MakeNode(2); $$->type = $2.type;	strcpy($$->lexeme,$2.text);
							 $$->child[0]=$1; $1->parent = $$;
							 $$->child[1]=$3; $3->parent = $$;	

							 if($1->type != INT || $3->type != INT){
							 	printf("Invalid operands for %s\n",$2.text);
							 	Totalerrors++;
							 }else{
							 	$$->type = INT;
							 }

							}
	;

conditional_exp
        : oror 		{$$ = $1;}
        ;
expression
	: conditional_exp						{$$=$1;}
	| unary_exp ass_operator expression 	{ $$ = $2; $$->child[0] = $1; $1->parent = $$;
											 $$->child[1] = $3; $3->parent = $$;

											 if($1->lval != 1){
											 	printf("Not an Lvalue Expression\n");
											 	Totalerrors++;
											 }else{
												if($2->type==100 || $2->type == MUL_ASSIGN || $2->type == DIV_ASSIGN || $2->type == ADD_ASSIGN || $2->type == SUB_ASSIGN){
													if($1->type != $3->type){
														printf("Invalid Operand for %s\n",$2->lexeme);
														Totalerrors++;
														//printf("= %d %d",$1->type,$3->type);
													}
													else
														$$->type = $1->type;
												}else{

													if($1->type!=INT || $3->type!=INT){
														printf("Invalid Operand for %s\n",$2->lexeme);
														Totalerrors++;
													}
													else
														$$->type = $1->type;
												} 

											}
											$$->lval = 0;
											}
	;
statement_list
	: statement   					{$$=$1;}
	| statement_list statement      
							{ $$ = MakeNode(2); $$->type =101; strcpy($$->lexeme,";");
							  $$->child[0] = $1; if($1 != NULL) $1->parent = $$;
							  $$->child[1] = $2;  if($2 != NULL) $2->parent = $$;
							}
	;

openB
		: '{'
		{
			if(open == 0)
				currentT = EnterScope(currentT);
			else{
				open = 0;
			}
		}
		;
closeB
		:	'}'
		{
			currentT = ExitScope(currentT);
		}
		;

body
        : openB statement_list closeB		{$$=$2;}
        ;

function_name 		
		: type IDENTIFIER 
							{
								open = 1;
								my.array = 3; my.pointer = 0; my.struct_member = 0; my.type = $1->type;
								AddSymbol($2.text,my,currentT);

								currentT = EnterScope(currentT);

								$$ = MakeNode(2); $$->type = $2.type; strcpy($$->lexeme,$2.text);
								$$->child[0] = $1; $1->parent = $$;
								$$->array = 50;

								returntype = $1->type;
								returnpointer = 0;

							}
		| STRUCT IDENTIFIER IDENTIFIER
							{
								open = 1;

								my.array = 3; my.pointer = 0; my.struct_member = 0; my.type = 5;
								strcpy(my.structID,$2.text);
								AddSymbol($3.text,my,currentT);
								currentT = EnterScope(currentT);

								$$ = MakeNode(2); $$->type = $3.type; strcpy($$->lexeme,$3.text);
								$$->child[0] = MakeNode(0); $$->child[0]->type = $2.type; strcpy($$->child[0]->lexeme,$2.text);
								$$->child[0]->parent  = $$;
								$$->array = 51;

								returntype = 5;
								returnpointer = 0;
								strcpy(returnchar,$2.text);
							}
		| type '*' IDENTIFIER
							{
								open = 1;

								my.array = 3; my.pointer = 1; my.struct_member = 0; my.type = $1->type;
								AddSymbol($3.text,my,currentT);
								currentT = EnterScope(currentT);

								$$ = MakeNode(2); $$->type = $3.type; strcpy($$->lexeme,$3.text);
								$$->child[0] = $1; $1->parent = $$;
								$$->array = 52;

								returnpointer = 1;
								returntype = $1->type;
							}
		;

function
	: function_name '(' argument_list ')' body		
								{

									$$ = $1;
								//	$$->child[1] = $3; $3->parent = $$;
									$$->child[1] = $5; $5->parent = $$;

									ALL[funcount] = (struct allFunc *)malloc(sizeof(struct allFunc));
									strcpy(ALL[funcount]->name,$1->lexeme);
									ALL[funcount]->t = $$;
									ALL[funcount]->arg = $3;
									ALL[funcount]->st = currentT->child[currentT->current - 1];
									funcount++;				
									//printf("I am in at %s %d\n",$1->lexeme,funcount);
								}
	| function_name '(' ')' body {
									$$ = $1;
									$$->child[1] = $4; $4->parent = $$;
									//$$->NumChild -= 1;
									$$->array += 3;	


									ALL[funcount] = (struct allFunc *)malloc(sizeof(struct allFunc));
									strcpy(ALL[funcount]->name,$1->lexeme);
									ALL[funcount]->t = $$;
									ALL[funcount]->arg = NULL;
									ALL[funcount]->st = currentT->child[currentT->current - 1];		
									funcount++;						
									//printf("I am in at khali mei %s %d\n",$1->lexeme,funcount);
								}
	
	;
program
	: declaration 	{$$=MakeNode(0); $$->type = -1;strcpy($$->lexeme,"dec");}
	| function		{$$ = $1; tree = $$; }
	| program declaration {$$ = $1; tree = $$;}
	| program function 	  
					{$$ = MakeNode(2); $$->type=1000; strcpy($$->lexeme,"@");
					 $$->child[0] = $1; $1->parent = $$;
					 $$->child[1] = $2; $2->parent = $$;
					tree = $$;	}
	;


%%
// 错误处理函数
yyerror(s)
char *s;
{
        fflush(stdout);
		printf("Parse Error\n");
		return 0;
}

int main()
{
	open = 0;
	jumpcount=0;
	returntype=0;
	returnpointer=0;
	Totalerrors=0;
	funcount = 0;
	init();
	yyparse();
	//AST_print(tree);
	depthSymbolTree(sym,1);
	printSymbolTree(sym);
	if(Totalerrors>0)
		printf("Total symantic errors: %d\n",Totalerrors);
	else{
		printf("Generating MIPS code...\n");
		GenerateMIPS();
	}
	
	return 0;
}

#include "definition.h"
#include "y.tab.h"
int checkmain();
void getLabel(char *s);	// output in s
void outputCode(FILE *fp,struct AST *t);
void Load(FILE *fp,char *reg,struct symbolTable *v,struct symbolTree *t,int off);
void Store(FILE *fp,char *reg,struct symbolTable *v,struct symbolTree *t,int off);
void operations(FILE *fp,char *s);
void While(FILE *fp,struct AST *t);
void For(FILE *fp,struct AST *t);
void If(FILE *fp,struct AST *t);
void var(FILE *fp,struct AST *t,int mode);
struct AST * recur(struct AST *t);
struct symbolTree * recur2(struct symbolTree *t);
void savearg(FILE *fp,struct AST *t);
void Unary(FILE *fp,char *s);
int now,lcount,current,myvar,must;
//struct symbolTree *last;
//////////////////////////////////////////
//     DataStructures
//  struct symbolTree *sym  -- symbol tree
// struct AST *tree  -- ast
// ALL , funcount
//////////////////////////////////////////////
// .array global stack

void GenerateMIPS(){
	lcount = 0;
	current = 0;
	myvar=0;
	must=0;
	if(checkmain()==0){
		printf("Error : main function not found\n");
		return;
	}
	FILE *fp;	
	fp = fopen("mips_code.s","w");
	int i;
	// Global Data Segment
	
	// text segment
	fprintf(fp,".data\n");
	fprintf(fp,"global: .word %d\n",sym->tableSize );
	fprintf(fp,".text\n");
	for(i=0;i<funcount;++i){
		now = i;
		fprintf(fp,"%s:\n",ALL[i]->name);
/*		if(!strcmp(ALL[i]->name,"main")){			// Global Data Allocation
			fprintf(fp,"\t li $t0, %d\n",sym->tableSize);
			fprintf(fp,"\t sub $sp, $sp, $t0\n");
			fprintf(fp,"\t move $t2, $sp\n");
		}
*/		
		fprintf(fp,"\t li $t0, %d\n",ALL[i]->st->tableSize);
		fprintf(fp,"\t sub $sp, $sp, $t0\n");
		fprintf(fp,"\t move $t2, $sp\n");
		current = ALL[i]->st->scope;

		outputCode(fp,ALL[i]->t->child[1]);
		
		fprintf(fp,"\t li $t0, %d\n",ALL[i]->st->tableSize); // assuming ki sp is at same position as before
		fprintf(fp,"\t add $sp, $sp, $t0\n");
		fprintf(fp,"\t move $t2, $sp\n");
		fprintf(fp,"\t jr $ra\n");
		
	}
	fclose(fp);	
}

void outputCode(FILE *fp,struct AST *t){
	int i;

	if(t == NULL)
		return;
//	printf("scope: %d\n",t->scope);
	t->lval = 0;					// using this variable to mess with scope -- serious problem in current code

	if(t->scope > current || must==1){
		//if(t->scope > current){
			//increase sp
			t->lval = 1;
			fprintf(fp,"#Scope Increased %d\n",t->scope);
			fprintf(fp,"\t li $t0, %d\n",t->scopenode->tableSize);
			fprintf(fp,"\t sub $sp, $sp, $t0\n");			// memory allocation
			fprintf(fp,"\t move $t2, $sp\n");
			//last = t->scopenode;
		//}
	/*	else{
			printf("tab :: %d\n",last->tableSize);
			fprintf(fp,"#Scope decreased %d\n",t->scope);
			fprintf(fp,"\t li $t0, %d\n",last->tableSize);
			fprintf(fp,"\t add $sp, $sp, $t0\n");
			fprintf(fp,"\t move $t2, $sp\n");

			last = t->scopenode;
		}
	*/	
		current = t->scope;
		must=0;
	}
	//printf("id mota  %s\n",t->lexeme);
	if(t->array >= 300){
		//printf("id %s\n",t->lexeme);
		var(fp,t,0);
	}
	else if(t->array==200 ){//} || t->type == FLOAT  || t->type == CHAR){
		
		if(t->type == INT){
			fprintf(fp,"\t li $t1, %s\n",t->lexeme);		// only for INT now
		}
		else if(t->type == CHAR){
			int temp = t->lexeme[1];
			//printf("%c-- this\n",t->lexeme[1]);
			fprintf(fp,"\t li $t1, %d\n",temp);
		}
		fprintf(fp,"\t li $t3,4\n");
		fprintf(fp,"\t sub $t2,$t2,$t3\n" );		// t2 current stack pointer 		
		fprintf(fp,"\t sw $t1,0($t2)\n\n" );	
	}
	else if(!strcmp(t->lexeme,"print")){
		Load(fp,"$a0",t->child[1]->where,t->child[1]->scopenode,0);
		if(t->child[0]->type == INT){
			fprintf(fp,"\t li $v0,1\n\t syscall\n");
			fprintf(fp,"\t li $a0,32\n");
			fprintf(fp,"\t li $v0,11\n\t syscall\n");
		}else if(t->child[0]->type == CHAR){
			fprintf(fp,"\t li $v0,11\n\t syscall\n");
			fprintf(fp,"\t li $a0,32\n\t syscall\n");
		}
	}
	else if(!strcmp(t->lexeme,"read")){
		if(t->child[0]->type == INT){
			fprintf(fp,"\t li $v0,5\n\t syscall\n");
		}
		else if(t->child[0]->type == CHAR){
			fprintf(fp,"\t li $v0,12\n\t syscall\n");
		}
		Store(fp,"$v0",t->child[1]->where,t->child[1]->scopenode,0);
	}
	else if(!strcmp(t->lexeme,"max")){
		Load(fp,"$t0",t->child[0]->where,t->child[0]->scopenode,0);
		Load(fp,"$t1",t->child[1]->where,t->child[1]->scopenode,0);
		char lb[100];
		getLabel(lb);
		fprintf(fp,"\t li $t3,4\n");
		fprintf(fp,"\t sub $t2,$t2,$t3\n" );
		fprintf(fp,"bgt $t0,$t1,%s\n",lb);
		fprintf(fp,"move $t0, $t1\n");
		fprintf(fp,"%s:\n",lb);
		fprintf(fp,"sw $t0, 0($t2)\n");

	}
	else if(!strcmp(t->lexeme,"min")){
		Load(fp,"$t0",t->child[0]->where,t->child[0]->scopenode,0);
		Load(fp,"$t1",t->child[1]->where,t->child[1]->scopenode,0);
		char lb[100];
		getLabel(lb);
		fprintf(fp,"\t li $t3,4\n");
		fprintf(fp,"\t sub $t2,$t2,$t3\n" );
		fprintf(fp,"ble $t0,$t1,%s\n",lb);
		fprintf(fp,"move $t0, $t1\n");
		fprintf(fp,"%s:\n",lb);
		fprintf(fp,"sw $t0, 0($t2)\n");
	}
	else if(!strcmp(t->lexeme,"swap")){
		Load(fp,"$t0",t->child[0]->where,t->child[0]->scopenode,0);
		Load(fp,"$t1",t->child[1]->where,t->child[1]->scopenode,0);
	
		Store(fp,"$t1",t->child[0]->where,t->child[0]->scopenode,0);
		Store(fp,"$t0",t->child[1]->where,t->child[1]->scopenode,0);
	}
	
	else if(t->NumChild == 2 && (!(strcmp(t->lexeme,"+")) || !(strcmp(t->lexeme,"-")) || !(strcmp(t->lexeme,"*")) || !(strcmp(t->lexeme,"/"))
			|| !(strcmp(t->lexeme,"%")) || !(strcmp(t->lexeme,">")) || !(strcmp(t->lexeme,"<")) || !(strcmp(t->lexeme,"&")) 
			|| !(strcmp(t->lexeme,"^")) || !(strcmp(t->lexeme,"|")) || !(strcmp(t->lexeme,">=")) || !(strcmp(t->lexeme,"<="))
			|| !(strcmp(t->lexeme,"!=")) || !(strcmp(t->lexeme,"==")) || !(strcmp(t->lexeme,">>")) || !(strcmp(t->lexeme,"<<"))	
			|| !(strcmp(t->lexeme,"&&")) || !(strcmp(t->lexeme,"||"))	)) {
		for(i=0;i<t->NumChild;++i)
			outputCode(fp,t->child[i]);

		fprintf(fp,"\t # ADDING ..\n");

		fprintf(fp,"\t lw $t1,0($t2)\n");		// right operand  $t1
		fprintf(fp,"\t lw $t0,4($t2)\n");		// left operand   $t0
		fprintf(fp,"\t li $t3,4\n");			// t3 temp stack for calculations
		fprintf(fp,"\t add $t2,$t2,$t3\n");
		
		operations(fp,t->lexeme);

		//fprintf(fp,"\t add $t1,$t1,$t0\n");

		fprintf(fp,"\t sw $t1,0($t2)\n\n");

	}
	else if(t->NumChild == 1 && (!(strcmp(t->lexeme,"+")) || !(strcmp(t->lexeme,"-")) || !(strcmp(t->lexeme,"*")) ||
				!(strcmp(t->lexeme,"!")) || !(strcmp(t->lexeme,"&")) || !(strcmp(t->lexeme,"~")) )){
		//printf("unary\n");
		if(strcmp(t->lexeme,"&")){
			outputCode(fp,t->child[0]);
			fprintf(fp,"\t lw $t1,0($t2)\n");
			Unary(fp,t->lexeme);
			fprintf(fp,"\t sw $t1,0($t2)\n\n");
		}
		else{									// handling case of &
			fprintf(fp,"\tli $t1,4\n");
			fprintf(fp,"\tsub $t2,$t2,$t1\n");
			Load(fp,"$t1",t->child[0]->where,t->child[0]->scopenode,3);
			fprintf(fp,"\tsw $t1,0($t2)\n");
		}		
	}
	else if(!strcmp(t->lexeme,"=")){				/////////  t0,t1 for calculations ,,, t2, actual stack pointer ,, t3 
		outputCode(fp,t->child[1]);
		
		fprintf(fp,"\t lw $t1,0($t2)\n");	 // get right value from stack

		if(strcmp(t->child[0]->lexeme,"*")){
			var(fp,t->child[0],1);
		}
		else{
			//printf("unary *\n");
			fprintf(fp,"\t move $s0,$t1\n");
			outputCode(fp,t->child[0]->child[0]);		// case of *
			fprintf(fp,"\t move $t1,$s0\n");

			fprintf(fp,"\tlw $t0,0($t2)\n");
			fprintf(fp,"\tadd $t2,$t2,4\n");
			fprintf(fp,"\tsw $t1, 0($t0)\n");

		}		

		if(strcmp(t->parent->lexeme,t->lexeme)){
			fprintf(fp,"\t add $t2,$t2,4\n" );
		}
	
	}
	else if( !strcmp(t->lexeme,"+=") || !strcmp(t->lexeme,"*=")|| !strcmp(t->lexeme,"-=")|| !strcmp(t->lexeme,"%=")|| !strcmp(t->lexeme,"/=")
		|| !strcmp(t->lexeme,"<<=")|| !strcmp(t->lexeme,">>=")|| !strcmp(t->lexeme,"^=")|| !strcmp(t->lexeme,"|=")|| !strcmp(t->lexeme,"&="))
	{
		outputCode(fp,t->child[1]);	// stored in 0t2
		fprintf(fp,"\t lw $t1,0($t2)\n");	 // get right value from stack		
		var(fp,t->child[0],0);
		fprintf(fp,"\tlw $t0,0($t2)\n");
		char c[5];
		strcpy(c,t->lexeme);
		c[2]='\0';
		operations(fp,c);
	//	fprintf(fp,"\tadd $t1,$t1,$t4\n");	
		fprintf(fp,"\tadd $t2,$t2,4\n");
		var(fp,t->child[0],1);

	}
	else if(t->array == 10)						// these should not leave anything in 0($t2)
		While(fp,t);
	else if(t->array == 11 || t->array==12)
		For(fp,t);
	else if(t->array == 15 || t->array == 16)
		If(fp,t);
	else if(t->type == CONTINUE){
		struct AST *t1 = recur(t);
		fprintf(fp,"\t b %s\n",t1->l1);
	}
	else if(t->type == BREAK){
		struct AST *t1 = recur(t);
		fprintf(fp,"\t b %s\n",t1->l2);
	}
	else if(t->type == RETURN){
		if(t->NumChild == 1){
			outputCode(fp,t->child[0]);
			fprintf(fp,"\tlw $v0,0($t2)\n");
		}

		int diff = t->scopenode->sumsize - sym->sumsize;
		fprintf(fp,"\t add $sp, $sp, %d\n",diff);
		fprintf(fp,"\t move $t2, $sp\n");
		fprintf(fp,"\t jr $ra\n");
	}
	else if(t->array == 3){			//function calls 
		fprintf(fp,"\tli $t0,4\n");
		fprintf(fp,"\tsub $sp,$sp,$t0\n");
		fprintf(fp,"\tsw $ra,0($sp)\n" );
		fprintf(fp,"\tmove $t2,$sp\n");
		fprintf(fp,"\tjal %s\n\n",t->lexeme);

		fprintf(fp,"\tlw $ra,0($sp)\n");
		fprintf(fp,"\tadd $sp,$sp,4\n");
		fprintf(fp,"\tmove $t2,$sp\n");
		if(t->type != VOID){
			fprintf(fp,"\tli $t0,4\n");
			fprintf(fp,"\tsub $t2,$t2,$t0\n");
			fprintf(fp,"\tsw $v0,0($t2)\n");
		}
	}
	else if(t->array == 4){
		

		savearg(fp,t->child[0]);
		
		fprintf(fp,"\tli $t0,4\n");
		fprintf(fp,"\tsub $sp,$sp,$t0\n");
		fprintf(fp,"\tsw $ra,0($sp)\n" );
		fprintf(fp,"\tmove $t2,$sp\n");

		fprintf(fp,"\tli $t0,12\n");	// extra space for argument evaluation in savearg
		fprintf(fp,"\tsub $sp,$sp,$t0\n");

		fprintf(fp,"\tjal %s\n\n",t->lexeme);

		fprintf(fp,"\tadd $sp,$sp,12\n");

		fprintf(fp,"\tlw $ra,0($sp)\n");
		fprintf(fp,"\tadd $sp,$sp,4\n");
		fprintf(fp,"\tmove $t2,$sp\n");
		if(t->type != VOID){
			fprintf(fp,"\tli $t0,4\n");
			fprintf(fp,"\tsub $t2,$t2,$t0\n");
			fprintf(fp,"\tsw $v0,0($t2)\n");
		}
	}
	else {
		//fprintf(fp,"\t move $t2,$sp\n" );
		for(i=0;i<t->NumChild;++i)
			outputCode(fp,t->child[i]);
	}
	if(t->lval == 1){
			//printf("tab :: %d\n",last->tableSize);
			fprintf(fp,"#Scope decreased %d\n",t->scope);
			fprintf(fp,"\t li $t0, %d\n",t->scopenode->tableSize);
			fprintf(fp,"\t add $sp, $sp, $t0\n");
			fprintf(fp,"\t move $t2, $sp\n");	
	}
}
void Unary(FILE *fp,char *s){
	char c = s[0];

	if(c == '+'){
		return;
	}else if(c == '-'){
		fprintf(fp,"\tsub $t1,$0,$t1\n");
	}else if(c == '*'){
		fprintf(fp,"\tlw $t1,0($t1)\n");
	}else if(c == '!'){
		fprintf(fp,"\t seq $t1,$0,$t1\n");
	}else if(c == '~'){
		fprintf(fp,"\tnot $t1,$t1\n");
	}
}
void operations(FILE *fp,char *s){
	char c = s[0];
	fprintf(fp,"\t# %s\n",s );
	
	if(!strcmp(s,">="))
		fprintf(fp,"\t sge $t1,$t0,$t1\n");
	else if(!strcmp(s,"<="))
		fprintf(fp,"\t sle $t1,$t0,$t1\n");
	else if(!strcmp(s,"!="))
		fprintf(fp,"\t sne $t1,$t0,$t1\n");
	else if(!strcmp(s,"=="))
		fprintf(fp,"\t seq $t1,$t0,$t1\n");
	else if(!strcmp(s,">>"))
		fprintf(fp,"\t srlv $t1,$t0,$t1\n");
	else if(!strcmp(s,"<<"))
		fprintf(fp,"\t sllv $t1,$t0,$t1\n");
	else if(!strcmp(s,"&&")){
		fprintf(fp,"\t and $t9,$t0,$t1\n");
		fprintf(fp,"\t sne $t1,$t9,$0\n");
	}
	else if(!strcmp(s,"||")){
		fprintf(fp,"\t or $t9,$t0,$t1\n");
		fprintf(fp,"\t sne $t1,$t9,$0\n");
	}
	else if(c=='+')
		fprintf(fp,"\t add $t1,$t0,$t1\n");
	else if( c =='-')
		fprintf(fp,"\t sub $t1,$t0,$t1\n");
	else if( c =='*')
		fprintf(fp,"\t mul $t1,$t0,$t1\n");
	else if( c == '/')
		fprintf(fp,"\t div $t1,$t0,$t1\n");
	else if( c == '%')
		fprintf(fp,"\t rem $t1,$t0,$t1\n");
	else if( c == '>')
		fprintf(fp,"\t sgt $t1,$t0,$t1\n");
	else if( c == '<')
		fprintf(fp,"\t slt $t1,$t0,$t1\n");
	else if( c == '&')
		fprintf(fp,"\t and $t1,$t0,$t1\n");
	else if( c == '|')
		fprintf(fp,"\t or $t1,$t0,$t1\n");
	else if( c == '^')
		fprintf(fp,"\t xor $t1,$t0,$t1\n");
}
// not done for arrays

void Store(FILE *fp,char *reg,struct symbolTable *v,struct symbolTree *t,int off){
	
	fprintf(fp,"\t # STORING ..\n" );
	//printf("S off:: %s %d\n",v->name,v->offset);
	if(v->parentT->scope == 0){
		fprintf(fp,"\t la $t9,global\n");

		fprintf(fp,"\t add $t9,$t9,%d\n",v->offset);
		if(off==1)
			fprintf(fp,"\t add $t9,$t9,$t8\n");
		else if(off != 0)
			fprintf(fp,"\t add $t9,$t9,%d\n",off );
	//	if(v->type == INT || v->type == FLOAT){
			//printf("%d\n",v->offset );
			fprintf(fp,"\t sw %s, 0($t9)\n",reg);
	}	
	else if(t->scope == v->parentT->scope){
		fprintf(fp,"\t add $t9,$sp,%d\n",v->offset);
		if(off==1)
			fprintf(fp,"\t add $t9,$t9,$t8\n");
		else if(off != 0)
			fprintf(fp,"\t add $t9,$t9,%d\n",off );
	//	if(v->type == INT || v->type == FLOAT){
			//printf("%d\n",v->offset );
			fprintf(fp,"\t sw %s, 0($t9)\n",reg);
	//	}
	//	else if(v->type == CHAR)
	//		fprintf(fp,"\t sb %s, 0($t9)\n",reg);
	}else{
		//int tmp = v->parentT->sumsize - t->sumsize + v->offset;
		int tmp =  t->sumsize - v->parentT->sumsize + v->offset ;
		fprintf(fp,"\t add $t9,$sp,%d\n",tmp);
		if(off==1)
			fprintf(fp,"\t add $t9,$t9,$t8\n");
		else if(off != 0)
			fprintf(fp,"\t add $t9,$t9,%d\n",off );
	//	if(v->type == INT || v->type == FLOAT){
			//printf("%s %d %d %d \n",v->name,v->parentT->sumsize,t->sumsize,v->offset);
			fprintf(fp,"\t sw %s, 0($t9)\n",reg);
	//	}
	//	else if(v->type == CHAR)
	//		fprintf(fp,"\t sb %s, 0($t9)\n",reg);
	}	
}
void While(FILE *fp, struct AST *t){
	char lbl[100],lbl2[100];
	getLabel(lbl);
	getLabel(lbl2);
	strcpy(t->l1,lbl);
	strcpy(t->l2,lbl2);
	fprintf(fp,"%s:\n",lbl);
	outputCode(fp,t->child[0]);
	fprintf(fp,"\t lw $t0,0($t2)\n");
	fprintf(fp,"\t beq $0, $t0,%s\n",lbl2);
	outputCode(fp,t->child[1]);
	fprintf(fp,"b %s\n",lbl);
	fprintf(fp,"%s:\n",lbl2);
	//outputCode(fp,t->child[2]);

}
void For(FILE *fp,struct AST *t){
	 if(t->array==11){
                //FOR '(' expression_statement expression_statement ')' istart statement_list iend
                char Lab[100],Lab1[100];
                getLabel(Lab);
                getLabel(Lab1);
                strcpy(t->l1,Lab);
				strcpy(t->l2,Lab1);
                outputCode(fp,t->child[0]);
                fprintf(fp,"%s:",Lab);
                outputCode(fp,t->child[1]);
                //temporay variable as t0
                fprintf(fp,"\t lw $t1,0($t2)\n");
                
				fprintf(fp,"\t add $t2,$t2,4\n" );	

                fprintf(fp,"\t beq $t1,$0,%s\n",Lab1);
                outputCode(fp,t->child[2]);
                fprintf(fp,"\t b %s\n",Lab);
                fprintf(fp,"%s:\n",Lab1);
               // outputCode(fp,t->child[3]);
        }
        else if(t->array==12){
                //FOR '(' expression_statement expression_statement expression ')' istart statement_list iend

                char Lab[100],Lab1[100],lb3[100];
                getLabel(Lab);
                getLabel(Lab1);
                getLabel(lb3);

                strcpy(t->l1,lb3);
				strcpy(t->l2,Lab1);
                //strcpy(t->l3,Lab);

                outputCode(fp,t->child[0]);
                fprintf(fp,"%s:",Lab);
                outputCode(fp,t->child[1]);
                //temporay variable as t0
                fprintf(fp,"\t lw $t1,0($t2)\n");
                fprintf(fp,"\t add $t2,$t2,4\n");
                //fprintf(fp,"\t li $t3,0\n");
                fprintf(fp,"\t beq $t1,$0,%s\n",Lab1);
                outputCode(fp,t->child[3]);

                fprintf(fp,"%s:\n",lb3);
                outputCode(fp,t->child[2]);
                fprintf(fp,"\t b %s\n",Lab);
                fprintf(fp,"%s:\n",Lab1);
               // outputCode(fp,t->child[4]);
        }
}
void If(FILE *fp,struct AST *t){
	char lb1[100],lb2[100];
	getLabel(lb1);
	getLabel(lb2);
	if(t->array == 15){
		outputCode(fp,t->child[0]);
		fprintf(fp,"\t lw $t0,0($t2)\n" );
		fprintf(fp,"\t add $t2,$t2,4\n");
		fprintf(fp,"\t beq $0, $t0,%s\n",lb1);
		outputCode(fp,t->child[1]);
		fprintf(fp,"%s:\n",lb1);
	}else{

		outputCode(fp,t->child[0]);
		fprintf(fp,"\t lw $t0,0($t2)\n" );
		fprintf(fp,"\t add $t2,$t2,4\n");
		fprintf(fp,"\t beq $0, $t0,%s\n",lb1);	//lb1 for else
		outputCode(fp,t->child[1]);
		fprintf(fp,"\t b %s\n",lb2);
		fprintf(fp,"%s:\n",lb1);
		must=1;
		outputCode(fp,t->child[2]);
		fprintf(fp,"%s:\n",lb2);
	}
}
void Load(FILE *fp,char *reg,struct symbolTable *v,struct symbolTree *t,int off){		// 3 for handling &
	// do for array
	fprintf(fp,"\t # LOADING ..\n" );
	//printf("L off:: %s %d\n",v->name,v->offset);

	if(v->parentT->scope == 0){
		fprintf(fp,"\t la $t9,global\n");
		fprintf(fp,"\t add $t9,$t9,%d\n",v->offset);
		if(off == 3){
			fprintf(fp,"\tmove %s,$t9\n",reg);
			return;
		}
		if(off==1)
			fprintf(fp,"\t add $t9,$t9,$t8\n");
		else if(off != 0)
			fprintf(fp,"\t add $t9,$t9,%d\n",off);
	//	if(v->type == INT || v->type == FLOAT){
			fprintf(fp,"\t lw %s, 0($t9)\n",reg);
	}
	else if(t->scope == v->parentT->scope){
		fprintf(fp,"\t add $t9,$sp,%d\n",v->offset);
		if(off == 3){
			fprintf(fp,"\tmove %s,$t9\n",reg);
			return;
		}
		if(off==1)
			fprintf(fp,"\t add $t9,$t9,$t8\n");
		else if(off != 0)
			fprintf(fp,"\t add $t9,$t9,%d\n",off);
	//	if(v->type == INT || v->type == FLOAT){
			fprintf(fp,"\t lw %s, 0($t9)\n",reg);
		
	}else{
		//int tmp = v->parentT->sumsize - t->sumsize + v->offset;
		int tmp =  t->sumsize - v->parentT->sumsize + v->offset;
		fprintf(fp,"\t add $t9,$sp,%d\n",tmp);
		if(off == 3){
			fprintf(fp,"\tmove %s,$t9\n",reg);
			return;
		}
		if(off==1)
			fprintf(fp,"\t add $t9,$t9,$t8\n");
	//	if(v->type == INT || v->type == FLOAT)
		else if(off != 0)
			fprintf(fp,"\t add $t9,$t9,%d\n",off);

			fprintf(fp,"\t lw %s, 0($t9)\n",reg);
	//	else if(v->type == CHAR)
	//		fprintf(fp,"\t lb %s, 0($t9)\n",reg);
	}
}
void var(FILE *fp,struct AST *t,int mode){	// 0 for load, 1 for save
		int offset;	// there is value in $t1 ,, save before calling outputcode

		if(t->array==300){
			offset = 0;
			if(mode==0){
				fprintf(fp,"\t li $t3,4\n");
				fprintf(fp,"\t sub $t2,$t2,$t3\n" );
			}	
		}
		else if(t->array == 301){
			fprintf(fp,"# ARRAY dim 1 index\n" );
			fprintf(fp,"move $s0,$t1\n");
			outputCode(fp,t->child[0]);
			fprintf(fp,"move $t1,$s0\n");
			fprintf(fp,"# ARRAY dim 1\n" );
			fprintf(fp,"\t lw $t8,0($t2)\n");
			//if(t->type == INT || t->type == FLOAT)
			fprintf(fp,"\t li $t9,4\n");
			//else
			//	fprintf(fp,"\t li $t9,1\n");

			fprintf(fp,"\t mul $t8,$t8,$t9\n");		// value in $t8 is added further in offset 
			offset = 1;
			//printf("yes %d\n",mode);
			if(mode==1)
				fprintf(fp,"\t add $t2,$t2,4\n");
		}
		else if(t->array == 302){
			fprintf(fp,"move $s0,$t1\n");
			outputCode(fp,t->child[0]);
			fprintf(fp,"move $t1,$s0\n");

			fprintf(fp,"# ARRAY dim 2\n" );
			fprintf(fp,"move $s0,$t1\n");
			outputCode(fp,t->child[1]);
			fprintf(fp,"move $t1,$s0\n");

			fprintf(fp,"\t lw $t7,0($t2)\n");	// dim 2
			fprintf(fp,"\t lw $t6,4($t2)\n");	// dim 1
			fprintf(fp,"\t add $t2,$t2,4\n");

			int x=t->where->dim2;
			//assert(x==5)
		//	if(t->type == INT || t->type == FLOAT){
			x=x*4;
			fprintf(fp,"\t li $t9,4\n");
		//	}else{
		//		fprintf(fp,"\t li $t9,1\n");
		//	}

			fprintf(fp,"li $t5, %d\n",x);
			fprintf(fp,"\t mul $t8,$t6,$t5\n");
			fprintf(fp,"\t mul $t9,$t7,$t9\n");
			fprintf(fp,"\t add $t8,$t8,$t9\n");
		//	fprintf(fp,"\t add $t8,$t8,1\n");
			offset = 1;
			if(mode==1)
				fprintf(fp,"\t add $t2,$t2,4\n");
		}
		else if(t->array == 303 || t->array == 304 ){
			

				if(t->array == 303){
					fprintf(fp,"\t li $t8, %d\n",t->child[1]->where->order);	
					if(mode==0){
						fprintf(fp,"\t sub $t2,$t2,$t3\n" );
						fprintf(fp,"\t sw $t4,0($t2)\n\n" );
					}
				}
				else {
					fprintf(fp,"move $s0,$t1\n");
	
			
					outputCode(fp,t->child[0]->child[0]);
					fprintf(fp,"move $t1,$s0\n");

					fprintf(fp,"\t lw $t7,0($t2)\n");	// dim 1 index
					fprintf(fp,"\t li $t9, %d\n", t->child[0]->where->order);	// size of struct
					fprintf(fp,"\t mul $t8,$t9,$t7\n");
					fprintf(fp,"\t add $t8, $t8, %d\n",t->child[1]->where->order );
					if(mode==1)
						fprintf(fp,"\t add $t2,$t2,4\n");
				}
				

				offset = 1;

				
				if(mode==0){
					Load(fp,"$t4",t->child[0]->where,t->child[0]->scopenode,offset);
																	//	load variable from sp and put on current stack pointed by $t3
					fprintf(fp,"\t sw $t4,0($t2)\n\n" );	
				}
				else{
					Store(fp,"$t1",t->child[0]->where,t->child[0]->scopenode,offset);
				}
				return;
		/*	}else{
				Store(fp,"$t1",t->child[0]->where,t->child[0]->scopenode,offset);
			}
			return;
		*/
		}
		if(mode==0){
			Load(fp,"$t4",t->where,t->scopenode,offset);
															//	load variable from sp and put on current stack pointed by $t3
			fprintf(fp,"\t sw $t4,0($t2)\n\n" );	
		}
		else{
			Store(fp,"$t1",t->where,t->scopenode,offset);
		}	
}

struct AST * recur(struct AST *t){
	struct AST *tmp = t;
	while (strcmp(tmp->lexeme,"for")!=0 && strcmp(tmp->lexeme,"while")!=0)
		tmp = tmp->parent;
	return tmp;
}

struct symbolTree * recur2(struct symbolTree *t){
	struct symbolTree *tmp = t;
	while(tmp->scope != 0)
		tmp = tmp->parent;

	return tmp;
}
void savearg(FILE *fp,struct AST *t){
	struct AST *tmp=t,*tmp2;
	int i=0,index;
	for(i=0;i<funcount;++i){
		if(!strcmp(t->parent->lexeme,ALL[i]->name)){
			index = i;
			break;
		}
	}
	printf("save ---> %s\n",ALL[index]->name);
	while(strcmp(tmp->lexeme,",")==0)
		tmp = tmp->child[0];

	int dist=0,act;

	if(t == tmp){
			
			outputCode(fp,tmp);
			act = ALL[index]->st->tableSize - dist + 16;
			printf("save2  %d\n",act);
			fprintf(fp,"\tmove $t0,$sp\n" );
			fprintf(fp,"\tli $t1, %d\n",act);
			fprintf(fp,"\tsub $t0,$t0,$t1\n");
			fprintf(fp,"\tlw $t4,0($t2)\n");
		//	if(tmp->type == INT || tmp->type == FLOAT){
				dist += 4;
				fprintf(fp,"\tsw $t4,0($t0)\n");
		//	}else{
		//		dist += 1;
		//		fprintf(fp,"\tsb $t4,0($t0)\n");
		//	}
			
	}else{
	//	tmp2 = tmp->parent;
		while(tmp != t->parent){
			if(dist==0){
				outputCode(fp,tmp);
				tmp2 = tmp;
			}
			else{
				outputCode(fp,tmp->child[1]);
				tmp2 = tmp->child[1];
			}

			act = ALL[index]->st->tableSize - dist  + 16;
			fprintf(fp,"\tmove $t8,$sp\n" );
			fprintf(fp,"\tli $t7, %d\n",act);
			fprintf(fp,"\tsub $t8,$t8,$t7\n");
			fprintf(fp,"\tlw $t4,0($t2)\n");
			fprintf(fp,"\t add $t2,$t2,4\n");
		//	if(tmp2->type == INT || tmp2->type == FLOAT){
				dist += 4;
				fprintf(fp,"\tsw $t4,0($t8)\n");
		//	}else{
		//		dist += 1;
		//		fprintf(fp,"\tsb $t4,0($t8)\n");
		//	}
			tmp = tmp->parent;
		}
	}

}
int checkmain(){
	int i;
	for(i=0;i<funcount;++i){
		if(!strcmp(ALL[i]->name,"main"))
			return 1;
	}
	return 0;
}

void getLabel(char *s){
	char t[100];
	sprintf(t,"%d",lcount++);
	strcpy(s,ALL[now]->name);
	strcat(s,t);
	//printf("%s\n",s);	
}
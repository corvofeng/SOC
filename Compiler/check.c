#include<stdio.h>
#include<string.h>

int main()
{
	char *s;
	while(1){
	scanf("%s",s);
	printf("if non strct %d\n",check(s,0));
	printf("if struct %d\n",check(s,1));
	}
return 0;
}
int check(char *name,int struct_or_not){
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
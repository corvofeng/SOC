
int fun(int x){
	if(x==0){
		return 1;	
	}
	int z;
	return x*fun(x-1);
}
void main(){
		int b,x,i,z;
		read(int,x);
		z=fun(x);
		print(int,z);
		
}


/*void main(){
	int a,*b,*c, d;
	read(int,a);
	c = &a;
	b = &d;
	*b = *c;
	*c = 4 + a + *b;
	print(int,a);
}
*/
/*int me;
void main(){
	int a,f;
	//for(a=1;a<=8;a=a+1){
	me = 2;
	a=1;
	while(a<=8){
		int f;
		for(f=a;f<=8;f=f+1){
			int x;
			if(f==5){
				int y;
				print(int,f);
			}else if(f > 5){
				int e;
				e = f+1;
				print(int,me);
			}
		}
		a+=1;
	}
}
*/

/*int main(){
	int a[5][5],b,c;
	int x,y;
	for(x=0;x<5;x=x+1){
		for(y=0;y<5;y=y+1){
			if(x==y){
				a[x][y] = 17;
			}else{
				a[x][y] = 15;
			}
			c=a[x][y];
			//print(int,c);
		}
		b=a[0][0];
		print(int,b);
	}
	
}
*/
/*int main()
{
	int b,x;
	x=1;
	b=100;
	for(x=1;x<=2;x=x+1){
		print(int,b);
		int b;
		b=20;
		print(int,b);
	}
	return 0;
}
*/
/*
int main(){
	struct AD{
		int a,b;
		char x,y;
	}sx;
	struct AD ss[5];
	
	int i,x;
	char c;

	for(i=0;i<5;i+=1){
		ss[i].a = i*i;
		ss[i].b = i+1;
	}
	for(i=0;i<5;i+=1){
		x = ss[i].a;
		print(int,x);
	
		x = ss[i].b;
		print(int,x);

		//print(char,c);
	}
	//ss.b = 4;
}
*/
/*
struct buz{
	int a,b;
} X;
void fun(){
	X.a=6;
	X.b=7;
}
int main(){
	X.a=2;
	X.b=5;
	int c;
	fun();
	c=X.a;
	print(int,c);
	c=X.b;
	print(int,c);
	//return 0;
}
*/

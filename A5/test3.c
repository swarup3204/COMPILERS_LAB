/*function definitions and nested calls*/

int fib[50];

int multiply(int a, int b){
	int ans=a*b;
	return ans;
}

void populate_fib(){
	fib[0]=fib[1]=1;
	
	int i;
	
	for(i=2;i<50;++i){
		fib[i]=multiply(fib[i],fib[i-1]);
	}
	
	return;
}

int main(){
	populate_fib();
	return 0;
}

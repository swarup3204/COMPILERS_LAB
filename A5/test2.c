/*conditionals and iteration statements*/

int main(){
	int a=3, b;
	b=7;
	
	char* message;
	
	/*if else statement check*/
	if(a>=b){
		message="a is greater than or equal to b";
		/*note: although the a string value will be assigned to message in the symbol table 
		of this block, type conversion from string literal to char* is not supported in our code*/
		int temp=a;
		a=b;
		b=a;
	}
	else{
		message="b is greater than a";
	}
	
	int mult=0;
	
	/*while statement check*/
	while(a>0){
		mult=mult+b;
		a=a-1;
	}

	int i;
	
	/*for statement check*/
	for(i=0;i<mult;++i){
		a++;
	}
	
	/*do while statement check*/
	do{
		i--;
	}while(i>=0);
	
	/*if statement check*/
	if(i==0 && a==mult){
		message="success";
	}
	
	return 0;
}

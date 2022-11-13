/*arrays and pointers*/
int main(){
	int a[10], b[2][3][4];
	float c[6][2];
	
	float *d;
	int **e, ***f;
	
	a[2]=b[1][2][3];
	*d=c[2][0];
	b[1][0][2]=(int)c[2][0];
	c[2][0]=*d;
	
	***f = **e + b[1][1][3];
	
	return 0;
	
}

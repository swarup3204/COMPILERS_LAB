/*global int, float, string literal, char declarations*/
int a=10, b, c=9;
float pi=3.14;
char* greet="Hello world\n";
char d='q';

float fl_2D_array[3][4];
int e, *ptr;

int main(){
	/*declaration and assignment of local variables*/
	char* test = "Area of circle";
	int radius = 5;
	float area;
	area = pi * (float)radius * (float)radius;
	
	float area_array[10];
	area_array[5] = area;
	
	int b1,b2=10,b3=20;
	
	/*aritmetic operations*/
	b1=b2+b3;
	b2=b1-b3;
	b1=b2*b3;
	b3=b1/b2;
	
	/*bitwise operations*/
	b1=b2^b3;
	b2=b1&b3;
	b3=b1|b2;
	
	/*shift operations*/
	b1=b2<<2;
	b2=b3>>4;
	
	return 0;
}

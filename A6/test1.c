int printInt(int num);
int printStr(char * c);

int a=10, b, c=9;



int e, *ptr;

int main(){

	printStr("Hello world\n");

	
	int b1,b2=10,b3=20;
    int ans1,ans2,ans3;
    int s1,s2,s3;
	

	b1=b2+b3;
	b2=b1-b3;
	b1=b2*b3;
	b3=b1/b2;
    ans1=b3;
	

	b1=b2^b3;
	b2=b1&b3;
	b3=b1|b2;
    ans2=b2;
	

	b1=b2<<2;
	b2=b3>>4;
    ans3=b2;

    printStr("ans1 = ");
    s1=printInt(ans1);
    printStr("\n");
    printStr("Number of characters in the integer just printed = ");
    printInt(s1);
    printStr("\n");

	
    printStr("ans2 = ");
    s2=printInt(ans2);
    printStr("\n");
    printStr("Number of characters in the integer just printed = ");
    printInt(s2);
    printStr("\n");

    printStr("ans3 = ");
    s3=printInt(ans3);
    printStr("\n");
    printStr("Number of characters in the integer just printed = ");
    printInt(s3);
    printStr("\n");

	return 0;
}
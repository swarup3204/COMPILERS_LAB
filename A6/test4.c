int printInt(int num);
int printStr(char * c);
int readInt(int *eP);

int gcd(int m, int n)
{
    if (n!=0)
    {
		int a, b;
		a = m % n;
		b = gcd(n, a);
	        return b;
    }
    else 
       return m;
}

int main()
{
	int a, b, c, p;
	printStr("This program computes the GCD of 2 numbers.\n");
	printStr("Enter a>0: ");
	a = readInt(&p);
	printStr("Enter b>0: ");
	b = readInt(&p);	
	printStr("The greatest common divisor of ");
	printInt(a);
	printStr(" & ");
	printInt(b);
	printStr(" is : ");
	c = gcd(a, b);
	printInt(c);
	printStr("\n");	
	return 0;
}
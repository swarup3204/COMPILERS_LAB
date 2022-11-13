int printInt(int num);
int printStr(char * c);
int readInt(int *eP);



int main()
{

	//useless comment

	printStr("This is a program to find sum of 2 arrays.\n");

	int a[20];
	int b[20];
	int p, n, x, i;
	int y, z;	

	printStr("Enter n: ");	
	n = readInt(&p);

	printStr("Enter the elements of first array:\n");
	for(i = 0; i < n; i++ )
	{
		x = readInt(&p);
		a[i] = x;
	}

	printStr("Enter the elements of second array:\n");
	for(i = 0; i < n; i++ )
	{
		x = readInt(&p);
		b[i] = x;
	}
	printStr("Elements of the product array are:\n");
	for( i = 0; i < n; i++ )
	{
		x = a[i];	
		y = b[i];
		z = x + y;
		printInt(z);
		printStr(" ");
	}
	printStr("\n");
	return 0;
}
int printInt(int num);
int printStr(char * c);
int readInt(int *eP);

//returns nth fibonacci number
int fibonacci(int n) 
{

   if(n == 0)
   {
      return 0;
   }
	
   if(n == 1) 
   {
      return 1;
   }
   int a,b,c;
   a = fibonacci(n-1);
   b = fibonacci(n-2);
   c = a + b;
   return c;
}

//returns factorial of n
int factorial(int n)
{
  int a;

  if (n == 0)
    return 1;
  else
  {
	a = factorial(n-1);
  }
    return(n * a);
}

int main()
{
	int num, fact, fib;
	printStr("This program tests recursive functions.\n");

	printStr("Enter a number(<=10) for finding factorial: ");
	int p;
	num = readInt(&p);
	if(num>10)
	{
		printStr("Sorry. Enter number is too large.\n");
	}
	else
	{
		fact = factorial(num);
		printStr("The factorial of ");
		printInt(num);
		printStr(" is : ");
		printInt(fact);
		printStr("\n");
	}

	printStr("Enter a number(<=10) for finding nth Fibonacci number: ");
	int p;
	num = readInt(&p);
	if(num>10)
	{
		printStr("Sorry. Enter number is too large.\n");
	}
	else
	{
		fib = fibonacci(num);
		printStr("The ");
		printInt(num);
		printStr("th fibonacci no. is ");
		printInt(fib);
		printStr("\n");
	}
	
	return 0;
}
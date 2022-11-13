int printInt(int n);
int readInt(int *eP);
int printStr(char *str);

int bsearch(int arr[10], int left, int right, int key)
{
	int mid, temp;
	if(left < right || left == right)
	{
		mid = (left + right)/2;
		if(arr[mid] == key)
			return mid;
		else if (key < arr[mid])
		{
			temp = bsearch(arr, left, mid - 1, key);
			return temp;
		}
		else
		{
			temp = bsearch(arr,mid + 1, right, key);
			return temp;			
		}
	}
	else
		return -1;		
}
int main()
{
	int n, p, i, x, value;
	int a[10];
	printStr("This function implements binary search recursively.\n");
	printStr("Enter n<10: ");
	n = readInt(&p);
	printStr("Enter the sorted array.\n");
	for(i=0; i<n ;i++)
	{
		x = readInt(&p);
		a[i] = x;
	}	
	printStr("Enter the value to search for: ");
	value = readInt(&p);
	int retval;
	retval = bsearch(a, 0, n-1, value);

	if(retval == -1)
		printStr("Value not found.\n");
	else
	{
		printStr("Value found at index ");
		printInt(retval);
		printStr("\n");
	}
	return 0;
}
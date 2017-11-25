#include <stdio.h>
int main()
{
	int a;
	printf ("Enter number ");
	scanf ("%i", &a);
	int res = a*a;
	printf("Square of %i is %i\n", a, res);
	return 0;
}


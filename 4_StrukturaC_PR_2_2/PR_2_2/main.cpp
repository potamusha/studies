#include <stdio.h>
int main()
{
	int a;
	printf("Enter first number ");
	scanf("%i", &a);
	int b;
	printf("Enter second number ");
	scanf("%i", &b);
	int res_sum = a+b;
	printf("Sum of %i and %i is %i\n", a, b, res_sum);
	int res_subs = a-b;
	printf("Substraction of %i and %i is %i\n", a, b, res_subs);
	int res_mult = a*b;
	printf("Multiplication of %i and %i is %i\n", a, b, res_mult);
	return 0;
}
#include<stdio.h>
#include<conio.h>
#include<ctype.h>

int main()
{
	char c;
	scanf("%c", &c);
	if (isdigit(c))
		printf("digit\n");
	else printf("not digit\n");
	getch();
	return 0;
}
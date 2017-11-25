#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string>

int main(){
	char str[255];
	gets_s(str);

		return 0;
}




/*#include<stdio.h>
#include<conio.h>
#include<string>


int main()
{
	char str[255];
	gets_s(str);
	int counter = 0;
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == ' ') counter++;
	printf("counter = %i", counter);
	getch();
	return 0;
}
*/

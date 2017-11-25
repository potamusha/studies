#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string>

void mytoupper(char *x);

int main() {
	char c = 'e';
	printf("%c \n %c \n", toupper(c), c);

	char symbol = 'r';
	mytoupper(&symbol);
	printf("%c \n",symbol);

	char str[200];
	printf("vvedite slovo>>> \n");
	//scanf("%c", &str);
	gets_s(str);
		for (int i = 0; i < strlen(str); i++) {
		if (isalpha(str[i])) {
			mytoupper(&str[i]);
			}
		}
		printf(str);



		char str2[200];
		printf("2.vvedite slovo>>>");
		//scanf("%c", &str);
		gets_s(str2);
		for (int i = 0; i < strlen(str2); i++) {
			if (isalpha(str2[i])) {
				char result = toupper(str2[i]);
				str2[i] = result;
			}
		}
		printf(str2);

	getch();
}

void mytoupper(char *x) {
	char variable =*x;
	char result = toupper(variable);
	*x = result;
}

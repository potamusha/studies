#include<stdio.h>
#include<conio.h>

bool iseven(int n);

int main() {
	int number;
	printf("Pleae enter a number: \n");
	scanf("%d", &number);
	char message [] = "Your number is ";

	if (iseven(number)) {
		printf("Your number is Even \n");
	} else {
		printf("Your number is Odd \n");
		}

	
	getch();
}

bool iseven(int n) {
	if (n % 2 == 0) {
		return true;
	} else {
		return false;
	}
	
}
#include<stdio.h>
#include<conio.h>
int main() {
	int number;
	printf("Enter trjohznachnoe number: ");
	scanf("%i", &number);
	int number1 = number / 100;
	int number2 = (number - number1 * 100) / 10;
	int number3 = (number-number1 * 100) % 10;
	printf("New number = %i%i%i\n", number3, number2, number1);
	getch();
}
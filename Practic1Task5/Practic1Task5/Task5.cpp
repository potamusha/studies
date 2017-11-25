#include<stdio.h>
#include<conio.h>



int min(int a, int b);
double min(double a, double b);
float min(float a, float b);
char min(char a, char b);

template <typename T>
T max(T a, T b);



int main() {
	printf("Integer: %d\n", max(4, 5));
	printf("Double: %fL\n", max(8.0, 5.9));
	printf("Float: %f\n", max(4.0F, 5.0F));
	printf("Char: %c\n", max('a', 'b'));

	getch();
	return 0;
}

int min(int a, int b) {
	return (a < b) ? a : b;
	
}

double min(double a, double b) {5
	if (a < b) return a;
	else return b;
}

float min(float a, float b) {
	if (a < b) return a;
	else return b;
}

char min(char a, char b) {
	if (a < b) return a;
	else return b;
}


template <typename T>
T max(T a, T b) {
	return (a > b) ? a : b;
}


void test() {
	return 0;
}
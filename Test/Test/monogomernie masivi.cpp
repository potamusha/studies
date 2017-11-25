/* #include<iostream>
#include<stdio.h>
#include<conio.h>
#include<time.h>

using namespace std;

int main() {
	int iArr[3][5];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++) {
		printf("Enter [%d][%d] value> ",i,j);
		scanf("%d", &iArr[i][j]);
	}

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 5; j++)
			printf("%d ", iArr[i][j]);
		printf("\n");
	}
	getch();
	return 0;
} */
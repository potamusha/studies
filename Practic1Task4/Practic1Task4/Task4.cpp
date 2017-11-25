#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#include<iostream>



int *generateArray(int n);
int min(int arr[], int lenght = 0);
void printArray(int mas[], int n);




bool less(int a, int b);
bool more(int a, int b);
bool equal(int a, int b);

typedef bool(*Compare)(int, int);
int countif(int*arr, int n, int x, Compare cmp);

void main() {
	int n;
	printf("Enter number of elements? ");
	scanf("%i", &n);

	int *mas = generateArray(n);
	printArray(mas, n);
	printf("\nMinimum is %i\n", min(mas, n));

	int userNumber;
	printf("Please enter your number> ");
	scanf("%d", &userNumber);

	int resLess = countif(mas, n, userNumber, less);
	printf("Number is less than %d is %i\n", userNumber, resLess);

	int resMore = countif(mas, n, userNumber, more);
	printf("Number is more than %d is %i\n", userNumber, resMore);

	int resEqual = countif(mas, n, userNumber, equal);
	printf("Number is equal to %d is %i\n", userNumber, resEqual);

	getch();
}

int min(int arr[], int lenght) {
	if (lenght) {
		int minimum = arr[0];
		for (int i = 1; i < lenght; i++)
			if (minimum > arr[i]) {
				minimum = arr[i];
			}
		return minimum;
	}
	else
		return INT_MIN;
}

int *generateArray(int n) {
	int *arr = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
	return arr;
}

void printArray(int mas[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%i ", mas[i]);
	}
}
	bool less(int a, int b) {
		if (a < b) return true;
		else return false;
	}

	bool more(int a, int b) {
		if (a > b) return true;
		else return false;
	}

	bool equal(int a, int b) {
		if (a == b) return true;
		else return false;
	}

	int countif(int*arr, int n, int x, Compare cmp) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (cmp(arr[i], x)) { 
				count++;
			}
		}
		return count;
	}


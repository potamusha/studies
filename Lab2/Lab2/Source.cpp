#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

int *setArray(int n);
void printArray(int *arr, int n);
void sortByQuicksort(int *arr, int left, int right, int count);
void sortByOddEven(int *arr, int n);
int count;

int main() {
	const int n = 100;
	for (int i = 0; i < 10; i++) {
		int m = n*(i + 1);
		printf("Razmer masiva = %d\n", m);
		printf("Nazhmite ljubuju klavishu chtobi vivesti massiv:");
		printf("\n\n");
		getch();
		int *arr1 = new int[m];
		arr1 = setArray(m);
		int *arr2 = new int[m];
		arr2 = setArray(m);
		
		printArray(arr1, m);
		printf("\n");
		printf("Nazhmite ljubuju klavishu chtobi otsortirovat massiv metodom QUICKSORT");
		printf("\n");
		getch();
		printf("\nMassiv otsortirovanni metodom QUICKSORT, razmerom %d : \n", m);
		int left = 0;
		int right = m-1;
		count = 0;
		sortByQuicksort(arr1,left, right, count);
		printArray(arr1, m);
		printf("\nKol-vo operacii sravnenija = %d", count);
		printf("\n\n");

		//printArray(arr2, m);
		printf("Nazhmite ljubuju klavishu chtobi otsortirovat massiv metodom ODD i EVEN transpozicii");
		getch();
		printf("\n");
		printf("\nMassiv otsortirovanni metodom ODDand EVEN , razmerom %d : \n", m);
		count = 0;
		sortByOddEven(arr2, m);
		printArray(arr2, m);
		printf("\nKol-vo operacii sravnenija = %d", count);
		printf("\n\n");
		getch();
		
		system("cls");
	}

	return 0;
	
}

int *setArray(int n) {
	int *newArr = new int[n];
	int i = 0;
	srand(time(NULL));
	while (i < n) {
		int temp = rand() % n;
		if (newArr[temp] < 0) {
			newArr[temp] = i + 1;
			i++;
		}
	}
	return newArr;
}

void printArray(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void sortByQuicksort(int *arr, int left, int right, int c = 0) {
	count = c;
	int i = left;
	int j = right;
	int pivot = arr[(left + right) / 2];
	do {
		while(arr[i] < pivot ){
			i++;
			count++;
		}
		while (pivot<arr[j]) {
			j--;
			count++;
		}
		if (i <= j) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
			count++;
		}
		count++;
	} while (i < j);
	if (left < j) {
		count++;
		sortByQuicksort(arr, left, j, count);
	}
	if (i < right) {
		count++;
		sortByQuicksort(arr, i, right, count);
	}
}


void sortByOddEven(int *arr, int n){
	int flag = 0; 
	do {
		for (int j = 0; j <= 1; j++) {
			flag = 0;
			int i = j;
			while (i < (n-1)) {
				if (arr[i] > arr[i + 1]) {
					int temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
					flag = 1;
				}
				i = i + 2;
				count++;
			}
		}
	} while (flag == 1);
}


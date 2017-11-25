#include<stdio.h>
#include<conio.h>
#include<time.h>
//#include<locale.h>
#include<stdlib.h>

int *setArray(int n);
void printArray(int *arr, int n);
void linearSearch(int *arr, int n, int x);
int *sortByHashMethod(int *arr, int n);
void adressSearch(int *arr, int n, int x);

int main() {
	/*setlocale(LC_ALL, "Russian");*/
	const int n = 100;
	for (int i = 0; i < 10; i++) {
		int m = n*(i + 1);
		printf("Razmer masiva = %d\n", m);
		printf("Nazhmite ljubuju klavishu chtobi vivesti massiv");
		getch();
		system("cls");
		int *arr = new int[m];
		arr = setArray(m);
		printArray(arr, m);
		printf("Nazhmite ljubuju klavishu chtobi naiti kljuchi");
		printf("\n\n");
		getch();
		int x1 = arr[0];
		int x2 = arr[m / 2];
		int x3 = arr[m - 1];
		int x4 = m+1;
		printf("-----Nachalo------\n");
		linearSearch(arr, m, x1);
		printf("-----Seredina------\n");
		linearSearch(arr, m, x2); 
		printf("-----Konec------\n");
		linearSearch(arr, m, x3); 
		printf("-----Net elementa------\n");
		linearSearch(arr, m, x4); 

		printf("Nazhmite ljubuju klavishu chtobi otsortirovat massiv metodom heshirovanija");
		getch();
		system("cls");
		printf("\nMassiv otsortirovanni metodom heshirovanija, razmerom %d \n", m);
		arr = sortByHashMethod(arr,m);
		printArray(arr, m);

		printf("\nNazhmite ljubuju klavishu chtobi naiti kljuchi");
		printf("\n\n");
		getch();
		x1 = arr[0];
		x2 = arr[m / 2];
		x3 = arr[m - 1];
		x4 = m+1;
		printf("-----Nachalo------\n");
		adressSearch(arr, m, x1);
		printf("-----Seredina------");
		adressSearch(arr, m, x2);
		printf("-----Konec------");
		adressSearch(arr, m, x3);
		printf("-----Net elementa------");

		adressSearch(arr, m, x4);

	}

	return 0;
;}

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

void linearSearch(int *arr, int n, int x) {
	int i=0;
	while (arr[i] != x && i != n) {
		i++;
	}
	if (arr[i] == x) {
		printf("Znachenie elementa = %d", x);
		printf("\nNomer iskomogo elementa %d", i);
	}
	else {
		printf("Znachenie elementa = %d", x);
		printf("\nPoisk ne udalsja");
	}
	printf("\nKol-vo operacii sravnenija = %d", i + 1);
	printf("\n\n");

}

int *sortByHashMethod(int *arr, int n) {
	int *newArr = new int[n];
	int newAdress;
	int i = 0;
	int C = 1;
	int retry = 0;
	while (i < n) {
		newAdress = arr[i] % n + C* retry;
		if (newAdress >= n){
			newAdress = newAdress-(n-retry)-(C*retry);
		}
		if (newArr[newAdress] < 0) {
				newArr[newAdress] = arr[i];
				i++;
				retry = 0;
		}
		else {
			retry++;
		}
	}
	return newArr;
}


void adressSearch(int *arr, int n, int x) {
	int i = 0;
	int C = 1;
	bool flag = 0;
	int adress = x % n + i*C;
	while (adress < n && !flag ) {
		i++;
		if (arr[adress] == x) {
			printf("\nZnachenie elementa = %d", x);
			printf("\nNomer iskomogo elementa %d", adress);
			flag = 1;
		}
		else if (arr[adress] < 0) {
			printf("\nZnachenie elementa = %d", x);
			printf("\nPoisk ne udalsja");
			flag = 1;
		}
		else {
			adress = x % n + i*C;
			//adress = adress - (n-i)-(C*i);
		}
	}
	if(!flag){
		printf("\nZnachenie elementa = %d", x);
		printf("\nPoisk ne udalsja");
	}
	printf("\nKol-vo operacii sravnenija = %d", i);
	printf("\n\n");
}
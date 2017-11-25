#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

//void setLineraTwoSidesList(int x);
void printArray(int n, int *arr);
void printAllElements(int *ptArr, int *arr, int v);
int lenghtOfList(int *arr);
void addElement(int *ptLeftArr, int *arr, int *ptRightArr, int v, int element);
void addThreeElements(int *ptLeftArr, int *arr, int *ptRightArr, int afterElemet, int element1, int element2, int element3);
int average(int *ptArr, int *arr, int v);
//void printaverage(int *ptArr, int *arr);

int const end = -1;
//int v;

int main() {
	int m = 10;
	int n = 5;
	int *arrayLeftPointer = new int[m];
	int *arrayRightPointer = new int[m];
	int *arrayValue = new int[m];

	srand(time(NULL));
	for (int i = 1; i < n + 1; i++) {
		arrayValue[i - 1] = rand() % 20;
		arrayLeftPointer[i - 1] = i - 2;
		if (i == n) {
			arrayRightPointer[i - 1] = end;
		}
		else {
			arrayRightPointer[i - 1] = i;
		}
	}

	int vLeft = n - 1;
	int vRight = 0;

	printArray(m, arrayLeftPointer);
	printf("	- Massiv LEFT adressov\n");
	printArray(m, arrayValue);
	printf("	- Massiv znachenii\n");
		printArray(m, arrayRightPointer);
		printf("	- Massiv RIGHT adressov\n");
		printf("\n***************************\n");
		printAllElements(arrayRightPointer, arrayValue, vRight);
		printf("	- A list goes to the RIGHT:\n");
		printAllElements(arrayLeftPointer, arrayValue, vLeft);
		printf("	- A list goes to the LEFT:\n");
		printf("\n***************************\n");

		/*int element = 111;
		int afterElement = 2;
		addElement(arrayLeftPointer, arrayValue, arrayRightPointer, afterElement, element);

		//element+= 111;
		//afterElemet =2;
		//addElement(arrayLeftPointer, arrayValue, arrayRightPointer, afterElemet, element);

		int k = 1;
		int element = 111;
		for (int i = 0; i < 3; i++) {
			addElement(arrayLeftPointer, arrayValue, arrayRightPointer, k, element);
			element += 111;
			//k++;
		}*/

		//printf("Dobavlenie trjoh elementov %d, %d, %d posle vtorogo elementa:\n\n", (element/3), (element/2), element);

		/*printArray(m, arrayLeftPointer);
		printf("	- Massiv LEFT adressov\n");
		printArray(m, arrayValue);
		printf("	- Massiv znachenii\n");
		printArray(m, arrayRightPointer);
		printf("	- Massiv RIGHT adressov\n");
		printf("\n***************************\n");

		printAllElements(arrayRightPointer, arrayValue, vRight);
		printf("	- A list goes to the RIGHT:\n");
		printAllElements(arrayLeftPointer, arrayValue, vLeft);
		printf("	- A list goes to the LEFT:\n");
		printf("\n***************************\n");
		*/

		int element1 = 222;
		int element2 = 333;
		int element3 = 444;
		int afterElement = 2;
		addThreeElements(arrayLeftPointer, arrayValue, arrayRightPointer, afterElement, element1, element2, element3);

		printArray(m, arrayLeftPointer);
		printf("	- Massiv LEFT adressov\n");
		printArray(m, arrayValue);
		printf("	- Massiv znachenii\n");
		printArray(m, arrayRightPointer);
		printf("	- Massiv RIGHT adressov\n");
		printf("\n***************************\n");

		printAllElements(arrayRightPointer, arrayValue, vRight);
		printf("	- A list goes to the RIGHT:\n");
		printAllElements(arrayLeftPointer, arrayValue, vLeft);
		printf("	- A list goes to the LEFT:\n");
		printf("\n***************************\n");

		int avarageOfList;
		avarageOfList = average(arrayRightPointer, arrayValue, vRight);
		printf("%d", avarageOfList);
		printf("	- Avarage for a list wich goes to the RIGHT\n");

		avarageOfList = average(arrayLeftPointer, arrayValue, vLeft);
		printf("%d", avarageOfList);
		printf("	- Avarage for a list wich goes to the LEFT\n");

		//printaverage(arrayRightPointer, arrayValue);

getch();
}


/*void setLineraTwoSidesList(int x) {
	int *arr = new int[x];
	int *arrPTLeft = new int[x];
	int *arrPTRight = new int[x];
	srand(time(NULL));
	for (int i = 1; i < x + 1; i++) {
		arr[i - 1] = rand() % 20;
		arrPTLeft[i - 1] = i - 2;
		if (i == x) {
			arrPTRight[i - 1] = end;
		} else {
			arrPTRight[i - 1] = i;
		}
		arrayValue = arr;
		arrayLeftPointer = arrPTLeft;
		arrayRightPointer = arrPTRight;
	}
}*/

void printArray(int n, int *arr) {
	for (int i = 0; i < n; i++) {
		printf("%d  ", arr[i]);
	}
}


void printAllElements(int *ptArr, int *arr, int v) {
		int i = v;
		printf("%d  ", arr[i]);
		while (ptArr[i] != end){
			i = ptArr[i];
			printf("%d	", arr[i]);
		}
}


 int lenghtOfList(int *arr) {
	int n = 0;
	while (arr[n] > 0) {
		n++;
	}
	return n;
}


void addElement(int *ptLeftArr, int *arr, int *ptRightArr, int afterElement, int element) {
	int k = afterElement - 1;
	int nextadress = lenghtOfList(arr);
	arr[nextadress] = element;
	ptLeftArr[nextadress] = ptLeftArr[k+1];
	ptLeftArr[k+1] = nextadress;

	ptRightArr[nextadress] = ptRightArr[k];
	ptRightArr[k] = nextadress;
}

void addThreeElements(int *ptLeftArr, int *arr, int *ptRightArr, int afterElemet, int element1, int element2, int element3) {
	int nextadress = lenghtOfList(arr);
	arr[nextadress] = element1;
	arr[nextadress + 1] = element2;
	arr[nextadress + 2] = element3;
	int k = afterElemet - 1;
	ptRightArr[nextadress] = nextadress + 1;
	ptRightArr[nextadress+1] = nextadress + 2;
	ptRightArr[nextadress+2] = ptRightArr[k];
	ptRightArr[k] = nextadress;


	ptLeftArr[nextadress] = ptLeftArr[k+1];
	ptLeftArr[k+1] = nextadress+2;
	ptLeftArr[nextadress + 1] = nextadress;
	ptLeftArr[nextadress + 2] = nextadress+1;
	
}

int average(int *ptArr, int *arr, int v) {
	int i = v;
	int number = arr[0];
	int sum = 0 + number;
	int count = 1;
	int result;
	while (ptArr[i] != end) {
		i = ptArr[i];
		number = arr[i];
		sum = sum + number;
		count++;
	}
	return result = sum / count;
}


/*void printaverage(int *ptArr, int *arr) {
	int i = 0;
	int number = arr[0];
	int sum = 0+number ;
	int count = 1;
	int result;

	printf("%d	", number);
	printf("%d	",  sum);
	printf("%d	\n", count);
	
	while (ptArr[i] != end) {
		i = ptArr[i];
		number = arr[i];
		sum = sum + number;
		count++;
		printf("%d	", i);
		printf("%d	", number);
		printf("%d	", sum);
		printf("%d	\n", count);
	}
}*/





/*void addElements(int *ptLeftArr, int *arr, int *ptRightArr, int afterElemet, int x, int element) {
	int nextadress = lenghtOfList(arr);
	int k = afterElemet - 1;
	for (int i = 0; i < x; i++) {
		arr[nextadress] = element;
	}


	//arr[nextadress] = element1;
	arr[nextadress + 1] = element2;
	arr[nextadress + 2] = element3;

	ptRightArr[nextadress] = nextadress + 1;
	ptRightArr[nextadress + 1] = nextadress + 2;
	ptRightArr[nextadress + 2] = ptRightArr[k];
	ptRightArr[k] = nextadress;


	ptLeftArr[nextadress] = ptLeftArr[k];
	ptLeftArr[k] = nextadress + 2;
	ptLeftArr[nextadress + 1] = nextadress;
	ptLeftArr[nextadress + 2] = nextadress + 1;

}*/
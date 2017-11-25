#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>

using namespace std;
vector<int> generateVector(int count);
void printVector(vector<int> a);


int main() {
	vector<int> v;

	int counter;
	printf("Enter count of number in vector: ");
	scanf_s("%i", &counter);
	v=generateVector(counter);
	printf("\nVash vector: \n");
	printVector(v);

	sort(v.begin(), v.end());
	cout<<"\nSorted vector: " << endl;
	printVector(v);
	
	///sort(v.begin()+3, v.end()-3);
	//cout << "\nSorted vector (3): " << endl;
	//printVector(v);

	int number;
	printf("\nEnter number what are looking for: ");
	scanf("%i", &number);
	vector<int>::iterator it = find(v.begin(), v.end(), number);

	if (it==v.end()){
		cout << "\nZnachenie ne naideno" << endl;
	}
	else {
		cout << "Znachenie= " << *it << " i ego pozicija = " <<it-v.begin()<< endl;
	}
	
	int c=count(v.begin(), v.end(), number);
	printf("\nCount of %i is %i times ", number, c);

	cout << endl << endl;
	return 0;

}

vector<int> generateVector(int count){
	vector<int> newVector;
	srand(time(NULL));
	for (int i = 0; i < count; i++) {
		int n = rand() % 10 + 1;
		newVector.push_back(n);
	}
	return newVector;
}

void printVector(vector<int> a) {
	for (int i = 0; i < a.size(); i++)
		printf("%i ", a[i]);
	printf("\n");
}
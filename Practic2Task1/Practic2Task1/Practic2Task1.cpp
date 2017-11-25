#include<iostream>
#include<vector>
#include<time.h>

using namespace std;

vector<int> fillVector();
void printVector(vector<int> v);
void printWithIterator(vector<int> v);
int sum(vector<int> a);
float aver(vector<int> a);
vector<int> generateVector(int count);

int main(){
	vector<int> v = fillVector();
	printVector(v);
	printWithIterator(v);
	printf("\nSumma vektora = %i \n", sum(v));
	printf("\nSrednee znachenie vektora = %f \n\n", aver(v));
	
	int count;
	printf("Enter count of number in vector: ");
	scanf_s("%i", &count);

	vector<int> vg (generateVector(count));
	cout << "Sgenerirovannii vector:" << endl;
	printVector(vg);
	return 0;
}

vector<int> fillVector() {
	vector<int> v;
	cout << "Vvedite 10 chisel" << endl;
	int n = 10;
	for (int i = 1; i <= n; i++) {
		cout << "Chislo No." << i << endl;
		int number;
		cin >> number;
		v.push_back(number);
	}
	return v;
}

void printVector(vector<int> v) {
	printf("\nVash vector: ");
	for (int i = 0; i < v.size(); i++)
		printf("%i ", v[i]);
	printf("\n");
}

void printWithIterator(vector<int> v) {
	cout << endl<< "Vash vektor with iterator: " << endl;
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";	
	}
	cout << endl;
}

int sum(vector<int> a) {
	int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a.at(i);
	}
	return sum;
}

float aver(vector<int> a) {
	float aver = (float) sum(a)/a.size();
	return aver;
}

vector<int> generateVector(int count) {
	vector<int> newVector;
	srand(time(NULL));
	for (int i = 0; i < count; i++) {
		newVector.push_back(rand() % 20 + 1);
	}
	return newVector;
}
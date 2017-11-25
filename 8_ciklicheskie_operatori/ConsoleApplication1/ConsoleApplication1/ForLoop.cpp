#include <iostream>
#include <windows.h>
using namespace std;
/**
This program counts 'n!' e.g. 'n' factorial.
*/
void main() {
	cout << "-----------------------------------" << endl
		<< " WELCOME TO THE FACTORIAL PARADISE" << endl
		<< "-----------------------------------" << endl;

	cout << "Please enter you factorial number :";
	int number;
	cin >> number;

	cout << "Wait, Mr. Computer is thinking";
	
	for (int i = 0; i <= 10; i++) {
		Sleep(1000);
		cout << ".";
	}

	double factorial = 1;
	for (int i = number; i > 1; i--) {
		factorial = factorial * i;
	}
	cout << endl << "Mr. Computer knows the answer!" << endl;
	cout << number << "! = " << factorial << endl;
}
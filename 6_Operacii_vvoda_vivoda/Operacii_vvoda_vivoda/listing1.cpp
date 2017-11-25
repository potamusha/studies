#include<windows.h>
#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	const int k_size = 64;
	const int k_left = 15;
	const int k_right = 30;
	char header1[k_size];
	char header2[k_size];
	CharToOem("Левое вырвнивание. ", header1);
	CharToOem("Правое выравнивание. ", header2);
	cout.setf(ios::left, ios::adjustfield);
	cout << "\t" << setw(k_left) << header1;
	cout.setf(ios::right, ios::adjustfield);
	cout << setw(k_right) << header2 << endl << endl;
	double result = 0.123456789;
	for (int i = 1; i <= 9; i++)
	{
		cout << setprecision(i);
		cout.setf(ios::left, ios::adjustfield);
		cout << "\t" << setw(k_left) << result;
		cout.setf(ios::right, ios::adjustfield);
		cout << setw(k_right) << result << endl;
	}
	cout << endl;
	return 0;
}

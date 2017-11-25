#include<conio.h>
#include<iostream>
#include<iomanip>
using namespace std;
void main2(void) {
	cout << "Test\t-\"text\"" << endl;
	cout << "Test text\n";

	int number = 125;
	cout << hex/*setbase(16)*/ << number << endl;//7d
	cout <</*oct*/setbase(8) << number << endl;//175
	cout << dec/*setbase(10)*/ << number << endl;//125
	
	double root2 = sqrt(102);
	cout.precision(9);
	cout << root2 << endl;
	cout << setprecision(7) << root2 << endl;
	getch();
}
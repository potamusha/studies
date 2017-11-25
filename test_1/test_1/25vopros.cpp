#include<iostream>
using namespace std;


int main() {
	/*int x = 3, y = 3;
	++x;
	y++;
	cout << x<< y;*/

	int a = 12, b = a / 5;
	if ((a*b) % 10 != 4) {
		b += 1;
		a = b;
	}
	cout << a<<endl<<b;

	return 0;
}
#include<iostream>

using namespace std;

void f(int a) {
	while (a--) {
		static int n = 0;
		cout << n++ << " ";
	}
}

int main() {
	f(0);
	f(1);
	f(2);
	return 0;
}
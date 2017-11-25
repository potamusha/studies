
#include <iostream>

using namespace std;

int main2() {
	int number;
	
	cout << "##################" << endl;
	cout << "##Hello Malvine!##" << endl;
	cout << "##################" << endl;
	cout << endl;
	cout << "Enter your number : ";
	cin >> number;

	int step = 1;
	cout << "Your number " << number << " divides on : \n";
	while (step <= number) {
		if (!(number % step)) {
			cout << step << "\n";
		}
		step++;
	}

	wcout << "This super program is copyrighted " << (wchar_t)0xA9 << " by Malvine Logina." << endl
		<< "If you would like to use it call 07447593668" << endl;

	return 0;
}
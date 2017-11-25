#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
	struct Employee{
		char name[20];
		char surname[20];
		int departmentID;
		float salary;
	};
	int n;
	printf ("Enter number of employies>?");
	scanf("%d", &n);
	
	Employee *Employies = new Employee[n];
	for (int i = 0; i < n; i++) {
		printf("Enter information about ")
	}


}
getch ();
return 0;
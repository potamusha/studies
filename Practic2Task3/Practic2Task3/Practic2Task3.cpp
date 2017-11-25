#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Student {
	char name[25];
	int age;
};

char name[25];

vector<Student> fillVector();
void printVector(vector<Student> v);
bool compare(Student st1, Student st2);
bool compare_if(Student st1);



int main() {
	vector <Student> students=fillVector();
	printf("\nVash students: ");
	printVector(students);

	/*Student st1, st2;
	st1.age = 1;
	st2.age = 0;
	bool answer = compare(st1, st2);
	cout << "ANswer " << answer;*/

	sort(students.begin(), students.end(), compare);
	cout << "\nSorted students: " << endl;
	printVector(students);

	cout <<endl<< "Find a student name: ";
	cin >> name;

	vector<Student>::iterator it = find_if(students.begin(), students.end(), compare_if);

	if (it == students.end()) {
		cout << endl << "Not founded" << endl;
	}
	else {
		cout << endl << "Student name: " << (*it).name <<" it's sequance number is "<< (it-students.begin()+1) << endl;
	}

	printf("\n");
	return 0;
}

vector<Student> fillVector() {
	vector <Student> students;
	cout << "Enter number of students: ";
	int number;
	cin >> number;

	for (int i = 0; i < number; i++) {
		Student person;
		cout << "\nEnter information about "<< i + 1<<" student: " << endl;
		printf("\Name: ");
		scanf("%s", person.name);
		printf("\Age: ");
		cin >> person.age;
		
		students.push_back(person);
	}
	return students;
}

void printVector(vector<Student> v) {
	for (int i = 0; i < v.size(); i++)
		printf("\nName: %s Age: %i ", v.at(i).name, v[i].age);
	printf("\n");
}

bool compare(Student st1, Student st2) {
	if (st1.age > st2.age) {
		return true;
	}
	return false;
}

bool compare_if(Student st1) {
	if (strcmp(st1.name, name) == 0) {
		return true;
	}
	return false;
}
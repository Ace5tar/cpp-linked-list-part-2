#include "Student.h"

using namespace std;

Student::Student(char* setFirst, char* setLast, double setGpa, int setId) {

	firstName = setFirst;
	lastName = setLast;
	gpa = setGpa;
	id = setId;
}

char* Student::getFirst() { return firstName; }
char* Student::getLast() { return lastName; }

double Student::getGpa() { return gpa; }
int Student::getId() { return id; }

Student::~Student() {
	delete firstName;
	delete lastName;
}

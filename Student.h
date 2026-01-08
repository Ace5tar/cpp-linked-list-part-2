
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student{
	private:
		char* firstName;
		char* lastName;
		double gpa;
		int id;
	public:
		Student(char* setFirst, char* setLast, double setGpa, int setId);
		~Student();
		double getGpa();	
		int getId();
		char* getFirst();
		char* getLast();
};

#endif

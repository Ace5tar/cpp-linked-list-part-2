#include <iostream>
#include <cstring>
#include "Student.h"
#include "node.h"

using namespace std;

void RecursiveAdd(Student* stud, Node* node);

void Add(Node* &head) {

	char* first = new char[80];
	cout << "First Name: ";
	cin.getline(first, 80);

	char* last = new char[80];
	cout << "Last Name: ";
	cin.getline(last, 80);

	int id;
	cout << "ID Number: ";
	cin >> id;
	cin.ignore();

	double gpa;
	cout << "GPA: ";
	cin >> gpa;
	cin.ignore();


	Student* stud = new Student(first, last, gpa, id);

	if(head == nullptr) {
		head = new Node(stud);
	} else {
		RecursiveAdd(stud, head);
	}

	printf("Student \"%s %s\" added.\n", 
		stud->getFirst(),
		stud->getLast());

}

void RecursiveAdd(Student* stud, Node* node) {
	if (node->getNext() == nullptr || node->getNext()->getStudent()->getId() > stud->getId()) {
		Node* newNode = new Node(stud);
		newNode->setNext(node->getNext());
		node->setNext(newNode);
	} else {
		RecursiveAdd(stud, node->getNext());
	}
}

void RecursiveDeallocate(Node* node) {

	if (node == nullptr) { return; }

	RecursiveDeallocate(node->getNext());

	delete node;
}

void RecursivePrint(Node* node) {
	if (node == nullptr) { return; }

	Student* stud = node->getStudent();

	printf("%s %s\nID: %d\nGPA: %.2f\n",
		stud->getFirst(),
		stud->getLast(),
		stud->getId(),
		stud->getGpa());

	RecursivePrint(node->getNext());
}




int main() {
	
	Node* head = nullptr;

	char* in = new char[80];
	bool running = true;

	while(running) {
		cin.getline(in, 80);
		if(strcmp(in, "QUIT") == 0) {
			running = false;
		}

		if(strcmp(in, "ADD") == 0) {
	 		Add(head);
	 	}
		if(strcmp(in, "PRINT") == 0) {
			RecursivePrint(head);
		}
	}
	
	RecursiveDeallocate(head);

	return 0;

}

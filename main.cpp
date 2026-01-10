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


	Student* stud = new Student(first, last, id, gpa);

	if(head == nullptr) {
		head = new Node(stud);
	} else {
		RecursiveAdd(stud, head);
	}
	
	cout<< "Student \"" 
		<< stud->getFirst() 
		<< " " 
		<< stud->getLast() 
		<< "\" added." 
		<< endl;
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

void RecursiveDelete(Node* node) {

	if (node == nullptr) { return; }

	RecursiveDelete(node->getNext());

	delete node;
}

void RecursivePrint(Node* node) {
	if (node == nullptr) { return; }

	Student* stud = node->getStudent();

	cout<< stud->getFirst()
		<< " "
		<< stud->getLast()
		<< endl
		<< "ID: "
		<< stud->getId()
		<< endl
		<< "GPA: "
		<< stud->getGpa()
		<< endl;

	RecursivePrint(node->getNext());
}




int main() {
	
	Node* head = nullptr;

	char* in = new char[80];
	bool running = true;

	while(running) {
		cin.getline(in, 80);
		if(strcmp(in, "END") == 0) {
			running = false;
		}

		if(strcmp(in, "ADD") == 0) {
	 		Add(head);
	 	}
		if(strcmp(in, "PRINT") == 0) {
			RecursivePrint(head);
		}
	}
	
	RecursiveDelete(head);

	return 0;

}

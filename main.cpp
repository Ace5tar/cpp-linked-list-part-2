#include <iostream>
#include <cstring>
#include "Student.h"
#include "node.h"

using namespace std;

// Recursive add function 
// loops over list until end or next id is greater then the current
void RecursiveAdd(Student* stud, Node* node) {
	if (node->getNext() == nullptr || node->getNext()->getStudent()->getId() > stud->getId()) {
		Node* newNode = new Node(stud);
		newNode->setNext(node->getNext());
		node->setNext(newNode);
	} else {
		RecursiveAdd(stud, node->getNext());
	}
}

// Add student function
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

// Recursively delete each node
void RecursiveDeallocate(Node* node) {

	if (node == nullptr) { return; }

	RecursiveDeallocate(node->getNext());

	delete node;
}

// Iterate over list and print each node
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

// If this nodes id = id then delete it
Node* RecursiveDelete(Node* node, int id) {
	if (node == nullptr) { return nullptr; }
	if (node->getStudent()->getId() == id) {
		Node* newNext = node->getNext();
		delete node;
		return newNext;
	}
	
	node->setNext(RecursiveDelete(node->getNext(), id));

	return node;

	}

// Prompt user for id to delete
// returns a node to set for the new head node
Node* Delete(Node* head) {
	
	int id;
	cout << "ID: ";
	cin >> id;
	cin.ignore();

	return RecursiveDelete(head, id);

	}

// Loop over each node and update an average each time
double RecursiveAverage(Node* node, double curAvg, int nodeCount) {
	if (node == nullptr) { return curAvg; }

	double newAvg = (((curAvg * (nodeCount - 1)) + node->getStudent()->getGpa()) / nodeCount);

	return RecursiveAverage(node->getNext(), newAvg, nodeCount + 1);
}

// Print the average gpa of every student
void PrintAverage(Node* head) {

	if (head == nullptr) { printf("List empty!\n");}

	printf("Average GPA: %2.f\n", RecursiveAverage(head, 0, 1));
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
		if(strcmp(in, "DELETE") == 0) {
			head = Delete(head);
		}
		if(strcmp(in, "AVERAGE") == 0) {
			PrintAverage(head);
		}
	}
	
	RecursiveDeallocate(head);

	return 0;

}

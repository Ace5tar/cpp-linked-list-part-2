#include <iostream>
#include "node.h"

using namespace std;

Node::Node(Student* inStudent){
  student = inStudent;
  nextNode = NULL;
}

Student* Node::getStudent(){
  return student;
}

Node* Node::getNext(){
  return nextNode;
}

void Node::setNext(Node* inNext){
  nextNode = inNext;
}

Node::~Node(){
  delete student;
}

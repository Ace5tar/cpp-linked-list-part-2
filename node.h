#ifndef node_h
#define node_h

#include <iostream>
#include "Student.h"
#include <cstring>

class Node{

public:

  Node(Student*); //constructor sets student* to this node
  Node* getNext(); //get next node pointer
  Student* getStudent(); //get student pointer at this node
  void setNext(Node*); //set the next node pointer
  
  ~Node(); //destructor

private:

  Student* student; //student linked to this node 
  Node* nextNode; //next node linked to this node
};

#endif

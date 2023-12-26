#ifndef NODE_H
#define NODE_H
#include "Student.h"
using namespace std;

class Node 
{
public:
    //constructor
  Node(Student* student); //Akhil: editing this to have name of variable
    //destructor
    ~Node();

    //the rest of the req fxns
    Node* getNext();
    Student* getStudent();
    void setNext(Node* nNext);

private: 
    Student* student;
    Node* next;

};

#endif

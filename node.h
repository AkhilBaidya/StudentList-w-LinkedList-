#ifndef NODE_H
#define NODE_H
#include "student.h"
using namespace std;

class Node 
{
    public:
    //constructor
    Node(Student*);
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

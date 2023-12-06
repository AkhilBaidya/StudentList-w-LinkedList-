#include "node.h"
#include <iostream>
using namespace std;
//most of this file is from the video + class heklp
Node::Node(Student* nStudent)
{
    student = nStudent;
    next = NULL;

}
Node::~Node()
{
    //explained to us in class
    delete student;
    next = NULL;

}
Node* Node::getNext()
{
    return next;
}
Student* Node::getStudent()
{
    return student;
}
void Node::setNext(Node* nNext)
{
    next = nNext;

}

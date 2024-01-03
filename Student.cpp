//C++ Programming: Linked List Project - Student Class Definitions
//by Akhil Baidya

//Date of Submission: 01/03/24

/*Note: Here, the methods of the student class are defined. This includes definitions for the constructor, destructor, and get and set methods (that get and set field values such as id, gpa, first name, and last name).*/

#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

//Constructor:
Student::Student(int theId, float theGpa, char theFirstN[20], char theSecN[20]) {
  id = theId; //set id
  gpa = theGpa; //set gpa

  firstName = new char[20]; //create space for first name
  strcpy(firstName, theFirstN); //set first name

  secondName = new char[20]; //create space for last name
  strcpy(secondName, theSecN); //set last name
}

//Destructor:
Student::~Student() { 
  delete[] firstName; //destroy the character arrays
  delete[] secondName;
}

//Get methods:
int Student::getId() {
  return id;
}
float Student::getGpa() {
  return gpa;
}
char* Student::getFirstN() {
  return firstName;
}
char* Student::getSecondN() {
  return secondName;
}

//Set methods:
void Student::setId(int newId) {
  id = newId;
}
void Student::setGpa(float newGpa) {
  gpa = newGpa;
}
void Student::setFirstN(char newFirstN[20]){
  firstName = new char[20]; //first create space for the first name
  strcpy(firstName, newFirstN);
}
void Student::setSecondN(char newSecN[20]) {
  secondName = new char[20]; //first create space for the last name
  strcpy(secondName, newSecN);
}


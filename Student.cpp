#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student(int theId, float theGpa, char theFirstN[20], char theSecN[20]) { //constructor
  id = theId;
  gpa = theGpa;

  firstName = new char[20];
  strcpy(firstName, theFirstN);

  secondName = new char[20];
  strcpy(secondName, theSecN);
}

Student::~Student() { //destructor
  delete[] firstName;
  delete[] secondName;
}

//get methods:
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

//set methods:
void Student::setId(int newId) {
  id = newId;
}
void Student::setGpa(float newGpa) {
  gpa = newGpa;
}
void Student::setFirstN(char newFirstN[20]){
  firstName = new char[20];
  strcpy(firstName, newFirstN);
}
void Student::setSecondN(char newSecN[20]) {
  secondName = new char[20];
  strcpy(secondName, newSecN);
}


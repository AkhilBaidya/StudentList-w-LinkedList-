#include <iostream>
#include <cstring>

using namespace std;

class Student {

 public:
  //constructor:
  Student(int theId, float theGpa, char theFirstN[20], char theSecN[20]);

  //destructor:
  ~Student();

  //get methods:
  int getId();
  float getGpa();
  char* getFirstN();
  char* getSecondN();

  //set methods:
  void setId(int newId);
  void setGpa(float newGpa);
  void setFirstN(char newFirstN[20]);
  void setSecondN(char newSecN[20]);
 
 protected:
  //fields
  int id;
  float gpa;
  char* firstName;
  char* secondName;
};

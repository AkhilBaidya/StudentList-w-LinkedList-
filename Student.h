//C++ Programming: Linked List Project - Student Class Header File
//by Akhil Baidya

//Date of Submission: 01/03/24

/*Note: Here, the methods and fields of the student class are stated. This includes the constructor, destructor, and get and set methods, as well as fields such as the student id, gpa, and name.*/

#include <iostream>
#include <cstring>

using namespace std;

class Student {

 public:

  //Constructor:
  Student(int theId, float theGpa, char theFirstN[20], char theSecN[20]);
  
  //Destructor:
  ~Student();

  //Get methods:
  int getId();
  float getGpa();
  char* getFirstN();
  char* getSecondN();

  //Set methods:
  void setId(int newId);
  void setGpa(float newGpa);
  void setFirstN(char newFirstN[20]);
  void setSecondN(char newSecN[20]);
 
 protected:
  //Fields
  int id;
  float gpa;
  char* firstName;
  char* secondName;
};

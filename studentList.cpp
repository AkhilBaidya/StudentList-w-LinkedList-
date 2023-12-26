//C++ Programming: Student List Project
//by Akhil Baidya

//Date of Submission (mm/dd/yy): 10/16/23

/* Notes: In this program, the user will be able to edit a list of students.
The user can input the commands "ADD," "DELETE," "PRINT" and "QUIT." QUIT
exits the program.

   1. ADD registers a new student in the list. The user inputs the student's names,
   id, and gpa (the id and gpa must be inputted as numbers).

   2. DELETE removes a student from the student list. The user must input a student
   id to identify this student to be removed.

   3. PRINT displays all the students currently registered in the student list and their info.
 */

#include <iostream>
#include <cstring>
#include "Node.o"

using namespace std;

//FUNCTION PROTOTYPES:

void ADD(Node* &prevNode, Node* &newNode);   
void PRINT(Node* &header);
void DELETE(Node* &header);
void QUIT(Node* &header, bool &running);
void AVERAGE(Node* &header);

  
//MAIN FUNCTION:

int main() { //this is where the user will input commands to edit a student list


  //Variables:
  
  bool running = true; //loops the student list program
  Node* header; //the "head" or dummy student at the beginning of the linked list
  char input[8]; //an array to store the user's inputs

  while (running) {
    
    cout << "What would you like to do? (ADD, DELETE, PRINT Students, AVERAGE gpas, QUIT program)" << endl;
    
    cin >> input;

    for (int i = 0; i < strlen(input); i++) {
      input[i] = toupper(input[i]); //convert user input to upper case (add and ADD will be considered the same)

      //referred to https://cplusplus.com/reference/cctype/toupper/ for toupper() command.
    }

    if (!strcmp(input, "QUIT")) { //if the character array (user input) spells out "QUIT"...
      cout << "quitting student list program" << endl;
      QUIT(header, running); //quit the program! (the program continues and loops if running = true)
    }

    else if (!strcmp(input, "ADD")) { //if the character array spells out "ADD"...
      cout << "Please input the information for the new student" << endl;

      char firstN[20];
      cout << "First name?" << endl;
      cin >> firstN;

      char secN[20];
      cout << "Second name?" << endl;
      cin >> secN;
      
      int id;
      cout << "ID?" << endl;
      cin >> id;
      
      float gpa;
      cout << "GPA?" << endl;
      cin >> gpa;

      Student* student = new Student(id, gpa, firstN, secN);
      Node* newNode = new Node(student);

      ADD(header, newNode); //add a student
    }

    else if (!strcmp(input, "DELETE")) { //if the character array spells out "DELETE"...
      DELETE(header); //delete a student
    }
    
    else if (!strcmp(input, "PRINT")) { //if the character array spells out "PRINT"...
      PRINT(header); //print out the students
    }

    else if (!strcmp(input, "AVERAGE")) {

      AVERAGE(header);
    }
  }
  return 0;
}


//OTHER FUNCTIONS IMPLEMENTED IN MAIN FUNCTION:


/*The ADD() function takes in the current vector of students (student pointers) and
creates a new student (and student pointer that is added to the vector).
 */

void ADD(Node* &prevNode, Node* &newNode) {
  
  Node* next = prevNode -> getNext();
  
  if (next -> getStudent() -> getId() >= newNode -> getStudent() -> getId()) { //if the next node after the prev node is greater in ID than the node we want to add, then add the new node right in front of the prev node

    prevNode -> setNext(newNode); //set the next node of the prev node to our new node
    newNode-> setNext(next); //the next node that was replaced now becomes the next node of the new node added
    return;
    
  }

  ADD(next, newNode); //for the sorting, continue doing this check for next nodes if the first next node was lesser in id than the new node we wanted to add
  
  return;
}


/* The PRINT() function takes in the current vector of students (student pointers) and
prints out each student registered (and their info).
*/
void PRINT(Node* &stud1) {

  if (stud1 -> getNext() == NULL) {
    return;
  }

  Student* student = stud1 -> getStudent();
  cout << student -> getFirstN() << " ";
  cout << student -> getSecondN() << ", ";
  cout << "ID: " << student -> getId() << ", ";
  cout << "GPA: " << student -> getGpa() << endl;

  PRINT(stud1 -> getNext()); //recurse and print out more!
  return;
    
    /*
  for (vector<Student*>::iterator student = studVec.begin(); student != studVec.end(); student++) { //iterate through each student in the vector

    referred to Mr. Galbraith's video on Vectors in Canvas to learn about using "->" to access aspects of an object pointed at
     (link in heading comments)

    cout << (*student) -> firstName << " "; //print out the first and last name of the student
    cout << (*student) -> secondName << ", ";

    cout << "ID: " << (*student) -> id << ", "; //print out the student's id

    referred to Mr. Galbraith's video on Formatting Outputs in Canvas to learn about .setf() and .precision()
      (link in heading comments)
    
    cout.setf(ios::showpoint); //want trailing zeroes in gpa (5 as 5.00)
    cout.precision(3); //restrict precision to three, allowing two decimal places for gpa
    cout << "GPA: " << (*student) -> gpa << endl; //print out the student's gpa
  }
  
  return;
*/
}

/* The DELETE() function takes in the current vector of students (student pointers) and
prompts the user for a student id. It then erases the student with that id from the student list.
*/
void DELETE(Node* &stud1) {
  /*
  //referred to this source for how to delete objects in a vector (with the .erase() command:
  //https://www.geeksforgeeks.org/cpp-stl-cheat-sheet/#T3

  This source shows how the .erase() command takes the position of an object
    in a vector and deletes the object at that position.

    The source also shows how the beginning position (of the first element
    in the vector) can be accessed through vectorName.begin())
   
  
  int rmID; //the id of the student that will be removed
  int count = 0; //counts the distance each "student" is away from the beginning
  int position = -1; //the position of the student needed to be deleted
 
  cout << "Which student do you want to remove from the student list? (Give ID)" << endl;
  cin >> rmID; //get the id of the student we want to remove


    for (vector<Student*>::iterator student = studVec.begin(); student != studVec.end(); student++) { //iterate through each student in the vector

    ++count; //increase the count (creates a "number" for each students position from studVec.begin())

     if (((*student) -> id) == rmID) { //if the student's id is equal to the id being searched for..
      position = count; //this is the position of the student we want removed!
      delete (*student); //help from Mr. Galbraith for delete command (deletes the Struct pointed to by the student pointer - removes the actual student)

    }
  }

    if (position != -1) { //if there is a student (position) with that id
      studVec.erase(studVec.begin() + position - 1); //remove student pointer at that position from the vector

      cout << "removed student" << endl;
    }

else {
      cout << "student not found" << endl;
    }
  */
  return;
}

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
void DELETE(Node* &header, int id);
bool QUIT(Node* &header);
float AVERAGE(Node* &header, float total, int num);

  
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
      running = QUIT(header); //quit the program! (the program continues and loops if running = true)
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
      cout << "Student added" << endl;
    }

    else if (!strcmp(input, "DELETE")) { //if the character array spells out "DELETE"...
      int id;
      cout << "What is the ID of the student you want to delete?" << endl;
      cin >> id;
      DELETE(header, id); //delete a student
      cout << "Deleted student" << endl;
    }
    
    else if (!strcmp(input, "PRINT")) { //if the character array spells out "PRINT"...
      PRINT(header); //print out the students
    }

    else if (!strcmp(input, "AVERAGE")) {
      float avgpa;
      avgpa = AVERAGE(header, 0.00, 0);

      cout << "The average student GPA is " << avgpa << endl;
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
void PRINT(Node* &header) {

  if (header -> getNext() == NULL) {
    return; //there are no students to print
  }

  Student* student = header -> getStudent(); //get the student
  cout << student -> getFirstN() << " ";
  cout << student -> getSecondN() << ", ";
  cout << "ID: " << student -> getId() << ", ";
  cout << "GPA: " << student -> getGpa() << endl;

  PRINT(header -> getNext()); //recurse and print out more!
  return;
}

/* The DELETE() function takes in the current vector of students (student pointers) and
prompts the user for a student id. It then erases the student with that id from the student list.
*/
void DELETE(Node* &header, int id) {

  if (header -> getNext() == NULL) {
    return;
  }
  
  Node* theNode = header -> getNext();
  Student* student = theNode -> getStudent();

  if (student -> getId() == id) {
    Node* nextNode = theNode -> getNext();
    theNode -> setNext(NULL);
    header -> setNext(nextNode); //move the deleted nodes next node to the prev nodes next node
    delete theNode;
    return;
  }

  DELETE(theNode, id);
  return;
}

bool QUIT(Node* &header) {

  if (header -> getNext() == NULL) {
    delete header;
    return false;
  }

  Node* nextNode = header -> getNext();
  header -> setNext(NULL);
  delete header;

  QUIT(nextNode, running);
  return false;
}

float AVERAGE(Node* &header, float total, int num) {
  Node* nextNode = header -> getNext();
  float gpa = header -> getStudent() -> getGpa();

  if (nextNode == NULL) {
    total += gpa;
    num++;
    return (total/num);
  }
  
  total += gpa;
  num++;
  AVERAGE(nextNode, total, num);
  return (total/num);
}

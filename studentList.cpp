//C++ Programming: Linked List Project (an extension on the Student List Project)
//by Akhil Baidya

//Date of Submission: 01/03/24

/* Notes: In this program, the user will be able to edit a list of students.
The user can input the commands "ADD," "DELETE," "PRINT," "AVERAGE," and "QUIT."

   1. ADD registers a new student in the list. The user inputs the student's names,
   id, and gpa (the id and gpa must be inputted as numbers).

   2. DELETE removes a student from the student list. The user must input a student
   id to identify this student to be removed.

   3. PRINT displays all the students currently registered in the student list and their info.
 */

#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

//FUNCTION PROTOTYPES:
void ADD(Node* &prevNode, Node* &newNode);   
void PRINT(Node* &header);
void DELETE(Node* &header, int id);
bool QUIT(Node* &header);
float AVERAGE(Node* &header, float &total, int &num);


//MAIN FUNCTION:
//In this function, the user will input commands to edit a list of students
int main() {
  
  //Variables:
  bool running = true; //This will loop the interface prompting the user for commands

  //This creates the dummy student at the head of the linked list (allows students to then be added to a list recursively)
  char dumName1[20] = "Dummy";
  char dumName2[20] = "Student";
  int id = -1;
  float gpa = 0.00;
  Student* student = new Student(id, gpa, dumName1, dumName2);
  Node* header = new Node(student);
  header -> setNext(NULL); //The head of the linked list has no "next node/student" yet

  char input[8]; //An array to store the user's inputs (commands)

  //Command-input loop:
  while (running) {
    
    cout << "What would you like to do? (ADD, DELETE, PRINT Students, AVERAGE gpas, QUIT program)" << endl;
    
    cin >> input;

    /*This for loop is taken from my Student List Project at
      https://github.com/AkhilBaidya/StudentList: */
    for (int i = 0; i < strlen(input); i++) {
      input[i] = toupper(input[i]); //converts each letter of whatever the user inputted to uppercase (the toupper() method was found on cplusplus.com at https://cplusplus.com/reference/cctype/toupper/)
    }

    if (!strcmp(input, "QUIT")) { //if the user inputs "QUIT"...
      cout << "quitting student list program" << endl;
      running = QUIT(header); //running is set to false ending the loop and program
    }

    else if (!strcmp(input, "ADD")) { //if the user inputs "ADD"...
      cout << "Please input the new student details" << endl;

      char firstN[20]; //input the first name
      cout << "First name?" << endl;
      cin >> firstN;

      char secN[20]; //input the last name
      cout << "Last name?" << endl;
      cin >> secN;
      
      int id; //input the student id
      cout << "ID?" << endl;
      cin >> id;
      
      float gpa; //input the gpa
      cout << "GPA?" << endl;
      cin >> gpa;

      Student* student = new Student(id, gpa, firstN, secN);
      Node* newNode = new Node(student); //create the student and the node that contains it
      
      ADD(header, newNode); //add the node to the linked list, which begins at node "header"
      cout << "Added student" << endl;
    }

    else if (!strcmp(input, "DELETE")) { //if the user inputs "DELETE"...
      int id;
      cout << "What is the ID of the student you want to delete?" << endl;
      cin >> id; //get id of student user wants to delete
      
      DELETE(header, id); //delete the node in the linked list (the linked list starts with node "header") that has a student with that id
      
      cout << "Deleted student" << endl;
    }
    
    else if (!strcmp(input, "PRINT")) { //if the user inputs "PRINT"...
      PRINT(header); //print out the students in the linked list
    }

    else if (!strcmp(input, "AVERAGE")) { //if the user inputs "AVERAGE"...
      float avgpa; //this will store the average gpa
      float begTot = 0; //this will store the sum of current gpas
      int begNum = 0; //this will store the number of current students

      avgpa = AVERAGE(header -> getNext(), begTot, begNum); //get the gpa

      if (avgpa < 0) { //the AVERAGE function returns -1.5 if there are no students
	cout << "There are no students" << endl;
      }
      else {
	cout << "The average student GPA is " << avgpa << endl;
      }
    }
  }
  return 0;
}


//OTHER FUNCTIONS IMPLEMENTED IN MAIN FUNCTION:

/*The ADD() function recursively checks through each node "prevNode" in the linked list, starting with the dummy header node. When the upcoming node after prevNode has an id greater than that of the newNode we want to add, make the newNode the node right after the prevNode and the node right before that upcoming node. Else, continue recursing through each node in the list*/

void ADD(Node* &prevNode, Node* &newNode) {
  Node* next = prevNode -> getNext(); 

  if (next == NULL) { //if the next node is empty, the newNode has to be added in that position
    prevNode -> setNext(newNode);
    return;
  }
  
  else if (next -> getStudent() -> getId() >= newNode -> getStudent() -> getId()) { //if the next node after the prev node is greater in ID than the node we want to add, then add the new node right in front of the prev node

    prevNode -> setNext(newNode); //set the next node of the prev node to our new node
    newNode-> setNext(next); //the next node that was replaced now becomes the next node of the new node added
    return;  
  }

  ADD(next, newNode); /*for the sorting (we want the student ids to be ordered from least to greatest and the next node to be greater in id than the new node we want to add), continue doing this check for next nodes if the first next node was lesser in id than the new node we wanted to add */
  
  return;
}


/* The PRINT() function takes in a node and prints out the details of its student (name, id, and gpa). It recurses, printing details for the next node in the linked list, until the next node is null (where it has reached the end of the list)*/
void PRINT(Node* &header) {

  Node* next = header -> getNext();
  
  if (next == NULL) { //this is the last node in the linked list
    Student* student = header -> getStudent(); //get the student and print out their details one last time
    cout << student -> getFirstN() << " ";
    cout << student -> getSecondN() << ", ";
    cout << "ID: " << student -> getId() << ", ";

    //This code to set the formatting of the output was taken from Mr. Galbraith's video on Canvas on Formatting Outputs at https://www.youtube.com/watch?v=kv8XRxxaD8Q&t=232s
    cout.setf(ios::showpoint); //allow trailing zeroes to be seen
    cout.precision(3); //allow for only two decimal places to be seen
  cout << "GPA: " << student -> getGpa() << endl;

    return; //there are no more students to print
  }

  //Normally:
  Student* student = header -> getStudent(); //get the student

  if (student -> getId() >= 0) { //if the student is not the dummy student (which has a negative id)
    cout << student -> getFirstN() << " ";
    cout << student -> getSecondN() << ", ";
    cout << "ID: " << student -> getId() << ", ";

    cout.setf(ios::showpoint);
    cout.precision(3);
    cout << "GPA: " << student -> getGpa() << endl;
  }
  
  PRINT(next); //recurse and print out details for more nodes!
  return;
}


/* The DELETE() function takes in the id of the student the user wants to delete and deletes that student and the node containing it from the linked list (some header node needs to be inputted into this function to enter this linked list). It recursively searches through each node in the linked list to see if it has the student that the user wants to delete*/
void DELETE(Node* &header, int id) {

  if (header -> getNext() == NULL) { //the program has reached the end of the linked list (there is no next node)
    return;
  }
  
  Node* theNode = header -> getNext(); //get the next node
  Student* student = theNode -> getStudent(); //get its student

  if (student -> getId() == id) {
    Node* nextNode = theNode -> getNext(); //get the node after the node that has the student id we want

    theNode -> setNext(NULL); //disconnect the node we want to delete from the nodes placed after it (by setting its next node to null)
    header -> setNext(nextNode); /*move the current node's "next node" to the next nodes's next node (the node after the node we want to delete), completely disconnecting the node we want to delete from the linked list*/
    
    delete theNode;
    return;
  }

  DELETE(theNode, id); //continue searching for the node with the student id we want if not found already (now looking at the node right after the previous node) 
  return;
}


/**/
bool QUIT(Node* &header) {

  if (header -> getNext() == NULL) {
    delete header;
    return false;
  }

  Node* nextNode = header -> getNext();
  header -> setNext(NULL);
  delete header;

  QUIT(nextNode); //recursively delete every node
  return false;
}

float AVERAGE(Node* &header, float &total, int &num) {
  if (header == NULL) {
    return -1.5;
  }
  Node* nextNode = header -> getNext();
  float gpa = header -> getStudent() -> getGpa();
  num++;
  
  if (nextNode == NULL) {
    total += gpa;
    return total/num;
  }

  total += gpa;
  return (0 + AVERAGE(nextNode, total, num));
}


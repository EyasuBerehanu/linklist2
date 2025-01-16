//Eyasu Berehanu
//12/25/2024
//This program ask for student info and you can add it in this game, print all the info as you can add mutiple student info, and delete info when certin id is imputed, you can also quit the list
//Help from: https: (erases vector)//www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/
//(what is a vector) https://www.youtube.com/watch?v=Cq1h1KPoGBU&t=883s&ab_channel
#include <iostream>
#include <cstring>
#include <vector> 
#include <cmath> //allows me to round the gpa variable
#include "head.h"
#include "student.h"

using namespace std;


void add(Node*& head); //calls the add function so it can be read in the int main
void print(Node*& head); //calls the print funtion so it can be read in the int main 
void deletee(Node*& head); //calls the delete funtion so it can be read in the int main (I called it deletee because delete dont work)

int main() {
  Node* head = nullptr; 
    string input;
    bool start = true;

    while (start = true) { //while true it will ask this prompt, only quit will make it false
        cout << "Enter ADD, PRINT, DELETE, or QUIT " << endl;
        cin >> input;

        if (input == "ADD") {
            add(head);
        } else if (input == "PRINT") {
            print(head);
        } else if (input == "DELETE") {
            deletee(head);
        } else if (input == "QUIT") {
            return false; 
	} else {
	  cout << "invalid" << endl;
	}
    }
    return 0;
}

void add(Node*& head) {
    int id;
    double gpa;
    char firstName[25], lastName[25];

    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter student ID: ";
    cin >> id;
    cout << "Enter GPA: ";
    cin >> gpa;

    Student* newStudent = new Student(id, gpa, firstName, lastName);
    Node* newNode = new Node(newStudent);

    if (head == nullptr) {
        head = newNode;
    } else if (head->getStudent()->getID() > newStudent->getID()) {
        newNode->setNext(head);
        head = newNode;
    } else {
        add(head->getNext());
    }
}


void print(vector<Student>& student) { //prints out all inputed stuent info by users
    
    for (int i = 0; i < student.size(); ++i) { 
        float roundedGPA = round(student[i].gpa * 100) / 100;
        cout << student[i].firstName << " " << student[i].lastName << ", " << student[i].id << ", " << roundedGPA << endl;
    
    }
}


void deletee(Node*& head) { //Deletes inputs based on the corresponding ID
    int deleteId = 0;
    
    cout << "Enter student ID to delete: ";
    cin >> deleteId;

    for (int i = 0; i < students.size(); ++i) { //makes sure every element is accounted for
        if (students[i].id == deleteId) {
	  students.erase(students.begin() + i); //removes elemnts from vector
            cout << "ID " << deleteId << " deleted." << endl;
            return;  
        }
    }

    cout << "ID not found." << endl;
}

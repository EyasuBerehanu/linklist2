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
//void print(Node*& head); //calls the print funtion so it can be read in the int main 
//void deletee(Node*& head); //calls the delete funtion so it can be read in the int main (I called it deletee because delete dont work)

int main() {
    char input[80];
    bool running = true;
    Node* head = nullptr;

    bool start = true;

    while (start = true) { 
        cout << "Enter ADD, PRINT, DELETE, or QUIT " << endl;
        cin.getline(input, 80, '\n');

        if (strcmp(input, "ADD") == 0) {
            char names[80];
            cout << "Enter name: " << endl;;
            cin.getline(input, 80, '\n');
            strcpy(names, input);

            double gpa;
            int id;
            int x;
            double y;
            cout << "Enter ID: " << endl;
            cin >> x;
            id = x;

            cout << "Enter GPA: " << endl;
            cin >> y;
            gpa = y;

    
            student* tempSt = new student(id, gpa, names);
            add(head, head, tempSt);
        } else if (strcmp(input, "PRINT") == 0) {
            print(head);
        } else if (strcmp(input, "DELETE") == 0) {
            cout << "Enter ID to delete: " << endl;
            cin.getline(input, 80, '\n');
            deleteNode(head, head, atoi(input));
        } else if (strcmp(input, "QUIT") == 0) {
            running = false;
        } else {
            //cout << "Invalid please try again." << endl;
        }
    }

    return 0;
}

void add(Node*& head, int n, double g, const char* names) {
   add(head->getNext(), n, g, names);
}

// Function to print all the students
void print(Node* head) {
    if (head == nullptr) {
        return;  // Base case: If the list is empty, just return
    }

    // Print the data of the current student
    cout << "Name: " << head->getStudent()->getName() << ", ";
    cout << "Student ID: " << head->getStudent()->getID() << ", ";
    cout << "GPA: " << head->getStudent()->getGpa() << endl;

    // Recursive call to print the rest of the list
    print(head->getNext());
}

/*
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
*/

//Eyasu Berehanu
//12/25/2024
//This program ask for student info and you can add it in this game, print all the info as you can add mutiple student info, and delete info when certin id is imputed, you can also quit the list
//Help from: https: (erases vector)//www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/
//(what is a vector) https://www.youtube.com/watch?v=Cq1h1KPoGBU&t=883s&ab_channel
#include <iostream>
#include <cstring>
#include <vector> 
#include <cmath>
#include <iomanip> //allows me to round the gpa variable
#include "head.h"
#include "student.h"

using namespace std;


void add(Node*& head, Node* current, student* newStudent); //calls the add function so it can be read in the int main
void print(Node* next); //calls the print funtion so it can be read in the int main 
void deletee(Node*& head, Node* current, int id); //calls the delete funtion so it can be read in the int main (I called it deletee because delete dont work)

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
            deletee(head, head, atoi(input));
        } else if (strcmp(input, "QUIT") == 0) {
	  return 0;
        } else {
            //cout << "Invalid please try again." << endl;
        }
    }

    return 0;
}

void add(Node*& head, Node* current, student* newStudent) {
    if (head == nullptr) {
        head = new Node();
        head->setStudent(newStudent);
        head->setNext(nullptr);
    } else if (current == nullptr || current->getStudent()->getID() > newStudent->getID()) {
        Node* newNode = new Node();
        newNode->setStudent(newStudent);
        newNode->setNext(current);

        if (current == head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->getNext() != current) {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
        }
    } else {
        add(head, current->getNext(), newStudent);
    }
}

void print(Node* next) {
    if (next == nullptr) {
        cout << "No students in list" << endl;
        return;
    }

    cout << fixed << setprecision(2);
    next->getStudent()->printData();

    print(next->getNext());
}

void deletee(Node*& head, Node* current, int id) {
    if (current == nullptr) {
        cout << "Student with ID " << id << " not found." << endl;
        return;
    }

    if (current == head && current->getStudent()->getID() == id) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
        cout << "Student with ID " << id << " deleted." << endl;
        return;
    }

    if (current->getNext() != nullptr && current->getNext()->getStudent()->getID() == id) {
        Node* temp = current->getNext();
        current->setNext(temp->getNext());
        delete temp;
        cout << "Student with ID " << id << " deleted." << endl;
        return;
    }

    deletee(head, current->getNext(), id);
}

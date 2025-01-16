//Eyasu Berehanu
//12/25/2024
//This program ask for student info and you can add it in this game, print all the info as you can add mutiple student info, and delete info when certin id is imputed, you can also quit the list
//Help from: https: (erases vector)//www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/
//(what is a vector) https://www.youtube.com/watch?v=Cq1h1KPoGBU&t=883s&ab_channel
#include <iostream>
#include <cstring>
#include <vector> 
#include <cmath> //allows me to round the gpa variable

using namespace std;

struct Student;

void add(vector<Student>& students); //calls the add function so it can be read in the int main
void print(vector<Student>& students); //calls the print funtion so it can be read in the int main 
void deletee(vector<Student>& students); //calls the delete funtion so it can be read in the int main (I called it deletee because delete dont work)

struct Student { //creats a struct containing all student related info
    char firstName[80];
    char lastName[80];
    int id;
    float gpa;
};

int main() {
    vector<Student> students; 
    string input;
    bool start = true;

    while (start = true) { //while true it will ask this prompt, only quit will make it false
        cout << "Enter ADD, PRINT, DELETE, or QUIT " << endl;
        cin >> input;

        if (input == "ADD") {
            add(students);
        } else if (input == "PRINT") {
            print(students);
        } else if (input == "DELETE") {
            deletee(students);
        } else if (input == "QUIT") {
            return false; 
	} else {
            cout << "invalid input try again" << endl;
        }
    }

    return 0;
}

void add(vector<Student>& students) { //when you say ADD it asks for you to input all the student info lik name id and gpa
    Student nerd; 

    cout << "Enter First Name: " << endl;
    cin >> nerd.firstName;

    cout << "Enter Last Name: " << endl;
    cin >> nerd.lastName;
    
    cout << "Enter ID (Like 123456): " << endl;
    cin >> nerd.id;
    
    cout << "Enter GPA (num should be from 0 to 4 range): " << endl;
    cin >> nerd.gpa;
    
    while (nerd.gpa > 4.0) {  //make sure gpa dosnt go higher then 4.0
        cout << "Gpa should be from 0 - 4: " << endl;
        cin >> nerd.gpa;
    }
    

    students.push_back(nerd); //puts incerted info into the back
}


void print(vector<Student>& student) { //prints out all inputed stuent info by users
    
    for (int i = 0; i < student.size(); ++i) { 
        float roundedGPA = round(student[i].gpa * 100) / 100;
        cout << student[i].firstName << " " << student[i].lastName << ", " << student[i].id << ", " << roundedGPA << endl;
    
    }
}

void deletee(vector<Student>& students) { //Deletes inputs based on the corresponding ID
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

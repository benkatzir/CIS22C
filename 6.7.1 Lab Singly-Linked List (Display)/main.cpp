/*
 CIS 22C
 
 This program builds and displays a sorted list.
 The list is sorted in ascending order by name.
 
 Requirement 
 Overload the displayList() function as shown below:
 list.displayList();    // displays the entire list
 list.displayList(3.0); // displays all students with the gpa below or equal to 3.0.
 list.displayList(3.1, 3.9); // displays all students with the gpa within this range, inclusive. 
 
 Written by: A. Student
 Reviewed by: Ben Katzir
 IDE: VS Code
 
 */
#include <iostream>
#include <sstream>
#include "StudentList.h"
using namespace std;

void buildList(StudentList &);

int main()
{
    // Define a StudentList object
    StudentList list;
    
    buildList(list); // insert data into the list
    
    list.displayList();
    double gpa;
    cout << "Enter a gpa: ";
    cin >> gpa;
    list.displayList(gpa);
    double from, to;
    cout << "Enter a gpa range: ";
    cin >> from >> to;
    list.displayList(from, to);

    
    return 0;
}
/* **************************************
This function builds a sorted linked list with data from the keyboard.
The list is sorted in ascending order by the students' names.
It calls the insertNode() function that inserts the new data at the right location in the linked list.
An input line contains the gpa of a student follow by its name (assume it is a single word name)
To stop reading enter "#"
************************************** */
void buildList(StudentList &list)
{
    string line;
    getline(cin, line);
    while (line != "#")
    {
       stringstream temp(line); // create a stringstream named temp with data from line
       Student newStu;
       temp >> newStu.gpa;  // read gpa from temp
       temp >> newStu.name; // read name from temp
       list.insertNode(newStu);
       getline(cin, line);
    }
}
  


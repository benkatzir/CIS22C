/*
 CIS 22C  // Student is a class, Linked List Node is a class
 
 This program builds and displays a sorted list
 The list is sorted in ascending order by name
 
 Written by: A. Student
 Reviewed & Modified by: Ben Katzir
 IDE: VS Code
 
 */
#include <iostream>
#include <sstream>
#include <string>
#include "StudentList.h"
using namespace std;

void buildList(StudentList &);
void deleteTestDriver(StudentList &);

int main()
{
    // Define a StudentList object
    StudentList list;
    
    buildList(list); // insert data into the list
    
    list.displayList();
    string answer;
    cout << "Test Delete [Y/N]?\n";
    cin >> answer;
    if (answer == "Y" || answer == "y")
    {
        deleteTestDriver(list);
        list.displayList();
    }
    return 0;
}

// ***************************************************
// This function builds a sorted linked list with data from the keyboard.
// The list is sorted in ascending order by the students' names.
// It calls the insertNode() function that inserts the new data at the right location in the linked list.
// An input line contains the gpa of a student follow by its name (assume it is a single word name)
// To stop reading enter "#"
// ***************************************************
void buildList(StudentList &list)
{
   string line, name;
   double gpa;

   getline(cin, line);
   while (line != "#")
   {
      stringstream temp(line); // create a stringstream named temp with data from line
      temp >> gpa;  // read gpa from temp
      temp >> name; // read name from temp
      Student newStu(gpa, name);
      list.insertNode(newStu);
      getline(cin, line);
   }
}

// ***************************************************
// This function is a test driver for the 
// linked list delete function
// ***************************************************
void deleteTestDriver(StudentList &list)
{
    string toDelete; 
    
    cout << "Enter strings to be deleted (# to stop)" << endl;
    cin >> toDelete;       
    while (toDelete != "#")
    {
        cout << "   " << toDelete;
        if (list.deleteNode(toDelete) ) // call deleteNode() 
            cout << " - deleted\n";
        else
            cout << " - not found\n";
        cin >> toDelete;         
    }
    cout << endl;
}

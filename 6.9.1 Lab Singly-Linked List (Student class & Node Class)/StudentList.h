// Specification file for the Student List class
// Written by: A. Student
// Reviewed by: Ben Katzir
// IDE: VS Code

#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "ListNode.h"

class StudentList
{
private:
    ListNode *head;      // List head pointer
    int count;           // To keep track of the number of nodes in the list
    
    
public:
    StudentList();  // Constructor
    ~StudentList();   // Destructor
    
    // Linked list operations
    int getCount() const {return count;}
    void insertNode(Student);
    bool deleteNode(string target);
    //void searchList() const;
    void displayList() const;
};
#endif


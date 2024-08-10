// Specification file for the StudentList class
// Written by: A. Student
// Reviewed by: Ben Katzir
// IDE: VS Code

#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include <iostream>
struct Student
{
    double gpa;
    std::string name;
};

class StudentList
{
private:
    // Declare a node structure for the linked list
    struct ListNode
    {
        Student stu;     // The value in this node
        ListNode *next;  // To point to the next node
    };
    
    ListNode *head;      // List head pointer
    int count;           // To keep track of the number of nodes in the list
    

public:
    StudentList();  // Constructor
   ~StudentList();   // Destructor
    
    // Linked list operations
    int getCount() const {return count;}
    void insertNode(Student);
    void displayList() const;
   
};
#endif

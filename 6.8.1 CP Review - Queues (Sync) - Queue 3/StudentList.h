// Specification file for the Student List class
// Written by: A. Student
// Reviewed by: Ben Katzir
// IDE: VS Code

#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "Student.h"


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
    bool deleteNode(std::string target);
    //void searchList() const;
    void displayList() const;
};
#endif


// Specification file for the LinkedList class
// Written By: A. Student
// Reviewed by: Ben Katzir
// IDE: VS Code


#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListNode.h"
class LinkedList
{
private:
    ListNode *head;
    int length;

public:
    LinkedList();   // constructor
    ~LinkedList();  // destructor

    // Linked list operations
    int getLength() const {return length;}
    bool isEmpty() const { return length == 0; }
    void insertNode(Park);
    bool deleteNode(string);
    void displayListForw() const;
    void displayListBack() const;
    bool searchList(string, Park &) const;
};

#endif


// Specification file for the LinkedList class
// Written By: A. Student
// Reviewed by: Ben Katzir
// IDE: VS Code

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Park.h"

class LinkedList
{
private:
    struct Node
    {
        Park park;
        Node *next;
    };

    Node *head;
    int length;

public:
    LinkedList();   // constructor
    ~LinkedList();  // destructor

    // Linked list operations
    int getLength() const {return length;}
    void insertNode(Park);
    bool deleteNode(string);
    void displayList() const;
    bool searchList(string, Park &) const;
};

#endif

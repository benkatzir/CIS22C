// Sorted Circular Doubly-Linked List with Sentinel Node
// Implementation file for the Student List class
// Written by: A. Student
// Reviewed & Modified by: Ben Katzir
// IDE: VS Code
#include <iostream>         // For cout  and NULL
#include "StudentList.h"
using namespace std;

// **************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
// **************************************************
StudentList::StudentList()
{
    head = new ListNode; // head points to the sentinel node
    
    head->stu.gpa = -1;
    head->stu.name = "";
    head->forw = head;
    /* Write your code here */
    head->back = head;
    count = 0;
}

// **************************************************
// display list forwards: shows the value
// stored in each node of the linked list
// pointed to by head. from A to Z
// **************************************************
void StudentList::displayListForw() const
{
    ListNode *pCur;  // To move through the list

    // Position pCur: skip the head of the list.
    pCur = head->forw;

    // While pCur points to a node, traverse the list.
    while (pCur != head)
    {
        // Display the value in this node.
        cout << pCur->stu.gpa << " " << pCur->stu.name << endl;

        // Move to the next node.
        pCur = pCur->forw;
    }
    cout << endl;
}
// **************************************************
// display list forwards: shows the value
// stored in each node of the linked list
// pointed to by head, from Z to A
// **************************************************

void StudentList::displayListBack() const
{
    ListNode *pCur;  // To move through the list

    // Position pCur: skip the tail of the list.
    pCur = head->back;

    // While pCur points to a node, traverse the list.
    while (pCur != head)
    {
        // Display the value in this node.
        cout << pCur->stu.gpa << " " << pCur->stu.name << endl;

        // Move to the next node.
        pCur = pCur->back;
    }
    
    cout << endl;
}
// **************************************************
// The insertNode function inserts a node with
// stu copied to its value member.
// **************************************************
void StudentList::insertNode(Student dataIn)
{
    ListNode *newNode;  // A new node
    ListNode *pCur;     // To traverse the list
    
    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->stu = dataIn;

    // Initialize pointers
    pCur = head->forw;
   
    // Find location: skip all nodes whose name is less than dataIn's name
    while (pCur != head && pCur->stu.name < dataIn.name)
    {
        pCur = pCur->forw;
    }

    // Insert the new node between pPre and pCur
    ListNode *pPre = pCur->back;     // The previous node
    pPre->forw = newNode;
    newNode->forw = pCur;
    
     /* Write your code here */
    newNode->back = pPre;
    pCur->back = newNode;
    // Update the counter
    count++;
}

// **************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// **************************************************
StudentList::~StudentList()
{
  
}

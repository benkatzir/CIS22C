// Implementation file for the LinkedList class
// Written By: A. Student
// Reviewed & Modified by: Ben Katzir
// IDE: VS Code

#include <iostream>
#include "LinkedList.h"

using namespace std;

//**************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
//**************************************************
LinkedList::LinkedList()
{
    head = new ListNode; // head points to the sentinel node
    head->setNext(head);
    head->setPrev(head);
    length = 0;
}

// **************************************************
// The insertNode function inserts a new node in a
// sorted linked list
// **************************************************
void LinkedList::insertNode(Park dataIn)
{
    ListNode *newNode;  // A new node
    ListNode *pCur;     // To traverse the list
    ListNode *pPre;     // The previous node
    
    // Allocate a new node and store num there.
    newNode = new ListNode(dataIn);

    // Initialize pointers
    pCur = head->getNext();

    // Find location: skip all nodes whose code is less than dataIn's code
    while (pCur != head && newNode->getData().getCode() > pCur->getData().getCode())
    {
        pCur = pCur->getNext();
    }
    
    // Insert the new node between pPre and pCur
    pPre = pCur->getPrev();
    pPre->setNext(newNode);
    newNode->setNext(pCur);
    
   /* Write your code here */
    newNode->setPrev(pPre);
    pCur->setPrev(newNode);
    
    // Update the counter
    length++;
}

// **************************************************
// The deleteNode function searches for a node
// in a sorted linked list; if found, the node is
// deleted from the list and from memory.
// **************************************************
bool LinkedList::deleteNode(string target)
{
    ListNode *pCur;       // To traverse the list
    ListNode *pPre;       // To point to the previous node
    bool deleted = false;
    
    // Initialize pointers
    pCur = head->getNext();

    // Find node containing the target: Skip all nodes whose gpa is less than the target
    while (pCur != head && pCur->getData().getCode() < target)
    {
        pCur = pCur->getNext();
    }
    
    // If found, delte the node
    if (pCur->getData().getCode() == target)
    {
        pPre = pCur->getPrev();
        pPre->setNext(pCur->getNext());
        
      /* Write your code here */
        pCur->getNext()->setPrev(pPre);
        delete pCur;
        deleted = true;
        length--;
    }
    return deleted;
}

// **************************************************
// displayListForw() shows the value
// stored in each node of the linked list
// pointed to by head, except the sentinel node,
// from head to tail (ascending order).
// **************************************************
void LinkedList::displayListForw() const
{
     ListNode *pCur;  // To move through the list

     // Position pCur: skip the head of the list.
     pCur = head->getNext();

     // While pCur points to a node, traverse the list.
     while (pCur != head)
     {
         // Display the value in this node.
         pCur->getData().hDdisplay();
         
         // Move to the next node.
         pCur = pCur->getNext();
    }
    cout << endl;
}

// **************************************************
// displayListBack() shows the value
// stored in each node of the linked list
// pointed to by head, except the sentinel node.
// from tail to head (descending order).
// **************************************************
void LinkedList::displayListBack() const
{
    ListNode *pCur;  // To move through the list

    // Position pCur: skip the tail of the list.
    pCur = head->getPrev();

    // While pCur points to a node, traverse the list.
    while (pCur != head)
    {
         // Display the value in this node.
         pCur->getData().hDdisplay();

        // Move to the next node.
        pCur = pCur->getPrev();
    }

    cout << endl;
}
// **************************************************
// The searchList function looks for a target college
// in the sorted linked list: if found, returns true
// and copies the data in that node to the output parameter
// **************************************************
bool LinkedList::searchList(string target, Park &dataOut) const
{
    bool found = false; // assume target not found
    ListNode *pCur;         // To move through the list
    
    // Position pCur: skip the head of the list.
    pCur = head->getNext();
    // Find location: skip all nodes whose code is less than target
   /* Write your code here */
    while (pCur != head && pCur->getData().getCode() < target)
    {
        pCur = pCur->getNext();
    }
 
    // If found, copy data to the output parameter, and change the flag to true
   /* Write your code here */
    if (pCur->getData().getCode() == target){
        found = true;
        dataOut = pCur->getData();
    };
    
    return found;
}

// **************************************************
// Destructor
// This function deletes every node in the list.
// **************************************************
LinkedList::~LinkedList()
{
    ListNode *pCur;     // To traverse the list
    ListNode *pNext;    // To hold the address of the next node
    
    // Position nodePtr: skip the head of the list
    pCur = head->getNext();
    // While pCur is not at the end of the list...
    while(pCur != head)
    {
        // Save a pointer to the next node.
        pNext = pCur->getNext();
        
        // Delete the current node.
        delete pCur;
        
         // Position pCur at the next node.
        pCur = pNext;
    }
    
    delete head; // delete the sentinel node
}

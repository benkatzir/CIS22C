// Implementation file for the Student List class
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
    head->next = NULL;
    count = 0;
}

// **************************************************
// displayList shows the value
// stored in each node of the linked list
// pointed to by head.                              
// **************************************************

void StudentList::displayList() const
{
    ListNode *pCur;  // To move through the list

    // Position pCur: skip the head of the list.
    pCur = head->next;

    // While pCur points to a node, traverse the list.
    cout << endl;
    while (pCur)
    {
        // Display the value in this node.
        cout << pCur->stu.gpa << " " << pCur->stu.name << endl;

        // Move to the next node.
        pCur = pCur->next;
    }
    cout << endl;
}


// **************************************************
// the first overloaded displayList: ...
// 
//                               
// **************************************************
/* Write your code here, including comment above */
void StudentList::displayList(double gpa) const
{
    ListNode *pCur;  // To move through the list

    // Position pCur: skip the head of the list.
    pCur = head->next;

    // While pCur points to a node, traverse the list.
    cout << endl;
    while (pCur)
    {   
        if (pCur->stu.gpa <= gpa) {
            // Display the value in this node.
            cout << pCur->stu.gpa << " " << pCur->stu.name << endl;
        }

        // Move to the next node.
        pCur = pCur->next;
    }
    cout << endl;
}


// **************************************************
// the second overloaded displayList: ...
// 
//                               
// **************************************************
/* Write your code here, including comment above */
void StudentList::displayList(double gpa1, double gpa2) const
{
    ListNode *pCur;  // To move through the list

    // Position pCur: skip the head of the list.
    pCur = head->next;

    // While pCur points to a node, traverse the list.
    cout << endl;
    while (pCur)
    {   
        if ((pCur->stu.gpa >= gpa1 && pCur->stu.gpa <= gpa2) || (pCur->stu.gpa <= gpa1 && pCur->stu.gpa >= gpa2)) {
            // Display the value in this node.
            cout << pCur->stu.gpa << " " << pCur->stu.name << endl;
        }

        // Move to the next node.
        pCur = pCur->next;
    }
    cout << endl;
}




// **************************************************
// The insertNode function inserts a node with
// dataIn copied to its stu member.
// **************************************************
void StudentList::insertNode(Student dataIn)
{
    ListNode *newNode;  // A new node
    ListNode *pCur;     // To traverse the list
    ListNode *pPre;     // The previous node
    
    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->stu = dataIn;

    // Initialize pointers
    pPre = head;
    pCur = head->next;
   
    // Find location: skip all nodes whose gpa is less than dataIn's gpa
    while (pCur != NULL && pCur->stu.name < dataIn.name)
    {
        pPre = pCur;
        pCur = pCur->next;
    }

    // Insert the new node between pPre and pCur
    pPre->next = newNode;
    newNode->next = pCur;
    
    // Update the counter
    count++;
}

//**************************************************
// Destructor                                       
// This function deletes every node in the list.    
//**************************************************
StudentList::~StudentList()
{
   // this function definition is not required 
}


/* 
Written by: Ben Katzir
=============================
   Stack template
*/

#ifndef STACK_ADT
#define STACK_ADT
#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
   // Structure for the stack nodes
   struct StackNode {
       T value;           // Value in the node
       StackNode *next;     // Pointer to next node
   };

   StackNode *top;          // Pointer to the stack top
   int length;

public:
   Stack(){ top = NULL; length = 0; }    //Constructor
   ~Stack();                          // Destructor

   // Stack operations
    bool isEmpty() {
        return top == nullptr;
    }

    bool push(T item);
    T pop();
    T peek() {
        return top->value;
    }
    int getLength() {
        return length;
    }
};


/**~*~*~*
  Member function push: pushes the argument onto the stack.
*~**/
template <typename T>
bool Stack<T>::push(T item)
{
   StackNode *newNode; // Pointer to a new node

   // Allocate a new node and store item there.
   newNode = new StackNode;
   if (!newNode)
       return false;
   newNode->value = item;

   // Update links and counter
   newNode->next = top;
   top = newNode;
   length++;

   return true;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) { // only print "Empty" if the showsEmpty parameter is true
        cout << " Empty";
    }

    T item = top->value;
    StackNode *temp = top;
    top = top->next;
    delete temp;
    length--;
    return item;
}

/* 
  Destructor:
  Traverses the list deleting each node (without calling pop)
*/
template <typename T>
Stack<T>:: ~Stack(){
    StackNode *currNode = top;
    StackNode *nextNode;

    while (currNode) 
    {
        nextNode = currNode->next; // Store the next node
        delete currNode; // Delete the current node
        currNode = nextNode; // Move to the next node
    }
};



#endif

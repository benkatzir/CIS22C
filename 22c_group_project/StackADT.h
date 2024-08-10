/*
Description:
Implements a stack using a linked list structure. Supports push, pop, peek, isEmpty operations, and tracks stack length. Suitable for generic type T, ensuring efficient memory management and stack operations.
*/
#ifndef STACK_ADT
#define STACK_ADT

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template <typename T>
class Stack
{
private:
    // Structure for the stack nodes
    struct StackNode
    {
        T value;          // Value in the node
        StackNode* next;  // Pointer to next node
    };

    StackNode* top;     // Pointer to the stack top
    int length;

public:
    // Constructor, Destructor
    Stack() { top = NULL; length = 0; }
    ~Stack();

    // Stack operations
    bool push(T item);
    T pop();
    T peek() { return top->value; }
    bool isEmpty() { return (!top); }
    int getLength() { return length; }
};

/*
  Member function push inserts the argument onto
  the stack.
*/
template <typename T>
bool Stack<T>::push(T item) {
    StackNode* newNode;

    // Allocate a new node and store item there.
    newNode = new StackNode;
    if (!newNode) { return false; }
    newNode->value = item;

    // Update links and counter
    newNode->next = top;
    top = newNode;
    length++;

    return true;
}

/*
  Member function pop deletes the value at the top
  of the stack and returns it.
  Assume stack is not empty.
*/
template <typename T>
T Stack<T>::pop() {
    StackNode* temp = top; // temp was nullptr

    T val = temp->value;
    top = top->next;
    delete temp; // delete temp
    length--; // update length

    return val;
}

/*
  Destructor:
  Traverses the list deleting each node (without calling pop)
*/
template <typename T>
Stack<T>::~Stack() {
    StackNode* currNode; // iteration node

    currNode = top;

    while (currNode) {
        top = top->next;
        delete currNode;
        length--; // update length
        currNode = top;
    }
}

#endif
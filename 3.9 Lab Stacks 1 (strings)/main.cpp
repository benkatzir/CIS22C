/**~*~*~*
CIS 22C
Project: Stack of strings

Written by: Ben Katzir
IDE: zyDE (zyBooks)
*~*/
#include <iostream>
#include <string>
using namespace std;

class Stack_str
{
private:
   // Structure for the stack nodes
   struct StackNode {
       string value;           // Value in the node
       StackNode *next;     // Pointer to next node
   };

   StackNode *top;          // Pointer to the stack top
   int length;

public:
   Stack_str(){ top = NULL; length = 0; }    //Constructor
   //~Stack_str();                           // Destructor

   // Stack operations
    bool isEmpty() {
        return top == nullptr;
    }

    bool push(string item);
    string pop();
    string peek() {
        return top->value;
    }
    int getLength() {
        return length;
    }
};

/**~*~*~*
  Member function push: pushes the argument onto the stack.
*~**/
bool Stack_str::push(string item)
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

string Stack_str::pop() {
    if (isEmpty()) {
        cerr << "Error: Cannot pop from an empty stack." << endl;
        return "";
    }
    string item = top->value;
    StackNode *temp = top;
    top = top->next;
    delete temp;
    length--;
    return item;
}

int main() {
    Stack_str s;
    string item;

    // Input loop
    while (true) {
        getline(cin, item);
        if (item == "0")
            break;
        s.push(item);
    }

    // Output
    cout << s.getLength() << endl;
    if (!s.isEmpty())
        cout << s.peek() << endl;
    else
        cout << "Empty Stack!" << endl;
    cout << s.getLength() << endl;

    return 0;
}
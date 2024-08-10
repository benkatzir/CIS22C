/*
 Written by: Ben Katzir
 =================================
   Queue template
*/

#include <iostream>
#include <string>
using namespace std;

template <class T>
class Queue
{
private:
   // Structure for the queue nodes
   struct QueueNode {
       T value;        // Value in the node
       QueueNode *next;     // Pointer to next node
   };

   QueueNode *front;          // Pointer to the first node
   QueueNode *rear;           // Pointer to the last node
   int length;                // Number of nodes in the queue

public:
   Queue(){ front = rear = NULL; length = 0; }    //Constructor
   ~Queue();                                    // Destructor

   // Queue operations
   bool isEmpty() {
      return length == 0;   
   }
   bool push(T);
   T pop();
   T peek() {
      if (isEmpty()) {
        cout << "Empty Queue!" << endl;
        exit(1);
      }
      return front->value;
      
   }
   T peekRear() {
      if (isEmpty()) {
        cout << "Empty Queue!" << endl;
        exit(1);
      }
      return rear->value;
   }
   int getLength() {
      return length;
   }
};

/**~*~*
  Member function push: inserts the argument into the queue
*~**/
template <typename T>
bool Queue<T>::push(T item) {
   QueueNode *newNode; // Pointer to a new node
   
   // Allocate a new node and store num there.
   newNode = new QueueNode;
   if (!newNode)
     return false;
   newNode->value = item;
   newNode->next = NULL;
   
   // Update links and counter
   if (!front) // front is NULL: empty queue
     front = newNode;
   else
     rear->next = newNode;
   
   rear = newNode;
   length++;
   
   return true;
}

/**~*~*~*
  Member function pop: removes and returns the value at the front of the queue
*~**/
template <typename T>
T Queue<T>::pop()
{
    if (isEmpty()) {
        cout << "Error: Queue is empty!" << endl;
        exit(1);
    }

    T value = front->value;
    QueueNode *temp = front;
    front = front->next;
    delete temp;
    length--;

    // If the queue becomes empty after the pop operation, update rear to NULL
    if (isEmpty())
        rear = NULL;

    return value;
}

/**~*~*~*
   Destructor
*~**/
template <typename T>
Queue<T>::~Queue()
{
    while (front)
    {
        QueueNode* delNode = front;
        front = front->next;
        delete delNode; 
    }
}

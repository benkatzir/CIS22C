/**~*~*~*
CIS 22C
Project: Queue of strings

Written by:
IDE:
*~*/
#include <iostream>
#include <string>
using namespace std;

class Queue_str
{
private:
   // Structure for the queue nodes
   struct QueueNode {
       string value;        // Value in the node
       QueueNode *next;     // Pointer to next node
   };

   QueueNode *front;          // Pointer to the first node
   QueueNode *rear;           // Pointer to the last node
   int length;                // Number of nodes in the queue

public:
   Queue_str(){ front = rear = NULL; length = 0; }    //Constructor
   ~Queue_str();                                    // Destructor

   // Queue operations
   bool isEmpty() {
      return length == 0;   
   }
   bool push(string);
   string pop();
   string peek() {
      if (isEmpty()) {
        cout << "Empty Queue!" << endl;
        exit(1);
      }
      return front->value;
      
   }
   string peekRear() {
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
bool Queue_str::push(string item) {
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
string Queue_str::pop()
{
    if (isEmpty()) {
        cerr << "Error: Queue is empty!" << endl;
        exit(EXIT_FAILURE);
    }

    string value = front->value;
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
Queue_str::~Queue_str()
{
    while (front)
    {
        QueueNode* delNode = front;
        front = front->next;
        delete delNode; 
    }
}

int main() {

    Queue_str que;
    string item;

    // Loop to enter strings until "#" is entered
    while (true) {
        getline(cin, item);
        if (item == "#")
            break;
        que.push(item);
    }
    if (que.isEmpty()) {
        cout << "Empty Queue!" << endl;
    } else {
        while(!que.isEmpty()) {
            cout << que.pop() << endl;
        }
    }
    
    return 0;
}
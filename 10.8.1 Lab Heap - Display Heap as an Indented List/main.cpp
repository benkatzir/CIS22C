/*
  This program will
     - read integers from the keyboard and insert them into a min-heap,
     - display the min-heap as an indented list (level numbers included) and
     - display the integers as they are deleted from the heap.
*/

#include <iostream>
#include "Heap.h"

using namespace std;

void iDisplay(int item, int level);

int main()
{
	Heap heap;
	
	// build heap
    int num;
    cout << "Enter integers [0 - to stop]" << endl;
    cin >> num;
    while ( num != 0)
    {
        heap.insertHeap(num);
        cin >> num;
    }
    cout << "Heap capacity: " << heap.getSize() << endl;
    cout << "Heap actual number of elements: " << heap.getCount() << endl;
    
	heap.printIndented(iDisplay);
	
    // print items as they are deleted from the heap (sorted)
    if (heap.isEmpty())
       cout << "N/A";
    while (!heap.isEmpty())
    {
        heap.deleteHeap(num);
        cout << num << " ";
    }
    cout << endl;

	return 0;
}


/* 
  indented display:
  displays one item including the level number
  and corresponding indentation
*/
void iDisplay(int item, int level)
{
	 for (int i = 0; i < level; i++)
        cout << "..";
     cout << level << "). " << item << endl;
}

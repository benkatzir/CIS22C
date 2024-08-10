/* *~*~*
Implementation file for the Heap class: max-heap of integers
Written By: A. Student
Changed by: Ben Katzir
IDE:  VS Code
*~**/

#include "Heap.h"

/* *~*~*
 The private member function _reHeapUp rearranges the heap after insert by moving the
 last item up to the correct location in the heap
 *~**/
void Heap::_reHeapUp(int lastndx)
{
	if (lastndx) // means lastndx != 0, i.e. newElement is not heap's root
	{
		int parent = _findParent(lastndx);
		if (lastndx && heapAry[lastndx] > heapAry[parent])
		{
			int temp = heapAry[lastndx];
			heapAry[lastndx] = heapAry[parent];
			heapAry[parent] = temp;
			_reHeapUp(parent);
		}
	}
}

/* *~*~*
 The private member function _reHeapDown rearranges the heap after delete by moving the
 data in the root down to the correct location in the heap
 *~**/
void Heap::_reHeapDown(int rootdex)
{
    int left = _findLeftChild(rootdex);
    int right = _findRightChild(rootdex);
    int largest = rootdex;

    if (left != -1 && heapAry[left] > heapAry[largest])
    {
        largest = left;
    }
    if (right != -1 && heapAry[right] > heapAry[largest])
    {
        largest = right;
    }

    if (largest != rootdex)
    {
        int temp = heapAry[rootdex];
        heapAry[rootdex] = heapAry[largest];
        heapAry[largest] = temp;
        _reHeapDown(largest);
    }

}
/* *~*~*
 The public member function insertHeap inserts a new item into a heap.
 It calls _reheapUp.
 *~**/
bool Heap::insertHeap(int newItem)
{
	if (isFull())
	{
		return false;
	}
	
	/* Write your code here */
	heapAry[count] = newItem;
    _reHeapUp(count);
    count++;
	
	return true;
}

/* *~*~*
 The public member function deleteHeap deletes the root of the heap and
 passes back the root's data. It calls _reheapDown.
 *~**/
bool Heap::deleteHeap(int &returnItem)
{
	if (isEmpty())
	{
		return false;
	}	
	/* Write your code here */
	returnItem = heapAry[0];
    heapAry[0] = heapAry[count - 1];
    count--;
    _reHeapDown(0);
	return true;
}
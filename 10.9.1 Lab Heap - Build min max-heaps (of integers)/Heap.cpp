/* *~*~*
Implementation file for the Heap class: min- or max-heap of integers
Written By: A. Student
Changed by: Ben Katzir
IDE: VS Code
*~**/

#include "Heap.h"

/* *~*~*
 The private member function _reHeapUp rearranges the heap after insert by moving the
 last item up to the correct location in the heap
 *~**/
void Heap::_reHeapUp(int lastndx, int compare(int, int))
{
    if (lastndx) // means lastndx != 0, i.e. newElement is not heap's root
    {
        int parent = _findParent(lastndx);
        if (parent >= 0 && compare(heapAry[lastndx], heapAry[parent]) < 0)
        {
            // Swap
            int temp = heapAry[lastndx];
            heapAry[lastndx] = heapAry[parent];
            heapAry[parent] = temp;
            // Recursive call
            _reHeapUp(parent, compare);
        }
    }
}

/* *~*~*
 The private member function _reHeapDown rearranges the heap after delete by moving the
 data in the root down to the correct location in the heap
 *~**/
void Heap::_reHeapDown(int rootdex, int compare(int, int))
{
    int left = _findLeftChild(rootdex);
    int right = _findRightChild(rootdex);
    int smallest = rootdex;

    if (left != -1 && compare(heapAry[left], heapAry[smallest]) < 0)
    {
        smallest = left;
    }
    if (right != -1 && compare(heapAry[right], heapAry[smallest]) < 0)
    {
        smallest = right;
    }
    if (smallest != rootdex)
    {
        // Swap
        int temp = heapAry[rootdex];
        heapAry[rootdex] = heapAry[smallest];
        heapAry[smallest] = temp;
        // Recursive call
        _reHeapDown(smallest, compare);
    }
}

/* *~*~*
 The public member function insertHeap inserts a new item into a heap.
 It calls _reheapUp.
 *~**/
bool Heap::insertHeap(int newItem, int compare(int, int))
{
    if (isFull())
        return false;

    heapAry[count] = newItem;
    _reHeapUp(count, compare);
    count++;
    return true;
}

/* *~*~*
 The public member function deleteHeap deletes the root of the heap and
 passes back the root's data. It calls _reheapDown.
 *~**/
bool Heap::deleteHeap(int& returnItem, int compare(int, int))
{
    if (isEmpty())
        return false;

    returnItem = heapAry[0];
    heapAry[0] = heapAry[count - 1];
    count--;
    _reHeapDown(0, compare);
    return true;
}
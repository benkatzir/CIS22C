// Binary Search Tree ADT
// Created by A. Student
// Modified by: Ben Katzir
 
#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryTree.h"

template<class ItemType>
class BinarySearchTree : public BinaryTree<ItemType>
{   
public:
    // insert a node at the correct location
    bool insert(const ItemType &item);
    // remove a node if found
    //bool remove(const ItemType &item);
    // find a target node
    //bool search(const ItemType &target, ItemType &returnedItem) const;
    // find the smallest node
    bool findSmallest(ItemType &returnedItem) const;
    // find the largest node
    bool findLargest(ItemType &returnedItem) const;
    
private:
	 // internal insert node: insert newNode in nodePtr subtree
	 BinaryNode<ItemType>* _insert(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* newNode);
   
	 // search for target node
	 //BinaryNode<ItemType>* _search(BinaryNode<ItemType>* treePtr, const ItemType &target) const;
    
    // find the smallest node
    BinaryNode<ItemType>* _findSmallest(BinaryNode<ItemType>* nodePtr, ItemType &smallest) const;
    
    // find the biggest node
    BinaryNode<ItemType>* _findLargest(BinaryNode<ItemType>* nodePtr, ItemType &smallest) const;
   
    // internal remove node: locate and delete target node under nodePtr subtree
    // BinaryNode<ItemType>* _remove(BinaryNode<ItemType>* nodePtr, const ItemType target, bool &success);
    
    // delete target node from tree, called by internal remove node
    //  BinaryNode<ItemType>* _removeNode(BinaryNode<ItemType>* targetNodePtr);
    
    // remove the leftmost node in the left subtree of nodePtr
    //  BinaryNode<ItemType>* _removeLeftmostNode(BinaryNode<ItemType>* nodePtr, ItemType &successor);
    
};


///////////////////////// public function definitions ///////////////////////////
// Inserting items within a tree
template<class ItemType>
bool BinarySearchTree<ItemType>::insert(const ItemType & newEntry)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
	this->rootPtr = _insert(this->rootPtr, newNodePtr);
	return true;
}  


// Finding the smallest, which is the leftmost leaf (wrapper function)
template<class ItemType>
bool BinarySearchTree<ItemType>::findSmallest(ItemType & returnedItem) const
{
    BinaryNode<ItemType>* temp = nullptr;
    temp = _findSmallest(this->rootPtr, returnedItem);
    if (temp) // != NULL
        return true;
    return false;
}

// Finding the biggest, which is the rightmost leaf (wrapper function)
template<class ItemType>
bool BinarySearchTree<ItemType>::findLargest(ItemType & returnedItem) const
{
    BinaryNode<ItemType>* temp = nullptr;
    temp = _findLargest(this->rootPtr, returnedItem);
    if (temp) // != NULL
        return true;
    return false;
}



//////////////////////////// private functions ////////////////////////////////////////////

// Implementation of the insert operation - iterative algorithm
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_insert(BinaryNode<ItemType>* nodePtr,
                                                          BinaryNode<ItemType>* newNodePtr)
{
    BinaryNode<ItemType>* pWalk = nodePtr, *parent = nullptr;
    
    if( !nodePtr) // == NULL
    {
        nodePtr = newNodePtr;
        return nodePtr;
    }
    else
    {
        while(pWalk) // != NULL
        {
            parent = pWalk;
            if (pWalk->getItem() > newNodePtr->getItem())
                pWalk = pWalk->getLeftPtr();
            else
                pWalk = pWalk->getRightPtr();
        }
        if (parent->getItem() > newNodePtr->getItem())
            parent->setLeftPtr(newNodePtr);
        else
            parent->setRightPtr(newNodePtr);
    }

    return nodePtr;
}

// Implementation to find the smallest: recursive
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_findSmallest(BinaryNode<ItemType>* nodePtr, ItemType & smallest) const
{
    /* Write your code here */
    if (!nodePtr) {
        return nullptr;  // Base case: empty subtree
    }

    if (!nodePtr->getLeftPtr()) {
        smallest = nodePtr->getItem();  // Found the smallest element
        return nodePtr;
    }

    // Continue searching in the left subtree
    return _findSmallest(nodePtr->getLeftPtr(), smallest);

}

// Implementation to find the largest: recursive
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_findLargest(BinaryNode<ItemType>* nodePtr, ItemType & biggest) const
{
    /* Write your code here */
    if (!nodePtr) {
        return nullptr;  // Base case: empty subtree
    }

    if (!nodePtr->getRightPtr()) {
        biggest = nodePtr->getItem();  // Found the largest element
        return nodePtr;
    }

    // Continue searching in the right subtree
    return _findLargest(nodePtr->getRightPtr(), biggest);
}


#endif
// Binary Search Tree ADT
// Created by A. Student
// Modified by:  Ben Katzir
 
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
    // bool remove(const ItemType &item);
    // find a target node
    bool search(const ItemType &target, ItemType &returnedItem) const;
    // find the smallest node
    // bool findSmallest(ItemType &returnedItem) const;
    // find the largest node
    // bool findLargest(ItemType &returnedItem) const;
    
private:
	// internal insert node: insert newNode in nodePtr subtree
	BinaryNode<ItemType>* _insert(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* newNode);
   
	// search for target node
	BinaryNode<ItemType>* _search(BinaryNode<ItemType>* treePtr, const ItemType &target) const;
    
   // find the smallest node
   // BinaryNode<ItemType>* _findSmallest(BinaryNode<ItemType>* nodePtr, ItemType &smallest) const;
    
   // find the largest node
   // BinaryNode<ItemType>* _findLargest(BinaryNode<ItemType>* nodePtr, ItemType &smallest) const;
   
   // internal remove node: locate and delete target node under nodePtr subtree
   // BinaryNode<ItemType>* _remove(BinaryNode<ItemType>* nodePtr, const ItemType target, bool &success);
    
   // delete target node from tree, called by internal remove node
   // BinaryNode<ItemType>* _removeNode(BinaryNode<ItemType>* targetNodePtr);
    
   // remove the leftmost node in the left subtree of nodePtr
   // BinaryNode<ItemType>* _removeLeftmostNode(BinaryNode<ItemType>* nodePtr, ItemType &successor);
    
};


///////////////////////// public function definitions ///////////////////////////
// Wrapper for _insert - Inserting items within a tree
template<class ItemType>
bool BinarySearchTree<ItemType>::insert(const ItemType & newEntry)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
	
	this->rootPtr = _insert(this->rootPtr, newNodePtr);
	
	return true;
}  

// Wrapper for _search
// - it calls the private _search function that returns a Node pointer or NULL
// - if found, it copies data from that node and sends it back to the caller 
//   via the output parameter, and returns true, otherwise it returns false.
template<class ItemType>
bool BinarySearchTree<ItemType>::search(const ItemType& anEntry, ItemType & returnedItem) const
{
    BinaryNode<ItemType>* temp = nullptr;
    /* Write your code here */
    temp = _search(this->rootPtr, anEntry); // Call the private _search function
    
    if (temp != nullptr) // If the item is found
    {
        returnedItem = temp->getItem(); // Copy data from the node to returnedItem
        return true; // Return true indicating the item is found
    }
    return false;
}


//////////////////////////// private functions ////////////////////////////////////////////

// Iterative implementation of the insert operation (TO DO: change it to a recursive function!)
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_insert(BinaryNode<ItemType>* nodePtr,
                                                          BinaryNode<ItemType>* newNodePtr)
{
    if (!nodePtr) // Base case: If the current node is null, insert the new node here
    {
        ++this->count;
        return newNodePtr;
    }
    
    if (newNodePtr->getItem() < nodePtr->getItem())
    {
        nodePtr->setLeftPtr(_insert(nodePtr->getLeftPtr(), newNodePtr)); // Recursively insert into the left subtree
    }
    else
    {
        nodePtr->setRightPtr(_insert(nodePtr->getRightPtr(), newNodePtr)); // Recursively insert into the right subtree
    }
    
    return nodePtr;
}

// Recursive implementation of the search operation
// - return NULL if target not found, otherwise
// - returns a pointer to the node that matched the target
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_search(BinaryNode<ItemType>* nodePtr,
                                                           const ItemType &target) const
{
    BinaryNode<ItemType>* found = nullptr;
    
    /* Write your code here */   
    if (nodePtr != nullptr) {
      if (target == nodePtr->getItem())
         found = nodePtr;
      else if (target < nodePtr->getItem())
         return _search(nodePtr->getLeftPtr(), target);
      else
         return _search(nodePtr->getRightPtr(), target);
   }
    return found;
}

#endif

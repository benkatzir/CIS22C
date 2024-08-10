
 #ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryTree.h"

/*
PROGRAMMER - BEN KATZIR
    Assignment - Unit 2: BST Algorithms (insert, delete inorder traversal, indented tree)
    Description: 
    The purpose of this part of the project was to create a BST class (ADT) that
    could be used to store data (antiqueCar items) for the project. It provides public 
    and private functions for the class for insert, remove and search operations. In
    addition to storing data, a crucial role of the BST in the project was also the 
    visualization of data (provided by inorder and indented tree display) as well as 
    testing/debugging tasks like delete, insert, and search which were created with other 
    parts of the project (hash table and stack). Displaying the indented tree was especially     helpful when debugging our delete and insert from file options.
*/

/*BEN KATZIR - ENTIRE FILE*/

template<class ItemType>
class BinarySearchTree : public BinaryTree<ItemType>
{   
public:
    // insert a node at the correct location
    bool insert(const ItemType &item);
    // remove a node if found
    bool remove(const ItemType &item);

    // find a target node - not used in main program, included for completness
    bool search(const ItemType &target, ItemType &returnedItem) const;

    
private:
	// internal insert node: insert newNode in nodePtr subtree
	BinaryNode<ItemType>* _insert(BinaryNode<ItemType>* nodePtr, BinaryNode<ItemType>* newNode);

    // internal remove node: remove node with given value from subtree
    BinaryNode<ItemType>* _remove(BinaryNode<ItemType>* nodePtr, const ItemType &target, bool &success);
    
    // find the leftmost node in the right subtree
    BinaryNode<ItemType>* findMin(BinaryNode<ItemType>* nodePtr) const;

	// search for target node
	BinaryNode<ItemType>* _search(BinaryNode<ItemType>* treePtr, const ItemType &target) const;


    
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

// Wrapper for _remove - Removing items within a tree
template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType & target)
{
    bool success = false;
    this->rootPtr = _remove(this->rootPtr, target, success);
    return success;
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

// Implementation of the insert operation
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

// Implementation of the remove operation
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::_remove(BinaryNode<ItemType>* nodePtr,
                                                          const ItemType & target,
                                                          bool & success)
{
    if (!nodePtr) // Base case: If the current node is null, the item is not found
    {
        success = false;
        return nullptr;
    }

    if (target < nodePtr->getItem())
    {
        nodePtr->setLeftPtr(_remove(nodePtr->getLeftPtr(), target, success)); // Recursively remove from the left subtree
    }
    else if (target > nodePtr->getItem())
    {
        nodePtr->setRightPtr(_remove(nodePtr->getRightPtr(), target, success)); // Recursively remove from the right subtree
    }
    else // Node found
    {
        if (!nodePtr->getLeftPtr() && !nodePtr->getRightPtr()) // Case 1: No children (leaf node)
        {
            delete nodePtr;
            nodePtr = nullptr;
            --this->count;
            success = true;
        }
        else if (!nodePtr->getRightPtr()) // Case 2: Only left child
        {
            BinaryNode<ItemType>* temp = nodePtr;
            nodePtr = nodePtr->getLeftPtr();
            delete temp;
            --this->count;
            success = true;
        }
        else if (!nodePtr->getLeftPtr()) // Case 2: Only right child
        {
            BinaryNode<ItemType>* temp = nodePtr;
            nodePtr = nodePtr->getRightPtr();
            delete temp;
            --this->count;
            success = true;
        }
        else // Case 3: Two children
        {
            BinaryNode<ItemType>* temp = findMin(nodePtr->getRightPtr());
            nodePtr->setItem(temp->getItem());
            nodePtr->setRightPtr(_remove(nodePtr->getRightPtr(), temp->getItem(), success));
        }
    }

    return nodePtr;
}

// Find the leftmost node in the right subtree
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findMin(BinaryNode<ItemType>* nodePtr) const
{
    while (nodePtr->getLeftPtr())
    {
        nodePtr = nodePtr->getLeftPtr();
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

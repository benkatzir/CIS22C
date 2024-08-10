#ifndef _BINARY_TREE
#define _BINARY_TREE

#include "BinaryNode.h"

/*
PROGRAMMER - BEN KATZIR
    Assignment - Unit 2: BST Algorithms (insert, delete inorder traversal, indented tree)
    Description:
    The BinaryTree class template defines a parent class for a BST. the BinaryTree holds items of type T, along with attributes indicating if it's empty, traversals insert, search, destroy tree, and print tree. It provides constructors for initialization, facilitating a class for BST to inheret from.
*/

/*BEN KATZIR - ENTIRE FILE*/

template<class ItemType>
class BinaryTree
{
protected:
	BinaryNode<ItemType>* rootPtr;		// ptr to root node
	int count;							      // number of nodes in tree

public:
	// "admin" functions
 	BinaryTree() {rootPtr = 0; count = 0;}
	BinaryTree(const BinaryTree<ItemType> & tree){ }
   virtual ~BinaryTree() { destroyTree(rootPtr); }
   
	// common functions for all binary trees
 	bool isEmpty() const	{return count == 0;}
	int getCount() const {return count;}
	void clear() {destroyTree(rootPtr); rootPtr = 0; count = 0;}
	void preOrder(void visit(const ItemType &)) const {_preorder(visit, rootPtr);}
   void inOrder(void visit(const ItemType &)) const  {_inorder(visit, rootPtr);}
	void postOrder(void visit(const ItemType &)) const{_postorder(visit, rootPtr);}
   void printTree(void visit(const ItemType &, int)) const{_printTree(visit, rootPtr, 1);}

	// abstract functions to be implemented by derived class
	virtual bool insert(const ItemType &newData) = 0;
	//virtual bool remove(const ItemType &data) = 0;
	virtual bool search(const ItemType &target, ItemType & returnedItem) const = 0;

private:   
	// delete all nodes from the tree
	void destroyTree(BinaryNode<ItemType>* nodePtr);

	// internal traverse
	void _preorder(void visit(const ItemType &), BinaryNode<ItemType>* nodePtr) const;
	void _inorder(void visit(const ItemType &), BinaryNode<ItemType>* nodePtr) const;
	void _postorder(void visit(const ItemType &), BinaryNode<ItemType>* nodePtr) const;
    void _printTree(void visit(const ItemType &, int), BinaryNode<ItemType>* nodePtr, int level) const;
   
}; 

//Destroy the entire tree
template<class ItemType>
void BinaryTree<ItemType>::destroyTree(BinaryNode<ItemType>* nodePtr)
{
    if(nodePtr) // != NULL
    {
        destroyTree(nodePtr->getLeftPtr());
        destroyTree(nodePtr->getRightPtr());
        delete nodePtr;
    }
}  

//Preorder Traversal
template<class ItemType>
void BinaryTree<ItemType>::_preorder(void visit(const ItemType &), BinaryNode<ItemType>* nodePtr) const
{
    if (nodePtr) // != NULL
    {
        ItemType item = nodePtr->getItem();
        visit(item);
		_preorder(visit, nodePtr->getLeftPtr());
        _preorder(visit, nodePtr->getRightPtr());
    }

}  

//Inorder Traversal
template<class ItemType>
void BinaryTree<ItemType>::_inorder(void visit(const ItemType &), BinaryNode<ItemType>* nodePtr) const
{
    if (nodePtr) // != NULL
    {
        ItemType item = nodePtr->getItem();
        _inorder(visit, nodePtr->getLeftPtr());
        visit(item);
        _inorder(visit, nodePtr->getRightPtr());
    }
}  

//Postorder Traversal
template<class ItemType>
void BinaryTree<ItemType>::_postorder(void visit(const ItemType &), BinaryNode<ItemType>* nodePtr) const
{
    if (nodePtr) // != NULL
    {
        ItemType item = nodePtr->getItem();
		_postorder(visit, nodePtr->getLeftPtr());
        _postorder(visit, nodePtr->getRightPtr());
		visit(item);
    }
	
}  

//Prints tree as an indented list
template<class ItemType>
void BinaryTree<ItemType>::_printTree(void visit(const ItemType &, int), BinaryNode<ItemType>* nodePtr, int level) const
{
    if (!nodePtr) {
        return;  // Base case: empty subtree
    }

   ItemType item = nodePtr->getItem();
    visit(item, level);

    // Recursively traverse the right subtree
    _printTree(visit, nodePtr->getRightPtr(), level + 1);

    // Recursively traverse the left subtree
    _printTree(visit, nodePtr->getLeftPtr(), level + 1);

}
#endif


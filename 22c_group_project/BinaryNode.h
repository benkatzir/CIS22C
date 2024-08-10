#ifndef _BINARY_NODE
#define _BINARY_NODE

/*
PROGRAMMER - BEN KATZIR
    Assignment - Unit 2: BST Algorithms (insert, delete inorder traversal, indented tree)
    Description: 
    The BinaryNode class template defines a node structure for a BinaryTree which BST ADT    
    will inherit from. Each node holds an item of type T, along with attributes item, left 
    pointer, and right pointer. It provides constructors for initialization and 
    setters/getters for these attributes, facilitating a class for BinaryTree to
    inheret from.

    Contributions outside my unit:
    I helped debug searchManager to correctly search for items with the hash.search function on Thursday
    + modify display manager to meet requirements outlined on canvas

    I created the first version of the loop to allow user input with  these original functions:
        loadCarsFromFile
        displayMenu
        addNewCar
        deleteCar
        inOrderTraversal
        displayIndentedTree

    I initialized the document for our poster and presentation and was incharge of the design, 
    application data, output, and comments section of our poster and helped others integrate
    their visualizations of the Hashtable and stack into the poster/presentation

    I created the Demonstration Test Plan (final version)
    and created output in output_example.txt based on the plan
*/

/*BEN KATZIR - ENTIRE FILE*/

template<class ItemType>
class BinaryNode
{
private:
    ItemType              item;        // Data portion
    BinaryNode<ItemType>* leftPtr;     // Pointer to left child
    BinaryNode<ItemType>* rightPtr;    // Pointer to right child

public:
    // constructors
    BinaryNode(const ItemType & anItem)    {item = anItem; leftPtr = 0; rightPtr = 0;}
    BinaryNode(const ItemType & anItem,
               BinaryNode<ItemType>* left,
               BinaryNode<ItemType>* right) {item = anItem; leftPtr = left; rightPtr = right;}
    // setters
    void setItem(const ItemType & anItem) {item = anItem;}
    void setLeftPtr(BinaryNode<ItemType>* left) {leftPtr = left;}
    void setRightPtr(BinaryNode<ItemType>* right) {rightPtr = right;}
    
    // getters
    ItemType getItem() const     {return item;}
    BinaryNode<ItemType>* getLeftPtr() const  {return leftPtr;}
    BinaryNode<ItemType>* getRightPtr() const {return rightPtr;}
};

#endif

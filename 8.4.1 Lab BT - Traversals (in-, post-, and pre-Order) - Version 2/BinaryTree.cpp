// Implementation file for the BinaryTree class
#include <iostream>  // For cout and NULL


#include "BinaryTree.h"
#include <cstdlib>   // For rand()
#include <ctime>     // For time()
using namespace std;

/**~*~*
   Constructor
*~**/
BinaryTree::BinaryTree()
{
    root = NULL;
    count = 0;
}

/**~*~*
   This function calls a recursive function to traverse the
   tree in postorder
*~**/
/* Write your code here */
void BinaryTree::postOrder(void visit(const Data &)) const
{
    _postOrder(root, visit);
}

/**~*~*
   Postorder Traversal of the Binary Tree:
   Left-Right-Root
*~**/
/* Write your code here */
void BinaryTree::_postOrder(Node *root, void visit(const Data &)) const
{
    if (root)
    {
        _postOrder(root->left, visit);
        _postOrder(root->right, visit);
        visit(root->data);
    }
}

/**~*~*
   This function calls a recursive function to traverse the
   tree in preorder
*~**/
/* Write your code here */
void BinaryTree::preOrder(void visit(const Data &)) const
{
    _preOrder(root, visit);
}

/**~*~*
   Preorder Traversal of the Binary Tree:
   Root-Left-Right
*~**/
/* Write your code here */
void BinaryTree::_preOrder(Node *root, void visit(const Data &)) const
{
    if (root)
    {
        visit(root->data);
        _preOrder(root->left, visit);
        _preOrder(root->right, visit);
    }
}


/**~*~*
   This function calls a recursive function to traverse the
   tree in inorder
*~**/
void BinaryTree::inOrder(void visit(const Data &)) const
{
    _inOrder(root, visit);
}

/**~*~*
   Inorder Traversal of the Binary Tree:
   Left-Root-Right
*~**/
void BinaryTree::_inOrder(Node *root, void visit(const Data &)) const
{
    if (root)
    {
        _inOrder(root->left, visit);
        //cout << root->data.num << " ";
        visit(root->data);
        // cout has been replaced with a call for visit
        // What is visit?
        // visit is a generic name for a display function
        // in main(), when inOrder is called, it is decided what function address to assign to visit
        // here, you just use visit the way you would use/call a function
        _inOrder(root->right, visit);
        // ------------------^^^^^^ visit as an argument
    }
}

/**~*~*
   Insert data into a random Binary Tree
*~**/
void BinaryTree::insert(Data dataIn)
{
    Node *newNode;
    Node *pWalk;
    Node *parent;
    int  rand_num;

    // allocate the new node
    newNode = new Node;
    newNode->data  = dataIn;
    newNode->left  = NULL;
    newNode->right = NULL;

    // find a "random" parent
    if (!root) // tree is empty
        root = newNode;
    else
    {
        parent = NULL; // root does not have a parent
        pWalk = root;
        while( pWalk ){
            parent   = pWalk;
            rand_num = rand( ) % 100;
            if( rand_num % 2 ) // if odd - take left
                pWalk = pWalk->left;
            else
                pWalk = pWalk->right;
        }

        // insert the new node
        if( !parent->left ) // no left child
             parent->left  = newNode;
        else
             parent->right = newNode;
    }

    count++;
}


/**~*~*
   Destructor
   This function calls a recursive function to delete all nodes in the binary tree
*~**/
BinaryTree::~BinaryTree()
{
    if (root)
        _destroy(root);
}

/**~*~*
   This function traverses the binary tree in postorder and deletes every node
*~**/
void BinaryTree::_destroy( Node *root)
{
    if (root)
    {
        _destroy(root->left);
        _destroy(root->right);
        delete root;
    }
}





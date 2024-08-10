// BST ADT - Traversals
// Name Ben Katzir
#include "BinarySearchTree.h"  
#include <iostream>
#include <string>

using namespace std;

void buildBST(int n, BinarySearchTree<int> &);
void hDisplay(int &);
void vDisplay(int &);


int main()
{
    BinarySearchTree<int> bst;
    
    int n;
    char option;
    
    cout << "What is the number of nodes in the BST? " << endl;
    cin >> n;
    cout << "What traversal[prE/posT]? " << endl;
    cin >> option;
    
    buildBST(n, bst);
    
    cout << "  Inorder: ";
    bst.inOrder(hDisplay); // pass hDisplay to inOrder
    cout << endl;
    if ( option == 'T' || option == 't')
    {
        cout << "Postorder: ";
        /* Write your code here */; // pass hDisplay to postOrder
        bst.postOrder(hDisplay);
        cout << endl;
        /* Write your code here */; // pass vDisplay to postOrder
        bst.postOrder(vDisplay);
        cout << endl;
    }
    else if ( option == 'E' || option == 'e')
    {
        cout << " Preorder: ";
        /* Write your code here */;  // pass hDisplay to preOrder
        bst.preOrder(hDisplay);
        cout << endl;
        /* Write your code here */;  // pass vDisplay to preOrder
        bst.preOrder(vDisplay);
        cout << endl;
    }
            
    return 0;
}  

/*
 buildBST: builds a binary search tree
 of integers
*/
void buildBST(int n, BinarySearchTree<int> &bst)
{
    int item;
    
    while(n--)
    {
        item = rand( ) % 30 + 10;
        bst.insert(item);
    }
}

/*
 horizontal display: all items on one line
*/
void hDisplay (int &item)
{
    cout << item << " ";
}

/*
 vertical display: one item per line
*/
void vDisplay (int &item)
{
    cout << item << endl;
}


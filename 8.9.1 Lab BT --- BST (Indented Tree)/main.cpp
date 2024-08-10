// BST ADT
#include "BinarySearchTree.h" 
#include <iostream>
#include <string>

using namespace std;

void buildBST(int n, BinarySearchTree<int> &);
void hDisplay(int &);
void vDisplay(int &);
void iDisplay(int &, int);

int main()
{
    BinarySearchTree<int> bst;
    
    int n;
    
    cout << "What is the number of nodes in the BST? " << endl;
    cin >> n;
    
    buildBST(n, bst);
    
    cout << "  Inorder: ";
    bst.inOrder(hDisplay);
    cout << endl;
    
    cout << "Indented Tree:" << endl;
    bst.printTree(iDisplay);        
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

/*
 indented tree display: one item per line, including the level number
*/
void iDisplay(int &item, int level)
{
    for (int i = 1; i < level; i++)
        cout << "..";
    cout << level << "). " << item << endl;
    
}
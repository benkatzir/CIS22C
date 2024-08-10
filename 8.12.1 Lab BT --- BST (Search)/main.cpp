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
    
    cout << "Inorder: ";
    bst.inOrder(hDisplay);
    cout << endl;
    cout << "Search Section:" << endl;
    int searchCount = n / 2;
    int target, item;
    while (searchCount--)
    {
        target = rand() % 30 + 10;
        cout << target;
        if (bst.search(target, item))
        {
            cout << " FOUND! Data contains: "
                 << item << endl;
        }
        else
            cout << " NOT FOUND!\n";
    }

    return 0;
}  
/*
 buildBST: builds a binary search tree
 of integers
*/
void buildBST(int n, BinarySearchTree<int> &bst)
{
    bool duplicate[41] = {false}; // all are set to 0 (false)
    int item;

    while(n > 0)
    {
        item = rand() % 31 + 10;
        if (duplicate[item] == false){ // not a duplicate
           bst.insert(item);
           n--;
           duplicate[item] = true; 
        }   
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
/**

 Test Driver for Binary Tree functions
 
 This program builds a BT of random integers
 
     Note: The BT_insert() function is specific to this exercise

 The main goal of this example is build a binary tree that could be used to
 test the traversal and other binary tree functions

*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include "BinaryTree.h"

using namespace std;

void build_BT( BinaryTree &tree, int n );
void hDisplay(const Data &item); // horizontal display: all items on one line
void vDisplay(const Data &item); // vertical display: one item per line

int main( void )
{
    BinaryTree tree;
    int n; // number of nodes
    char option;
    cout << "What is the number of nodes in the BT? " << endl;
    cin >> n;
    cout << "What traversal[prE/posT]? " << endl;
    cin >> option;
    
    build_BT(tree, n );
    
    cout << "  Inorder: ";
    tree.inOrder(hDisplay); // hDisplay is the inOrder's argument
    cout << endl;
    
    if ( option == 'T' || option == 't')
    {
        cout << "Postorder: ";
        tree.postOrder(hDisplay); // passing hDisplay to postOrder
        cout << endl;
        tree.postOrder(vDisplay); // passing vDisplay to postOrder
        cout << endl;
    }
    if ( option == 'E' || option == 'e')
    {
        cout << " Preorder: ";
        tree.preOrder(hDisplay);  // passing hDisplay to preOrder
        cout << endl;
        tree.preOrder(vDisplay);  // passing vDisplay to preOrder
        cout << endl;
    }
    return 0;
}

/**~*~*
   Builds a random Binary Tree of integer numbers within the range
   [10, 99]; root is always 50
*/
void build_BT( BinaryTree &tree, int n )
{
    Data data = {50};

    // allocate and initialize the root
    tree.insert(data);

    //srand((unsigned int)time(0));
    while(--n)
    {
        data.num = rand( ) % 90  + 10;
        tree.insert(data);
   }
}

// The following two functions are used as arguments to other functions
/**~*~*
   horizontal display: all items on one line
*/
void hDisplay(const Data &item)
{
    cout << item.num << " ";
}

/**~*~*
   // vertical display: one item per line
*/
void vDisplay(const Data &item)
{
    cout << item.num << endl;
}

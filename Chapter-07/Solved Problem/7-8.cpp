/*
Page 263
7.8 Suppose the following list of letters is inserted in order into an empty binary search tree:

J, R, D, G, T, E, M, H, P, A, F, Q

(a) Find the final tree T and (b) find the inorder traversal of T.
*/
#include <iomanip>
#include <iostream>
#include <stack>
using namespace std;
typedef struct _tree
{
    char data;
    _tree *left;
    _tree *right;
} TREE;

TREE *insert(TREE *root, char data)
{
    if (root == NULL)
    {
        TREE *ptr = new TREE;
        ptr->data = data;
        ptr->left = NULL;
        ptr->right = NULL;
        root = ptr;
    }
    else if (root->data < data)
    {
       root->right =  insert(root->right, data);
    }
    else
       root->left =  insert(root->left, data);
    return root;
}
void inorder(TREE *root)
{

    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

}
int main()
{
    int AVAIL = 12;
    char  temp;
    TREE *root = NULL;
    for(int i = 0; i < AVAIL; i++)
    {
        cin >> temp;
        root = insert(root, temp);
    }
    inorder(root);

}
/*
 g++ 7-8.cpp -o 7-8 } ; if ($?) { .\7-8 }
J
R
D
G
T
E
M
H
P
A
F
Q
A D E F G H J M P Q R T
*/
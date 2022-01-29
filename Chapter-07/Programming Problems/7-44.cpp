/*
page 275
7.44 Write a program which prints the terminal nodes of T in (a) preorder (b) inorder and (c) postorder.

(Note: All three lists should be the same.)
*/

#include <iomanip>
#include <iostream>
#include <stack>
using namespace std;
typedef struct _tree
{
    int  data;
    _tree *left;
    _tree *right;
} TREE;

TREE *insert(TREE *root, int  data)
{
    if (root == NULL)
    {
        TREE *ptr = new TREE;
        ptr->data = data;
        ptr->left = NULL;
        ptr->right = NULL;
        root = ptr;
    }
    else if (root->data > data)
    {
       root->right =  insert(root->right, data);
    }
    else
       root->left =  insert(root->left, data);
    return root;
}
void PreOrder(TREE *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
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
void postorder(TREE *root)
{

    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

}
void printLeafNodes_Pre(TREE *root)
{
    // if node is null, return
    if (!root)
        return;
     
    // if node is leaf node, print its data   
    if (!root->left && !root->right)
    {
        cout << root->data << " ";
        return;
    }
 
    // if left child exists, check for leaf
    // recursively
    if (root->left)
       printLeafNodes_Pre(root->left);
         
    // if right child exists, check for leaf
    // recursively
    if (root->right)
       printLeafNodes_Pre(root->right);
}
void printLeafNodes_in(TREE *root)
{
    // if node is null, return
    if (!root)
        return;
    // if left child exists, check for leaf
    // recursively
    if (root->left)
       printLeafNodes_in(root->left);
         
         
    // if node is leaf node, print its data   
    if (!root->left && !root->right)
    {
        cout << root->data << " ";
        return;
    }
    // if right child exists, check for leaf
    // recursively
    if (root->right)
       printLeafNodes_in(root->right);
}
void printLeafNodes_post(TREE *root)
{
    // if node is null, return
    if (!root)
        return;
    // if left child exists, check for leaf
    // recursively
    if (root->left)
       printLeafNodes_post(root->left);
    // if right child exists, check for leaf
    // recursively
    if (root->right)
       printLeafNodes_post(root->right);
           // if node is leaf node, print its data   
    if (!root->left && !root->right)
    {
        cout << root->data << " ";
        return;
    }
}
int main()
{
    int AVAIL = 9;
    int   temp = 0;
    TREE *root = NULL;
    for(int i = 0; i < AVAIL; i++)
    {
        cin >> temp;
        root = insert(root, temp);
    }
    inorder(root);
    cout << "\n";
    PreOrder(root);
    cout << "\n";
    postorder(root);
    cout << "\n";
    printLeafNodes_in(root);cout << "\n";
    printLeafNodes_Pre(root);cout << "\n";
    printLeafNodes_post(root);cout << "\n";
}
/*
60
30
70
20
55
35
45
40
50
70 60 55 50 45 40 35 30 20 
60 70 30 55 35 45 50 40 20
70 50 40 45 35 55 20 30 60
70 50 40 20
70 50 40 20
70 50 40 20 
*/
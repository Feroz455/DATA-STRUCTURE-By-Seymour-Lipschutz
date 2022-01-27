/*
Page 260
7.2 A binary tree T has 9 nodes. The inorder and preorder
 traversals of T yield the following sequences of nodes:

Inorder:	E	A	C	K	F	H	D	B	G
Preorder:	F	A	E	K	C	D	H	G	B
Draw the tree T.
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
    else if (root->data > data)
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
void COUNT(TREE *root, int &NUM)
{

    if(root == NULL)
    {
        return;
    }
    else 
    {
        NUM = NUM + 1;
        COUNT(root->left,NUM);
        COUNT(root->right,NUM);
    }

}
void PreOrder(TREE *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        inorder(root->left);
        inorder(root->right);
    }
}
int main()
{
    int AVAIL = 9;
    char  temp;
    TREE *root = NULL;
    for(int i = 0; i < AVAIL; i++)
    {
        cin >> temp;
        root = insert(root, temp);
    }
    inorder(root);
    cout << "\n";
    PreOrder(root);
    int NUM = 0;
    COUNT(root, NUM);
    cout<< "Number of node in tree " << NUM<< endl;


}
/*
F
H
D
B
G
A
E
C
K
K H G F E D C B A 
F K H G E D C B A 
Number of node in tree 9 
*/
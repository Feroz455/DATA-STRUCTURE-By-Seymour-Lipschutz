/*
page 271
  7.6  Suppose a binary tree T is in memory. Write a nonrecursive procedure for each of the following:

(a) Finding the number of nodes in T.

(b) Finding the depth D of T.

(c) Finding the number of terminal nodes in T.
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
int MAX(int i, int j)
{
    return (i>j)? i:j;
}
int Find_Depth(TREE *root)
{
    if(root == NULL)
    {
        return -1;
    }
        int l = Find_Depth(root->left);
        int r = Find_Depth(root->right);
        return MAX(l, r) + 1;
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
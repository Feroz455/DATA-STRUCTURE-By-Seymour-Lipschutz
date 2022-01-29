/*
Page 
  7.45  Write a program which makes a copy T ′ of T using ROOTB as a pointer. 
Test the program by printing the nodes of T ′ in preorder and inorder and 
comparing the lists with those obtained in Programming Problem 7.1
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
TREE *copy(TREE *rootA, TREE *rootB)
{
    if(rootA != NULL)
    {
        rootB = insert(rootB,rootA->data);
        copy(rootA->left,rootB);
        copy(rootA->right,rootB);
    }
    return rootB;
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
void PreOrder(TREE *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void PostOrder(TREE *root)
{
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
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
    cout << "\n";
    PostOrder(root);
    TREE *rootB = NULL;
    rootB = copy(root, rootB);
    cout << "\n";
    inorder(rootB);
    cout << "\n";
    PreOrder(rootB);
    cout << "\n";
    PostOrder(rootB);

}
/*
J
R
D
G
T
E
M
H
P
T R P M J H G E D 
J R T M P D G H E
T P M R H E G D J

T R P M J H G E D
J R T M P D G H E
T P M R H E G D J
*/
/*
page 271
7.8  Suppose ROOTA points to a binary tree T1 in memory. Write a procedure which 
makes a copy T2 of the tree T1 using ROOTB as a pointer.

*/

#include <iomanip>
#include <iostream>
#include <stack>
using namespace std;
typedef struct _tree
{
    int data;
    _tree *left;
    _tree *right;
} TREE;

TREE *insert(TREE *root, int data)
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

int main()
{
    int AVAIL = 11, temp;
    TREE *rootA = NULL;
    for(int i = 0; i < AVAIL; i++)
    {
        cin >> temp;
        rootA = insert(rootA, temp);
    }
    inorder(rootA);
    cout << "\n";
    TREE *rootB = rootA;
    inorder(rootB);
    cout << "\n";

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
90
80
90 80 70 60 55 50 45 40 35 30 20 
90 80 70 60 55 50 45 40 35 30 20
*/
/*
page 261
7.5 Suppose a binary tree T is in memory. Write a recursive procedure which finds the depth DEP of T.

The depth DEP of T is 1 more than the maximum of the depths of the left and right subtrees of T. Accordingly:

Procedure P7.5: DEPTH(LEFT, RIGHT, ROOT, DEP)

This procedure finds the depth DEP of a binary tree T in memory.

1. If ROOT = NULL, then: Set DEP := 0, and Return.

2. Call DEPTH(LEFT, RIGHT, LEFT[ROOT], DEPL).

3. Call DEPTH(LEFT, RIGHT, RIGHT[ROOT], DEPR).

4. If DEPL ≥ DEPR, then:
  Set DEP := DEPL + 1.
Else:
  Set DEP := DEPR + 1.
[End of If structure.]

5. Return.
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
    int AVAIL = 9;
    char  temp;
    TREE *root = NULL;
    for(int i = 0; i < AVAIL; i++)
    {
        cin >> temp;
        root = insert(root, temp);
    }
    inorder(root);
    cout<< "Hight of the tree = " << Find_Depth(root) << endl;
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
Hight of the tree = 3
*/

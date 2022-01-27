/*
7.10 Suppose n data items A1, A2, …, AN are already sorted, i.e.,

A1 < A2 < ... < AN


(a) Assuming the items are inserted in order into an empty binary search tree, 
describe the final tree T.

(b) What is the depth D of the tree T?

(c) Compare D with the average depth AD of a binary search tree 
with n nodes for (i) n = 50, (ii) n = 100 and (iii) n = 500.
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
    else if(data <= root->data)
		root->left = insert(root->left,data);
	else 
		root->right = insert(root->right,data);
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
void PreOrder(TREE *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        inorder(root->left);
        inorder(root->right);
    }
}
TREE *FindMin(TREE *root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
TREE *Delete(TREE *root, int data)
{
    if(root == NULL)
    {
        return root;
    }
    else if(data < root->data)
    {
        root->left = Delete(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = Delete(root->right, data);
    }
    else 
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if(root->left == NULL)
        {
            TREE *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->left == NULL)
        {
            TREE *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            TREE *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
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
int main()
{
    int AVAIL = 100;
    int temp;
    TREE *root = NULL;
    for(int i = 0; i < AVAIL; i++)
    {
        cin >> temp;
        root = insert(root, temp);
    }
    return 0;
}
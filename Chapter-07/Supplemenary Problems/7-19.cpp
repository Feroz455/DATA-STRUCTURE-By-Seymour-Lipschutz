/*
Page 269
7.1  Consider the tree T in Fig. 7.98(a).



Fig. 7.19

(a) Fill in the values for ROOT, LEFT and RIGHT in Fig. 7.98(b) so that T will be stored in memory.

(b) Find (i) the depth D of T, (ii) the number of null subtrees and (iii) the descendants of node B.
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
int main()
{
    int AVAIL = 11, temp;
    TREE *root = NULL;
    for(int i = 0; i < AVAIL; i++)
    {
        cin >> temp;
        root = insert(root, temp);
    }
    inorder(root);

}
/*
*/
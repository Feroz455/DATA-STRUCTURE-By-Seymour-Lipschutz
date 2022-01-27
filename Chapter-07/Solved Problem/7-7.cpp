/*
Page 260
7.7 Consider the binary search tree T in Fig. 7.73(b), 
which is stored in memory as in Fig. 7.72. Suppose ITEM = 33 
is added to the tree T. 
(a) Find the new tree T. 
(b) Which changes occur in Fig. 7.72?
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
    int AVAIL = 12, temp;
    TREE *root = NULL;
    for(int i = 0; i <= AVAIL; i++)
    {
        cin >> temp;
        root = insert(root, temp);
    }
    inorder(root);

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
95
33
95 90 80 70 60 55 50 45 40 35 33 30 20 
*/
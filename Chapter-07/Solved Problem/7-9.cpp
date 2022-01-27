/*
page 264
7.9 Consider the binary search tree T in Fig. 7.79. Describe the tree after
(a) the node M is deleted and (b) the node D is also deleted.
(a) The node M has only one child, P. Hence delete M and let
P become the left child of R in place of M.

(b) The node D has two children. Find the inorder successor of D,
which is the node E. First delete E from the tree, and then replace D by the node E.

Figure 7.80 shows the updated tree.
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
TREE *Delete(TREE *root, char data)
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
int main()
{
    int AVAIL = 13;
    char temp;
    TREE *root = NULL;
    for(int i = 0; i < AVAIL; i++)
    {
        cin >> temp;
        root = insert(root, temp);
    }
    inorder(root);
    cout << "\n";
    cout << "Enter your Value\n";
    cin >> temp;
    root = Delete(root, temp);
    inorder(root);
     cout << "\n";
    cout << "Enter your Value\n";
    cin >> temp;
    root = Delete(root, temp);
    inorder(root);
     cout << "\n";

    return 0;
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
A
F
Q
W
A D E F G H J M P Q R T W 
Enter your Value
M
A D E F G H J P Q R T W 
Enter your Value
D
A E F G H J P Q R T W 
*/
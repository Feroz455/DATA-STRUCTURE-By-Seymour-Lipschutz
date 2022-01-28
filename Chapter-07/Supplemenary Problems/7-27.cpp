/*
page 271
7.28  Consider the binary search tree T in Fig. 7.100. Draw the tree T if each of the following operations is applied to the original tree T. (That is, the operations are applied independently, not successively.)

(a) Node 20 is added to T.

(b) Node 15 is added to T.

(c) Node 88 is added to T.

(d) Node 22 is deleted from T.

(e) Node 25 is deleted from T.

(f) Node 75 is deleted from T.

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
int main()
{
    int AVAIL = 13;
    int temp;
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
50
25
22
15
40
30
44
33
75
60
90
80
99
15 22 25 30 33 40 44 50 60 75 80 90 99 
*/
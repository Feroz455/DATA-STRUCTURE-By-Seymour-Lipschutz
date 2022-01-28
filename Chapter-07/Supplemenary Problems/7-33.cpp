/*
page 272/
7.33  Consider the binary tree T in Fig. 7.60(a).

(a) Draw the one-way inorder threading of T.

(b) Draw the one-way preorder threading of T.

(c) Draw the two-way inorder threading of T.
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
    int AVAIL = 8;
    char temp;
    TREE *root = NULL;
    for(int i = 0; i < AVAIL; i++)
    {
        cin >> temp;
        root = insert(root, temp);
    }
    cout << "\nInorder travelsel\n";
    inorder(root);
    cout << "\nPreorder travelsel\n";
    PreOrder(root);
    cout << "\nPostorder travelsel\n";
    PostOrder(root);
    return 0;
}
/*
A
B
D
E
H
G
C
F

Inorder travelsel
A B C D E F G H
Preorder travelsel
A B D C E H G F
Postorder travelsel
C F G H E D B A
*/
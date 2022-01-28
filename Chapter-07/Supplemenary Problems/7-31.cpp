/*
page 264
7.13  Consider the binary search tree T in Fig. 7.101. Describe the changes in INFO, LEFT,
 RIGHT, ROOT and AVAIL if each of the following operations is applied independently (not successively) to T.



Fig. 7.100

(a) Davis is added to T.

(b) Harris is added to T.

(c) Smith is added to T.

(d) Parker is deleted from T.

(e) Fox is deleted from T.

(f) Murphy is deleted from T.
*/

#include <iomanip>
#include <iostream>
#include <stack>
using namespace std;
typedef struct _tree
{
    string  data;
    _tree *left;
    _tree *right;
} TREE;

TREE *insert(TREE *root, string  data)
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
TREE *Delete(TREE *root, string  data)
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
    int AVAIL = 8;
    string  temp;
    TREE *root = NULL;
    for(int i = 0; i < AVAIL; i++)
    {
        cin >> temp;
        root = insert(root, temp);
    }
    inorder(root);
    cout << "\n";
    root = insert(root, "Davis");
    root = insert(root, "Harris");
    root = insert(root, "Smith");
    inorder(root);
    cout << "\n";
    root = Delete(root, "Parker");
    root = Delete(root, "Fox");
    root = Delete(root, "Murphy");
    inorder(root);
    cout << "\n";


    return 0;
}
/*
Jones
Fox   
Murphy
Thomas
Conroy
Parker
Rosen
Green
Conroy Fox Green Jones Murphy Parker Rosen Thomas 
Conroy Davis Fox Green Harris Jones Murphy Parker Rosen Smith Thomas
Conroy Davis Green Harris Jones Rosen Smith Thomas
*/
/*
page 242
ALGORITHM 7.8

TreeNode* find_min(TreeNode *root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}


TreeNode *Delete(TreeNode *root, int data)
{
    if(root == NULL)
    {
        return root;
    }
    else
    if(root->data > data)
    {
        root->left = Delete(root->left, data);
    }
    else 
    if(root->data < data)
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
        else 
        if(root->left == NULL)
        {
            TreeNode *temp = root;
            root = root->right;
            delete temp;
        }
        else 
        if(root->right == NULL)
        {
            TreeNode *temp = root;
            root = root->left;
            delete temp;
          
        }
        else 
        {
            TreeNode *temp = find_min(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;

}
*/
#include<iomanip>
#include<iostream>
using namespace std;
typedef struct _tree
{
    int data;
    _tree *left;
    _tree *right;
}TreeNode;

TreeNode* Insert(TreeNode *root,int data)
 {
	if(root == NULL) {
		root = new TreeNode();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}
void pre_order(TreeNode *root)
{
    if(root != NULL)
    {
        cout << root->data <<  " ";
        pre_order(root->left);
        pre_order(root->right);
    }
}
TreeNode* find_min(TreeNode *root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
TreeNode *Delete(TreeNode *root, int data)
{
    if(root == NULL)
    {
        return root;
    }
    else
    if(root->data > data)
    {
        root->left = Delete(root->left, data);
    }
    else 
    if(root->data < data)
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
        else 
        if(root->left == NULL)
        {
            TreeNode *temp = root;
            root = root->right;
            delete temp;
        }
        else 
        if(root->right == NULL)
        {
            TreeNode *temp = root;
            root = root->left;
            delete temp;
          
        }
        else 
        {
            TreeNode *temp = find_min(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;

}
int main()
{
    srand(time(0));
    int temp;
    TreeNode *root = NULL;
    for(int i = 0; i < 10; i++)
    {
        root = Insert(root, rand()%100);
    }
    pre_order(root);
    cout << "\nEnter number to delete\n";
    cin >> temp;
    root = Delete(root, temp);
    cout << "\n";
    pre_order(root);
    return 0;
}
/*
15 0 1 4 43 40 41 48 67 93 
Enter number to delete     
43

15 0 1 4 48 40 41 67 93 
*/
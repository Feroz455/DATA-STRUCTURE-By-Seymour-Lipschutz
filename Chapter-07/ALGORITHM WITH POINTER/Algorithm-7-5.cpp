/*
Page 236
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
TreeNode pre_order(TreeNode *root)
{
    if(root != NULL)
    {
        cout << root->data <<  " ";
        pre_order(root->left);
        pre_order(root->right);
    }
}
int main()
{
    srand(time(0));
    TreeNode *root = NULL;
    for(int i = 0; i < 10; i++)
    {
        root = Insert(root, rand()%100);
    }
    pre_order(root);
    return 0;
}
/*
80 70 42 38 16 42 69 67 78 74
*/
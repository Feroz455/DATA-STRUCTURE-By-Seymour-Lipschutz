/*
page 229
void in_order(tree_node *root)
{
    if (root != NULL)
    {
        in_order(root->left);
        in_order(root->right);
        cout << root->data << " ";
    }
}
*/
#include <iostream>
#include <iomanip>
#include<ctime>
#include<queue>
using namespace std;
typedef struct _tree
{
    int data;
    _tree *left;
    _tree *right;
} tree_node;

tree_node *new_node(int data)
{
    tree_node *temp = new tree_node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
//insert data into tree
tree_node *insert(tree_node *root, int data)
{
    if (root == NULL)
    {
        root = new_node(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
//INORDER
void post_order(tree_node *root)
{
    if (root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        cout << root->data << " ";
    }
}
int main()
{
    srand(time(0));
    int temp;
    tree_node *start = NULL;
    for(int i = 0; i < 10; i++)
    {
        temp  = (rand()%20)-5;
        start = insert(start, temp);
    }
    post_order(start);

}
/*
output
-5 -4 2 -1 -4 -5 12 3 14 2 
*/
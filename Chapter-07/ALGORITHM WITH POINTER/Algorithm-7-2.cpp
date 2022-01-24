/*
page 227
void in_order(tree_node *root)
{
    if (root != NULL)
    {
        in_order(root->left);
        cout << root->data << " ";
        in_order(root->right);
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
void in_order(tree_node *root)
{
    if (root != NULL)
    {
        in_order(root->left);
        cout << root->data << " ";
        in_order(root->right);
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
    in_order(start);

}
/*
output
-3 -1 1 4 6 8 8 8 12 12
*/
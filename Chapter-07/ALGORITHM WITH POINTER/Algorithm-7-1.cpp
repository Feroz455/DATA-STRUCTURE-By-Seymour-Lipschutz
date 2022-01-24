/*
page 226
void pre_order(tree_node *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        pre_order(root->left);
        pre_order(root->right);
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
//PRERDER
void pre_order(tree_node *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        pre_order(root->left);
        pre_order(root->right);
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
    pre_order(start);

}
/*
output
13 -4 -4 -1 -1 11 0 5 11 14
*/
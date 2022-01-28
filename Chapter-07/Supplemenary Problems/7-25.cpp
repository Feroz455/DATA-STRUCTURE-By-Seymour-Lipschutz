/*
page 271
  7.25  Suppose a binary tree T is in memory. Write a procedure which deletes all the terminal nodes in T.
*/
// C++ program to delete leaf Node from
// binary search tree.
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
 
// Create a newNode in binary search tree.
struct Node* newNode(int data)
{
    struct Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Insert a Node in binary search tree.
struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
 
// Function for inorder traversal in a BST.
void inorder(struct Node* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
 
// Delete leaf nodes from binary search tree.
struct Node* leafDelete(struct Node* root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }
 
    // Else recursively delete in left and right
    // subtrees.
    root->left = leafDelete(root->left);
    root->right = leafDelete(root->right);
 
    return root;
}
 
// Driver code
int main()
{
    struct Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 30);
    insert(root, 25);
    insert(root, 35);
    cout << "Inorder before Deleting the leaf Node." << endl;
    inorder(root);
    cout << endl;
    leafDelete(root);
    cout << "INorder after Deleting the leaf Node." << endl;
    inorder(root);
    return 0;
}
/*
Inorder before Deleting the leaf Node.
5 10 15 20 25 30 35
INorder after Deleting the leaf Node.
10 20 30
*/
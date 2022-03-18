#include <iostream>
#include <ctime>
#include <queue>
using namespace std;
struct TreeNode
{
    int DATA;
    TreeNode *lchild, *rchild;
};
TreeNode *NewNode(int DATA)
{
    TreeNode *node = new TreeNode;
    node->DATA = DATA;
    node->lchild = node->rchild = nullptr;
    return node;
}
void INSERT(TreeNode **root, int DATA)
{
    if (*root == NULL)
    {
        *root = NewNode(DATA);
        return;
    }
    TreeNode *temp = *root, *parentNode = NULL;
    while (temp != NULL)
    {
        parentNode = temp;
        temp = (DATA > temp->DATA) ? temp->rchild : temp->lchild;
    }
    if (DATA > parentNode->DATA)
    {
        parentNode->rchild = NewNode(DATA);
    }
    else
        parentNode->lchild = NewNode(DATA);
}
bool FIND(TreeNode **root, int key)
{
    TreeNode *temp = *root;
    if (key == temp->DATA)
    {
        return true;
    }
    while ((temp != NULL) && temp->DATA != key)
    {
        temp = (key > temp->DATA) ? temp->rchild : temp->lchild;
    }
    if (temp == NULL)
    {
        return false;
    }
    return true;
}
bool MAX(TreeNode *root, int &item)
{
    if (root == NULL)
    {
        cout << "ROOT is Empty\n";
        return false;
    }
    TreeNode *current = root;
    while (current->rchild != NULL)
    {
        current = current->rchild;
    }
    item = current->DATA;
    return true;
}
bool MIN(TreeNode *root, int &item)
{
    if (root == NULL)
    {
        cout << "ROOT is Empty\n";
        return false;
    }
    TreeNode *current = root;
    while (current->lchild != NULL)
    {
        current = current->lchild;
    }
    item = current->DATA;
    return true;
}

int MAX(int x, int y)
{
    return (x > y ? x : y);
}
int FindHeight(TreeNode *node)
{

    if (node == NULL)
    {
        return -1;
    }
    else
        return MAX(FindHeight(node->lchild), FindHeight(node->rchild) + 1);
}
void LeverOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode *> Q;
    Q.push(root);
    TreeNode *current;
    while (!Q.empty())
    {
        current = Q.front();
        Q.pop();
        cout << current->DATA << " ";
        if (current->lchild != NULL)
        {
            Q.push(current->lchild);
        }
        if (current->rchild != NULL)
            Q.push(current->rchild);
    }
}
void Pre_order(TreeNode *root)
{
    if (root != NULL)
    {
        cout << root->DATA << " ";
        Pre_order(root->lchild);
        Pre_order(root->rchild);
    }
}
void In_order(TreeNode *root)
{
    if (root != NULL)
    {
        In_order(root->lchild);
        cout << root->DATA << " ";
        In_order(root->rchild);
    }
}
void Post_order(TreeNode *root)
{
    if (root != NULL)
    {
        Post_order(root->lchild);
        Post_order(root->rchild);
        cout << root->DATA << " ";
    }
}
bool IsSubtreeLesser(TreeNode *root, int value)
{
    if (root == NULL)
        return true;
    if (root->DATA <= value && IsSubtreeLesser(root->lchild, value) && IsSubtreeLesser(root->rchild, value))
        return true;
    else
        return false;
}
bool IsSubtreeGreater(TreeNode *root, int value)
{
    if (root == NULL)
        return true;
    if (root->DATA > value && IsSubtreeGreater(root->lchild, value) && IsSubtreeGreater(root->rchild, value))
        return true;
    else
        return false;
}
bool IsBinarySearchTree(TreeNode *root)
{
    if (IsSubtreeLesser(root->lchild, root->DATA) && IsSubtreeGreater(root->rchild, root->DATA) && IsBinarySearchTree(root->lchild) && IsBinarySearchTree(root->rchild))
        return true;
    else
        return false;
}
TreeNode *FindMin(TreeNode *root)
{
    while (root->lchild != NULL)
    {
        root = root->lchild;
    }
    return root;
}
TreeNode *Delete(TreeNode *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data < root->DATA)
    {
        root->lchild = Delete(root->lchild, data);
    }
    else if (data > root->DATA)
    {
        root->rchild = Delete(root->rchild, data);
    }
    else
    {
        // case 1: NO child
        if (root->lchild == NULL && root->rchild == NULL)
        {
            delete root;
            root == NULL;
        }
        // Case 2: one child
        else if (root->lchild == NULL)
        {
            TreeNode *temp = root;
            root = root->rchild;
            delete temp;
        }
        else if (root->rchild == NULL)
        {
            TreeNode *temp = root;
            root = root->lchild;
            delete temp;
        }
        else
        {
            TreeNode *temp = FindMin(root->rchild);
            root->DATA = temp->DATA;
            root->rchild = Delete(root->rchild, temp->DATA);
        }
    }
    return root;
}

TreeNode *Find(TreeNode *root, int data)
{
    if (root == NULL)
        return NULL;
    else if (root->DATA == data)
        return root;
    else if (root->DATA < data)
        return Find(root->rchild, data);
    else
        return Find(root->lchild, data);
}
TreeNode *GetSuccessor(TreeNode *root, int data)
{
    TreeNode *current = Find(root, data);
    if (current == NULL)
        return NULL;
    if (current->rchild != NULL)
    {
        return FindMin(current->rchild);
    }
    else
    {
        TreeNode *successor = NULL, *ancestor = root;
        while (ancestor != current)
        {
            if (current->DATA < ancestor->DATA)
            {
                successor = ancestor;
                ancestor = ancestor->lchild;
            }
            else
                ancestor = ancestor->rchild;
        }
        return successor;
    }
}
int main()
{
    srand(time(0));
    TreeNode *ROOT = NULL;
    int N = (rand() % 20) + 5, item;
    for (int i = 0; i < N; i++)
    {
        item = rand() % 20;
        INSERT(&ROOT, item);
        cout << item << " ";
    }
    cout << "\n";
    TreeNode *successor = GetSuccessor(ROOT, 5);
    if(successor == NULL)
    {
        cout << "No successor found\n";
    }
    else 
    cout << "Successor is -> " << successor->DATA << "\n"; 

    return 0;
}
/*
18 4 16 15 15 7 6 15 6 5 0 5 13 3 10 0 2 19 1 15 16 10 3 7 
Successor is -> 6
*/
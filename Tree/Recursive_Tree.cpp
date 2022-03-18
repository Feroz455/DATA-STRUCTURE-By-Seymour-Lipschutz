#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};


Node *newNode(int key)
{
    Node *node = new Node;
    node->data = key;
    node->left = node->right = nullptr;

    return node;
}

void insert(Node* &travptr, int data){

    if (travptr == nullptr)
    {
        travptr = newNode(data);
        return;
    }
    (data > travptr->data)? insert(travptr->right,data) : insert(travptr->left, data);
    
}

bool contains(Node* travptr, int data){

    if (travptr == nullptr)
    {  
        return false;
    }
    if (data == travptr->data)
    {
        return true;
    }

    return (data > travptr->data) ? contains(travptr->right, data) : contains(travptr->left, data);
    
}

int main()
{
    Node* root = nullptr;

    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);

    cout << contains(root, 3) << "\t" << contains(root, 10) << "\t" << contains(root, 5);
    
    return 0;
}
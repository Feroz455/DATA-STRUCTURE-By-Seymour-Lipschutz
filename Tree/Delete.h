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
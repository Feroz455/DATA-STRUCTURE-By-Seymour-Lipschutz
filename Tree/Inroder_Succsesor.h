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
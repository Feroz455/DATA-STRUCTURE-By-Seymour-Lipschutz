bool MIN(TreeNode *root, int &item)
{
    if(root == NULL)
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
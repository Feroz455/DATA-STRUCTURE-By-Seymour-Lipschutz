bool MAX(TreeNode *root, int &item)
{
    if(root == NULL)
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
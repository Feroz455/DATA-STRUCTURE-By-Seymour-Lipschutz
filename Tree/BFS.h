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
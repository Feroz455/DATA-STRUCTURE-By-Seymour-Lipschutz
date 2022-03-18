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
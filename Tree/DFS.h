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
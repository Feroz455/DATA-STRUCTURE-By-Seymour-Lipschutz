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
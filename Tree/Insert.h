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
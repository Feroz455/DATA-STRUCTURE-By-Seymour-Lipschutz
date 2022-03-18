bool FIND(TreeNode **root, int key)
{
    TreeNode *temp = *root;
    if (key == temp->DATA)
    {
        return true;
    }
    while ((temp != NULL) && temp->DATA != key)
    {
        temp = (key > temp->DATA) ? temp->rchild : temp->lchild;
    }
    if (temp == NULL)
    {
        return false;
    }
    return true;
}
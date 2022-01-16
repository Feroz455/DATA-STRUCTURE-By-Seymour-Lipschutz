void PRINT_SUB_STR(LINKED **START , int K, int N)
{
    LINKED *PTR = (*START);
    while (K--)
    {
        PTR = PTR->next;
    }
    while (N--)
    {
        cout << PTR->CHAR << " ";
        PTR = PTR->next;
    }
}
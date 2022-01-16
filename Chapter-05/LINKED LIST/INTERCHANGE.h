void MAKE_FIRST_ELEMENT_LAST_ELEMENT(LINKED **START)
{
    (*START) = (*START)->next;
}
void INTERCHANGE(LINKED **START, int lOC)
{
    LINKED *PTR = (*START);
    if(lOC == 0)
    {
        MAKE_FIRST_ELEMENT_LAST_ELEMENT(START);
        return;
    }
    while (lOC-- != 1)
    {
        PTR = PTR->next;
    }
    int TEMP = PTR->DATA;
    PTR->DATA = PTR->next->DATA;
    PTR->next->DATA = TEMP;
}
void SWAP(LINKED *a, LINKED *b)
{
    int temp = a->DATA;
    a->DATA = b->DATA;
    b->DATA = temp;
}
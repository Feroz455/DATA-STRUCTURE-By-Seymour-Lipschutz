void SWAP(LINKED *FIRST, LINKED *SECOND)
{
    int TEMP = FIRST->DATA;
    FIRST->DATA = SECOND->DATA;
    SECOND->DATA = TEMP;
}
void BUBBLE_SORT(LINKED *START)
{
    int SWAPPED, i;
    LINKED *PTR, *LAST = START;
    if(START == NULL)
    {
        return;
    }
    do
    {
        SWAPPED = 0;
        PTR = START;
        while(PTR->next != LAST)
        {
            if(PTR->DATA > PTR->next->DATA)
            {
                SWAP(PTR, PTR->next);
                SWAPPED = 1;
            }
            PTR = PTR->next;
        }
        LAST = PTR;
    }while (SWAPPED);
}

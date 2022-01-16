int SEARCH(LINKED **START, int DATA)
{
    LINKED *PTR = (*START);
    int count = 1;
    if(PTR->DATA == DATA)
    {
        return count;
    }
    else 
    {
        while(PTR->next != (*START) && PTR->DATA != DATA)
        {
            PTR = PTR->next;
            count++;
        }
        if(PTR->DATA != DATA && PTR->next == (*START))
        return 0;
        return count++;
    }
}
int SEARCH_SORTED_LIST(LINKED **START, int DATA)
{
    LINKED *PTR = (*START);
    int count = 1;
    if(PTR->DATA == DATA)
    {
        return count;
    }
    else 
    {
        while(PTR->next != (*START) && PTR->DATA != DATA)
        {
            if(PTR->DATA > DATA);
            {
                return 0;
            }
            PTR = PTR->next;
            count++;
        }
        if(PTR->DATA != DATA && PTR->next == (*START))
        return 0;
        return count++;
    }
}
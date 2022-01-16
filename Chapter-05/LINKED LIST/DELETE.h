void DELETE_ALL(LINKED **START)
{
    LINKED *PTR = (*START)->prev, *PP;
    while (PTR->prev != (*START))
    {
        PP = PTR;
        PTR = PTR->prev;
        delete PP;
    }
     *START = NULL;
}
void DELETE_FIRST_LINK(LINKED **START)
{
    if((*START) == NULL)
    {
        return;
    }
    if((*START)->next == (*START))
    {
        delete (*START);
        (*START) = NULL;
        return;
    }
    LINKED *PTR = (*START);
    (*START)->prev->next = (*START)->next;
    (*START)= (*START)->next;
    (*START)->prev = PTR->prev;
    delete PTR;
}
void DELETE_LAST_LINK(LINKED **START)
{
    if((*START) == NULL)
    {
        return;
    }
    if((*START)->next == (*START))
    {
        delete (*START);
        (*START) = NULL;
        return;
    }
    LINKED *PTR = (*START)->prev, *PP;
    PP = (*START)->prev->prev;
    PP->next = (*START);
    (*START)->prev = PP;
    delete PTR;
}
void DELETE_ITEM(LINKED **START, int DATA)
{
    LINKED *PTR = (*START);
    if(PTR->DATA == DATA)
    {
        DELETE_FIRST_LINK(START);
    }
    else 
    if(PTR->prev->DATA == DATA)
    {
        DELETE_LAST_LINK(START);
    }
    else 
    {
        while(PTR->next != (*START) && PTR->DATA != DATA)
        {
            PTR = PTR->next;
        }
        if(PTR->next == (*START))
        {
            return;
        }
        PTR->next->prev = PTR->prev;
        PTR->prev->next = PTR->next;
    }
}
void DELETE_ON_LOCATION(LINKED **START, int DATA)
{
    DATA = DATA - 1;
    LINKED *PTR = (*START);
    if(DATA == 0)
    {
        DELETE_FIRST_LINK(START);
    }
    else 
    {
        while(DATA-- != 0 && PTR->next != *START)
        {
            PTR = PTR->next;
        }
        if(PTR->next == (*START))
        {
            if(DATA == 1)
            DELETE_LAST_LINK(START);
            else
            cout << "\nLOCATION DAES NOT EXISTED\n";
            return;
        }
        PTR->next->prev = PTR->prev;
        PTR->prev->next = PTR->next;
    }
}

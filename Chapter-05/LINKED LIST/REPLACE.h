void REPLACE(LINKED **START, int DATA, int RDATA)
{
    LINKED *PTR = (*START);
    if(PTR->DATA == DATA)
    {
        PTR->DATA = RDATA;
    }
    else 
    if(PTR->prev->DATA == DATA)
    {
        PTR->prev->DATA = RDATA;
    }
    else 
    {
        while(PTR->next != (*START) && PTR->DATA != DATA)
        {
            PTR = PTR->next;
        }
        if(PTR->next == (*START))
        {
            cout << DATA << " NOT FOUND\n";
            return;
        }
        PTR->DATA = RDATA;
    }
}

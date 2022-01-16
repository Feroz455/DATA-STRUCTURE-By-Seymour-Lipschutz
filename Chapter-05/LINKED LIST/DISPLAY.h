
void DISPLAY_FORWORD( LINKED **START)
{
    if((*START) == NULL)
    {
        cout << "LIST IS EMPTY\n";
        return;
    }
     LINKED *PTR = (*START);
    while (PTR->next != *START)
    {

        cout << PTR->DATA << "-> " ;
        PTR = PTR->next;
    }
    cout << PTR->DATA ; 
}
void DISPLAY_REVERSE( LINKED **START)
{
    if((*START) == NULL)
    {
        cout << "LIST IS EMPTY\n";
        return;
    }
     LINKED *PTR = (*START)->prev;
    while (PTR != *START)
    {
        cout << PTR->DATA << "-> " ;
        PTR = PTR->prev;
    }
    cout << PTR->DATA ; 
}


void NON_EMPTY(LINKED **START)
{
    int COUNT = 0;
    LINKED *PTR = (*START);
    while(PTR->next != (*START))
    {
        if(PTR->DATA != 0)
        COUNT++;
        PTR = PTR->next;
    }
    if(PTR->DATA != 0)
    COUNT++;
    cout << "\nNUMBER OF OCARENCE -> " <<  COUNT+1 << "\n"; 
}

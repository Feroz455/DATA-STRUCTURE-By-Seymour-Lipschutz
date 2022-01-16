void OCARANCE(LINKED **START, int NUM)
{
    int COUNT = 0;
    LINKED *PTR = (*START);
    while(PTR->next != (*START))
    {
        if(PTR->DATA == NUM)
        COUNT++;
        PTR = PTR->next;
    }
    if(PTR->DATA == NUM)
    COUNT++;
    cout << "NUMBER OF OCARENCE -> " <<  COUNT+1 << "\n"; 
}
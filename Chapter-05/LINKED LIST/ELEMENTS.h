void ELEMENT(LINKED **START)
{
    int COUNT = 0 ;
    LINKED *PTR = (*START);
    if(PTR == NULL)
    {
        cout << "LIST IS EMPTY\n";
    }
    while (PTR->next != *START)
    {
        COUNT++;
        PTR = PTR->next;
    }
    cout << "NUMBER OF ELEMENT -> " <<  COUNT+1 << "\n"; 
}
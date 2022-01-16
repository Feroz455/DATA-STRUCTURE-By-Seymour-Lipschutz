void INSERT_END(LINKED **START, int DATA)
{
    if((*START) == NULL)
    {
        LINKED *NEW = new LINKED;
        NEW->DATA = DATA;
        NEW->next = NEW->prev = NEW;
        *START = NEW;
    }
    else
    {
        LINKED *LAST = (*START)->prev;
        LINKED *NEW = new LINKED;
        NEW->DATA = DATA;

        NEW->next = (*START);
        NEW->prev = LAST;
        (*START)->prev = NEW;
        LAST->next = NEW;
    }   
}
void INSERT_BEGIN(LINKED **START, int DATA)
{
    if((*START) == NULL)
    {
        LINKED *NEW = new LINKED;
        NEW->DATA = DATA;
        NEW->next = NEW->prev = NEW;
        *START = NEW;
    }
    else
    {
        LINKED *LAST = (*START)->prev;

        LINKED *NEW_LINK = new LINKED;
        NEW_LINK->DATA = DATA;

        NEW_LINK->next = *START;
        NEW_LINK->prev = LAST;

        LAST->next = (*START)->prev = NEW_LINK;
        *START = NEW_LINK;
    }
}
void INSERT_AFTER( LINKED **START, int DATA1, int DATA2)
{

     LINKED * NEW_LINK = new  LINKED;

     NEW_LINK->DATA = DATA2;

     LINKED *PTR = *START;
    while(PTR->DATA != DATA1 && PTR->next != *START)
    {
        PTR = PTR->next; 
    }
    LINKED *NEXT_NODE = PTR->next;
    PTR->next =  NEW_LINK;
    NEW_LINK->prev = PTR;
    NEW_LINK->next = NEXT_NODE;
    NEXT_NODE->prev =  NEW_LINK;
}

void INSERT_DATA_SORTED( LINKED **START, int DATA)
{
    if((*START) == NULL)
    {
        LINKED *NEW = new LINKED;
        NEW->DATA = DATA;
        NEW->next = NEW->prev = NEW;
        *START = NEW;
    }
    else 
    if((*START)->DATA >= DATA)
    {
        INSERT_BEGIN(START, DATA);
    }
    else
    if((*START)->prev->DATA <= DATA)
    {
        INSERT_END(START, DATA);
    }
    else
    {
        LINKED *PTR = (*START);
        LINKED *NEW = new LINKED, *PP;
        NEW->DATA = DATA;

        while(PTR->DATA < DATA)
        {
            PP = PTR;
            PTR = PTR->next;
        }
        NEW->next = PTR;
        NEW->prev = PTR->prev;
        PTR->prev = NEW;
        PP->next = NEW;
    }
}
void INSER_AFTER_LOC(LINKED **START,int DATA,int LOC)
{
    LINKED *PTR = (*START),*PP;
    if((*START == NULL))
    {
        cout << "LIST IS EMPTY\n";
        cout << "DO YOU WANTO INSERT DATA INTO THE LIST?\n";
        cout << "\nYES = 1 || NO = 0 \n";
        int check = 0;
        cin >> check ;
        if(check == 1)
        {
            INSERT_BEGIN(START, DATA);
        }
        else 
        return;
    } 
    else 
    {
        while(LOC-- != 0 && PTR->next != *START)
        {
            PP = PTR;
            PTR = PTR->next;
        }
        if(PTR->next == *START)
        {
            cout << "LOCATION DOES NOT EXIST";
        }
        LINKED *NEW = new LINKED;
        NEW->DATA = DATA;
        NEW->next = PTR;
        NEW->prev = PTR->prev;
        PTR->prev = NEW;
        PP->next = NEW;
    }
}

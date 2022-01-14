/*
5.10 Discuss the advantages, if any, of a two-way list over a one-way list for each of the following operations:

(a) Traversing the list to process each node

(b) Deleting a node whose location LOC is given

(c) Searching an unsorted list for a given element ITEM

(d) Searching a sorted list for a given element ITEM

(e) Inserting a node before the node with a given location LOC

(f) Inserting a node after the node with a given location LOC
*/

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
typedef struct _link
{
    int DATA;
    _link *next;
    _link *prev;
}LINKED;

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
int main()
{
    LINKED *START = NULL;
    for(int i = 1; i < 11; i++)
    {
        INSERT_BEGIN(&START, i*10);
    }
    DISPLAY_FORWORD(&START);
    DELETE_ON_LOCATION(&START, 15);
    cout << '\n';
     DISPLAY_FORWORD(&START);
     cout << "\n";
     INSER_AFTER_LOC(&START, 45, 4);
     cout << "\n";
     DISPLAY_FORWORD(&START);
}
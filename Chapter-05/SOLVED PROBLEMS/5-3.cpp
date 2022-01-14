/*
Page 151

Algorithm 5.1: (Traversing a Linked List) Let LIST be a linked list in memory. 
This algorithm traverses LIST, applying an operation PROCESS to each element 
of LIST. The variable PTR points to the node currently being processed.
1. Set PTR := START. [Initializes pointer PTR.]
2. Repeat Steps 3 and 4 while PTR ≠ NULL.
3.       Apply PROCESS to INFO[PTR].
4.       Set PTR := LINK[PTR]. [PTR now points to the next node.]
[End of Step 2 loop.]

5. Exit.



PROGRAM 5-3
5.3 Let LIST be a linked list in memory. Write a procedure which

(a) Finds the number NUM of times a given ITEM occurs in LIST

(b) Finds the number NUM of nonzero elements in LIST

(c) Adds a given value K to each element in LIST
*/
#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
typedef struct _link
{
    int DATA;
    _link *next;
    _link *prev;
}LINKED;
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
int main()
{
    srand(time(0));
    LINKED *START = NULL;
    for(int i = 1; i < 10; i++)
    {
        INSERT_DATA_SORTED(&START, rand()%10);
    }
    DISPLAY_REVERSE(&START);
    OCARANCE(&START,5);
    NON_EMPTY(&START);
}
/*
Algorithm 6.17: This algorithm deletes and processes the first element 
in a priority queue which appears in memory as a one-way list.

1. Set ITEM := INFO[START]. [This saves the data in the first node.]

2. Delete first node from the list.

3. Process ITEM.

4. Exit
*/
#include<iostream>
#include<iomanip>
typedef struct _pQueue
{
    int DATA;
    int PRIORITY;
    _pQueue *next;
}P_QUEUE;
using namespace std;
void INSERT_FIRST(P_QUEUE **START, int ITEM, int PARIORITY)
{
    P_QUEUE *PTR = new P_QUEUE;
    PTR->DATA = ITEM;
    PTR->PRIORITY = PARIORITY;
    PTR->next = (*START);
    (*START) = PTR;
}
void INSERT(P_QUEUE **START, int ITEM, int PARIORITY)
{
    if((*START) == NULL)
    {
        INSERT_FIRST(START, ITEM, PARIORITY);
        return;
    }
    else
    {
        P_QUEUE *PTR = (*START);
        P_QUEUE *PREV, *TEMP = new P_QUEUE;
        TEMP->DATA = ITEM;
        TEMP->PRIORITY = PARIORITY;
        while(PTR->next != NULL && PTR->PRIORITY <= PARIORITY)
        {
            PREV = PTR;
            PTR = PTR->next;
        }
        if(PTR->next == NULL)
        {
            TEMP->next = NULL;
            PTR->next = TEMP;
        }
        else if(PTR == (*START))
        {
            TEMP->next = PTR;
            (*START) = TEMP;
        }
        else 
        {
            TEMP->next = PTR;
            PREV->next = TEMP;
        }

    }
}

int DELETE(P_QUEUE **START,int &ITEM, int &PARIORITY)
{
    if((*START) == NULL)
    {
        cout << "UNDER FLOW\n";
        return 0;
    }
    P_QUEUE *PTR = (*START);
    ITEM = (*START)->DATA;
    PARIORITY = (*START)->PRIORITY;
    (*START) = (*START)->next;
    delete PTR;
    return 1;
}
void DISPLAY(P_QUEUE *START)
{
    P_QUEUE *PTR = START;
    if((START) == NULL)
    {
        return;
    }
    while(PTR->next != NULL)
    {
        cout << PTR->DATA << " _ " << PTR->PRIORITY << " -> ";
        PTR = PTR->next;
    }
    cout << PTR->DATA << " _  " << PTR->PRIORITY  << endl;
    cout << "\n";
}
int main()
{
    P_QUEUE *START = NULL;
    int ITEM, PARIORITY;
    INSERT(&START, 22, 2);
    if(DELETE(&START, ITEM, PARIORITY))
    cout << "ITEM = " << ITEM << " PARIORITY " << PARIORITY << endl ;
    DISPLAY(START);
    if(DELETE(&START, ITEM, PARIORITY))
    cout << "ITEM = " << ITEM << " PARIORITY " << PARIORITY << endl ;
    DISPLAY(START);
    INSERT(&START, 33, 2);
    INSERT(&START, 44, 3);
    INSERT(&START, 11, 1);
    INSERT(&START, 22, 2);
    INSERT(&START, 33, 2);
    INSERT(&START, 44, 3);
    DISPLAY(START);
    if(DELETE(&START, ITEM, PARIORITY))
    cout << "ITEM = " << ITEM << " PARIORITY " << PARIORITY << endl ;
    DISPLAY(START);
    INSERT(&START, 55, 2);
    DISPLAY(START);
    INSERT(&START, 66, 1);
    DISPLAY(START);
    INSERT(&START, 77, 1);
    DISPLAY(START);
    if(DELETE(&START, ITEM, PARIORITY))
    cout << "ITEM = " << ITEM << " PARIORITY " << PARIORITY << endl ;
    DISPLAY(START);
    if(DELETE(&START, ITEM, PARIORITY))
    cout << "ITEM = " << ITEM << " PARIORITY " << PARIORITY << endl ;
    DISPLAY(START);
    if(DELETE(&START, ITEM, PARIORITY))
    cout << "ITEM = " << ITEM << " PARIORITY " << PARIORITY << endl ;
    DISPLAY(START);
    if(DELETE(&START, ITEM, PARIORITY))
    cout << "ITEM = " << ITEM << " PARIORITY " << PARIORITY << endl ;
    DISPLAY(START);
    if(DELETE(&START, ITEM, PARIORITY))
    cout << "ITEM = " << ITEM << " PARIORITY " << PARIORITY << endl ;
    DISPLAY(START);
    if(DELETE(&START, ITEM, PARIORITY))
    cout << "ITEM = " << ITEM << " PARIORITY " << PARIORITY << endl ;
    DISPLAY(START);
    if(DELETE(&START, ITEM, PARIORITY))
    cout << "ITEM = " << ITEM << " PARIORITY " << PARIORITY << endl ;
    DISPLAY(START);
    
    if(DELETE(&START, ITEM, PARIORITY))
    cout << "ITEM = " << ITEM << " PARIORITY " << PARIORITY << endl ;
    DISPLAY(START);
    if(DELETE(&START, ITEM, PARIORITY))
    cout << "ITEM = " << ITEM << " PARIORITY " << PARIORITY << endl ;
    DISPLAY(START);
    if(DELETE(&START, ITEM, PARIORITY))
    cout << "ITEM = " << ITEM << " PARIORITY " << PARIORITY << endl ;
    DISPLAY(START);
}
/*
ITEM = 22 PARIORITY 2
UNDER FLOW
11 _ 1 -> 33 _ 2 -> 33 _ 2 -> 44 _ 3 -> 22 _ 2 -> 44 _  3

ITEM = 11 PARIORITY 1
33 _ 2 -> 33 _ 2 -> 44 _ 3 -> 22 _ 2 -> 44 _  3

33 _ 2 -> 33 _ 2 -> 55 _ 2 -> 44 _ 3 -> 22 _ 2 -> 44 _  3

66 _ 1 -> 33 _ 2 -> 33 _ 2 -> 55 _ 2 -> 44 _ 3 -> 22 _ 2 -> 44 _  3

66 _ 1 -> 77 _ 1 -> 33 _ 2 -> 33 _ 2 -> 55 _ 2 -> 44 _ 3 -> 22 _ 2 -> 44 _  3

ITEM = 66 PARIORITY 1
77 _ 1 -> 33 _ 2 -> 33 _ 2 -> 55 _ 2 -> 44 _ 3 -> 22 _ 2 -> 44 _  3

ITEM = 77 PARIORITY 1
33 _ 2 -> 33 _ 2 -> 55 _ 2 -> 44 _ 3 -> 22 _ 2 -> 44 _  3

ITEM = 33 PARIORITY 2
33 _ 2 -> 55 _ 2 -> 44 _ 3 -> 22 _ 2 -> 44 _  3

ITEM = 33 PARIORITY 2
55 _ 2 -> 44 _ 3 -> 22 _ 2 -> 44 _  3

ITEM = 55 PARIORITY 2
44 _ 3 -> 22 _ 2 -> 44 _  3

ITEM = 44 PARIORITY 3
22 _ 2 -> 44 _  3

ITEM = 22 PARIORITY 2
44 _  3

ITEM = 44 PARIORITY 3
UNDER FLOW
UNDER FLOW
*/
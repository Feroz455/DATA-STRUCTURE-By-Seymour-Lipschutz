/*
6.24 Consider the priority queue in Fig. 6.35(b), which is maintained 
as a one-way list.

(a) Describe the structure if two elements are deleted.

(b) Describe the structure if, after the preceding deletions, the elements 
(RRR, 3), (SSS, 1), (TIT, 3) and (UUU, 2) are added to the queue.

(c) Describe the structure if, after the preceding insertions, three elements are deleted.
*/
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
typedef struct _pQueue
{
    string ITEM;
    int PRIORITY;
    _pQueue *next;
}P_QUEUE;

void INSERT_FIRST(P_QUEUE **START, string ITEM, int PARIORITY)
{
    P_QUEUE *PTR = new P_QUEUE;
    PTR->ITEM = ITEM;
    PTR->PRIORITY = PARIORITY;
    PTR->next = (*START);
    (*START) = PTR;
}
void INSERT(P_QUEUE **START, string ITEM, int PARIORITY)
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
        TEMP->ITEM = ITEM;
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

int DELETE(P_QUEUE **START,string ITEM, int &PARIORITY)
{
    if((*START) == NULL)
    {
        cout << "UNDER FLOW\n";
        return 0;
    }
    P_QUEUE *PTR = (*START);
    ITEM = (*START)->ITEM;
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
        cout << PTR->ITEM << "_" << PTR->PRIORITY << " -> ";
        PTR = PTR->next;
    }
    cout << PTR->ITEM << "_" << PTR->PRIORITY  << endl;
    cout << "\n";
}
int main()
{
    P_QUEUE *START = NULL;
    string ITEM;
    int PARIORITY;
    ITEM = "UUU" , PARIORITY = 2;
    INSERT(&START, ITEM, PARIORITY);
    ITEM = "RRR" , PARIORITY = 3;
    INSERT(&START, ITEM, PARIORITY);
    ITEM = "SSS" , PARIORITY = 1;
    INSERT(&START, ITEM, PARIORITY);
    ITEM = "TTT" , PARIORITY = 3;
    INSERT(&START, ITEM, PARIORITY);
    DISPLAY(START);
}
/*
output
SSS_1 -> UUU_2 -> RRR_3 -> TTT_3
*/
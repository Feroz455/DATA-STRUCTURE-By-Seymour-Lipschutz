/*
page 209
6.28 Consider the priority queue in Fig. 6.30, which is maintained by a 
two-dimensional array QUEUE. (a) Describe the structure after (RRR, 3), 
(SSS, 4), (TTT, 1), (UUU, 4) and (VVV, 2) are added to the queue. 
(b) Describe the structure if, after the preceding insertions, three elements are deleted.

(a) Insert each element in its priority row. That is, add RRR as the rear 
element in row 3, add SSS as the rear element in row 4, add TTT as the rear 
element in row 1, add UUU as the rear element in row 4 and add VVV as the 
rear element in row 2. This yields the structure in Fig. 6.36(a). (As noted 
previously, insertions with this array representation are usually simpler 
than insertions with the one-way list representation.)

(b) First delete the elements with the highest priority in row 1. Since row 1 
contains only two elements, AAA and TTT, then the front element in row 2, BBB, 
must also be deleted. This finally leaves the structure in Fig. 6.36(b).

Remark: Observe that, in both cases, FRONT and REAR are changed accordingly.
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

    ITEM = "AAA" , PARIORITY = 1;
    INSERT(&START, ITEM, PARIORITY);
    ITEM = "TTT" , PARIORITY = 1;
    INSERT(&START, ITEM, PARIORITY);
    ITEM = "BBB" , PARIORITY = 2;
    INSERT(&START, ITEM, PARIORITY);
    ITEM = "CCC" , PARIORITY = 2;
    INSERT(&START, ITEM, PARIORITY);
    ITEM = "XXX" , PARIORITY = 2;
    INSERT(&START, ITEM, PARIORITY);
    ITEM = "VVV" , PARIORITY = 2;
    INSERT(&START, ITEM, PARIORITY);
    DISPLAY(START);
}
/*
output
AAA_1 -> TTT_1 -> BBB_2 -> CCC_2 -> XXX_2 -> VVV_2
*/
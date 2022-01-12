/*
Page 142
Algorithm 5.12: SRCHHL(INFO, LINK, START, ITEM, LOC)
LIST is a circular header list in memory. This algorithm finds the location LOC of the node where ITEM first appears in LIST or sets LOC = NULL.

1. Set PTR := LlNK[START].

2. Repeat while INFO[PTR] ≠ ITEM and PTR ≠ START:

Set PTR :=LlNK[PTR]. [PTR now points to the next node.]

[End of loop.]

3. If INFO[PTR] = ITEM, then:

Set LOC := PTR.

Else:

Set LOC := NULL.

[End of If structure.]

4. Exit
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
typedef struct _link
{
    int DATA;
    _link *next;
}LINKED;
/****************************/
void ADD_TILE(LINKED **HEAD, int DATA)
{
    LINKED *PTR  = *HEAD , *NEW;
    if(*HEAD == NULL)
    {
        *HEAD = new LINKED;
        (*HEAD)->DATA = DATA;
        (*HEAD)->next = *HEAD;
    }
    else 
    {
        while(PTR->next != *HEAD)
        {
            PTR = PTR->next;
        }
        NEW = new LINKED;
        NEW->DATA = DATA;
        NEW->next = *HEAD;
        PTR->next = NEW;
    }
    return;
}
void DISPLAY(LINKED *HEAD)
{
    LINKED *PTR = HEAD;
    while(PTR->next != HEAD)
    {
        cout << PTR->DATA << " \n";
        PTR = PTR->next;
    }
    cout << PTR->DATA << " \n";
}
int SRCHHL(LINKED *HEAD, int ITEM)
{
    int LOC = 1;
    LINKED *PTR = HEAD;
    while(PTR->next != HEAD && PTR->DATA != ITEM)
    {
        LOC++;
        PTR = PTR->next;
    }
    if(PTR->DATA == ITEM)
    {
        cout << "ITEM FOUND AT " << LOC << " \n"; 
        return LOC;
    }
    else
    cout << "ITEM NOT FOUND\n";
    return 0;
    
}

/* Function to delete a given node from the list */
void DELETE(LINKED** HEAD, int key) 
{
    
    // If linked list is empty
    if (*HEAD == NULL)
        return;
        
    // If the list contains only a single node
    if((*HEAD)->DATA==key && (*HEAD)->next==*HEAD)
    {
        delete *HEAD;
        *HEAD=NULL;
        return;
    }
    
    LINKED *LAST = *HEAD ,*prev;
    
    // If head is to be deleted
    if((*HEAD)->DATA==key) 
    {
        
        // Find the last node of the list
        while(LAST->next!=*HEAD)
            LAST=LAST->next;
            
        // Point last node to the next of head i.e. 
        // the second node of the list
        LAST->next = (*HEAD)->next;
        delete *HEAD;
        *HEAD = LAST->next;
      return;
    }
    
    // Either the node to be deleted is not found 
    // or the end of list is not reached
    while(LAST->next != *HEAD && LAST->next->DATA != key) 
    {
        LAST =  LAST->next;
    }
    
    // If node to be deleted was found
    if(LAST->next->DATA==key) 
    {
        prev=LAST->next;
        LAST->next=prev->next;
        delete prev;
    }
    else
        cout<<"no such keyfound";
    }
int main()
{
    int DATA;
    LINKED *HEAD;
    HEAD = NULL;
    for(int i = 1; i < 11; i++)
    {
        ADD_TILE(&HEAD, i*10);
        //cout << "I = " << i*10 << endl;
     }
    DISPLAY(HEAD);
    DELETE(&HEAD, 10);
    cout << "\n**************\n";
    DISPLAY(HEAD);
}

/*
5.7 Form header (circular) lists from the one-way lists in Fig. 5.11.

Choose TEST[l] as a header node for the list ALG, and TEST[16] as a header node 
for the list GEOM. Then, for each list:

(a) Change the list pointer variable so that it points to the header node.

(b) Change the header node so that it points to the first node in the list.

(c) Change the last node so that it points back to the header node.

Finally, reorganize the AVAIL list. Figure 5.43 shows the updated data structure.
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
void SRCHHL(LINKED *HEAD, int ITEM)
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
    }
    else
    cout << "ITEM NOT FOUND\n";
    
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
    SRCHHL(HEAD, 10);

}
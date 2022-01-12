/*
Page 142

Algorithm 5.11: (Traversing a Circular Header List) Let LIST be a circular header 
list in memory. This algorithm traverses LIST, applying an operation PROCESS to each node of LIST.
1. Set PTR := LINK[START]. [Initializes the pointer PTR.]
2. Repeat Steps 3 and 4 while PTR ≠ START:
3.       Apply PROCESS to INFO[PTR].
4.       Set PTR := LINK[PTR]. [PTR now points to the next node.]
[End of Step 2 loop.]
5. Exit.
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

}

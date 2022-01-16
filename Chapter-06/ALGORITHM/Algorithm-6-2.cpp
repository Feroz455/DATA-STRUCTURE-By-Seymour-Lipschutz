/*
Page 167
Procedure 6.2: POP(STACK, TOP, ITEM)

This procedure deletes the top element of STACK and assigns it to the variable

ITEM.

1. [Stack has an item to be removed?]
If TOP = 0, then: Print: UNDERFLOW, and Return.

2. Set ITEM := STACK[TOP]. [Assigns TOP element to ITEM.]

3. Set TOP := TOP – 1. [Decreases TOP by 1.]

4. Return.
*/
#include<iostream>
#include<iomanip>
using namespace std;
typedef struct _link
{
    int DATA;
    _link *next;
}STACK;
void PUSH(STACK **TOP, int DATA)
{
    if(*TOP == NULL)
    {
        STACK *PTR = new STACK;
        PTR->DATA = DATA;
        PTR->next = NULL;
        (*TOP) = PTR;
        return;
    }
    STACK *PTR = new STACK;
    PTR->DATA = DATA;
    PTR->next = (*TOP);
    (*TOP) = PTR;
}
int POP(STACK **TOP)
{
    if(*TOP == NULL)
    {
        cout << "UNDER FLOW\n";
        return 0;
    }
    int temp = (*TOP)->DATA;
    (*TOP) = (*TOP)->next;
    return temp;
}
int main()
{
    STACK *TOP = NULL;
    for(int i = 1; i <= 10; i++)
    {
        PUSH(&TOP,i);
    }
    int temp = POP(&TOP);
    while(temp)
    {
        cout << temp << "  ";
        temp = POP(&TOP);
    }

}
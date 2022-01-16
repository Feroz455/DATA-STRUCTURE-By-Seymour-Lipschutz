/*
Page 167
Procedure 6.1: PUSH(STACK, TOP, MAXSTK, ITEM)

This procedure pushes an ITEM onto a stack.

1. [Stack already filled?]
If TOP = MAXSTK, then: Print: OVERFLOW, and Return.

2. Set TOP := TOP + 1. [Increases TOP by 1.]

3. Set STACK[TOP] := ITEM. [Inserts ITEM in new TOP position.]

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
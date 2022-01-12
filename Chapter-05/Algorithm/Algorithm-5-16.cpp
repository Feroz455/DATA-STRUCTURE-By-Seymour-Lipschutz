/*
Algorithm 5.16: INSTWL(INFO, FORW, BACK, START, AVAIL, LOCA, LOCB, ITEM)
1. [OVERFLOW?] If AVAIL = NULL, then: Write: OVERFLOW, and Exit.
2. [Remove node from AVAIL list and copy new data into node.]
Set NEW := AVAIL, AVAIL := FORW[AVAIL], INFO[NEW] := ITEM.
3. [Insert node into list.]
Set FORW[LOCA] := NEW, FORW[NEW] := LOCB,
BACK[LOCB] := NEW, BACK[NEW] := LOCA.
4. Exit.
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

typedef struct _node
{
    int DATA;
    _node *next;
    _node *prev;
}NODE;

void INSERT_END(NODE **START, int DATA)
{
    cout << "INSERT_END\n";
    if(*START == NULL)
    {
        NODE * NEW = new NODE;
        NEW->DATA = DATA;
        NEW->next = NEW->prev = NEW;
        *START = NEW;
        return;
    }
    NODE *LAST = (*START)->prev;
    NODE *NEW_NODE = new NODE;
    NEW_NODE->DATA = DATA;
    NEW_NODE->next = *START;
    (*START)->prev = NEW_NODE;
    NEW_NODE->prev = LAST;
    LAST->next = NEW_NODE; 
}
void INSERT_BEGIN(NODE **START, int DATA)
{
    cout << "INSERT_BEGIN\n";
    NODE *LAST = (*START)->prev;

    NODE *NEW_NODE = new NODE;
    NEW_NODE->DATA = DATA;

    NEW_NODE->next = *START;
    NEW_NODE->prev = LAST;

    LAST->next = (*START)->prev = NEW_NODE;
    *START = NEW_NODE;
}
void INSERT_AFTER(NODE **START, int DATA1, int DATA2)
{
    cout << "INSERT_AFTER\n";
    NODE *NEW_NODE = new NODE;

    NEW_NODE->DATA = DATA1;

    NODE *PTR = *START;
    while(PTR->DATA != DATA2 && PTR != *START)
    {
        PTR = PTR->next; 
    }
    NODE *NEXT_NODE = PTR->next;
    PTR->next = NEW_NODE;
    NEW_NODE->prev = PTR;
    NEW_NODE->next = NEXT_NODE;
    NEXT_NODE->prev = NEW_NODE;
}
void insertAfter(NODE** start, int value1,
                                      int value2)
{
    cout << "\n*****\n";
    NODE* new_node = new NODE;
    new_node->DATA = value1; // Inserting the data
    NODE *temp = *start;
    while (temp->DATA != value2 && temp != *start)
    {
        temp = temp->next;
    }

    NODE *next = temp->next;
    // insert new_node between temp and next.
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = next;
    next->prev = new_node;

}
 
void DISPLAY(NODE *START)
{
    NODE *PTR = START;
    cout << "\nPRINTING THE LIST\n";
    while (PTR->next != START)
    {
        cout << PTR->DATA << endl;
        PTR = PTR->next;
    }
    cout << PTR->DATA << endl;
    
}
int main()
{
    NODE *START = NULL;
    INSERT_END(&START , 5);
    INSERT_END(&START , 10);
    INSERT_END(&START , 15);
    INSERT_END(&START , 20);
    DISPLAY(START);
    INSERT_BEGIN(&START, 4);
    INSERT_END(&START, 7);
    cout << "\n---------\n";
    insertAfter(&START, 22, 20);
    cout << "\n---------\n";
    DISPLAY(START);
    return 0;
}
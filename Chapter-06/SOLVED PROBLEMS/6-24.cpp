/*
6.25 Consider a deque maintained by a circular array with N memory cells.

(a) Suppose an element is added to the deque. How is LEFT or RIGHT changed?

(b) Suppose an element is deleted. How is LEFT or RIGHT changed?

(a) If the element is added on the left, then LEFT is decreased by 1 (mod N). On 
the other hand, if the element is added on the right, then RIGHT is increased by 1 (mod N).

(b) If the element is deleted from the left, then LEFT is increased by 1 (mod N). 
However if the element is deleted from the right, then RIGHT is decreased by 1 
(mod N). In the case that LEFT = RIGHT before the deletion (that is, when the 
deque has only one element), then LEFT and RIGHT are both assigned NULL to ind
icate that the deque is empty.
*/
#include<iostream>
using namespace std;
typedef struct _queue
{
    int data;
    _queue *next;
}DQ;

void insert_right(DQ **START, int data)
{

        DQ *PTR = new DQ;
        PTR->data = data;
        PTR->next = *START;
        (*START) = PTR;
}
void insert_left(DQ **START, int data)
{
    if(*START == NULL)
    {
        insert_right(START, data);
        return;
    }

    DQ *PTR = (*START), *temp = new DQ;
    temp->data = data;
    temp->next = NULL;
    while (PTR->next != NULL)
    {
        PTR  = PTR->next;
    }
    PTR->next = temp;
}
void display(DQ *start)
{
    if(start == NULL)
    {
        cout << "list is empty\n";
        return;
    }
    else
    {
        DQ *PTR = start;
        while (PTR->next != NULL)
        {
            cout << PTR->data << " " ;
            PTR = PTR->next;
        }
        cout << PTR->data << " \n" ;
        return;  
    }
}
bool delete_left(DQ **START, int &item)
{
    if((*START) == NULL)
    {
        cout << "UNDERFLOW\n";
        return 0;
    }
    DQ *PTR =(*START);
    item = PTR->data;
    (*START) = (*START)->next;
    delete PTR;
    return 1;
}

bool delete_right(DQ **START, int &item)
{
    if((*START) == NULL)
    {
        cout << "UNDERFLOW\n";
        return 0;
    }
    DQ *PTR =(*START),*prev;
    while (PTR->next != NULL)
    {
        prev = PTR;
        PTR = PTR->next;
    }
    item =  PTR->data;
    prev->next = NULL;
    delete PTR;
    return 1;
}
int main()
{
    int ITEM;
    DQ *START = NULL;
    for(int i = 0; i < 10; i++)
    {
        insert_right(&START, i+1);
    }
    if(delete_right(&START, ITEM))
    {
        cout << ITEM << endl;
    }
    if(delete_right(&START, ITEM))
    {
        cout << ITEM << endl;
    }
    if(delete_right(&START, ITEM))
    {
        cout << ITEM << endl;
    }
    if(delete_right(&START, ITEM))
    {
        cout << ITEM << endl;
    }
    if(delete_left(&START, ITEM))
    {
        cout << ITEM << endl;
    }
    display(START);
    return 0;
}
/*
1
2
3
4
10        
9 8 7 6 5 
*/
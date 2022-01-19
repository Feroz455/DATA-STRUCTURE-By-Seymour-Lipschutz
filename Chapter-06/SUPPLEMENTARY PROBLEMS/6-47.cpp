/*
6.22 Consider the following deque where DEQUE is allocated 6 memory cells:

LEFT = 2, RIGHT = 5 DEQUE: ______, London, Berlin, Rome, Paris, ______

Describe the deque, including LEFT and RIGHT, as the following operations take place:

(a) Athens is added on the left.

(b) Two cities are deleted from the right.

(c) Madrid is added on the left.

(d) Moscow is added on the right.

(e) Two cities are deleted from the right.

(f) A city is deleted from the left.

(g) Oslo is added on the left
*/
#include<iostream>
#include<string>
using namespace std;
typedef struct _queue
{
    string data;
    _queue *next;
}DQ;

void insert_right(DQ **START, string data)
{

        DQ *PTR = new DQ;
        PTR->data = data;
        PTR->next = *START;
        (*START) = PTR;
}
void insert_left(DQ **START, string data)
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
bool delete_left(DQ **START, string &item)
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

bool delete_right(DQ **START, string &item)
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
    string ITEM;
    DQ *START = NULL;
    //______, London, Berlin, Rome, Paris, ______
    ITEM = "AAAAA"; 
    insert_right(&START, ITEM);
    ITEM = "London"; 
    insert_right(&START, ITEM);
    ITEM = "Berlin"; 
    insert_right(&START, ITEM);
    ITEM = "Rome"; 
    insert_right(&START, ITEM);
    ITEM = "Paris"; 
    insert_right(&START, ITEM);

    if(delete_right(&START,ITEM))
    {
        cout << ITEM << endl;
    }
    ITEM = "Athens"; 
    insert_left(&START, ITEM);
    if(delete_right(&START,ITEM))
    {
        cout << ITEM << endl;
    }
    if(delete_right(&START,ITEM))
    {
        cout << ITEM << endl;
    }
    ITEM = "Madrid"; 
    insert_left(&START, ITEM);
    ITEM = "Moscow"; 
    insert_right(&START, ITEM);
    if(delete_right(&START,ITEM))
    {
        cout << ITEM << endl;
    }
    if(delete_right(&START,ITEM))
    {
        cout << ITEM << endl;
    }
    if(delete_left(&START,ITEM))
    {
        cout << ITEM << endl;
    }
    ITEM = "Oslo"; 
    insert_right(&START, ITEM);   


    return 0;
}
/*
AAAAA 
Athens
London
Madrid
Berlin
Moscow
*/
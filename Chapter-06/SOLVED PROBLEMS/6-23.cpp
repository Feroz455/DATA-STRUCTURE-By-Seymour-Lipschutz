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
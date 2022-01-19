/*
Page 212
6.23 Suppose a queue is maintained by a circular array 
QUEUE with N = 12 memory cells. Find the number of elements 
in QUEUE if (a) FRONT = 4, REAR = 8; (b) FRONT = 10, 
REAR = 3; and (c) FRONT = 5, REAR = 6 and then two elements are deleted.
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
void QINSERT(string QUEUE[], int N, int &FRONT, int &REAR, string &ITEM)
{
    if(((FRONT == 0) && (REAR == N-1)) || FRONT == REAR+1)
    {
        cout << "OVERFLOW\n";
        return;
    }
    if(FRONT == -1)
    {
        FRONT = 0;
        REAR = 0;
    }
    else 
    if(REAR == N-1)
    {
        REAR = 0;
    }
    else 
    REAR = REAR+1;
    QUEUE[REAR] = ITEM;
    return;
}
int QDELETE(string QUEUE[], int N, int &FRONT, int &REAR, string &ITEM)
{
    if(FRONT == -1)
    {
        cout << "UNDERFLOW\n";
        return 0;
    }
    else
    {
        ITEM = QUEUE[FRONT];
        if(FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        if(FRONT == N-1)
        FRONT = 0;
        else
        FRONT = FRONT + 1;
    }
   
    return 1;
}
int main()
{
    int N = 12;
    string QUEUE[N], ITEM;
    int FRONT, REAR;
    FRONT = REAR = -1;
    //______, London, Berlin, Rome, Paris, ______
    ITEM = "AAAAAA";
    QINSERT(QUEUE,N, FRONT, REAR, ITEM);   
    ITEM = "London";
    QINSERT(QUEUE,N, FRONT, REAR, ITEM);
    ITEM = "Berlin";
    QINSERT(QUEUE,N, FRONT, REAR, ITEM);
    ITEM = "Rome";
    QINSERT(QUEUE,N, FRONT, REAR, ITEM);
    ITEM = "Paris";
    QINSERT(QUEUE,N, FRONT, REAR, ITEM);
    ITEM = "Athens";
    QINSERT(QUEUE,N, FRONT, REAR, ITEM);
    ITEM = "Madrid";
    QINSERT(QUEUE,N, FRONT, REAR, ITEM);
    ITEM = "Moscow";
    QINSERT(QUEUE,N, FRONT, REAR, ITEM);
    ITEM = "Oslo";
    QINSERT(QUEUE,N, FRONT, REAR, ITEM);
    if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    {
        cout << ITEM << endl;
    }
    if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    {
        cout << ITEM << endl;
    }
     if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    {
        cout << ITEM << endl;
    }
    if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    {
        cout << ITEM << endl;
    }
     if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    {
        cout << ITEM << endl;
    }
    if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    {
        cout << ITEM << endl;
    }
     if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    {
        cout << ITEM << endl;
    }
    if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    {
        cout << ITEM << endl;
    }
}
/*
AAAAAA
London
Berlin
Rome  
Paris 
Athens
Madrid
Moscow

///////////////////////
_ _ _ _ _ _ _ _ _ _ _ _ 
_ _ _ _ * * * * _ _ _ _ 
* * * _ _ _ _ _ _ * * *
_ _ _ _ _ * _ _ _ _ _ _ 

*/
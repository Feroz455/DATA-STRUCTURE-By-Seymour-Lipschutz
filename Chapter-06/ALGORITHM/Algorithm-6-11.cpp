/*
Procedure 6.13: QINSERT(QUEUE, N, FRONT, REAR, ITEM)

This procedure inserts an element ITEM into a queue.

1. [Queue already filled?]
If FRONT = 1 and REAR = N, or if FRONT = REAR + 1, then:

Write: OVERFLOW, and Return.

2. [Find new value of REAR.]
If FRONT := NULL, then: [Queue initially empty.]

Set FRONT := 1 and REAR := 1.

Else if REAR = N, then:

Set REAR := 1.

Else:

Set REAR := REAR + 1.

[End of If structure.]

3. Set QUEUE[REAR] := ITEM. [This inserts new element.]

4. Return.
*/
#include<iostream>
#include<iomanip>
using namespace std;
void QINSERT(int QUEUE[], int N, int &FRONT, int &REAR, int ITEM)
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
int main()
{
    int N = 5;
    int QUEUE[N];
    int FRONT, REAR, ITEM;
    FRONT = REAR = -1;
    for(int i = 0; i < 5; i++)
    {
        QINSERT(QUEUE, N, FRONT, REAR, i);
    }
    cout << QUEUE[FRONT];
}
/*
0
*/
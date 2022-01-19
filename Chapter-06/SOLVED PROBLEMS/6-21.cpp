/*
Page 192
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


/**********************************
* Procedure 6.14: QDELETE(QUEUE, N, FRONT, REAR, ITEM)

This procedure deletes an element from a queue and assigns it to the variable ITEM.

1. [Queue already empty?]
If FRONT := NULL, then: Write: UNDERFLOW, and Return.

2. Set ITEM := QUEUE[FRONT].

3. [Find new value of FRONT.]

If FRONT = REAR, then: [Queue has only one element to start.]
Set FRONT := NULL and REAR := NULL.

Else if FRONT = N, then:
Set FRONT := 1.

Else:
Set FRONT := FRONT + 1.

[End of If structure.]

4. Return.
*/
#include<iostream>
#include<iomanip>
using namespace std;
void QINSERT(char QUEUE[], int N, int &FRONT, int &REAR, char &ITEM)
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
int QDELETE(char QUEUE[], int N, int &FRONT, int &REAR, char &ITEM)
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
    int N = 6;
    char QUEUE[N];
    int FRONT, REAR;
    char ITEM;
    FRONT = REAR = -1;
    ITEM = 'B';
    QINSERT(QUEUE, N, FRONT, REAR, ITEM);
    ITEM = 'A';
    QINSERT(QUEUE, N, FRONT, REAR, ITEM);
    ITEM = 'C';
    QINSERT(QUEUE, N, FRONT, REAR, ITEM);
    ITEM = 'D';
    QINSERT(QUEUE, N, FRONT, REAR, ITEM);
    if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    cout << ITEM << endl;
    if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    cout << ITEM << endl;
    if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    cout << ITEM << endl;
    ITEM = 'K';
    QINSERT(QUEUE, N, FRONT, REAR, ITEM);
    ITEM = 'L';
    QINSERT(QUEUE, N, FRONT, REAR, ITEM);
    ITEM = 'M';
    QINSERT(QUEUE, N, FRONT, REAR, ITEM);
     if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    cout << ITEM << endl;
    if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    cout << ITEM << endl;
    ITEM = 'R';
    QINSERT(QUEUE, N, FRONT, REAR, ITEM);
    if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    cout << ITEM << endl;
    if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    cout << ITEM << endl;
    ITEM = 'S';
    QINSERT(QUEUE, N, FRONT, REAR, ITEM);
    if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    cout << ITEM << endl;
    if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    cout << ITEM << endl;
    if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    cout << ITEM << endl;
    if(QDELETE(QUEUE, N, FRONT, REAR, ITEM))
    cout << ITEM << endl;
}
/*
B
A
C
D
K
L
M
R
S
UNDERFLOW
UNDERFLOW
*/
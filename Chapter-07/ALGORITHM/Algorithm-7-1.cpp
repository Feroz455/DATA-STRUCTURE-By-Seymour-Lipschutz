/*
Algorithm 7.1: PREORD(INFO, LEFT, RIGHT, ROOT)
A binary tree T is in memory. The algorithm does a preorder traversal of T, 
applying an operation PROCESS to each of its nodes. An array STACK is used 
to temporarily hold the addresses of nodes.

1. [Initially push NULL onto STACK, and initialize PTR.]
Set TOP := 1, STACK[1] := NULL and PTR := ROOT.

2. Repeat Steps 3 to 5 while PTR ≠ NULL:

3. Apply PROCESS to INFO[PTR].

4. [Right child?]

If RIGHT[PTR] ≠ NULL, then: [Push on STACK.]

  Set TOP := TOP + 1, and STACK[TOP] := RIGHT[PTR].

[End of If structure.]

5. [Left child?]

If LEFT[PTR] ≠ NULL, then:

  Set PTR := LEFT[PTR].

Else: [Pop from STACK.]

  Set PTR := STACK[TOP] and TOP := TOP – 1.

[End of If structure.]

[End of Step 2 loop.]

6. Exit.
*/
#include<iostream>
using namespace std;
template<typename T>
void PREORD(T INFO[], int LEFT[], int RIGHT[], int ROOT)
{
    int STACK[10], PTR, TOP;
    STACK[0] = -1;
    PTR = ROOT;
    TOP = 0;
    while(PTR != -1)
    {
        cout << INFO[PTR];
        if(RIGHT[PTR] != NULL)
        {
            TOP = TOP + 1;
            STACK[TOP]  = RIGHT[PTR];
        }
        if(LEFT[PTR] != -1)
        {
            PTR = LEFT[PTR];
        }
        else
        {
            PTR = STACK[TOP];
            TOP =  TOP - 1;
        }
    }
    return ;

}

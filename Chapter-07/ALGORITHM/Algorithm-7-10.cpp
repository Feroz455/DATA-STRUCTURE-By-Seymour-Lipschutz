/*
page 247
Procedure 7.10: DELHEAP(TREE, N, ITEM)

A heap H with N elements is stored in the array TREE. This procedure assigns the root TREE[1] of H to the variable ITEM and then reheaps the remaining elements. The variable LAST saves the value of the original last node of H. The pointers PTR, LEFT and RIGHT give the locations of LAST and its left and right children as LAST sinks in the tree.

1. Set ITEM := TREE[1]. [Removes root of H.]

2. Set LAST := TREE[N] and N := N – 1. [Removes last node of H.]

3. Set PTR := 1, LEFT := 2 and RIGHT := 3. [Initializes pointers.]

4. Repeat Steps 5 to 7 while RIGHT ≤ N:

5.   If LAST ≥ TREE[LEFT] and LAST ≥ TREE[RIGHT], then:
    Set TREE[PTR] := LAST and Return.
  [End of If structure.]

6.   IF TREE[RIGHT] ≤ TREE[LEFT], then:
    Set TREE[PTR] := TREE[LEFT] and PTR := LEFT.
  Else:
    Set TREE[PTR] := TREE[RIGHT] and PTR := RIGHT.
  [End of If structure.]

7.   Set LEFT := 2*PTR and RIGHT := LEFT + 1.
[End of Step 4 loop.]

8. If LEFT = N and if LAST < TREE[LEFT], then: Set PTR := LEFT.

9. Set TREE[PTR] := LAST.

10. Return.
*/
#include<cmath>
#include<iostream>
using namespace std;

void INSHEAP(int TREE[], int &N, int ITEM)
{
    N = N + 1;
    int PTR = N, PAR, temp;
    while(PTR > 0)
    {
        PAR = floor(PTR/2);
        if(ITEM <= TREE[PAR])
        {
            TREE[PTR] = ITEM;
            return; 
        }
        temp = TREE[PTR];
        TREE[PTR] = TREE[PAR];
        TREE[PAR] = temp;
        PTR = PAR;
    }
    TREE[0] = ITEM;
    return;
}

void DELETE(int TREE[], int &N, int &ITEM)
{
    ITEM = TREE[0];
    int LAST = TREE[N];
    N = N - 1;
    int PTR = 0, temp;
    int LEFT = 1;
    int RIGHT = 2;
    while(RIGHT <= N)
    {
        if(LAST >= TREE[LEFT] && LAST >= TREE[RIGHT])
        {
            TREE[PTR] = LAST;
            return;
        }
        if(TREE[RIGHT] < TREE[LEFT])
        {

            temp = TREE[PTR];
            TREE[PTR] = TREE[LEFT];
            TREE[LEFT] = temp;
            PTR = LEFT;
        }
        else 
        {
            temp = TREE[PTR];
            TREE[PTR] = TREE[RIGHT];
            TREE[RIGHT] = temp;
            PTR = RIGHT;
        }
        LEFT = 2 * PTR;
        RIGHT = LEFT + 1;
    }
    if(LEFT ==  N)
    {
        if(LAST < TREE[LEFT])
        PTR = LEFT;
    }
    TREE[PTR] = LAST;
    return;
}
int main()
{
    int TREE[50];
    int N = -1, temp, ITEM;
    for(int i = 0; i < 11; i++)
    {
        cin >> temp;
        INSHEAP(TREE, N, temp);
    }
    for(int i = 0; i <= N; i++)
    {
        cout << TREE[i] << " " ;
    }
    cout << "\n";
    DELETE(TREE, N, ITEM);
    cout << ITEM;
}
/*
95
85
70
55
33
30
65
15
20
15
22
95 85 70 65 33 30 55 15 20 15 22 
95
*/
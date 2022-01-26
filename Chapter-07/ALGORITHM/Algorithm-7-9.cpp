/*
page 246
Procedure 7.9: INSHEAP(TREE, N, ITEM)
A heap H with N elements is stored in the array TREE, 
and an ITEM of information is given. This procedure inserts 
ITEM as a new element of H. PTR gives the location of ITEM 
as it rises in the tree, and PAR denotes the location of 
the parent of ITEM.

1. [Add new node to H and initialize PTR.]
Set N := N + 1 and PTR := N.

2. [Find location to insert ITEM.]
Repeat Steps 3 to 6 while PTR < 1.

3.   Set PAR := ⌊PTR/2⌋. [Location of parent node.]

4.   If ITEM ≤ TREE[PAR], then:
    Set TREE[PTR] := ITEM, and Return.
  [End of If structure.]

5.   Set TREE[PTR] := TREE[PAR]. [Moves node down.]

6.   Set PTR := PAR. [Updates PTR.] 
[End of Step 2 loop.]

7. [Assign ITEM as the root of H.]
Set TREE[I] := ITEM.

8. Return.
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
int main()
{
    int TREE[50];
    int N = -1, temp;
    for(int i = 0; i < 11; i++)
    {
        cin >> temp;
        INSHEAP(TREE, N, temp);
    }
    for(int i = 0; i <= N; i++)
    {
        cout << TREE[i] << " " ;
    }
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
*/
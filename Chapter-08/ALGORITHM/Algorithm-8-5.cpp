/*
page 290
Procedure 8.5 : FINDEDGE(NODE, NEXT, ADJ, START, DEST, LINK, A, B, LOC)
This procedure finds the location LOC of an edge (A, B) in the graph G, or sets LOC := NULL.

1. Call FIND(NODE, NEXT, START, A, LOCA).

2. CALL FIND(NODE, NEXT, START, B, LOCB).

3. If LOCA = NULL or LOCB = NULL, then: Set LOC := NULL.

Else: Call FIND(DEST, LINK, ADJ[LOCA], LOCB, LOC).

4. Return.
*//*
Procedure 8.3 : FIND(INFO, LINK START, ITEM, LOC) [Algorithm 5.2]

Finds the location LOC of the first node containing ITEM, or sets LOC := NULL.

1. Set PTR := START.

2. Repeat while PTR ≠ NULL:

If ITEM = INFO[PTR], then: Set LOC := PTR, and Return.

Else: Set PTR := LINK[PTR].

[End of loop.]

3. Set LOC := NULL, and Return
*/
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
void PRINT(list<int> A, list<int> X[])
{
    list<int>::iterator ptr = A.begin();
    cout << "\n==========GRAPH=============\n";
    while (ptr != A.end())
    {
        list<int>::iterator ptr1 = X[*ptr].begin();
        cout << *ptr << " -> ";
        while (ptr1 != X[*ptr].end())
        {
            cout << *ptr1++ << " ";
        }
        cout << "\n";
        ptr++;
    }

    cout << "=======================\n";
}
void FINDEDGE(list<int> A, list<int> X[], int SRC, int DEST, int NODE)
{
    if (SRC > NODE)
    {
        return;
    }
    else
    {
        list<int>::iterator ptr = find(A.begin(), A.end(), SRC);
        if (ptr != A.end())
        {
            list<int>::iterator temp = find(X[*ptr].begin(), X[*ptr].end(), DEST);
            if (temp != X[*ptr].end())
            {
                cout << "Match found\n";
                cout << SRC << " -> " << DEST <<endl;
            }
            else
            {
                cout << "NOT FOUND\n";
            }
        }
        else
        {
            cout << "NOT FOUND\n";
        }
    }
}
int main()
{
    list<int> A;
    list<int> X[2000];
    int EDGE, NODE, SRC, DEST;
    cout << "Enter Nodes and EDGE\n";
    cin >> NODE >> EDGE;

    for (int i = 0; i < EDGE; i++)
    {
        cin >> SRC >> DEST;
        X[SRC].push_back(DEST);
    }
    for (int i = 0; i < NODE; i++)
    {
        A.push_back(i);
    }
    PRINT(A, X);
    FINDEDGE(A, X, 0, 2, NODE);
}
/*
Enter Nodes and EDGE
5 7
0 1
0 2
0 3
1 2
3 2
3 4
4 2

==========GRAPH=============
0 -> 1 2 3
1 -> 2
2 ->
3 -> 2 4
4 -> 2
=======================
Match found
0 -> 2
*/
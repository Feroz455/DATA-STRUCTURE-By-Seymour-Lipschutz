/*
page 292
Procedure 8.9 : DELNODE(NODE, NEXT, ADJ, START, AVAILN, DEST, LINK, AVAILE, N, FLAG)

This procedure deletes the node N from the graph G.

1. Call FIND(NODE, NEXT, START, N, LOC). [Locates node N.]

2. If LOC = NULL, then: Set FLAG := FALSE, and Return.

3. [Delete edges ending at N.]

(a) Set PTR := START.

(b) Repeat while PTR ≠ NULL:

(i) Call DELETE(DEST, LINK, ADJ[PTR], AVAILE, LOC, FLAG).

(ii) Set PTR := NEXT[PTR].

[End of loop.]

4. [Successor list empty?] If ADJ[LOC] = NULL, then: Go to Step 7.

5. [Find the first and last successor of N.]

(a) Set BEG := ADJ[LOC], END := ADJ[LOC] and PTR := LINK[END].

(b) Repeat while PTR ≠ NULL:

Set END := PTR and PTR := LINK[PTR].

[End of loop.]

6. [Add successor list of N to AVAILE list.]

Set LINK[END] := AVAILE and AVAILE := BEG.

7. [Delete N using Procedure 8.4.]

Call DELETE(NODE, NEXT, START, AVAILN, N, FLAG).

8. Return.
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
void INSER_NODE(list<int> &A, list<int> X[], int &NODE)
{
    A.push_back(NODE);
    NODE = NODE + 1;
}
void INSERT_EDGE(list<int> X[], int NODE, int &EDGE, int SRC, int DEST)
{
    if (SRC > NODE && SRC > DEST)
    {
        return;
    }
    else
    {
        X[SRC].push_back(DEST);
        EDGE += 1;
    }
}
void DELETE_EDGE(list<int> X[], int SRC, int DEST, int NODE, int &EDGE)
{
    if (SRC > NODE || DEST > NODE)
        return;
    else
    {
        list<int>::iterator ptr = find(X[SRC].begin(), X[SRC].end(), DEST);
        if (ptr != X[SRC].end())
        {
            X[SRC].remove(DEST);
            EDGE -= 1;
        }
        else
            cout << "EDGE NOT EXIST\n";
    }

    return;
}
void DELETE_NODE(list<int> &A, list<int> X[], int &NODE, int node)
{
    list<int>::iterator ptr = A.begin();
    while (ptr != A.end())
    {
        X[*ptr].remove(node);
        ptr++;
    }
    X[node].clear();
    A.remove(node);
    NODE -= 1;
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
    DELETE_NODE(A, X, NODE, 4);
    PRINT(A, X);
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

==========GRAPH=============
0 -> 1 2 3
1 -> 2
2 -> 
3 -> 2
=======================
*/
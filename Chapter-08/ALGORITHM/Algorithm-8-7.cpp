/*
page 290
Algorithm 8.6
Procedure 8.6 : INSNODE(NODE, NEXT, ADJ, START, AVAILN, N, FLAG)

This procedure inserts the node N in the graph G.

1. [OVERFLOW?] If AVAILN = NULL, then: Set FLAG := FALSE, and Return.

2. Set ADJ[AVAILN] := NULL.

3. [Removes node from AVAILN list]

Set NEW := AVAILN and AVAILN := NEXT[AVAILN].

4. [Inserts node N in the NODE list.]

Set NODE[NEW] := N, NEXT[NEW] := START and START := NEW.

5. Set FLAG := TRUE, and Return.
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
    INSER_NODE(A,X,NODE);
    INSERT_EDGE(X, NODE, EDGE, 5, 2);
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
3 -> 2 4
4 -> 2
5 -> 2
=======================
*/
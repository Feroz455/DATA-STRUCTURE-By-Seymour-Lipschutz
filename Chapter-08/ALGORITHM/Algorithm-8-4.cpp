/*
page 290
Procedure 8.4 : DELETE(INFO, LINK, START, AVAIL, ITEM, FLAG)
[Algorithm 5.10] Deletes the first node in the list containing
ITEM, or sets FLAG := FALSE when ITEM does not appear in the list.

1. [List empty?] If START = NULL, then: Set FLAG := FALSE, and Return.

2. [ITEM in first node?] If INFO[START]. = ITEM, then:

Set PTR := START, START := LINK[START],

LINK[PTR] := AVAIL, AVAIL := PTR,

FLAG := TRUE, and Return.

[End of If structure.]

3. Set PTR := LINK[START] and SAVE := START. [Initializes pointers.}

4. Repeat Steps 5 and 6 while PTR ≠ NULL:

5.          If INFO[PTR] = ITEM, then:

Set LINK[SAVE] := LINK[PTR], LINK[PTR} := AVAIL,

AVAIL := PTR, FLAG := TRUE, and Return.

[End of If structure.]

6.          Set SAVE := PTR and PTR := LINK[PTR]. [Updates pointers]

[End of Step 4 loop.]

7. Set FLAG := FALSE, and Return.
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
*/
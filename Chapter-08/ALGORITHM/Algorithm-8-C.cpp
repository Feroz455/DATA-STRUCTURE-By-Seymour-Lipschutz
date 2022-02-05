/*
page 299
Algorithm C : This algorithm finds a topological sort T of a graph S without cycles.

1. Find the indegree INDEG(N) of each node N of S. (This can be done by
traversing each adjacency list as in Problem 8.15.)

2. Put in a queue all the nodes with zero indegree.

3. Repeat Steps 4 and 5 until the queue is empty.

4.          Remove the front node N of the queue (by setting FRONT := FRONT + 1).

5.          Repeat the following for each neighbor M of the node N:

(a) Set INDEG(M) := INDEG(M) ‒ 1.

[This deletes the edge from N to M.]

(b) If INDEG(M) = 0, then: Add M to the rear of the queue.

[End of loop.]

[End of Step 3 loop.]

6. Exit.
*/
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;
void PRINT(list<int> A, list<int> X[])
{
    list<int>::iterator ptr = A.begin();
    cout << "\n==========GRAPH=============\n";
    while (ptr != A.end())
    {
        list<int>::iterator ptr1 = X[*ptr].begin();
        cout << char((*ptr)+65) << " -> ";
        while (ptr1 != X[*ptr].end())
        {
            cout << char((*ptr1++)+65) << " ";
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

void INDEGREE(list<int> A, list<int> X[], int indg[])
{
    list<int>::iterator ptr = A.begin();
    while (ptr != A.end())
    {
        list<int>::iterator ptr1 = X[*ptr].begin();
        while (ptr1 != X[*ptr].end())
        {
            indg[*ptr1] += 1;
            ptr1++;
        }
        ptr++;
    }
    for (int i = 0; i < A.size(); i++)
    {
        cout << char(65 + i) << " -> " << indg[i] << " \n";
    }
    cout << "\n";
    return;
}

void TOPOLOGICAL_ORDER(list<int> A, list<int> X[])
{
    int indg[A.size()] = {0}, visit[A.size()] = {0}, temp = 0, check = 1;
    queue<int> Q;
    list<int>::iterator ptr;
    INDEGREE(A, X, indg);
    cout << "\nTOPOLOGICAL_ORDER\n";
    while (check)
    {
        check = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (indg[i] == 0 && visit[i] == 0)
            {
                visit[i] = 1;
                Q.push(i);
                check = 1;
            }
        }
        while (!Q.empty())
        {
            temp = Q.front();
            Q.pop();
            if (indg[temp] == 0)
            {
                cout << char(temp + 65) << " ";
            }
            ptr = X[temp].begin();
            while (ptr != X[temp].end())
            {
                indg[*ptr]--;
                ptr++;
            }
        }
    }
}
int main()
{
    list<int> A;
    list<int> X[2000];
    int EDGE, NODE, SRC, DEST;
    char n, m;
    cout << "Enter Nodes and EDGE\n";
    cin >> NODE >> EDGE;

    for (int i = 0; i < EDGE; i++)
    {
        cin >> n >> m;
        SRC = n - 65;
        DEST = m - 65;
        X[SRC].push_back(DEST);
    }
    for (int i = 0; i < NODE; i++)
    {
        A.push_back(i);
    }

    PRINT(A, X);
    TOPOLOGICAL_ORDER(A, X);
}
/*
Enter Nodes and EDGE
7 7
A C
B D
B F
D C
E C
G A
G F

==========GRAPH=============
A -> C
B -> D F
C ->
D -> C
E -> C
F ->
G -> A F
=======================     
A -> 1
B -> 0
C -> 3
D -> 1
E -> 0
F -> 2
G -> 0


TOPOLOGICAL_ORDER
B E G A D F C 
*/
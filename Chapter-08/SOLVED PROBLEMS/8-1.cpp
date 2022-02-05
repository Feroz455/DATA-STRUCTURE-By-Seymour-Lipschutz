/*
page 302
8.1 Consider the (undirected) graph G in Fig. 8.19.
(a) Describe G formally in terms of its set V of nodes and its set E of edges.
(b) Find the degree of each node.

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
        cout << char((*ptr) + 97) << " -> ";
        while (ptr1 != X[*ptr].end())
        {
            cout << char((*ptr1++) + 97) << " ";
        }
        cout << "\n";
        ptr++;
    }

    cout << "=======================\n";
}
void INDEGREE(list<int> A, list<int> X[])
{
    int indg[A.size()] = {0};
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
        cout<< "in_deg(" << char(97 + i) << "):  " << indg[i] << " \n";
    }
    cout << "\n";
    return;
}
void OUTDEGREE(list<int> A, list<int> X[])
{
    int outdeg[A.size()] = {0};
    list<int>::iterator ptr = A.begin();
    while (ptr != A.end())
    {
        outdeg[*ptr] = X[*ptr].size();
        ptr++;
    }
    for (int i = 0; i < A.size(); i++)
    {
        cout<< "out_deg(" << char(97 + i) << "):  " << outdeg[i] << " \n";
    }
    cout << "\n";
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
        SRC = n - 97;
        DEST = m - 97;
        X[SRC].push_back(DEST);
        X[DEST].push_back(SRC);
    }
    for (int i = 0; i < NODE; i++)
    {
        A.push_back(i);
    }
    PRINT(A, X);
    cout << "INDEGREE \n";
    INDEGREE(A, X);
    cout << "OUTDEGREE \n";
    OUTDEGREE(A, X);
}
/*
Enter Nodes and EDGE
5 7
a b
a c
a d
b c
b e
c d
c e
*/
/*
8.6 Consider the graph G in Fig. 8.37. Suppose the nodes are stored in 
memory in an array DATA as follows:
DATA: X, Y, Z, S, T
(a) Find the adjacency matrix A of G. 
(b) Find the path matrix P or G. 
(c) Is G strongly connected?

Fig. 8.37
*/
#include <iostream>
#include <list>
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
int main()
{
    list<int> A;
    list<int> X[2000];
    int EDGE, NODE, SRC, DEST;
    cout << "Enter Nodes and EDGE\n";
    cin >> NODE >> EDGE;

    int M, N;
    M = N = NODE;
    int **MATRIX = new int *[M];
    for (int i = 0; i < M; i++)
    {
        MATRIX[i] = new int[N];
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            MATRIX[i][j] = 0;
        }
    }

    for (int i = 0; i < EDGE; i++)
    {
        cin >> SRC >> DEST;
        X[SRC].push_back(DEST);
        MATRIX[SRC][DEST];
    }
    for (int i = 0; i < NODE; i++)
    {
        A.push_back(i);
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
           cout <<  MATRIX[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n*********************\n";
    return 0;
}
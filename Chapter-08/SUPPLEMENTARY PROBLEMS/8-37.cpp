

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
        cout << char((*ptr) + 65) << " -> ";
        while (ptr1 != X[*ptr].end())
        {
            cout << char((*ptr1++) + 65) << " ";
        }
        cout << "\n";
        ptr++;
    }

    cout << "=============================\n";
}
int FINDEDGE(list<int> A, list<int> X[], int SRC, int DEST, int NODE)
{
    if (SRC > NODE)
    {
        return 0;
    }
    else
    {
        list<int>::iterator ptr = find(A.begin(), A.end(), SRC);
        if (ptr != A.end())
        {
            list<int>::iterator temp = find(X[*ptr].begin(), X[*ptr].end(), DEST);
            if (temp != X[*ptr].end())
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
}

int check_underected(list<int> A, list<int> X[])
{
    list<int>::iterator Aptr = A.begin();
    while (Aptr != A.end())
    {
        list<int>::iterator Xptr = X[*Aptr].begin();
        if (FINDEDGE(A, X, *Xptr, *Aptr, A.size()) == 0)
        {
            return 0;
        }
    }
    return 1;
}
void MATRIX(list<int> A, list<int> X[])
{
    int M, N;
    M = N = A.size();
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
    list<int>::iterator Aptr = A.begin();
    while (Aptr != A.end())
    {
        list<int>::iterator Xptr = X[*Aptr].begin();
        while (Xptr != X[*Aptr].end())
        {
            MATRIX[*Aptr][*Xptr++] = 1;
        }
        Aptr++;
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << MATRIX[i][j] << " ";
        }
        cout << "\n";
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
    MATRIX(A, X);
}
/*
Enter Nodes and EDGE
5 8
A B
A D
B D
B C
B E
C E
D E
E D

==========GRAPH=============
A -> B D
B -> D C E
C -> E
D -> E
E -> D
=============================
0 1 0 1 0 
0 0 1 1 1
0 0 0 0 1
0 0 0 0 1
0 0 0 1 0
*/
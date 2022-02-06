/*
Page 315
8.1 Suppose a graph G is input by means of an integer M, representing the nodes 1, 2, …, 
M, and a list of N ordered pairs of the integers, representing the edges of G. Write a 
procedure for each of the following:

(a) To find the M × M adjacency matrix A of the graph G.

(b) To use the adjacency matrix A and Warshall’s algorithm to find the path matrix P of the graph G.

Test the above using the following data:

(i) M = 5; N = 8; (3, 4), (5, 3), (2, 4), (1, 5), (3, 2), (4, 2), (3, 1), (5, 1),

(ii) M = 6; N = 10; (1, 6), (2, 1), (2, 3), (3, 5), (4, 5), (4, 2), (2, 6), (5, 3), (4, 3), (6, 4)
*/
#include <iostream>
#include <iomanip>
using namespace std;
#define INF 99999
void SORTEST(int **A, int N)
{
    int P[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (A[i][j] == 0)
                P[i][j] = 0;
            else
                P[i][j] = 1;
        }
    }
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                P[i][j] = P[i][j] || (P[i][k] && P[k][j]);
            }
        }
    }
    cout << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << P[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    int M, N, NODE, EDGE, SRC, DEST;
    ;
    cout << "NUMBER OF NODE\n";
    cin >> NODE >> EDGE;
    N = M = NODE + 1;
    int **A = new int *[M];
    for (int i = 0; i < M; i++)
    {
        A[i] = new int[N];
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = 0;
        }
    }
    for (int j = 0; j < EDGE; j++)
    {
        cin >> SRC >> DEST;
        A[SRC][DEST] = 1;
    }
    cout << "\n*********************\n";
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "SOTEDT PATH\n";
    SORTEST(A, M);
    return 0;
}
/*
NUMBER OF NODE
5 8 
3 4 
5 3 
2 4 
1 5 
3 2 
4 2 
3 1 
5 1

*********************
0 0 0 0 0 0
0 0 0 0 0 1
0 0 0 0 1 0
0 1 1 0 1 0
0 0 1 0 0 0
0 1 0 1 0 0
SOTEDT PATH

0 0 0 0 0 0 
0 1 1 1 1 1
0 0 1 0 1 0
0 1 1 1 1 1
0 0 1 0 1 0
0 1 1 1 1 1
*/
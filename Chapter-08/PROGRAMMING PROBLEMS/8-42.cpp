/*
Page 315

8.2 Suppose a weighted graph G is input by means of an integer M,
representing the nodes 1, 2, …, M, and a list of N ordered triplets
(ai, bi, wi) of integers such that the pair (ai, bi) is an edge of
G and wi is its weight. Write a procedure for each of the following:

(a) To find the M × M weight matrix W of the graph G.

(b) To use the weight matrix W and Warshall’s Algorithm 8.2 to find
the matrix Q of shor- test paths between the nodes.

Test the above using the following data:

(i) M = 4; N = 7; (1, 2, 5), (2, 4, 2), (3, 2, 3), (1, 1, 7), (4, 1, 4),
(4, 3, 1). (Compare with Example 8.4.)

(ii) M = 5; N = 8; (3, 5, 3), (4, 1, 2), (5, 2, 2), (1, 5, 5), (1, 3, 1),
(2, 4, 1), (3, 4, 4), (5, 4, 4).
*/
#include <iostream>
#include <iomanip>
using namespace std;
#define INF 99999
int MIN(int A, int B)
{
    return (A > B) ? B : A;
}
void SORTEST(int **W, int N)
{
    int Q[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << W[i][j] << " ";
            if (W[i][j] == 0)
                Q[i][j] = INF;
            else
                Q[i][j] = W[i][j];
        }
        cout << "\n";
    }
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                Q[i][j] = MIN(Q[i][j], Q[i][k] + Q[k][j]);
            }
        }
    }
    cout << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Q[i][j] == INF)
                cout << "INF ";
            else
                cout << setw(3) << Q[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    int M, N, NODE, EDGE, SRC, DEST, WIGHT;
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
        cin >> SRC >> DEST >> WIGHT;
        A[SRC][DEST] = WIGHT;
    }
    cout << "\n*********************\n";
    cout << "SOTEDT PATH\n";
    SORTEST(A, M);
    return 0;
}
/*
NUMBER OF NODE
4 6
1 2 5
2 4 2
3 2 3
1 1 7
4 1 4
4 3 1

*********************
SOTEDT PATH
0 0 0 0 0
0 7 5 0 0
0 0 0 0 2
0 0 3 0 0
0 4 0 1 0

INF INF INF INF INF
INF   7   5   8   7
INF   6   6   3   2
INF   9   3   6   5
INF   4   4   1   6 
*/
/*
Algorithm 8.2 : (Shortest-Path Algorithm) A weighted graph G with M 
nodes is maintained in memory by its weight matrix W. This algorithm 
finds a matrix Q such that Q[I, J] is the length of a shortest path 
from node VI to node VJ. INFINITY is a very large number, and MIN is 
the minimum value function.

1. Repeat for I, J = 1, 2, …, M: [Initializes Q.]

W[I, J] = 0, then: Set Q[I, J] := INFINITY;

Else: Set Q[I, J]:= W[I, J].

[End of loop.]

2. Repeat Steps 3 and N for K = 1, 2, …, M: [Updates Q.]

3.     Repeat Step N for I = 1, 2, …, M:

N.          Repeat for J = 1, 2, …, M:

Set Q[I, J]:= MIN(Q[I, J], Q[I, K] + Q[K, J]).

[End of loop.]

[End of Step 3 loop.]

[End of Step 2 loop.]

5. Exit.
*/
#include<iostream>
#include<iomanip>
#include<limits>
using namespace std;
#define INF 99999
int MIN(int A, int B)
{
    return (A>B) ? B : A;
}
void SORTEST(int W[][4], int N)
{
    int Q[N][N];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << W[i][j] << " ";
            if(W[i][j] == 0)
            Q[i][j] = INF;
            else 
            Q[i][j] = W[i][j];
        }
        cout << "\n";
    }
    for(int k = 0; k < N; k++)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                Q[i][j] = MIN(Q[i][j], Q[i][k] + Q[k][j]);
            }
        }
    }
    cout << "\n";
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << Q[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    int W[4][4] = { {7,5,0,0},
                    {7,0,0,2},
                    {0,3,0,0},
                    {4,0,1,0}};
    SORTEST(W, 4);
   
}
/*
7 5 0 0 
7 0 0 2 
0 3 0 0 
4 0 1 0 
        
7 5 8 7 
6 6 3 2 
9 3 6 5
4 4 1 6
*/

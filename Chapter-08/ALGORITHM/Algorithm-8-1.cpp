/*
Algorithm 8.1 : (Warshall’s Algorithm) A directed graph G with M 
nodes is maintained in memory by its adjacency matrix A. This 
algorithm finds the (Boolean) path matrix P of the graph G.


1. Repeat for I, J = 1, 2,…, M: [Initializes P.]

If A[I, J] = 0, then: Set P[I, J] := 0;

Else: Set P[I, J] := 1.

[End of loop.]

2. Repeat Steps 3 and 4 for K = 1, 2, …, M: [Updates P.]

3.     Repeat Step 4 for I = 1, 2, …, M:

4.          Repeat for J = 1, 2, …, M:

Set P[I, J] : = P[I, J]  (P[I, K]  P[K, J]).

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
void SORTEST(int A[][4], int N)
{
    int P[N][N];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(A[i][j] == 0)
            P[i][j] = 0;
            else 
            P[i][j] = 1;
        }
    }
    for(int k = 0; k < N; k++)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                P[i][j] = P[i][j] ||  (P[i][k] && P[k][j]);
            }
        }
    }
    cout << "\n";
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << P[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    int A[4][4] = { {7,5,0,0},
                    {7,0,0,2},
                    {0,3,0,0},
                    {4,0,1,0}};
    SORTEST(A, 4);
   
}

/*
output

1 1 1 1 
1 1 1 1 
1 1 1 1 
1 1 1 1
*/
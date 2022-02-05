#include <iostream>
#include <iomanip>
using namespace std;
#define INF 99999
void SORTEST(int **A, int N)
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


int MIN(int A, int B)
{
    return (A>B) ? B : A;
}
void SORTEST_W(int **W, int N)
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
    int M, N;
    cout << "Matrix col number\n";
    cin >> M;
    N = M;
    int **A = new int *[M];
    for (int i = 0; i < M; i++)
    {
        A[i] = new int[N];
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }
    cout << "\n*********************\n";
    SORTEST(A, M);
    return 0;
}
/*
Matrix col number
4
0 1 1 1
0 0 0 1
0 1 0 1
0 0 1 0

*********************

0 1 1 1
0 1 1 1
0 1 1 1
0 1 1 1
*/
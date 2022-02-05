#include<iostream>
#include<iomanip>
#include<limits>
using namespace std;
#define INF 99999
int MIN(int A, int B)
{
    return (A>B) ? B : A;
}
void SORTEST(int **W, int N)
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
            cout<< setw(3) << Q[i][j] << " ";
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
5 
0 6 0 4 1
6 0 5 0 8
0 5 0 0 2
4 0 0 0 3
1 8 2 3 0

*********************
0 6 0 4 1
6 0 5 0 8
0 5 0 0 2
4 0 0 0 3
1 8 2 3 0

  2   6   3   4   1
  6  10   5  10   7 
  3   5   4   5   2
  4  10   5   6   3
  1   7   2   3   2 
*/
/*
8.7 Consider the weighted graph G in Fig. 8.38. 
Suppose the nodes are stored in an array DATA as follows:

DATA: X, Y, S, T



Fig. 8.38

(a) Find the weight matrix W of G.
 (b) Find the matrix Q of shortest paths using Warshall’s Algorithm 8.2.
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
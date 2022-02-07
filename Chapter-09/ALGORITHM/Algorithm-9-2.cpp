/*
page 325
Procedure 9.2: MIN(A, K, N, LOC)

An array A is in memory. This procedure finds the location LOC of the 
smallest element among A[K], A[K + 1], …, A[N].

1.    Set MIN := A[K] and LOC := K. [Initializes pointers.]

2.    Repeat for J = K + 1, K + 2, …, N:

If MIN > A[J], then: Set MIN := A[J] and LOC := A[J] and LOC := J.

[End of loop.]

3.    Return.
*/
#include <iostream>
using namespace std;
void MIN(int A[], int K, int N, int &LOC)
{
    int min = A[K];
    LOC = K;
    for (int i = K + 1; i < N; i++)
    {
        if (min > A[i])
        {
            min = A[i];
            LOC = i;
        }
    }
}
void selection(int A[], int N)
{
    int LOC = 0;
    int temp;
    for (int i = 0; i < N - 1; i++)
    {
        MIN(A, i, N, LOC);
        temp = A[i];
        A[i] = A[LOC];
        A[LOC] = temp;
    }
}
int main()
{
    int A[] = {2, 7, 4, 1, 5, 3};
    selection(A, 6);
    for (int i : A)
    {
        cout << i << " ";
    }
}
/*
1 2 3 4 5 7
*/

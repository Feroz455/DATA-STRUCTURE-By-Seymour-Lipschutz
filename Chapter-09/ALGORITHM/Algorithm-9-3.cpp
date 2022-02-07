/*
page 325
Algorithm 9.3: (Selection Sort) SELECTION(A, N)

This algorithm sorts the array A with N elements.

1.    Repeat Steps 2 and 3 for K = 1, 2, …, N – 1:

2.           Call MIN(A, K, N, LOC).

3.           [Interchange A[K] and A[LOC].]

Set TEMP := A[K], A[K] := A[LOC] and A[LOC] := TEMP.

[End of Step 1 loop.]

4.    Exit.
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

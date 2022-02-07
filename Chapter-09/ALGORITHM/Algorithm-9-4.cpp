/*
page 327
Algorithm 9.4:   MERGING(A, R, B, S, C)

Let A and B be sorted arrays with R and S elements, respectively.
This algorithm merges A and B into an array C with N = R + S elements.
1.    [Initialize.] Set NA := 1, NB := 1 and PTR := 1.
2.    [Compare.] Repeat while NA ≤ R and NB ≤ S:
If A[NA] < B[NB], then:
(a)   [Assign element from A to C.] Set C[PTR] := A[NA].
(b)   [Update pointers.] Set PTR := PTR + 1 and NA := NA + 1.
Else:
(a)   [Assign element from B to C.] Set C[PTR] := B[NB].
(b)   [Update pointers.] Set PTR := PTR + 1 and NB := NB + 1.
[End of If structure.]
      [End of loop.]
3.    [Assign remaining elements to C.]
      If NA > R, then:
Repeat for K = 0, 1, 2, …, S – NB:
                 Set C[PTR + K] := B[NB + K].
[End of loop.]
Else:
Repeat for K = 0, 1, 2, …, R – NA:
                 Set C[PTR + K] := A[NA + K].
[End of loop.]
[End of If structure.]
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
void mergeArrays(int A[], int R, int B[], int S, int C[])
{
    int NA = 0, NB = 0, PTR = 0;
    while (NA < R && NB < S)
    {
        if (A[NA] < B[NB])
            C[PTR++] = A[NA++];
        else
            C[PTR++] = B[NB++];
    }
    while (NA < R)
        C[PTR++] = A[NA++];
    while (NB < S)
        C[PTR++] = B[NB++];
}
int main()
{
    int R = 6, S = 7, C[R + S];
    int A[R] = {45, 12, 34, 66, 99, 88};
    int B[S] = {65, 25, 35, 15, 75, 55, 45};
    selection(B, S);
    selection(A, R);
    mergeArrays(A, R, B, S, C);
    cout << "\n";
    for (int x : A)
    {
        cout << x << " ";
    }
    cout << "\n";
    for (int x : B)
    {
        cout << x << " ";
    }
    cout << "\n";
    for (int x : C)
    {
        cout << x << " ";
    }
}
/*
12 15 23 25 35 45 45 65 66 75 87 95
*/
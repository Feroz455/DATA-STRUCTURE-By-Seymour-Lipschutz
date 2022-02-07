/*
page 327
Procedure 9.5: MERGE(A, R, LBA, S, LBB, C, LBC)

This procedure merges the sorted arrays A and B into the array C.

1.    Set NA := LBA, NB := LBB, PTR := LBC, UBA := LBA + R – 1, UBB := LBB + S – 1.

2.    Same as Algorithm 9.4 except R is replaced by UBA and S by UBB.

3.    Same as Algorithm 9.4 except R is replaced by UBA and S by UBB.

4.    Return.
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
void MARCHING(int A[], int R, int LBA, int B[], int S, int LBB, int C[], int LBC)
{

    int NA = LBA, NB = LBB, PTR = LBC;
    int UBA = LBA + R - 1, UBB = LBB + S - 1;
    while (NA <= UBA && NB <= UBB)
    {
        if (A[NA] < B[NB])
            C[PTR++] = A[NA++];
        else
            C[PTR++] = B[NB++];
    }
    while (NA <= UBA)
        C[PTR++] = A[NA++];
    while (NB <= UBB)
        C[PTR++] = B[NB++];
}
int main()
{
    int R = 6, S = 7, C[R + S];
    int A[R] = {45, 12, 34, 66, 99, 88};
    int B[S] = {65, 25, 35, 15, 75, 55, 45};
    selection(B, S);
    selection(A, R);
    MARCHING(A, R, 0, B, S, 0, C, 0);
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
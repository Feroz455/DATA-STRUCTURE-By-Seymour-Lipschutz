/*
page 338
9.7   Translate Procedure 9.2 into a subprogram MIN(A, LB, UB, LOC)
which finds the location LOC of the smallest elements among A[LB], A[LB + 1], …, A[UB].
*/
#include <iostream>
using namespace std;
template <typename T>
int MIN(T A[],int LB, int UB, int N)
{
    T temp;
    int hole;
    for (int i = LB; i < UB-1; i++)
    {
        temp = A[i];
        hole = i;
        while (hole > 0 && A[hole - 1] > temp)
        {
            A[hole] = A[hole - 1];
            hole = hole - 1;
        }
        A[hole] = temp;
    }
    return A[LB];
}
int main()
{
    int A[] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
   cout <<  MIN(A, 0, 12, 13) << " ";
}
/*
11
*/
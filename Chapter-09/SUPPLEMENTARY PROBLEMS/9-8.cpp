/*
page 338
9.8   Translate selection sort into a subprogram SELECTSORT(A, N) 
which sorts the array with N elements. Test the program using:

(a)  44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66

(b)  D, A, T, A, S, T, R, U, C, T, U, R, E, S
*/
#include <iostream>
using namespace std;
template<typename T>
void MIN(T A[], int K, int N, int &LOC)
{
    T min = A[K];
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
template<typename T>
void selection(T A[], int N)
{
    int LOC = 0;
    T temp;
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
        int A[] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
    selection<int>(A, 12);
    for (int i : A)
    {
        cout << i << " ";
    }
    cout << "\n";
    char B[] = {'D', 'A', 'T', 'A', 'S', 'T', 'R', 'U', 'C', 'T', 'U', 'R', 'E', 'S'};
    selection<char>(B, 14);
    for (char i : B)
    {
        cout << i << " ";
    }
}
/*
11 22 33 40 44 55 60 66 77 88 90 99 
A A C D E R R S S T T T U U
*/
/*
page 338
9.2   Translate insertion sort into a subprogram INSERTSORT(A, N) 
which sorts the array A with N elements. Test the program using:
(a)  44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66
(b)  D, A, T, A, S, T, R, U, C, T, U, R, E, S
*/
#include <iostream>
using namespace std;
template <typename T>
void insertion_sort(T A[], int N)
{
    T temp;
    int hole;
    for (int i = 1; i < N - 1; i++)
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
}
int main()
{
    int A[] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
    insertion_sort<int>(A, 13);
    for (int i : A)
    {
        cout << i << " ";
    }
    cout << "\n";
    char B[] = {'D', 'A', 'T', 'A', 'S', 'T', 'R', 'U', 'C', 'T', 'U', 'R', 'E', 'S'};
    insertion_sort<char>(B, 15);
    for (char i : B)
    {
        cout << i << " ";
    }
}
/*
11 22 33 40 44 55 60 66 77 88 90 99 
A A C D E R R S S T T T U U
*/
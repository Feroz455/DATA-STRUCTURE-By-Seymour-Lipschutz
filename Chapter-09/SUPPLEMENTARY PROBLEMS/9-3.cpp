/*
page 338
9.3   Translate insertion sort into a subprogram INSERTCOUNT(A, N, NUMB) 
which sorts the array A with N elements and which also counts the number NUMB of comparisons.
*/
#include <iostream>
using namespace std;
template <typename T>
int insertion_sort(T A[], int N)
{
    int count = 0;
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
            count++;
        }
        A[hole] = temp;
    }
    return count;
}
int main()
{
    int A[] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
   cout << "Number of Comparisons = "<< insertion_sort<int>(A, 13)<<"\n";
    for (int i : A)
    {
        cout << i << " ";
    }
    cout << "\n";
    char B[] = {'D', 'A', 'T', 'A', 'S', 'T', 'R', 'U', 'C', 'T', 'U', 'R', 'E', 'S'};
    cout << "Number of Comparisons = "<< insertion_sort<char>(B, 15) << endl;
    for (char i : B)
    {
        cout << i << " ";
    }
}
/*
Number of Comparisons = 23
11 22 33 40 44 55 60 66 77 88 90 99
Number of Comparisons = 33
A A C D E R R S S T T T U U
*/
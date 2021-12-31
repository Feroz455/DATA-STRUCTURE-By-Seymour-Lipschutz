/*
Page 109
Program
4-23
An array A contains 25 positive integers. Write a module which

(a) Finds all pairs of elements whose sum is 25.

(b) Finds the number EVNUM of elements of A which are even, 
    and the number ODNUM of elements of A which are odd.
*/
#include<iostream>
#include<string>
#include<time.h>
#include<iomanip>
using namespace std;
//Main from Here
int main()
{
    srand(time(0));
    int A[25];
    for(int i = 0; i < 25; i++)
    {
        A[i] = rand() % 15 + 1;
    }
    for(int i = 0; i < 25; i++)
    {
        cout << setw(5) << A[i] ;
    }
    cout << "\n";

    for(int i = 0;  i < 25; i++)
    {
        for(int j = 0; j < 25; j++)
        {
            if((A[i]+A[j]) >= 25)
            cout << setw(5) << "A[" << setw(2)<<  i << "] + A[" << setw(2) << j << "]  = " << setw(5)  <<  (A[i]+A[j]) << endl; 
        }
    }
    cout << "\nEVEN NUMBER\n";

    for(int i = 0;  i < 25; i++)
    {
        if(A[i]%2 == 0)
        {
            cout << "A[" << setw(2) <<  i << "]  = " << setw(5)  << A[i] << endl;
        }
    }
    cout << "\nODD NUMBER\n";
     for(int i = 0;  i < 25; i++)
    {
        if(A[i]%2 != 0)
        {
            cout << "A[" << setw(2) <<  i << "]  = " << setw(5)  << A[i] << endl;
        }
    }




}

/*
Output
    3   14    5   11    5   12    1   12   15    1   15    7    9   13    5    2    2    1    2   11   13    6    2    8    6
   A[ 1] + A[ 1]  =    28
   A[ 1] + A[ 3]  =    25
   A[ 1] + A[ 5]  =    26
   A[ 1] + A[ 7]  =    26
   A[ 1] + A[ 8]  =    29
   A[ 1] + A[10]  =    29
   A[ 1] + A[13]  =    27
   A[ 1] + A[19]  =    25
   A[ 1] + A[20]  =    27
   A[ 3] + A[ 1]  =    25
   A[ 3] + A[ 8]  =    26
   A[ 3] + A[10]  =    26
   A[ 5] + A[ 1]  =    26
   A[ 5] + A[ 8]  =    27
   A[ 5] + A[10]  =    27
   A[ 5] + A[13]  =    25
   A[ 5] + A[20]  =    25
   A[ 7] + A[ 1]  =    26
   A[ 7] + A[ 8]  =    27
   A[ 7] + A[10]  =    27
   A[ 7] + A[13]  =    25
   A[ 7] + A[20]  =    25
   A[ 8] + A[ 1]  =    29
   A[ 8] + A[ 3]  =    26
   A[ 8] + A[ 5]  =    27
   A[ 8] + A[ 7]  =    27
   A[ 8] + A[ 8]  =    30
   A[ 8] + A[10]  =    30
   A[ 8] + A[13]  =    28
   A[ 8] + A[19]  =    26
   A[ 8] + A[20]  =    28
   A[10] + A[ 1]  =    29
   A[10] + A[ 3]  =    26
   A[10] + A[ 5]  =    27
   A[10] + A[ 7]  =    27
   A[10] + A[ 8]  =    30
   A[10] + A[10]  =    30
   A[10] + A[13]  =    28
   A[10] + A[19]  =    26
   A[10] + A[20]  =    28
   A[13] + A[ 1]  =    27
   A[13] + A[ 5]  =    25
   A[13] + A[ 7]  =    25
   A[13] + A[ 8]  =    28
   A[13] + A[10]  =    28
   A[13] + A[13]  =    26
   A[13] + A[20]  =    26
   A[19] + A[ 1]  =    25
   A[19] + A[ 8]  =    26
   A[19] + A[10]  =    26
   A[20] + A[ 1]  =    27
   A[20] + A[ 5]  =    25
   A[20] + A[ 7]  =    25
   A[20] + A[ 8]  =    28
   A[20] + A[10]  =    28
   A[20] + A[13]  =    26
   A[20] + A[20]  =    26

EVEN NUMBER
A[ 1]  =    14
A[ 5]  =    12
A[ 7]  =    12
A[15]  =     2
A[16]  =     2
A[18]  =     2
A[21]  =     6
A[22]  =     2
A[23]  =     8
A[24]  =     6

ODD NUMBER
A[ 0]  =     3
A[ 2]  =     5
A[ 3]  =    11
A[ 4]  =     5
A[ 6]  =     1
A[ 8]  =    15
A[ 9]  =     1
A[10]  =    15
A[11]  =     7
A[12]  =     9
A[13]  =    13
A[14]  =     5
A[17]  =     1
A[19]  =    11
A[20]  =    13
*/
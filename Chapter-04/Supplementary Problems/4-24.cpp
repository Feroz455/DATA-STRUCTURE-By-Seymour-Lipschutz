/*
Page 109

Program
4.4 Suppose A is a linear array with n numeric values. Write a procedure

MEAN(A, N, AVE)

which finds the average AVE of the values in A. 
The arithmetic mean or average  of the values x1, x2, …, xn is defined by
 AVE = (x1+x2+x3....+xn)/n
*/
#include<iostream>
#include<string>
#include<time.h>
#include<iomanip>
using namespace std;
int MEAN(int A[], int N, int AVE)
{
    
    for(int i = 0; i < N; i++)
    {
        AVE += A[i];
    }
    return (AVE / N);
}
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
    cout << "Average of all Array A is = " << MEAN(A, 25, 0) << endl;

}

/*
Output
   10    2   10    4
    1   10   15    4    
    2    3    7    4   
    14   11   15    9   
    10    6    7    5   
     9    7    8    3    1
Average of all Array A is = 7
*/
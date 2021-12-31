/*
Page
Program 
4.16 Consider the polynomial

f (x) = a1xn + a2xn−1 + … + anx + an+1

Evaluating the polynomial in the obvious way would require

multiplications and n additions. However, one can rewrite the 
polynomial by successively factoring out x as follows:

f (x) = ((… ((a1x + a2)x + a3)x + …)x + an)x + an+l

This uses only n multiplications and n additions. This second 
way of evaluating a polynomial is called Horner’s method.

(a) Rewrite the polynomial f (x) = 5x4 − 6x3 + 7x2 + 8x − 9 as 
it would be evaluated using Horner’s method.

(b) Suppose the coefficients of a polynomial are in memory in a 
linear array A(N + 1). (That is, A[1] is the coefficient of xn, 
A[2] is the coefficient of xn–1, …, and A[N + 1] is the constant.) 
Write a procedure HORNER(A, N + 1, X, Y) which finds the value 
Y = F(X) for a given value X using Horner’s method.

Test the program using X = 2 and f (x) from part (a).
*/
#include<iostream>
#include<string>
#include<math.h>
using namespace std;
void HORNER(int A[], int N, int X, int &Y)
{
    
     for(int i = 0; i < N; i++)
    {
        if(i == N-1 )
        {
            Y = Y + A[i];
        }
        else
        {
            Y = (Y+A[i])*X;
        }
    }
   
}
//Main from Here
int main()
{
    int sum = 0, X = 2, Y;
    int A[5] = {5,-6,7,8,-9};
     HORNER(A, 5, X, Y);
    cout << "Horner's method = " << Y << " \n";

}

/*
Output
Horner's method = 67 
*/
/*
6.14 Let A and B be nonnegative integers. Suppose a 
function GCD is recursively defined as follows:

            GCD(B,A)        if(A < B)
GCD(A,B) =  A               if B = 0
            GCD(B, MOD(A,B)) otherwise

(Here MOD(A, B), read “A modulo B,” denotes the 
remainder when A is divided by B.) (a) Find GCD(6, 15), 
GCD(20, 28) and GCD(540, 168). (b) What does this function do?

*/
#include<iostream>
#include<cmath>
using namespace std;
int GCD(int A, int B)
{
    if(A<B)
    {
        return GCD(B,A);
    }
    if(B == 0)
    {
        return A;
    }
    else
    GCD(B, (A%B));
}
int main()
{
    cout << GCD(6, 15) << endl;
    cout << GCD(20, 28) << endl;
    cout << GCD(540, 168) << endl;

}
/*
3
4 
12
*/
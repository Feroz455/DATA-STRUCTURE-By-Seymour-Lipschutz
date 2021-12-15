/*
Page 40
Program 2.24
Write a program using DIV(J, K) which reads a positive integer N > 10 
and determines whether or not N is a prime number. (Hint: N is prime 
if (i) DlV(2, N) = 0 (i.e., N is odd) and (ii) DIV(K, N) = 0 for all 
odd integers K where 1 < K2 ≤ N.)
*/
#include<iostream>
using namespace std;

// Take Divisor and  Dividend
//if reminder is 0 then retrun true
//else retrun 1
template<typename T>
T DIV(T J, T K)
{
    if(K % J== 0)
    return 1;
    else
    return 0;
}
//This function get a input to check its prime or not 

int Prime(int N)
{
    if(DIV<int>(2,N) == 0)
    {
       for(int K  = 3 ; K  < N ; K += 2)
            {
                if(DIV<int>(K,N) == 1)
                 {
                     return 1;
                 }   
            }
            return 0;
    }
    else 
    return 1;
}
int main()
{
    int N;
    cout << "Enter a positive integer greater then 10\n";
    cin >> N ;
    if(Prime(N) == 0)
    cout << N << " is Prime\n";
    else 
    cout << N << " is not Prime\n";

    
    getchar();
    return 0;
}

/*
Output
Enter a positive integer greater then 10
111
111 is not Prime 
*/
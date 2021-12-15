/*
page 
37
Program 
2.9 An integer n > 1 is called a prime number if its only positive divisors are 1 
and n; otherwise, n is called a composite number. For example, the following are 
the prime numbers less than 20:

2, 3, 5, 7, 11, 13, 17, 19

If n > 1 is not prime, i.e., if n is composite, then n must have a divisor k ≠ 1 
such that k ≤  or, in other words, k2 ≤ n.

Suppose we want to find all the prime numbers less than a given number m, such as 
30. This can be done by the “sieve method,” which consists of the following steps. 
First list the 30 numbers:

1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15

16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30

Cross out 1 and the multiples of 2 from the list as follows:



Since 3 is the first number following 2 that has not been eliminated, cross out the 
multiples of 3 from the list as follows:



Since 5 is the first number following 3 that has not been eliminated, cross out the 
multiples of 5 from the list as follows:



Now 7 is the first number following 5 that has not been eliminated, but 72 > 30. This 
means the algorithm is finished and the numbers left in the list are the primes less than 30:

2, 3, 5, 7, 11, 13, 17, 19, 23, 29

Translate the sieve method into an algorithm to find all prime numbers less than a given 
number n.
*/
#include<iostream>
#include<cmath>
using namespace std;
template<typename T>
void CORSSOUT(T A[], int N, int K)
{
   // cout << K << " " << N << endl;
        if(A[K] == 1)
        { 
            //cout << "Hello \n";
        return;
        }
        for(int l = 2*K ; l < N; l = l + K)
        {
           // cout << "Hello\n";
            A[l] = 1;
            //cout << "A[" << l << "]" << endl;
        }
        return ;

}

//main begin
int main()
{
    int N = 20 , K;
    int A[N];
    for(int i = 0; i < N ; i++)
    {
         A[i] = i;
    }
    for( K = 2; K <= ceil(sqrt(N)); K++)
    {
        CORSSOUT<int>(A,N,K);
    }
    for(K = 2; K < N ; K++)
    {
        if(A[K] != 1)
         cout << A[K] << endl;
    }

    getchar();
    return 0;
}
//main end
///Program end

/*
output
*/
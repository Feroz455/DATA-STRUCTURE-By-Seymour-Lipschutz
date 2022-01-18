/*
Page 181
Procedure 6.10: FIBONACCI(FIB, N)

This procedure calculates FN and returns the value in the first parameter FIB.

1. If N = 0 or N = 1, then: Set FIB := N, and Return.

2. Call FIBONACCI(FIBA, N – 2).

3. Call FIBONACCI(FIBB, N – 1).

4. Set FIB := FIBA + FIBB.

5. Return.
*/
#include<iostream>
using namespace std;
int FIBONACCHI(int N)
{
    if(N <= 1)
    {
        return N;
    }
    return FIBONACCHI(N-1)+FIBONACCHI(N-2);
}
int main()
{
    int N;
    cout << "Enter a number\n";
    cin >> N;
    cout<< N  << "'s fibonacchi is =  " << FIBONACCHI(N);
    return 0;
}
/*
Enter a number
30
30's fibonacchi is =  832040
*/
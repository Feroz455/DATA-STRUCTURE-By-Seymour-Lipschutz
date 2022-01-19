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
void  FIB(int F[], int N)
{
    F[0] = 1;
    cout << F[0] << ' ';
    F[1] = 1;
    cout << F[1] << ' ';
    for(int L = 2; L < N; L++)
    {
        F[L] = F[L-1] + F[L-2];
        cout << F[L] << ' ';
    }
}
int main()
{
    int N, F[N];
    cout << "Enter a number\n";
    cin >> N;
    cout<< N  << "'s fibonacchi is =  " << FIBONACCHI(N) << "\n";
    FIB(F, N);
    return 0;
}
/*
Enter a number
12
12's fibonacchi is =  144

Enter a number
13
13's fibonacchi is =  233

Enter a number
14
14's fibonacchi is =  377

Enter a number
15
15's fibonacchi is =  610



Enter a number
16
16's fibonacchi is =  987
1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 
*/
/*
Procedure 6.9B: FACTORIAL(FACT, N)

This procedure calculates N! and returns the value in the variable FACT.

1. If N = 0, then: Set FACT := 1, and Return.

2. Call FACTORIAL(FACT, N – 1).

3. Set FACT := N*FACT.

4. Return.
*/
#include<iostream>
#include<iomanip>
using namespace std;
int FACTORIAL(int n)
{
    if (n <= 1)
        return n;
    return (n * FACTORIAL(n-1));
}
 
int main ()
{
    int n;
    cout << "Enter an integer number \n";
    cin >> n;
    cout<< n <<"'s FACTORIAL is = " << FACTORIAL(n);
    getchar();
    return 0;
}
 /*
Enter an integer number
12
12's FACTORIAL is = 479001600
 */
/*
Program 
The solutions of the quadratic equation
ax^2 + bx + c = 0
where a ≠ 0, are given by the quadratic formula
The quantity D = b2 – 4ac is called the discriminant
of the equation. If D is negative, then there are no
real solutions. If D = 0, then there is only one 
(double) real solution, x = – b/2a. If D is positive,
the formula gives the two distinct real solutions. The
following algorithm finds the solutions of a quadratic
equation.
*/
//Algorithm 
/*
Algorithm 2.2: (Quadratic Equation) This algorithm inputs
the coefficients A, B, C of a quadratic equation and outputs
the real solutions, if any.

Step 1. Read: A, B, C.
Step 2. Set D: = B2 – 4AC.
Step 3. If D > 0, then:
(a) Set X1 := (–B + )/2A and
 X2 := (–B – )/2A.
(b) Write: X1, X2.
Else if D = 0, then:
(a) Set X := –B/2A.
(b) Write: ‘UNIQUE SOLUTION’, X.
Else:
Write: ‘NO REAL SOLUTIONS’
[End of If structure.]
Step 4. Exit.
*/
#include<iostream>
#include<cmath>
using namespace std;

//main begin
int main()
{
    int A, B, C, X1, X2, X;
    cout << "TO CALCULATE QUADRATIC EQUATION " << endl;
    cout << "Enter Value of A, B and C " << endl;
    cout << "A = "; cin >> A;
    cout << "B = "; cin >> B;
    cout << "C = "; cin >> C;
    int D = (B*B) - (4 * A * C);
    if (D > 0)
    {
        X1 = ((-B) + sqrt(D)) / (2*A);
        X2 = ((-B) -(sqrt(D))) / (2*A);
        cout << "X1 = " << X1 << endl;
        cout << "X2 = " << X2 << endl;
    }
    else if(D = 0)
    {
        X = (-B) / (2 * A);
        cout << "UNIQUE SOLUTION, X"; 
    }
    else
    cout << "NO REAL SOLUTIONS" << endl;
    getchar();
    return 0;
}
//main end
///Program end

/*
output
Enter Value of A, B and C       
A = 10 
B = 10 
C = 10
NO REAL SOLUTIONS
*/
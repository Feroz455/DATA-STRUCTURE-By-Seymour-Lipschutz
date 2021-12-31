/*
Page 112
Program 
4.14 Suppose A and B are n-element vector arrays in memory and X and Y are scalars. Write a program to find 
(a)  XA + YB and 
(b) A · B
Test the program using A = (16, −6, 7), B = (4, 2, −3), X = 2 and Y= −5.
*/
#include<iostream>
#include<iomanip>
using namespace std;

//Main from Here
int main()
{
    int AR = 2 , AC = 2 , BR = 2 , BC = 3, X, Y;
    cout << "Enter A's row number\n";
    cin >> AR;
    cout << "Enter A's column number\n";
    cin >> AC;
    cout << "Enter B's row number\n";
    cin >> BR;
    cout << "Enter B's column number\n";
    cin >> BC;
     cout << "Enter Value of X " << endl;
    cin >> X;
    cout << "Enter Value of X " << endl;
    cin >> Y;

    

    int A[AR][AC];
    int B[BR][BC];
    int C[AR][BC];
    if(AC != BR)
    {
        cout << "MATRIX MULTIPLICATION NOT POSSIBLE";
    }
    else
    {
        cout << "Enter Value of A MATRIX " << AR << " x " << AC << endl;
        for(int i = 0; i < AR; i++)
        {
            for(int j = 0; j < AC; j++)
            {
                 cin >>  A[i][j];
                 A[i][j] =   A[i][j] * X;
            }
           
        }

        cout << "Enter Value of A MATRIX " << BR << " x " << BC << endl;
        for(int i = 0; i < BR; i++)
        {
            for(int j = 0; j < BC; j++)
            {
                
            }
            cin >>  B[i][j];
        }

        for(int i = 0; i < AR; i++) 
        {
            for(int j = 0;  j < BC; j++)
            {
                C[i][j] = 0;
                for(int k = 0; k < BR; k++)
                {
                    C[i][j] +=  A[i][k] * B[k][j];
                }
            }
        }
        cout << "\n\n\n";
        for(int i = 0; i < AR; i++)
        {
            for(int j = 0; j < BC; j++)
            cout << setw(5) << C[i][j] << " ";
            cout << endl;
        }

    }
 
}

/*
Output

*/
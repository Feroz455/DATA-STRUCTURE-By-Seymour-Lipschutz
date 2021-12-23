/*
Page  54
Algorithm 3.3: (Pattern Matching) P and T are strings with lengths R and S, 
respectively, and are stored as arrays with one character per element. This 
algorithm finds the INDEX of P in T.

1. [Initialize.] Set K := 1 and MAX : = S − R + 1.
2.  Repeat Steps 3 to 5 while K ≤ MAX:
3.    Repeat for L = 1 to R: [Tests each character of P.]
            If P[L] ≠ T[K + L − 1], then: Go to Step 5.
        [End of inner loop.]
4.    [Success.] Set INDEX = K, and Exit.
5.    Set K := K + 1.
[End of Step 2 outer loop.]
6. [Failure.] Set INDEX = 0.
7. Exit.
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string T, P;
    size_t K, MAX, S, R, INDEX = 0;
    

    cout << "Enter your Text\n";
    getline(cin,T);
    cout << "Enter your keyword\n";
    cin >> P;
    S = T.length(); //length of Main string
    R = P.length(); // Length of sub string
    K = 0; 
    MAX = S - R + 1;
    while(K <= MAX)
    {
        for(int L = 0; L < R; L++)
        {
            if(P[L] != T[K + L -1])
                goto Lable;
        }
        INDEX = K;
        break;
    Lable:
        K++;
         
    }
    cout << "Index = " << INDEX << endl;
    return 0;
}
/*
output
Enter your Text
stored as arrays with one character per element
Enter your keyword
ent
Index = 45
*/
/*
Page 53
program 
Algorithm 3.2: A text T and patterns P and Q are in memory. This algorithm replaces every occurrence of P in T by Q.

1. [Find index of P.] Set K := INDEX(T, P).

2. Repeat while K ≠ 0:

(a) [Replace P by Q.] Set T := REPLACE(T, P, Q).

(b) [Update index.] Set K := INDEX(T, P).

[End of loop.]

3. Write: T.

4. Exit.

*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string T, P, Q;
    size_t K;
    cout << "Enter your Text\n";
    getline(cin,T);
    cout << "Enter your keyword to replace\n";
    cin >> P;
    cout << "Enter replace keyword\n";
    cin >> Q;
    cout << T << endl;
    cout << P <<  endl;
    cout << Q << endl;
    K = T.find(P);
    while(K != string::npos)
    {
        T.replace(K,P.length(),Q);
        K = T.find(P);
    }
    cout << T << endl;
    cout << P <<  endl;
    cout << Q << endl;
    return 0;
    
}
/*
output
Enter your Text
XABYABZAB
Enter your keyword to replace
AB
Enter replace keyword
PQR
XABYABZAB
AB
PQR
XPQRYPQRZPQR
AB
PQR
*/

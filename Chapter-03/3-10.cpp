#include<iostream>
#include<string>
using namespace std;
int INDEX(string &T, string P)
{
     size_t K, MAX, S, R, INDEX = 0;
    
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
    return INDEX;

}
int main()
{
    string  S("JOHN PAUL JONES"), T("A THING OF BEAUTY IS A JOY FOREVER");
    cout << INDEX(S,"JO") << endl;
    cout << INDEX(S, "JOY") << endl;
    cout << INDEX(S, " JO") << endl;
    cout << INDEX(T, "A") << endl;
    cout << INDEX(T, " A ") << endl;
    cout << INDEX(T, "THE") << endl;

    return 0;
}
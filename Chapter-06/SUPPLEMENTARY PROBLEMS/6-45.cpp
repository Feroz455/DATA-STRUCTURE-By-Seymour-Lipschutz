/*
page  212
6.20 Suppose S is a string with N characters. Let SUB(S, J, L) 
denote the substring of S beginning in the position J and having 
length L. Let A//B denote the concatenation of strings A and B. 
Suppose REV(S, N) is recursively defined by



(a) Find REV(S, N) when 
(i) N = 3, S = abc and (ii) N = 5, S = ababc. 
(b) What does this function do?
*/
#include<iostream>
#include<string>
using namespace std;
string REV(string S, int N)
{
    if(N == 1)
    {
        return S;
    }
    return (S.substr(N,1)+REV(S.substr(1,N-1),N-1));
}
int main()
{
    string S = "ABC";

    cout << REV(S,2) << endl;
    S = "ababc";
    cout << REV(S,3) << endl;
}
/*
CB
ba
*/
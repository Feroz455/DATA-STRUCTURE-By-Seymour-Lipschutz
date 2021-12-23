/*
Program

*/
#include<iostream>
#include<string>
using namespace std;
//main begin
int main()
{
    string T, P;

    cout << "Enter your Text\n";
    getline(cin,T);
    cout << "Enter your keyword\n";
    cin >> P;
    size_t K = T.find(P);
    while(K != string::npos)
    {
        T.erase(K, P.length());
        K = T.find(P);
    }
    cout << T << endl;
    return 0;
}
//main end
///Program end

/*
output
Enter your Text
ZAAABBBY
Enter your keyword
AB
ZY
*/

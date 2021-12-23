/*
page 60
program 3.9

*/
#include<iostream>
#include<cstring>
using namespace std;
int LENGTH(char const *S)
{
    int i = 0;
    while(S[i++] != '\0');
    return i;
}
char *SUBSTR(char const *S, int from, int to)
{   int i;
    char *str = new char[to + 1];
    for( i = 0; i < to && S[i+from] != '\0'; i++)
    {
        str[i]  = S[i+from];
    }
    str[i] = '\0';
    return str;

}
int main()
{
    char const *S = "JOHN PAUL JONES", *T = "A THING OF BEAUTY IS A JOY FOREVER";
    cout << S  << endl;
    cout << T  << endl;
    cout << LENGTH(S) << endl;
    cout << LENGTH(T) << endl;
}

/*
JOHN PAUL JONES
A THING OF BEAUTY IS A JOY FOREVER
16
35
*/
#include<iostream>
#include<cstring>
using namespace std;
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
    char *s = SUBSTR(S,4,8);
    cout << s << endl;
    s = SUBSTR(T,10,5);
    cout << s << endl;
}
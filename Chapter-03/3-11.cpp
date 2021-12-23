/*
3.11 Recall that we use S1//S2 to denote the concatenation of strings S1 and S2.

(a) How is this function denoted in (i) PL/1, (ii) FORTRAN, (iii) BASIC, (iv) SNOBOL and (v) UCSD Pascal?

(b) Find (i) 'THE' // 'END' and (ii) 'THE' // ''//'END'.s

(c) Find (i) SUBSTRING(S, 11, 5)//','//SUBSTRING(S, 1, 9) and (ii) SUBSTRING (T, 28, 3)//'GIVEN'.
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
char *STRCAT(char const *S, char const *C, char const *T)
{
    int i = LENGTH(S) + LENGTH(T);
    char * str = new char[i+1];
    char * str0 = str;

    str = strcat(str,S);
    str = strcat(str, C);
    str = strcat(str,T);

    return str0;
}
char *STRCAT(char const *S, char const *T)
{
    int i = LENGTH(S) + LENGTH(T);
    char * str = new char[i+1];

    str = strcat(str,S);
    //str = strcat(str, " ");
    str = strcat(str,T);

    return str;
}
int main()
{
     char const *S = "JOHN PAUL JONES", *T = "A THING OF BEAUTY IS A JOY FOREVER";
     cout << LENGTH(S) << " " << LENGTH(T) << " " << endl;

    cout << STRCAT("THE"," ", "END") <<  endl;
    cout << STRCAT(SUBSTR(S,10, 5)," ",SUBSTR(S, 0, 9)) << endl;
    cout << STRCAT(SUBSTR(T,27,3), "GIVEN") << endl;
}
/*
output
16 35
THE END     
JONES JOHN PAUL
FORGIVE
*/
/*
page 42
Program 3-1
*/

#include<iostream>
#include<cstring>
using namespace std;
int main() 
{
    char *c = new char[100];
    int i = 0;
    cin.get(c[i]);
    while(c[i] != EOF)
    {
        cin.get(c[++i]);
    }
    c[i] = '\0';
    cout << c << endl;


    return 0;
}
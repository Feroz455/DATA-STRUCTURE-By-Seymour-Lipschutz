/*
page 68
program
Example 4-1 
*/
#include<iostream>
using namespace std;
int main()
{
    int DATA[6] = {247,56,429,135,87,156};
    for(int i = 0; i < sizeof(DATA)/sizeof(int); i++)
    cout << DATA[i] <<  endl;
    return 0;
}
/*
output

247
56 
429
135
87 
156
*/
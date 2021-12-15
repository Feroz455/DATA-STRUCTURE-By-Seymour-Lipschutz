/*
Page 34
Program 
List all the permutations of the numbers 1, 2, 3, 4.
*/
#include<iostream>
#include<cstring>
using namespace std;

/* Function to swap values at two pointers */
void swap(char &a, char &b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
    return;
}
/* Function to print permutations of string
This function takes three parameters:
1. String
2. Starting index of the string
3. Ending index of the string. */
void permutation(char str[], int x, int y)
{
    if(x == y)
    {
        cout << str << " \n" ;
    }
    else
    {

        for(int i = x; i < y; i++)
        {

            swap(str[x], str[i]);
            permutation(str, x+1, y);
            swap(str[i], str[x]);//backtrack
        }
    }
}
/* Driver program to test above functions */
int main()
{

    char String[20];
	cout << "Enter your string\n";
	cin >> String;
    int n = strlen(String);
    permutation(String, 0, n);
    return 0;
}
/*
Enter your string
1234
1234
1243
1324
1342
1432
1423
2134
2143
2314
2341
2431
2413
3214
3241
3124
3142
3412
3421
4231
4213
4321
4312
4132
4123
*/
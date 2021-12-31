/*
Page 109
Program 
4.26
4.6 Consider the data in Fig. 4.26(c). 
(a) Write a procedure which prints the list of clients belonging to LAWYER[K]. 
(b) Assuming CLIENT has space for 400 elements, define an array FREE such that 
FREE[K] contains the number of empty cells following the list of clients belonging 
to LAWYER[K].
*/
#include<iostream>
#include<string>
using namespace std;
struct LAWYER
{
    string Name;
    //Number of clint
    int NUMB;
    string *PTR;
    //number of free space in Clint array
    int FREE;
};
void CLIENT_PRINT(LAWYER L[],int M)
{
   
    string *LAST = (L[M].PTR) - 1;
    cout << L[M-1].Name << "'s Clint are\n";
    for( string *FIRST = L[M-1].PTR; FIRST < LAST; FIRST++)
    {
        cout << *FIRST << endl;
    }

}
//Main from Here
int main()
{
    string CLIENT[400];
    LAWYER L[3];
    L[0].PTR = &CLIENT[0];
    L[1].PTR = &CLIENT[150];
    L[2].PTR = &CLIENT[300];
}

/*
Output

*/
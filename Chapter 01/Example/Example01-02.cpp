/*
Program  example 1.2
A linear array STUDENT consisting of the names of six students in picture 
in Fig 1.1, Here STUDENT[1] denotes John Brown STUDENT[2] Sandra Gold
STUDENT[3] Tom Jones  STUDENT[4]June Kelly 
and so on.

*/
#include<iostream>
#include<string>
using namespace std;

//main begin
int main()
{
    string STUDENT[5];
    cout <<"Enter Studet name " << "\n"; 
    for(int i = 0; i < 5; i++)
    {
        getline(cin, STUDENT[i]);
    }
    cout << "\n";
    for (int i = 0; i < 5; i++)
    {
        cout <<  STUDENT[i] << "\n";
    }
    cout << "\n";
    getchar();
    return 0;
}
//main end
///Program end

/*
output
Enter Studet name 
John Brown
Sandra Gold
Tom Jones  
June Kelly 
Marry Reed 

John Brown 
Sandra Gold
Tom Jones  
June Kelly 
Marry Reed 
*/

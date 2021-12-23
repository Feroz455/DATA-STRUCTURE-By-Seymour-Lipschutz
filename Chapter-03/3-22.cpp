/*
Page 64
Program 3.22

*/
#include<iostream>
#include<string>
using namespace std;
struct TEST
{
    string s;
    int num;
};

int main()
{
    TEST T[12];
    for(int i = 0 ; i <= 12; i++)
    {
        cout << "Enter text\n";
        getline(cin,T[i].s);
        cout << "Enter number\n";
        cin >> T[i].num;
        getchar();
    }
    int j = 5;
    while(T[j].num != 0)
    {
        cout << T[j].s;
        j = T[j].num;
    }
  
 
  return 0;
}
/*
Output

*/
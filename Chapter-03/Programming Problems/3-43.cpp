/*
Page  66
Program 
Write a program which interchanges the Jth and Kth paragraphs. 
Test the program using J = 2 and K = 4.
*/
#include<iostream>
#include<string>
using namespace std;
void INTERCHANGE(string LINK[], int N, int FirstLine, int secontLine)
{
    string S;
    S = LINK[FirstLine];
    LINK[FirstLine] = LINK[secontLine];
    LINK[secontLine] = S;


}
int main()
{
  string S[100];
    int  i, FirstLine, SecondLine;
    cout <<  "Enter your string\n";
    for(i ; i < 100; i++)
    {
        getline(cin,S[i]);
        if(S[i].substr(0,5) == "$$$$$")
        break;
    }
    cout << "Enter line number to Interchange\n";
    cout << "First Line " ; cin >> FirstLine ;
    cout << "Second Line "; cin >> SecondLine;
    INTERCHANGE(S,i,FirstLine+1,SecondLine+1);
    for(int k = 0; k < i ; k++)
    {
        cout << S[k] <<  endl;
    }
  return 0;
}
/*
Output
Enter your string
1 the We do not count the in mother, and we assume no sentence ends with the word the
2 the We do not count the in mother, and we assume no sentence ends with the word the
3 the We do not count the in mother, and we assume no sentence ends with the word the
4 the We do not count the in mother, and we assume no sentence ends with the word the
5 the We do not count the in mother, and we assume no sentence ends with the word the
6 the We do not count the in mother, and we assume no sentence ends with the word the
$$$$$
Enter line number to Interchange
First Line 2
Second Line 4
1 the We do not count the in mother, and we assume no sentence ends with the word the
2 the We do not count the in mother, and we assume no sentence ends with the word the
3 the We do not count the in mother, and we assume no sentence ends with the word the
6 the We do not count the in mother, and we assume no sentence ends with the word the
5 the We do not count the in mother, and we assume no sentence ends with the word the
4 the We do not count the in mother, and we assume no sentence ends with the word the
*/
/*
Page  62
Program 
3.17 Outline an algorithm which will interchange the kth and lth paragraphs in the short story S.
The algorithm reduces to two procedures:

Procedure A. 
Find the values of arrays BEG and END where
LINE[BEG[K]]   and   LINE[END[K]]
contain, respectively, the first and last lines of paragraph K of the story S.

Procedure B. 
Using the values of BEG[K] and END[K] and the values of BEG[L] 
and END[L], interchange the block of lines of paragraph K with the block of lines of paragraph L
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
Enter line number to Interchange
First Line 1
Second Line 3
1 the We do not count the in mother, and we assume no sentence ends with the word the
2 the We do not count the in mother, and we assume no sentence ends with the word the
1
4 the We do not count the in mother, and we assume no sentence ends with the word the
3 the We do not count the in mother, and we assume no sentence ends with the word the
3

*/
/*
Page  62
Program
3.16 Discuss the changes that must be made in Procedure P3.15 
if one wants to count the number of occurrences of an aribitrary 
word W with length R.
*/

#include<iostream>
#include<string>
using namespace std;
int COUNT(string WORD[], int N,int NUM)
{
    string key;
    cout << "Enter your key\n";
    cin >> key;
    
    string BEG(key + " "), END(" " + key), MID(" "+key+" ");
  
  for(int i = 0; i < N ; i++)
  {
    if( WORD[i].substr(0, BEG.length()) == BEG)
    {
    NUM += 1; 
    }
    if(WORD[i].substr(WORD[i].length()- END.length(), WORD[i].length()) == END)
    {
    NUM += 1; 
    }
    for(int K = 2; K < WORD[i].length()-3; K++)
    {
      if(WORD[i].substr(K,MID.length()) ==  MID)
      {
        NUM += 1; 
      }
    }   
  }
 
  return NUM;
}

int main()
{

    string S[100];
    int  i;
    cout <<  "Enter your string\n";
    for(i ; i < 100; i++)
    {
        getline(cin,S[i]);
        if(S[i].substr(0,5) == "$$$$$")
        break;
    }
    int NUM = COUNT(S,i,0);
     cout << "Number of ' the ' = " << NUM << " Times\n";
    return 0;
}
/*
Output
Enter your string
the We do not count the in mother, and we assume no sentence ends with the word the
the We do not count the in mother, and we assume no sentence ends with the word the
the We do not count the in mother, and we assume no sentence ends with the word the
the We do not count the in mother, and we assume no sentence ends with the word the
$$$$$
Enter your key
we
Number of ' the ' = 4 Times
*/
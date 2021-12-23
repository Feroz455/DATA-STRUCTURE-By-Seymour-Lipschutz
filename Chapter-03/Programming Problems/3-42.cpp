/*
page 66
Program 3.342
Write a program which reads a given WORD and then counts the number 
C of times WORD occurs in TEXT. Test the program using 
(a) WORD = 'THE' and 
(b) WORD = 'HENCE'.
*/
#include<iostream>
#include<string>
using namespace std;
int COUNT(string WORD[], int N,int NUM, string key)
{
    
    string BEG(key + " "), END(" " + key), MID(" "+key+" ");
  
  for(int i = 0; i < N ; i++)
  {
    if( WORD[i].substr(0, 4) == BEG)
    {
    NUM += 1; 
    }
    if(WORD[i].substr(WORD[i].length()- 4, WORD[i].length()) == END)
    {
    NUM += 1; 
    }
    for(int K = 2; K < WORD[i].length()-3; K++)
    {
      if(WORD[i].substr(K,5) ==  MID)
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
    string key;
    cout << "Enter your keyword\n";
    cin >> key;
    int NUM = COUNT(S,i,0,key);
    cout << "Number of " <<key <<  " = " << NUM << " Times\n";
    return 0;
}
/*
FIRST RUN
Enter your string
the We do not count the in mother, and we assume no sentence ends with the word the
the We do not count the in mother, and we assume no sentence ends with the word the
the We do not count the in mother, and we assume no sentence ends with the word the
the We do not count the in mother, and we assume no sentence ends with the word the
$$$$$
Enter your keyword
the
Number of the = 16 Times


second RUN 
Enter your string
the We do not count the in mother, and we assume no sentence ends with the word the
the We do not count the in mother, and we assume no sentence ends with the word the
the We do not count the in mother, and we assume no sentence ends with the word the
the We do not count the in mother, and we assume no sentence ends with the word the
$$$$$
Enter your keyword
HENCE
Number of HENCE = 0 Times
*/
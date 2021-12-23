/*
Page 66
Program 3.44
Write a program which reads words WORD1 and WORD2 
and then replaces each occurrence of WORD1 in TEXT 
by WORD2. Test the program using WORD1 = 'HENCE' and WORD2 = 'THUS'

*/
#include<iostream>
#include<string>
using namespace std;
int COUNT(string WORD[], int N,int NUM, string key)
{
    
    string BEG(key + " "), END(" " + key), MID(" "+key+" ");
  
  for(int i = 0; i < N ; i++)
  {
     // cout << "Hello 1\n";
    if( WORD[i].substr(0, 4) == BEG)
    {
    WORD[i].replace(0, BEG.length(), "THIS "); 
    NUM++;
    }
    if(WORD[i].substr(WORD[i].length()- 4, WORD[i].length()) == END)
    {
    WORD[i].replace(WORD[i].length()- 4, END.length(), " THIS ");  
    NUM++;
    }
    for(int K = 2; K < WORD[i].length()-3; K++)
    {
      //  cout << "Hello 2\n";
      if(WORD[i].substr(K,5) ==  MID)
      {
        WORD[i].replace(K, MID.length(), " THIS ");
        NUM++;  
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
    for(i = 0 ; i < 100; i++)
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
    for(i = 0 ; i < 100; i++)
    {
        cout << S[i];
        if(S[i].substr(0,5) == "$$$$$")
        break;
    }
    return 0;
}
/*
Enter your keyword
the
Number of the = 16 Times
THIS We do not count THIS in mother, and we assume no sentence ends with 
THIS word THIS THIS We do not count THIS in mother, and we assume no 
sentence ends with THIS word THIS THIS We do not count THIS in mother, 
and we assume no sentence ends with THIS word THIS THIS We do not count 
THIS in mother, and we assume no sentence ends with THIS word THIS $$$$$
*/
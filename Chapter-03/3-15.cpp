/*
Page  61
Program
3-15
Write a procedure which counts the number NUM of times the word 
“the” appears in the short story S. (We do not count “the” in 
“mother,” and we assume no sentence ends with the word “the.”

************Algorithm**************
Procedure P3.15: COUNT(LINE, N, NUM)
1. Set WORD := 'THE' and NUM := 0.
2. [Prepare for the three cases.]
Set BEG := WORD//' ', END := ' '//WORD and
MID := ' ' //WORD// ''.
3. Repeat Steps 4 through 6 for K = 1 to N:
4.      [First case.] If SUBSTRING(LINE[K], 1, 4) = BEG, then:
Set NUM := NUM + 1.
5.      [Second case.] If SUBSTRING(LINE[K], 77, 4) = END, then:
Set NUM := NUM + 1.
6.      [General case.] Repeat for J = 2 to 76.
If SUBSTRING(LINE[K], J, 5) = MID, then:
      Set NUM := NUM + 1.
[End of If structure.]
[End of Step 6 loop.]
[End of Step 3 loop.]
7. Return
*/

#include<iostream>
#include<string>
using namespace std;
int COUNT(string WORD[], int N,int NUM)
{
    string key("the");
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
    int NUM = COUNT(S,i,0);
     cout << "Number of ' the ' = " << NUM << " Times\n";
    return 0;
}
/*
Output
the We do not count the in mother, and we assume no sentence ends with the word the
the We do not count the in mother, and we assume no sentence ends with the word the
the We do not count the in mother, and we assume no sentence ends with the word the
the We do not count the in mother, and we assume no sentence ends with the word the
$$$$$
Number of ' the ' = 16 Times
*/
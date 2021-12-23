/* 
Page 66
Program 
Write a subprogram PRINT(TEXT, K) 
which prints the character string TEXT 
in lines with at most K characters. No 
word should be divided in the middle and 
appear on two lines, so some lines may 
contain trailing blank spaces. Each 
paragraph should begin with its own 
line and be indented using 5 blank spaces. 
Test the program using
 (a) K = 800, (b) K = 70 and (c) K = 60.
*/
#include<iostream>
#include<string>
using namespace std;
int N = 100;
void PRINT(string TEXT[], int K)
{
    int z = 0;
    for(int j = 0; j < N-1; j++)
    {
        for(int i = 0 ;i < TEXT[j].length(); i++)
        {
            if((z++) % K == 0)
            cout << "\n";
            else if(TEXT[j].at(i) == '\n')
            continue;
            else 
            if(TEXT[j].at(i) == '$')
            return;
            else
            cout <<TEXT[j].at(i);
        }
    }
 
    return;
}
int main()
{
  string S[100];
    int  i;
    cout <<  "Enter your string\n";
    for(i = 0 ; i < 100; i++)
    {
        getline(cin,S[i]);
        N++;
        if(S[i].substr(0,5) == "$$$$$")
        break;
    }

    PRINT(S,80);
  return 0;
}
/*
Output
Enter your string
The Story of An Hour

This story was first published in 1894 as The Dream of an Hour before being republished under this title in 1895.
We encourage students and teachers to use our The Story of An Hour Study Guide and Feminist Literature Study Guide.

     Knowing that Mrs. Mallard was afflicted with a heart trouble, great care was taken to break to her as gently 
     as possible the news of her husband's death.
     It was her sister Josephine who told her, in broken sentences; veiled hints that revealed in half concealing. 
     Her husband's friend Richards was there, too, near her. It was he who had been in the newspaper office when
     intelligence of the railroad disaster was received, with Brently Mallard's name leading the list of "killed."
     He had only taken the time to assure himself of its truth by a second telegram, and had hastened to forestall
     any less careful, less tender friend in bearing the sad message.
     She did not hear the story as many women have heard the same, with a paralyzed inability to accept its significance.
      wept at once, with sudden, wild
abandonment, in her sister's arms. When the storm of grief had spent itself she went away to her room alone.
She would have no one follow her.
$$$$$

he Story of An HourThis story was first published in 1894 as The Dream of an Ho
r before being republished under this title in 1895.We encourage students and t
achers to use our The Story of An Hour Study Guide and Feminist Literature Stud
 Guide.     Knowing that Mrs. Mallard was afflicted with a heart trouble, great
care was taken to break to her as gently      as possible the news of her husba
d's death.     It was her sister Josephine who told her, in broken sentences; v
iled hints that revealed in half concealing.      Her husband's friend Richards
was there, too, near her. It was he who had been in the newspaper office when
  intelligence of the railroad disaster was received, with Brently Mallard's na
e leading the list of "killed."     He had only taken the time to assure himsel
 of its truth by a second telegram, and had hastened to forestall     any less
areful, less tender friend in bearing the sad message.     She did not hear the
story as many women have heard the same, with a paralyzed inability to accept i
s significance.      wept at once, with sudden, wildabandonment, in her sister'
 arms. When the storm of grief had spent itself she went away to her room alone
She would have no one follow her.

*/
/*
Page 66
Program
3.45
Write a subprogram INST(TEXT, NEW, K) 
which inserts a string NEW into TEXT beginning at TEXT[K]
*/
#include<iostream>
#include<string>
using namespace std;
void INSERT(string TEXT[], string NEW ,int  K)
{
    TEXT[K].insert(0,NEW);
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
        if(S[i].substr(0,5) == "$$$$$")
        break;
    }
    INSERT(S, "****HEllo DEAR*****" , 4);


    for(i = 0 ; i < 100; i++)
    {
        cout << S[i] << endl;
        if(S[i].substr(0,5) == "$$$$$")
        break;
    }
 
  return 0;
}
/*
Output
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
The Story of An Hour

This story was first published in 1894 as The Dream of an Hour before being republished under this title in 1895.
We encourage students and teachers to use our The Story of An Hour Study Guide and Feminist Literature Study Guide.
****HEllo DEAR*****
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

*/
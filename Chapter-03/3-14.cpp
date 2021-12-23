/*
Page 61
Program 3.14
3.14 Write a procedure which counts the number NUM of paragraphs in the short story S.
Procedure P3.14: PAR(LINE, N, NUM)
1. Set NUM := 0 and BLANK := 
2. [Initialize counter.] Set K := 2.
3. Repeat Steps 4 and 5 while K ≤ N − 1.
4.        [Compare first 5 characters of each line with BLANK.]
If SUBSTRING(LINE[K], 1, 5) = BLANK, then:
Set NUM := NUM + 1
[End of If structure.)
5.        Set K := K + 1. [Increments counter.]
[End of Step 3 loop.]
6. Return
*/
#include<iostream>
#include<string>
using namespace std;

int PAR(string LINK[], int N, int NUM)
{
    NUM = 0;
    string BLANK("     ");
    int K = 2;
    while (K <= N-1)
    {
        if(LINK[K].substr(0, 5) == BLANK)
        NUM++;
        K = K + 1;
    }
    return NUM;
    
}

int main()
{
    string S[100];
    int i;
    for(i = 0; i < 100; i++)
    {
        getline(cin, S[i]);
        if(S[i] == "$$$$$")
        break;
    }
    i =  PAR(S,i,0);
   cout << "Number of Pragrap " << i << endl;
}
/*
output
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
Number of Pragrap 9
*/
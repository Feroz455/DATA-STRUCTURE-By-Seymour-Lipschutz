/*
Page 57
parogram
Algorithm 3.4: (Pattern Matching). The pattern matching table F(Q1, T) 
of a pattern P is in memory, and the input is an N-character string T = 
T1T2 … TN. This algorithm finds the INDEX of P in T.
1. [Initialize.] Set K := 1 and S1 = Q0
2. Repeat Steps 3 to 5 while SK ≠ P and K ≤ N.
3.      Read TK.
4.     Set SK + l := F(SK, TK). [Finds next state.]
5.      Set K := K + 1. [Updates counter.]
[End of Step 2 loop.]
6. [Successful?]
If SK = P, then:
INDEX = K − LENGTH(P).
Else:
INDEX = 0.
[End of If structure.]
7. Exit

*/

#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string p;
string Q[100];
///////////////////////////////////////////////////////////
string F(string S, string C)
{
    string ck = S + C;
    int i ;
    for(i = 0; i < ck.length(); i++)
    {
        if(ck.substr(i,ck.length()) == Q[(ck.length() - i)])
        {
        //cout << " CK " << (ck.length() - i) <<  endl;
        break;

        }

    }
   // cout << " CK " << (ck.length() - i) <<  endl;
   return  Q[(ck.length() - i)];
}


/////////////////////////////////////////////////////////////
void INITIAL()
{
   for(int i = 0; i <= p.length(); i++)
   {
       Q[i] = p.substr(0,i);
     //  cout << "Q[" << i << "] = " << Q[i] << endl;
   }
}

int main()
{
    string T, S[100];
    int i, INDEX = 0;
    cout << "Enter your string\n";
    cin >> T ;
    cout << "Enter your keyword\n";
    cin >> p;
    INITIAL();
    S[0] = Q[0];
    for(i  = 0; i < T.length(); i++)
    {

           S[i+1] = F(S[i],T.substr(i,1));
           if(S[i+1] == p)
           {
              INDEX = i - p.length();
              break;
           }
    }
    cout <<  S[i+1] <<  "INDEX = " << INDEX << endl;

    return 0;
}
/*
output


#First run

Enter your string
aabbaabbaabbaabb
Enter your keyword
aaa
INDEX = 0



#second run 

Enter your string
abaabbaaabbbaaaabbbb
Enter your keyword
aaa
aaaINDEX = 5
*/
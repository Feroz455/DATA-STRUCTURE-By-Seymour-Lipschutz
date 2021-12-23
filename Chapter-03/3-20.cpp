/*
page 63
program 3.20

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
/*
Page 65
Program 3.28
Find (a) INDEX(S, 'P'), 
(b) INDEX(S, 'E'), 
(c) INDEX(S, 'THE'), 
(d) INDEX(T, 'THE'), 
(e) INDEX(T, 'THEN') and 
(f) INDEX(T, 'TE').
*/
#include<iostream>
#include<string>
using namespace std;
string Q[100];
string F(string S, string C)
{
    string ck = S + C;
    int i ;
    for(i = 0; i < ck.length(); i++)
    {
        if(ck.substr(i,ck.length()) == Q[(ck.length() - i)])
        {
       // cout << " CK " << (ck.length() - i) <<  endl;
        break;

        }

    }
   // cout << " CK " << (ck.length() - i) <<  endl;
   return  Q[(ck.length() - i)];
}
void INITIAL(string p)
{
   for(int i = 0; i <= p.length(); i++)
   {
       Q[i] = p.substr(0,i);
    //  cout << "Q[" << i << "] = " << Q[i] << endl;
   }
}

int IND(string T, string p)
{
    string  S[100];
    int i, INDEX = 0;
   INITIAL(p);
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
    cout <<  S[i+1] <<  "  INDEX = " << INDEX + 1<< endl;

    return INDEX + 1;
}
int main()
{
  string S("WE THE PEOPLE");
  string T("OF THE UNITED STATES");
  cout << IND(S,"P") << endl;
  cout << IND(S,"E") << endl;
  cout << IND(S,"THE") << endl;
  cout << IND(T,"THE") << endl;
  cout << IND(T,"THEN") << endl;
  cout << IND(S,"TH") << endl;
  return 0;
}
/*
Output
P  INDEX = 7
7
E  INDEX = 1
1
THE  INDEX = 3
3
THE  INDEX = 3
3
  INDEX = 1
1
TH  INDEX = 3
3
*/
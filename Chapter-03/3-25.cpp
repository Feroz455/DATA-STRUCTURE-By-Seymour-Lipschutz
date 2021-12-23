/*
Suppose STATE is a character variable with fixed length 12. 
Describe the contents of STATE after the assignment 
(a) STATE := 'NEW YORK', 
(b) STATE := 'SOUTH CAROLINA' and 
(c) STATE := 'PENNSYLVANIA'.

Page 
Program
*/
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
  char s[12];
  strcpy(s,"NEW YORK");
  cout << s <<  endl;
  strcpy(s,"SOUTH CAROLINA");
  cout << s <<  endl;
  strcpy(s,"PENNSYLVANIA");
  cout << s <<  endl;


 
  return 0;
}
/*
Output

*/
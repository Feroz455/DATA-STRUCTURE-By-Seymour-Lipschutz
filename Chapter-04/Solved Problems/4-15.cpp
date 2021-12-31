/*
Page 105
Program
4.15 Three lawyers, Davis, Levine and Nelson, share the same office. 
Each lawyer has his own clients. Figure 4.26 shows three ways of organizing the data.

(a) Here there is an alphabetized array CLIENT and an array 
LAWYER such that LAWYER[K] is the lawyer for CLIENT[K]
(b) Here there are three separate arrays, DAVIS, LEVINE and NELSON, 
each array containing the list of the lawyer’s clients.

(c) Here there is a LAWYER array, and arrays NUMB and PTR giving, 
respectively, the number and location of each lawyer’s alphabetized list of clients in an array CLIENT.

Which data structure is most useful? Why?



The most useful data structure depends on how the office is organized and how the clients are processed.

Suppose there are only one secretary and one telephone number, and suppose there is a single monthly 
billing of the clients. Also, suppose clients frequently change from one lawyer to another. Then Fig. 
4.26(a) would probably be the most useful data structure.

Suppose the lawyers operate completely independently: each lawyer has his own secretary and his own 
telephone number and bills his clients differently. Then Fig. 4.26(b) would likely be the most useful 
data structure.

Suppose the office processes all the clients frequently and each lawyer has to process his own clients 
frequently. Then Fig. 4.26(c) would likely be the most useful data structure.
*/
#include<iostream>
#include<string>
using namespace std;
//Main from Here
int main()
{
    string name[22];
    string *Grp[5];
    for(int i = 0;  i < 21; i++)
    {
        cin >> name[i] ;
    }
    Grp[0] = &name[0];
    Grp[1] = &name[4];
    Grp[2] = &name[13];
    Grp[3] = &name[15];
    Grp[4] = &name[21];

    cout << "\n****************************\n";
    string *first, *last;
    for(int i = 0; i < 5; i++)
    {
        cout << "\n****************************\n";
        for(first = Grp[i]; first <= Grp[i+1]-1; first++)
        {
            cout << *first << endl;
        }
    }
   
}

/*
Output
Allen
Clark  
Dickens
Edwards
Goodman
Hobbs  
Irwin  
Klein  
Lewis
Morgan
Richards
Scott
Tucker
Walton
Evans
Harris
Lewis
Shaw
Davis
Segal
Baker
*/
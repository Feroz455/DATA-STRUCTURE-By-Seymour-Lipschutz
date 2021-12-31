/*
Page 112
Program 
Assume the data in Table 4.2 are stored in a single linear array 
CLASS (with space for 50 names). Also assume that there are 2 em
pty cells between the sections, and that there are linear arrays 
NUMB, PTR and FREE defined so that NUMB[K] contains the number o
f elements in Section K, PTR[K] gives the location in CLASS of t
he first name in Section K, and FREE[K] gives the number of empt
y cells in CLASS following Section K.


4.11 Write a program which prints the names in columns as they appear in Table 4.2.
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int COUNT = 50;
struct STUDENT
{
    int NUMB;
    int FREE;
    string *PTR;
};
void INPUT(STUDENT section[],string Name[], int SN)
{

    ;
    int j = 0;
    for(int i = 0 ; i < SN; i++)
    {
        cout << "Enter Name list   " << i+1 << " section \n";
        while(j < 52)
        {
            cin >> Name[j];
            section[i].NUMB++;
            section[i].FREE--;
            if(Name[j] == "$$$$$")
            {
                j = (i+1)*13;
                break;
            } 
            j++;
        }
    }
    return;

}
void OUTPUT(STUDENT section[], int SN)
{
    string *NNN[4];
    NNN[0] = section[0].PTR;
    NNN[1] = section[1].PTR;
    NNN[2] = section[2].PTR;
    NNN[3] = section[3].PTR;
    cout << setw(12) << "section#1" << setw(12) << "section#2"  << setw(12) << "section#3" << setw(12) << "section#4" << endl;
    for(int j = 0; j < 13; j++)
    {
        for(int i = 0 ; i < SN; i++)
        {
            cout << setw(12) << *(NNN[i]);
            NNN[i]++;
            
        }
        cout << "\n";
        //cout << "section[ " << i+1 << "].NUMB = " << section[i].NUMB-1 << endl;
    }
}
void PTRMAP(STUDENT section[], string NAME[])
{
    for(int i = 0, j = 0; i < 52; i += 13, j++)
    {
        //cout << " i  = " << i << "\n";
        section[j].PTR = &NAME[i];
        section[j].FREE = 13;
        section[j].NUMB = 0;  
    }
}
//Main from Here
int main()
{
    int SN = 4;
    STUDENT section[SN];
    string NAME[52];
    PTRMAP(section,NAME);
    INPUT(section,NAME, SN);
    OUTPUT(section,SN);

    return 0;
}
/*
Enter Name list   1 section 
Brown 
Davis 
Jones
Samuels
$$$$$
Enter Name list   2 section
Abrams
Collins
Forman
Hughes
Klein
Lee
Moore
Quinn
Rosen
Scott
Taylor
Weaver
$$$$$
Enter Name list   3 section
Allen
Conroy
Damario 
Harris
Rich
Sweeney
$$$$$
Enter Name list   4 section 
Burns
Cohen
Evans
Gilbert
Harlan
Lopez
Meth 
Ryan
Williams
$$$$$
   section#1   section#2   section#3   section#4
       Brown      Abrams       Allen       Burns
       Davis     Collins      Conroy       Cohen
       Jones      Forman     Damario       Evans
     Samuels      Hughes      Harris     Gilbert
       $$$$$       Klein        Rich      Harlan
                     Lee     Sweeney       Lopez
                   Moore       $$$$$        Meth
                   Quinn                    Ryan
                   Rosen                Williams
                   Scott                   $$$$$
                  Taylor
                  Weaver
                   $$$$$
*/
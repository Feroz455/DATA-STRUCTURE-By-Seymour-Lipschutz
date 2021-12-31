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



4.9 Write a program which reads an integer K and prints the names in Section K. 
Test the program using (a) K = 2 and (b) K = 3.
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
    string *NNN;
   for(int i = 0 ; i < SN; i++)
    {
        cout << "\nSECTION " << i+1 << endl;
        NNN = section[i].PTR;
        for(int j = 0; j < section[i].NUMB - 1; j++)
        {
            cout << "#" << setw(2) << j+1  << ". "<< *(NNN) << endl;
            NNN++;
            
        }
        //cout << "section[ " << i+1 << "].NUMB = " << section[i].NUMB-1 << endl;
    }
}
void OUTPUT_K_SECTION(STUDENT section[], int i)
{
    cout << "\nSECTION " << i << endl;
    string *NNN;
    i = i -1;
        NNN = section[i].PTR;
        for(int j = 0; j < section[i].NUMB - 1; j++)
        {
            cout << "#" << setw(2) << j+1  << ". "<< *(NNN) << endl;
            NNN++;
            
        }
        cout << "\n*************************************\n" << endl;
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
    cout << "Enter section Number\n";
    int i;
    cin >> i ;
    OUTPUT_K_SECTION(section,i);
    cout << "Enter section Number\n";
    cin >> i ;
    OUTPUT_K_SECTION(section,i);
    //OUTPUT

    return 0;
}

/*
Output

Section 1
Section 2
Section 3
Section 4



Brown 
Davis 
Jones 
Samuels
$$$$$
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
Allen 
Conroy 
Damario 
Harris 
Rich 
Sweeney
$$$$$
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

SECTION 1
# 1. Brown
# 2. Davis
# 3. Jones
# 4. Samuels

SECTION 2
# 1. Abrams
# 2. Collins
# 3. Forman
# 4. Hughes
# 5. Klein
# 6. Lee
# 7. Moore
# 8. Quinn
# 9. Rosen
#10. Scott
#11. Taylor
#12. Weaver

SECTION 3
# 1. Allen
# 2. Conroy
# 3. Damario
# 4. Harris
# 5. Rich
# 6. Sweeney

SECTION 4
# 1. Burns
# 2. Cohen
# 3. Evans
# 4. Gilbert
# 5. Harlan
# 6. Lopez
# 7. Meth
# 8. Ryan
# 9. Williams
Enter section Number
2

SECTION 2
# 1. Abrams
# 2. Collins
# 3. Forman
# 4. Hughes
# 5. Klein
# 6. Lee
# 7. Moore
# 8. Quinn
# 9. Rosen
#10. Scott
#11. Taylor
#12. Weaver

*************************************

Enter section Number
3

SECTION 3
# 1. Allen
# 2. Conroy
# 3. Damario
# 4. Harris
# 5. Rich
# 6. Sweeney

*************************************
*/
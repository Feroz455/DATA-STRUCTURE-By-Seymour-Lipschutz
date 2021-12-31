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
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<stdlib.h>
using namespace std;
/****************************/
int COUNT = 50;
struct STUDENT
{
    int NUMB;
    int FREE;
    string *PTR;
};

/***************************/

void PRINTLINE(string c = "##");
void INPUT(STUDENT section[],string Name[], int SN);
void OUTPUT(STUDENT section[], int SN);
void OUTPUT_K_SECTION(STUDENT section[], int i);
void PTRMAP(STUDENT section[], string NAME[]);
void OPTION();
void START(STUDENT section, string NAME,int N, int SN);
void OUTPUT_TABLE(STUDENT section[], int SN);
void INSERT(STUDENT section[],string NAME[], string Name, int SN);
void DELETE(STUDENT section[], string name, int SN);
/****************************/

void DELETE(STUDENT section[], string name, int SN)
{
    string *NNN;
   for(int i = 0 ; i < SN; i++)
    {
        //cout << "\nSECTION " << i+1 << endl;
        NNN = section[i].PTR;
        for(int j = 0; j <= section[i].NUMB; j++)
        {
            if(name == *NNN)
            {
                while(*NNN != "$$$$$")
                {
                    *NNN = *(NNN+1);
                    NNN++;
                }
                *(NNN) = " ";
                section[i].FREE += 1;
                section[i].NUMB -= 1;
                return;
                
            }
            NNN++;
            
        }
        //cout << "section[ " << i+1 << "].NUMB = " << section[i].NUMB-1 << endl;
    }

}
void INSERT(STUDENT section[],string NAME[], string Name, int SN)
{
    int N = SN - 1;
    SN = (N * 13);
    NAME[SN+section[N].NUMB] = Name;
    section[N].NUMB += 1;
    NAME[SN+section[N].NUMB] = "$$$$$";
    section[N].FREE -= 1;

}
void START(STUDENT section[], string NAME[],int N, int SN)
{
    string name;
    char CK;
    int temp, CHECK = 0;
    while(1)
    {
        OPTION();
        cout << "->  ";
        cin >> CK;
        switch (CK)
        {
            case '1':
                if(CHECK == 0)
                {
                    INPUT(section, NAME, SN);
                    CHECK = 1;
                }
                else 
                cout << "DATA ALREADY LOADED\n";    
                break;
            case '2':
                if(CHECK != 0)
                OUTPUT(section, SN);
                else 
                cout << "EMPTY LIST\n";
                break;
            case '3':
                if(CHECK != 0)
                OUTPUT_TABLE(section, SN);
                else 
                cout << "EMPTY LIST\n";
                break;
            case '4':
                if(CHECK != 0)
                {
                    AGAIN:
                    cout << "Enter section number\n";
                    cin >> temp;
                    if(temp < 5 && temp > 0)
                    OUTPUT_K_SECTION(section,temp);
                    else 
                    {
                        cout << "INVELID SECTION\nTRY AGAIN\n";
                        goto AGAIN;
                    }
                }
                    else 
                    cout << "EMPTY LIST\n";                
                break;
            case '5':
            cout << "Section number\n";
                    AGAIN1:
                    cin >> temp;
                    if(temp < 5 && temp > 0)
                    {
                        if(section[temp-1].NUMB < 12)
                        {
                            cout << "Enter Name to insert\n";
                            cin >> name;
                            INSERT(section,NAME, name,temp);
                           // CHECK = 1;
                        }
                        else
                        cout << "LIST IS FULL"; 
                    }
                    else 
                    {
                        cout << "INVELID SECTION\nTRY AGAIN\n";
                        goto AGAIN1;
                    }     
                break;
            case '6':
                    if(CHECK != 0)
                    {
                        cout << "Enter Name to delete\n";
                        cin >> name;   
                        DELETE(section, name, SN);
                    }
                    else
                    cout << "LIST EMPTY\n";
                break;
            case '7':
                exit(0);
            default:
                cout << "INVALID INPUT!!!\nTRY AGAIN\n";
                break;
        }
    }
}

//Main from Here
int main()
{
    int SN = 4, N = 52;
    STUDENT section[SN];
    string NAME[N];
    PTRMAP(section, NAME);
    PRINTLINE();
    PRINTLINE();
    START(section, NAME, N, SN);
    return 0;
}


//Geting name from User

void INPUT(STUDENT section[],string Name[], int SN)
{

    int j = 0;
    for(int i = 0 ; i < SN; i++)
    {
        cout << "Enter Name list   " << i+1 << " section \n";
        while(j < 52)
        {
            cin >> Name[j];
            
            if(Name[j] == "$$$$$")
            {
                j = (i+1)*13;
                break;
            } 
            section[i].NUMB += 1 ;
            //cout << section[i].NUMB << endl;
            section[i].FREE -= -1;
            j++;
        }
    }
    return;

}

//Show Name SECTION WISE
void OUTPUT(STUDENT section[], int SN)
{
    string *NNN;
   for(int i = 0 ; i < SN; i++)
    {
        cout << "\nSECTION " << i+1 << endl;
        NNN = section[i].PTR;
        for(int j = 0; j < section[i].NUMB; j++)
        {
            cout << "#" << setw(2) << j+1  << ". "<< *(NNN) << endl;
            NNN++;
            
        }
        //cout << "section[ " << i+1 << "].NUMB = " << section[i].NUMB-1 << endl;
    }
}


void OUTPUT_TABLE(STUDENT section[], int SN)
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
void OUTPUT_K_SECTION(STUDENT section[], int i)
{
    cout << "\nSECTION " << i << endl;
    string *NNN;
    i = i -1;
        NNN = section[i].PTR;
        for(int j = 0; j < section[i].NUMB; j++)
        {
            cout << "#" << setw(2) << j+1  << ". "<< *(NNN) << endl;
            NNN++;
            
        }
        PRINTLINE();
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

void PRINTLINE(string c)
{
    cout << endl;
    for(int i = 0; i < 50; i++)
    {
        cout << c;
    }
    cout << endl;
}
//PRINTING OPTION 
void OPTION()
{
    cout << "\n" << setw(50) << "Enter Your Choice\n";
    PRINTLINE("**");
    cout << setw(3) << 1 << ". INPUT STUDENT NAME\n";
    cout << setw(3) << 2 << ". SHOW ALL STUDENT\n";
    cout << setw(3) << 2+1 << ". SHOW ALL STUDENT TABLE\n";
    cout << setw(3) << 3+1 << ". SHOW INDIVIDULE SECTION\n";
    cout << setw(3) << 4+1 << ". INSERT NAME\n";
    cout << setw(3) << 5+1 << ". DELETE NAME FROM SECTION\n";
    cout << setw(3) << 6+1 << ". EXIT";
    PRINTLINE("**");
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




####################################################################################################

####################################################################################################

                                Enter Your Choice

****************************************************************************************************
  1. INPUT STUDENT NAME
  2. SHOW ALL STUDENT
  3. SHOW ALL STUDENT TABLE
  4. SHOW INDIVIDULE SECTION
  5. INSERT NAME
  6. DELETE NAME FROM SECTION
  7. EXIT
****************************************************************************************************
->  1
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

                                Enter Your Choice

****************************************************************************************************
  1. INPUT STUDENT NAME
  2. SHOW ALL STUDENT
  3. SHOW ALL STUDENT TABLE
  4. SHOW INDIVIDULE SECTION
  5. INSERT NAME
  6. DELETE NAME FROM SECTION
  7. EXIT
****************************************************************************************************
->  3
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

                                Enter Your Choice

****************************************************************************************************
  1. INPUT STUDENT NAME
  2. SHOW ALL STUDENT
  3. SHOW ALL STUDENT TABLE
  4. SHOW INDIVIDULE SECTION
  5. INSERT NAME
  6. DELETE NAME FROM SECTION
  7. EXIT
****************************************************************************************************
->  5
Section number
3
Enter Name to insert
Eden

                                Enter Your Choice

****************************************************************************************************
  1. INPUT STUDENT NAME
  2. SHOW ALL STUDENT
  3. SHOW ALL STUDENT TABLE
  4. SHOW INDIVIDULE SECTION
  5. INSERT NAME
  6. DELETE NAME FROM SECTION
  7. EXIT
****************************************************************************************************
->  5
Section number
4
Enter Name to insert
Novak

                                Enter Your Choice

****************************************************************************************************
  1. INPUT STUDENT NAME
  2. SHOW ALL STUDENT
  3. SHOW ALL STUDENT TABLE
  4. SHOW INDIVIDULE SECTION
  5. INSERT NAME
  6. DELETE NAME FROM SECTION
  7. EXIT
****************************************************************************************************
->  5
Section number
2
LIST IS FULL
                                Enter Your Choice

****************************************************************************************************
  1. INPUT STUDENT NAME
  2. SHOW ALL STUDENT
  3. SHOW ALL STUDENT TABLE
  4. SHOW INDIVIDULE SECTION
  5. INSERT NAME
  6. DELETE NAME FROM SECTION
  7. EXIT
****************************************************************************************************
->  5
Section number
3
Enter Name to insert
Vaughn

                                Enter Your Choice

****************************************************************************************************
  1. INPUT STUDENT NAME
  2. SHOW ALL STUDENT
  3. SHOW ALL STUDENT TABLE
  4. SHOW INDIVIDULE SECTION
  5. INSERT NAME
  6. DELETE NAME FROM SECTION
  7. EXIT
****************************************************************************************************
->  5
Section number
3
Enter Name to insert
Bennett

                                Enter Your Choice

****************************************************************************************************
  1. INPUT STUDENT NAME
  2. SHOW ALL STUDENT
  3. SHOW ALL STUDENT TABLE
  4. SHOW INDIVIDULE SECTION
  5. INSERT NAME
  6. DELETE NAME FROM SECTION
  7. EXIT
****************************************************************************************************
->  3
   section#1   section#2   section#3   section#4
       Brown      Abrams       Allen       Burns
       Davis     Collins      Conroy       Cohen
       Jones      Forman     Damario       Evans
     Samuels      Hughes      Harris     Gilbert
       $$$$$       Klein        Rich      Harlan
                     Lee     Sweeney       Lopez
                   Moore        Eden        Meth
                   Quinn      Vaughn        Ryan
                   Rosen     Bennett    Williams
                   Scott       $$$$$       Novak
                  Taylor                   $$$$$
                  Weaver
                   $$$$$

                                Enter Your Choice

****************************************************************************************************
  1. INPUT STUDENT NAME
  2. SHOW ALL STUDENT
  3. SHOW ALL STUDENT TABLE
  4. SHOW INDIVIDULE SECTION
  5. INSERT NAME
  6. DELETE NAME FROM SECTION
  7. EXIT
****************************************************************************************************
->  6
Enter Name to delete
Klein

                                Enter Your Choice

****************************************************************************************************
  1. INPUT STUDENT NAME
  2. SHOW ALL STUDENT
  3. SHOW ALL STUDENT TABLE
  4. SHOW INDIVIDULE SECTION
  5. INSERT NAME
  6. DELETE NAME FROM SECTION
  7. EXIT
****************************************************************************************************
->  6
Enter Name to delete
Daniels

                                Enter Your Choice

****************************************************************************************************
  1. INPUT STUDENT NAME
  2. SHOW ALL STUDENT
  3. SHOW ALL STUDENT TABLE
  4. SHOW INDIVIDULE SECTION
  5. INSERT NAME
  6. DELETE NAME FROM SECTION
  7. EXIT
****************************************************************************************************
->  6
Enter Name to delete
Meth


                                Enter Your Choice

****************************************************************************************************
  1. INPUT STUDENT NAME
  2. SHOW ALL STUDENT
  3. SHOW ALL STUDENT TABLE
  4. SHOW INDIVIDULE SECTION
  5. INSERT NAME
  6. DELETE NAME FROM SECTION
  7. EXIT
****************************************************************************************************
->  6
Enter Name to delete
Herris

                                Enter Your Choice

****************************************************************************************************
  1. INPUT STUDENT NAME
  2. SHOW ALL STUDENT
  3. SHOW ALL STUDENT TABLE
  4. SHOW INDIVIDULE SECTION
  5. INSERT NAME
  6. DELETE NAME FROM SECTION
  7. EXIT
****************************************************************************************************
->  3
   section#1   section#2   section#3   section#4
       Brown      Abrams       Allen       Burns
       Davis     Collins      Conroy       Cohen
       Jones      Forman     Damario       Evans
     Samuels      Hughes      Harris     Gilbert
       $$$$$         Lee        Rich      Harlan
                   Moore     Sweeney       Lopez
                   Quinn        Eden        Ryan
                   Rosen      Vaughn    Williams
                   Scott     Bennett       Novak
                  Taylor       $$$$$       $$$$$
                  Weaver
                   $$$$$


                                Enter Your Choice

****************************************************************************************************
  1. INPUT STUDENT NAME
  2. SHOW ALL STUDENT
  3. SHOW ALL STUDENT TABLE
  4. SHOW INDIVIDULE SECTION
  5. INSERT NAME
  6. DELETE NAME FROM SECTION
  7. EXIT
****************************************************************************************************
->  7 

*/
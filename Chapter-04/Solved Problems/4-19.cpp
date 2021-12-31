/*
Page 107
Program
4.19 An automobile dealership keeps track of the serial number 
and price of each of its automobiles in arrays AUTO and PRICE, 
respectively. In addition, it uses the data structure 
in Fig. 4.27, which combines a record structure with pointer 
variables. The new Chevys, new Buicks, new Oldsmobiles, and 
used cars are listed together in AUTO. The variables

NUMB and PTR under USED give, respectively, the number and location of the list of used automobiles.

(a) How does one index the location of the list of new Buicks in AUTO?

(b) Write a procedure to print serial numbers of all new Buicks under $10 000.
*/
#include<iostream>
#include<string>
using namespace std;
struct CAR
{
    int AUTO;
    int PRICE;
};
struct DEALER
{
    struct N
    {
        struct  C
        {
            int NUMB;
            CAR *PTR;
        }CHEVY;
        struct B
        {
            int NUMB;
            CAR *PTR;
        }BUICK;
        struct O
        {
            int NUMB;
            CAR *PTR;
        }ILDS;
        
    } NEW;
    struct U
    {
        int NUMB;
        CAR *PTR;
    }USED;
};

void GET_INPUT(CAR DATA[], int N)
{
    for(int i = 0; i < N; i++)
    {
        cin >> DATA[i].AUTO ;
        cin >> DATA[i].PRICE ;
    }
 
    return;
}
void OUTPUT(CAR DATA[], int N)
{
    for(int i = 0; i < N; i++)
    {
        cout << i + 1 << ". Serial = " << DATA[i].AUTO  <<  " ";
        cout << " Price  = " << DATA[i].PRICE << endl;
    }
    return;
}
//(b) Write a procedure to print serial numbers of all new Buicks under $10 000.
void USEDCAR(CAR car[] , int N, DEALER &X)
{
    CAR *FIRST, *LAST;
    FIRST = X.NEW.BUICK.PTR;
    LAST = FIRST + X.NEW.BUICK.NUMB - 1;
    for(;FIRST < LAST; FIRST++)
    {
        if(FIRST->PRICE < 10000)
        {
            cout << "Serial = "  << FIRST->AUTO << " ";
            cout << "Price  = "  << FIRST->PRICE << " ";
        }
    }
}
//Main from Here
int main()
{
    int N = 200;
    CAR VV[200];
    DEALER XX;
   // (a) How does one index the location of the list of new Buicks in AUTO?
    XX.NEW.BUICK.PTR = &VV[175];
    GET_INPUT(VV, N);
    cout << "\n*********************************\n";
    OUTPUT(VV, N);
}
/*
Output



*/
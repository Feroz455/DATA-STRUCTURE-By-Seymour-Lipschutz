/*
Page 77
Algorithm 4.5: (Linear Search) LINEAR(DATA, N, ITEM, LOC)
Here DATA is a linear array with N elements, and ITEM is a given item of information. 
This algorithm finds the location LOC of ITEM in DATA, or sets LOC := 0 if the search is unsuccessful.


1. [Insert ITEM at the end of DATA.] Set DATA[N + 1] := ITEM.
2. [Initialize counter.] Set LOC := 1.
3. [Search for ITEM.]
Repeat while DATA[LOC] ≠ ITEM:
Set LOC := LOC + 1.
[End of loop.]
4. [Successful?] If LOC = N + 1, then: Set LOC := 0.
5. Exit.
*/
#include<iostream>
using namespace std;
int Global_J;
/**************Print Array****************/
template<typename T>
void PRINT(T A[], int j)
{
    cout << "\n**************************\n";
    for(int i = 1; i <= j; i++)
    {
        cout << A[i-1] << " ";
        if(i % 4 == 0)
        cout << "\n";
    }
}

/************Insert***********************/
template<typename T>
void INSERT(T LA[],int N, int K, T ITEM)
{
    int J = N;
    while(J >= K)
    {
        LA[J+1] = LA[J];
        J--;
    }
    LA[K] = ITEM;
    Global_J++;
}
/************Bubble Sort******************/
template<typename T>
void Bubble(T DATA[], int N)
{
    T CHANGE;
    for(int K = 0; K < N; K++)
    {
        for(int PTR = 0; PTR < N - K; PTR++)
        {
            if(DATA[PTR]> DATA[PTR+1])
            {
                CHANGE = DATA[PTR];
                DATA[PTR] = DATA[PTR+1];
                DATA[PTR+1] = CHANGE;
            }
        }
    }
    return;
}
/****************Linear Search*********************/
template<typename T>
int LINEAR(T DATA[], int N, T ITEM)
{
    int K = 0;
    int LOC = -1;
    while(LOC == -1 && K <= N)
    {
        if(ITEM == DATA[K])
            LOC = K ;
        K++;
    }
    if(LOC == -1)
    {
       INSERT<T>(DATA,N,N,ITEM);
    }
    return LOC+1;
}
/***********Input Array****************/
template<typename T>
void INPUT(T DATA[], int j)
{

    for(int i = 0; i < j; i++)
    {
        cin >> DATA[i];
    }
}
/**************Check LOC *****************/
void CHECK(int ck)
{
    if(ck != 0)
    {
        cout << "\nItem Found at " << ck  << endl;
    }
    else 
    cout << "\nItem not found item was added at the end of array\n";
}
/*************Main Function ************/
int main()
{
    Global_J = 52;
    int A[Global_J], ITEM, ck;
    INPUT(A, Global_J);
    PRINT<int>(A,Global_J);
    cout << "Enter your key \n";
    cin >> ITEM;
    ck = LINEAR(A,Global_J,ITEM);
    CHECK(ck);
    PRINT<int>(A,Global_J);
    ck = LINEAR(A,Global_J,ITEM);
    CHECK(ck);


}
/*
331 222 902 679
911 275 9 457  
857 253 851 222
364 158 66 748
652 359 393 467
657 852 414 866
891 161 629 149
119 20 963 929
442 370 486 219
666 582 19 270
405 15 423 683
772 802 954 806
904 536 449 214

**************************
331 222 902 679
911 275 9 457
857 253 851 222
364 158 66 748
652 359 393 467
657 852 414 866
891 161 629 149
119 20 963 929
442 370 486 219 
666 582 19 270
405 15 423 683
772 802 954 806
904 536 449 214
Enter your key
777777

Item not found item was added at the end of array

**************************
331 222 902 679
911 275 9 457
857 253 851 222
364 158 66 748
652 359 393 467
657 852 414 866
891 161 629 149
119 20 963 929
442 370 486 219
666 582 19 270
405 15 423 683
772 802 954 806
904 536 449 214
777777
Item Found at 53
*/
#include<iostream>
using namespace std;
template<typename T>
void PRINT(T A[], int j)
{
    cout << "\n**************************\n";
    for(int i = 0; i < j; i++)
    {
        cout << A[i] << " ";
    }
}
void Bubble(int DATA[], int N)
{
    int CHANGE;
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
int main()
{
    int j = 52;
    int A[j];
    for(int i = 0; i < j; i++)
    {
        cin >> A[i];
    }
    PRINT<int>(A,j);
    Bubble(A,j);
    PRINT<int>(A,j);

}
/*
331 
222 902 679 911
275 9 457 857
253 851 222 364
158 66 748 652
359 393 467 657 
852 414 866 891
161 629 149 119
20 963 929 442
370 486 219 666
582 19 270 405
15 423 683 772
802 954 806 904
536 449 214

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
**************************
9 15 19 20 66 119 149 158 161 214 219 222 222 253 270 
275 331 359 364 370 393 405 414 423 442 449 457 467 
486 536 582 629 652 657 666 679 683 748 772 802 806 
851 852 857 866 891 902 904 911 929 954 963

*/
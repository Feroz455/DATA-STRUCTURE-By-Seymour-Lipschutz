/*
PAGE 213
6.25 Consider the priority queue in Fig. 6.36(b), which is maintained by a
 two-dimensional array QUEUE.

(a) Describe the structure if two elements are deleted.

(b) Describe the structure if, after the preceding deletions, the elements 
(JJJ, 3), (KKK, 1), (LLL, 4) and (MMM, 5) are added to the queue.

(c) Describe the structure if, after the preceding insertions, six elements are deleted.
*/
#include<iostream>
#include<ctime>
#include<string>
using namespace std;
template<typename T>
void INSPQA(T A[][6],int FRONT[], int REAR[], T ITEM, int M)
{
    M = M -1 ;
    if(FRONT[M] == 0 && REAR[M] == 5)
    {
        cout << "OVERFLOW\n";
        return;
    }
    if(FRONT[M] == -1)
    {
        FRONT[M] = 0;
        REAR[M] = 0;
    }
    else
    if(REAR[M] == 5)
    {
        REAR = 0;
    }
    else
    REAR[M] = REAR[M] + 1;
    A[M][REAR[M]] = ITEM;
    return;
}
template<typename T>
int DELPQA(T A[][6],int FRONT[], int REAR[], T &ITEM, int X)
{
    int i = 0;
    while((FRONT[i]==-1) && (i < X))
    {
        if((i == X-1) && FRONT[i] == -1)
        {
            cout << "UNDERFLOW\n";
            return 0;
        }

        i = i + 1;
    }
    ITEM = A[i][FRONT[i]];
    if(FRONT[i] == REAR[i])
    {
        FRONT[i] = -1;
        REAR[i] = -1;
    }
    else 
    if(FRONT[i] == 5)
    {
        FRONT[i] = 0;
    }
    else 
    FRONT[i] = FRONT[i]+1;
    return 1;
}
int main()
{
    srand(time(0));
    int x = 5, y = 6, FRONT[x], REAR[x],M;
    string PQUE[x][6], ITEM;
    for(int i = 0 ; i < x; i++)
    {
        FRONT[i] = -1;
        REAR[i] = -1;
    } 
    cout << "ENTER ITEM NAME AND PARITY\n";
    for(int i = 0; i < 11; i++)
    {
        cin >> ITEM;
        cin >> M;
        INSPQA<string>(PQUE, FRONT, REAR, ITEM, M);
    }
    for(int i = 0; i < 11; i++)
    {
        if( DELPQA<string>(PQUE, FRONT, REAR, ITEM, x))
        cout << ITEM << " ";
    }
    cout << endl;

    
}
/*
ENTER ITEM NAME AND PARITY
BBB 2
XXX 2
DDD 4
EEE 4
AAA 1
CCC 2
YYY 3
GGG 5
FFF 4
ZZZ 2
WWW 1
JJJ 3
*/

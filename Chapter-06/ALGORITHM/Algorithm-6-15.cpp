/*
page 196
Algorithm 6.19: This algorithm deletes and processes the first element 
in a priority queue maintained by a two-dimensional array QUEUE.

1. [Find the first nonempty queue.]
Find the smallest K such that FRONT[K] ≠ NULL.

2. Delete and process the front element in row K of QUEUE.

3. Exit.
*/
#include<iostream>
#include<ctime>
using namespace std;
void INSPQA(int A[][6],int FRONT[], int REAR[], int ITEM, int M)
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
int DELPQA(int A[][6],int FRONT[], int REAR[], int &ITEM, int M)
{
    int i = 0;
    while((FRONT[i]==-1) && (i < M))
    {
        if((i == M-1) && FRONT[i] == -1)
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
    int x = 5, y = 6, FRONT[x], REAR[x],M, ITEM;
    int PQUE[x][6];
    for(int i = 0 ; i < x; i++)
    {
        FRONT[i] = -1;
        REAR[i] = -1;
    }

    ITEM = 100, M = 1;
    INSPQA(PQUE,FRONT, REAR, ITEM, M);
    if(DELPQA(PQUE,FRONT, REAR, ITEM, M))
    cout << ITEM << endl;  
}
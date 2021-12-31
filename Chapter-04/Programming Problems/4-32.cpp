/*
Page  110
Program 
rch algorithm into a subprogram LINEAR(ARRAY, LB, UB, ITEM, LOC) 
which either finds the location LOC where ITEM appears in ARRAY or returns LOC = 0.
*/
#include<iostream>
#include<string>
using namespace std;
/****************Linear Search*********************/
template<typename T>
int LINEAR(T DATA[],int LB, int UB, T ITEM)
{
    int K = LB;
    int LOC = -1;
    while(LOC == -1 && K <= UB)
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
//Main from Here
int main()
{

}

/*
Output

*/
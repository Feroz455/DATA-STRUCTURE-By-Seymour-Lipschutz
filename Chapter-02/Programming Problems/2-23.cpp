/*
Page 40
Program
 Write a function subprogram DIV(J, K), where J and K are 
 positive integers such that DIV(J, K) = 1 if J divides K 
 but otherwise DIV(J, K) = 0. (For example, DIV(3, 15) = 1 
 but DIV(3, 16) = 0.)

*/
#include<iostream>
using namespace std;

template<typename T>
T DIV(T J, T K)
{
    if(K % J== 0)
    return 1;
    else
    return 0;
}

//main begin

int main()
{
    cout <<  DIV<int>(3,15) << endl;
    cout <<  DIV<int>(3,16) << endl;
    getchar();
    return 0;
}
//main end
///Program end

/*
output
*/
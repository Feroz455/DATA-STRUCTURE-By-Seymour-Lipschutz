/*
Page 39
Program
Find (a) 3^−4, 4^7/2, 27^2/3; (b) log2 64, log10 0.001, log2 (1/8); (c)floor(log 1000000), floor(log 0.001). 

*/
#include<iostream>
#include<cmath>
using namespace std;

template<typename T>
T Power(T x, T y)
{
    if(y < 0)
    {
        y = y*(-1);
        return (1/pow(x,y));
    }
    else 
    {
        return (pow(x,y));  
    }
}
template<typename T>
T Power(T x, T y, T z)
{
    T temp;
    if(y < 0)
    {
        temp = (-1*y) / z;
        return (1/(pow(x,temp)));
    }
    else
    {
        temp = y / z;
        return (pow(x,temp));
    }
}

//main begin
int main()
{
    //(a) 3^−4, 4^7/2, 27^2/3;
    cout << "3^-4      = " << Power<float>(3.0, -4.0) << endl;
    cout << "4^7/2     = " << Power<float>(4,7,2) << endl;
    cout << "27^(-2/3) = " << Power<float>(27,-2,3) << endl;
   
    //(b) log2 64, log10 0.001, log2 (1/8);

    cout << "log2 64     = " <<log2(64) << endl;
    cout << "Log10 0.001 = " << log10(0.001) << endl;
    cout << "Log2 (1/8)  = " << log2(1.0/8.0) << endl; 

    //(c)floor(log 1000000), floor(log 0.001)
    cout << "floor(log 1000000) = " << floor(log2 (1000000)) << endl;
    cout << "floor(log 0.001) = " << floor(log2 (0.001)) << endl;

    return 0;
}
//main end
///Program end

/*
output
3^-4      = 0.0123457  
4^7/2     = 128        
27^(-2/3) = 0.111111   
log2 64     = 6        
Log10 0.001 = -3       
Log2 (1/8)  = -3       
floor(log 1000000) = 19
floor(log 0.001) = -10 

*/
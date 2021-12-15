/*
page 39
Program
Find
(a) |3 + 8|, |3 − 8|, |−3 + 8|, |−3−8|;
(b) 7!, 8!, 14!/12!, 15!/16!,
*/
#include<iostream>
using namespace std;
template<typename T>
T fact(T x, T y = 0.0);
int absoluteValue(int x, int y)
{
    int temp = x = y;
    if(temp < 0)
    return(temp*(-1));
    else
    return (temp);
}
template<typename T>
T fact(T x, T y)
{
    if(x == y)
    return 1;
    else
    return(x*fact(x-1,y));
}
template<typename T>
T factDc(T  x, T y)
{
    if(x < y)
    {
        return (1/fact<T>(y,x));
    }
    else
    return(fact<T>(x,y));
}
//main begin
int main()
{
    //a) |3 + 8|, |3 − 8|, |−3 + 8|, |−3−8|;
    cout << "|3 + 8| = " << absoluteValue(3,4) << endl;
    cout << "|3 - 8| = " << absoluteValue(3,-8) << endl;
    cout << "|3 + 8| = "  << absoluteValue(-3,8) <<endl;
    cout << "|-3 -8| = " << absoluteValue(-3,-8) << endl;

   // (b) 7!, 8!, 14!/12!, 15!/16!
    cout << "7! = " << fact<int>(7) << endl;
    cout << "8! = " << fact<int>(8) << endl;
    cout << "14! / 12! = " << factDc<int>(14,12) <<endl;
    cout << "15! / 16! = " << factDc<float>(15.0,16.0) << endl;


    getchar();
    return 0;
}
//main end
///Program end

/*
output
int fact(int x)
{
    if(x == 0)
    {
        return (1);
    }
    else
    return(x*fact(x-1));
}

|3 + 8| = 4
|3 - 8| = 8
|3 + 8| = 8
|-3 -8| = 8
7! = 5040
8! = 40320
14! / 12! = 182
15! / 16! = 0.0625
*/

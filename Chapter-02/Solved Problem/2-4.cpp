/*
page 34
Program
2.4 Find: (a) 2^-5, 8^(2/3), 25^(−3/2); (b)log2 32, log10 (1000), log2 (1/16); (c) log2 (1000), log2 (0.01). 

*/
#include<iostream>
#include<cmath>
using namespace std;

//main begin
int main()
{
    //((a) 2^-5) ,8^(2/3), 25^(−3/2);
    cout << pow(2,(-5)) << endl;
    cout << 1/pow(2,5) << endl;
    cout << pow((cbrt(8)),2) << endl;
    cout << float(1/125) << endl;
    cout << "*********************************\n";
    cout << log2(32) << endl;
    cout << log10(1000) << endl;
    cout << log2(1/16) << endl;

    cout << "*********************************\n";
    cout << floor(log2(1000)) << endl;
    cout << floor(log2(0.01)) << endl;

    return 0;
}
//main end
///Program end

/*
output
*/
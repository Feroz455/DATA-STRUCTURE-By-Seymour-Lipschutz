/*
Page 33
Program
2.2 (a) Find 26 (mod 7), 34 (mod 8), 2345 (mod 6), 495 (mod 11).
(b) Find −26 (mod 7), −2345 (mod 6), −371 (mod 8), −39 (mod 3).
(c) Using arithmetic modulo 15, evaluate 9 + 13, 7 + 11, 4 − 9, 2 − 10. 
*/
#include<iostream>
using namespace std;
//main begin
int main()
{
    //(a) Find 26 (mod 7), 34 (mod 8), 2345 (mod 6), 495 (mod 11).
    cout << "26 (mod 7) " << 26 % 7 << endl;
    cout << "34 (mod 8) " << 34 % 8 << endl;
    cout << "2345 (mod 6)" << 2345 % 6 << endl;
    cout << "495 (mod 11) " << 495 % 11 << endl;

    cout << "******************************\n";
    //(b) Find −26 (mod 7), −2345 (mod 6), −371 (mod 8), −39 (mod 3).
    cout << "-26 (mod 7) " << ((-26) % 7)+7  << endl;
    cout << "-2345 (mod 6) " << ((-2345)%6)+6 << endl;
    cout << "-371 (mod 8)" << ((-371)%8) + 8<< endl;
    cout << "-39 (mod 3) " << (-39) % 3 << endl;
    cout << "*******************************\n";
    //(c) Using arithmetic modulo 15, evaluate 9 + 13, 7 + 11, 4 − 9, 2 − 10.

    cout << "9 + 13 = " << ( 9 + 13 )  << " # " << ( 9 + 13 ) - 15  << endl;
    cout << "7 + 11 = " << (7+11) << " # " << (7+11) - 15  << endl;
    cout << "4 - 9 = " << (4-9) << " # " << (4-9) + 15  << endl;
    cout << "2 - 10 = " << ( 2 - 10) << " # " << (4-9) + 15 << endl;

    
    return 0;
}
//main end
///Program end

/*
output
26 (mod 7) 5
34 (mod 8) 2
2345 (mod 6)5
495 (mod 11) 0
******************************
-26 (mod 7) 2
-2345 (mod 6) 1
-371 (mod 8)5
-39 (mod 3) 0
*******************************
9 + 13 = 22 # 7
7 + 11 = 18 # 3
4 - 9 = -5 # 10
2 - 10 = -8 # 10
*/
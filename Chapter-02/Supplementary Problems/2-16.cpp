/*
Page 39
Program 
2.2 (a) Find 48 (mod 5), 48 (mod 7), 1397 (mod 11), 2468 (mod 9).

(b) Find –48 (mod 5), –152 (mod 7), –358 (mod 11), –1326 (mod 13).

(c) Using arithmetic modulo 13, evaluate

9 + 10,  8 + 12,  3 + 4  3 − 4,  2 −7,  5 − 8
*/
#include<iostream>
using namespace std;

int findMod(int x, int y)
{
    int temp;
    if(x > 0)
    {
        return (x % y);
    }
    else 
    {
    temp = x % y;
    if(temp == 0)
    return 0;
    else 
    return (temp+y);
    }
}
int findMod(int x, int y, int z)
{
    int temp;
    temp = x + y;
    if(temp > 0)
    {
        return (temp-z);
    }
    else 
    {
        return(temp + z);
    }
}

//main begin
int main()
{
    //(a) Find 48 (mod 5), 48 (mod 7), 1397 (mod 11), 2468 (mod 9)
    cout << "48 (mod 5) = " << findMod(48,5) << endl;
    cout << "48 (mod 7) = " << findMod(48,7) << endl;
    cout << "1397 (mod 11) = " << findMod(1397,11) << endl;

    //(b) Find –48 (mod 5), –152 (mod 7), –358 (mod 11), –1326 (mod 13)
    cout << "-48 (mod 5) = " << findMod(-48,5) << endl;
    cout << "-152 (mod 7) = " << findMod(-152,7) << endl;
    cout << "-358 (mod 11) = " << findMod(-358, 11) << endl;
    cout << "-1326 (mod 13) = " << findMod(-1326,13) << endl;

    /*
    Using arithmetic modulo 13, evaluate

    9 + 10,  8 + 12,  3 + 4  3 − 4,  2 −7,  5 − 8
    */
    cout << "9 + 10 " << "mod 13 = "  << findMod(9,10,13)<<endl;
    cout << "8 + 12 " << "mod 13 = "  << findMod(8,12,13)<<endl;
    cout << "3 + 4 " << "mod 13 = "  << findMod(3,4,13)<<endl;
    cout << "3 - 4 " << "mod 13 = "  << findMod(3,-4,13)<<endl;
    cout << "2 - 7 "  <<  "mod 13 = "  << findMod(2,-7,13)<<endl;
    cout << "5 - 8 " << "mod 13 = "  << findMod(5,-8,13)<<endl;
    getchar();
    return 0;
}
//main end
///Program end

/*
output
48 (mod 5) = 3
48 (mod 7) = 6
1397 (mod 11) = 0
-48 (mod 5) = 2
-152 (mod 7) = 2
-358 (mod 11) = 5
-1326 (mod 13) = 0
9 + 10 mod 13 = 6
8 + 12 mod 13 = 7
3 + 4 mod 13 = -6
3 - 4 mod 13 = 12
2 - 7 mod 13 = 8
5 - 8 mod 13 = 10


*/
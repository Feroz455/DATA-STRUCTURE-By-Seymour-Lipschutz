/*
Page 39
Program 
2.1 Find (a)floor (3.4),floor(–3.4), floor(–7),floor(sqrt(75)) ,floor(cbrt(75)) , floor(e);
(b) ceil(3.4), ceil(–3.4), ceil(–7),ceil(sqrt(75)) ,ceil(cbrt(75)) ,ceil(e);
*/
#include<iostream>
#include<cmath>
using namespace std;

//main begin
int main()
{
    cout << "floor (3.4) = " <<      floor (3.4) << endl;
    cout << "floor(-3.4) = " <<      floor(-3.4) << endl;
    cout << "floor(-7) = "  <<       floor(-7) << endl;
    cout << "floor(sqrt(75)) = " <<  floor(sqrt(75)) << endl;
    cout << "floor(cbrt(75)) = "  << floor(cbrt(75)) << endl;
    cout << "floor(e)=  " <<         floor(exp(1.0)) << endl;


    cout << "\n*****************\n";
    cout << "ceil (3.4) = " <<      ceil(3.4) << endl;
    cout << "ceil(-3.4) = " <<      ceil(-3.4) << endl;
    cout << "ceil(-7) = "  <<       ceil(-7) << endl;
    cout << "ceil(sqrt(75)) = " <<  ceil(sqrt(75)) << endl;
    cout << "ceil(cbrt(75)) = "  << ceil(cbrt(75)) << endl;
    cout << "ceil(e)=  " <<         ceil(exp(1.0));
    return 0;
}
//maiceil
///Program end

/*
output
floor (3.4) = 3    
floor(-3.4) = -4   
floor(-7) = -7     
floor(sqrt(75)) = 8
floor(cbrt(75)) = 4
floor(e)=  2       

*****************  
ceil (3.4) = 4     
ceil(-3.4) = -3    
ceil(-7) = -7
ceil(sqrt(75)) = 9
ceil(cbrt(75)) = 5
ceil(e)=  3
*/
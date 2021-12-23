/*
Let W be the string ABCD. 
(a) Find the length of W. 
(b) List all substrings of W. 
(c) List all the initial substrings of W.
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string W, R;
    cout << "Enter your String \n";
    cin >> W;
    //(a) Find the length of W. 
    cout << "Length of String = " << W.length() << endl;

    int k = W.length();
    //(b) List all substrings of W. 
    cout << "(b) List all substrings of W.\n";
    for(int i = 0; i <= W.length(); i++,k--)
    {
        for(int j = 0; j <= i; j++)
        {
                R = W.substr(j,k);
                cout << R << " " ;
        }
        cout << "\n";
    }
    k = W.length();
    //(c) List all the initial substrings of W.
    cout << "(c)List all the initial substrings of W\n";
    for(int i = 0; i <= W.length(); i++,k--)
    {
        for(int j = 0; j < 1; j++)
        {
                R = W.substr(j,k);
                cout << R << " " ;
        }
        cout << "\n";
    }
    //
    return 0;
}
/*
Enter your String 
Bangladesh
Length of String = 10        
(b) List all substrings of W.
Bangladesh
Banglades angladesh
Banglade anglades ngladesh   
Banglad anglade nglades gladesh
Bangla anglad nglade glades ladesh
Bangl angla nglad glade lades adesh
Bang angl ngla glad lade ades desh
Ban ang ngl gla lad ade des esh
Ba an ng gl la ad de es sh
B a n g l a d e s h

(c)List all the initial substrings of W
Bangladesh
Banglades
Banglade
Banglad
Bangla
Bangl
Bang
Ban
Ba
B
*/
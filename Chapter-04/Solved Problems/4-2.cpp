/*
Page 99
Program 4.2
4.2 Suppose a company keeps a linear array YEAR(1920 : 1970) 
such that YEAR[K] contains the number of employees born in year
K. Write a module for each of the following tasks:

(a)To print each of the years in which no employee was born.

(b) To find the number NNN of years in which no employee was born.

(c) To find the number N50 of employees who will be at least 50 
years old at the end of the year. (Assume 1984 is the current year.)

(d)To find the number NL of employees who will be at least 
L years old at the end of the year. (Assume 1984 is the current year.

*/
#include<iostream>
#include<iomanip>
using namespace std;
using namespace std;
int COUNT(int AUTO[], int UB, int LB)
{
    int NUM = 0;
    for(int i = LB, j = LB; i < UB; i++)
    {
        if( AUTO[i-j] == 0)
        {
            cout<< "\nIn " <<   i << "  No Employee Born\n";
            NUM++;
        }
     
    }
    return NUM;
}
int COUNT_EM(int AUTO[], int UB, int LB)
{
    int NUM = 0;
    for(int i = LB, j = LB; i < UB; i++)
    {
      NUM += AUTO[i-j];
    // cout  << AUTO[i-j] << endl;
     
    }
    cout << NUM << endl;
    return NUM;
}
//Print Array 
void PRINT(int AUTO[], int UB, int LB)
{
    for(int i = LB, j = LB; i < UB; i++)
    {
        cout<< "In " << i << " Employee born  " << AUTO[i-j] << endl;
    }
}
//Main from Here
int main()
{
    int UB =  1970, LB = 1920;
    int YEAR[UB - LB];
    for(int i = LB, j = LB; i < UB; i++)
    {
        cin >> YEAR[i-j];
    }
    //a
    int NNN =  COUNT(YEAR,UB, LB);
    //b
    cout << "\n****No employee born in  " << NNN << " years***\n" << endl;
    PRINT(YEAR,UB, LB);
    //c
    int N50 = COUNT_EM(YEAR,1934,1920);
    cout << "Employee born in 1934 or earlier " << N50 << endl;
    //d
    int L = 20;
    int NL = COUNT_EM(YEAR,1984-L,1920);
    cout << "Employee born in " <<  1984 << " - " <<  L  << " or earlier " << NL << endl;
    return 0;
}

/*
Output
9 0 4 6 
6 7 3 8 
2 8 4 5 
5 5 7 7 
1 7 0 1 
7 6 2 9 
8 2 7 0 
8 2 5 7 
2 1 4 2 
6 0 4 6 
7 3 9 3 
5 3 0 7 
8 7     

In 1921  No Employee Born

In 1938  No Employee Born

In 1947  No Employee Born

In 1957  No Employee Born

In 1966  No Employee Born

****No employee born in  5 years***

In 1920 Employee born  9
In 1921 Employee born  0
In 1922 Employee born  4
In 1923 Employee born  6
In 1924 Employee born  6
In 1925 Employee born  7
In 1926 Employee born  3
In 1927 Employee born  8
In 1928 Employee born  2
In 1929 Employee born  8
In 1930 Employee born  4
In 1931 Employee born  5
In 1932 Employee born  5
In 1933 Employee born  5
In 1934 Employee born  7
In 1935 Employee born  7
In 1936 Employee born  1
In 1937 Employee born  7
In 1938 Employee born  0
In 1939 Employee born  1
In 1940 Employee born  7
In 1941 Employee born  6
In 1942 Employee born  2
In 1943 Employee born  9
In 1944 Employee born  8
In 1945 Employee born  2
In 1946 Employee born  7
In 1947 Employee born  0
In 1948 Employee born  8
In 1949 Employee born  2
In 1950 Employee born  5
In 1951 Employee born  7
In 1952 Employee born  2
In 1953 Employee born  1
In 1954 Employee born  4
In 1955 Employee born  2
In 1956 Employee born  6
In 1957 Employee born  0
In 1958 Employee born  4
In 1959 Employee born  6
In 1960 Employee born  7
In 1961 Employee born  3
In 1962 Employee born  9
In 1963 Employee born  3
In 1964 Employee born  5
In 1965 Employee born  3
In 1966 Employee born  0
In 1967 Employee born  7
In 1968 Employee born  8
In 1969 Employee born  7
72
Employee born in 1934 or earlier 72
205
Employee born in 1984 - 20 or earlier 205
*/
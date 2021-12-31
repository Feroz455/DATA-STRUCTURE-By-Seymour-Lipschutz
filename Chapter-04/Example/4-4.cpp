/*
page 
program
Example 4.4
Example 4.4

Consider the array AUTO in Example 4.1(b), which records the number of automobiles 
sold each year from 1932 through 1984. Each of the following modules, which carry 
out the given operation, involves traversing AUTO.

(a) Find the number NUM of years during which more than 300 automobiles were sold.

1. [Initialization step.] Set NUM := 0.

2. Repeat for K = 1932 to 1984:

If AUTO[K] > 300, then: Set NUM := NUM + 1.

[End of loop.]

3. Return.





(b) Print each year and the number of automobiles sold in that year.

1. Repeat for K = 1932 to 1984:

Write: K, AUTO[K].

[End of loop.]

2. Return.

(Observe that (a) requires an initialization step for the variable NUM before traversing the array AUTO.)
*/
#include<iostream>
using namespace std;
int SOLD(int AUTO[], int UB, int LB)
{
    int NUM = 0;
    for(int i = LB, j = LB; i < UB; i++)
    {
        if( AUTO[i-j] > 300)
        NUM++;
    }
    return NUM;
}
void PRINT(int AUTO[], int UB, int LB)
{
    for(int i = LB, j = LB; i < UB; i++)
    {
        cout<< "In " << i << " Auto mobiles sold  " << AUTO[i-j] << endl;
    }
}
int main()
{
    int UB =  1984, LB = 1932;
    int AUTO[UB - LB];
    for(int i = LB, j = LB; i < UB; i++)
    {
        cin >> AUTO[i-j];
    }
    cout << "In " << SOLD(AUTO,UB, LB) << " years  Auto mobiles sold more then 300+" << endl;
    PRINT(AUTO,UB, LB);
    return 0;
}
/*
output
331 
222 902 679 911 
275 9 457 857   
253 851 222 364 
158 66 748 652  
359 393 467 657 
852 414 866 891 
161 629 149 119
20 963 929 442 
370 486 219 666
582 19 270 405 
15 423 683 772 
802 954 806 904
536 449 214
In 36 years  Auto mobiles sold more then 300+
In 1932 Auto mobiles sold  331
In 1933 Auto mobiles sold  222
In 1934 Auto mobiles sold  902
In 1935 Auto mobiles sold  679
In 1936 Auto mobiles sold  911
In 1937 Auto mobiles sold  275
In 1938 Auto mobiles sold  9
In 1939 Auto mobiles sold  457
In 1940 Auto mobiles sold  857
In 1941 Auto mobiles sold  253
In 1942 Auto mobiles sold  851
In 1943 Auto mobiles sold  222
In 1944 Auto mobiles sold  364
In 1945 Auto mobiles sold  158
In 1946 Auto mobiles sold  66
In 1947 Auto mobiles sold  748
In 1948 Auto mobiles sold  652
In 1949 Auto mobiles sold  359
In 1950 Auto mobiles sold  393
In 1951 Auto mobiles sold  467
In 1952 Auto mobiles sold  657
In 1953 Auto mobiles sold  852
In 1954 Auto mobiles sold  414
In 1955 Auto mobiles sold  866
In 1956 Auto mobiles sold  891
In 1957 Auto mobiles sold  161
In 1958 Auto mobiles sold  629
In 1959 Auto mobiles sold  149
In 1960 Auto mobiles sold  119
In 1961 Auto mobiles sold  20
In 1962 Auto mobiles sold  963
In 1963 Auto mobiles sold  929
In 1964 Auto mobiles sold  442
In 1965 Auto mobiles sold  370
In 1966 Auto mobiles sold  486
In 1967 Auto mobiles sold  219
In 1968 Auto mobiles sold  666
In 1969 Auto mobiles sold  582
In 1970 Auto mobiles sold  19
In 1971 Auto mobiles sold  270
In 1972 Auto mobiles sold  405
In 1973 Auto mobiles sold  15
In 1974 Auto mobiles sold  423
In 1975 Auto mobiles sold  683
In 1976 Auto mobiles sold  772
In 1977 Auto mobiles sold  802
In 1978 Auto mobiles sold  954
In 1979 Auto mobiles sold  806
In 1980 Auto mobiles sold  904
In 1981 Auto mobiles sold  536
In 1982 Auto mobiles sold  449
In 1983 Auto mobiles sold  214
*/
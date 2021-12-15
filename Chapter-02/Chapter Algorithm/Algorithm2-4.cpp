/*
Page 28
Algorithm 2.4
Suppose a linear array DATA contains n 
elements, and suppose a specific ITEM of 
information is given. We want either to 
find the location LOC of ITEM in the array 
DATA, or to send some message, such as LOC = 0, 
to indicate that ITEM does not appear in DATA. 
The linear search algorithm solves this problem 
by comparing ITEM, one by one, with each element 
in DATA. That is, we compare ITEM with DATA[1], 
then DATA[2], and so on, until we find LOC such 
that ITEM = DATA[LOC]. A formal presentation of
this algorithm follows.

*/
/*
Algorithm 
Algorithm 2.4: (Linear Search) A linear array DATA 
with N elements and a specific ITEM of information 
are given. This algorithm finds the location LOC of 
ITEM in the array DATA or sets LOC = O.

1. [Initialize] Set K := 1 and LOC := 0.
2. Repeat Steps 3 and 4 while LOC = 0 and K ≤ N.
3. If ITEM = DATA[K], then: Set LOC: = K.
4. Set K := K + 1. [Increments counter.]
[End of Step 2 loop.]
5. [Successful?]
If LOC = 0, then:
Write: ITEM is not in the array DATA.
Else:
Write: LOC is the location of ITEM.
[End of If structure.]
6. Exit.
*/

#include<iostream>
using namespace std;

//main begin
int main()
{
    int K, LOC, N, ITEM;
    K = 0;
    LOC = -1;
    N = 5;
    int DATA[N] = {22,33,44,55,66};
    cout << "Enter Search Key\n";
    cin >> ITEM;
    while(LOC == -1 && K <= N)
    {
        if(ITEM == DATA[K])
            LOC = K ;
        K++;
    }
    if (LOC == -1)
    {
        cout << "ITEM in not in the array DATA" << endl;
    }
    else
    {
         cout << LOC + 1 << " is the location of " << ITEM << endl;
    }
 
    getchar();
    return 0;
}
//main end
///Program end

/*
output
-----First Run------- 
Enter Search Key
77
ITEM in not in the array DATA
-----Second RUN --------
Enter Search Key
55
4 is the location of 55

*/
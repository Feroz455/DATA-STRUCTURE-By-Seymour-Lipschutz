/*

Chapter 2
Page 21

Algorithm 2.1: (Largest Element in Array) A nonempty array DATA with N numerical values is given.
 This algorithm finds the location LOC and the value MAX of the largest element of DATA. 
 The variable K is used as a counter.

Step 1. [Initialize.] Set K : = 1, LOC : = 1 and MAX : = DATA[1].

Step 2. [Increment counter.] Set K : = K + 1.

Step 3. [Test counter.] If K > N, then:

Write: LOC, MAX, and Exit.

Step 4. [Compare and update.] If MAX < DATA[K], then:

Set LOC : = K and MAX : = DATA[K].

Step 5. [Repeat loop.] Go to Step 2
*/

#include<iostream>
using namespace std;
int main()
{
    int K , LOC, MAX, N;    // Declaring Variable K< LOC , N and MAX
    N = 5;                  // Initialize N = 5 
    int DATA[N] = { 45, 18, 65 ,78,14};  // Declar and Initialize at the same time
    
    LOC = 0;                //Initialize LOC = 0 .. or First Position
    MAX = DATA[0];          //Initialize MAX == DATA[0] Or First Data int Data Array 
                            // Checking conditon if Number of comprison is greater
    while (K < N)           // then Number of Data in Data Array then break the loop
   {
       K++;
       if(MAX < DATA[K])    // If MAX is less then DATA[K] Then Update MAX Value and Also LOC value
       {
           LOC = K; 
           MAX = DATA[K];
       }
   }
   cout << "LOC " << LOC + 1 << " MAX " <<  MAX <<  endl;
   return 0;
}
//main end
///Program end

/*
output
LOC 4 MAX 78
*/
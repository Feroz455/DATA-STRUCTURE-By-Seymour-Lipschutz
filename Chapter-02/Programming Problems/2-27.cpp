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


****************************************
Let C denote the number of times LOC is updated using Algorithm 2.3 to find the 
largest element in an array A with N elements.

(a) Write a subprogram COUNT(A, N, C) which finds C.

(b) Write a Procedure P2.27 which (i) reads N random numbers between 0 and 1 into 
an array A and (ii) uses COUNT(A, N, C) to find the value of C.

(c) Write a program which repeats Procedure P2.27 1000 times and finds the average 
of the 1000 C’s.

(i) Test the program for N = 3 and compare the result with the value obtained in 
Solved Problem 2.6.

(ii) Test the program for N = 4 and compare the result with the value in Supplementary Problem 2.5
*/

#include<iostream>
using namespace std;
template<typename T>
int COUNT(T A[],int N, int C)
{
    int K, LOC, MAX;
    LOC = 0;
    MAX = A[0];
    while(K < N)
    {
         K++;
       if(MAX < A[K])    // If MAX is less then DATA[K] Then Update MAX Value and Also LOC value
       {
           LOC = K; 
           MAX = A[K];
           C++;
       }
    }
    return C;

}
template<typename T>
int MAX(T A[], int N)
{
    int  K, LOC = 0;                //Initialize LOC = 0 .. or First Position
    int M = A[0];          //Initialize MAX == DATA[0] Or First Data int Data Array 
                            // Checking conditon if Number of comprison is greater
    while (K < N)           // then Number of Data in Data Array then break the loop
   {
       K++;
       if(M < A[K])    // If MAX is less then DATA[K] Then Update MAX Value and Also LOC value
       {
           LOC = K; 
           M = A[K];
       }
   }
    cout << "LOC " << LOC + 1 << " MAX " <<  M <<  endl;
   return LOC;
}

int main()
{         
    int N;
    float  DATA[100];
    N  = 10;
    cout << "Enter 5 floating number from  0 to 1\n";
    for(int i = 0; i < N ; i++)
    {
        cin >> DATA[i];
    }
   cout << "Number of time COUNT Updates are " <<   COUNT<float>(DATA, N, 0) << endl;
   return 0;
}
//main end
///Program end

/*
output
LOC 4 MAX 78



Enter 5 floating number from  0 to 1
.01
.5
.1
0.2
0.3
0.5
0.7
0.985
0.254
0.12356
Number of time COUNT Updates are 10
*/
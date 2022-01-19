/*
6.18 Let A be an integer array with N elements. Suppose X is an integer function defined by

                    0                   if(K = 0)
X(K) = X(A, N, k) = X(K - 1)+A(K)       if (0 < K && k <= N)
                    X(K - 1)            if(K > N)

Find X(5) for each of the following arrays:

(a) N = 8, A: 3, 7, –2, 5, 6, –4, 2, 7 (b) N = 3, A: 2, 7, –4

What does this function do?

*/
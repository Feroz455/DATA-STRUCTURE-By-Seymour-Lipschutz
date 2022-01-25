/*
page 229
Algorithm 7.3: POSTORD(INFO, LEFT, RIGHT, ROOT)

A binary tree T is in memory. This algorithm does a postorder traversal of T, applying an operation PROCESS to each of its nodes. An array STACK is used to temporarily hold the addresses of nodes.

1. [Push NULL onto STACK and initialize PTR.]
Set TOP := 1, STACK[1] := NULL and PTR := ROOT.

2. [Push left-most path onto STACK.]
Repeat Steps 3 to 5 while PTR ≠ NULL:

3.    Set TOP := TOP + 1 and STACK[TOP] := PTR.
   [Pushes PTR on STACK.]

4.    If RIGHT[PTR] ≠ NULL, then: [Push on STACK.]
   Set TOP := TOP + 1 and STACK[TOP] := –RIGHT[PTR].
   [End of If structure.]

5.    Set PTR := LEFT[PTR]. [Updates pointer PTR.]
   [End of Step 2 loop.]

6.    Set PTR := STACK[TOP] and TOP := TOP – 1.
   [Pops node from STACK,]

7. Repeat while PTR > 0:

  (a)   Apply PROCESS to INFO[PTR].

  (b)   Set PTR := STACK[TOP] and TOP := TOP – 1.
   [Pops node from STACK.]
   [End of loop.]

8. If PTR < 0, then:

  (a)   Set PTR := –PTR.

  (b)   Go to Step 2.
   [End of If structure.]

9. Exit.
*/
template<typename T>
void POSTORD(T INFO[], int LEFT[], int RIGHT[], int ROOT, int N)
{
        int STACK[N] , PTR, TOP ;
    STACK[0] = -1;
    TOP = 0;
    PTR = ROOT;
    STEP2:
    while(PTR != -1)
    {
        TOP = TOP + 1;
        STACK[TOP] = PTR;
        if(RIGHT[PTR] != -1)
        {
            TOP = TOP + 1;
            STACK[TOP] = - RIGHT[PTR];
        }
        PTR = LEFT[PTR];
    }
    PTR = STACK[TOP];
    TOP = TOP - 1;
    while(PTR > 0)
    {
        cout << INFO[PTR] << " ";
        PTR = STACK[TOP];
        TOP = TOP - 1;
    }
    if(PTR < 0)
    {
        PTR = -PTR;
        goto STEP2;
    }
}
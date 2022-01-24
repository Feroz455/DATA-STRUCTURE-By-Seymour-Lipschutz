/*
Algorithm 7.2: INORD(INFO, LEFT, RIGHT, ROOT)
A binary tree is in memory. This algorithm does an inorder traversal of T, 
applying an operation PROCESS to each of its nodes. An array STACK is used 
to temporarily hold the addresses of nodes.

1. [Push NULL onto STACK and initialize PTR.]
Set TOP := 1, STACK[1] := NULL and PTR := ROOT.

2. Repeat while PTR ≠ NULL: [Pushes left-most path onto STACK.]

(a)   Set TOP := TOP + 1 and STACK[TOP] := PTR. [Saves node.]

(b)    Set PTR := LEFT[PTR]. [Updates PTR.]

[End of loop.]

3. Set PTR := STACK[TOP] and TOP := TOP – 1. [Pops node from STACK.]

4. Repeat Steps 5 to 7 while PTR ≠ NULL: [Backtracking.]

5. Apply PROCESS to INFO[PTR].

6. [Right child?] If RIGHT[PTR] ≠ NULL, then:

(a)   Set PTR := RIGHT[PTR].

(b) Go to Step 3.

[End of If structure.]

7. Set PTR := STACK[TOP] and TOP := TOP –1. [Pops node.]

[End of Step 4 loop.]

8. Exit.
*/
template<typename T>
void INORD(T INFO[], int LEFT[], int RIGHT[], int ROOT, int N)
{
    int STACT[N] , PTR, TOP ;
    STACT[0] = -1;
    TOP = 0;
    PTR = ROOT;
    STEP2:
    while(PTR != -1)
    {
        TOP = TOP + 1;
        STACT[TOP] = PTR;
        PTR = LEFT[PTR];
    }
    STEP3:
    PTR = STACT[TOP];
    TOP = TOP - 1;
    while(PTR  != -1)
    {
        cout << INFO[PTR] << endl;
        if(RIGHT[PTR] != -1)
        {
            PTR = RIGHT[PTR];
            goto STEP2;
        }
        PTR = STACT[TOP];
        TOP = TOP - 1;
    }
}
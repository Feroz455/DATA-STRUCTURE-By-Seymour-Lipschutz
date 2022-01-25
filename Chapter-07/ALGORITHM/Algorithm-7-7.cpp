/*
page 243
Procedure 7.7: CASEB(INFO, LEFT, RIGHT, ROOT, LOC, PAR)
This procedure will delete the node N at location LOC, 
where N has two children. The pointer PAR gives the location 
of the parent of N, or else PAR = NULL indicates that N is the 
root node. The pointer SUC gives the location of the inorder 
successor of N, and PARSUC gives the location of the parent of 
the inorder successor.

1. [Find SUC and PARSUC.]

(a) Set PTR := RIGHT[LOC] and SAVE := LOC.

(b) Repeat while LEFT[PTR] ≠ NULL:

    Set SAVE := PTR and PTR := LEFT[PTR].

   [End of loop.]

(c) Set SUC := PTR and PARSUC := SAVE.

2. [Delete inorder successor, using Procedure 7.6.]

Call CASEA(INFO, LEFT, RIGHT, ROOT, SUC, PARSUC).

3. [Replace node N by its inorder successor.]
(a) If PAR ≠ NULL, then:
    If LOC = LEFT[PAR], then:

      Set LEFT[PAR] := SUC.

    Else:

      Set RIGHT[PAR] := SUC.

    [End of If structure.]

Else:

    Set ROOT := SUC.

[End of If structure.]

(b) Set LEFT[SUC] := LEFT[LOC] and

   RIGHT[SUC] := RIGHT[LOC].

4. Return.
*/
template<typename T>
void CASEA(T INFO[], int LEFT[], int RIGHT[], int ROOT, int LOC, int PAR)
{
    int CHILD;
    if((LEFT[LOC] == -1) && (RIGHT[LOC]== -1))
    {
        CHILD = -1;
    }
    else 
    if(LEFT[LOC] != -1)
    {
        CHILD = LEFT[LOC];
    }
    else 
    CHILD = RIGHT[LOC];

    if(PAR != -1)
    {
        if(LOC == LEFT[PAR])
        LEFT[PAR] = CHILD;
        else
        RIGHT[PAR] = CHILD;
    }
    else 
    ROOT = CHILD;
}
template<typename T>
void CASEB(T INFO[], int LEFT[], int RIGHT[], int ROOT, int LOC, int PAR)
{
    int SAVE, SUC, PARSUC;
    PTR = RIGHT[LOC];
    SAVE = LOC;
    while(LEFT[PTR] != -1)
    {
        LEFT[PTR] != -1;
        SAVE = PTR;
    }
    CASEA<T>(INFO, LEFT, RIGHT, ROOT, SUC, PARSUC);
    if(PAR != NULL)
    {
        if(LOC = LEFT[PAR])
        {
            LEFT[PAR] = SUC;
        }
        else 
        RIGHT[PAR] = SUC;
    }
    else 
    ROOT = SUC;
    LEFT[SUC] = LEFT[LOC];
    RIGHT[SUC] = RIGHT[LOC];
}
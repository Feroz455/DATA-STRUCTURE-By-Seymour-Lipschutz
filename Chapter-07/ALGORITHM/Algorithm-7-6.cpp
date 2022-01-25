/*
page 241
Procedure 7.6: CASEA(INFO, LEFT, RIGHT, ROOT, LOC, PAR)
This procedure deletes the node N at location LOC, where N does not
 have two children. The pointer PAR gives the location of the parent 
 of N, or else PAR = NULL indicates that N is the root node. The pointer 
 CHILD gives the location of the only child of N, or else CHILD = NULL 
 indicates N has no children.

1. [Initializes CHILD.]

If LEFT[LOC] = NULL and RIGHT[LOC] = NULL, then:

  Set CHILD := NULL.

Else if LEFT[LOC] ≠ NULL, then:

  Set CHILD := LEFT[LOC].

Else

  Set CHILD := RIGHT[LOC].

[End of If structure.]

2. If PAR ≠ NULL, then:

  If LOC = LEFT[PAR], then:

    Set LEFT[PAR] := CHILD.

  Else:

    Set RIGHT[PAR] := CHILD.

  [End of If structure.]

Else:

  Set ROOT := CHILD.

[End of If structure.]

3. Return.
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
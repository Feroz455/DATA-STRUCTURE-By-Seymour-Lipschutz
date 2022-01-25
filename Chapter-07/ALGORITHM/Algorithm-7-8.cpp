/*
Page 242
Algorithm 7.8: DEL(INFO, LEFT, RIGHT, ROOT, AVAIL, ITEM)
A binary search tree T is in memory, and an ITEM of information is given. 
This algorithm deletes ITEM from the tree.

1. [Find the locations of ITEM and its parent, using Procedure 7.4.]

Call FIND(INFO, LEFT, RIGHT, ROOT, ITEM, LOC, PAR).

2. [ITEM in tree?]

If LOC = NULL, then: Write: ITEM not in tree, and Exit.

3. [Delete node containing ITEM.]

If RIGHT[LOC] ≠ NULL and LEFT[LOC] ≠ NULL, then:

  Call CASEB(INFO, LEFT, RIGHT, ROOT, LOC, PAR).

Else:

  Call CASEA(INFO, LEFT, RIGHT, ROOT, LOC, PAR).

[End of If structure.]

4. [Return deleted node to the AVAIL list.]

Set LEFT[LOC] := AVAIL and AVAIL := LOC.

5. Exit.
*/

template<typename T>
void FIND(T INFO[], int LEFT[], int RIGHT[], int ROOT, int ITEM, int &LOC, int &PAR)
{
    int PTR, SAVE;
    if(ROOT == -1)
    {
        LOC = -1;
        PAR = -1;
        return;
    }
    if(ITEM == INFO[ROOT])
    {
        LOC = ROOT;
        PAR = -1;
        return;
    }
    if(ITEM < INFO[ROOT])
    {
        PTR = LEFT[ROOT];
        SAVE = ROOT;
    }
    else 
    {
        PTR = RIGHT[ROOT];
        SAVE = ROOT;
    }
    while(PTR != -1)
    {
        if(ITEM == INFO[PTR])
        {
            SAVE = PTR;
            PTR = LEFT[PTR];

        }
        else 
        {
            SAVE = PTR;
            PTR = RIGHT[PTR];
        }
    }
    LOC  = NULL;
    PAR = SAVE;
}
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
template<typename T>
void DEL(T INFO[], int LEFT[], int RIGHT[], int ROOT, int AVAIL, int ITEM)
{
    int LOC, PAR;
    FIND<int>(INFO, LEFT, RIGHT, ROOT, ITEM, LOC, PAR);
    if(LOC == -1)
    {
        cout << "ITEM NOT IN TREE\n";
        return;
    }
    if((RIGHT[LOC] != -1) && (LEFT[LOC] != -1))
    {
        CASEB<int>(INFO,LEFT, RIGHT, ROOT, LOC, PAR);
    }
    else
    CASEA<T>(INFO, LEFT, RIGHT, ROOT, LOC, PAR);
    LEFT[LOC] = AVAIL;
    AVAIL = LOC;
}
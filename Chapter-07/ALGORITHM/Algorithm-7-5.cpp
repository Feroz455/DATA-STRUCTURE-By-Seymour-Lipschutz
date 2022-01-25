/*
Algorithm 7.5: INSBST(INFO, LEFT, RIGHT, ROOT, AVAIL, ITEM, LOC)
A binary search tree T is in memory and an ITEM of information is given. 
This algorithm finds the location LOC of ITEM in T or adds ITEM as a new node in T at location LOC.

1. Call FIND(INFO, LEFT, RIGHT, ROOT, ITEM, LOC, PAR).
[Procedure 7.4.]

2. If LOC ≠ NULL, then Exit.

3. [Copy ITEM into new node in AVAIL list.]

(a) If AVAIL = NULL, then: Write: OVERFLOW, and Exit.

(b) Set NEW := AVAIL, AVAIL := LEFT[AVAIL] and

       INFO[NEW] := ITEM.

(c) Set LOC := NEW, LEFT[NEW] := NULL and

       RIGHT[NEW] := NULL.

4. [Add ITEM to tree.]

If PAR = NULL, then:

       Set ROOT := NEW.

Else if ITEM < INFO[PAR], then:

       Set LEFT[PAR] := NEW.

Else:

       Set RIGHT[PAR] := NEW.

[End of If structure.]

5. Exit
*/
#include<iostream>
#include<iomanip>
using namespace std;

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
void INSBST(T INFO[], int LEFT[], int RIGHT[], int ROOT,int AVAIL, int ITEM, int LOC)
{
    int PAR, NEW;
    FIND<int>(INFO,LEFT, RIGHT, ROOT, ITEM, LOC, PAR);
    if(LOC != NULL)
    {
        return;
    }
    if(AVAIL == -1)
    {
        cout << "OVERFLOW";
        return;
    }
    NEW = AVAIL;
    AVAIL = LEFT[AVAIL];
    INFO[NEW] = ITEM;
    LOC = NEW;
    LEFT[NEW] = -1;
    RIGHT[NEW] = -1;
    if(PAR == -1)
    {
        ROOT = NEW;
    }
    else 
    if(ITEM < INFO[PAR])
    {
        LEFT[PAR] = NEW;
    }
    else 
    RIGHT[PAR] = NEW;
}
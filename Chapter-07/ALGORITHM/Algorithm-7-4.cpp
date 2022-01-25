/*
Page 235
Procedure 7.4: FIND(INFO, LEFT, RIGHT, ROOT, ITEM, LOC, PAR)
    A binary search tree T is in memory and an ITEM of information is given. 
This procedure finds the location LOC of ITEM in T and also the location PAR 
of the parent of ITEM. There are three special cases:

(i) LOC = NULL and PAR = NULL will indicate that the tree is empty.

(ii) LOC ≠ NULL and PAR = NULL will indicate that ITEM is the root of T.

(iii) LOC = NULL and PAR ≠ NULL will indicate that ITEM is not in T and can 
be added to T as a child of the node N with location PAR.

1. [Tree empty?]
If ROOT = NULL, then: Set LOC := NULL and PAR := NULL, and Return.

2. [ITEM at root?]
If ITEM = INFO[ROOT], then: Set LOC := ROOT and PAB := NULL, and Return.

3. [Initialize pointers PTR and SAVE.]
If ITEM < INFO[ROOT], then:
  Set PTR := LEFT[ROOT] and SAVE := ROOT.
Else:
  Set PTR := RIGHT[ROOT] and SAVE := ROOT.
[End of If structure.]

4. Repeat Steps 5 and 6 while PTR ≠ NULL:

5.  [ITEM found?]
  If ITEM = INFO[PTR], then: Set LOC := PTR and PAR := SAVE, and Return.

6.  If ITEM < INFO[PTR], then:
    Set SAVE := PTR and PTR := LEFT[PTR].
  Else:
    Set SAVE := PTR and PTR := RIGHT[PTR].
  [End of If structure.]
  [End of Step 4 loop.]

7. [Search unsuccessful.]    Set LOC := NULL and PAR := SAVE.

8. Exi
*/
template<typename T>
void FIND(T INFO[], int LEFT[], int RIGHT[], int ROOT, int ITEM, int LOC, int PAR, int N)
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
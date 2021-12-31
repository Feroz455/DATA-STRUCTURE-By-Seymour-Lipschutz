/*
Algorithm P4.7: (Binary Search and Insertion)
DATA is a sorted array with N elements, and 
ITEM is a given item of information. 
This algorithm finds the location LOC of 
ITEM in DATA or inserts ITEM in its proper place in DATA.

Steps 1 through 4. Same as in Algorithm 4.6.
5. If ITEM < DATA[MID), then:
Set LOC := MID.
Else:
Set LOC := MID + 1.
[End of If structure.]
6. Insert ITEM into DATA[LOC] using Algorithm 4.2.
7. Exit
*/
template<typename T>
int BINARY(T DATA[], int LB, int UB, T ITEM, int LOC)
{
    int BEG, END, MID;
    BEG = LB;
    END = UB;
    MID = (int)((LB+UB)/2);
    while(BEG <= END && DATA[MID] != ITEM)
    {
        if(ITEM < DATA[MID])
        {
            END = MID - 1;
        }
        else 
        BEG = MID + 1;
        MID = (int)((BEG + END) / 2);        
    }
    if(DATA[MID] == ITEM)
    LOC = MID;
    else
    if(ITEM < DATD[MID])
    LOC = MID;
    else
    LOC = MID + 1;
    INSERT<string>(DATA, LOC, ITEM);
    return LOC;
}
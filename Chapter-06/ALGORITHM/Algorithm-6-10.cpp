/*
page 185
Procedure 6.12: TOWER(N, BEG, AUX, END)

This is a nonrecursive solution to the Towers of Hanoi problem for N 
disks which is obtained by translating the recursive solution. Stacks 
STN, STBEG, STAUX, STEND and STADD will correspond, respectively, to 
the variables N, BEG, AUX, END and ADD.

0. Set TOP := NULL.

1. If N = l, then:

(a) Write: BEG → END.

(b) Go to Step 5.

[End of If structure.]

2. [Translation of “Call TOWER(N – 1, BEG, END, AUX).”]

(a) [Push current values and new return address onto stacks.]

(i) Set TOP := TOP + 1.

(ii) Set STN[TOP] := N, STBEG[TOP] := BEG,
STAUX[TOP] := AUX, STEND[TOP] := END,
STADD[TOP] := 3.

(b) [Reset parameters.]

Get N := N – 1, BEG := BEG, AUX := END, END := AUX.

(c) Go to Step 1.

3. Write: BEG → END.

4. [Translation of “Call TOWER(N – 1, AUX, BEG, END).”]

(a) [Push current values and new return address onto stacks.]

(i) Set TOP := TOP + 1.

(ii) Set STN[TOP] := N, STBEG[TOP] := BEG,
STAUX[TOP] := AUX, STEND[TOP] := END,
STADD[TOP] := 5.

(b) [Reset parameters.]

Set N := N – 1, BEG := AUX, AUX := BEG, END := END.

(c) Go to Step 1.

5. [Translation of “Return.”]

(a) If TOP := NULL, then: Return.

(b) [Restore top values on stacks.]

(i) Set N := STN[TOP], BEG := STBEG[TOP],
AUX := STAUX[TOP], STEND[TOP],
ADD := STADD[TOP].

(ii) Set TOP := TOP – 1.

(c) Go to Step ADD
//extra
if(ADD == 3)
goto step 3;
if(ADD == 5)
goto step 5;
*/
#include<iomanip>
#include<iostream>
using namespace std;
void TOWER(int N, int  BEG, int AUX, int END)
{

   int STN[N], STBEG[N], STAUX[N], STEND[N], STADD[N];
   int TOP = -1, ADD, temp;
   STEP1:
   if(N == 1)
   {
       cout << "Move top disk  form pag " << (char)BEG << " to pag " << (char)END << endl;
       goto STEP5;
   }
   STEP2:
   TOP = TOP + 1;
   STN[TOP] = N;
   STBEG[TOP] = BEG;
   STAUX[TOP] = AUX;
   STEND[TOP] = END;
   STADD[TOP] = 3;
  // cout << N << " " << (char) BEG << " " << (char)AUX << " " << (char)END << endl;
   N = N - 1;
   BEG = BEG;
   temp = AUX;
   AUX = END;
   END = temp;
   cout << N << " " << (char) BEG << " " << (char)AUX << " " << (char)END << endl;
   goto STEP1;
   STEP3:
   cout << "Move top disk  form pag " << (char)BEG << " to pag " << (char)END << endl;
   STEP4:
   TOP = TOP + 1;
   STN[TOP] = N;
   STBEG[TOP] = BEG;
   STAUX[TOP] = AUX;
   STEND[TOP] = END;
   STADD[TOP] = 5;
   N = N - 1;
   temp = BEG;
   BEG = AUX;
   AUX = temp;
   END = END;
   cout << N << " " << (char) BEG << " " << (char)AUX << " " << (char)END << endl;
   goto STEP1;

   STEP5:
   if(TOP == -1)
   return;
   N = STN[TOP];
   BEG = STBEG[TOP];
   AUX = STAUX[TOP];
   END = STEND[TOP]; 
   ADD = STADD[TOP];
   TOP = TOP - 1;
   cout << N << " " << (char) BEG << " " << (char)AUX << " " << (char)END << endl;
   if(ADD == 3){
       goto STEP3;
   }
   if(ADD == 5)
   {
       goto STEP5;
   }

}
int main()
{
    TOWER(3, 'A', 'B', 'C');
    return 0;
}
/*
Move top disk  form pag A to pag C
Move top disk  form pag A to pag B
Move top disk  form pag C to pag B
Move top disk  form pag A to pag C
Move top disk  form pag B to pag A
Move top disk  form pag B to pag C
Move top disk  form pag A to pag C
*/
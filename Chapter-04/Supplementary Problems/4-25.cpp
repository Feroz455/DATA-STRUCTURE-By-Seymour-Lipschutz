/*
Page 109
Program
4.5 Each student in a class of 30 students takes 6 tests in which 
scores range between 0 and 100. Suppose the test scores are stored 
in a 30 × 6 array TEST. Write a module which

(a) Finds the average grade for each test

(b) Finds the final grade for each student where the final grade 
is the average of the student’s five highest test scores

(c) Finds the number NUM of students who have failed, i.e. 
whose final grade is less than 60

(d) Finds the average of the final grades
*/
#include<iostream>
#include<string>
#include<time.h>
#include<iomanip>
using namespace std;
template<typename T>
void Bubble_Sort(T DATA[], int N)
{
    int K, PTR;
    T CHANGE;
    N = N - 1;
    for(K = 0; K < N; K++)
    {
        PTR = 0;
        while(PTR < (N - K))
        {
            if(DATA[PTR] > DATA[PTR+1])
            {
                CHANGE = DATA[PTR];
                DATA[PTR] = DATA[PTR+1];
                DATA[PTR+1] = CHANGE;
            }
            
            PTR++;
        }
    }
    return;
}
//Main from Here
int main()
{
    int STUDENT[30][6], SUM, grade[6], GradeAverage[30];
    srand(time(0));
 
    for(int i = 0; i< 30; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            STUDENT[i][j] = rand() % 100 ;
        } 
    }
    for(int j = 0; j < 6; j++)
    {
        SUM = 0;
        for(int i = 0; i< 30; i++)
        {
            cout << setw(3) << STUDENT[i][j] << " " ;
            SUM += STUDENT[i][j] ; 
        }

         cout << "AVEREGE = " << SUM / 30 << "\n";   
    }
    
    for(int i = 0; i< 30; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            grade[j] = STUDENT[i][j];
        } 
        Bubble_Sort(grade,6);
        SUM = 0;
        for(int k = 5; k > 0; k--)
        {
            SUM += grade[k];
            cout << grade[k] << endl;
        }
        GradeAverage[i] = SUM / 5;
       cout << "STUDENT [" << i + 1 << "] = " << "AVEREGE = " << GradeAverage[i]  << "\n";   
    }
    int Fail = 0;
    SUM = 0;
    for(int i = 0; i < 30; i++)
    {
        SUM += GradeAverage[i];
        if(GradeAverage[i] < 60)
            Fail++;
    }
    cout << Fail << " students fail " << endl;
    cout << "AVEREGE OF THE FINAL GRADES = " << SUM / 30 << "\n"; 



    /*******************************/
    


}

/*
Output
 68  72  59  49  58  15  92   3  95  41  67  74  57  72   1  87  28  83  91  21  32  42  39  69  16  72  91  69  31  46 AVEREGE = 54
 67  47  43  91  82  60  98  19  48  20  10  32  72  47  53  19  81  78  50  79  24  11  62  61   7  27  80  10  94   6 AVEREGE = 49
 81  67  69  44  52  99  46  97  38  60  96  90   6  55  62  15  32  92  97  75  88   5  56   4   2  47  44  34  30  37 AVEREGE = 54
 21  60  24  96  71  49  22   5  42  16  37  84  26  73   7  24  56  61  53  43  99  35   4  50  93  56  80  11  38  72 AVEREGE = 46
 87  79  76  53  81  27  31  59  12  81  10  70  49  39  31  99  88  31  45  76   6  94  41  16  69  19  54  63  12  80 AVEREGE = 52
 51  42  16  85  69  41  54   4  93  88  97  98  40   9  24  65   4  91  43  34   1  27  34  26  75  54  87  50  61  43 AVEREGE = 50
87
81
68
67
51
STUDENT [1] = AVEREGE = 70
79
72
67
60
47
STUDENT [2] = AVEREGE = 65
76
69
59
43
24
STUDENT [3] = AVEREGE = 54
96
91
85
53
49
STUDENT [4] = AVEREGE = 74
82
81
71
69
58
STUDENT [5] = AVEREGE = 72
99
60
49
41
27
STUDENT [6] = AVEREGE = 55
98
92
54
46
31
STUDENT [7] = AVEREGE = 64
97
59
19
5
4
STUDENT [8] = AVEREGE = 36
95
93
48
42
38
STUDENT [9] = AVEREGE = 63
88
81
60
41
20
STUDENT [10] = AVEREGE = 58
97
96
67
37
10
STUDENT [11] = AVEREGE = 61
98
90
84
74
70
STUDENT [12] = AVEREGE = 83
72
57
49
40
26
STUDENT [13] = AVEREGE = 48
73
72
55
47
39
STUDENT [14] = AVEREGE = 57
62
53
31
24
7
STUDENT [15] = AVEREGE = 35
99
87
65
24
19
STUDENT [16] = AVEREGE = 58
88
81
56
32
28
STUDENT [17] = AVEREGE = 57
92
91
83
78
61
STUDENT [18] = AVEREGE = 81
97
91
53
50
45
STUDENT [19] = AVEREGE = 67
79
76
75
43
34
STUDENT [20] = AVEREGE = 61
99
88
32
24
6
STUDENT [21] = AVEREGE = 49
94
42
35
27
11
STUDENT [22] = AVEREGE = 41
62
56
41
39
34
STUDENT [23] = AVEREGE = 46
69
61
50
26
16
STUDENT [24] = AVEREGE = 44
93
75
69
16
7
STUDENT [25] = AVEREGE = 52
72
56
54
47
27
STUDENT [26] = AVEREGE = 51
91
87
80
80
54
STUDENT [27] = AVEREGE = 78
69
63
50
34
11
STUDENT [28] = AVEREGE = 45
94
61
38
31
30
STUDENT [29] = AVEREGE = 50
80
72
46
43
37
STUDENT [30] = AVEREGE = 55
18 students fail
AVEREGE OF THE FINAL GRADES = 57
*/
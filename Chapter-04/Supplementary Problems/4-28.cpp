/*
Page 110
Program 
4.8 Consider the data structure in Fig. 4.27. Write a procedure to carry out each of the following:

(a) Finding the number of new Oldsmobiles selling for under $10 000.

(b) Finding the number of new automobiles selling for under $10 000.

(c) Finding the number of automobiles selling for under $10 000.

(d) Listing all automobiles selling for under $10 000.

(Note: Parts (c) and (d) require only the arrays AUTO and PRICE together with the number of automobiles.)

*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct CAR
{
    int AUTO;
    int PRICE;
};

struct DEALER
{
    struct 
    {
        struct 
        {
            int NUMB;
            CAR *PTR;
        }CHEVY;
        struct
        {
            int NUMB;
            CAR *PTR;
        }BUICK;
        struct
        {
            int NUMB;
            CAR *PTR;
        }OLDS;
        
    } NEW;
    struct
    {
        int NUMB;
        CAR *PTR;
    }USED;
};
int  MOBILES(CAR *SATRT, CAR *END)
{
    cout << "\n******************\n";
    int i = 0;
    for(CAR *FIRST = SATRT; FIRST < END; FIRST++)
    {
        if(FIRST->PRICE < 10000 )
        {
            cout<< setw(5) << FIRST->AUTO << setw(3) << ". Serial Number = " << FIRST->AUTO  << " ";
            cout << setw(10)<< "PRICE = " << setw(7) << FIRST->PRICE << " " << endl;
            i++;
        }
      
    }
    return i;
}
//Main from Here
int main()
{
    srand(time(0));
    CAR car[200];
    for(int i = 0; i < 200; i++)
    {
        car[i].AUTO = 1000+i;
        car[i].PRICE = rand();
    }
    for(int i = 0 ; i < 200; i++)
    {
        cout << setw(3) << i + 1 << ". Serial Number = " << car[i].AUTO << " ";
        cout << "PRICE = " << setw(7) << car[i].PRICE << " " << endl;
    }
    DEALER DD;
    DD.NEW.BUICK.PTR = &car[0];
    DD.NEW.CHEVY.PTR= &car[50];
    DD.NEW.OLDS.PTR = &car[100];
    DD.USED.PTR = &car[150];
    cout << "\n\nNEW OLDSMOBILES SELLING FOR UNDER $10000\n";
    MOBILES(DD.NEW.OLDS.PTR,DD.USED.PTR);
    cout << "\n\nNEW AUTOMOBILES SELLING FOR UNDER $10000\n";
    MOBILES(DD.NEW.BUICK.PTR,DD.USED.PTR);
    cout << "\n\nAUTOMOBILES SELLING FOR UNDER $10000\n";
    int i = MOBILES(DD.NEW.BUICK.PTR,&car[200]);
    cout << "\n\nNUMBER OF AUTOMOBILES SELLING UNDER $10000 = " << i+1 <<  endl;
 
    return 0;
}

/*
Output
  1. Serial Number = 1000 PRICE =   28141 
  2. Serial Number = 1001 PRICE =   11863 
  3. Serial Number = 1002 PRICE =   23764 
  4. Serial Number = 1003 PRICE =   26527 
  5. Serial Number = 1004 PRICE =    5165 
  6. Serial Number = 1005 PRICE =   14500 
  7. Serial Number = 1006 PRICE =   23050 
  8. Serial Number = 1007 PRICE =   25062 
  9. Serial Number = 1008 PRICE =   31960 
 10. Serial Number = 1009 PRICE =   28767 
 11. Serial Number = 1010 PRICE =   29922 
 12. Serial Number = 1011 PRICE =    1411 
 13. Serial Number = 1012 PRICE =    1752 
 14. Serial Number = 1013 PRICE =      29 
 15. Serial Number = 1014 PRICE =    6065 
 16. Serial Number = 1015 PRICE =    5442 
 17. Serial Number = 1016 PRICE =    9301 
 18. Serial Number = 1017 PRICE =    8628 
 19. Serial Number = 1018 PRICE =    9213 
 20. Serial Number = 1019 PRICE =   32609 
 21. Serial Number = 1020 PRICE =    4649 
 22. Serial Number = 1021 PRICE =   18408 
 23. Serial Number = 1022 PRICE =    1427 
 24. Serial Number = 1023 PRICE =   29775 
 25. Serial Number = 1024 PRICE =    9109 
 26. Serial Number = 1025 PRICE =    2887 
 27. Serial Number = 1026 PRICE =   31700 
 28. Serial Number = 1027 PRICE =   23219
 29. Serial Number = 1028 PRICE =   30258
 30. Serial Number = 1029 PRICE =   24145
 31. Serial Number = 1030 PRICE =    3408
 32. Serial Number = 1031 PRICE =   17584 
 33. Serial Number = 1032 PRICE =    8746
 34. Serial Number = 1033 PRICE =   19676
 35. Serial Number = 1034 PRICE =   22934
 36. Serial Number = 1035 PRICE =   19047
 37. Serial Number = 1036 PRICE =   15015
 38. Serial Number = 1037 PRICE =   19127
 39. Serial Number = 1038 PRICE =   15689
 40. Serial Number = 1039 PRICE =   28094
 41. Serial Number = 1040 PRICE =   12940
 42. Serial Number = 1041 PRICE =   21902 
 43. Serial Number = 1042 PRICE =   31863
 44. Serial Number = 1043 PRICE =   27488
 45. Serial Number = 1044 PRICE =   31076
 46. Serial Number = 1045 PRICE =   28173
 47. Serial Number = 1046 PRICE =   26407
 48. Serial Number = 1047 PRICE =    7430 
 49. Serial Number = 1048 PRICE =   25751
 50. Serial Number = 1049 PRICE =   11336
 51. Serial Number = 1050 PRICE =   11313
 52. Serial Number = 1051 PRICE =   20724
 53. Serial Number = 1052 PRICE =   14564
 54. Serial Number = 1053 PRICE =   29531
 55. Serial Number = 1054 PRICE =   20051
 56. Serial Number = 1055 PRICE =   15046
 57. Serial Number = 1056 PRICE =   26635
 58. Serial Number = 1057 PRICE =    2125 
 59. Serial Number = 1058 PRICE =   28544
 60. Serial Number = 1059 PRICE =   24940
 61. Serial Number = 1060 PRICE =   22218
 62. Serial Number = 1061 PRICE =    4155
 63. Serial Number = 1062 PRICE =   26235
 64. Serial Number = 1063 PRICE =   11892 
 65. Serial Number = 1064 PRICE =   16139
 66. Serial Number = 1065 PRICE =   14770
 67. Serial Number = 1066 PRICE =   21157
 68. Serial Number = 1067 PRICE =     647
 69. Serial Number = 1068 PRICE =     604
 70. Serial Number = 1069 PRICE =    5468
 71. Serial Number = 1070 PRICE =    8724
 72. Serial Number = 1071 PRICE =   29495
 73. Serial Number = 1072 PRICE =     159 
 74. Serial Number = 1073 PRICE =   25055
 75. Serial Number = 1074 PRICE =   15844
 76. Serial Number = 1075 PRICE =    5624
 77. Serial Number = 1076 PRICE =   18179
 78. Serial Number = 1077 PRICE =   20226
 79. Serial Number = 1078 PRICE =   20690
 80. Serial Number = 1079 PRICE =   31851
 81. Serial Number = 1080 PRICE =   11059
 82. Serial Number = 1081 PRICE =   31762
 83. Serial Number = 1082 PRICE =   23558
 84. Serial Number = 1083 PRICE =   17891
 85. Serial Number = 1084 PRICE =    9933
 86. Serial Number = 1085 PRICE =   13700
 87. Serial Number = 1086 PRICE =    3633 
 88. Serial Number = 1087 PRICE =   27170
 89. Serial Number = 1088 PRICE =    1813
 90. Serial Number = 1089 PRICE =   13787
 91. Serial Number = 1090 PRICE =    4312
 92. Serial Number = 1091 PRICE =    8547
 93. Serial Number = 1092 PRICE =   17643
 94. Serial Number = 1093 PRICE =   28108
 95. Serial Number = 1094 PRICE =   16368
 96. Serial Number = 1095 PRICE =    3486
 97. Serial Number = 1096 PRICE =    6394 
 98. Serial Number = 1097 PRICE =    6048
 99. Serial Number = 1098 PRICE =   32682
100. Serial Number = 1099 PRICE =    2311
101. Serial Number = 1100 PRICE =    8243
102. Serial Number = 1101 PRICE =    6619
103. Serial Number = 1102 PRICE =    9360
104. Serial Number = 1103 PRICE =   15831 
105. Serial Number = 1104 PRICE =    9338
106. Serial Number = 1105 PRICE =   32027
107. Serial Number = 1106 PRICE =    8657
108. Serial Number = 1107 PRICE =   27472
109. Serial Number = 1108 PRICE =   23966
110. Serial Number = 1109 PRICE =   31042
111. Serial Number = 1110 PRICE =   29145
112. Serial Number = 1111 PRICE =   31739
113. Serial Number = 1112 PRICE =   16015 
114. Serial Number = 1113 PRICE =   24023
115. Serial Number = 1114 PRICE =   27941
116. Serial Number = 1115 PRICE =   20789
117. Serial Number = 1116 PRICE =    8907
118. Serial Number = 1117 PRICE =   22954
119. Serial Number = 1118 PRICE =     854 
120. Serial Number = 1119 PRICE =   26601
121. Serial Number = 1120 PRICE =   28698
122. Serial Number = 1121 PRICE =   26039
123. Serial Number = 1122 PRICE =    2692
124. Serial Number = 1123 PRICE =   15007
125. Serial Number = 1124 PRICE =     123
126. Serial Number = 1125 PRICE =   22349
127. Serial Number = 1126 PRICE =    6356
128. Serial Number = 1127 PRICE =    1206
129. Serial Number = 1128 PRICE =   26718
130. Serial Number = 1129 PRICE =   23920
131. Serial Number = 1130 PRICE =    7245
132. Serial Number = 1131 PRICE =   19181
133. Serial Number = 1132 PRICE =   27923
134. Serial Number = 1133 PRICE =   28027
135. Serial Number = 1134 PRICE =    9447
136. Serial Number = 1135 PRICE =   19753
137. Serial Number = 1136 PRICE =   16259 
138. Serial Number = 1137 PRICE =   25354
139. Serial Number = 1138 PRICE =    5349
140. Serial Number = 1139 PRICE =   17778
141. Serial Number = 1140 PRICE =   20254
142. Serial Number = 1141 PRICE =   22294
143. Serial Number = 1142 PRICE =   11109
144. Serial Number = 1143 PRICE =    6206
145. Serial Number = 1144 PRICE =   18708 
146. Serial Number = 1145 PRICE =   29282
147. Serial Number = 1146 PRICE =    7478
148. Serial Number = 1147 PRICE =   23026
149. Serial Number = 1148 PRICE =    6088
150. Serial Number = 1149 PRICE =   16150
151. Serial Number = 1150 PRICE =   12265
152. Serial Number = 1151 PRICE =   19878
153. Serial Number = 1152 PRICE =   30338
154. Serial Number = 1153 PRICE =   15786 
155. Serial Number = 1154 PRICE =    2859
156. Serial Number = 1155 PRICE =   16680
157. Serial Number = 1156 PRICE =   28003
158. Serial Number = 1157 PRICE =   16646
159. Serial Number = 1158 PRICE =   13394
160. Serial Number = 1159 PRICE =   27204
161. Serial Number = 1160 PRICE =   18847 
162. Serial Number = 1161 PRICE =   21992
163. Serial Number = 1162 PRICE =   26677
164. Serial Number = 1163 PRICE =   10563
165. Serial Number = 1164 PRICE =   26086
166. Serial Number = 1165 PRICE =   14725
167. Serial Number = 1166 PRICE =   18241
168. Serial Number = 1167 PRICE =   21682
169. Serial Number = 1168 PRICE =   22307
170. Serial Number = 1169 PRICE =    9075 
171. Serial Number = 1170 PRICE =    1993
172. Serial Number = 1171 PRICE =   29285
173. Serial Number = 1172 PRICE =   20841
174. Serial Number = 1173 PRICE =   26310
175. Serial Number = 1174 PRICE =    8862
176. Serial Number = 1175 PRICE =     443
177. Serial Number = 1176 PRICE =   22826 
178. Serial Number = 1177 PRICE =   11898
179. Serial Number = 1178 PRICE =   11744
180. Serial Number = 1179 PRICE =   15138
181. Serial Number = 1180 PRICE =    5291
182. Serial Number = 1181 PRICE =   22801
183. Serial Number = 1182 PRICE =   23059
184. Serial Number = 1183 PRICE =   26846
185. Serial Number = 1184 PRICE =   20916 
186. Serial Number = 1185 PRICE =   14204
187. Serial Number = 1186 PRICE =   17781
188. Serial Number = 1187 PRICE =   15623
189. Serial Number = 1188 PRICE =    5004
190. Serial Number = 1189 PRICE =   13119
191. Serial Number = 1190 PRICE =    6543
192. Serial Number = 1191 PRICE =   18641
193. Serial Number = 1192 PRICE =   15653
194. Serial Number = 1193 PRICE =    8145
195. Serial Number = 1194 PRICE =    9995 
196. Serial Number = 1195 PRICE =   30993
197. Serial Number = 1196 PRICE =   11155
198. Serial Number = 1197 PRICE =   15169
199. Serial Number = 1198 PRICE =   29637
200. Serial Number = 1199 PRICE =   15356


NEW OLDSMOBILES SELLING FOR UNDER $10000

******************
 1100. Serial Number = 1100   PRICE =    8243 
 1101. Serial Number = 1101   PRICE =    6619
 1102. Serial Number = 1102   PRICE =    9360
 1104. Serial Number = 1104   PRICE =    9338
 1106. Serial Number = 1106   PRICE =    8657
 1116. Serial Number = 1116   PRICE =    8907
 1118. Serial Number = 1118   PRICE =     854
 1122. Serial Number = 1122   PRICE =    2692
 1124. Serial Number = 1124   PRICE =     123 
 1126. Serial Number = 1126   PRICE =    6356
 1127. Serial Number = 1127   PRICE =    1206
 1130. Serial Number = 1130   PRICE =    7245
 1134. Serial Number = 1134   PRICE =    9447
 1138. Serial Number = 1138   PRICE =    5349
 1143. Serial Number = 1143   PRICE =    6206 
 1146. Serial Number = 1146   PRICE =    7478
 1148. Serial Number = 1148   PRICE =    6088


NEW AUTOMOBILES SELLING FOR UNDER $10000

******************
 1004. Serial Number = 1004   PRICE =    5165
 1011. Serial Number = 1011   PRICE =    1411
 1012. Serial Number = 1012   PRICE =    1752
 1013. Serial Number = 1013   PRICE =      29
 1014. Serial Number = 1014   PRICE =    6065
 1015. Serial Number = 1015   PRICE =    5442
 1016. Serial Number = 1016   PRICE =    9301
 1017. Serial Number = 1017   PRICE =    8628
 1018. Serial Number = 1018   PRICE =    9213
 1020. Serial Number = 1020   PRICE =    4649
 1022. Serial Number = 1022   PRICE =    1427
 1024. Serial Number = 1024   PRICE =    9109 
 1025. Serial Number = 1025   PRICE =    2887
 1030. Serial Number = 1030   PRICE =    3408
 1032. Serial Number = 1032   PRICE =    8746
 1047. Serial Number = 1047   PRICE =    7430
 1057. Serial Number = 1057   PRICE =    2125
 1061. Serial Number = 1061   PRICE =    4155 
 1067. Serial Number = 1067   PRICE =     647
 1068. Serial Number = 1068   PRICE =     604
 1069. Serial Number = 1069   PRICE =    5468
 1070. Serial Number = 1070   PRICE =    8724
 1072. Serial Number = 1072   PRICE =     159
 1075. Serial Number = 1075   PRICE =    5624 
 1084. Serial Number = 1084   PRICE =    9933
 1086. Serial Number = 1086   PRICE =    3633
 1088. Serial Number = 1088   PRICE =    1813
 1090. Serial Number = 1090   PRICE =    4312
 1091. Serial Number = 1091   PRICE =    8547
 1095. Serial Number = 1095   PRICE =    3486 
 1096. Serial Number = 1096   PRICE =    6394
 1097. Serial Number = 1097   PRICE =    6048
 1099. Serial Number = 1099   PRICE =    2311
 1100. Serial Number = 1100   PRICE =    8243 
 1101. Serial Number = 1101   PRICE =    6619
 1102. Serial Number = 1102   PRICE =    9360
 1104. Serial Number = 1104   PRICE =    9338
 1106. Serial Number = 1106   PRICE =    8657
 1116. Serial Number = 1116   PRICE =    8907
 1118. Serial Number = 1118   PRICE =     854 
 1122. Serial Number = 1122   PRICE =    2692
 1124. Serial Number = 1124   PRICE =     123
 1126. Serial Number = 1126   PRICE =    6356
 1127. Serial Number = 1127   PRICE =    1206 
 1130. Serial Number = 1130   PRICE =    7245
 1134. Serial Number = 1134   PRICE =    9447
 1138. Serial Number = 1138   PRICE =    5349
 1143. Serial Number = 1143   PRICE =    6206
 1146. Serial Number = 1146   PRICE =    7478
 1148. Serial Number = 1148   PRICE =    6088 


AUTOMOBILES SELLING FOR UNDER $10000

******************
 1004. Serial Number = 1004   PRICE =    5165
 1011. Serial Number = 1011   PRICE =    1411
 1012. Serial Number = 1012   PRICE =    1752 
 1013. Serial Number = 1013   PRICE =      29
 1014. Serial Number = 1014   PRICE =    6065
 1015. Serial Number = 1015   PRICE =    5442
 1016. Serial Number = 1016   PRICE =    9301
 1017. Serial Number = 1017   PRICE =    8628
 1018. Serial Number = 1018   PRICE =    9213
 1020. Serial Number = 1020   PRICE =    4649 
 1022. Serial Number = 1022   PRICE =    1427
 1024. Serial Number = 1024   PRICE =    9109
 1025. Serial Number = 1025   PRICE =    2887 
 1030. Serial Number = 1030   PRICE =    3408
 1032. Serial Number = 1032   PRICE =    8746
 1047. Serial Number = 1047   PRICE =    7430 
 1057. Serial Number = 1057   PRICE =    2125 
 1061. Serial Number = 1061   PRICE =    4155
 1067. Serial Number = 1067   PRICE =     647
 1068. Serial Number = 1068   PRICE =     604 
 1069. Serial Number = 1069   PRICE =    5468
 1070. Serial Number = 1070   PRICE =    8724
 1072. Serial Number = 1072   PRICE =     159 
 1075. Serial Number = 1075   PRICE =    5624
 1084. Serial Number = 1084   PRICE =    9933 
 1086. Serial Number = 1086   PRICE =    3633
 1088. Serial Number = 1088   PRICE =    1813
 1090. Serial Number = 1090   PRICE =    4312 
 1091. Serial Number = 1091   PRICE =    8547
 1095. Serial Number = 1095   PRICE =    3486 
 1096. Serial Number = 1096   PRICE =    6394
 1097. Serial Number = 1097   PRICE =    6048
 1099. Serial Number = 1099   PRICE =    2311
 1100. Serial Number = 1100   PRICE =    8243 
 1101. Serial Number = 1101   PRICE =    6619
 1102. Serial Number = 1102   PRICE =    9360
 1104. Serial Number = 1104   PRICE =    9338 
 1106. Serial Number = 1106   PRICE =    8657
 1116. Serial Number = 1116   PRICE =    8907
 1118. Serial Number = 1118   PRICE =     854
 1122. Serial Number = 1122   PRICE =    2692
 1124. Serial Number = 1124   PRICE =     123
 1126. Serial Number = 1126   PRICE =    6356
 1127. Serial Number = 1127   PRICE =    1206 
 1130. Serial Number = 1130   PRICE =    7245
 1134. Serial Number = 1134   PRICE =    9447
 1138. Serial Number = 1138   PRICE =    5349
 1143. Serial Number = 1143   PRICE =    6206
 1146. Serial Number = 1146   PRICE =    7478
 1148. Serial Number = 1148   PRICE =    6088 
 1154. Serial Number = 1154   PRICE =    2859
 1169. Serial Number = 1169   PRICE =    9075
 1170. Serial Number = 1170   PRICE =    1993
 1174. Serial Number = 1174   PRICE =    8862
 1175. Serial Number = 1175   PRICE =     443
 1180. Serial Number = 1180   PRICE =    5291
 1188. Serial Number = 1188   PRICE =    5004
 1190. Serial Number = 1190   PRICE =    6543 
 1193. Serial Number = 1193   PRICE =    8145
 1194. Serial Number = 1194   PRICE =    9995


NUMBER OF AUTOMOBILES SELLING UNDER $10000 = 61
*/



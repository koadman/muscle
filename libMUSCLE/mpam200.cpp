#include "muscle.h"

const float PAM_200_CENTER = (float) 20.0;

#define v(x)	((float) x + PAM_200_CENTER)
#define ROW(A, C, D, E, F, G, H, I, K, L, M, N, P, Q, R, S, T, V, W, Y) \
	{ v(A), v(C), v(D), v(E), v(F), v(G), v(H), v(I), v(K), v(L), \
	  v(M), v(N), v(P), v(Q), v(R), v(S), v(T), v(V), v(W), v(Y) },

float PAM200[32][32] =
	{
//       A       C       D       E       F       G       H       I       K       L
//       M       N       P       Q       R       S       T       V       W       Y
ROW(   388,     -0,     34,     32,   -202,    159,    -88,     89,    -55,    -67, 
        19,     86,    186,    -34,    -32,    237,    273,    171,   -326,   -239)  // A
ROW(    -0,   1170,   -248,   -315,     74,    -14,     43,   -151,   -204,   -196, 
      -132,    -49,   -142,   -215,     29,    165,     -7,    -69,    179,    313)  // C
ROW(    34,   -248,    625,    496,   -419,    148,     78,   -245,     55,   -361, 
      -255,    332,   -169,    122,    -64,     45,    -13,   -167,   -438,   -148)  // D
ROW(    32,   -315,    496,    610,   -480,    125,     25,   -245,    175,   -327, 
      -242,    166,   -141,    279,     34,    -30,    -56,   -150,   -386,   -305)  // E
ROW(  -202,     74,   -419,   -480,    888,   -407,     62,     80,   -443,    320, 
        67,   -236,   -180,   -294,   -327,    -51,   -173,     31,     -1,    584)  // F
ROW(   159,    -14,    148,    125,   -407,    662,   -114,   -216,    -34,   -324, 
      -246,     79,    -77,    -68,     97,    155,     21,    -93,    -58,   -349)  // G
ROW(   -88,     43,     78,     25,     62,   -114,    766,   -205,    144,    -92, 
      -152,    238,     66,    368,    257,     35,    -35,   -217,   -201,    468)  // H
ROW(    89,   -151,   -245,   -245,     80,   -216,   -205,    554,   -224,    288, 
       391,   -114,   -115,   -222,   -208,    -19,    162,    469,   -274,   -153)  // I
ROW(   -55,   -204,     55,    175,   -443,    -34,    144,   -224,    632,   -249, 
      -118,    186,    -86,    315,    466,      2,     19,   -227,   -216,   -264)  // K
ROW(   -67,   -196,   -361,   -327,    320,   -324,    -92,    288,   -249,    591, 
       369,   -223,     53,    -86,   -170,    -69,    -41,    239,    -66,    -29)  // L
ROW(    19,   -132,   -255,   -242,     67,   -246,   -152,    391,   -118,    369, 
       756,   -131,    -98,   -124,   -129,    -49,    129,    331,   -229,   -182)  // M
ROW(    86,    -49,    332,    166,   -236,     79,    238,   -114,    186,   -223, 
      -131,    516,    -21,     88,     73,    240,    168,   -118,   -379,     -8)  // N
ROW(   186,   -142,   -169,   -141,   -180,    -77,     66,   -115,    -86,     53, 
       -98,    -21,    736,    122,      5,    221,    139,    -75,   -373,   -226)  // P
ROW(   -34,   -215,    122,    279,   -294,    -68,    368,   -222,    315,    -86, 
      -124,     88,    122,    635,    301,    -13,    -35,   -195,   -243,    -73)  // Q
ROW(   -32,     29,    -64,     34,   -327,     97,    257,   -208,    466,   -170, 
      -129,     73,      5,    301,    606,     28,     -4,   -201,    104,   -133)  // R
ROW(   237,    165,     45,    -30,    -51,    155,     35,    -19,      2,    -69, 
       -49,    240,    221,    -13,     28,    353,    259,      8,   -213,    -55)  // S
ROW(   273,     -7,    -13,    -56,   -173,     21,    -35,    162,     19,    -41, 
       129,    168,    139,    -35,     -4,    259,    422,    143,   -343,   -190)  // T
ROW(   171,    -69,   -167,   -150,     31,    -93,   -217,    469,   -227,    239, 
       331,   -118,    -75,   -195,   -201,      8,    143,    505,   -245,   -197)  // V
ROW(  -326,    179,   -438,   -386,     -1,    -58,   -201,   -274,   -216,    -66, 
      -229,   -379,   -373,   -243,    104,   -213,   -343,   -245,   1475,     63)  // W
ROW(  -239,    313,   -148,   -305,    584,   -349,    468,   -153,   -264,    -29, 
      -182,     -8,   -226,    -73,   -133,    -55,   -190,   -197,     63,    979)  // Y
	};

#undef v
#define v(x)	((float) x)
#define RNC(A, C, D, E, F, G, H, I, K, L, M, N, P, Q, R, S, T, V, W, Y) \
	{ v(A), v(C), v(D), v(E), v(F), v(G), v(H), v(I), v(K), v(L), \
	  v(M), v(N), v(P), v(Q), v(R), v(S), v(T), v(V), v(W), v(Y) },

float PAM200NoCenter[32][32] =

	{
//       A       C       D       E       F       G       H       I       K       L
//       M       N       P       Q       R       S       T       V       W       Y
RNC(   388,     -0,     34,     32,   -202,    159,    -88,     89,    -55,    -67, 
        19,     86,    186,    -34,    -32,    237,    273,    171,   -326,   -239)  // A
RNC(    -0,   1170,   -248,   -315,     74,    -14,     43,   -151,   -204,   -196, 
      -132,    -49,   -142,   -215,     29,    165,     -7,    -69,    179,    313)  // C
RNC(    34,   -248,    625,    496,   -419,    148,     78,   -245,     55,   -361, 
      -255,    332,   -169,    122,    -64,     45,    -13,   -167,   -438,   -148)  // D
RNC(    32,   -315,    496,    610,   -480,    125,     25,   -245,    175,   -327, 
      -242,    166,   -141,    279,     34,    -30,    -56,   -150,   -386,   -305)  // E
RNC(  -202,     74,   -419,   -480,    888,   -407,     62,     80,   -443,    320, 
        67,   -236,   -180,   -294,   -327,    -51,   -173,     31,     -1,    584)  // F
RNC(   159,    -14,    148,    125,   -407,    662,   -114,   -216,    -34,   -324, 
      -246,     79,    -77,    -68,     97,    155,     21,    -93,    -58,   -349)  // G
RNC(   -88,     43,     78,     25,     62,   -114,    766,   -205,    144,    -92, 
      -152,    238,     66,    368,    257,     35,    -35,   -217,   -201,    468)  // H
RNC(    89,   -151,   -245,   -245,     80,   -216,   -205,    554,   -224,    288, 
       391,   -114,   -115,   -222,   -208,    -19,    162,    469,   -274,   -153)  // I
RNC(   -55,   -204,     55,    175,   -443,    -34,    144,   -224,    632,   -249, 
      -118,    186,    -86,    315,    466,      2,     19,   -227,   -216,   -264)  // K
RNC(   -67,   -196,   -361,   -327,    320,   -324,    -92,    288,   -249,    591, 
       369,   -223,     53,    -86,   -170,    -69,    -41,    239,    -66,    -29)  // L
RNC(    19,   -132,   -255,   -242,     67,   -246,   -152,    391,   -118,    369, 
       756,   -131,    -98,   -124,   -129,    -49,    129,    331,   -229,   -182)  // M
RNC(    86,    -49,    332,    166,   -236,     79,    238,   -114,    186,   -223, 
      -131,    516,    -21,     88,     73,    240,    168,   -118,   -379,     -8)  // N
RNC(   186,   -142,   -169,   -141,   -180,    -77,     66,   -115,    -86,     53, 
       -98,    -21,    736,    122,      5,    221,    139,    -75,   -373,   -226)  // P
RNC(   -34,   -215,    122,    279,   -294,    -68,    368,   -222,    315,    -86, 
      -124,     88,    122,    635,    301,    -13,    -35,   -195,   -243,    -73)  // Q
RNC(   -32,     29,    -64,     34,   -327,     97,    257,   -208,    466,   -170, 
      -129,     73,      5,    301,    606,     28,     -4,   -201,    104,   -133)  // R
RNC(   237,    165,     45,    -30,    -51,    155,     35,    -19,      2,    -69, 
       -49,    240,    221,    -13,     28,    353,    259,      8,   -213,    -55)  // S
RNC(   273,     -7,    -13,    -56,   -173,     21,    -35,    162,     19,    -41, 
       129,    168,    139,    -35,     -4,    259,    422,    143,   -343,   -190)  // T
RNC(   171,    -69,   -167,   -150,     31,    -93,   -217,    469,   -227,    239, 
       331,   -118,    -75,   -195,   -201,      8,    143,    505,   -245,   -197)  // V
RNC(  -326,    179,   -438,   -386,     -1,    -58,   -201,   -274,   -216,    -66, 
      -229,   -379,   -373,   -243,    104,   -213,   -343,   -245,   1475,     63)  // W
RNC(  -239,    313,   -148,   -305,    584,   -349,    468,   -153,   -264,    -29, 
      -182,     -8,   -226,    -73,   -133,    -55,   -190,   -197,     63,    979)  // Y
	};

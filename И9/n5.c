#include <stdio.h>

void RectPS(int x1, int y1, int x2, int y2, int *P, int *S)
{
    int a, b;
    if(x1 > 0 && x2 > 0)
        b = x1 > x2 ? x1 - x2 : x2 - x1;
    else
        b =  x1 > 0 && x2 < 0 ? x1 + abs(x2) : x2 + abs(x1);
    if(y1 > 0 && y2 > 0)
        a = y1 > y2 ? y1 - y2 : y2 - y1;
    else
        a =  y1 > 0 && y2 < 0 ? y1 + abs(y2) : y2 + abs(y1);
    *P = (a + b) * 2;
    *S = a * b;

}

#include <stdio.h>

void ShiftRight3(int *a, int *b, int *c)
{
    int swap = *c;
    swap++;
    *c = *b;
    *b = *a;
    *a = swap - 1;
}

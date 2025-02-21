#include <stdio.h>

void powerA234(int a, int *b, int *c, int *d)
{
    int clone = a;
    *b = a * a;
    *c = *b * clone;
    *d = *b * *b;
}

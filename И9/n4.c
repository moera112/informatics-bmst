#include <stdio.h>

void invertDigits(int *k)
{
    int t = 10, clone = 0;
    while(*k % t != *k)
        t*=10;
    t /= 10;
    while(*k % 10 != *k)
    {
        clone += t * (*k % 10);
        *k /= 10;
        t /= 10;
    }
    clone += *k;
    *k = clone;
}

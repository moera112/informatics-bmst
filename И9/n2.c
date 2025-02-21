#include <stdio.h>

void DigitCountSum(int k, int *c, int *s)
{
    while(k % 10 != k)
    {
        *s += k % 10;
        *c++;
        k /= 10;
    }

    *c += 1;
    *s += k;
}

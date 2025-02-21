#include <stdio.h>

int DigitN(int n, int k)
{
    for(int i = 1; i < k; i++)
        if(n % 10 != n)
            n /= 10;
        else
            return -1;
    return n % 10;
}


int main()
{
    printf("%d",DigitN(123456, 3));
}



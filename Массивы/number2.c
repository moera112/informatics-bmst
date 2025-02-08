#include <stdio.h>
#include <stdlib.h>

/* Дано целое число N и набор из N чисел.
Найти номер минимального элемента из данного набора. */


int main()
{
    int n, min, min_count;

    scanf("%d\n%d",&n,&min);
    for(int i = 1; i < n; i ++)
    {
        int s;
        scanf("%d",&s);
        if (s < min)
        {
            min = s;
            min_count = i;
        }
    }
    printf("min index = %d, min = %d",min_count + 1,min);
    return 0;
}

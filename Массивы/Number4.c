#include <stdio.h>
#include <stdlib.h>

/*Дано целое число N > 0.
Сформировать и вывести целочисленный массив размером N,
содержащий степени двойки от первой до N: i = 2, 4, 8, 16, ... */

int main()
{
    int n, s = 1, chet;
    int mas[100];
    scanf("%d",&n);
    for(int i = 0; i < n + 1;i++)
    {
        mas[i] = s;
        s *= 2;
        printf("%d ",mas[i]);
    }

    return 0;
}

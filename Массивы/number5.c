#include <stdio.h>
#include <stdlib.h>

/*Даны целые числа N ≥ 2, и Z ≥ 2.
Сформировать и вывести целочисленный массив размером N, в котором элемент которого равен сумме всех предыдущих,
а каждый последующий элемент равен сумме всех предыдущих. */

int main()
{
    int n, s = 1, sum = 0, a, b;
    int mas[100];
    scanf("%d %d %d",&n, &a,&b);
    sum = a + b; mas[0] = a; mas[1] = b;
    printf("%d %d ",mas[0],mas[1]);
    for(int i = 2; i < n + 1;i++)
    {
        mas[i] = sum;
        sum *= 2;
        printf("%d ",mas[i]);
    }

    return 0;
}

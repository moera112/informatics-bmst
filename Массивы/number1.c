#include <stdio.h>

/*. Дано целое число N и набор из N чисел.
Найти минимальный и максимальный из элементов данного набора и вывести их в указанном порядке.*/





int main()
{
    int n, min, max = 0;
    scanf("%d\n%d",&n,&min);
    for(int i = 1; i < n; i++)
    {
        int s;
        scanf("%d",&s);
        if (s < min)
        {
            min = s;
        }
        if (s > max)
        {
            max = s;
        }

    }
    printf("max number = %d, min number = %d",max,min);
    return 0;
}

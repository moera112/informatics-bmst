#include <stdio.h>
#include <stdlib.h>

/*Дано целое число N и набор из N пар чисел (m, v) — данные о массе m и объеме v деталей,
изготовленных из различных материалов.
Вывести номер детали, изготовленной из материала максимальной плотности,
а также величину этой максимальной плотности. Плотность P вычисляется по формуле P = m/v. */

int main()
{
    int n, count = 1, chet = 0;
    float m, v, max = 0;
    scanf("%d",&n);
    while(count <= n*2)
    {
        count++;
        if (chet == 0)
        {
            scanf("%f",&m);
            chet++;
        }else if(chet == 1)
        {
            scanf("%f",&v);
            if (max < (m/v))
                max = m/v;
            chet--;
        }
    }
    printf("max plotnost = %f",max);
    return 0;
}

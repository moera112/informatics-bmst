#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    srand(time(NULL));
    int n, max_ = -100000, min_ = 100000, ind_m, ind_x;
    double arr[10000];
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        arr[i] = (double)(rand() % 100);
        printf("%.2f ",arr[i]);
    }
    printf("\r\n");
    for(int i = 0; i < n; i++)
        if(i != 0 && i != n - 1)
        {
            arr[i] = (arr[i - 1] + arr[i] + arr[i + 1]) / 3;
        }
        else if(i == 0)
        {
            arr[i] = (arr[i] + arr[i + 1]) / 2;
        }
        else
        {
            arr[i] = (arr[i] + arr[i - 1]) / 2;
        }

    for(int i = 0; i < n; i++)
    {
        printf("%.1f ",arr[i]);
    }
}

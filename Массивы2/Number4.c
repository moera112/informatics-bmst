#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    srand(time(NULL));
    int n, max_ = -100000, min_ = 100000, ind_m, ind_x;
    int arr[10000];
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ",arr[i]);
    }

    for(int i = n + 1; i > 0; i--)
        arr[i] = arr[i - 1];

    arr[0] = 0; 
    printf("\r\n");

    for(int i = 0; i < n + 1;i++)
    {
        printf("%d ",arr[i]);
    }
}

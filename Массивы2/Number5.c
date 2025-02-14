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
    int k, l;
    scanf("%d %d",&k,&l);

    int clone[100] = {};
    for(int i = 0, j = 0; i < n;i++)
    {
        if(i < k || i > l)
        {
            continue;

        }
        clone[j] = arr[i];
        j++;
    }
    for(int i = 0; i < n; i++)
        if(clone[i] != 0)
            printf(" %d ",clone[i]);
        else
            break;
}

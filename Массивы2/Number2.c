#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    srand(time(NULL));
    int n, max_ = -100000, min_ = 100000, ind_m, ind_x;
    int arr[10000];
    int clone[10000];
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
       arr[i] = rand() % 1000;
       if(arr[i] > max_)
       {
           max_ = arr[i];
           ind_x = i;
       }
       if(arr[i] < min_)
       {
           min_ = arr[i];
           ind_m = i;
       }
       printf("%d ",arr[i]);
    }

    printf("\r\nmin = %d, min index = %d max = %d max index = %d\r\n",min_, ind_m, max_, ind_x);

    int m = ind_m > ind_x ? ind_m : ind_x, s = m == ind_m ? ind_x : ind_m;

    for(int i = m - 1, j = s + 1; i > s, j < m; i--, j++)
    {
        clone[j] = arr[i];
    }
    
    printf("Result mas = ");
    
    for(int i = s + 1; i < m; i++)
    {
        arr[i] = clone[i];
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }

}

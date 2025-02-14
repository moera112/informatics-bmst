
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    srand(time(NULL));
    int arr[10000];
    int n, k;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        /*int a;
        scanf("%d",&a);
        arr[i] = a;*/
        arr[i] = rand() % 100;
        printf("%d ",arr[i]);
    }

    scanf("%d\n",&k);

    for(int i = 0; i < n; i++)
    {
        arr[i] *= k;
        printf("%d ",arr[i]);
    }
}

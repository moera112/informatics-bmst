#include <stdio.h>

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

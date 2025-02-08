#include <stdio.h>
#include <stdlib.h>



int main()
{
    int n, k ,l;
    scanf("%d %d %d",&n,&k,&l);
    int i = 1;
    for(; i < n + 1;i++)
    {

        if (i == k)
            break;
        scanf("%*d");
    }
    int sum = 0;
    scanf("%d",&sum);
    while (i != l)
    {
        int s;
        scanf("%d",&s);
        sum += s;
        i++;
    }
    if (i < n)
    {
        while(i < n)
        {
            scanf("%*d");
            i++;
        }
    }
    printf("%d",sum);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int len;

    scanf("%d\r\n",&len);

    int num = 0;

    char str[100];

    for(int i = 0; i <= len; i++)
        str[i] = getchar();

    int two = 1;


    for(int i = len-1; i > -1; i--)
    {
        num += two * (str[i] - '0');
        two *= 2;
    }

    printf("%d",num);
}

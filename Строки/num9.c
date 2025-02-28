#include <stdio.h>


int main()
{
  const int n = 5;
    int sum = 0;
    char str[n];
    for(int i = 0; i < n; i++)
    {
        str[i] = getchar();
        sum += (str[i] - '0');
    }

    printf("%d",sum);
    return 0;
}

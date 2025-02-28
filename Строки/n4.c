#include <stdio.h>

int main()
{
  char a = getchar(), b = getchar();
  int n;
  scanf("%d",&n);
  for(int i = 0; i < n; i++)
    if(!(i % 2))
      putchar(a);
    else
      putchar(b);
}

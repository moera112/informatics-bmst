#include <stdio.h>

int main()
{
  char last = 'z';
  int n;
  scanf("%d",&n);
  for(int i = last; i > n; i--)
    printf("%c",i);
}

#include <stdio.h>



int main()
{
  int n;
  char str[100];
  scanf("%d",&n);
  for(int i = 0; i < n; i++)
  {
      str[i] = getchar();
      if(str[i] == '.')
      {
          printf("2");
          goto link;
      }
      else if(str[i] - '0' < 0 && str[i] - '0' > 9)
      {
          printf("0");
          goto link;
      }
  }
  printf("1");
  link: return 0;


}

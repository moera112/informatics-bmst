#include <stdio.h>

#define IFF if(str[i] - '0' >= 0 && str[i] - '0' <= 9) count++;
#define IN for(int i = 0; i < n; i++) str[i] = getchar()

int main()
{
  char str[100];
  int n = 11, count = 0; // Длина строки
  IN;
  for(int i = 0; i < n; i++)
    IFF;
  printf("%d",count);
}

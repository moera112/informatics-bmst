#include <stdio.h>

#define IN for(int i = 0; i < n; i++) str[i] = getchar()
#define REVERSE for(int i = n-1; i > -1; i--) putchar(str[i])

int main()
{
  char str[100];
  int n = 11 // Длина строки
  IN;
  REVERSE;
}

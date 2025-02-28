#include <stdio.h>

#define IFF if(str[i] >= 97) str[i] -= 32;;
#define IN for(int i = 0; i < n; i++) str[i] = getchar()
#define OUT for(int i = 0; i < n; i++) putchar(str[i])

int main()
{
  char str[100];
  int n = 11; // Длина строки
  IN;
  for(int i = 0; i < n; i++)
    IFF;

  OUT;
  
}

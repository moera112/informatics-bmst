#include <strdio.h>
#include <stdbool.h>

bool IsLeapYear(int n)
{
    if(n % 4 == 0 && n % 100 != 0 || n % 400 == 0)
        return true;
    else
        return false;
}

int main()
{
    printf("%d",IsLeapYear(2023));
}

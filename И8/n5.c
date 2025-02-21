#include <stdio.h>

int Nod2(int n, int k)
{
    int min = n > k ? k : n;
    int max = n > k ? n : k;
    while (min > 0) {
        max = max % min;

        if (max == 0) {
            break;
        }
        int temp = min;
        min = max;
        max = temp;
    }
    return min;

}


int main()
{
    printf("%d",Nod2(123,435));
}

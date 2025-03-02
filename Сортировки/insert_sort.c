#include <stdio.h>
#include <iso646.h>

#define IN for(int i = 0; i < n; ++i) scanf("%d",&arr[i])
#define OUT for(int i = 0; i < n; ++i) printf("%d ",arr[i])
#define SIZE 1000

int arr[SIZE];


void insert_sort(int ar[], int len)
{
    for(int i = 1; i < len; i++)
    {
        int k = i;
        while(k > 0 and ar[k-1] > ar[k])
        {
            int swap = ar[k] + 1;
            swap--;
            ar[k] = ar[k-1];
            ar[k-1] = swap;
            k--;
        }
    }
}


int main()
{

    int n;
    scanf("%d",&n);
    IN;
    insert_sort(arr, n);
    OUT;
}


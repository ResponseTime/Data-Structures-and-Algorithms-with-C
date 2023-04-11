#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int maxi(int *arr, int n)
{
    int m = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > m)
        {
            m = arr[i];
        }
    }
    return m;
}
void cs(int *arr, int n)
{
    int i, j;
    int max = maxi(arr, n);
    int *t = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        t[arr[i]]++;
    }
    i = 0;
    j = 0;
    while (i <= max)
    {
        if (t[i] > 0)
        {
            arr[j++] = i;
            t[i]--;
        }
        else
        {
            i++;
        }
    }
}
int main(int argc, char **argv)
{
    int arr[] = {32, 12, 45, 23, 67, 89, 34, 56, 78, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cs(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
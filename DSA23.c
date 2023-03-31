#include <stdio.h>

void sel(int *arr, int n)
{
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}
int main(int argc, char **argv)
{
    int arr[] = {43, 76, 87, 2, 1, 34, 78};
    int len = sizeof(arr) / sizeof(arr[0]);
    sel(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
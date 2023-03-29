#include <stdio.h>

void ins(int *arr, int n)
{
    int k, j;
    for (int i = 1; i < n; i++)
    {
        k = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
    }
}

int main(int argc, char **argv)
{
    int arr[] = {43, 76, 87, 2, 1, 34, 78};
    int len = sizeof(arr) / sizeof(arr[0]);
    ins(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
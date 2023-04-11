#include <stdio.h>
void merge(int *arr, int l, int m, int h)
{
    int i = l;
    int j = m + 1;
    int k = 0;
    int temp[h - l + 1];
    while (i <= m && j <= h)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= m)
    {
        temp[k++] = arr[i++];
    }
    while (j <= h)
    {
        temp[k++] = arr[j++];
    }
    for (int i = l, k = 0; i <= h; i++, k++)
    {
        arr[i] = temp[k];
    }
}
void mergeSort(int *arr, int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}
int main(int argc, char **argv)
{
    int arr[] = {32, 12, 45, 23, 67, 89, 34, 56, 78, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
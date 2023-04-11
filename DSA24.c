#include <stdio.h>

int partition(int *arr, int l, int h)
{
    int pivot = arr[l];
    int i = l + 1;
    int j = h;

    do
    {

        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    int temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    return j;
}

void qs(int *arr, int l, int h)
{
    if (l < h)
    {

        int pivot = partition(arr, l, h);
        qs(arr, l, pivot - 1);
        qs(arr, pivot + 1, h);
    }
}
int main(int argc, char **argv)
{
    int arr[] = {32, 12, 45, 23, 67, 89, 34, 56, 78, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    qs(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
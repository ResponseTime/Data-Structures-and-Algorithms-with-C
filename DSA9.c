#include <stdio.h>

int linear_search(int *arr, int n, int data)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == data)
        {
            return i;
        }
    }
    return -1;
}

int binary_search(int *arr, int data, int l, int h)
{
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] == data)
        {
            return mid;
        }
        else if (data > arr[mid])
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}
int main(int argc, char **argv)
{
    int arr[] = {1, 2, 4, 65, 766, 890, 900};
    int len = sizeof(arr) / sizeof(arr[0]);
    int f = linear_search(arr, len, 2);
    int fi = binary_search(arr, 766, 0, len - 1);
    printf("%d\n", fi);
    return 0;
}
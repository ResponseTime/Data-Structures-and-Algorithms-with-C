#include <stdio.h>
void bubble(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main(int argc, char **argv)
{
    int arr[] = {43, 76, 87, 2, 1, 34, 78};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubble(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
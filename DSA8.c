#include <stdio.h>
#include <Math.h>
typedef struct Array
{
    int total_size;
    int used_size;
    int iter;
    int *base;
} Array;

Array *create(int used_size)
{
    Array *arr = (Array *)malloc(sizeof(Array));
    arr->total_size = pow(2, used_size);
    arr->used_size = used_size;
    arr->iter = 0;
    arr->base = (int *)malloc(sizeof(int) * arr->total_size);
    return arr;
}
int max(Array *arr)
{
    int max = arr->base[0];
    for (int i = 1; i < arr->used_size; i++)
    {
        if (arr->base[i] > max)
        {
            max = arr->base[i];
        }
    }
    return max;
}
int min(Array *arr)
{
    int min = arr->base[0];
    for (int i = 1; i < arr->used_size; i++)
    {
        if (arr->base[i] < min)
        {
            min = arr->base[i];
        }
    }
    return min;
}
int sum(Array *arr)
{
    int sum = 0;
    for (int i = 0; i < arr->used_size; i++)
    {
        sum += arr->base[i];
    }
    return sum;
}
void add(Array *arr, int data)
{
    arr->base[arr->iter++] = data;
    arr->used_size++;
}
void set(Array *arr, int i, int data)
{
    if (i <= arr->iter)
    {
        arr->base[i] = data;
    }
}
int get(Array *arr, int i)
{
    if (i <= arr->iter)
    {
        return arr->base[i];
    }
    return -1;
}
void insert(Array *arr, int i, int data)
{
    if (i <= arr->iter)
    {
        for (int j = arr->iter; j > i; j--)
        {
            arr->base[j] = arr->base[j - 1];
        }
        arr->base[i] = data;
        arr->iter++;
        arr->used_size++;
    }
}
void delete(Array *arr, int i)
{
    if (i <= arr->iter)
    {
        for (int j = i; j < arr->iter; j++)
        {
            arr->base[j] = arr->base[j + 1];
        }
        arr->iter--;
        arr->used_size--;
    }
}
int main(int argc, char **argv)
{

    return 0;
}
#include <stdio.h>
#include <conio.h>

void main()
{
    int arr[6];

    printf("Enter 6 random numbers\n");

    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, 5);

    for (int i = 0; i < 6; i++)
    {
        printf("%d \t", arr[i]);
    }
}

void quicksort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);

        quicksort(arr, start, pivot - 1);
        quicksort(arr, pivot + 1, end);
    }
}

int partition(int *arr, int start, int end)
{
    int pivot = start - 1;
    while (start <= end)
    {
        if (arr[end] >= arr[start])
        {
            pivot++;
            swap(arr, start, pivot);
        }
        start++;
    }
    return pivot;
}

void swap(int *arr, int i, int j)
{
    int first = arr[i];
    arr[i] = arr[j];
    arr[j] = first;
}
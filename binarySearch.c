#include <stdio.h>
#include <malloc.h>

void binarySearch(int arr[], int search, int start, int end);

int main()
{
    int length, search;
    printf("Enter the length of array : ");
    scanf("%d", &length);

    int *arr = (int *)calloc(length, 4);

    printf("Enter the array : \n");
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search : ");
    scanf("%d", &search);

    binarySearch(arr, search, 0, length - 1);
}

void binarySearch(int arr[], int search, int start, int end)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;
        printf("mid %d \n", mid);
        if (search == arr[mid])
        {
            printf("%d found at location %d", search, mid);
        }
        else if (search > arr[mid])
        {
            binarySearch(arr, search, mid + 1, end);
        }
        else
        {
            binarySearch(arr, search, start, mid - 1);
        }
    }
    else
    {
        printf("%d not found", search);
    }
}
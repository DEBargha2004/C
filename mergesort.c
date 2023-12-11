#include <stdio.h>
#include <malloc.h>

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main()
{
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    int *arr = (int *)calloc(size, 4);
    printf("Enter the numbers\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }
    return 0;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int l_arr_size = mid - left + 1;
    int r_arr_size = right - mid;

    int *L = (int *)calloc(l_arr_size, 4);
    int *R = (int *)calloc(r_arr_size, 4);

    for (i = 0; i < l_arr_size; i++)
    {
        L[i] = arr[left + i];
    }
    for (j = 0; j < r_arr_size; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    i = 0, j = 0, k = left;

    while (i < l_arr_size && j < r_arr_size)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < l_arr_size)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < r_arr_size)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}
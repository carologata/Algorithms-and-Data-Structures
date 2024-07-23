#include <string.h>
#include <stdlib.h>

void merge(int *arr, int l, int middle, int r)
{
    int len_left;
    int len_right;

    len_left = middle - l + 1;
    len_right = r - middle;

    int arr_left[len_left];
    int arr_right[len_right];

    for (int i = 0; i < len_left; i++)
        arr_left[i] = arr[l + i];

    for (int j = 0; j < len_right; j++)
        arr_right[j] = arr[middle + 1 + j];

    for (int i = 0, j = 0, k = l; k <= r; k++)
    {
        if (i < len_left && (j >= len_right || arr_left[i] <= arr_right[j]))
        {
            arr[k] = arr_left[i];
            i++;
        }
        else
        {
            arr[k] = arr_right[j];
            j++;
        }
    }
}

void mergeSortRecursion(int *arr, int l, int r)
{
    int middle;

    if (r > l)
    {
        middle = (r + l) / 2;

        mergeSortRecursion(arr, l, middle);
        mergeSortRecursion(arr, middle + 1, r);

        merge(arr, l, middle, r);
    }
}

void mergeSort(int *arr, int len)
{
    mergeSortRecursion(arr, 0, len - 1);
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int i;
    int len;
    int *arr;
    double value1;
    double value2;
    double median;

    median = 0;
    len = nums1Size + nums2Size;
    arr = calloc(len, sizeof(int));

    for (i = 0; i < nums1Size; i++)
        arr[i] = nums1[i];
    for (i = 0; i < nums2Size; i++)
        arr[nums1Size + i] = nums2[i];

    mergeSort(arr, len);

    if (len % 2 == 0)
    {
        value1 = arr[len / 2 - 1];
        value2 = arr[len / 2];
        median = (value1 + value2) / 2;
    }
    else
        median = (double)arr[len / 2];

    return (median);
}

/* #include <stdio.h>

int main(void)
{
    double median;

    int *arr1 = malloc(2 * sizeof(int));
    arr1[0] = 1;
    arr1[1] = 2;
    // arr1[2] = 9;
    // arr1[3] = 0;
    int len1 = 2;

    int *arr2 = malloc(1 * sizeof(int));
    arr2[0] = 3;
    arr2[1] = 4;
    // arr2[2] = 3;
    int len2 = 2;

    median = findMedianSortedArrays(arr1, len1, arr2, len2);
    printf("median: %f\n", median);
} */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int binarySearch(int arr[], int low, int high, int key)
{
    int mid = (low + high) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return binarySearch(arr, low, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, high, key);
    return -1;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void tabularOutput()
{
    printf("Sl no.\t\tn\t\tTime Complexity\n");
    int count = 1;
    for (int i = 5000; i <= 50000; i += 5000)
    {
        int arr[i];
        for (int j = 0; j < i; j++)
        {
            arr[j] = rand() % i;
        }
        bubbleSort(arr, i);
        int key = rand() % i;
        clock_t t1 = clock();
        binarySearch(arr, 0, i - 1, arr[key]);
        t1 = clock() - t1;
        printf("%d\t\t%d\t\t%f\n", count, i, (double)t1 / CLOCKS_PER_SEC);
        count++;
    }
}
int main()
{
    tabularOutput();
    return 0;
}
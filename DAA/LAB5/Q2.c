#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void merge(int a[], int b[], int n, int m) // n=mid , m= high
{
    int i, j, k;
    i = j = k = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            a[k++] = a[i++];
        else
            a[k++] = b[j++];
    }
    while (i < n)
        a[k++] = a[i++];
    while (j < m)
        a[k++] = b[j++];
}
void mergeSort(int a[], int n) // n=sizeofarray
{
    int m; // m=mid
    if (n < 2)
        return;
    m = n / 2;
    mergeSort(a, m);
    mergeSort(a + m, n - m);
    merge(a, a + m, m, n - m);
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
            if (arr[j] < arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void tabularOutput()
{
    printf("Sl no.\t\tn\t\tTime Complexity\t\tTime for Sorted in Ascending Order\t\t Time for Sorted in Descending Order\n");
    int count = 1;
    for (int i = 5000; i <= 50000; i += 5000)
    {
        int arr[i];
        for (int j = 0; j < i; j++)
        {
            arr[j] = rand() % i;
        }
        clock_t t1 = clock();
        mergeSort(arr, i);
        t1 = clock() - t1;
        clock_t t2 = clock();
        mergeSort(arr, i);
        t2 = clock() - t2;
        bubbleSort(arr, i);
        clock_t t3 = clock();
        mergeSort(arr, i);
        t3 = clock() - t3;
        printf("%d\t\t%d\t\t%f\t\t%f\t\t\t\t\t  %f\n", count, i, (double)t1 / CLOCKS_PER_SEC, (double)t2 / CLOCKS_PER_SEC, (double)t3 / CLOCKS_PER_SEC);
        count++;
    }
}

int main()
{
    tabularOutput();
    return 0;
}

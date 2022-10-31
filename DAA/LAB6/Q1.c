#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
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
        heapSort(arr, i);
        t1 = clock() - t1;
        clock_t t2 = clock();
        heapSort(arr, i);
        t2 = clock() - t2;
        bubbleSort(arr, i);
        clock_t t3 = clock();
        heapSort(arr, i);
        t3 = clock() - t3;
        printf("%d\t\t%d\t\t%f\t\t%f\t\t\t\t\t  %f\n", count, i, (double)t1 / CLOCKS_PER_SEC, (double)t2 / CLOCKS_PER_SEC, (double)t3 / CLOCKS_PER_SEC);
        count++;
    }
}
/*void array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
*/
int main()
{
   /* printf("MAX HEAP AND PRIORITY QUEUE MENU\n");
    printf("0. Exit\n");
    printf("1.n Random Numbers=>array\n");
    printf("2.Display array\n");
    printf("3.Sort array in Ascending Order(Max-Heap Sort)\n");
    printf("4.Time Complexity (tabular output)\n");
    printf("5.Extract largest element from heap\n");
    printf("6.Insert element in heap\n");
    printf("7.Delete element from heap\n");
    int c, n;
    int arr[n];
    do
    {
        printf("ENTER YOUR CHOICE->");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("ENTER n->");
            scanf("%d", &n);
            array(arr, n);
            break;
        case 2:
            printf("ARRAY IS->");
            printArray(arr, n);
            break;
        case 3:
            printf("SORTED ARRAY IS->");
            heapSort(arr, n);
            printArray(arr, n);
            break;
        case 4:
            tabularOutput();
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (c != 0);
    */
   tabularOutput();
   return 0;
}
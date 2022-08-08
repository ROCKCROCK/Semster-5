#include <stdio.h>
int main()
{
    int size, i;
    printf("Enter the size of array->");
    scanf("%d", &size);
    int a[size];
    printf("Enter the array->");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    int max = a[0], max1 = a[size - 2];
    for (i = 0; i < size; i++)
    {
        if (a[i] > max)
        {
            max1 = max;
            max = a[i];
        }
        if (a[i] > max1 && a[i] != max)
        {
            max1 = a[i];
        }
    }
    printf("maximum 1->%d  maximum 2->%d", max, max1);
    return 0;
}
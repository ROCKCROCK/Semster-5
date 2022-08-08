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
    int b, f;
    printf("Enter the element to be searched in the array->");
    scanf("%d", &b);
    for (i = 0; i < size; i++)
    {
        if (a[i] == b)
        {
            f = 0;
            break;
        }
    }
    if (f == 0)
    {
        printf("Number found at location->%d", i + 1);
    }
    else
    {
        printf("NOT FOUND!");
    }
    return 0;
}
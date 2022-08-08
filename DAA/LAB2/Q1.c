#include <stdio.h>
int main()
{
    int i, j, n, d, c = 0, e = 0;
    printf("Enter no. of elements->");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter %d  element->", i + 1);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                d = a[i];
                a[i] = a[j];
                a[j] = d;
                c++;
            }
            e++;
        }
    }
    printf("array is->\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nNo. of swap happened-> %d\n", c);
    printf("%d", e);
    return 0;
}
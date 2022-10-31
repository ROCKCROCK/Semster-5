#include <stdio.h>
#include <stdlib.h>
struct activity
{
    int start;
    int finish;
};
void sort(struct activity *a, int n)
{
    int i, j;
    struct activity temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (a[j].finish > a[j + 1].finish)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void activity_selection(struct activity *a, int n)
{
    int i, j;
    printf("The selected activities are: ");
    i = 0;
    printf("%d,", i);
    for (j = 1; j < n; j++)
    {
        if (a[j].start >= a[i].finish)
        {
            printf("%d,", j);
            i = j;
        }
    }
}
int main()
{
    int n, i;
    printf("Enter the number of activities:");
    scanf("%d", &n);
    struct activity *a = (struct activity *)malloc(n * sizeof(struct activity));
    for (i = 0; i < n; i++)
    {
        printf("Enter the start time of (%d) activity->", i + 1);
        scanf("%d", &a[i].start);
        printf("Enter the finish time of (%d) activity->", i + 1);
        scanf("%d", &a[i].finish);
    }
    sort(a, n);
    activity_selection(a, n);
    return 0;
}
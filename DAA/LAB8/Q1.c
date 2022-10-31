
#include <stdio.h>
#include <stdlib.h>
struct item
{
    int weight;
    int profit;
    float ratio;
};
void sort(struct item *a, int n)
{
    int i, j;
    struct item temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (a[j].ratio > a[j + 1].ratio)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void Fractional_Knap(struct item *a, int n, int W)
{
    int i;
    float maxprofit = 0;
    for (int i = 0; i < n; i++)
    {
        a[i].ratio = (float)(a[i].profit / a[i].weight);
    }

    for (int j = 0; j < n; j++)
    {
        if (a[j].weight <= W)
        {
            maxprofit += a[j].profit;
            W -= a[j].weight;
        }
        else
        {
            maxprofit += a[j].ratio * W;
            break;
        }
    }
    printf("Maximum profit is:%0.2f", maxprofit);
}
int main()
{
    int n, i;
    printf("Enter the number of items:");
    scanf("%d", &n);
    struct item *a = (struct item *)malloc(n * sizeof(struct item));

    for (i = 0; i < n; i++)
    {
        printf("Enter the weight of (%d) item->", i + 1);
        scanf("%d", &a[i].weight);
        printf("Enter the profit of (%d) item->", i + 1);
        scanf("%d", &a[i].profit);
    }
    printf("Enter the maximum weight:");
    scanf("%d", &i);
    sort(a, n);
    Fractional_Knap(a, n, i);
    return 0;
}

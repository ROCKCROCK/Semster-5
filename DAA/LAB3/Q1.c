#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int gat(long n)
{
    long i = 2;
    while (i < n)
    {
        if (n % i == 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int rat(int n, int i)
{
    if (n <= 2)
        return (n == 2) ? 1 : 0;
    if (n % i == 0)
        return 0;
    if (i * i > n)
        return 1;
    return rat(n, i + 1);
}
long long c[10000];
void coef(int n)
{
    c[0] = 1;
    for (int i = 0; i < n; c[0] = -c[0], i++)
    {
        c[1 + i] = 1;
        for (int j = i; j > 0; j--)
            c[j] = c[j - 1] - c[j];
    }
}
int aks(int n)
{
    coef(n);
    c[0]++, c[n]--;
    int i = n;
    while (i-- && c[i] % n == 0)
        ;
    return i < 0;
}
int main()
{
    clock_t start, end;
    double time_taken;
    long int n;
    srand(time(0));
    for (int i = 1; i <= 10; i++)
    {
        printf("Enter value->");
        scanf("%ld", &n);
        start = clock();
        if (gat(n) == 0)
            printf("It is not a prime number\n");
        else
            printf("It is a prime number\n");
        end = clock();
        time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("General algorithm time(Algorithm 1) -> %f\n", time_taken);

        start = clock();
        if (rat(n, 2) == 0)
            printf("It is not a prime number\n");
        else
            printf("It is a prime number\n");
        end = clock();
        time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Recursive algorithm time(Algorithm 2) -> %f\n", time_taken);

        start = clock();
        if (aks(n) == 0)
            printf("It is not a prime number\n");
        else
            printf("It is a prime number\n");
        end = clock();
        time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("AKS algorithm time (Algorithm 3)-> %f\n", time_taken);
    }
    return 0;
}
#include <stdio.h>

int algo1(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > n / 2)
        {
            return arr[i];
        }
    }

    return -1;
}

int algo2(int arr[], int n)
{
    int votes = 0, candidate;
    for (int i = 0; i < n; i++)
    {
        if (votes == 0)
        {
            candidate = arr[i];
            votes = 1;
        }
        else
        {
            if (arr[i] == candidate)
            {
                votes++;
            }
            else
            {
                votes--;
            }
        }
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == candidate)
            {
                count++;
            }
        }

        if (count > n / 2)
        {
            return candidate;
        }
        else
        {
            return -1;
        }
    }
}

int main()
{

    int n = 10;

    int arr[] = {
        4, 4, 4, 4, 4, 4, 5, 2, 7, 1};

    int res1 = algo1(arr, n);
    int res2 = algo2(arr, n);

    printf("Result of n^2 algo-> %d\n", res1);
    printf("Result of n algo-> %d\n", res2);
}
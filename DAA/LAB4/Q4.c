#include <stdio.h>

int maxSubArray(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (sum > max)
            {
                max = sum;
            }
        }
    }

    return max;
}

int main()
{

    int arr[] = {
        -1, -3, -7, -2, -1, -5, -1, -2, -4, -6, -3};
    int n = 11;

    int res = maxSubArray(arr, 11);

    printf("Max Sum of the subaaray is %d", res);
}
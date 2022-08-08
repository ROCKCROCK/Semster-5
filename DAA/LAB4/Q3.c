#include <stdio.h>
double sqrt1(int n, int prec)
{
    double s = 0, d = 1;
    for (int i = 0; i < prec; i++, d /= 10)
    {
        for (; (s + d) * (s + d) <= n; s += d)
            ;
        if (s * s == n)
            return s;
    }
    return s;
}
#include <stdio.h>

float findSQRT(int number)
{
    int start = 0, end = number;
    int mid;

    float ans;

    while (start <= end)
    {

        mid = (start + end) / 2;

        if (mid * mid == number)
        {
            ans = mid;
            break;
        }

        if (mid * mid < number)
        {

            ans = start;

            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }
    }

    float increment = 0.1;
    for (int i = 0; i < 5; i++)
    {
        while (ans * ans <= number)
        {
            ans += increment;
        }
        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
}

int main()
{
    int x = 11;
    printf("%0.3f\n", sqrt1(x, 4));
    int num = 45;
    float res = findSQRT(45);
    printf("Sqrt of the number %d is %f ", num, res);
    return 0;
}
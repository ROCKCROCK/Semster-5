#include <string.h>
#include <stdio.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int lcs(char *x, char *y, int m, int n)
{
    int l[m + 1][n + 1];
    int i, j;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                l[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                l[i][j] = l[i - 1][j - 1] + 1;
            else
                l[i][j] = max(l[i - 1][j], l[i][j - 1]);
        }
    }
    int index = l[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';
    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            lcs[index - 1] = x[i - 1];
            i--;
            j--;
            index--;
        }
        else if (l[i - 1][j] > l[i][j - 1])
            i--;
        else
            j--;
    }
    printf("Length of LCS is %d\n", l[m][n]);
    printf("lcs is-> %s\n", lcs);
}
int main()
{
    char x[20], y[20];
    int m, n;
    printf("Enter the first string:");
    scanf("%s", x);
    printf("Enter the second string:");
    scanf("%s", y);
    m = strlen(x);
    n = strlen(y);
    lcs(x, y, m, n);
    return 0;
}

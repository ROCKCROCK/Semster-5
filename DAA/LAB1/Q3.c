#include <stdio.h>
int main()
{
    char name[30];
    int i, j = 0;
    printf("Enter your full name->");
    gets(name);
    char ini[14];

    for (i = 0; name[i] != '\0'; i++)
    {
        if (name[i] == ' ')
        {
            if (name[i + 1] >= 97)
            {
                ini[j] = name[i + 1] - 32;
                ++j;
            }
            else
            {
                ini[j] = name[i + 1];
                ++j;
            }
        }
    }
    printf("%s", ini);

    return 0;
}
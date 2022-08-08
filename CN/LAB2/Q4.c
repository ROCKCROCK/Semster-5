#include <stdio.h>
int main()
{
    unsigned int value = 0x2;
    char *p = (char *)&value;
    if (*p == 2)
    {
        printf("Little Endian");
    }
    else
    {
        printf("Big Endian");
    }
    return 0;
}
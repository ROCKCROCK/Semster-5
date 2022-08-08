#include <stdio.h>

struct pkt
{
    unsigned char ch1;
    unsigned char ch2[2];
    unsigned char ch3;
};

int main()
{

    unsigned int value = 20051538;

    int a, b, c, d;

    a = (value & 0xFF);
    b = ((value >> 8) & 0xFF);
    c = ((value >> 16) & 0xFF);
    d = ((value >> 24) & 0xFF);

    struct pkt abc;

    abc.ch1 = a;
    abc.ch2[0] = b;
    abc.ch2[1] = c;
    abc.ch3 = d;

    int num = ((int)(abc.ch3 << 24) + (int)(abc.ch2[1] << 16) + (int)(abc.ch2[0] << 8) + (int)(abc.ch1));
    printf("The Number is(Combined Byte)->%d", num);

    return 0;
}
#include <stdio.h>
void swap(float *, float *);
void swap(float *a, float *b)
{
    float c;
    c = *a;
    *a = *b;
    *b = c;
}
int main()
{
    float a, b;
    printf("Enter 1st Float Value->");
    scanf("%f", &a);
    printf("Enter 2nd Float Value->");
    scanf("%f", &b);
    printf("Before Swapping a->%0.2f\n", a);
    printf("Before Swapping b->%0.2f\n", b);
    swap(&a, &b);
    printf("After Swapping a->%0.2f\n", a);
    printf("After Swapping b->%0.2f\n", b);
    return 0;
}
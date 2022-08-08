#include <stdio.h>
struct dob
{
    int date;
    int month;
    int year;
};
struct student
{
    char name[30];
    long int rollno;
    float cgpa;
    struct dob d;
};
void in(struct student *);
void out(struct student);
void in(struct student *a)
{
    printf("Enter Name->");
    scanf("%30[^\n]s", &a->name);
    printf("Enter Roll No.->");
    scanf("%ld", &a->rollno);
    printf("Enter cgpa->");
    scanf("%f", &a->cgpa);
    printf("Enter dob->");
    printf("\nDate->");
    scanf("%d", &a->d.date);
    printf("Month->");
    scanf("%d", &a->d.month);
    printf("Year->");
    scanf("%d", &a->d.year);
}
void out(struct student a)
{
    printf("Name-> %s\n", a.name);
    printf("Roll No.-> %ld\n", a.rollno);
    printf("cgpa-> %0.2f\n", a.cgpa);
    printf("DOB-> %d-%d-%d\n", a.d.date, a.d.month, a.d.year);
}
int main()
{
    struct student p;
    in(&p);
    printf("\n**Printing**\n");
    out(p);
    return 0;
}
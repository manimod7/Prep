#include<stdio.h>

    int main()
{
    int year;

    printf("Enter any year: ");
    scanf("%d", &year);
    (year % 4 == 0 && year % 100 != 0) ? printf("Leap year\n") : (year % 400 == 0) ? printf("Leap Year\n"): printf("Not a leap year\n");

    return 0;
}
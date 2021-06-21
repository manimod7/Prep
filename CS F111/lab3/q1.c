#include <stdio.h>

int main()
{
    double num1,num2,num3,num4,num5;
    printf("Enter the marks in first subject\n");
    scanf("%lf", &num1);
    printf("Enter the marks in second subject\n");
    scanf("%lf", &num2);
    printf("Enter the marks in third subject\n");
    scanf("%lf", &num3);
    printf("Enter the marks in fourth subject\n");
    scanf("%lf", &num4);
    printf("Enter the marks in fifth subject\n");
    scanf("%lf", &num5);
    double sum =num1+num2+num3+num4+num5;
    if(sum/5>=75)
        printf("Pass\n");
    else
        printf("Fail\n");
    return 0;
}



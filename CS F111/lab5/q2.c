#include <stdio.h>
int main()
{
    int age, premium, max_amount;
    char health, location, sex;
    scanf("%c %d %c %c", &health, &age, &location, &sex);
    if ((health == 'e') && ((age >= 18) && (age <= 30)) && (location == 'c') && (sex == 'm'))
    {
        premium = 50;
        max_amount = 3;
        printf("The payable premium is Rs.%d", premium);
        printf("\tThe maximum policy amount is Rs. %d Lakhs INR", max_amount);
    }
    else if ((health == 'e') && ((age >= 18) && (age <= 30)) && (location == 'c') && (sex == 'f'))
    {
        premium = 30;
        max_amount = 2;
        printf("The payable premium is Rs%d", premium);
        printf("\t The maximum policy amount is Rs. %d Lakhs INR", max_amount);
    }
    else if ((health == 'p') && ((age >= 18) && (age <= 30)) && (location == 'v') && (sex == 'm'))
    {
        premium = 70;
        max_amount = 1;
        printf("The payable premium is Rs%d", premium);
        printf("\t The maximum policy amount is Rs. %d Lakhs INR", max_amount);
    }
    else
    {
        printf("This person is not insured.");
    }
}
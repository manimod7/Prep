//Fibonacci

#include <stdio.h>

void main()
{
    int num1 = 0, num2 = 1,no, counter, fab;
    
    printf("ENTER LENGTH OF SERIES (N): ");
    scanf("\n%d",&no);
    
    printf("<----FIBONACCI SERIES----->");
    printf("\n%d %d", num1, num2);
    
    for(counter = 1; counter <= no-2; counter++){
        fab = num1+ num2;
        printf(" %d",fab);
        num1=num2;
        num2=fab;
    }
}
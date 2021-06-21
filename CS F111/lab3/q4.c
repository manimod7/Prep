#include <stdio.h>

int main() {
    
    char op;
    float num1, num2;
    
    printf("Enter operator either + or - or * or /: ");
    scanf("%c",&op);
    
    printf("Enter two operands: ");
    scanf("%f", &num1);
    scanf("%f", &num2);
    
    if(op == '+')
        printf("Result: %f", num1+num2);
    else if(op == '-')
        printf("Result: %f", num1-num2);
    else if(op == '*')
        printf("Result: %f", num1*num2);
    else if(op == '/')
        printf("Result: %f", num1/num2);
    else
        printf("Error! operator is not correct");
        
    return 0;
}
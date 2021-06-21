//Square Root of a number

#include <stdio.h>

void main()
{
    int n;
    
    float temp, squareroot;
    
    printf("Provide the number: ");
    
    scanf("%d", &n);
    squareroot = n/2;
    temp = 0;
    
    while(squareroot != temp){
        temp = squareroot;
        squareroot = (n/temp + temp) / 2;
    }
    
    printf("The squareroot of '%d' is '%f'",n, squareroot);
}
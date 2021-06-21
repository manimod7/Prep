//Odd Even Increase Decrease and print Question 4

#include<stdio.h>
int main(){

    int n;
    printf("Enter a number\n");
    scanf("%d",&n);
    (n%2==0)?printf("%d",--n):printf("%d",++n);
    return 0;
}
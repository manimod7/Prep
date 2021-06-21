#include<stdio.h>
#include<math.h>

int main(){
    float a,b,c,root1,root2;
    printf("Enter the values of a,b,c of the quadratic equation ax^2+bx+c=0\n");
    scanf("%f%f%f",&a,&b,&c);
    float D = b*b-4*a*c;
    if(D>=0){
        root1 =(-b+sqrt(D))/2*a;
        root2 =(-b-sqrt(D))/2*a; 
        printf("Root 1 = %f\nRoot 2 = %f\n",root1,root2);
    }
    else
        printf("\nImaginary Roots.\n");
    return 0;
}
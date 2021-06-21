    #include<stdio.h>  
    int main()    
    {    
    int i,fact=1,number;    
    printf("Enter a number: ");    
    scanf("%d",&number);
    if(number<0)
        printf("Cannot calculate factorial for negative input.\n");
        else{
            for(i=1;i<=number;i++){    
            fact=fact*i;    
    }    
    printf("Factorial of %d is: %d\n",number,fact); 
        }    
    return 0;  
    }   
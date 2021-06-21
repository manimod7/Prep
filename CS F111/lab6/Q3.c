#include <stdio.h>
#include <limits.h>
int main()
{
    printf("Minimum Int is %d\n", INT_MIN);
    printf("Maximum Int is %d\n", INT_MAX);
    printf("Minimum int * Max Int is %d\n", INT_MIN * INT_MAX);
    printf("Minimum int * Max Int considering overflow is %li\n", (long)INT_MIN * (long)INT_MAX);

    return 0;
}

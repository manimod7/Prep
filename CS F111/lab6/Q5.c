//Question 5 Print Value of division in decimal form
#include <stdio.h>
int main()
{
    int n, m;
    printf("Enter numbers a and b to get a/b\n");
    scanf("%d %d", &n, &m);
    printf("%f", (float)n / (float)m);
    return 0;
}

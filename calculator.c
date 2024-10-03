#include <stdio.h>
#include <stdlib.h>

int main () {
    
    int num1;
    int num2;
    printf("Enter first int: ");
    scanf("%d", &num1);
    printf("Enter second int: ");
    scanf("%d", &num2);
    printf("Answer: %d\n", num1 + num2);
    
    double num3;
    double num4;
    printf("Enter first float: ");
    scanf("%lf", &num3);
    printf("Enter second float: ");
    scanf("%lf", &num4);
    printf("Answer: %f\n", num3 + num4);
    
    return 0;
}

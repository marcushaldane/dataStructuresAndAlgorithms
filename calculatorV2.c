#include <stdio.h>
#include <stdlib.h>

int main () {
    
    double num1;
    double num2;
    char op;

    printf("Enter first float: ");
    scanf("%lf", &num1);
    printf("Enter an operator: ");
    scanf(" %c", &op);
    printf("Enter second float: ");
    scanf("%lf", &num2);

    if(op == '+') {
        printf("%lf %c %lf = %lf\n", num1, op, num2, num1 + num2);
    } else if (op == '-') {
        printf("%lf %c %lf = %lf\n", num1, op, num2, num1 - num2);
    } else if (op == '*') {
        printf("%lf %c %lf = %lf\n", num1, op, num2, num1 * num2);
    } else if (op == '/') {
        printf("%lf %c %lf = %lf\n", num1, op, num2, num1 / num2);
    } else {
        printf("Invalid Calculation");
    }



    
    return 0;
}

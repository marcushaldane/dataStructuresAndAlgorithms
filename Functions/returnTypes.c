#include <stdio.h>
#include <stdlib.h>

double cubic(double number);

int main () {    

    double userNum;
    printf("Enter an double: ");
    scanf("%lf", &userNum);
    printf("the cube of %lf is %lf\n", userNum, cubic(userNum));

    return 0;
}

double cubic(double number) {
    return number * number * number;
}

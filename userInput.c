#include <stdio.h>
#include <stdlib.h>

int main () {
    
    int age;
    printf("enter your age: ");
    scanf("%d", &age);
    printf("you are %d years old. \n", age);

    float gpa;
    printf("enter your gpa: ");
    scanf("%f", &gpa);
    printf("you have a %.2f gpa.\n", gpa);

    double pi;
    printf("enter as many digits of pi as you can remember: ");
    scanf("%lf", &pi);
    printf("you entered the following approximation of pi: %lf\n", pi);

    char name[20];
    printf("enter your name: ");
    // scanf delimits user input on space char
    // scanf("%s", name);
    fflush(stdin); //fgets() may break after using scanf() above because of how both functions use '\n' chars
    fgets(name, 20, stdin);
    printf("hello %s\n", name);
     
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main () {
    
    int age = 25;
    double gpa = 4.0;
    char grade = 'A';
    
    printf("The value of the variable age: %d is stored at: %p\n", age, &age);
    printf("The value of the variable gpa: %lf is stored at: %p\n", gpa, &gpa);
    printf("The value of the variable grade: %c is stored at: %p\n", grade, &grade);

    return 0;
}

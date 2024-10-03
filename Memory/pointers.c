#include <stdio.h>
#include <stdlib.h>

int main () {
    
    int age = 25;
    int * pAge = &age;

    printf("The value of the variable age: %d is stored at: %p\n", age, pAge);
    *pAge = 26;
    printf("After changing the value pointed to by pAge, \n");
    printf("The value of the variable age: %d is stored at: %p\n", age, pAge);

    return 0;
}

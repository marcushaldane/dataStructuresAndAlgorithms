#include <stdio.h>
#include <stdlib.h>


int main () {
    
    int index = 1;
    printf("Entering While Loop\n");
    while(index <= 5) {
        printf("%d\n", index);
        index++;
    }
    

    do {
        printf("Now in Do - While Loop\n%d\n", index);
        index++;
    } while(index <= 5); 


    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main () {
    
    int *a = malloc(sizeof(int) * 10);

    for(int i = 0; i < 10; i++) {
        a[i] = 10 - i;
    }

    // printf("After populating a:\n");
    for(int i = 0; i < 10; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    } 
    printf("a: %p\n", a);
    printf("\n");

    int *save = a;
    free(a);

    printf("save: %p\n", save);
    for(int i = 0; i < 10; i++) {
        printf("save[%d] = %d\n", i, save[i]);
    } 
    printf("\n");

    return 0;
}

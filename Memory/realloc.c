#include <stdio.h>
#include <stdlib.h>

int main () {
    
    int *a = malloc(sizeof(int) * 5);

    for(int i = 0; i < 5; i++) {
        a[i] = 5 - i;
    }

    for(int i = 0; i < 5; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    } 
    printf("a before: %p\n", a);
    printf("\n");

    a = realloc(a, sizeof(int) * 10);

    for (int i = 5; i < 10; i++) {
        a[i] = 15 - i;
    }

    for(int i = 0; i < 10; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    } 
    printf("a after: %p\n", a);
    printf("\n");
    
    free(a);
    //====================================
    printf("====================================\n");

    int *b = malloc(sizeof(int) * 5);
    int *c = malloc(sizeof(int) * 5);

    for(int i = 0; i < 5; i++) {
        b[i] = 5 - i;
        c[i] = 20 - i;
    }

    for(int i = 0; i < 5; i++) {
        printf("b[%d] = %d\n", i, b[i]);
    } 
    printf("b before: %p\n", b);
    printf("\n");

    for(int i = 0; i < 5; i++) {
        printf("c[%d] = %d\n", i, c[i]);
    } 
    printf("c: %p\n", c);
    printf("\n");

    int *saveB = b;
    b = realloc(b, sizeof(int) * 10);

    for (int i = 5; i < 10; i++) {
        b[i] = 15 - i;
    }

    for(int i = 0; i < 10; i++) {
        printf("b[%d] = %d\n", i, b[i]);
    } 
    printf("b after: %p\n", b);
    printf("\n");

    free(b);
    free(c);

    printf("saveB: %p\n", saveB);
    for(int i = 0; i < 5; i++) {
        printf("saveB[%d] = %d\n", i, saveB[i]);
    } 

    return 0;
}

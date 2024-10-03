#include <stdio.h>
#include <stdlib.h>


int main () {
    
    int powersOfTwo[] = {1, 2, 4, 8, 16, 32};
    for(int i = 0; i < 6; i++) {
        printf("2^%d = %d\n", i, powersOfTwo[i]);
    }

    return 0;
}

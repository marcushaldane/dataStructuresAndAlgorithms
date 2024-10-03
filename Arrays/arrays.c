#include <stdio.h>
#include <stdlib.h>

int main () {
    
    int powersOfTwo[] = {1, 2, 4, 8, 16, 32};
    printf("%d\n", powersOfTwo[3]);

    int wrongPowersOfTwo[5];
    wrongPowersOfTwo[0] = 3;
    printf("%d\n", wrongPowersOfTwo[0]);


    return 0;
}

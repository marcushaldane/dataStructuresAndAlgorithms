#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int findMaxConsecutiveOnes(int* nums, int numsSize);
void printArray(int* nums, int numsSize);

int main () {
    
    int numsSize = 20;
    int nums[numsSize];
    srand(time(NULL)); 
    int r;
    for(int i = 0; i < numsSize; i++) {
        nums[i] = rand() % 2;
    }

    printf("Maximum consecutive ones found: %d\n", findMaxConsecutiveOnes(nums, numsSize));
    printArray(nums, numsSize);

    return 0;
}

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int onesCount = 0;
    int maxOnes = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == 1) {
            onesCount++;
        } else {
            onesCount = 0;
        }
        if(onesCount > maxOnes) {
            maxOnes = onesCount;
        }
        printf("onesCount: %d\nmaxOnes: %d\nindex: %d\n==============\n", onesCount, maxOnes, i);
    }
    return maxOnes;
}

void printArray(int* nums, int numsSize) {
    for(int i = 0; i < numsSize; i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n");
}
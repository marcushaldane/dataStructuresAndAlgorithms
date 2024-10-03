#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findNumbers(int* nums, int numsSize);
void printArray(int* nums, int numsSize);

int main () {
    
    int numsSize = 20;
    int nums[numsSize];
    srand(time(NULL)); 
    int r;
    for(int i = 0; i < numsSize; i++) {
        nums[i] = rand()% 10000;
    }
    printArray(nums, numsSize);

    printf("Even digit numbers found: %d\n", findNumbers(nums, numsSize));

    return 0;
}

int findNumbers(int* nums, int numsSize) {
    int evenDigitNumsFound = 0;
    for(int i = 0; i < numsSize; i++) {
        int numsDecomposed = nums[i];
        int numDigits = 0;
        // printf("--------------------\n");
        while(numsDecomposed > 0) {
            // printf("numsDecomposed: %d\n", numsDecomposed);
            // printf("numDigits: %d\n", numDigits);
            numsDecomposed = numsDecomposed / 10;
            numDigits++;
        }
        // printf("numsDecomposed: %d\n", numsDecomposed);
        // printf("numDigits: %d\n", numDigits);
        if(numDigits % 2 == 0) {
            evenDigitNumsFound++;
        }
        // printf("evenDigitNumsFound: %d\n", evenDigitNumsFound);
    }   
    return evenDigitNumsFound;
}

void printArray(int* nums, int numsSize) {
    for(int i = 0; i < numsSize; i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n");
}
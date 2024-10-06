#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize);
void printArray(int* nums, int numsSize);

int main () {
    int returnSize = 5;

    int testCase1[] = {-4, -1, 0, 3, 10}; //expected output: {0,1,9,16,100}
    int testCase1Size = 5;
    printArray(testCase1, testCase1Size);
    int* sortedArr = sortedSquares(testCase1, testCase1Size, &returnSize);
    printArray(sortedArr, returnSize);

    int testCase2[] = {-7, -3, 2, 3, 11}; //expected output: {4,9,9,49,121}
    int testCase2Size = 5;
    printArray(testCase2, testCase2Size);
    int* sortedArr2 = sortedSquares(testCase2, testCase2Size, &returnSize);
    printArray(sortedArr2, returnSize);

    free(sortedArr);
    free(sortedArr2);

    return 0;
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *returnArray = (int*)malloc(sizeof(int) * numsSize);
    if (numsSize == 0) {
        return returnArray;
    }
    int left = 0;
    int right = numsSize - 1;
    for (int i = 0; i < numsSize; i++) {
        if(abs(nums[left]) > abs(nums[right])) {
            returnArray[numsSize - 1 - i] = nums[left]*nums[left];
            left++; 
        } else {
            returnArray[numsSize - 1 - i] = nums[right]*nums[right];
            right--; 
        }
    }
    return returnArray;
}

void printArray(int* nums, int numsSize) {
    for(int i = 0; i < numsSize; i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n");
}



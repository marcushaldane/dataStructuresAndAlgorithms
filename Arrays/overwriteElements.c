#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int* nums, int numsSize);
int* replaceElements(int* arr, int arrSize, int* returnSize);

int main () {

    int testCase1[] = {17,18,5,4,6,1}; //expected output: {18,6,6,6,1,-1}
    int testCase1Size = 6;
    int returnArray1Size = testCase1Size;
    printArray(testCase1, testCase1Size);
    int* returnArray1 = replaceElements(testCase1, testCase1Size, &returnArray1Size);
    printf("Expected Output: [ 18, 6, 6, 6, 1, -1 ]\nActual Output: ");
    printArray(returnArray1, returnArray1Size);    
    free(returnArray1);
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    printf("==========================================\n");


    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    int *returnArray = (int*)malloc(sizeof(int) * arrSize);
    int greatestElementRight = -1;
    for(int i = arrSize - 1; i >= 0; i--) {
        returnArray[i] = greatestElementRight;
        if(arr[i] > greatestElementRight) {
            greatestElementRight = arr[i];
        }
    }
    return returnArray;
}

void printArray(int* arr, int arrSize) {
    printf("[ ");
    for(int i = 0; i < arrSize - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d ]\n",arr[arrSize - 1]);
}
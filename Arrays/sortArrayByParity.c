#include <stdio.h>
#include <stdlib.h>


void printArray(int* nums, int numsSize);
int* sortArrayByParity(int* nums, int numsSize, int* returnSize);

int main () {

    int array1[] = {3,1,2,4}; 
    int array1Size = 4;
    int rtnArray1Size;
    printf("array1 Initially: ");
    printArray(array1, array1Size);
    sortArrayByParity(array1, array1Size, &rtnArray1Size);
    printf("Expected Output: [ 2, 4, 3, 1 ]\nActual Output: "); // The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
    printArray(array1, array1Size);
    
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    printf("==========================================\n");
    int array2[] = {0};
    int array2Size = 1;
    int rtnArray2Size;
    printf("array2 Initially: ");
    printArray(array2, array2Size);
    sortArrayByParity(array2, array2Size, &rtnArray2Size); 
    printf("Expected Output: [ 0 ]\nActual Output: ");
    printArray(array2, array2Size);
    
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    // int *returnArray = (int*)malloc(sizeof(int) * numsSize);
    int nextAvailableIndex = 0;
    int temp;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] % 2 == 0) {
            temp = nums[nextAvailableIndex];
            nums[nextAvailableIndex] = nums[i];
            nums[i] = temp;
            nextAvailableIndex++;
        }
    }
    return nums;
}


void printArray(int* arr, int arrSize) {
    printf("[ ");
    for(int i = 0; i < arrSize - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d ]\n",arr[arrSize - 1]);
}
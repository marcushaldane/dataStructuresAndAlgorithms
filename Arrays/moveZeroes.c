#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int* arr, int arrSize);
void moveZeroes(int* nums, int numsSize);

int main () {
    
    int array1[] = {0,1,0,3,12}; 
    int array1Size = 5;
    printf("array1 Initially: ");
    printArray(array1, array1Size);
    moveZeroes(array1, array1Size); // expected k value = 2
    printf("Expected Output: [ 1, 3, 12, 0, 0 ]\nActual Output: ");
    printArray(array1, array1Size);
    
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    printf("==========================================\n");
    int array2[] = {0};
    int array2Size = 1;
    printf("array2 Initially: ");
    printArray(array2, array2Size);
    moveZeroes(array2, array2Size); // expected k value = 5
    printf("Expected Output: [ 0 ]\nActual Output: ");
    printArray(array2, array2Size);
    
    return 0;
}

void moveZeroes(int* nums, int numsSize) {
    if(sizeof(nums) == 0 || numsSize == 0) {
        return;
    }
    
    int nextOpenIndex = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != 0) {
            nums[nextOpenIndex] = nums[i];
            nextOpenIndex++;
        }
    }
    for(int i = nextOpenIndex; i < numsSize; i++) {
        nums[i] = 0;
    }
}

void printArray(int* arr, int arrSize) {
    printf("[ ");
    for(int i = 0; i < arrSize - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d ]\n",arr[arrSize - 1]);
}
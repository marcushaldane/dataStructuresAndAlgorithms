#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int* arr, int arrSize);
int removeDuplicates(int* nums, int numsSize);

int main () {
    
    int array1[] = {1,1,2}; 
    int array1Size = 3;
    printf("array1 Initially: \n");
    printArray(array1, array1Size);
    int k1 = removeDuplicates(array1, array1Size); // expected k value = 2
    printf("Expected Output: [ 1, 2, _ ]\nActual Output: ");
    printArray(array1, array1Size);
    printf("Expected K: 2, Actual K: %d\n", k1);
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    printf("==========================================\n");
    int array2[] = {0,0,1,1,1,2,2,3,3,4};
    int array2Size = 10;
    printf("array2 Initially: \n");
    printArray(array2, array2Size);
    int k2 = removeDuplicates(array2, array2Size); // expected k value = 5
    printf("Expected Output: [ 0, 1, 2, 3, 4, _, _, _, _, _ ]\nActual Output: ");
    printArray(array2, array2Size);
    printf("Expected K: 5, Actual K: %d\n", k2);

    return 0;
}

int removeDuplicates(int* nums, int numsSize) {

    if(sizeof(nums) == 0 || numsSize == 0) {
        return 0;
    }

    int lastSeenNumber = nums[0];
    int nextOpenIndex = 1;

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != lastSeenNumber) {
            nums[nextOpenIndex] = nums[i];
            lastSeenNumber = nums[i];
            nextOpenIndex++;
        }
    }
    return nextOpenIndex;
}

void printArray(int* arr, int arrSize) {
    printf("[ ");
    for(int i = 0; i < arrSize - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d ]\n",arr[arrSize - 1]);
}
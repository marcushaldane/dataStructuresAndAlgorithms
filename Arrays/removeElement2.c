#include <stdio.h>
#include <stdlib.h>


void printArray(int* nums, int numsSize);
int removeElement(int* nums, int numsSize, int val);

int main () {

    int array1[] = {3,2,2,3}; 
    int array1Size = 4;
    int val1ToRemove = 3;
    int k1 = removeElement(array1, array1Size, val1ToRemove);
    printf("Expected Output: [ 2, 2, _, _ ]\nActual Output: "); 
    printArray(array1, array1Size);
    printf("k1: %d\n", k1);
    
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    printf("==========================================\n");
    int array2[] = {0,1,2,2,3,0,4,2};
    int array2Size = 8;
    int val2ToRemove = 2;
    int k2 = removeElement(array2, array2Size, val2ToRemove); 
    printf("Expected Output: [ 0, 1, 4, 0, 3, _, _, _ ]\nActual Output: ");
    printArray(array2, array2Size);
    printf("k2: %d\n", k2);
    
    return 0;
}

int removeElement(int* nums, int numsSize, int val) {
    // printf("Removing %d\n", val);
    int numItemsRemoved = 0;
    for(int i = 0; i < numsSize; i++) {
        // printf("i: %d\n", i);
        // printArray(nums, numsSize);
        if(nums[i] == val) {
            nums[i] = nums[numsSize - 1 - numItemsRemoved];
            nums[numsSize - 1 - numItemsRemoved] = -99; // arbitrary value
            numItemsRemoved++;
            i--;
        }
    }
    return (numsSize - numItemsRemoved);
}

void printArray(int* arr, int arrSize) {
    printf("[ ");
    for(int i = 0; i < arrSize - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d ]\n",arr[arrSize - 1]);
}
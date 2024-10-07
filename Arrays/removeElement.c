#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int arrSize);
int removeElement(int* nums, int numsSize, int val);

int main () {
    
    int array1[] = {3,2,2,3}; 
    int val1 = 3;
    int array1Size = 4;
    printArray(array1, array1Size);
    int k = removeElement(array1, array1Size, val1);
    printf("Expected Output: [ 2, 2, _, _ ]\nActual Output: ");
    printArray(array1, array1Size);
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    printf("==========================================\n");
    int array2[] = {0,1,2,2,3,0,4,2};
    int val2 = 2;
    int array2Size = 8;
    printArray(array2, array2Size);
    int k2 = removeElement(array2, array2Size, val2);
    printf("Expected Output: [ 0, 1, 4, 0, 3, _, _, _ ]\nActual Output: ");
    printArray(array2, array2Size);

    return 0;
}


int removeElement(int* nums, int numsSize, int val) {
    int nonValElements = 0;
    int length = numsSize - 1;
    for(int i = length; i >= 0; i--) {
        if(nums[i] == val) { // ex: nums[4] = 5 == val 
            for (int j = i + 1; j <= length; j++) { // ex: j = 5; j <=7 j++
                nums[j - 1] = nums[j];
            }
            nums[length] = -99; // -99 is a placeholder for deleting a value
            length--;
        } else {
            nonValElements++;
        }
    }
    return nonValElements;
}

void printArray(int* arr, int arrSize) {
    printf("[ ");
    for(int i = 0; i < arrSize - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d ]\n",arr[arrSize - 1]);
}
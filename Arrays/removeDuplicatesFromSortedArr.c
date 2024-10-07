#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int* arr, int arrSize);
int removeDuplicates(int* nums, int numsSize);

int main () {
    
    int array1[] = {1,1,2}; 
    int array1Size = 3;
    printArray(array1, array1Size);
    int k1 = removeDuplicates(array1, array1Size); // expected k value = 2
    printf("Expected Output: [ 1, 2, _ ]\nActual Output: ");
    printArray(array1, array1Size);
    printf("Expected K: 2, Actual K: %d\n", k1);
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    printf("==========================================\n");
    int array2[] = {0,0,1,1,1,2,2,3,3,4};
    int array2Size = 10;
    printArray(array2, array2Size);
    int k2 = removeDuplicates(array2, array2Size); // expected k value = 5
    printf("Expected Output: [ 0, 1, 2, 3, 4, _, _, _, _, _ ]\nActual Output: ");
    printArray(array2, array2Size);
    printf("Expected K: 5, Actual K: %d\n", k2);

    return 0;
}

int removeDuplicates(int* nums, int numsSize) {
    // Much more efficient solution that is not mine. 
    if (numsSize == 0) { 
        return 0;
    }
    int numUniqueElements = 1;
    int numDuplicateElements = 0;
    printf("+++++++++++++++++++++++++++++++\n");
    for(int i = 0; i < numsSize - 1; i++) {
        printArray(nums, numsSize);
        if(nums[i] != nums[i + 1]) {
            numUniqueElements++;
            nums[i + 1 - numDuplicateElements] = nums[i + 1];
        } else {
            numDuplicateElements++;
        }
    }
    printf("+++++++++++++++++++++++++++++++\n");
    return numUniqueElements;
}

// int removeDuplicates(int* nums, int numsSize) {
//     int numUniqueElements = 0;

//     int *seenElements = calloc(numsSize, sizeof(int));
//     int seenElementsLength = 0;
//     for(int i = 0; i < numsSize; i++) {
//         seenElements[i] = -999;
//     }
//     bool unseenElement = true;

//     for(int i = numsSize - 1; i >= 0; i--) {
//         for(int j = 0; j < seenElementsLength; j++) {
//             if(nums[i] == seenElements[j]) {
//                 unseenElement = false;
//             } else {
//                 unseenElement = true;
//             } 
//         }
//         if(unseenElement) {
//             seenElements[seenElementsLength] = nums[i];
//             seenElementsLength++;
//             unseenElement = false;
//         }
//     }
//     printArray(seenElements, numsSize);

//     for(int i = 0; i < seenElementsLength; i++) {
//         nums[i] = seenElements[seenElementsLength-i-1];
//         numUniqueElements++;
//     }

//     free(seenElements);

//     return numUniqueElements;
// }

void printArray(int* arr, int arrSize) {
    printf("[ ");
    for(int i = 0; i < arrSize - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d ]\n",arr[arrSize - 1]);
}
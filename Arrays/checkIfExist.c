#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int* arr, int arrSize);
bool checkIfExist(int* arr, int arrSize);

int main () {
    
    int array1[] = {10,2,5,3}; 
    int array1Size = 4;
    printArray(array1, array1Size);
    bool NandDoubleExist1 = checkIfExist(array1, array1Size);
    printf("Expected Output: True \nActual Output: %s\n", NandDoubleExist1 ? "True" : "False");
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    printf("==========================================\n");
    int array2[] = {3,1,7,11}; 
    int array2Size = 4;
    printArray(array2, array2Size);
    bool NandDoubleExist2 = checkIfExist(array2, array2Size);
    printf("Expected Output: False \nActual Output: %s\n", NandDoubleExist2 ? "True" : "False");
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    printf("==========================================\n");
    int array3[] = {-2,0,10,-19,4,6,-8};
    int array3Size = 7;
    printArray(array3, array3Size);
    bool NandDoubleExist3 = checkIfExist(array3, array3Size);
    printf("Expected Output: False \nActual Output: %s\n", NandDoubleExist3 ? "True" : "False");

    return 0;
}


bool checkIfExist(int* arr, int arrSize) {
    if(arrSize <= 1) {
        return false;
    }
    for(int i = 0; i < arrSize; i++) {
        for(int j = i + 1; j < arrSize; j++) {
            printf("arr[i = %d] = %d\n2 * arr[j = %d] = %d\n====================\narr[j = %d] = %d\n2 * arr[i = %d] = %d\n", i, arr[i], j, 2 * arr[j], j, arr[j], i, 2 * arr[i]);
            if(arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i]) {
                return true;
            }
            printf("++++++++++++++++++++\n");
        }    
    }
    return false;
}

void printArray(int* arr, int arrSize) {
    printf("[ ");
    for(int i = 0; i < arrSize - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d ]\n",arr[arrSize - 1]);
}
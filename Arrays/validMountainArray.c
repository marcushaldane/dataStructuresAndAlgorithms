#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int* arr, int arrSize);
bool validMountainArray(int* arr, int arrSize);

int main () {
    
    int array1[] = {2,1}; 
    int array1Size = 2;
    printArray(array1, array1Size);
    bool validMountainArray1 = validMountainArray(array1, array1Size);
    printf("Expected Output: False \nActual Output: %s\n", validMountainArray1 ? "True" : "False");
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    printf("==========================================\n");
    int array2[] = {3,5,5}; 
    int array2Size = 3;
    printArray(array2, array2Size);
    bool validMountainArray2 = validMountainArray(array2, array2Size);
    printf("Expected Output: False \nActual Output: %s\n", validMountainArray2 ? "True" : "False");
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    printf("==========================================\n");
    int array3[] = {0,3,2,1};
    int array3Size = 4;
    printArray(array3, array3Size);
    bool validMountainArray3 = validMountainArray(array3, array3Size);
    printf("Expected Output: True \nActual Output: %s\n", validMountainArray3 ? "True" : "False");
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    printf("==========================================\n");
    int array4[] = {1,7,9,5,4,1,2};
    int array4Size = 7;
    printArray(array4, array4Size);
    bool validMountainArray4 = validMountainArray(array4, array4Size);
    printf("Expected Output: False \nActual Output: %s\n", validMountainArray4 ? "True" : "False");

    return 0;
}



bool validMountainArray(int* arr, int arrSize) {
    if(arrSize < 3) {
        return false;
    }
    bool peakFound = false;
    bool continuouslyIncreasing = false;
    bool continuouslyDecreasing = false;
    for(int i = 1; i < arrSize - 1; i++) {
        continuouslyIncreasing = arr[i - 1] < arr[i];
        continuouslyDecreasing = arr[i] > arr[i + 1];
        if(continuouslyIncreasing && continuouslyDecreasing && !peakFound) {
            peakFound = true;
        }  
        if((!peakFound && !continuouslyIncreasing) || (peakFound && !continuouslyDecreasing)) {
            return false;    
        }
    }
    return peakFound;
}


void printArray(int* arr, int arrSize) {
    printf("[ ");
    for(int i = 0; i < arrSize - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d ]\n",arr[arrSize - 1]);
}
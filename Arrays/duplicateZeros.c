#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int arrSize);
void duplicateZeros(int* arr, int arrSize);

int main () {
    
    int testCase[] = {1, 0, 2, 3, 0, 4, 5, 0}; //expected output: {1,0,0,2,3,0,0,4}
    int testCaseSize = 8;

    duplicateZeros(testCase, testCaseSize);
    printArray(testCase, testCaseSize);

    return 0;
}

void duplicateZeros(int* arr, int arrSize) {
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] == 0) {
            for(int j = arrSize - 1; j > i + 1; j--) {
                if(j >= 1) {
                    arr[j] = arr[j - 1];
                }
            }
            if(i + 1 < arrSize) {
                arr[i + 1] = 0;    
            }
            i++;
        }
    }
}

void printArray(int* arr, int arrSize) {
    printf("[ ");
    for(int i = 0; i < arrSize - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d ]\n",arr[arrSize - 1]);
}


#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int arrSize);
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

int main () {
    
    int array1[] = {1,2,3,0,0,0}; 
    int array1Size = 3;
    int array1Capacity = 6;
    int array2[] = {2,5,6};
    int array2Size = 3;
    int array2Capacity = 3;

    printArray(array1, array1Capacity);
    merge(array1, array1Capacity, array1Size, array2, array2Capacity, array2Size);
    printf("Expected Output: [ 1, 2, 2, 3, 5, 6 ]\nActual Output: ");
    printArray(array1, array1Capacity);

    int array3[] = {0}; 
    int array3Size = 0;
    int array3Capacity = 0;
    int array4[] = {1};
    int array4Size = 1;
    int array4Capacity = 1;

    printArray(array3, array3Capacity);
    merge(array3, array3Capacity, array3Size, array4, array4Capacity, array4Size);
    printf("Expected Output: [ 1 ]\nActual Output: ");
    printArray(array3, array3Capacity);


    return 0;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) { 
    int nums1Capacity = nums1Size - 1;
    m--;
    n--;
    while(m >= 0 && n >= 0) {
        // printf("nums1[%d] = %d; nums2[%d] = %d\n", m, nums1[m], n, nums2[n]);
        if(nums1[m] > nums2[n]) {
            // printf("merging from arr1[%d] = %d\n", m, nums1[m]);
            nums1[nums1Capacity--] = nums1[m--];
        } else {
            // printf("merging from arr2[%d] = %d at arr1[%d]\n", n, nums2[n], nums1[nums1Capacity]);
            nums1[nums1Capacity--] = nums2[n--];
        }
        // printArray(nums1, 6);
        // printf("==================\n");
    }
    while(n >= 0) {
        nums1[nums1Capacity--] = nums2[n--];
    }
}

void printArray(int* arr, int arrSize) {
    printf("[ ");
    for(int i = 0; i < arrSize - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d ]\n",arr[arrSize - 1]);
}
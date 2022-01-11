#include<stdio.h>

void quickSort(int array[], int left, int right);

// function to print array elements
void printArray(int array[], int size) {
  for (int itr = 0; itr < size; ++itr) {
    printf("%d  ", array[itr]);
  }
  printf("\n");
}

void main(){
    int array[] = {6, 2, 9, 5, 3, 8, 7, 1, 4};
    //int array[] = {9,8,1,2,7,6,4,5,3};
    int n = sizeof(array)/sizeof(array[0]);

    printf("Unsorted Array\n");
    printArray(array, n);

    quickSort(array, 0, n-1);

    printf("Sorted Array\n");
    printArray(array, n);
}

#include<stdio.h>
#include "mySorting.h"

// function to print array elements
void printArray(int array[], int size) {
  for (int itr = 0; itr < size; ++itr) {
    printf("%d  ", array[itr]);
  }
  printf("\n");
}

void main()
{

  //Insertion Sorting
  int arrayInsertionSort[] = {7, 5, 1, 9, 3};
  size_t nInsert= sizeof(arrayInsertionSort)/sizeof(arrayInsertionSort[0]);

  printf("\t\t\tInsertion Sort\n");
  printf("Unsorted Array\n");
  printArray(arrayInsertionSort, nInsert);

  insertSort(arrayInsertionSort, nInsert);

  printf("Sorted Array\n");
  printArray(arrayInsertionSort, nInsert);

  //Quick Sorting
  int arrayQuickSort[] = {6, 2, 9, 5, 3, 8, 7, 1, 4};
  size_t nQuick = sizeof(arrayQuickSort)/sizeof(arrayQuickSort[0]);

  printf("\t\t\tQuick Sort\n");
  printf("Unsorted Array\n");
  printArray(arrayQuickSort, nQuick);

  quickSort(arrayQuickSort, 0, nQuick-1);

  printf("Sorted Array\n");
  printArray(arrayQuickSort, nQuick);

  //Radix Sorting
  int arrayRadixSort[] = {727, 345, 982, 821, 527, 833, 742, 203, 731, 917};
  size_t nRadix= sizeof(arrayRadixSort)/sizeof(arrayRadixSort[0]);

  printf("\t\t\tRadix Sort\n");
  printf("Unsorted Array\n");
  printArray(arrayRadixSort, nRadix);

  radixSort(arrayRadixSort, 10, nRadix);

  printf("Sorted Array\n");
  printArray(arrayRadixSort, nRadix);

}

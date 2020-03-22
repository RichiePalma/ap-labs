#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mergeSort(void *array[], int leftPart, int rightPart) {
  int i, j, k;

  if (leftPart < rightPart) {
    int middle = leftPart+(rightPart-leftPart)/2;
    mergeSort(array, leftPart, middle);
    mergeSort(array, middle+1, rightPart);
    int left = middle - leftPart + 1;
    int right = rightPart - middle;
    void *leftPartArr[left], *rightPartArr[right];
    for (i = 0; i < left; i++) {
      leftPartArr[i] = array[leftPart + i];
    }
    for (j = 0; j < right; j++) {
      rightPartArr[j] = array[middle + 1+ j];
    }
    i = 0;
    j = 0;
    k = leftPart;
    while (i < left && j < right) {
      if(strcmp(leftPartArr[i],rightPartArr[j]) < 1 || strcmp(leftPartArr[i], rightPartArr[j]) == 0) {
        array[k] = leftPartArr[i];
        i++;
      }
      else {
        array[k] = rightPartArr[j];
        j++;
      }
      k++;
    }
    while (i < left) {
      array[k] = leftPartArr[i];
      i++;
      k++;
    }
    while (j < right) {
      array[k] = rightPartArr[j];
      j++;
      k++;
    }
  }
}

int main(int argc, char *argv[]){

  int argvLenght = sizeof(argv)/sizeof(argv[0]);
  // Sort arguments
  printf("Unsorted: ");
  for(int i = 1; i < argc; i++){
    printf("%s ", argv[i]);
  }
  printf("\nSorted: ");
  mergeSort(argv, 0, argc-1);
  for(int i = 1; i < argc; i++){
    printf("%s ", argv[i]);
  }
  printf("\n");

  return 0;
}
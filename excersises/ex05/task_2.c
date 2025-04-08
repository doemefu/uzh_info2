#include "stdio.h"

int counter = 0;

void swap(int array[], int index1, int index2) {
    int tmp = array[index2];
    array[index2] = array[index1];
    array[index1] = tmp;
}

int hoarePartition(int array[], int leftIndex, int rightIndex) {
    int i = leftIndex - 1;
    int j = rightIndex + 1;
    int pivot = array[rightIndex];
    while (1) {
        do {
            counter++;
            j--;
        } while (array[j] > pivot);
        do {
            counter++;
            i++;
        } while (array[i] < pivot);
        if (i >= j) {
            return i;
        }
        swap(array, i, j);
    }
}

void quicksort(int array[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        int m = hoarePartition(array, leftIndex, rightIndex);
        quicksort(array, leftIndex, m - 1);
        quicksort(array, m, rightIndex);
    }
}

int main() {
    int array[] = {6, 8, 4, 5, 3, 7, 2, 1, 0, 9};
    int n = sizeof(array) / sizeof(array[0]);
    quicksort(array, 0, n - 1);
    printf("Counter: %d \n", counter);
    for (int i = 0; i < n; i++) {
        printf("%d, ", array[i]);
    }
    return 0;
}

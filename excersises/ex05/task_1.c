#include <stdio.h>

int leftChild(int index) {
    return index * 2 + 1;
}

int rightChild(int index) {
    return index * 2 + 2;
}

void swap(int array[], int index1, int index2) {
    int tmp = array[index2];
    array[index2] = array[index1];
    array[index1] = tmp;
}

int controlMaxHeap(int array[], int currentIndex, int length) {
    int leftIndex = leftChild(currentIndex);
    if (leftIndex < length) {
        if (array[currentIndex] < array[leftIndex]) {
            return currentIndex;
        }
        int leftViolation = controlMaxHeap(array, leftIndex, length);
        if (leftViolation != -1) {
            return leftViolation;
        }
    }
    int rightIndex = rightChild(currentIndex);
    if (rightIndex < length) {
        if (array[currentIndex] < array[rightIndex]) {
            return currentIndex;
        }
        int rightViolation = controlMaxHeap(array, rightIndex, length);
        if (rightViolation != -1) {
            return rightViolation;
        }
    }
    return -1;
}

void heapify(int array[], int currentIndex, int length) {
    int leftIndex = leftChild(currentIndex);
    int rightIndex = rightChild(currentIndex);
    int indexLargestElement = currentIndex;
    if (leftIndex < length) {
        if (array[leftIndex] > array[indexLargestElement]) {
            indexLargestElement = leftIndex;
        }
    }
    if (rightIndex < length) {
        if (array[rightIndex] > array[indexLargestElement]) {
            indexLargestElement = rightIndex;
        }
    }
    if (indexLargestElement != currentIndex) {
        swap(array, indexLargestElement, currentIndex);
        heapify(array, indexLargestElement, length);
    }
}

void fixHeap(int array[], int length) {
    int problemIndex = controlMaxHeap(array, 0, length);
    while (problemIndex != -1) {
        heapify(array, problemIndex, length);
        problemIndex = controlMaxHeap(array, 0, length);
    }
    // The loop is necessary to cover cases such as [5, 5, 3, 2, 1, 6].
    // You could also make this part a bit more efficient by comparing the element directly with the parent node.
    // However, for the sake of simplicity, this optimization has not been done.
}

int main() {
    int array[] = {5, 5, 3, 2, 1, 4};
    int length = sizeof(array) / sizeof(array[0]);
    fixHeap(array, length);
    for (int i = 0; i < length; i++) {
        printf("%d, ", array[i]);
    }
    return 0;
}

#include "stdio.h"

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
            j--;
        } while (array[j] > pivot);
        do {
            i++;
        } while (array[i] < pivot);
        if (i >= j) {
            return i;
        }
        swap(array, i, j);
    }
}

int medianRecursive(int array[], int leftIndex, int rightIndex, int medianIndex) {
    if (leftIndex >= rightIndex) {
        return array[leftIndex];
    }
    int m = hoarePartition(array, leftIndex, rightIndex);
    // Sort only the part in which the median will end up
    if (medianIndex >= m) {
        return medianRecursive(array, m, rightIndex, medianIndex);
    } else {
        return medianRecursive(array, leftIndex, m - 1, medianIndex);
    }
}

float median(int array[], int length) {
    if (length == 0) {
        return 0;
    }
    if (length % 2 == 0) {
        // Guarantees that the small element from which the median is composed is placed at it's correct position.
        int smallerMedianElement = medianRecursive(array, 0, length - 1, (length - 1) / 2);
        /*
         Since we do not run the complete sorting algorithm, there is no guarantee that the larger element of the median
         is already in the correct position. To find this element, we could run the same algorithm again, except that
         we search for the element one to the right. Alternatively, we can make use of the fact that we now search the
         next bigger element of our previously found element and the fact that this element must be on the right-hand side.
         */
        int largerMedianElement = array[(length / 2)];
        for (int i = (length / 2) + 1; i < length; i++) {
            if (largerMedianElement > array[i]) {
                largerMedianElement = array[i];
            }
        }
        return (float) (smallerMedianElement + largerMedianElement) / 2;
    } else {
        return (float) medianRecursive(array, 0, length - 1, length / 2);
    }
}

int main() {
    int array[] = {5, 4, 6, 3, 1, 2, 7, 8, 9, 10};
    int n = sizeof(array) / sizeof(array[0]);
    printf("%f", median(array, n));
    return 0;
}
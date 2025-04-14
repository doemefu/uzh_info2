#include <stdio.h>
#include <time.h> // measuring run time

int n, t;
int A[100000000];

int linear_search(int A[], int n, int t) {
    for(int i = 0; i < n; i++) {
        if (A[i] == t) {
            return 1; // found in the array
        }
    }
    return 0; // not found
}

int binary_search(int A[], int n, int t) {
    int l = 0, r = n - 1;
    int mid;
    while (l <= r) {
        mid = (int)((r - l) / 2 + l);
        // printf("%d\n", mid);
        if (A[mid] == t) {
            return 1; // found in the array
        } else if(A[mid] > t) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    } 
    return 0; // not found
}

int main() {
    clock_t start, end;
    printf("Enter an integer for n: ");
    scanf("%d", &n); 
    printf("Generate an array with %d distinct integers from 1 to %d.\n", n, n);
    for(int i = 0; i < n; i++) A[i] = i + 1;
    printf("Enter an integer for t: \n");
    scanf("%d", &t);
    int count = 100; 
    start = clock();
    for(int c = 1; c <= count; c++) {
        linear_search(A, n, t); // complete your implementation
    }
    end = clock();
    double run_time = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
    printf("Linear search takes : %f millseconds\n", run_time / count); 

    start = clock();
    for(int c = 1; c <= count; c++) {
        binary_search(A, n, t); // complete your implementation
    }
    end = clock();
    run_time = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
    printf("Binary search takes : %f millseconds\n", run_time / count); 
}
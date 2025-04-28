//
// Created by Dominic Furchert on 28.04.2025.
//

#include <stdio.h>

int maxOverlap(int A[], int l, int m, int r) {

  int leftSum = 0;
  int leftMax = -9999;
  int rightSum = 0;
  int rightMax = -9999;

  for (int i = m; i>=l; --i) {
    leftSum += A[i];
    if (leftSum>leftMax) {
      leftMax=leftSum;
    }
  }

  for (int i = m+1; i<=r;++i) {
    rightSum+=A[i];
    if (rightSum>rightMax) {
      rightMax=rightSum;
    }
  }

  return leftMax+rightMax;
}

int maxSubArray(int A[], int l, int r) {
  if (l==r) {
    return A[l];
  }
  int m = (l+r)/2;

  int left = maxSubArray(A,l,m);
  int right = maxSubArray(A,m+1,r);

  int overlap = maxOverlap(A,l,m,r);

  if (right > left && right > overlap){
    return right;
  }
  else if (left > right && left > overlap){
    return left;
  }
  else {
    return overlap;
  }

}

void print_array(int A[], int n){
  for (int i = 0; i < n - 1; i++){
    printf("%d, ", A[i]);
  }
  printf("%d", A[n-1]);
}

int main(int argc, char *argv[]) {
  int A[] = {-2, -3, 4, -1, -2, 1, 5, -3};
  int n = 8;

  int max_sum = maxSubArray(A, 0, n-1);
  printf("The sum of the maximum subarray in array A = [");
  print_array(A, n);
  printf("] is %d.", max_sum);
  return 0;
}

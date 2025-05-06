//
// Created by Dominic Furchert on 06.05.2025.
//

#include <stdio.h>

int majorityElement(int A[], int l, int r) {

  if (l==r) {
    return A[l];
  }

  int m = (l+r)/2;
  int leftside = majorityElement(A, l, m);
  int rightSide = majorityElement(A,m+1,r);

  if (leftside == rightSide) {
    return leftside;
  }

  int counterLeftElement = 0;
  int counterRightElement = 0;

  for (int i = l; i < r; i++) {
    if (A[i]==leftside) {
      counterLeftElement++;
    } else if (A[i]==rightSide) {
      counterRightElement++;
    }
  }

  if (counterLeftElement<counterRightElement) {
    return rightSide;
  }
  return leftside;
}

void print_array(int A[], int n){
  for (int i = 0; i < n - 1; i++){
    printf("%d, ", A[i]);
  }
  printf("%d", A[n-1]);
}

int main(int argc, char *argv[]) {
  int A[] = {1,1,2, 2, 1, 2, 2, 1, 1, 1, 1};
  int n = sizeof(A)/sizeof(A[0]);

  int majEle = majorityElement(A, 0, n-1);
  printf("The majority Element in array A = [");
  print_array(A, n);
  printf("] is %d.", majEle);
  return 0;
}

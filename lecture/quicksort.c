//
// Created by Dominic Furchert on 21.06.2025.
// Quicksort with median over 3 rands for pivoting
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_pivot(int A[], int l, int r) {
  int pivot = -1;

  if ((r-l)>2) {
    int rand_i_1 = l + rand()%(r-l+1);
    int rand1 = A[rand_i_1];

    int rand_i_2 = l+ rand()%(r-l+1);
    int rand2 = A[rand_i_2];

    int rand_i_3 = l+ rand()%(r-l+1);
    int rand3 = A[rand_i_3];

    if ((rand1 >= rand2 && rand1 <= rand3) || (rand1 <= rand2 && rand1 >= rand3)) {
      pivot = rand_i_1;
    } else if ((rand2 >= rand1 && rand2 <= rand3) || (rand2 <= rand1 && rand2 >= rand3)) {
      pivot = rand_i_2;
    } else {
      pivot = rand_i_3;
    }
  }else {
    pivot = (l+r)/2;
  }

  return pivot;
}

int partitioning(int A[], int start, int end) {
  int pivot = A[get_pivot(A,start,end)];
  int l = start-1;
  int r = end+1;
  while (1) {
    do {
      r--;
    } while (A[r] > pivot);

    do {
      l++;
    } while (A[l] < pivot);

    if (l < r) {
      int tmp = A[l];
      A[l] = A[r];
      A[r] = tmp;
    } else {
      return r;
    }
    printf("partitioning around %i with l:%i and r:%i :\n",pivot,l,r);
    for (int i = start; i <= end; i++) {
      printf("%d ", A[i]);
    }
    printf("\n");
  }
  return r;
}

void quicksort(int A[], int l, int r, char side) {
  if (l<r) {
    printf("\n%c side quicksort with l:%i, r:%i:\n",side,l,r);
    for (int i = l; i <= r; i++) {
      printf("%d ", A[i]);
    }
    printf("\n");
    int pivot = partitioning(A,l,r);
    quicksort(A, l,pivot, 'l');
    quicksort(A,pivot+1,r,'r');
  }

}

int main() {
  int Array1[] = {6, 0, 5, 9, 4, 1, 3, 7, 8, 2};
  int Array[] = {
    23,  89,   3,  45,  66,  12,  99,  34,  58,  71,
     5,  89,  40,  17,   2,  76,  28,  61,  14,  90,
     8
 };

  int n = sizeof(Array)/sizeof(Array[0]);
  srand(time(NULL));

  quicksort(Array, 0,n-1,'i');

  for (int i = 0; i < n; i++) {
    printf("%d ", Array[i]);
  }
  printf("\n");


  return 0;
}
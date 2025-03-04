//
// Created by Dominic Furchert on 27.02.2025.
//

#include <stdio.h>
#include <stdbool.h>

void compression(char string[], int n){
  char out[n];
  int counter = 1;
  int pos = 0;

  for(int i = 1; i<n; i++){

    if(string[i-1] != string[i]){
      //out[pos] = counter;
      //out[pos+1] = string[i-1];
      printf("%d", counter);
      printf("%c", string[i-1]);
      sprintf(&out[pos], "%d%c", counter, string[i - 1]);
      counter = 1;
      pos += 2;

    } else {
      counter++;
    }
  }

  printf("%c", *"\n");
  printf("%s", out);
  printf("%c", *"\n");

}

int sum_or_not(int A[], int n, int t) {
  for (int i=0; i<n;i++) {
    for (int a=n-i; a<n; a--) {
      if (A[i]+A[a] == t) {
        return 1;
      }
    }
  }
  return 0;
}

//precondition: A sorted ascending
int sum_or_not_efficient(int A[], int n, int t) {
  int i = 0;
  int j = n-1;
  while (i<j) {
    if (A[i]+A[j] == t) {
      return 1;
    }else if (A[i]+A[j] < t) {
      i++;
    }else{
      j--;
    }
  }
}

int zeroSubarray(int A[], int n) {
  for (int i=0; i<n; i++) {
    for (int a=i+1; a<n; a++) {
      int sum=0;
      for (int x=0; x < a-i; x++) {
        sum += A[x];
      }
      if (sum == 0) {
        return 1;
      }
    }
  }
  return 0;
}

int main(){


  while(true){
    char compress[50];
    printf("Enter a String that you want to compress: ");
    scanf("%s",compress);
    //char string[] = "xaaabbbcccajksdhfiewabcaulebrvealjghfjdgaldhjsfkahsdfhkew";
  	int n = sizeof(compress)/sizeof(compress[0]);
    printf("The length of the string is: %d\n", n);
  	compression(compress, n);
  }


  int numbers[] = {1,5,6,3,8,2,9,4,7};
  int m = sizeof(numbers)/sizeof(numbers[0]);
  int goal = 6;
  //printf("%d", sum_or_not(numbers, m, goal));

  int arr1[] = {1, 2, -3, 4};  // Subarray [1, 2, -3] sums to 0
  int arr2[] = {4, -1, -3, 5}; // Subarray [-1, -3, 4] sums to 0
  int arr3[] = {3, 1, 7, 5};   // No subarray sums to 0
  int arr4[] = {0, 5, 6};      // Single element 0 is a valid subarray
  int arr5[] = {-5, 5};        // Entire array sums to 0

  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  int n3 = sizeof(arr3) / sizeof(arr3[0]);
  int n4 = sizeof(arr4) / sizeof(arr4[0]);
  int n5 = sizeof(arr5) / sizeof(arr5[0]);

  //printf("Test Case 1: %d\n", zeroSubarray(arr1, n1)); // Expected: 1
  //printf("Test Case 2: %d\n", zeroSubarray(arr2, n2)); // Expected: 1
  //printf("Test Case 3: %d\n", zeroSubarray(arr3, n3)); // Expected: 0
  //printf("Test Case 4: %d\n", zeroSubarray(arr4, n4)); // Expected: 1
  //printf("Test Case 5: %d\n", zeroSubarray(arr5, n5)); // Expected: 1

  return 0;
}

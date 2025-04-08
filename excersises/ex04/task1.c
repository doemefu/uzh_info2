//
// Created by Dominic Furchert on 24.03.2025.
//

#include <stdio.h>


void task1(int a[], int s, int x){
  int l=0;
  int r=s-1;
  int m = (l+r)/2;

  while(a[m]!=x && (a[l] <= x && a[r] >= x)){
    m=(l+r)/2;
    printf("%d \n", a[m]);
    if(x < a[m]){
      r=m-1;
    }else{
      l=m+1;
    }
  }
  if(a[m]==x){
    printf("Final: %d \n", a[m]);
  }else if(x>a[m] && x-a[m] > x-a[m+1]){
    printf("Final: %d \n", a[m+1]);
  }else if(x<a[m] && x-a[m] > x-a[m-1]){
    printf("Final: %d \n", a[m-1]);
  }else{
    printf("Final: %d \n", a[m]);
  }
}


int main (){
  int array[] = {1,3,5,6,9,10,11,12,19,22,24,25,30};
  int size = sizeof(array) / sizeof(array[0]);
  printf("Size: %d \n", size);
  int toFind;

  printf("Enter an integer: ");
  scanf("%d", &toFind);

  task1(array, size, toFind);

  return 0;
}
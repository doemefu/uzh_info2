//
// Created by Dominic Furchert on 24.03.2025.
//

#include <stdio.h>

void printer(int array[], int size){
  for (int i = 0; i < size; i++){
    printf("%d", array[i]);
    printf("-");
  }
  printf("\n");
}

int task4(int a[], int size){
  printer(a, size);
  if(size==1){
    return a[0];
  }
  int b[size-1];
  for (int i = 0; i < size-1; i++){
    b[i] = a[i] + a[i+1];
  }
  task4(b, size-1);
  return 0;
}



int main(){

  int array[] = {5,4,6,1,3,5};
  int size = sizeof(array) / sizeof(array[0]);


  int b = task4(array, size);

  return 0;
}
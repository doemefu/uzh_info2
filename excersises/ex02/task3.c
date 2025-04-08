//
// Created by Dominic Furchert on 24.03.2025.
//

#include <stdio.h>


void sequence(int n){
  printf("%d", n);
  printf("; ");
  if(n==1){
    return;
  }
  if(n%2==0){
    sequence(n/2);
  }else{
    sequence(3*n+1);
  }
}

int main(){
  int a = 3;
  printf("Enter an integer: ");
  scanf("%d", &a);
  printf("The Sequqnce: ");
  sequence(a);


  return 0;
}
//
// Created by Dominic Furchert on 24.02.2025.
//
#include <stdio.h>
#include <stdbool.h>

int value;
int k;

int main ()
{

    printf("Enter a number: ");
    scanf("%d",&value);
    int A[value];
    A[0] = false;
    A[1] = false;
    for (int i = 2; i < (value); i++)
    {
      A[i] = true;
    }

    for (int i = 2; i <= ((value)/2); i++)
    {
      if (i < (value-1)/i)
      {
        k = i;
      }
      else {k = (value-1)/i;}
      for (int j = 2; j <= k; j++)
      {
      A[i*j] = false;
      }
    }

    for (int i = 0; i < value; i++)
    {
    printf("%d: %d\n",i, A[i]);
    }
    //printf("\n");
    //printf("%d", 7/2);
}
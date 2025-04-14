//
// Created by Dominic Furchert on 14.04.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct myStack{
  int *content; //int array
  int first;
};

// Fixed size version
struct myStack* new(int size){
  struct myStack* s;
  s = malloc(sizeof(struct myStack));
  s->content = malloc(sizeof(int)*size);
  s->first = 0;
  return s;
}

bool isEmpty(struct myStack* s) {
  if (s->first == 0) {
    return 1;
  }
  return 0;
}

int pop(struct myStack* s) {
  if (isEmpty(s)) {
    return -1;
  }
  s->first--; //s->first = s->first-1;
  return s->content[s->first];
}

void push(int number, struct myStack* s) {
  s->content[s->first] = number;
  s->first++;
}

void printer(struct myStack* s) {
  int list_length = sizeof(s->content) / sizeof(s->content[0]);
  for (int i=0;i<list_length;i++) {
    printf("%i",s->content[i]);
  }
}

void main(){
  printf("start");
  struct myStack* elStack = new(5);
  push(5,elStack);
  push(3,elStack);
  printf("%i",*elStack->content);
  printf("\n");

  printer(elStack);
  while (!isEmpty(elStack)){
    printf("Popped: %d\n", pop(elStack));
  }

  free(elStack->content);
  free(elStack);
}
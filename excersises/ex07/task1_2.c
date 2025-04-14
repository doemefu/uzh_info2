//
// Created by Dominic Furchert on 14.04.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct myStack{
  int content; //int
  struct myStack *next;
};

struct myStack** new(){
  struct myStack** s;
  s = malloc(sizeof(struct myStack*));
  *s = NULL; //init empty
  return s;
}

bool isEmpty(struct myStack** s) {
  return *s == NULL;
}

struct myStack* popElement(struct myStack* s) {
  if (isEmpty(s)) {
    return NULL;
  }
  struct myStack* tmp = s->next;
  s->next=s->next->next;
  return tmp;
}

int popValue(struct myStack** s) {
  if (isEmpty(s)) {
    return -1;
  }
  struct myStack* top = *s;
  int value = top->content;
  *s = top->next;
  free(top);
  return value;
}

void push(int number, struct myStack** s) {
  struct myStack* newElement = malloc(sizeof(struct myStack));
  newElement->content = number;
  newElement->next = *s;
  *s = newElement;
}

void printer(struct myStack** s) {
  struct myStack* curr = *s;
  while(curr->next != NULL){
    printf("%i",curr->content);
    curr=curr->next;
  }
}

void main(){
  printf("start");
  struct myStack** elStack = new();
  push(5,elStack);
  push(3,elStack);
  push(9,elStack);

  printer(elStack);
  printf("\n");

  while (!isEmpty(elStack)){
    printf("Popped: %d\n", popValue(elStack));
  }

  free(elStack);
}
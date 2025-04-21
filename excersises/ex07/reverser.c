//
// Created by Dominic Furchert on 15.04.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


struct myStack{
  char content; //bracket
  struct myStack *next;
};

struct myStack** newStack(){
  struct myStack **s = malloc(sizeof(struct myStack *));
  *s = NULL; //init empty
  return s;
}

bool isEmpty(struct myStack** s) {
  return *s == NULL;
}

struct myStack* popElement(struct myStack** s) {
  if (isEmpty(s)) {
    return NULL;
  }
  struct myStack* top = *s;
  *s = top->next;
  return top;
}

char popValue(struct myStack** s) {
  if (isEmpty(s)) {
    return 'x';
  }
  struct myStack* top = *s;
  char value = top->content;
  *s = top->next;
  free(top);
  return value;
}

void push(char element, struct myStack** s) {
  struct myStack* newElement = malloc(sizeof(struct myStack));
  newElement->content = element;
  newElement->next = *s;
  *s = newElement;
}

void printerStack(struct myStack** s) {
  struct myStack* curr = *s;
  while(curr != NULL){
    printf("%c",curr->content);
    curr=curr->next;
  }
  printf("\n"); // Add newline to separate output

}

struct myQueueStruct{
  struct myQueueElement *head;
  struct myQueueElement *tail;
};

struct myQueueElement{
  char content;
  struct myQueueElement *next;
};

struct myQueueStruct* newQueue(){
  struct myQueueStruct* q;
  q = malloc(sizeof(struct myQueueStruct));
  q->head = NULL;
  q->tail = NULL;
  return q;
}

bool is_empty(struct myQueueStruct *q){
  return q->head == NULL;
}

char dequeue(struct myQueueStruct *q){
  if (is_empty(q)){
    return -1;
  }
  char value = q->head->content;
  struct myQueueElement *tmp = q->head;
  q->head=q->head->next;
  free(tmp);
  return value;
}

void enqueue(struct myQueueStruct *q, char x){
  struct myQueueElement *new = malloc(sizeof(struct myQueueElement));
  new->content = x;
  new->next = NULL;
  if (is_empty(q)) {
    q->head = new;
    q->tail = new;
  }else {
    q->tail->next = new;
    q->tail = new;
  }
}

void printerQueue(struct myQueueStruct* q) {
  struct myQueueElement *first = q->head;
  while(first != NULL){
    printf("%c", first->content);
    first = first->next;
  }
  printf("\n");
}

void free_stack(struct myStack** s) {
  struct myStack* current = *s;
  while (current != NULL) {
    struct myStack* next = current->next;
    free(current);
    current = next;
  }
  *s = NULL;
}

void stackToQueue(){

}

bool reverser(char *S){

  struct myStack** elStack = newStack();
  struct myQueueStruct* elQueue = newQueue();
  for (int i = 0; i < strlen(S); i++) {
    if(S[i]==' '){
      while(!isEmpty(elStack)){
        enqueue(elQueue, popValue(elStack));
      }
      enqueue(elQueue, ' ');
    }else{
      push(S[i], elStack);
      printf("here %i \n", i);
    }
  }
  while(!isEmpty(elStack)){
    enqueue(elQueue, popValue(elStack));
  }
  printerQueue(elQueue);

  return 1;
}

int main(){
  char *word_zero = "hello World this is info 2 jejjiiiii";

  printf("Testing %s \n", word_zero);
  reverser(word_zero);

  printf("done");
  return 0;
}
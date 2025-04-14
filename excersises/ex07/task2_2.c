//
// Created by Dominic Furchert on 14.04.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct myQueueStruct{
  struct myQueueElement *head;
  struct myQueueElement *tail;
};

struct myQueueElement{
  int content;
  struct myQueueElement *next;
};

struct myQueueStruct* new(){
  struct myQueueStruct* q;
  q = malloc(sizeof(struct myQueueStruct));
  q->head = NULL;
  q->tail = NULL;
  return q;
}

bool is_empty(struct myQueueStruct *q){
  return q->head == NULL;
}

int dequeue(struct myQueueStruct *q){
  if (is_empty(q)){
    return -1;
  }
  int value = q->head->content;
  struct myQueueElement *tmp = q->head;
  q->head=q->head->next;
  free(tmp);
  return value;
}

void enqueue(struct myQueueStruct *q, int x){
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

void printer(struct myQueueStruct* q) {
  struct myQueueElement *first = q->head;
  while(first != NULL){
    printf("%i", first->content);
    first = first->next;
  }
  printf("\n");
}


int main(){

  struct myQueueStruct* elQueue = new();
  enqueue(elQueue, 3);
  enqueue(elQueue, 5);
  enqueue(elQueue, 7);
  enqueue(elQueue, 9);
  printer(elQueue);

  printf("\n");
  printf("%i \n",dequeue(elQueue));
  printf("%i \n",dequeue(elQueue));
  printf("%i \n",dequeue(elQueue));
  enqueue(elQueue, 1);
  enqueue(elQueue, 2);
  enqueue(elQueue, 4);
  printf("%i \n",dequeue(elQueue));
  printf("%i \n",dequeue(elQueue));
  printer(elQueue);

  free(elQueue);
  return 0;
}
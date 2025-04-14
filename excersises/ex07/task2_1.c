//
// Created by Dominic Furchert on 14.04.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct myQueue{
  int *content;
  int head;
  int tail;
};

struct myQueue* new(int size){
  struct myQueue* q;
  q = malloc(sizeof(struct myQueue));
  q->content = malloc(sizeof(int)*size);
  q->head = 0;
  q->tail = 0;
  return q;
}

bool is_empty(struct myQueue *q){
  return q->head == q->tail;
}

int dequeue(struct myQueue *q){
  if (is_empty(q)){
    return -1;
  }
  int value = q->content[q->head];
  q->head++;
  return value;
}

void enqueue(struct myQueue *q, int x){
  q->content[q->tail] = x;
  q->tail++;
}

void printer(struct myQueue* q) {
  for (int i = q->head; i < q->tail; i++) {
    printf("%i ", q->content[i]);
  }
  printf("\n");
}


int main(){

  struct myQueue* elQueue = new(100);
  enqueue(elQueue, 3);
  enqueue(elQueue, 5);
  enqueue(elQueue, 7);
  enqueue(elQueue, 9);
  printer(elQueue);

  printf("\n");
  printf("%i \n",dequeue(elQueue));
  printf("%i \n",dequeue(elQueue));
  printf("%i \n",dequeue(elQueue));
  printf("%i \n",dequeue(elQueue));

  free(elQueue);
  return 0;
}
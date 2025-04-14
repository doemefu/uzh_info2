//
// Created by Dominic Furchert on 14.04.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct myStack{
  char content; //bracket
  struct myStack *next;
};

struct myStack** new(){
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

void printer(struct myStack** s) {
  struct myStack* curr = *s;
  while(curr != NULL){
    printf("%c",curr->content);
    curr=curr->next;
  }
  printf("\n"); // Add newline to separate output

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

bool validate_parentheses(char *S){

  struct myStack** elStack = new();

  for (int i = 0; i < strlen(S); i++) {
    if (S[i] == '(' || S[i] == '[') {
      push(S[i], elStack);
    }else {
      char prev = popValue(elStack);
      if (S[i]==')' && prev != '(') {
        return 0;
      }else if(S[i]==']' && prev != '[') {
        return 0;
      }
    }
    printer(elStack);
  }

  bool finale = isEmpty(elStack);
  free_stack(elStack);
  free(elStack);
  return finale;
}

int main(){

  char *word_zero = "(())";
  char *word_one = "(())((()))";
  char *word_three = "(()))()";
  char *word_two = "[[()[()]]]";
  char *word_four = "[[()]";

  printf("Testing %s should result in True, res is %s\n", word_zero, validate_parentheses(word_zero) ? "true" : "false");
  printf("Testing %s should result in True, res is %s\n", word_one, validate_parentheses(word_one) ? "true" : "false");
  printf("Testing %s should result in True, res is %s\n", word_two, validate_parentheses(word_two) ? "true" : "false");
  printf("Testing %s should result in False, res is %s\n", word_three, validate_parentheses(word_three) ? "true" : "false");
  printf("Testing %s should result in False, res is %s\n", word_four, validate_parentheses(word_four) ? "true" : "false");

  return 0;
}
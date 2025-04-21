//
// Created by Dominic Furchert on 21.04.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//
// Created by Dominic Furchert on 15.04.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode{
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

struct TreeNode* insert(struct TreeNode** root, int val){
  struct TreeNode* newNode = malloc(sizeof(struct TreeNode));
  newNode->val = val;
  newNode->left = NULL;
  newNode->right = NULL;

  struct TreeNode **curr = root;

  while(*curr!=NULL){
    if((*curr)->val > val){
      curr = &((*curr)->left);
    } else {
      curr = &((*curr)->right);
    }
  }
  *curr=newNode;
  printf("%i ",(*curr)->val);
  return NULL;
}

//parent vor children
void preTraverse(struct TreeNode* root){
  if (root == NULL) {
    return;
  }
  printf("%i ",root->val);
  preTraverse(root->left);
  preTraverse(root->right);
}

// parent zwischen children
void inTraverse(struct TreeNode* root){
  if (root == NULL) {
    return;
  }
  inTraverse(root->left);
  printf("%i  ",root->val);
  inTraverse(root->right);
}

//parent nach children
void postTraverse(struct TreeNode* root){
  if (root == NULL) {
    return;
  }
  postTraverse(root->left);
  postTraverse(root->right);
  printf("%i  ",root->val);
}

void traverseTree(struct TreeNode* root){
  printf("\nPreOrder: ");
  preTraverse(root);
  printf("\nInOrder: ");
  inTraverse(root);
  printf("\nPostOrder: ");
  postTraverse(root);
}

void stack_traverseTree(struct TreeNode* root){

}

struct TreeNode* delete(struct TreeNode** root, int val){

  return NULL;
}

struct TreeNode* flipTree(struct TreeNode* root) {
  if (root == NULL) {
    return NULL;
  }else {
    flipTree(root->left);
    flipTree(root->right);
  }
  struct TreeNode* tmp = root->left;
  root->left = root->right;
  root->right = tmp;
  return root;
}

int main(){
  struct TreeNode** myTree = malloc(sizeof *myTree);
  *myTree = NULL;

  insert(myTree, 8);
  insert(myTree, 5);
  insert(myTree, 7);
  insert(myTree, 3);
  insert(myTree, 4);
  insert(myTree, 9);
  insert(myTree, 11);

  traverseTree(*myTree);

  printf("\n Now flipped:");
  struct TreeNode* myNewTree = flipTree(*myTree);
  traverseTree(myNewTree);

  return 0;
}
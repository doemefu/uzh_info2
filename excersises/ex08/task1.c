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
    //printf("%i ",(*curr)->val);
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

  struct TreeNode* parent = NULL;
  struct TreeNode* current = *root;

  while (current != NULL && current->val != val) {
    parent = current;
    if (current->val > val) {
      current = current->left;
    }else {
      current = current->right;
    }
  }

  if (current==NULL || parent==NULL) { //not found
    *root = NULL;
    return *root;
  }

  if (current->left == NULL && current->right==NULL) { //zero leaf nodes
    if (parent->left == current) {
      parent->left==NULL;
    }else {
      parent->right==NULL;
    }
    return *root;
  }

  if (current->left == NULL || current->right==NULL) {    //one leaf node
    if (parent->left == current) {                        //curr is left
      if (current->left != NULL) {                        //child is left
        parent->left = current->left;
      }else {                                             //child is right
        parent->left = current->right;
      }
    }else {                                               //curr is right
      if (current->left != NULL) {                        //child is left
        parent->right = current->left;
      }else {                                             //child is right
        parent->right = current->right;
      }
    }
    return *root;
  }




  return NULL;
}

int main(){
  struct TreeNode** myTree = malloc(sizeof *myTree);
  *myTree = NULL;

  insert(myTree, 9);
  insert(myTree, 3);
  insert(myTree, 10);
  insert(myTree, 6);
  insert(myTree, 12);
  insert(myTree, 1);
  insert(myTree, 8);

  printf("__ %i __ ", (*myTree)->right->val);

  //print traversals
  traverseTree(*myTree);

  delete(myTree, 23);
  delete(myTree, 1);
  delete(myTree, 3);
  delete(myTree, 9);

  //print traversals

  return 0;

  /*
   *                            9
   *                       3        10
   *                   1      6        12
   *                            8
   *
   */
}
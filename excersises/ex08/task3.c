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
  //printf("%i ",(*curr)->val);
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

bool equalTree(struct TreeNode* root1, struct TreeNode* root2){
  if (root1 == NULL && root2==NULL) {
    return 1;
  }else if ((root1 != NULL && root2==NULL) || (root1 == NULL && root2!=NULL)) {
    return 0;
  }
  if(root1->val != root2->val){
    return 0;
  }
  if(!equalTree(root1->left, root2->left)){
    return 0;
  }
  if(!equalTree(root1->right, root2->right)){
    return 0;
  }
  return 1;
}

int main(){
  struct TreeNode** myTree1 = malloc(sizeof *myTree1);
  *myTree1 = NULL;

  insert(myTree1, 8);
  insert(myTree1, 5);
  insert(myTree1, 7);
  insert(myTree1, 3);
  insert(myTree1, 4);
  insert(myTree1, 9);
  insert(myTree1, 11);

  printf("Tree1:\n");
  inTraverse(*myTree1);

  struct TreeNode** myTree2 = malloc(sizeof *myTree2);
  *myTree2 = NULL;

  insert(myTree2, 8);
  insert(myTree2, 5);
  insert(myTree2, 7);
  insert(myTree2, 3);
  insert(myTree2, 4);
  insert(myTree2, 9);
  insert(myTree2, 11);

  printf("\nTree2:\n");
  inTraverse(*myTree2);

  printf("\nAre tree 1 and 2 Equal?\n");
  printf("%s",equalTree(*myTree1, *myTree2) ? "Yes!" : "No!");

  return 0;
}